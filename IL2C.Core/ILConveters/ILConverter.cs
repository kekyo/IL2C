/////////////////////////////////////////////////////////////////////////////////////////////////
//
// IL2C - A translator for ECMA-335 CIL/MSIL to C language.
// Copyright (c) 2016-2019 Kouji Matsui (@kozy_kekyo, @kekyo2)
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//	http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
/////////////////////////////////////////////////////////////////////////////////////////////////

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
