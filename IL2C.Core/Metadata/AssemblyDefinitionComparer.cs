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
