using System;

using Mono.Cecil;
using Mono.Cecil.Cil;
using Mono.Cecil.Rocks;

using IL2C.Translators;

namespace IL2C.ILConveters
{
    internal static class LdlocConverterUtilities
    {
        private static Func<IExtractContext, string[]> Apply(
            string targetName, TypeReference targetType, DecodeContext decodeContext, bool isReference)
        {
            targetType = targetType.GetStackableType();
            targetType = isReference ? targetType.MakeByReferenceType() : targetType;
                
            var symbolName = decodeContext.PushStack(targetType);

            return extractContext => new[] { string.Format(
                "{0} = {1}{2}",
                symbolName,
                isReference ? "&" : string.Empty,
                targetName) };
        }

        public static Func<IExtractContext, string[]> Apply(
            int localIndex, DecodeContext decodeContext, bool isReference = false)
        {
            var local = decodeContext.Locals[localIndex];
            return Apply(local.SymbolName, local.TargetType, decodeContext, isReference);
        }

        public static Func<IExtractContext, string[]> Apply(
            VariableReference localVariable, DecodeContext decodeContext, bool isReference = false)
        {
            var local = decodeContext.Locals[localVariable.Index];
            return Apply(local.SymbolName, local.TargetType, decodeContext, isReference);
        }
    }

    internal sealed class Ldloc_0Converter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Ldloc_0;

        public override Func<IExtractContext, string[]> Apply(DecodeContext decodeContext)
        {
            return LdlocConverterUtilities.Apply(0, decodeContext);
        }
    }

    internal sealed class Ldloc_1Converter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Ldloc_1;

        public override Func<IExtractContext, string[]> Apply(DecodeContext decodeContext)
        {
            return LdlocConverterUtilities.Apply(1, decodeContext);
        }
    }

    internal sealed class Ldloc_2Converter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Ldloc_2;

        public override Func<IExtractContext, string[]> Apply(DecodeContext decodeContext)
        {
            return LdlocConverterUtilities.Apply(2, decodeContext);
        }
    }

    internal sealed class Ldloc_3Converter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Ldloc_3;

        public override Func<IExtractContext, string[]> Apply(DecodeContext decodeContext)
        {
            return LdlocConverterUtilities.Apply(3, decodeContext);
        }
    }

    internal sealed class Ldloc_SConverter : ShortInlineVarConverter
    {
        public override OpCode OpCode => OpCodes.Ldloc_S;

        public override Func<IExtractContext, string[]> Apply(
            VariableReference operand, DecodeContext decodeContext)
        {
            return LdlocConverterUtilities.Apply(operand, decodeContext);
        }
    }

    internal sealed class Ldloca_sConverter : ShortInlineVarConverter
    {
        public override OpCode OpCode => OpCodes.Ldloca_S;

        public override Func<IExtractContext, string[]> Apply(
            VariableReference operand, DecodeContext decodeContext)
        {
            return LdlocConverterUtilities.Apply(operand, decodeContext, true);
        }
    }
}
