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
using System.Diagnostics;
using System.Linq;
using System.Runtime.InteropServices;
using System.Threading.Tasks;

using Mono.Options;

using IL2C.Drivers;
using IL2C.Metadata;

#pragma warning disable CS0219

namespace IL2C
{
    // warning CS0649: Field is never assigned to, and will always have its default value `null'
#pragma warning disable 0649

    public static class Program
    {
        private enum DrivingModes
        {
            Translation = 1,
            Compilation = 2,
            Both = 3,
        }

        public static async Task<int> Main(string[] args)
        {
            try
            {
                var drivingMode = DrivingModes.Both;
                var debugInformationOptions = DebugInformationOptions.None;
                var produceCpp = false;
                var enableBundler = false;
                var targetPlatform = TargetPlatforms.Generic;
                var refDirs = new string[0];
                var outputNativeDirPath = default(string);
                var nativeCompiler = default(string);
                var nativeCompilerFlags = "";
                var nativeLinkingFlags = "";
                var nativeArchiver = default(string);
                var outputNativeExecutableFileName = default(string);
                var outputNativeArchiveFileName = default(string);
                var additionalIncludeDirs = new string[0];
                var libraryPaths = new string[0];
                var mainTemplatePath = default(string);
                var enableParallelism = false;
                var logLevel = LogLevels.Information;
                var logtfm = default(string);
                var launchDebugger = false;
                var help = false;

                var options = new OptionSet()
                {
                    { "mode=", "Driving mode [both|translation|compilation]", v => drivingMode = Enum.TryParse<DrivingModes>(v, true, out var dm) ? dm : DrivingModes.Both },
                    { "debug=", "Emit debug informations [none|commentonly|full]", v => debugInformationOptions = Enum.TryParse<DebugInformationOptions>(v, true, out var t) ? t : DebugInformationOptions.None },
                    { "produceCpp=", "Produce C++ extension files (apply extension *.cpp instead *.c, body will not change)", v => produceCpp = bool.TryParse(v, out var pc) && pc },
                    { "bundler=", "Produce bundler source file", v => enableBundler = bool.TryParse(v, out var eb) && eb },
                    { "target=", "Target platform [generic|ue4]", v => targetPlatform = Enum.TryParse<TargetPlatforms>(v, true, out var tp) ? tp : TargetPlatforms.Generic },
                    { "refDirs=", "Reference assembly paths (semi-colon separated)", v => refDirs = v.Split(new[] { ';' }, StringSplitOptions.RemoveEmptyEntries) },
                    { "compiler=", "Native compiler driver file", v => nativeCompiler = v },
                    { "compilerFlags=", "Native compiler flags", v => nativeCompilerFlags = v },
                    { "linkingFlags=", "Native compiler linking flags", v => nativeLinkingFlags = v },
                    { "archiver=", "Native archiver file", v => nativeArchiver = v },
                    { "includeDirs=", "Compilation additional include directory path", v => additionalIncludeDirs = v.Split(new[] { ';' }, StringSplitOptions.RemoveEmptyEntries) },
                    { "libs=", "Compilation library path", v => libraryPaths = v.Split(new[] { ';' }, StringSplitOptions.RemoveEmptyEntries) },
                    { "outputNativeArchive=", "Output native archive file name", v => outputNativeArchiveFileName = v },
                    { "outputNativeExecutable=", "Output native executable file name", v => outputNativeExecutableFileName = v },
                    { "outputNativeDir=", "Output native binary directory path", v => outputNativeDirPath = v },
                    { "mainTemplate=", "Native main template path", v => mainTemplatePath = v },
                    { "enableParallel", "Enable parallelism", _ => enableParallelism = true },
                    { "logLevel=", "Log level [debug|trace|information|warning|error|silent]", v => logLevel = Enum.TryParse<LogLevels>(v, true, out var ll) ? ll : LogLevels.Information },
                    { "logtfm=", "Log header tfm", v => logtfm = v },
                    { "launchDebugger", "Launch debugger", _ => launchDebugger = true },
                    { "h|help", "Print this help", _ => help = true },
                };

                var extra = options.Parse(args);
                if (help || (extra.Count < 2))
                {
                    Console.Out.WriteLine($"IL2C.Build [{ThisAssembly.AssemblyVersion}]");
                    Console.Out.WriteLine("  A translator for ECMA-335 CIL/MSIL to C language.");
                    Console.Out.WriteLine("  Copyright (c) Kouji Matsui.");
                    Console.Out.WriteLine("usage: il2c.exe [options] <output_path> <assembly_path>");
                    options.WriteOptionDescriptions(Console.Out);
                }
                else
                {
                    var outputBaseDirPath = extra[0];
                    var inputPaths = extra.Skip(1);

                    using var logger = new TextWriterLogger(
                        logLevel, Console.Out, logtfm);

                    logger.Information($"Started.");

                    if (launchDebugger)
                    {
                        Debugger.Launch();
                    }

                    // TODO: refs, trace

                    IMethodInformation? mainEntryPoint = null;
                    string inputCompilationDirPath;
                    if ((drivingMode & DrivingModes.Translation) == DrivingModes.Translation)
                    {
                        var translationOptions = new TranslationOptions(
                            refDirs, enableBundler,
                            targetPlatform, debugInformationOptions);

                        IList<IMethodInformation> entryPoints;
                        if (enableParallelism)
                        {
                            entryPoints = await Task.WhenAll(
                                inputPaths.Select(assemblyPath =>
                                    SimpleTranslator.TranslateAsync(
                                        logger,
                                        outputBaseDirPath,
                                        produceCpp,
                                        translationOptions,
                                        assemblyPath).AsTask())).
                                ConfigureAwait(false);
                        }
                        else
                        {
                            entryPoints = new List<IMethodInformation>();
                            foreach (var assemblyPath in inputPaths)
                            {
                                var r = await SimpleTranslator.TranslateAsync(
                                    logger,
                                    outputBaseDirPath,
                                    produceCpp,
                                    translationOptions,
                                    assemblyPath);
                                entryPoints.Add(r);
                            }
                        }

                        mainEntryPoint = entryPoints.FirstOrDefault();
                        inputCompilationDirPath = outputBaseDirPath;
                    }
                    else
                    {
                        inputCompilationDirPath = inputPaths.First();
                    }

                    if ((drivingMode & DrivingModes.Compilation) == DrivingModes.Compilation &&
                        !string.IsNullOrWhiteSpace(nativeCompiler) &&
                        !string.IsNullOrWhiteSpace(nativeArchiver) &&
                        !string.IsNullOrWhiteSpace(outputNativeArchiveFileName))
                    {
                        var toolchainOptions = new ToolchainOptions(
                            nativeCompiler!, nativeCompilerFlags, nativeLinkingFlags, nativeArchiver!,
                            additionalIncludeDirs, libraryPaths, mainTemplatePath,
                            enableParallelism);
                        var artifactPathOptions = new ArtifactPathOptions(
                            outputNativeArchiveFileName!, outputNativeExecutableFileName);

                        await NativeBinaryBuilder.CompileToNativeAsync(
                            logger,
                            toolchainOptions,
                            artifactPathOptions,
                            mainEntryPoint,
                            inputCompilationDirPath,
                            string.IsNullOrWhiteSpace(outputNativeDirPath) ?
                                inputCompilationDirPath : outputNativeDirPath!);
                    }
                }

                return 0;
            }
            catch (OptionException ex)
            {
                Console.Error.WriteLine(ex.Message);
                return Marshal.GetHRForException(ex);
            }
            catch (Exception ex)
            {
                Console.Error.WriteLine(ex);
                return Marshal.GetHRForException(ex);
            }
        }
    }
}
