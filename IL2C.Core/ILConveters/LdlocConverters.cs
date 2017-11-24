using System;
using System.Reflection.Emit;
using IL2C.Translators;

namespace IL2C.ILConveters
{
    internal static class LdlocConverterUtilities
    {
        public static Func<IExtractContext, string[]> Apply(int localIndex, DecodeContext decodeContext)
        {
            var local = decodeContext.Locals[localIndex];
            var targetType = local.LocalType;

            if (local.LocalType == typeof(bool))
            {
                var symbolName = decodeContext.PushStack(typeof(int));
                return _ => new[] { string.Format(
                    "{0} = local{1} ? 1 : 0",
                    symbolName,
                    localIndex) };
            }
            else
            {
                if ((local.LocalType == typeof(byte))
                    || (local.LocalType == typeof(sbyte))
                    || (local.LocalType == typeof(short))
                    || (local.LocalType == typeof(ushort)))
                {
                    targetType = typeof(int);
                }

                var symbolName = decodeContext.PushStack(targetType);
                return _ => new[] { string.Format(
                    "{0} = local{1}",
                    symbolName,
                    localIndex) };
            }
        }

        public static Func<IExtractContext, string[]> ApplyWithAddress(int localIndex, DecodeContext decodeContext)
        {
            var local = decodeContext.Locals[localIndex];
            var targetType = local.LocalType;

            var managedReferenceType = targetType.MakeByRefType();
                
            var symbolName = decodeContext.PushStack(managedReferenceType);
            return _ => new[] { string.Format(
                "{0} = &local{1}",
                symbolName,
                localIndex) };
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

        public override Func<IExtractContext, string[]> Apply(byte localIndex, DecodeContext decodeContext)
        {
            if (localIndex > 225)
            {
                throw new InvalidProgramSequenceException(
                    "Index overflow at ldloca.s: ILByteIndex={0}, LocalIndex={1}",
                    decodeContext.ILByteIndex,
                    localIndex);
            }

            return LdlocConverterUtilities.ApplyWithAddress(localIndex, decodeContext);
        }
    }
}
