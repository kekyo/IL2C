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
    [TestCase(123f, "SByte", (sbyte)123)]
    [TestCase(-123f, "SByte", (sbyte)-123)]
    [TestCase(12345f, "Int16", (short)12345)]
    [TestCase(-12345f, "Int16", (short)-12345)]
    [TestCase((float)456789012, "Int32", 456789012)]
    [TestCase((float)-456789012, "Int32", -456789012)]
    [TestCase((float)45678901234L, "Int64", 45678901234L)]
    [TestCase((float)-45678901234L, "Int64", -45678901234L)]
    [TestCase((float)456789012, "IntPtr", 456789012)]
    //[TestCase(unchecked((float)4567890123L), "IntPtr", 4567890123L)]  // Will cause overflow on 32bit test environment (IntPtr.Size == 4)
    [TestCase((float)-456789012, "IntPtr", -456789012)]
    [TestCase(123f, "Byte", (byte)123)]
    [TestCase(12345f, "UInt16", (ushort)12345)]
    [TestCase((float)456789012, "UInt32", (uint)456789012)]
    [TestCase((float)45678901234UL, "UInt64", 45678901234UL)]
    [TestCase((float)456789012, "UIntPtr", (uint)456789012)]
    [TestCase(456789.012f, "Single", 456789.012f)]
    [TestCase(-456789.012f, "Single", -456789.012f)]
    [TestCase(456789.012f, "Double", 456789.012)]
    [TestCase(-456789.012f, "Double", -456789.012)]
    public sealed class Conv_r4
    {
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern float SByte(sbyte value);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern float Int16(short value);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern float Int32(int value);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern float Int64(long value);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern float IntPtr(IntPtr value);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern float Byte(byte value);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern float UInt16(ushort value);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern float UInt32(uint value);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern float UInt64(ulong value);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern float UIntPtr(UIntPtr value);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern float Single(float value);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern float Double(double value);
    }
}
