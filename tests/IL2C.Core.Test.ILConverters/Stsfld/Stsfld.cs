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
    public static class Stsfld_Field
    {
        public static bool BooleanValue;
        public static byte ByteValue;
        public static short Int16Value;
        public static int Int32Value;
        public static long Int64Value;
        public static sbyte SByteValue;
        public static ushort UInt16Value;
        public static uint UInt32Value;
        public static ulong UInt64Value;
        public static IntPtr IntPtrValue;
        public static UIntPtr UIntPtrValue;
        public static float SingleValue;
        public static double DoubleValue;
        public static char CharValue;
        public static string? StringValue;
    }

    public sealed class Stsfld
    {
        [TestCase(true, "Boolean", true, IncludeTypes = new[] { typeof(Stsfld_Field) })]
        [TestCase(false, "Boolean", false, IncludeTypes = new[] { typeof(Stsfld_Field) })]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern bool Boolean(bool value);

        [TestCase(byte.MaxValue, "Byte", byte.MaxValue, IncludeTypes = new[] { typeof(Stsfld_Field) })]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern byte Byte(byte value);

        [TestCase(short.MaxValue, "Int16", short.MaxValue, IncludeTypes = new[] { typeof(Stsfld_Field) })]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern short Int16(short value);

        [TestCase(int.MaxValue, "Int32", int.MaxValue, IncludeTypes = new[] { typeof(Stsfld_Field) })]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern int Int32(int value);

        [TestCase(long.MaxValue, "Int64", long.MaxValue, IncludeTypes = new[] { typeof(Stsfld_Field) })]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern long Int64(long value);

        [TestCase(sbyte.MaxValue, "SByte", sbyte.MaxValue, IncludeTypes = new[] { typeof(Stsfld_Field) })]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern sbyte SByte(sbyte value);

        [TestCase(ushort.MaxValue, "UInt16", ushort.MaxValue, IncludeTypes = new[] { typeof(Stsfld_Field) })]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern ushort UInt16(ushort value);

        [TestCase(uint.MaxValue, "UInt32", uint.MaxValue, IncludeTypes = new[] { typeof(Stsfld_Field) })]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern uint UInt32(uint value);

        [TestCase(ulong.MaxValue, "UInt64", ulong.MaxValue, IncludeTypes = new[] { typeof(Stsfld_Field) })]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern ulong UInt64(ulong value);

        [TestCase(int.MaxValue, "IntPtr", int.MaxValue, IncludeTypes = new[] { typeof(Stsfld_Field) })]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern IntPtr IntPtr(IntPtr value);

        [TestCase(uint.MaxValue, "UIntPtr", uint.MaxValue, IncludeTypes = new[] { typeof(Stsfld_Field) })]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern UIntPtr UIntPtr(UIntPtr value);

        [TestCase(3.14159274f, "Single", 3.14159274f, IncludeTypes = new[] { typeof(Stsfld_Field) })]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern float Single(float value);

        [TestCase(3.1415926535897931, "Double", 3.1415926535897931, IncludeTypes = new[] { typeof(Stsfld_Field) })]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern double Double(double value);

        [TestCase('A', "Char", 'A', IncludeTypes = new[] { typeof(Stsfld_Field) })]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern char Char(char value);

        [TestCase("ABC", "String", "ABC", IncludeTypes = new[] { typeof(Stsfld_Field) })]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern string String(string value);
    }
}
