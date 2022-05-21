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
    public sealed class Stelem_r8
    {
        [TestCase(123.111, new[] { "Double", "DoubleInner" }, 0, 123.111)]
        [TestCase(456.222, new[] { "Double", "DoubleInner" }, 1, 456.222)]
        [TestCase(789.333, new[] { "Double", "DoubleInner" }, 2, 789.333)]
        public static double Double(int index, double value)
        {
            var values = new double[] { 1, 2, 3 };
            DoubleInner(values, index, value);
            return values[index];
        }

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern void DoubleInner(double[] values, int index, double value);

        [TestCase(123.111, new[] { "DoubleIntPtrIndex", "DoubleIntPtrIndexInner" }, 0, 123.111)]
        [TestCase(456.222, new[] { "DoubleIntPtrIndex", "DoubleIntPtrIndexInner" }, 1, 456.222)]
        [TestCase(789.333, new[] { "DoubleIntPtrIndex", "DoubleIntPtrIndexInner" }, 2, 789.333)]
        public static double DoubleIntPtrIndex(int index, double value)
        {
            var values = new double[] { 1, 2, 3 };
            DoubleIntPtrIndexInner(values, index, value);
            return values[index];
        }

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern void DoubleIntPtrIndexInner(double[] values, int index, double value);
    }
}
