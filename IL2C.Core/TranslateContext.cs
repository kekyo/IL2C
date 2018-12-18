using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Reflection;

using IL2C.Translators;
using IL2C.Metadata;

namespace IL2C
{
    public sealed class TranslateContext
        : IPrepareContext, IExtractContextHost
    {
        #region  Fields
        private readonly HashSet<string> includes = new HashSet<string>();
        private readonly HashSet<string> privateIncludes = new HashSet<string>();
        private readonly HashSet<string> importIncludes = new HashSet<string>();
        private readonly Dictionary<string, IFieldInformation> staticFields =
            new Dictionary<string, IFieldInformation>();
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
        public TranslateContext(Assembly assembly, bool readSymbols)
            : this(assembly.Location, readSymbols)
        {
        }

        public TranslateContext(string assemblyPath, bool readSymbols)
        {
            var context = new MetadataContext(assemblyPath, readSymbols);
            this.MetadataContext = context;
            this.Assembly = context.MainAssembly;
        }
        #endregion

        public IMetadataContext MetadataContext { get; }

        public IAssemblyInformation Assembly { get; }

        #region IPrepareContext
        private void RegisterIncludeFile(string includeFileName) =>
            includes.Add(includeFileName);

        void IPrepareContext.RegisterIncludeFile(string includeFileName) =>
            this.RegisterIncludeFile(includeFileName);

        private void RegisterPrivateIncludeFile(string includeFileName) =>
            privateIncludes.Add(includeFileName);

        void IPrepareContext.RegisterPrivateIncludeFile(string includeFileName) =>
            this.RegisterPrivateIncludeFile(includeFileName);

        private void RegisterImportIncludeFile(string includeFileName) =>
            importIncludes.Add(includeFileName);

        void IPrepareContext.RegisterImportIncludeFile(string includeFileName) =>
            this.RegisterImportIncludeFile(includeFileName);

        private void RegisterType(ITypeInformation type)
        {
            if (type.IsByReference || type.IsPointer)
            {
                var dereferencedType = type.ElementType;
                this.RegisterType(dereferencedType);
            }
            else
            {
                var assembly = type.DeclaringModule.DeclaringAssembly;
                if (!assembly.Equals(this.MetadataContext.ObjectType.DeclaringModule.DeclaringAssembly))
                {
                    this.RegisterIncludeFile(assembly.CLanguageIncludeFileName);
                }
            }
        }

        void IPrepareContext.RegisterType(ITypeInformation type) =>
            this.RegisterType(type);

        private void RegisterStaticField(IFieldInformation staticField)
        {
            Debug.Assert(staticField.IsStatic);

            staticFields.Add(staticField.UniqueName, staticField);
        }

        void IPrepareContext.RegisterStaticField(IFieldInformation staticField) =>
            this.RegisterStaticField(staticField);

        private string RegisterConstString(string value)
        {
            if (!constStrings.TryGetValue(value, out var symbolName))
            {
                symbolName = string.Format("string{0}__", constStrings.Count);
                constStrings.Add(value, symbolName);
            }

            return symbolName;
        }

        string IPrepareContext.RegisterConstString(string value) =>
            this.RegisterConstString(value);

        private string RegisterDeclaredValue(IFieldInformation declaredField, byte[] resourceData)
        {
            if (!declaredValues.TryGetValue(resourceData, out var entry))
            {
                entry = (string.Format("declaredValue{0}__", declaredValues.Count), new HashSet<IFieldInformation>());
                declaredValues.Add(resourceData, entry);
            }

            entry.fields.Add(declaredField);

            return entry.symbolName;
        }

        string IPrepareContext.RegisterDeclaredValues(IFieldInformation declaredField, byte[] resourceData) =>
            this.RegisterDeclaredValue(declaredField, resourceData);

        private void RegisterDeclaredValuesHintType(string symbolName, ITypeInformation type)
        {
            if (!declaredValueHintTypes.TryGetValue(symbolName, out var types))
            {
                types = new HashSet<ITypeInformation>();
                declaredValueHintTypes.Add(symbolName, types);
            }

            types.Add(type);
        }

        void IPrepareContext.RegisterDeclaredValuesHintType(string symbolName, ITypeInformation type) =>
            this.RegisterDeclaredValuesHintType(symbolName, type);
        #endregion

        #region IExtractContext
        IEnumerable<string> IExtractContext.EnumerateRequiredIncludeFileNames() =>
            includes;
        IEnumerable<string> IExtractContext.EnumerateRequiredPrivateIncludeFileNames() =>
            privateIncludes;
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
                        lhsType.MangledName,
                        rhsType.ElementType.CLanguageStaticSizeOfExpression,
                        rhsType.CalculateInterfaceIndex(lhsType),
                        rhsExpression);
                }
                // IHoge <-- Hoge  (use il2c_cast_to_interface() macro)
                else if (lhsType.IsInterface && !rhsType.IsInterface)
                {
                    return string.Format(
                        "il2c_cast_to_interface({0}, {1}, {2})",
                        lhsType.MangledName,
                        rhsType.MangledName,
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
                        "({0}) ? true : false",
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
            else if (rhsType.IsBooleanType)
            {
                // intValue = boolValue  (implicitly conversion)
                if (lhsType.IsNumericPrimitive)
                {
                    return string.Format(
                        "({0}) ? 1 : 0",
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
                return variable.UnsafeRawSymbolName;
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

        IEnumerable<IFieldInformation> IExtractContext.ExtractStaticFields() =>
            staticFields.Values;

        IEnumerable<(string symbolName, string value)> IExtractContext.ExtractConstStrings() =>
            constStrings.Select(kv => (kv.Value, kv.Key));

        IEnumerable<DeclaredValuesInformation> IExtractContext.ExtractDeclaredValues()
        {
            return declaredValues.
                Select(kv =>
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
        }

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
