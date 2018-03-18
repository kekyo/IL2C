using System;
using System.IO;
using System.Linq;
using System.Text;

namespace IL2C
{
    public static class Program
    {
        public static int Main(string[] args)
        {
            if (args.Length < 2)
            {
                Console.Error.WriteLine("Usage: IL2C.exe [options] <target assembly> <output path>");
                Console.Error.WriteLine("  --cpp       : Produce C++ files (apply extension *.cpp instead *.c, body will not changed)");
                Console.Error.WriteLine("  --debug     : Emit debug informations (contains only comments)");
                Console.Error.WriteLine("  --debug-full: Emit debug informations (contains line numbers)");

                return 0;
            }

            var options = args
                .Where(arg => arg.StartsWith("--"))
                .Select(arg => arg.Substring(2))
                .ToArray();
            var paths = args
                .Where(arg => !arg.StartsWith("--"))
                .ToArray();

            var enableCpp = options.Contains("cpp");
            var debug = options.Contains("debug");
            var debugFull = options.Contains("debug-full");

            var debugInformationOptions = debugFull
                ? DebugInformationOptions.Full
                : debug
                    ? DebugInformationOptions.CommentOnly
                    : DebugInformationOptions.None;

            var assemblyPath = paths[0];
            var outputPath = paths[1];

            SimpleDriver.Translate(
                Console.Out,
                assemblyPath,
                outputPath,
                enableCpp,
                debugInformationOptions);

            return 0;
        }
    }
}
