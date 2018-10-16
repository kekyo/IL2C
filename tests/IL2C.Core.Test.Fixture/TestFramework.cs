using System;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Text;
using System.Threading.Tasks;

using NUnit.Framework;

using IL2C.Metadata;

namespace IL2C
{
    public static class TestFramework
    {
        private static readonly string il2cRuntimePath =
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
            if (value.Equals(int.MinValue)) return "INT32_MIN";
            if (value.Equals(long.MinValue)) return "INT64_MIN";
            if (value is long) return string.Format("INT64_C({0})", value);
            if (value is ulong) return string.Format("UINT64_C({0})", value);
            if (value is uint) return string.Format("UINT32_C({0})", value);
            if (value.Equals(new IntPtr(int.MinValue))) return "INT32_MIN";
            try
            {
                if (value.Equals(new IntPtr(long.MinValue))) return "INT64_MIN";
            }
            catch (OverflowException)
            {
            }
            if (value is IntPtr) return string.Format("(intptr_t)INT64_C({0})", ((IntPtr)value).ToInt64());
            if (value is UIntPtr) return string.Format("(uintptr_t)UINT64_C({0})", ((UIntPtr)value).ToUInt64());
            if (value is float) return string.Format("{0:g9}f", value);
            if (value is double) return string.Format("{0:g17}", value);
            if (value is bool) return (bool)value ? "true" : "false";
            if (value is char) return "L'" + value + "'";
            if (value is string) return "il2c_new_string(L\"" + value + "\")";
            return value.ToString();
        }

        private static string GetCLanguageCompareExpression(ITypeInformation type)
        {
            return type.IsStringType ?
                "wcscmp(expected->string_body__, actual->string_body__) == 0" :
                "expected == actual";
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
                (type.IsIntPtrType) ? "0x%08x" :
                (type.IsUIntPtrType) ? "0x%08x" :
                (type.IsBooleanType) ? "%d" :
                (type.IsCharType) ? "'%c'" :
                (type.IsStringType) ? "\\\"%s\\\"" :
                "%s";
        }

        private static string GetCLanguagePrintArgumentExpression(ITypeInformation type, string symbolName)
        {
            return type.IsBooleanType ?
                symbolName + " ? \"true\" : \"false\"" :
                type.IsStringType ?
                    symbolName + "->string_body__" :
                    symbolName;
        }

        public static async Task ExecuteTestAsync(
            MethodInfo method, MethodInfo[] additionalMethods, object expected, object[] args)
        {
            Assert.IsTrue(method.IsPublic && method.IsStatic);
            foreach (var m in additionalMethods)
            {
                Assert.IsTrue(m.IsPublic && m.IsStatic);
                Assert.AreEqual(m.DeclaringType, method.DeclaringType);
            }

            // Split current thread context.
            await Task.Yield();

            var translateContext = new TranslateContext(method.DeclaringType.Assembly.Location, false);

            var prepared = AssemblyPreparer.Prepare(
                translateContext,
                m =>
                    (m.DeclaringType.FriendlyName == method.DeclaringType.FullName) &&
                    ((m.Name == method.Name) || (additionalMethods.FirstOrDefault(am => m.Name == am.Name) != null)));

            var targetType =
                translateContext.Assembly.Modules
                .First().Types
                .First(t => t.FriendlyName == method.DeclaringType.FullName);

            var targetMethod =
                targetType.DeclaredMethods
                .First(m => m.Name == method.Name);
            var targetAdditionalMethods =
                targetType.DeclaredMethods
                .Where(m => (additionalMethods.FirstOrDefault(am => m.Name == am.Name) != null))
                .ToArray();

            var body = new StringWriter();
            AssemblyWriter.WriteConstStrings(
                body, translateContext);
            foreach (var tam in targetAdditionalMethods)
            {
                AssemblyWriter.InternalConvertFromMethod(
                    body, translateContext, prepared, tam, "  ", DebugInformationOptions.Full);
            }
            AssemblyWriter.InternalConvertFromMethod(
                body, translateContext, prepared, targetMethod, "  ", DebugInformationOptions.Full);

            var translatedPath = Path.GetFullPath(
                Path.Combine(
                    Path.GetDirectoryName(method.DeclaringType.Assembly.Location),
                    "translated",
                    targetMethod.DeclaringType.Name,
                    targetMethod.Name));

            while (!Directory.Exists(translatedPath))
            {
                try
                {
                    Directory.CreateDirectory(translatedPath);
                }
                catch (IOException)
                {
                }
            }

            var templatePath = Path.Combine(translatedPath, "test.vcxproj");
            using (var fs = await TestUtilities.CreateStreamAsync(templatePath))
            {
                using (var ts = typeof(TestFramework).Assembly.GetManifestResourceStream("IL2C.Templates.test.vcxproj"))
                {
                    await ts.CopyToAsync(fs);
                    await fs.FlushAsync();
                }

                fs.Close();
            }

            var sourceCode = new StringBuilder();
            using (var ts = typeof(TestFramework).Assembly.GetManifestResourceStream("IL2C.Templates.test.c"))
            {
                var tr = new StreamReader(ts);
                sourceCode.Append(await tr.ReadToEndAsync());
            }

            sourceCode.Replace("{body}", body.ToString());

            var expectedType = targetMethod.ReturnType;
            sourceCode.Replace("{isRefType}", (expectedType.IsByReference || expectedType.IsClass) ? "1" : "0");

            sourceCode.Replace("{type}", targetMethod.ReturnType.CLanguageTypeName);
            sourceCode.Replace("{expected}", GetCLanguageLiteralExpression(expected));
            sourceCode.Replace("{function}", targetMethod.CLanguageFunctionName);
            sourceCode.Replace("{arguments}", string.Join(", ", args.Select(GetCLanguageLiteralExpression)));
            sourceCode.Replace("{equality}", GetCLanguageCompareExpression(expectedType));
            sourceCode.Replace("{format}", GetCLanguagePrintFormatFromType(targetMethod.ReturnType));
            sourceCode.Replace("{expectedExpression}", GetCLanguagePrintArgumentExpression(expectedType, "expected"));
            sourceCode.Replace("{actualExpression}", GetCLanguagePrintArgumentExpression(expectedType, "actual"));

            var sourcePath = Path.Combine(translatedPath, "test.c");
            using (var fs = await TestUtilities.CreateStreamAsync(sourcePath))
            {
                var tw = new StreamWriter(fs);

                await tw.WriteAsync(sourceCode.ToString());
                await tw.FlushAsync();

                fs.Close();
            }

            // Step1: Test real IL code at this runtime.
            var rawResult = method.Invoke(null, args);
            Assert.AreEqual(expected, rawResult);

            // Step2: Test compiled C source code and execute.
            var il2cRuntimeSourcePath = Path.Combine(il2cRuntimePath, "il2c.c");
            var executedResult = await GccDriver.CompileAndRunAsync(sourcePath, new[] { il2cRuntimeSourcePath }, il2cRuntimePath);
            var sanitized = executedResult.Trim(' ', '\r', '\n');

            Assert.AreEqual("Success", sanitized);
        }
    }
}
