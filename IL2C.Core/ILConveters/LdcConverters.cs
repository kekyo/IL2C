using System.Reflection.Emit;

namespace IL2C.ILConveters
{
    internal sealed class Ldc_i4_0Converter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Ldc_I4_0;

        public override string[] Apply(DecodeContext decodeContext)
        {
            var symbolName = decodeContext.PushStack(typeof(int));
            return new[] { string.Format("{0} = 0", symbolName) };
        }
    }

    internal sealed class Ldc_i4_1Converter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Ldc_I4_1;

        public override string[] Apply(DecodeContext decodeContext)
        {
            var symbolName = decodeContext.PushStack(typeof(int));
            return new[] { string.Format("{0} = 1", symbolName) };
        }
    }

    internal sealed class Ldc_i4_2Converter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Ldc_I4_2;

        public override string[] Apply(DecodeContext decodeContext)
        {
            var symbolName = decodeContext.PushStack(typeof(int));
            return new[] { string.Format("{0} = 2", symbolName) };
        }
    }

    internal sealed class Ldc_i4_5Converter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Ldc_I4_5;

        public override string[] Apply(DecodeContext decodeContext)
        {
            var symbolName = decodeContext.PushStack(typeof(int));
            return new[] { string.Format("{0} = 5", symbolName) };
        }
    }

    internal sealed class Ldc_i4Converter : InlineI4Converter
    {
        public override OpCode OpCode => OpCodes.Ldc_I4;

        public override string[] Apply(int operand, DecodeContext decodeContext)
        {
            var symbolName = decodeContext.PushStack(typeof(int));
            return new[] { string.Format("{0} = {1}", symbolName, operand) };
        }
    }

    internal sealed class Ldc_i4_sConverter : ShortInlineI1Converter
    {
        public override OpCode OpCode => OpCodes.Ldc_I4_S;

        public override string[] Apply(sbyte operand, DecodeContext decodeContext)
        {
            var symbolName = decodeContext.PushStack(typeof(int));
            return new[] { string.Format("{0} = {1}", symbolName, operand) };
        }
    }

    internal sealed class Ldc_i8Converter : InlineI8Converter
    {
        public override OpCode OpCode => OpCodes.Ldc_I8;

        public override string[] Apply(long operand, DecodeContext decodeContext)
        {
            var symbolName = decodeContext.PushStack(typeof(long));
            return new[] { string.Format("{0} = {1}LL", symbolName, operand) };
        }
    }
}
