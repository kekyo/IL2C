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

            Console.Write("IL2C: Preparing assembly: \"{0}\" ...", Path.GetFileName(assemblyPath));

            if (Directory.Exists(outputPath) == false)
            {
                try
                {
                    Directory.CreateDirectory(outputPath);
                }
                catch
                {
                }
            }

            var translateContext = new TranslateContext(assemblyPath);
            var preparedFunctions = AssemblyPreparer.Prepare(translateContext);

            Console.WriteLine(" done.");

            var assemblyName = Path.GetFileNameWithoutExtension(assemblyPath);
            var filePath = Path.Combine(outputPath, assemblyName);
            var sourceFilePath = filePath + (enableCpp ? ".cpp" : ".c");

            Console.Write("IL2C: Writing source code: \"{0}\" ...", Path.GetFileName(sourceFilePath));

            using (var fsSource = new FileStream(
                sourceFilePath,
                FileMode.Create,
                FileAccess.ReadWrite,
                FileShare.None))
            {
                var twSource = new StreamWriter(fsSource, Encoding.UTF8);
                AssemblyWriter.WriteSourceCode(
                    twSource, translateContext, preparedFunctions, "    ", debugInformationOptions);
                twSource.Flush();
            }

            Console.WriteLine(" done.");

            var headerFilePath = filePath + ".h";

            Console.Write("IL2C: Writing header: \"{0}\" ...", Path.GetFileName(headerFilePath));

            using (var fsHeader = new FileStream(
                headerFilePath,
                FileMode.Create,
                FileAccess.ReadWrite,
                FileShare.None))
            {
                var twHeader = new StreamWriter(fsHeader, Encoding.UTF8);
                AssemblyWriter.WriteHeader(twHeader, translateContext, preparedFunctions, "    ");
                twHeader.Flush();
            }

            Console.WriteLine(" done.");

            return 0;
        }
    }
}
