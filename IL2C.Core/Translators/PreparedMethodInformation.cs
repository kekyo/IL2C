using System;
using System.Collections.Generic;

using IL2C.Metadata;

namespace IL2C.Translators
{
    public sealed class PreparedMethodInformation
    {
        public readonly IMethodInformation Method;
        public readonly IVariableInformation[] Stacks;
        public readonly IReadOnlyDictionary<int, string> LabelNames;
        internal readonly IReadOnlyDictionary<int, Func<IExtractContext, string[]>> Generators;

        internal PreparedMethodInformation(
            IMethodInformation method,
            IVariableInformation[] stacks,
            IReadOnlyDictionary<int, string> labelNames,
            IReadOnlyDictionary<int, Func<IExtractContext, string[]>> generators)
        {
            this.Method = method;
            this.Stacks = stacks;
            this.LabelNames = labelNames;
            this.Generators = generators;
        }
    }
}
