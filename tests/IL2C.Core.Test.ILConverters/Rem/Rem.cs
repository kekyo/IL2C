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
    public sealed class Rem
    {
        [TestCase(12, "Int32_Int32", 288, 23)]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern int Int32_Int32(int lhs, int rhs);

        [TestCase(12, "Int32_IntPtr", 288, 23)]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern IntPtr Int32_IntPtr(int lhs, IntPtr rhs);

        [TestCase(12L, "Int64_Int64", 288L, 23L)]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern long Int64_Int64(long lhs, long rhs);

        [TestCase(12, "IntPtr_Int32", 288, 23)]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern IntPtr IntPtr_Int32(IntPtr lhs, int rhs);

        [TestCase(12, "IntPtr_IntPtr", 288, 23)]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern IntPtr IntPtr_IntPtr(IntPtr lhs, IntPtr rhs);

        [TestCase(123.0f % 0.45f, "Single_Single", 123.0f, 0.45f)]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern float Single_Single(float lhs, float rhs);

        [TestCase(123.0f % 0.45, "Single_Double", 123.0f, 0.45)]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern double Single_Double(float lhs, double rhs);

        [TestCase(123.0 % 0.45f, "Double_Single", 123.0, 0.45f)]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern double Double_Single(double lhs, float rhs);

        [TestCase(123.0 % 0.45, "Double_Double", 123.0, 0.45)]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern double Double_Double(double lhs, double rhs);
    }
}
