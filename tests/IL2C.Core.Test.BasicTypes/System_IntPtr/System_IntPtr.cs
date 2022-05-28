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
    public sealed class System_IntPtr
    {
        [TestCase(true, "IsValueType")]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern bool IsValueType();

        [TestCase(4, "SizeOf", Assert = TestCaseAsserts.IgnoreValidateInvokeResult)]    // Unit test environment is unknown, gcc is 32bit
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern int SizeOf();

        [TestCase("2147483647", "ToString", int.MaxValue)]
        [TestCase("-2147483648", "ToString", int.MinValue)]
        public static string ToString(IntPtr value)
        {
            return value.ToString();
        }

        [TestCase(true, "Zero", 0)]
        public static bool Zero(IntPtr v)
        {
            return v == IntPtr.Zero;
        }

        [TestCase(true, "Equality", 0)]
        public static bool Equality(IntPtr v)
        {
            return v == IntPtr.Zero;
        }

        [TestCase(false, "NonEquality", 0)]
        public static bool NonEquality(IntPtr v)
        {
            return v != IntPtr.Zero;
        }

        [TestCase(123, "ToInt32", 123)]
        public static int ToInt32(int v)
        {
            var ip = (IntPtr)v;
            return ip.ToInt32();
        }

        [TestCase(123L, "ToInt64", 123L)]
        public static long ToInt64(long v)
        {
            var ip = (IntPtr)v;
            return ip.ToInt64();
        }
    }
}
