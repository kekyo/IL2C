using System;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Reflection;

using NUnit.Framework;
using Mono.Cecil;

namespace IL2C
{
    [TestFixture]
    public static class ConverterTest
    {
        private static readonly Assembly testTypeAssembly = typeof(TestTargetClass).Assembly;
        private static readonly TypeDefinition testType =
            AssemblyDefinition.ReadAssembly(testTypeAssembly.Location).MainModule.Types
            .First(type => type.FullName == typeof(TestTargetClass).FullName);

        private static MethodDefinition GetMethod(this TypeDefinition type, string methodName)
        {
            return type.Methods.First(method => method.Name == methodName);
        }
        #region Byte

        [Test]
        public static void SimpleOverallByByteSummationTest()
        {
            var mainMethod = testType.GetMethod("ByteMainBody");

            var translateContext = new TranslateContext(testTypeAssembly.Location);
            var tw = new StringWriter();

            var prepared = AssemblyPreparer.Prepare(
                translateContext, method => method.MemberEquals(mainMethod));
            AssemblyWriter.InternalConvertFromMethod(tw, translateContext, prepared, mainMethod, "  ");

            var sourceCode = tw.ToString();

            var expected = new StringWriter();
            expected.WriteLine(@"uint8_t IL2C_TestTargetClass_ByteMainBody(void)");
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

        [Test]
        public static void SimpleOverallBySByteSummationTest()
        {
            var mainMethod = testType.GetMethod("SByteMainBody");

            var translateContext = new TranslateContext(testTypeAssembly.Location);
            var tw = new StringWriter();

            var prepared = AssemblyPreparer.Prepare(
                translateContext, method => method.MemberEquals(mainMethod));
            AssemblyWriter.InternalConvertFromMethod(tw, translateContext, prepared, mainMethod, "  ");

            var sourceCode = tw.ToString();

            var expected = new StringWriter();
            expected.WriteLine(@"int8_t IL2C_TestTargetClass_SByteMainBody(void)");
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

        [Test]
        public static void SimpleOverallBySByteWithMinusSummationTest()
        {
            var mainMethod = testType.GetMethod("SByteWithMinusMainBody");

            var translateContext = new TranslateContext(testTypeAssembly.Location);
            var tw = new StringWriter();

            var prepared = AssemblyPreparer.Prepare(
                translateContext, method => method.MemberEquals(mainMethod));
            AssemblyWriter.InternalConvertFromMethod(tw, translateContext, prepared, mainMethod, "  ");

            var sourceCode = tw.ToString();

            var expected = new StringWriter();
            expected.WriteLine(@"int8_t IL2C_TestTargetClass_SByteWithMinusMainBody(void)");
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

        [Test]
        public static void SimpleOverallByInt16SummationTest()
        {
            var mainMethod = testType.GetMethod("Int16MainBody");

            var translateContext = new TranslateContext(testTypeAssembly.Location);
            var tw = new StringWriter();

            var prepared = AssemblyPreparer.Prepare(
                translateContext, method => method.MemberEquals(mainMethod));
            AssemblyWriter.InternalConvertFromMethod(tw, translateContext, prepared, mainMethod, "  ");

            var sourceCode = tw.ToString();

            var expected = new StringWriter();
            expected.WriteLine(@"int16_t IL2C_TestTargetClass_Int16MainBody(void)");
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

        [Test]
        public static void SimpleOverallByInt16WithMinusSummationTest()
        {
            var mainMethod = testType.GetMethod("Int16WithMinusMainBody");

            var translateContext = new TranslateContext(testTypeAssembly.Location);
            var tw = new StringWriter();

            var prepared = AssemblyPreparer.Prepare(
                translateContext, method => method.MemberEquals(mainMethod));
            AssemblyWriter.InternalConvertFromMethod(tw, translateContext, prepared, mainMethod, "  ");

            var sourceCode = tw.ToString();

            var expected = new StringWriter();
            expected.WriteLine(@"int16_t IL2C_TestTargetClass_Int16WithMinusMainBody(void)");
            expected.WriteLine(@"{");
            expected.WriteLine(@"  int16_t local0;");
            expected.WriteLine(@"  int16_t local1;");
            expected.WriteLine(@"  int16_t local2;");
            expected.WriteLine(@"  int16_t local3;");
            expected.WriteLine(@"");
            expected.WriteLine(@"  int32_t __stack0_int32_t;");
            expected.WriteLine(@"  int32_t __stack1_int32_t;");
            expected.WriteLine(@"");
            expected.WriteLine(@"  __stack0_int32_t = -2;");
            expected.WriteLine(@"  local0 = (int16_t)__stack0_int32_t;");
            expected.WriteLine(@"  __stack0_int32_t = 5;");
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

        #region UInt16

        [Test]
        public static void SimpleOverallByUInt16SummationTest()
        {
            var mainMethod = testType.GetMethod("UInt16MainBody");

            var translateContext = new TranslateContext(testTypeAssembly.Location);
            var tw = new StringWriter();

            var prepared = AssemblyPreparer.Prepare(
                translateContext, method => method.MemberEquals(mainMethod));
            AssemblyWriter.InternalConvertFromMethod(tw, translateContext, prepared, mainMethod, "  ");

            var sourceCode = tw.ToString();

            var expected = new StringWriter();
            expected.WriteLine(@"uint16_t IL2C_TestTargetClass_UInt16MainBody(void)");
            expected.WriteLine(@"{");
            expected.WriteLine(@"  uint16_t local0;");
            expected.WriteLine(@"  uint16_t local1;");
            expected.WriteLine(@"  uint16_t local2;");
            expected.WriteLine(@"  uint16_t local3;");
            expected.WriteLine(@"");
            expected.WriteLine(@"  int32_t __stack0_int32_t;");
            expected.WriteLine(@"  int32_t __stack1_int32_t;");
            expected.WriteLine(@"");
            expected.WriteLine(@"  __stack0_int32_t = 1;");
            expected.WriteLine(@"  local0 = (uint16_t)__stack0_int32_t;");
            expected.WriteLine(@"  __stack0_int32_t = 2;");
            expected.WriteLine(@"  local1 = (uint16_t)__stack0_int32_t;");
            expected.WriteLine(@"  __stack0_int32_t = local0;");
            expected.WriteLine(@"  __stack1_int32_t = local1;");
            expected.WriteLine(@"  __stack0_int32_t = __stack0_int32_t + __stack1_int32_t;");
            expected.WriteLine(@"  __stack0_int32_t = (uint16_t)__stack0_int32_t;");
            expected.WriteLine(@"  local2 = (uint16_t)__stack0_int32_t;");
            expected.WriteLine(@"  __stack0_int32_t = local2;");
            expected.WriteLine(@"  local3 = (uint16_t)__stack0_int32_t;");
            expected.WriteLine(@"  goto L_0000;");
            expected.WriteLine(@"L_0000:");
            expected.WriteLine(@"  __stack0_int32_t = local3;");
            expected.WriteLine(@"  return (uint16_t)__stack0_int32_t;");
            expected.WriteLine(@"}");

            Assert.AreEqual(expected.ToString(), sourceCode);
        }

        [Test]
        public static void SimpleOverallByUInt16WithMaxValueSummationTest()
        {
            var mainMethod = testType.GetMethod("UInt16WithMaxValueMainBody");

            var translateContext = new TranslateContext(testTypeAssembly.Location);
            var tw = new StringWriter();

            var prepared = AssemblyPreparer.Prepare(
                translateContext, method => method.MemberEquals(mainMethod));
            AssemblyWriter.InternalConvertFromMethod(tw, translateContext, prepared, mainMethod, "  ");

            var sourceCode = tw.ToString();

            var expected = new StringWriter();
            expected.WriteLine(@"uint16_t IL2C_TestTargetClass_UInt16WithMaxValueMainBody(void)");
            expected.WriteLine(@"{");
            expected.WriteLine(@"  uint16_t local0;");
            expected.WriteLine(@"  uint16_t local1;");
            expected.WriteLine(@"  uint16_t local2;");
            expected.WriteLine(@"  uint16_t local3;");
            expected.WriteLine(@"");
            expected.WriteLine(@"  int32_t __stack0_int32_t;");
            expected.WriteLine(@"  int32_t __stack1_int32_t;");
            expected.WriteLine(@"");
            expected.WriteLine(@"  __stack0_int32_t = 65530;");
            expected.WriteLine(@"  local0 = (uint16_t)__stack0_int32_t;");
            expected.WriteLine(@"  __stack0_int32_t = 2;");
            expected.WriteLine(@"  local1 = (uint16_t)__stack0_int32_t;");
            expected.WriteLine(@"  __stack0_int32_t = local0;");
            expected.WriteLine(@"  __stack1_int32_t = local1;");
            expected.WriteLine(@"  __stack0_int32_t = __stack0_int32_t + __stack1_int32_t;");
            expected.WriteLine(@"  __stack0_int32_t = (uint16_t)__stack0_int32_t;");
            expected.WriteLine(@"  local2 = (uint16_t)__stack0_int32_t;");
            expected.WriteLine(@"  __stack0_int32_t = local2;");
            expected.WriteLine(@"  local3 = (uint16_t)__stack0_int32_t;");
            expected.WriteLine(@"  goto L_0000;");
            expected.WriteLine(@"L_0000:");
            expected.WriteLine(@"  __stack0_int32_t = local3;");
            expected.WriteLine(@"  return (uint16_t)__stack0_int32_t;");
            expected.WriteLine(@"}");

            Assert.AreEqual(expected.ToString(), sourceCode);
        }
        #endregion

        #region Int32

        [Test]
        public static void SimpleOverallByInt32SummationTest()
        {
            var mainMethod = testType.GetMethod("Int32MainBody");

            var translateContext = new TranslateContext(testTypeAssembly.Location);
            var tw = new StringWriter();

            var prepared = AssemblyPreparer.Prepare(
                translateContext, method => method.MemberEquals(mainMethod));
            AssemblyWriter.InternalConvertFromMethod(tw, translateContext, prepared, mainMethod, "  ");

            var sourceCode = tw.ToString();

            var expected = new StringWriter();
            expected.WriteLine(@"int32_t IL2C_TestTargetClass_Int32MainBody(void)");
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

        [Test]
        public static void SimpleOverallByInt32LargeValueSummationTest()
        {
            var mainMethod = testType.GetMethod("Int32LargeValueMainBody");

            var translateContext = new TranslateContext(testTypeAssembly.Location);
            var tw = new StringWriter();

            var prepared = AssemblyPreparer.Prepare(
                translateContext, method => method.MemberEquals(mainMethod));
            AssemblyWriter.InternalConvertFromMethod(tw, translateContext, prepared, mainMethod, "  ");

            var sourceCode = tw.ToString();

            var expected = new StringWriter();
            expected.WriteLine(@"int32_t IL2C_TestTargetClass_Int32LargeValueMainBody(void)");
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

        [Test]
        public static void SimpleOverallByInt32WithArgumentsSummationTest()
        {
            var mainMethod = testType.GetMethod("Int32WithArgumentsMainBody");

            var translateContext = new TranslateContext(testTypeAssembly.Location);
            var tw = new StringWriter();

            var prepared = AssemblyPreparer.Prepare(
                translateContext, method => method.MemberEquals(mainMethod));
            AssemblyWriter.InternalConvertFromMethod(tw, translateContext, prepared, mainMethod, "  ");

            var sourceCode = tw.ToString();

            var expected = new StringWriter();
            expected.WriteLine(@"int32_t IL2C_TestTargetClass_Int32WithArgumentsMainBody(int32_t a, int32_t b)");
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

        [Test]
        public static void SimpleOverallByInt64SummationTest()
        {
            var mainMethod = testType.GetMethod("Int64MainBody");

            var translateContext = new TranslateContext(testTypeAssembly.Location);
            var tw = new StringWriter();

            var prepared = AssemblyPreparer.Prepare(
                translateContext, method => method.MemberEquals(mainMethod));
            AssemblyWriter.InternalConvertFromMethod(tw, translateContext, prepared, mainMethod, "  ");

            var sourceCode = tw.ToString();

            var expected = new StringWriter();
            expected.WriteLine(@"int64_t IL2C_TestTargetClass_Int64MainBody(void)");
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

        [Test]
        public static void SimpleOverallByInt64LargeValueSummationTest()
        {
            var mainMethod = testType.GetMethod("Int64LargeValueMainBody");

            var translateContext = new TranslateContext(testTypeAssembly.Location);
            var tw = new StringWriter();

            var prepared = AssemblyPreparer.Prepare(
                translateContext, method => method.MemberEquals(mainMethod));
            AssemblyWriter.InternalConvertFromMethod(tw, translateContext, prepared, mainMethod, "  ");

            var sourceCode = tw.ToString();

            var expected = new StringWriter();
            expected.WriteLine(@"int64_t IL2C_TestTargetClass_Int64LargeValueMainBody(void)");
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

        [Test]
        public static void ConditionalBranchTest()
        {
            var mainMethod = testType.GetMethod("ConditionalBranchMainBody");

            var translateContext = new TranslateContext(testTypeAssembly.Location);
            var tw = new StringWriter();

            var prepared = AssemblyPreparer.Prepare(
                translateContext, method => method.MemberEquals(mainMethod));
            AssemblyWriter.InternalConvertFromMethod(tw, translateContext, prepared, mainMethod, "  ");

            var sourceCode = tw.ToString();

            var expected = new StringWriter();
            expected.WriteLine(@"int32_t IL2C_TestTargetClass_ConditionalBranchMainBody(int32_t a)");
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

        #region Value types

        [Test]
        public static void CallStaticMethodTest()
        {
            var mainMethod = testType.GetMethod("CallTestMethod");

            var translateContext = new TranslateContext(testTypeAssembly.Location);
            var tw = new StringWriter();

            var prepared = AssemblyPreparer.Prepare(
                translateContext, method => method.MemberEquals(mainMethod));
            AssemblyWriter.InternalConvertFromMethod(tw, translateContext, prepared, mainMethod, "  ");

            var sourceCode = tw.ToString();

            var expected = new StringWriter();
            expected.WriteLine(@"int32_t IL2C_TestTargetClass_CallTestMethod(void)");
            expected.WriteLine(@"{");
            expected.WriteLine(@"  int32_t local0;");
            expected.WriteLine(@"");
            expected.WriteLine(@"  int32_t __stack0_int32_t;");
            expected.WriteLine(@"  int32_t __stack1_int32_t;");
            expected.WriteLine(@"");
            expected.WriteLine(@"  __stack0_int32_t = 1;");
            expected.WriteLine(@"  __stack1_int32_t = 2;");
            expected.WriteLine(@"  __stack0_int32_t = IL2C_TestTargetClass_CallStaticMethodTestType_Test(__stack0_int32_t, (int16_t)__stack1_int32_t);");
            expected.WriteLine(@"  local0 = __stack0_int32_t;");
            expected.WriteLine(@"  goto L_0000;");
            expected.WriteLine(@"L_0000:");
            expected.WriteLine(@"  __stack0_int32_t = local0;");
            expected.WriteLine(@"  return __stack0_int32_t;");
            expected.WriteLine(@"}");

            Assert.AreEqual(expected.ToString(), sourceCode);
        }

        [Test]
        public static void AccessStaticFieldMethodTest()
        {
            var mainMethod = testType.GetMethod("AccessStaticFieldTestMethod");

            var translateContext = new TranslateContext(testTypeAssembly.Location);
            var tw = new StringWriter();

            var prepared = AssemblyPreparer.Prepare(
                translateContext, method => method.MemberEquals(mainMethod));
            AssemblyWriter.InternalConvertFromMethod(tw, translateContext, prepared, mainMethod, "  ");

            var sourceCode = tw.ToString();

            var expected = new StringWriter();
            expected.WriteLine(@"int32_t IL2C_TestTargetClass_CallStaticMethodWithFieldReferencedTestType_Field0 = 1;");
            expected.WriteLine(@"int64_t IL2C_TestTargetClass_CallStaticMethodWithFieldReferencedTestType_Field1 = 2LL;");
            expected.WriteLine(@"");
            expected.WriteLine(@"int64_t IL2C_TestTargetClass_AccessStaticFieldTestMethod(void)");
            expected.WriteLine(@"{");
            expected.WriteLine(@"  int64_t local0;");
            expected.WriteLine(@"");
            expected.WriteLine(@"  int32_t __stack0_int32_t;");
            expected.WriteLine(@"  int64_t __stack0_int64_t;");
            expected.WriteLine(@"  int64_t __stack1_int64_t;");
            expected.WriteLine(@"");
            expected.WriteLine(@"  __stack0_int32_t = IL2C_TestTargetClass_CallStaticMethodWithFieldReferencedTestType_Field0;");
            expected.WriteLine(@"  __stack0_int64_t = __stack0_int32_t;");
            expected.WriteLine(@"  __stack1_int64_t = IL2C_TestTargetClass_CallStaticMethodWithFieldReferencedTestType_Field1;");
            expected.WriteLine(@"  __stack0_int64_t = __stack0_int64_t + __stack1_int64_t;");
            expected.WriteLine(@"  local0 = __stack0_int64_t;");
            expected.WriteLine(@"  goto L_0000;");
            expected.WriteLine(@"L_0000:");
            expected.WriteLine(@"  __stack0_int64_t = local0;");
            expected.WriteLine(@"  return __stack0_int64_t;");
            expected.WriteLine(@"}");

            Assert.AreEqual(expected.ToString(), sourceCode);
        }

        [Test]
        public static void AccessValueTypeFieldTest()
        {
            Assert.Fail("TODO:");

            var mainMethod = testType.GetMethod("AccessValueTypeFieldMethod");

            var translateContext = new TranslateContext(testTypeAssembly.Location);
            var tw = new StringWriter();

            var targetType = typeof(TestTargetClass.AccessValueTypeFieldTestType);

            var prepared = AssemblyPreparer.Prepare(
                translateContext, method => method.MemberEquals(mainMethod));
            AssemblyWriter.InternalConvertFromMethod(tw, translateContext, prepared, mainMethod, "  ");

            var sourceCode = tw.ToString();

            var expected = new StringWriter();
            expected.WriteLine(@"");

            Assert.AreEqual(expected.ToString(), sourceCode);
        }
        #endregion

    }
}
