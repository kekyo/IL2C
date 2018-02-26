using System;
using System.Collections.Generic;
using System.Linq;

using IL2C.Metadata;

namespace IL2C.Translators
{
    public sealed class PreparedFunctions
    {
        internal readonly IReadOnlyDictionary<MethodInformation, PreparedFunction> Functions;

        internal PreparedFunctions(IReadOnlyDictionary<MethodInformation, PreparedFunction> functions)
        {
            this.Functions = functions;
        }

        public int Count => this.Functions.Count;

        public bool TryGet(string methodName, out PreparedFunction preparedFunction)
        {
            preparedFunction = this.Functions
                .Where(entry => entry.Key.UniqueName == methodName)
                .Select(entry => entry.Value)
                .FirstOrDefault();
            return preparedFunction != null;
        }
    }
}
