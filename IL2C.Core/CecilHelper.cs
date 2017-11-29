using System;
using System.Collections.Generic;
using System.Linq;

using Mono.Cecil;

namespace IL2C
{
    internal static class CecilHelper
    {
        #region MemberReferenceComparer
        public sealed class MemberReferenceComparer<T> : IEqualityComparer<T>, IComparer<T>
            where T : MemberReference
        {
            private MemberReferenceComparer()
            {
            }

            public int Compare(T x, T y)
            {
                return StringComparer.InvariantCulture.Compare(x.FullName, y.FullName);
            }

            public bool Equals(T x, T y)
            {
                return StringComparer.InvariantCulture.Equals(x.FullName, y.FullName);
            }

            public int GetHashCode(T obj)
            {
                return StringComparer.InvariantCulture.GetHashCode(obj.FullName);
            }

            public static readonly MemberReferenceComparer<T> Instance = new MemberReferenceComparer<T>();
        }
        #endregion

        #region Fields
        private static readonly HashSet<string> primitiveTypes = new HashSet<string>
        {
            typeof(byte).FullName,
            typeof(sbyte).FullName,
            typeof(short).FullName,
            typeof(ushort).FullName,
            typeof(int).FullName,
            typeof(uint).FullName,
            typeof(long).FullName,
            typeof(ulong).FullName,
        };
        #endregion

        private static T ResolveIf<T>(MemberReference reference)
            where T : IMemberDefinition
        {
            var definition = reference as IMemberDefinition;
            if (definition == null)
            {
                definition = reference.Resolve();
            }
            return (T)definition;
        }

        public static bool MemberEquals(this MemberReference lhs, MemberReference rhs)
        {
            if (object.ReferenceEquals(lhs, rhs))
            {
                return true;
            }

            return lhs.FullName == rhs.FullName;
        }

        public static bool IsValidDefinition(this TypeDefinition type)
        {
            return (type.IsValueType || type.IsClass) && (type.BaseType != null);
        }

        public static bool IsNumericPrimitive(this TypeReference type)
        {
            return type.IsPrimitive && primitiveTypes.Contains(type.FullName);
        }

        public static bool IsAssignableFrom(this TypeReference lhsType, TypeReference rhsType)
        {
            if (object.ReferenceEquals(lhsType, rhsType))
            {
                return true;
            }

            var lhsDefinition = ResolveIf<TypeDefinition>(lhsType);
            var rhsDefinition = ResolveIf<TypeDefinition>(rhsType);

            // BaseClass <-- DerivedClass
            if (lhsDefinition.IsClass && rhsDefinition.IsClass)
            {
                return rhsDefinition
                    .Traverse(type => type.BaseType?.Resolve(), true)
                    .Any(type => type.MemberEquals(lhsDefinition));
            }

            // IBase <-- DerivedClass
            // IBase <-- IDerived
            if (lhsDefinition.IsInterface)
            {
                return rhsDefinition.Interfaces
                    .Any(type => type.InterfaceType.MemberEquals(lhsDefinition));
            }

            return false;
        }

        public static string GetFullMemberName(this MemberReference member)
        {
            if (member.DeclaringType != null)
            {
                var declaringTypes = member.DeclaringType
                    .Traverse(current => current.DeclaringType)
                    .Reverse()
                    .ToArray();

                return String.Format(
                    "{0}.{1}.{2}",
                    declaringTypes.First().Namespace,
                    String.Join(".", declaringTypes.Select(dt => dt.Name)),
                    member.Name);
            }
            else
            {
                var type = member as TypeReference;
                if (type != null)
                {
                    return type.FullName;
                }
                else
                {
                    return member.Name;
                }
            }
        }

        #region Type system safed references
        public static TypeReference GetSafeVoidType(this MemberReference member)
        {
            return member.Module.TypeSystem.Void;
        }

        public static TypeReference GetSafeObjectType(this MemberReference member)
        {
            return member.Module.TypeSystem.Object;
        }

        public static TypeReference GetSafeValueTypeType(this MemberReference member)
        {
            return member.Module.TypeSystem.Object.Module.GetType("System.ValueType");
        }

        public static TypeReference GetSafeBooleanType(this MemberReference member)
        {
            return member.Module.TypeSystem.Boolean;
        }

        public static TypeReference GetSafeByteType(this MemberReference member)
        {
            return member.Module.TypeSystem.Byte;
        }

        public static TypeReference GetSafeSByteType(this MemberReference member)
        {
            return member.Module.TypeSystem.SByte;
        }

        public static TypeReference GetSafeInt16Type(this MemberReference member)
        {
            return member.Module.TypeSystem.Int16;
        }

        public static TypeReference GetSafeUInt16Type(this MemberReference member)
        {
            return member.Module.TypeSystem.UInt16;
        }

        public static TypeReference GetSafeInt32Type(this MemberReference member)
        {
            return member.Module.TypeSystem.Int32;
        }

        public static TypeReference GetSafeUInt32Type(this MemberReference member)
        {
            return member.Module.TypeSystem.UInt32;
        }

        public static TypeReference GetSafeInt64Type(this MemberReference member)
        {
            return member.Module.TypeSystem.Int64;
        }

        public static TypeReference GetSafeUInt64Type(this MemberReference member)
        {
            return member.Module.TypeSystem.UInt64;
        }

        ///

        public static TypeReference GetSafeVoidType(this ModuleDefinition module)
        {
            return module.TypeSystem.Void;
        }

        public static TypeReference GetSafeObjectType(this ModuleDefinition module)
        {
            return module.TypeSystem.Object;
        }

        public static TypeReference GetSafeValueTypeType(this ModuleDefinition module)
        {
            return module.TypeSystem.Object.Module.GetType("System.ValueType");
        }

        public static TypeReference GetSafeBooleanType(this ModuleDefinition module)
        {
            return module.TypeSystem.Boolean;
        }

        public static TypeReference GetSafeByteType(this ModuleDefinition module)
        {
            return module.TypeSystem.Byte;
        }

        public static TypeReference GetSafeSByteType(this ModuleDefinition module)
        {
            return module.TypeSystem.SByte;
        }

        public static TypeReference GetSafeInt16Type(this ModuleDefinition module)
        {
            return module.TypeSystem.Int16;
        }

        public static TypeReference GetSafeUInt16Type(this ModuleDefinition module)
        {
            return module.TypeSystem.UInt16;
        }

        public static TypeReference GetSafeInt32Type(this ModuleDefinition module)
        {
            return module.TypeSystem.Int32;
        }

        public static TypeReference GetSafeUInt32Type(this ModuleDefinition module)
        {
            return module.TypeSystem.UInt32;
        }

        public static TypeReference GetSafeInt64Type(this ModuleDefinition module)
        {
            return module.TypeSystem.Int64;
        }

        public static TypeReference GetSafeUInt64Type(this ModuleDefinition module)
        {
            return module.TypeSystem.UInt64;
        }
        #endregion

        #region Type system safed "is" operators
        public static bool IsVoidType(this TypeReference type)
        {
            return type.GetSafeVoidType().MemberEquals(type);
        }

        public static bool IsObjectType(this TypeReference type)
        {
            return type.GetSafeObjectType().MemberEquals(type);
        }

        public static bool IsValueTypeType(this TypeReference type)
        {
            return type.GetSafeValueTypeType().MemberEquals(type);
        }

        public static bool IsBooleanType(this TypeReference type)
        {
            return type.GetSafeBooleanType().MemberEquals(type);
        }

        public static bool IsByteType(this TypeReference type)
        {
            return type.GetSafeByteType().MemberEquals(type);
        }

        public static bool IsSByteType(this TypeReference type)
        {
            return type.GetSafeSByteType().MemberEquals(type);
        }

        public static bool IsInt16Type(this TypeReference type)
        {
            return type.GetSafeInt16Type().MemberEquals(type);
        }

        public static bool IsUInt16Type(this TypeReference type)
        {
            return type.GetSafeUInt16Type().MemberEquals(type);
        }

        public static bool IsInt32Type(this TypeReference type)
        {
            return type.GetSafeInt32Type().MemberEquals(type);
        }

        public static bool IsUInt32Type(this TypeReference type)
        {
            return type.GetSafeUInt32Type().MemberEquals(type);
        }

        public static bool IsInt64Type(this TypeReference type)
        {
            return type.GetSafeInt64Type().MemberEquals(type);
        }

        public static bool IsUInt64Type(this TypeReference type)
        {
            return type.GetSafeUInt64Type().MemberEquals(type);
        }
        #endregion
    }
}
