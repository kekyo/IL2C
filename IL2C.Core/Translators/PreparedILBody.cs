using System;

using IL2C.ILConverters;
using IL2C.Metadata;

using Mono.Cecil.Cil;

namespace IL2C.Translators
{
    public struct PreparedILBody
    {
        public readonly Label Label;
        internal readonly ExpressionEmitter Emitter;
        public readonly int UniqueCodeBlockIndex;
        public readonly ICodeInformation Code;

        private readonly int decodingPathNumber;  // For use debugging

        internal PreparedILBody(
            Label label,
            ExpressionEmitter emitter,
            int uniqueCodeBlockIndex,
            ICodeInformation code,
            int decodingPathNumber)
        {
            this.Label = label;
            this.Emitter = emitter;
            this.UniqueCodeBlockIndex = uniqueCodeBlockIndex;
            this.Code = code;

            this.decodingPathNumber = decodingPathNumber;
        }

        private string GetOperandPrintable()
        {
            if (this.Code.Operand == null)
            {
                return string.Empty;
            }

            var inst = this.Code.Operand as Instruction;
            if (inst != null)
            {
                return string.Format(
                    " IL_{0:x4}",
                    inst.Offset);
            }

            var varRef = this.Code.Operand as VariableReference;
            if (varRef != null)
            {
                return string.Format(
                    " local{0}",
                    varRef.Index);
            }

            var str = this.Code.Operand as string;
            if (str != null)
            {
                return string.Format(
                    " \"{0}\"",
                    str);
            }

            return " " + this.Code.Operand;
        }

        public override string ToString()
        {
            return string.Format(
                "Path={0}, Unique={1}: {2}",
                this.decodingPathNumber,
                this.UniqueCodeBlockIndex,
                this.Code);
        }
    }
}
