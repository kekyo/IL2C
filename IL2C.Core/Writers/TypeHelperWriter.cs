using System.Diagnostics;
using System.Linq;

using IL2C.Metadata;

namespace IL2C.Writers
{
    internal static class TypeHelperWriter
    {
        //private struct VirtualFunctionInformation
        //{
        //    public readonly string MangledTypeName;
        //    public readonly string CLanguageTypeName;
        //    public readonly string CLanguageVirtualFunctionDeclarationName;
        //    public readonly string CLanguageReturnTypeName;
        //    public readonly KeyValuePair<string, string>[] Parameters;

        //    public VirtualFunctionInformation(
        //        string mangledTypeName,
        //        string cLanguageTypeName,
        //        string cLanguageVirtualFunctionDeclarationName,
        //        string cLanguageReturnTypeName,
        //        KeyValuePair<string, string>[] parameters)
        //    {
        //        this.MangledTypeName = mangledTypeName;
        //        this.CLanguageTypeName = cLanguageTypeName;
        //        this.CLanguageVirtualFunctionDeclarationName = cLanguageVirtualFunctionDeclarationName;
        //        this.CLanguageReturnTypeName = cLanguageReturnTypeName;
        //        this.Parameters = parameters;
        //    }
        //}

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

        public static void InternalConvertTypeHelper(
            CodeTextWriter tw,
            ITypeInformation declaredType)
        {
            Debug.Assert(!declaredType.IsInterface);

            tw.WriteLine("//////////////////////");
            tw.WriteLine("// [7] Runtime helpers:");
            tw.SplitLine();

            // Write trampoline virtual functions if type is value type.
            var virtualMethods = declaredType.CalculatedVirtualMethods;
            var trampolineTargets = virtualMethods.
                Where(entry => declaredType.IsValueType && entry.method.DeclaringType.Equals(declaredType)).
                Select(entry => entry.method).
                ToArray();
            foreach (var method in trampolineTargets)
            {
                tw.WriteLine(
                    "// [7-12] Trampoline virtual function: {0}",
                    method.FriendlyName);
                tw.WriteLine(
                    "static {0} {1}_Trampoline_VFunc__(System_ValueType* this__{2})",
                    method.ReturnType.CLanguageTypeName,
                    method.CLanguageFunctionName,
                    string.Concat(method.Parameters.
                        Skip(1).
                        Select(p => string.Format(", {0} {1}", p.TargetType.CLanguageTypeName, p.ParameterName))));
                tw.WriteLine(
                    "{");

                using (var _ = tw.Shift())
                {
                    tw.WriteLine(
                        "il2c_assert(this__ != NULL);");
                    tw.SplitLine();
                    tw.WriteLine(
                        "{0}* pValue =",
                        declaredType.CLanguageTypeName);

                    using (var __ = tw.Shift())
                    {
                        tw.WriteLine(
                            "il2c_unsafe_unbox__(this__, {0});",
                            declaredType.CLanguageTypeName);
                    }

                    tw.WriteLine(
                        "return {0}(pValue{1});",
                        method.CLanguageFunctionName,
                        string.Concat(method.Parameters.
                            Skip(1).
                            Select(p => string.Format(", {0}", p.ParameterName))));    // These aren't required expression evaluation.
                }

                tw.WriteLine(
                    "}");
                tw.SplitLine();
            }

            var overrideMethods = declaredType.OverrideMethods;
            var newSlotMethods = declaredType.NewSlotMethods;
            var overrideBaseMethods = declaredType.OverrideBaseMethods;

#if true
            // If virtual method collection doesn't contain reuseslot and newslot method at declared types:
            if (!overrideMethods.Any() && !newSlotMethods.Any(method => method.DeclaringType.Equals(declaredType)))
            {
                tw.WriteLine(
                    "// [7-10-1] VTable (Not defined, same as {0})",
                    declaredType.BaseType.FriendlyName);
                tw.SplitLine();
            }
            // Require new vtable.
            else
            {
                // Write virtual methods
                tw.WriteLine(
                    "// [7-10-2] VTable");
                tw.WriteLine(
                    "{0}_VTABLE_DECL__ {0}_VTABLE__ = {{",
                    declaredType.MangledName);

                using (var _ = tw.Shift())
                {
                    foreach (var (method, _) in virtualMethods)
                    {
                        // MEMO: Transfer trampoline virtual function if declared type is value type.
                        //   Because arg0 type is native value type pointer, but the virtual function requires boxed objref.
                        //   The trampoline unboxes from objref to target value type.
                        tw.WriteLine(
                            "({0}){1}{2},",
                            method.CLanguageFunctionTypePrototype,
                            method.CLanguageFunctionName,
                            (declaredType.IsValueType && method.DeclaringType.Equals(declaredType)) ? "_Trampoline_VFunc__" : string.Empty);
                    }
                }

                tw.WriteLine("};");
                tw.SplitLine();
            }
#else
            // Write virtual methods
            tw.WriteLine(
                "// [7-10] Vtable of {0}",
                declaredType.FriendlyName);
            tw.WriteLine(
                "{0}_VTABLE_DECL__ {0}_VTABLE__ = {{",
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
            tw.SplitLine();

            foreach (var interfaceType in declaredType.InterfaceTypes)
            {
                var interfaceVirtualFunctions = GetVirtualFunctions(
                    interfaceType,
                    declaredType);

                foreach (var function in interfaceVirtualFunctions)
                {
                    // Adjustor thunk will not invoke direct, so try to emit static function.
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
                    tw.SplitLine();
                }

                tw.WriteLine(
                    "// [7-12] Vtable of {0} (with adjustor thunk)",
                    interfaceType.FriendlyName);
                tw.WriteLine(
                    "{0}_VTABLE_DECL__ {1}_{0}_VTABLE__ = {{",
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
                tw.SplitLine();
            }
#endif

            // Write runtime type information
            tw.WriteLine("// [7-8] Runtime type information");

            // Aggregate mark target fields (except the enum type and the delegate type)
            var markTargetFields =
                (!declaredType.IsEnum && !declaredType.IsDelegate) ?
                    declaredType.Fields.
                    Where(field => !field.IsStatic && field.FieldType.IsReferenceType).
                    ToArray() :
                new IFieldInformation[0];

            // ex: IL2C_RUNTIME_TYPE_BEGIN(System_ValueType, "System.ValueType", IL2C_TYPE_REFERENCE, System_Object, 0, 0)
            tw.WriteLine(
                "IL2C_RUNTIME_TYPE_BEGIN({0}, \"{1}\", {2}, {3}, {4}, {5})",
                declaredType.MangledName,
                declaredType.FriendlyName, // Type name (UTF-8 string, C compiler embeds)
                declaredType.IsEnum ?      // Type attribute flags
                    (declaredType.ElementType.IsUnsigned ? "IL2C_TYPE_UNSIGNED_INTEGER" : "IL2C_TYPE_INTEGER") :
                    declaredType.IsDelegate ? "IL2C_TYPE_VARIABLE" :
                    declaredType.IsReferenceType ? "IL2C_TYPE_REFERENCE" :
                    "IL2C_TYPE_VALUE",
                declaredType.BaseType.MangledName,
                declaredType.IsDelegate ? "System_Delegate_MarkHandler__" : markTargetFields.Length.ToString(),
                0);

            // Mark target offsets.
            using (var _ = tw.Shift())
            {
                foreach (var field in markTargetFields)
                {
                    // ex: IL2C_RUNTIME_TYPE_MARK_TARGET(System_Exception, message__)
                    tw.WriteLine(
                        "IL2C_RUNTIME_TYPE_MARK_TARGET({0}, {1})",
                        declaredType.MangledName,
                        field.Name);
                }
            }

            // TODO: interfaces

            tw.WriteLine("IL2C_RUNTIME_TYPE_END();");
            tw.SplitLine();
        }

        public static void InternalConvertTypeHelperForInterface(
            CodeTextWriter tw,
            ITypeInformation declaredType)
        {
            Debug.Assert(declaredType.IsInterface);

            tw.WriteLine("//////////////////////");
            tw.WriteLine("// [8] Runtime helpers:");
            tw.SplitLine();

            // Write runtime type information
            tw.WriteLine("// [8-1] Runtime type information");

            // ex: IL2C_RUNTIME_TYPE_BEGIN(System_ValueType, "System.ValueType", IL2C_TYPE_INTERFACE, System_Object, 0, 0)
            tw.WriteLine(
                "IL2C_RUNTIME_TYPE_BEGIN({0}, \"{1}\", IL2C_TYPE_INTERFACE, {2}, 0, {3})",
                declaredType.MangledName,
                declaredType.FriendlyName, // Type name (UTF-8 string, C compiler embeds)
                declaredType.BaseType.MangledName,
                0);

            // TODO: interfaces

            tw.WriteLine(
                "IL2C_RUNTIME_TYPE_END();");
            tw.SplitLine();
        }
    }
}
