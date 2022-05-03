/////////////////////////////////////////////////////////////////////////////////////////////////
//
// IL2C - A translator for ECMA-335 CIL/MSIL to C language.
// Copyright (c) 2016-2019 Kouji Matsui (@kozy_kekyo, @kekyo2)
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//	http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
/////////////////////////////////////////////////////////////////////////////////////////////////

using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Threading.Tasks;

using NUnit.Framework;

using IL2C.Metadata;
using IL2C.Internal;
using NUnit.Framework.Internal;
using NUnit.Framework.Interfaces;
using ILVerify;

#pragma warning disable CS0436

namespace IL2C
{
    public static class TestFramework
    {
        #region Test infrastructures
        private static readonly string binPath =
            Path.GetFullPath(
                Path.Combine(
                    Path.GetDirectoryName(typeof(TestFramework).Assembly.Location),
                    "..",
                    "..",
                    "..",
                    "..",
                    "..",
                    "toolchain",
                    "gcc4",
                    "bin"));

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

        private static string GetCLanguageCompareExpression(
            ITypeInformation type, string expectedSymbolName, string actualSymbolName)
        {
            return
                type.IsStringType ?
                    string.Format(
                        "((il2c_c_str({0}) == NULL) && (il2c_c_str({1}) == NULL)) || \r\n        ((il2c_c_str({0}) != NULL) && (il2c_c_str({1}) != NULL) && (wcscmp(il2c_c_str({0}), il2c_c_str({1})) == 0))",
                        expectedSymbolName,
                        actualSymbolName) :
                // HACK: gcc4 causes difference larger than DBL_EPSILON at float32 div float64 calculation.
                (type.IsDoubleType || type.IsSingleType) ?
                    string.Format(
                        "fabs({0} - {1}) < FLT_EPSILON",
                        expectedSymbolName,
                        actualSymbolName) :
                string.Format(
                    "{0} == {1}",
                    expectedSymbolName,
                    actualSymbolName);
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
                (type.IsUInt64Type) ? "%llu" :
                (type.IsInt64Type) ? "%lld" :
                (type.IsSingleType) ? "%f" :
                (type.IsDoubleType) ? "%lf" :
                (type.IsIntPtrType) ? "0x%08x" :
                (type.IsUIntPtrType) ? "0x%08x" :
                (type.IsBooleanType) ? "%s" :
                (type.IsCharType) ? "'%c'" :
                (type.IsStringType) ? "\\\"%s\\\"" :
                (type.IsEnum) ? GetCLanguagePrintFormatFromType(type.ElementType) :
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

        private static readonly ILVerifier ilVerifier = new ILVerifier();

        public static async Task ExecuteTestAsync(TestCaseInformation caseInfo)
        {
            Assert.IsTrue(caseInfo.Method.IsPublic && caseInfo.Method.IsStatic);

            // Split current thread context.
            await Task.Delay(1);

#if DEBUG
            const string configuration = "Debug";
#else
            const string configuration = "Release";
#endif

            ///////////////////////////////////////////////

            // Step 1-1: Create translation context.
            var translateContext = new TranslateContext(
                caseInfo.Method.DeclaringType.Assembly.Location,
                true,
                TargetPlatforms.Generic);

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

            // Step 1-4: Create storing director for test artifacts
            //   HACK: It's reliability for Windows MAX_PATH limitation.
            var basePath =
                Path.GetFullPath(
                    Path.Combine(
                        Path.GetDirectoryName(caseInfo.Method.DeclaringType.Assembly.Location),
                        "..", "..", "..", "..", "..",
                        "test-artifacts",
                        configuration,
                        ThisAssembly.AssemblyMetadata.TargetFramework));
            while (true)
            {
                try
                {
                    if (!Directory.Exists(basePath))
                    {
                        Directory.CreateDirectory(basePath);
                    }
                    break;
                }
                catch
                {
                }
            }

            // Step 1-4: Translate caseInfo.Method bodies.
            var translatedPath =
                Path.Combine(
                    basePath,
                    caseInfo.CategoryName,
                    caseInfo.Id,
                    caseInfo.UniqueName);

            var logw = new StringWriter();
            var storage = new CodeTextStorage(logw, translatedPath, false, "    ");

            AssemblyWriter.WriteHeader(
                storage,
                translateContext,
                prepared);
            var sourceFiles = AssemblyWriter.WriteSourceCode(
                storage,
                translateContext,
                prepared,
                true,
                DebugInformationOptions.CommentOnly);

            // Step 1-5: Write source code into a file from template.
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
                    p.ParameterName,
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
                        Utilities.GetCLanguageExpression(expectedType.InternalStaticEmptyValue))).
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
                            Utilities.GetCLanguageExpression(argument.TargetType.InternalStaticEmptyValue))).
                    Concat(new Constant[]
                    {
                        new Constant(
                            "_actual",
                            expectedType,
                            caseInfo.Expected?.GetType(),
                            Utilities.GetCLanguageExpression(expectedType.InternalStaticEmptyValue)),
                    }).
                    ToArray();
            }

            // Construct test definitions.
            var expectedSymbolName = locals.
                Any(entry => (entry.SymbolName == "_expected") && entry.TargetType.IsReferenceType) ?
                    "frame__._expected" :
                    "_expected";
            var actualSymbolName = locals.
                Any(entry => (entry.SymbolName == "_actual") && entry.TargetType.IsReferenceType) ?
                    "frame__._actual" :
                    "_actual";
            var replaceValues = new Dictionary<string, object>
            {
                { "assemblyName", targetMethod.DeclaringType.DeclaringModule.DeclaringAssembly.Name},
                { "testName", targetMethod.FriendlyName},
                { "type", targetMethod.ReturnType.CLanguageTypeName},
                { "constants", string.Join(" ", constants.
                    Select(entry => string.Format("{0} {1} = {2};",
                        (entry.ExpressionType != null) ? Utilities.GetCLanguageTypeName(entry.ExpressionType) : entry.TargetType.CLanguageTypeName,
                        entry.SymbolName,
                        entry.Expression))) },
                { "locals", string.Join(" ", locals.
                    Where(entry => !entry.TargetType.IsReferenceType).
                    Select(entry => string.Format("{0} {1} = {2};",
                        entry.TargetType.CLanguageTypeName,
                        entry.SymbolName,
                        entry.Expression))) },
                { "frames", string.Join(" ", locals.
                    Where(entry => entry.TargetType.IsReferenceType).
                    Select(entry => string.Format("{0} {1};",
                        entry.TargetType.CLanguageTypeName,
                        entry.SymbolName))) },
                { "frameCount", locals.
                    Where(entry => entry.TargetType.IsClass).Count() },
                { "arguments", string.Join(" ", arguments.
                    Select(entry => string.Format("{0}{1} = {2};",
                        entry.TargetType.IsReferenceType ? "frame__." : string.Empty,
                        entry.SymbolName,
                        entry.Expression))) },
                { "actual", actualSymbolName },
                { "function", targetMethod.CLanguageFunctionFullName },
                { "argumentList", string.Join(", ", argumentList.
                    Select(arg => string.Format(
                        "{0}{1}",
                        arg.TargetType.IsReferenceType ? "frame__." : string.Empty,
                        arg.SymbolName)))},
                { "equality", GetCLanguageCompareExpression(expectedType, expectedSymbolName, actualSymbolName)},
                { "format", GetCLanguagePrintFormatFromType(targetMethod.ReturnType)},
                { "expectedExpression", GetCLanguagePrintArgumentExpression(expectedType, expectedSymbolName)},
                { "actualExpression", GetCLanguagePrintArgumentExpression(expectedType, actualSymbolName)},
                { "sourcePath", translateContext.Assembly.Name + "_bundle.c" }
            };

            // Step 1-6: Write Visual C++ project file and Visual Studio Code launch config from template.
            //     Note: It's only debugging purpose. The test doesn't use.
            var vcxprojTemplatePath = Path.Combine(translatedPath, "test.vcxproj");
            await TestUtilities.CopyResourceToTextFileAsync(vcxprojTemplatePath, "test.vcxproj", replaceValues);

            TestContext.AddTestAttachment(vcxprojTemplatePath, "Generated VC++ project");

            var launchTemplatePath = Path.Combine(translatedPath, ".vscode", "launch.json");
            await TestUtilities.CopyResourceToTextFileAsync(launchTemplatePath, "launch.json", replaceValues);

            var sourcePath = Path.Combine(translatedPath, "test.c");
            await TestUtilities.WriteTextFileAsync(sourcePath, sourceCode, replaceValues);

            ///////////////////////////////////////////////
            // Step 2: Verify IL code.

            var verifyResults = ilVerifier.Verify(caseInfo.Method).
                Where(r => !caseInfo.IgnoreILErrors.Contains(r.result.Code.ToString())).
                ToArray();
            if (verifyResults.Length >= 1)
            {
                // TODO: ILVerify (IL.Verification library comes portable version of PEVerify)
                //   produces a lot of minor or invalid result.
                //   So currently IL2C doesn't make error message.
                static void RecordInformation(string message)
                {
                    var currentResult = TestExecutionContext.CurrentContext.CurrentResult;
                    currentResult.OutWriter.WriteLine(message);
                }

                foreach (var resultx in verifyResults)
                {
                    RecordInformation($"IL.Verification: {caseInfo.Method.DeclaringType.FullName}.{caseInfo.Method.Name}: [{resultx.result.Code}/{resultx.result.ExceptionID?.ToString() ?? "None"}]: {string.Format(resultx.result.Message, resultx.result.Args ?? Array.Empty<object>())}: {string.Join(",", resultx.result.ErrorArguments?.Select(a => $"{a.Name}={a.Value}") ?? Array.Empty<string>())}: {resultx.instruction}");
                }
            }

            ///////////////////////////////////////////////
            // Step 3: Test and verify result by real IL code at this runtime.

            object rawResult;
            switch (caseInfo.Assert)
            {
                case TestCaseAsserts.IgnoreValidateInvokeResult:
                    break;
                case TestCaseAsserts.CauseBreak:
                    rawResult = null;
                    break;
                default:
                    CultureInfo.CurrentCulture = CultureInfo.InvariantCulture;
                    CultureInfo.CurrentUICulture = CultureInfo.InvariantCulture;
                    rawResult = caseInfo.Method.Invoke(null, caseInfo.Arguments);
                    Assert.AreEqual(caseInfo.Expected, rawResult);
                    break;
            }

            ///////////////////////////////////////////////
            // Step 4: Test compiled C source code and execute.

            string sanitized = null;
            try
            {
                var executedResult = await CMakeDriver.BuildAsync(
                    binPath,
                    configuration,
                    sourcePath,
                    il2cRuntimePath);

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
            // Step 5: Verify result.

            Assert.AreEqual("Success", sanitized);
        }
    }
}
