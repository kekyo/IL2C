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
        [Test]
        public static void StoreLocalVariableFromConstantTest()
        {
            var ilBytes = new byte[]
            {
                // C#: var local0 = 1;
                0x17, // IL: ldc.i4.1
                0x0a  // IL: stloc.0
            };

            var stack = new Stack<object>();
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

        public static long Int64MainBody()
        {
            var a = 1L;
            var b = 2L;
            var c = a + b;
            return c;
        }

        [Test]
        public static void SimpleOverallByInt64SummationTest()
        {
            var testType = typeof(ConverterTest);
            var mainMethod = testType.GetMethod("Int64MainBody");

            var tw = new StringWriter();
            IL2C.Converter.Convert(tw, mainMethod);

            var sourceCode = tw.ToString();

            var expected = new StringWriter();
            expected.WriteLine(@"#include <stdint.h>");
            expected.WriteLine(@"int64_t Int64MainBody(void)");
            expected.WriteLine(@"{");
            expected.WriteLine(@"int64_t local0;");
            expected.WriteLine(@"int64_t local1;");
            expected.WriteLine(@"int64_t local2;");
            expected.WriteLine(@"int64_t local3;");
            expected.WriteLine();
            expected.WriteLine(@"local0 = 1LL;");
            expected.WriteLine(@"local1 = 2LL;");
            expected.WriteLine(@"local2 = local1 + local0;");
            expected.WriteLine(@"local3 = local2;");
            expected.WriteLine(@"return local3;");
            expected.WriteLine(@"}");

            Assert.AreEqual(expected.ToString(), sourceCode);
        }

        public static long Int64LargeValueMainBody()
        {
            var a = 1234567890123456L;
            var b = 2345678901234567L;
            var c = a + b;
            return c;
        }

        [Test]
        public static void SimpleOverallByInt64LargeValueSummationTest()
        {
            var testType = typeof(ConverterTest);
            var mainMethod = testType.GetMethod("Int64LargeValueMainBody");

            var tw = new StringWriter();
            IL2C.Converter.Convert(tw, mainMethod);

            var sourceCode = tw.ToString();

            var expected = new StringWriter();
            expected.WriteLine(@"#include <stdint.h>");
            expected.WriteLine(@"int64_t Int64LargeValueMainBody(void)");
            expected.WriteLine(@"{");
            expected.WriteLine(@"int64_t local0;");
            expected.WriteLine(@"int64_t local1;");
            expected.WriteLine(@"int64_t local2;");
            expected.WriteLine(@"int64_t local3;");
            expected.WriteLine();
            expected.WriteLine(@"local0 = 1234567890123456LL;");
            expected.WriteLine(@"local1 = 2345678901234567LL;");
            expected.WriteLine(@"local2 = local1 + local0;");
            expected.WriteLine(@"local3 = local2;");
            expected.WriteLine(@"return local3;");
            expected.WriteLine(@"}");

            Assert.AreEqual(expected.ToString(), sourceCode);
        }

        public static int Int32MainBody()
        {
            var a = 1;
            var b = 2;
            var c = a + b;
            return c;
        }

        [Test]
        public static void SimpleOverallByIn32SummationTest()
        {
            var testType = typeof(ConverterTest);
            var mainMethod = testType.GetMethod("Int32MainBody");

            var tw = new StringWriter();
            IL2C.Converter.Convert(tw, mainMethod);

            var sourceCode = tw.ToString();

            var expected = new StringWriter();
            expected.WriteLine(@"#include <stdint.h>");
            expected.WriteLine(@"int32_t Int32MainBody(void)");
            expected.WriteLine(@"{");
            expected.WriteLine(@"int32_t local0;");
            expected.WriteLine(@"int32_t local1;");
            expected.WriteLine(@"int32_t local2;");
            expected.WriteLine(@"int32_t local3;");
            expected.WriteLine();
            expected.WriteLine(@"local0 = 1;");
            expected.WriteLine(@"local1 = 2;");
            expected.WriteLine(@"local2 = local1 + local0;");
            expected.WriteLine(@"local3 = local2;");
            expected.WriteLine(@"return local3;");
            expected.WriteLine(@"}");

            Assert.AreEqual(expected.ToString(), sourceCode);
        }

        public static int Int32LargeValueMainBody()
        {
            var a = 12345678;
            var b = 23456789;
            var c = a + b;
            return c;
        }

        [Test]
        public static void SimpleOverallByIn32LargeValueSummationTest()
        {
            var testType = typeof(ConverterTest);
            var mainMethod = testType.GetMethod("Int32LargeValueMainBody");

            var tw = new StringWriter();
            IL2C.Converter.Convert(tw, mainMethod);

            var sourceCode = tw.ToString();

            var expected = new StringWriter();
            expected.WriteLine(@"#include <stdint.h>");
            expected.WriteLine(@"int32_t Int32LargeValueMainBody(void)");
            expected.WriteLine(@"{");
            expected.WriteLine(@"int32_t local0;");
            expected.WriteLine(@"int32_t local1;");
            expected.WriteLine(@"int32_t local2;");
            expected.WriteLine(@"int32_t local3;");
            expected.WriteLine();
            expected.WriteLine(@"local0 = 12345678;");
            expected.WriteLine(@"local1 = 23456789;");
            expected.WriteLine(@"local2 = local1 + local0;");
            expected.WriteLine(@"local3 = local2;");
            expected.WriteLine(@"return local3;");
            expected.WriteLine(@"}");

            Assert.AreEqual(expected.ToString(), sourceCode);
        }
    }
}
