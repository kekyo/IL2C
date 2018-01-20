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

        internal PreparedILBody(
            Label label,
            Func<IExtractContext, string[]> generator,
            int uniqueCodeBlockIndex,
            SequencePoint[] sequencePoints)
        {
            this.Label = label;
            this.Generator = generator;
            this.UniqueCodeBlockIndex = uniqueCodeBlockIndex;
            this.SequencePoints = sequencePoints;
        }
    }
}
