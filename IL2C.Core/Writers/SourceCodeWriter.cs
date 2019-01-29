using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;

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
                OrderByDependant().
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

                return ((CodeTextStorage.InternalCodeTextWriter)twSource).Path;
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

                    twSource.WriteLine("//////////////////////////////////////////////////////////////////////////////////");
                    twSource.WriteLine("// [9-3] Static field instances:");
                    twSource.SplitLine();

                    if (!type.IsEnum)
                    {
                        // All static fields
                        foreach (var field in type.Fields.
                            Where(field => field.IsStatic))
                        {
                            if (field.NativeValue == null)
                            {
                                twSource.WriteLine(
                                    "{0};",
                                    field.GetCLanguageStaticPrototype(true));
                            }
                        }
                        twSource.SplitLine();
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
                    g => g.OrderByDependant().ToArray());

            var sourceFiles = new List<string>();

            foreach (var targetType in prepared.Types.
                Where(type => type.DeclaringType == null))
            {
                using (var _ = storage.EnterScope(targetType.ScopeName))
                {
                    using (var twSource = storage.CreateSourceCodeWriter(targetType.Name))
                    {
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

                        sourceFiles.Add(((CodeTextStorage.InternalCodeTextWriter)twSource).Path);
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
