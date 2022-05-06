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
using System.Linq;
using System.Runtime.InteropServices;
using System.Threading.Tasks;

using Mono.Options;

using IL2C.Metadata;

#pragma warning disable CS0219

namespace IL2C
{
    // warning CS0649: Field is never assigned to, and will always have its default value `null'
#pragma warning disable 0649

    public static class Program
    {
        public static async Task<int> Main(string[] args)
        {
            try
            {
                var debugInformationOptions = DebugInformationOptions.None;
                var readSymbols = true;
                var enableCpp = false;
                var enableBundler = false;
                var targetPlatform = TargetPlatforms.Generic;
                var refDirs = new string[0];
                var nativeCompiler = "";
                var nativeCompilerFlags = "";
                var nativeLinkingFlags = "";
                var nativeArchiver = "";
                var outputNativeExecutableFileName = "";
                var outputNativeArchiveFileName = "";
                var additionalIncludeDirs = new string[0];
                var libraryPaths = new string[0];
                var mainTemplatePath = "";
                var trace = false;
                var help = false;

                var options = new OptionSet()
                {
                    { "debug=", "Emit debug informations [none|commentonly|full]", v => debugInformationOptions = Enum.TryParse<DebugInformationOptions>(v, true, out var t) ? t : DebugInformationOptions.None },
                    { "readSymbol=", "Read symbol files [true|false]", v => readSymbols = bool.TryParse(v, out var rs) ? rs : true },
                    { "produceCpp=", "Produce C++ extension files (apply extension *.cpp instead *.c, body will not change)", v => enableCpp = bool.TryParse(v, out var ec) ? ec : false },
                    { "bundler=", "Produce bundler source file", _ => enableBundler = true },
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
                    { "mainTemplate=", "Native main template path", v => mainTemplatePath = v },
                    { "t", "Enable trace log", _ => trace = true },
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
                    var assemblyPaths = extra.Skip(1);

                    Console.Out.WriteLine($"IL2C.Build [{ThisAssembly.AssemblyVersion}] Started.");

                    // TODO: refs, trace
                    // TODO: Makes parallelism

                    var translationOptions = new TranslationOptions(
                        readSymbols, enableBundler, targetPlatform, debugInformationOptions);

#if DEBUG
                    var results = new List<IMethodInformation>();
                    foreach (var assemblyPath in assemblyPaths)
                    {
                        var r = await SimpleDriver.TranslateAsync(
                            Console.Out,
                            outputBaseDirPath,
                            enableCpp,
                            translationOptions,
                            assemblyPath);
                        results.Add(r);
                    }
#else
                    var results = await Task.WhenAll(
                        assemblyPaths.Select(assemblyPath =>
                            SimpleDriver.TranslateAsync(
                                Console.Out,
                                outputBaseDirPath,
                                enableCpp,
                                translationOptions,
                                assemblyPath))).
                        ConfigureAwait(false);
#endif
                    if (!string.IsNullOrWhiteSpace(nativeCompiler) &&
                        !string.IsNullOrWhiteSpace(nativeArchiver) &&
                        !string.IsNullOrWhiteSpace(outputNativeExecutableFileName) &&
                        !string.IsNullOrWhiteSpace(outputNativeArchiveFileName))
                    {
                        var toolchainOptions = new ToolchainOptions(
                            nativeCompiler, nativeCompilerFlags, nativeLinkingFlags, nativeArchiver,
                            additionalIncludeDirs, libraryPaths, mainTemplatePath);
                        var artifactPathOptions = new ArtifactPathOptions(
                            outputNativeArchiveFileName, outputNativeExecutableFileName);

                        await SimpleDriver.CompileToNativeAsync(
                            Console.Out,
                            toolchainOptions,
                            artifactPathOptions,
                            results.FirstOrDefault(),
                            outputBaseDirPath);
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
