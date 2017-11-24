using System;
using System.Diagnostics;
using System.Reflection.Emit;
using IL2C.Translators;

namespace IL2C.ILConveters
{
    internal sealed class Br_sConverter : ShortInlineBrTargetConverter
    {
        public override OpCode OpCode => OpCodes.Br_S;

        public override bool IsEndOfPath => true;

        public override Func<IExtractContext, string[]> Apply(sbyte operand, DecodeContext decodeContext)
        {
            var offset = decodeContext.ILByteIndex + operand;
            var labelName = decodeContext.EnqueueNewPath(offset);
            return _ => new[] { string.Format("goto {0}", labelName) };
        }
    }

    internal sealed class Brfalse_sConverter : ShortInlineBrTargetConverter
    {
        public override OpCode OpCode => OpCodes.Brfalse_S;

        public override Func<IExtractContext, string[]> Apply(sbyte operand, DecodeContext decodeContext)
        {
            var si = decodeContext.PopStack();

            var offset = decodeContext.ILByteIndex + operand;
            var labelName = decodeContext.EnqueueNewPath(offset);

            if (Utilities.IsNumericPrimitive(si.TargetType))
            {
                return _ => new[] { string.Format(
                    "if ({0} == 0) goto {1}",
                    si.SymbolName,
                    labelName) };
            }

            throw new InvalidOperationException();
        }
    }

    internal sealed class Brtrue_sConverter : ShortInlineBrTargetConverter
    {
        public override OpCode OpCode => OpCodes.Brtrue_S;

        public override Func<IExtractContext, string[]> Apply(sbyte operand, DecodeContext decodeContext)
        {
            var si = decodeContext.PopStack();

            var offset = decodeContext.ILByteIndex + operand;
            var labelName = decodeContext.EnqueueNewPath(offset);

            if (Utilities.IsNumericPrimitive(si.TargetType))
            {
                return _ => new[] { string.Format(
                    "if ({0} != 0) goto {1}",
                    si.SymbolName,
                    labelName) };
            }

            throw new InvalidOperationException();
        }
    }
}
