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
    [TestCase((sbyte)123, "SByte", (sbyte)123)]
    [TestCase((sbyte)-123, "SByte", (sbyte)-123)]
    [TestCase((sbyte)123, "Int16", (short)123)]
    [TestCase(unchecked((sbyte)12345), "Int16", (short)12345)]
    [TestCase((sbyte)123, "Int32", 123)]
    [TestCase(unchecked ((sbyte)456), "Int32", 456)]
    [TestCase((sbyte)123, "Int64", 123L)]
    [TestCase(unchecked((sbyte)456), "Int64", 456L)]
    [TestCase((sbyte)123, "IntPtr", 123)]
    [TestCase(unchecked((sbyte)456), "IntPtr", 456)]
    [TestCase((sbyte)123, "Byte", (byte)123)]
    [TestCase(unchecked((sbyte)0x80), "Byte", (byte)0x80)]
    [TestCase(unchecked((sbyte)12345), "UInt16", (ushort)12345)]
    [TestCase(unchecked((sbyte)0x8000), "UInt16", (ushort)0x8000)]
    [TestCase(unchecked((sbyte)456789012), "UInt32", (uint)456789012)]
    [TestCase(unchecked((sbyte)0x80000000), "UInt32", (uint)0x80000000)]
    [TestCase(unchecked((sbyte)456789012), "UInt64", 456789012UL)]
    [TestCase(unchecked((sbyte)0x8000000000000000UL), "UInt64", 0x8000000000000000UL)]
    [TestCase(unchecked((sbyte)456789012), "UIntPtr", (uint)456789012)]
    [TestCase((sbyte)123, "Single", 123.45f)]
    [TestCase(unchecked((sbyte)456), "Single", 456.78f)]
    [TestCase((sbyte)123, "Double", 123.45)]
    [TestCase(unchecked((sbyte)456), "Double", 456.78)]
    public sealed class Conv_i1
    {
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern sbyte SByte(sbyte value);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern sbyte Int16(short value);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern sbyte Int32(int value);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern sbyte Int64(long value);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern sbyte IntPtr(IntPtr value);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern sbyte Byte(byte value);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern sbyte UInt16(ushort value);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern sbyte UInt32(uint value);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern sbyte UInt64(ulong value);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern sbyte UIntPtr(UIntPtr value);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern sbyte Single(float value);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern sbyte Double(double value);
    }
}
