////////////////////////////////////////////////////////////////////////////
//
// IL2C - A translator for ECMA-335 CIL/MSIL to C language.
// Copyright (c) Kouji Matsui (@kozy_kekyo, @kekyo@mastodon.cloud)
//
// Licensed under Apache-v2: https://opensource.org/licenses/Apache-2.0
//
////////////////////////////////////////////////////////////////////////////

using System;
using System.Linq;
using System.Runtime.InteropServices;

using Mono.Options;

namespace IL2C
{
// warning CS0649: Field is never assigned to, and will always have its default value `null'
#pragma warning disable 0649

    public static class Program
    {
        public static int Main(string[] args)
        {
            try
            {
                var debugInformationOptions = DebugInformationOptions.None;
                var readSymbols = true;
                var enableCpp = false;
                var enableBundler = false;
                var targetPlatform = TargetPlatforms.Generic;
                var refs = new string[0];
                var help = false;

                var options = new OptionSet()
                {
                    { "debug=", "Emit debug informations [none|commentonly|full]", v => debugInformationOptions = Enum.TryParse<DebugInformationOptions>(v, true, out var t) ? t : DebugInformationOptions.None },
                    { "readSymbol=", "Read symbol files [true|false]", v => readSymbols = bool.TryParse(v, out var rs) ? rs : true },
                    { "cpp=", "Produce C++ extension files (apply extension *.cpp instead *.c, body will not change)", v => enableCpp = bool.TryParse(v, out var ec) ? ec : false },
                    { "bundler=", "Produce bundler source file", _ => enableBundler = true },
                    { "target=", "Target platform [generic|ue4]", v => targetPlatform = Enum.TryParse<TargetPlatforms>(v, true, out var t) ? t : TargetPlatforms.Generic },
                    { "refs=", "Reference assembly paths (semi-colon separated)", v => refs = v.Split(new[] { ';' }, StringSplitOptions.RemoveEmptyEntries) },
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
                    var outputPath = extra[0];
                    var assemblyPaths = extra.Skip(1);

                    // TODO: refs

                    SimpleDriver.TranslateAll(
                        Console.Out,
                        outputPath,
                        readSymbols,
                        enableCpp,
                        enableBundler,
                        targetPlatform,
                        debugInformationOptions,
                        assemblyPaths);
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
