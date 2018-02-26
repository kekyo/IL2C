using System;
using System.Collections;
using System.Collections.Generic;

using Mono.Cecil.Cil;

namespace IL2C.Metadata
{
    public sealed class DebugInformation
    {
        public readonly string Path;
        public readonly int Line;
        public readonly int Column;

        internal DebugInformation(string path, int line, int column)
        {
            this.Path = path;
            this.Line = line;
            this.Column = column;
        }
    }

    public struct CodeInformation
    {
        public readonly int Offset;
        public readonly OpCode OpCode;
        public readonly object Operand;
        public readonly int Size;
        public readonly DebugInformation[] Debug;

        internal CodeInformation(int offset, OpCode opCode, object operand, int size, DebugInformation[] debug)
        {
            this.Offset = offset;
            this.OpCode = opCode;
            this.Operand = operand;
            this.Size = size;
            this.Debug = debug;
        }

        private string GetOperandForPrintable()
        {
            if (this.Operand == null)
            {
                return string.Empty;
            }

            var inst = this.Operand as Instruction;
            if (inst != null)
            {
                return string.Format(
                    " IL_{0:x4}",
                    inst.Offset);
            }

            var varRef = this.Operand as VariableReference;
            if (varRef != null)
            {
                return string.Format(
                    " local{0}",
                    varRef.Index);
            }

            var str = this.Operand as string;
            if (str != null)
            {
                return string.Format(
                    " \"{0}\"",
                    str);
            }

            return " " + this.Operand;
        }

        public override string ToString()
        {
            return string.Format(
                "IL_{0:x4}: {1}{2}",
                this.Offset,
                this.OpCode,
                this.GetOperandForPrintable());
        }
    }

    public interface ICodeStream : IReadOnlyCollection<CodeInformation>
    {
        bool Contains(int offset);
        bool TryGetValue(int offset, out CodeInformation code);
    }

    internal sealed class CodeStream
        : SortedDictionary<int, CodeInformation>
        , ICodeStream
    {
        public CodeStream(IEnumerable<CodeInformation> codeInformations)
        {
            foreach (var codeInformation in codeInformations)
            {
                this.Add(codeInformation.Offset, codeInformation);
            }
        }

        public bool Contains(int offset)
        {
            return this.ContainsKey(offset);
        }

        IEnumerator<CodeInformation> IEnumerable<CodeInformation>.GetEnumerator()
        {
            return this.Values.GetEnumerator();
        }

        IEnumerator IEnumerable.GetEnumerator()
        {
            return this.Values.GetEnumerator();
        }
    }
}
