using System;
using System.Collections.Generic;
using System.Linq;
using System.Reflection;

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
            if (type == typeof(Boolean))
            {
                return "bool";
            }
            if (type == typeof(Byte))
            {
                return "uint8_t";
            }
            if (type == typeof(SByte))
            {
                return "int8_t";
            }
            if (type == typeof(Int16))
            {
                return "int16_t";
            }
            if (type == typeof(UInt16))
            {
                return "uint16_t";
            }
            if (type == typeof(Int32))
            {
                return "int32_t";
            }
            if (type == typeof(Int64))
            {
                return "int64_t";
            }
            return type.FullName;
        }

        public static bool IsNumericPrimitive(Type type)
        {
            if (type == typeof(Byte))
            {
                return true;
            }
            if (type == typeof(SByte))
            {
                return true;
            }
            if (type == typeof(Int16))
            {
                return true;
            }
            if (type == typeof(UInt16))
            {
                return true;
            }
            if (type == typeof(Int32))
            {
                return true;
            }
            if (type == typeof(Int64))
            {
                return true;
            }

            return false;
        }

        public static string GetRightExpression(Type lhsType, StackInformation rhs)
        {
            if (lhsType.IsAssignableFrom(rhs.TargetType))
            {
                return rhs.SymbolName;
            }

            if (IsNumericPrimitive(rhs.TargetType))
            {
                if (IsNumericPrimitive(lhsType))
                {
                    return String.Format(
                        "({0}){1}",
                        GetCLanguageTypeName(lhsType),
                        rhs.SymbolName);
                }
                else if (lhsType == typeof(bool))
                {
                    return String.Format(
                        "{0} ? true : false",
                        rhs.SymbolName);
                }
            }

            return null;
        }

        public static string GetFullMethodName(MethodInfo method)
        {
            var declaringTypes = method.DeclaringType
                .Traverse(current => current.DeclaringType)
                .Reverse()
                .ToArray();

            return string.Format(
                "{0}.{1}.{2}",
                declaringTypes.First().Namespace,
                string.Join(".", declaringTypes.Select(dt => dt.Name)),
                method.Name);
        }

        public static IEnumerable<T> Traverse<T>(this T first, Func<T, T> next)
            where T : class
        {
            T current = first;
            while (current != null)
            {
                yield return current;
                current = next(current);
            }
        }
    }
}
