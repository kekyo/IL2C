using System;
using System.Collections.Generic;
using System.Linq;
using System.Reflection;

using Mono.Cecil;

namespace IL2C
{
    internal static class CecilHelper
    {
        #region PseudoZeroType
        [Obsolete("Will remove")]
        private sealed class PseudoZeroType
        {
            private PseudoZeroType()
            {
            }
        }
        #endregion

        #region Fields
        [Obsolete("Will remove")]
        private static readonly TypeDefinition pseudoZeroTypeDefinition = AssemblyDefinition
            .ReadAssembly(typeof(PseudoZeroType).GetTypeInfo().Assembly.Location)
            .MainModule
            .GetType(typeof(CecilHelper).FullName)
            .NestedTypes
            .First(t2 => t2.Name == typeof(PseudoZeroType).Name);
        #endregion
    }
}
