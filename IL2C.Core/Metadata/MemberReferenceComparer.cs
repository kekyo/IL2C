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
