using System;

namespace IL2C.Translators
{
    public struct PreparedILBody
    {
        public readonly Label Label;
        internal readonly Func<IExtractContext, string[]> Generator;

        internal PreparedILBody(Label label, Func<IExtractContext, string[]> generator)
        {
            this.Label = label;
            this.Generator = generator;
        }
    }
}
