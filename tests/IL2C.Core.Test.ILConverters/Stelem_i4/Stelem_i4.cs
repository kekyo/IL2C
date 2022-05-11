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
    [TestCase(123, new[] { "Int32", "Int32Inner" }, 0, 123)]
    [TestCase(456, new[] { "Int32", "Int32Inner" }, 1, 456)]
    [TestCase(789, new[] { "Int32", "Int32Inner" }, 2, 789)]
    [TestCase(123, new[] { "Int32IntPtrIndex", "Int32IntPtrIndexInner" }, 0, 123)]
    [TestCase(456, new[] { "Int32IntPtrIndex", "Int32IntPtrIndexInner" }, 1, 456)]
    [TestCase(789, new[] { "Int32IntPtrIndex", "Int32IntPtrIndexInner" }, 2, 789)]
    public sealed class Stelem_i4
    {
        public static int Int32(int index, int value)
        {
            var values = new[] { 1, 2, 3 };
            Int32Inner(values, index, value);
            return values[index];
        }

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern void Int32Inner(int[] values, int index, int value);

        public static int Int32IntPtrIndex(int index, int value)
        {
            var values = new[] { 1, 2, 3 };
            Int32IntPtrIndexInner(values, index, value);
            return values[index];
        }

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern void Int32IntPtrIndexInner(int[] values, int index, int value);
    }
}
