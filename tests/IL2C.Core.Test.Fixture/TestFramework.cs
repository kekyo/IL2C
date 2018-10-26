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

        private static string GetCLangaugeSafeConversionExpression(
            ITypeInformation argumentType, Type constantType, string constantExpression)
        {
            // abbrev
            if (constantType != null)
            {
                if (TestUtilities.GetCLanguageTypeName(constantType) == argumentType.CLanguageTypeName)
                {
                    return constantExpression;
                }
                else if (constantType == typeof(string))
                {
                    return string.Format("({0})il2c_new_string({1})",
                        argumentType.CLanguageTypeName,
                        constantExpression);
                }
                else if (argumentType.IsObjectType && constantType.IsValueType)
                {
                    return string.Format("il2c_box(&{0}, {1})",
                        constantExpression,
                        Utilities.ToMangledName(constantType.FullName));
                }
            }

            return string.Format("({0}){1}", argumentType.CLanguageTypeName, constantExpression);
        }

        private static string GetCLanguageCompareExpression(ITypeInformation type)
        {
            return type.IsStringType ?
                "((il2c_c_str(_expected) == NULL) && (il2c_c_str(actual) == NULL)) || \r\n        ((il2c_c_str(_expected) != NULL) && (il2c_c_str(actual) != NULL) && (wcscmp(il2c_c_str(_expected), il2c_c_str(actual)) == 0))" :
                "_expected == actual";
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

        private struct Constant
        {
            public readonly string SymbolName;
            public readonly ITypeInformation TargetType;
            public readonly Type ExpressionType;
            public readonly string Expression;

            public Constant(string symbolName, ITypeInformation targetType, Type expressionType, string expression)
            {
                this.SymbolName = symbolName;
                this.TargetType = targetType;
                this.ExpressionType = expressionType;
                this.Expression = expression;
            }
        }

        public static async Task ExecuteTestAsync(
            string categoryName, string subCategoryName, string testName, object expected, TestCaseAsserts assert,
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
                    subCategoryName,
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

            var constants = args.
                Zip(targetMethod.Parameters, (arg, p) => new Constant(
                    p.SymbolName,
                    p.TargetType,
                    arg?.GetType(),
                    Utilities.ToCLanguageLiteralExpression(arg))
                ).
                ToArray();
            var argumentList = constants.
                Select(constant => new Constant(
                    "_" + constant.SymbolName,
                    constant.TargetType,
                    null,
                    GetCLangaugeSafeConversionExpression(constant.TargetType, constant.ExpressionType, constant.SymbolName))).
                ToArray();

            var arguments = argumentList;
            var locals = argumentList.
                Select(argument =>
                    new Constant(
                        argument.SymbolName,
                        argument.TargetType,
                        argument.ExpressionType,
                        Utilities.ToCLanguageLiteralExpression(expectedType.EmptyValue))).
                ToArray();

            if (!(expectedType.IsVoidType || (assert == TestCaseAsserts.CauseBreak)))
            {
                // VERY DIRTY:
                constants = constants.Concat(new Constant[]
                    {
                        new Constant(
                            "expected",
                            expectedType,
                            expected?.GetType(),
                            Utilities.ToCLanguageLiteralExpression(expected)),
                    }).
                    ToArray();
                arguments = constants.
                    Select(constant => new Constant(
                        "_" + constant.SymbolName,
                        constant.TargetType,
                        null,
                        GetCLangaugeSafeConversionExpression(constant.TargetType, constant.ExpressionType, constant.SymbolName))).
                    ToArray();
                locals = arguments.
                    Select(argument =>
                        new Constant(
                            argument.SymbolName,
                            argument.TargetType,
                            argument.ExpressionType,
                            Utilities.ToCLanguageLiteralExpression(argument.TargetType.EmptyValue))).
                    Concat(new Constant[]
                    {
                        new Constant(
                            "actual",
                            expectedType,
                            expected?.GetType(),
                            Utilities.ToCLanguageLiteralExpression(expectedType.EmptyValue)),
                    }).
                    ToArray();
            }

            // Construct test definitions.
            var replaceValues = new Dictionary<string, object>
            {
                { "testName", targetMethod.FriendlyName},
                { "type", targetMethod.ReturnType.CLanguageTypeName},
                { "body", body.ToString() },
                { "constants", string.Join(" ", constants.
                    Select(entry => string.Format("{0} {1} = {2};",
                        (entry.ExpressionType != null) ? TestUtilities.GetCLanguageTypeName(entry.ExpressionType) : entry.TargetType.CLanguageTypeName,
                        entry.SymbolName,
                        entry.Expression))) },
                { "locals", string.Join(" ", locals.
                    Select(entry => string.Format("{0} {1} = {2};",
                        entry.TargetType.CLanguageTypeName,
                        entry.SymbolName,
                        entry.Expression))) },
                { "frames", string.Join(" ", locals.
                    Where(entry => entry.TargetType.IsClass).
                    Select(entry => string.Format("{0}* {1}__;",
                        entry.TargetType.CLanguageTypeName,
                        entry.SymbolName))) },
                { "frameCount", locals.
                    Where(entry => entry.TargetType.IsClass).Count() },
                { "frameInitializers", string.Join(" ", locals.
                    Where(entry => entry.TargetType.IsClass).
                    Select(entry => string.Format("__executionFrame__.{0}__ = &{0};",
                        entry.SymbolName))) },
                { "arguments", string.Join(" ", arguments.
                    Select(entry => string.Format("{0} = {1};",
                        entry.SymbolName, entry.Expression))) },
                { "function", targetMethod.CLanguageFunctionName},
                { "argumentList", string.Join(", ", argumentList.
                    Select(arg => arg.SymbolName))},
                { "equality", GetCLanguageCompareExpression(expectedType)},
                { "format", GetCLanguagePrintFormatFromType(targetMethod.ReturnType)},
                { "expectedExpression", GetCLanguagePrintArgumentExpression(expectedType, "_expected")},
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
