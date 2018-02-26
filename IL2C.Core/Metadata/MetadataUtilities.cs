using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using Mono.Cecil;

namespace IL2C.Metadata
{
    internal static class MetadataUtilities
    {
        public static IOrderedEnumerable<MethodDefinition> OrderByParameters(
           this IEnumerable<MethodDefinition> methods)
        {
            var ms = methods.ToArray();
            var maxParameterCount = (ms.Length >= 1) ? ms.Max(m => m.Parameters.Count) : 0;

            var expr = ms.OrderBy(m => m.Parameters.Count);
            for (var index = 0; index < maxParameterCount; index++)
            {
                // HACK: C# lambda captured inner incremented value.
                var capturedIndex = index;

                // TODO: Improve human predictivity and stable compatibility.
                expr = expr.ThenBy(m =>
                    m.Parameters.ElementAtOrDefault(capturedIndex)
                        ?.ParameterType.GetFullMemberName()
                        ?? string.Empty);
            }

            return expr;
        }

    }
}
