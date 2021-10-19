﻿/////////////////////////////////////////////////////////////////////////////////////////////////
//
// IL2C - A translator for ECMA-335 CIL/MSIL to C language.
// Copyright (c) 2016-2019 Kouji Matsui (@kozy_kekyo, @kekyo2)
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//	http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
/////////////////////////////////////////////////////////////////////////////////////////////////

using System;
using System.Diagnostics;
using System.Linq;
using IL2C.Internal;
using IL2C.Metadata;

namespace IL2C.Writers
{
    internal static class TypeHelperWriter
    {
        private static void InternalConvertTrampolineVirtualFunction(
            CodeTextWriter tw,
            ITypeInformation declaredType,
            IMethodInformation method)
        {
            tw.WriteLine(
                "// [7-12] Trampoline virtual function: {0}",
                method.FriendlyName);
            tw.WriteLine(
                "static {0} {1}__Trampoline_VFunc__(System_ValueType* this__{2})",
                method.ReturnType.CLanguageTypeName,
                method.CLanguageFunctionFullName,
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

                // This method is virtual (or overrided).
                if (method.IsVirtual)
                {
                    tw.WriteLine(
                        "{0}* pUnboxedValue__ =  // unbox without copy because it's truly objref",
                        declaredType.CLanguageTypeName);

                    using (var __ = tw.Shift())
                    {
                        tw.WriteLine(
                            "il2c_unsafe_unbox__(this__, {0});",
                            declaredType.CLanguageTypeName);
                    }

                    tw.WriteLine(
                        "return {0}(pUnboxedValue__{1});",
                        method.CLanguageFunctionFullName,
                        string.Concat(method.Parameters.
                            Skip(1).
                            Select(p => string.Format(", {0}", p.ParameterName))));    // These aren't required expression evaluation.
                }
                // This method implemented onto the interface.
                else
                {
                    Debug.Assert(method.IsOverridedOrImplemented);

                    // It requires unboxing WITH COPY.
                    tw.WriteLine(
                        "{0} unboxedValue__ =  // unbox with copy because it will be from interface reference",
                        declaredType.CLanguageTypeName);

                    using (var __ = tw.Shift())
                    {
                        tw.WriteLine(
                            "*il2c_unsafe_unbox__(this__, {0});",
                            declaredType.CLanguageTypeName);
                    }

                    tw.WriteLine(
                        "return {0}(&unboxedValue__{1});",
                        method.CLanguageFunctionFullName,
                        string.Concat(method.Parameters.
                            Skip(1).
                            Select(p => string.Format(", {0}", p.ParameterName))));    // These aren't required expression evaluation.
                }
            }

            tw.WriteLine(
                "}");
            tw.SplitLine();
        }

        private static (IMethodInformation interfaceMethod, IMethodInformation targetMethod)[] CalculateImplementationMethods(
            ITypeInformation declaredType, ITypeInformation interfaceType, IMethodInformation[] declaredMethods)
        {
            return interfaceType.DeclaredMethods.
                Select(interfaceMethod =>
                {
                    // Extract interface implementation methods by overrided from derived to based.
                    var targetMethod = declaredMethods.
                        Select(dm => dm.Overrides.Contains(interfaceMethod) ? dm : null).
                        FirstOrDefault(vm => vm != null);
                    if (targetMethod != null)
                    {
                        return (interfaceMethod, targetMethod);
                    }

                    /////////////////////////////////////////////////////////
                    // If didn't find the method for explicitly implementation,
                    // try to find implicitly implementation by the method signature.
                    // (See also: InstanceMultipleCombinedImplement test)

                    // Detect the implicitly interface implemented method:

                    // (1) Aggregate all visible declared methods from derived to base types.
                    //   firstInterfaceImplementedType = Foo2
                    //     interfaceType: IBar1
                    //     System.Object <-- Foo1 <-- Foo2 <-- Foo3
                    //                       |        |        +-- IBar2 / Method1
                    //                       |        +----------- IBar1 / Method2, Method3
                    //                       +-------------------- IBar2 / Method1, Method3
                    //   declaredVisibleMethods = [Foo2.Method2, Foo2.Method3, Foo1.Method1]
                    //     (Except Foo1.Method3 by VirtualMethodSignatureComparer)
                    var firstInterfaceImplementedType = declaredType.
                        Traverse(type => type.BaseType).
                        First(type => type.InterfaceTypes.Contains(interfaceType));
                    var declaredVisibleMethods = firstInterfaceImplementedType.
                        Traverse(type => type.BaseType).
                        SelectMany(type => type.DeclaredMethods).
                        Where(dm => !dm.IsConstructor && !dm.IsStatic &&
                            (dm.IsPublic || dm.IsFamily || dm.IsFamilyOrAssembly)).
                        Distinct(MetadataUtilities.VirtualMethodSignatureComparer).
                        ToArray();

                    // (2) Find first matching declaredMethod for same as this interfaceMethod.
                    //     "Same" means the method signature (using VirtualMethodSignatureComparer)
                    //   declaredVisibleMethods = [Foo2.Method2, Foo2.Method3, Foo1.Method1]
                    //   interfaceMethod = IBar2.Method1
                    //   targetBaseMethod = Foo1.Method1
                    var targetBaseMethod = declaredVisibleMethods.
                        Select(dm => MetadataUtilities.VirtualMethodSignatureComparer.Equals(dm, interfaceMethod) ? dm : null).
                        First(dm => dm != null);    // We will find exactly.

                    // (3) Find last matching (mostly derived) method from base to overrides.
                    //   baseInterfaceImplementedTypes = [Foo1, Foo2, Foo3]
                    //   interfaceMethod = IBar2.Method1
                    //   targetBaseMethod = Foo1.Method1
                    //   lastMatchedMethod = Foo3.Method1
                    var baseInterfaceImplementedTypes = declaredType.
                        Traverse(type => type.BaseType).
                        Reverse().
                        Where(type => targetBaseMethod.DeclaringType.IsAssignableFrom(type)).
                        ToArray();
                    targetMethod = baseInterfaceImplementedTypes.
                        SelectMany(type => type.DeclaredMethods.
                            Where(dm => MetadataUtilities.VirtualMethodSignatureComparer.Equals(dm, interfaceMethod))).
                        TakeWhile(dm => (dm.IsVirtual && (!dm.IsNewSlot || dm.IsReuseSlot)) ||
                            dm.Equals(targetBaseMethod)).
                        Last();

                    return (interfaceMethod, targetMethod);
                }).
                ToArray();
        }

        public static void InternalConvertTypeHelper(
            CodeTextWriter tw,
            ITypeInformation declaredType)
        {
            Debug.Assert(!declaredType.IsInterface);

            tw.WriteLine("//////////////////////");
            tw.WriteLine("// [7] Runtime helpers:");
            tw.SplitLine();

            // Get virtual methods.
            var allOverrideMethods = declaredType.AllOverrideMethods;

            // All declared methods from derived to base types.
            var allDeclaredMethods = declaredType.DeclaredAllInheritedMethods;

            // Write trampoline virtual functions if type is value type.
            var trampolineVirtualMethods = allDeclaredMethods.
                Where(method => declaredType.IsValueType && method.DeclaringType.Equals(declaredType)).
                ToArray();
            foreach (var method in trampolineVirtualMethods)
            {
                InternalConvertTrampolineVirtualFunction(tw, declaredType, method);
            }

            // Write vtable excepts abstract types.
            if (allOverrideMethods.All(method => !method.IsAbstract))
            {
                var overrideMethods = declaredType.DeclaredOverrideMethods;
                var newSlotMethods = declaredType.DeclaredNewslotMethods;

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
                        declaredType.MangledUniqueName);

                    using (var _ = tw.Shift())
                    {
                        tw.WriteLine("0, // Adjustor offset");

                        // Write only visible methods because virtual method collection contains the explicitly implementation methods.
                        foreach (var method in allOverrideMethods.
                            Where(method => method.IsPublic || method.IsFamily || method.IsFamilyOrAssembly))
                        {
                            // NOTE: Transfer trampoline virtual function if declared type is value type.
                            //   Because arg0 type is native value type pointer, but the virtual function requires boxed objref.
                            //   The trampoline will unbox from objref to target value type.
                            tw.WriteLine(
                                "({0}){1}{2},",
                                method.CLanguageFunctionType,
                                method.CLanguageFunctionFullName,
                                trampolineVirtualMethods.Contains(method) ? "__Trampoline_VFunc__" : string.Empty);
                        }
                    }

                    tw.WriteLine("};");
                    tw.SplitLine();
                }
            }

            var declaredFields =
                (!declaredType.IsEnum && !declaredType.IsDelegate) ?
                    declaredType.Fields.
                    Where(field => !field.IsStatic).
                    ToArray() :
                new IFieldInformation[0];

            // Write interface VTables.
            var interfaceTypes = declaredType.
                Traverse(type => type.BaseType).
                SelectMany(type => type.InterfaceTypes).
                Distinct(). // Important operator sequence: distinct --> reverse
                Reverse().  // Because all interface types overrided by derived class type,
                ToArray();  // we have to aggregate to be visible interface types.

            foreach (var interfaceType in interfaceTypes)
            {
                // Calculate interface index.
                var interfaceIndex = declaredType.CalculateInterfaceIndex(interfaceType);

                // Calculate current interface type's implementation methods.
                var implementationMethods =
                    CalculateImplementationMethods(declaredType, interfaceType, allDeclaredMethods);

                tw.WriteLine(
                    "// [7-13] VTable for {0}",
                    interfaceType.FriendlyName);
                tw.WriteLine(
                    "{0}_VTABLE_DECL__ {1}_{0}_VTABLE__ = {{",
                    interfaceType.MangledUniqueName,
                    declaredType.MangledUniqueName);

                using (var _ = tw.Shift())
                {
                    // If value type:
                    if (declaredType.IsValueType)
                    {
                        // The adjustor offset at the value type interface.
                        // See 'System_ValueType.c' NOTE section.
                        tw.WriteLine(
                            "sizeof(System_ValueType) + {0} + {1} * sizeof(void*),",
                            declaredType.CLanguageStaticSizeOfExpression,
                            interfaceIndex);
                    }
                    else
                    {
                        tw.WriteLine(
                            "il2c_adjustor_offset({0}, {1}),",
                            declaredType.MangledUniqueName,
                            interfaceType.MangledUniqueName);
                    }

                    foreach (var entry in implementationMethods)
                    {
                        tw.WriteLine(
                            "({0}){1}{2},",
                            entry.interfaceMethod.CLanguageFunctionType,
                            entry.targetMethod.CLanguageFunctionFullName,
                            trampolineVirtualMethods.Contains(entry.targetMethod) ? "__Trampoline_VFunc__" : string.Empty);
                    }
                }

                tw.WriteLine("};");
                tw.SplitLine();
            }

            // Write runtime type information
            tw.WriteLine("// [7-8] Runtime type information");

            // Aggregate mark target fields (except the enum type and the delegate type)
            var markTargetFields =
                declaredFields.
                Where(field =>
                    field.FieldType.IsReferenceType ||
                    (field.FieldType.IsValueType && !field.FieldType.IsPrimitive &&
                    field.FieldType.Fields.Length >= 1)).
                ToArray();

            // All virtual methods are implemented.
            if (allOverrideMethods.All(method => !method.IsAbstract))
            {
                // ex: IL2C_RUNTIME_TYPE_BEGIN(Foo_Bar, "Foo.Bar", IL2C_TYPE_REFERENCE, sizeof(Foo_Bar), System_Object, 0, 0)
                tw.WriteLine(
                    "IL2C_RUNTIME_TYPE_BEGIN({0}, \"{1}\", {2}, {3}, {4}, {5}, {6})",
                    declaredType.MangledUniqueName,
                    declaredType.FriendlyName, // Type name (UTF-8 string, C compiler embeds into .rdata)
                    declaredType.IsEnum ?      // Type attribute flags
                        (declaredType.ElementType.IsUnsigned ? "IL2C_TYPE_UNSIGNED_INTEGER" : "IL2C_TYPE_INTEGER") :
                        declaredType.IsDelegate ? "IL2C_TYPE_VARIABLE | IL2C_TYPE_WITH_MARK_HANDLER" :
                        declaredType.IsReferenceType ? "IL2C_TYPE_REFERENCE" :
                        "IL2C_TYPE_VALUE",
                    declaredType.CLanguageStaticSizeOfExpression,
                    declaredType.BaseType == null ? "NULL" : declaredType.BaseType.MangledUniqueName,
                    declaredType.IsDelegate ? "System_Delegate_MarkHandler__" : markTargetFields.Length.ToString(),
                    interfaceTypes.Length);
            }
            else
            {
                // ex: IL2C_RUNTIME_TYPE_ABSTRACT_BEGIN(Foo_Bar, "Foo.Bar", sizeof(Foo_Bar), System_Object, 0, 0)
                tw.WriteLine(
                    "IL2C_RUNTIME_TYPE_ABSTRACT_BEGIN({0}, \"{1}\", {2}, {3}, {4}, {5})",
                    declaredType.MangledUniqueName,
                    declaredType.FriendlyName, // Type name (UTF-8 string, C compiler embeds into .rdata)
                    declaredType.CLanguageStaticSizeOfExpression,
                    declaredType.BaseType.MangledUniqueName,
                    markTargetFields.Length.ToString(),
                    interfaceTypes.Length);
            }

            using (var _ = tw.Shift())
            {
                // Mark target offsets.
                foreach (var field in markTargetFields)
                {
                    if (field.FieldType.IsReferenceType)
                    {
                        // ex: IL2C_RUNTIME_TYPE_MARK_TARGET_FOR_REFERENCE(System_Exception, message__)
                        tw.WriteLine(
                            "IL2C_RUNTIME_TYPE_MARK_TARGET_FOR_REFERENCE({0}, {1})",
                            declaredType.MangledUniqueName,
                            field.MangledName);
                    }
                    else
                    {
                        // ex: IL2C_RUNTIME_TYPE_MARK_TARGET_FOR_VALUE(System_Exception, System_Int32 , result__)
                        tw.WriteLine(
                            "IL2C_RUNTIME_TYPE_MARK_TARGET_FOR_VALUE({0}, {1}, {2})",
                            declaredType.MangledUniqueName,
                            field.FieldType.MangledUniqueName,
                            field.MangledName);
                    }
                }

                // Write implemented interfaces (IL2C_IMPLEMENTED_INTERFACE)
                foreach (var interfaceType in interfaceTypes)
                {
                    // ex: IL2C_RUNTIME_TYPE_INTERFACE(Foo, System_IDisposable)
                    tw.WriteLine(
                        "IL2C_RUNTIME_TYPE_INTERFACE({0}, {1})",
                        declaredType.MangledUniqueName,
                        interfaceType.MangledUniqueName);
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
                declaredType.MangledUniqueName,
                declaredType.FriendlyName, // Type name (UTF-8 string, C compiler embeds into .rdata)
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
                        declaredType.MangledUniqueName,
                        interfaceType.MangledUniqueName);
                }
            }

            tw.WriteLine(
                "IL2C_RUNTIME_TYPE_END();");
            tw.SplitLine();
        }
    }
}
