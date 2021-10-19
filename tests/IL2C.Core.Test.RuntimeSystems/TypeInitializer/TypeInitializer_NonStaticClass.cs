using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace IL2C.RuntimeSystems
{
    public class TypeInitializer_NonStaticClass_Fields
    {
        public static bool BooleanValue;
        public static readonly byte ByteValue;
        public static readonly short Int16Value;
        public static readonly int Int32Value;
        public static readonly long Int64Value;
        public static readonly sbyte SByteValue;
        public static ushort UInt16Value;
        public static readonly uint UInt32Value;
        public static readonly ulong UInt64Value;
        public static readonly IntPtr IntPtrValue;
        public static readonly UIntPtr UIntPtrValue;
        public static float SingleValue;
        public static readonly double DoubleValue;
        public static readonly char CharValue;
        public static readonly string StringValue;

        static TypeInitializer_NonStaticClass_Fields()
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

    [TestId("TypeInitializer_Non_Static_Class")]
    [Description("These tests are verified the IL2C can handle the type initializer special translation cases.")]
    [TestCase(true, "Bool", IncludeTypes = new[] { typeof(TypeInitializer_NonStaticClass_Fields) })]
    [TestCase((byte)1, "Byte", IncludeTypes = new[] { typeof(TypeInitializer_NonStaticClass_Fields) })]
    [TestCase((short)1, "Int16", IncludeTypes = new[] { typeof(TypeInitializer_NonStaticClass_Fields) })]
    [TestCase((int)3, "Int32", IncludeTypes = new[] { typeof(TypeInitializer_NonStaticClass_Fields) })]
    [TestCase((long)1, "Int64", IncludeTypes = new[] { typeof(TypeInitializer_NonStaticClass_Fields) })]
    [TestCase((sbyte)1, "SByte", IncludeTypes = new[] { typeof(TypeInitializer_NonStaticClass_Fields) })]
    [TestCase((ushort)1, "UInt16", IncludeTypes = new[] { typeof(TypeInitializer_NonStaticClass_Fields) })]
    [TestCase((uint)1, "UInt32", IncludeTypes = new[] { typeof(TypeInitializer_NonStaticClass_Fields) })]
    [TestCase((ulong)1, "UInt64", IncludeTypes = new[] { typeof(TypeInitializer_NonStaticClass_Fields) })]
    [TestCase((int)1, "IntPtr", IncludeTypes = new[] { typeof(TypeInitializer_NonStaticClass_Fields) })]
    [TestCase((uint)1, "UIntPtr", IncludeTypes = new[] { typeof(TypeInitializer_NonStaticClass_Fields) })]
    [TestCase((float)1, "Single", IncludeTypes = new[] { typeof(TypeInitializer_NonStaticClass_Fields) })]
    [TestCase((double)1, "Double", IncludeTypes = new[] { typeof(TypeInitializer_NonStaticClass_Fields) })]
    [TestCase((char)1, "Char", IncludeTypes = new[] { typeof(TypeInitializer_NonStaticClass_Fields) })]
    [TestCase("ABC", "String", IncludeTypes = new[] { typeof(TypeInitializer_NonStaticClass_Fields) })]
    public sealed class TypeInitializer_NonStaticClass
    {
        public static bool Bool()
        {
            return TypeInitializer_NonStaticClass_Fields.BooleanValue;
        }

        public static byte Byte()
        {
            return TypeInitializer_NonStaticClass_Fields.ByteValue;
        }

        public static short Int16()
        {
            return TypeInitializer_NonStaticClass_Fields.Int16Value;
        }

        public static int Int32()
        {
            return TypeInitializer_NonStaticClass_Fields.Int32Value;
        }

        public static long Int64()
        {
            return TypeInitializer_NonStaticClass_Fields.Int64Value;
        }

        public static sbyte SByte()
        {
            return TypeInitializer_NonStaticClass_Fields.SByteValue;
        }

        public static ushort UInt16()
        {
            return TypeInitializer_NonStaticClass_Fields.UInt16Value;
        }

        public static uint UInt32()
        {
            return TypeInitializer_NonStaticClass_Fields.UInt32Value;
        }

        public static ulong UInt64()
        {
            return TypeInitializer_NonStaticClass_Fields.UInt64Value;
        }

        public static IntPtr IntPtr()
        {
            return TypeInitializer_NonStaticClass_Fields.IntPtrValue;
        }

        public static UIntPtr UIntPtr()
        {
            return TypeInitializer_NonStaticClass_Fields.UIntPtrValue;
        }

        public static float Single()
        {
            return TypeInitializer_NonStaticClass_Fields.SingleValue;
        }

        public static double Double()
        {
            return TypeInitializer_NonStaticClass_Fields.DoubleValue;
        }

        public static char Char()
        {
            return TypeInitializer_NonStaticClass_Fields.CharValue;
        }

        public static string String()
        {
            return TypeInitializer_NonStaticClass_Fields.StringValue;
        }
    }
}
