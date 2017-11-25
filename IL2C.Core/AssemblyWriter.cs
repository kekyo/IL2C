using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Runtime.InteropServices;
using IL2C.Translators;

namespace IL2C
{
    public static class AssemblyWriter
    {
        private static void InternalConvertType(
            TextWriter tw,
            IExtractContext extractContext,
            Type declaredType,
            string indent)
        {
            if (declaredType.IsPrimitive
                || !(declaredType.IsValueType || declaredType.IsClass))
            {
                return;
            }

            var structName = extractContext.GetCLanguageTypeName(declaredType, TypeNameFlags.Dereferenced)
                .ManglingSymbolName();

            tw.WriteLine("////////////////////////////////////////////////////////////");
            tw.WriteLine(
                "// {0}: {1}",
                declaredType.IsValueType ? "Struct" : "Class",
                Utilities.GetFullMemberName(declaredType));
            tw.WriteLine();

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
            if (fields.Length >= 1)
            {
                tw.WriteLine(
                    "struct {0}",
                    structName);
                tw.WriteLine("{");

                foreach (var field in fields)
                {
                    tw.WriteLine(
                        "{0}{1} {2};",
                        indent,
                        extractContext.GetCLanguageTypeName(field.FieldType),
                        field.Name);
                }

                tw.WriteLine("};");

                // Write sizeof:
                tw.WriteLine();
                tw.WriteLine(
                    "#define __{0}_SIZEOF__() (sizeof({0}))",
                    structName);
            }
            else
            {
                // Write sizeof:
                tw.WriteLine();
                tw.WriteLine(
                    "#define __{0}_SIZEOF__() (0)",
                    structName);
            }
        }

        private static void InternalConvertToPrototypes(
            TextWriter tw,
            Type[] types,
            IExtractContext extractContext,
            string indent)
        {
            tw.WriteLine();
            tw.WriteLine("#ifdef __cplusplus");
            tw.WriteLine("extern \"C\" {");
            tw.WriteLine("#endif");

            tw.WriteLine();
            tw.WriteLine("//////////////////////////////////////////////////////////////////////////////////");
            tw.WriteLine("// Types:");
            tw.WriteLine();

            // Output prototypes.
            foreach (var type in types)
            {
                var typeName = extractContext.GetCLanguageTypeName(type, TypeNameFlags.Dereferenced)
                    .ManglingSymbolName();

                tw.WriteLine(
                    "typedef struct {0} {0};",
                    typeName);
            }

            // Output value type and object reference type.
            foreach (var type in types)
            {
                tw.WriteLine();
                InternalConvertType(
                    tw,
                    extractContext,
                    type,
                    indent);
            }

            tw.WriteLine();
            tw.WriteLine("//////////////////////////////////////////////////////////////////////////////////");
            tw.WriteLine("// Public static fields:");

            foreach (var type in types)
            {
                tw.WriteLine();

                foreach (var field in
                    from field in type.GetFields(
                        BindingFlags.Public |
                        BindingFlags.Static | BindingFlags.DeclaredOnly)
                    select field)
                {
                    tw.WriteLine(
                        "extern {0};",
                        Utilities.GetStaticFieldPrototypeString(field, false, extractContext));
                }
            }

            tw.WriteLine();
            tw.WriteLine("//////////////////////////////////////////////////////////////////////////////////");
            tw.WriteLine("// Methods:");

            foreach (var type in types)
            {
                tw.WriteLine();

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
                        extractContext);

                    tw.WriteLine("extern {0};", functionPrototype);

                    // Is this instance constructor?
                    // TODO: Type initializer's handlers
                    if (method.IsConstructor && (method.IsStatic == false))
                    {
                        var typeName = extractContext.GetCLanguageTypeName(type, TypeNameFlags.Dereferenced);

                        // Write mark handler:
                        var makrHandlerPrototype = string.Format(
                            "extern void __{0}_MARK_HANDLER__(void* pReference);",
                            typeName);
                        tw.WriteLine(makrHandlerPrototype);

                        // Write new:
                        var newPrototype = string.Format(
                            "extern void __{0}_NEW__({0}** ppReference);",
                            typeName);

                        tw.WriteLine(newPrototype);
                    }
                }
            }

            tw.WriteLine();
            tw.WriteLine("#ifdef __cplusplus");
            tw.WriteLine("}");
            tw.WriteLine("#endif");
        }

        private static void InternalConvertFromFunction(
            TextWriter tw,
            IExtractContext extractContext,
            PreparedFunction preparedFunction,
            string indent)
        {
            var locals = preparedFunction.LocalVariables;

            var functionPrototype = Utilities.GetFunctionPrototypeString(
                preparedFunction.MethodName,
                preparedFunction.ReturnType,
                preparedFunction.Parameters,
                extractContext);

            tw.WriteLine();
            tw.WriteLine("///////////////////////////////////////");
            tw.WriteLine("// {0}", preparedFunction.RawMethodName);
            tw.WriteLine();

            tw.WriteLine(functionPrototype);
            tw.WriteLine("{");

            tw.WriteLine("{0}//-------------------", indent);
            tw.WriteLine("{0}// Local variables:", indent);
            tw.WriteLine();

            // Important NULL assigner (p = NULL):
            //   Because these variables are pointer (of object reference).
            //   So GC will traverse these variables just setup the stack frame.

            foreach (var local in preparedFunction.LocalVariables)
            {
                tw.WriteLine(
                    "{0}{1} local{2}{3};",
                    indent,
                    extractContext.GetCLanguageTypeName(local.LocalType),
                    local.LocalIndex,
                    local.LocalType.IsValueType ? string.Empty : " = NULL");
            }

            tw.WriteLine();
            tw.WriteLine("{0}//-------------------", indent);
            tw.WriteLine("{0}// Evaluation stacks:", indent);
            tw.WriteLine();

            foreach (var si in preparedFunction.Stacks)
            {
                tw.WriteLine(
                    "{0}{1} {2}{3};",
                    indent,
                    extractContext.GetCLanguageTypeName(si.TargetType),
                    si.SymbolName,
                    si.TargetType.IsValueType ? string.Empty : " = NULL");
            }

            var frameEntries = locals
                .Where(local => local.LocalType.IsValueType == false)
                .Select(local => new { Type = local.LocalType, Name = "local" + local.LocalIndex })
                .Concat(preparedFunction.Stacks
                    .Where(stack => stack.TargetType.IsValueType == false)
                    .Select(stack => new { Type = stack.TargetType, Name = stack.SymbolName }))
                .ToArray();

            if (frameEntries.Length >= 1)
            {
                tw.WriteLine();
                tw.WriteLine("{0}//-------------------", indent);
                tw.WriteLine("{0}// Setup stack frame:", indent);
                tw.WriteLine();

                tw.WriteLine("{0}struct /* __EXECUTION_FRAME__ */", indent);
                tw.WriteLine("{0}{{", indent);
                tw.WriteLine("{0}{0}__EXECUTION_FRAME__* pNext;", indent);
                tw.WriteLine("{0}{0}uint8_t targetCount;", indent);

                foreach (var frameEntry in frameEntries)
                {
                    tw.WriteLine(
                        "{0}{0}{1}* p{2};",
                        indent,
                        extractContext.GetCLanguageTypeName(frameEntry.Type),
                        frameEntry.Name);
                }

                tw.WriteLine("{0}}} __executionFrame__;", indent);
                tw.WriteLine();
                tw.WriteLine("{0}__executionFrame__.targetCount = {1};", indent, frameEntries.Length);

                foreach (var frameEntry in frameEntries)
                {
                    tw.WriteLine(
                        "{0}__executionFrame__.p{1} = &{1};",
                        indent,
                        frameEntry.Name);
                }

                tw.WriteLine("{0}__gc_link_execution_frame__(&__executionFrame__);", indent);
            }

            tw.WriteLine();
            tw.WriteLine("{0}//-------------------", indent);
            tw.WriteLine("{0}// IL body:", indent);
            tw.WriteLine();

            foreach (var preparedOpCode in preparedFunction.PreparedILBodies)
            {
                if (preparedFunction.TryGetLabelName(
                    preparedOpCode.Label, out var labelName))
                {
                    tw.WriteLine("{0}:", labelName);
                }

                var sourceCodes = preparedOpCode.Generator(extractContext);
                foreach (var sourceCode in sourceCodes)
                {
                    // Dirty hack:
                    if (sourceCode.StartsWith("return")
                        && (frameEntries.Length >= 1))
                    {
                        tw.WriteLine(
                            "{0}__gc_unlink_execution_frame__(&__executionFrame__);",
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

        private static void InternalConvertFromFunction(
            TextWriter tw,
            IExtractContext extractContext,
            PreparedFunction preparedFunction,
            DllImportAttribute dllImportAttribute,
            string indent)
        {
            var functionPrototype = Utilities.GetFunctionPrototypeString(
                preparedFunction.MethodName,
                preparedFunction.ReturnType,
                preparedFunction.Parameters,
                extractContext);

            tw.WriteLine();
            tw.WriteLine("///////////////////////////////////////");
            tw.WriteLine("// P/Invoke: {0}", preparedFunction.RawMethodName);
            tw.WriteLine();

            tw.WriteLine(functionPrototype);
            tw.WriteLine("{");

            var realTargetName = string.IsNullOrWhiteSpace(dllImportAttribute.EntryPoint)
                ? preparedFunction.RawMethodName
                : dllImportAttribute.EntryPoint;
            var arguments = string.Join(
                ", ",
                preparedFunction.Parameters.Select(parameter => parameter.Name));

            if (preparedFunction.ReturnType != typeof(void))
            {
                tw.WriteLine("{0}return {1}({2});", indent, realTargetName, arguments);
            }
            else
            {
                tw.WriteLine("{0}{1}({2});", indent, realTargetName, arguments);
            }

            tw.WriteLine("}");
        }

        private static void InternalConvertTypeHelper(
            TextWriter tw,
            IExtractContext extractContext,
            Type type,
            string indent)
        {
            tw.WriteLine();
            tw.WriteLine("//////////////////////");
            tw.WriteLine("// Runtime helpers:");

            var typeName = extractContext.GetCLanguageTypeName(type, TypeNameFlags.Dereferenced);
            var baseTypeName = extractContext.GetCLanguageTypeName(type.BaseType, TypeNameFlags.Dereferenced);

            // Write mark handler:
            var makrHandlerPrototype = string.Format(
                "void __{0}_MARK_HANDLER__(void* pReference)",
                typeName);

            tw.WriteLine();
            tw.WriteLine(makrHandlerPrototype);
            tw.WriteLine("{");

            foreach (var field in type.GetFields(
                    BindingFlags.Public | BindingFlags.NonPublic
                    | BindingFlags.Instance | BindingFlags.DeclaredOnly)
                .Where(field => field.FieldType.IsValueType == false))
            {
                tw.WriteLine(
                    "{0}__TRY_MARK_FROM_HANDLER__((({1}*)pReference)->{2});",
                    indent,
                    typeName,
                    field.Name);
            }

            tw.WriteLine(
                "{0}__{1}_MARK_HANDLER__(pReference);",
                indent,
                baseTypeName);
            tw.WriteLine("}");

            // Write new:
            var newPrototype = string.Format(
                "void __{0}_NEW__({0}** ppReference)",
                typeName);

            tw.WriteLine();
            tw.WriteLine(newPrototype);
            tw.WriteLine("{");
            tw.WriteLine("{0}__gc_get_uninitialized_object__(", indent);
            tw.WriteLine("{0}{0}(void**)ppReference,", indent);
            tw.WriteLine("{0}{0}__{1}_SIZEOF__(),", indent, typeName);
            tw.WriteLine("{0}{0}__{1}_MARK_HANDLER__);", indent, typeName);
            tw.WriteLine("{0}{1}__ctor(*ppReference);", indent, typeName);
            tw.WriteLine("}");
        }

        internal static void InternalConvertFromMethod(
            TextWriter tw,
            IExtractContext extractContext,
            IReadOnlyDictionary<MethodBase, PreparedFunction> preparedFunctions,
            MethodBase method,
            string indent)
        {
            var methodName = Utilities.GetFullMemberName(method);
            var preparedFunction = preparedFunctions[method];

            // Write method body:
            if (preparedFunction.PreparedILBodies != null)
            {
                InternalConvertFromFunction(
                    tw,
                    extractContext,
                    preparedFunction,
                    indent);
            }
            else if ((method.Attributes & MethodAttributes.PinvokeImpl) == MethodAttributes.PinvokeImpl)
            {
                var dllImportAttribute = method.GetCustomAttribute<DllImportAttribute>();
                if (dllImportAttribute == null)
                {
                    throw new InvalidProgramSequenceException(
                        "Missing DllImport attribute at P/Invoke entry: Method={0}",
                        methodName);
                }

                InternalConvertFromFunction(
                    tw,
                    extractContext,
                    preparedFunction,
                    dllImportAttribute,
                    indent);
            }

            // Is this instance constructor?
            // TODO: Type initializer's handlers
            if (method.IsConstructor && (method.IsStatic == false))
            {
                InternalConvertTypeHelper(
                    tw,
                    extractContext,
                    method.DeclaringType,
                    indent);
            }
        }

        public static void WriteHeader(
            TextWriter twHeader,
            TranslateContext translateContext,
            string indent)
        {
            IExtractContext extractContext = translateContext;

            var assemblyName = extractContext.Assembly.GetName().Name;

            twHeader.WriteLine("#ifndef __MODULE_{0}__", assemblyName);
            twHeader.WriteLine("#define __MODULE_{0}__", assemblyName);
            twHeader.WriteLine();

            foreach (var fileName in extractContext.EnumerateRequiredIncludeFileNames())
            {
                twHeader.WriteLine("#include <{0}>", fileName);
            }

            var types = extractContext.Assembly.GetTypes()
                .Where(type => (type.IsValueType || type.IsClass)
                    && (type.IsPublic || type.IsNestedPublic || type.IsNestedFamily || type.IsNestedFamORAssem))
                .ToArray();

            InternalConvertToPrototypes(
                twHeader,
                types,
                extractContext,
                indent);

            twHeader.WriteLine();
            twHeader.WriteLine("#endif");
        }

        public static void WriteSourceCode(
            TextWriter twSource,
            TranslateContext translateContext,
            IReadOnlyDictionary<MethodBase, PreparedFunction> preparedFunctions,
            string indent)
        {
            IExtractContext extractContext = translateContext;

            foreach (var fileName in extractContext.EnumerateRequiredPrivateIncludeFileNames())
            {
                twSource.WriteLine("#include <{0}>", fileName);
            }

            var assemblyName = extractContext.Assembly.GetName().Name;
            twSource.WriteLine("#include \"{0}.h\"", assemblyName);

            var allTypes = extractContext.Assembly.GetTypes()
                .Where(type => type.IsValueType || type.IsClass)
                .ToArray();
            var types = allTypes
                .Where(type => !(type.IsPublic || type.IsNestedPublic || type.IsNestedFamily || type.IsNestedFamORAssem))
                .ToArray();

            InternalConvertToPrototypes(
                twSource,
                types,
                extractContext,
                indent);

            twSource.WriteLine();
            twSource.WriteLine("//////////////////////////////////////////////////////////////////////////////////");
            twSource.WriteLine("// Static fields:");

            foreach (var type in allTypes)
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
                        Utilities.GetStaticFieldPrototypeString(field, true, extractContext));
                }
            }

            twSource.WriteLine();
            twSource.WriteLine("//////////////////////////////////////////////////////////////////////////////////");
            twSource.WriteLine("// Methods:");

            foreach (var type in allTypes)
            {
                twSource.WriteLine();
                twSource.WriteLine("////////////////////////////////////////////////////////////");
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
                    InternalConvertFromMethod(
                        twSource,
                        extractContext,
                        preparedFunctions,
                        method,
                        indent);
                }
            }
        }
    }
}
