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

            [MethodImpl(MethodImplOptions.ForwardRef)]
            public static extern int SizeOfImpl();

        [TestCase(true, "SizeOf")]
        public static bool SizeOf() =>
            IntPtr.Size == SizeOfImpl();

        [TestCase("2147483647", "ToString", int.MaxValue)]
        [TestCase("-2147483648", "ToString", int.MinValue)]
        public static string ToString(int value)
        {
            return ((IntPtr)value).ToString();
        }

        [TestCase(true, "Zero", 0)]
        public static bool Zero(int v)
        {
            return ((IntPtr)v) == IntPtr.Zero;
        }

        [TestCase(true, "Equality", 0)]
        public static bool Equality(int v)
        {
            return ((IntPtr)v) == IntPtr.Zero;
        }

        [TestCase(false, "NonEquality", 0)]
        public static bool NonEquality(int v)
        {
            return ((IntPtr)v) != IntPtr.Zero;
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
