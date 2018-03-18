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
                "// {0}",
                declaredType.ToString());

            if (declaredType.IsEnum)
            {
                tw.WriteLine();
                tw.WriteLine(
                    "// {0} layout",
                    declaredType.MemberTypeName);
                tw.WriteLine(
                    "typedef enum {0}",
                    declaredType.CLanguageName);
                tw.WriteLine("{");

                // Emit enum values
                foreach (var field in declaredType.Fields.Where(field => field.HasConstant))
                {
                    tw.WriteLine(
                        "{0}{1}_{2} = {3},",
                        indent,
                        declaredType.CLanguageName,
                        field.Name,
                        field.ConstantValue);
                }
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
                            TypeName = field.FieldType.CLanguageName
                        });

                    return vptrs.Concat(thisFields);
                })
                .ToArray();

            if ((declaredType.IsValueType == false) ||
                (fields.Length >= 1))
            {
                tw.WriteLine();
                tw.WriteLine(
                    "// {0} vtable layout",
                    declaredType.MemberTypeName);
                tw.WriteLine("typedef const struct");
                tw.WriteLine("{");
                tw.WriteLine(
                    "{0}/* internalcall */ void* (*IL2C_RuntimeCast)({1}* this__, IL2C_RUNTIME_TYPE_DECL* type);",
                    indent,
                    declaredType.MangledName);

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
                    "// {0} layout",
                    declaredType.MemberTypeName);
                tw.WriteLine(
                    "struct {0}",
                    declaredType.CLanguageName);
                tw.WriteLine("{");

                // Emit vptr:
                if (declaredType.IsClass || declaredType.IsInterface)
                {
                    tw.WriteLine(
                        "{0}__{1}_VTABLE_DECL__* vptr0__;",
                        indent,
                        declaredType.MangledName);
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

            tw.WriteLine();
            tw.WriteLine(
                "// {0} runtime type information",
                declaredType.MemberTypeName);
            tw.WriteLine(
                "extern IL2C_RUNTIME_TYPE_DECL __{0}_RUNTIME_TYPE__;",
                declaredType.MangledName);

            tw.WriteLine();
            tw.WriteLine(
                "// {0} vtable",
                declaredType.MemberTypeName);
            tw.WriteLine(
                "extern __{0}_VTABLE_DECL__ __{0}_VTABLE__;",
                declaredType.MangledName);
        }

        private static void InternalConvertToPrototypes(
            TextWriter tw,
            ITypeInformation[] types,
            Func<IMethodInformation, bool> predictMethod,
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
            foreach (var type in types.Where(type => !type.IsEnum))
            {
                tw.WriteLine(
                    "typedef struct {0} {0};",
                    type.CLanguageName);
            }

            // Output value type and object reference type.
            foreach (var type in types)
            {
                tw.WriteLine();
                InternalConvertType(
                    tw,
                    type,
                    indent);
            }

            tw.WriteLine();
            tw.WriteLine("//////////////////////////////////////////////////////////////////////////////////");
            tw.WriteLine("// Public static fields:");

            foreach (var type in types.Where(type => !type.IsEnum))
            {
                tw.WriteLine();

                foreach (var field in type.Fields
                    .Where(field => field.IsPublic && field.IsStatic))
                {
                    tw.WriteLine(
                        "extern {0};",
                        field.GetCLanguagePrototype(false));
                }
            }

            tw.WriteLine();
            tw.WriteLine("//////////////////////////////////////////////////////////////////////////////////");
            tw.WriteLine("// Methods:");

            foreach (var type in types.Where(type => !type.IsEnum))
            {
                tw.WriteLine();
                tw.WriteLine(
                    "// {0}",
                    type.MangledName);

                if (!type.IsInterface)
                {
                    tw.WriteLine(
                        "extern /* internalcall */ void __{0}_IL2C_MarkHandler__({1}* this__);",
                        type.MangledName,
                        type.CLanguageName);
                }

                tw.WriteLine(
                    "extern /* internalcall */ void* __{0}_IL2C_RuntimeCast__({1}* this__, IL2C_RUNTIME_TYPE_DECL* type);",
                    type.MangledName,
                    type.CLanguageName);

                foreach (var method in type.GetCallableMethods()
                    .Where(predictMethod))
                {
                    tw.WriteLine(
                        "extern {0}{1};",
                        method.IsVirtual ? "/* virtual */ " : string.Empty,
                        method.CLanguageFunctionPrototype);
                }

                foreach (var method in type.VirtualMethods
                    .Where(predictMethod))
                {
                    var functionParametersDeclaration = string.Join(
                        ", ",
                        method.Parameters
                            .Select(parameter => string.Format(
                                "/* {0} */ {1}",
                                parameter.TargetType.CLanguageName,
                                parameter.SymbolName)));
                    tw.WriteLine(
                        "#define {0}({1}) \\",
                        method.MangledName,
                        functionParametersDeclaration);

                    var functionParameters = string.Join(
                        ", ",
                        method.Parameters
                            .Select(parameter => parameter.SymbolName));
                    tw.WriteLine(
                        "{0}((this__)->vptr0__->{1}({2}))",
                        indent,
                        method.MangledName,
                        functionParameters);
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
                "// {0}{1}",
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
                    local.TargetType.CLanguageName,
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
                    stack.TargetType.CLanguageName,
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
                        frameEntry.TargetType.CLanguageName,
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
                if (preparedMethod.Labels.ContainsKey(ci.Offset))
                {
                    tw.WriteLine("{0}:", ci.Label);
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
            tw.WriteLine("// Abstract: {0}", method.FriendlyName);
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
                    method.ReturnType.CLanguageName,
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
            tw.WriteLine("// Abstract: {0}", method.FriendlyName);
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
                    method.ReturnType.CLanguageName,
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
            tw.WriteLine("// P/Invoke: {0}", method.FriendlyName);
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
            ITypeInformation adjustorThunkTargetType,
            ITypeInformation delegationTargetType)
        {
            return adjustorThunkTargetType
                .OverridedMethods
                .Select(method => new VirtualMethodInformation(
                    method.DeclaringType.Equals(adjustorThunkTargetType)
                        ? delegationTargetType.MangledName
                        : method.DeclaringType.MangledName,
                    method.MangledName,
                    method.ReturnType.MangledName,
                    method.GetParameters(adjustorThunkTargetType)
                        .Select(parameter => Utilities.KeyValue(
                            parameter.TargetType.MangledName,
                            parameter.SymbolName))
                        .ToArray()))
                .ToArray();
        }

        private static void InternalConvertTypeHelper(
            TextWriter tw,
            IExtractContext extractContext,
            ITypeInformation declaredType,
            string indent)
        {
            tw.WriteLine();
            tw.WriteLine("//////////////////////");
            tw.WriteLine("// Runtime helpers:");

            //var typeName = extractContext.GetCLanguageTypeName(
            //    declaredType,
            //    TypeNameFlags.Dereferenced);

            // Write RuntimeCast function:
            tw.WriteLine();
            tw.WriteLine("// Runtime cast");
            tw.WriteLine(
                "void* __{0}_IL2C_RuntimeCast__({1} this__, IL2C_RUNTIME_TYPE_DECL* type)",
                declaredType.MangledName,
                declaredType.CLanguageName);
            tw.WriteLine("{");

            // RuntimeCast: this type.
            //   TODO: inlining all base type comparer are better than base invoker?
            tw.WriteLine(
                "{0}// This type",
                indent);
            tw.WriteLine(
                "{0}if (type == il2c_typeof({1})) return this__;",
                indent,
                declaredType.MangledName);

            // RuntimeCast: implemented interfaces.
            if (declaredType.InterfaceTypes.Length >= 1)
            {
                tw.WriteLine();
                tw.WriteLine(
                    "{0}// Interface types",
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
                "{0}// Delegate checking base types",
                indent);
            tw.WriteLine(
                "{0}return __{1}_IL2C_RuntimeCast__(({2})this__, type);",
                indent,
                declaredType.BaseType.MangledName,
                extractContext.GetCLanguageTypeName(
                    declaredType.BaseType,
                    TypeNameFlags.ForcePointer));
            tw.WriteLine("}");

            // Write mark handler:
            var makrHandlerPrototype = string.Format(
                "void __{0}_IL2C_MarkHandler__({1} this__)",
                declaredType.MangledName,
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
                if ((baseType.IsObjectType || baseType.IsValueTypeType) == false)
                {
                    tw.WriteLine();
                    tw.WriteLine(
                        "{0}// Delegate checking base types",
                        indent);
                    tw.WriteLine(
                        "{0}__{1}_IL2C_MarkHandler__(({2})this__);",
                        indent,
                        declaredType.BaseType.MangledName,
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
                declaredType.MangledName);
            tw.WriteLine(
                "{0}\"{1}\",",
                indent,
                declaredType.FriendlyName);
            tw.WriteLine(
                "{0}sizeof({1}),",
                indent,
                declaredType.CLanguageName);
            tw.WriteLine(
                "{0}/* internalcall */ (IL2C_MARK_HANDLER)__{1}_IL2C_MarkHandler__,",
                indent,
                declaredType.MangledName);

            tw.WriteLine("};");

            tw.WriteLine();
            tw.WriteLine("//////////////////////");
            tw.WriteLine("// VTables:");

            // Write virtual methods
            tw.WriteLine();
            tw.WriteLine(
                "// Vtable of {0}",
                declaredType.FriendlyName);
            tw.WriteLine(
                "__{0}_VTABLE_DECL__ __{0}_VTABLE__ = {{",
                declaredType.MangledName);

            var virtualMethods = GetVirtualMethods(
                declaredType,
                declaredType);

            foreach (var method in virtualMethods)
            {
                tw.WriteLine(
                    "{0}({1} (*)({2}))__{3}_{4}__,",
                    indent,
                    method.ReturnTypeName,
                    string.Join(", ", method.Parameters.Select(p => p.Key)),
                    method.TypeName,
                    method.Name);
            }

            tw.WriteLine("};");

            foreach (var interfaceType in declaredType.InterfaceTypes)
            {
                var interfaceVirtualMethods = GetVirtualMethods(
                    interfaceType,
                    declaredType);

                foreach (var method in interfaceVirtualMethods)
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
                        interfaceType.MangledName);
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
                                        declaredType.MangledName,
                                        interfaceType.MangledName,
                                        parameter.Value)
                                    : parameter.Value)));
                    tw.WriteLine(
                        "}");
                }

                tw.WriteLine();
                tw.WriteLine(
                    "// Vtable of {0} (with adjustor thunk)",
                    interfaceType.FriendlyName);
                tw.WriteLine(
                    "__{0}_VTABLE_DECL__ __{1}_{0}_VTABLE__ = {{",
                    interfaceType.MangledName,
                    declaredType.MangledName);

                foreach (var method in interfaceVirtualMethods)
                {
                    tw.WriteLine(
                        "{0}__{1}_{2}_AT_{3}__,",
                        indent,
                        method.TypeName,
                        method.Name,
                        interfaceType.MangledName);
                }

                tw.WriteLine("};");
            }
        }

        private static void InternalConvertTypeHelperForInterface(
            TextWriter tw,
            ITypeInformation declaredType,
            string indent)
        {
            tw.WriteLine();
            tw.WriteLine("//////////////////////");
            tw.WriteLine("// Runtime helpers:");

            // Write runtime type information
            tw.WriteLine();
            tw.WriteLine("// Runtime type information");

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

            var assemblyName = extractContext.Assembly.UniqueName;
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
                .SelectMany(type => new[] { type }.Concat(type.NestedTypes))
                // All types exclude privates
                .Where(type => type.IsValidDefinition
                    && (type.IsPublic || type.IsNestedPublic || type.IsNestedFamily || type.IsNestedFamilyOrAssembly))
                .ToArray();

            InternalConvertToPrototypes(
                twHeader,
                types,
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

            var assemblyName = extractContext.Assembly.UniqueName;
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
                .SelectMany(type => new[] { type }.Concat(type.NestedTypes))
                .Where(type => type.IsValidDefinition)
                .ToArray();

            // All types exclude publics and internals (for file scope prototypes)
            var types = allTypes
                .Where(type => !(type.IsPublic || type.IsNestedPublic || type.IsNestedFamily || type.IsNestedFamilyOrAssembly))
                .ToArray();

            InternalConvertToPrototypes(
                twSource,
                types,
                method => !(method.IsPublic || method.IsFamily || method.IsFamilyOrAssembly),
                indent);

            twSource.WriteLine();
            twSource.WriteLine("//////////////////////////////////////////////////////////////////////////////////");
            twSource.WriteLine("// Static fields:");

            foreach (var type in allTypes.Where(type => !type.IsEnum))
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

            foreach (var type in allTypes.Where(type => !type.IsEnum))
            {
                twSource.WriteLine();
                twSource.WriteLine("////////////////////////////////////////////////////////////");
                twSource.WriteLine("// Type: {0}", type.FriendlyName);

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
