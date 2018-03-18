using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Reflection;
using System.Text;

using Mono.Cecil;
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

            var resolved = parameter.ParameterType.Resolve();
            if (resolved.IsEnum)
            {
                return string.Format(
                    "({0}){1}",
                    resolved.Name,      // Simple enum type name for use P/Invoke.
                    parameter.SymbolName);
            }

            return parameter.Name;
        }

        public static string GetFunctionPrototypeString(
            string methodName,
            ITypeInformation returnType,
            VariableInformation[] parameters,
            IExtractContext extractContext)
        {
            var parametersString = string.Join(
                ", ",
                parameters.Select(parameter => string.Format(
                    "{0} {1}",
                    extractContext.GetCLanguageTypeName(parameter.TargetType),
                    parameter.SymbolName)));

            var returnTypeName =
                extractContext.GetCLanguageTypeName(returnType);

            return string.Format(
                "{0} {1}({2})",
                returnTypeName,
                methodName.ManglingSymbolName(),
                (parametersString.Length >= 1) ? parametersString : "void");
        }

        public static string GetFunctionTypeString(
            string methodName,
            ITypeInformation returnType,
            VariableInformation[] parameters,
            IExtractContext extractContext)
        {
            var parametersString = string.Join(
                ", ",
                parameters.Select(parameter => string.Format(
                    "{0} {1}",
                    extractContext.GetCLanguageTypeName(parameter.TargetType),
                    parameter.SymbolName)));

            var returnTypeName =
                extractContext.GetCLanguageTypeName(returnType);

            return string.Format(
                "{0} (*{1})({2})",
                returnTypeName,
                methodName.ManglingSymbolName(),
                (parametersString.Length >= 1) ? parametersString : "void");
        }

        public static string GetFunctionTypeString(
            TypeReference returnType,
            TypeReference[] parameterTypes,
            IExtractContext extractContext)
        {
            var parametersString = string.Join(
                ", ",
                parameterTypes.Select(parameterType =>
                    extractContext.GetCLanguageTypeName(parameterType)));

            var returnTypeName =
                extractContext.GetCLanguageTypeName(returnType);

            return string.Format(
                "{0} (*)({1})",
                returnTypeName,
                (parametersString.Length >= 1) ? parametersString : "void");
        }

        public static string GetStaticFieldPrototypeString(
            IFieldInformation field,
            bool requireInitializerExpression,
            IExtractContext extractContext)
        {
            var initializer = String.Empty;
            if (requireInitializerExpression)
            {
                if (field.FieldType.IsNumericPrimitive)
                {
                    // TODO: numericPrimitive and (literal or readonly static) ?
                    Debug.Assert(field.IsStatic);
                    var value = field.HasConstant ? field.ConstantValue : 0;

                    Debug.Assert(value != null);

                    initializer = field.FieldType.IsInt64Type
                        ? String.Format(" = {0}LL", value)
                        : String.Format(" = {0}", value);
                }
                else if (field.FieldType.IsValueType == false)
                {
                    initializer = " = NULL";
                }
            }

            return string.Format(
                "{0} {1}{2}",
                extractContext.GetCLanguageTypeName(field.FieldType),
                field.GetFullMemberName().ManglingSymbolName(),
                initializer);
        }

        public struct RightExpressionGivenParameter
        {
            public readonly TypeInformation TargetType;
            public readonly SymbolInformation SymbolInformation;

            public RightExpressionGivenParameter(
                TypeInformation targetType, SymbolInformation symbolinformation)
            {
                this.TargetType = targetType;
                this.SymbolInformation = symbolinformation;
            }

            public override string ToString()
            {
                return string.Format("{0} <-- {1}", this.TargetType.GetFullMemberName(), this.SymbolInformation);
            }
        }

        public static string GetGivenParameterDeclaration(
            RightExpressionGivenParameter[] parameters,
            IExtractContext extractContext,
            int offset)
        {
            return string.Join(", ", parameters.Select(entry =>
            {
                var rightExpression = extractContext.GetRightExpression(
                    entry.TargetType, entry.SymbolInformation);
                if (rightExpression == null)
                {
                    throw new InvalidProgramSequenceException(
                        "Invalid parameter type: Offset={0}, StackType={1}, ParameterType={2}",
                        offset,
                        entry.SymbolInformation.TargetType.FullName,
                        entry.TargetType.FullName);
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

        public static KeyValuePair<TKey, TValue> KeyValue<TKey, TValue>(TKey key, TValue value)
        {
            return new KeyValuePair<TKey, TValue>(key, value);
        }
    }
}
