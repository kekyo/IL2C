using System;
using System.Collections.Generic;
using System.Reflection;

namespace IL2C
{
    public sealed class TranslateContext
    {
        private readonly Module module;
        private readonly HashSet<string> includes = new HashSet<string>();

        public TranslateContext(Module module)
        {
            this.module = module;
        }

        public IEnumerable<string> EnumerateRequiredIncludeFileNames()
        {
            return includes;
        }

        internal Type ResolveType(int typeToken)
        {
            return module.ResolveType(typeToken);
        }

        internal FieldInfo ResolveField(int fieldToken)
        {
            return module.ResolveField(fieldToken);
        }

        internal MethodBase ResolveMethod(int methodToken)
        {
            return module.ResolveMethod(methodToken);
        }

        internal void RegisterIncludeFile(string includeFileName)
        {
            includes.Add(includeFileName);
        }
        internal string GetCLanguageTypeName(Type type)
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
                return this.GetCLanguageTypeName(dereferencedType) + "*";
            }

            return Utilities.GetFullMemberName(type).ManglingSymbolName();
        }

        internal string GetRightExpression(Type lhsType, SymbolInformation rhs)
        {
            if (lhsType.IsAssignableFrom(rhs.TargetType))
            {
                return rhs.SymbolName;
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

            return null;
        }

    }
}
