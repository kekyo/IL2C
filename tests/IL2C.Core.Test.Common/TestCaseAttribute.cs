﻿////////////////////////////////////////////////////////////////////////////
//
// IL2C - A translator for ECMA-335 CIL/MSIL to C language.
// Copyright (c) Kouji Matsui (@kozy_kekyo, @kekyo@mastodon.cloud)
//
// Licensed under Apache-v2: https://opensource.org/licenses/Apache-2.0
//
////////////////////////////////////////////////////////////////////////////

#nullable enable

using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using NUnit.Framework.Interfaces;

namespace IL2C
{
    [IgnoreTranslation]
    public enum TestCaseAsserts
    {
        PerfectMatch,
        IgnoreValidateInvokeResult,
        CauseBreak
    }

    [IgnoreTranslation]
    [Flags]
    public enum RunOnOSs
    {
        None = 0x00,
        Windows = 0x01,
        Posix = 0x02,   // (Except Windows)
        All = 0xff,
    }

    [IgnoreTranslation]
    [Flags]
    public enum RunOnPlatforms
    {
        None = 0x00,
        DotNet = 0x04,  // .NET Framework / .NET Core / .NET 5 or upper
        Mono = 0x08,
        All = 0xff,
    }

    [IgnoreTranslation]
    [AttributeUsage(AttributeTargets.Method, AllowMultiple = true)]
    public sealed class TestCaseAttribute :
        NUnit.Framework.TestCaseAttribute, NUnit.Framework.ITestAction
    {
        // HACK: Modified the tests that were realized using non-public knowledge of NUnit to be tested in an official way.
        //   In doing so, to minimize the amount of refactoring, a condition that is difficult to understand was required:
        //   * If a valid value is specified for `expected`, store the value in `ExpectedResult` and let NUnit check it.
        //   * If `expected` is null, we don't know if we want to compare with null or ignore the result.
        //     * If we had access to `MethodInfo` at construction time, we could distinguish by looking at `ReturnType`, but we don't.
        //     * The value of `TestCaseAsserts` is called separately at constructor completion, so it cannot be determined in the constructor.
        //     * If you do not collate the result values, do not set any value to `ExpectedResult`.
        private TestCaseAsserts assert;
        private RunOnOSs runOnOSs = RunOnOSs.All;
        private RunOnPlatforms runOnPlatforms = RunOnPlatforms.All;
        private readonly bool isExpectedNull;
        private bool isSetAssert;
        private bool isSetRunOnOSs;
        private bool isSetRunOnPlatforms;

        public TestCaseAttribute(
            object? expected, string methodName, params object?[] args) :
            base(args ?? new object?[] { null })  // HACK
        {
            if (expected != null)
            {
                base.ExpectedResult = expected;
                this.assert = TestCaseAsserts.PerfectMatch;
            }
            else
            {
                this.isExpectedNull = true;
                this.assert = TestCaseAsserts.IgnoreValidateInvokeResult;
            }

            this.MethodName = methodName;
            this.AdditionalMethodNames = new string[0];

            this.IncludeBaseTypes = false;
            this.IncludeTypes = Type.EmptyTypes;
            this.IgnoreILErrors = new string[0];
        }

        // This overload contains additional methods, those are used from the test method (first methodName is target.)
        public TestCaseAttribute(
            object? expected, string[] methodNames, params object?[] args) :
            base(args ?? new object?[] { null })  // HACK
        {
            if (expected != null)
            {
                base.ExpectedResult = expected;
                this.assert = TestCaseAsserts.PerfectMatch;
            }
            else
            {
                this.isExpectedNull = true;
                this.assert = TestCaseAsserts.IgnoreValidateInvokeResult;
            }

            this.MethodName = methodNames[0];   // test method
            this.AdditionalMethodNames = GetAdditionalMethodNames(methodNames);   // additionals

            this.IncludeBaseTypes = false;
            this.IncludeTypes = Type.EmptyTypes;
            this.IgnoreILErrors = new string[0];
        }

        private static string[] GetAdditionalMethodNames(string[] methodNames)
        {
            var amns = new string[methodNames.Length - 1];
            for (var index = 0; index < (methodNames.Length - 1); index++)
            {
                amns[index] = methodNames[index + 1];
            }
            return amns;
        }

        public string MethodName { get; }
        public string[] AdditionalMethodNames { get; }

        public TestCaseAsserts Assert
        {
            get => this.assert;
            set
            {
                if (!this.isSetAssert)
                {
                    this.isSetAssert = true;
                    this.assert = value;

                    if (this.isExpectedNull &&
                        value == TestCaseAsserts.PerfectMatch)
                    {
                        this.ExpectedResult = null;
                    }
                }
                else if (value != this.assert)
                {
                    throw new InvalidOperationException();
                }
            }
        }

        public RunOnOSs RunOnOSs
        {
            get => this.runOnOSs;
            set
            {
                if (!this.isSetRunOnOSs)
                {
                    this.isSetRunOnOSs = true;
                    this.runOnOSs = value;

                    var ignores = new List<string>();
                    if (TestUtilities.IsRunningOnWindows &&
                        !value.HasFlag(RunOnOSs.Windows))
                    {
                        ignores.Add("NotWindows");
                    }
                    if (!TestUtilities.IsRunningOnWindows &&
                        !value.HasFlag(RunOnOSs.Posix))
                    {
                        ignores.Add("NotPosix");
                    }

                    if (ignores.Count >= 1)
                    {
                        this.Ignore = string.IsNullOrWhiteSpace(this.Ignore) ?
                            string.Join(" | ", ignores) :
                            string.Join(" | ", new[] { this.Ignore }.Concat(ignores));
                    }
                }
                else if (value != this.runOnOSs)
                {
                    throw new InvalidOperationException();
                }
            }
        }

        public RunOnPlatforms RunOnPlatforms
        {
            get => this.runOnPlatforms;
            set
            {
                if (!this.isSetRunOnPlatforms)
                {
                    this.isSetRunOnPlatforms = true;
                    this.runOnPlatforms = value;

                    var ignores = new List<string>();
                    if (!TestUtilities.IsRunningOnMono &&
                        !value.HasFlag(RunOnPlatforms.DotNet))
                    {
                        ignores.Add("NotDotNet");
                    }
                    if (TestUtilities.IsRunningOnMono &&
                        !value.HasFlag(RunOnPlatforms.Mono))
                    {
                        ignores.Add("NotMono");
                    }

                    if (ignores.Count >= 1)
                    {
                        this.Ignore = string.IsNullOrWhiteSpace(this.Ignore) ?
                            string.Join(" | ", ignores) :
                            string.Join(" | ", new[] { this.Ignore }.Concat(ignores));
                    }
                }
                else if (value != this.runOnPlatforms)
                {
                    throw new InvalidOperationException();
                }
            }
        }

        public bool IncludeBaseTypes { get; set; }
        public Type[] IncludeTypes { get; set; }
        public string[] IgnoreILErrors { get; set; }

        public NUnit.Framework.ActionTargets Targets =>
            NUnit.Framework.ActionTargets.Default;

        public void BeforeTest(ITest test)
        {
            // TRANSITIVE DEBUG CODE: Check whether method name is equal.
            NUnit.Framework.Assert.AreEqual(test.Method?.Name, this.MethodName);
        }

        public void AfterTest(ITest test)
        {
            // TODO: delegates to test native code.
        }
    }
}
