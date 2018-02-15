using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.Remoting.Messaging;
using Mono.Cecil;

namespace IL2C
{
    internal enum MethodNameTypes
    {
        Nothing,
        Full,
        Types,
        Index
    }

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

        #region PseudoZeroType
        private sealed class PseudoZeroType
        {
            private PseudoZeroType()
            {
            }
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
            typeof(IntPtr).FullName,
            typeof(UIntPtr).FullName,
            typeof(char).FullName
        };

        private static readonly TypeDefinition pseudoZeroTypeDefinition = AssemblyDefinition
            .ReadAssembly(typeof(PseudoZeroType).Assembly.Location)
            .MainModule
            .GetType(typeof(CecilHelper).FullName)
            .NestedTypes
            .First(t2 => t2.Name == typeof(PseudoZeroType).Name);
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
            return ((type.IsValueType || type.IsClass) && (type.BaseType != null)) || type.IsInterface;
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

            // System.Object <-- Any
            if (lhsDefinition.IsObjectType())
            {
                return true;
            }

            // System.ValueType <-- ValueType
            if (lhsDefinition.IsValueTypeType() && rhsDefinition.IsValueType)
            {
                return true;
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
                        ??string.Empty);
            }

            return expr;
        }

        public static int GetMethodOverloadIndex(this MethodReference method)
        {
            var declaringType = method.DeclaringType.Resolve();
            if (declaringType.Methods.Count < 2)
            {
                return 0;
            }

            var found = declaringType.Methods
                .Where(m => m.Name == method.Name)
                .OrderByParameters()     // Stable by overload types.
                .Select((m, i) => new {m, i})
                .First(e => e.m.MemberEquals(method));
            return found.i;
        }

        public static IEnumerable<MethodDefinition> EnumerateOrderedOverridedMethods(this TypeReference type)
        {
            var results = new List<MethodDefinition>();

            foreach (var t in type.Resolve()
                .Traverse(t =>
                {
                    return (t.IsValueType || t.IsClass)
                        ? t.BaseType?.Resolve()
                        // TODO: Traverse interface inheritance
                        : t.GetSafeObjectType().Resolve();
                })
                .Reverse())
            {
                foreach (var method in t.Methods
                    .Where(method => method.IsVirtual)
                    .OrderByParameters())    // Make stable in current type.
                {
                    if (method.IsNewSlot == false)
                    {
                        var index = results
                            .FindIndex(md => (md.Name == method.Name)
                            && (md.Parameters.Select(p => p.ParameterType).SequenceEqual(method.Parameters.Select(p => p.ParameterType))));
                        if (index >= 0)
                        {
                            results[index] = method;
                        }
                        else
                        {
                            results.Add(method);
                        }
                    }
                    else
                    {
                        results.Add(method);
                    }
                }
            }

            return results.ToArray();
        }

        public static string GetFullMemberName(
            this TypeReference type, MemberReference member, MethodNameTypes nameType = MethodNameTypes.Nothing)
        {
            var declaringTypes = type
                .Traverse(current => current.DeclaringType)
                .Reverse()
                .ToArray();

            var namespaceName = declaringTypes.First().Namespace;

            var method = member as MethodReference;
            if (method != null)
            {
                switch (nameType)
                {
                    case MethodNameTypes.Full:
                        return string.Format(
                            "{0}.{1}.{2}({3})",
                            namespaceName,
                            string.Join(".", declaringTypes.Select(dt => dt.Name)),
                            method.Name,
                            string.Join(
                                ", ",
                                method.Parameters.Select(parameter => string.Format(
                                    "{0} {1}",
                                    parameter.ParameterType.GetFullMemberName(),
                                    parameter.Name))));

                    case MethodNameTypes.Types:
                        return string.Format(
                            "{0}.{1}.{2}({3})",
                            namespaceName,
                            string.Join(".", declaringTypes.Select(dt => dt.Name)),
                            method.Name,
                            string.Join(
                                ", ",
                                method.Parameters.Select(parameter => parameter.ParameterType.GetFullMemberName())));

                    case MethodNameTypes.Index:
                        var index = method.GetMethodOverloadIndex();
                        if (index >= 1)
                        {
                            // Atmark will replace to underscore by ManglingSymbolName()
                            return string.Format(
                                "{0}.{1}.{2}@{3}",
                                namespaceName,
                                string.Join(".", declaringTypes.Select(dt => dt.Name)),
                                method.Name,
                                index);
                        }
                        break;
                }
            }

            return string.Format(
                "{0}.{1}.{2}",
                namespaceName,
                string.Join(".", declaringTypes.Select(dt => dt.Name)),
                member.Name);
        }

        public static string GetFullMemberName(
            this MemberReference member, MethodNameTypes nameType = MethodNameTypes.Nothing)
        {
            if (member.DeclaringType == null)
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
            else
            {
                return GetFullMemberName(member.DeclaringType, member, nameType);
            }
        }

        public static string GetOverloadedMethodName(this MethodReference method)
        {
            var index = method.GetMethodOverloadIndex();
            if (index >= 1)
            {
                // Atmark will replace to underscore by ManglingSymbolName()
                return string.Format(
                    "{0}@{1}",
                    method.Name,
                    index);
            }

            return method.Name;
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
            var realObject = member.Module.TypeSystem.Object.Resolve();
            return realObject.Module.GetType("System.ValueType");
        }

        public static TypeReference GetSafeIntPtrType(this MemberReference member)
        {
            return member.Module.TypeSystem.IntPtr;
        }

        public static TypeReference GetSafeUIntPtrType(this MemberReference member)
        {
            return member.Module.TypeSystem.UIntPtr;
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

        public static TypeReference GetSafeStringType(this MemberReference member)
        {
            return member.Module.TypeSystem.String;
        }

        public static TypeReference GetSafeCharType(this MemberReference member)
        {
            return member.Module.TypeSystem.Char;
        }

        public static TypeReference GetPseudoZeroType(this MemberReference member)
        {
            return pseudoZeroTypeDefinition;
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
            var realObject = module.TypeSystem.Object.Resolve();
            return realObject.Module.GetType("System.ValueType");
        }

        public static TypeReference GetSafeIntPtrType(this ModuleDefinition module)
        {
            return module.TypeSystem.IntPtr;
        }

        public static TypeReference GetSafeUIntPtrType(this ModuleDefinition module)
        {
            return module.TypeSystem.UIntPtr;
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

        public static TypeReference GetSafeStringType(this ModuleDefinition module)
        {
            return module.TypeSystem.String;
        }

        public static TypeReference GetSafeCharType(this ModuleDefinition module)
        {
            return module.TypeSystem.Char;
        }

        public static TypeReference GetPseudoZeroType(this ModuleDefinition module)
        {
            return pseudoZeroTypeDefinition;
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

        public static bool IsIntPtrType(this TypeReference type)
        {
            return type.GetSafeIntPtrType().MemberEquals(type);
        }

        public static bool IsUIntPtrType(this TypeReference type)
        {
            return type.GetSafeUIntPtrType().MemberEquals(type);
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

        public static bool IsStringType(this TypeReference type)
        {
            return type.GetSafeStringType().MemberEquals(type);
        }

        public static bool IsCharType(this TypeReference type)
        {
            return type.GetSafeCharType().MemberEquals(type);
        }

        public static bool IsPseudoZeroType(this TypeReference type)
        {
            return type.GetPseudoZeroType().MemberEquals(type);
        }
        #endregion
    }
}
