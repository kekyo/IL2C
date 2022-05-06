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
using System.Text;
using System.Threading.Tasks;

using IL2C.Internal;
using IL2C.Metadata;

namespace IL2C
{
    public sealed class TranslationOptions
    {
        public readonly bool ReadSymbols;
        public readonly bool EnableBundler;
        public readonly TargetPlatforms TargetPlatform;
        public readonly DebugInformationOptions DebugInformationOption;

        public TranslationOptions(
            bool readSymbols,
            bool enableBundler,
            TargetPlatforms targetPlatform,
            DebugInformationOptions debugInformationOption)
        {
            this.ReadSymbols = readSymbols;
            this.EnableBundler = enableBundler;
            this.TargetPlatform = targetPlatform;
            this.DebugInformationOption = debugInformationOption;
        }
    }

    public sealed class ToolchainOptions
    {
        public readonly string NativeCompiler;
        public readonly string NativeCompilerFlags;
        public readonly string NativeArchiver;
        public readonly string[] AdditionalIncludeDirs;
        public readonly string[] LibraryPaths;
        public readonly string MainTemplatePath;

        public ToolchainOptions(
            string nativeCompiler,
            string nativeCompilerFlags,
            string nativeArchiver,
            string[] additionalIncludeDirs,
            string[] libraryPaths,
            string mainTemplatePath)
        {
            this.NativeCompiler = nativeCompiler;
            this.NativeCompilerFlags = nativeCompilerFlags;
            this.NativeArchiver = nativeArchiver;
            this.AdditionalIncludeDirs = additionalIncludeDirs;
            this.LibraryPaths = libraryPaths;
            this.MainTemplatePath = mainTemplatePath;
        }
    }

    public sealed class ArtifactPathOptions
    {
        public readonly string OutputNativeArchiveFileName;
        public readonly string OutputNativeExecutableFileName;

        public ArtifactPathOptions(
            string outputNativeArchiveFileName,
            string outputNativeExecutableFileName)
        {
            this.OutputNativeExecutableFileName = outputNativeExecutableFileName;
            this.OutputNativeArchiveFileName = outputNativeArchiveFileName;
        }
    }

    public static class SimpleDriver
    {
        public static Task<IMethodInformation> TranslateAsync(
            TextWriter logw,
            CodeTextStorage storage,
            TranslationOptions options,
            string assemblyPath)
        {
            logw.WriteLine("IL2C: Preparing assembly: \"{0}\" ...", Path.GetFullPath(assemblyPath));

            var translateContext = new TranslateContext(
                assemblyPath, options.ReadSymbols, options.TargetPlatform);
            var preparedFunctions = AssemblyPreparer.Prepare(
                translateContext);

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
                    options.EnableBundler,
                    options.DebugInformationOption);
            }

            logw.WriteLine("IL2C: Translated assembly: Stored into \"{0}\"", Path.GetFullPath(storage.BasePath));

            // TODO: Makes asynchronously operation.
            return Task.FromResult(translateContext.MetadataContext.EntryPoint);
        }

        public static Task<IMethodInformation> TranslateAsync(
            TextWriter logw,
            string outputBaseDirPath,
            bool enableCpp,
            TranslationOptions options,
            string assemblyPath)
        {
            var storage = new CodeTextStorage(
                logw,
                outputBaseDirPath,
                enableCpp,
                "    ");

            return TranslateAsync(
                logw,
                storage,
                options,
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
            string outputFileName,
            string[] nativeToolchainBasePaths,
            string nativeCompiler,
            string nativeCompilerFlags,
            string includeDir,
            string sourceDir,
            bool isCompileOnly,
            string libraryPath,
            string[] additionalIncludeDirs,
            string[] additionalLibraryPaths)
        {
            var sourceCodeFileName = Path.GetFileNameWithoutExtension(sourceCodePath);
            var outputBasePath = Path.Combine(
                outputStagingDirPath,
                Path.GetDirectoryName(sourceCodePath.Substring(sourceDir.Length + 1)));
            var outputPath = Path.Combine(
                outputBasePath,
                outputFileName);
            var buildScriptPath = Path.Combine(
                outputBasePath,
                $"build_{sourceCodeFileName}");

            SafeCreateDirectory(outputBasePath, false);

            var result = await Utilities.ExecuteAsync(
                sourceDir,
                buildScriptPath,
                nativeToolchainBasePaths,
                nativeCompiler,
                new[]
                {
                    nativeCompilerFlags,
                    isCompileOnly ? "-c" : "",
                    $"-I{includeDir}",
                    $"-I{sourceDir}",
                }.
                Concat(additionalIncludeDirs.Select(p => $"-I{p}")).
                Concat(new[]
                {
                    "-o", outputPath,
                    sourceCodePath,
                }).
                Concat(libraryPath is { } lp ? new[] { lp } : new string[0]).
                Concat(additionalLibraryPaths).
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
            ToolchainOptions toolchainOptions,
            ArtifactPathOptions artifactPathOptions,
            IMethodInformation mainEntryPoint,
            string baseDirPath)
        {
            var baseDirFullPath = Path.GetFullPath(baseDirPath);
            var outputNativeArchiveFullPath = Path.GetFullPath(
                Path.Combine(
                    baseDirFullPath,
                    artifactPathOptions.OutputNativeArchiveFileName));
            var outputNativeExecutableFullPath = Path.GetFullPath(
                Path.Combine(
                    baseDirFullPath,
                    artifactPathOptions.OutputNativeExecutableFileName));
            var nativeToolchainBasePath = Path.GetDirectoryName(toolchainOptions.NativeCompiler);
            var nativeToolchainBasePaths =
                string.IsNullOrWhiteSpace(nativeToolchainBasePath) ?
                    new string[0] :
                    new[] { Path.GetFullPath(nativeToolchainBasePath) };

            logw.WriteLine("IL2C: Preparing for building native binary: \"{0}\" ...", baseDirFullPath);

            SafeCreateDirectory(baseDirPath, false);

            var outputStagingBaseDirPath = Path.Combine(baseDirPath, "obj");
            SafeCreateDirectory(outputStagingBaseDirPath, true);

            var includeDir = Path.Combine(baseDirFullPath, "include");
            var sourceDir = Path.Combine(baseDirFullPath, "src");
            var sourceCodePaths =
                Directory.EnumerateFiles(
                    sourceDir, "*.*", SearchOption.AllDirectories).
                Where(p =>
                    Path.GetExtension(p) switch { ".c" => true, ".cpp" => true, _ => false, } &&
                    !Path.GetFileNameWithoutExtension(p).EndsWith("_bundle")).  // Except bundler
                Select(p => Path.Combine(baseDirFullPath, p)).
                ToArray();

            /////////////////////////////////////////////////////////////
            // Compiling step:

            logw.WriteLine("IL2C: Compiling native binary into \"{0}\" ...", outputNativeArchiveFullPath);

            // Compile in small pieces:
            //   Because LTO (LTCG) is not always enable, it is better to subdivide object files
            //   to reduce the amount of code when linking.
#if DEBUG
            var crs = new List<CompilationResult>();
            foreach (var sourceCodePath in sourceCodePaths)
            {
                var r = await ExecuteCompilerAsync(
                    sourceCodePath,
                    outputStagingBaseDirPath,
                    Path.GetFileNameWithoutExtension(sourceCodePath) + ".o",
                    nativeToolchainBasePaths,
                    toolchainOptions.NativeCompiler,
                    toolchainOptions.NativeCompilerFlags,
                    includeDir,
                    sourceDir,
                    true,
                    null,
                    toolchainOptions.AdditionalIncludeDirs,
                    new string[0]).
                    ConfigureAwait(false);
                crs.Add(r);
            }
#else
            var crs = await Task.WhenAll(
                sourceCodePaths.
                Select(sourceCodePath => ExecuteCompilerAsync(
                    sourceCodePath,
                    outputStagingBaseDirPath,
                    Path.GetFileNameWithoutExtension(sourceCodePath) + ".o",
                    nativeToolchainBasePaths,
                    toolchainOptions.NativeCompiler,
                    toolchainOptions.NativeCompilerFlags,
                    includeDir,
                    sourceDir,
                    true,
                    null,
                    toolchainOptions.AdditionalIncludeDirs,
                    new string[0]))).
                ConfigureAwait(false);
#endif
            var cr = crs.FirstOrDefault(r => r.ExitCode != 0);
            if (cr.ExitCode != 0)
            {
                throw new Exception($"{Path.GetFileName(toolchainOptions.NativeCompiler)}: {cr}");
            }

            var ar = await ExecuteArchiverAsync(
                crs.Select(cr => cr.OutputPath).ToArray(),
                outputNativeArchiveFullPath,
                nativeToolchainBasePaths,
                toolchainOptions.NativeArchiver).
                ConfigureAwait(false);

            if (ar.ExitCode != 0)
            {
                throw new Exception($"{Path.GetFileName(toolchainOptions.NativeArchiver)}: {ar}");
            }

            /////////////////////////////////////////////////////////////
            // Linking step:

            if (mainEntryPoint is { } && toolchainOptions.MainTemplatePath is { })
            {
                logw.WriteLine("IL2C: Linking native binary \"{0}\" ...", outputNativeExecutableFullPath);

                var mainSourceCodePath = Path.Combine(
                    baseDirPath,
                    Path.GetFileNameWithoutExtension(outputNativeExecutableFullPath) + ".c");

#if NETSTANDARD2_1_OR_GREATER || NETCOREAPP2_0_OR_GREATER
                var mainBody = new StringBuilder(
                    await File.ReadAllTextAsync(toolchainOptions.MainTemplatePath).
                        ConfigureAwait(false));
#else
                var mainBody = new StringBuilder(
                    File.ReadAllText(toolchainOptions.MainTemplatePath));
#endif
                mainBody.Replace("{headerName}", mainEntryPoint.DeclaringModule.DeclaringAssembly.Name + ".h");
                mainBody.Replace("{mainIsVoid}", mainEntryPoint.ReturnType.IsVoidType ? "1" : "0");
                mainBody.Replace("{mainSymbol}", mainEntryPoint.CLanguageFunctionFullName);

#if NETSTANDARD2_1_OR_GREATER || NETCOREAPP2_0_OR_GREATER
                await File.WriteAllTextAsync(mainSourceCodePath, mainBody.ToString()).
                        ConfigureAwait(false);
#else
                File.WriteAllText(mainSourceCodePath, mainBody.ToString());
#endif

                var crf = await ExecuteCompilerAsync(
                    mainSourceCodePath,
                    baseDirPath,
                    outputNativeExecutableFullPath,
                    nativeToolchainBasePaths,
                    toolchainOptions.NativeCompiler,
                    toolchainOptions.NativeCompilerFlags,
                    includeDir,
                    sourceDir,
                    false,
                    outputNativeArchiveFullPath,
                    toolchainOptions.AdditionalIncludeDirs,
                    toolchainOptions.LibraryPaths).
                    ConfigureAwait(false);

                if (crf.ExitCode != 0)
                {
                    throw new Exception($"{Path.GetFileName(toolchainOptions.NativeCompiler)}: {crf}");
                }

                logw.WriteLine("IL2C: Built native binary: \"{0}\" ...", outputNativeExecutableFullPath);
            }
        }
    }
}
