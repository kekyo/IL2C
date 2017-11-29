using System;
using System.IO;
using System.Linq;

using Mono.Cecil;

using IL2C.Translators;

namespace IL2C
{
    public static class AssemblyWriter
    {
        private static void InternalConvertType(
            TextWriter tw,
            IExtractContext extractContext,
            TypeDefinition declaredType,
            string indent)
        {
            if (declaredType.IsPrimitive
                || !(declaredType.IsValueType || declaredType.IsClass))
            {
                return;
            }

            var structName = extractContext.GetCLanguageTypeName(
                declaredType,
                TypeNameFlags.Dereferenced)
                .ManglingSymbolName();

            tw.WriteLine("////////////////////////////////////////////////////////////");
            tw.WriteLine(
                "// {0}: {1}",
                declaredType.IsValueType ? "Struct" : "Class",
                declaredType.GetFullMemberName());
            tw.WriteLine();

            var stopType = declaredType.IsValueType
                ? declaredType.GetSafeValueTypeType()
                : declaredType.GetSafeObjectType();

            var instanceFields = declaredType
                .Traverse(type => type.BaseType?.Resolve())
                .TakeWhile(type => type != stopType)
                .Reverse()
                .SelectMany(type => type.Fields.Where(field => !field.IsStatic))
                .ToArray();
            if (instanceFields.Length >= 1)
            {
                tw.WriteLine(
                    "struct {0}",
                    structName);
                tw.WriteLine("{");

                instanceFields.ForEach(field =>
                    tw.WriteLine(
                        "{0}{1} {2};",
                        indent,
                        extractContext.GetCLanguageTypeName(field.FieldType),
                        field.Name));

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
            TypeDefinition[] types,
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
            types.ForEach(type =>
            {
                var typeName = extractContext.GetCLanguageTypeName(type, TypeNameFlags.Dereferenced)
                    .ManglingSymbolName();
                tw.WriteLine(
                    "typedef struct {0} {0};",
                    typeName);
            });

            // Output value type and object reference type.
            types.ForEach(type =>
            {
                tw.WriteLine();
                InternalConvertType(
                    tw,
                    extractContext,
                    type,
                    indent);
            });

            tw.WriteLine();
            tw.WriteLine("//////////////////////////////////////////////////////////////////////////////////");
            tw.WriteLine("// Public static fields:");

            types.ForEach(type =>
            {
                tw.WriteLine();
                type.Fields
                    .Where(field => field.IsPublic && field.IsStatic)
                    .ForEach(field =>
                    {
                        tw.WriteLine(
                            "extern {0};",
                            Utilities.GetStaticFieldPrototypeString(field, false, extractContext));
                    });
            });

            tw.WriteLine();
            tw.WriteLine("//////////////////////////////////////////////////////////////////////////////////");
            tw.WriteLine("// Methods:");

            types.ForEach(type =>
            {
                tw.WriteLine();

                type.Methods
                    .Where(method => !method.IsConstructor || !method.IsStatic)
                    .ForEach(method =>
                    {
                        var methodName = method.GetFullMemberName();

                        var functionPrototype = Utilities.GetFunctionPrototypeString(
                            methodName,
                            method.ReturnType?.Resolve() ?? method.GetSafeVoidType(),
                            method.GetSafeParameters(),
                            extractContext);

                        tw.WriteLine("extern {0};", functionPrototype);

                        // Is this instance constructor?
                        // TODO: Type initializer's handlers
                        if (method.IsConstructor && !method.IsStatic)
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
                    });
            });

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

            preparedFunction.LocalVariables.ForEach(local =>
            {
                tw.WriteLine(
                    "{0}{1} local{2}{3};",
                    indent,
                    extractContext.GetCLanguageTypeName(local.VariableType),
                    local.Index,
                    local.VariableType.IsValueType ? string.Empty : " = NULL");
            });

            tw.WriteLine();
            tw.WriteLine("{0}//-------------------", indent);
            tw.WriteLine("{0}// Evaluation stacks:", indent);
            tw.WriteLine();

            preparedFunction.Stacks.ForEach(si =>
            {
                tw.WriteLine(
                    "{0}{1} {2}{3};",
                    indent,
                    extractContext.GetCLanguageTypeName(si.TargetType),
                    si.SymbolName,
                    si.TargetType.IsValueType ? string.Empty : " = NULL");
            });

            var frameEntries = locals
                .Where(local => local.VariableType.IsValueType == false)
                .Select(local => new { Type = local.VariableType, Name = "local" + local.Index })
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

                frameEntries.ForEach(frameEntry =>
                {
                    tw.WriteLine(
                        "{0}{0}{1}* p{2};",
                        indent,
                        extractContext.GetCLanguageTypeName(frameEntry.Type),
                        frameEntry.Name);
                });

                tw.WriteLine("{0}}} __executionFrame__;", indent);
                tw.WriteLine();
                tw.WriteLine("{0}__executionFrame__.targetCount = {1};", indent, frameEntries.Length);

                frameEntries.ForEach(frameEntry =>
                {
                    tw.WriteLine(
                        "{0}__executionFrame__.p{1} = &{1};",
                        indent,
                        frameEntry.Name);
                });

                tw.WriteLine("{0}__gc_link_execution_frame__(&__executionFrame__);", indent);
            }

            tw.WriteLine();
            tw.WriteLine("{0}//-------------------", indent);
            tw.WriteLine("{0}// IL body:", indent);
            tw.WriteLine();

            preparedFunction.PreparedILBodies.ForEach(ilBody =>
            {
                if (preparedFunction.TryGetLabelName(
                    ilBody.Label, out var labelName))
                {
                    tw.WriteLine("{0}:", labelName);
                }

                var sourceCodes = ilBody.Generator(extractContext);
                sourceCodes.ForEach(sourceCode =>
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
                });
            });

            tw.WriteLine("}");
        }

        private static void InternalConvertFromFunction(
            TextWriter tw,
            IExtractContext extractContext,
            PreparedFunction preparedFunction,
            PInvokeInfo pinvokeInfo,
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

            var arguments = string.Join(
                ", ",
                preparedFunction.Parameters.Select(parameter => parameter.Name));

            if (preparedFunction.ReturnType.IsVoidType())
            {
                tw.WriteLine("{0}{1}({2});", indent, pinvokeInfo.EntryPoint, arguments);
            }
            else
            {
                tw.WriteLine("{0}return {1}({2});", indent, pinvokeInfo.EntryPoint, arguments);
            }

            tw.WriteLine("}");
        }

        private static void InternalConvertTypeHelper(
            TextWriter tw,
            IExtractContext extractContext,
            TypeDefinition type,
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

            type.Fields
                .Where(field => !field.IsStatic && !field.FieldType.IsValueType)
                .ForEach(field =>
                {
                    tw.WriteLine(
                        "{0}__TRY_MARK_FROM_HANDLER__((({1}*)pReference)->{2});",
                        indent,
                        typeName,
                        field.Name);
                });

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
            PreparedFunctions preparedFunctions,
            MethodDefinition method,
            string indent)
        {
            var methodName = method.GetFullMemberName();
            var preparedFunction = preparedFunctions.Functions[method];

            // Write method body:
            if (preparedFunction.PreparedILBodies != null)
            {
                InternalConvertFromFunction(
                    tw,
                    extractContext,
                    preparedFunction,
                    indent);
            }
            else if (method.IsPInvokeImpl)
            {
                var pinvokeInfo = method.PInvokeInfo;
                if (pinvokeInfo == null)
                {
                    throw new InvalidProgramSequenceException(
                        "Missing DllImport attribute at P/Invoke entry: Method={0}",
                        methodName);
                }

                InternalConvertFromFunction(
                    tw,
                    extractContext,
                    preparedFunction,
                    pinvokeInfo,
                    indent);
            }

            // Is this instance constructor?
            // TODO: Type initializer's handlers
            if (method.IsConstructor && !method.IsStatic)
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

            var assemblyName = extractContext.Assembly.Name.Name;

            twHeader.WriteLine("#ifndef __MODULE_{0}__", assemblyName);
            twHeader.WriteLine("#define __MODULE_{0}__", assemblyName);
            twHeader.WriteLine();

            extractContext.EnumerateRequiredIncludeFileNames()
                .ForEach(fileName => twHeader.WriteLine("#include <{0}>", fileName));

            var types = extractContext.Assembly.Modules
                .SelectMany(module => module.Types)
                // All types exclude privates
                .Where(type => (type.IsValueType || type.IsClass)
                    && (type.IsPublic || type.IsNestedPublic || type.IsNestedFamily || type.IsNestedFamilyOrAssembly))
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
            PreparedFunctions preparedFunctions,
            string indent)
        {
            IExtractContext extractContext = translateContext;

            extractContext.EnumerateRequiredPrivateIncludeFileNames()
                .ForEach(fileName => twSource.WriteLine("#include <{0}>", fileName));

            var assemblyName = extractContext.Assembly.Name.Name;
            twSource.WriteLine("#include \"{0}.h\"", assemblyName);

            var allTypes = extractContext.Assembly.Modules
                .SelectMany(module => module.Types)
                .Where(type => type.IsValidDefinition())
                .ToArray();

            // All types exclude publics and internals (for file scope prototypes)
            var types = allTypes
                .Where(type => !(type.IsPublic || type.IsNestedPublic || type.IsNestedFamily || type.IsNestedFamilyOrAssembly))
                .ToArray();

            InternalConvertToPrototypes(
                twSource,
                types,
                extractContext,
                indent);

            twSource.WriteLine();
            twSource.WriteLine("//////////////////////////////////////////////////////////////////////////////////");
            twSource.WriteLine("// Static fields:");

            allTypes.ForEach(type =>
            {
                twSource.WriteLine();

                // All static fields
                type.Fields
                    .Where(field => field.IsStatic)
                    .ForEach(field => twSource.WriteLine(
                        "{0};",
                        Utilities.GetStaticFieldPrototypeString(field, true, extractContext)));
            });

            twSource.WriteLine();
            twSource.WriteLine("//////////////////////////////////////////////////////////////////////////////////");
            twSource.WriteLine("// Methods:");

            allTypes.ForEach(type =>
            {
                twSource.WriteLine();
                twSource.WriteLine("////////////////////////////////////////////////////////////");
                twSource.WriteLine("// Type: {0}", type.GetFullMemberName());

                // All methods and constructor exclude type initializer
                type.Methods
                    .Where(method => !method.IsConstructor || !method.IsStatic)
                    .ForEach(method =>
                    {
                        InternalConvertFromMethod(
                            twSource,
                            extractContext,
                            preparedFunctions,
                            method,
                            indent);
                    });
            });
        }
    }
}
