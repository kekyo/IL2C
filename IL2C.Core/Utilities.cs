using System;
using System.Collections;
using System.Collections.Generic;
using System.Diagnostics;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Text;

using Mono.Cecil.Cil;

using IL2C.ILConverters;
using IL2C.Translators;
using IL2C.Metadata;

namespace IL2C
{
    internal static class Utilities
    {
        private static readonly string intMinValueExpression = string.Format("{0} - 1", int.MinValue + 1);
        private static readonly string longMinValueExpression = string.Format("{0}LL - 1LL", long.MinValue + 1);

        private static readonly char[] replaceChars = {
            '.', ',', '@', '+', '-', '*', '/', '^', '\\', '#', '%', '&', '$', '?', '!', '=', '~', '|',
            '(', ')', '<', '>', '[', ']', '{', '}', '\'', '"', '`', ';', ':', ' ' };

        private static readonly Dictionary<OpCode, ILConverter> ilConverters;

        static Utilities()
        {
            ilConverters = typeof(ILConverter).
                GetTypeInfo().
                Assembly.
                DefinedTypes.
                Where(type => type.IsSealed && typeof(ILConverter).GetTypeInfo().IsAssignableFrom(type)).
                Select(type => (ILConverter)Activator.CreateInstance(type.AsType())).
                ToDictionary(ilc => ilc.OpCode);
        }

        public static bool TryGetILConverter(OpCode opCode, out ILConverter ilc) =>
            ilConverters.TryGetValue(opCode, out ilc);

        public static string GetMangledName(string name)
        {
            var sb = new StringBuilder(name);
            foreach (var ch in replaceChars)
            {
                sb.Replace(ch, '_');
            }
            return sb.ToString();
        }

        public static string GetCLanguageTypeName(
            Type type, string symbolName = null, bool cArrayExpression = false)
        {
            var sn = (symbolName != null) ? (" " + symbolName) : string.Empty;

            if (type.IsByRef || type.IsPointer)
            {
                return string.Format(
                    "{0}*{1}",
                    GetCLanguageTypeName(type.GetElementType()),
                    sn);
            }

            if (type.IsArray)
            {
                if (cArrayExpression)
                {
                    return string.Format(
                        "{0}{1}[]",
                        GetCLanguageTypeName(type.GetElementType(), null, true),
                        sn);
                }
                else
                {
                    return string.Format(
                        "{0}*{1}",
                        GetCLanguageTypeName(type.GetElementType(), null, true),
                        sn);
                }
            }

            string typeName = null;
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
                typeName = GetMangledName(type.FullName);
                if (!type.IsValueType)
                {
                    typeName += "*";
                }
            }

            Debug.Assert(typeName != null);

            return typeName + sn;
        }

        #region GetCLanguageSizeOf
        private static string InternalGetCLanguageSizeOfExpression(Type type)
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
                    GetMangledName(value.GetType().FullName),
                    value) :
                string.Format("({0}){1}",
                    GetMangledName(value.GetType().FullName),
                    GetCLanguageExpression(
                        value.GetType().
                        GetFields(BindingFlags.Public | BindingFlags.NonPublic | BindingFlags.Instance | BindingFlags.DeclaredOnly).
                        First().
                        GetValue(value)));

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
            return value.ToString();
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
                value.GetType().GetElementType().Name,
                string.Join(
                    ", ",
                    ((IEnumerable)value).RuntimeCast<object>().Select(GetCSharpLanguageExpression)));
            return value.ToString();
        }

        public static Array ResourceDataToSpecificArray(byte[] values, Type elementType)
        {
            if (elementType == typeof(byte))
            {
                return values;
            }

            var ms = new MemoryStream(values);
            var br = new EndiannessBinaryReader(ms, EndianSpecific.Little, Encoding.Unicode);
            var temp = new ArrayList();

            if (elementType == typeof(sbyte))
            {
                while (!br.IsEOF)
                {
                    temp.Add(br.ReadSByte());
                }
            }
            else if (elementType == typeof(short))
            {
                while (!br.IsEOF)
                {
                    temp.Add(br.ReadInt16());
                }
            }
            else if (elementType == typeof(int))
            {
                while (!br.IsEOF)
                {
                    temp.Add(br.ReadInt32());
                }
            }
            else if (elementType == typeof(long))
            {
                while (!br.IsEOF)
                {
                    temp.Add(br.ReadInt64());
                }
            }
            else if (elementType == typeof(ushort))
            {
                while (!br.IsEOF)
                {
                    temp.Add(br.ReadUInt16());
                }
            }
            else if (elementType == typeof(uint))
            {
                while (!br.IsEOF)
                {
                    temp.Add(br.ReadUInt32());
                }
            }
            else if (elementType == typeof(ulong))
            {
                while (!br.IsEOF)
                {
                    temp.Add(br.ReadUInt64());
                }
            }
            else if (elementType == typeof(float))
            {
                while (!br.IsEOF)
                {
                    temp.Add(br.ReadSingle());
                }
            }
            else if (elementType == typeof(double))
            {
                while (!br.IsEOF)
                {
                    temp.Add(br.ReadDouble());
                }
            }
            else if (elementType == typeof(char))
            {
                while (!br.IsEOF)
                {
                    temp.Add(br.ReadChar());
                }
            }
            else if (elementType == typeof(bool))
            {
                while (!br.IsEOF)
                {
                    temp.Add(br.ReadBoolean());
                }
            }
            else
            {
                Debug.Fail("Cannot convert");
            }

            return temp.ToArray(elementType);
        }

        public static string GetMarshaledInExpression(this IParameterInformation parameter)
        {
            if (parameter.TargetType.IsStringType)
            {
                return string.Format("{0}->string_body__", parameter.ParameterName);
            }

            if (parameter.TargetType.IsEnum)
            {
                return string.Format(
                    "({0}){1}",
                    parameter.TargetType.Name,      // Simple enum type name for use P/Invoke.
                    parameter.ParameterName);
            }

            return parameter.ParameterName;
        }

        public struct RightExpressionGivenParameter
        {
            public readonly ITypeInformation TargetType;
            public readonly IVariableInformation SymbolInformation;
            public readonly string Expression;

            public RightExpressionGivenParameter(
                ITypeInformation targetType, IVariableInformation symbolinformation, string expression = null)
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

        #region Linq
        public static IEnumerable<T> RuntimeCast<T>(this IEnumerable enumerable)
        {
            foreach (object value in enumerable)
            {
                yield return (T)value;
            }
        }

        public static IEnumerable<T> Traverse<T>(this T first, Func<T, T> next, bool invokeNextFirst = false)
            where T : class
        {
            T current = first;
            if (invokeNextFirst)
            {
                if (current != null)
                {
                    while (true)
                    {
                        current = next(current);
                        if (current == null)
                        {
                            break;
                        }
                        yield return current;
                    }
                }
            }
            else
            {
                while (current != null)
                {
                    yield return current;
                    current = next(current);
                }
            }
        }

        public static IEnumerable<T> Distinct<T, U>(
            this IEnumerable<T> enumerable,
            Func<T, U> keySelector)
        {
            var took = new HashSet<U>();
            foreach (var value in enumerable)
            {
                if (took.Add(keySelector(value)))
                {
                    yield return value;
                }
            }
        }

        private sealed class DistinctEqualityComparer<T> : IEqualityComparer<T>
        {
            private readonly Func<T, int> getHashCode;
            private readonly Func<T, T, bool> equals;

            public DistinctEqualityComparer(
                Func<T, int> getHashCode,
                Func<T, T, bool> equals)
            {
                this.getHashCode = getHashCode;
                this.equals = equals;
            }

            public bool Equals(T x, T y)
            {
                return equals(x, y);
            }

            public int GetHashCode(T obj)
            {
                return getHashCode(obj);
            }
        }

        public static IEnumerable<T> Distinct<T>(
            this IEnumerable<T> enumerable,
            Func<T, int> getHashCode,
            Func<T, T, bool> equals)
        {
            var took = new HashSet<T>(new DistinctEqualityComparer<T>(getHashCode, equals));
            foreach (var value in enumerable)
            {
                if (took.Add(value))
                {
                    yield return value;
                }
            }
        }
        #endregion

        public static U UnsafeGetValue<T, U>(this IReadOnlyDictionary<T, U> dict, T key, U defaultValue = default(U))
        {
            return dict.TryGetValue(key, out var value) ? value : defaultValue;
        }

        public static U GetOrAdd<T, U>(this Dictionary<T, U> dict, T key, U value)
        {
            if (dict.TryGetValue(key, out var v) == false)
            {
                v = value;
                dict.Add(key, v);
            }

            return v;
        }

        private sealed class LooseTypeKindComparerImpl
            : IEqualityComparer<object>
        {
            public LooseTypeKindComparerImpl()
            {
            }

            public new bool Equals(object x, object y)
            {
                if (object.ReferenceEquals(x, y))
                {
                    return true;
                }

                var tx = x.GetType();
                var ty = y.GetType();
                if (!tx.Equals(ty))
                {
                    return false;
                }

                if (x is string)
                {
                    return x.Equals(y);
                }
                if (x is IEnumerable)
                {
                    var ex = ((IEnumerable)x).RuntimeCast<object>();
                    var ey = ((IEnumerable)x).RuntimeCast<object>();
                    return ex.SequenceEqual(ey, this);
                }

                return x.Equals(y);
            }

            public int GetHashCode(object obj)
            {
                if (obj is string)
                {
                    return obj.GetHashCode();
                }
                if (obj is IEnumerable)
                {
                    return ((IEnumerable)obj).
                        RuntimeCast<object>().
                        Aggregate(0, (s, v) => s ^ this.GetHashCode(v));
                }
                return obj.GetHashCode();
            }
        }

        public static readonly IEqualityComparer<object> LooseTypeKindComparer = new LooseTypeKindComparerImpl();
    }
}
