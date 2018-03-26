using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;

using Mono.Cecil;

using IL2C.Translators;
using IL2C.Metadata;

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
        private static IMethodInformation[] GetCallableMethods(this ITypeInformation declaredType)
        {
            return declaredType
                .DeclaredMethods
                .Where(method => method.IsCallableMethod)
                .ToArray();
        }

        private static void InternalConvertType(
            TextWriter tw,
            ITypeInformation declaredType,
            string indent)
        {
            if (declaredType.IsPrimitive
                || !(declaredType.IsValueType || declaredType.IsClass || declaredType.IsInterface))
            {
                return;
            }

            tw.WriteLine("////////////////////////////////////////////////////////////");
            tw.WriteLine(
                "// [1] {0}",
                declaredType.FriendlyName);

            // Enum declarator:
            if (declaredType.IsEnum)
            {
                tw.WriteLine();
                tw.WriteLine(
                    "// [1-1] {0} layout",
                    declaredType.MemberTypeName);
                tw.WriteLine(
                    "typedef enum {0}",
                    declaredType.MangledName);
                tw.WriteLine("{");

                // Emit enum values
                foreach (var field in declaredType.Fields.Where(field => field.HasConstant))
                {
                    tw.WriteLine(
                        "{0}{1}_{2} = {3},",
                        indent,
                        declaredType.MangledName,
                        field.Name,
                        field.ConstantValue);
                }

                tw.WriteLine(
                    "}} {0};",
                    declaredType.MangledName);
            }

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

            // NOTE: 1 of 2
            //   Enum type derived from System.Enum,
            //   so all enum types boxed to System.Enum
            //   (and those types can dynamic cast to IConvertible, IFormattable and IComparable with NO specialized boxed type layouts... in C#?)
            if (!declaredType.IsEnum)
            {
                tw.WriteLine();
                tw.WriteLine(
                    "// [1-2] {0} vtable layout",
                    declaredType.MemberTypeName);
                tw.WriteLine("typedef const struct");
                tw.WriteLine("{");
                tw.WriteLine(
                    "{0}/* internalcall */ void* (*IL2C_RuntimeCast)({1} this__, IL2C_RUNTIME_TYPE_DECL* type);",
                    indent,
                    declaredType.CLanguageThisTypeName);

                foreach (var method in declaredType.VirtualMethods)
                {
                    tw.WriteLine(
                        "{0}{1};",
                        indent,
                        method.CLanguageFunctionPrototype);
                }

                tw.WriteLine(
                    "}} __{0}_VTABLE_DECL__;",
                    declaredType.MangledName);

                tw.WriteLine();
                tw.WriteLine(
                    "// [1-3] {0} layout",
                    declaredType.MemberTypeName);
                tw.WriteLine(
                    "struct {0}",
                    declaredType.MangledName);
                tw.WriteLine("{");

                // Emit vptr:
                if (declaredType.IsClass || declaredType.IsInterface)
                {
                    tw.WriteLine(
                        "{0}__{1}_VTABLE_DECL__* vptr0__;",
                        indent,
                        declaredType.MangledName);
                }

                // TODO: If value type implements interfaces, how to assigns vptr into value type?
                //   (We often have to resolve at enum types...)
                var fields = declaredType
                    .Traverse(type => type.BaseType)
                    .Reverse()
                    .SelectMany(type =>
                    {
                        var vptrs = type.InterfaceTypes
                            .Select(interfaceType => new
                            {
                                Name = string.Format(
                                    "vptr_{0}__",
                                    interfaceType.MangledName),
                                TypeName = string.Format(
                                    "__{0}_VTABLE_DECL__*",
                                    interfaceType.MangledName)
                            });

                        var thisFields = type.Fields
                            .Where(field => !field.IsStatic)
                            .Select(field => new
                            {
                                field.Name,
                                TypeName = field.FieldType.CLanguageTypeName
                            });

                        return vptrs.Concat(thisFields);
                    })
                    .ToArray();

                foreach (var field in fields)
                {
                    tw.WriteLine(
                        "{0}{1} {2};",
                        indent,
                        field.TypeName,
                        field.Name);
                }

                tw.WriteLine("};");
            }

            tw.WriteLine();
            tw.WriteLine(
                "// [1-4] {0} runtime type information",
                declaredType.MemberTypeName);
            tw.WriteLine(
                "extern IL2C_RUNTIME_TYPE_DECL __{0}_RUNTIME_TYPE__;",
                declaredType.MangledName);

            tw.WriteLine();
            tw.WriteLine(
                "// [1-5] {0} vtable",
                declaredType.MemberTypeName);
            tw.WriteLine(
                "extern __{0}_VTABLE_DECL__ __{0}_VTABLE__;",
                declaredType.MangledName);
        }

        private static void InternalConvertToPrototypes(
            TextWriter tw,
            ITypeInformation[] types,
            Func<ITypeInformation, bool> predictType,
            Func<IFieldInformation, bool> predictField,
            Func<IMethodInformation, bool> predictMethod,
            string indent)
        {
            tw.WriteLine();
            tw.WriteLine("#ifdef __cplusplus");
            tw.WriteLine("extern \"C\" {");
            tw.WriteLine("#endif");

            tw.WriteLine();
            tw.WriteLine("//////////////////////////////////////////////////////////////////////////////////");
            tw.WriteLine("// [2-1] Types:");
            tw.WriteLine();

            // Output prototypes.
            foreach (var type in types
                .Where(type => !type.IsEnum && predictType(type)))
            {
                tw.WriteLine(
                    "typedef struct {0} {0};",
                    type.MangledName);
            }

            // Output value type and object reference type.
            foreach (var type in types
                .Where(predictType))
            {
                tw.WriteLine();
                InternalConvertType(
                    tw,
                    type,
                    indent);
            }

            tw.WriteLine();
            tw.WriteLine("//////////////////////////////////////////////////////////////////////////////////");
            tw.WriteLine("// [2-2] Public static fields:");

            foreach (var type in types
                .Where(type => !type.IsEnum))
            {
                tw.WriteLine();

                foreach (var field in type.Fields
                    .Where(field => field.IsPublic && field.IsStatic && predictField(field)))
                {
                    tw.WriteLine(
                        "extern {0};",
                        field.GetCLanguagePrototype(false));
                }
            }

            tw.WriteLine();
            tw.WriteLine("//////////////////////////////////////////////////////////////////////////////////");
            tw.WriteLine("// [2-3] Methods:");

            foreach (var type in types
                .Where(type => !type.IsEnum))
            {
                tw.WriteLine();
                tw.WriteLine(
                    "// [2-4] Member methods: {0}",
                    type.FriendlyName);
                tw.WriteLine();

                if (!type.IsStatic)
                {
                    if (!type.IsInterface)
                    {
                        tw.WriteLine(
                            "extern /* internalcall */ void __{0}_IL2C_MarkHandler__({1} this__);",
                            type.MangledName,
                            type.CLanguageThisTypeName);
                    }

                    tw.WriteLine(
                        "extern /* internalcall */ void* __{0}_IL2C_RuntimeCast__({1} this__, IL2C_RUNTIME_TYPE_DECL* type);",
                        type.MangledName,
                        type.CLanguageThisTypeName);
                }

                foreach (var method in type.GetCallableMethods()
                    .Where(predictMethod))
                {
                    tw.WriteLine(
                        "extern {0}{1};",
                        method.IsVirtual ? "/* virtual */ " : string.Empty,
                        method.CLanguageFunctionPrototype);
                }

                if (!type.IsStatic)
                {
                    tw.WriteLine();
                    tw.WriteLine(
                        "// [2-5] Virtual methods: {0}",
                        type.FriendlyName);
                    tw.WriteLine();

                    foreach (var method in type.VirtualMethods
                        .Where(predictMethod))
                    {
                        var functionParametersDeclaration = string.Join(
                            ", ",
                            method.Parameters
                                .Select(parameter => string.Format(
                                    "/* {0} */ {1}",
                                    type.MangledName,
                                    parameter.SymbolName)));
                        tw.WriteLine(
                            "#define {0}_{1}({2}) \\",
                            type.MangledName,
                            method.CLanguageVirtualFunctionDeclarationName,
                            functionParametersDeclaration);

                        var functionParameters = string.Join(
                            ", ",
                            method.Parameters
                                .Select(parameter => parameter.SymbolName));
                        tw.WriteLine(
                            "{0}((this__)->vptr0__->{1}({2}))",
                            indent,
                            method.CLanguageVirtualFunctionDeclarationName,
                            functionParameters);
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
            PreparedMethodInformation preparedMethod,
            string indent,
            DebugInformationOptions debugInformationOption)
        {
            var locals = preparedMethod.Method.LocalVariables;

            tw.WriteLine();
            tw.WriteLine("///////////////////////////////////////");
            tw.WriteLine(
                "// [3] {0}{1}",
                preparedMethod.Method.IsVirtual ? "Virtual: " : string.Empty,
                preparedMethod.Method.FriendlyName);
            tw.WriteLine();

            tw.WriteLine(preparedMethod.Method.CLanguageFunctionPrototype);
            tw.WriteLine("{");

            tw.WriteLine("{0}//-------------------", indent);
            tw.WriteLine("{0}// Local variables:", indent);
            tw.WriteLine();

            // Important NULL assigner (p = NULL):
            //   Because these variables are pointer (of object reference).
            //   So GC will traverse these variables just setup the stack frame.

            foreach (var local in preparedMethod.Method.LocalVariables)
            {
                tw.WriteLine(
                    "{0}{1} {2}{3};",
                    indent,
                    local.TargetType.CLanguageTypeName,
                    local.SymbolName,
                    local.TargetType.IsValueType ? string.Empty : " = NULL");
            }

            tw.WriteLine();
            tw.WriteLine("{0}//-------------------", indent);
            tw.WriteLine("{0}// Evaluation stacks:", indent);
            tw.WriteLine();

            foreach (var stack in preparedMethod.Stacks)
            {
                tw.WriteLine(
                    "{0}{1} {2}{3};",
                    indent,
                    stack.TargetType.CLanguageTypeName,
                    stack.SymbolName,
                    stack.TargetType.IsValueType ? string.Empty : " = NULL");
            }

            var frameEntries = locals
                .Concat(preparedMethod.Stacks)
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
                        frameEntry.TargetType.CLanguageTypeName,
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
            foreach (var ci in preparedMethod.Method.CodeStream)
            {
                // Write label if available and used.
                if (preparedMethod.LabelNames.TryGetValue(ci.Offset, out var labelName))
                {
                    tw.WriteLine("{0}:", labelName);
                }

                // Write the line preprocessor directive if available.
                if (canWriteSequencePoint && ci.Debug.Any())
                {
                    var sp = ci.Debug.First();
                    switch (debugInformationOption)
                    {
                        case DebugInformationOptions.Full:
                            tw.WriteLine(
                                "#line {0} \"{1}\"",
                                sp.Line,
                                sp.Path.Replace("\\", "\\\\"));
                            break;
                        case DebugInformationOptions.CommentOnly:
                            tw.WriteLine(
                                "/* {0}({1}): */",
                                sp.Path.Replace("\\", "\\\\"),
                                sp.Line);
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
                        ci);
                }

                // Generate source code fragments and write.
                var sourceCodes = preparedMethod.Generators[ci.Offset](extractContext);
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

        private static void InternalConvertFromDelegateFunction(
            TextWriter tw,
            IMethodInformation method,
            string indent)
        {
            tw.WriteLine();
            tw.WriteLine("///////////////////////////////////////");
            tw.WriteLine("// [4] Abstract: {0}", method.FriendlyName);
            tw.WriteLine();

            tw.WriteLine(method.CLanguageFunctionPrototype);
            tw.WriteLine("{");

            tw.WriteLine(
                "{0}// WARNING: Pure virtual function called.",
                indent);
            tw.WriteLine(
                "{0}//TODO: throw : assert(0);",
                indent);

            if (method.ReturnType.IsVoidType == false)
            {
                tw.WriteLine(
                    "{0}return ({1}){2};",
                    indent,
                    method.ReturnType.CLanguageTypeName,
                    method.ReturnType.IsNumericPrimitive ? "0" : "NULL");
            }

            tw.WriteLine("}");
        }

        private static void InternalConvertFromAbstractFunction(
            TextWriter tw,
            IMethodInformation method,
            string indent)
        {
            tw.WriteLine();
            tw.WriteLine("///////////////////////////////////////");
            tw.WriteLine("// [5] Abstract: {0}", method.FriendlyName);
            tw.WriteLine();

            tw.WriteLine(method.CLanguageFunctionPrototype);
            tw.WriteLine("{");

            tw.WriteLine(
                "{0}// WARNING: Pure virtual function called.",
                indent);
            tw.WriteLine(
                "{0}//TODO: throw : assert(0);",
                indent);

            if (method.ReturnType.IsVoidType == false)
            {
                tw.WriteLine(
                    "{0}return ({1}){2};",
                    indent,
                    method.ReturnType.CLanguageTypeName,
                    method.ReturnType.IsNumericPrimitive ? "0" : "NULL");
            }

            tw.WriteLine("}");
        }

        private static void InternalConvertFromPInvokeFunction(
            TextWriter tw,
            IMethodInformation method,
            PInvokeInfo pinvokeInfo,
            string indent)
        {
            tw.WriteLine();
            tw.WriteLine("///////////////////////////////////////");
            tw.WriteLine("// [6] P/Invoke: {0}", method.FriendlyName);
            tw.WriteLine();

            tw.WriteLine(method.CLanguageFunctionPrototype);
            tw.WriteLine("{");

            var arguments = string.Join(
                ", ",
                method.Parameters
                    .Select(parameter => parameter.GetMarshaledInExpression()));

            if (method.ReturnType.IsVoidType)
            {
                tw.WriteLine("{0}{1}({2});", indent, pinvokeInfo.EntryPoint, arguments);
            }
            else
            {
                tw.WriteLine("{0}return {1}({2});", indent, pinvokeInfo.EntryPoint, arguments);
            }

            tw.WriteLine("}");
        }

        private struct VirtualFunctionInformation
        {
            public readonly string MangledTypeName;
            public readonly string CLanguageTypeName;
            public readonly string CLanguageVirtualFunctionDeclarationName;
            public readonly string CLanguageReturnTypeName;
            public readonly KeyValuePair<string, string>[] Parameters;

            public VirtualFunctionInformation(
                string mangledTypeName,
                string cLanguageTypeName,
                string cLanguageVirtualFunctionDeclarationName,
                string cLanguageReturnTypeName,
                KeyValuePair<string, string>[] parameters)
            {
                this.MangledTypeName = mangledTypeName;
                this.CLanguageTypeName = cLanguageTypeName;
                this.CLanguageVirtualFunctionDeclarationName = cLanguageVirtualFunctionDeclarationName;
                this.CLanguageReturnTypeName = cLanguageReturnTypeName;
                this.Parameters = parameters;
            }
        }

        private static VirtualFunctionInformation[] GetVirtualFunctions(
            ITypeInformation adjustorThunkTargetType,
            ITypeInformation delegationTargetType) =>
            adjustorThunkTargetType
                .OverridedMethods
                .Select(method => new VirtualFunctionInformation(
                    method.DeclaringType.Equals(adjustorThunkTargetType)
                        ? delegationTargetType.MangledName
                        : method.DeclaringType.MangledName,
                    method.DeclaringType.Equals(adjustorThunkTargetType)
                        ? delegationTargetType.CLanguageTypeName
                        : method.DeclaringType.CLanguageTypeName,
                    method.CLanguageVirtualFunctionDeclarationName,
                    method.ReturnType.CLanguageTypeName,
                    method.GetParameters(adjustorThunkTargetType)
                        .Select((parameter, index) => Utilities.KeyValue(
                            (index == 0) ? parameter.TargetType.CLanguageThisTypeName : parameter.TargetType.CLanguageTypeName,
                            parameter.SymbolName))
                        .ToArray()))
                .ToArray();

        private static void InternalConvertTypeHelper(
            TextWriter tw,
            ITypeInformation declaredType,
            string indent)
        {
            tw.WriteLine();
            tw.WriteLine("//////////////////////");
            tw.WriteLine("// [7] Runtime helpers:");

            // Write RuntimeCast function:
            tw.WriteLine();
            tw.WriteLine("// [7-1] Runtime cast");
            tw.WriteLine(
                "void* __{0}_IL2C_RuntimeCast__({1} this__, IL2C_RUNTIME_TYPE_DECL* type)",
                declaredType.MangledName,
                declaredType.CLanguageThisTypeName);
            tw.WriteLine("{");

            // RuntimeCast: this type.
            // If type is value type, this operations invalid (ignore operation then cause InvalidCastException)
            //   TODO: inlining all base type comparer are better than base invoker?
            if (!declaredType.IsValueType)
            {
                tw.WriteLine(
                    "{0}// [7-2] This type",
                    indent);
                tw.WriteLine(
                    "{0}if (type == il2c_typeof({1})) return this__;",
                    indent,
                    declaredType.MangledName);
            }

            // RuntimeCast: implemented interfaces.
            if (declaredType.InterfaceTypes.Length >= 1)
            {
                tw.WriteLine();
                tw.WriteLine(
                    "{0}// [7-3] Interface types",
                    indent);

                foreach (var interfaceType in declaredType.InterfaceTypes)
                {
                    // NOTE:
                    //  The virtual function pointer added offset from between vptr_TYPE__ and vptr0__.
                    //  If will invoke interface's virtual function,
                    //  the function is delegated "Adjust thunk" function,
                    //  it will recalculate this pointer offset.
                    tw.WriteLine(
                        "{0}if (type == il2c_typeof({1})) return (void*)&(this__->vptr_{1}__);",
                        indent,
                        interfaceType.MangledName);
                }
            }

            // RuntimeCast: reflect base types.
            tw.WriteLine();
            tw.WriteLine(
                "{0}// [7-4] Delegate checking base types",
                indent);
            tw.WriteLine(
                "{0}return __{1}_IL2C_RuntimeCast__(({2})this__, type);",
                indent,
                declaredType.BaseType.MangledName,
                declaredType.BaseType.CLanguageThisTypeName);
            tw.WriteLine("}");

            // Write mark handler:
            tw.WriteLine();
            tw.WriteLine(
                "// [7-5] GC's mark handler");
            tw.WriteLine(
                "void __{0}_IL2C_MarkHandler__({1} this__)",
                declaredType.MangledName,
                declaredType.CLanguageThisTypeName);
            tw.WriteLine("{");

            var fields = declaredType.Fields
                .Where(field => !field.IsStatic && !field.FieldType.IsValueType)
                .ToArray();
            if (fields.Length >= 1)
            {
                tw.WriteLine(
                    "{0}// [7-6] Try marking each object reference fields",
                    indent);
                foreach (var field in fields)
                {
                    tw.WriteLine(
                        "{0}il2c_try_mark_from_handler(this__->{1});",
                        indent,
                        field.MangledName);
                }
            }

            // NOTE:
            //   Invoke base class mark handler except contains NO fields.
            //   (ex: System.Object, System.ValueType...)
            var baseType = declaredType.BaseType;
            if (baseType != null)
            {
                if (baseType
                    .Traverse(type => type.BaseType)
                    .Any(type => type.Fields.Length >= 1) == false)
                {
                    tw.WriteLine();
                    tw.WriteLine(
                        "{0}// [7-7] Delegate checking base types",
                        indent);
                    tw.WriteLine(
                        "{0}__{1}_IL2C_MarkHandler__(({2})this__);",
                        indent,
                        declaredType.BaseType.MangledName,
                        declaredType.BaseType.CLanguageTypeName);
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
            tw.WriteLine("// [7-8] Runtime type information");
            tw.WriteLine(
                "IL2C_RUNTIME_TYPE_DECL __{0}_RUNTIME_TYPE__ = {{",
                declaredType.MangledName);
            tw.WriteLine(
                "{0}\"{1}\",",
                indent,
                declaredType.FriendlyName);
            tw.WriteLine(
                "{0}sizeof({1}),",
                indent,
                declaredType.MangledName);
            tw.WriteLine(
                "{0}/* internalcall */ (IL2C_MARK_HANDLER)__{1}_IL2C_MarkHandler__,",
                indent,
                declaredType.MangledName);

            tw.WriteLine("};");

            // NOTE: 2 of 2
            //   Enum type derived from System.Enum,
            //   so all enum types boxed to System.Enum
            //   (and those types can dynamic cast to IConvertible, IFormattable and IComparable with NO specialized boxed type layouts... in C#?)
            if (!declaredType.IsEnum)
            {
                tw.WriteLine();
                tw.WriteLine("//////////////////////");
                tw.WriteLine("// [7-9] VTables:");

                // Write virtual methods
                tw.WriteLine();
                tw.WriteLine(
                    "// [7-10] Vtable of {0}",
                    declaredType.FriendlyName);
                tw.WriteLine(
                    "__{0}_VTABLE_DECL__ __{0}_VTABLE__ = {{",
                    declaredType.MangledName);

                var virtualFunctions = GetVirtualFunctions(
                    declaredType,
                    declaredType);

                foreach (var function in virtualFunctions)
                {
                    tw.WriteLine(
                        "{0}__{1}_{2}__,",
                        indent,
                        function.MangledTypeName,
                        function.CLanguageVirtualFunctionDeclarationName);
                    //tw.WriteLine(
                    //    "{0}{1} (*{2})({3}),",
                    //    indent,
                    //    function.ReturnTypeName,
                    //    function.Name,
                    //    string.Join(", ", function.Parameters.Select(p => p.Key)));
                }

                tw.WriteLine("};");

                foreach (var interfaceType in declaredType.InterfaceTypes)
                {
                    var interfaceVirtualFunctions = GetVirtualFunctions(
                        interfaceType,
                        declaredType);

                    foreach (var function in interfaceVirtualFunctions)
                    {
                        // Adjustor thunk will not invoke direct, so try to emit static function.
                        tw.WriteLine();
                        tw.WriteLine(
                            "// [7-11] Adjustor thunk: {0}.{1}",
                            function.CLanguageTypeName,
                            function.CLanguageVirtualFunctionDeclarationName);
                        tw.WriteLine(
                            "static {0} __{1}_{2}_AT_{3}__(",
                            function.CLanguageReturnTypeName,
                            function.CLanguageTypeName,
                            function.CLanguageVirtualFunctionDeclarationName,
                            interfaceType.MangledName);
                        tw.WriteLine(
                            "{0}{1})",
                            indent,
                            string.Join(
                                ", ",
                                function.Parameters.Select(parameter =>
                                    string.Format(
                                        "{0} {1}",
                                        parameter.Key,
                                        parameter.Value))));
                        tw.WriteLine(
                            "{");
                        tw.WriteLine(
                            "{0}{1}__{2}_{3}__({4});",
                            indent,
                            (function.CLanguageReturnTypeName != "void") ? "return " : string.Empty,
                            function.CLanguageTypeName,
                            function.CLanguageVirtualFunctionDeclarationName,
                            string.Join(
                                ", ",
                                function.Parameters.Select((parameter, index) =>
                                    (index == 0)
                                        // Adjust vptr offset with il2c_cast_from_interface() macro.
                                        ? string.Format(
                                            "({0}*)il2c_cast_from_interface({1}, {2}, {3})",
                                            function.CLanguageTypeName,
                                            declaredType.MangledName,
                                            interfaceType.MangledName,
                                            parameter.Value)
                                        : parameter.Value)));
                        tw.WriteLine(
                            "}");
                    }

                    tw.WriteLine();
                    tw.WriteLine(
                        "// [7-12] Vtable of {0} (with adjustor thunk)",
                        interfaceType.FriendlyName);
                    tw.WriteLine(
                        "__{0}_VTABLE_DECL__ __{1}_{0}_VTABLE__ = {{",
                        interfaceType.MangledName,
                        declaredType.MangledName);

                    foreach (var function in interfaceVirtualFunctions)
                    {
                        tw.WriteLine(
                            "{0}__{1}_{2}_AT_{3}__,",
                            indent,
                            function.CLanguageTypeName,
                            function.CLanguageVirtualFunctionDeclarationName,
                            interfaceType.MangledName);
                    }

                    tw.WriteLine("};");
                }
            }
        }

        private static void InternalConvertTypeHelperForInterface(
            TextWriter tw,
            ITypeInformation declaredType,
            string indent)
        {
            tw.WriteLine();
            tw.WriteLine("//////////////////////");
            tw.WriteLine("// [8] Runtime helpers:");

            // Write runtime type information
            tw.WriteLine();
            tw.WriteLine("// [8-1] Runtime type information");

            // TODO: IL2C_RUNTIME_TYPE_DECL's some fields not used.
            tw.WriteLine(
                "IL2C_RUNTIME_TYPE_DECL __{0}_RUNTIME_TYPE__ = {{",
                declaredType.MangledName);
            tw.WriteLine(
                "{0}\"{1}\", 0, NULL",
                indent,
                declaredType.FriendlyName);
            tw.WriteLine("};");
        }

        internal static void InternalConvertFromMethod(
            TextWriter tw,
            IExtractContext extractContext,
            PreparedMethodInformations preparedFunctions,
            IMethodInformation method,
            string indent,
            DebugInformationOptions debugInformationOption = DebugInformationOptions.None)
        {
            if (method.IsVirtual)
            {
                if (method.IsAbstract)
                {
                    Debug.Assert(method.DeclaringType.IsInterface == false);

                    InternalConvertFromAbstractFunction(
                        tw,
                        method,
                        indent);
                    return;
                }
            }

            if (method.IsExtern)
            {
                var pinvokeInfo = method.PInvokeInfo;
                if (pinvokeInfo == null)
                {
                    // TODO: Support marked by internalcall.
                    throw new InvalidProgramSequenceException(
                        "Missing DllImport attribute at P/Invoke entry: Method={0}",
                        method.FriendlyName);
                }

                InternalConvertFromPInvokeFunction(
                    tw,
                    method,
                    pinvokeInfo,
                    indent);
                return;
            }

            if (preparedFunctions.Functions.TryGetValue(method, out var preparedMethod))
            {
                InternalConvertFromFunction(
                    tw,
                    extractContext,
                    preparedMethod,
                    indent,
                    debugInformationOption);
            }
        }

        public static void WriteHeader(
            TextWriter twHeader,
            TranslateContext translateContext,
            PreparedMethodInformations preparedMethods,
            string indent)
        {
            IExtractContext extractContext = translateContext;

            var assemblyName = extractContext.Assembly.MangledName;

            twHeader.WriteLine("#ifndef __{0}_H__", assemblyName);
            twHeader.WriteLine("#define __{0}_H__", assemblyName);
            twHeader.WriteLine();

            foreach (var fileName in extractContext.EnumerateRequiredIncludeFileNames())
            {
                twHeader.WriteLine("#include <{0}>", fileName);
            }

            var allTypes = extractContext.Assembly.Modules
                .SelectMany(module => module.Types)
                .SelectMany(type => new[] { type }.Concat(type.NestedTypes))
                .Where(type => type.IsValidDefinition)
                .ToArray();

            // All types exclude privates
            InternalConvertToPrototypes(
                twHeader,
                allTypes,
                type => type.IsCLanguagePublicScope,
                field => field.IsPublic || field.IsFamily || field.IsFamilyOrAssembly,
                method => method.IsPublic || method.IsFamily || method.IsFamilyOrAssembly,
                indent);

            twHeader.WriteLine();
            twHeader.WriteLine("#endif");
        }

        public static void WriteSourceCode(
            TextWriter twSource,
            TranslateContext translateContext,
            PreparedMethodInformations preparedMethods,
            string indent,
            DebugInformationOptions debugInformationOption = DebugInformationOptions.Full)
        {
            IExtractContext extractContext = translateContext;

            foreach (var fileName in extractContext.EnumerateRequiredPrivateIncludeFileNames())
            {
                twSource.WriteLine("#include \"{0}\"", fileName);
            }

            twSource.WriteLine("#include \"{0}.h\"", extractContext.Assembly.Name);

            twSource.WriteLine();
            twSource.WriteLine("//////////////////////////////////////////////////////////////////////////////////");
            twSource.WriteLine("// [9-1] Const strings:");
            twSource.WriteLine();

            foreach (var kv in extractContext.ExtractConstStrings())
            {
                var escaped = Utilities.GetEscapedCString(kv.Value);
                twSource.WriteLine(
                    "IL2C_CONST_STRING({0}, L\"{1}\");",
                    kv.Key,
                    escaped);
            }

            twSource.WriteLine();
            twSource.WriteLine("//////////////////////////////////////////////////////////////////////////////////");
            twSource.WriteLine("// [9-2] File scope prototypes:");

            var allTypes = extractContext.Assembly.Modules
                .SelectMany(module => module.Types)
                .SelectMany(type => new[] { type }.Concat(type.NestedTypes))
                .Where(type => type.IsValidDefinition)
                .ToArray();

            // All types exclude publics and internals (for file scope prototypes)
            InternalConvertToPrototypes(
                twSource,
                allTypes,
                type => !type.IsCLanguagePublicScope,
                field => !(field.IsPublic || field.IsFamily || field.IsFamilyOrAssembly),
                method => !(method.IsPublic || method.IsFamily || method.IsFamilyOrAssembly),
                indent);

            twSource.WriteLine();
            twSource.WriteLine("//////////////////////////////////////////////////////////////////////////////////");
            twSource.WriteLine("// [9-3] Declare static fields:");

            foreach (var type in allTypes
                .Where(type => !type.IsEnum))
            {
                twSource.WriteLine();

                // All static fields
                foreach (var field in type.Fields
                    .Where(field => field.IsStatic))
                {
                    twSource.WriteLine(
                        "{0};",
                        field.GetCLanguagePrototype(true));
                }
            }

            twSource.WriteLine();
            twSource.WriteLine("//////////////////////////////////////////////////////////////////////////////////");
            twSource.WriteLine("// [9-4] Declare methods:");

            foreach (var type in allTypes)
            {
                twSource.WriteLine();
                twSource.WriteLine("////////////////////////////////////////////////////////////");
                twSource.WriteLine("// [9-4] Type: {0}", type.FriendlyName);

                // All methods and constructor exclude type initializer
                foreach (var method in type.DeclaredMethods)
                {
                    InternalConvertFromMethod(
                        twSource,
                        extractContext,
                        preparedMethods,
                        method,
                        indent,
                        debugInformationOption);
                }

                if (type.IsClass || type.IsValueType)
                {
                    InternalConvertTypeHelper(
                        twSource,
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
