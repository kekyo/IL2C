using System;
using System.Collections.Generic;
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
            twHeader.WriteLine("#ifdef __cplusplus");
            twHeader.WriteLine("extern \"C\" {");
            twHeader.WriteLine("#endif");

            twHeader.WriteLine();
            twHeader.WriteLine("//////////////////////////////////////////////////////////////////");
            twHeader.WriteLine("// Types:");

            // Output value type and object reference type.
            foreach (var type in
                from type in assembly.GetTypes()
                where type.IsValueType || type.IsClass
                select type)
            {
                twHeader.WriteLine();
                ConvertType(
                    translateContext,
                    twHeader,
                    type,
                    indent);
            }

            twHeader.WriteLine();
            twHeader.WriteLine("//////////////////////////////////////////////////////////////////");
            twHeader.WriteLine("// Public static fields:");

            foreach (var type in
                from type in assembly.GetTypes()
                where type.IsValueType || type.IsClass
                select type)
            {
                twHeader.WriteLine();

                foreach (var field in
                    from field in type.GetFields(
                        BindingFlags.Public |
                        BindingFlags.Static | BindingFlags.DeclaredOnly)
                    select field)
                {
                    twHeader.WriteLine(
                        "extern {0};",
                        Utilities.GetStaticFieldPrototypeString(field, false, translateContext));
                }
            }

            twHeader.WriteLine();
            twHeader.WriteLine("//////////////////////////////////////////////////////////////////");
            twHeader.WriteLine("// Methods:");

            foreach (var type in
                from type in assembly.GetTypes()
                where type.IsValueType || type.IsClass
                select type)
            {
                twHeader.WriteLine();

                foreach (var method in
                    from method in type.GetMembers(
                        BindingFlags.Public | BindingFlags.NonPublic
                        | BindingFlags.Static | BindingFlags.Instance
                        | BindingFlags.DeclaredOnly)
                        .OfType<MethodBase>()
                    where (method is MethodInfo) || !method.IsStatic
                    select method)
                {
                    var methodName = Utilities.GetFullMemberName(method);

                    var mi = method as MethodInfo;
                    var functionPrototype = Utilities.GetFunctionPrototypeString(
                        methodName,
                        mi?.ReturnType ?? typeof(void),
                        method.GetSafeParameters(),
                        translateContext);

                    twHeader.WriteLine("extern {0};", functionPrototype);

                    // Is this instance constructor?
                    // TODO: Type initializer's handlers
                    if (method.IsConstructor && (method.IsStatic == false))
                    {
                        var typeName = Utilities.GetFullMemberName(type);

                        // Write mark handler:
                        var makrHandlerPrototype = string.Format(
                            "extern __{0}_MARK_HANDLER__(void* pReference);",
                            typeName);
                        twHeader.WriteLine(makrHandlerPrototype);

                        // Write new:
                        var newPrototype = string.Format(
                            "extern __{0}_NEW__({0}** ppReference);",
                            typeName);

                        twHeader.WriteLine(newPrototype);
                    }
                }
            }

            twHeader.WriteLine();
            twHeader.WriteLine("#ifdef __cplusplus");
            twHeader.WriteLine("}");
            twHeader.WriteLine("#endif");

            twHeader.WriteLine();
            twHeader.WriteLine("#endif");
        }

        public static void ConvertType(
            TranslateContext translateContext,
            TextWriter tw,
            Type declaredType,
            string indent)
        {
            if (declaredType.IsPrimitive
                || !(declaredType.IsValueType || declaredType.IsClass))
            {
                return;
            }

            var structName = translateContext.GetCLanguageTypeName(declaredType, true)
                .ManglingSymbolName();

            tw.WriteLine("////////////////////////////////////////////");
            tw.WriteLine(
                "// {0}: {1}",
                declaredType.IsValueType ? "Struct" : "Class",
                Utilities.GetFullMemberName(declaredType));
            tw.WriteLine();

            tw.WriteLine(
                "typedef struct {0}",
                structName);
            tw.WriteLine("{");

            if (declaredType.IsClass)
            {
                tw.WriteLine("{0}char __dummy;", indent);
            }

            var stopType = declaredType.IsValueType
                ? typeof(ValueType)
                : typeof(object);

            var fields = declaredType
                .Traverse(type => type.BaseType)
                .TakeWhile(type => type != stopType)
                .Reverse()
                .SelectMany(type => type.GetFields(
                    BindingFlags.Public | BindingFlags.NonPublic
                    | BindingFlags.Instance | BindingFlags.DeclaredOnly))
                .ToArray();
            foreach (var field in fields)
            {
                tw.WriteLine(
                    "{0}{1} {2};",
                    indent,
                    translateContext.GetCLanguageTypeName(field.FieldType),
                    field.Name);
            }

            tw.WriteLine(
                "}} {0};",
                structName);
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
            twSource.WriteLine("#ifdef __cplusplus");
            twSource.WriteLine("extern \"C\" {");
            twSource.WriteLine("#endif");
            twSource.WriteLine();

            // TODO: prototypes (internal/private types and methods)

            twSource.WriteLine();
            twSource.WriteLine("#ifdef __cplusplus");
            twSource.WriteLine("}");
            twSource.WriteLine("#endif");

            twSource.WriteLine();
            twSource.WriteLine("//////////////////////////////////////////////////////////////////");
            twSource.WriteLine("// Static fields:");

            foreach (var type in
                from type in assembly.GetTypes()
                where type.IsClass || type.IsValueType
                select type)
            {
                twSource.WriteLine();

                foreach (var field in
                    from field in type.GetFields(
                        BindingFlags.Public | BindingFlags.NonPublic |
                        BindingFlags.Static | BindingFlags.DeclaredOnly)
                    select field)
                {
                    twSource.WriteLine(
                        "{0};",
                        Utilities.GetStaticFieldPrototypeString(field, true, translateContext));
                }
            }

            twSource.WriteLine();
            twSource.WriteLine("//////////////////////////////////////////////////////////////////");
            twSource.WriteLine("// Methods:");

            foreach (var type in
                from type in assembly.GetTypes()
                where type.IsClass || type.IsValueType
                select type)
            {
                twSource.WriteLine();
                twSource.WriteLine("////////////////////////////////////////////");
                twSource.WriteLine("// Type: {0}", Utilities.GetFullMemberName(type));

                foreach (var method in
                    from method in type.GetMembers(
                            BindingFlags.Public | BindingFlags.NonPublic
                            | BindingFlags.Static | BindingFlags.Instance
                            | BindingFlags.DeclaredOnly)
                        .OfType<MethodBase>()
                    where (method is MethodInfo) || !method.IsStatic
                    select method)
                {
                    ConvertMethod(
                        translateContext,
                        twSource,
                        method,
                        indent);
                }
            }
        }

        public static void ConvertMethod(
            TranslateContext translateContext,
            TextWriter tw,
            MethodBase method,
            string indent)
        {
            var methodName = Utilities.GetFullMemberName(method);
            var mi = method as MethodInfo;

            // Write method body:
            InternalConvert(
                translateContext,
                tw,
                method.Module,
                methodName,
                mi?.ReturnType ?? typeof(void),
                method.GetSafeParameters(),
                method.GetMethodBody(),
                indent);

            // Is this instance constructor?
            // TODO: Type initializer's handlers
            if (method.IsConstructor && (method.IsStatic == false))
            {
                tw.WriteLine();
                tw.WriteLine("//////////////////////");
                tw.WriteLine("// Runtime helpers:");

                var type = method.DeclaringType;
                var typeName = Utilities.GetFullMemberName(type);
                var baseTypeName = Utilities.GetFullMemberName(type.BaseType);

                // Write mark handler:
                var makrHandlerPrototype = string.Format(
                    "__{0}_MARK_HANDLER__(void* pReference)",
                    typeName);

                tw.WriteLine();
                tw.WriteLine(makrHandlerPrototype);
                tw.WriteLine("{");
                foreach (var field in type.GetFields(
                    BindingFlags.Public | BindingFlags.NonPublic
                    | BindingFlags.Instance | BindingFlags.DeclaredOnly))
                {
                    tw.WriteLine("{0}__TRY_MARK_FROM_HANDLER__((({1}*)pReference)->{2});", indent, typeName, field.Name);
                }
                tw.WriteLine("{0}__{1}_MARK_HANDLER__(pReference);", indent, baseTypeName);
                tw.WriteLine("}");

                // Write new:
                var newPrototype = string.Format(
                    "__{0}_NEW__({0}** ppReference)",
                    typeName);

                tw.WriteLine();
                tw.WriteLine(newPrototype);
                tw.WriteLine("{");
                tw.WriteLine("{0}__gc_get_uninitialized_object__(", indent);
                tw.WriteLine("{0}{0}(void**)ppReference,", indent);
                tw.WriteLine("{0}{0}__{1}_SIZEOF__(),", indent, typeName);
                tw.WriteLine("{0}{0}__{1}_MARK_HANDLER__);", indent, typeName);
                tw.WriteLine("}");
            }
        }

        private struct GeneratedSourceCode
        {
            public readonly Label Label;
            public readonly string[] SourceCode;

            public GeneratedSourceCode(Label label, string[] sourceCode)
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

            var functionPrototype = Utilities.GetFunctionPrototypeString(
                methodName,
                returnType,
                parameters,
                translateContext);

            tw.WriteLine();
            tw.WriteLine("///////////////////////////////////////");
            tw.WriteLine("// {0}", methodName);
            tw.WriteLine();

            tw.WriteLine(functionPrototype);
            tw.WriteLine("{");

            tw.WriteLine("{0}//-------------------", indent);
            tw.WriteLine("{0}// Local variables:", indent);
            tw.WriteLine();

            foreach (var local in locals)
            {
                tw.WriteLine(
                    "{0}{1} local{2};",
                    indent,
                    translateContext.GetCLanguageTypeName(local.LocalType),
                    local.LocalIndex);
            }

            tw.WriteLine();
            tw.WriteLine("{0}//-------------------", indent);
            tw.WriteLine("{0}// Evaluation stacks:", indent);
            tw.WriteLine();

            var stacks = decodeContext.ExtractStacks().ToArray();
            foreach (var si in stacks)
            {
                tw.WriteLine(
                    "{0}{1} {2};",
                    indent,
                    translateContext.GetCLanguageTypeName(si.TargetType),
                    si.SymbolName);
            }

            var frameEntries = locals
                .Where(local => local.LocalType.IsClass)
                .Select(local => new { Type = local.LocalType, Name = "local" + local.LocalIndex })
                .Concat(stacks
                    .Where(stack => stack.TargetType.IsClass)
                    .Select(stack => new { Type = stack.TargetType, Name = stack.SymbolName }))
                .ToArray();

            if (frameEntries.Length >= 1)
            {
                tw.WriteLine();
                tw.WriteLine("{0}//-------------------", indent);
                tw.WriteLine("{0}// Runtime helpers: Setup stack frame", indent);
                tw.WriteLine();

                tw.WriteLine("{0}struct /* __EXECUTION_FRAME__ */", indent);
                tw.WriteLine("{0}{{", indent);
                tw.WriteLine("{0}{0}__EXECUTION_FRAME__* pNext;", indent);
                tw.WriteLine("{0}{0}uint8_t targetCount;", indent);

                foreach (var frameEntry in frameEntries)
                {
                    tw.WriteLine(
                        "{0}{0}{1}** p{2};",
                        indent,
                        translateContext.GetCLanguageTypeName(frameEntry.Type),
                        frameEntry.Name);
                }

                tw.WriteLine("{0}}} __execution_frame__;", indent);
                tw.WriteLine();
                tw.WriteLine("{0}__execution_frame__.targetCount = {1};", indent, frameEntries.Length);

                foreach (var frameEntry in frameEntries)
                {
                    tw.WriteLine(
                        "{0}__execution_frame__.p{1} = &{1};",
                        indent,
                        frameEntry.Name);
                }

                tw.WriteLine("{0}__gc_link_execution_frame__(&__execution_frame__);", indent);
            }

            tw.WriteLine();
            tw.WriteLine("{0}//-------------------", indent);
            tw.WriteLine("{0}// IL body:", indent);
            tw.WriteLine();

            foreach (var entry in bodySourceCode)
            {
                if (decodeContext.TryGetLabelName(
                    entry.Label, out var labelName))
                {
                    tw.WriteLine("{0}:", labelName);
                }

                foreach (var sourceCode in entry.SourceCode)
                {
                    // Dirty hack:
                    if (sourceCode.StartsWith("return ")
                        && (frameEntries.Length >= 1))
                    {
                        tw.WriteLine(
                            "{0}__gc_unlink_execution_frame__(&__execution_frame__);",
                            indent);
                    }

                    tw.WriteLine(
                        "{0}{1};",
                        indent,
                        sourceCode);
                }
            }

            tw.WriteLine("}");
        }
    }
}
