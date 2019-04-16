using System;

using Mono.Cecil.Cil;

using IL2C.Translators;

namespace IL2C.ILConverters
{
    internal static class LdindConverterUtilities
    {
        public static ExpressionEmitter Prepare(DecodeContext decodeContext)
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

            return (extractContext, _) => new[] { string.Format(
                "{0} = *{1}",
                extractContext.GetSymbolName(symbol),
                extractContext.GetSymbolName(siFrom)) };
        }
    }

    internal sealed class Ldind_u1Converter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Ldind_U1;

        public override ExpressionEmitter Prepare(DecodeContext decodeContext)
        {
            return LdindConverterUtilities.Prepare(decodeContext);
        }
    }

    internal sealed class Ldind_i2Converter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Ldind_I2;

        public override ExpressionEmitter Prepare(DecodeContext decodeContext)
        {
            return LdindConverterUtilities.Prepare(decodeContext);
        }
    }

    internal sealed class Ldind_i4Converter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Ldind_I4;

        public override ExpressionEmitter Prepare(DecodeContext decodeContext)
        {
            return LdindConverterUtilities.Prepare(decodeContext);
        }
    }

    internal sealed class Ldind_i8Converter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Ldind_I8;

        public override ExpressionEmitter Prepare(DecodeContext decodeContext)
        {
            return LdindConverterUtilities.Prepare(decodeContext);
        }
    }

    internal sealed class Ldind_i1Converter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Ldind_I1;

        public override ExpressionEmitter Prepare(DecodeContext decodeContext)
        {
            return LdindConverterUtilities.Prepare(decodeContext);
        }
    }

    internal sealed class Ldind_u2Converter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Ldind_U2;

        public override ExpressionEmitter Prepare(DecodeContext decodeContext)
        {
            return LdindConverterUtilities.Prepare(decodeContext);
        }
    }

    internal sealed class Ldind_u4Converter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Ldind_U4;

        public override ExpressionEmitter Prepare(DecodeContext decodeContext)
        {
            return LdindConverterUtilities.Prepare(decodeContext);
        }
    }

    internal sealed class Ldind_r4Converter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Ldind_R4;

        public override ExpressionEmitter Prepare(DecodeContext decodeContext)
        {
            return LdindConverterUtilities.Prepare(decodeContext);
        }
    }

    internal sealed class Ldind_r8Converter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Ldind_R8;

        public override ExpressionEmitter Prepare(DecodeContext decodeContext)
        {
            return LdindConverterUtilities.Prepare(decodeContext);
        }
    }

    internal sealed class Ldind_iConverter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Ldind_I;

        public override ExpressionEmitter Prepare(DecodeContext decodeContext)
        {
            return LdindConverterUtilities.Prepare(decodeContext);
        }
    }

    internal sealed class Ldind_refConverter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Ldind_Ref;

        public override ExpressionEmitter Prepare(DecodeContext decodeContext)
        {
            return LdindConverterUtilities.Prepare(decodeContext);
        }
    }
}
