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
    public sealed class Stelem_r4
    {
        [TestCase(123f, new[] { "Single", "SingleInner" }, 0, 123f)]
        [TestCase(456f, new[] { "Single", "SingleInner" }, 1, 456f)]
        [TestCase(789f, new[] { "Single", "SingleInner" }, 2, 789f)]
        public static float Single(int index, float value)
        {
            var values = new[] { 1f, 2f, 3f };
            SingleInner(values, index, value);
            return values[index];
        }

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern void SingleInner(float[] values, int index, float value);

        [TestCase(123f, new[] { "SingleIntPtrIndex", "SingleIntPtrIndexInner" }, 0, 123f)]
        [TestCase(456f, new[] { "SingleIntPtrIndex", "SingleIntPtrIndexInner" }, 1, 456f)]
        [TestCase(789f, new[] { "SingleIntPtrIndex", "SingleIntPtrIndexInner" }, 2, 789f)]
        public static float SingleIntPtrIndex(int index, float value)
        {
            var values = new[] { 1f, 2f, 3f };
            SingleIntPtrIndexInner(values, index, value);
            return values[index];
        }

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern void SingleIntPtrIndexInner(float[] values, int index, float value);
    }
}
