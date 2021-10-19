using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace IL2C.RuntimeSystems
{
    public static class TypeInitializer_DefaultValues_Field
    {
        public static bool BooleanValue = true;
        public static readonly byte ByteValue = 10;
        public static short Int16Value = 10;
        public static readonly int Int32Value = 10;
        public static readonly long Int64Value = 10;
        public static readonly sbyte SByteValue = 10;
        public static readonly ushort UInt16Value = 10;
        public static uint UInt32Value = 10;
        public static readonly ulong UInt64Value = 10;
        public static readonly IntPtr IntPtrValue = (IntPtr)10;
        public static UIntPtr UIntPtrValue = (UIntPtr)10;
        public static readonly float SingleValue = 10.0f;
        public static readonly double DoubleValue = 10.0;
        public static readonly char CharValue = 'X';
        public static string StringValue = "StringValue";
        public static int[] Array = new[] { 1, 2, 3 };
    }

    [TestId("TypeInitializer_Defaults")]
    [Description("These tests are verified the IL2C can handle the type initializer special translation cases.")]
    [TestCase(true, "Bool", IncludeTypes = new[] { typeof(TypeInitializer_DefaultValues_Field) })]
    [TestCase((byte)10, "Byte", IncludeTypes = new[] { typeof(TypeInitializer_DefaultValues_Field) })]
    [TestCase((short)10, "Int16", IncludeTypes = new[] { typeof(TypeInitializer_DefaultValues_Field) })]
    [TestCase((int)10, "Int32", IncludeTypes = new[] { typeof(TypeInitializer_DefaultValues_Field) })]
    [TestCase((long)10, "Int64", IncludeTypes = new[] { typeof(TypeInitializer_DefaultValues_Field) })]
    [TestCase((sbyte)10, "SByte", IncludeTypes = new[] { typeof(TypeInitializer_DefaultValues_Field) })]
    [TestCase((ushort)10, "UInt16", IncludeTypes = new[] { typeof(TypeInitializer_DefaultValues_Field) })]
    [TestCase((uint)10, "UInt32", IncludeTypes = new[] { typeof(TypeInitializer_DefaultValues_Field) })]
    [TestCase((ulong)10, "UInt64", IncludeTypes = new[] { typeof(TypeInitializer_DefaultValues_Field) })]
    [TestCase((int)10, "IntPtr", IncludeTypes = new[] { typeof(TypeInitializer_DefaultValues_Field) })]
    [TestCase((uint)10, "UIntPtr", IncludeTypes = new[] { typeof(TypeInitializer_DefaultValues_Field) })]
    [TestCase((float)10f, "Single", IncludeTypes = new[] { typeof(TypeInitializer_DefaultValues_Field) })]
    [TestCase((double)10f, "Double", IncludeTypes = new[] { typeof(TypeInitializer_DefaultValues_Field) })]
    [TestCase((char)'X', "Char", IncludeTypes = new[] { typeof(TypeInitializer_DefaultValues_Field) })]
    [TestCase("StringValue", "String", IncludeTypes = new[] { typeof(TypeInitializer_DefaultValues_Field) })]
    [TestCase(true, "Array", IncludeTypes = new[] { typeof(TypeInitializer_DefaultValues_Field) })]
    public sealed class TypeInitializer_DefaultValues
    {
        public static bool Bool()
        {
            return TypeInitializer_DefaultValues_Field.BooleanValue;
        }

        public static byte Byte()
        {
            return TypeInitializer_DefaultValues_Field.ByteValue;
        }

        public static short Int16()
        {
            return TypeInitializer_DefaultValues_Field.Int16Value;
        }

        public static int Int32()
        {
            return TypeInitializer_DefaultValues_Field.Int32Value;
        }

        public static long Int64()
        {
            return TypeInitializer_DefaultValues_Field.Int64Value;
        }

        public static sbyte SByte()
        {
            return TypeInitializer_DefaultValues_Field.SByteValue;
        }

        public static ushort UInt16()
        {
            return TypeInitializer_DefaultValues_Field.UInt16Value;
        }

        public static uint UInt32()
        {
            return TypeInitializer_DefaultValues_Field.UInt32Value;
        }

        public static ulong UInt64()
        {
            return TypeInitializer_DefaultValues_Field.UInt64Value;
        }

        public static IntPtr IntPtr()
        {
            return TypeInitializer_DefaultValues_Field.IntPtrValue;
        }

        public static UIntPtr UIntPtr()
        {
            return TypeInitializer_DefaultValues_Field.UIntPtrValue;
        }

        public static float Single()
        {
            return TypeInitializer_DefaultValues_Field.SingleValue;
        }

        public static double Double()
        {
            return TypeInitializer_DefaultValues_Field.DoubleValue;
        }

        public static char Char()
        {
            return TypeInitializer_DefaultValues_Field.CharValue;
        }

        public static string String()
        {
            return TypeInitializer_DefaultValues_Field.StringValue;
        }

        public static bool Array()
        {
            var array = TypeInitializer_DefaultValues_Field.Array;
            if (array == null) return false;
            if (array.Length != 3) return false;
            if (array[0] != 1) return false;
            if (array[1] != 2) return false;
            if (array[2] != 3) return false;
            return true;
        }
    }
}
