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
    [TestCase(123, "SByte", (sbyte)123)]
    [TestCase(-123, "SByte", (sbyte)-123)]
    [TestCase(12345, "Int16", (short)12345)]
    [TestCase(-12345, "Int16", (short)-12345)]
    [TestCase(456789012, "Int32", 456789012)]
    [TestCase(-456789012, "Int32", -456789012)]
    [TestCase(456789012, "Int64", 456789012L)]
    [TestCase(unchecked((int)4567890123L), "Int64", 4567890123L)]
    [TestCase(456789012, "IntPtr", 456789012)]
    //[TestCase(unchecked((int)4567890123L), "IntPtr", 4567890123L)]  // Will cause overflow on 32bit test environment (IntPtr.Size == 4)
    [TestCase(123, "Byte", (byte)123)]
    [TestCase(12345, "UInt16", (ushort)12345)]
    [TestCase(456789012, "UInt32", (uint)456789012)]
    [TestCase(unchecked((int)0x80000000), "UInt32", (uint)0x80000000)]
    [TestCase(456789012, "UInt64", 456789012UL)]
    [TestCase(unchecked((int)0x8000000000000000UL), "UInt64", 0x8000000000000000UL)]
    [TestCase(456789012, "UIntPtr", (uint)456789012)]
    [TestCase(456789, "Single", 456789.012f)]
    [TestCase(unchecked((int)456789.012f), "Single", 456789.012f)]
    [TestCase(456789, "Double", 456789.012)]
    [TestCase(unchecked((int)456789.012), "Double", 456789.012)]
    public sealed class Conv_i4
    {
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern int SByte(sbyte value);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern int Int16(short value);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern int Int32(int value);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern int Int64(long value);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern int IntPtr(IntPtr value);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern int Byte(byte value);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern int UInt16(ushort value);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern int UInt32(uint value);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern int UInt64(ulong value);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern int UIntPtr(UIntPtr value);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern int Single(float value);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern int Double(double value);
    }
}
