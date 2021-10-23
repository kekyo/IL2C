/////////////////////////////////////////////////////////////////////////////////////////////////
//
// IL2C - A translator for ECMA-335 CIL/MSIL to C language.
// Copyright (c) 2016-2019 Kouji Matsui (@kozy_kekyo, @kekyo2)
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//	http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
/////////////////////////////////////////////////////////////////////////////////////////////////

using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using IL2C.Internal;
using Mono.Cecil;

namespace IL2C.Metadata
{
    internal static class MetadataUtilities
    {
        public static string GetLabelName(int offset) =>
            string.Format("IL_{0:x4}", offset);

        public static string TrimGenericIdentifier(string memberName)
        {
            // Foo`1 --> Foo
            var index = memberName.LastIndexOf('`');
            return (index >= 0) ? memberName.Substring(0, index) : memberName;
        }

        #region GetUniqueName
        private sealed class MemberElementFormats
        {
            public readonly string NameSeparator;       // Foo.Bar.Baz
            public readonly string MemberItemSeparator; // Foo,Bar,Baz
            public readonly string PrefixForGeneric;    // Foo<Bar ...
            public readonly string PostfixForGeneric;   // ... Bar>
            public readonly string PrefixForArgument;   // Foo( ...
            public readonly string PostfixForArgument;  // ... )
            public readonly bool IsMakeEmptyArgument;   // Foo() / Foo
            public readonly bool IsMangledName;

            public MemberElementFormats(
                string nameSeparator,
                string memberItemSeparator,
                string prefixForGeneric,
                string postfixForGeneric,
                string prefixForArgument,
                string postfixForArgument,
                bool isMakeEmptyArgument,
                bool isMangledName)
            {
                this.NameSeparator = nameSeparator;
                this.MemberItemSeparator = memberItemSeparator;
                this.PrefixForGeneric = prefixForGeneric;
                this.PostfixForGeneric = postfixForGeneric;
                this.PrefixForArgument = prefixForArgument;
                this.PostfixForArgument = postfixForArgument;
                this.IsMakeEmptyArgument = isMakeEmptyArgument;
                this.IsMangledName = isMangledName;
            }
        }

        private static readonly MemberElementFormats uniqueNameMemberFormat =
            new MemberElementFormats(".", ",", "<", ">", "(", ")", true, false);
        private static readonly MemberElementFormats mangledUniqueNameMemberFormat =
            new MemberElementFormats("_", "_", "__", string.Empty, "__", string.Empty, false, true);

        private static string GetMemberName(
            MemberReference member, bool onlyMemberName, MemberElementFormats memberFormat)
        {
            var memberName = memberFormat.IsMangledName ?
                Utilities.GetMangledName(TrimGenericIdentifier(member.Name)) :
                TrimGenericIdentifier(member.Name);

            if (onlyMemberName)
            {
                // namespace    typename   result
                // Foo.Bar.Baz  Bebe       Bebe
                // Foo.Bar.Baz  Bebe+Momo  Momo
                return memberName;
            }
            else
            {
                // namespace    typename   result
                // Foo.Bar.Baz  Bebe       Foo.Bar.Baz.Bebe
                // Foo.Bar.Baz  Bebe+Momo  Foo.Bar.Baz.Bebe.Momo

                var declaringTypes = member.DeclaringType.
                    Traverse(current => current.DeclaringType).
                    Reverse().
                    ToArray();
                var namespaceName = declaringTypes.FirstOrDefault()?.Namespace ??
                    (member as TypeReference)?.Namespace;
                if (memberFormat.IsMangledName && (namespaceName != null))
                {
                    namespaceName = Utilities.GetMangledName(namespaceName);
                }

                return string.Join(
                    memberFormat.NameSeparator,
                    ((namespaceName != null) ? new[] { namespaceName } : new string[0]).
                        Concat(declaringTypes.Select(type => ConstructUniqueName(type, true, memberFormat))).  // Made inner types.
                        Concat(new[] { memberName }));
            }
        }

        private static string ConstructUniqueName(
            TypeReference type, bool onlyMemberName, MemberElementFormats memberFormat)
        {
            if (type is GenericParameter parameter)
            {
                // T
                return parameter.Name;
            }

            if (type.IsArray)
            {
                // System.Array<int>
                return "System" + memberFormat.NameSeparator + "Array" +
                    memberFormat.PrefixForGeneric + ConstructUniqueName(type.GetElementType(), onlyMemberName, memberFormat) + memberFormat.PostfixForGeneric;
            }

            if (memberFormat.IsMangledName)
            {
                if (type.IsByReference)
                {
                    return ConstructUniqueName(type.GetElementType(), onlyMemberName, memberFormat) + "_REF";
                }
                if (type.IsPointer)
                {
                    return ConstructUniqueName(type.GetElementType(), onlyMemberName, memberFormat) + "_PTR";
                }
            }
            else
            {
                if (type.IsByReference)
                {
                    return ConstructUniqueName(type.GetElementType(), onlyMemberName, memberFormat) + "&";
                }
                if (type.IsPointer)
                {
                    return ConstructUniqueName(type.GetElementType(), onlyMemberName, memberFormat) + "*";
                }
            }

            var typeName = GetMemberName(type, onlyMemberName, memberFormat);

            if (type is GenericInstanceType genericInstanceType)
            {
                // FooType<int,T,long>
                return typeName + memberFormat.PrefixForGeneric +
                    string.Join(memberFormat.MemberItemSeparator, genericInstanceType.GenericArguments.
                        Select(a => ConstructUniqueName(a, false, memberFormat))) +
                    memberFormat.PostfixForGeneric;
            }

            if (type.HasGenericParameters)
            {
                // FooType<T,U,V>      ; GenericDefinition
                return typeName + memberFormat.PrefixForGeneric +
                    string.Join(memberFormat.MemberItemSeparator, type.GenericParameters.
                        Select(p => ConstructUniqueName(p, false, memberFormat))) +
                    memberFormat.PostfixForGeneric;
            }

            // FooType
            return typeName;
        }

        private static string ConstructUniqueName(
            MethodReference method, bool onlyMemberName, bool containsArgument, MemberElementFormats memberFormat)
        {
            var methodName = GetMemberName(method, onlyMemberName, memberFormat);

            string firstElement;
            if (method is GenericInstanceMethod genericInstanceMethod)
            {
                // BarMethod<int,T,long>
                firstElement = methodName + memberFormat.PrefixForGeneric +
                    string.Join(memberFormat.MemberItemSeparator, genericInstanceMethod.GenericArguments.
                        Select(a => ConstructUniqueName(a, false, memberFormat))) +
                    memberFormat.PostfixForGeneric;
            }
            else if (method.HasGenericParameters)
            {
                // BarMethod<T,U,V>      ; GenericDefinition
                firstElement = methodName + memberFormat.PrefixForGeneric +
                    string.Join(memberFormat.MemberItemSeparator, method.GenericParameters.
                        Select(p => ConstructUniqueName(p, false, memberFormat))) +
                    memberFormat.PostfixForGeneric;
            }
            else
            {
                // BarMethod
                firstElement = methodName;
            }

            var parameters = method.Parameters.
                Select(p => ConstructUniqueName(p.ParameterType, false, memberFormat)).
                ToArray();

            if (memberFormat.IsMakeEmptyArgument || (parameters.Length >= 1))
            {
                // BarMethod(float,byte,bool)
                return firstElement + memberFormat.PrefixForArgument +
                    string.Join(memberFormat.MemberItemSeparator, parameters) +
                    memberFormat.PostfixForArgument;
            }
            else
            {
                // BarMethod
                return firstElement;
            }
        }

        private static string ConstructUniqueName(
            MemberReference member, bool onlyMemberName, bool containsArgumentIfMemberIsMethod, MemberElementFormats memberFormat)
        {
            if (member is TypeReference type)
            {
                return ConstructUniqueName(type, onlyMemberName, memberFormat);
            }

            if (member is MethodReference method)
            {
                return ConstructUniqueName(method, onlyMemberName, containsArgumentIfMemberIsMethod, memberFormat);
            }

            return GetMemberName(member, onlyMemberName, memberFormat);
        }

        public static string GetUniqueName(this MemberReference member, bool onlyMemberName = false, bool containsArgumentIfMemberIsMethod = true) =>
            ConstructUniqueName(member, onlyMemberName, containsArgumentIfMemberIsMethod, uniqueNameMemberFormat);

        public static string GetMangledUniqueName(this MemberReference member, bool onlyMemberName = false) =>
            ConstructUniqueName(member, onlyMemberName, true, mangledUniqueNameMemberFormat);
        #endregion

        public static ITypeInformation UnwrapCoveredType(this ITypeInformation type)
        {
            if (type.IsByReference || type.IsPointer)
            {
                return type.ElementType;
            }
            if (type.IsArray)
            {
                return type.ElementType.UnwrapCoveredType();
            }
            return type;
        }

        #region MethodSignatureTypeComparer
        private sealed class MethodSignatureTypeComparerImpl
            : ICombinedComparer<ITypeInformation>
        {
            public MethodSignatureTypeComparerImpl()
            {
            }

            public int Compare(ITypeInformation x, ITypeInformation y)
            {
                if (x.Equals(y))
                {
                    return 0;
                }

                // Prioritize for narrowing base type.
                var xr = x.IsAssignableFrom(y);
                var yr = y.IsAssignableFrom(x);

                if (!xr && yr)
                {
                    return -1;
                }
                if (xr && !yr)
                {
                    return 1;
                }
                Debug.Assert(!(xr && yr));

                if (!x.IsByReference && y.IsByReference)
                {
                    var r = Compare(x, y.ElementType);
                    return (r == 0) ? -1 : r;
                }
                if (x.IsByReference && !y.IsByReference)
                {
                    var r = Compare(x.ElementType, y);
                    return (r == 0) ? 1 : r;
                }
                if (x.IsByReference && y.IsByReference)
                {
                    return Compare(x.ElementType, y.ElementType);
                }

                if (x.IsPrimitive)
                {
                    return -1;
                }
                if (y.IsPrimitive)
                {
                    return 1;
                }
                if (x.IsValueType)
                {
                    return -1;
                }
                if (y.IsValueType)
                {
                    return 1;
                }

                if (x.IsClass)
                {
                    return -1;
                }
                if (y.IsClass)
                {
                    return 1;
                }
                if (x.IsInterface)
                {
                    return -1;
                }
                if (y.IsInterface)
                {
                    return 1;
                }
                if (x.IsArray)
                {
                    return -1;
                }
                if (y.IsArray)
                {
                    return 1;
                }
                if (x.IsPointer)
                {
                    return -1;
                }
                if (y.IsPointer)
                {
                    return 1;
                }

                return -1;
            }

            public bool Equals(ITypeInformation x, ITypeInformation y)
            {
                return x.Equals(y);
            }

            public int GetHashCode(ITypeInformation obj)
            {
                return obj.UniqueName.GetHashCode();
            }
        }

        public static readonly ICombinedComparer<ITypeInformation> MethodSignatureTypeComparer =
            new MethodSignatureTypeComparerImpl();
        #endregion

        #region MethodSignatureParameterComparer
        private sealed class MethodSignatureParameterComparerImpl
            : ICombinedComparer<IParameterInformation>
        {
            public MethodSignatureParameterComparerImpl()
            {
            }

            public int Compare(IParameterInformation x, IParameterInformation y)
            {
                var xt = x.TargetType;
                var yt = y.TargetType;

                var xr = xt.IsAssignableFrom(yt);
                var yr = yt.IsAssignableFrom(xt);

                return MethodSignatureTypeComparer.Compare(xt, yt);
            }

            public bool Equals(IParameterInformation x, IParameterInformation y)
            {
                var xt = x.TargetType;
                var yt = y.TargetType;

                return MethodSignatureTypeComparer.Equals(xt, yt);
            }

            public int GetHashCode(IParameterInformation obj)
            {
                return obj.TargetType.GetHashCode();
            }
        }

        public static readonly ICombinedComparer<IParameterInformation> MethodSignatureParameterComparer =
            new MethodSignatureParameterComparerImpl();
        #endregion

        #region MethodSignatureComparer
        private sealed class MethodSignatureComparerImpl
            : ICombinedComparer<IMethodInformation>
        {
            // This is a overload stabilizer

            private readonly bool isVirtual;

            public MethodSignatureComparerImpl(bool isVirtual)
            {
                this.isVirtual = isVirtual;
            }

            public int Compare(IMethodInformation x, IMethodInformation y)
            {
                var rn = x.Name.CompareTo(y.Name);
                if (rn != 0)
                {
                    return rn;
                }

                var xps = x.Parameters;
                var yps = y.Parameters;

                rn = xps.Length.CompareTo(yps.Length);
                if (rn != 0)
                {
                    return rn;
                }

                // The arg0 type for virtual method has to ignore different types.
                return xps.
                    Zip(yps, (xp, yp) => new { xp, yp }).
                    Select((entry, index) =>
                        (isVirtual && (index == 0)) ? 0 : MethodSignatureParameterComparer.Compare(entry.xp, entry.yp)).
                    FirstOrDefault(r => r != 0);
            }

            public bool Equals(IMethodInformation x, IMethodInformation y)
            {
                if (x.Name != y.Name)
                {
                    return false;
                }

                var xps = x.Parameters;
                var yps = y.Parameters;

                if (xps.Length != yps.Length)
                {
                    return false;
                }

                // The arg0 type for virtual method has to ignore different types.
                return xps.
                    Zip(yps, (xp, yp) => new { xp, yp }).
                    Select((entry, index) =>
                        (isVirtual && (index == 0)) ? true : MethodSignatureParameterComparer.Equals(entry.xp, entry.yp)).
                    FirstOrDefault(r => r);
            }

            public int GetHashCode(IMethodInformation obj)
            {
                return obj.Name.GetHashCode();
            }
        }

        public static readonly ICombinedComparer<IMethodInformation> MethodSignatureComparer =
            new MethodSignatureComparerImpl(false);

        // It compares type equality without first argument.
        // Because the first argument is maybe different type by polymorphic at the virtual methods.
        public static readonly ICombinedComparer<IMethodInformation> VirtualMethodSignatureComparer =
            new MethodSignatureComparerImpl(true);
        #endregion

        public static IDictionary<string, IMethodInformation[]> OrderByOverloadPriority(
            this IEnumerable<IMethodInformation> methods)
        {
            // Aggregate overloads and overrides.
            var dict = new SortedDictionary<string, IMethodInformation[]>();
            foreach (var g in methods.GroupBy(method => method.Name))
            {
                var r = g.
                    OrderBy(method => method.IsStatic ? 1 : 0).
                    ThenBy(method => method.Parameters.Any(p => p.IsParamArray) ? 1 : 0).
                    ThenBy(method => method.Parameters.Length).
                    ThenBy(method => method.IsReuseSlot ? 1 : 0).
                    ThenBy(method => method, MethodSignatureComparer).
                    ToArray();

                dict.Add(g.Key, r);
            }
            return dict;
        }

        public static IEnumerable<IMethodInformation> FilterByNewslots(
            this IEnumerable<IMethodInformation> methods) =>
            methods.Where(method => method.IsVirtual && method.IsNewSlot);

        public static IEnumerable<(IMethodInformation newslotMethod, IMethodInformation[] reuseslotMethods)> OrderByMostOverrides(
            this IEnumerable<IMethodInformation> methods)
        {
            var list = new List<Tuple<IMethodInformation, List<IMethodInformation>>>();
            foreach (var method in methods.Where(method => method.IsVirtual))
            {
                if (method.IsNewSlot)
                {
                    list.Add(Tuple.Create(method, new List<IMethodInformation> { method }));
                }
                else if (method.IsReuseSlot)
                {
                    var index = list.FindLastIndex(entry => entry.Item1.CLanguageFunctionName == method.CLanguageFunctionName);
                    Debug.Assert(index >= 0);
                    list[index].Item2.Add(method);
                }
                else
                {
                    Debug.Assert(false);
                }
            }
            return list.
                Select(entry => (entry.Item1, entry.Item2.ToArray()));
        }

        public static IEnumerable<IMethodInformation> FilterAndOrderByMostOverrides(
            this IEnumerable<IMethodInformation> methods) =>
            OrderByMostOverrides(methods).Select(entry => entry.reuseslotMethods.Last());

        //[Obsolete]
        public static IEnumerable<(IMethodInformation method, int overloadIndex)> OrderByNewSlotVirtuals(
            this IEnumerable<IMethodInformation> methods)
        {
            // Calculate overrided virtual methods using NewSlot attribute.

            var overloadIndexes = new List<(IMethodInformation method, int overloadIndex)>();

            foreach (var method in methods.Where(method => method.IsVirtual))
            {
                // Search from derived to base
                var index = overloadIndexes.FindLastIndex(entry =>
                    VirtualMethodSignatureComparer.Equals(entry.method, method));
                if (index >= 0)
                {
                    // It's new slotted.
                    if (method.IsNewSlot)
                    {
                        // Add new method.
                        var (_, oi) = overloadIndexes[index];
                        overloadIndexes.Add((method, oi + 1));
                    }
                    else
                    {
                        // ReuseSlot: It's overrided from base method.
                        Debug.Assert(method.IsReuseSlot);

                        // Replace.
                        var (_, oi) = overloadIndexes[index];
                        overloadIndexes[index] = (method, oi);
                    }
                }
                else
                {
                    overloadIndexes.Add((method, 0));
                }
            }

            return overloadIndexes.ToArray();
        }
    }
}
