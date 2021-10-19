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
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using IL2C.Internal;
using IL2C.Metadata;

namespace IL2C.Writers
{
    internal static class TypeWriter
    {
        public static void WriteTypeDefinitions(
            CodeTextWriter tw,
            ITypeInformation declaredType)
        {
            if (declaredType.IsPrimitive || !(declaredType.IsValueType || declaredType.IsReferenceType))
            {
                return;
            }

            tw.WriteLine("////////////////////////////////////////////////////////////");
            tw.WriteLine(
                "// [1] {0}",
                declaredType.FriendlyName);
            tw.SplitLine();

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
            // +----------------------+ <-- this__       A_VTABLE__
            // | vptr0__              | -------------> +--------------------+
            // +----------------------+                | [0]                |
            // | vptr_A_IB__          | ----------+    | ToString()         |
            // +----------------------+           |    | GetHashCode()      |
            // | int F1               |           |    | Finalize()         |
            // | string F2            |           |    | Equals()           |
            // +----------------------+           |    | Calc()             |
            //                                    |    +--------------------+
            //                                    |      A_IB_VTABLE__
            //                                    +--> +--------------------+
            //                                         | [offset__]         |
            //                                         | ToString()         |
            //                                         | GetHashCode()      |
            //                                         | Finalize()         |
            //                                         | Equals()           |
            //                                         | Calc()             |
            //                                         +--------------------+

            var declaredOverrideMethods = declaredType.DeclaredOverrideMethods;
            var declaredNewslotMethods = declaredType.DeclaredNewslotMethods;
            var allNewslotMethods = declaredType.AllNewslotMethods;

            // If virtual method collection doesn't contain newslot method at this declared type:
            if (!declaredNewslotMethods.Any(method => method.DeclaringType.Equals(declaredType)))
            {
                // (The typedef alias contains into prototype definitions.)
            }
            // Require new VTable layout.
            else
            {
                if (declaredType.IsInterface)
                {
                    tw.WriteLine(
                        "// [1-2-2] {0} VTable layout",
                        declaredType.MemberTypeName);
                }
                else
                {
                    tw.WriteLine(
                        "// [1-2-3] {0} VTable layout (Derived from {1})",
                        declaredType.MemberTypeName,
                        declaredType.BaseType?.FriendlyName);
                }

                tw.WriteLine(
                    "struct {0}_VTABLE_DECL___",
                    declaredType.MangledUniqueName);
                tw.WriteLine("{");
                using (var _ = tw.Shift())
                {
                    // This makes adjustor-thunk free VTable.
                    tw.WriteLine("intptr_t offset__; // Adjustor offset");

                    // Write only visible methods because virtual method collection contains the explicitly implementation methods.
                    var vtableMethods = allNewslotMethods.
                        Where(method => method.IsPublic || method.IsFamily || method.IsFamilyOrAssembly);

                    // Rename function name if the method declareted NOT top of override.
                    var functionDeclarationNames = new HashSet<string>();
                    var vtableRenamedMethods = vtableMethods.
                        Reverse().
                        Select(method => functionDeclarationNames.Add(method.CLanguageFunctionName) ?
                            method.CLanguageFunctionNamedType :
                            method.CLanguageFunctionFullNamedType).
                        Reverse();

                    // Write VTable layout.
                    foreach (var methodName in vtableRenamedMethods)
                    {
                        tw.WriteLine("{0};", methodName);
                    }
                }

                tw.WriteLine("};");
                tw.SplitLine();
            }

            // The NativeTypeAttribute doesn't write the layout structure because it aliased from the native C language type.
            if (declaredType.NativeType != null)
            {
            }
            // Delegate types doesn't write the layout structure because it's same as System.MulticastDelegate.
            else if (declaredType.IsDelegate)
            {
            }
            // Write a enum:
            else if (declaredType.IsEnum)
            {
                tw.WriteLine(
                    "// [1-1-1] {0} layout",
                    declaredType.MemberTypeName);

                // Emit enum values:
                //   Unfortunately the enum type at C language doesn't have the strict underlying type.
                //   IL2C emits the enum types using not C language syntax.
                foreach (var field in declaredType.Fields.Where(field => field.HasConstant))
                {
                    tw.WriteLine(
                        "/* {0} */ static const {1} {2}_{3} = {4};",
                        declaredType.AttributeDescription,
                        declaredType.CLanguageTypeName,
                        declaredType.MangledUniqueName,
                        field.Name,
                        Utilities.GetCLanguageExpression(field.DeclaredValue));
                }
                tw.SplitLine();
            }
            // Write a class/interface/struct:
            else
            {
                tw.WriteLine(
                    "// [1-1-2] {0} layout",
                    declaredType.MemberTypeName);

                tw.WriteLine(
                    "/* {0} */ struct {1}",
                    declaredType.AttributeDescription,
                    declaredType.MangledUniqueName);
                tw.WriteLine("{");

                using (var _ = tw.Shift())
                {
                    var tookInterfaceTypes = new HashSet<ITypeInformation>();
                    var fields = declaredType.
                        Traverse(type => type.BaseType).
                        Reverse().
                        SelectMany(type =>
                        {
                            // The vptr can contain only one unique interface type.
                            var interfaceTypes = new List<ITypeInformation>();
                            // Emit interface vptr (class/interface)
                            if (declaredType.IsClass || declaredType.IsInterface)
                            {
                                foreach (var interfaceType in type.InterfaceTypes)
                                {
                                    if (tookInterfaceTypes.Add(interfaceType))
                                    {
                                        interfaceTypes.Add(interfaceType);
                                    }
                                }
                            }

                            var vptrs = interfaceTypes.
                                Select(interfaceType => new
                                {
                                    Name = string.Format(
                                        "vptr_{0}__",
                                        interfaceType.MangledUniqueName),
                                    TypeName = string.Format(
                                        "{0}_VTABLE_DECL__*",
                                        interfaceType.MangledUniqueName),
                                    Required = true
                                });

                            var thisFields = type.Fields.
                                // It's instance field
                                Where(field => !field.IsStatic).
                                Select(field => new
                                {
                                    Name = field.MangledName,
                                    TypeName = field.FieldType.CLanguageTypeName,
                                    // This field's public or at the declared type.
                                    // If not it, we have to declare the field but symbol name will be hide.
                                    // TODO: We have to calculate totally shadowing fields between base type to derived type.
                                    Required = field.IsPublic || field.IsFamily || field.IsFamilyOrAssembly || field.DeclaringType.Equals(declaredType)
                                });

                            return vptrs.Concat(thisFields);
                        }).
                        Select((entry, index) => entry.Required ?
                            new { entry.Name, entry.TypeName } :
                            new { Name = string.Format("baseField{0}__", index), entry.TypeName }).
                        ToArray();

                    // Emit vptr (class/interface)
                    if (declaredType.IsClass || declaredType.IsInterface)
                    {
                        tw.WriteLine(
                            "{0}_VTABLE_DECL__* vptr0__;",
                            declaredType.MangledUniqueName);
                    }

                    if (fields.Length >= 1)
                    {
                        // Emit fields.
                        foreach (var field in fields)
                        {
                            tw.WriteLine(
                                "{0} {1};",
                                field.TypeName,
                                field.Name);
                        }
                    }
                    else
                    {
                        // HACK: Zero-sized value type can't directly translate to the C structure.
                        //   Because ANSI C structure must have one or more fields and construct SIZED storage.
                        //   IL2C hacks for the zero-sized value type, inserts a dummy field into it.
                        if (declaredType.IsValueType)
                        {
                            Debug.Assert(declaredType.InternalStaticSizeOfValue == 0);
                            tw.WriteLine("// The struct meaning size to zero. It doesn't use anything. It has validity for C compiler.");
                            tw.WriteLine("uint8_t dummy_for_c_compiler__;");
                        }
                    }
                }

                tw.WriteLine("};");
                tw.SplitLine();
            }

            // VTable substance not required for interface type.
            if (!declaredType.IsInterface)
            {
                // If virtual method collection doesn't contain reuseslot and newslot method at declared types:
                if (!declaredOverrideMethods.Any() && !declaredNewslotMethods.Any())
                {
                    tw.WriteLine(
                        "// [1-5-1] VTable (Same as {0})",
                        declaredType.BaseType?.FriendlyName);
                    tw.WriteLine(
                        "#define {0}_VTABLE__ {1}_VTABLE__",
                        declaredType.MangledUniqueName,
                        declaredType.BaseType.MangledUniqueName);
                }
                // Require new vtable
                else if (declaredType.AllOverrideMethods.All(method => !method.IsAbstract))
                {
                    tw.WriteLine(
                        "// [1-5-2] VTable (Derived from {0})",
                        declaredType.BaseType?.FriendlyName);
                    tw.WriteLine(
                        "extern {0}_VTABLE_DECL__ {0}_VTABLE__;",
                        declaredType.MangledUniqueName);
                }
                tw.SplitLine();
            }

            tw.WriteLine(
                "// [1-4] Runtime type information");
            tw.WriteLine(
                "IL2C_DECLARE_RUNTIME_TYPE({0});",
                declaredType.MangledUniqueName);
            tw.SplitLine();
        }

        public static void WriteMemberDefinitions(
            CodeTextWriter tw,
            ITypeInformation declaredType,
            Func<IFieldInformation, bool> predictField,
            Func<IMethodInformation, bool> predictMethod)
        {
            // Doesn't required writing the enum type members.
            if (!declaredType.IsEnum)
            {
                var staticFields = declaredType.Fields.
                    Where(field => field.IsStatic && predictField(field)).
                    ToArray();
                if (staticFields.Length >= 1)
                {
                    tw.WriteLine("//////////////////////////////////////////////////////////////////////////////////");
                    tw.WriteLine(
                        "// [2-2] Static fields: {0}",
                        declaredType.FriendlyName);
                    tw.SplitLine();

                    foreach (var field in staticFields)
                    {
                        if (field.NativeValue != null)
                        {
                            tw.WriteLine(
                                "/* {0} */ #define {1} {2}",
                                field.AttributeDescription,
                                field.MangledUniqueName,
                                field.CLanguageNativeSymbolName);
                        }
                        else
                        {
                            tw.WriteLine(
                                "extern {0}* {1}_HANDLER__(void);",
                                field.FieldType.CLanguageTypeName,
                                field.MangledUniqueName);
                            tw.WriteLine(
                                "/* {0} */ #define {1}_REF__ ({1}_HANDLER__())",
                                field.AttributeDescription,
                                field.MangledUniqueName);
                        }
                        tw.SplitLine();
                    }
                }

                var methods = declaredType.DeclaredMethods.
                    Where(predictMethod).
                    ToArray();
                if (methods.Length >= 1)
                {
                    tw.WriteLine("//////////////////////////////////////////////////////////////////////////////////");
                    tw.WriteLine(
                        "// [2-3] Methods: {0}",
                        declaredType.FriendlyName);
                    tw.SplitLine();

                    foreach (var method in methods)
                    {
                        // Special case: The type initializer hides into the file scope.
                        if (method.IsConstructor && method.IsStatic)
                        {
                            tw.WriteLine(
                                "static {0};",
                                method.CLanguageFunctionPrototype);
                        }
                        // Make inlining private interop methods
                        else if (method.IsExtern && method.IsPrivate)
                        {
                            tw.WriteLine(
                                "static inline /* {0} */ {1};",
                                method.AttributeDescription,
                                method.CLanguageFunctionPrototype);
                        }
                        else
                        {
                            tw.WriteLine(
                                "extern /* {0} */ {1};",
                                method.AttributeDescription,
                                method.CLanguageFunctionPrototype);
                        }
                    }
                    tw.SplitLine();
                }
            }
        }
    }
}
