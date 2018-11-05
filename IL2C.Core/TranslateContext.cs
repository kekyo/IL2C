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
        : IPrepareContext
        , IExtractContext
    {
        #region  Fields
        private readonly HashSet<string> includes = new HashSet<string>();
        private readonly HashSet<string> privateIncludes = new HashSet<string>();
        private readonly Dictionary<string, IFieldInformation> staticFields =
            new Dictionary<string, IFieldInformation>();
        private readonly Dictionary<string, string> constStrings =
            new Dictionary<string, string>();
        private readonly Dictionary<object, string> declaredValues =
            new Dictionary<object, string>(Utilities.LooseTypeKindComparer);
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
        private void RegisterIncludeFile(string includeFileName)
        {
            includes.Add(includeFileName);
        }

        void IPrepareContext.RegisterIncludeFile(string includeFileName)
        {
            this.RegisterIncludeFile(includeFileName);
        }

        private void RegisterPrivateIncludeFile(string includeFileName)
        {
            privateIncludes.Add(includeFileName);
        }

        void IPrepareContext.RegisterPrivateIncludeFile(string includeFileName)
        {
            this.RegisterPrivateIncludeFile(includeFileName);
        }

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

        void IPrepareContext.RegisterType(ITypeInformation type)
        {
            this.RegisterType(type);
        }

        private void RegisterStaticField(IFieldInformation staticField)
        {
            Debug.Assert(staticField.IsStatic);

            staticFields.Add(staticField.UniqueName, staticField);
        }

        void IPrepareContext.RegisterStaticField(IFieldInformation staticField)
        {
            this.RegisterStaticField(staticField);
        }

        private string RegisterConstString(string value)
        {
            if (!constStrings.TryGetValue(value, out var symbolName))
            {
                symbolName = string.Format("string{0}__", constStrings.Count);
                constStrings.Add(value, symbolName);
            }

            return symbolName;
        }

        string IPrepareContext.RegisterConstString(string value)
        {
            return this.RegisterConstString(value);
        }

        private string RegisterDeclaredValue(object value)
        {
            if (!declaredValues.TryGetValue(value, out var symbolName))
            {
                symbolName = string.Format("declaredValue{0}__", declaredValues.Count);
                declaredValues.Add(value, symbolName);
            }

            return symbolName;
        }

        string IPrepareContext.RegisterDeclaredValue(object value)
        {
            return this.RegisterDeclaredValue(value);
        }
        #endregion

        #region IExtractContext
        IEnumerable<string> IExtractContext.EnumerateRequiredIncludeFileNames()
        {
            return includes;
        }

        IEnumerable<string> IExtractContext.EnumerateRequiredPrivateIncludeFileNames()
        {
            return privateIncludes;
        }

        IEnumerable<IFieldInformation> IExtractContext.ExtractStaticFields()
        {
            return staticFields.Values;
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
                Debug.Assert((rhsType.IsValueType == false) || rhsType.IsUntypedReferenceType);

                // (RefType) <-- UntypedReferenceType  (maybe ldnull value)
                if (rhsType.IsUntypedReferenceType)
                {
                    return string.Format(
                        "({0}){1}",
                        lhsType.CLanguageTypeName,
                        rhsExpression);
                }
                // IHoge <-- Hoge  (use il2c_cast_to_interface() macro)
                else if (lhsType.IsInterface && !rhsType.IsInterface)
                {
                    return string.Format(
                        "il2c_cast_to_interface({0}, {1}, {2})",
                        lhsType.CLanguageTypeName,
                        rhsType.CLanguageTypeName,
                        rhsExpression);
                }
                else
                {
                    return string.Format(
                        "({0}){1}",
                        lhsType.CLanguageTypeName,
                        rhsExpression);
                }
            }

            if (rhsType.IsNumericPrimitive)
            {
                if (lhsType.IsNumericPrimitive)
                {
                    return string.Format(
                        "({0}){1}",
                        lhsType.CLanguageTypeName,
                        rhsExpression);
                }

                if (lhsType.IsBooleanType)
                {
                    return string.Format(
                        "({0}) ? true : false",
                        rhsExpression);
                }

                if (!lhsType.IsValueType && rhsType.IsIntPtrType)
                {
                    return string.Format(
                        "({0}){1}",
                        lhsType.CLanguageTypeName,
                        rhsExpression);
                }

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
                if (lhsType.IsNumericPrimitive)
                {
                    return string.Format(
                        "({0}) ? 1 : 0",
                        rhsExpression);
                }
            }
            else if (rhsType.IsByReference)
            {
                if (lhsType.IsByReference)
                {
                    return string.Format(
                        "({0}){1}",
                        lhsType.CLanguageTypeName,
                        rhsExpression);
                }
            }
            else if (lhsType.IsByReference)
            {
                return string.Format(
                    "({0}){1}",
                    lhsType.CLanguageTypeName,
                    rhsExpression);
            }
            else if (rhsType.IsUntypedReferenceType)
            {
                if (lhsType.IsIntPtrType || lhsType.IsUIntPtrType || lhsType.IsClass || lhsType.IsInterface)
                {
                    return string.Format(
                        "({0}){1}",
                        lhsType.CLanguageTypeName,
                        rhsExpression);
                }
            }

            return null;
        }

        string IExtractContext.GetRightExpression(ITypeInformation lhsType, VariableInformation rhs)
        {
            return this.GetRightExpression(lhsType, rhs.TargetType, rhs.SymbolName);
        }

        string IExtractContext.GetRightExpression(
            ITypeInformation lhsType, ITypeInformation rhsType, string rhsExpression) =>
            this.GetRightExpression(lhsType, rhsType, rhsExpression);

        private IEnumerable<(string symbolName, string value)> ExtractConstStrings()
        {
            return constStrings.
                Select(kv => (kv.Value, kv.Key));
        }

        IEnumerable<(string symbolName, string value)> IExtractContext.ExtractConstStrings() =>
            this.ExtractConstStrings();

        private IEnumerable<(string symbolName, object value)> ExtractDeclaredValues()
        {
            return declaredValues.
                Select(kv => (kv.Value, kv.Key));
        }

        IEnumerable<(string symbolName, object value)> IExtractContext.ExtractDeclaredValues() =>
            this.ExtractDeclaredValues();
        #endregion
    }
}
