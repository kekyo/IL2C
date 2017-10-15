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

        public static void ConvertToHeader(
            TextWriter twHeader,
            Assembly assembly,
            TranslateContext translateContext,
            string indent)
        {
            var assemblyName = assembly.GetName().Name;

            twHeader.WriteLine("#ifndef __MODULE_{0}__", assemblyName);
            twHeader.WriteLine("#define __MODULE_{0}__", assemblyName);

            twHeader.WriteLine();

            foreach (var fileName in translateContext.EnumerateRequiredIncludeFileNames())
            {
                twHeader.WriteLine("#include <{0}>", fileName);
            }

            twHeader.WriteLine();

            foreach (var type in
                from type in assembly.GetTypes()
                where type.IsValueType
                select type)
            {
                ConvertType(
                    translateContext,
                    twHeader,
                    type,
                    indent);

                twHeader.WriteLine();
            }

            foreach (var field in
                from type in assembly.GetTypes()
                where type.IsValueType
                from field in type.GetFields(
                    BindingFlags.Public |
                    BindingFlags.Static | BindingFlags.DeclaredOnly)
                select field)
            {
                twHeader.WriteLine(
                    "extern {0};",
                    Utilities.GetStaticFieldPrototypeString(field, false, translateContext));
            }

            twHeader.WriteLine();

            foreach (var method in
                from type in assembly.GetTypes()
                where type.IsClass || type.IsValueType
                from method in type.GetMethods(
                    BindingFlags.Public |
                    BindingFlags.Static | BindingFlags.Instance | BindingFlags.DeclaredOnly)
                select method)
            {
                var methodName = Utilities.GetFullMemberName(method);

                var functionPrototype = Utilities.GetFunctionPrototypeString(
                    methodName,
                    method.ReturnType,
                    method.GetSafeParameters(),
                    translateContext);

                twHeader.WriteLine("extern {0};", functionPrototype);
            }

            twHeader.WriteLine();
            twHeader.WriteLine("#endif");
        }

        public static void ConvertToSourceCode(
            TextWriter twSource,
            Assembly assembly,
            TranslateContext translateContext,
            string indent)
        {
            var assemblyName = assembly.GetName().Name;

            twSource.WriteLine("#include \"{0}.h\"", assemblyName);
            twSource.WriteLine();

            // TODO: prototypes (internal/private types and methods)

            foreach (var field in
                from type in assembly.GetTypes()
                where type.IsValueType
                from field in type.GetFields(
                    BindingFlags.Public | BindingFlags.NonPublic |
                    BindingFlags.Static | BindingFlags.DeclaredOnly)
                select field)
            {
                twSource.WriteLine(
                    "{0};",
                    Utilities.GetStaticFieldPrototypeString(field, true, translateContext));
            }

            twSource.WriteLine();

            foreach (var method in
                from type in assembly.GetTypes()
                where type.IsClass || type.IsValueType
                from method in type.GetMethods(
                    BindingFlags.Public | BindingFlags.NonPublic |
                    BindingFlags.Static | BindingFlags.Instance | BindingFlags.DeclaredOnly)
                select method)
            {
                ConvertMethod(
                    translateContext,
                    twSource,
                    method,
                    indent);

                twSource.WriteLine();
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

                tw.WriteLine(String.Format(
                    "typedef struct {0}",
                    structName));

                tw.WriteLine("{");

                foreach (var field in type.GetFields(
                    BindingFlags.Public | BindingFlags.NonPublic
                    | BindingFlags.Instance | BindingFlags.DeclaredOnly))
                {
                    tw.WriteLine(String.Format(
                        "{0}{1} {2};",
                        indent,
                        translateContext.GetCLanguageTypeName(field.FieldType),
                        field.Name));
                }

                tw.WriteLine(String.Format(
                    "}} {0};",
                    structName));
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
                method.Module,
                methodName,
                method.ReturnType,
                method.GetSafeParameters(),
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
            Module module,
            string methodName,
            Type returnType,
            Parameter[] parameters,
            MethodBody body,
            string indent)
        {
            var locals = body.LocalVariables;

            var decodeContext = new DecodeContext(
                module,
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

            tw.WriteLine();

            var functionPrototype = Utilities.GetFunctionPrototypeString(
                methodName,
                returnType,
                parameters,
                translateContext);

            tw.WriteLine(functionPrototype);
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
