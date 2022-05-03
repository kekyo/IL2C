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
using System.Linq;

using IL2C.Metadata;

namespace IL2C.Translators
{
    public sealed class PreparedInformations
    {
        internal readonly ITypeInformation[] Types;
        internal readonly IReadOnlyDictionary<IMethodInformation, PreparedMethodInformation> Functions;

        internal PreparedInformations(
            ITypeInformation[] types,
            IReadOnlyDictionary<IMethodInformation, PreparedMethodInformation> functions)
        {
            this.Types = types;
            this.Functions = functions;
        }

        public int Count => this.Functions.Count;

        public bool TryGet(string methodName, out PreparedMethodInformation preparedFunction)
        {
            preparedFunction = this.Functions
                .Where(entry => entry.Key.UniqueName == methodName)
                .Select(entry => entry.Value)
                .FirstOrDefault();
            return preparedFunction != null;
        }
    }
}
