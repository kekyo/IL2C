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

using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using IL2C.Internal;
using IL2C.Metadata;
using IL2C.Translators;

namespace IL2C.Writers
{
    internal static class SourceCodeWriter
    {
        private static void InternalWriteAssemblyReferences(
            CodeTextWriter tw,
            TranslateContext translateContext,
            IExtractContext extractContext,
            ITypeInformation declaringType)
        {
            foreach (var assembly in extractContext.EnumerateRegisteredTypesByDeclaringType(declaringType).
                Distinct().
                OrderByDependant(declaringType.DeclaringModule.DeclaringAssembly).
                Select(type => type.DeclaringModule.DeclaringAssembly).
                Where(assembly => !assembly.Equals(translateContext.Assembly)).
                Distinct().
                OrderBy(assembly => assembly.Name))
            {
                tw.WriteLine("#include <{0}.h>", assembly.Name);
            }
            tw.SplitLine();
        }

        public static string WriteCommonInternalSourceCode(
            CodeTextStorage storage,
            TranslateContext translateContext,
            PreparedInformations prepared,
            string assemblyName)
        {
            IExtractContext extractContext = translateContext;

            using (var twSource = storage.CreateSourceCodeWriter(assemblyName + "_internal"))
            {
                var assemblyMangledName = Utilities.GetMangledName(assemblyName);

                twSource.WriteLine(
                    "// [15-1] This is {0} native code translated by IL2C, do not edit.",
                    assemblyName);
                twSource.SplitLine();

                twSource.WriteLine(
                    "#include <{0}.h>",
                    assemblyName);
                twSource.WriteLine(
                    "#include <{0}_internal.h>",
                    assemblyName);
                twSource.SplitLine();

                var constStrings = extractContext.
                    ExtractConstStrings().
                    ToArray();
                if (constStrings.Length >= 1)
                {
                    twSource.WriteLine("//////////////////////////////////////////////////////////////////////////////////");
                    twSource.WriteLine("// [9-1-2] Const strings:");
                    twSource.SplitLine();

                    foreach (var (symbolName, value) in constStrings)
                    {
                        twSource.WriteLine(
                            "IL2C_CONST_STRING({0}, {1});",
                            symbolName,
                            Utilities.GetCLanguageExpression(value));
                    }

                    twSource.SplitLine();
                }

                var declaredValues = extractContext.
                    ExtractDeclaredValues().
                    ToArray();
                if (declaredValues.Length >= 1)
                {
                    twSource.WriteLine("//////////////////////////////////////////////////////////////////////////////////");
                    twSource.WriteLine("// [12-1-2] Declared values:");
                    twSource.SplitLine();

                    foreach (var information in declaredValues)
                    {
                        foreach (var declaredFields in information.DeclaredFields)
                        {
                            twSource.WriteLine(
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
                        twSource.WriteLine(
                            "const {0} =",
                            lhs);
                        using (var _ = twSource.Shift())
                        {
                            twSource.WriteLine(
                                "{0};",
                                Utilities.GetCLanguageExpression(values));
                        }
                    }

                    twSource.SplitLine();
                }

                twSource.Flush();

                return twSource.RelatedPath;
            }
        }

        private static void InternalWriteSourceCode(
            CodeTextWriter twSource,
            IExtractContextHost extractContext,
            PreparedInformations prepared,
            ITypeInformation targetType,
            DebugInformationOptions debugInformationOption,
            IReadOnlyDictionary<ITypeInformation, ITypeInformation[]> typesByDeclaring)
        {
            // TODO: invalid sequence for multiple nested types.
            if (typesByDeclaring.TryGetValue(targetType, out var types))
            {
                foreach (var type in types)
                {
                    // The nested types have to declare before outer types.
                    if (!type.Equals(targetType))
                    {
                        InternalWriteSourceCode(
                            twSource,
                            extractContext,
                            prepared,
                            type,
                            debugInformationOption,
                            typesByDeclaring);
                    }

                    twSource.WriteLine("//////////////////////////////////////////////////////////////////////////////////");
                    twSource.WriteLine(
                        "// [9-1] Type: {0}",
                        targetType.FriendlyName);
                    twSource.SplitLine();

                    twSource.WriteLine("//////////////////////////////////////////////////////////////////////////////////");
                    twSource.WriteLine("// [9-2] File scope prototypes:");
                    twSource.SplitLine();

                    // Write type members.
                    TypeWriter.WriteMemberDefinitions(
                        twSource,
                        type,
                        field => field.CLanguageMemberScope == MemberScopes.File,
                        method => (method.CLanguageMemberScope == MemberScopes.File) && prepared.Functions.ContainsKey(method));

                    // All static fields except enum and native value.
                    if (!type.IsEnum)
                    {
                        var staticFields = type.Fields.
                            Where(field => field.IsStatic && (field.NativeValue == null)).
                            ToArray();
                        if (staticFields.Length >= 1)
                        {
                            twSource.WriteLine("//////////////////////////////////////////////////////////////////////////////////");
                            twSource.WriteLine("// [9-3] Static field handlers:");
                            twSource.SplitLine();

                            var staticFieldsName = type.MangledUniqueName + "_STATIC_FIELDS";

                            twSource.WriteLine(
                                "static volatile interlock_t {0}_initializerCount__ = 0;",
                                staticFieldsName);
                            twSource.WriteLine(
                                "static volatile interlock_t {0}_initializedCount__ = 0;",
                                staticFieldsName);
                            twSource.SplitLine();
                            twSource.WriteLine(
                                "static struct {0}_DECL__ /* IL2C_STATIC_FIELDS */",
                                staticFieldsName);
                            twSource.WriteLine("{");

                            var objrefStaticFields = staticFields.
                                Where(field => field.FieldType.IsReferenceType).
                                ToArray();
                            var valueTypeStaticFields = staticFields.
                                Where(field => field.FieldType.IsValueType && field.FieldType.IsRequiredTraverse).
                                ToArray();
                            var otherStaticFields = new HashSet<IFieldInformation>(staticFields.
                                Except(objrefStaticFields).
                                Except(valueTypeStaticFields));

                            using (var _ = twSource.Shift())
                            {
                                twSource.WriteLine("IL2C_STATIC_FIELDS* pNext__;");
                                twSource.WriteLine("const uint16_t objRefCount__;");
                                twSource.WriteLine("const uint16_t valueCount__;");

                                if (objrefStaticFields.Length >= 1)
                                {
                                    twSource.WriteLine("//-------------------- objref");
                                    foreach (var field in objrefStaticFields)
                                    {
                                        twSource.WriteLine(
                                            "{0} {1};",
                                            field.FieldType.CLanguageTypeName,
                                            field.MangledName);
                                    }
                                }

                                if (valueTypeStaticFields.Length >= 1)
                                {
                                    twSource.WriteLine("//-------------------- value type");
                                    foreach (var field in valueTypeStaticFields)
                                    {
                                        twSource.WriteLine(
                                            "{0} {1};",
                                            field.FieldType.CLanguageTypeName,
                                            field.MangledName);
                                    }
                                }
                            }

                            twSource.WriteLine(
                                "}} {0}__ = {{ NULL, {1}, {2} }};",
                                staticFieldsName,
                                objrefStaticFields.Length,
                                valueTypeStaticFields.Length);
                            twSource.SplitLine();

                            // Generate static fileds
                            foreach (var field in otherStaticFields)
                            {
                                twSource.WriteLine(
                                   "static {0} {1};",
                                   field.FieldType.CLanguageTypeName,
                                   field.MangledUniqueName);
                            }
                            twSource.SplitLine();

                            // Generate type initializer function
                            var typeInitializerName =
                                $"{type.MangledUniqueName}_TypeIntializer__";
                            twSource.WriteLine(
                                "static void {0}(void)",
                                typeInitializerName);
                            twSource.WriteLine("{");
                            using (var __ = twSource.Shift())
                            {
                                twSource.WriteLine(
                                    "if (il2c_unlikely__(il2c_required_initializing_type__(&{0}_initializerCount__)))",
                                    staticFieldsName);
                                twSource.WriteLine("{");
                                using (var ____ = twSource.Shift())
                                {
                                    twSource.WriteLine(
                                        "il2c_register_static_fields(&{0}__);",
                                        staticFieldsName);

                                    twSource.WriteLine(
                                        "il2c_try(nest0, il2c_default_finally_filter__)");
                                    twSource.WriteLine("{");
                                    using (var _____ = twSource.Shift())
                                    {
                                        var typeInitializer = type.DeclaredMethods.
                                            FirstOrDefault(method => method.IsConstructor && method.IsStatic);
                                        if (typeInitializer != null)
                                        {
                                            twSource.WriteLine(
                                                "{0}();",
                                                typeInitializer.CLanguageFunctionFullName);
                                        }
                                        twSource.WriteLine("il2c_leave(nest0, 0);");
                                    }
                                    twSource.WriteLine("}");
                                    twSource.WriteLine("il2c_finally(nest0)");
                                    twSource.WriteLine("{");
                                    using (var _____ = twSource.Shift())
                                    {
                                        twSource.WriteLine(
                                            "{0}_initializedCount__ = *il2c_initializer_count;",
                                            staticFieldsName);
                                        twSource.WriteLine("il2c_endfinally(nest0);");
                                    }
                                    twSource.WriteLine("}");
                                    twSource.WriteLine("il2c_leave_to(nest0)");
                                    twSource.WriteLine("{");
                                    using (var _____ = twSource.Shift())
                                    {
                                        twSource.WriteLine("il2c_leave_bind(nest0, 0, CCTOR_F);");
                                    }
                                    twSource.WriteLine("}");
                                    twSource.WriteLine("il2c_end_try(nest0);");

                                    twSource.WriteLine("CCTOR_F: return;");
                                }
                                twSource.WriteLine("}");

                                twSource.WriteLine(
                                    "while (il2c_unlikely__({0}_initializedCount__ != *il2c_initializer_count));",
                                    staticFieldsName);
                            }
                            twSource.WriteLine("}");
                            twSource.SplitLine();

                            // Generate filed access handlers
                            foreach (var field in staticFields)
                            {
                                twSource.WriteLine(
                                    "{0}* {1}_HANDLER__(void)",
                                    field.FieldType.CLanguageTypeName,
                                    field.MangledUniqueName);
                                twSource.WriteLine("{");

                                using (var _ = twSource.Shift())
                                {
                                    twSource.WriteLine(
                                        "if (il2c_unlikely__({0}_initializedCount__ != *il2c_initializer_count))",
                                        staticFieldsName);
                                    twSource.WriteLine("{");
                                    using (var __ = twSource.Shift())
                                    {
                                        twSource.WriteLine(
                                            "{0}();",
                                            typeInitializerName);
                                    }
                                    twSource.WriteLine("}");

                                    if (otherStaticFields.Contains(field))
                                    {
                                        twSource.WriteLine(
                                            "return &{0};",
                                            field.MangledUniqueName);
                                    }
                                    else
                                    {
                                        twSource.WriteLine(
                                            "return &{0}__.{1};",
                                            staticFieldsName,
                                            field.MangledName);
                                    }
                                }

                                twSource.WriteLine("}");
                                twSource.SplitLine();
                            }
                        }
                    }

                    twSource.WriteLine("//////////////////////////////////////////////////////////////////////////////////");
                    twSource.WriteLine("// [9-4] Type: {0}", type.FriendlyName);
                    twSource.SplitLine();

                    // All methods and constructor exclude type initializer
                    foreach (var method in type.DeclaredMethods.
                        Where(method => prepared.Functions.ContainsKey(method)))
                    {
                        FunctionWriter.InternalConvertFromMethod(
                            twSource,
                            extractContext,
                            prepared,
                            method,
                            debugInformationOption);
                    }

                    if (type.IsClass || type.IsValueType)
                    {
                        TypeHelperWriter.InternalConvertTypeHelper(
                            twSource,
                            type);
                    }
                    else if (type.IsInterface)
                    {
                        TypeHelperWriter.InternalConvertTypeHelperForInterface(
                            twSource,
                            type);
                    }

                    twSource.SplitLine();
                }
            }
        }

        public static string[] WriteSourceCodes(
            CodeTextStorage storage,
            TranslateContext translateContext,
            PreparedInformations prepared,
            DebugInformationOptions debugInformationOption)
        {
            IExtractContextHost extractContext = translateContext;
            var assemblyName = extractContext.Assembly.Name;

            var typesByDeclaring = prepared.Types.
                GroupBy(type => type.DeclaringType ?? type).
                ToDictionary(
                    g => g.Key,
                    g => g.OrderByDependant(translateContext.Assembly).ToArray());

            var sourceFiles = new List<string>();

            foreach (var targetType in prepared.Types.
                Where(type => type.DeclaringType == null))
            {
                using (var _ = storage.EnterScope(targetType.ScopeName))
                {
                    using (var twSource = storage.CreateSourceCodeWriter(targetType.Name))
                    {
                        // HACK: Unreal Engine 4 needs include directive with same file name as header extension (ex: foo.c --> foo.h) at first line.
                        if (extractContext.TargetPlatform == TargetPlatforms.UE4)
                        {
                            twSource.WriteLine(
                                "#include \"{0}.h\"   // [16-1] Needs for Unreal Engine 4.",
                                targetType.Name);
                            twSource.SplitLine();
                        }

                        twSource.WriteLine(
                            "// [15-2] This is {0} native code translated by IL2C, do not edit.",
                            assemblyName);
                        twSource.SplitLine();

                        twSource.WriteLine(
                            "#include <{0}.h>",
                            assemblyName);
                        twSource.WriteLine(
                            "#include <{0}_internal.h>",
                            assemblyName);
                        twSource.SplitLine();

                        // Write assembly references at the file scope.
                        InternalWriteAssemblyReferences(
                            twSource,
                            translateContext,
                            extractContext,
                            targetType);

                        twSource.WriteLine("#ifdef __cplusplus");
                        twSource.WriteLine("extern \"C\" {");
                        twSource.WriteLine("#endif");
                        twSource.SplitLine();

                        InternalWriteSourceCode(
                            twSource,
                            extractContext,
                            prepared,
                            targetType,
                            debugInformationOption,
                            typesByDeclaring);

                        twSource.WriteLine("#ifdef __cplusplus");
                        twSource.WriteLine("}");
                        twSource.WriteLine("#endif");
                        twSource.SplitLine();

                        twSource.Flush();

                        sourceFiles.Add(twSource.RelatedPath);
                    }

                    // HACK: Unreal Engine 4 needs include directive with same file name as header extension (ex: foo.c --> foo.h) at first line.
                    if (extractContext.TargetPlatform == TargetPlatforms.UE4)
                    {
                        using (var twUE4Header = storage.CreateHeaderWriter(targetType.Name))
                        {
                            twUE4Header.WriteLine(
                                "// [16-2] This is {0} native code translated by IL2C, do not edit.",
                                assemblyName);
                            twUE4Header.WriteLine(
                                "// It's a dummy header file for helping and using only Unreal Engine 4.",
                                assemblyName);

                            twUE4Header.Flush();
                        }
                    }
                }
            }

            return sourceFiles.ToArray();
        }

        public static void WriteBundlerSourceCode(
            CodeTextStorage storage,
            PreparedInformations prepared,
            string assemblyName)
        {
            using (var twSource = storage.CreateSourceCodeWriter(assemblyName + "_bundle"))
            {
                var assemblyMangledName = Utilities.GetMangledName(assemblyName);

                twSource.WriteLine(
                    "// [15-3] This is {0} native code translated by IL2C, do not edit.",
                    assemblyName);
                twSource.SplitLine();
                twSource.WriteLine(
                    "// This is the bundler source code for {0},",
                    assemblyName);
                twSource.WriteLine(
                    "// you can use it if you wanna compile only one source file.");
                twSource.SplitLine();

                twSource.WriteLine(
                    "#include \"{0}_internal.c\"",
                    assemblyName);

                foreach (var type in prepared.Types.
                    Where(type => type.DeclaringType == null))
                {
                    twSource.WriteLine(
                        "#include \"{0}/{1}/{2}.c\"",
                        assemblyName,
                        Utilities.GetCLanguageScopedPath(type.ScopeName),
                        type.Name);
                }

                twSource.SplitLine();
                twSource.Flush();
            }
        }
    }
}
