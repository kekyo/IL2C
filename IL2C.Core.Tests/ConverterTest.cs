using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Text;
using IL2C.ILConveters;
using NUnit.Framework;

namespace IL2C
{
    [TestFixture]
    public static class ConverterTest
    {
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
            IL2C.Converter.Convert(tw, mainMethod, "  ");

            var sourceCode = tw.ToString();

            var expected = new StringWriter();
            expected.WriteLine(@"#include <stdint.h>");
            expected.WriteLine();
            expected.WriteLine(@"int64_t Int64MainBody(void)");
            expected.WriteLine(@"{");
            expected.WriteLine(@"  int64_t local0;");
            expected.WriteLine(@"  int64_t local1;");
            expected.WriteLine(@"  int64_t local2;");
            expected.WriteLine(@"  int64_t local3;");
            expected.WriteLine();
            expected.WriteLine(@"  int32_t __stack0_int32_t;");
            expected.WriteLine(@"  int64_t __stack0_int64_t;");
            expected.WriteLine(@"  int64_t __stack1_int64_t;");
            expected.WriteLine();
            expected.WriteLine(@"  __stack0_int32_t = 1;");
            expected.WriteLine(@"  __stack0_int64_t = (int64_t)__stack0_int32_t;");
            expected.WriteLine(@"  local0 = __stack0_int64_t;");
            expected.WriteLine(@"  __stack0_int32_t = 2;");
            expected.WriteLine(@"  __stack0_int64_t = (int64_t)__stack0_int32_t;");
            expected.WriteLine(@"  local1 = __stack0_int64_t;");
            expected.WriteLine(@"  __stack0_int64_t = local0;");
            expected.WriteLine(@"  __stack1_int64_t = local1;");
            expected.WriteLine(@"  __stack0_int64_t = __stack0_int64_t + __stack1_int64_t;");
            expected.WriteLine(@"  local2 = __stack0_int64_t;");
            expected.WriteLine(@"  __stack0_int64_t = local2;");
            expected.WriteLine(@"  local3 = __stack0_int64_t;");
            expected.WriteLine(@"  __stack0_int64_t = local3;");
            expected.WriteLine(@"  return __stack0_int64_t;");
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
            IL2C.Converter.Convert(tw, mainMethod, "  ");

            var sourceCode = tw.ToString();

            var expected = new StringWriter();
            expected.WriteLine(@"#include <stdint.h>");
            expected.WriteLine();
            expected.WriteLine(@"int64_t Int64LargeValueMainBody(void)");
            expected.WriteLine(@"{");
            expected.WriteLine(@"  int64_t local0;");
            expected.WriteLine(@"  int64_t local1;");
            expected.WriteLine(@"  int64_t local2;");
            expected.WriteLine(@"  int64_t local3;");
            expected.WriteLine();
            expected.WriteLine(@"  int64_t __stack0_int64_t;");
            expected.WriteLine(@"  int64_t __stack1_int64_t;");
            expected.WriteLine();
            expected.WriteLine(@"  __stack0_int64_t = 1234567890123456LL;");
            expected.WriteLine(@"  local0 = __stack0_int64_t;");
            expected.WriteLine(@"  __stack0_int64_t = 2345678901234567LL;");
            expected.WriteLine(@"  local1 = __stack0_int64_t;");
            expected.WriteLine(@"  __stack0_int64_t = local0;");
            expected.WriteLine(@"  __stack1_int64_t = local1;");
            expected.WriteLine(@"  __stack0_int64_t = __stack0_int64_t + __stack1_int64_t;");
            expected.WriteLine(@"  local2 = __stack0_int64_t;");
            expected.WriteLine(@"  __stack0_int64_t = local2;");
            expected.WriteLine(@"  local3 = __stack0_int64_t;");
            expected.WriteLine(@"  __stack0_int64_t = local3;");
            expected.WriteLine(@"  return __stack0_int64_t;");
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
            IL2C.Converter.Convert(tw, mainMethod, "  ");

            var sourceCode = tw.ToString();

            var expected = new StringWriter();
            expected.WriteLine(@"#include <stdint.h>");
            expected.WriteLine();
            expected.WriteLine(@"int32_t Int32MainBody(void)");
            expected.WriteLine(@"{");
            expected.WriteLine(@"  int32_t local0;");
            expected.WriteLine(@"  int32_t local1;");
            expected.WriteLine(@"  int32_t local2;");
            expected.WriteLine(@"  int32_t local3;");
            expected.WriteLine();
            expected.WriteLine(@"  int32_t __stack0_int32_t;");
            expected.WriteLine(@"  int32_t __stack1_int32_t;");
            expected.WriteLine();
            expected.WriteLine(@"  __stack0_int32_t = 1;");
            expected.WriteLine(@"  local0 = __stack0_int32_t;");
            expected.WriteLine(@"  __stack0_int32_t = 2;");
            expected.WriteLine(@"  local1 = __stack0_int32_t;");
            expected.WriteLine(@"  __stack0_int32_t = local0;");
            expected.WriteLine(@"  __stack1_int32_t = local1;");
            expected.WriteLine(@"  __stack0_int32_t = __stack0_int32_t + __stack1_int32_t;");
            expected.WriteLine(@"  local2 = __stack0_int32_t;");
            expected.WriteLine(@"  __stack0_int32_t = local2;");
            expected.WriteLine(@"  local3 = __stack0_int32_t;");
            expected.WriteLine(@"  __stack0_int32_t = local3;");
            expected.WriteLine(@"  return __stack0_int32_t;");
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
            IL2C.Converter.Convert(tw, mainMethod, "  ");

            var sourceCode = tw.ToString();

            var expected = new StringWriter();
            expected.WriteLine(@"#include <stdint.h>");
            expected.WriteLine();
            expected.WriteLine(@"int32_t Int32LargeValueMainBody(void)");
            expected.WriteLine(@"{");
            expected.WriteLine(@"  int32_t local0;");
            expected.WriteLine(@"  int32_t local1;");
            expected.WriteLine(@"  int32_t local2;");
            expected.WriteLine(@"  int32_t local3;");
            expected.WriteLine();
            expected.WriteLine(@"  int32_t __stack0_int32_t;");
            expected.WriteLine(@"  int32_t __stack1_int32_t;");
            expected.WriteLine();
            expected.WriteLine(@"  __stack0_int32_t = 12345678;");
            expected.WriteLine(@"  local0 = __stack0_int32_t;");
            expected.WriteLine(@"  __stack0_int32_t = 23456789;");
            expected.WriteLine(@"  local1 = __stack0_int32_t;");
            expected.WriteLine(@"  __stack0_int32_t = local0;");
            expected.WriteLine(@"  __stack1_int32_t = local1;");
            expected.WriteLine(@"  __stack0_int32_t = __stack0_int32_t + __stack1_int32_t;");
            expected.WriteLine(@"  local2 = __stack0_int32_t;");
            expected.WriteLine(@"  __stack0_int32_t = local2;");
            expected.WriteLine(@"  local3 = __stack0_int32_t;");
            expected.WriteLine(@"  __stack0_int32_t = local3;");
            expected.WriteLine(@"  return __stack0_int32_t;");
            expected.WriteLine(@"}");

            Assert.AreEqual(expected.ToString(), sourceCode);
        }

        public static int Int32WithArgumentsMainBody(int a, int b)
        {
            var c = a + b;
            return c;
        }

        [Test]
        public static void SimpleOverallByIn32WithArgumentsSummationTest()
        {
            var testType = typeof(ConverterTest);
            var mainMethod = testType.GetMethod("Int32WithArgumentsMainBody");

            var tw = new StringWriter();
            IL2C.Converter.Convert(tw, mainMethod, "  ");

            var sourceCode = tw.ToString();

            var expected = new StringWriter();
            expected.WriteLine(@"#include <stdint.h>");
            expected.WriteLine();
            expected.WriteLine(@"int32_t Int32WithArgumentsMainBody(int32_t a, int32_t b)");
            expected.WriteLine(@"{");
            expected.WriteLine(@"  int32_t local0;");
            expected.WriteLine(@"  int32_t local1;");
            expected.WriteLine();
            expected.WriteLine(@"  int32_t __stack0_int32_t;");
            expected.WriteLine(@"  int32_t __stack1_int32_t;");
            expected.WriteLine();
            expected.WriteLine(@"  __stack0_int32_t = a;");
            expected.WriteLine(@"  __stack1_int32_t = b;");
            expected.WriteLine(@"  __stack0_int32_t = __stack0_int32_t + __stack1_int32_t;");
            expected.WriteLine(@"  local0 = __stack0_int32_t;");
            expected.WriteLine(@"  __stack0_int32_t = local0;");
            expected.WriteLine(@"  local1 = __stack0_int32_t;");
            expected.WriteLine(@"  __stack0_int32_t = local1;");
            expected.WriteLine(@"  return __stack0_int32_t;");
            expected.WriteLine(@"}");

            Assert.AreEqual(expected.ToString(), sourceCode);
        }






    }
}
