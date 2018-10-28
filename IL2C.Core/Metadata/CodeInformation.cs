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

    public interface ICodeInformation
    {
        IMethodInformation Method { get; }
        int Offset { get; }
        OpCode OpCode { get; }
        object Operand { get; }
        int Size { get; }
        string Label { get; }
        DebugInformation[] Debug { get; }

        // For debugging friendly string
        string RawLocation { get; }
    }

    internal sealed class CodeInformation
        : ICodeInformation, IOperandPrintable
    {
        private readonly object operand;
        private readonly Func<object, object> translateOperand;

        public CodeInformation(
            MethodInformation method,
            int offset,
            OpCode opCode,
            object operand,
            int size,
            DebugInformation[] debug,
            Func<object, object> translateOperand)
        {
            this.Method = method;
            this.Offset = offset;
            this.OpCode = opCode;
            this.Size = size;
            this.Debug = debug;
            this.operand = operand;
            this.translateOperand = translateOperand;
        }

        public IMethodInformation Method { get; }
        public int Offset { get; }
        public OpCode OpCode { get; }
        public int Size { get; }
        public string Label => MetadataUtilities.GetLabelName(this.Offset);
        public DebugInformation[] Debug { get; }

        public object Operand => translateOperand(operand);

        private string GetOperandForPrintable()
        {
            var printable = this.Operand as IOperandPrintable;
            if (printable != null)
            {
                return printable.PrintableString;
            }

            var str = this.Operand as string;
            if (str != null)
            {
                return string.Format(
                    "\"{0}\"",
                    str);
            }

            // Single type format issue: https://docs.microsoft.com/en-us/dotnet/api/system.single.tostring
            if (this.Operand is float)
            {
                return string.Format(
                    "{0:g9}f",
                    this.Operand);
            }

            // Double type format issue: https://docs.microsoft.com/en-us/dotnet/api/system.double.tostring
            if (this.Operand is double)
            {
                return string.Format(
                    "{0:g17}",
                    this.Operand);
            }

            return this.Operand?.ToString() ?? string.Empty;
        }

        public override string ToString() =>
            string.Format(
                "{0}: {1} {2}",
                this.Label,
                this.OpCode,
                this.GetOperandForPrintable());

        string IOperandPrintable.PrintableString => this.Label;

        public string RawLocation =>
            string.Format(
                "{0}:{1}",
                this.Method.FriendlyName,
                this.Label);
    }

    public interface ICodeStream : IReadOnlyCollection<ICodeInformation>
    {
        bool Contains(int offset);
        bool TryGetValue(int offset, out ICodeInformation code);
    }

    internal sealed class CodeStream
        : SortedDictionary<int, ICodeInformation>, ICodeStream
    {
        public CodeStream()
        {
        }

        public bool Contains(int offset)
        {
            return this.ContainsKey(offset);
        }

        IEnumerator<ICodeInformation> IEnumerable<ICodeInformation>.GetEnumerator()
        {
            return this.Values.GetEnumerator();
        }

        IEnumerator IEnumerable.GetEnumerator()
        {
            return this.Values.GetEnumerator();
        }
    }
}
