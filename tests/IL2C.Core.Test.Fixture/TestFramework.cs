using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Reflection;
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
            if (value is string) return "il2c_new_string(" + Utilities.ToCLanguageLiteralExpression(value) + ")";
            return Utilities.ToCLanguageLiteralExpression(value);
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
                "((il2c_c_str(expected) == NULL) && (il2c_c_str(actual) == NULL)) || \r\n        ((il2c_c_str(expected) != NULL) && (il2c_c_str(actual) != NULL) && (wcscmp(il2c_c_str(expected), il2c_c_str(actual)) == 0))" :
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
                (type.IsBooleanType) ? "%s" :
                (type.IsCharType) ? "'%c'" :
                (type.IsStringType) ? "\\\"%s\\\"" :
                "%s";
        }

        private static string GetCLanguagePrintArgumentExpression(ITypeInformation type, string symbolName)
        {
            return type.IsBooleanType ?
                symbolName + " ? L\"true\" : L\"false\"" :
                type.IsStringType ?
                    string.Format("il2c_c_str({0})", symbolName) :
                    symbolName;
        }
        #endregion

        public static async Task ExecuteTestAsync(
            string categoryName, string testName, object expected, TestCaseAsserts assert,
            MethodInfo method, MethodBase[] additionalMethods, object[] args)
        {
            Assert.IsTrue(method.IsPublic && method.IsStatic);
            foreach (var m in additionalMethods)
            {
                Assert.AreEqual(m.DeclaringType, method.DeclaringType);
            }

            // Split current thread context.
            await Task.Yield();

            ///////////////////////////////////////////////

            // Step 1-1: Create translation context.
            var translateContext = new TranslateContext(method.DeclaringType.Assembly.Location, false);

            // Step 1-2: Prepare target methods.
            var prepared = AssemblyPreparer.Prepare(
                translateContext,
                t => t.FriendlyName == method.DeclaringType.FullName,
                m => ((m.Name == method.Name) || (additionalMethods.FirstOrDefault(am => m.Name == am.Name) != null)));

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
            var header = new StringWriter();
            var body = new StringWriter();
            AssemblyWriter.InternalWriteHeader(
                header, translateContext, prepared, "    ", false);
            AssemblyWriter.InternalWriteSourceCode(
                body, translateContext, prepared, "    ", DebugInformationOptions.Full, false);

            // Step 1-5: Write Visual C++ project file and Visual Studio Code launch config from template.
            //     Note: It's only debugging purpose. The test doesn't use.
            var translatedPath = Path.GetFullPath(
                Path.Combine(
                    Path.GetDirectoryName(method.DeclaringType.Assembly.Location),
                    categoryName,
                    targetMethod.DeclaringType.Name,
                    testName));

            var vcxprojTemplatePath = Path.Combine(translatedPath, "test.vcxproj");
            await TestUtilities.CopyResourceToTextFileAsync(vcxprojTemplatePath, "test.vcxproj");

            var launchTemplatePath = Path.Combine(translatedPath, ".vscode", "launch.json");
            await TestUtilities.CopyResourceToTextFileAsync(launchTemplatePath, "launch.json");

            // Step 1-6: Write source code into a file from template.
            var expectedType = targetMethod.ReturnType;

            var sourceCodeStream = new MemoryStream();
            await TestUtilities.CopyResourceToStreamAsync(
                sourceCodeStream,
                // If the target method result is void-type, we have to use void-type tolerant template.
                (expectedType.IsVoidType || (assert == TestCaseAsserts.CauseBreak)) ? "test_void.c" : "test.c");
            sourceCodeStream.Position = 0;
            var sourceCode = new StreamReader(sourceCodeStream);

            var arguments = args.
                Zip(targetMethod.Parameters, (arg, p) =>
                    (p.SymbolName, p.TargetType, GetCLanguageTypedLiteralExpression(arg, p.TargetType))).
                ToArray();
            var locals = (!(expectedType.IsVoidType || (assert == TestCaseAsserts.CauseBreak)) ?
                new ValueTuple<string, ITypeInformation, string>[]
                {
                    ( "expected", expectedType, GetCLanguageTypedLiteralExpression(expected, targetMethod.ReturnType) ),
                    ( "actual", expectedType, (string)null ),
                } :
                new ValueTuple<string, ITypeInformation, string>[]
                {
                }).
                Concat(arguments);

            // Construct test definitions.
            var replaceValues = new Dictionary<string, object>
            {
                { "testName", targetMethod.FriendlyName},
                { "type", targetMethod.ReturnType.CLanguageTypeName},
                { "body", body.ToString() },
                { "locals", string.Join(" ", locals.
                    Select(entry => string.Format("{0} {1} = {2};",
                        entry.Item2.CLanguageTypeName,
                        entry.Item1,
                        entry.Item2.IsClass ? "NULL" : "0"))) },
                { "frames", string.Join(" ", locals.
                    Where(entry => entry.Item2.IsClass).
                    Select(entry => string.Format("{0}* {1}__;",
                        entry.Item2.CLanguageTypeName,
                        entry.Item1))) },
                { "frameCount", locals.
                    Where(entry => entry.Item2.IsClass).Count() },
                { "frameInitializers", string.Join(" ", locals.
                    Where(entry => entry.Item2.IsClass).
                    Select(entry => string.Format("__executionFrame__.{0}__ = &{0};",
                        entry.Item1))) },
                { "argInitializers", string.Join(" ", arguments.
                    Select(entry => string.Format("{0} = {1};",
                        entry.Item1, entry.Item3))) },
                { "expected", GetCLanguageTypedLiteralExpression(expected, targetMethod.ReturnType)},
                { "function", targetMethod.CLanguageFunctionName},
                { "arguments", string.Join(", ", arguments.
                    Select(arg => arg.SymbolName))},
                { "equality", GetCLanguageCompareExpression(expectedType)},
                { "format", GetCLanguagePrintFormatFromType(targetMethod.ReturnType)},
                { "expectedExpression", GetCLanguagePrintArgumentExpression(expectedType, "expected")},
                { "actualExpression", GetCLanguagePrintArgumentExpression(expectedType, "actual")},
            };

            var sourcePath = Path.Combine(translatedPath, "test.c");
            var headerPath = Path.Combine(translatedPath, "test.h");

            await Task.WhenAll(
                TestUtilities.WriteTextFileAsync(sourcePath, sourceCode, replaceValues),
                TestUtilities.WriteTextFileAsync(headerPath, header.ToString()));

            ///////////////////////////////////////////////
            // Step 2: Test and verify result by real IL code at this runtime.

            object rawResult;
            switch (assert)
            {
                case TestCaseAsserts.IgnoreInvokeResult:
                    rawResult = method.Invoke(null, args);
                    break;
                case TestCaseAsserts.CauseBreak:
                    rawResult = null;
                    break;
                default:
                    rawResult = method.Invoke(null, args);
                    Assert.AreEqual(expected, rawResult);
                    break;
            }

            ///////////////////////////////////////////////
            // Step 3: Test compiled C source code and execute.

            string sanitized = null;
            try
            {
                var il2cRuntimeSourcePaths = new[] {
                    // Use combined runtime source. 5 times faster!
                    Path.Combine(il2cRuntimePath, "il2c_combined.c")
                };
                var executedResult = await GccDriver.CompileAndRunAsync(sourcePath, il2cRuntimePath);
                sanitized = executedResult.Trim(' ', '\r', '\n');
            }
            catch (Exception ex)
            {
                if ((assert == TestCaseAsserts.CauseBreak) && ex.Message.Contains("ExitCode=-2147483645"))
                {
                    return;
                }
                throw;
            }

            Assert.IsFalse(assert == TestCaseAsserts.CauseBreak, "Code didn't break.");

            ///////////////////////////////////////////////
            // Step 4: Verify result.

            Assert.AreEqual("Success", sanitized);
        }
    }
}
