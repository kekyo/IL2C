////////////////////////////////////////////////////////////////////////////
//
// IL2C - A translator for ECMA-335 CIL/MSIL to C language.
// Copyright (c) Kouji Matsui (@kozy_kekyo, @kekyo@mastodon.cloud)
//
// Licensed under Apache-v2: https://opensource.org/licenses/Apache-2.0
//
////////////////////////////////////////////////////////////////////////////

using System;
using System.Linq;

using NUnit.Framework.Interfaces;

namespace IL2C
{
    public enum TestCaseAsserts
    {
        PerfectMatch,
        IgnoreValidateInvokeResult,
        CauseBreak
    }

    // It's test case attribute contains expected value, method name and argument values at overall.
    [AttributeUsage(AttributeTargets.Class | AttributeTargets.Method, AllowMultiple = true)]
    public sealed class TestCaseAttribute :
        NUnit.Framework.TestCaseAttribute, NUnit.Framework.ITestAction
    {
        public TestCaseAttribute(
            object? expected, string methodName, params object?[] args) :
            base(args ?? new object?[] { null })  // HACK
        {
            base.ExpectedResult = expected;

            this.MethodName = methodName;
            this.AdditionalMethodNames = new string[0];

            this.Assert = TestCaseAsserts.PerfectMatch;
            this.IncludeBaseTypes = false;
            this.IncludeTypes = Type.EmptyTypes;
            this.IgnoreILErrors = Array.Empty<string>();
        }

        // This overload contains additional methods, those are used from the test method (first methodName is target.)
        public TestCaseAttribute(
            object? expected, string[] methodNames, params object?[] args) :
            base(args ?? new object?[] { null })  // HACK
        {
            base.ExpectedResult = expected;

            this.MethodName = methodNames[0];   // test method
            this.AdditionalMethodNames = methodNames.Skip(1).ToArray();   // additionals

            this.Assert = TestCaseAsserts.PerfectMatch;
            this.IncludeBaseTypes = false;
            this.IncludeTypes = Type.EmptyTypes;
            this.IgnoreILErrors = Array.Empty<string>();
        }

        public string MethodName { get; }
        public string[] AdditionalMethodNames { get; }

        public TestCaseAsserts Assert { get; set; }
        public bool IncludeBaseTypes { get; set; }
        public Type[] IncludeTypes { get; set; }
        public string[] IgnoreILErrors { get; set; }

        public NUnit.Framework.ActionTargets Targets => throw new NotImplementedException();

        public void BeforeTest(ITest test)
        {
        }

        public void AfterTest(ITest test)
        {
            // TODO: delegates to test native code.
        }
    }
}
