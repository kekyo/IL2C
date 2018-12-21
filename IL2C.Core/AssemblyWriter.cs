using System.Diagnostics;
using System.Linq;

using IL2C.Translators;
using IL2C.Writers;

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
        internal static void InternalWriteHeader(
            CodeTextWriter twHeader,
            TranslateContext translateContext,
            PreparedInformations prepared,
            bool includeAssemblyHeader)
        {
            IExtractContext extractContext = translateContext;

            var assemblyName = Utilities.GetMangledName(extractContext.Assembly.FriendlyName);

            twHeader.WriteLine("#ifndef __{0}_H__", assemblyName);
            twHeader.WriteLine("#define __{0}_H__", assemblyName);
            twHeader.SplitLine();
            twHeader.WriteLine("#pragma once");
            twHeader.SplitLine();
            twHeader.WriteLine("#include <il2c.h>");
            twHeader.SplitLine();

            if (includeAssemblyHeader)
            {
                foreach (var fileName in extractContext.EnumerateRequiredIncludeFileNames())
                {
                    twHeader.WriteLine("#include <{0}>", fileName);
                }
                twHeader.SplitLine();
            }

            // All types exclude privates
            PrototypeWriter.InternalConvertToPrototypes(
                twHeader,
                prepared.Types,
                type => type.IsCLanguagePublicScope,
                field => field.IsCLanguagePublicScope,
                method => method.IsCLanguagePublicScope &&
                    prepared.Functions.ContainsKey(method));

            twHeader.WriteLine("#endif");
            twHeader.SplitLine();
        }

        public static void WriteHeader(
            CodeTextWriter twHeader,
            TranslateContext translateContext,
            PreparedInformations prepared)
        {
            InternalWriteHeader(
                twHeader, translateContext, prepared, true);
        }

        internal static void WriteConstStrings(
            CodeTextWriter twSource,
            TranslateContext translateContext)
        {
            IExtractContext extractContext = translateContext;

            var constStrings = extractContext.
                ExtractConstStrings().
                ToArray();

            if (constStrings.Length >= 1)
            {
                twSource.WriteLine("//////////////////////////////////////////////////////////////////////////////////");
                twSource.WriteLine("// [9-1] Const strings:");
                twSource.SplitLine();

                foreach (var (symbolName, value) in extractContext.ExtractConstStrings())
                {
                    var expr = Utilities.GetCLanguageExpression(value);
                    twSource.WriteLine(
                        "IL2C_CONST_STRING({0}, {1});",
                        symbolName,
                        expr);
                }

                twSource.SplitLine();
            }
        }

        internal static void WriteDeclaredValues(
            CodeTextWriter twSource,
            TranslateContext translateContext)
        {
            IExtractContext extractContext = translateContext;

            var declaredValues = extractContext.
                ExtractDeclaredValues().
                ToArray();

            if (declaredValues.Length >= 1)
            {
                twSource.WriteLine("//////////////////////////////////////////////////////////////////////////////////");
                twSource.WriteLine("// [12-1] Declared values:");

                foreach (var information in extractContext.ExtractDeclaredValues())
                {
                    twSource.SplitLine();
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
                    var expr = Utilities.GetCLanguageExpression(values);
                    twSource.WriteLine(
                        "static const {0} =",
                        lhs);
                    using (var _ = twSource.Shift())
                    {
                        twSource.WriteLine(
                            "{0};",
                            expr);
                    }
                }

                twSource.SplitLine();
            }
        }

        internal static void InternalWriteSourceCode(
            CodeTextWriter twSource,
            TranslateContext translateContext,
            PreparedInformations prepared,
            DebugInformationOptions debugInformationOption,
            bool includeAssemblyHeader)
        {
            IExtractContextHost extractContext = translateContext;

            foreach (var fileName in extractContext.EnumerateRequiredPrivateIncludeFileNames())
            {
                twSource.WriteLine("#include \"{0}\"", fileName);
            }

            foreach (var fileName in extractContext.EnumerateRequiredImportIncludeFileNames())
            {
                twSource.WriteLine("#include <{0}>", fileName);
            }

            if (includeAssemblyHeader)
            {
                twSource.WriteLine("#include \"{0}.h\"", extractContext.Assembly.Name);
            }

            twSource.SplitLine();

            WriteConstStrings(twSource, translateContext);
            WriteDeclaredValues(twSource, translateContext);

            twSource.WriteLine("//////////////////////////////////////////////////////////////////////////////////");
            twSource.WriteLine("// [9-2] File scope prototypes:");
            twSource.SplitLine();

            // All types exclude publics and internals (for file scope prototypes)
            PrototypeWriter.InternalConvertToPrototypes(
                twSource,
                prepared.Types,
                type => type.IsCLanguageLinkageScope || type.IsCLanguageFileScope,
                field => field.IsCLanguageLinkageScope || field.IsCLanguageFileScope,    // TODO: scope calculation (related packaging)
                method => (method.IsCLanguageLinkageScope || method.IsCLanguageFileScope) &&
                    prepared.Functions.ContainsKey(method));

            twSource.WriteLine("//////////////////////////////////////////////////////////////////////////////////");
            twSource.WriteLine("// [9-3] Static field instances:");
            twSource.SplitLine();

            foreach (var type in prepared.Types.
                Where(type => !type.IsEnum))
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

            foreach (var type in prepared.Types)
            {
                twSource.WriteLine("//////////////////////////////////////////////////////////////////////////////////");
                twSource.WriteLine("// [9-4] Type: {0}", type.FriendlyName);
                twSource.SplitLine();

                // All methods and constructor exclude type initializer
                foreach (var method in type.DeclaredMethods)
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
            }

            twSource.SplitLine();
        }

        public static void WriteSourceCode(
            CodeTextWriter twSource,
            TranslateContext translateContext,
            PreparedInformations prepared,
            DebugInformationOptions debugInformationOption = DebugInformationOptions.Full)
        {
            InternalWriteSourceCode(
                twSource, translateContext, prepared, debugInformationOption, true);
        }
    }
}
