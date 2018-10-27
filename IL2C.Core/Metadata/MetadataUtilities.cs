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

        public sealed class TypeComparerImpl
            : IComparer<ITypeInformation>, IEqualityComparer<ITypeInformation>
        {
            public TypeComparerImpl()
            {
            }

            public int Compare(ITypeInformation x, ITypeInformation y)
            {
                // Prioritize for narrowing base type.
                var xr = x.IsAssignableFrom(y);
                var yr = y.IsAssignableFrom(x);

                if (!xr && yr)
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

            public bool Equals(ITypeInformation x, ITypeInformation y)
            {
                return x.Equals(y);
            }

            public int GetHashCode(ITypeInformation obj)
            {
                return obj.UniqueName.GetHashCode();
            }
        }

        public static readonly TypeComparerImpl TypeComparer =
            new TypeComparerImpl();

        public sealed class MethodSignatureComparerImpl
            : IComparer<IMethodInformation>, IEqualityComparer<IMethodInformation>
        {
            // This is a overload stablizer

            private readonly bool isVirtual;

            public MethodSignatureComparerImpl(bool isVirtual)
            {
                this.isVirtual = isVirtual;
            }

            private static int Compare(VariableInformation x, VariableInformation y)
            {
                var xt = x.TargetType;
                var yt = y.TargetType;

                var xr = xt.IsAssignableFrom(yt);
                var yr = yt.IsAssignableFrom(xt);

                return TypeComparer.Compare(xt, yt);
            }

            private static bool Equals(VariableInformation x, VariableInformation y)
            {
                var xt = x.TargetType;
                var yt = y.TargetType;

                return TypeComparer.Equals(xt, yt);
            }

            public int Compare(IMethodInformation x, IMethodInformation y)
            {
                var rn = x.Name.CompareTo(y.Name);
                if (rn != 0)
                {
                    return rn;
                }

                var xps = x.Parameters;
                var yps = y.Parameters;

                rn = xps.Length.CompareTo(yps.Length);
                if (rn != 0)
                {
                    return rn;
                }

                // The arg0 type for virtual method has to ignore different types.
                return xps.
                    Zip(yps, (xp, yp) => new { xp, yp }).
                    Select((entry, index) => (isVirtual && (index == 0)) ? 0 : Compare(entry.xp, entry.yp)).
                    FirstOrDefault(r => r != 0);
            }

            public bool Equals(IMethodInformation x, IMethodInformation y)
            {
                if (x.Name != y.Name)
                {
                    return false;
                }

                var xps = x.Parameters;
                var yps = y.Parameters;

                if (xps.Length != yps.Length)
                {
                    return false;
                }

                // The arg0 type for virtual method has to ignore different types.
                return xps.
                    Zip(yps, (xp, yp) => new { xp, yp }).
                    Select((entry, index) => (isVirtual && (index == 0)) ? true : Equals(entry.xp, entry.yp)).
                    FirstOrDefault(r => r);
            }

            public int GetHashCode(IMethodInformation obj)
            {
                return obj.Name.GetHashCode();
            }
        }

        public static readonly MethodSignatureComparerImpl MethodSignatureComparer =
            new MethodSignatureComparerImpl(false);
        public static readonly MethodSignatureComparerImpl VirtualMethodSignatureComparer =
            new MethodSignatureComparerImpl(true);

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
                    ThenBy(method => method, MethodSignatureComparer).
                    ToArray();

                dict.Add(g.Key, r);
            }
            return dict;
        }

        public static IEnumerable<(IMethodInformation method, int overloadIndex)> CalculateVirtualMethods(
            this IEnumerable<IMethodInformation> methods)
        {
            // Calculate overrided virtual methods using NewSlot attribute.

            var overloadIndexes = new List<(IMethodInformation method, int overloadIndex)>();

            foreach (var method in methods.Where(method => method.IsVirtual))
            {
                // Search from derived to base
                var index = overloadIndexes.FindLastIndex(entry =>
                    VirtualMethodSignatureComparer.Equals(entry.method, method));
                if (index >= 1)
                {
                    // It's new slotted.
                    if (method.IsNewSlot)
                    {
                        // Add new method.
                        var (_, oi) = overloadIndexes[index];
                        overloadIndexes.Add((method, oi + 1));
                    }
                    else
                    {
                        // ReuseSlot: It's overrided from base method.
                        Debug.Assert(method.IsReuseSlot);

                        // Replace.
                        var (_, oi) = overloadIndexes[index];
                        overloadIndexes[index] = (method, oi + 1);  // TODO: really increment??
                    }
                }
                else
                {
                    overloadIndexes.Add((method, 0));
                }
            }

            return overloadIndexes.ToArray();
        }
    }
}
