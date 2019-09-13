/////////////////////////////////////////////////////////////////////////////////////////////////
//
// IL2C - A translator for ECMA-335 CIL/MSIL to C language.
// Copyright (c) 2016-2019 Kouji Matsui (@kozy_kekyo, @kekyo2)
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//	http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
/////////////////////////////////////////////////////////////////////////////////////////////////

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
