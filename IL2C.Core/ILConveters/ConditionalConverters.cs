using System.Reflection.Emit;

namespace IL2C.ILConveters
{
    internal sealed class CgtConverter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Cgt;

        public override string Apply(DecodeContext context)
        {
            var si1 = context.PopStack();
            var si0 = context.PopStack();

            if (Utilities.IsNumericPrimitive(si0.TargetType)
                && Utilities.IsNumericPrimitive(si1.TargetType))
            {
                var resultName = context.PushStack(typeof(bool));
                return string.Format(
                    "{0} = ({1} > {2}) ? true : false",
                    resultName,
                    si0.SymbolName,
                    si1.SymbolName);
            }

            throw new InvalidProgramSequenceException(
                "Unknown cgt operation: TargetIndex={0}, Type0={1}, Type1={2}",
                context.ILByteIndex,
                si0.TargetType.FullName,
                si1.TargetType.FullName);
        }
    }
}
