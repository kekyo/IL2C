using System.Diagnostics;
using System.Reflection.Emit;

namespace IL2C.ILConveters
{
    internal sealed class AddConverter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Add;

        public override string Apply(DecodeContext context)
        {
            var si1 = context.PopStack();
            var si0 = context.PopStack();

            // https://msdn.microsoft.com/en-us/library/system.reflection.emit.opcodes.add(v=vs.100).aspx
            if ((si0.TargetType == typeof(int)) && (si1.TargetType == typeof(int)))
            {
                var resultName = context.PushStack(typeof(int));
                return string.Format("{0} = {1} + {2}", resultName, si0.SymbolName, si1.SymbolName);
            }
            if ((si0.TargetType == typeof(long)) && (si1.TargetType == typeof(long)))
            {
                var resultName = context.PushStack(typeof(long));
                return string.Format("{0} = {1} + {2}", resultName, si0.SymbolName, si1.SymbolName);
            }

            throw new InvalidProgramSequenceException(
                "Unknown add operation: TargetIndex={0}, Type0={1}, Type1={2}",
                context.ILByteIndex,
                si0.TargetType.FullName,
                si1.TargetType.FullName);
        }
    }
}
