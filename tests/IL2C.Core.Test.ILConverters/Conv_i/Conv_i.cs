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
    [TestCase(12345, "Int16", (short)12345)]
    [TestCase(12345, "Int32", 12345)]
    [TestCase(12345, "Int64", 12345L)]
    [TestCase(12345, "IntPtr", 12345)]
    [TestCase(123, "Byte", (byte)123)]
    [TestCase(12345, "UInt16", (ushort)12345)]
    [TestCase(12345, "UInt32", (uint)12345)]
    [TestCase(12345, "UInt64", 12345UL)]
    [TestCase(12345, "UIntPtr", (uint)12345)]
    [TestCase(12345, "Single", 12345.67f)]
    [TestCase(12345, "Double", 12345.67)]
    public sealed class Conv_i
    {
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern IntPtr SByte(sbyte value);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern IntPtr Int16(short value);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern IntPtr Int32(int value);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern IntPtr Int64(long value);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern IntPtr IntPtr(IntPtr value);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern IntPtr Byte(byte value);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern IntPtr UInt16(ushort value);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern IntPtr UInt32(uint value);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern IntPtr UInt64(ulong value);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern IntPtr UIntPtr(UIntPtr value);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern IntPtr Single(float value);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern IntPtr Double(double value);
    }
}
