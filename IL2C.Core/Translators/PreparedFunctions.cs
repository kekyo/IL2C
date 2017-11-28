using System;
using System.Collections.Generic;
using System.Linq;

using Mono.Cecil;

namespace IL2C.Translators
{
    public sealed class PreparedFunctions
    {
        internal readonly IReadOnlyDictionary<MethodDefinition, PreparedFunction> Functions;

        internal PreparedFunctions(IReadOnlyDictionary<MethodDefinition, PreparedFunction> functions)
        {
            this.Functions = functions;
        }

        public int Count => this.Functions.Count;

        public bool TryGet(string methodName, out PreparedFunction preparedFunction)
        {
            preparedFunction = this.Functions
                .Where(entry => entry.Key.GetFullMemberName() == methodName)
                .Select(entry => entry.Value)
                .FirstOrDefault();
            return preparedFunction != null;
        }
    }
}
