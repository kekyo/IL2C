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
