using System;
using Mono.Cecil.Cil;

namespace IL2C.Translators
{
    public struct PreparedILBody
    {
        public readonly Label Label;
        internal readonly Func<IExtractContext, string[]> Generator;
        public readonly SequencePoint[] SequencePoints;

        internal PreparedILBody(
            Label label,
            Func<IExtractContext, string[]> generator,
            SequencePoint[] sequencePoints)
        {
            this.Label = label;
            this.Generator = generator;
            this.SequencePoints = sequencePoints;
        }
    }
}
