using System;
using System.Collections.Generic;
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

            var virtualMethods = declaredType.CalculatedVirtualMethods;
            var overrideMethods = declaredType.OverrideMethods;
            var newSlotMethods = declaredType.NewSlotMethods;
            var overrideBaseMethods = declaredType.OverrideBaseMethods;

            // If virtual method collection doesn't contain newslot method at this declared type:
            if (!newSlotMethods.Any(method => method.DeclaringType.Equals(declaredType)))
            {
                tw.WriteLine();
                tw.WriteLine(
                    "// [1-2-1] {0} vtable layout (Same as {1})",
                    declaredType.MemberTypeName,
                    declaredType.BaseType.FriendlyName);

                tw.WriteLine(
                    "typedef __{0}_VTABLE_DECL__ __{1}_VTABLE_DECL__;",
                    declaredType.BaseType.MangledName,
                    declaredType.MangledName);
            }
            // Require new vtable layout.
            else
            {
                tw.WriteLine();
                tw.WriteLine(
                    "// [1-2-2] {0} vtable layout (Derived from {1})",
                    declaredType.MemberTypeName,
                    declaredType.BaseType.FriendlyName);

                tw.WriteLine("typedef const struct");
                tw.WriteLine("{");
                tw.WriteLine(
                    "{0}/* internalcall */ void* (*il2c_isinst__)(void* this__, IL2C_RUNTIME_TYPE_DECL* type);",
                    indent);

                foreach (var (method, overloadIndex) in virtualMethods)
                {
                    tw.WriteLine(
                        "{0}{1};",
                        indent,
                        method.GetCLanguageFunctionPrototype(overloadIndex));
                }

                tw.WriteLine(
                    "}} __{0}_VTABLE_DECL__;",
                    declaredType.MangledName);
            }

            // Write a enum:
            if (declaredType.IsEnum)
            {
                tw.WriteLine();
                tw.WriteLine(
                    "// [1-1] {0} layout",
                    declaredType.MemberTypeName);
                tw.WriteLine(
                    "enum {0}",
                    declaredType.MangledName);
                tw.WriteLine("{");

                // Emit enum values
                long currentValue = 0;
                foreach (var field in declaredType.Fields.Where(field => field.HasConstant))
                {
                    long value = Convert.ToInt64(field.ConstantValue);
                    if (value == currentValue)
                    {
                        tw.WriteLine(
                            "{0}{1}_{2},",
                            indent,
                            declaredType.MangledName,
                            field.Name);
                        currentValue++;
                    }
                    else
                    {
                        tw.WriteLine(
                            "{0}{1}_{2} = {3},",
                            indent,
                            declaredType.MangledName,
                            field.Name,
                            value);
                        currentValue = value + 1;
                    }
                }

                tw.WriteLine("};");
            }
            // Write a class/interface/struct.
            else
            {
                tw.WriteLine();
                tw.WriteLine(
                    "// [1-3] {0} layout",
                    declaredType.MemberTypeName);
                tw.WriteLine(
                    "struct {0}",
                    declaredType.MangledName);
                tw.WriteLine("{");

                // Emit vptr (class/interface)
                if (declaredType.IsClass || declaredType.IsInterface)
                {
                    tw.WriteLine(
                        "{0}__{1}_VTABLE_DECL__* vptr0__;",
                        indent,
                        declaredType.MangledName);
                }

                // TODO: If value type implements interfaces, how to assigns vptr into value type?
                //   (We often have to resolve at enum types...)
                var fields = declaredType.
                    Traverse(type => type.BaseType).
                    Reverse().
                    SelectMany(type =>
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

            // If virtual method collection doesn't contain reuseslot and newslot method at declared types:
            if (!overrideMethods.Any() && !newSlotMethods.Any(method => method.DeclaringType.Equals(declaredType)))
            {
                tw.WriteLine();
                tw.WriteLine(
                    "// [1-5-1] Vtable (Same as {0})",
                    declaredType.BaseType.FriendlyName);

                tw.WriteLine(
                    "#define __{0}_VTABLE__ __{1}_VTABLE__",
                    declaredType.MangledName,
                    declaredType.BaseType.MangledName);
            }
            // Require new vtable.
            else
            {
                tw.WriteLine();
                tw.WriteLine(
                    "// [1-5-2] Vtable (Derived from {0})",
                    declaredType.BaseType.FriendlyName);

                tw.WriteLine(
                    "extern __{0}_VTABLE_DECL__ __{0}_VTABLE__;",
                    declaredType.MangledName);
            }

            tw.WriteLine();
            tw.WriteLine(
                "// [1-4] Runtime type information");
            tw.WriteLine(
                "extern IL2C_RUNTIME_TYPE_DECL __{0}_RUNTIME_TYPE__;",
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
                .Where(type => predictType(type)))
            {
                tw.WriteLine(
                    "typedef {0} {1} {1};",
                    type.IsEnum ? "enum" : "struct",
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
                        field.GetCLanguageStaticPrototype(false));
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
                }

                foreach (var method in type.DeclaredMethods
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

#if true
                    tw.WriteLine("/* TODO: virtual methods [2] */");
#else
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
#endif
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

            if (!preparedMethod.Method.IsStatic)
            {
                tw.WriteLine(
                    "{0}il2c_assert(this__ != NULL);",
                    indent);
                tw.WriteLine();
            }

            tw.WriteLine("{0}//-------------------", indent);
            tw.WriteLine("{0}// Local variables:", indent);
            tw.WriteLine();

            // Important NULL assigner (p = NULL):
            //   Because these variables are pointer (of object reference 'O' type).
            //   So GC will traverse these variables just setup the stack frame.
            foreach (var local in preparedMethod.Method.LocalVariables)
            {
                tw.WriteLine(
                    "{0}{1} {2}{3};",
                    indent,
                    local.TargetType.CLanguageTypeName,
                    local.SymbolName,
                    local.TargetType.IsClass ? " = NULL" : string.Empty);
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
                    stack.TargetType.IsClass ? " = NULL" : string.Empty);
            }

            var frameEntries = locals
                .Concat(preparedMethod.Stacks)
                .Where(local => local.TargetType.IsClass)
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

        //private static VirtualFunctionInformation[] GetVirtualFunctions(
        //    ITypeInformation adjustorThunkTargetType,
        //    ITypeInformation delegationTargetType) =>
        //    adjustorThunkTargetType
        //        .DeclaredMethods.Where(m => m.IsVirtual)        // TODO: virtual method
        //        .Select(method => new VirtualFunctionInformation(
        //            method.DeclaringType.Equals(adjustorThunkTargetType)
        //                ? delegationTargetType.MangledName
        //                : method.DeclaringType.MangledName,
        //            method.DeclaringType.Equals(adjustorThunkTargetType)
        //                ? delegationTargetType.CLanguageTypeName
        //                : method.DeclaringType.CLanguageTypeName,
        //            method.CLanguageVirtualFunctionDeclarationName,
        //            method.ReturnType.CLanguageTypeName,
        //            method.GetParameters(adjustorThunkTargetType)
        //                .Select((parameter, index) => Utilities.KeyValue(
        //                    (index == 0) ? parameter.TargetType.CLanguageThisTypeName : parameter.TargetType.CLanguageTypeName,
        //                    parameter.SymbolName))
        //                .ToArray()))
        //        .ToArray();

        private static void InternalConvertTypeHelper(
            TextWriter tw,
            ITypeInformation declaredType,
            string indent)
        {
            tw.WriteLine();
            tw.WriteLine("//////////////////////");
            tw.WriteLine("// [7] Runtime helpers:");

            if (!declaredType.IsEnum)
            {
                // Write mark handler:
                tw.WriteLine();
                tw.WriteLine(
                    "// [7-5] GC's mark handler");
                tw.WriteLine(
                    "void __{0}_IL2C_MarkHandler__({1} this__)",
                    declaredType.MangledName,
                    declaredType.CLanguageThisTypeName);
                tw.WriteLine("{");
                tw.WriteLine(
                    "{0}il2c_assert(this__ != NULL);",
                    indent);

                var fields = declaredType.Fields.
                    Where(field => !field.IsStatic && !field.FieldType.IsValueType).
                    ToArray();
                if (fields.Length >= 1)
                {
                    tw.WriteLine();
                    tw.WriteLine(
                        "{0}// [7-6] Try marking each object reference fields",
                        indent);

                    // Write unbox function if type is value type.
                    string thisRefForMarker;
                    if (declaredType.IsValueType)
                    {
                        tw.WriteLine(
                            "{0}{1}* pValue =",
                            indent,
                            declaredType.CLanguageTypeName);
                        tw.WriteLine(
                            "{0}{0}il2c_unsafe_unbox__(this__, {1});",
                            indent,
                            declaredType.CLanguageTypeName);
                        thisRefForMarker = "pValue";
                    }
                    else
                    {
                        thisRefForMarker = "this__";
                    }

                    // Write marker expression.
                    foreach (var field in fields)
                    {
                        tw.WriteLine(
                            "{0}il2c_try_mark_from_handler({1}->{2});",
                            indent,
                            thisRefForMarker,
                            field.Name);
                    }
                }

                // NOTE:
                //   Invoke base class mark handler except contains NO fields.
                //   (ex: System.Object, System.ValueType...)
                var baseType = declaredType.BaseType;
                if (baseType != null)
                {
                    if (baseType.
                        Traverse(type => type.BaseType).
                        Any(type => type.Fields.Length >= 1) == false)
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
            }

            // Write trampoline virtual functions if type is value type.
            var virtualMethods = declaredType.CalculatedVirtualMethods;
            var trampolineTargets = virtualMethods.
                Where(entry => declaredType.IsValueType && entry.method.DeclaringType.Equals(declaredType)).
                Select(entry => entry.method).
                ToArray();
            foreach (var method in trampolineTargets)
            {
                tw.WriteLine();
                tw.WriteLine(
                    "// [7-12] Trampoline virtual function: {0}",
                    method.FriendlyName);
                tw.WriteLine(
                    "static {0} {1}_Trampoline_VFunc__(System_ValueType* this__{2})",
                    method.ReturnType.CLanguageTypeName,
                    method.CLanguageFunctionName,
                    string.Concat(method.Parameters.
                        Skip(1).
                        Select(p => string.Format(", {0} {1}", p.TargetType.CLanguageTypeName, p.SymbolName))));
                tw.WriteLine(
                    "{");
                tw.WriteLine(
                    "{0}il2c_assert(this__ != NULL);",
                    indent);
                tw.WriteLine();
                tw.WriteLine(
                    "{0}{1}* pValue =",
                    indent,
                    declaredType.CLanguageTypeName);
                tw.WriteLine(
                    "{0}{0}il2c_unsafe_unbox__(this__, {1});",
                    indent,
                    declaredType.CLanguageTypeName);
                tw.WriteLine(
                    "{0}return {1}(pValue{2});",
                    indent,
                    method.CLanguageFunctionName,
                    string.Concat(method.Parameters.
                        Skip(1).
                        Select(p => string.Format(", {0}", p.SymbolName))));    // These aren't required expression evaluation.
                tw.WriteLine(
                    "}");
            }

            var overrideMethods = declaredType.OverrideMethods;
            var newSlotMethods = declaredType.NewSlotMethods;
            var overrideBaseMethods = declaredType.OverrideBaseMethods;

#if true
            // If virtual method collection doesn't contain reuseslot and newslot method at declared types:
            if (!overrideMethods.Any() && !newSlotMethods.Any(method => method.DeclaringType.Equals(declaredType)))
            {
                tw.WriteLine();
                tw.WriteLine(
                    "// [7-10-1] Vtable (Not defined, same as {0})",
                    declaredType.BaseType.FriendlyName);
            }
            // Require new vtable.
            else
            {
                // Write virtual methods
                tw.WriteLine();
                tw.WriteLine(
                    "// [7-10-2] Vtable");
                tw.WriteLine(
                    "__{0}_VTABLE_DECL__ __{0}_VTABLE__ = {{",
                    declaredType.MangledName);
                tw.WriteLine(
                    "{0}/* internalcall */ il2c_isinst__,",
                    indent,
                    declaredType.MangledName);

                foreach (var (method, _) in virtualMethods)
                {
                    // MEMO: Transfer trampoline virtual function if declared type is value type.
                    //   Because arg0 type is native value type pointer, but the virtual function requires boxed objref.
                    //   The trampoline unboxes from objref to target value type.
                    tw.WriteLine(
                        "{0}({1}){2}{3},",
                        indent,
                        method.CLanguageFunctionTypePrototype,
                        method.CLanguageFunctionName,
                        (declaredType.IsValueType && method.DeclaringType.Equals(declaredType)) ? "_Trampoline_VFunc__" : string.Empty);
                }

                tw.WriteLine("};");
            }
#else
            // Write virtual methods
            tw.WriteLine();
            tw.WriteLine(
                "// [7-10] Vtable of {0}",
                declaredType.FriendlyName);
            tw.WriteLine(
                "__{0}_VTABLE_DECL__ __{0}_VTABLE__ = {{",
                declaredType.MangledName);
            tw.WriteLine(
                "{0}/* internalcall */ il2c_runtime_isinst,",
                indent,
                declaredType.MangledName);

            var virtualFunctions = GetVirtualFunctions(
                declaredType,
                declaredType);

            foreach (var function in virtualFunctions)
            {
                tw.WriteLine(
                    "{0}{1}_{2},",
                    indent,
                    function.MangledTypeName,
                    function.CLanguageVirtualFunctionDeclarationName);
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
#endif

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
                "{0}{1},",
                indent,
                declaredType.IsValueType ? "IL2C_TYPE_VALUE" : "IL2C_TYPE_REFERENCE");
            tw.WriteLine(
                "{0}sizeof({1}),",
                indent,
                declaredType.MangledName);
            if (declaredType.IsEnum)
            {
                tw.WriteLine(
                    "{0}/* internalcall */ IL2C_DEFAULT_MARK_HANDLER,",
                    indent,
                    declaredType.MangledName);
            }
            else
            {
                tw.WriteLine(
                    "{0}/* internalcall */ (IL2C_MARK_HANDLER)__{1}_IL2C_MarkHandler__,",
                    indent,
                    declaredType.MangledName);
            }
            tw.WriteLine(
                "{0}il2c_typeof({1})",
                indent,
                declaredType.BaseType.MangledName);

            tw.WriteLine("};");
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
            PreparedInformations preparedFunctions,
            IMethodInformation method,
            string indent,
            DebugInformationOptions debugInformationOption = DebugInformationOptions.None)
        {
            if (method.IsVirtual)
            {
                if (method.IsAbstract)
                {
                    if (!method.DeclaringType.IsInterface)
                    {
                        InternalConvertFromAbstractFunction(
                            tw,
                            method,
                            indent);
                    }
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

        internal static void InternalWriteHeader(
            TextWriter twHeader,
            TranslateContext translateContext,
            PreparedInformations prepared,
            string indent,
            bool includeAssemblyHeader)
        {
            IExtractContext extractContext = translateContext;

            var assemblyName = extractContext.Assembly.MangledName;

            twHeader.WriteLine("#ifndef __{0}_H__", assemblyName);
            twHeader.WriteLine("#define __{0}_H__", assemblyName);
            twHeader.WriteLine();
            twHeader.WriteLine("#pragma once");
            twHeader.WriteLine();
            twHeader.WriteLine("#include <il2c.h>");

            if (includeAssemblyHeader)
            {
                twHeader.WriteLine();
                foreach (var fileName in extractContext.EnumerateRequiredIncludeFileNames())
                {
                    twHeader.WriteLine("#include <{0}>", fileName);
                }
            }

            // All types exclude privates
            InternalConvertToPrototypes(
                twHeader,
                prepared.Types,
                type => type.IsCLanguagePublicScope,
                field => field.IsPublic || field.IsFamily || field.IsFamilyOrAssembly,
                method => (method.IsPublic || method.IsFamily || method.IsFamilyOrAssembly) &&
                    prepared.Functions.ContainsKey(method),
                indent);

            twHeader.WriteLine();
            twHeader.WriteLine("#endif");
        }

        public static void WriteHeader(
            TextWriter twHeader,
            TranslateContext translateContext,
            PreparedInformations prepared,
            string indent)
        {
            InternalWriteHeader(
                twHeader, translateContext, prepared, indent, true);
        }

        internal static void WriteConstStrings(
            TextWriter twSource,
            TranslateContext translateContext)
        {
            IExtractContext extractContext = translateContext;

            twSource.WriteLine();
            twSource.WriteLine("//////////////////////////////////////////////////////////////////////////////////");
            twSource.WriteLine("// [9-1] Const strings:");
            twSource.WriteLine();

            foreach (var kv in extractContext.ExtractConstStrings())
            {
                var expr = Utilities.ToCLanguageExpression(kv.Value);
                twSource.WriteLine(
                    "IL2C_CONST_STRING({0}, {1});",
                    kv.Key,
                    expr);
            }
        }

        internal static void InternalWriteSourceCode(
            TextWriter twSource,
            TranslateContext translateContext,
            PreparedInformations prepared,
            string indent,
            DebugInformationOptions debugInformationOption,
            bool includeAssemblyHeader)
        {
            IExtractContext extractContext = translateContext;

            if (includeAssemblyHeader)
            {
                twSource.WriteLine();

                foreach (var fileName in extractContext.EnumerateRequiredPrivateIncludeFileNames())
                {
                    twSource.WriteLine("#include \"{0}\"", fileName);
                }

                twSource.WriteLine("#include \"{0}.h\"", extractContext.Assembly.Name);
            }

            WriteConstStrings(twSource, translateContext);

            twSource.WriteLine();
            twSource.WriteLine("//////////////////////////////////////////////////////////////////////////////////");
            twSource.WriteLine("// [9-2] File scope prototypes:");

            // All types exclude publics and internals (for file scope prototypes)
            InternalConvertToPrototypes(
                twSource,
                prepared.Types,
                type => !type.IsCLanguagePublicScope,
                field => !(field.IsPublic || field.IsFamily || field.IsFamilyOrAssembly),
                method => (method.IsPublic || method.IsFamily || method.IsFamilyOrAssembly) &&
                    prepared.Functions.ContainsKey(method),
                indent);

            twSource.WriteLine();
            twSource.WriteLine("//////////////////////////////////////////////////////////////////////////////////");
            twSource.WriteLine("// [9-3] Declare static fields:");

            foreach (var type in prepared.Types
                .Where(type => !type.IsEnum))
            {
                twSource.WriteLine();

                // All static fields
                foreach (var field in type.Fields
                    .Where(field => field.IsStatic))
                {
                    twSource.WriteLine(
                        "{0};",
                        field.GetCLanguageStaticPrototype(true));
                }
            }

            foreach (var type in prepared.Types)
            {
                twSource.WriteLine();
                twSource.WriteLine("//////////////////////////////////////////////////////////////////////////////////");
                twSource.WriteLine("// [9-4] Type: {0}", type.FriendlyName);

                // All methods and constructor exclude type initializer
                foreach (var method in type.DeclaredMethods)
                {
                    InternalConvertFromMethod(
                        twSource,
                        extractContext,
                        prepared,
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

        public static void WriteSourceCode(
            TextWriter twSource,
            TranslateContext translateContext,
            PreparedInformations prepared,
            string indent,
            DebugInformationOptions debugInformationOption = DebugInformationOptions.Full)
        {
            InternalWriteSourceCode(
                twSource, translateContext, prepared, indent, debugInformationOption, true);
        }
    }
}
