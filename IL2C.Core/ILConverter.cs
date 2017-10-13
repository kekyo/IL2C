using System.Diagnostics;
using System.Reflection.Emit;

namespace IL2C
{
    internal abstract class ILConverter
    {
        public abstract OpCode OpCode { get; }

        public virtual bool IsEndOfPath => false;

        public abstract object DecodeOperand(DecodeContext decodeContext);

        public abstract string Apply(object operand, DecodeContext decodeContext);
    }

    internal abstract class ILConverter<T> : ILConverter
    {
        public sealed override string Apply(object operand, DecodeContext decodeContext)
        {
            Debug.Assert(operand is T);
            return this.Apply((T)operand, decodeContext);
        }

        public abstract string Apply(T operand, DecodeContext decodeContext);
    }
}
