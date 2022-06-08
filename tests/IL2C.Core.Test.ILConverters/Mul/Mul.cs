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
    public sealed class Mul
    {
        [TestCase(288, "Int32_Int32", 12, 24)]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern int Int32_Int32(int lhs, int rhs);

            [MethodImpl(MethodImplOptions.ForwardRef)]
            private static extern IntPtr Int32_IntPtrImpl(int lhs, IntPtr rhs);

        [TestCase(288, "Int32_IntPtr", 12, 24)]
        public static int Int32_IntPtr(int lhs, int rhs) =>
            Int32_IntPtrImpl(lhs, (IntPtr)rhs).ToInt32();

        [TestCase(288L, "Int64_Int64", 12L, 24L)]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern long Int64_Int64(long lhs, long rhs);

            [MethodImpl(MethodImplOptions.ForwardRef)]
            private static extern IntPtr IntPtr_Int32Impl(IntPtr lhs, int rhs);

        [TestCase(288, "IntPtr_Int32", 12, 24)]
        public static int IntPtr_Int32(int lhs, int rhs) =>
            IntPtr_Int32Impl((IntPtr)lhs, rhs).ToInt32();

            [MethodImpl(MethodImplOptions.ForwardRef)]
            private static extern IntPtr IntPtr_IntPtrImpl(IntPtr lhs, IntPtr rhs);

        [TestCase(288, "IntPtr_IntPtr", 12, 24)]
        public static int IntPtr_IntPtr(int lhs, int rhs) =>
            IntPtr_IntPtrImpl((IntPtr)lhs, (IntPtr)rhs).ToInt32();

        [TestCase(123.0f * 0.45f, "Single_Single", 123.0f, 0.45f)]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern float Single_Single(float lhs, float rhs);

        [TestCase(123.0f * 0.45, "Single_Double", 123.0f, 0.45)]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern double Single_Double(float lhs, double rhs);

        [TestCase(123.0 * 0.45f, "Double_Single", 123.0, 0.45f)]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern double Double_Single(double lhs, float rhs);

        [TestCase(123.0 * 0.45, "Double_Double", 123.0, 0.45)]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern double Double_Double(double lhs, double rhs);
    }
}
