using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Threading.Tasks;

using NUnit.Framework;

namespace IL2C
{
    [TestFixture]
    public sealed class Test
    {
        private static readonly Assembly targetAssembly = typeof(Target).Assembly;

        [Test]
        public async Task SimpleTestAsync()
        {
            var translateContext = new TranslateContext(targetAssembly.Location, false);

            var prepared = AssemblyPreparer.Prepare(
                translateContext, method => method.DeclaringType.FriendlyName == "IL2C.Target");

            var targetMethod =
                translateContext.Assembly.Modules
                .First().Types
                .First(type => type.FriendlyName == "IL2C.Target").DeclaredMethods
                .First(method => method.Name == "ByteMainBody");

            var tw = new StringWriter();
            tw.WriteLine("#include <stdio.h>");
            tw.WriteLine("#include <stdint.h>");
            tw.WriteLine("#include <stdbool.h>");
            tw.WriteLine("#include <string.h>");
            tw.WriteLine();

            AssemblyWriter.InternalConvertFromMethod(tw, translateContext, prepared, targetMethod, "  ");

            tw.WriteLine();
            tw.WriteLine("int main()");
            tw.WriteLine("{");
            tw.WriteLine(string.Format("  auto result = {0}();", targetMethod.CLanguageFunctionName));
            tw.WriteLine(string.Format("  printf(\"%d\", result);"));
            tw.WriteLine(string.Format("  return 0;"));
            tw.WriteLine("}");

            var sourceCode = tw.ToString();

            var result = await GccDriver.CompileAndRunAsync(new StringReader(sourceCode));
            var lines = result.Split(new[] { '\r', '\n' });

            Assert.AreEqual(Target.ByteMainBody().ToString(), lines[0]);
        }

        //[Test]
        public async Task CompileTestAsync()
        {
            var tr = new StringReader(
                string.Join("\n", new[]
                {
                    "#include <stdio.h>",
                    "int main() {",
                    "printf(\"This is test.\\nAAA\");",
                    "return 0;",
                    "}"
                }));
            var result = await GccDriver.CompileAndRunAsync(tr);

            Assert.AreEqual("This is test.\r\nAAA\r\n", result);
        }
    }
}
