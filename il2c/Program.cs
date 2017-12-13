﻿using System;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Text;

namespace IL2C
{
    public static class Program
    {
        public static int Main(string[] args)
        {
            if (args.Length < 2)
            {
                Console.WriteLine("Usage: il2c.exe <target assembly> <output path>");
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

            var assemblyPath = paths[0];
            var outputPath = paths[1];

            Console.WriteLine("il2c: Translating assembly \"{0}\".", Path.GetFileName(assemblyPath));

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
            var prepared = AssemblyPreparer.Prepare(translateContext);
            
            var assemblyName = Path.GetFileNameWithoutExtension(assemblyPath);
            var filePath = Path.Combine(outputPath, assemblyName);

            using (var fsSource = new FileStream(
                filePath + ".c",
                FileMode.Create,
                FileAccess.ReadWrite,
                FileShare.None))
            {
                var twSource = new StreamWriter(fsSource, Encoding.UTF8);
                AssemblyWriter.WriteSourceCode(twSource, translateContext, prepared, "    ");
                twSource.Flush();
            }

            using (var fsHeader = new FileStream(
                filePath + ".h",
                FileMode.Create,
                FileAccess.ReadWrite,
                FileShare.None))
            {
                var twHeader = new StreamWriter(fsHeader, Encoding.UTF8);
                AssemblyWriter.WriteHeader(twHeader, translateContext, prepared, "    ");
                twHeader.Flush();
            }

            return 0;
        }
    }
}
