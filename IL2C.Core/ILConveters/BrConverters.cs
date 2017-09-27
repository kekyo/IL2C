using System.Diagnostics;
using System.Reflection.Emit;

namespace IL2C.ILConveters
{
    internal sealed class Br_sConverter : ILConverter
    {
        public override OpCode OpCode => OpCodes.Br_S;

        public override bool IsEndOfPath => true;

        public override object DecodeOperand(DecodeContext context)
        {
            // ShortInlineBrTarget (signed 8bit)
            var operand = (sbyte)context.FetchByte();
            return operand;
        }

        public override string Apply(object operand, DecodeContext context)
        {
            var offset = context.TargetIndex + (sbyte)operand;
            var labelName = context.EnqueueNewPath(offset);
            return string.Format("goto {0}", labelName);
        }
    }
}
