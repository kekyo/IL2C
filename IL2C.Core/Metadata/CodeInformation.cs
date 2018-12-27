using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;

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

    public enum ExceptionCatchHandlerTypes
    {
        Catch,
        Finally
    }

    public sealed class ExceptionCatchHandler : IEquatable<ExceptionCatchHandler>
    {
        public readonly ExceptionCatchHandlerTypes CatchHandlerType;
        public readonly ITypeInformation CatchType;
        public readonly int CatchStart;
        public readonly int CatchEnd;

        public ExceptionCatchHandler(
            ExceptionCatchHandlerTypes catchHandlerType,
            ITypeInformation catchType,
            int catchStart,
            int catchEnd)
        {
            this.CatchHandlerType = catchHandlerType;
            this.CatchType = catchType;
            this.CatchStart = catchStart;
            this.CatchEnd = catchEnd;
        }

        public bool ContainsOffset(int offset) =>
            (offset >= this.CatchStart) && (offset < this.CatchEnd);

        public bool Equals(ExceptionCatchHandler other)
        {
            if (other == null)
            {
                return false;
            }

            return
                (this.CatchHandlerType == other.CatchHandlerType) &&
                (this.CatchStart == other.CatchStart) &&
                (this.CatchEnd == other.CatchEnd) &&
                (this.CatchType?.Equals(other.CatchType) ?? (other.CatchType == null));
        }

        public override bool Equals(object obj) =>
            this.Equals(obj as ExceptionCatchHandler);

        public override int GetHashCode() =>
            this.CatchHandlerType.GetHashCode() ^
                (this.CatchType?.GetHashCode() ?? 0) ^
                this.CatchStart.GetHashCode() ^
                this.CatchEnd.GetHashCode();

        public override string ToString() =>
            string.Format(
                "{0}({1}{2}-{3})",
                this.CatchHandlerType,
                (this.CatchType != null) ? (this.CatchType.MangledUniqueName + ",") : string.Empty,
                this.CatchStart,
                this.CatchEnd);
    }

    public sealed class ExceptionHandler : IEquatable<ExceptionHandler>
    {
        public readonly int TryStart;
        public readonly int TryEnd;
        public readonly ExceptionCatchHandler[] CatchHandlers;

        internal ExceptionHandler(
            int tryStart, int tryEnd, ExceptionCatchHandler[] catchHandlers)
        {
            this.TryStart = tryStart;
            this.TryEnd = tryEnd;
            this.CatchHandlers = catchHandlers;
        }

        public bool ContainsOffset(int offset) =>
            ((offset >= this.TryStart) && (offset < this.TryEnd)) ||
            this.CatchHandlers.Any(catchHandler => catchHandler.ContainsOffset(offset));

        public bool Equals(ExceptionHandler other)
        {
            if (other == null)
            {
                return false;
            }

            return
                 (this.TryStart == other.TryStart) &&
                (this.TryEnd == other.TryEnd) &&
                this.CatchHandlers.SequenceEqual(other.CatchHandlers);
        }

        public override bool Equals(object obj) =>
            this.Equals(obj as ExceptionHandler);

        public override int GetHashCode() =>
            this.CatchHandlers.Aggregate(
                this.TryStart.GetHashCode() ^ this.TryEnd.GetHashCode(),
                (s, catchHander) => s ^ catchHander.GetHashCode());

        public override string ToString() =>
            string.Format(
                "Try({0}-{1}),{2}",
                this.TryStart,
                this.TryEnd,
                string.Join(
                    ",",
                    this.CatchHandlers.AsEnumerable()));
    }

    public interface ICodeStream : IReadOnlyCollection<ICodeInformation>
    {
        bool Contains(int offset);
        bool TryGetValue(int offset, out ICodeInformation code);

        ExceptionHandler[] ExceptionHandlers { get; }
    }

    internal sealed class CodeStream
        : SortedDictionary<int, ICodeInformation>, ICodeStream
    {
        public CodeStream(ExceptionHandler[] exceptionHandlers) =>
            this.ExceptionHandlers = exceptionHandlers;

        public bool Contains(int offset) =>
            this.ContainsKey(offset);

        IEnumerator<ICodeInformation> IEnumerable<ICodeInformation>.GetEnumerator() =>
            this.Values.GetEnumerator();

        IEnumerator IEnumerable.GetEnumerator() =>
            this.Values.GetEnumerator();

        public ExceptionHandler[] ExceptionHandlers { get; }
    }
}
