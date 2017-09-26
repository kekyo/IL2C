using System.Diagnostics;
using System.Reflection.Emit;

namespace IL2C.ILConveters
{
    internal sealed class Br_sConverter : ILConverter
    {
        public override OpCode OpCode => OpCodes.Br_S;

        public override object DecodeOperand(DecodeContext context)
        {
            // ShortInlineBrTarget (signed 8bit)
            var operand = (sbyte)context.FetchByte();

            // TODO: Move into Apply()
            context.TransferIndex(operand);

            return operand;
        }

        public override string Apply(object operand, DecodeContext context)
        {
            // TODO:
            Debug.Assert(((sbyte)0).Equals(operand));
            return null;
        }
    }
}
