/////////////////////////////////////////////////////////////////////////////////////////////////
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
using IL2C.Translators;

namespace IL2C.Writers
{
    internal static class HeaderWriter
    {
        private static void InternalWriteTypePreDefinitions(
            CodeTextWriter twHeader,
            ITypeInformation targetType,
            IReadOnlyDictionary<ITypeInformation, ITypeInformation[]> typesByDeclaring)
        {
            if (typesByDeclaring.TryGetValue(targetType, out var types))
            {
                if (types.Length >= 1)
                {
                    twHeader.WriteLine("////////////////////////////////////////////////////////////");
                    twHeader.WriteLine("// [2-1-1] .NET types:");
                    twHeader.SplitLine();

                    foreach (var type in types)
                    {
                        // The nested types have to declare before outer types.
                        if (!type.Equals(targetType))
                        {
                            InternalWriteTypePreDefinitions(
                                twHeader,
                                type,
                                typesByDeclaring);
                        }

                        // If it applied native type attribute.
                        if (type.NativeType != null)
                        {
                            twHeader.WriteLine(
                                "/* native type */ typedef {0} {1};",
                                type.CLanguageNativeTypeName,
                                type.MangledUniqueName);
                        }
                        // Unfortunately the enum type at C language has not the underlying type.
                        // IL2C emits the enum types don't use C language syntax.
                        else if (type.IsEnum)
                        {
                            twHeader.WriteLine(
                                "/* {0} */ typedef {1} {2};",
                                type.AttributeDescription,
                                type.ElementType.CLanguageTypeName,
                                type.MangledUniqueName);
                        }
                        // The delegate derived types are same as System.MulticastDelegate.
                        else if (type.IsDelegate)
                        {
                            twHeader.WriteLine(
                                "/* {0} */ typedef System_MulticastDelegate {1};",
                                type.AttributeDescription,
                                type.MangledUniqueName);
                        }
                        else
                        {
                            twHeader.WriteLine(
                                "/* {0} */ typedef struct {1} {1};",
                                type.AttributeDescription,
                                type.MangledUniqueName);
                        }
                    }

                    twHeader.SplitLine();
                }
            }
        }

        private static void InternalWriteVTableTypePreDefinitions(
            CodeTextWriter twHeader,
            ITypeInformation targetType,
            IReadOnlyDictionary<ITypeInformation, ITypeInformation[]> typesByDeclaring)
        {
            if (typesByDeclaring.TryGetValue(targetType, out var types))
            {
                if (types.Length >= 1)
                {
                    twHeader.WriteLine("////////////////////////////////////////////////////////////");
                    twHeader.WriteLine("// [2-1-2] VTable types:");
                    twHeader.SplitLine();

                    foreach (var type in types)
                    {
                        // The nested types have to declare before outer types.
                        if (!type.Equals(targetType))
                        {
                            InternalWriteVTableTypePreDefinitions(
                                twHeader,
                                type,
                                typesByDeclaring);
                        }

                        // If virtual method collection doesn't contain newslot method at this declared type:
                        if (!type.DeclaredNewslotMethods.Any(method => method.DeclaringType.Equals(type)))
                        {
                            twHeader.WriteLine(
                                "typedef {0}_VTABLE_DECL__ {1}_VTABLE_DECL__;",
                                type.BaseType.MangledUniqueName,
                                type.MangledUniqueName);
                        }
                        // Require new vtable layout.
                        else
                        {
                            // Important: The vtable structure definition marked for "const",
                            //    because these vtables place into the ".rdata" section or same location.
                            //    Many small system have very tiny space for RAM (writable memory),
                            //    IL2C has to efficient memory space, vtable can place into ROM location.
                            twHeader.WriteLine(
                                "typedef const struct {0}_VTABLE_DECL___ {0}_VTABLE_DECL__;",
                                type.MangledUniqueName);
                        }
                    }

                    twHeader.SplitLine();
                }
            }
        }

        public static void WriteTypePreDefinitions(
            CodeTextWriter twHeader,
            ITypeInformation targetType,
            IReadOnlyDictionary<ITypeInformation, ITypeInformation[]> typesByDeclaring)
        {
            InternalWriteTypePreDefinitions(twHeader, targetType, typesByDeclaring);
            InternalWriteVTableTypePreDefinitions(twHeader, targetType, typesByDeclaring);
        }

        public static void WriteCommonHeader(
            CodeTextStorage storage,
            TranslateContext translateContext,
            PreparedInformations prepared,
            string assemblyName)
        {
            IExtractContext extractContext = translateContext;
            var assemblyMangledName = Utilities.GetMangledName(assemblyName);

            using (var twHeader = storage.CreateHeaderWriter(assemblyName))
            {
                twHeader.WriteLine(
                    "// [13-1] This is {0} native code translated by IL2C, do not edit.",
                    assemblyName);
                twHeader.SplitLine();

                twHeader.WriteLine(
                    "#ifndef __{0}_H__",
                    assemblyMangledName);
                twHeader.WriteLine(
                    "#define __{0}_H__",
                    assemblyMangledName);
                twHeader.SplitLine();
                twHeader.WriteLine("#pragma once");
                twHeader.SplitLine();

                // Write assembly references.
                var assemblies = extractContext.EnumerateRegisteredTypes().
                    SelectMany(entry => entry.Value).
                    Distinct().
                    OrderByDependant(translateContext.Assembly).
                    Select(type => type.DeclaringModule.DeclaringAssembly).
                    Where(assembly => !assembly.Equals(translateContext.Assembly)).
                    Distinct().
                    ToArray();
                if (assemblies.Length >= 1)
                {
                    twHeader.WriteLine("///////////////////////////////////////////////////////////////////////////");
                    twHeader.WriteLine("// [13-2] Assembly references:");
                    twHeader.SplitLine();

                    foreach (var assembly in assemblies)
                    {
                        twHeader.WriteLine("#include <{0}.h>", assembly.Name);
                    }
                    twHeader.SplitLine();
                }

                // Write native headers from the NativeType/NativeMethod/NativeValue attributes.
                var importFileNames = extractContext.EnumerateRequiredImportIncludeFileNames().ToArray();
                if (importFileNames.Length >= 1)
                {
                    twHeader.WriteLine("///////////////////////////////////////////////////////////////////////////");
                    twHeader.WriteLine("// [13-3] Import native headers:");
                    twHeader.SplitLine();

                    foreach (var fileName in importFileNames)
                    {
                        twHeader.WriteLine("#include <{0}>", fileName);
                    }
                    twHeader.SplitLine();
                }

                var types = prepared.Types.
                    Where(type => type.DeclaringType == null).
                    OrderByDependant(translateContext.Assembly).
                    ToArray();
                if (types.Length >= 1)
                {
                    // Write pre definitions of type.
                    twHeader.WriteLine("///////////////////////////////////////////////////////////////////////////");
                    twHeader.WriteLine("// [13-4] Type pre definitions:");
                    twHeader.SplitLine();

                    foreach (var type in types)
                    {
                        twHeader.WriteLine(
                            "#include \"{0}/{1}/{2}.h\"",
                            assemblyName,
                            Utilities.GetCLanguageScopedPath(type.ScopeName),
                            type.Name);
                    }
                    twHeader.SplitLine();

                    // Write body definitions of type.
                    twHeader.WriteLine("///////////////////////////////////////////////////////////////////////////");
                    twHeader.WriteLine("// [13-5] Type body definitions:");
                    twHeader.SplitLine();

                    twHeader.WriteLine(
                        "#define {0}_DECL_TYPE_BODY__ 1",
                        assemblyMangledName);
                    twHeader.SplitLine();

                    foreach (var type in types)
                    {
                        twHeader.WriteLine(
                            "#include \"{0}/{1}/{2}.h\"",
                            assemblyName,
                            Utilities.GetCLanguageScopedPath(type.ScopeName),
                            type.Name);
                    }
                    twHeader.SplitLine();
                }

                twHeader.WriteLine("#endif");
                twHeader.Flush();
            }
        }

        public static void WriteCommonInternalHeader(
            CodeTextStorage storage,
            TranslateContext translateContext,
            PreparedInformations prepared,
            string assemblyName)
        {
            IExtractContext extractContext = translateContext;
            var annotatedAssemblyName = assemblyName + "_internal";
            var annotatedAssemblyMangledName = Utilities.GetMangledName(annotatedAssemblyName);

            using (var twHeader = storage.CreateHeaderWriter(annotatedAssemblyName))
            {
                twHeader.WriteLine(
                    "// [13-1] This is {0} native code translated by IL2C, do not edit.",
                    assemblyName);
                twHeader.SplitLine();

                twHeader.WriteLine(
                    "#ifndef __{0}_H__",
                    annotatedAssemblyMangledName);
                twHeader.WriteLine(
                    "#define __{0}_H__",
                    annotatedAssemblyMangledName);
                twHeader.SplitLine();
                twHeader.WriteLine("#pragma once");
                twHeader.SplitLine();

                twHeader.WriteLine("#include <{0}.h>", assemblyName);
                twHeader.SplitLine();

                var constStrings = extractContext.
                    ExtractConstStrings().
                    ToArray();
                if (constStrings.Length >= 1)
                {
                    twHeader.WriteLine("//////////////////////////////////////////////////////////////////////////////////");
                    twHeader.WriteLine("// [9-1-1] Const strings:");
                    twHeader.SplitLine();

                    foreach (var (symbolName, _) in constStrings)
                    {
                        twHeader.WriteLine(
                            "extern System_String* const {0};",
                            symbolName);
                    }
                    twHeader.SplitLine();
                }

                var declaredValues = extractContext.
                    ExtractDeclaredValues().
                    ToArray();
                if (declaredValues.Length >= 1)
                {
                    twHeader.WriteLine("//////////////////////////////////////////////////////////////////////////////////");
                    twHeader.WriteLine("// [12-1-1] Declared values:");
                    twHeader.SplitLine();

                    foreach (var information in declaredValues)
                    {
                        foreach (var declaredFields in information.DeclaredFields)
                        {
                            twHeader.WriteLine(
                                "// {0}",
                                declaredFields.FriendlyName);
                        }

                        var targetType = (information.HintTypes.Length == 1) ?
                            information.HintTypes[0] :
                            extractContext.MetadataContext.ByteType.MakeArray();
                        Debug.Assert(targetType.IsArray);

                        var elementType = targetType.ElementType.ResolveToRuntimeType();
                        var values = Utilities.ResourceDataToSpecificArray(information.ResourceData, elementType);

                        var lhs = targetType.GetCLanguageTypeName(information.SymbolName, true);
                        twHeader.WriteLine(
                            "extern const {0};",
                            lhs);
                    }
                    twHeader.SplitLine();
                }

                twHeader.WriteLine("#endif");
                twHeader.Flush();
            }
        }

        private static void InternalWriteHeader(
            CodeTextWriter twHeader,
            PreparedInformations prepared,
            ITypeInformation targetType,
            MemberScopes memberScope,
            IReadOnlyDictionary<ITypeInformation, ITypeInformation[]> typesByDeclaring)
        {
            if (typesByDeclaring.TryGetValue(targetType, out var types))
            {
                foreach (var type in types)
                {
                    // The nested types have to declare before outer types.
                    if (!type.Equals(targetType))
                    {
                        InternalWriteHeader(
                            twHeader,
                            prepared,
                            type,
                            memberScope,
                            typesByDeclaring);
                    }

                    // Write value type and object reference type.
                    TypeWriter.WriteTypeDefinitions(
                        twHeader,
                        type);

                    // Write type members.
                    TypeWriter.WriteMemberDefinitions(
                        twHeader,
                        type,
                        field => true,
                        method =>
                            // Except type initializer
                            !(method.IsConstructor && method.IsStatic) &&
                            prepared.Functions.ContainsKey(method));

                        // TODO: The internal or private members can separate into the internal headers.
                        //field => field.CLanguageMemberScope == memberScope,
                        //method => (method.CLanguageMemberScope == memberScope) && prepared.Functions.ContainsKey(method));
                }
            }
        }

        public static void WriteHeaders(
            CodeTextStorage storage,
            TranslateContext translateContext,
            PreparedInformations prepared)
        {
            IExtractContext extractContext = translateContext;
            var assemblyName = translateContext.Assembly.Name;
            var assemblyMangledName = translateContext.Assembly.MangledName;

            var typesByDeclaring = prepared.Types.
                GroupBy(type => type.DeclaringType ?? type).
                ToDictionary(
                    g => g.Key,
                    g => g.OrderByDependant(translateContext.Assembly).ToArray());

            foreach (var g in prepared.Types.
                Where(type => type.DeclaringType == null).
                GroupBy(type => type.ScopeName))
            {
                using (var _ = storage.EnterScope(g.Key))
                {
                    foreach (var type in g)
                    {
                        using (var twHeader = storage.CreateHeaderWriter(type.Name))
                        {
                            var scopeName = Utilities.GetMangledName(type.ScopeName);

                            twHeader.WriteLine(
                                "// [14-1] This is {0} native code translated by IL2C, do not edit.",
                                assemblyName);
                            twHeader.SplitLine();

                            twHeader.WriteLine(
                                "#include <{0}.h>",
                                assemblyName);
                            twHeader.SplitLine();

                            twHeader.WriteLine("#ifdef __cplusplus");
                            twHeader.WriteLine("extern \"C\" {");
                            twHeader.WriteLine("#endif");
                            twHeader.SplitLine();

                            twHeader.WriteLine("///////////////////////////////////////////////////////////////////////////");
                            twHeader.WriteLine("// [14-2] Type pre definitions:");
                            twHeader.SplitLine();

                            // All types exclude privates
                            WriteTypePreDefinitions(
                                twHeader,
                                type,
                                typesByDeclaring);

                            twHeader.WriteLine("///////////////////////////////////////////////////////////////////////////");
                            twHeader.WriteLine("// [14-3] Type body definitions:");
                            twHeader.SplitLine();

                            twHeader.WriteLine(
                                "#ifdef {0}_DECL_TYPE_BODY__",
                                assemblyMangledName);
                            twHeader.SplitLine();

                            InternalWriteHeader(
                                twHeader,
                                prepared,
                                type,
                                MemberScopes.Public,
                                typesByDeclaring);

                            twHeader.WriteLine("#endif");
                            twHeader.SplitLine();

                            twHeader.WriteLine("#ifdef __cplusplus");
                            twHeader.WriteLine("}");
                            twHeader.WriteLine("#endif");
                            twHeader.SplitLine();

                            twHeader.Flush();
                        }
                    }
                }
            }
        }
    }
}
