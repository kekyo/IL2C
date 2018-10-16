using System;

using Mono.Cecil.Cil;

using IL2C.Translators;

namespace IL2C.ILConverters
{
    internal sealed class Ldind_i4Converter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Ldind_I4;

        public override Func<IExtractContext, string[]> Apply(DecodeContext decodeContext)
        {
            var siFrom = decodeContext.PopStack();

            var targetType = decodeContext.PrepareContext.MetadataContext.Int32Type;
            var symbolName = decodeContext.PushStack(targetType);

            return extractContext => new[] { string.Format(
                "{0} = *(int32_t*){1}",
                symbolName,
                siFrom.SymbolName) };

        }
    }

    internal sealed class Ldind_u1Converter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Ldind_U1;

        public override Func<IExtractContext, string[]> Apply(DecodeContext decodeContext)
        {
            var siFrom = decodeContext.PopStack();

            var targetType = decodeContext.PrepareContext.MetadataContext.ByteType;
            var symbolName = decodeContext.PushStack(targetType);

            return extractContext => new[] { string.Format(
                "{0} = *(uint8_t*){1}",
                symbolName,
                siFrom.SymbolName) };

        }
    }
}
