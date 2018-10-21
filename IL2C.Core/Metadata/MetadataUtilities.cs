using System;
using System.Collections.Generic;
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

        public static IOrderedEnumerable<IMethodInformation> OrderByStableAllOverloads(
            this IEnumerable<IMethodInformation> methods)
        {
            // TODO: Improve human predictivity and stable compatibility.

            var ms = methods.ToArray();
            var maxParameterCount = (ms.Length >= 1) ? ms.Max(m => m.Parameters.Length) : 0;

            // Step 1: Stable by parameter count
            var expr = ms.OrderBy(m => m.Parameters.Length);
            for (var index = 0; index < maxParameterCount; index++)
            {
                // HACK: C# lambda captured inner incremented value.
                var capturedIndex = index;

                // Step 2: Stable by non virtual --> virtual
                expr = expr.ThenBy(m => m.IsVirtual ? 1 : 0).
                // Step 3: Stable by the type letter for each of a prameter
                    ThenBy(m => (capturedIndex < m.Parameters.Length)
                        ? m.Parameters[capturedIndex].TargetType.FriendlyName
                        : string.Empty);
            }

            return expr;
        }
    }
}
