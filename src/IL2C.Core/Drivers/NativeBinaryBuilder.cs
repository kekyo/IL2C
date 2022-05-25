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
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using IL2C.Internal;
using IL2C.Metadata;

namespace IL2C.Drivers
{
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

    public static class NativeBinaryBuilder
    {
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
            string? libraryPath,
            string[] additionalIncludeDirs,
            string[] additionalLibraryPaths)
        {
            var sourceCodeFileName = Path.GetFileNameWithoutExtension(sourceCodePath);
            var outputBasePath = Path.Combine(
                outputStagingDirPath,
                IOAccessor.GetDirectoryPath(sourceCodePath.Substring(sourceDir.Length + 1)));
            var outputPath = Path.Combine(
                outputBasePath,
                outputFileName);
            var buildScriptPath = Path.Combine(
                outputBasePath,
                $"build_{sourceCodeFileName}");

            await IOAccessor.SafeCreateDirectoryAsync(
                outputBasePath, false).
                ConfigureAwait(false);

            var result = await IOAccessor.ExecuteAsync(
                outputBasePath,
                buildScriptPath,
                nativeToolchainBasePaths,
                nativeCompiler,
                new[]
                {
                    nativeCompilerFlags,
                    isCompileOnly ? "-c" : "",
                    $"-I{IOAccessor.ToRelativePath(outputBasePath, includeDir)}",
                    $"-I{IOAccessor.ToRelativePath(outputBasePath, sourceDir)}",
                }.
                Concat(additionalIncludeDirs.Select(p => $"-I{IOAccessor.ToRelativePath(outputBasePath, p)}")).
                Concat(new[]
                {
                    "-o", IOAccessor.ToRelativePath(outputBasePath, outputPath),
                    IOAccessor.ToRelativePath(outputBasePath, sourceCodePath),
                }).
                Concat(libraryPath is { } lp ? new[] { IOAccessor.ToRelativePath(outputBasePath, lp) } : new string[0]).
                Concat(additionalLibraryPaths.Select(p => IOAccessor.ToRelativePath(outputBasePath, p))).
                ToArray()).
                ConfigureAwait(false);

            return new CompilationResult(result.ExitCode, result.Logs, outputPath);
        }

        private static ValueTask<ExecuteResult> ExecuteArchiverAsync(
            string[] objectPaths,
            string outputPath,
            string[] nativeCompilerBasePaths,
            string nativeArchiver)
        {
            var outputBasePath = IOAccessor.GetDirectoryPath(outputPath);
            var buildScriptPath = Path.Combine(
                outputBasePath,
                $"build_{Path.GetFileNameWithoutExtension(outputPath)}");

            return IOAccessor.ExecuteAsync(
                outputBasePath,
                buildScriptPath,
                nativeCompilerBasePaths,
                nativeArchiver,
                new[]
                {
                    "rcs",
                    IOAccessor.ToRelativePath(outputBasePath, outputPath),
                }.
                Concat(objectPaths.Select(p => IOAccessor.ToRelativePath(outputBasePath, p))).
                ToArray());
        }

        public static async ValueTask CompileToNativeAsync(
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
            var nativeToolchainBasePath = IOAccessor.GetDirectoryPath(
                toolchainOptions.NativeCompiler);
            var nativeToolchainBasePaths =
                string.IsNullOrWhiteSpace(nativeToolchainBasePath) ?
                    new string[0] :
                    new[] { Path.GetFullPath(nativeToolchainBasePath) };

            logger.Information($"Preparing for compilation native binary: {sourceCodeDirFullPath}");

            await IOAccessor.SafeCreateDirectoryAsync(
                outputDirFullPath, outputDirFullPath != sourceCodeDirFullPath).
                ConfigureAwait(false);

            var outputStagingBaseDirPath = Path.Combine(outputDirFullPath, "obj");
            await IOAccessor.SafeCreateDirectoryAsync(
                outputStagingBaseDirPath, true).
                ConfigureAwait(false);

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

            logger.Information($"Compiling native binary into: {outputNativeArchiveFullPath}");

            // Compile in small pieces:
            //   Because LTO (LTCG) is not always enable, it is better to subdivide object files
            //   to reduce the amount of code when linking.
#if DEBUG
            var crs = new List<CompilationResult>();
            foreach (var sourceCodePath in sourceCodePaths)
            {
                logger.Trace($"Compiling source code: {sourceCodePath}");
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
                Select(sourceCodePath =>
                {
                    logger.Trace($"Compiling source code: \"{sourceCodePath}\" ...");
                    return ExecuteCompilerAsync(
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
                        new string[0]);
                })).
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

                logger.Information($"Linking native binary: {outputNativeExecutableFullPath}");

                var mainSourceCodePath = Path.Combine(
                    outputDirFullPath,
                    Path.GetFileNameWithoutExtension(outputNativeExecutableFullPath) + ".c");

                var mainBody = new StringBuilder(
                    await IOAccessor.ReadAllTextAsync(toolchainOptions.MainTemplatePath, new UTF8Encoding(false, true)).
                        ConfigureAwait(false));

                mainBody.Replace("{headerName}", mainEntryPoint.DeclaringModule.DeclaringAssembly.Name + ".h");
                mainBody.Replace("{mainIsVoid}", mainEntryPoint.ReturnType.IsVoidType ? "1" : "0");
                mainBody.Replace("{mainSymbol}", mainEntryPoint.CLanguageFunctionFullName);

                await IOAccessor.WriteAllTextAsync(mainSourceCodePath, mainBody.ToString(), new UTF8Encoding(false, true)).
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

                logger.Information($"Built native binary: {outputNativeExecutableFullPath}");
            }
        }
    }
}
