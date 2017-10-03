using System.Diagnostics;
using System.Reflection.Emit;

namespace IL2C.ILConveters
{
    internal abstract class InlineNoneConverter : ILConverter
    {
        public sealed override object DecodeOperand(DecodeContext context)
        {
            Debug.Assert(this.OpCode.OperandType == OperandType.InlineNone);
            return null;
        }

        public sealed override string Apply(object operand, DecodeContext context)
        {
            Debug.Assert(operand == null);
            return this.Apply(context);
        }

        public abstract string Apply(DecodeContext context);
    }

    internal abstract class InlineI4Converter : ILConverter<int>
    {
        public sealed override object DecodeOperand(DecodeContext context)
        {
            Debug.Assert(this.OpCode.OperandType == OperandType.InlineI);
            return context.FetchInt32();
        }
    }

    internal abstract class InlineI8Converter : ILConverter<long>
    {
        public sealed override object DecodeOperand(DecodeContext context)
        {
            Debug.Assert(this.OpCode.OperandType == OperandType.InlineI8);
            return context.FetchInt64();
        }
    }

    internal abstract class InlineMethodConverter : ILConverter<int>
    {
        public sealed override object DecodeOperand(DecodeContext context)
        {
            Debug.Assert(this.OpCode.OperandType == OperandType.InlineMethod);
            return context.FetchInt32();
        }
    }

    internal abstract class InlineFieldConverter : ILConverter<int>
    {
        public sealed override object DecodeOperand(DecodeContext context)
        {
            Debug.Assert(this.OpCode.OperandType == OperandType.InlineField);
            return context.FetchInt32();
        }
    }

    internal abstract class ShortInlineBrTargetConverter : ILConverter<sbyte>
    {
        public sealed override object DecodeOperand(DecodeContext context)
        {
            Debug.Assert(this.OpCode.OperandType == OperandType.ShortInlineBrTarget);
            return context.FetchSByte();
        }
    }

    internal abstract class ShortInlineI1Converter : ILConverter<sbyte>
    {
        public sealed override object DecodeOperand(DecodeContext context)
        {
            Debug.Assert(this.OpCode.OperandType == OperandType.ShortInlineI);
            return context.FetchSByte();
        }
    }
}
