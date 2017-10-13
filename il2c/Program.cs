using System;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Text;
using IL2C;

namespace il2c
{
    public static class Program
    {
        public static int Main(string[] args)
        {
            if (args.Length != 2)
            {
                Console.WriteLine("Usage: il2c.exe <target assembly> <output path>");
                return 0;
            }

            var assemblyPath = args[0];
            var outputPath = args[1];

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

            var assembly = Assembly.LoadFrom(assemblyPath);

            foreach (var module in assembly.GetModules())
            {
                var moduleFileName = Path.GetFileNameWithoutExtension(module.Name);

                var filePath = Path.Combine(outputPath, moduleFileName);

                var translateContext = new TranslateContext(module);

                using (var fsSource = new FileStream(
                    filePath + ".c",
                    FileMode.Create,
                    FileAccess.ReadWrite,
                    FileShare.None))
                {
                    var twSource = new StreamWriter(fsSource, Encoding.UTF8);

                    twSource.WriteLine("#include \"{0}.h\"", moduleFileName);
                    twSource.WriteLine();

                    foreach (var method in
                        from type in module.GetTypes()
                        where type.IsClass || type.IsValueType
                        from method in type.GetMethods(
                            BindingFlags.Public | BindingFlags.NonPublic |
                            BindingFlags.Static | BindingFlags.DeclaredOnly)
                        select method)
                    {
                        IL2C.Converter.ConvertMethod(
                            translateContext,
                            twSource,
                            method,
                            "    ");

                        twSource.WriteLine();
                    }

                    twSource.Flush();
                }

                using (var fsHeader = new FileStream(
                    filePath + ".h",
                    FileMode.Create,
                    FileAccess.ReadWrite,
                    FileShare.None))
                {
                    var twHeader = new StreamWriter(fsHeader, Encoding.UTF8);

                    twHeader.WriteLine("#ifndef __MODULE_{0}__", moduleFileName);
                    twHeader.WriteLine("#define __MODULE_{0}__", moduleFileName);

                    twHeader.WriteLine();

                    foreach (var fileName in translateContext.EnumerateRequiredIncludeFileNames())
                    {
                        twHeader.WriteLine("#include <{0}>", fileName);
                    }

                    twHeader.WriteLine();

                    foreach (var type in
                        from type in module.GetTypes()
                        where type.IsValueType
                        select type)
                    {
                        IL2C.Converter.ConvertType(
                            translateContext,
                            twHeader,
                            type,
                            "    ");

                        twHeader.WriteLine();
                    }

                    twHeader.WriteLine("#endif");

                    twHeader.Flush();
                }
            }

            return 0;
        }
    }
}
