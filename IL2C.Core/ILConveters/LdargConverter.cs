using System;

using Mono.Cecil;
using Mono.Cecil.Cil;

using IL2C.Translators;
using IL2C.Metadata;

namespace IL2C.ILConveters
{
    internal static class LdargConverterUtilities
    {
        public static Func<IExtractContext, string[]> Apply(int parameterIndex, DecodeContext decodeContext)
        {
            var parameter = decodeContext.Method.Parameters[parameterIndex];
            var targetType = parameter.TargetType.StackableType;
            var symbolName = decodeContext.PushStack(targetType);

            return extractContext => new[] { string.Format(
                "{0} = {1}",
                symbolName,
                extractContext.GetRightExpression(targetType, parameter.TargetType, parameter.SymbolName)) };
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

    internal sealed class Ldarg_3Converter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Ldarg_3;

        public override Func<IExtractContext, string[]> Apply(DecodeContext decodeContext)
        {
            return LdargConverterUtilities.Apply(3, decodeContext);
        }
    }

    internal sealed class Ldarg_sConverter : ShortInlineParamConverter
    {
        public override OpCode OpCode => OpCodes.Ldarg_S;

        public override Func<IExtractContext, string[]> Apply(
            IVariableInformation operand, DecodeContext decodeContext)
        {
            var index = operand.DeclaredMethod.HasThis ? (operand.Index + 1) : operand.Index;
            return LdargConverterUtilities.Apply(index, decodeContext);
        }
    }
}
