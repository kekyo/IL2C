////////////////////////////////////////////////////////////////////////////
//
// IL2C - A translator for ECMA-335 CIL/MSIL to C language.
// Copyright (c) Kouji Matsui (@kozy_kekyo, @kekyo@mastodon.cloud)
//
// Licensed under Apache-v2: https://opensource.org/licenses/Apache-2.0
//
////////////////////////////////////////////////////////////////////////////

#nullable enable

using System;
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
    [AttributeUsage(AttributeTargets.Method, AllowMultiple = true)]
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
            this.IgnoreILErrors = new string[0];
        }

        // This overload contains additional methods, those are used from the test method (first methodName is target.)
        public TestCaseAttribute(
            object? expected, string[] methodNames, params object?[] args) :
            base(args ?? new object?[] { null })  // HACK
        {
            base.ExpectedResult = expected;

            this.MethodName = methodNames[0];   // test method
            this.AdditionalMethodNames = GetAdditionalMethodNames(methodNames);   // additionals

            this.Assert = TestCaseAsserts.PerfectMatch;
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

        public TestCaseAsserts Assert { get; set; }
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

#if false
        private static object?[] ConvertToArgumentsType(object?[] args, Type[] argumentTypes) =>
            args.Zip(argumentTypes, ConvertToArgumentType).ToArray();

        private static object? ConvertToArgumentType(object? value, Type argumentType)
        {
            // This is helper function that convert between raw value type and argument type.
            // Because .NET attribute can't have complex type arguments.
            if (value == null)
            {
                return null;
            }
            else if (value.GetType() == argumentType)
            {
                return value;
            }
            else if (argumentType == typeof(IntPtr))
            {
                if (value is int)
                {
                    return new IntPtr((int)value);
                }
                else if (value is long)
                {
                    return new IntPtr((long)value);
                }
                else
                {
                    throw new InvalidCastException();
                }
            }
            else if (argumentType == typeof(UIntPtr))
            {
                if (value is uint)
                {
                    return new UIntPtr((uint)value);
                }
                else if (value is ulong)
                {
                    return new UIntPtr((ulong)value);
                }
                else
                {
                    throw new InvalidCastException();
                }
            }
            else
            {
                return Convert.ChangeType(value, argumentType);
            }
        }
#endif
    }
}
