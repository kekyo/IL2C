////////////////////////////////////////////////////////////////////////////
//
// IL2C - A translator for ECMA-335 CIL/MSIL to C language.
// Copyright (c) Kouji Matsui (@kozy_kekyo, @kekyo@mastodon.cloud)
//
// Licensed under Apache-v2: https://opensource.org/licenses/Apache-2.0
//
////////////////////////////////////////////////////////////////////////////

using System;
using System.ComponentModel;

namespace IL2C.RuntimeSystems
{
    public static class TypeInitializer_Field
    {
        public static readonly bool BooleanValue;
        public static readonly byte ByteValue;
        public static readonly short Int16Value;
        public static readonly int Int32Value;
        public static readonly long Int64Value;
        public static readonly sbyte SByteValue;
        public static readonly ushort UInt16Value;
        public static readonly uint UInt32Value;
        public static readonly ulong UInt64Value;
        public static readonly IntPtr IntPtrValue;
        public static readonly UIntPtr UIntPtrValue;
        public static readonly float SingleValue;
        public static readonly double DoubleValue;
        public static readonly char CharValue;
        public static readonly string StringValue;

        static TypeInitializer_Field()
        {
            BooleanValue = !BooleanValue;
            ByteValue = (byte)(ByteValue + 1);
            Int16Value = (short)(Int16Value + 1);
            Int32Value = (int)(Int32Value + 1);
            Int64Value = (long)(Int64Value + 1);
            SByteValue = (sbyte)(SByteValue + 1);
            UInt16Value = (ushort)(UInt16Value + 1);
            UInt32Value = (uint)(UInt32Value + 1);
            UInt64Value = (ulong)(UInt64Value + 1);
            IntPtrValue = (IntPtr)(IntPtrValue + 1);
            UIntPtrValue = (UIntPtr)(UIntPtrValue + 1);
            SingleValue = (float)(SingleValue + 1);
            DoubleValue = (double)(DoubleValue + 1);
            CharValue = (char)(CharValue + 1);
            StringValue = StringValue + "ABC";

            DoRefInt32(ref Int32Value);
        }

        private static void DoRefInt32(ref int value)
        {
            value += 2;
        }
    }

    public static class TypeInitializer_None
    {
        public static readonly int Int32Value;
        public static readonly string? StringValue;
    }

    public static class TypeInitializer_NonTrackingGCs
    {
        public static readonly bool BooleanValue;
        public static readonly byte ByteValue;
        public static readonly short Int16Value;
        public static readonly int Int32Value;
        public static readonly long Int64Value;
        public static readonly sbyte SByteValue;
        public static readonly ushort UInt16Value;
        public static readonly uint UInt32Value;
        public static readonly ulong UInt64Value;
        public static readonly IntPtr IntPtrValue;
        public static readonly UIntPtr UIntPtrValue;
        public static readonly float SingleValue;
        public static readonly double DoubleValue;
        public static readonly char CharValue;
    }

    [TestId("TypeInitializer")]
    [Description("These tests are verified the IL2C can handle the type initializer special translation cases.")]
    public sealed partial class TypeInitializer
    {
        [TestCase(true, "Bool", IncludeTypes = new[] { typeof(TypeInitializer_Field) })]
        public static bool Bool()
        {
            return TypeInitializer_Field.BooleanValue;
        }

        [TestCase((byte)1, "Byte", IncludeTypes = new[] { typeof(TypeInitializer_Field) })]
        public static byte Byte()
        {
            return TypeInitializer_Field.ByteValue;
        }

        [TestCase((short)1, "Int16", IncludeTypes = new[] { typeof(TypeInitializer_Field) })]
        public static short Int16()
        {
            return TypeInitializer_Field.Int16Value;
        }

        [TestCase((int)3, "Int32", IncludeTypes = new[] { typeof(TypeInitializer_Field) })]
        public static int Int32()
        {
            return TypeInitializer_Field.Int32Value;
        }

        [TestCase((long)1, "Int64", IncludeTypes = new[] { typeof(TypeInitializer_Field) })]
        public static long Int64()
        {
            return TypeInitializer_Field.Int64Value;
        }

        [TestCase((sbyte)1, "SByte", IncludeTypes = new[] { typeof(TypeInitializer_Field) })]
        public static sbyte SByte()
        {
            return TypeInitializer_Field.SByteValue;
        }

        [TestCase((ushort)1, "UInt16", IncludeTypes = new[] { typeof(TypeInitializer_Field) })]
        public static ushort UInt16()
        {
            return TypeInitializer_Field.UInt16Value;
        }

        [TestCase((uint)1, "UInt32", IncludeTypes = new[] { typeof(TypeInitializer_Field) })]
        public static uint UInt32()
        {
            return TypeInitializer_Field.UInt32Value;
        }

        [TestCase((ulong)1, "UInt64", IncludeTypes = new[] { typeof(TypeInitializer_Field) })]
        public static ulong UInt64()
        {
            return TypeInitializer_Field.UInt64Value;
        }

        [TestCase((int)1, "IntPtr", IncludeTypes = new[] { typeof(TypeInitializer_Field) })]
        public static int IntPtr()
        {
            return TypeInitializer_Field.IntPtrValue.ToInt32();
        }

        [TestCase((uint)1, "UIntPtr", IncludeTypes = new[] { typeof(TypeInitializer_Field) })]
        public static uint UIntPtr()
        {
            return TypeInitializer_Field.UIntPtrValue.ToUInt32();
        }

        [TestCase((float)1, "Single", IncludeTypes = new[] { typeof(TypeInitializer_Field) })]
        public static float Single()
        {
            return TypeInitializer_Field.SingleValue;
        }

        [TestCase((double)1, "Double", IncludeTypes = new[] { typeof(TypeInitializer_Field) })]
        public static double Double()
        {
            return TypeInitializer_Field.DoubleValue;
        }

        [TestCase((char)1, "Char", IncludeTypes = new[] { typeof(TypeInitializer_Field) })]
        public static char Char()
        {
            return TypeInitializer_Field.CharValue;
        }

        [TestCase("ABC", "String", IncludeTypes = new[] { typeof(TypeInitializer_Field) })]
        public static string String()
        {
            return TypeInitializer_Field.StringValue;
        }

        [TestCase(0, "Int32_None", IncludeTypes = new[] { typeof(TypeInitializer_None) })]
        public static int Int32_None()
        {
            return TypeInitializer_None.Int32Value;
        }

        [TestCase(null, "String_None", IncludeTypes = new[] { typeof(TypeInitializer_None) }, Assert = TestCaseAsserts.PerfectMatch)]
        public static string? String_None()
        {
            return TypeInitializer_None.StringValue;
        }

        // Only manual revewing generated C source code.
        [TestCase(0, "NonTracked", IncludeTypes = new[] { typeof(TypeInitializer_NonTrackingGCs) })]
        public static int NonTracked()
        {
            return TypeInitializer_NonTrackingGCs.Int32Value;
        }
    }
}
