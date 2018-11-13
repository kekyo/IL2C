using System;

using Mono.Cecil.Cil;

using IL2C.Translators;

namespace IL2C.ILConverters
{
    internal static class LdindConverterUtilities
    {
        public static Func<IExtractContext, string[]> Apply(DecodeContext decodeContext)
        {
            var siFrom = decodeContext.PopStack();

            // Requre only managed refs
            if (!siFrom.TargetType.IsByReference)
            {
                throw new InvalidProgramSequenceException(
                    "Invalid managed reference: Location={0}, StackType={1}",
                    decodeContext.CurrentCode.RawLocation,
                    siFrom.TargetType.FriendlyName);
            }

            var targetType = siFrom.TargetType.ElementType;
            var symbol = decodeContext.PushStack(targetType);

            return extractContext => new[] { string.Format(
                "{0} = *{1}",
                extractContext.GetSymbolName(symbol),
                extractContext.GetSymbolName(siFrom)) };
        }
    }

    internal sealed class Ldind_i4Converter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Ldind_I4;

        public override Func<IExtractContext, string[]> Apply(DecodeContext decodeContext)
        {
            return LdindConverterUtilities.Apply(decodeContext);
        }
    }

    internal sealed class Ldind_u1Converter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Ldind_U1;

        public override Func<IExtractContext, string[]> Apply(DecodeContext decodeContext)
        {
            return LdindConverterUtilities.Apply(decodeContext);
        }
    }

    internal sealed class Ldind_refConverter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Ldind_Ref;

        public override Func<IExtractContext, string[]> Apply(DecodeContext decodeContext)
        {
            return LdindConverterUtilities.Apply(decodeContext);
        }
    }
}
