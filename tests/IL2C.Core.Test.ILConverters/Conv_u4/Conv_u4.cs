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
    [TestCase((uint)123, "Byte", (byte)123)]
    [TestCase((uint)12345, "Int16", (short)12345)]
    [TestCase(unchecked((uint)-12345), "Int16", (short)-12345)]
    [TestCase((uint)12345, "Int32", 12345)]
    [TestCase(unchecked ((uint)-45678), "Int32", -45678)]
    [TestCase((uint)12345, "Int64", 12345L)]
    [TestCase(unchecked((uint)-45678L), "Int64", -45678L)]
    [TestCase((uint)12345, "IntPtr", 12345)]
    [TestCase(unchecked((uint)-45678), "IntPtr", -45678)]
    [TestCase((uint)123, "SByte", (sbyte)123)]
    [TestCase(unchecked((uint)-123), "SByte", (sbyte)-123)]
    [TestCase((uint)12345, "UInt16", (ushort)12345)]
    [TestCase((uint)12345, "UInt32", (uint)12345)]
    [TestCase((uint)12345, "UInt64", (ulong)12345)]
    [TestCase((uint)12345, "UIntPtr", (uint)12345)]
    [TestCase((uint)12345.67f, "Single", 12345.67f)]
    [TestCase(unchecked((uint)(int)-45678.91f), "Single", -45678.91f)]
    [TestCase((uint)12345.6789, "Double", 12345.6789)]
    [TestCase(unchecked((uint)45678.90123), "Double", 45678.90123)]
    public sealed class Conv_u4
    {
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern uint Byte(byte value);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern uint Int16(short value);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern uint Int32(int value);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern uint Int64(long value);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern uint IntPtr(IntPtr value);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern uint SByte(sbyte value);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern uint UInt16(ushort value);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern uint UInt32(uint value);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern uint UInt64(ulong value);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern uint UIntPtr(UIntPtr value);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern uint Single(float value);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern uint Double(double value);
    }
}
