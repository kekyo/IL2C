using System;
using System.Collections.Generic;

using IL2C.Metadata;

namespace IL2C.Translators
{
    public sealed class PreparedMethodInformation
    {
        public readonly IMethodInformation Method;
        public readonly ILocalVariableInformation[] Stacks;
        public readonly IReadOnlyDictionary<int, string> LabelNames;
        public readonly IReadOnlyDictionary<int, ILocalVariableInformation> CatchVariables;
        public readonly IReadOnlyDictionary<int, (ISet<int> fromOffsets, int targetOffset)> LeaveContinuations;
        internal readonly IReadOnlyDictionary<int, Func<IExtractContext, string[]>> Generators;

        internal PreparedMethodInformation(
            IMethodInformation method,
            ILocalVariableInformation[] stacks,
            IReadOnlyDictionary<int, string> labelNames,
            IReadOnlyDictionary<int, ILocalVariableInformation> catchVariables,
            IReadOnlyDictionary<int, (ISet<int> fromOffsets, int targetOffset)> leaveContinuations,
            IReadOnlyDictionary<int, Func<IExtractContext, string[]>> generators)
        {
            this.Method = method;
            this.Stacks = stacks;
            this.LabelNames = labelNames;
            this.CatchVariables = catchVariables;
            this.LeaveContinuations = leaveContinuations;
            this.Generators = generators;
        }
    }
}
