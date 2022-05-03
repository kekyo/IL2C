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

namespace IL2C.ILConverters
{
    [TestCase(0x12345678 ^ 0x55555555, "Int32_Int32", 0x12345678, 0x55555555)]
    [TestCase(0x12345678 ^ 0x55555555, "Int32_IntPtr", 0x12345678, 0x55555555)]
    [TestCase(0x123456789abcdef ^ 0x55555555aaaaaaaa, "Int64_Int64", 0x123456789abcdef, 0x55555555aaaaaaaa)]
    [TestCase(0x12345678 ^ 0x55555555, "IntPtr_Int32", 0x12345678, 0x55555555)]
    [TestCase(0x12345678 ^ 0x55555555, "IntPtr_IntPtr", 0x12345678, 0x55555555)]
    public sealed class Xor
    {
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern int Int32_Int32(int lhs, int rhs);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern IntPtr Int32_IntPtr(int lhs, IntPtr rhs);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern long Int64_Int64(long lhs, long rhs);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern IntPtr IntPtr_Int32(IntPtr lhs, int rhs);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern IntPtr IntPtr_IntPtr(IntPtr lhs, IntPtr rhs);
    }
}
