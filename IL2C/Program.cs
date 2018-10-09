using System;
using System.ComponentModel.DataAnnotations;
using System.Runtime.InteropServices;

namespace IL2C
{
// warning CS0649: Field is never assigned to, and will always have its default value `null'
#pragma warning disable 0649

    internal struct IL2COption
    {
        [Option("Produce C++ files (apply extension *.cpp instead *.c, body will not changed)")]
        public bool Cpp;
        [Option("Emit debug informations (contains only comments)")]
        public bool Debug;
        [Option("Emit debug informations (contains line numbers)")]
        public bool DebugFull;
        [Required]
        public string AssemblyPath;
        [Required]
        public string OutputPath;
    }

    public static class Program
    {
        public static int Main(string[] args)
        {
            var extractor = new CommandLineExtractor<IL2COption>();
            try
            {
                var option = extractor.Extract(args);

                var debugInformationOptions = option.DebugFull
                    ? DebugInformationOptions.Full
                    : option.Debug
                        ? DebugInformationOptions.CommentOnly
                        : DebugInformationOptions.None;

                SimpleDriver.Translate(
                    Console.Out,
                    option.AssemblyPath,
                    option.OutputPath,
                    option.Cpp,
                    debugInformationOptions);

                return 0;
            }
            catch (CommandLineArgumentException ex)
            {
                extractor.WriteUsages(Console.Error);
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
