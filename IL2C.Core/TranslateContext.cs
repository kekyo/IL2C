using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Reflection;

namespace IL2C
{
    public sealed class TranslateContext
    {
        private readonly Assembly assembly;
        private readonly HashSet<string> includes = new HashSet<string>();
        private readonly HashSet<FieldInfo> staticFields =
            new HashSet<FieldInfo>();

        public TranslateContext(Assembly assembly)
        {
            this.assembly = assembly;

            includes.Add("il2c.h");
        }

        public IEnumerable<string> EnumerateRequiredIncludeFileNames()
        {
            return includes;
        }

        internal void RegisterIncludeFile(string includeFileName)
        {
            includes.Add(includeFileName);
        }

        internal string GetCLanguageTypeName(Type type, bool isDereference = false)
        {
            if (type == typeof(void))
            {
                return "void";
            }
            if (type == typeof(Boolean))
            {
                this.RegisterIncludeFile("stdbool.h");
                return "bool";
            }
            if (type == typeof(Byte))
            {
                this.RegisterIncludeFile("stdint.h");
                return "uint8_t";
            }
            if (type == typeof(SByte))
            {
                this.RegisterIncludeFile("stdint.h");
                return "int8_t";
            }
            if (type == typeof(Int16))
            {
                this.RegisterIncludeFile("stdint.h");
                return "int16_t";
            }
            if (type == typeof(UInt16))
            {
                this.RegisterIncludeFile("stdint.h");
                return "uint16_t";
            }
            if (type == typeof(Int32))
            {
                this.RegisterIncludeFile("stdint.h");
                return "int32_t";
            }
            if (type == typeof(Int64))
            {
                this.RegisterIncludeFile("stdint.h");
                return "int64_t";
            }

            if (type.IsByRef)
            {
                var dereferencedType = type.GetElementType();
                return isDereference
                    ? this.GetCLanguageTypeName(dereferencedType)
                    : this.GetCLanguageTypeName(dereferencedType) + "*";
            }

            if (type.IsClass)
            {
                return isDereference
                    ? Utilities.GetFullMemberName(type).ManglingSymbolName()
                    : Utilities.GetFullMemberName(type).ManglingSymbolName() + "*";
            }
            else
            {
                return Utilities.GetFullMemberName(type).ManglingSymbolName();
            }
        }

        internal string GetRightExpression(Type lhsType, SymbolInformation rhs)
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

        internal string GetRightExpression(Type lhsType, Type rhsType, string rhsExpression)
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

        public void AddStaticField(FieldInfo staticField)
        {
            Debug.Assert(staticField.IsStatic);

            staticFields.Add(staticField);
        }

        public IEnumerable<FieldInfo> ExtractStaticFields()
        {
            return staticFields;
        }
    }
}
