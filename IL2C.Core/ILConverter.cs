using System.Diagnostics;
using System.Reflection.Emit;

namespace IL2C
{
    internal abstract class ILConverter
    {
        public abstract OpCode OpCode { get; }

        public virtual bool IsEndOfPath => false;

        public abstract object DecodeOperand(DecodeContext context);

        public abstract string Apply(object operand, DecodeContext context);
    }

    internal abstract class ILConverter<T> : ILConverter
    {
        public sealed override string Apply(object operand, DecodeContext context)
        {
            Debug.Assert(operand is T);
            return this.Apply((T)operand, context);
        }

        public abstract string Apply(T operand, DecodeContext context);
    }
}
