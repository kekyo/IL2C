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
            [MethodImpl(MethodImplOptions.ForwardRef)]
            private static extern UIntPtr SByteImpl(sbyte value);

        [TestCase((uint)123, "SByte", (sbyte)123)]
        public static uint SByte(sbyte value) =>
            SByteImpl(value).ToUInt32();

            [MethodImpl(MethodImplOptions.ForwardRef)]
            private static extern UIntPtr Int16Impl(short value);

        [TestCase((uint)12345, "Int16", (short)12345)]
        public static uint Int16(short value) =>
            Int16Impl(value).ToUInt32();

            [MethodImpl(MethodImplOptions.ForwardRef)]
            private static extern UIntPtr Int32Impl(int value);

        [TestCase((uint)12345, "Int32", 12345)]
        public static uint Int32(int value) =>
            Int32Impl(value).ToUInt32();

            [MethodImpl(MethodImplOptions.ForwardRef)]
            private static extern UIntPtr Int64Impl(long value);

        [TestCase((uint)12345, "Int64", 12345L)]
        public static uint Int64(long value) =>
            Int64Impl(value).ToUInt32();

            [MethodImpl(MethodImplOptions.ForwardRef)]
            private static extern UIntPtr IntPtrImpl(IntPtr value);

        [TestCase((uint)12345, "IntPtr", 12345)]
        public static uint IntPtr(int value) =>
            IntPtrImpl((IntPtr)value).ToUInt32();

            [MethodImpl(MethodImplOptions.ForwardRef)]
            private static extern UIntPtr ByteImpl(byte value);

        [TestCase((uint)123, "Byte", (byte)123)]
        public static uint Byte(byte value) =>
            ByteImpl(value).ToUInt32();

            [MethodImpl(MethodImplOptions.ForwardRef)]
            private static extern UIntPtr UInt16Impl(ushort value);

        [TestCase((uint)12345, "UInt16", (ushort)12345)]
        public static uint UInt16(ushort value) =>
            UInt16Impl(value).ToUInt32();

            [MethodImpl(MethodImplOptions.ForwardRef)]
            private static extern UIntPtr UInt32Impl(uint value);

        [TestCase((uint)12345, "UInt32", (uint)12345)]
        public static uint UInt32(uint value) =>
            UInt32Impl(value).ToUInt32();

            [MethodImpl(MethodImplOptions.ForwardRef)]
            private static extern UIntPtr UInt64Impl(ulong value);

        [TestCase((uint)12345, "UInt64", 12345UL)]
        public static uint UInt64(ulong value) =>
            UInt64Impl(value).ToUInt32();

            [MethodImpl(MethodImplOptions.ForwardRef)]
            private static extern UIntPtr UIntPtrImpl(UIntPtr value);

        [TestCase((uint)12345, "UIntPtr", (uint)12345)]
        public static uint UIntPtr(uint value) =>
            UIntPtrImpl((UIntPtr)value).ToUInt32();

            [MethodImpl(MethodImplOptions.ForwardRef)]
            private static extern UIntPtr SingleImpl(float value);

        [TestCase((uint)12345, "Single", 12345.67f)]
        public static uint Single(float value) =>
            SingleImpl(value).ToUInt32();

            [MethodImpl(MethodImplOptions.ForwardRef)]
            public static extern UIntPtr DoubleImpl(double value);

        [TestCase((uint)12345, "Double", 12345.67)]
        public static uint Double(double value) =>
            DoubleImpl(value).ToUInt32();
    }
}
