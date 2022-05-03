////////////////////////////////////////////////////////////////////////////
//
// IL2C - A translator for ECMA-335 CIL/MSIL to C language.
// Copyright (c) Kouji Matsui (@kozy_kekyo, @kekyo@mastodon.cloud)
//
// Licensed under Apache-v2: https://opensource.org/licenses/Apache-2.0
//
////////////////////////////////////////////////////////////////////////////

using System;
using System.Runtime.CompilerServices;

namespace IL2C.BasicTypes
{
    [TestCase(true, "IsValueType")]
    [TestCase(4, "SizeOf", Assert = TestCaseAsserts.IgnoreValidateInvokeResult)]    // Unit test environment is unknown, gcc is 32bit
    [TestCase("2147483647", "ToString", int.MaxValue)]
    [TestCase("-2147483648", "ToString", int.MinValue)]
    [TestCase(true, "Zero", 0)]
    [TestCase(true, "Equality", 0)]
    [TestCase(false, "NonEquality", 0)]
    public sealed class System_IntPtr
    {
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern bool IsValueType();

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern int SizeOf();

        public static string ToString(IntPtr value)
        {
            return value.ToString();
        }

        public static bool Zero(IntPtr v)
        {
            return v == IntPtr.Zero;
        }

        public static bool Equality(IntPtr v)
        {
            return v == IntPtr.Zero;
        }

        public static bool NonEquality(IntPtr v)
        {
            return v != IntPtr.Zero;
        }
    }
}
