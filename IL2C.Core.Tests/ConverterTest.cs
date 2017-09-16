using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using NUnit.Framework;

namespace IL2C
{
    [TestFixture]
    public static class ConverterTest
    {
        public static int main()
        {
            var a = 1;
            var b = 2;
            var c = a + b;
            return c;
        }

        [Test]
        public static void StoreLocalVariableFromConstantTest()
        {
            var ilBytes = new byte[]
            {
                // C#: var local0 = 1;
                0x17, // IL: ldc.i4.1
                0x0a  // IL: stloc.0
            };

            var stack = new Stack<string>();
            var results =
                IL2C.Converter.DecodeAndEnumerateOpCodes(ilBytes)
                    .Select(ilData => ilData.Apply(stack))
                    .ToArray();

            var expected = new[]
            {
                null,
                "local0 = 1;"
            };

            Assert.IsTrue(expected.SequenceEqual(results));
            Assert.AreEqual(0, stack.Count);
        }

        [Test]
        public static void SimpleOverallBySummationTest()
        {
            var testType = typeof(ConverterTest);
            var mainMethod = testType.GetMethod("main");

            var tw = new StringWriter();
            IL2C.Converter.Convert(tw, mainMethod);

            var sourceCode = tw.ToString();

            var expected = new StringWriter();
            expected.WriteLine(@"int main(void)");
            expected.WriteLine(@"{");
            expected.WriteLine(@"int local0;");
            expected.WriteLine(@"int local1;");
            expected.WriteLine(@"int local2;");
            expected.WriteLine(@"int local3;");
            expected.WriteLine();
            expected.WriteLine(@"local0 = 1;");
            expected.WriteLine(@"local1 = 2;");
            expected.WriteLine(@"local2 = local1 + local0;");
            expected.WriteLine(@"local3 = local2;");
            expected.WriteLine(@"return local3;");
            expected.WriteLine(@"}");

            Assert.AreEqual(expected.ToString(), sourceCode);
        }
    }
}
