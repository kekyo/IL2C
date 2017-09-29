using System.IO;
using NUnit.Framework;

namespace IL2C
{
    [TestFixture]
    public static class ConverterTest
    {
        #region Byte
        public static byte ByteMainBody()
        {
            var a = (byte)1;
            var b = (byte)2;
            var c = (byte)(a + b);
            return c;
        }

        [Test]
        public static void SimpleOverallByByteSummationTest()
        {
            var testType = typeof(ConverterTest);
            var mainMethod = testType.GetMethod("ByteMainBody");

            var tw = new StringWriter();
            IL2C.Converter.Convert(tw, mainMethod, "  ");

            var sourceCode = tw.ToString();

            var expected = new StringWriter();
            expected.WriteLine(@"#include <stdbool.h>");
            expected.WriteLine(@"#include <stdint.h>");
            expected.WriteLine(@"");
            expected.WriteLine(@"uint8_t ByteMainBody(void)");
            expected.WriteLine(@"{");
            expected.WriteLine(@"  uint8_t local0;");
            expected.WriteLine(@"  uint8_t local1;");
            expected.WriteLine(@"  uint8_t local2;");
            expected.WriteLine(@"  uint8_t local3;");
            expected.WriteLine(@"");
            expected.WriteLine(@"  int32_t __stack0_int32_t;");
            expected.WriteLine(@"  int32_t __stack1_int32_t;");
            expected.WriteLine(@"");
            expected.WriteLine(@"  __stack0_int32_t = 1;");
            expected.WriteLine(@"  local0 = (uint8_t)__stack0_int32_t;");
            expected.WriteLine(@"  __stack0_int32_t = 2;");
            expected.WriteLine(@"  local1 = (uint8_t)__stack0_int32_t;");
            expected.WriteLine(@"  __stack0_int32_t = local0;");
            expected.WriteLine(@"  __stack1_int32_t = local1;");
            expected.WriteLine(@"  __stack0_int32_t = __stack0_int32_t + __stack1_int32_t;");
            expected.WriteLine(@"  __stack0_int32_t = (uint8_t)__stack0_int32_t;");
            expected.WriteLine(@"  local2 = (uint8_t)__stack0_int32_t;");
            expected.WriteLine(@"  __stack0_int32_t = local2;");
            expected.WriteLine(@"  local3 = (uint8_t)__stack0_int32_t;");
            expected.WriteLine(@"  goto L_0000;");
            expected.WriteLine(@"L_0000:");
            expected.WriteLine(@"  __stack0_int32_t = local3;");
            expected.WriteLine(@"  return (uint8_t)__stack0_int32_t;");
            expected.WriteLine(@"}");

            Assert.AreEqual(expected.ToString(), sourceCode);
        }
        #endregion

        #region SByte
        public static sbyte SByteMainBody()
        {
            var a = (sbyte)1;
            var b = (sbyte)2;
            var c = (sbyte)(a + b);
            return c;
        }

        [Test]
        public static void SimpleOverallBySByteSummationTest()
        {
            var testType = typeof(ConverterTest);
            var mainMethod = testType.GetMethod("SByteMainBody");

            var tw = new StringWriter();
            IL2C.Converter.Convert(tw, mainMethod, "  ");

            var sourceCode = tw.ToString();

            var expected = new StringWriter();
            expected.WriteLine(@"#include <stdbool.h>");
            expected.WriteLine(@"#include <stdint.h>");
            expected.WriteLine(@"");
            expected.WriteLine(@"int8_t SByteMainBody(void)");
            expected.WriteLine(@"{");
            expected.WriteLine(@"  int8_t local0;");
            expected.WriteLine(@"  int8_t local1;");
            expected.WriteLine(@"  int8_t local2;");
            expected.WriteLine(@"  int8_t local3;");
            expected.WriteLine(@"");
            expected.WriteLine(@"  int32_t __stack0_int32_t;");
            expected.WriteLine(@"  int32_t __stack1_int32_t;");
            expected.WriteLine(@"");
            expected.WriteLine(@"  __stack0_int32_t = 1;");
            expected.WriteLine(@"  local0 = (int8_t)__stack0_int32_t;");
            expected.WriteLine(@"  __stack0_int32_t = 2;");
            expected.WriteLine(@"  local1 = (int8_t)__stack0_int32_t;");
            expected.WriteLine(@"  __stack0_int32_t = local0;");
            expected.WriteLine(@"  __stack1_int32_t = local1;");
            expected.WriteLine(@"  __stack0_int32_t = __stack0_int32_t + __stack1_int32_t;");
            expected.WriteLine(@"  __stack0_int32_t = (int8_t)__stack0_int32_t;");
            expected.WriteLine(@"  local2 = (int8_t)__stack0_int32_t;");
            expected.WriteLine(@"  __stack0_int32_t = local2;");
            expected.WriteLine(@"  local3 = (int8_t)__stack0_int32_t;");
            expected.WriteLine(@"  goto L_0000;");
            expected.WriteLine(@"L_0000:");
            expected.WriteLine(@"  __stack0_int32_t = local3;");
            expected.WriteLine(@"  return (int8_t)__stack0_int32_t;");
            expected.WriteLine(@"}");

            Assert.AreEqual(expected.ToString(), sourceCode);
        }

        public static sbyte SByteWithMinusMainBody()
        {
            var a = (sbyte)-2;
            var b = (sbyte)5;
            var c = (sbyte)(a + b);
            return c;
        }

        [Test]
        public static void SimpleOverallBySByteWithMinusSummationTest()
        {
            var testType = typeof(ConverterTest);
            var mainMethod = testType.GetMethod("SByteWithMinusMainBody");

            var tw = new StringWriter();
            IL2C.Converter.Convert(tw, mainMethod, "  ");

            var sourceCode = tw.ToString();

            var expected = new StringWriter();
            expected.WriteLine(@"#include <stdbool.h>");
            expected.WriteLine(@"#include <stdint.h>");
            expected.WriteLine(@"");
            expected.WriteLine(@"int8_t SByteWithMinusMainBody(void)");
            expected.WriteLine(@"{");
            expected.WriteLine(@"  int8_t local0;");
            expected.WriteLine(@"  int8_t local1;");
            expected.WriteLine(@"  int8_t local2;");
            expected.WriteLine(@"  int8_t local3;");
            expected.WriteLine(@"");
            expected.WriteLine(@"  int32_t __stack0_int32_t;");
            expected.WriteLine(@"  int32_t __stack1_int32_t;");
            expected.WriteLine(@"");
            expected.WriteLine(@"  __stack0_int32_t = -2;");
            expected.WriteLine(@"  local0 = (int8_t)__stack0_int32_t;");
            expected.WriteLine(@"  __stack0_int32_t = 5;");
            expected.WriteLine(@"  local1 = (int8_t)__stack0_int32_t;");
            expected.WriteLine(@"  __stack0_int32_t = local0;");
            expected.WriteLine(@"  __stack1_int32_t = local1;");
            expected.WriteLine(@"  __stack0_int32_t = __stack0_int32_t + __stack1_int32_t;");
            expected.WriteLine(@"  __stack0_int32_t = (int8_t)__stack0_int32_t;");
            expected.WriteLine(@"  local2 = (int8_t)__stack0_int32_t;");
            expected.WriteLine(@"  __stack0_int32_t = local2;");
            expected.WriteLine(@"  local3 = (int8_t)__stack0_int32_t;");
            expected.WriteLine(@"  goto L_0000;");
            expected.WriteLine(@"L_0000:");
            expected.WriteLine(@"  __stack0_int32_t = local3;");
            expected.WriteLine(@"  return (int8_t)__stack0_int32_t;");
            expected.WriteLine(@"}");

            Assert.AreEqual(expected.ToString(), sourceCode);
        }
        #endregion

        #region Int16
        public static short Int16MainBody()
        {
            var a = (short)1;
            var b = (short)2;
            var c = (short)(a + b);
            return c;
        }

        [Test]
        public static void SimpleOverallByInt16SummationTest()
        {
            var testType = typeof(ConverterTest);
            var mainMethod = testType.GetMethod("Int16MainBody");

            var tw = new StringWriter();
            IL2C.Converter.Convert(tw, mainMethod, "  ");

            var sourceCode = tw.ToString();

            var expected = new StringWriter();
            expected.WriteLine(@"#include <stdbool.h>");
            expected.WriteLine(@"#include <stdint.h>");
            expected.WriteLine(@"");
            expected.WriteLine(@"int16_t Int16MainBody(void)");
            expected.WriteLine(@"{");
            expected.WriteLine(@"  int16_t local0;");
            expected.WriteLine(@"  int16_t local1;");
            expected.WriteLine(@"  int16_t local2;");
            expected.WriteLine(@"  int16_t local3;");
            expected.WriteLine(@"");
            expected.WriteLine(@"  int32_t __stack0_int32_t;");
            expected.WriteLine(@"  int32_t __stack1_int32_t;");
            expected.WriteLine(@"");
            expected.WriteLine(@"  __stack0_int32_t = 1;");
            expected.WriteLine(@"  local0 = (int16_t)__stack0_int32_t;");
            expected.WriteLine(@"  __stack0_int32_t = 2;");
            expected.WriteLine(@"  local1 = (int16_t)__stack0_int32_t;");
            expected.WriteLine(@"  __stack0_int32_t = local0;");
            expected.WriteLine(@"  __stack1_int32_t = local1;");
            expected.WriteLine(@"  __stack0_int32_t = __stack0_int32_t + __stack1_int32_t;");
            expected.WriteLine(@"  __stack0_int32_t = (int16_t)__stack0_int32_t;");
            expected.WriteLine(@"  local2 = (int16_t)__stack0_int32_t;");
            expected.WriteLine(@"  __stack0_int32_t = local2;");
            expected.WriteLine(@"  local3 = (int16_t)__stack0_int32_t;");
            expected.WriteLine(@"  goto L_0000;");
            expected.WriteLine(@"L_0000:");
            expected.WriteLine(@"  __stack0_int32_t = local3;");
            expected.WriteLine(@"  return (int16_t)__stack0_int32_t;");
            expected.WriteLine(@"}");

            Assert.AreEqual(expected.ToString(), sourceCode);
        }
        #endregion

        #region Int32
        public static int Int32MainBody()
        {
            var a = 1;
            var b = 2;
            var c = a + b;
            return c;
        }

        [Test]
        public static void SimpleOverallByInt32SummationTest()
        {
            var testType = typeof(ConverterTest);
            var mainMethod = testType.GetMethod("Int32MainBody");

            var tw = new StringWriter();
            IL2C.Converter.Convert(tw, mainMethod, "  ");

            var sourceCode = tw.ToString();

            var expected = new StringWriter();
            expected.WriteLine(@"#include <stdbool.h>");
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
            expected.WriteLine(@"  goto L_0000;");
            expected.WriteLine(@"L_0000:");
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
        public static void SimpleOverallByInt32LargeValueSummationTest()
        {
            var testType = typeof(ConverterTest);
            var mainMethod = testType.GetMethod("Int32LargeValueMainBody");

            var tw = new StringWriter();
            IL2C.Converter.Convert(tw, mainMethod, "  ");

            var sourceCode = tw.ToString();

            var expected = new StringWriter();
            expected.WriteLine(@"#include <stdbool.h>");
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
            expected.WriteLine(@"  goto L_0000;");
            expected.WriteLine(@"L_0000:");
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
        public static void SimpleOverallByInt32WithArgumentsSummationTest()
        {
            var testType = typeof(ConverterTest);
            var mainMethod = testType.GetMethod("Int32WithArgumentsMainBody");

            var tw = new StringWriter();
            IL2C.Converter.Convert(tw, mainMethod, "  ");

            var sourceCode = tw.ToString();

            var expected = new StringWriter();
            expected.WriteLine(@"#include <stdbool.h>");
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
            expected.WriteLine(@"  goto L_0000;");
            expected.WriteLine(@"L_0000:");
            expected.WriteLine(@"  __stack0_int32_t = local1;");
            expected.WriteLine(@"  return __stack0_int32_t;");
            expected.WriteLine(@"}");

            Assert.AreEqual(expected.ToString(), sourceCode);
        }
        #endregion

        #region Int64
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
            expected.WriteLine(@"#include <stdbool.h>");
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
            expected.WriteLine(@"  __stack0_int64_t = __stack0_int32_t;");
            expected.WriteLine(@"  local0 = __stack0_int64_t;");
            expected.WriteLine(@"  __stack0_int32_t = 2;");
            expected.WriteLine(@"  __stack0_int64_t = __stack0_int32_t;");
            expected.WriteLine(@"  local1 = __stack0_int64_t;");
            expected.WriteLine(@"  __stack0_int64_t = local0;");
            expected.WriteLine(@"  __stack1_int64_t = local1;");
            expected.WriteLine(@"  __stack0_int64_t = __stack0_int64_t + __stack1_int64_t;");
            expected.WriteLine(@"  local2 = __stack0_int64_t;");
            expected.WriteLine(@"  __stack0_int64_t = local2;");
            expected.WriteLine(@"  local3 = __stack0_int64_t;");
            expected.WriteLine(@"  goto L_0000;");
            expected.WriteLine(@"L_0000:");
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
            expected.WriteLine(@"#include <stdbool.h>");
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
            expected.WriteLine(@"  goto L_0000;");
            expected.WriteLine(@"L_0000:");
            expected.WriteLine(@"  __stack0_int64_t = local3;");
            expected.WriteLine(@"  return __stack0_int64_t;");
            expected.WriteLine(@"}");

            Assert.AreEqual(expected.ToString(), sourceCode);
        }
        #endregion

        #region Conditional branch
        public static int ConditionalBranchMainBody(int a)
        {
            if (a > 0)
            {
                return a + 1;
            }
            else
            {
                return a + 2;
            }
        }

        [Test]
        public static void ConditionalBranchTest()
        {
            var testType = typeof(ConverterTest);
            var mainMethod = testType.GetMethod("ConditionalBranchMainBody");

            var tw = new StringWriter();
            IL2C.Converter.Convert(tw, mainMethod, "  ");

            var sourceCode = tw.ToString();

            var expected = new StringWriter();
            expected.WriteLine(@"#include <stdbool.h>");
            expected.WriteLine(@"#include <stdint.h>");
            expected.WriteLine();
            expected.WriteLine(@"int32_t ConditionalBranchMainBody(int32_t a)");
            expected.WriteLine(@"{");
            expected.WriteLine(@"  bool local0;");
            expected.WriteLine(@"  int32_t local1;");
            expected.WriteLine();
            expected.WriteLine(@"  int32_t __stack0_int32_t;");
            expected.WriteLine(@"  int32_t __stack1_int32_t;");
            expected.WriteLine();
            expected.WriteLine(@"  __stack0_int32_t = a;");
            expected.WriteLine(@"  __stack1_int32_t = 0;");
            expected.WriteLine(@"  __stack0_int32_t = (__stack0_int32_t > __stack1_int32_t) ? 1 : 0;");
            expected.WriteLine(@"  local0 = __stack0_int32_t ? true : false;");
            expected.WriteLine(@"  __stack0_int32_t = local0 ? 1 : 0;");
            expected.WriteLine(@"  if (__stack0_int32_t == 0) goto L_0000;");
            expected.WriteLine(@"  __stack0_int32_t = a;");
            expected.WriteLine(@"  __stack1_int32_t = 1;");
            expected.WriteLine(@"  __stack0_int32_t = __stack0_int32_t + __stack1_int32_t;");
            expected.WriteLine(@"  local1 = __stack0_int32_t;");
            expected.WriteLine(@"  goto L_0001;");
            expected.WriteLine(@"L_0000:");
            expected.WriteLine(@"  __stack0_int32_t = a;");
            expected.WriteLine(@"  __stack1_int32_t = 2;");
            expected.WriteLine(@"  __stack0_int32_t = __stack0_int32_t + __stack1_int32_t;");
            expected.WriteLine(@"  local1 = __stack0_int32_t;");
            expected.WriteLine(@"  goto L_0001;");
            expected.WriteLine(@"L_0001:");
            expected.WriteLine(@"  __stack0_int32_t = local1;");
            expected.WriteLine(@"  return __stack0_int32_t;");
            expected.WriteLine(@"}");

            Assert.AreEqual(expected.ToString(), sourceCode);
        }
        #endregion
    }
}
