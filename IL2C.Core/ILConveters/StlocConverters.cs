using System.Reflection.Emit;

namespace IL2C.ILConveters
{
    internal static class StlocConverterUtilities
    {
        public static string Apply(int localIndex, DecodeContext context)
        {
            var si = context.PopStack();
            var localType = context.Locals[localIndex].LocalType;
            if (localType.IsAssignableFrom(si.TargetType))
            {
                return string.Format(
                    "local{0} = {1}",
                    localIndex, 
                    si.SymbolName);
            }

            if (Utilities.IsNumericPrimitive(si.TargetType))
            {
                if (Utilities.IsNumericPrimitive(localType))
                {
                    return string.Format(
                        "local{0} = ({1}){2}",
                        localIndex,
                        Utilities.GetCLanguageTypeName(localType),
                        si.SymbolName);
                }
                else if (localType == typeof(bool))
                {
                    return string.Format(
                        "local{0} = {1} ? true : false",
                        localIndex,
                        si.SymbolName);
                }
            }

            throw new InvalidProgramSequenceException(
                "Invalid store operation: ILByteIndex={0}, StackType={1}, LocalType={2}, LocalIndex={3}",
                context.ILByteIndex,
                si.TargetType.FullName,
                localType.FullName,
                localIndex);
        }
    }

    internal sealed class Stloc_0Converter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Stloc_0;

        public override string Apply(DecodeContext context)
        {
            return StlocConverterUtilities.Apply(0, context);
        }
    }

    internal sealed class Stloc_1Converter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Stloc_1;

        public override string Apply(DecodeContext context)
        {
            return StlocConverterUtilities.Apply(1, context);
        }
    }

    internal sealed class Stloc_2Converter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Stloc_2;

        public override string Apply(DecodeContext context)
        {
            return StlocConverterUtilities.Apply(2, context);
        }
    }

    internal sealed class Stloc_3Converter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Stloc_3;

        public override string Apply(DecodeContext context)
        {
            return StlocConverterUtilities.Apply(3, context);
        }
    }
}
