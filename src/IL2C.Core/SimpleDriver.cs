////////////////////////////////////////////////////////////////////////////
//
// IL2C - A translator for ECMA-335 CIL/MSIL to C language.
// Copyright (c) Kouji Matsui (@kozy_kekyo, @kekyo@mastodon.cloud)
//
// Licensed under Apache-v2: https://opensource.org/licenses/Apache-2.0
//
////////////////////////////////////////////////////////////////////////////

using System;
using System.IO;
using System.Linq;
using System.Threading.Tasks;

using IL2C.Internal;

namespace IL2C
{
    public static class SimpleDriver
    {
        public static Task TranslateAsync(
            TextWriter logw,
            CodeTextStorage storage,
            bool readSymbols,
            bool enableBundler,
            TargetPlatforms targetPlatform,
            DebugInformationOptions debugInformationOptions,
            string assemblyPath)
        {
            logw.WriteLine("IL2C: Preparing assembly: \"{0}\" ...", Path.GetFullPath(assemblyPath));

            var translateContext = new TranslateContext(assemblyPath, readSymbols, targetPlatform);
            var preparedFunctions = AssemblyPreparer.Prepare(translateContext);

            logw.WriteLine("IL2C: Translating assembly: \"{0}\" ...", Path.GetFullPath(assemblyPath));

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

            logw.WriteLine("IL2C: Translated assembly: Stored into \"{0}\"", Path.GetFullPath(storage.BasePath));

            // TODO:
#if NET452_OR_GREATER || NETSTANDARD || NETCOREAPP
            return Task.CompletedTask;
#else
            return Task.FromResult(0);
#endif
        }

        public static Task TranslateAsync(
            TextWriter logw,
            string outputDirPath,
            bool readSymbols,
            bool enableCpp,
            bool enableBundler,
            TargetPlatforms targetPlatform,
            DebugInformationOptions debugInformationOptions,
            string assemblyPath)
        {
            var storage = new CodeTextStorage(
                logw,
                outputDirPath,
                enableCpp,
                "    ");

            return TranslateAsync(
                logw,
                storage,
                readSymbols,
                enableBundler,
                targetPlatform,
                debugInformationOptions,
                assemblyPath);
        }

        public static async Task CompileAsync(
            TextWriter logw,
            string outputNativePath,
            string nativeCompiler,
            string nativeCompilerFlags,
            string[] includeDirs,
            string[] libPaths,
            bool enableCpp,
            bool enableBundler,
            bool isLibrary,
            string sourceCodeDirPath)
        {
            var sourceCodeDirFullPath = Path.GetFullPath(sourceCodeDirPath);
            var outputNativeFullPath = Path.GetFullPath(outputNativePath);
            var nativeCompilerBasePath = Path.GetDirectoryName(nativeCompiler);
            var nativeCompilerBasePaths =
                string.IsNullOrWhiteSpace(nativeCompilerBasePath) ?
                    new string[0] :
                    new[] { Path.GetFullPath(nativeCompilerBasePath) };

            logw.WriteLine("IL2C: Preparing for building native binary: \"{0}\" ...", sourceCodeDirFullPath);

            var outputNativeDirPath = Path.GetDirectoryName(outputNativeFullPath);
            if (!Directory.Exists(outputNativeDirPath))
            {
                try
                {
                    Directory.CreateDirectory(outputNativeDirPath);
                }
                catch
                {
                }
            }

            var sourceCodePaths =
                Directory.EnumerateFiles(
                    sourceCodeDirFullPath,
                    enableBundler ?
                        $"*_bundle.{(enableCpp ? "cpp" : "c")}" :
                        $"*.{(enableCpp ? "cpp" : "c")}",
                    SearchOption.AllDirectories).
                Select(p => Path.Combine(sourceCodeDirFullPath, p));
            var includeDir = Path.Combine(sourceCodeDirFullPath, "include");
            var srcDir = Path.Combine(sourceCodeDirFullPath, "src");

            logw.WriteLine("IL2C: Building native binary: \"{0}\" ...", outputNativeFullPath);

            var (exitCode, log) = await Utilities.ExecuteAsync(
                sourceCodeDirFullPath,
                "build",
                nativeCompilerBasePaths,
                nativeCompiler,
                new[]
                {
                    nativeCompilerFlags,
                    isLibrary ? "-c" : "",
                    $"-I{includeDir}",
                    $"-I{srcDir}",
                }.
                Concat(includeDirs.Select(p => $"-I{p}")).
                Concat(new[]
                {
                    "-o", outputNativeFullPath,
                }).
                Concat(sourceCodePaths).
                Concat(libPaths).
                ToArray());

            if (exitCode != 0)
            {
                throw new Exception($"{Path.GetFileName(nativeCompiler)}: ExitCode={exitCode}: {log}");
            }

            logw.WriteLine("IL2C: Built native binary: \"{0}\" ...", outputNativeFullPath);
        }
    }
}
