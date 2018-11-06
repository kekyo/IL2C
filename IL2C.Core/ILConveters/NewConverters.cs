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

            decodeContext.PrepareContext.RegisterIncludeFile("string.h");

            return extractContext =>
            {
                return new[] { string.Format(
                    "memset({0}, 0x00, sizeof({1}))",
                    si.SymbolName,
                    type.MangledName) };
            };
        }
    }

    internal sealed class NewobjConverter : InlineMethodConverter
    {
        public override OpCode OpCode => OpCodes.Newobj;

        public override Func<IExtractContext, string[]> Apply(
            IMethodInformation method, DecodeContext decodeContext)
        {
            if (!method.IsConstructor)
            {
                throw new InvalidProgramSequenceException(
                    "Invalid new object constructor: Location={0}, Method={1}",
                    decodeContext.CurrentCode.RawLocation,
                    method.FriendlyName);
            }

            // Generate the constructor's argument expressions.
            var type = method.DeclaringType;
            string thisSymbolName = null;

            var pairParameters = new LinkedList<Utilities.RightExpressionGivenParameter>();
            foreach (var parameter in method.Parameters.Reverse())
            {
                // Except this parameter
                if (pairParameters.Count < (method.Parameters.Length) - 1)
                {
                    pairParameters.AddFirst(new Utilities.RightExpressionGivenParameter(
                        parameter.TargetType,
                        decodeContext.PopStack()));
                }
                // This parameter
                else
                {
                    thisSymbolName = decodeContext.PushStack(type);
                    pairParameters.AddFirst(new Utilities.RightExpressionGivenParameter(
                        parameter.TargetType,
                        new VariableInformation(method, 0, thisSymbolName, type)));
                }
            }

            Debug.Assert(!string.IsNullOrWhiteSpace(thisSymbolName));

            var codeInformation = decodeContext.CurrentCode;

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

                if (!(method.Parameters.Length == 2) &&
                    (method.Parameters[0].TargetType.IsObjectType) &&
                    (method.Parameters[0].TargetType.IsIntPtrType))
                {
                    throw new InvalidProgramSequenceException(
                        "Invalid delegate constructor: Location={0}, Method={1}",
                        codeInformation.RawLocation,
                        method.FriendlyName);
                }

                return extractContext =>
                {
                    var parameterString = Utilities.GetGivenParameterDeclaration(
                        pairParameters.Skip(1).ToArray(), extractContext, codeInformation);

                    return new[]
                    {
                        string.Format(
                            "{0} = il2c_new_delegate({1}, {2})",
                            thisSymbolName,
                            type.MangledName,
                            parameterString)
                    };
                };
            }

            var overloadIndex = method.OverloadIndex;

            return extractContext =>
            {
                var parameterString = Utilities.GetGivenParameterDeclaration(
                    pairParameters.ToArray(), extractContext, codeInformation);

                // newobj opcode can handle value type with parameter applied constructor.
                if (type.IsValueType)
                {
                    var typeName = type.CLanguageTypeName;
                    // If constructor's arguments greater than or equal 2 (this and others)
                    if (pairParameters.Count >= 2)
                    {
                        return new[] {
                            string.Format(
                                "memset(&{0}, 0x00, sizeof({1}))",
                                thisSymbolName,
                                typeName),
                            (overloadIndex >= 1)
                                ? string.Format(
                                    "{0}__ctor_{1}(&{2})",
                                    typeName,
                                    overloadIndex,
                                    parameterString)
                                : string.Format(
                                    "{0}__ctor(&{1})",
                                    typeName,
                                    parameterString)
                        };
                    }
                    else
                    {
                        // ValueType's default constructor not declared.
                        return new[] { string.Format(
                            "memset(&{0}, 0x00, sizeof({1}))",
                            thisSymbolName,
                            typeName) };
                    }
                }
                // Object reference types.
                else
                {
                    var get = new[]
                    {
                        string.Format(
                            "{0} = il2c_get_uninitialized_object({1})",
                            thisSymbolName,
                            type.MangledName)
                    };

                    // TODO: Setup vptr from vtables.
                    var vptrs = type.InterfaceTypes.Select(interfaceType =>
                    {
                        // Interface's vptr:
                        //   These are unique tables by pair of instance type and interface type.
                        //   Because vtable has function pointers from unique adjustor thunk by instance type layout offset.
                        return string.Format(
                            "{0}->vptr_{1}__ = &__{2}_{1}_VTABLE__",
                            thisSymbolName,
                            interfaceType.MangledName,
                            type.MangledName);
                    });

                    var ctor = new[]
                    {
                        (overloadIndex >= 1)
                            ? string.Format(
                                "{0}__ctor_{1}({2})",
                                type.MangledName,
                                overloadIndex,
                                parameterString)
                            : string.Format(
                                "{0}__ctor({1})",
                                type.MangledName,
                                parameterString)
                    };

                    return get.
                        //Concat(vptrs). // TODO: 
                        Concat(ctor).
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

            var symbolName = decodeContext.PushStack(elementType.MakeArray());

            return _ => new[] { string.Format(
                "{0} = il2c_new_array({1}, {2})",
                symbolName,
                elementType.MangledName,
                siCount.SymbolName) };
        }
    }
}
