using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
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
            if (constantType != null)
            {
                if (Utilities.GetCLanguageTypeName(constantType) == argumentType.CLanguageTypeName)
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
                    return string.Format("(System_Object*)il2c_box(&{0}, {1})",
                        constantExpression,
                        Utilities.GetMangledName(constantType.FullName));
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

        public static async Task ExecuteTestAsync(TestCaseInformation caseInfo)
        {
            Assert.IsTrue(caseInfo.Method.IsPublic && caseInfo.Method.IsStatic);

            // Split current thread context.
            await Task.Yield();

            ///////////////////////////////////////////////

            // Step 1-1: Create translation context.
            var translateContext = new TranslateContext(caseInfo.Method.DeclaringType.Assembly.Location, false);

            // Step 1-2: Prepare target methods.
            var targetTypes = new HashSet<string>(
                new[] { caseInfo.Method }.
                Concat(caseInfo.AdditionalMethods).
                Select(method => method.DeclaringType).
                Concat(caseInfo.AdditionalTypes).
                Select(type => type.FullName).
                Distinct());
            var targetMethods = new[] { caseInfo.Method }.
                Concat(caseInfo.AdditionalMethods).
                GroupBy(method => method.Name).
                ToDictionary(g => g.Key, g => g.ToArray());

            var prepared = AssemblyPreparer.Prepare(
                translateContext,
                t => targetTypes.Contains(t.FriendlyName),
                m => targetMethods.ContainsKey(m.Name));

            // Step 1-3: Extract prepared target type/caseInfo.Method informations.
            var targetType =
                translateContext.Assembly.Modules
                .First().Types
                .First(t => t.FriendlyName == caseInfo.Method.DeclaringType.FullName);
            var targetMethod =
                targetType.DeclaredMethods
                .First(m => m.Name == caseInfo.Method.Name);
            var targetAdditionalMethods =
                targetType.DeclaredMethods
                .Where(m => (caseInfo.AdditionalMethods.FirstOrDefault(am => m.Name == am.Name) != null))
                .ToArray();

            // Step 1-4: Translate caseInfo.Method bodies.
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
                    Path.GetDirectoryName(caseInfo.Method.DeclaringType.Assembly.Location),
                    caseInfo.CategoryName,
                    caseInfo.Id,
                    caseInfo.Name));

            var vcxprojTemplatePath = Path.Combine(translatedPath, "test.vcxproj");
            await TestUtilities.CopyResourceToTextFileAsync(vcxprojTemplatePath, "test.vcxproj");

            var launchTemplatePath = Path.Combine(translatedPath, ".vscode", "launch.json");
            await TestUtilities.CopyResourceToTextFileAsync(launchTemplatePath, "launch.json");

            // Step 1-6: Write source code into a file from template.
            var expectedType = targetMethod.ReturnType;

            var sourceCodeStream = new MemoryStream();
            await TestUtilities.CopyResourceToStreamAsync(
                sourceCodeStream,
                // If the target caseInfo.Method result is void-type, we have to use void-type tolerant template.
                (expectedType.IsVoidType || (caseInfo.Assert == TestCaseAsserts.CauseBreak)) ? "test_void.c" : "test.c");
            sourceCodeStream.Position = 0;
            var sourceCode = new StreamReader(sourceCodeStream);

            var constants = caseInfo.Arguments.
                Zip(targetMethod.Parameters, (arg, p) => new Constant(
                    p.SymbolName,
                    p.TargetType,
                    arg?.GetType(),
                    Utilities.GetCLanguageExpression(arg))
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
                        Utilities.GetCLanguageExpression(expectedType.PseudoEmptyValue))).
                ToArray();

            if (!(expectedType.IsVoidType || (caseInfo.Assert == TestCaseAsserts.CauseBreak)))
            {
                // VERY DIRTY:
                constants = constants.Concat(new Constant[]
                    {
                        new Constant(
                            "expected",
                            expectedType,
                            caseInfo.Expected?.GetType(),
                            Utilities.GetCLanguageExpression(caseInfo.Expected)),
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
                            Utilities.GetCLanguageExpression(argument.TargetType.PseudoEmptyValue))).
                    Concat(new Constant[]
                    {
                        new Constant(
                            "actual",
                            expectedType,
                            caseInfo.Expected?.GetType(),
                            Utilities.GetCLanguageExpression(expectedType.PseudoEmptyValue)),
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
                        (entry.ExpressionType != null) ? Utilities.GetCLanguageTypeName(entry.ExpressionType) : entry.TargetType.CLanguageTypeName,
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
            switch (caseInfo.Assert)
            {
                case TestCaseAsserts.IgnoreValidateInvokeResult:
                    rawResult = caseInfo.Method.Invoke(null, caseInfo.Arguments);
                    break;
                case TestCaseAsserts.CauseBreak:
                    rawResult = null;
                    break;
                default:
                    rawResult = caseInfo.Method.Invoke(null, caseInfo.Arguments);
                    Assert.AreEqual(caseInfo.Expected, rawResult);
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

                // TODO: !optimize
                var executedResult = await GccDriver.CompileAndRunAsync(false, sourcePath, il2cRuntimePath);
                sanitized = executedResult.Trim(' ', '\r', '\n');
            }
            catch (Exception ex)
            {
                if ((caseInfo.Assert == TestCaseAsserts.CauseBreak) && ex.Message.Contains("ExitCode=-2147483645"))
                {
                    return;
                }
                throw;
            }

            Assert.IsFalse(caseInfo.Assert == TestCaseAsserts.CauseBreak, "Code didn't break.");

            ///////////////////////////////////////////////
            // Step 4: Verify result.

            Assert.AreEqual("Success", sanitized);
        }
    }
}
