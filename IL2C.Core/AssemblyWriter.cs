using System;
using System.Collections.Generic;

using IL2C.Metadata;
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
        public static void WriteHeader(
            CodeTextStorage storage,
            TranslateContext translateContext,
            PreparedInformations prepared)
        {
            var assemblyName = translateContext.Assembly.Name;

            // Write assembly level common public header.
            HeaderWriter.WriteCommonHeader(
                storage,
                translateContext,
                prepared,
                assemblyName,
                MemberScopes.Public);

            using (var _ = storage.EnterScope(assemblyName, false))
            {
                // Write public headers.
                HeaderWriter.WriteHeader(
                    storage,
                    translateContext,
                    prepared,
                    MemberScopes.Public);
            }
        }

        public static string[] WriteSourceCode(
            CodeTextStorage storage,
            TranslateContext translateContext,
            PreparedInformations prepared,
            DebugInformationOptions debugInformationOption)
        {
            var sourceFilePaths = new List<string>();

            var assemblyName = translateContext.Assembly.Name;

            // Write assembly level common internal header.
            HeaderWriter.WriteCommonHeader(
                storage,
                translateContext,
                prepared,
                assemblyName,
                MemberScopes.Linkage);

            // Write assembly level common internal source code.
            sourceFilePaths.Add(
                SourceCodeWriter.WriteCommonSourceCode(
                    storage,
                    translateContext,
                    prepared,
                    assemblyName));

            // Write source code bundler.
            SourceCodeWriter.WriteBundlerSourceCode(
                storage,
                prepared,
                assemblyName);

            using (var _ = storage.EnterScope(assemblyName, false))
            {
                // Write internal headers.
                HeaderWriter.WriteHeader(
                    storage,
                    translateContext,
                    prepared,
                    MemberScopes.Linkage);

                // Write source codes.
                sourceFilePaths.AddRange(
                    SourceCodeWriter.WriteSourceCode(
                        storage,
                        translateContext,
                        prepared,
                        debugInformationOption));
            }

            return sourceFilePaths.ToArray();
        }
    }
}
