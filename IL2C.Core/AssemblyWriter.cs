using System;
using System.Collections.Generic;
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
                || !(declaredType.IsValueType || declaredType.IsClass || declaredType.IsInterface))
            {
                return;
            }

            var structName = extractContext.GetCLanguageTypeName(
                declaredType,
                TypeNameFlags.Dereferenced)
                .ManglingSymbolName();

            var rawTypeName = declaredType
                .GetFullMemberName()
                .ManglingSymbolName();
            var typeString = declaredType.IsValueType
                ? "Struct"
                : declaredType.IsInterface
                    ? "Interface"
                    : "Class";

            tw.WriteLine("////////////////////////////////////////////////////////////");
            tw.WriteLine(
                "// {0}: {1}",
                typeString,
                declaredType.GetFullMemberName());
            tw.WriteLine();

            // IL2C vtable model case [1]:
            //
            // public class A : IB {
            //   public int F1;
            //   public string F2;
            //   public virtual int Calc(int a, int b);
            // }
            // public interface IB {
            //   int Calc(int a, int b);
            // }
            //
            // +----------------------+
            // | IL2C_REF_HEADER      |
            // +----------------------+ <-- this__       __A_VTABLE__
            // | vptr0__              | -------------> +--------------------+
            // +----------------------+                | ILC2_RuntimeCast() |
            // | vptr_A_IB__          | ----------+    | ToString()         |
            // +----------------------+           |    | GetHashCode()      |
            // | int F1               |           |    | Finalize()         |
            // | string F2            |           |    | Equals()           |
            // +----------------------+           |    | Calc()             |
            //                                    |    +--------------------+
            //                                    |      __A_IB_VTABLE__
            //                                    +--> +------------------------------+
            //                                         | ILC2_RuntimeCast() [with AT] |
            //                                         | ToString() [with AT]         |
            //                                         | GetHashCode() [with AT]      |
            //                                         | Finalize() [with AT]         |
            //                                         | Equals() [with AT]           |
            //                                         | Calc() [with AT]             |
            //                                         +------------------------------+

            tw.WriteLine(
                "// {0} vtable layout",
                typeString);
            tw.WriteLine("typedef const struct");
            tw.WriteLine("{");
            tw.WriteLine(
                "{0}/* internalcall */ void* (*IL2C_RuntimeCast)({1}* this__, IL2C_RUNTIME_TYPE_DECL* type);",
                indent,
                rawTypeName);

            var virtualMethods = declaredType
                .EnumerateOrderedOverridedMethods()
                .ToArray();
            foreach (var method in virtualMethods)
            {
                var functionPrototype = Utilities.GetFunctionTypeString(
                    method.GetOverloadedMethodName().ManglingSymbolName(),
                    method.ReturnType,
                    method.GetSafeParameters(declaredType),
                    extractContext);
                tw.WriteLine(
                    "{0}{1};",
                    indent,
                    functionPrototype);
            }

            tw.WriteLine(
                "}} __{0}_VTABLE_DECL__;",
                rawTypeName);

            var fields = declaredType
                .Traverse(type => type.BaseType?.Resolve())
                .Reverse()
                .SelectMany(type =>
                {
                    var vptrs = type.Interfaces
                        .Select(interfaceImpl => new
                        {
                            Name = string.Format(
                                "vptr_{0}__",
                                interfaceImpl.InterfaceType
                                    .GetFullMemberName()
                                    .ManglingSymbolName()),
                            TypeName = string.Format(
                                "__{0}_VTABLE_DECL__*",
                                interfaceImpl.InterfaceType
                                    .GetFullMemberName()
                                    .ManglingSymbolName())
                        });
                    var thisFields = type.Fields
                        .Where(field => !field.IsStatic)
                        .Select(field => new
                        {
                            field.Name,
                            TypeName = extractContext.GetCLanguageTypeName(field.FieldType)
                        });
                    return vptrs.Concat(thisFields);
                })
                .ToArray();
            if ((declaredType.IsValueType == false) ||
                (fields.Length >= 1))
            {
                tw.WriteLine();
                tw.WriteLine(
                    "// {0} layout",
                    typeString);
                tw.WriteLine(
                    "struct {0}",
                    structName);
                tw.WriteLine("{");

                // Emit vptr:
                if (declaredType.IsClass)
                {
                    tw.WriteLine(
                        "{0}__{1}_VTABLE_DECL__* vptr0__;",
                        indent,
                        rawTypeName);
                }
                else if (declaredType.IsInterface)
                {
                    tw.WriteLine(
                        "{0}__{1}_VTABLE_DECL__* vptr_{1}__;",
                        indent,
                        rawTypeName);
                }

                foreach (var field in fields)
                {
                    tw.WriteLine(
                        "{0}{1} {2};",
                        indent,
                        field.TypeName,
                        field.Name);
                }

                tw.WriteLine("};");
                tw.WriteLine();
            }

            var makrHandlerPrototype = string.Format(
                "extern IL2C_RUNTIME_TYPE_DECL __{0}_RUNTIME_TYPE__;",
                rawTypeName);
            tw.WriteLine();
            tw.WriteLine(
                "// {0} runtime type information",
                typeString);
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

                foreach (var field in type.Fields
                    .Where(field => field.IsPublic && field.IsStatic))
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
                var rawTypeName = type
                    .GetFullMemberName()
                    .ManglingSymbolName();
                var typeName = extractContext
                    .GetCLanguageTypeName(type, TypeNameFlags.Dereferenced)
                    .ManglingSymbolName();

                tw.WriteLine();
                tw.WriteLine(
                    "// {0}",
                    type.FullName);

                if (!type.IsInterface)
                {
                    tw.WriteLine(
                        "extern /* internalcall */ void __{0}_IL2C_MarkHandler__({1}* this__);",
                        rawTypeName,
                        typeName);
                }

                tw.WriteLine(
                    "extern /* internalcall */ void* __{0}_IL2C_RuntimeCast__({1}* this__, IL2C_RUNTIME_TYPE_DECL* type);",
                    rawTypeName,
                    typeName);

                foreach (var method in type.Methods
                    .Where(method => !method.IsConstructor || !method.IsStatic))
                {
                    var preparedFunction = preparedFunctions.Functions[method];

                    var functionPrototype = Utilities.GetFunctionPrototypeString(
                        GetFunctionNameByFunctionType(preparedFunction),
                        preparedFunction.ReturnType,
                        preparedFunction.Parameters,
                        extractContext);

                    tw.WriteLine(
                        "extern {0}{1};",
                        method.IsVirtual ? "/* virtual */ " : string.Empty,
                        functionPrototype);
                }

                var virtualMethods = type
                    .EnumerateOrderedOverridedMethods()
                    .ToArray();
                if (virtualMethods.Length >= 1)
                {
                    foreach (var method in virtualMethods)
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
                                .Select(parameter => parameter.Name));

                        if (type.IsValueType || type.IsClass)
                        {
                            tw.WriteLine(
                                "{0}((this__)->vptr0__->{1}({2}))",
                                indent,
                                methodName,
                                functionParameters);
                        }
                        else
                        {
                            // TODO: If interface's vtable layout same as class vtable.
                            //   We can use instead to classes.
                            //   Invoke and space cost efficient because classes directly pointed to function without adjustor thunk.
                            //     1. First interface type
                            //     2. Method list sequence equal between class and intrerface.
                            //   (But we can't remove interface's vptr, because we'll have to do with C++ interoperability)
                            tw.WriteLine(
                                "{0}((this__)->vptr_{1}__->{2}({3}))",
                                indent,
                                rawTypeName,
                                methodName,
                                functionParameters);
                        }
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

            foreach (var local in preparedFunction.LocalVariables)
            {
                tw.WriteLine(
                    "{0}{1} {2}{3};",
                    indent,
                    extractContext.GetCLanguageTypeName(local.TargetType),
                    local.SymbolName,
                    local.TargetType.IsValueType ? string.Empty : " = NULL");
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
                .Concat(preparedFunction.Stacks)
                .Where(local => !local.TargetType.IsValueType && !local.TargetType.IsPointer)
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

                foreach (var frameEntry in frameEntries)
                {
                    tw.WriteLine(
                        "{0}{0}{1}* p{2};",
                        indent,
                        extractContext.GetCLanguageTypeName(frameEntry.TargetType),
                        frameEntry.SymbolName);
                }

                tw.WriteLine("{0}}} __executionFrame__;", indent);
                tw.WriteLine();
                tw.WriteLine("{0}__executionFrame__.targetCount = {1};", indent, frameEntries.Length);

                foreach (var frameEntry in frameEntries)
                {
                    tw.WriteLine(
                        "{0}__executionFrame__.p{1} = &{1};",
                        indent,
                        frameEntry.SymbolName);
                }

                tw.WriteLine("{0}il2c_link_execution_frame(&__executionFrame__);", indent);
            }

            tw.WriteLine();
            tw.WriteLine("{0}//-------------------", indent);
            tw.WriteLine("{0}// IL body:", indent);
            tw.WriteLine();

            var canWriteSequencePoint = true;
            foreach (var ilBody in preparedFunction.PreparedILBodies)
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
                foreach (var sourceCode in sourceCodes)
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
                }
            }

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
                preparedFunction.Parameters
                    .Select(parameter => parameter.GetMarshaledInExpression()));

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

        private struct VirtualMethodInformation
        {
            public readonly string TypeName;
            public readonly string Name;
            public readonly string ReturnTypeName;
            public readonly KeyValuePair<string, string>[] Parameters;

            public VirtualMethodInformation(
                string typeName,
                string name,
                string returnTypeName,
                KeyValuePair<string, string>[] parameters)
            {
                this.TypeName = typeName;
                this.Name = name;
                this.ReturnTypeName = returnTypeName;
                this.Parameters = parameters;
            }
        }

        private static VirtualMethodInformation[] GetVirtualMethods(
            IExtractContext extractContext,
            TypeReference adjustorThunkTargetType,
            TypeReference delegationTargetType)
        {
            var typeName = extractContext
                .GetCLanguageTypeName(adjustorThunkTargetType);
            var delegationTargetTypeName = delegationTargetType
                .GetFullMemberName()
                .ManglingSymbolName();

            return new []
                {
                    new VirtualMethodInformation(
                        delegationTargetTypeName,
                        "IL2C_RuntimeCast",
                        "void*",
                        new[]
                        {
                            Utilities.KeyValue(typeName, "this__"),
                            Utilities.KeyValue("IL2C_RUNTIME_TYPE_DECL*", "type"), 
                        }), 
                }
                .Concat(adjustorThunkTargetType
                    .EnumerateOrderedOverridedMethods()
                    .Select(method => new VirtualMethodInformation(
                        method.DeclaringType.MemberEquals(adjustorThunkTargetType)
                            ? delegationTargetTypeName
                            : method.DeclaringType
                                .GetFullMemberName()
                                .ManglingSymbolName(),
                        method.GetOverloadedMethodName()
                            .ManglingSymbolName(),
                        extractContext.GetCLanguageTypeName(
                            method.ReturnType),
                        method.GetSafeParameters(adjustorThunkTargetType)
                            .Select(parameter => Utilities.KeyValue(
                                extractContext.GetCLanguageTypeName(parameter.ParameterType),
                                parameter.Name))
                            .ToArray())))
                .ToArray();
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

            var rawTypeName = declaredType
                .GetFullMemberName()
                .ManglingSymbolName();
            var typeName = extractContext.GetCLanguageTypeName(
                declaredType,
                TypeNameFlags.Dereferenced);

            // Write RuntimeCast function:
            tw.WriteLine();
            tw.WriteLine("// Runtime cast");
            tw.WriteLine(
                "void* __{0}_IL2C_RuntimeCast__({1} this__, IL2C_RUNTIME_TYPE_DECL* type)",
                rawTypeName,
                extractContext.GetCLanguageTypeName(
                    declaredType,
                    TypeNameFlags.ForcePointer));
            tw.WriteLine("{");

            // RuntimeCast: this type.
            //   TODO: inlining all base type comparer are better than base invoker?
            tw.WriteLine(
                "{0}// This type",
                indent);
            tw.WriteLine(
                "{0}if (type == il2c_typeof({1})) return this__;",
                indent,
                rawTypeName);

            // RuntimeCast: implemented interfaces.
            if (declaredType.Interfaces.Count >= 1)
            {
                tw.WriteLine();
                tw.WriteLine(
                    "{0}// Interface types",
                    indent);

                foreach (var interfaceImpl in declaredType.Interfaces)
                {
                    var rawInterfaceTypeName = interfaceImpl.InterfaceType
                        .GetFullMemberName()
                        .ManglingSymbolName();

                    // NOTE:
                    //  The virtual function pointer added offset from between vptr_TYPE__ and vptr0__.
                    //  If will invoke interface's virtual function,
                    //  the function is delegated "Adjust thunk" function,
                    //  it will recalculate this pointer offset.
                    tw.WriteLine(
                        "{0}if (type == il2c_typeof({1})) return (void*)&(this__->vptr_{1}__);",
                        indent,
                        rawInterfaceTypeName);
                }
            }

            var rawBaseTypeName = declaredType.BaseType
                .GetFullMemberName()
                .ManglingSymbolName();

            // RuntimeCast: reflect base types.
            tw.WriteLine();
            tw.WriteLine(
                "{0}// Delegate checking base types",
                indent);
            tw.WriteLine(
                "{0}return __{1}_IL2C_RuntimeCast__(({2})this__, type);",
                indent,
                rawBaseTypeName,
                extractContext.GetCLanguageTypeName(
                    declaredType.BaseType,
                    TypeNameFlags.ForcePointer));
            tw.WriteLine("}");

            // Write mark handler:
            var makrHandlerPrototype = string.Format(
                "void __{0}_IL2C_MarkHandler__({1} this__)",
                rawTypeName,
                extractContext.GetCLanguageTypeName(declaredType, TypeNameFlags.ForcePointer));

            tw.WriteLine();
            tw.WriteLine("// GC's mark handler");
            tw.WriteLine(makrHandlerPrototype);
            tw.WriteLine("{");

            var fields = declaredType.Fields
                .Where(field => !field.IsStatic && !field.FieldType.IsValueType)
                .ToArray();
            if (fields.Length >= 1)
            {
                tw.WriteLine(
                    "{0}// Try marking each object reference fields",
                    indent);
                foreach (var field in fields)
                {
                    tw.WriteLine(
                        "{0}il2c_try_mark_from_handler(this__->{1});",
                        indent,
                        field.Name);
                }
            }

            // Invoke base class mark handler except System.Object and System.ValueType.
            var baseType = declaredType.BaseType;
            if (baseType != null)
            {
                if ((baseType.IsObjectType() || baseType.IsValueTypeType()) == false)
                {
                    tw.WriteLine();
                    tw.WriteLine(
                        "{0}// Delegate checking base types",
                        indent);
                    tw.WriteLine(
                        "{0}__{1}_IL2C_MarkHandler__(({2})this__);",
                        indent,
                        rawBaseTypeName,
                        extractContext.GetCLanguageTypeName(declaredType.BaseType));
                }
                else
                {
                    tw.WriteLine();
                    tw.WriteLine(
                        "{0}/* Suppressed invoke base mark handler */",
                        indent);
                }
            }

            tw.WriteLine("}");

            // Write runtime type information
            tw.WriteLine();
            tw.WriteLine("// Runtime type information");
            tw.WriteLine(
                "IL2C_RUNTIME_TYPE_DECL __{0}_RUNTIME_TYPE__ = {{",
                rawTypeName);
            tw.WriteLine(
                "{0}\"{1}\",",
                indent,
                declaredType.GetFullMemberName());
            tw.WriteLine(
                "{0}sizeof({1}),",
                indent,
                typeName);
            tw.WriteLine(
                "{0}/* internalcall */ (void*)__{1}_IL2C_MarkHandler__,",
                indent,
                rawTypeName);

            tw.WriteLine("};");

            tw.WriteLine();
            tw.WriteLine("//////////////////////");
            tw.WriteLine("// VTables:");

            // Write virtual methods
            tw.WriteLine();
            tw.WriteLine(
                "// Vtable of {0}",
                declaredType.FullName);
            tw.WriteLine(
                "__{0}_VTABLE_DECL__ __{0}_VTABLE__ = {{",
                rawTypeName);

            foreach (var method in GetVirtualMethods(extractContext, declaredType, declaredType))
            {
                tw.WriteLine(
                    "{0}(void*)__{1}_{2}__,",
                    indent,
                    method.TypeName,
                    method.Name);
            }

            tw.WriteLine("};");

            foreach (var interfaceType in declaredType.Interfaces
                .Select(interfaceImpl => interfaceImpl.InterfaceType))
            {
                var rawInterfaceTypeName = interfaceType
                    .GetFullMemberName()
                    .ManglingSymbolName();

                var methods = GetVirtualMethods(
                    extractContext,
                    interfaceType,
                    declaredType);

                foreach (var method in methods)
                {
                    // Adjustor thunk will not invoke direct, so try to emit static function.
                    tw.WriteLine();
                    tw.WriteLine(
                        "// Adjustor thunk: {0}.{1}",
                        method.TypeName,
                        method.Name);
                    tw.WriteLine(
                        "static {0} __{1}_{2}_AT_{3}__(",
                        method.ReturnTypeName,
                        method.TypeName,
                        method.Name,
                        rawInterfaceTypeName);
                    tw.WriteLine(
                        "{0}{1})",
                        indent,
                        string.Join(
                            ", ",
                            method.Parameters.Select(parameter =>
                                string.Format(
                                    "{0} {1}",
                                    parameter.Key,
                                    parameter.Value))));
                    tw.WriteLine(
                        "{");
                    tw.WriteLine(
                        "{0}{1}__{2}_{3}__({4});",
                        indent,
                        (method.ReturnTypeName != "void") ? "return " : string.Empty,
                        method.TypeName,
                        method.Name,
                        string.Join(
                            ", ",
                            method.Parameters.Select((parameter, index) =>
                                (index == 0)
                                    // Adjust vptr offset with il2c_cast_from_interface() macro.
                                    ? string.Format(
                                        "({0}*)il2c_cast_from_interface({1}, {2}, {3})",
                                        method.TypeName,
                                        rawTypeName,
                                        rawInterfaceTypeName,
                                        parameter.Value)
                                    : parameter.Value)));
                    tw.WriteLine(
                        "}");
                }

                tw.WriteLine();
                tw.WriteLine(
                    "// Vtable of {0} (with adjustor thunk)",
                    interfaceType.FullName);
                tw.WriteLine(
                    "__{0}_VTABLE_DECL__ __{1}_{0}_VTABLE__ = {{",
                    rawInterfaceTypeName,
                    rawTypeName);

                foreach (var method in methods)
                {
                    tw.WriteLine(
                        "{0}__{1}_{2}_AT_{3}__,",
                        indent,
                        method.TypeName,
                        method.Name,
                        rawInterfaceTypeName);
                }

                tw.WriteLine("};");
            }
        }

        private static void InternalConvertTypeHelperForInterface(
            TextWriter tw,
            TypeDefinition declaredType,
            string indent)
        {
            tw.WriteLine();
            tw.WriteLine("//////////////////////");
            tw.WriteLine("// Runtime helpers:");

            var rawTypeName = declaredType
                .GetFullMemberName()
                .ManglingSymbolName();

            // Write runtime type information
            tw.WriteLine();
            tw.WriteLine("// Runtime type information");

            // TODO: IL2C_RUNTIME_TYPE_DECL's some fields not used.
            tw.WriteLine(
                "IL2C_RUNTIME_TYPE_DECL __{0}_RUNTIME_TYPE__ = {{",
                rawTypeName);
            tw.WriteLine(
                "{0}\"{1}\", 0, NULL",
                indent,
                declaredType.GetFullMemberName());
            tw.WriteLine("};");
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

                case FunctionTypes.InterfaceVirtual:
                    // Nothing to do
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

            foreach (var fileName in extractContext.EnumerateRequiredIncludeFileNames())
            {
                twHeader.WriteLine("#include <{0}>", fileName);
            }

            var types = extractContext.Assembly.Modules
                .SelectMany(module => module.Types)
                // All types exclude privates
                .Where(type => (type.IsValueType || type.IsClass || type.IsInterface)
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

            foreach (var fileName in extractContext.EnumerateRequiredPrivateIncludeFileNames())
            {
                twSource.WriteLine("#include <{0}>", fileName);
            }

            var assemblyName = extractContext.Assembly.Name.Name;
            twSource.WriteLine("#include \"{0}.h\"", assemblyName);

            twSource.WriteLine();
            twSource.WriteLine("//////////////////////////////////////////////////////////////////////////////////");
            twSource.WriteLine("// Const strings:");
            twSource.WriteLine();

            foreach (var kv in extractContext.ExtractConstStrings())
            {
                var escaped = Utilities.GetEscapedCString(kv.Value);
                twSource.WriteLine(
                    "IL2C_CONST_STRING({0}, L\"{1}\");",
                    kv.Key,
                    escaped);
            }

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

            foreach (var type in allTypes)
            {
                twSource.WriteLine();

                // All static fields
                foreach (var field in type.Fields
                    .Where(field => field.IsStatic))
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
                twSource.WriteLine("// Type: {0}", type.GetFullMemberName());

                // All methods and constructor exclude type initializer
                foreach (var method in type.Methods
                    .Where(method => !method.IsConstructor || !method.IsStatic))
                {
                    InternalConvertFromMethod(
                        twSource,
                        extractContext,
                        preparedFunctions,
                        method,
                        indent,
                        debugInformationOption);
                }

                if (type.IsClass || type.IsValueType)
                {
                    InternalConvertTypeHelper(
                        twSource,
                        extractContext,
                        type,
                        indent);
                }
                else if (type.IsInterface)
                {
                    InternalConvertTypeHelperForInterface(
                        twSource,
                        type,
                        indent);
                }
            }
        }
    }
}
