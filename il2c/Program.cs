using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Reflection.Emit;
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
                Console.WriteLine("Usage: il2c.exe <target assembly> <source code>");
                return 0;
            }

            var assemblyPath = args[0];
            var outputPath = args[1];

            var assembly = Assembly.LoadFrom(assemblyPath);

            using (var fs = new FileStream(outputPath, FileMode.Create, FileAccess.ReadWrite, FileShare.None))
            {
                var ms = new MemoryStream();
                var tw = new StreamWriter(ms, Encoding.UTF8);

                foreach (var module in assembly.GetModules())
                {
                    var translateContext = new TranslateContext(module);

                    foreach (var method in
                        from type in module.GetTypes()
                        where type.IsClass || type.IsValueType
                        from method in type.GetMethods(
                            BindingFlags.Public | BindingFlags.NonPublic |
                            BindingFlags.Static | BindingFlags.DeclaredOnly)
                        select method)
                    {
                        IL2C.Converter.ConvertMethod(translateContext, tw, method, "    ");
                        tw.WriteLine();
                    }
                }

                tw.Flush();

                var tw2 = new StreamWriter(fs, Encoding.UTF8);
                tw2.WriteLine("#include <{0}>");    // TODO:n
                tw2.WriteLine();
                tw2.WriteLine("typedef struct Hoge {...}"); // TODO: n
                tw2.WriteLine();

                tw2.Flush();

                ms.Position = 0;
                ms.CopyTo(fs);

                fs.Flush();
            }

            return 0;
        }
    }
}
