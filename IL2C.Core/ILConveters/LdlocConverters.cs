using System;

using Mono.Cecil.Cil;
using Mono.Cecil.Rocks;

using IL2C.Translators;

namespace IL2C.ILConveters
{
    internal static class LdlocConverterUtilities
    {
        public static Func<IExtractContext, string[]> Apply(
            int localIndex, DecodeContext decodeContext)
        {
            var local = decodeContext.Locals[localIndex];
            var targetType = local.VariableType;

            if (targetType.IsBooleanType())
            {
                var symbolName = decodeContext.PushStack(decodeContext.Module.GetSafeInt32Type());
                return _ => new[] { string.Format(
                    "{0} = local{1} ? 1 : 0",
                    symbolName,
                    localIndex) };
            }
            else
            {
                targetType = targetType.GetStackableType();
                var symbolName = decodeContext.PushStack(targetType);
                return _ => new[] { string.Format(
                    "{0} = local{1}",
                    symbolName,
                    localIndex) };
            }
        }

        public static Func<IExtractContext, string[]> Apply(
            VariableReference local, DecodeContext decodeContext)
        {
            var targetType = local.VariableType;
            var managedReferenceType = targetType.MakeByReferenceType();
                
            var symbolName = decodeContext.PushStack(managedReferenceType);
            return _ => new[] { string.Format(
                "{0} = &local{1}",
                symbolName,
                local.Index) };
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

    internal sealed class Ldloca_sConverter : ShortInlineVarConverter
    {
        public override OpCode OpCode => OpCodes.Ldloca_S;

        public override Func<IExtractContext, string[]> Apply(
            VariableReference operand, DecodeContext decodeContext)
        {
            return LdlocConverterUtilities.Apply(operand, decodeContext);
        }
    }
}
