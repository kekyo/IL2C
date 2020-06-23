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

using Mono.Cecil;

namespace IL2C.Metadata
{
    internal sealed class MemberReferenceComparer
        : IEqualityComparer<MemberReference>
        , IComparer<MemberReference>
    {
        private MemberReferenceComparer()
        {
        }

        public int Compare(MemberReference x, MemberReference y)
        {
            return object.ReferenceEquals(x, y)
                ? 0
                : StringComparer.Ordinal.Compare(x.FullName, y.FullName);
        }

        public bool Equals(MemberReference x, MemberReference y)
        {
            return object.ReferenceEquals(x, y)
                || StringComparer.Ordinal.Equals(x.FullName, y.FullName);
        }

        public int GetHashCode(MemberReference obj)
        {
            return StringComparer.Ordinal.GetHashCode(obj.FullName);
        }

        public static readonly MemberReferenceComparer Instance = new MemberReferenceComparer();
    }
}
