using System;

using Mono.Cecil.Cil;

using IL2C.Metadata;
using IL2C.Translators;

namespace IL2C.ILConverters
{
    internal sealed class BrConverter : InlineBrTargetConverter
    {
        public override OpCode OpCode => OpCodes.Br;

        public override bool IsEndOfPath => true;

        public override Func<IExtractContext, string[]> Apply(
            ICodeInformation operand, DecodeContext decodeContext)
        {
            var labelName = decodeContext.EnqueueNewPath(operand.Offset);

            return _ => new[] { string.Format("goto {0}", labelName) };
        }
    }

    internal sealed class Br_sConverter : ShortInlineBrTargetConverter
    {
        public override OpCode OpCode => OpCodes.Br_S;

        public override bool IsEndOfPath => true;

        public override Func<IExtractContext, string[]> Apply(
            ICodeInformation operand, DecodeContext decodeContext)
        {
            var labelName = decodeContext.EnqueueNewPath(operand.Offset);

            return _ => new[] { string.Format("goto {0}", labelName) };
        }
    }

    internal sealed class BrfalseConverter : InlineBrTargetConverter
    {
        public override OpCode OpCode => OpCodes.Brfalse;

        public override Func<IExtractContext, string[]> Apply(
            ICodeInformation operand, DecodeContext decodeContext)
        {
            var si = decodeContext.PopStack();

            var labelName = decodeContext.EnqueueNewPath(operand.Offset);

            if (si.TargetType.IsBooleanType)
            {
                return extractContext => new[] { string.Format(
                    "if (!({0})) goto {1}",
                    extractContext.GetSymbolName(si),
                    labelName) };
            }
            else if (si.TargetType.IsNumericPrimitive)
            {
                return extractContext => new[] { string.Format(
                    "if ({0} == 0) goto {1}",
                    extractContext.GetSymbolName(si),
                    labelName) };
            }
            else
            {
                return extractContext => new[] { string.Format(
                    "if ({0} == NULL) goto {1}",
                    extractContext.GetSymbolName(si),
                    labelName) };
            }
        }
    }

    internal sealed class Brfalse_sConverter : ShortInlineBrTargetConverter
    {
        public override OpCode OpCode => OpCodes.Brfalse_S;

        public override Func<IExtractContext, string[]> Apply(
            ICodeInformation operand, DecodeContext decodeContext)
        {
            var si = decodeContext.PopStack();

            var labelName = decodeContext.EnqueueNewPath(operand.Offset);

            if (si.TargetType.IsBooleanType)
            {
                return extractContext => new[] { string.Format(
                    "if (!({0})) goto {1}",
                    extractContext.GetSymbolName(si),
                    labelName) };
            }
            else if (si.TargetType.IsNumericPrimitive)
            {
                return extractContext => new[] { string.Format(
                    "if ({0} == 0) goto {1}",
                    extractContext.GetSymbolName(si),
                    labelName) };
            }
            else
            {
                return extractContext => new[] { string.Format(
                    "if ({0} == NULL) goto {1}",
                    extractContext.GetSymbolName(si),
                    labelName) };
            }
        }
    }

    internal sealed class BrtrueConverter : InlineBrTargetConverter
    {
        public override OpCode OpCode => OpCodes.Brtrue;

        public override Func<IExtractContext, string[]> Apply(
            ICodeInformation operand, DecodeContext decodeContext)
        {
            var si = decodeContext.PopStack();

            var labelName = decodeContext.EnqueueNewPath(operand.Offset);

            if (si.TargetType.IsBooleanType)
            {
                return extractContext => new[] { string.Format(
                    "if ({0}) goto {1}",
                    extractContext.GetSymbolName(si),
                    labelName) };
            }
            else if (si.TargetType.IsNumericPrimitive)
            {
                return extractContext => new[] { string.Format(
                    "if ({0} != 0) goto {1}",
                    extractContext.GetSymbolName(si),
                    labelName) };
            }
            else
            {
                return extractContext => new[] { string.Format(
                    "if ({0} != NULL) goto {1}",
                    extractContext.GetSymbolName(si),
                    labelName) };
            }
        }
    }

    internal sealed class Brtrue_sConverter : ShortInlineBrTargetConverter
    {
        public override OpCode OpCode => OpCodes.Brtrue_S;

        public override Func<IExtractContext, string[]> Apply(
            ICodeInformation operand, DecodeContext decodeContext)
        {
            var si = decodeContext.PopStack();

            var labelName = decodeContext.EnqueueNewPath(operand.Offset);

            if (si.TargetType.IsBooleanType)
            {
                return extractContext => new[] { string.Format(
                    "if ({0}) goto {1}",
                    extractContext.GetSymbolName(si),
                    labelName) };
            }
            else if (si.TargetType.IsNumericPrimitive)
            {
                return extractContext => new[] { string.Format(
                    "if ({0} != 0) goto {1}",
                    extractContext.GetSymbolName(si),
                    labelName) };
            }
            else
            {
                return extractContext => new[] { string.Format(
                    "if ({0} != NULL) goto {1}",
                    extractContext.GetSymbolName(si),
                    labelName) };
            }
        }
    }

    internal sealed class Beq_sConverter : ShortInlineBrTargetConverter
    {
        public override OpCode OpCode => OpCodes.Beq_S;

        public override Func<IExtractContext, string[]> Apply(
            ICodeInformation operand, DecodeContext decodeContext)
        {
            var si1 = decodeContext.PopStack();
            var si0 = decodeContext.PopStack();

            var labelName = decodeContext.EnqueueNewPath(operand.Offset);

            return extractContext => new[] { string.Format(
                "if ({0} == {1}) goto {2}",
                extractContext.GetSymbolName(si0),
                extractContext.GetSymbolName(si1),
                labelName) };
        }
    }

    internal sealed class Blt_sConverter : ShortInlineBrTargetConverter
    {
        public override OpCode OpCode => OpCodes.Blt_S;

        public override Func<IExtractContext, string[]> Apply(
            ICodeInformation operand, DecodeContext decodeContext)
        {
            var si1 = decodeContext.PopStack();
            var si0 = decodeContext.PopStack();

            var labelName = decodeContext.EnqueueNewPath(operand.Offset);

            return extractContext => new[] { string.Format(
                "if ({0} < {1}) goto {2}",
                extractContext.GetSymbolName(si0),
                extractContext.GetSymbolName(si1),
                labelName) };
        }
    }

    internal sealed class Bne_Un_sConverter : ShortInlineBrTargetConverter
    {
        public override OpCode OpCode => OpCodes.Bne_Un_S;

        public override Func<IExtractContext, string[]> Apply(
            ICodeInformation operand, DecodeContext decodeContext)
        {
            var si1 = decodeContext.PopStack();
            var si0 = decodeContext.PopStack();

            var labelName = decodeContext.EnqueueNewPath(operand.Offset);

            return extractContext => new[] { string.Format(
                "if ({0} != {1}) goto {2}",
                extractContext.GetSymbolName(si0),
                extractContext.GetSymbolName(si1),
                labelName) };
        }
    }
}
