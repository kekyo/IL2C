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

namespace IL2C
{
    public enum TestCaseAsserts
    {
        PerfectMatch,
        IgnoreValidateInvokeResult,
        CauseBreak
    }

    // It's test case attribute contains expected value, method name and argument values at overall.
    [AttributeUsage(AttributeTargets.Class, AllowMultiple = true)]
    public sealed class TestCaseAttribute : Attribute
    {
        public TestCaseAttribute(object? expected, string methodName, params object?[] args)
        {
            this.MethodName = methodName;
            this.AdditionalMethodNames = new string[0];
            this.Expected = expected;
            this.Arguments = args ?? new object?[] { null };  // HACK
            this.Assert = TestCaseAsserts.PerfectMatch;
            this.IncludeBaseTypes = false;
            this.IncludeTypes = Type.EmptyTypes;
            this.IgnoreILErrors = Array.Empty<string>();
        }

        // This overload contains additional methods, those are used from the test method (first methodName is target.)
        public TestCaseAttribute(object? expected, string[] methodNames, params object?[] args)
        {
            this.MethodName = methodNames[0];   // test method
            this.AdditionalMethodNames = methodNames.Skip(1).ToArray();   // additionals
            this.Expected = expected;
            this.Arguments = args ?? new object?[] { null };  // HACK
            this.Assert = TestCaseAsserts.PerfectMatch;
            this.IncludeBaseTypes = false;
            this.IncludeTypes = Type.EmptyTypes;
            this.IgnoreILErrors = Array.Empty<string>();
        }

        public string MethodName { get; }
        public string[] AdditionalMethodNames { get; }
        public object? Expected { get; }
        public object?[] Arguments { get; }

        public TestCaseAsserts Assert { get; set; }
        public bool IncludeBaseTypes { get; set; }
        public Type[] IncludeTypes { get; set; }
        public string[] IgnoreILErrors { get; set; }
    }
}
