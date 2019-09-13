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
using System.IO;

namespace IL2C
{
    public static class SimpleDriver
    {
        public static void Translate(
            TextWriter logw,
            CodeTextStorage storage,
            bool readSymbols,
            bool enableBundler,
            DebugInformationOptions debugInformationOptions,
            string assemblyPath)
        {
            logw.Write("IL2C: Preparing assembly: \"{0}\" ...", Path.GetFullPath(assemblyPath));

            var translateContext = new TranslateContext(assemblyPath, readSymbols);
            var preparedFunctions = AssemblyPreparer.Prepare(translateContext);

            logw.WriteLine(" done.");

            using (var _ = storage.EnterScope("include"))
            {
                AssemblyWriter.WriteHeader(
                    storage,
                    translateContext,
                    preparedFunctions);
            }

            using (var _ = storage.EnterScope("src"))
            {
                AssemblyWriter.WriteSourceCode(
                    storage,
                    translateContext,
                    preparedFunctions,
                    enableBundler,
                    debugInformationOptions);
            }
        }

        public static void TranslateAll(
            TextWriter logw,
            CodeTextStorage storage,
            bool readSymbols,
            bool enableBundler,
            DebugInformationOptions debugInformationOptions,
            IEnumerable<string> assemblyPaths)
        {
            foreach (var aseemblyPath in assemblyPaths)
            {
                Translate(
                    logw,
                    storage,
                    readSymbols,
                    enableBundler,
                    debugInformationOptions,
                    aseemblyPath);
            }
        }

        public static void TranslateAll(
            TextWriter logw,
            CodeTextStorage storage,
            bool readSymbols,
            bool enableBundler,
            DebugInformationOptions debugInformationOptions,
            params string[] assemblyPaths)
        {
            TranslateAll(
                logw,
                storage,
                readSymbols,
                enableBundler,
                debugInformationOptions,
                (IEnumerable<string>)assemblyPaths);
        }

        public static void TranslateAll(
            TextWriter logw,
            string outputPath,
            bool readSymbols,
            bool enableCpp,
            bool enableBundler,
            DebugInformationOptions debugInformationOptions,
            IEnumerable<string> assemblyPaths)
        {
            var storage = new CodeTextStorage(
                logw,
                outputPath,
                enableCpp,
                "    ");

            foreach (var aseemblyPath in assemblyPaths)
            {
                Translate(
                    logw,
                    storage,
                    readSymbols,
                    enableBundler,
                    debugInformationOptions,
                    aseemblyPath);
            }
        }

        public static void TranslateAll(
            TextWriter logw,
            string outputPath,
            bool readSymbols,
            bool enableCpp,
            bool enableBundler,
            DebugInformationOptions debugInformationOptions,
            params string[] assemblyPaths)
        {
            TranslateAll(
                logw,
                outputPath,
                readSymbols,
                enableCpp,
                enableBundler,
                debugInformationOptions,
                (IEnumerable<string>)assemblyPaths);
        }
    }
}
