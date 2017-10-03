using System.Diagnostics;
using System.Reflection.Emit;

namespace IL2C.ILConveters
{
    internal sealed class NopConverter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Nop;

        public override string Apply(DecodeContext context)
        {
            return null;
        }
    }

    internal sealed class RetConverter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Ret;

        public override bool IsEndOfPath => true;

        public override string Apply(DecodeContext context)
        {
            var si = context.PopStack();
            var returnType = context.ReturnType;

            var rightExpression = Utilities.GetRightExpression(returnType, si);
            if (rightExpression == null)
            {
                throw new InvalidProgramSequenceException(
                    "Invalid return operation: ILByteIndex={0}, StackType={1}, ReturnType={2}",
                    context.ILByteIndex,
                    si.TargetType.FullName,
                    returnType.FullName);
            }

            return string.Format(
                "return {0}",
                rightExpression);
        }
    }
}
