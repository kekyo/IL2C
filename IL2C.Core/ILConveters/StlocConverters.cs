using System;
using System.Reflection.Emit;

using IL2C.Translators;

namespace IL2C.ILConveters
{
    internal static class StlocConverterUtilities
    {
        public static Func<IExtractContext, string[]> Apply(int localIndex, DecodeContext decodeContext)
        {
            var si = decodeContext.PopStack();
            var localType = decodeContext.Locals[localIndex].VariableType;

            var ilByteIndex = decodeContext.ILByteIndex;

            return lookupper =>
            {
                var rightExpression = lookupper.GetRightExpression(localType, si);
                if (rightExpression == null)
                {
                    throw new InvalidProgramSequenceException(
                        "Invalid store operation: ILByteIndex={0}, StackType={1}, LocalType={2}, LocalIndex={3}",
                        ilByteIndex,
                        si.TargetType.FullName,
                        localType.FullName,
                        localIndex);
                }

                return new[] { string.Format(
                    "local{0} = {1}",
                    localIndex,
                    rightExpression) };
            };
        }
    }

    internal sealed class Stloc_0Converter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Stloc_0;

        public override Func<IExtractContext, string[]> Apply(DecodeContext decodeContext)
        {
            return StlocConverterUtilities.Apply(0, decodeContext);
        }
    }

    internal sealed class Stloc_1Converter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Stloc_1;

        public override Func<IExtractContext, string[]> Apply(DecodeContext decodeContext)
        {
            return StlocConverterUtilities.Apply(1, decodeContext);
        }
    }

    internal sealed class Stloc_2Converter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Stloc_2;

        public override Func<IExtractContext, string[]> Apply(DecodeContext decodeContext)
        {
            return StlocConverterUtilities.Apply(2, decodeContext);
        }
    }

    internal sealed class Stloc_3Converter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Stloc_3;

        public override Func<IExtractContext, string[]> Apply(DecodeContext decodeContext)
        {
            return StlocConverterUtilities.Apply(3, decodeContext);
        }
    }
}
