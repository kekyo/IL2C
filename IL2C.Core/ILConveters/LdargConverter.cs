using System.Reflection.Emit;

namespace IL2C.ILConveters
{
    internal static class LdargConverterUtilities
    {
        public static string Apply(int parameterIndex, DecodeContext decodeContext)
        {
            var parameter = decodeContext.Parameters[parameterIndex];
            var targetType = parameter.ParameterType;

            if (targetType == typeof(bool))
            {
                var symbolName = decodeContext.PushStack(typeof(int));
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

                var symbolName = decodeContext.PushStack(targetType);
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

        public override string Apply(DecodeContext decodeContext)
        {
            return LdargConverterUtilities.Apply(0, decodeContext);
        }
    }

    internal sealed class Ldarg_1Converter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Ldarg_1;

        public override string Apply(DecodeContext decodeContext)
        {
            return LdargConverterUtilities.Apply(1, decodeContext);
        }
    }
}
