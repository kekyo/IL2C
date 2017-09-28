using System;
using System.Diagnostics;
using System.Reflection.Emit;

namespace IL2C.ILConveters
{
    internal sealed class Br_sConverter : ShortInlineBrTargetConverter
    {
        public override OpCode OpCode => OpCodes.Br_S;

        public override bool IsEndOfPath => true;

        public override string Apply(sbyte operand, DecodeContext context)
        {
            var offset = context.ILByteIndex + operand;
            var labelName = context.EnqueueNewPath(offset);
            return string.Format("goto {0}", labelName);
        }
    }

    internal sealed class Brfalse_sConverter : ShortInlineBrTargetConverter
    {
        public override OpCode OpCode => OpCodes.Brfalse_S;

        public override string Apply(sbyte operand, DecodeContext context)
        {
            var si = context.PopStack();

            var offset = context.ILByteIndex + operand;
            var labelName = context.EnqueueNewPath(offset);

            if (Utilities.IsNumericPrimitive(si.TargetType))
            {
                return string.Format(
                    "if ({0} == 0) goto {1}",
                    si.SymbolName,
                    labelName);
            }

            throw new InvalidOperationException();
        }
    }
}
