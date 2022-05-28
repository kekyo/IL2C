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
    public sealed class System_UIntPtr
    {
        [TestCase(true, "IsValueType")]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern bool IsValueType();

        [TestCase(4, "SizeOf", Assert = TestCaseAsserts.IgnoreValidateInvokeResult)]    // Unit test environment is unknown, gcc is 32bit
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern int SizeOf();

        [TestCase("4294967295", "ToString", uint.MaxValue)]
        [TestCase("0", "ToString", uint.MinValue)]
        public static string ToString(UIntPtr value)
        {
            return value.ToString();
        }

        [TestCase(123, "ToUInt32", 123)]
        public static int ToUInt32(int v)
        {
            var ip = (IntPtr)v;
            return ip.ToInt32();
        }

        [TestCase(123UL, "ToUInt64", 123UL)]
        public static ulong ToUInt64(ulong v)
        {
            var ip = (UIntPtr)v;
            return ip.ToUInt64();
        }
    }
}
