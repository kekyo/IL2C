using System;
using System.Diagnostics;
using System.IO;
using System.Linq;

using Mono.Cecil;

using IL2C.Translators;

namespace IL2C
{
    public enum DebugInformationOptions
    {
        None,
        CommentOnly,
        Full
    }

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

            var rawTypeName = declaredType
                .GetFullMemberName().ManglingSymbolName();

            tw.WriteLine("////////////////////////////////////////////////////////////");
            tw.WriteLine(
                "// {0}: {1}",
                declaredType.IsValueType ? "Struct" : "Class",
                declaredType.GetFullMemberName());
            tw.WriteLine();

            var instanceFields = declaredType
                .Traverse(type => type.BaseType?.Resolve())
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
            }

            // Write mark handler:
            tw.WriteLine();
            var makrHandlerPrototype = string.Format(
                "extern const IL2C_RUNTIME_TYPE __{0}_RUNTIME_TYPE__;",
                rawTypeName);
            tw.WriteLine(makrHandlerPrototype);
        }

        private static string GetFunctionNameByFunctionType(PreparedFunction preparedFunction)
        {
            return (preparedFunction.FunctionType == FunctionTypes.Virtual)
                ? ("__" + preparedFunction.MethodName + "__")
                : preparedFunction.MethodName;
        }

        private static void InternalConvertToPrototypes(
            TextWriter tw,
            TypeDefinition[] types,
            IExtractContext extractContext,
            PreparedFunctions preparedFunctions,
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
                        var preparedFunction = preparedFunctions.Functions[method];

                        var functionPrototype = Utilities.GetFunctionPrototypeString(
                            GetFunctionNameByFunctionType(preparedFunction),
                            preparedFunction.ReturnType,
                            preparedFunction.Parameters,
                            extractContext);

                        tw.WriteLine("extern {0};", functionPrototype);
                    });

                var virtualMethods = type
                    .EnumerateOrderedOverridedMethods()
                    .ToArray();
                if (virtualMethods.Length >= 1)
                {
                    var typeName = type.GetFullMemberName().ManglingSymbolName();

                    tw.WriteLine();
                    tw.WriteLine("typedef const struct");
                    tw.WriteLine("{");
                    Enumerable.Range(0, 3)
                        .ForEach(index => tw.WriteLine(
                            "{0}intptr_t reserved{1}__;",
                            indent,
                            index));

                    virtualMethods.ForEach(method =>
                    {
                        var functionPrototype = Utilities.GetFunctionTypeString(
                            method.GetOverloadedMethodName().ManglingSymbolName(),
                            method.ReturnType,
                            method.GetSafeParameters(),
                            extractContext);

                        tw.WriteLine(
                            "{0}{1};",
                            indent,
                            functionPrototype);
                    });

                    tw.WriteLine(
                        "}} __{0}_RUNTIME_TYPE_DECL__;",
                        typeName);
                    tw.WriteLine();

                    virtualMethods.ForEach(method =>
                    {
                        var fullMethodName = type
                            .GetFullMemberName(method, MethodNameTypes.Index)
                            .ManglingSymbolName();
                        var functionParametersDeclaration = string.Join(
                            ", ",
                            method.GetSafeParameters()
                                .Select((parameter, index) => (index == 0)
                                    ? string.Format(
                                        "/* {0} */ {1}",
                                        extractContext.GetCLanguageTypeName(type),
                                        parameter.Name)
                                    : string.Format(
                                        "/* {0} */ {1}",
                                        extractContext.GetCLanguageTypeName(parameter.ParameterType),
                                        parameter.Name)));
                        tw.WriteLine(
                            "#define {0}({1}) \\",
                            fullMethodName,
                            functionParametersDeclaration);

                        var methodName = method
                            .GetOverloadedMethodName()
                            .ManglingSymbolName();
                        var functionParameters = string.Join(
                            ", ",
                            method.GetSafeParameters()
                                .Select((parameter, index) => (index == 0)
                                    ? string.Format(
                                        "({0}){1}",
                                        extractContext.GetCLanguageTypeName(parameter.ParameterType),
                                        parameter.Name)
                                    : parameter.Name));

                        tw.WriteLine(
                            "{0}(il2c_get_vtable({1}, this__)->{2}({3}))",
                            indent,
                            typeName,
                            methodName,
                            functionParameters);
                    });
                }
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
            string indent,
            DebugInformationOptions debugInformationOption)
        {
            var locals = preparedFunction.LocalVariables;

            var functionPrototype = Utilities.GetFunctionPrototypeString(
                GetFunctionNameByFunctionType(preparedFunction),
                preparedFunction.ReturnType,
                preparedFunction.Parameters,
                extractContext);

            tw.WriteLine();
            tw.WriteLine("///////////////////////////////////////");
            tw.WriteLine(
                "// {0}{1}",
                (preparedFunction.FunctionType == FunctionTypes.Virtual)
                    ? "Virtual: "
                    : string.Empty,
                preparedFunction.RawMethodName);
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
                .Where(local => !local.VariableType.IsValueType && !local.VariableType.IsPointer)
                .Select(local => new { Type = local.VariableType, Name = "local" + local.Index })
                .Concat(preparedFunction.Stacks
                    .Where(stack => !stack.TargetType.IsValueType && !stack.TargetType.IsPointer)
                    .Select(stack => new { Type = stack.TargetType, Name = stack.SymbolName }))
                .ToArray();

            if (frameEntries.Length >= 1)
            {
                tw.WriteLine();
                tw.WriteLine("{0}//-------------------", indent);
                tw.WriteLine("{0}// Setup stack frame:", indent);
                tw.WriteLine();

                tw.WriteLine("{0}struct /* IL2C_EXECUTION_FRAME */", indent);
                tw.WriteLine("{0}{{", indent);
                tw.WriteLine("{0}{0}IL2C_EXECUTION_FRAME* pNext;", indent);
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

                tw.WriteLine("{0}il2c_link_execution_frame(&__executionFrame__);", indent);
            }

            tw.WriteLine();
            tw.WriteLine("{0}//-------------------", indent);
            tw.WriteLine("{0}// IL body:", indent);
            tw.WriteLine();

            var canWriteSequencePoint = true;
            preparedFunction.PreparedILBodies.ForEach(ilBody =>
            {
                // Write label if available and used.
                if (preparedFunction.TryGetLabelName(
                    ilBody.Label, out var labelName))
                {
                    tw.WriteLine("{0}:", labelName);
                }

                // Write the line preprocessor directive if available.
                if (canWriteSequencePoint && ilBody.SequencePoints.Any())
                {
                    var sp = ilBody.SequencePoints.First();
                    switch (debugInformationOption)
                    {
                        case DebugInformationOptions.Full:
                            tw.WriteLine(
                                "#line {0} \"{1}\"",
                                sp.StartLine,
                                sp.Document.Url.Replace("\\", "\\\\"));
                            break;
                        case DebugInformationOptions.CommentOnly:
                            tw.WriteLine(
                                "/* {0}({1}): */",
                                sp.Document.Url.Replace("\\", "\\\\"),
                                sp.StartLine);
                            break;
                    }

                    canWriteSequencePoint = false;
                }

                if (debugInformationOption != DebugInformationOptions.None)
                {
                    // Write debugging information.
                    tw.WriteLine(
                        "{0}/* {1} */",
                        indent,
                        ilBody);
                }

                // Generate source code fragments and write.
                var sourceCodes = ilBody.Generator(extractContext);
                sourceCodes.ForEach(sourceCode =>
                {
                    // Dirty hack:
                    //   Write unlink execution frame code if cause exiting method.
                    if (sourceCode.StartsWith("return")
                        && (frameEntries.Length >= 1))
                    {
                        tw.WriteLine(
                            "{0}il2c_unlink_execution_frame(&__executionFrame__);",
                            indent);
                    }

                    tw.WriteLine(
                        "{0}{1};",
                        indent,
                        sourceCode);

                    canWriteSequencePoint = true;
                });
            });

            tw.WriteLine("}");
        }

        private static void InternalConvertFromAbstractFunction(
            TextWriter tw,
            IExtractContext extractContext,
            PreparedFunction preparedFunction,
            string indent)
        {
            var functionPrototype = Utilities.GetFunctionPrototypeString(
                GetFunctionNameByFunctionType(preparedFunction),
                preparedFunction.ReturnType,
                preparedFunction.Parameters,
                extractContext);

            tw.WriteLine();
            tw.WriteLine("///////////////////////////////////////");
            tw.WriteLine("// Abstract: {0}", preparedFunction.RawMethodName);
            tw.WriteLine();

            tw.WriteLine(functionPrototype);
            tw.WriteLine("{");

            tw.WriteLine(
                "{0}// WARNING: Pure virtual function called.",
                indent);
            tw.WriteLine(
                "{0}//TODO: throw : assert(0);",
                indent);

            if (preparedFunction.ReturnType.IsVoidType() == false)
            {
                tw.WriteLine(
                    "{0}return ({1}){2};",
                    indent,
                    extractContext.GetCLanguageTypeName(preparedFunction.ReturnType),
                    preparedFunction.ReturnType.IsNumericPrimitive() ? "0" : "NULL");
            }

            tw.WriteLine("}");
        }

        private static void InternalConvertFromPInvokeFunction(
            TextWriter tw,
            IExtractContext extractContext,
            PreparedFunction preparedFunction,
            PInvokeInfo pinvokeInfo,
            string indent)
        {
            var functionPrototype = Utilities.GetFunctionPrototypeString(
                GetFunctionNameByFunctionType(preparedFunction),
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
                preparedFunction.Parameters.Select(parameter => parameter.GetMarshaledInExpression()));

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
            TypeDefinition declaredType,
            string indent)
        {
            tw.WriteLine();
            tw.WriteLine("//////////////////////");
            tw.WriteLine("// Runtime helpers:");

            var rawTypeName = declaredType.GetFullMemberName().ManglingSymbolName();
            var typeName = extractContext.GetCLanguageTypeName(declaredType, TypeNameFlags.Dereferenced);
            var rawBaseTypeName = declaredType.BaseType.GetFullMemberName().ManglingSymbolName();

            // Write mark handler:
            var makrHandlerPrototype = string.Format(
                "static void __{0}_MARK_HANDLER__(void* pReference)",
                rawTypeName);

            tw.WriteLine();
            tw.WriteLine(makrHandlerPrototype);
            tw.WriteLine("{");

            declaredType.Fields
                .Where(field => !field.IsStatic && !field.FieldType.IsValueType)
                .ForEach(field =>
                {
                    tw.WriteLine(
                        "{0}il2c_try_mark_from_handler((({1}*)pReference)->{2});",
                        indent,
                        typeName,
                        field.Name);
                });

            tw.WriteLine(
                "{0}il2c_typeof({1})->pMarkHandler(pReference);",
                indent,
                rawBaseTypeName);
            tw.WriteLine("}");

            // Write runtime type information
            tw.WriteLine();
            tw.WriteLine(
                "static __{0}_RUNTIME_TYPE_DECL__ __{0}_RUNTIME_TYPE_DEF__ = {{",
                rawTypeName);

            tw.WriteLine(
                "{0}(intptr_t)\"{1}\",",
                indent,
                declaredType.GetFullMemberName());
            var instanceFields = declaredType
                .Traverse(type => type.BaseType?.Resolve())
                .SelectMany(type => type.Fields.Where(field => !field.IsStatic));
            if (instanceFields.Any())
            {
                tw.WriteLine(
                    "{0}(intptr_t)sizeof({1}),",
                    indent,
                    typeName);
            }
            else
            {
                // HACK: C language can't resolve empty structure size.
                tw.WriteLine(
                    "{0}(intptr_t)0,",
                    indent);
            }
            tw.WriteLine(
                "{0}(intptr_t)__{1}_MARK_HANDLER__,",
                indent,
                rawTypeName);

            // Write virtual methods
            declaredType
                .EnumerateOrderedOverridedMethods()
                .ForEach(method =>
                {
                    tw.WriteLine(
                        "{0}__{1}__,",
                        indent,
                        method.GetFullMemberName(MethodNameTypes.Index).ManglingSymbolName());
                });

            tw.WriteLine("};");

            tw.WriteLine(
                "const IL2C_RUNTIME_TYPE __{0}_RUNTIME_TYPE__ =",
                rawTypeName);
            tw.WriteLine(
                "   (const IL2C_RUNTIME_TYPE)(&__{0}_RUNTIME_TYPE_DEF__);",
                rawTypeName);
        }

        internal static void InternalConvertFromMethod(
            TextWriter tw,
            IExtractContext extractContext,
            PreparedFunctions preparedFunctions,
            MethodDefinition method,
            string indent,
            DebugInformationOptions debugInformationOption = DebugInformationOptions.None)
        {
            var methodName = method.GetFullMemberName();
            var preparedFunction = preparedFunctions.Functions[method];

            // Write method body
            switch (preparedFunction.FunctionType)
            {
                case FunctionTypes.Standard:
                    Debug.Assert(preparedFunction.PreparedILBodies != null);

                    InternalConvertFromFunction(
                        tw,
                        extractContext,
                        preparedFunction,
                        indent,
                        debugInformationOption);
                    break;

                case FunctionTypes.Virtual:
                    if (preparedFunction.PreparedILBodies != null)
                    {
                        InternalConvertFromFunction(
                            tw,
                            extractContext,
                            preparedFunction,
                            indent,
                            debugInformationOption);
                    }
                    else
                    {
                        InternalConvertFromAbstractFunction(
                            tw,
                            extractContext,
                            preparedFunction,
                            indent);
                    }
                    break;

                case FunctionTypes.PInvoke:
                    var pinvokeInfo = method.PInvokeInfo;
                    if (pinvokeInfo == null)
                    {
                        throw new InvalidProgramSequenceException(
                            "Missing DllImport attribute at P/Invoke entry: Method={0}",
                            methodName);
                    }

                    InternalConvertFromPInvokeFunction(
                        tw,
                        extractContext,
                        preparedFunction,
                        pinvokeInfo,
                        indent);
                    break;
            }
        }

        public static void WriteHeader(
            TextWriter twHeader,
            TranslateContext translateContext,
            PreparedFunctions preparedFunctions,
            string indent)
        {
            IExtractContext extractContext = translateContext;

            var assemblyName = extractContext.Assembly.Name.Name;
            var safeSymbolName = assemblyName.Replace('.', '_').Replace('-', '_');

            twHeader.WriteLine("#ifndef __MODULE_{0}__", safeSymbolName);
            twHeader.WriteLine("#define __MODULE_{0}__", safeSymbolName);
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
                preparedFunctions,
                indent);

            twHeader.WriteLine();
            twHeader.WriteLine("#endif");
        }

        public static void WriteSourceCode(
            TextWriter twSource,
            TranslateContext translateContext,
            PreparedFunctions preparedFunctions,
            string indent,
            DebugInformationOptions debugInformationOption = DebugInformationOptions.Full)
        {
            IExtractContext extractContext = translateContext;

            extractContext.EnumerateRequiredPrivateIncludeFileNames()
                .ForEach(fileName => twSource.WriteLine("#include <{0}>", fileName));

            var assemblyName = extractContext.Assembly.Name.Name;
            twSource.WriteLine("#include \"{0}.h\"", assemblyName);

            twSource.WriteLine();
            twSource.WriteLine("//////////////////////////////////////////////////////////////////////////////////");
            twSource.WriteLine("// Const strings:");
            twSource.WriteLine();

            extractContext.ExtractConstStrings()
                .ForEach(kv =>
                {
                    var escaped = Utilities.GetEscapedCString(kv.Value);
                    twSource.WriteLine(
                        "IL2C_CONST_STRING({0}, L\"{1}\");",
                        kv.Key,
                        escaped);
                });

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
                preparedFunctions,
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
                            indent,
                            debugInformationOption);
                    });

                InternalConvertTypeHelper(
                    twSource,
                    extractContext,
                    type,
                    indent);
            });
        }
    }
}
