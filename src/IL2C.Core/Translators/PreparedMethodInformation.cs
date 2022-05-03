////////////////////////////////////////////////////////////////////////////
//
// IL2C - A translator for ECMA-335 CIL/MSIL to C language.
// Copyright (c) Kouji Matsui (@kozy_kekyo, @kekyo@mastodon.cloud)
//
// Licensed under Apache-v2: https://opensource.org/licenses/Apache-2.0
//
////////////////////////////////////////////////////////////////////////////

using System;
using System.Collections.Generic;

using IL2C.ILConverters;
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
        internal readonly IReadOnlyDictionary<int, ExpressionEmitter> Emitters;

        internal PreparedMethodInformation(
            IMethodInformation method,
            ILocalVariableInformation[] stacks,
            IReadOnlyDictionary<int, string> labelNames,
            IReadOnlyDictionary<int, ILocalVariableInformation> catchVariables,
            IReadOnlyDictionary<int, (ISet<int> fromOffsets, int targetOffset)> leaveContinuations,
            IReadOnlyDictionary<int, ExpressionEmitter> emitters)
        {
            this.Method = method;
            this.Stacks = stacks;
            this.LabelNames = labelNames;
            this.CatchVariables = catchVariables;
            this.LeaveContinuations = leaveContinuations;
            this.Emitters = emitters;
        }
    }
}
