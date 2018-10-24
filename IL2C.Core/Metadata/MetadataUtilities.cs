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

        private sealed class MethodSignatureComparer : IComparer<IMethodInformation>
        {
            // This is a overload stablizer

            private MethodSignatureComparer()
            {
            }

            private static int Compare(ITypeInformation x, ITypeInformation y)
            {
                var xr = x.IsAssignableFrom(y);
                var yr = y.IsAssignableFrom(x);

                if (!xr && xr)
                {
                    return -1;
                }
                if (xr && !yr)
                {
                    return 1;
                }
                if (xr && yr)
                {
                    return 0;
                }

                if (!x.IsByReference && y.IsByReference)
                {
                    return Compare(x.ElementType, y);
                }
                if (x.IsByReference && !y.IsByReference)
                {
                    return Compare(x, y.ElementType);
                }
                if (x.IsByReference && y.IsByReference)
                {
                    return Compare(x.ElementType, y.ElementType);
                }

                if (x.IsPrimitive)
                {
                    return -1;
                }
                if (y.IsPrimitive)
                {
                    return 1;
                }
                if (x.IsValueType)
                {
                    return -1;
                }
                if (y.IsValueType)
                {
                    return 1;
                }

                if (x.IsClass)
                {
                    return -1;
                }
                if (y.IsClass)
                {
                    return 1;
                }
                if (x.IsInterface)
                {
                    return -1;
                }
                if (y.IsInterface)
                {
                    return 1;
                }
                if (x.IsArray)
                {
                    return -1;
                }
                if (y.IsArray)
                {
                    return 1;
                }
                if (x.IsPointer)
                {
                    return -1;
                }
                if (y.IsPointer)
                {
                    return 1;
                }

                return -1;
            }

            private static int Compare(VariableInformation x, VariableInformation y)
            {
                var xt = x.TargetType;
                var yt = y.TargetType;

                var xr = xt.IsAssignableFrom(yt);
                var yr = yt.IsAssignableFrom(xt);

                return Compare(xt, yt);
            }

            public int Compare(IMethodInformation x, IMethodInformation y)
            {
                var xps = x.Parameters;
                var yps = y.Parameters;

                var result = xps.Zip(yps, Compare).FirstOrDefault(r => r != 0);
                if (result != 0)
                {
                    return result;
                }
                else
                {
                    return xps.Length.CompareTo(yps.Length);
                }
            }

            public static readonly IComparer<IMethodInformation> Instance = new MethodSignatureComparer();
        }

        public static IDictionary<string, IMethodInformation[]> CalculateOverloadMethods(
            this IEnumerable<IMethodInformation> methods)
        {
            // Aggregate overloads and overrides.
            var dict = new SortedDictionary<string, IMethodInformation[]>();
            foreach (var g in methods.GroupBy(method => method.Name))
            {
                var r = g.
                    OrderBy(method => method.IsStatic ? 1 : 0).
                    ThenBy(method => method.Parameters.Length).
                    ThenBy(method => method.IsReuseSlot ? 1 : 0).
                    ThenBy(method => method, MethodSignatureComparer.Instance).
                    ToArray();

                dict.Add(g.Key, r);
            }
            return dict;
        }
    }
}
