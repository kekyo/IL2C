using System;
using System.Collections.Generic;
using System.Linq;

using IL2C.ILConveters;

namespace IL2C
{
    internal static class Utilities
    {
        private static readonly Dictionary<ushort, ILConverter> ilConverters;

        static Utilities()
        {
            ilConverters = typeof(ILConverter)
                .Assembly
                .GetTypes()
                .Where(type => type.IsSealed && typeof(ILConverter).IsAssignableFrom(type))
                .Select(type => (ILConverter) Activator.CreateInstance(type))
                .ToDictionary(ilc => (ushort) ilc.OpCode.Value);
        }

        public static bool TryGetILConverter(ushort opCodeBytes, out ILConverter ilc)
        {
            return ilConverters.TryGetValue(opCodeBytes, out ilc);
        }

        public static string GetCLanguageTypeName(Type type)
        {
            if (type == typeof(System.Int32))
            {
                return "int32_t";
            }
            if (type == typeof(System.Int64))
            {
                return "int64_t";
            }
            return type.FullName;
        }
    }
}
