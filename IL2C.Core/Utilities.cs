using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Reflection;
using System.Text;

using Mono.Cecil.Cil;

using IL2C.ILConveters;
using IL2C.Translators;
using IL2C.Metadata;

namespace IL2C
{
    internal static class Lazy
    {
        public static Lazy<T> Create<T>(Func<T> generator)
        {
            return new Lazy<T>(generator);
        }
    }

    internal static class Utilities
    {
        private static readonly char[] replaceChars = { '.', '@', '<', '>', '$', '-', '=', ',', '.' };
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

        public static bool TryGetILConverter(OpCode opCode, out ILConverter ilc)
        {
            return ilConverters.TryGetValue(opCode, out ilc);
        }

        public static string GetEscapedCString(string value)
        {
            var encoded = Encoding.UTF8.GetBytes(value);

            var sb = new StringBuilder();
            
            var index = 0;
            while (index < encoded.Length)
            {
                var ch = (char)encoded[index++];
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
                        if (char.IsControl(ch))
                        {
                            sb.AppendFormat("\\x{0:x2}", (byte)ch);
                        }
                        else
                        {
                            sb.Append(ch);
                        }
                        break;                
                }
            }

            return sb.ToString();
        }

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
                //Debug.Assert(codeInformation.RawLocation != "IL2C.Tests.ValueTypeTest.Test5():IL_001e");

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
    }
}
