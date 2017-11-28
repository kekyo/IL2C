using System;
using System.Diagnostics;

using Mono.Cecil.Cil;

using IL2C.Translators;

namespace IL2C.ILConveters
{
    internal abstract class ILConverter
    {
        public abstract OpCode OpCode { get; }

        public virtual bool IsEndOfPath => false;

        public abstract Func<IExtractContext, string[]> Apply(object operand, DecodeContext decodeContext);
    }

    internal abstract class ILConverter<T> : ILConverter
    {
        public sealed override Func<IExtractContext, string[]> Apply(object operand, DecodeContext decodeContext)
        {
            Debug.Assert(operand is T);
            return this.Apply((T)operand, decodeContext);
        }

        public abstract Func<IExtractContext, string[]> Apply(T operand, DecodeContext decodeContext);
    }
}
