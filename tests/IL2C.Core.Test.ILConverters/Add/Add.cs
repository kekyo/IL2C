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
    public sealed class Add
    {
        [TestCase(36, "Int32_Int32", 12, 24)]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern int Int32_Int32(int lhs, int rhs);

            [MethodImpl(MethodImplOptions.ForwardRef)]
            private static extern IntPtr Int32_IntPtrImpl(int lhs, IntPtr rhs);

        [TestCase(36, "Int32_IntPtr", 12, 24)]
        public static int Int32_IntPtr(int lhs, int rhs) =>
            Int32_IntPtrImpl(lhs, (IntPtr)rhs).ToInt32();

            [MethodImpl(MethodImplOptions.ForwardRef)]
            private static extern ref int Add_Int32_IntRef(int lhs, ref int rhs);

        [TestCase(123, new[] { "Int32_IntRef", "Add_Int32_IntRef" }, 123)]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern int Int32_IntRef(int value);

        [TestCase(36L, "Int64_Int64", 12L, 24L)]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern long Int64_Int64(long lhs, long rhs);

            [MethodImpl(MethodImplOptions.ForwardRef)]
            private static extern IntPtr IntPtr_Int32Impl(IntPtr lhs, int rhs);

        [TestCase(36, "IntPtr_Int32", 12, 24)]
        public static int IntPtr_Int32(int lhs, int rhs) =>
            IntPtr_Int32Impl((IntPtr)lhs, rhs).ToInt32();

            [MethodImpl(MethodImplOptions.ForwardRef)]
            private static extern IntPtr IntPtr_IntPtrImpl(IntPtr lhs, IntPtr rhs);

        [TestCase(36, "IntPtr_IntPtr", 12, 24)]
        public static int IntPtr_IntPtr(int lhs, int rhs) =>
            IntPtr_IntPtrImpl((IntPtr)lhs, (IntPtr)rhs).ToInt32();

            [MethodImpl(MethodImplOptions.ForwardRef)]
            private static extern ref int Add_IntPtr_IntRef(IntPtr lhs, ref int rhs);

        [TestCase(123, new[] { "IntPtr_IntRef", "Add_IntPtr_IntRef" }, 123)]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern int IntPtr_IntRef(int value);

        [TestCase(0.45f + 123.0f, "Single_Single", 0.45f, 123.0f)]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern float Single_Single(float lhs, float rhs);

        [TestCase(0.45f + 123.0, "Add_Single_Double", 0.45f, 123.0)]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern double Add_Single_Double(float lhs, double rhs);

        [TestCase(0.45 + 123.0f, "Add_Double_Single", 0.45, 123.0f)]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern double Add_Double_Single(double lhs, float rhs);

        [TestCase(0.45 + 123.0, "Double_Double", 0.45, 123.0)]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern double Double_Double(double lhs, double rhs);

            [MethodImpl(MethodImplOptions.ForwardRef)]
            private static extern ref int Add_IntRef_Int32(ref int lhs, int rhs);

        [TestCase(123, new[] { "IntRef_Int32", "Add_IntRef_Int32" }, 123)]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern int IntRef_Int32(int value);

            [MethodImpl(MethodImplOptions.ForwardRef)]
            private static extern ref int Add_IntRef_IntPtr(ref int lhs, IntPtr rhs);

        [TestCase(123, new[] { "IntRef_IntPtr", "Add_IntRef_IntPtr" }, 123)]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern int IntRef_IntPtr(int value);
    }
}
