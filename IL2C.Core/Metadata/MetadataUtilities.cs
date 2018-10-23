using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;

using Mono.Cecil;

namespace IL2C.Metadata
{
    internal static class MetadataUtilities
    {
        public static string GetLabelName(int offset) =>
            string.Format("IL_{0:x4}", offset);

        public static string GetFriendlyName(this MemberReference member)
        {
            var declaringTypes = member.DeclaringType
                .Traverse(current => current.DeclaringType)
                .Reverse()
                .ToArray();
            var namespaceName = declaringTypes.FirstOrDefault()
                ?.Namespace
                ??(member as TypeReference)?.Namespace;

            return string.Join(
                ".",
                new[] { namespaceName }
                    .Concat(declaringTypes.Select(type => type.Name))
                    .Concat(new[] { member.Name }));
        }

        private sealed class MethodSignatureComparer : IEqualityComparer<IMethodInformation>
        {
            private MethodSignatureComparer()
            {
            }

            public bool Equals(IMethodInformation x, IMethodInformation y)
            {
                // We have to test if both parameters equal but different static/instance combination.
                // (The MethodInformation gives the "this" objref at arg0)
                if ((x.Name != y.Name) || (x.IsStatic != y.IsStatic))
                {
                    return false;
                }
                if (x.Parameters.Length != y.Parameters.Length)
                {
                    return false;
                }

                for (var index = 0; index < x.Parameters.Length; index++)
                {
                    // Instance method arg0 type ignores different type.
                    if ((index == 0) && x.HasThis)
                    {
                        continue;
                    }
                    if (!x.Parameters[index].TargetType.Equals(y.Parameters[index].TargetType))
                    {
                        return false;
                    }
                }
                return true;
            }

            public int GetHashCode(IMethodInformation obj)
            {
                return obj.Name.GetHashCode() ^ obj.IsStatic.GetHashCode() ^ obj.Parameters.Length;
            }

            public static readonly IEqualityComparer<IMethodInformation> Instance = new MethodSignatureComparer();
        }

        private static IEnumerable<IMethodInformation> StableDistinctBySignature(
            this IEnumerable<IMethodInformation> methods)
        {
            // LINQ to Object implement is stable argorithm, but not documented.
            // So, here's manually calculation.
            // return methods.Distinct(MethodSignatureComparer.Instance);
            var handled = new HashSet<IMethodInformation>(MethodSignatureComparer.Instance);
            foreach (var method in methods)
            {
                if (handled.Add(method))
                {
                    yield return method;
                }
            }
        }

        public static IDictionary<string, IMethodInformation[]> OrderByStableAllOverloads(
            this IEnumerable<IMethodInformation> methods)
        {
            // Aggregate overloads and overrides.
            var dict = new SortedDictionary<string, IMethodInformation[]>();
            foreach (var g in methods.GroupBy(method => method.Name))
            {
                var r = g.
                    Select(method => new { index = method.DeclaringType.Traverse(type => type.BaseType).Count(), method }).
                    OrderByDescending(entry => entry.index).
                    ThenBy(entry => entry.method.IsStatic ? 1 : 0).
                    ThenBy(entry => entry.method.IsReuseSlot ? 0 : 1).
                    Select(entry => entry.method).
                    StableDistinctBySignature().
                    Select((method, index) => new { index, method }).
                    OrderBy(entry => entry.index).
                    ThenBy(entry => entry.method.Parameters.Length).
                    ThenBy(entry => entry.method.IsVirtual ? 1 : 0).
                    Select(entry => entry.method).
                    ToArray();

                dict.Add(g.Key, r);
            }
            return dict;
        }
    }
}
