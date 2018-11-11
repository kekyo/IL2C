using System;
using System.Collections.Generic;

using IL2C.Metadata;

namespace IL2C.Translators
{
    public sealed class PreparedMethodInformation
    {
        public readonly IMethodInformation Method;
        public readonly VariableInformation[] Stacks;
        public readonly IReadOnlyDictionary<int, string> LabelNames;
        public readonly IReadOnlyDictionary<int, string> CatchExpressions;
        public readonly IReadOnlyDictionary<int, string> ContinuationLabelNames;
        internal readonly IReadOnlyDictionary<int, Func<IExtractContext, string[]>> Generators;

        internal PreparedMethodInformation(
            IMethodInformation method,
            VariableInformation[] stacks,
            IReadOnlyDictionary<int, string> labelNames,
            IReadOnlyDictionary<int, string> catchExpressions,
            IReadOnlyDictionary<int, string> continuationLabelNames,
            IReadOnlyDictionary<int, Func<IExtractContext, string[]>> generators)
        {
            this.Method = method;
            this.Stacks = stacks;
            this.LabelNames = labelNames;
            this.CatchExpressions = catchExpressions;
            this.ContinuationLabelNames = continuationLabelNames;
            this.Generators = generators;
        }
    }
}
