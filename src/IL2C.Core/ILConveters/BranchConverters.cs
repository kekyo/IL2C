////////////////////////////////////////////////////////////////////////////
//
// IL2C - A translator for ECMA-335 CIL/MSIL to C language.
// Copyright (c) Kouji Matsui (@kozy_kekyo, @kekyo@mastodon.cloud)
//
// Licensed under Apache-v2: https://opensource.org/licenses/Apache-2.0
//
////////////////////////////////////////////////////////////////////////////

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

        public override ExpressionEmitter Prepare(
            ICodeInformation operand, DecodeContext decodeContext)
        {
            var labelName = decodeContext.EnqueueNewPath(operand.Offset);

            return (_, __) => new[] { string.Format("goto {0}", labelName) };
        }
    }

    internal sealed class Br_sConverter : ShortInlineBrTargetConverter
    {
        public override OpCode OpCode => OpCodes.Br_S;

        public override bool IsEndOfPath => true;

        public override ExpressionEmitter Prepare(
            ICodeInformation operand, DecodeContext decodeContext)
        {
            var labelName = decodeContext.EnqueueNewPath(operand.Offset);

            return (_, __) => new[] { string.Format("goto {0}", labelName) };
        }
    }

    internal static class BranchExpressionUtilities
    {
        public static ExpressionEmitter ApplyFalse(
            ICodeInformation operand, string oper, DecodeContext decodeContext)
        {
            var si = decodeContext.PopStack();

            var labelName = decodeContext.EnqueueNewPath(operand.Offset);

            if (si.TargetType.IsBooleanType)
            {
                return (extractContext, _) => new[] { string.Format(
                    "if ({0} {1} false) goto {2}",
                    extractContext.GetSymbolName(si),
                    oper,
                    labelName) };
            }
            else if (si.TargetType.IsNumericPrimitive ||
                si.TargetType.IsEnum)
            {
                return (extractContext, _) => new[] { string.Format(
                    "if ({0} {1} 0) goto {2}",
                    extractContext.GetSymbolName(si),
                    oper,
                    labelName) };
            }
            else
            {
                return (extractContext, _) => new[] { string.Format(
                    "if ({0} {1} NULL) goto {2}",
                    extractContext.GetSymbolName(si),
                    oper,
                    labelName) };
            }
        }

        public static ExpressionEmitter ApplyBinary(
            ICodeInformation operand, string oper, DecodeContext decodeContext)
        {
            var si1 = decodeContext.PopStack();
            var si0 = decodeContext.PopStack();

            var labelName = decodeContext.EnqueueNewPath(operand.Offset);

            return (extractContext, _) => new[] { string.Format(
                "if ({0} {1} {2}) goto {3}",
                extractContext.GetSymbolName(si0),
                oper,
                extractContext.GetSymbolName(si1),
                labelName) };
        }
    }

    internal sealed class BrfalseConverter : InlineBrTargetConverter
    {
        public override OpCode OpCode => OpCodes.Brfalse;

        public override ExpressionEmitter Prepare(
            ICodeInformation operand, DecodeContext decodeContext)
        {
            return BranchExpressionUtilities.ApplyFalse(operand, "==", decodeContext);
        }
    }

    internal sealed class Brfalse_sConverter : ShortInlineBrTargetConverter
    {
        public override OpCode OpCode => OpCodes.Brfalse_S;

        public override ExpressionEmitter Prepare(
            ICodeInformation operand, DecodeContext decodeContext)
        {
            return BranchExpressionUtilities.ApplyFalse(operand, "==", decodeContext);
        }
    }

    internal sealed class BrtrueConverter : InlineBrTargetConverter
    {
        public override OpCode OpCode => OpCodes.Brtrue;

        public override ExpressionEmitter Prepare(
            ICodeInformation operand, DecodeContext decodeContext)
        {
            return BranchExpressionUtilities.ApplyFalse(operand, "!=", decodeContext);
        }
    }

    internal sealed class Brtrue_sConverter : ShortInlineBrTargetConverter
    {
        public override OpCode OpCode => OpCodes.Brtrue_S;

        public override ExpressionEmitter Prepare(
            ICodeInformation operand, DecodeContext decodeContext)
        {
            return BranchExpressionUtilities.ApplyFalse(operand, "!=", decodeContext);
        }
    }

    internal sealed class BeqConverter : ShortInlineBrTargetConverter
    {
        public override OpCode OpCode => OpCodes.Beq;

        public override ExpressionEmitter Prepare(
            ICodeInformation operand, DecodeContext decodeContext)
        {
            return BranchExpressionUtilities.ApplyBinary(operand, "==", decodeContext);
        }
    }

    internal sealed class Beq_sConverter : ShortInlineBrTargetConverter
    {
        public override OpCode OpCode => OpCodes.Beq_S;

        public override ExpressionEmitter Prepare(
            ICodeInformation operand, DecodeContext decodeContext)
        {
            return BranchExpressionUtilities.ApplyBinary(operand, "==", decodeContext);
        }
    }

    internal sealed class Bne_UnConverter : ShortInlineBrTargetConverter
    {
        public override OpCode OpCode => OpCodes.Bne_Un;

        public override ExpressionEmitter Prepare(
            ICodeInformation operand, DecodeContext decodeContext)
        {
            return BranchExpressionUtilities.ApplyBinary(operand, "!=", decodeContext);
        }
    }

    internal sealed class Bne_Un_sConverter : ShortInlineBrTargetConverter
    {
        public override OpCode OpCode => OpCodes.Bne_Un_S;

        public override ExpressionEmitter Prepare(
            ICodeInformation operand, DecodeContext decodeContext)
        {
            return BranchExpressionUtilities.ApplyBinary(operand, "!=", decodeContext);
        }
    }

    internal sealed class BltConverter : ShortInlineBrTargetConverter
    {
        public override OpCode OpCode => OpCodes.Blt;

        public override ExpressionEmitter Prepare(
            ICodeInformation operand, DecodeContext decodeContext)
        {
            return BranchExpressionUtilities.ApplyBinary(operand, "<", decodeContext);
        }
    }

    internal sealed class Blt_sConverter : ShortInlineBrTargetConverter
    {
        public override OpCode OpCode => OpCodes.Blt_S;

        public override ExpressionEmitter Prepare(
            ICodeInformation operand, DecodeContext decodeContext)
        {
            return BranchExpressionUtilities.ApplyBinary(operand, "<", decodeContext);
        }
    }

    internal sealed class BgtConverter : ShortInlineBrTargetConverter
    {
        public override OpCode OpCode => OpCodes.Bgt;

        public override ExpressionEmitter Prepare(
            ICodeInformation operand, DecodeContext decodeContext)
        {
            return BranchExpressionUtilities.ApplyBinary(operand, ">", decodeContext);
        }
    }

    internal sealed class Bgt_sConverter : ShortInlineBrTargetConverter
    {
        public override OpCode OpCode => OpCodes.Bgt_S;

        public override ExpressionEmitter Prepare(
            ICodeInformation operand, DecodeContext decodeContext)
        {
            return BranchExpressionUtilities.ApplyBinary(operand, ">", decodeContext);
        }
    }

    internal sealed class BleConverter : ShortInlineBrTargetConverter
    {
        public override OpCode OpCode => OpCodes.Ble;

        public override ExpressionEmitter Prepare(
            ICodeInformation operand, DecodeContext decodeContext)
        {
            return BranchExpressionUtilities.ApplyBinary(operand, ">", decodeContext);
        }
    }

    internal sealed class Ble_sConverter : ShortInlineBrTargetConverter
    {
        public override OpCode OpCode => OpCodes.Ble_S;

        public override ExpressionEmitter Prepare(
            ICodeInformation operand, DecodeContext decodeContext)
        {
            return BranchExpressionUtilities.ApplyBinary(operand, ">", decodeContext);
        }
    }

    internal sealed class BgeConverter : ShortInlineBrTargetConverter
    {
        public override OpCode OpCode => OpCodes.Bge;

        public override ExpressionEmitter Prepare(
            ICodeInformation operand, DecodeContext decodeContext)
        {
            return BranchExpressionUtilities.ApplyBinary(operand, ">=", decodeContext);
        }
    }

    internal sealed class Bge_sConverter : ShortInlineBrTargetConverter
    {
        public override OpCode OpCode => OpCodes.Bge_S;

        public override ExpressionEmitter Prepare(
            ICodeInformation operand, DecodeContext decodeContext)
        {
            return BranchExpressionUtilities.ApplyBinary(operand, ">=", decodeContext);
        }
    }
}
