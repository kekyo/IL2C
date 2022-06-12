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
    public sealed class Conv_u8
    {
        [TestCase((ulong)123, "Byte", (byte)123)]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern ulong Byte(byte value);

        [TestCase((ulong)12345, "Int16", (short)12345)]
        [TestCase(unchecked((ulong)(uint)-12345), "Int16", (short)-12345)]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern ulong Int16(short value);

        [TestCase((ulong)12345, "Int32", 12345)]
        [TestCase(unchecked((ulong)(uint)-45678), "Int32", -45678)]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern ulong Int32(int value);

        [TestCase((ulong)12345, "Int64", 12345L)]
        [TestCase(unchecked((ulong)-45678L), "Int64", -45678L)]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern ulong Int64(long value);

            [MethodImpl(MethodImplOptions.ForwardRef)]
            private static extern ulong IntPtrImpl(IntPtr value);

        [TestCase((ulong)12345, "IntPtr", 12345)]
        //[TestCase(unchecked((ulong)(uint)-45678), "IntPtr", -45678)]  // Different result on both 32/64bit test environment
        public static ulong IntPtr(int value) =>
            IntPtrImpl((IntPtr)value);

        [TestCase((ulong)123, "SByte", (sbyte)123)]
        [TestCase(unchecked((ulong)(uint)-123), "SByte", (sbyte)-123)]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern ulong SByte(sbyte value);

        [TestCase((ulong)12345, "UInt16", (ushort)12345)]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern ulong UInt16(ushort value);

        [TestCase((ulong)12345, "UInt32", (uint)12345)]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern ulong UInt32(uint value);

        [TestCase((ulong)12345, "UInt64", 12345UL)]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern ulong UInt64(ulong value);

            [MethodImpl(MethodImplOptions.ForwardRef)]
            private static extern ulong UIntPtrImpl(UIntPtr value);

        [TestCase((ulong)12345, "UIntPtr", (uint)12345)]
        public static ulong UIntPtr(uint value) =>
            UIntPtrImpl((UIntPtr)value);

        [TestCase((ulong)12345.67f, "Single", 12345.67f)]
        [TestCase(unchecked((ulong)(long)-45678.91f), "Single", -45678.91f)]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern ulong Single(float value);

        [TestCase((ulong)12345.6789, "Double", 12345.6789)]
        [TestCase(unchecked((ulong)45678.90123), "Double", 45678.90123)]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern ulong Double(double value);
    }
}
