////////////////////////////////////////////////////////////////////////////
//
// IL2C - A translator for ECMA-335 CIL/MSIL to C language.
// Copyright (c) Kouji Matsui (@kozy_kekyo, @kekyo@mastodon.cloud)
//
// Licensed under Apache-v2: https://opensource.org/licenses/Apache-2.0
//
////////////////////////////////////////////////////////////////////////////

using System;
using System.Collections.Generic;
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

        ////////////////////////////////////////////////////////////////////////////

        private static void SafeCreateDirectory(string path, bool clean)
        {
            if (clean)
            {
                try
                {
                    Directory.Delete(path, true);
                }
                catch
                {
                }
            }
            if (!Directory.Exists(path))
            {
                try
                {
                    Directory.CreateDirectory(path);
                }
                catch
                {
                }
            }
        }

        private readonly struct CompilationResult
        {
            public readonly int ExitCode;
            public readonly string Logs;
            public readonly string OutputPath;

            public CompilationResult(int exitCode, string logs, string outputPath)
            {
                this.ExitCode = exitCode;
                this.Logs = logs;
                this.OutputPath = outputPath;
            }

            public override string ToString() =>
                $"{this.ExitCode}: {this.Logs}";
        }

        private static async Task<CompilationResult> ExecuteCompilerAsync(
            string sourceCodePath,
            string outputStagingDirPath,
            string[] nativeCompilerBasePaths,
            string nativeCompiler,
            string nativeCompilerFlags,
            string includeDir,
            string sourceDir,
            string[] additionalIncludeDirs)
        {
            var sourceCodeFileName = Path.GetFileNameWithoutExtension(sourceCodePath);
            var outputBasePath = Path.Combine(
                outputStagingDirPath,
                Path.GetDirectoryName(sourceCodePath.Substring(sourceDir.Length + 1)));
            var outputPath = Path.Combine(
                outputBasePath,
                sourceCodeFileName + ".o");
            var buildScriptPath = Path.Combine(
                outputBasePath,
                $"build_{sourceCodeFileName}");

            SafeCreateDirectory(outputBasePath, false);

            var result = await Utilities.ExecuteAsync(
                sourceDir,
                buildScriptPath,
                nativeCompilerBasePaths,
                nativeCompiler,
                new[]
                {
                        nativeCompilerFlags,
                        "-c",
                        $"-I{includeDir}",
                        $"-I{sourceDir}",
                }.
                Concat(additionalIncludeDirs.Select(p => $"-I{p}")).
                Concat(new[]
                {
                        "-o", outputPath,
                        sourceCodePath,
                }).
                ToArray()).
                ConfigureAwait(false);

            return new CompilationResult(result.ExitCode, result.Logs, outputPath);
        }

        private static Task<ExecuteResult> ExecuteArchiverAsync(
            string[] objectPaths,
            string outputPath,
            string[] nativeCompilerBasePaths,
            string nativeArchiver)
        {
            var outputBasePath = Path.GetDirectoryName(outputPath);
            var buildScriptPath = Path.Combine(
                outputBasePath,
                $"build_{Path.GetFileNameWithoutExtension(outputPath)}");

            return Utilities.ExecuteAsync(
                outputBasePath,
                buildScriptPath,
                nativeCompilerBasePaths,
                nativeArchiver,
                new[]
                {
                        "rcs",
                        outputPath,
                }.
                Concat(objectPaths).
                ToArray());
        }

        public static async Task CompileToNativeAsync(
            TextWriter logw,
            string outputNativePath,
            string nativeCompiler,
            string nativeCompilerFlags,
            string nativeArchiver,
            string[] additionalIncludeDirs,
            string[] libPaths,
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
            SafeCreateDirectory(outputNativeDirPath, false);

            var outputStagingDirPath = Path.Combine(outputNativeDirPath, "stage");
            SafeCreateDirectory(outputStagingDirPath, true);

            var includeDir = Path.Combine(sourceCodeDirFullPath, "include");
            var sourceDir = Path.Combine(sourceCodeDirFullPath, "src");
            var sourceCodePaths =
                Directory.EnumerateFiles(
                    sourceDir, "*.*", SearchOption.AllDirectories).
                Where(p =>
                    Path.GetExtension(p) switch { ".c" => true, ".cpp" => true, _ => false, } &&
                    !Path.GetFileNameWithoutExtension(p).EndsWith("_bundle")).
                Select(p => Path.Combine(sourceCodeDirFullPath, p));

            logw.WriteLine("IL2C: Building native binary: \"{0}\" ...", outputNativeFullPath);

#if DEBUG
            var crs = new List<CompilationResult>();
            foreach (var sourceCodePath in sourceCodePaths)
            {
                var r = await ExecuteCompilerAsync(
                    sourceCodePath,
                    outputStagingDirPath,
                    nativeCompilerBasePaths,
                    nativeCompiler,
                    nativeCompilerFlags,
                    includeDir,
                    sourceDir,
                    additionalIncludeDirs).
                    ConfigureAwait(false);
                crs.Add(r);
            }
#else
            var crs = await Task.WhenAll(
                sourceCodePaths.Select(sourceCodePath =>
                    ExecuteCompilerAsync(
                        sourceCodePath,
                        outputStagingDirPath,
                        nativeCompilerBasePaths,
                        nativeCompiler,
                        nativeCompilerFlags,
                        includeDir,
                        sourceDir,
                        additionalIncludeDirs))).
                ConfigureAwait(false);
#endif

            var cr = crs.FirstOrDefault(r => r.ExitCode != 0);
            if (cr.ExitCode != 0)
            {
                throw new Exception($"{Path.GetFileName(nativeCompiler)}: {cr}");
            }

            if (isLibrary)
            {
                var ar = await ExecuteArchiverAsync(
                    crs.Select(cr => cr.OutputPath).ToArray(),
                    outputNativeFullPath,
                    nativeCompilerBasePaths,
                    nativeArchiver).
                    ConfigureAwait(false);

                if (ar.ExitCode != 0)
                {
                    throw new Exception($"{Path.GetFileName(nativeArchiver)}: {ar}");
                }
            }
            else
            {
                // TODO:
            }

            logw.WriteLine("IL2C: Built native binary: \"{0}\" ...", outputNativeFullPath);
        }
    }
}
