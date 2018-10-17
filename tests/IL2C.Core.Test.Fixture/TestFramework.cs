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
        #region Test infrastructures
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
            if (value is int) return ILConverters.LdcConverterUtilities.ToCLanguageExpression((int)value);
            if (value is uint) return ILConverters.LdcConverterUtilities.ToCLanguageExpression((uint)value);
            if (value is long) return ILConverters.LdcConverterUtilities.ToCLanguageExpression((long)value);
            if (value is ulong) return ILConverters.LdcConverterUtilities.ToCLanguageExpression((ulong)value);
            if (value is IntPtr) return string.Format("(intptr_t)({0})", ILConverters.LdcConverterUtilities.ToCLanguageExpression(((IntPtr)value).ToInt64()));
            if (value is UIntPtr) return string.Format("(uintptr_t)({0})", ILConverters.LdcConverterUtilities.ToCLanguageExpression(((UIntPtr)value).ToUInt64()));
            if (value is float) return ILConverters.LdcConverterUtilities.ToCLanguageExpression((float)value);
            if (value is double) return ILConverters.LdcConverterUtilities.ToCLanguageExpression((double)value);
            if (value is bool) return (bool)value ? "true" : "false";
            if (value is char) return "L'" + value + "'";
            if (value is string) return "il2c_new_string(L\"" + value + "\")";
            return value.ToString();
        }

        private static string GetCLanguageTypedLiteralExpression(object value, ITypeInformation type)
        {
            return ((value != null) && (value.GetType().FullName == type.FriendlyName)) ?
                GetCLanguageLiteralExpression(value) :
                string.Format("({0})({1})", type.CLanguageTypeName, GetCLanguageLiteralExpression(value));
        }

        private static string GetCLanguageCompareExpression(ITypeInformation type)
        {
            return type.IsStringType ?
                "wcscmp(il2c_c_str(expected), il2c_c_str(actual)) == 0" :
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
                    string.Format("il2c_c_str({0})", symbolName) :
                    symbolName;
        }
        #endregion

        public static readonly object Expected_TrapBreak = new object();

        public static async Task ExecuteTestAsync(
            string testName, MethodInfo method, MethodInfo[] additionalMethods, object expected, object[] args)
        {
            Assert.IsTrue(method.IsPublic && method.IsStatic);
            foreach (var m in additionalMethods)
            {
                Assert.AreEqual(m.DeclaringType, method.DeclaringType);
            }

            // Split current thread context.
            await Task.Yield();

            var isTrapBreak = object.ReferenceEquals(expected, Expected_TrapBreak);

            ///////////////////////////////////////////////

            // Step 1-1: Create translation context.
            var translateContext = new TranslateContext(method.DeclaringType.Assembly.Location, false);

            // Step 1-2: Prepare target methods.
            var prepared = AssemblyPreparer.Prepare(
                translateContext,
                m =>
                    (m.DeclaringType.FriendlyName == method.DeclaringType.FullName) &&
                    ((m.Name == method.Name) || (additionalMethods.FirstOrDefault(am => m.Name == am.Name) != null)));

            // Step 1-3: Extract prepared target type/method informations.
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

            // Step 1-4: Translate method bodies.
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

            // Step 1-5: Write Visual C++ project file from template.
            //     Note: It's only debugging purpose. The test doesn't use.
            var translatedPath = Path.GetFullPath(
                Path.Combine(
                    Path.GetDirectoryName(method.DeclaringType.Assembly.Location),
                    "translated",
                    targetMethod.DeclaringType.Name,
                    testName));

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

            // Step 1-6: Write source code into a file from template.
            var expectedType = targetMethod.ReturnType;

            var sourceCode = new StringBuilder();
            using (var ts = typeof(TestFramework).Assembly.GetManifestResourceStream(
                // If the target method result is void-type, we have to use void-type tolerant template.
                (expectedType.IsVoidType || isTrapBreak) ? "IL2C.Templates.test_void.c" : "IL2C.Templates.test.c"))
            {
                var tr = new StreamReader(ts);
                sourceCode.Append(await tr.ReadToEndAsync());
            }

            sourceCode.Replace("{body}", body.ToString());

            sourceCode.Replace("{isRefType}", (expectedType.IsByReference || expectedType.IsClass) ? "1" : "0");

            sourceCode.Replace("{type}", targetMethod.ReturnType.CLanguageTypeName);
            sourceCode.Replace("{expected}", GetCLanguageTypedLiteralExpression(expected, targetMethod.ReturnType));
            sourceCode.Replace("{function}", targetMethod.CLanguageFunctionName);
            sourceCode.Replace("{arguments}", string.Join(
                ", ",
                args.Zip(targetMethod.Parameters, (arg, p) => GetCLanguageTypedLiteralExpression(arg, p.TargetType))));
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

            ///////////////////////////////////////////////

            // Step 2: Test and verify result by real IL code at this runtime.
            if (!isTrapBreak)
            {
                var rawResult = method.Invoke(null, args);
                Assert.AreEqual(expected, rawResult);
            }

            ///////////////////////////////////////////////

            string sanitized = null;
            try
            {
                // Step 3: Test compiled C source code and execute.
                var il2cRuntimeSourcePaths = new[] {
                    // Use combined runtime source. 5 times faster!
                    Path.Combine(il2cRuntimePath, "il2c_combined.c")
                };
                var executedResult = await GccDriver.CompileAndRunAsync(sourcePath, il2cRuntimeSourcePaths, il2cRuntimePath);
                sanitized = executedResult.Trim(' ', '\r', '\n');
            }
            catch (Exception ex)
            {
                if (isTrapBreak && ex.Message.Contains("ExitCode=-1073741795"))
                {
                    return;
                }
                throw;
            }

            Assert.IsFalse(isTrapBreak, "Code didn't break.");

            ///////////////////////////////////////////////

            // Step 4: Verify result.
            Assert.AreEqual("Success", sanitized);
        }
    }
}
