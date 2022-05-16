////////////////////////////////////////////////////////////////////////////
//
// IL2C - A translator for ECMA-335 CIL/MSIL to C language.
// Copyright (c) Kouji Matsui (@kozy_kekyo, @kekyo@mastodon.cloud)
//
// Licensed under Apache-v2: https://opensource.org/licenses/Apache-2.0
//
////////////////////////////////////////////////////////////////////////////

#nullable enable

using System;
using System.Collections;
using System.Collections.Generic;
using System.Diagnostics;
using System.Globalization;
using System.Linq;
using System.Reflection;
using System.Text;

using IL2C.Metadata;
using IL2C.Translators;

namespace IL2C.Internal
{
    internal static class SymbolManipulator
    {
        private static readonly string intMinValueExpression = string.Format("{0} - 1", int.MinValue + 1);
        private static readonly string longMinValueExpression = string.Format("{0}LL - 1LL", long.MinValue + 1);

        private static readonly char[] replaceChars = {
            '.', ',', '@', '+', '-', '*', '/', '^', '\\', '#', '%', '&', '$', '?', '!', '=', '~', '|',
            '(', ')', '<', '>', '[', ']', '{', '}', '\'', '"', '`', ';', ':', ' ' };

        public static string GetMangledName(string name)
        {
            var sb = new StringBuilder(name);
            foreach (var ch in replaceChars)
            {
                sb.Replace(ch, '_');
            }
            return sb.ToString();
        }

        public static string GetCLanguageScopedPath(IEnumerable<string> scopeNames) =>
            string.Join("/", scopeNames.SelectMany(sn => sn.Split('.')));

        public static string GetCLanguageScopedPath(params string[] scopeNames) =>
            GetCLanguageScopedPath((IEnumerable<string>)scopeNames);

        public static IEnumerable<string> SymbolRenaming(this IEnumerable<string> names)
        {
            // symbol
            // symbol2
            // symbol3
            // ...

            var nameIndex = new Dictionary<string, int>();
            foreach (var name in names)
            {
                if (nameIndex.TryGetValue(name, out var index))
                {
                    index++;
                    nameIndex[name] = index;
                    yield return name + index;
                }
                else
                {
                    nameIndex[name] = 1;
                    yield return name;
                }
            }
        }

        public static string GetCLanguageTypeName(
            Type type, string? symbolName = null, bool cArrayExpression = false)
        {
            var sn = (symbolName != null) ? (" " + symbolName) : string.Empty;

            if (type.IsByRef || type.IsPointer)
            {
                return string.Format(
                    "{0}*{1}",
                    GetCLanguageTypeName(type.GetElementType()!),
                    sn);
            }

            if (type.IsArray)
            {
                if (cArrayExpression)
                {
                    return string.Format(
                        "{0}{1}[]",
                        GetCLanguageTypeName(type.GetElementType()!, null, true),
                        sn);
                }
                else
                {
                    return string.Format(
                        "{0}*{1}",
                        GetCLanguageTypeName(type.GetElementType()!, null, true),
                        sn);
                }
            }

            string typeName;
            if (type == typeof(bool))
            {
                typeName = "bool";
            }
            else if (type == typeof(byte))
            {
                typeName = "uint8_t";
            }
            else if (type == typeof(sbyte))
            {
                typeName = "int8_t";
            }
            else if (type == typeof(short))
            {
                typeName = "int16_t";
            }
            else if (type == typeof(ushort))
            {
                typeName = "uint16_t";
            }
            else if (type == typeof(int))
            {
                typeName = "int32_t";
            }
            else if (type == typeof(uint))
            {
                typeName = "uint32_t";
            }
            else if (type == typeof(long))
            {
                typeName = "int64_t";
            }
            else if (type == typeof(ulong))
            {
                typeName = "uint64_t";
            }
            else if (type == typeof(IntPtr))
            {
                typeName = "intptr_t";
            }
            else if (type == typeof(UIntPtr))
            {
                typeName = "uintptr_t";
            }
            else if (type == typeof(float))
            {
                typeName = "float";
            }
            else if (type == typeof(double))
            {
                typeName = "double";
            }
            else if (type == typeof(char))
            {
                typeName = "wchar_t";
            }
            else if (type == typeof(string))
            {
                typeName = "wchar_t*";
            }
            else if (type == typeof(void))
            {
                typeName = "void";
            }
            else
            {
                typeName = GetMangledName(type.FullName!);
                if (!type.IsValueType)
                {
                    typeName += "*";
                }
            }

            return typeName + sn;
        }

        #region GetCLanguageSizeOf
        private static string? InternalGetCLanguageSizeOfExpression(Type type)
        {
            if (type.IsEnum)
            {
                return InternalGetCLanguageSizeOfExpression(type.GetEnumUnderlyingType());
            }
            if ((type == typeof(byte)) || (type == typeof(sbyte)) || (type == typeof(bool)))
            {
                return "sizeof(uint8_t)";
            }
            if ((type == typeof(short)) || (type == typeof(ushort)) || (type == typeof(char)))
            {
                return "sizeof(uint16_t)";
            }
            if ((type == typeof(int)) || (type == typeof(uint)) || (type == typeof(float)))
            {
                return "sizeof(uint32_t)";
            }
            if ((type == typeof(long)) || (type == typeof(ulong)) || (type == typeof(double)))
            {
                return "sizeof(uint64_t)";
            }
            if ((type == typeof(IntPtr)) || (type == typeof(UIntPtr)) ||
                type.IsByRef || type.IsPointer)
            {
                return "sizeof(intptr_t)";
            }
            if (type == typeof(void))
            {
                return "0";
            }
            return null;
        }

        public static string GetCLanguageSizeOfExpression(Type type)
        {
            var expression = InternalGetCLanguageSizeOfExpression(type);
            if (expression != null)
            {
                return expression;
            }

            throw new ArgumentException("Uninterpreted value size: " + type.FullName);
        }

        public static string GetCLanguageSizeOfExpression(object value)
        {
            if (value == null)
            {
                return "0";
            }

            if (value is string)
            {
                return (sizeof(char) * (((string)value).Length + 1)).ToString();
            }

            if (value is IEnumerable)
            {
                return string.Join(
                    " + ",
                    ((IEnumerable)value).RuntimeCast<object>().
                    Select(v => GetCLanguageSizeOfExpression(v)).
                    GroupBy(expr => expr).
                    Select(
                        g =>
                        {
                            var vs = g.ToArray();
                            if (vs.Length == 1)
                            {
                                return g.Key;
                            }
                            else
                            {
                                return string.Format("{0} * {1}", g.Key, vs.Length);
                            }
                        }));
            }

            var expression = InternalGetCLanguageSizeOfExpression(value.GetType());
            if (expression != null)
            {
                return expression;
            }

            throw new ArgumentException("Uninterpreted value size: " + value.GetType().FullName);
        }
        #endregion

        #region GetCLanguageExpression
        public static string GetCLanguageExpression(int value)
        {
            // HACK: if operand is int.MinValue, compiler will cause constant literal warning:
            //   "warning: this decimal constant is unsigned only in ISO C90 [enabled by default]" (it's gcc, but vc causes same)
            //   IL2C makes the expression it special case.
            return (value != int.MinValue)
                ? value.ToString()
                : intMinValueExpression;
        }

        public static string GetCLanguageExpression(long value)
        {
            // HACK: if operand is int.MinValue, compiler will cause constant literal warning:
            //   "warning: this decimal constant is unsigned only in ISO C90 [enabled by default]" (it's gcc, but vc causes same)
            //   IL2C makes the expression it special case.
            return (value != long.MinValue)
                ? (value.ToString() + "LL")
                : longMinValueExpression;
        }

        public static string GetCLanguageExpression(uint value) =>
            value.ToString() + "U";

        public static string GetCLanguageExpression(ulong value) =>
            value.ToString() + "ULL";

        public static string GetCLanguageExpression(float value)
        {
            // Single type format issue: https://docs.microsoft.com/en-us/dotnet/api/system.single.tostring
            //   By default, the return value only contains 7 digits of precision although a maximum of
            //   9 digits is maintained internally.
            //   If the value of this instance has greater than 7 digits, ToString returns
            //   PositiveInfinitySymbol or NegativeInfinitySymbol instead of the expected number.
            //   If you require more precision, specify format with the "G9" format specification,
            //   which always returns 9 digits of precision, or "R", which returns 7 digits if the number
            //   can be represented with that precision or 9 digits if the number can only be represented
            //   with maximum precision.
            var str = value.ToString("g9");

            // HACK: C compiler requires dot-notation for float type literal.
            return str.Contains(".") ? (str + "f") : (str + ".0f");
        }

        public static string GetCLanguageExpression(double value)
        {
            // Double type format issue: https://docs.microsoft.com/en-us/dotnet/api/system.double.tostring
            //   By default, the return value only contains 15 digits of precision although a maximum of
            //   17 digits is maintained internally.
            //   If the value of this instance has greater than 15 digits, ToString returns
            //   PositiveInfinitySymbol or NegativeInfinitySymbol instead of the expected number.
            //   If you require more precision, specify format with the "G17" format specification,
            //   which always returns 17 digits of precision, or "R", which returns 15 digits if the number
            //   can be represented with that precision or 17 digits if the number can only be represented
            //   with maximum precision.
            var str = value.ToString("g17");

            // HACK: C compiler requires dot-notation for float type literal.
            return str.Contains(".") ? str : (str + ".0");
        }

        private static void AppendEscapedCharString(StringBuilder sb, char ch)
        {
            switch (ch)
            {
                case '"':
                case '\\':
                    sb.Append('\\');
                    sb.Append(ch);
                    break;
                case '\a':
                    sb.Append("\\a");
                    break;
                case '\b':
                    sb.Append("\\b");
                    break;
                case '\n':
                    sb.Append("\\n");
                    break;
                case '\r':
                    sb.Append("\\r");
                    break;
                case '\f':
                    sb.Append("\\f");
                    break;
                case '\v':
                    sb.Append("\\v");
                    break;
                default:
                    var cat = char.GetUnicodeCategory(ch);
                    switch (cat)
                    {
                        case UnicodeCategory.Control:
                        case UnicodeCategory.PrivateUse:
                        case UnicodeCategory.OtherNotAssigned:
                            sb.AppendFormat("\\x{0:x4}", (ushort)ch);
                            break;
                        default:
                            sb.Append(ch);
                            break;
                    }
                    break;
            }
        }

        public static string GetCLanguageExpression(char value)
        {
            var sb = new StringBuilder("L'");
            AppendEscapedCharString(sb, value);
            sb.Append('\'');
            return sb.ToString();
        }

        public static string GetCLanguageExpression(string value)
        {
            var sb = new StringBuilder("L\"");
            foreach (var ch in value)
            {
                AppendEscapedCharString(sb, ch);
            }
            sb.Append('"');
            return sb.ToString();
        }

        public static string GetCLanguageExpression(bool value) =>
            value ? "true" : "false";

        public static string GetCLanguageExpression(IntPtr value) =>
            string.Format("((intptr_t){0})", GetCLanguageExpression(value.ToInt64()));

        public static string GetCLanguageExpression(UIntPtr value) =>
            string.Format("((uintptr_t){0})", GetCLanguageExpression(value.ToUInt64()));

        public static string GetCLanguageExpression(Enum value) =>
            Enum.IsDefined(value.GetType(), value) ?
                string.Format("{0}_{1}",
                    GetMangledName(value.GetType().FullName!),
                    value) :
                string.Format("({0}){1}",
                    GetMangledName(value.GetType().FullName!),
                    GetCLanguageExpression(
                        value.GetType().
                        GetFields(BindingFlags.Public | BindingFlags.NonPublic | BindingFlags.Instance | BindingFlags.DeclaredOnly).
                        First().
                        GetValue(value)!));

        public static string GetCLanguageExpression(Array arr)
        {
            return string.Format(
                "{{ {0} }}",
                string.Join(
                    ", ",
                    ((IEnumerable)arr).RuntimeCast<object>().Select(GetCLanguageExpression)));
        }

        public static string GetCLanguageExpression(object value)
        {
            if (value == null) return "NULL";
            if (value is int) return GetCLanguageExpression((int)value);
            if (value is uint) return GetCLanguageExpression((uint)value);
            if (value is long) return GetCLanguageExpression((long)value);
            if (value is ulong) return GetCLanguageExpression((ulong)value);
            if (value is IntPtr) return GetCLanguageExpression((IntPtr)value);
            if (value is UIntPtr) return GetCLanguageExpression((UIntPtr)value);
            if (value is float) return GetCLanguageExpression((float)value);
            if (value is double) return GetCLanguageExpression((double)value);
            if (value is bool) return GetCLanguageExpression((bool)value);
            if (value is char) return GetCLanguageExpression((char)value);
            if (value is string) return GetCLanguageExpression((string)value);
            if (value is Enum) return GetCLanguageExpression((Enum)value);
            if (value is Array) return GetCLanguageExpression((Array)value);
            return value.ToString() ?? "NULL";
        }
        #endregion

        public static string GetCSharpLanguageExpression(object value)
        {
            if (value == null) return "null";
            if (value is bool) return (bool)value ? "true" : "false";
            if (value is string) return string.Format("\"{0}\"", value);
            if (value is char) return string.Format("'{0}'", value);
            if (value is Array) return string.Format(
                "{0}[{1}]",
                value.GetType().GetElementType()!.Name,
                string.Join(
                    ", ",
                    ((IEnumerable)value).RuntimeCast<object>().Select(GetCSharpLanguageExpression)));
            return value.ToString() ?? "null";
        }

        #region GetGivenParameterDeclaration
        public struct RightExpressionGivenParameter
        {
            public readonly ITypeInformation TargetType;
            public readonly IVariableInformation SymbolInformation;
            public readonly string? Expression;

            public RightExpressionGivenParameter(
                ITypeInformation targetType, IVariableInformation symbolinformation, string? expression = null)
            {
                this.TargetType = targetType;
                this.SymbolInformation = symbolinformation;
                this.Expression = expression;
            }

            public override string ToString()
            {
                return string.Format("{0} <-- {1}{2}",
                    this.TargetType.FriendlyName,
                    (this.Expression != null) ? (this.Expression + " ") : string.Empty,
                    (this.Expression != null) ? ("[" + this.SymbolInformation + "]") : string.Empty);
            }
        }

        public static string GetGivenParameterDeclaration(
            RightExpressionGivenParameter[] parameters,
            IExtractContext extractContext,
            ICodeInformation codeInformation)
        {
            return string.Join(", ", parameters.Select(parameter =>
            {
                var rightExpression = (parameter.Expression != null) ?
                    extractContext.GetRightExpression(parameter.TargetType, parameter.SymbolInformation.TargetType, parameter.Expression) :
                    extractContext.GetRightExpression(parameter.TargetType, parameter.SymbolInformation);
                if (rightExpression == null)
                {
                    throw new InvalidProgramSequenceException(
                        "Invalid parameter type: Location={0}, StackType={1}, ParameterType={2}",
                        codeInformation.RawLocation,
                        parameter.SymbolInformation.TargetType.FriendlyName,
                        parameter.TargetType.FriendlyName);
                }

                return rightExpression;
            }));
        }
        #endregion
    }
}
