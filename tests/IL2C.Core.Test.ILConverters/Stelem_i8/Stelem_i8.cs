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
    public sealed class Stelem_i8
    {
        [TestCase(123L, new[] { "Int64", "Int64Inner" }, 0, 123L)]
        [TestCase(456L, new[] { "Int64", "Int64Inner" }, 1, 456L)]
        [TestCase(789L, new[] { "Int64", "Int64Inner" }, 2, 789L)]
        public static long Int64(int index, long value)
        {
            var values = new long[] { 1, 2, 3 };
            Int64Inner(values, index, value);
            return values[index];
        }

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern void Int64Inner(long[] values, int index, long value);

        [TestCase(123L, new[] { "Int64IntPtrIndex", "Int64IntPtrIndexInner" }, 0, 123L)]
        [TestCase(456L, new[] { "Int64IntPtrIndex", "Int64IntPtrIndexInner" }, 1, 456L)]
        [TestCase(789L, new[] { "Int64IntPtrIndex", "Int64IntPtrIndexInner" }, 2, 789L)]
        public static long Int64IntPtrIndex(int index, long value)
        {
            var values = new long[] { 1, 2, 3 };
            Int64IntPtrIndexInner(values, index, value);
            return values[index];
        }

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern void Int64IntPtrIndexInner(long[] values, int index, long value);
    }
}
