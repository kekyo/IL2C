////////////////////////////////////////////////////////////////////////////
//
// IL2C - A translator for ECMA-335 CIL/MSIL to C language.
// Copyright (c) Kouji Matsui (@kozy_kekyo, @kekyo@mastodon.cloud)
//
// Licensed under Apache-v2: https://opensource.org/licenses/Apache-2.0
//
////////////////////////////////////////////////////////////////////////////

using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;

using Mono.Cecil.Cil;

using IL2C.Translators;
using IL2C.Metadata;
using IL2C.Internal;

namespace IL2C.ILConverters
{
    internal sealed class InitobjConverter : InlineTypeConverter
    {
        public override OpCode OpCode => OpCodes.Initobj;

        public override ExpressionEmitter Prepare(
            ITypeInformation type, DecodeContext decodeContext)
        {
            var si = decodeContext.PopStack();
            if (si.TargetType.IsByReference == false)
            {
                throw new InvalidProgramSequenceException(
                    "Invalid type at stack: Location={0}, TokenType={1}, StackType={2}",
                    decodeContext.CurrentCode.RawLocation,
                    type.FriendlyName,
                    si.TargetType.FriendlyName);
            }

            // Register target type (at the file scope).
            decodeContext.PrepareContext.RegisterType(type, decodeContext.Method);

            return (extractContext, _) =>
            {
                // IL2C can't understand the native type size.
                // So, the expression will make calculation at the C compiler.
                var memsetExpression =
                    (si.TargetType.ElementType.NativeType != null) ?
                    "memset({0}, 0x00, sizeof *{0})" :
                    "memset({0}, 0x00, {1})";

                return new[] { string.Format(
                    memsetExpression,
                    extractContext.GetSymbolName(si),
                    si.TargetType.ElementType.CLanguageStaticSizeOfExpression) };
            };
        }
    }

    internal sealed class NewobjConverter : InlineMethodConverter
    {
        public override OpCode OpCode => OpCodes.Newobj;

        public override ExpressionEmitter Prepare(
            IMethodInformation ctor, DecodeContext decodeContext)
        {
            if (!ctor.IsConstructor)
            {
                throw new InvalidProgramSequenceException(
                    "Invalid new object constructor: Location={0}, Method={1}",
                    decodeContext.CurrentCode.RawLocation,
                    ctor.FriendlyName);
            }

            // Generate the constructor's argument expressions.
            var type = ctor.DeclaringType;
            ILocalVariableInformation thisSymbol = null;

            var pairParameters = new LinkedList<SymbolManipulator.RightExpressionGivenParameter>();
            foreach (var parameter in ctor.Parameters.Reverse())
            {
                // Except this parameter
                if (pairParameters.Count < (ctor.Parameters.Length) - 1)
                {
                    pairParameters.AddFirst(new SymbolManipulator.RightExpressionGivenParameter(
                        parameter.TargetType,
                        decodeContext.PopStack()));
                }
                // "this" parameter
                else
                {
                    Debug.Assert(thisSymbol == null);

                    // Instance from get_uninitialized_object
                    thisSymbol = decodeContext.PushStack(type, ctor);

                    pairParameters.AddFirst(new SymbolManipulator.RightExpressionGivenParameter(
                        type,
                        thisSymbol));
                }
            }

            Debug.Assert(thisSymbol != null);

            var codeInformation = decodeContext.CurrentCode;

            // Register target constructor declaring type (at the file scope).
            decodeContext.PrepareContext.RegisterType(type, decodeContext.Method);

            // Specialized the delegate type:
            //   We can use for instantiate the delegate instance with "il2c_new_delegate()."
            if (type.IsDelegate)
            {
                if (type.IsAbstract || type.IsDelegateType || type.IsMulticastDelegateType)
                {
                    throw new InvalidProgramSequenceException(
                        "Invalid delegate type: Location={0}, Method={1}",
                        codeInformation.RawLocation,
                        type.FriendlyName);
                }

                if ((ctor.Parameters.Length != 3) ||
                    !ctor.Parameters[1].TargetType.IsObjectType ||
                    !ctor.Parameters[2].TargetType.IsIntPtrType)
                {
                    throw new InvalidProgramSequenceException(
                        "Invalid delegate constructor: Location={0}, Method={1}",
                        codeInformation.RawLocation,
                        ctor.FriendlyName);
                }

                return (extractContext, _) =>
                {
                    var parameterString = SymbolManipulator.GetGivenParameterDeclaration(
                        pairParameters.Skip(1).ToArray(), extractContext, codeInformation);

                    return new[]
                    {
                        string.Format(
                            "{0} = il2c_new_delegate({1}, {2})",
                            extractContext.GetSymbolName(thisSymbol),
                            type.MangledUniqueName,
                            parameterString)
                    };
                };
            }

            // Specialized the thread type:
            if (type.UniqueName == "System.Threading.Thread")
            {
                if (!type.IsClass || !type.IsSealed)
                {
                    throw new InvalidProgramSequenceException(
                        "Invalid thread type: Location={0}, Method={1}",
                        codeInformation.RawLocation,
                        type.FriendlyName);
                }

                if ((ctor.Parameters.Length != 2) ||
                    ((ctor.Parameters[1].TargetType.UniqueName != "System.Threading.ThreadStart") &&
                     (ctor.Parameters[1].TargetType.UniqueName != "System.Threading.ParameterizedThreadStart")))
                {
                    throw new InvalidProgramSequenceException(
                        "Invalid thread constructor: Location={0}, Method={1}",
                        codeInformation.RawLocation,
                        ctor.FriendlyName);
                }

                return (extractContext, _) =>
                {
                    var parameterString = SymbolManipulator.GetGivenParameterDeclaration(
                        pairParameters.Skip(1).ToArray(), extractContext, codeInformation);

                    return new[]
                    {
                        string.Format(
                            "{0} = il2c_new_thread({1})",
                            extractContext.GetSymbolName(thisSymbol),
                            parameterString)
                    };
                };
            }

            // TODO: overloadIndex
            var overloadIndex = ctor.OverloadIndex;

            return (extractContext, _) =>
            {
                var parameterString = SymbolManipulator.GetGivenParameterDeclaration(
                    pairParameters.ToArray(), extractContext, codeInformation);

                // newobj opcode can handle value type with parameter applied constructor.
                if (type.IsValueType)
                {
                    // IL2C can't understand the native type size.
                    // So, the expression will make calculation at the C compiler.
                    var memsetExpression =
                        (type.NativeType != null) ?
                        "memset(&{0}, 0x00, sizeof {0})" :
                        "memset(&{0}, 0x00, {1})";

                    // If constructor's arguments greater than or equal 2 (this and others)
                    if (pairParameters.Count >= 2)
                    {
                        var typeName = type.CLanguageTypeName;
                        return new[] {
                            string.Format(
                                memsetExpression,
                                extractContext.GetSymbolName(thisSymbol),
                                type.CLanguageStaticSizeOfExpression),
                            string.Format(
                                "{0}(&{1})",
                                ctor.CLanguageFunctionFullName,
                                parameterString)
                        };
                    }
                    else
                    {
                        // ValueType's default constructor not declared.
                        return new[] { string.Format(
                            memsetExpression,
                            extractContext.GetSymbolName(thisSymbol),
                            type.MangledUniqueName) };
                    }
                }
                // Object reference types.
                else
                {
                    var get = new[]
                    {
                        string.Format(
                            "{0} = il2c_get_uninitialized_object({1})",
                            extractContext.GetSymbolName(thisSymbol),
                            type.MangledUniqueName)
                    };

                    var callCtor = new[]
                    {
                        string.Format(
                            "{0}({1})",
                            ctor.CLanguageFunctionFullName,
                            parameterString)
                    };

                    return get.
                        Concat(callCtor).
                        ToArray();
                }
            };
        }
    }

    internal sealed class NewarrConverter : InlineTypeConverter
    {
        public override OpCode OpCode => OpCodes.Newarr;

        public override ExpressionEmitter Prepare(
            ITypeInformation elementType, DecodeContext decodeContext)
        {
            var siCount = decodeContext.PopStack();
            if (!(siCount.TargetType.IsInt32StackFriendlyType || siCount.TargetType.IsIntPtrStackFriendlyType))
            {
                throw new InvalidProgramSequenceException(
                    "Invalid array size type: Location={0}, StackType={1}",
                    decodeContext.CurrentCode.RawLocation,
                    siCount.TargetType.FriendlyName);
            }

            var symbol = decodeContext.PushStack(elementType.MakeArray());

            return (extractContext, _) => new[] { string.Format(
                "{0} = il2c_new_array({1}, {2})",
                extractContext.GetSymbolName(symbol),
                elementType.MangledUniqueName,
                extractContext.GetSymbolName(siCount)) };
        }
    }
}
