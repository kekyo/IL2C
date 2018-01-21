using System;

using Mono.Cecil.Cil;

namespace IL2C.Translators
{
    public struct PreparedILBody
    {
        public readonly Label Label;
        internal readonly Func<IExtractContext, string[]> Generator;
        public readonly int UniqueCodeBlockIndex;
        public readonly SequencePoint[] SequencePoints;

        private readonly OpCode opCode;   // For use debugging
        private readonly object operand;  // For use debugging
        private readonly int decodingPathNumber;  // For use debugging

        internal PreparedILBody(
            Label label,
            Func<IExtractContext, string[]> generator,
            int uniqueCodeBlockIndex,
            SequencePoint[] sequencePoints,
            OpCode opCode,
            object operand,
            int decodingPathNumber)
        {
            this.Label = label;
            this.Generator = generator;
            this.UniqueCodeBlockIndex = uniqueCodeBlockIndex;
            this.SequencePoints = sequencePoints;

            this.opCode = opCode;
            this.operand = operand;
            this.decodingPathNumber = decodingPathNumber;
        }

        private string GetOperandPrintable()
        {
            if (operand == null)
            {
                return string.Empty;
            }

            var inst = operand as Instruction;
            if (inst != null)
            {
                return string.Format(
                    " IL_{0:x4}",
                    inst.Offset);
            }

            var varRef = operand as VariableReference;
            if (varRef != null)
            {
                return string.Format(
                    " local{0}",
                    varRef.Index);
            }

            var str = operand as string;
            if (str != null)
            {
                return string.Format(
                    " \"{0}\"",
                    str);
            }

            return " " + operand;
        }

        public override string ToString()
        {
            return string.Format(
                "Path={0}, Unique={1}: IL_{2:x4}: {3}{4}",
                this.decodingPathNumber,
                this.UniqueCodeBlockIndex,
                this.Label.Offset,
                opCode,
                this.GetOperandPrintable());
        }
    }
}
