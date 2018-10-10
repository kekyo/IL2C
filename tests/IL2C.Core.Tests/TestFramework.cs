using System;
using System.IO;
using System.Linq;
using System.Linq.Expressions;
using System.Threading.Tasks;

using NUnit.Framework;

namespace IL2C
{
    public static class TestFramework
    {
        private static readonly string il2cIncludePath =
            Path.GetFullPath(
                Path.Combine(
                    Path.GetDirectoryName(typeof(TestFramework).Assembly.Location),
                    "..",
                    "..",
                    "..",
                    "..",
                    "..",
                    "IL2C.Runtime"));

        public static async Task ExecuteTestAsync<T>(Expression<Func<T>> testFunction)
        {
            var body = (MethodCallExpression)testFunction.Body;
            var method = body.Method;

            Assert.IsTrue(method.IsPublic && method.IsStatic);

            var expected = method.Invoke(null, null);

            var translateContext = new TranslateContext(method.DeclaringType.Assembly.Location, false);

            var prepared = AssemblyPreparer.Prepare(
                translateContext, m => m.Name == method.Name);

            var targetMethod =
                translateContext.Assembly.Modules
                .First().Types
                .First(t => t.FriendlyName == method.DeclaringType.FullName).DeclaredMethods
                .First(m => m.Name == method.Name);

            var tw = new StringWriter();
            tw.WriteLine("#include <il2c.h>");
            tw.WriteLine();

            AssemblyWriter.InternalConvertFromMethod(tw, translateContext, prepared, targetMethod, "  ");

            tw.WriteLine();
            tw.WriteLine("#include <stdio.h>");
            tw.WriteLine();
            tw.WriteLine("int main()");
            tw.WriteLine("{");
            tw.WriteLine(string.Format("  auto result = {0}();", targetMethod.CLanguageFunctionName));
            tw.WriteLine(string.Format("  printf(\"%d\", result);"));
            tw.WriteLine(string.Format("  return 0;"));
            tw.WriteLine("}");

            var sourceCode = tw.ToString();

            var result = await GccDriver.CompileAndRunAsync(new StringReader(sourceCode), il2cIncludePath);
            var lines = result.Split(new[] { "\r\n", "\r", "\n" }, StringSplitOptions.None);

            Assert.AreEqual(expected?.ToString(), lines[0]);
        }
    }
}
