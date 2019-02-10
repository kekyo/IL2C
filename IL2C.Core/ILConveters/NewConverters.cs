using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;

using Mono.Cecil.Cil;

using IL2C.Translators;
using IL2C.Metadata;

namespace IL2C.ILConverters
{
    internal sealed class InitobjConverter : InlineTypeConverter
    {
        public override OpCode OpCode => OpCodes.Initobj;

        public override Func<IExtractContext, string[]> Apply(
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

            return extractContext =>
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

        public override Func<IExtractContext, string[]> Apply(
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

            var pairParameters = new LinkedList<Utilities.RightExpressionGivenParameter>();
            foreach (var parameter in ctor.Parameters.Reverse())
            {
                // Except this parameter
                if (pairParameters.Count < (ctor.Parameters.Length) - 1)
                {
                    pairParameters.AddFirst(new Utilities.RightExpressionGivenParameter(
                        parameter.TargetType,
                        decodeContext.PopStack()));
                }
                // "this" parameter
                else
                {
                    Debug.Assert(thisSymbol == null);

                    // Instance from get_uninitialized_object
                    thisSymbol = decodeContext.PushStack(type, ctor);

                    pairParameters.AddFirst(new Utilities.RightExpressionGivenParameter(
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

                if (!(ctor.Parameters.Length == 2) &&
                    (ctor.Parameters[0].TargetType.IsObjectType) &&
                    (ctor.Parameters[0].TargetType.IsIntPtrType))
                {
                    throw new InvalidProgramSequenceException(
                        "Invalid delegate constructor: Location={0}, Method={1}",
                        codeInformation.RawLocation,
                        ctor.FriendlyName);
                }

                return extractContext =>
                {
                    var parameterString = Utilities.GetGivenParameterDeclaration(
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

            var overloadIndex = ctor.OverloadIndex;

            return extractContext =>
            {
                var parameterString = Utilities.GetGivenParameterDeclaration(
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
                            (overloadIndex >= 1) ?
                                string.Format(
                                    "{0}__ctor_{1}(&{2})",
                                    typeName,
                                    overloadIndex,
                                    parameterString) :
                                string.Format(
                                    "{0}__ctor(&{1})",
                                    typeName,
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
                        (overloadIndex >= 1) ?
                            string.Format(
                                "{0}__ctor_{1}({2})",
                                type.MangledUniqueName,
                                overloadIndex,
                                parameterString) :
                            string.Format(
                                "{0}__ctor({1})",
                                type.MangledUniqueName,
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

        public override Func<IExtractContext, string[]> Apply(
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

            return extractContext => new[] { string.Format(
                "{0} = il2c_new_array({1}, {2})",
                extractContext.GetSymbolName(symbol),
                elementType.MangledUniqueName,
                extractContext.GetSymbolName(siCount)) };
        }
    }
}
