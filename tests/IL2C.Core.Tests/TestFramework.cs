using System;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Threading.Tasks;

using IL2C.Metadata;
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

        private static string GetCLanguageLiteralExpression(object value)
        {
            if (value == null) return "NULL";
            // String instance will leak but no problem for test.
            if (value is string) return "il2c_new_string(L\"" + value + "\")";
            if (value is char) return "il2c_new_string(L\"" + value + "\")";
            if (value is long) return string.Format("INT64_C({0})", value);
            if (value is ulong) return string.Format("UINT64_C({0})", value);
            if (value is int) return string.Format("INT32_C({0})", value);
            if (value is uint) return string.Format("UINT32_C({0})", value);
            if (value is short) return string.Format("INT16_C({0})", value);
            if (value is ushort) return string.Format("UINT16_C({0})", value);
            if (value is byte) return string.Format("UINT8_C({0})", value);
            if (value is sbyte) return string.Format("INT8_C({0})", value);
            return value.ToString();
        }

        private static string GetCLanguagePrintFormatFromType(ITypeInformation type)
        {
            return
                (type.IsByteType) ? "%u" :
                (type.IsSByteType) ? "%d" :
                (type.IsUInt16Type) ? "%u" :
                (type.IsInt16Type) ? "%d" :
                (type.IsUInt32Type) ? "%u" :
                (type.IsInt32Type) ? "%d" :
                (type.IsUInt64Type) ? "%lld" :
                (type.IsInt64Type) ? "%llu" :
                (type.IsSingleType) ? "%f" :
                (type.IsDoubleType) ? "%lf" :
                (type.IsBooleanType) ? "%d" :
                "%s";
        }

        public static async Task ExecuteTestAsync(MethodInfo method, object expected, object[] args)
        {
            Assert.IsTrue(method.IsPublic && method.IsStatic);

            var rawResult = method.Invoke(null, args);
            Assert.AreEqual(expected, rawResult);

            var translateContext = new TranslateContext(method.DeclaringType.Assembly.Location, false);

            var prepared = AssemblyPreparer.Prepare(
                translateContext, m => m.Name == method.Name);

            var targetMethod =
                translateContext.Assembly.Modules
                .First().Types
                .First(t => t.FriendlyName == method.DeclaringType.FullName).DeclaredMethods
                .First(m => m.Name == method.Name);

            var translatedPath = Path.GetFullPath(
                Path.Combine(
                    Path.GetDirectoryName(method.DeclaringType.Assembly.Location),
                    "translated",
                    targetMethod.CLanguageFunctionName));
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

            var sourcePath = Path.Combine(translatedPath, "test.c");
            using (var fs = new FileStream(sourcePath, FileMode.Create, FileAccess.ReadWrite, FileShare.None, 65536, true))
            {
                var tw = new StreamWriter(fs);

                await tw.WriteLineAsync("#include <il2c.h>");

                AssemblyWriter.InternalConvertFromMethod(
                    tw, translateContext, prepared, targetMethod, "  ", DebugInformationOptions.Full);

                var formatChar = GetCLanguagePrintFormatFromType(targetMethod.ReturnType);

                await tw.WriteLineAsync();
                await tw.WriteLineAsync("//////////////////////////////////////////////////////");
                await tw.WriteLineAsync();
                await tw.WriteLineAsync("#include <stdio.h>");
                await tw.WriteLineAsync();
                await tw.WriteLineAsync("int main()");
                await tw.WriteLineAsync("{");
                await tw.WriteLineAsync(
                    string.Format("  const {0} expected = {1};",
                        targetMethod.ReturnType.CLanguageTypeName,
                        GetCLanguageLiteralExpression(expected)));
                await tw.WriteLineAsync(
                    string.Format("  const {0} actual = {1}({2});",
                        targetMethod.ReturnType.CLanguageTypeName,
                        targetMethod.CLanguageFunctionName,
                        string.Join(",", args.Select(GetCLanguageLiteralExpression))));
                await tw.WriteLineAsync();
                await tw.WriteLineAsync("  if (expected == actual) { printf(\"Success\\n\"); return 0; }");
                await tw.WriteLineAsync(string.Format("  else {{ printf(\"Failed: {0}\\n\", actual); return 1; }}", formatChar));
                await tw.WriteLineAsync("}");

                await tw.FlushAsync();
            }

            var executedResult = await GccDriver.CompileAndRunAsync(sourcePath, il2cIncludePath);
            var sanitized = executedResult.Trim(' ', '\r', '\n');

            Assert.AreEqual("Success", sanitized);
        }
    }
}
