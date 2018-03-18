using System;
using System.Collections.Generic;

using IL2C.Metadata;

namespace IL2C.Translators
{
    public sealed class PreparedMethodInformation
    {
        public readonly IMethodInformation Method;
        public readonly VariableInformation[] Stacks;
        public readonly IReadOnlyDictionary<int, CodeInformation> Labels;
        internal readonly IReadOnlyDictionary<int, Func<IExtractContext, string[]>> Generators;

        internal PreparedMethodInformation(
            IMethodInformation method,
            VariableInformation[] stacks,
            IReadOnlyDictionary<int, CodeInformation> labels,
            IReadOnlyDictionary<int, Func<IExtractContext, string[]>> generators)
        {
            this.Method = method;
            this.Stacks = stacks;
            this.Labels = labels;
            this.Generators = generators;
        }
    }
}
