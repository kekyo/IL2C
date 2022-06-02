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

            [MethodImpl(MethodImplOptions.ForwardRef)]
            private static extern int SizeOfImpl();

        [TestCase(true, "SizeOf")]
        public static bool SizeOf() =>
            UIntPtr.Size == SizeOfImpl();

        [TestCase("4294967295", "ToString", uint.MaxValue)]
        [TestCase("0", "ToString", uint.MinValue)]
        public static string ToString(uint value)
        {
            return ((UIntPtr)value).ToString();
        }

        [TestCase(123U, "ToUInt32", 123U)]
        public static uint ToUInt32(uint v)
        {
            var ip = (UIntPtr)v;
            return ip.ToUInt32();
        }

        [TestCase(123UL, "ToUInt64", 123UL)]
        public static ulong ToUInt64(ulong v)
        {
            var ip = (UIntPtr)v;
            return ip.ToUInt64();
        }
    }
}
