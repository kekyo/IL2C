using NUnit.Framework;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace IL2C
{
    [TestFixture]
    public sealed class Test
    {
        [Test]
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
