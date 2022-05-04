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
            logw.Write("IL2C: Preparing assembly: \"{0}\" ...", Path.GetFullPath(assemblyPath));

            var translateContext = new TranslateContext(assemblyPath, readSymbols, targetPlatform);
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
            string outputDirPath,
            string assemblyName,
            string nativeCompiler,
            string nativeCompilerFlags,
            string[] includeDirs,
            string[] libPaths,
            bool enableCpp,
            bool enableBundler,
            string sourceCodeDirPath)
        {
            if (!Directory.Exists(outputDirPath))
            {
                try
                {
                    Directory.CreateDirectory(outputDirPath);
                }
                catch
                {
                }
            }

            var sourceCodeDirFullPath = Path.GetFullPath(sourceCodeDirPath);
            var nativeCompilerBasePath = Path.GetDirectoryName(nativeCompiler);
            var nativeCompilerBasePaths =
                string.IsNullOrWhiteSpace(nativeCompilerBasePath) ?
                    new string[0] :
                    new[] { Path.GetFullPath(nativeCompilerBasePath) };

            var outputFilePath = Path.GetFullPath(Path.Combine(
                outputDirPath,
                Environment.OSVersion.Platform == PlatformID.Win32NT ?
                    assemblyName + ".exe" :
                    assemblyName));
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

            var (exitCode, log) = await Utilities.ExecuteAsync(
                sourceCodeDirFullPath,
                "build",
                nativeCompilerBasePaths,
                nativeCompiler,
                new[]
                {
                    nativeCompilerFlags,
                    $"-I{includeDir}",
                    $"-I{srcDir}",
                }.
                Concat(includeDirs.Select(p => $"-I{p}")).
                Concat(new[]
                {
                    "-o", outputFilePath,
                }).
                Concat(sourceCodePaths).
                Concat(libPaths).
                ToArray());

            if (exitCode != 0)
            {
                throw new Exception($"{Path.GetFileName(nativeCompiler)}: ExitCode={exitCode}: {log}");
            }

            logw.WriteLine($"{Path.GetFileName(nativeCompiler)}: Built native binary: Path={outputFilePath}");
        }
    }
}
