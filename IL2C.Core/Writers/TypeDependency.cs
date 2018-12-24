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
            private readonly Dictionary<ITypeInformation, ITypeInformation[]> dependTypeCache =
                new Dictionary<ITypeInformation, ITypeInformation[]>();
            private readonly Dictionary<(ITypeInformation, ITypeInformation), bool> isDependCache =
                new Dictionary<(ITypeInformation, ITypeInformation), bool>();

            public Context()
            {
            }

            private static ITypeInformation UnwrapElementType(ITypeInformation type)
            {
                if (type.IsByReference || type.IsPointer)
                {
                    return type.ElementType;
                }
                else if (type.IsArray)
                {
                    return UnwrapElementType(type.ElementType);
                }
                else
                {
                    return type;
                }
            }

            private ITypeInformation[] GetDependentTypes(ITypeInformation type)
            {
                if (!dependTypeCache.TryGetValue(type, out var results))
                {
                    results = new[] { type }.
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
                        Select(UnwrapElementType).
                        Distinct().
                        Where(t => t.DeclaringModule.Equals(type.DeclaringModule)).
                        ToArray();
                    dependTypeCache.Add(type, results);
                }

                return results;
            }

            public bool IsDepend(ITypeInformation to, ITypeInformation from)
            {
                if (!isDependCache.TryGetValue((to, from), out var result))
                {
                    var fromTypes = GetDependentTypes(from);

                    result = fromTypes.Any(fromType => to.IsAssignableFrom(fromType));
                    isDependCache.Add((to, from), result);
                }

                return result;
            }
        }

        public static ITypeInformation[] OrderBy(IEnumerable<ITypeInformation> types)
        {
            var context = new Context();
            var list = new LinkedList<ITypeInformation>();
            foreach (var type in types)
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
