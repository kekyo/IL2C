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
    internal sealed class AssemblyDefinitionComparer
        : IEqualityComparer<AssemblyDefinition>
        , IComparer<AssemblyDefinition>
    {
        private AssemblyDefinitionComparer()
        {
        }

        public int Compare(AssemblyDefinition x, AssemblyDefinition y)
        {
            return object.ReferenceEquals(x, y)
                ? 0
                : StringComparer.Ordinal.Compare(x.FullName, y.FullName);
        }

        public bool Equals(AssemblyDefinition x, AssemblyDefinition y)
        {
            return object.ReferenceEquals(x, y)
                || StringComparer.Ordinal.Equals(x.FullName, y.FullName);
        }

        public int GetHashCode(AssemblyDefinition obj)
        {
            return StringComparer.Ordinal.GetHashCode(obj.FullName);
        }

        public static readonly AssemblyDefinitionComparer Instance = new AssemblyDefinitionComparer();
    }
}
