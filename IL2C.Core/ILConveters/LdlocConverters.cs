using System.Reflection.Emit;

namespace IL2C.ILConveters
{
    internal sealed class Ldloc_0Converter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Ldloc_0;

        public override string Apply(DecodeContext context)
        {
            var local = context.Locals[0];
            var symbolName = context.PushStack(local.LocalType);
            return string.Format("{0} = local0;", symbolName);
        }
    }

    internal sealed class Ldloc_1Converter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Ldloc_1;

        public override string Apply(DecodeContext context)
        {
            var local = context.Locals[1];
            var symbolName = context.PushStack(local.LocalType);
            return string.Format("{0} = local1;", symbolName);
        }
    }

    internal sealed class Ldloc_2Converter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Ldloc_2;

        public override string Apply(DecodeContext context)
        {
            var local = context.Locals[2];
            var symbolName = context.PushStack(local.LocalType);
            return string.Format("{0} = local2;", symbolName);
        }
    }

    internal sealed class Ldloc_3Converter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Ldloc_3;

        public override string Apply(DecodeContext context)
        {
            var local = context.Locals[3];
            var symbolName = context.PushStack(local.LocalType);
            return string.Format("{0} = local3;", symbolName);
        }
    }
}
