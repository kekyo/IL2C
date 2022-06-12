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
    public sealed class Conv_i8
    {
        [TestCase(123L, "SByte", (sbyte)123)]
        [TestCase(-123L, "SByte", (sbyte)-123)]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern long SByte(sbyte value);

        [TestCase(12345L, "Int16", (short)12345)]
        [TestCase(-12345L, "Int16", (short)-12345)]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern long Int16(short value);

        [TestCase(456789012L, "Int32", 456789012)]
        [TestCase(-456789012L, "Int32", -456789012)]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern long Int32(int value);

        [TestCase(45678901234L, "Int64", 45678901234L)]
        [TestCase(-45678901234L, "Int64", -45678901234L)]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern long Int64(long value);

            [MethodImpl(MethodImplOptions.ForwardRef)]
            private static extern long IntPtrImpl(IntPtr value);

        [TestCase(456789012L, "IntPtr", 456789012)]
        //[TestCase(unchecked((int)4567890123L), "IntPtr", 4567890123L)]  // Will cause overflow on 32bit test environment (IntPtr.Size == 4)
        [TestCase(-456789012L, "IntPtr", -456789012)]
        public static long IntPtr(long value) =>
            IntPtrImpl((IntPtr)value);

        [TestCase(123L, "Byte", (byte)123)]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern long Byte(byte value);

        [TestCase(12345L, "UInt16", (ushort)12345)]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern long UInt16(ushort value);

        [TestCase(456789012L, "UInt32", (uint)456789012)]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern long UInt32(uint value);

        [TestCase(45678901234L, "UInt64", 45678901234UL)]
        [TestCase(unchecked((long)0x8000000000000000UL), "UInt64", 0x8000000000000000UL)]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern long UInt64(ulong value);

            [MethodImpl(MethodImplOptions.ForwardRef)]
            private static extern long UIntPtrImpl(UIntPtr value);

        [TestCase(456789012L, "UIntPtr", (uint)456789012)]
        public static long UIntPtr(uint value) =>
            UIntPtrImpl((UIntPtr)value);

        [TestCase((long)45678900000.56f, "Single", 45678900000.56f)]
        [TestCase((long)-45678900000.56f, "Single", -45678900000.56f)]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern long Single(float value);

        [TestCase(45678901234L, "Double", 45678901234.56)]
        [TestCase(-45678901234L, "Double", -45678901234.56)]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern long Double(double value);
    }
}
