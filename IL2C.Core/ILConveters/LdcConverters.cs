using System.Reflection.Emit;

namespace IL2C.ILConveters
{
    internal sealed class Ldc_i4_1Converter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Ldc_I4_1;

        public override string Apply(DecodeContext context)
        {
            var symbolName = context.PushStack(typeof(int));
            return string.Format("{0} = 1", symbolName);
        }
    }

    internal sealed class Ldc_i4_2Converter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Ldc_I4_2;

        public override string Apply(DecodeContext context)
        {
            var symbolName = context.PushStack(typeof(int));
            return string.Format("{0} = 2", symbolName);
        }
    }

    internal sealed class Ldc_i4Converter : InlineI4Converter
    {
        public override OpCode OpCode => OpCodes.Ldc_I4;

        public override string Apply(int operand, DecodeContext context)
        {
            var symbolName = context.PushStack(typeof(int));
            return string.Format("{0} = {1}", symbolName, operand);
        }
    }

    internal sealed class Ldc_i8Converter : InlineI8Converter
    {
        public override OpCode OpCode => OpCodes.Ldc_I8;

        public override string Apply(long operand, DecodeContext context)
        {
            var symbolName = context.PushStack(typeof(long));
            return string.Format("{0} = {1}LL", symbolName, operand);
        }
    }
}
