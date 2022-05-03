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
    [TestCase((short)123, new[] { "Int16", "Int16Inner" }, 0, (short)123)]
    [TestCase((short)456, new[] { "Int16", "Int16Inner" }, 1, (short)456)]
    [TestCase((short)789, new[] { "Int16", "Int16Inner" }, 2, (short)789)]
    [TestCase((short)123, new[] { "Int16IntPtrIndex", "Int16IntPtrIndexInner" }, 0, (short)123)]
    [TestCase((short)456, new[] { "Int16IntPtrIndex", "Int16IntPtrIndexInner" }, 1, (short)456)]
    [TestCase((short)789, new[] { "Int16IntPtrIndex", "Int16IntPtrIndexInner" }, 2, (short)789)]
    public sealed class Stelem_i2
    {
        public static short Int16(int index, short value)
        {
            var values = new short[] { 1, 2, 3 };
            Int16Inner(values, index, value);
            return values[index];
        }

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern void Int16Inner(short[] values, int index, short value);

        public static short Int16IntPtrIndex(int index, short value)
        {
            var values = new short[] { 1, 2, 3 };
            Int16IntPtrIndexInner(values, index, value);
            return values[index];
        }

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern void Int16IntPtrIndexInner(short[] values, int index, short value);
    }
}
