using System.Reflection.Emit;

namespace IL2C.ILConveters
{
    internal static class LdargConverterUtilities
    {
        public static string Apply(int parameterIndex, DecodeContext context)
        {
            var parameter = context.Parameters[parameterIndex];
            var targetType = parameter.ParameterType;

            if (targetType == typeof(bool))
            {
                var symbolName = context.PushStack(typeof(int));
                return string.Format(
                    "{0} = {1} ? 1 : 0",
                    symbolName,
                    parameter.Name);
            }
            else
            {
                if ((targetType == typeof(byte))
                    || (targetType == typeof(sbyte))
                    || (targetType == typeof(short))
                    || (targetType == typeof(ushort)))
                {
                    targetType = typeof(int);
                }

                var symbolName = context.PushStack(targetType);
                return string.Format(
                    "{0} = {1}",
                    symbolName,
                    parameter.Name);
            }
        }
    }

    internal sealed class Ldarg_0Converter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Ldarg_0;

        public override string Apply(DecodeContext context)
        {
            return LdargConverterUtilities.Apply(0, context);
        }
    }

    internal sealed class Ldarg_1Converter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Ldarg_1;

        public override string Apply(DecodeContext context)
        {
            return LdargConverterUtilities.Apply(1, context);
        }
    }
}
