////////////////////////////////////////////////////////////////////////////
//
// IL2C - A translator for ECMA-335 CIL/MSIL to C language.
// Copyright (c) Kouji Matsui (@kozy_kekyo, @kekyo@mastodon.cloud)
//
// Licensed under Apache-v2: https://opensource.org/licenses/Apache-2.0
//
////////////////////////////////////////////////////////////////////////////

using System.Collections.Generic;

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

            // Write assembly level common header.
            HeaderWriter.WriteCommonHeader(
                storage,
                translateContext,
                prepared,
                assemblyName);

            using (var _ = storage.EnterScope(assemblyName, false))
            {
                // Write public headers.
                HeaderWriter.WriteHeaders(
                    storage,
                    translateContext,
                    prepared);
            }
        }

        public static string[] WriteSourceCode(
            CodeTextStorage storage,
            TranslateContext translateContext,
            PreparedInformations prepared,
            bool enableBundler,
            DebugInformationOptions debugInformationOption)
        {
            var sourceFilePaths = new List<string>();

            var assemblyName = translateContext.Assembly.Name;

            // Write assembly level common internal header.
            HeaderWriter.WriteCommonInternalHeader(
                storage,
                translateContext,
                prepared,
                assemblyName);

            // Write assembly level common internal source code.
            sourceFilePaths.Add(
                SourceCodeWriter.WriteCommonInternalSourceCode(
                    storage,
                    translateContext,
                    prepared,
                    assemblyName));

            // Write source code bundler.
            if (enableBundler)
            {
                SourceCodeWriter.WriteBundlerSourceCode(
                    storage,
                    prepared,
                    assemblyName);
            }

            using (var _ = storage.EnterScope(assemblyName, false))
            {
                // Write source codes.
                sourceFilePaths.AddRange(
                    SourceCodeWriter.WriteSourceCodes(
                        storage,
                        translateContext,
                        prepared,
                        debugInformationOption));
            }

            return sourceFilePaths.ToArray();
        }
    }
}
