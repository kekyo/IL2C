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
    public sealed class And
    {
        [TestCase(0x12345678 & 0x55555555, "Int32_Int32", 0x12345678, 0x55555555)]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern int Int32_Int32(int lhs, int rhs);

            [MethodImpl(MethodImplOptions.ForwardRef)]
            private static extern IntPtr Int32_IntPtrImpl(int lhs, IntPtr rhs);

        [TestCase(0x12345678 & 0x55555555, "Int32_IntPtr", 0x12345678, 0x55555555)]
        public static int Int32_IntPtr(int lhs, int rhs) =>
            Int32_IntPtrImpl(lhs, (IntPtr)rhs).ToInt32();

        [TestCase(0x123456789abcdef & 0x55555555aaaaaaaa, "Int64_Int64", 0x123456789abcdef, 0x55555555aaaaaaaa)]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern long Int64_Int64(long lhs, long rhs);

            [MethodImpl(MethodImplOptions.ForwardRef)]
            private static extern IntPtr IntPtr_Int32Impl(IntPtr lhs, int rhs);

        [TestCase(0x12345678 & 0x55555555, "IntPtr_Int32", 0x12345678, 0x55555555)]
        public static int IntPtr_Int32(int lhs, int rhs) =>
            IntPtr_Int32Impl((IntPtr)lhs, rhs).ToInt32();

            [MethodImpl(MethodImplOptions.ForwardRef)]
            private static extern IntPtr IntPtr_IntPtrImpl(IntPtr lhs, IntPtr rhs);
        
        [TestCase(0x12345678 & 0x55555555, "IntPtr_IntPtr", 0x12345678, 0x55555555)]
        public static int IntPtr_IntPtr(int lhs, int rhs) =>
            IntPtr_IntPtrImpl((IntPtr)lhs, (IntPtr)rhs).ToInt32();
    }
}
