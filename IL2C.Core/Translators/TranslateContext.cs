using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Reflection;

namespace IL2C.Translators
{
    [Flags]
    internal enum TypeNameFlags
    {
        Strict = 0,
        Dereferenced = 1,
        StructPrefix = 2
    }

    internal interface IPrepareContext
    {
        void RegisterIncludeFile(string includeFileName);
        void RegisterPrivateIncludeFile(string includeFileName);
        void RegisterType(Type type);
        void RegisterStaticField(FieldInfo staticField);
    }

    internal interface IExtractContext
    {
        Assembly Assembly { get; }

        string GetCLanguageTypeName(Type type, TypeNameFlags flags = TypeNameFlags.Strict);
        string GetRightExpression(Type lhsType, SymbolInformation rhs);
        string GetRightExpression(Type lhsType, Type rhsType, string rhsExpression);
        IEnumerable<string> EnumerateRequiredIncludeFileNames();
        IEnumerable<string> EnumerateRequiredPrivateIncludeFileNames();
        IEnumerable<FieldInfo> ExtractStaticFields();
    }

    public sealed class TranslateContext : IPrepareContext, IExtractContext
    {
        private readonly HashSet<string> includes = new HashSet<string>();
        private readonly HashSet<string> privateIncludes = new HashSet<string>();
        private readonly HashSet<FieldInfo> staticFields = new HashSet<FieldInfo>();

        public TranslateContext(Assembly assembly)
        {
            this.Assembly = assembly;

            includes.Add("il2c.h");
        }

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

        private void RegisterType(Type type)
        {
            if (type == typeof(Boolean))
            {
                this.RegisterIncludeFile("stdbool.h");
            }
            else if (type == typeof(Byte))
            {
                this.RegisterIncludeFile("stdint.h");
            }
            else if (type == typeof(SByte))
            {
                this.RegisterIncludeFile("stdint.h");
            }
            else if (type == typeof(Int16))
            {
                this.RegisterIncludeFile("stdint.h");
            }
            else if (type == typeof(UInt16))
            {
                this.RegisterIncludeFile("stdint.h");
            }
            else if (type == typeof(Int32))
            {
                this.RegisterIncludeFile("stdint.h");
            }
            else if (type == typeof(UInt32))
            {
                this.RegisterIncludeFile("stdint.h");
            }
            else if (type == typeof(Int64))
            {
                this.RegisterIncludeFile("stdint.h");
            }
            else if (type == typeof(UInt64))
            {
                this.RegisterIncludeFile("stdint.h");
            }
            else if (type.IsByRef)
            {
                var dereferencedType = type.GetElementType();
                this.RegisterType(dereferencedType);
            }
        }

        void IPrepareContext.RegisterType(Type type)
        {
            this.RegisterType(type);
        }

        private void RegisterStaticField(FieldInfo staticField)
        {
            Debug.Assert(staticField.IsStatic);

            staticFields.Add(staticField);
        }

        void IPrepareContext.RegisterStaticField(FieldInfo staticField)
        {
            this.RegisterStaticField(staticField);
        }
        #endregion

        #region IExtractContext
        public Assembly Assembly { get; }

        IEnumerable<string> IExtractContext.EnumerateRequiredIncludeFileNames()
        {
            return includes;
        }

        IEnumerable<string> IExtractContext.EnumerateRequiredPrivateIncludeFileNames()
        {
            return privateIncludes;
        }

        IEnumerable<FieldInfo> IExtractContext.ExtractStaticFields()
        {
            return staticFields;
        }

        private string GetCLanguageTypeName(Type type, TypeNameFlags flags = TypeNameFlags.Strict)
        {
            if (type == typeof(void))
            {
                return "void";
            }
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
            if (type == typeof(UInt32))
            {
                return "uint32_t";
            }
            if (type == typeof(Int64))
            {
                return "int64_t";
            }
            if (type == typeof(UInt64))
            {
                return "uint64_t";
            }

            if (type.IsByRef)
            {
                var dereferencedType = type.GetElementType();
                var name = this.GetCLanguageTypeName(dereferencedType);
                return ((flags & TypeNameFlags.Dereferenced) == TypeNameFlags.Dereferenced)
                    ? name : (name + "*");
            }
            else
            {
                var name = Utilities.GetFullMemberName(type).ManglingSymbolName();
                if ((flags & TypeNameFlags.StructPrefix) == TypeNameFlags.StructPrefix)
                {
                    name = "struct " + name;
                }

                if (type.IsClass)
                {
                    return ((flags & TypeNameFlags.Dereferenced) == TypeNameFlags.Dereferenced)
                        ? name : (name + "*");
                }
                else
                {
                    return name;
                }
            }
        }

        string IExtractContext.GetCLanguageTypeName(Type type, TypeNameFlags flags)
        {
            return this.GetCLanguageTypeName(type, flags);
        }

        private string GetRightExpression(Type lhsType, SymbolInformation rhs)
        {
            if (lhsType == rhs.TargetType)
            {
                return rhs.SymbolName;
            }

            if (lhsType.IsAssignableFrom(rhs.TargetType))
            {
                Debug.Assert(lhsType.IsClass);
                Debug.Assert(rhs.TargetType.IsClass);

                return String.Format(
                    "({0}){1}",
                    this.GetCLanguageTypeName(lhsType),
                    rhs.SymbolName);
            }

            if (Utilities.IsNumericPrimitive(rhs.TargetType))
            {
                if (Utilities.IsNumericPrimitive(lhsType))
                {
                    return String.Format(
                        "({0}){1}",
                        this.GetCLanguageTypeName(lhsType),
                        rhs.SymbolName);
                }
                else if (lhsType == typeof(bool))
                {
                    return String.Format(
                        "{0} ? true : false",
                        rhs.SymbolName);
                }
            }
            else if (rhs.TargetType == typeof(bool))
            {
                if (Utilities.IsNumericPrimitive(lhsType))
                {
                    return String.Format(
                        "{0} ? 1 : 0",
                        rhs.SymbolName);
                }
            }

            return null;
        }

        string IExtractContext.GetRightExpression(Type lhsType, SymbolInformation rhs)
        {
            return this.GetRightExpression(lhsType, rhs);
        }

        private string GetRightExpression(Type lhsType, Type rhsType, string rhsExpression)
        {
            if (lhsType.IsAssignableFrom(rhsType))
            {
                return rhsExpression;
            }

            if (Utilities.IsNumericPrimitive(rhsType))
            {
                if (Utilities.IsNumericPrimitive(lhsType))
                {
                    return String.Format(
                        "({0})({1})",
                        this.GetCLanguageTypeName(lhsType),
                        rhsExpression);
                }
                else if (lhsType == typeof(bool))
                {
                    return String.Format(
                        "({0}) ? true : false",
                        rhsExpression);
                }
            }
            else if (rhsType == typeof(bool))
            {
                if (Utilities.IsNumericPrimitive(lhsType))
                {
                    return String.Format(
                        "({0}) ? 1 : 0",
                        rhsExpression);
                }
            }

            return null;
        }

        string IExtractContext.GetRightExpression(Type lhsType, Type rhsType, string rhsExpression)
        {
            return this.GetRightExpression(lhsType, rhsType, rhsExpression);
        }
        #endregion
    }
}
