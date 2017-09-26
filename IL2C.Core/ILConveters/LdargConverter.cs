using System.Reflection.Emit;

namespace IL2C.ILConveters
{
    internal sealed class Ldarg_0Converter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Ldarg_0;

        public override string Apply(DecodeContext context)
        {
            var parameter = context.Parameters[0];
            var symbolName = context.PushStack(parameter.ParameterType);
            return string.Format("{0} = {1};", symbolName, parameter.Name);
        }
    }

    internal sealed class Ldarg_1Converter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Ldarg_1;

        public override string Apply(DecodeContext context)
        {
            var parameter = context.Parameters[1];
            var symbolName = context.PushStack(parameter.ParameterType);
            return string.Format("{0} = {1};", symbolName, parameter.Name);
        }
    }
}
