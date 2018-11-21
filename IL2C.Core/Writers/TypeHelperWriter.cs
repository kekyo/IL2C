using System.Diagnostics;
using System.Linq;

using IL2C.Metadata;

namespace IL2C.Writers
{
    internal static class TypeHelperWriter
    {
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

            // If virtual method collection doesn't contain reuseslot and newslot method at declared types:
            if (!overrideMethods.Any() &&
                !newSlotMethods.Any(method => method.DeclaringType.Equals(declaredType)))
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
                    tw.WriteLine("0, // Adjustor offset");

                    // Write only visible methods because virtual method collection contains the explicitly implementation methods.
                    foreach (var (method, _) in virtualMethods.
                        Where(entry => entry.method.IsPublic || entry.method.IsFamily || entry.method.IsFamilyOrAssembly))
                    {
                        // MEMO: Transfer trampoline virtual function if declared type is value type.
                        //   Because arg0 type is native value type pointer, but the virtual function requires boxed objref.
                        //   The trampoline will unbox from objref to target value type.
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

            // Write interface VTables.
            var interfaceTypes = declaredType.InterfaceTypes;
            foreach (var interfaceType in interfaceTypes)
            {
                var implementationMethods = interfaceType.DeclaredMethods.
                    Select(dm =>
                    {
                        // Extract interface implementation methods by relation from overrided.
                        var method = virtualMethods.
                            Select(entry => entry.method.Overrides.Any(om => om.Equals(dm)) ? entry.method : null).
                            FirstOrDefault(om => om != null);
                        if (method != null)
                        {
                            return method;
                        }

                        // If didn't find the method for explicitly implementation,
                        // try to find implicitly implementation by the method signature.
                        // (See also: InstanceMultipleCombinedImplement test)
                        return virtualMethods.
                            Select(entry => MetadataUtilities.VirtualMethodSignatureComparer.Equals(entry.method, dm) ? entry.method : null).
                            First(vm => vm != null);    // We will find exactly.
                    }).
                    ToArray();

                tw.WriteLine(
                    "// [7-12] VTable for {0}",
                    interfaceType.FriendlyName);
                tw.WriteLine(
                    "{0}_VTABLE_DECL__ {1}_{0}_VTABLE__ = {{",
                    interfaceType.MangledName,
                    declaredType.MangledName);

                using (var _ = tw.Shift())
                {
                    // The adjustor offset.
                    tw.WriteLine(
                        "il2c_adjustor_offset({0}, {1}),",
                        declaredType.MangledName,
                        interfaceType.MangledName);

                    foreach (var method in implementationMethods)
                    {
                        tw.WriteLine(
                            "({0}){1},",
                            method.CLanguageFunctionTypePrototype,
                            method.CLanguageFunctionName);
                    }
                }

                tw.WriteLine("};");
                tw.SplitLine();
            }

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
                interfaceTypes.Length);

            using (var _ = tw.Shift())
            {
                // Mark target offsets.
                foreach (var field in markTargetFields)
                {
                    // ex: IL2C_RUNTIME_TYPE_MARK_TARGET(System_Exception, message__)
                    tw.WriteLine(
                        "IL2C_RUNTIME_TYPE_MARK_TARGET({0}, {1})",
                        declaredType.MangledName,
                        field.Name);
                }

                // Write implemented interfaces (IL2C_IMPLEMENTED_INTERFACE)
                foreach (var interfaceType in declaredType.InterfaceTypes)
                {
                    // ex: IL2C_RUNTIME_TYPE_INTERFACE(Foo, System_IDisposable)
                    tw.WriteLine(
                        "IL2C_RUNTIME_TYPE_INTERFACE({0}, {1})",
                        declaredType.MangledName,
                        interfaceType.MangledName);
                }
            }

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

            // ex: IL2C_RUNTIME_TYPE_INTERFACE_BEGIN(System_IDisposable, "System.IDisposable", 0)
            var interfaceTypes = declaredType.InterfaceTypes;
            tw.WriteLine(
                "IL2C_RUNTIME_TYPE_INTERFACE_BEGIN({0}, \"{1}\", {2})",
                declaredType.MangledName,
                declaredType.FriendlyName, // Type name (UTF-8 string, C compiler embeds)
                interfaceTypes.Length);

            using (var _ = tw.Shift())
            {
                // TODO: can't place for IL2C_IMPLEMENTED_INTERFACE, because the interface type doesn't define the VTable.
                // Write implemented interfaces (IL2C_IMPLEMENTED_INTERFACE)
                foreach (var interfaceType in interfaceTypes)
                {
                    // ex: IL2C_RUNTIME_TYPE_INTERFACE(Foo, System_IDisposable)
                    tw.WriteLine(
                        "IL2C_RUNTIME_TYPE_INTERFACE({0}, {1})",
                        declaredType.MangledName,
                        interfaceType.MangledName);
                }
            }

            tw.WriteLine(
                "IL2C_RUNTIME_TYPE_END();");
            tw.SplitLine();
        }
    }
}
