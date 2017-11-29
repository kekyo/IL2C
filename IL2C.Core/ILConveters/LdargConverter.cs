using System;

using Mono.Cecil.Cil;

using IL2C.Translators;

namespace IL2C.ILConveters
{
    internal static class LdargConverterUtilities
    {
        public static Func<IExtractContext, string[]> Apply(int parameterIndex, DecodeContext decodeContext)
        {
            var parameter = decodeContext.Parameters[parameterIndex];
            var targetType = parameter.ParameterType.GetStackableType();
            var symbolName = decodeContext.PushStack(targetType);

            if (parameter.ParameterType.IsBooleanType())
            {
                return _ => new[] { string.Format(
                    "{0} = {1} ? 1 : 0",
                    symbolName,
                    parameter.Name) };
            }
            else
            {
                return _ => new[] { string.Format(
                    "{0} = {1}",
                    symbolName,
                    parameter.Name) };
            }
        }
    }

    internal sealed class Ldarg_0Converter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Ldarg_0;

        public override Func<IExtractContext, string[]> Apply(DecodeContext decodeContext)
        {
            return LdargConverterUtilities.Apply(0, decodeContext);
        }
    }

    internal sealed class Ldarg_1Converter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Ldarg_1;

        public override Func<IExtractContext, string[]> Apply(DecodeContext decodeContext)
        {
            return LdargConverterUtilities.Apply(1, decodeContext);
        }
    }

    internal sealed class Ldarg_2Converter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Ldarg_2;

        public override Func<IExtractContext, string[]> Apply(DecodeContext decodeContext)
        {
            return LdargConverterUtilities.Apply(2, decodeContext);
        }
    }
}
