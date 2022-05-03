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
    [TestCase((ushort)123, "Byte", (byte)123)]
    [TestCase((ushort)12345, "Int16", (short)12345)]
    [TestCase(unchecked((ushort)-12345), "Int16", (short)-12345)]
    [TestCase((ushort)12345, "Int32", 12345)]
    [TestCase(unchecked((ushort)45678), "Int32", 45678)]
    [TestCase(unchecked((ushort)-45678), "Int32", -45678)]
    [TestCase((ushort)12345L, "Int64", 12345L)]
    [TestCase(unchecked((ushort)45678L), "Int64", 45678L)]
    [TestCase(unchecked((ushort)-45678L), "Int64", -45678L)]
    [TestCase((ushort)12345, "IntPtr", 12345)]
    [TestCase(unchecked((ushort)45678), "IntPtr", 45678)]
    [TestCase((ushort)123, "SByte", (sbyte)123)]
    [TestCase(unchecked((ushort)-123), "SByte", (sbyte)-123)]
    [TestCase((ushort)12345, "UInt16", (ushort)12345)]
    [TestCase((ushort)12345, "UInt32", (uint)12345)]
    [TestCase((ushort)12345, "UInt64", (ulong)12345)]
    [TestCase((ushort)12345, "UIntPtr", (uint)12345)]
    [TestCase((ushort)12345, "Single", 12345.67f)]
    [TestCase(unchecked((ushort)45678), "Single", 45678.91f)]
    [TestCase((ushort)12345, "Double", 12345.67)]
    [TestCase(unchecked((ushort)45678), "Double", 45678.91)]
    public sealed class Conv_u2
    {
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern ushort Byte(byte value);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern ushort Int16(short value);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern ushort Int32(int value);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern ushort Int64(long value);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern ushort IntPtr(IntPtr value);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern ushort SByte(sbyte value);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern ushort UInt16(ushort value);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern ushort UInt32(uint value);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern ushort UInt64(ulong value);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern ushort UIntPtr(UIntPtr value);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern ushort Single(float value);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern ushort Double(double value);
    }
}
