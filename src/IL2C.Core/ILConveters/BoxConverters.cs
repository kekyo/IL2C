////////////////////////////////////////////////////////////////////////////
//
// IL2C - A translator for ECMA-335 CIL/MSIL to C language.
// Copyright (c) Kouji Matsui (@kozy_kekyo, @kekyo@mastodon.cloud)
//
// Licensed under Apache-v2: https://opensource.org/licenses/Apache-2.0
//
////////////////////////////////////////////////////////////////////////////

using System;

using Mono.Cecil.Cil;

using IL2C.Metadata;
using IL2C.Translators;
using IL2C.Metadata.Specialized;

namespace IL2C.ILConverters
{
    internal sealed class BoxConverter : InlineTypeConverter
    {
        public override OpCode OpCode => OpCodes.Box;

        public override ExpressionEmitter Prepare(
            ITypeInformation operand, DecodeContext decodeContext)
        {
            var si = decodeContext.PopStack();
            if (!(si.TargetType.IsValueType &&      // We have to value type
                (operand.Equals(si.TargetType) ||   // Same type
                (operand.IsInt32StackFriendlyType && si.TargetType.IsInt32StackFriendlyType) ||     // Same size or implicit expanders
                (operand.IsInt64StackFriendlyType && si.TargetType.IsInt64StackFriendlyType) ||     // Same size
                (operand.IsIntPtrStackFriendlyType && si.TargetType.IsIntPtrStackFriendlyType))))   // Same size
            {
                throw new InvalidProgramSequenceException(
                    "Invalid type at stack: Location={0}, TokenType={1}, StackType={2}",
                    decodeContext.CurrentCode.RawLocation,
                    operand.FriendlyName,
                    si.TargetType.FriendlyName);
            }

            // NOTE: The 'O' type means System.Object, but we have to push the System.ValueType (BoxedValueTypeInformation).
            //   Because the boxed value types can implicit cast to both types.
            //   The upcast can be inlining (System.ValueType --> System.Object),
            //   but downcast requires runtime cast operator (System.Object --> System.ValueType).
            var symbol = decodeContext.PushStack(
                new BoxedValueTypeInformation(si.TargetType));

            // Register target type (at the file scope).
            decodeContext.PrepareContext.RegisterType(operand, decodeContext.Method);

            // NOTE: The IL2C strict type infers the evaluation stack.
            //   The unbox operator is handling by the pointer.
            //   So, we have to simulate implicitly conversion from little size value to large size value.
            //   (It's only 8/16 --> 32bit. See ECMA-335 III.1.1.1 Numeric data types)
            //   We can use conversion with the "il2c_box2" function in this case.
            //   For example:
            //     // object value = (byte)123;
            //     ldc.i4.s 123                 // int32_t
            //     box [mscorlib]System.Byte    // int32_t --> objref(uint8_t)   // size[4] --> size[1]
            if (operand.InternalStaticSizeOfValue == si.TargetType.InternalStaticSizeOfValue)
            {
                return (extractContext, _) =>
                {
                    return new[] { string.Format(
                        "{0} = il2c_box(&{1}, {2})",
                        extractContext.GetSymbolName(symbol),
                        extractContext.GetSymbolName(si),
                        operand.MangledUniqueName) };
                };
            }
            else
            {
                return (extractContext, _) =>
                {
                    return new[] { string.Format(
                        "{0} = il2c_box2(&{1}, {2}, {3})",
                        extractContext.GetSymbolName(symbol),
                        extractContext.GetSymbolName(si),
                        operand.MangledUniqueName,
                        si.TargetType.MangledUniqueName) };
                };
            }
        }
    }

    internal sealed class Unbox_AnyConverter : InlineTypeConverter
    {
        public override OpCode OpCode => OpCodes.Unbox_Any;

        public override ExpressionEmitter Prepare(
            ITypeInformation operand, DecodeContext decodeContext)
        {
            var si = decodeContext.PopStack();

            if (si.TargetType.IsValueType || si.TargetType.IsByReference || si.TargetType.IsPointer)
            {
                throw new InvalidProgramSequenceException(
                    "Invalid type at stack: Location={0}, TokenType={1}, StackType={2}",
                    decodeContext.CurrentCode.RawLocation,
                    operand.FriendlyName,
                    si.TargetType.FriendlyName);
            }

            var symbol = decodeContext.PushStack(operand);

            return (extractContext, _) =>
            {
                return new[] { string.Format(
                    "{0} = *il2c_unbox({1}, {2})",
                    extractContext.GetSymbolName(symbol),
                    extractContext.GetSymbolName(si),
                    operand.MangledUniqueName) };
            };
        }
    }
}
