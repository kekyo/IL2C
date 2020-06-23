/////////////////////////////////////////////////////////////////////////////////////////////////
//
// IL2C - A translator for ECMA-335 CIL/MSIL to C language.
// Copyright (c) 2016-2019 Kouji Matsui (@kozy_kekyo, @kekyo2)
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//	http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
/////////////////////////////////////////////////////////////////////////////////////////////////

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

    [TestId("TypeInitializer")]
    [Description("These tests are verified the IL2C can handle the type initializer special translation cases.")]
    [TestCase(true, "Bool", IncludeTypes = new[] { typeof(TypeInitializer_Field) })]
    [TestCase((byte)1, "Byte", IncludeTypes = new[] { typeof(TypeInitializer_Field) })]
    [TestCase((short)1, "Int16", IncludeTypes = new[] { typeof(TypeInitializer_Field) })]
    [TestCase((int)3, "Int32", IncludeTypes = new[] { typeof(TypeInitializer_Field) })]
    [TestCase((long)1, "Int64", IncludeTypes = new[] { typeof(TypeInitializer_Field) })]
    [TestCase((sbyte)1, "SByte", IncludeTypes = new[] { typeof(TypeInitializer_Field) })]
    [TestCase((ushort)1, "UInt16", IncludeTypes = new[] { typeof(TypeInitializer_Field) })]
    [TestCase((uint)1, "UInt32", IncludeTypes = new[] { typeof(TypeInitializer_Field) })]
    [TestCase((ulong)1, "UInt64", IncludeTypes = new[] { typeof(TypeInitializer_Field) })]
    [TestCase((int)1, "IntPtr", IncludeTypes = new[] { typeof(TypeInitializer_Field) })]
    [TestCase((uint)1, "UIntPtr", IncludeTypes = new[] { typeof(TypeInitializer_Field) })]
    [TestCase((float)1, "Single", IncludeTypes = new[] { typeof(TypeInitializer_Field) })]
    [TestCase((double)1, "Double", IncludeTypes = new[] { typeof(TypeInitializer_Field) })]
    [TestCase((char)1, "Char", IncludeTypes = new[] { typeof(TypeInitializer_Field) })]
    [TestCase("ABC", "String", IncludeTypes = new[] { typeof(TypeInitializer_Field) })]
    public sealed class TypeInitializer
    {
        public static bool Bool()
        {
            return TypeInitializer_Field.BooleanValue;
        }

        public static byte Byte()
        {
            return TypeInitializer_Field.ByteValue;
        }

        public static short Int16()
        {
            return TypeInitializer_Field.Int16Value;
        }

        public static int Int32()
        {
            return TypeInitializer_Field.Int32Value;
        }

        public static long Int64()
        {
            return TypeInitializer_Field.Int64Value;
        }

        public static sbyte SByte()
        {
            return TypeInitializer_Field.SByteValue;
        }

        public static ushort UInt16()
        {
            return TypeInitializer_Field.UInt16Value;
        }

        public static uint UInt32()
        {
            return TypeInitializer_Field.UInt32Value;
        }

        public static ulong UInt64()
        {
            return TypeInitializer_Field.UInt64Value;
        }

        public static IntPtr IntPtr()
        {
            return TypeInitializer_Field.IntPtrValue;
        }

        public static UIntPtr UIntPtr()
        {
            return TypeInitializer_Field.UIntPtrValue;
        }

        public static float Single()
        {
            return TypeInitializer_Field.SingleValue;
        }

        public static double Double()
        {
            return TypeInitializer_Field.DoubleValue;
        }

        public static char Char()
        {
            return TypeInitializer_Field.CharValue;
        }

        public static string String()
        {
            return TypeInitializer_Field.StringValue;
        }
    }
}
