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
using System.Reflection;

using IL2C.Translators;
using IL2C.Metadata;
using IL2C.Internal;

namespace IL2C
{
    public enum TargetPlatforms
    {
        Generic,
        UE4         // Unreal Engine 4
    }

    public sealed class TranslateContext
        : IPrepareContext, IExtractContextHost
    {
        #region  Fields
        private readonly Dictionary<MemberScopes, HashSet<ITypeInformation>> registeredTypes =
            new Dictionary<MemberScopes, HashSet<ITypeInformation>>();
        private readonly Dictionary<ITypeInformation, HashSet<ITypeInformation>> registeredTypesByDeclaringType =
            new Dictionary<ITypeInformation, HashSet<ITypeInformation>>();
        private readonly HashSet<string> importIncludes = new HashSet<string>();
        private readonly Dictionary<string, string> constStrings =
            new Dictionary<string, string>();
        private readonly Dictionary<byte[], (string symbolName, HashSet<IFieldInformation> fields)> declaredValues =
            new Dictionary<byte[], (string symbolName, HashSet<IFieldInformation> fields)>(Utilities.LooseTypeKindComparer);
        private readonly Dictionary<string, HashSet<ITypeInformation>> declaredValueHintTypes =
            new Dictionary<string, HashSet<ITypeInformation>>();
        private Func<ILocalVariableInformation, string> prefixGenerator;
        private string currentExceptionNestedFrameIndexName;
        #endregion

        #region Constructors
        public TranslateContext(Assembly assembly, bool readSymbols, TargetPlatforms targetPlatform)
            : this(assembly.Location, readSymbols, targetPlatform)
        {
        }

        public TranslateContext(string assemblyPath, bool readSymbols, TargetPlatforms targetPlatform)
        {
            var context = new MetadataContext(assemblyPath, readSymbols);
            this.MetadataContext = context;
            this.Assembly = context.MainAssembly;
            this.TargetPlatform = targetPlatform;
        }
        #endregion

        public IMetadataContext MetadataContext { get; }

        public IAssemblyInformation Assembly { get; }

        public TargetPlatforms TargetPlatform { get; }

        #region IPrepareContext
        void IPrepareContext.RegisterImportIncludeFile(string includeFileName) =>
            importIncludes.Add(includeFileName);

        void IPrepareContext.RegisterType(ITypeInformation type, MemberScopes scope)
        {
            if (!registeredTypes.TryGetValue(scope, out var set))
            {
                set = new HashSet<ITypeInformation>();
                registeredTypes.Add(scope, set);
            }
            set.Add(type);
        }

        void IPrepareContext.RegisterType(ITypeInformation type, IMethodInformation declaringMethod)
        {
            // Assembly internal types (ex: ArrayInitializer constants) will be null value.
            if (type == null)
            {
                // Ignore.
                return;
            }

            // Aggregates by declaring type instead declaring method.
            // Because the IL2C will write source files separating by the types.
            // "EnumerateRegisteredTypesByDeclaringType" method enumerates by each types.
            var declaringType = declaringMethod.DeclaringType;

            if (!registeredTypesByDeclaringType.TryGetValue(declaringType, out var set))
            {
                set = new HashSet<ITypeInformation>();
                registeredTypesByDeclaringType.Add(declaringType, set);
            }
            set.Add(type);
        }

        string IPrepareContext.RegisterConstString(string value)
        {
            if (!constStrings.TryGetValue(value, out var symbolName))
            {
                symbolName = string.Format(
                    "{0}_string{1}__",
                    this.Assembly.MangledName,
                    constStrings.Count);
                constStrings.Add(value, symbolName);
            }

            return symbolName;
        }

        string IPrepareContext.RegisterDeclaredValues(IFieldInformation declaredField, byte[] resourceData)
        {
            if (!declaredValues.TryGetValue(resourceData, out var entry))
            {
                entry =
                    (string.Format(
                        "{0}_declaredValue{1}__",
                        this.Assembly.MangledName,
                        declaredValues.Count),
                    new HashSet<IFieldInformation>());
                declaredValues.Add(resourceData, entry);
            }

            entry.fields.Add(declaredField);

            return entry.symbolName;
        }

        void IPrepareContext.RegisterDeclaredValuesHintType(string symbolName, ITypeInformation type)
        {
            if (!declaredValueHintTypes.TryGetValue(symbolName, out var types))
            {
                types = new HashSet<ITypeInformation>();
                declaredValueHintTypes.Add(symbolName, types);
            }

            types.Add(type);
        }
        #endregion

        #region IExtractContext
        IReadOnlyDictionary<MemberScopes, IEnumerable<ITypeInformation>> IExtractContext.EnumerateRegisteredTypes() =>
            registeredTypes.ToDictionary(entry => entry.Key, entry => entry.Value.AsEnumerable());

        IEnumerable<ITypeInformation> IExtractContext.EnumerateRegisteredTypesByDeclaringType(ITypeInformation declaringType)
        {
            registeredTypesByDeclaringType.TryGetValue(declaringType, out var list);
            return list ?? Enumerable.Empty<ITypeInformation>();
        }

        IEnumerable<ITypeInformation> IExtractContext.EnumerateDeclaredTypes()
        {
            return registeredTypesByDeclaringType.Values.SelectMany(typeInfo => typeInfo).Distinct();
        }

        IEnumerable<string> IExtractContext.EnumerateRequiredImportIncludeFileNames() =>
            importIncludes;

        string IExtractContext.GetExceptionNestedFrameIndexName()
        {
            Debug.Assert(currentExceptionNestedFrameIndexName != null);
            return currentExceptionNestedFrameIndexName;
        }

        private string GetRightExpression(
            ITypeInformation lhsType, ITypeInformation rhsType, string rhsExpression)
        {
            if (lhsType.Equals(rhsType))
            {
                return rhsExpression;
            }

            if (lhsType.IsAssignableFrom(rhsType))
            {
                Debug.Assert(rhsType.IsReferenceType || rhsType.IsUntypedReferenceType || rhsType.IsByReference);

                // (RefType) <-- UntypedReferenceType  (maybe ldnull value)
                if (rhsType.IsUntypedReferenceType)
                {
                    return string.Format(
                        "({0}){1}",
                        lhsType.CLanguageTypeName,
                        rhsExpression);
                }
                // (RefType) <-- boxedtype<HogeValue>  (maybe box value)
                else if (lhsType.IsClass && rhsType.IsBoxedType)
                {
                    return string.Format(
                        "({0}){1}",
                        lhsType.CLanguageTypeName,
                        rhsExpression);
                }
                // IHoge <-- boxedtype<HogeValue>  (maybe box value)
                else if (lhsType.IsInterface && rhsType.IsBoxedType)
                {
                    return string.Format(
                        "il2c_cast_from_boxed_to_interface({0}, {1}, {2}, {3})",
                        lhsType.MangledUniqueName,
                        rhsType.ElementType.CLanguageStaticSizeOfExpression,
                        rhsType.CalculateInterfaceIndex(lhsType),
                        rhsExpression);
                }
                // IHoge <-- Hoge  (use il2c_cast_to_interface() macro)
                else if (lhsType.IsInterface && !rhsType.IsInterface)
                {
                    return string.Format(
                        "il2c_cast_to_interface({0}, {1}, {2})",
                        lhsType.MangledUniqueName,
                        rhsType.MangledUniqueName,
                        rhsExpression);
                }
                // object <-- IHoge
                else if (lhsType.IsObjectType && rhsType.IsInterface)
                {
                    return string.Format(
                        "il2c_adjusted_reference({0})",
                        rhsExpression);
                }
                else
                {
                    // Special case: System.Object <-- managed pointer
                    //   The value type arg0

                    return string.Format(
                        "({0}){1}",
                        lhsType.CLanguageTypeName,
                        rhsExpression);
                }
            }

            if (rhsType.IsNumericPrimitive)
            {
                // intValue = longValue
                if (lhsType.IsNumericPrimitive)
                {
                    return string.Format(
                        "({0}){1}",
                        lhsType.CLanguageTypeName,
                        rhsExpression);
                }

                // boolValue = intValue  (implicitly conversion)
                if (lhsType.IsBooleanType)
                {
                    return string.Format(
                        "(bool){0}",
                        rhsExpression);
                }

                // TODO: ??
                if (!lhsType.IsValueType && rhsType.IsIntPtrType)
                {
                    return string.Format(
                        "({0}){1}",
                        lhsType.CLanguageTypeName,
                        rhsExpression);
                }

                // enumValue = intValue  (implicitly conversion)
                if (lhsType.IsEnum)
                {
                    return string.Format(
                        "({0}){1}",
                        lhsType.CLanguageTypeName,
                        rhsExpression);
                }
            }
            else if (rhsType.IsEnum)
            {
                // intValue = (int)enumValue
                if (lhsType.IsNumericPrimitive)
                {
                    return string.Format(
                        "({0}){1}",
                        lhsType.CLanguageTypeName,
                        rhsExpression);
                }
            }
            else if (rhsType.IsBooleanType)
            {
                // intValue = boolValue  (implicitly conversion)
                if (lhsType.IsInt32Type)
                {
                    return string.Format(
                        "(int){0}",
                        rhsExpression);
                }
                else
                {
                    return string.Format(
                        "({0})(int){1}",
                        lhsType.CLanguageTypeName,
                        rhsExpression);
                }
            }
            else if (rhsType.IsByReference)
            {
                // TODO: &intValue = &longValue
                if (lhsType.IsByReference)
                {
                    return string.Format(
                        "({0}){1}",
                        lhsType.CLanguageTypeName,
                        rhsExpression);
                }
            }
            // TODO: &intValue = intValue
            else if (lhsType.IsByReference)
            {
                return string.Format(
                    "({0}){1}",
                    lhsType.CLanguageTypeName,
                    rhsExpression);
            }
            else if (rhsType.IsUntypedReferenceType)
            {
                // intptrValue = null
                // objRefValue = null
                if (lhsType.IsIntPtrType || lhsType.IsUIntPtrType || lhsType.IsReferenceType)
                {
                    return string.Format(
                        "({0}){1}",
                        lhsType.CLanguageTypeName,
                        rhsExpression);
                }
            }

            return null;
        }

        private string GetSymbolName(IVariableInformation variable)
        {
            var local = variable as ILocalVariableInformation;
            if (local != null)
            {
                var prefix = prefixGenerator?.Invoke(local);
                return local.ExtractSymbolName(prefix);
            }
            else
            {
                return variable.UnsafeCLanguageSymbolName;
            }
        }

        string IExtractContext.GetRightExpression(
            ITypeInformation lhsType, IVariableInformation rhs) =>
            this.GetRightExpression(lhsType, rhs.TargetType, this.GetSymbolName(rhs));

        string IExtractContext.GetRightExpression(
            ITypeInformation lhsType, ITypeInformation rhsType, string rhsExpression) =>
            this.GetRightExpression(lhsType, rhsType, rhsExpression);

        string IExtractContext.GetSymbolName(IVariableInformation variable) =>
            this.GetSymbolName(variable);

        IEnumerable<(string symbolName, string value)> IExtractContext.ExtractConstStrings() =>
            constStrings.Select(kv => (kv.Value, kv.Key));

        IEnumerable<DeclaredValuesInformation> IExtractContext.ExtractDeclaredValues() =>
            declaredValues.Select(kv =>
            {
                if (!declaredValueHintTypes.TryGetValue(kv.Value.symbolName, out var hintTypes))
                {
                    return new DeclaredValuesInformation(
                        kv.Value.symbolName,
                        kv.Value.fields.ToArray(),
                        new ITypeInformation[0],
                        kv.Key);
                }
                else
                {
                    return new DeclaredValuesInformation(
                        kv.Value.symbolName,
                        kv.Value.fields.ToArray(),
                        hintTypes.ToArray(),
                        kv.Key);
                }
            });

        private sealed class LocalVariablePrefixDisposer : IDisposable
        {
            private TranslateContext parent;

            public LocalVariablePrefixDisposer(TranslateContext parent)
            {
                this.parent = parent;
            }

            public void Dispose()
            {
                if (parent != null)
                {
                    parent.prefixGenerator = null;
                    parent = null;
                }
            }
        }

        IDisposable IExtractContextHost.BeginLocalVariablePrefix(Func<ILocalVariableInformation, string> prefixGenerator)
        {
            Debug.Assert(this.prefixGenerator == null);

            this.prefixGenerator = prefixGenerator;

            return new LocalVariablePrefixDisposer(this);
        }

        void IExtractContextHost.SetNestedExceptionFrameIndexName(string nestedIndexName)
        {
            currentExceptionNestedFrameIndexName = nestedIndexName;
        }
        #endregion
    }
}
