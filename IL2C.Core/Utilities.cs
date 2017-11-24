using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Reflection;
using IL2C.ILConveters;
using IL2C.Translators;

namespace IL2C
{
    internal static class Utilities
    {
        private static readonly Dictionary<ushort, ILConverter> ilConverters;

        static Utilities()
        {
            ilConverters = typeof(ILConverter)
                .Assembly
                .GetTypes()
                .Where(type => type.IsSealed && typeof(ILConverter).IsAssignableFrom(type))
                .Select(type => (ILConverter) Activator.CreateInstance(type))
                .ToDictionary(ilc => (ushort) ilc.OpCode.Value);
        }

        public static bool TryGetILConverter(ushort opCodeBytes, out ILConverter ilc)
        {
            return ilConverters.TryGetValue(opCodeBytes, out ilc);
        }

        public static Parameter[] GetSafeParameters(this MethodBase method)
        {
            var parameters = method.GetParameters()
                .Select(parameter => new Parameter(parameter.Name, parameter.ParameterType));
            if (method.IsStatic == false)
            {
                var type = method.DeclaringType;
                var thisType = type.IsValueType ? type.MakeByRefType() : type;
                parameters = new[]
                    {
                        new Parameter("__this", thisType)
                    }
                    .Concat(parameters);
            }

            return parameters.ToArray();
        }

        public static bool IsNumericPrimitive(Type type)
        {
            if (type == typeof(Byte))
            {
                return true;
            }
            if (type == typeof(SByte))
            {
                return true;
            }
            if (type == typeof(Int16))
            {
                return true;
            }
            if (type == typeof(UInt16))
            {
                return true;
            }
            if (type == typeof(Int32))
            {
                return true;
            }
            if (type == typeof(UInt32))
            {
                return true;
            }
            if (type == typeof(Int64))
            {
                return true;
            }
            if (type == typeof(UInt64))
            {
                return true;
            }

            return false;
        }

        public static string GetFullMemberName(MemberInfo member)
        {
            if (member.DeclaringType != null)
            {
                var declaringTypes = member.DeclaringType
                    .Traverse(current => current.DeclaringType)
                    .Reverse()
                    .ToArray();

                return String.Format(
                    "{0}.{1}.{2}",
                    declaringTypes.First().Namespace,
                    String.Join(".", declaringTypes.Select(dt => dt.Name)),
                    member.Name);
            }
            else
            {
                var type = member as Type;
                if (type != null)
                {
                    return type.FullName;
                }
                else
                {
                    return member.Name;
                }
            }
        }

        public static string ManglingSymbolName(this string rawSymbolName)
        {
            return rawSymbolName
                .Replace('.', '_')
                .Replace("*", "_reference");
        }

        public static string GetFunctionPrototypeString(
            string methodName,
            Type returnType,
            Parameter[] parameters,
            IExtractContext extractContext)
        {
            var parametersString = String.Join(
                ", ",
                parameters.Select(parameter => String.Format(
                    "{0} {1}",
                    extractContext.GetCLanguageTypeName(parameter.ParameterType),
                    parameter.Name)));

            var returnTypeName =
                extractContext.GetCLanguageTypeName(returnType);

            return String.Format(
                "{0} {1}({2})",
                returnTypeName,
                methodName.ManglingSymbolName(),
                (parametersString.Length >= 1) ? parametersString : "void");
        }

        public static string GetStaticFieldPrototypeString(
            FieldInfo field,
            bool requireInitializerExpression,
            IExtractContext extractContext)
        {
            var initializer = String.Empty;
            if (requireInitializerExpression)
            {
                if (IsNumericPrimitive(field.FieldType))
                {
                    // TODO: numericPrimitive and (literal or readonly static) ?
                    Debug.Assert(field.IsStatic);
                    var value = field.GetValue(null);

                    Debug.Assert(value != null);

                    initializer = (value is long)
                        ? String.Format(" = {0}LL", value)
                        : String.Format(" = {0}", value);
                }
                else if (field.FieldType.IsClass)
                {
                    initializer = " = NULL";
                }
            }

            return string.Format(
                "{0} {1}{2}",
                extractContext.GetCLanguageTypeName(field.FieldType),
                Utilities.GetFullMemberName(field).ManglingSymbolName(),
                initializer);
        }

        public struct RightExpressionGivenParameter
        {
            public readonly Type TargetType;
            public readonly SymbolInformation SymbolInformation;

            public RightExpressionGivenParameter(Type targetType, SymbolInformation symbolinformation)
            {
                this.TargetType = targetType;
                this.SymbolInformation = symbolinformation;
            }
        }

        public static string GetGivenParameterDeclaration(
            RightExpressionGivenParameter[] parameters,
            IExtractContext extractContext,
            int ilByteIndex)
        {
            return string.Join(", ", parameters.Select(entry =>
            {
                var rightExpression = extractContext.GetRightExpression(
                    entry.TargetType, entry.SymbolInformation);
                if (rightExpression == null)
                {
                    throw new InvalidProgramSequenceException(
                        "Invalid parameter type: ILByteIndex={0}, StackType={1}, ParameterType={2}",
                        ilByteIndex,
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
    }
}
