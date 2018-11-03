using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Reflection;
using System.Text;

using Mono.Cecil.Cil;

using IL2C.ILConverters;
using IL2C.Translators;
using IL2C.Metadata;
using System.Collections;

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
            ilConverters = typeof(ILConverter)
                .GetTypeInfo()
                .Assembly
                .DefinedTypes
                .Where(type => type.IsSealed && typeof(ILConverter).GetTypeInfo().IsAssignableFrom(type))
                .Select(type => (ILConverter)Activator.CreateInstance(type.AsType()))
                .ToDictionary(ilc => ilc.OpCode);
        }

        public static bool TryGetILConverter(OpCode opCode, out ILConverter ilc) =>
            ilConverters.TryGetValue(opCode, out ilc);

        public static string ToMangledName(string name)
        {
            var sb = new StringBuilder(name);
            foreach (var ch in replaceChars)
            {
                sb.Replace(ch, '_');
            }
            return sb.ToString();
        }

        #region ToCLanguageExpression
        public static string ToCLanguageExpression(int value)
        {
            // HACK: if operand is int.MinValue, compiler will cause constant literal warning:
            //   "warning: this decimal constant is unsigned only in ISO C90 [enabled by default]" (it's gcc, but vc causes same)
            //   IL2C makes the expression it special case.
            return (value != int.MinValue)
                ? value.ToString()
                : intMinValueExpression;
        }

        public static string ToCLanguageExpression(long value)
        {
            // HACK: if operand is int.MinValue, compiler will cause constant literal warning:
            //   "warning: this decimal constant is unsigned only in ISO C90 [enabled by default]" (it's gcc, but vc causes same)
            //   IL2C makes the expression it special case.
            return (value != long.MinValue)
                ? (value.ToString() + "LL")
                : longMinValueExpression;
        }

        public static string ToCLanguageExpression(uint value) =>
            value.ToString() + "U";

        public static string ToCLanguageExpression(ulong value) =>
            value.ToString() + "ULL";

        public static string ToCLanguageExpression(float value)
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

        public static string ToCLanguageExpression(double value)
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

        public static string ToCLanguageExpression(char value)
        {
            var sb = new StringBuilder("L'");
            AppendEscapedCharString(sb, value);
            sb.Append('\'');
            return sb.ToString();
        }

        public static string ToCLanguageExpression(string value)
        {
            var sb = new StringBuilder("L\"");
            foreach (var ch in value)
            {
                AppendEscapedCharString(sb, ch);
            }
            sb.Append('"');
            return sb.ToString();
        }

        public static string ToCLanguageExpression(bool value) =>
            value ? "true" : "false";

        public static string ToCLanguageExpression(IntPtr value) =>
            string.Format("((intptr_t){0})", ToCLanguageExpression(value.ToInt64()));

        public static string ToCLanguageExpression(UIntPtr value) =>
            string.Format("((uintptr_t){0})", ToCLanguageExpression(value.ToUInt64()));

        public static string ToCLanguageExpression(Enum value) =>
            Enum.IsDefined(value.GetType(), value) ?
                string.Format("{0}_{1}",
                    ToMangledName(value.GetType().FullName),
                    value) :
                string.Format("({0}){1}",
                    ToMangledName(value.GetType().FullName),
                    ToCLanguageExpression(
                        value.GetType().
                        GetFields(BindingFlags.Public | BindingFlags.NonPublic | BindingFlags.Instance | BindingFlags.DeclaredOnly).
                        First().
                        GetValue(value)));

        public static string ToCLanguageExpression(object value)
        {
            if (value == null) return "NULL";
            if (value is int) return ToCLanguageExpression((int)value);
            if (value is uint) return ToCLanguageExpression((uint)value);
            if (value is long) return ToCLanguageExpression((long)value);
            if (value is ulong) return ToCLanguageExpression((ulong)value);
            if (value is IntPtr) return ToCLanguageExpression((IntPtr)value);
            if (value is UIntPtr) return ToCLanguageExpression((UIntPtr)value);
            if (value is float) return ToCLanguageExpression((float)value);
            if (value is double) return ToCLanguageExpression((double)value);
            if (value is bool) return ToCLanguageExpression((bool)value);
            if (value is char) return ToCLanguageExpression((char)value);
            if (value is string) return ToCLanguageExpression((string)value);
            if (value is Enum) return ToCLanguageExpression((Enum)value);
            return value.ToString();
        }
        #endregion

        public static string GetMarshaledInExpression(this VariableInformation parameter)
        {
            if (parameter.TargetType.IsStringType)
            {
                return string.Format("{0}->string_body__", parameter.SymbolName);
            }

            if (parameter.TargetType.IsEnum)
            {
                return string.Format(
                    "({0}){1}",
                    parameter.TargetType.Name,      // Simple enum type name for use P/Invoke.
                    parameter.SymbolName);
            }

            return parameter.SymbolName;
        }

        public struct RightExpressionGivenParameter
        {
            public readonly ITypeInformation TargetType;
            public readonly VariableInformation SymbolInformation;

            public RightExpressionGivenParameter(
                ITypeInformation targetType, VariableInformation symbolinformation)
            {
                this.TargetType = targetType;
                this.SymbolInformation = symbolinformation;
            }

            public override string ToString()
            {
                return string.Format("{0} <-- {1}", this.TargetType.FriendlyName, this.SymbolInformation);
            }
        }

        public static string GetGivenParameterDeclaration(
            RightExpressionGivenParameter[] parameters,
            IExtractContext extractContext,
            ICodeInformation codeInformation)
        {
            return string.Join(", ", parameters.Select(entry =>
            {
                var rightExpression = extractContext.GetRightExpression(
                    entry.TargetType, entry.SymbolInformation);
                if (rightExpression == null)
                {
                    throw new InvalidProgramSequenceException(
                        "Invalid parameter type: Location={0}, StackType={1}, ParameterType={2}",
                        codeInformation.RawLocation,
                        entry.SymbolInformation.TargetType.FriendlyName,
                        entry.TargetType.FriendlyName);
                }

                return rightExpression;
            }));
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

        public static KeyValuePair<TKey, TValue> KeyValue<TKey, TValue>(TKey key, TValue value)
        {
            return new KeyValuePair<TKey, TValue>(key, value);
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
                    var ex = ((IEnumerable)x).Cast<object>();
                    var ey = ((IEnumerable)x).Cast<object>();
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
                        Cast<object>().
                        Aggregate(0, (s, v) => s ^ this.GetHashCode(v));
                }
                return obj.GetHashCode();
            }
        }

        public static readonly IEqualityComparer<object> LooseTypeKindComparer = new LooseTypeKindComparerImpl();
    }
}
