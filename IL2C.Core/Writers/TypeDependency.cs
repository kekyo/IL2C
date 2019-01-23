using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;

using IL2C.Metadata;

namespace IL2C.Writers
{
    internal static class TypeDependency
    {
        private sealed class Context
        {
            private readonly Dictionary<ITypeInformation, HashSet<ITypeInformation>> dependTypeCache =
                new Dictionary<ITypeInformation, HashSet<ITypeInformation>>();
            private readonly Dictionary<(ITypeInformation, ITypeInformation), bool> isDependCache =
                new Dictionary<(ITypeInformation, ITypeInformation), bool>();

            public Context()
            {
            }

            private ISet<ITypeInformation> GetDependentTypes(ITypeInformation type)
            {
                if (!dependTypeCache.TryGetValue(type, out var results))
                {
                    results = new HashSet<ITypeInformation>();
                    dependTypeCache.Add(type, results);

                    foreach (var t in
                        new[] { type, type.BaseType }.
                        Concat(type.InterfaceTypes).
                        Concat(type.NestedTypes).
                        Concat(type.Fields.
                            Select(field => field.FieldType)).
                        Concat(type.DeclaredMethods.
                            Select(method => method.ReturnType)).
                        Concat(type.DeclaredMethods.
                            SelectMany(method => method.Parameters.Select(parameter => parameter.TargetType))).
                        Concat(type.DeclaredMethods.
                            SelectMany(method => method.CodeStream?.Select(ci => ci.Operand).
                                OfType<ITypeInformation>() ??
                                Enumerable.Empty<ITypeInformation>())).
                        Where(t => t != null).
                        Select(MetadataUtilities.UnwrapCoveredType).
                        Distinct())
                    {
                        results.Add(t);
                    }
                }

                return results;
            }

            public bool IsDepend(ITypeInformation to, ITypeInformation from)
            {
                if (!isDependCache.TryGetValue((to, from), out var result))
                {
                    var fromTypes = GetDependentTypes(from);

                    result = fromTypes.Contains(to);
                    isDependCache.Add((to, from), result);
                }

                return result;
            }
        }

        public static ITypeInformation[] OrderByDependant(this IEnumerable<ITypeInformation> types)
        {
            var context = new Context();
            var list = new LinkedList<ITypeInformation>();
            foreach (var type in types.
                Select(MetadataUtilities.UnwrapCoveredType).
                Distinct())
            {
                var phase = 1;
                var node = list.Last;
                while (node != null)
                {
                    if (node.Value.Equals(type))
                    {
                        break;
                    }

                    if (phase == 1)
                    {
                        if (context.IsDepend(type, node.Value))
                        {
                            phase = 2;
                        }
                    }
                    if (context.IsDepend(node.Value, type))
                    {
                        list.AddAfter(node, type);
                        break;
                    }

                    node = node.Previous;
                }

                if (node == null)
                {
                    if (phase == 1)
                    {
                        list.AddLast(type);
                    }
                    else
                    {
                        list.AddFirst(type);
                    }
                }
            }

            return list.ToArray();
        }
    }
}
