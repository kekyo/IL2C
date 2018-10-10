using System;
using System.IO;
using System.Linq;
using System.Linq.Expressions;
using System.Reflection;
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

        public static async Task ExecuteTestAsync(MethodInfo method)
        {
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

            var translatedPath = Path.GetFullPath(
                Path.Combine(Path.GetDirectoryName(method.DeclaringType.Assembly.Location), "translated"));
            await Task.Run(() =>
            {
                if (!Directory.Exists(translatedPath))
                {
                    try
                    {
                        Directory.CreateDirectory(translatedPath);
                    }
                    catch
                    {
                    }
                }
            }).ConfigureAwait(false);

            using (var ms = new MemoryStream())
            {
                var tw = new StreamWriter(ms);

                await tw.WriteLineAsync("#include <il2c.h>");
                await tw.WriteLineAsync();

                AssemblyWriter.InternalConvertFromMethod(tw, translateContext, prepared, targetMethod, "  ");

                var formatChar =
                    (targetMethod.ReturnType.IsByteType) ? "%u" :
                    (targetMethod.ReturnType.IsSByteType) ? "%d" :
                    (targetMethod.ReturnType.IsUInt16Type) ? "%u" :
                    (targetMethod.ReturnType.IsInt16Type) ? "%d" :
                    (targetMethod.ReturnType.IsUInt32Type) ? "%u" :
                    (targetMethod.ReturnType.IsInt32Type) ? "%d" :
                    (targetMethod.ReturnType.IsUInt64Type) ? "%\" PRIu64 \"" :
                    (targetMethod.ReturnType.IsInt64Type) ? "%\" PRId64 \"" :
                    (targetMethod.ReturnType.IsSingleType) ? "%f" :
                    (targetMethod.ReturnType.IsSingleType) ? "%f" :
                    (targetMethod.ReturnType.IsDoubleType) ? "%lf" :
                    "%s";

                await tw.WriteLineAsync();
                await tw.WriteLineAsync("#include <stdio.h>");
                await tw.WriteLineAsync();
                await tw.WriteLineAsync("int main()");
                await tw.WriteLineAsync("{");
                await tw.WriteLineAsync(string.Format("  auto result = {0}();", targetMethod.CLanguageFunctionName));
                await tw.WriteLineAsync(string.Format("  printf(\"{0}\", result);", formatChar));
                await tw.WriteLineAsync(string.Format("  return 0;"));
                await tw.WriteLineAsync("}");

                await tw.FlushAsync();

                ms.Position = 0;
                var tr = new StreamReader(ms);

                var result = await GccDriver.CompileAndRunAsync(
                    translatedPath, targetMethod.CLanguageFunctionName, tr, il2cIncludePath);
                var lines = result.Split(new[] { "\r\n", "\r", "\n" }, StringSplitOptions.RemoveEmptyEntries);

                Assert.AreEqual(expected?.ToString(), lines[0]);
            }
        }

        public static Task ExecuteTestAsync(Type targetType, string methodName)
        {
            var method = targetType.GetMethod(methodName, BindingFlags.Public | BindingFlags.Static);
            return ExecuteTestAsync(method);
        }

        public static Task ExecuteTestAsync<T>(Expression<Func<T>> testFunction)
        {
            var body = (MethodCallExpression)testFunction.Body;
            var method = body.Method;

            return ExecuteTestAsync(method);
        }
    }
}
