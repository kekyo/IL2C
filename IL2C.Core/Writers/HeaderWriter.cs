using System;
using System.Diagnostics;
using System.Linq;

using IL2C.Metadata;
using IL2C.Translators;

namespace IL2C.Writers
{
    internal static class HeaderWriter
    {
        public static void WriteTypePreDefinitions(
            CodeTextWriter tw,
            ITypeInformation type)
        {
            tw.WriteLine("//////////////////////////////////////////////////////////////////////////////////");
            tw.WriteLine("// [2-1] Types:");
            tw.SplitLine();

            tw.WriteLine("////////////////////////////////////////////////////////////");
            tw.WriteLine("// [2-1-1] .NET types:");
            tw.SplitLine();

            // If it applied native type attribute.
            if (type.NativeType != null)
            {
                tw.WriteLine(
                    "typedef {0} {1};",
                    type.CLanguageNativeTypeName,
                    type.MangledUniqueName);
            }
            // Unfortunately the enum type at C language has not the underlying type.
            // IL2C emits the enum types don't use C language syntax.
            else if (type.IsEnum)
            {
                tw.WriteLine(
                    "typedef {0} {1};",
                    type.ElementType.CLanguageTypeName,
                    type.MangledUniqueName);
            }
            // The delegate derived types are same as System.MulticastDelegate.
            else if (type.IsDelegate)
            {
                tw.WriteLine(
                    "typedef System_MulticastDelegate {0};",
                    type.MangledUniqueName);
            }
            else
            {
                tw.WriteLine(
                    "typedef struct {0} {0};",
                    type.MangledUniqueName);
            }
            tw.SplitLine();

            tw.WriteLine("////////////////////////////////////////////////////////////");
            tw.WriteLine("// [2-1-2] VTable types:");
            tw.SplitLine();

            // If virtual method collection doesn't contain newslot method at this declared type:
            if (!type.NewSlotMethods.Any(method => method.DeclaringType.Equals(type)))
            {
                tw.WriteLine(
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
                tw.WriteLine(
                    "typedef const struct {0}_VTABLE_DECL___ {0}_VTABLE_DECL__;",
                    type.MangledUniqueName);
            }

            tw.SplitLine();
        }

        private static void InternalWriteAssemblyReferences(
            CodeTextWriter tw,
            TranslateContext translateContext,
            IExtractContext extractContext,
            MemberScopes scope)
        {
            foreach (var assembly in extractContext.EnumerateRegisteredTypes().
                Where(entry => entry.Key == scope).
                SelectMany(entry => entry.Value).
                Distinct().
                OrderByDependant().
                Select(type => type.DeclaringModule.DeclaringAssembly).
                Where(assembly => !assembly.Equals(translateContext.Assembly)).
                Distinct())
            {
                tw.WriteLine("#include <{0}.h>", assembly.Name);
            }
            tw.SplitLine();
        }

        public static void WriteCommonHeader(
            CodeTextStorage storage,
            TranslateContext translateContext,
            PreparedInformations prepared,
            string assemblyName,
            MemberScopes scope)
        {
            IExtractContext extractContext = translateContext;

            var annotatedAssemblyName = (scope == MemberScopes.Public) ?
                assemblyName :
                (assemblyName + "_internal");
            var annotatedAssemblyMangledName = Utilities.GetMangledName(annotatedAssemblyName);

            using (var twHeader = storage.CreateHeaderWriter(annotatedAssemblyName))
            {
                twHeader.WriteLine("#ifndef __{0}_H__", annotatedAssemblyMangledName);
                twHeader.WriteLine("#define __{0}_H__", annotatedAssemblyMangledName);
                twHeader.SplitLine();
                twHeader.WriteLine("#pragma once");
                twHeader.SplitLine();
                twHeader.WriteLine("// This is {0} native code translated by IL2C, do not edit.", assemblyName);
                twHeader.SplitLine();

                // Write assembly references.
                InternalWriteAssemblyReferences(
                    twHeader,
                    translateContext,
                    extractContext,
                    scope);

                foreach (var fileName in extractContext.EnumerateRequiredImportIncludeFileNames())
                {
                    twHeader.WriteLine("#include <{0}>", fileName);
                }
                twHeader.SplitLine();

                var expr = (scope == MemberScopes.Public) ?
                    prepared.Types.Where(type => type.IsCLanguagePublicScope) :
                    prepared.Types.Where(type => type.IsCLanguageLinkageScope);

                twHeader.WriteLine("///////////////////////////////////////////////////////////////////////////");
                twHeader.WriteLine("// Type pre definitions:");
                twHeader.SplitLine();

                foreach (var type in expr.OrderByDependant())
                {
                    twHeader.WriteLine(
                        "#include \"{0}/{1}/{2}.h\"",
                        assemblyName,
                        Utilities.GetCLanguageScopedPath(type.ScopeName),
                        type.Name);
                }
                twHeader.SplitLine();

                twHeader.WriteLine("///////////////////////////////////////////////////////////////////////////");
                twHeader.WriteLine("// Type body definitions:");
                twHeader.SplitLine();

                twHeader.WriteLine(
                    "#define {0}_DECL_TYPE_BODY__ 1",
                    annotatedAssemblyMangledName);
                twHeader.SplitLine();

                foreach (var type in expr.OrderByDependant())
                {
                    twHeader.WriteLine(
                        "#include \"{0}/{1}/{2}.h\"",
                        assemblyName,
                        Utilities.GetCLanguageScopedPath(type.ScopeName),
                        type.Name);
                }
                twHeader.SplitLine();

                if (scope != MemberScopes.Public)
                {
                    var constStrings = extractContext.
                        ExtractConstStrings().
                        ToArray();

                    if (constStrings.Length >= 1)
                    {
                        twHeader.WriteLine("//////////////////////////////////////////////////////////////////////////////////");
                        twHeader.WriteLine("// [9-1-1] Const strings:");
                        twHeader.SplitLine();

                        foreach (var (symbolName, _) in extractContext.ExtractConstStrings())
                        {
                            twHeader.WriteLine(
                                "System_String* const {0};",
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

                        foreach (var information in extractContext.ExtractDeclaredValues())
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
                }

                twHeader.WriteLine("#endif");
                twHeader.Flush();
            }
        }

        public static void WriteHeader(
            CodeTextStorage storage,
            TranslateContext translateContext,
            PreparedInformations prepared,
            MemberScopes scope)
        {
            IExtractContext extractContext = translateContext;
            var assemblyName = translateContext.Assembly.Name;
            var annotatedAssemblyMangledName = (scope == MemberScopes.Public) ?
                translateContext.Assembly.MangledName :
                (translateContext.Assembly.MangledName + "_internal");

            var predictField = (scope == MemberScopes.Public) ?
                new Func<IFieldInformation, bool>(field => field.IsCLanguagePublicScope) :
                new Func<IFieldInformation, bool>(field => field.IsCLanguageLinkageScope);
            var predictMethod = (scope == MemberScopes.Public) ?
                new Func<IMethodInformation, bool>(method => method.IsCLanguagePublicScope && prepared.Functions.ContainsKey(method)) :
                new Func<IMethodInformation, bool>(method => method.IsCLanguageLinkageScope && prepared.Functions.ContainsKey(method));

            foreach (var g in prepared.Types.GroupBy(type => type.ScopeName))
            {
                using (var _ = storage.EnterScope(g.Key))
                {
                    var typeExpr = (scope == MemberScopes.Public) ?
                        g.Where(type => type.IsCLanguagePublicScope) :
                        g.Where(type => type.IsCLanguageLinkageScope);
                    foreach (var type in typeExpr)
                    {
                        using (var twHeader = storage.CreateHeaderWriter(type.Name))
                        {
                            var scopeName = Utilities.GetMangledName(type.ScopeName);

                            twHeader.WriteLine("// This is {0} native code translated by IL2C, do not edit.", assemblyName);
                            twHeader.SplitLine();

                            twHeader.WriteLine("#include <{0}.h>", assemblyName);
                            if (scope != MemberScopes.Public)
                            {
                                twHeader.WriteLine("#include <{0}_internal.h>", assemblyName);
                            }
                            twHeader.SplitLine();

                            twHeader.WriteLine("#ifdef __cplusplus");
                            twHeader.WriteLine("extern \"C\" {");
                            twHeader.WriteLine("#endif");
                            twHeader.SplitLine();

                            twHeader.WriteLine("///////////////////////////////////////////////////////////////////////////");
                            twHeader.WriteLine("// Type pre definitions:");
                            twHeader.SplitLine();

                            // All types exclude privates
                            WriteTypePreDefinitions(
                                twHeader,
                                type);

                            twHeader.WriteLine("///////////////////////////////////////////////////////////////////////////");
                            twHeader.WriteLine("// Type body definitions:");
                            twHeader.SplitLine();

                            twHeader.WriteLine(
                                "#ifdef {0}_DECL_TYPE_BODY__",
                                annotatedAssemblyMangledName);
                            twHeader.SplitLine();

                            // Write value type and object reference type.
                            TypeWriter.WriteTypeDefinitions(
                                twHeader,
                                type);

                            // Write type members.
                            TypeWriter.WriteMemberDefinitions(
                                twHeader,
                                type,
                                predictField,
                                predictMethod);

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
