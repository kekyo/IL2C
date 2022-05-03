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

using Mono.Cecil;

namespace IL2C.Metadata
{
    internal sealed class ModuleReferenceComparer
        : IEqualityComparer<ModuleReference>
        , IComparer<ModuleReference>
    {
        private ModuleReferenceComparer()
        {
        }

        public int Compare(ModuleReference x, ModuleReference y)
        {
            return object.ReferenceEquals(x, y)
                ? 0
                : StringComparer.Ordinal.Compare(x.Name, y.Name);
        }

        public bool Equals(ModuleReference x, ModuleReference y)
        {
            return object.ReferenceEquals(x, y)
                || StringComparer.Ordinal.Equals(x.Name, y.Name);
        }

        public int GetHashCode(ModuleReference obj)
        {
            return StringComparer.Ordinal.GetHashCode(obj.Name);
        }

        public static readonly ModuleReferenceComparer Instance = new ModuleReferenceComparer();
    }
}
