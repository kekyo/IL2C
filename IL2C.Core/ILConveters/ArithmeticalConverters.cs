using System.Diagnostics;
using System.Reflection.Emit;

namespace IL2C.ILConveters
{
    internal sealed class AddConverter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Add;

        public override string[] Apply(DecodeContext decodeContext)
        {
            var si1 = decodeContext.PopStack();
            var si0 = decodeContext.PopStack();

            // https://msdn.microsoft.com/en-us/library/system.reflection.emit.opcodes.add(v=vs.100).aspx
            if ((si0.TargetType == typeof(int)) && (si1.TargetType == typeof(int)))
            {
                var resultName = decodeContext.PushStack(typeof(int));
                return new[] { string.Format("{0} = {1} + {2}", resultName, si0.SymbolName, si1.SymbolName) };
            }
            if ((si0.TargetType == typeof(long)) && (si1.TargetType == typeof(long)))
            {
                var resultName = decodeContext.PushStack(typeof(long));
                return new[] { string.Format("{0} = {1} + {2}", resultName, si0.SymbolName, si1.SymbolName) };
            }

            throw new InvalidProgramSequenceException(
                "Unknown add operation: TargetIndex={0}, Type0={1}, Type1={2}",
                decodeContext.ILByteIndex,
                si0.TargetType.FullName,
                si1.TargetType.FullName);
        }
    }
}
