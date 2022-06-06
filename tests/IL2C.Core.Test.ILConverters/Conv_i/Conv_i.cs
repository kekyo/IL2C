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
    public sealed class Conv_i
    {
            [MethodImpl(MethodImplOptions.ForwardRef)]
            private static extern IntPtr SByteImpl(sbyte value);

        [TestCase(123, "SByte", (sbyte)123)]
        public static int SByte(sbyte value) =>
            SByteImpl(value).ToInt32();

            [MethodImpl(MethodImplOptions.ForwardRef)]
            private static extern IntPtr Int16Impl(short value);

        [TestCase(12345, "Int16", (short)12345)]
        public static int Int16(short value) =>
            Int16Impl(value).ToInt32();

            [MethodImpl(MethodImplOptions.ForwardRef)]
        private static extern IntPtr Int32Impl(int value);

        [TestCase(12345, "Int32", 12345)]
        public static int Int32(int value) =>
            Int32Impl(value).ToInt32();

            [MethodImpl(MethodImplOptions.ForwardRef)]
            private static extern IntPtr Int64Impl(long value);

        [TestCase(12345L, "Int64", 12345L)]
        public static long Int64(long value) =>
            Int64Impl(value).ToInt64();

            [MethodImpl(MethodImplOptions.ForwardRef)]
            private static extern IntPtr IntPtrImpl(IntPtr value);

        [TestCase(12345, "IntPtr", 12345)]
        public static int IntPtr(int value) =>
            IntPtrImpl((IntPtr)value).ToInt32();

            [MethodImpl(MethodImplOptions.ForwardRef)]
            private static extern IntPtr ByteImpl(byte value);

        [TestCase(123, "Byte", (byte)123)]
        public static int Byte(byte value) =>
            ByteImpl(value).ToInt32();

            [MethodImpl(MethodImplOptions.ForwardRef)]
            private static extern IntPtr UInt16Impl(ushort value);

        [TestCase(12345, "UInt16", (ushort)12345)]
        public static int UInt16(ushort value) =>
            UInt16Impl(value).ToInt32();

            [MethodImpl(MethodImplOptions.ForwardRef)]
            private static extern IntPtr UInt32Impl(uint value);

        [TestCase(12345, "UInt32", (uint)12345)]
        public static int UInt32(uint value) =>
            UInt32Impl(value).ToInt32();

            [MethodImpl(MethodImplOptions.ForwardRef)]
            private static extern IntPtr UInt64Impl(ulong value);

        [TestCase(12345, "UInt64", 12345UL)]
        public static int UInt64(ulong value) =>
            UInt64Impl(value).ToInt32();

            [MethodImpl(MethodImplOptions.ForwardRef)]
            private static extern IntPtr UIntPtrImpl(UIntPtr value);

        [TestCase(12345, "UIntPtr", (uint)12345)]
        public static int UIntPtr(uint value) =>
            UIntPtrImpl((UIntPtr)value).ToInt32();

            [MethodImpl(MethodImplOptions.ForwardRef)]
            private static extern IntPtr SingleImpl(float value);

        [TestCase(12345, "Single", 12345.67f)]
        public static int Single(float value) =>
            SingleImpl(value).ToInt32();

            [MethodImpl(MethodImplOptions.ForwardRef)]
            private static extern IntPtr DoubleImpl(double value);

        [TestCase(12345, "Double", 12345.67)]
        public static int Double(double value) =>
            DoubleImpl(value).ToInt32();
    }
}
