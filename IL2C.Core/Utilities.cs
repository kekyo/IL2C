using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Text;

using Mono.Cecil;
using Mono.Cecil.Cil;
using Mono.Cecil.Rocks;

using IL2C.ILConveters;
using IL2C.Translators;

namespace IL2C
{
    internal static class Utilities
    {
        private static readonly char[] replaceChars = { '.', '@' };
        private static readonly Dictionary<OpCode, ILConverter> ilConverters;

        static Utilities()
        {
            ilConverters = typeof(ILConverter)
                .Assembly
                .GetTypes()
                .Where(type => type.IsSealed && typeof(ILConverter).IsAssignableFrom(type))
                .Select(type => (ILConverter)Activator.CreateInstance(type))
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

        public static TypeReference GetStackableType(this TypeReference type)
        {
            if (type.IsByteType()
                || type.IsSByteType()
                || type.IsInt16Type()
                || type.IsUInt16Type()
                || type.IsUInt32Type()
                || type.IsBooleanType()
                || type.IsCharType())
            {
                return type.GetSafeInt32Type();
            }

            if (type.IsUInt64Type())
            {
                return type.GetSafeInt64Type();
            }

            if (type.IsUIntPtrType())
            {
                return type.GetSafeIntPtrType();
            }

            return type;
        }

        public static Parameter[] GetSafeParameters(this MethodReference method, TypeReference thisType = null)
        {
            var parameters = method.Parameters
                .Select(parameter => new Parameter(parameter.Name, parameter.ParameterType));
            if (method.HasThis)
            {
                var type = method.DeclaringType;
                thisType = thisType ?? (type.IsValueType ? type.MakeByReferenceType() : type);
                parameters = new[]
                    {
                        new Parameter("this__", thisType)
                    }
                    .Concat(parameters);
            }

            return parameters.ToArray();
        }

        public static string GetMarshaledInExpression(this Parameter parameter)
        {
            if (parameter.ParameterType.IsStringType())
            {
                return string.Format("{0}->string_body__", parameter.Name);
            }
            else
            {
                return parameter.Name;
            }
        }

        public static string ManglingSymbolName(this string rawSymbolName)
        {
            var sb = new StringBuilder(rawSymbolName);
            foreach (var ch in replaceChars)
            {
                sb.Replace(ch, '_');
            }

            Debug.Assert(!rawSymbolName.Contains("*"));

            sb.Replace("*", "_reference");
            return sb.ToString();
        }

        public static string GetFunctionPrototypeString(
            string methodName,
            TypeReference returnType,
            Parameter[] parameters,
            IExtractContext extractContext)
        {
            var parametersString = string.Join(
                ", ",
                parameters.Select(parameter => string.Format(
                    "{0} {1}",
                    extractContext.GetCLanguageTypeName(parameter.ParameterType),
                    parameter.Name)));

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
            TypeReference returnType,
            Parameter[] parameters,
            IExtractContext extractContext)
        {
            var parametersString = string.Join(
                ", ",
                parameters.Select(parameter => string.Format(
                    "{0} {1}",
                    extractContext.GetCLanguageTypeName(parameter.ParameterType),
                    parameter.Name)));

            var returnTypeName =
                extractContext.GetCLanguageTypeName(returnType);

            return string.Format(
                "{0} (*{1})({2})",
                returnTypeName,
                methodName.ManglingSymbolName(),
                (parametersString.Length >= 1) ? parametersString : "void");
        }

        public static string GetStaticFieldPrototypeString(
            FieldReference field,
            bool requireInitializerExpression,
            IExtractContext extractContext)
        {
            var initializer = String.Empty;
            if (requireInitializerExpression)
            {
                if (field.FieldType.IsNumericPrimitive())
                {
                    // TODO: numericPrimitive and (literal or readonly static) ?
                    var fieldDefinition = field.Resolve();
                    Debug.Assert(fieldDefinition.IsStatic);
                    var value = fieldDefinition.HasConstant ? fieldDefinition.Constant : 0;

                    Debug.Assert(value != null);

                    initializer = fieldDefinition.FieldType.IsInt64Type()
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
            public readonly TypeReference TargetType;
            public readonly SymbolInformation SymbolInformation;

            public RightExpressionGivenParameter(
                TypeReference targetType, SymbolInformation symbolinformation)
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

        public static void ForEach<T>(this IEnumerable<T> enumerable, Action<T> action)
        {
            foreach (var value in enumerable)
            {
                action(value);
            }
        }

        public static void ForEach<T>(this IEnumerable<T> enumerable, Action<T, int> action)
        {
            var index = 0;
            foreach (var value in enumerable)
            {
                action(value, index++);
            }
        }

        public static U UnsafeGetValue<T, U>(this IReadOnlyDictionary<T, U> dict, T key, U defaultValue = default(U))
        {
            return dict.TryGetValue(key, out var value) ? value : defaultValue;
        }
    }
}
