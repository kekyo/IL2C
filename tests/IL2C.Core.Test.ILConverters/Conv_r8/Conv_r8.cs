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
    public sealed class Conv_r8
    {
        [TestCase(123.0, "SByte", (sbyte)123)]
        [TestCase(-123.0, "SByte", (sbyte)-123)]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern double SByte(sbyte value);

        [TestCase(12345.0, "Int16", (short)12345)]
        [TestCase(-12345.0, "Int16", (short)-12345)]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern double Int16(short value);

        [TestCase(456789012.0, "Int32", 456789012)]
        [TestCase(-456789012.0, "Int32", -456789012)]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern double Int32(int value);

        [TestCase(45678901234.0, "Int64", 45678901234L)]
        [TestCase(-45678901234.0, "Int64", -45678901234L)]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern double Int64(long value);

        [TestCase(456789012.0, "IntPtr", 456789012)]
        //[TestCase(unchecked(4567890123.0), "IntPtr", 4567890123L)]  // Will cause overflow on 32bit test environment (IntPtr.Size == 4)
        [TestCase(-456789012.0, "IntPtr", -456789012)]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern double IntPtr(IntPtr value);

        [TestCase(123.0, "Byte", (byte)123)]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern double Byte(byte value);

        [TestCase(12345.0, "UInt16", (ushort)12345)]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern double UInt16(ushort value);

        [TestCase(456789012.0, "UInt32", (uint)456789012)]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern double UInt32(uint value);

        [TestCase(45678901234.0, "UInt64", 45678901234UL)]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern double UInt64(ulong value);

        [TestCase(456789012.0, "UIntPtr", (uint)456789012)]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern double UIntPtr(UIntPtr value);

        [TestCase((double)456789.012f, "Single", 456789.012f)]
        [TestCase((double)-456789.012f, "Single", -456789.012f)]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern double Single(float value);

        [TestCase(456789.01234, "Double", 456789.01234)]
        [TestCase(-456789.01234, "Double", -456789.01234)]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern double Double(double value);
    }
}
