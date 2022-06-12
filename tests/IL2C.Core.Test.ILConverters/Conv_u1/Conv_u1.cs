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
    public sealed class Conv_u1
    {
        [TestCase((byte)123, "Byte", (byte)123)]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern byte Byte(byte value);

        [TestCase((byte)123, "Int16", (short)123)]
        [TestCase(unchecked((byte)456), "Int16", (short)456)]
        [TestCase(unchecked((byte)-456), "Int16", (short)-456)]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern byte Int16(short value);

        [TestCase((byte)123, "Int32", 123)]
        [TestCase(unchecked((byte)456), "Int32", 456)]
        [TestCase(unchecked((byte)-456), "Int32", -456)]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern byte Int32(int value);

        [TestCase((byte)123L, "Int64", 123L)]
        [TestCase(unchecked((byte)456L), "Int64", 456L)]
        [TestCase(unchecked((byte)-456L), "Int64", -456L)]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern byte Int64(long value);

            [MethodImpl(MethodImplOptions.ForwardRef)]
            private static extern byte IntPtrImpl(IntPtr value);

        [TestCase((byte)123, "IntPtr", 123)]
        [TestCase(unchecked((byte)456), "IntPtr", 456)]
        public static byte IntPtr(int value) =>
            IntPtrImpl((IntPtr)value);

        [TestCase((byte)123, "SByte", (sbyte)123)]
        [TestCase(unchecked((byte)-123), "SByte", (sbyte)-123)]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern byte SByte(sbyte value);

        [TestCase((byte)123, "UInt16", (ushort)123)]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern byte UInt16(ushort value);

        [TestCase((byte)123, "UInt32", (uint)123)]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern byte UInt32(uint value);

        [TestCase((byte)123, "UInt64", (ulong)123)]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern byte UInt64(ulong value);

            [MethodImpl(MethodImplOptions.ForwardRef)]
            private static extern byte UIntPtrImpl(UIntPtr value);

        [TestCase((byte)123, "UIntPtr", (uint)123)]
        public static byte UIntPtr(uint value) =>
            UIntPtrImpl((UIntPtr)value);

        [TestCase((byte)123, "Single", 123.45f)]
        [TestCase(unchecked((byte)456), "Single", 456.78f)]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern byte Single(float value);

        [TestCase((byte)123, "Double", 123.45)]
        [TestCase(unchecked((byte)456), "Double", 456.78)]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern byte Double(double value);
    }
}
