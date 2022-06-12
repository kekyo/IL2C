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
    public sealed class Conv_i2
    {
        [TestCase((short)123, "SByte", (sbyte)123)]
        [TestCase((short)-123, "SByte", (sbyte)-123)]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern short SByte(sbyte value);

        [TestCase((short)12345, "Int16", (short)12345)]
        [TestCase((short)-12345, "Int16", (short)-12345)]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern short Int16(short value);

        [TestCase((short)12345, "Int32", 12345)]
        [TestCase(unchecked((short)45678), "Int32", 45678)]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern short Int32(int value);

        [TestCase((short)12345, "Int64", 12345L)]
        [TestCase(unchecked((short)45678), "Int64", 45678L)]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern short Int64(long value);

            [MethodImpl(MethodImplOptions.ForwardRef)]
            private static extern short IntPtrImpl(IntPtr value);

        [TestCase((short)12345, "IntPtr", 12345)]
        [TestCase(unchecked((short)45678), "IntPtr", 45678)]
        public static short IntPtr(int value) =>
            IntPtrImpl((IntPtr)value);

        [TestCase((short)123, "Byte", (byte)123)]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern short Byte(byte value);

        [TestCase((short)12345, "UInt16", (ushort)12345)]
        [TestCase(unchecked((short)0x8000), "UInt16", (ushort)0x8000)]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern short UInt16(ushort value);

        [TestCase(unchecked((short)456789012), "UInt32", (uint)456789012)]
        [TestCase(unchecked((short)0x80000000), "UInt32", (uint)0x80000000)]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern short UInt32(uint value);

        [TestCase(unchecked((short)456789012), "UInt64", 456789012UL)]
        [TestCase(unchecked((short)0x8000000000000000UL), "UInt64", 0x8000000000000000UL)]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern short UInt64(ulong value);

            [MethodImpl(MethodImplOptions.ForwardRef)]
            private static extern short UIntPtrImpl(UIntPtr value);

        [TestCase(unchecked((short)456789012), "UIntPtr", (uint)456789012)]
        public static short UIntPtr(uint value) =>
            UIntPtrImpl((UIntPtr)value);

        [TestCase((short)12345, "Single", 12345.67f)]
        [TestCase(unchecked((short)45678), "Single", 45678.91f)]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern short Single(float value);

        [TestCase((short)12345, "Double", 12345.67)]
        [TestCase(unchecked((short)45678), "Double", 45678.91)]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern short Double(double value);
    }
}
