using System.Reflection.Emit;

namespace IL2C.ILConveters
{
    internal static class LdlocConverterUtilities
    {
        public static string Apply(int localIndex, DecodeContext context)
        {
            var local = context.Locals[localIndex];
            var targetType = local.LocalType;

            if (local.LocalType == typeof(bool))
            {
                var symbolName = context.PushStack(typeof(int));
                return string.Format(
                    "{0} = local{1} ? 1 : 0",
                    symbolName,
                    localIndex);
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

                var symbolName = context.PushStack(targetType);
                return string.Format(
                    "{0} = local{1}",
                    symbolName,
                    localIndex);
            }
        }

        public static string ApplyWithAddress(int localIndex, DecodeContext context)
        {
            var local = context.Locals[localIndex];
            var targetType = local.LocalType;

            var managedReferenceType = targetType.MakeByRefType();
                
            var symbolName = context.PushStack(managedReferenceType);
            return string.Format(
                "{0} = &local{1}",
                symbolName,
                localIndex);
        }
    }

    internal sealed class Ldloc_0Converter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Ldloc_0;

        public override string Apply(DecodeContext context)
        {
            return LdlocConverterUtilities.Apply(0, context);
        }
    }

    internal sealed class Ldloc_1Converter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Ldloc_1;

        public override string Apply(DecodeContext context)
        {
            return LdlocConverterUtilities.Apply(1, context);
        }
    }

    internal sealed class Ldloc_2Converter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Ldloc_2;

        public override string Apply(DecodeContext context)
        {
            return LdlocConverterUtilities.Apply(2, context);
        }
    }

    internal sealed class Ldloc_3Converter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Ldloc_3;

        public override string Apply(DecodeContext context)
        {
            return LdlocConverterUtilities.Apply(3, context);
        }
    }

    internal sealed class Ldloca_sConverter : ShortInlineVarConverter
    {
        public override OpCode OpCode => OpCodes.Ldloca_S;

        public override string Apply(byte localIndex, DecodeContext context)
        {
            if (localIndex > 225)
            {
                throw new InvalidProgramSequenceException(
                    "Index overflow at ldloca.s: ILByteIndex={0}, LocalIndex={1}",
                    context.ILByteIndex,
                    localIndex);
            }

            return LdlocConverterUtilities.ApplyWithAddress(localIndex, context);
        }
    }
}
