////////////////////////////////////////////////////////////////////////////
//
// IL2C - A translator for ECMA-335 CIL/MSIL to C language.
// Copyright (c) Kouji Matsui (@kozy_kekyo, @kekyo@mastodon.cloud)
//
// Licensed under Apache-v2: https://opensource.org/licenses/Apache-2.0
//
////////////////////////////////////////////////////////////////////////////

using System;
using System.Diagnostics;

using Mono.Cecil.Cil;

using IL2C.Translators;

namespace IL2C.ILConverters
{
    internal sealed class ExpressionEmitContext
    {
        public readonly bool ExecutionFrameEmitted;

        public ExpressionEmitContext(
            bool executionFrameEmitted)
        {
            this.ExecutionFrameEmitted = executionFrameEmitted;
        }
    }

    internal delegate string[] ExpressionEmitter(
        IExtractContext extractContext,
        ExpressionEmitContext emitContext);

    internal abstract class ILConverter
    {
        protected static readonly string[] empty = new string[0];
        protected static readonly ExpressionEmitter emptyEmitter = (_, __) => empty;

        public abstract OpCode OpCode { get; }

        public virtual bool IsEndOfPath => false;

        public abstract ExpressionEmitter Prepare(object operand, DecodeContext decodeContext);
    }

    internal abstract class ILConverter<T> : ILConverter
    {
        public sealed override ExpressionEmitter Prepare(object operand, DecodeContext decodeContext)
        {
            Debug.Assert(operand is T);
            return this.Prepare((T)operand, decodeContext);
        }

        public abstract ExpressionEmitter Prepare(T operand, DecodeContext decodeContext);
    }
}
