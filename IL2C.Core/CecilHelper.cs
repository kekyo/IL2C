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

        internal static readonly TypeDefinition VoidType;
        internal static readonly TypeDefinition ObjectType;
        internal static readonly TypeDefinition ValueTypeType;
        internal static readonly TypeDefinition BooleanType;
        internal static readonly TypeDefinition ByteType;
        internal static readonly TypeDefinition SByteType;
        internal static readonly TypeDefinition Int16Type;
        internal static readonly TypeDefinition UInt16Type;
        internal static readonly TypeDefinition Int32Type;
        internal static readonly TypeDefinition UInt32Type;
        internal static readonly TypeDefinition Int64Type;
        internal static readonly TypeDefinition UInt64Type;
        #endregion

        #region Type initializer
        static CecilHelper()
        {
            var mscorlib = ModuleDefinition.ReadModule(typeof(object).Module.FullyQualifiedName);

            VoidType = mscorlib.GetType(typeof(void).FullName);
            ObjectType = mscorlib.GetType(typeof(object).FullName);
            ValueTypeType = mscorlib.GetType(typeof(ValueType).FullName);

            BooleanType = mscorlib.GetType(typeof(bool).FullName);
            ByteType = mscorlib.GetType(typeof(byte).FullName);
            SByteType = mscorlib.GetType(typeof(sbyte).FullName);
            Int16Type = mscorlib.GetType(typeof(short).FullName);
            UInt16Type = mscorlib.GetType(typeof(ushort).FullName);
            Int32Type = mscorlib.GetType(typeof(int).FullName);
            UInt32Type = mscorlib.GetType(typeof(uint).FullName);
            Int64Type = mscorlib.GetType(typeof(long).FullName);
            UInt64Type = mscorlib.GetType(typeof(ulong).FullName);
        }
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
    }
}
