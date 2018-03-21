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
        private static readonly Dictionary<string, string> predefinedIncludeHints = new Dictionary<string, string>
        {
            { typeof(bool).FullName, "stdbool.h" },
            { typeof(byte).FullName, "stdint.h" },
            { typeof(sbyte).FullName, "stdint.h" },
            { typeof(short).FullName, "stdint.h" },
            { typeof(ushort).FullName, "stdint.h" },
            { typeof(int).FullName, "stdint.h" },
            { typeof(uint).FullName, "stdint.h" },
            { typeof(long).FullName, "stdint.h" },
            { typeof(ulong).FullName, "stdint.h" },
            { typeof(string).FullName, "string.h" },
            { typeof(IntPtr).FullName, "stdint.h" },
            { typeof(UIntPtr).FullName, "stdint.h" },
            { typeof(char).FullName, "wchar.h" }
        };

        private static readonly Dictionary<string, string> predefinedCTypeNames = new Dictionary<string, string>
        {
            { typeof(void).FullName, "void" },
            { typeof(bool).FullName, "bool" },
            { typeof(byte).FullName, "uint8_t" },
            { typeof(sbyte).FullName, "int8_t" },
            { typeof(short).FullName, "int16_t" },
            { typeof(ushort).FullName, "uint16_t" },
            { typeof(int).FullName, "int32_t" },
            { typeof(uint).FullName, "uint32_t" },
            { typeof(long).FullName, "int64_t" },
            { typeof(ulong).FullName, "uint64_t" },
            { typeof(IntPtr).FullName, "intptr_t" },
            { typeof(UIntPtr).FullName, "uintptr_t" },
            { typeof(char).FullName, "wchar_t" }
        };

        private readonly HashSet<string> includes = new HashSet<string>();
        private readonly HashSet<string> privateIncludes = new HashSet<string>();
        private readonly Dictionary<string, IFieldInformation> staticFields =
            new Dictionary<string, IFieldInformation>();
        private readonly Dictionary<string, string> constStrings =
            new Dictionary<string, string>();
        #endregion

        #region Constructors
        public TranslateContext(Assembly assembly)
            : this(assembly.Location)
        {
            includes.Add("il2c.h");
        }

        public TranslateContext(string assemblyPath)
        {
            var context = new MetadataContext(assemblyPath);
            this.MetadataContext = context;
            this.Assembly = context.MainAssembly;

            includes.Add("il2c.h");
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
            if (predefinedIncludeHints.TryGetValue(type.UniqueName, out var includeFile))
            {
                this.RegisterIncludeFile(includeFile);
            }
            else if (type.IsByReference)
            {
                var dereferencedType = type.ElementType;
                this.RegisterType(dereferencedType);
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

        private string RegisterConstString(string str)
        {
            if (!constStrings.TryGetValue(str, out var symbolName))
            {
                symbolName = string.Format("string{0}__", constStrings.Count);
                constStrings.Add(str, symbolName);
            }

            return symbolName;
        }

        string IPrepareContext.RegisterConstString(string str)
        {
            return this.RegisterConstString(str);
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

        private string GetRightExpression(ITypeInformation lhsType, IVariableInformation rhs)
        {
            if (lhsType.Equals(rhs.TargetType))
            {
                return rhs.SymbolName;
            }

            if (lhsType.IsAssignableFrom(rhs.TargetType))
            {
                Debug.Assert(lhsType.IsValueType == false);
                Debug.Assert(rhs.TargetType.IsValueType == false);

                // IHoge <-- Hoge  (use il2c_cast_to_interface() macro)
                if (lhsType.IsInterface && !rhs.TargetType.IsInterface)
                {
                    return string.Format(
                        "il2c_cast_to_interface({0}, {1}, {2})",
                        lhsType.CLanguageDeclaration,
                        rhs.TargetType.CLanguageDeclaration,
                        rhs.SymbolName);
                }
                else
                {
                    return string.Format(
                        "({0}){1}",
                        lhsType.CLanguageDeclaration,
                        rhs.SymbolName);
                }
            }

            if (rhs.TargetType.IsNumericPrimitive)
            {
                if (lhsType.IsNumericPrimitive)
                {
                    return String.Format(
                        "({0}){1}",
                        lhsType.CLanguageDeclaration,
                        rhs.SymbolName);
                }
                else if (lhsType.IsBooleanType)
                {
                    return String.Format(
                        "{0} ? true : false",
                        rhs.SymbolName);
                }

                if (lhsType.IsEnum)
                {
                    var lhsElementType = lhsType.Fields
                        .First(f => f.Name == "value__")
                        .FieldType;
                    if (lhsElementType.IsAssignableFrom(rhs.TargetType))
                    {
                        return String.Format(
                            "({0}){1}",
                            lhsType.CLanguageDeclaration,
                            rhs.SymbolName);
                    }
                }
            }
            else if (rhs.TargetType.IsBooleanType)
            {
                if (lhsType.IsNumericPrimitive)
                {
                    return String.Format(
                        "{0} ? 1 : 0",
                        rhs.SymbolName);
                }
            }
            else if (rhs.TargetType.IsPointer)
            {
                if (lhsType.IsPointer)
                {
                    return String.Format(
                        "({0}){1}",
                        lhsType.CLanguageDeclaration,
                        rhs.SymbolName);
                }
            }
            else if (!lhsType.IsValueType && rhs.TargetType.IsIntPtrType)
            {
                return String.Format(
                    "({0}){1}",
                    lhsType.CLanguageDeclaration,
                    rhs.SymbolName);
            }

            return null;
        }

        string IExtractContext.GetRightExpression(ITypeInformation lhsType, IVariableInformation rhs)
        {
            return this.GetRightExpression(lhsType, rhs);
        }

        private string GetRightExpression(
            ITypeInformation lhsType, ITypeInformation rhsType, string rhsExpression)
        {
            if (lhsType.IsAssignableFrom(rhsType))
            {
                return rhsExpression;
            }

            if (rhsType.IsNumericPrimitive)
            {
                if (lhsType.IsNumericPrimitive)
                {
                    return String.Format(
                        "({0})({1})",
                        lhsType.CLanguageDeclaration,
                        rhsExpression);
                }
                else if (lhsType.IsBooleanType)
                {
                    return String.Format(
                        "({0}) ? true : false",
                        rhsExpression);
                }
            }
            else if (rhsType.IsBooleanType)
            {
                if (lhsType.IsNumericPrimitive)
                {
                    return String.Format(
                        "({0}) ? 1 : 0",
                        rhsExpression);
                }
            }
            else if (rhsType.IsPointer)
            {
                if (lhsType.IsPointer)
                {
                    return String.Format(
                        "({0}){1}",
                        lhsType.CLanguageDeclaration,
                        rhsExpression);
                }
            }

            return null;
        }

        string IExtractContext.GetRightExpression(
            ITypeInformation lhsType, ITypeInformation rhsType, string rhsExpression)
        {
            return this.GetRightExpression(lhsType, rhsType, rhsExpression);
        }

        private IEnumerable<KeyValuePair<string, string>> ExtractConstStrings()
        {
            return constStrings
                .Select(kv => new KeyValuePair<string, string>(kv.Value, kv.Key));
        }

        IEnumerable<KeyValuePair<string, string>> IExtractContext.ExtractConstStrings()
        {
            return this.ExtractConstStrings();
        }
        #endregion
    }
}
