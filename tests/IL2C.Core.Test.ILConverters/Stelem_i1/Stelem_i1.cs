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
    [TestCase((byte)123, new[] { "Byte", "ByteInner" }, 0, (byte)123)]
    [TestCase((byte)125, new[] { "Byte", "ByteInner" }, 1, (byte)125)]
    [TestCase((byte)127, new[] { "Byte", "ByteInner" }, 2, (byte)127)]
    [TestCase((byte)123, new[] { "ByteIntPtrIndex", "ByteIntPtrIndexInner" }, 0, (byte)123)]
    [TestCase((byte)125, new[] { "ByteIntPtrIndex", "ByteIntPtrIndexInner" }, 1, (byte)125)]
    [TestCase((byte)127, new[] { "ByteIntPtrIndex", "ByteIntPtrIndexInner" }, 2, (byte)127)]
    public sealed class Stelem_i1
    {
        public static byte Byte(int index, byte value)
        {
            var values = new byte[] { 1, 2, 3 };
            ByteInner(values, index, value);
            return values[index];
        }

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern void ByteInner(byte[] values, int index, byte value);

        public static byte ByteIntPtrIndex(int index, byte value)
        {
            var values = new byte[] { 1, 2, 3 };
            ByteIntPtrIndexInner(values, index, value);
            return values[index];
        }

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern void ByteIntPtrIndexInner(byte[] values, int index, byte value);
    }
}
