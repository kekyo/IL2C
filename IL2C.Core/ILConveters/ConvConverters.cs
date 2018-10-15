using System;

using Mono.Cecil.Cil;

using IL2C.Translators;

namespace IL2C.ILConverters
{
    internal sealed class Conv_i1Converter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Conv_I1;

        public override Func<IExtractContext, string[]> Apply(DecodeContext decodeContext)
        {
            var siFrom = decodeContext.PopStack();
            if (siFrom.TargetType.IsNumericPrimitive == false)
            {
                throw new InvalidProgramSequenceException(
                    "Cannot convert to numeric type: Location={0}, FromType={1}",
                    decodeContext.CurrentCode.RawLocation,
                    siFrom.TargetType.FriendlyName);
            }

            var resultName = decodeContext.PushStack(decodeContext.PrepareContext.MetadataContext.Int32Type);
            return _ => new[] { string.Format("{0} = (int8_t){1}", resultName, siFrom.SymbolName) };
        }
    }

    internal sealed class Conv_i2Converter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Conv_I2;

        public override Func<IExtractContext, string[]> Apply(DecodeContext decodeContext)
        {
            var siFrom = decodeContext.PopStack();
            if (siFrom.TargetType.IsNumericPrimitive == false)
            {
                throw new InvalidProgramSequenceException(
                    "Cannot convert to numeric type: Location={0}, FromType={1}",
                    decodeContext.CurrentCode.RawLocation,
                    siFrom.TargetType.FriendlyName);
            }

            var resultName = decodeContext.PushStack(decodeContext.PrepareContext.MetadataContext.Int32Type);
            return _ => new[] { string.Format("{0} = (int16_t){1}", resultName, siFrom.SymbolName) };
        }
    }

    internal sealed class Conv_i8Converter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Conv_I8;

        public override Func<IExtractContext, string[]> Apply(DecodeContext decodeContext)
        {
            var siFrom = decodeContext.PopStack();
            if (siFrom.TargetType.IsNumericPrimitive == false)
            {
                throw new InvalidProgramSequenceException(
                    "Cannot convert to numeric type: Location={0}, FromType={1}",
                    decodeContext.CurrentCode.RawLocation,
                    siFrom.TargetType.FriendlyName);
            }

            var resultName = decodeContext.PushStack(decodeContext.PrepareContext.MetadataContext.Int64Type);
            return _ => new[] { string.Format("{0} = (int64_t){1}", resultName, siFrom.SymbolName) };
        }
    }

    internal sealed class Conv_u1Converter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Conv_U1;

        public override Func<IExtractContext, string[]> Apply(DecodeContext decodeContext)
        {
            var siFrom = decodeContext.PopStack();
            if (siFrom.TargetType.IsNumericPrimitive == false)
            {
                throw new InvalidProgramSequenceException(
                    "Cannot convert to numeric type: Location={0}, FromType={1}",
                    decodeContext.CurrentCode.RawLocation,
                    siFrom.TargetType.FriendlyName);
            }

            var resultName = decodeContext.PushStack(decodeContext.PrepareContext.MetadataContext.Int32Type);
            return _ => new[] { string.Format("{0} = (uint8_t){1}", resultName, siFrom.SymbolName) };
        }
    }

    internal sealed class Conv_u2Converter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Conv_U2;

        public override Func<IExtractContext, string[]> Apply(DecodeContext decodeContext)
        {
            var siFrom = decodeContext.PopStack();
            if (siFrom.TargetType.IsNumericPrimitive == false)
            {
                throw new InvalidProgramSequenceException(
                    "Cannot convert to numeric type: Location={0}, FromType={1}",
                    decodeContext.CurrentCode.RawLocation,
                    siFrom.TargetType.FriendlyName);
            }

            var resultName = decodeContext.PushStack(decodeContext.PrepareContext.MetadataContext.Int32Type);
            return _ => new[] { string.Format("{0} = (uint16_t){1}", resultName, siFrom.SymbolName) };
        }
    }

    internal sealed class Conv_u4Converter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Conv_U4;

        public override Func<IExtractContext, string[]> Apply(DecodeContext decodeContext)
        {
            var siFrom = decodeContext.PopStack();
            if (siFrom.TargetType.IsNumericPrimitive == false)
            {
                throw new InvalidProgramSequenceException(
                    "Cannot convert to numeric type: Location={0}, FromType={1}",
                    decodeContext.CurrentCode.RawLocation,
                    siFrom.TargetType.FriendlyName);
            }

            var symbolName = decodeContext.PushStack(decodeContext.PrepareContext.MetadataContext.Int32Type);
            return _ => new[] { string.Format("{0} = (int32_t)(uint32_t){1}", symbolName, siFrom.SymbolName) };
        }
    }

    internal sealed class Conv_u8Converter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Conv_U8;

        public override Func<IExtractContext, string[]> Apply(DecodeContext decodeContext)
        {
            var siFrom = decodeContext.PopStack();
            if (siFrom.TargetType.IsNumericPrimitive == false)
            {
                throw new InvalidProgramSequenceException(
                    "Cannot convert to numeric type: Location={0}, FromType={1}",
                    decodeContext.CurrentCode.RawLocation,
                    siFrom.TargetType.FriendlyName);
            }

            var symbolName = decodeContext.PushStack(decodeContext.PrepareContext.MetadataContext.Int64Type);
            return _ => new[] { string.Format("{0} = (int64_t)(uint64_t){1}", symbolName, siFrom.SymbolName) };
        }
    }

    internal sealed class Conv_iConverter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Conv_I;

        public override Func<IExtractContext, string[]> Apply(DecodeContext decodeContext)
        {
            var siFrom = decodeContext.PopStack();
            if (siFrom.TargetType.IsNumericPrimitive == false)
            {
                throw new InvalidProgramSequenceException(
                    "Cannot convert to numeric type: Location={0}, FromType={1}",
                    decodeContext.CurrentCode.RawLocation,
                    siFrom.TargetType.FriendlyName);
            }

            var resultName = decodeContext.PushStack(decodeContext.PrepareContext.MetadataContext.IntPtrType);
            return _ => new[] { string.Format("{0} = (intptr_t){1}", resultName, siFrom.SymbolName) };
        }
    }

    internal sealed class Conv_uConverter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Conv_U;

        public override Func<IExtractContext, string[]> Apply(DecodeContext decodeContext)
        {
            var siFrom = decodeContext.PopStack();
            if (siFrom.TargetType.IsNumericPrimitive == false)
            {
                throw new InvalidProgramSequenceException(
                    "Cannot convert to numeric type: Location={0}, FromType={1}",
                    decodeContext.CurrentCode.RawLocation,
                    siFrom.TargetType.FriendlyName);
            }

            var resultName = decodeContext.PushStack(decodeContext.PrepareContext.MetadataContext.IntPtrType);
            return _ => new[] { string.Format("{0} = (intptr_t)(uintptr_t){1}", resultName, siFrom.SymbolName) };
        }
    }
}
