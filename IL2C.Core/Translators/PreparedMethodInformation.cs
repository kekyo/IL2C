using System;
using System.Collections.Generic;

using IL2C.Metadata;

namespace IL2C.Translators
{
    public sealed class PreparedMethodInformation
    {
        public readonly IMethodInformation Method;
        public readonly IVariableInformation[] Stacks;
        public readonly IReadOnlyDictionary<int, ICodeInformation> Labels;
        internal readonly IReadOnlyDictionary<int, Func<IExtractContext, string[]>> Generators;

        internal PreparedMethodInformation(
            IMethodInformation method,
            IVariableInformation[] stacks,
            IReadOnlyDictionary<int, ICodeInformation> labels,
            IReadOnlyDictionary<int, Func<IExtractContext, string[]>> generators)
        {
            this.Method = method;
            this.Stacks = stacks;
            this.Labels = labels;
            this.Generators = generators;
        }
    }
}
