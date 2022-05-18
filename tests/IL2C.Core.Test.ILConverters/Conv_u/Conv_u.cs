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
    public sealed class Conv_u
    {
        [TestCase((uint)123, "SByte", (sbyte)123)]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern UIntPtr SByte(sbyte value);

        [TestCase((uint)12345, "Int16", (short)12345)]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern UIntPtr Int16(short value);

        [TestCase((uint)12345, "Int32", 12345)]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern UIntPtr Int32(int value);

        [TestCase((uint)12345, "Int64", 12345L)]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern UIntPtr Int64(long value);

        [TestCase((uint)12345, "IntPtr", 12345)]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern UIntPtr IntPtr(IntPtr value);

        [TestCase((uint)123, "Byte", (byte)123)]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern UIntPtr Byte(byte value);

        [TestCase((uint)12345, "UInt16", (ushort)12345)]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern UIntPtr UInt16(ushort value);

        [TestCase((uint)12345, "UInt32", (uint)12345)]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern UIntPtr UInt32(uint value);

        [TestCase((uint)12345, "UInt64", 12345UL)]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern UIntPtr UInt64(ulong value);

        [TestCase((uint)12345, "UIntPtr", (uint)12345)]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern UIntPtr UIntPtr(UIntPtr value);

        [TestCase((uint)12345, "Single", 12345.67f)]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern UIntPtr Single(float value);

        [TestCase((uint)12345, "Double", 12345.67)]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern UIntPtr Double(double value);
    }
}
