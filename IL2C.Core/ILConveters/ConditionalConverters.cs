using System;
using System.Reflection.Emit;
using IL2C.Translators;

namespace IL2C.ILConveters
{
    internal sealed class CgtConverter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Cgt;

        public override Func<IExtractContext, string[]> Apply(DecodeContext decodeContext)
        {
            var si1 = decodeContext.PopStack();
            var si0 = decodeContext.PopStack();

            if (Utilities.IsNumericPrimitive(si0.TargetType)
                && Utilities.IsNumericPrimitive(si1.TargetType))
            {
                var resultName = decodeContext.PushStack(typeof(int));
                return _ => new[] { string.Format(
                    "{0} = ({1} > {2}) ? 1 : 0",
                    resultName,
                    si0.SymbolName,
                    si1.SymbolName) };
            }

            throw new InvalidProgramSequenceException(
                "Unknown cgt operation: ILByteIndex={0}, Type0={1}, Type1={2}",
                decodeContext.ILByteIndex,
                si0.TargetType.FullName,
                si1.TargetType.FullName);
        }
    }
}
