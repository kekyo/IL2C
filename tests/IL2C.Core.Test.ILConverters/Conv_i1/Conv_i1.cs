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
    public sealed class Conv_i1
    {
        [TestCase((sbyte)123, "SByte", (sbyte)123)]
        [TestCase((sbyte)-123, "SByte", (sbyte)-123)]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern sbyte SByte(sbyte value);

        [TestCase((sbyte)123, "Int16", (short)123)]
        [TestCase(unchecked((sbyte)12345), "Int16", (short)12345)]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern sbyte Int16(short value);

        [TestCase((sbyte)123, "Int32", 123)]
        [TestCase(unchecked((sbyte)456), "Int32", 456)]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern sbyte Int32(int value);

        [TestCase((sbyte)123, "Int64", 123L)]
        [TestCase(unchecked((sbyte)456), "Int64", 456L)]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern sbyte Int64(long value);

            [MethodImpl(MethodImplOptions.ForwardRef)]
            private static extern sbyte IntPtrImpl(IntPtr value);

        [TestCase((sbyte)123, "IntPtr", 123)]
        [TestCase(unchecked((sbyte)456), "IntPtr", 456)]
        public static sbyte IntPtr(int value) =>
            IntPtrImpl((IntPtr)value);

        [TestCase((sbyte)123, "Byte", (byte)123)]
        [TestCase(unchecked((sbyte)0x80), "Byte", (byte)0x80)]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern sbyte Byte(byte value);

        [TestCase(unchecked((sbyte)12345), "UInt16", (ushort)12345)]
        [TestCase(unchecked((sbyte)0x8000), "UInt16", (ushort)0x8000)]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern sbyte UInt16(ushort value);

        [TestCase(unchecked((sbyte)456789012), "UInt32", (uint)456789012)]
        [TestCase(unchecked((sbyte)0x80000000), "UInt32", (uint)0x80000000)]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern sbyte UInt32(uint value);

        [TestCase(unchecked((sbyte)456789012), "UInt64", 456789012UL)]
        [TestCase(unchecked((sbyte)0x8000000000000000UL), "UInt64", 0x8000000000000000UL)]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern sbyte UInt64(ulong value);

            [MethodImpl(MethodImplOptions.ForwardRef)]
                private static extern sbyte UIntPtrImpl(UIntPtr value);

        [TestCase(unchecked((sbyte)456789012), "UIntPtr", (uint)456789012)]
        public static sbyte UIntPtr(uint value) =>
            UIntPtrImpl((UIntPtr)value);

        [TestCase((sbyte)123, "Single", 123.45f)]
        [TestCase(unchecked((sbyte)456), "Single", 456.78f)]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern sbyte Single(float value);

        [TestCase((sbyte)123, "Double", 123.45)]
        [TestCase(unchecked((sbyte)456), "Double", 456.78)]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern sbyte Double(double value);
    }
}
