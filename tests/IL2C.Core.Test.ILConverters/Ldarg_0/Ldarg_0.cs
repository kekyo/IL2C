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
    public sealed class Ldarg_0
    {
        [TestCase(true, "Boolean", false)]
        [TestCase(false, "Boolean", true)]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern bool Boolean(bool value);

        [TestCase((byte)(byte.MaxValue - 1), "Byte", byte.MaxValue)]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern byte Byte(byte num);

        [TestCase((short)(short.MaxValue - 1), "Int16", short.MaxValue)]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern short Int16(short num);

        [TestCase(int.MaxValue - 1, "Int32", int.MaxValue)]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern int Int32(int num);

        [TestCase(long.MaxValue - 1, "Int64", long.MaxValue)]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern long Int64(long num);

        [TestCase((sbyte)(sbyte.MaxValue - 1), "SByte", sbyte.MaxValue)]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern sbyte SByte(sbyte num);

        [TestCase((ushort)(ushort.MaxValue - 1), "UInt16", ushort.MaxValue)]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern ushort UInt16(ushort num);

        [TestCase(uint.MaxValue - 1, "UInt32", uint.MaxValue)]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern uint UInt32(uint num);

        [TestCase(ulong.MaxValue - 1, "UInt64", ulong.MaxValue)]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern ulong UInt64(ulong num);

        [TestCase(int.MaxValue - 1, "IntPtr", int.MaxValue)]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern IntPtr IntPtr(IntPtr num);

        [TestCase(uint.MaxValue - 1, "UIntPtr", uint.MaxValue)]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern UIntPtr UIntPtr(UIntPtr num);

        [TestCase((float)((double)123.45f + (double)3.14159274f), "Single", 123.45f)]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern float Single(float num);

        [TestCase(123.45 + 3.1415926535897931, "Double", 123.45)]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern double Double(double num);

        [TestCase('B', "Char", 'A')]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern char Char(char ch);

        [TestCase("ABCD", "String", "ABC")]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern string String(string v);
    }
}
