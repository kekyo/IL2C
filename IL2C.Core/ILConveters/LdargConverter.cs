using System;

using Mono.Cecil.Cil;

using IL2C.Translators;
using IL2C.Metadata;

namespace IL2C.ILConverters
{
    internal static class LdargConverterUtilities
    {
        public static Func<IExtractContext, string[]> Apply(
            int parameterIndex, DecodeContext decodeContext, bool isReference)
        {
            var parameter = decodeContext.Method.Parameters[parameterIndex];
            var targetType = isReference ? parameter.TargetType.MakeByReference() : parameter.TargetType;
            var symbol = decodeContext.PushStack(targetType);

            return extractContext => new[] { string.Format(
                "{0} = {1}{2}",
                extractContext.GetSymbolName(symbol),
                // MEMO: Don't check "targetType.IsByReference" instead "isReference."
                //   Because it's maybe double encoded byref type.
                isReference ? "&" : string.Empty,
                parameter.ParameterName) };
        }
    }

    internal sealed class Ldarg_0Converter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Ldarg_0;

        public override Func<IExtractContext, string[]> Apply(DecodeContext decodeContext)
        {
            return LdargConverterUtilities.Apply(0, decodeContext, false);
        }
    }

    internal sealed class Ldarg_1Converter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Ldarg_1;

        public override Func<IExtractContext, string[]> Apply(DecodeContext decodeContext)
        {
            return LdargConverterUtilities.Apply(1, decodeContext, false);
        }
    }

    internal sealed class Ldarg_2Converter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Ldarg_2;

        public override Func<IExtractContext, string[]> Apply(DecodeContext decodeContext)
        {
            return LdargConverterUtilities.Apply(2, decodeContext, false);
        }
    }

    internal sealed class Ldarg_3Converter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Ldarg_3;

        public override Func<IExtractContext, string[]> Apply(DecodeContext decodeContext)
        {
            return LdargConverterUtilities.Apply(3, decodeContext, false);
        }
    }

    internal sealed class Ldarg_sConverter : ShortInlineParamConverter
    {
        public override OpCode OpCode => OpCodes.Ldarg_S;

        public override Func<IExtractContext, string[]> Apply(
            VariableInformation operand, DecodeContext decodeContext)
        {
            return LdargConverterUtilities.Apply(operand.Index, decodeContext, false);
        }
    }

    internal sealed class LdargConverter : InlineParamConverter
    {
        public override OpCode OpCode => OpCodes.Ldarg;

        public override Func<IExtractContext, string[]> Apply(
            VariableInformation operand, DecodeContext decodeContext)
        {
            return LdargConverterUtilities.Apply(operand.Index, decodeContext, false);
        }
    }

    internal sealed class Ldarga_sConverter : ShortInlineParamConverter
    {
        public override OpCode OpCode => OpCodes.Ldarga_S;

        public override Func<IExtractContext, string[]> Apply(
            VariableInformation operand, DecodeContext decodeContext)
        {
            return LdargConverterUtilities.Apply(operand.Index, decodeContext, true);
        }
    }
}
