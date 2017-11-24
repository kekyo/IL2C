using System;
using System.Diagnostics;
using System.Reflection.Emit;
using IL2C.Translators;

namespace IL2C.ILConveters
{
    internal abstract class InlineNoneConverter : ILConverter
    {
        public sealed override object DecodeOperand(DecodeContext decodeContext)
        {
            Debug.Assert(this.OpCode.OperandType == OperandType.InlineNone);
            return null;
        }

        public sealed override Func<IExtractContext, string[]> Apply(object operand, DecodeContext decodeContext)
        {
            Debug.Assert(operand == null);
            return this.Apply(decodeContext);
        }

        public abstract Func<IExtractContext, string[]> Apply(DecodeContext decodeContext);
    }

    internal abstract class InlineI4Converter : ILConverter<int>
    {
        public sealed override object DecodeOperand(DecodeContext decodeContext)
        {
            Debug.Assert(this.OpCode.OperandType == OperandType.InlineI);
            return decodeContext.FetchInt32();
        }
    }

    internal abstract class InlineI8Converter : ILConverter<long>
    {
        public sealed override object DecodeOperand(DecodeContext decodeContext)
        {
            Debug.Assert(this.OpCode.OperandType == OperandType.InlineI8);
            return decodeContext.FetchInt64();
        }
    }

    internal abstract class InlineMethodConverter : ILConverter<int>
    {
        public sealed override object DecodeOperand(DecodeContext decodeContext)
        {
            Debug.Assert(this.OpCode.OperandType == OperandType.InlineMethod);
            return decodeContext.FetchInt32();
        }
    }

    internal abstract class InlineFieldConverter : ILConverter<int>
    {
        public sealed override object DecodeOperand(DecodeContext decodeContext)
        {
            Debug.Assert(this.OpCode.OperandType == OperandType.InlineField);
            return decodeContext.FetchInt32();
        }
    }

    internal abstract class InlineTypeConverter : ILConverter<int>
    {
        public sealed override object DecodeOperand(DecodeContext decodeContext)
        {
            Debug.Assert(this.OpCode.OperandType == OperandType.InlineType);
            return decodeContext.FetchInt32();
        }
    }

    internal abstract class ShortInlineBrTargetConverter : ILConverter<sbyte>
    {
        public sealed override object DecodeOperand(DecodeContext decodeContext)
        {
            Debug.Assert(this.OpCode.OperandType == OperandType.ShortInlineBrTarget);
            return decodeContext.FetchSByte();
        }
    }

    internal abstract class ShortInlineI1Converter : ILConverter<sbyte>
    {
        public sealed override object DecodeOperand(DecodeContext decodeContext)
        {
            Debug.Assert(this.OpCode.OperandType == OperandType.ShortInlineI);
            return decodeContext.FetchSByte();
        }
    }

    internal abstract class ShortInlineVarConverter : ILConverter<byte>
    {
        public sealed override object DecodeOperand(DecodeContext decodeContext)
        {
            Debug.Assert(this.OpCode.OperandType == OperandType.ShortInlineVar);
            return decodeContext.FetchByte();
        }
    }
}
