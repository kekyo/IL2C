using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Reflection.Emit;
using System.Text;

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
                var tw = new StreamWriter(fs, Encoding.UTF8);

                foreach (var method in
                    from type in assembly.GetTypes()
                    where type.IsClass || type.IsValueType
                    from method in type.GetMethods(
                        BindingFlags.Public | BindingFlags.NonPublic |
                        BindingFlags.Static | BindingFlags.DeclaredOnly)
                    select method)
                {
                    IL2C.Converter.Convert(tw, method, "    ");
                    tw.WriteLine();
                }

                tw.Flush();
            }

            return 0;
        }
    }
}
