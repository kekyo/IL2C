////////////////////////////////////////////////////////////////////////////
//
// IL2C - A translator for ECMA-335 CIL/MSIL to C language.
// Copyright (c) Kouji Matsui (@kozy_kekyo, @kekyo@mastodon.cloud)
//
// Licensed under Apache-v2: https://opensource.org/licenses/Apache-2.0
//
////////////////////////////////////////////////////////////////////////////

#nullable enable

using System;
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
        public readonly string NativeLinkingFlags;
        public readonly string NativeArchiver;
        public readonly string[] AdditionalIncludeDirs;
        public readonly string[] LibraryPaths;
        public readonly string? MainTemplatePath;

        public ToolchainOptions(
            string nativeCompiler,
            string nativeCompilerFlags,
            string nativeLinkingFlags,
            string nativeArchiver,
            string[] additionalIncludeDirs,
            string[] libraryPaths,
            string? mainTemplatePath)
        {
            this.NativeCompiler = nativeCompiler;
            this.NativeCompilerFlags = nativeCompilerFlags;
            this.NativeLinkingFlags = nativeLinkingFlags;
            this.NativeArchiver = nativeArchiver;
            this.AdditionalIncludeDirs = additionalIncludeDirs;
            this.LibraryPaths = libraryPaths;
            this.MainTemplatePath = mainTemplatePath;
        }
    }

    public sealed class ArtifactPathOptions
    {
        public readonly string OutputNativeArchiveFileName;
        public readonly string? OutputNativeExecutableFileName;

        public ArtifactPathOptions(
            string outputNativeArchiveFileName,
            string? outputNativeExecutableFileName)
        {
            this.OutputNativeExecutableFileName = outputNativeExecutableFileName;
            this.OutputNativeArchiveFileName = outputNativeArchiveFileName;
        }
    }

    public static class SimpleDriver
    {
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

        ////////////////////////////////////////////////////////////////////////////

        public static Task<IMethodInformation> TranslateAsync(
            ILogger logger,
            CodeTextStorage storage,
            TranslationOptions options,
            string assemblyPath)
        {
            logger.Information($"Preparing assembly: \"{Path.GetFullPath(assemblyPath)}\" ...");

            SafeCreateDirectory(storage.BasePath, true);

            var translateContext = new TranslateContext(
                assemblyPath, options.ReadSymbols, options.TargetPlatform);
            var preparedFunctions = AssemblyPreparer.Prepare(
                translateContext);

            logger.Information($"Translating assembly: \"{Path.GetFullPath(assemblyPath)}\" ...");

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

            logger.Information($"Translated assembly: Stored into \"{Path.GetFullPath(storage.BasePath)}\"");

            // TODO: Makes asynchronously operation.
            return Task.FromResult(translateContext.MetadataContext.EntryPoint);
        }

        public static Task<IMethodInformation> TranslateAsync(
            ILogger logger,
            string outputBaseDirPath,
            bool produceCpp,
            TranslationOptions options,
            string assemblyPath)
        {
            var storage = new CodeTextStorage(
                logger,
                outputBaseDirPath,
                produceCpp,
                "    ");

            return TranslateAsync(
                logger,
                storage,
                options,
                assemblyPath);
        }

        ////////////////////////////////////////////////////////////////////////////

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

        private static string ToRelativePath(string baseDirPath, string path)
        {
            var length = baseDirPath.EndsWith(Path.DirectorySeparatorChar.ToString()) ?
                baseDirPath.Length : baseDirPath.Length + 1;
            var candidate = path.StartsWith(baseDirPath) ?
                path.Substring(length) : path;
            return candidate.Length >= 1 ? candidate : ".";
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
            string? libraryPath,
            string[] additionalIncludeDirs,
            string[] additionalLibraryPaths)
        {
            var sourceCodeFileName = Path.GetFileNameWithoutExtension(sourceCodePath);
            var outputBasePath = Path.Combine(
                outputStagingDirPath,
                Path.GetDirectoryName(sourceCodePath.Substring(sourceDir.Length + 1))!);
            var outputPath = Path.Combine(
                outputBasePath,
                outputFileName);
            var buildScriptPath = Path.Combine(
                outputBasePath,
                $"build_{sourceCodeFileName}");

            SafeCreateDirectory(outputBasePath, false);

            var result = await Utilities.ExecuteAsync(
                outputBasePath,
                buildScriptPath,
                nativeToolchainBasePaths,
                nativeCompiler,
                new[]
                {
                    nativeCompilerFlags,
                    isCompileOnly ? "-c" : "",
                    $"-I{ToRelativePath(outputBasePath, includeDir)}",
                    $"-I{ToRelativePath(outputBasePath, sourceDir)}",
                }.
                Concat(additionalIncludeDirs.Select(p => $"-I{ToRelativePath(outputBasePath, p)}")).
                Concat(new[]
                {
                    "-o", ToRelativePath(outputBasePath, outputPath),
                    ToRelativePath(outputBasePath, sourceCodePath),
                }).
                Concat(libraryPath is { } lp ? new[] { ToRelativePath(outputBasePath, lp) } : new string[0]).
                Concat(additionalLibraryPaths.Select(p => ToRelativePath(outputBasePath, p))).
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
            var outputBasePath = Path.GetDirectoryName(outputPath)!;
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
                    ToRelativePath(outputBasePath, outputPath),
                }.
                Concat(objectPaths.Select(p => ToRelativePath(outputBasePath, p))).
                ToArray());
        }

        public static async Task CompileToNativeAsync(
            ILogger logger,
            ToolchainOptions toolchainOptions,
            ArtifactPathOptions artifactPathOptions,
            IMethodInformation? mainEntryPoint,
            string sourceCodeDirPath,
            string outputDirPath)
        {
            var sourceCodeDirFullPath = Path.GetFullPath(sourceCodeDirPath);
            var outputDirFullPath = Path.GetFullPath(outputDirPath);
            var outputNativeArchiveFullPath = Path.GetFullPath(
                Path.Combine(
                    outputDirFullPath,
                    artifactPathOptions.OutputNativeArchiveFileName));
            var nativeToolchainBasePath = Path.GetDirectoryName(toolchainOptions.NativeCompiler);
            var nativeToolchainBasePaths =
                string.IsNullOrWhiteSpace(nativeToolchainBasePath) ?
                    new string[0] :
                    new[] { Path.GetFullPath(nativeToolchainBasePath) };

            logger.Information($"Preparing for compilation native binary: \"{sourceCodeDirFullPath}\" ...");

            SafeCreateDirectory(outputDirFullPath, outputDirFullPath != sourceCodeDirFullPath);

            var outputStagingBaseDirPath = Path.Combine(outputDirFullPath, "obj");
            SafeCreateDirectory(outputStagingBaseDirPath, true);

            var includeDir = Path.Combine(sourceCodeDirFullPath, "include");
            var sourceDir = Path.Combine(sourceCodeDirFullPath, "src");
            var sourceCodePaths =
                Directory.EnumerateFiles(
                    sourceDir, "*.*", SearchOption.AllDirectories).
                Where(p =>
                    Path.GetExtension(p) switch { ".c" => true, ".cpp" => true, _ => false, } &&
                    !Path.GetFileNameWithoutExtension(p).EndsWith("_bundle")).  // Except bundler
                Select(p => Path.Combine(sourceCodeDirFullPath, p)).
                ToArray();

            /////////////////////////////////////////////////////////////
            // Compiling step:

            logger.Information($"Compiling native binary into \"{outputNativeArchiveFullPath}\" ...");

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

            if (artifactPathOptions.OutputNativeExecutableFileName is { } &&
                mainEntryPoint is { } &&
                toolchainOptions.MainTemplatePath is { })
            {
                var outputNativeExecutableFullPath = Path.GetFullPath(
                    Path.Combine(
                        outputDirFullPath,
                        artifactPathOptions.OutputNativeExecutableFileName));

                logger.Information($"Linking native binary \"{outputNativeExecutableFullPath}\"");

                var mainSourceCodePath = Path.Combine(
                    outputDirFullPath,
                    Path.GetFileNameWithoutExtension(outputNativeExecutableFullPath) + ".c");

                var mainBody = new StringBuilder(
                    await Utilities.ReadAllTextAsync(toolchainOptions.MainTemplatePath, new UTF8Encoding(false, true)).
                        ConfigureAwait(false));

                mainBody.Replace("{headerName}", mainEntryPoint.DeclaringModule.DeclaringAssembly.Name + ".h");
                mainBody.Replace("{mainIsVoid}", mainEntryPoint.ReturnType.IsVoidType ? "1" : "0");
                mainBody.Replace("{mainSymbol}", mainEntryPoint.CLanguageFunctionFullName);

                await Utilities.WriteAllTextAsync(mainSourceCodePath, mainBody.ToString(), new UTF8Encoding(false, true)).
                        ConfigureAwait(false);

                var crf = await ExecuteCompilerAsync(
                    mainSourceCodePath,
                    outputDirFullPath,
                    outputNativeExecutableFullPath,
                    nativeToolchainBasePaths,
                    toolchainOptions.NativeCompiler,
                    toolchainOptions.NativeCompilerFlags + " " + toolchainOptions.NativeLinkingFlags,
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

                logger.Information($"Built native binary: \"{outputNativeExecutableFullPath}\" ...");
            }
        }
    }
}
