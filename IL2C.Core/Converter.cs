using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Reflection;

namespace IL2C
{
    public static class Converter
    {
        internal static IEnumerable<ILData> DecodeAndEnumerateOpCodes(DecodeContext decodeContext)
        {
            while (true)
            {
                var label = decodeContext.MakeLabel();
                if (decodeContext.TryDecode(out var ilc) == false)
                {
                    break;
                }

                var operand = ilc.DecodeOperand(decodeContext);
                yield return new ILData(label, ilc, operand);

                if (ilc.IsEndOfPath)
                {
                    yield break;
                }
            }
        }

        public static void ConvertType(
            TranslateContext translateContext,
            TextWriter tw,
            Type type,
            string indent)
        {
            if (type.IsValueType && (type.IsPrimitive == false))
            {
                var structName = translateContext.GetCLanguageTypeName(type)
                    .ManglingSymbolName();

                tw.WriteLine(string.Format(
                    "typedef struct {0}",
                    structName));

                tw.WriteLine("{");

                foreach (var field in type.GetFields(
                    BindingFlags.Public | BindingFlags.NonPublic
                    | BindingFlags.Instance | BindingFlags.DeclaredOnly))
                {
                    tw.WriteLine(string.Format(
                        "{0}{1} {2};",
                        indent,
                        translateContext.GetCLanguageTypeName(field.FieldType),
                        field.Name));
                }

                tw.WriteLine(string.Format(
                    "}} {0};",
                    structName));
            }
        }

        public static void ConvertMethod(
            TranslateContext translateContext,
            TextWriter tw,
            Type type,
            string indent)
        {
            foreach (var method in type.GetMethods(
                BindingFlags.Public | BindingFlags.NonPublic |
                BindingFlags.Static | BindingFlags.DeclaredOnly))
            {
                ConvertMethod(translateContext, tw, method, indent);
                tw.WriteLine();
            }
        }

        public static void ConvertMethod(
            TranslateContext translateContext,
            TextWriter tw,
            MethodInfo method,
            string indent)
        {
            var methodName = Utilities.GetFullMemberName(method);

            InternalConvert(
                translateContext,
                tw,
                method.ReturnType,
                methodName,
                method.GetParameters(),
                method.GetMethodBody(),
                indent);
        }

        private struct GeneratedSourceCode
        {
            public readonly Label Label;
            public readonly string SourceCode;

            public GeneratedSourceCode(Label label, string sourceCode)
            {
                this.Label = label;
                this.SourceCode = sourceCode;
            }
        }

        private static void InternalConvert(
            TranslateContext translateContext,
            TextWriter tw,
            Type returnType,
            string methodName,
            ParameterInfo[] parameters,
            MethodBody body,
            string indent)
        {
            var locals = body.LocalVariables;

            var returnTypeName =
                translateContext.GetCLanguageTypeName(returnType);

            var decodeContext = new DecodeContext(
                methodName,
                returnType,
                parameters,
                locals,
                body.GetILAsByteArray(),
                translateContext);

            var bodySourceCode = new List<GeneratedSourceCode>();
            while (decodeContext.TryDequeueNextPath())
            {
                bodySourceCode.AddRange(
                    from ilData in DecodeAndEnumerateOpCodes(decodeContext)
                    let sourceCode = ilData.ILConverter.Apply(ilData.Operand, decodeContext)
                    select new GeneratedSourceCode(ilData.Label, sourceCode));
            }

            var found = false;
            foreach (var fi in decodeContext.ExtractStaticFields())
            {
                var initializer = string.Empty;
                if (Utilities.IsNumericPrimitive(fi.FieldType))
                {
                    Debug.Assert(fi.IsStatic);
                    var value = fi.GetValue(null);

                    Debug.Assert(value != null);

                    initializer = (value is long)
                        ? string.Format(" = {0}LL", value)
                        : string.Format(" = {0}", value);
                }

                tw.WriteLine(
                    "{0} {1}{2};",
                    translateContext.GetCLanguageTypeName(fi.FieldType),
                    Utilities.GetFullMemberName(fi).ManglingSymbolName(),
                    initializer);
                found = true;
            }

            if (found)
            {
                tw.WriteLine();
            }

            var parametersString = string.Join(
                ", ",
                parameters.Select(parameter => string.Format(
                    "{0} {1}",
                    translateContext.GetCLanguageTypeName(parameter.ParameterType),
                    parameter.Name)));

            tw.WriteLine("{0} {1}({2})",
                returnTypeName,
                methodName.ManglingSymbolName(),
                (parametersString.Length >= 1) ? parametersString : "void");
            tw.WriteLine("{");

            foreach (var local in locals)
            {
                tw.WriteLine(
                    "{0}{1} local{2};",
                    indent,
                    translateContext.GetCLanguageTypeName(local.LocalType),
                    local.LocalIndex);
            }

            tw.WriteLine();

            foreach (var si in decodeContext.ExtractStacks())
            {
                tw.WriteLine(
                    "{0}{1} {2};",
                    indent,
                    translateContext.GetCLanguageTypeName(si.TargetType),
                    si.SymbolName);
            }

            tw.WriteLine();

            foreach (var entry in bodySourceCode)
            {
                if (decodeContext.TryGetLabelName(
                    entry.Label, out var labelName))
                {
                    tw.WriteLine("{0}:", labelName);
                }

                if (entry.SourceCode != null)
                {
                    tw.WriteLine(
                        "{0}{1};",
                        indent, entry.SourceCode);
                }
            }

            tw.WriteLine("}");
        }
    }
}
