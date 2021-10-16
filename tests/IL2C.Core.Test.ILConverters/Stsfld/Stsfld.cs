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
        public static string StringValue;
    }

    [TestCase(true, "Boolean", true, IncludeTypes = new[] { typeof(Stsfld_Field) })]
    [TestCase(false, "Boolean", false, IncludeTypes = new[] { typeof(Stsfld_Field) })]
    [TestCase(byte.MaxValue, "Byte", byte.MaxValue, IncludeTypes = new[] { typeof(Stsfld_Field) })]
    [TestCase(short.MaxValue, "Int16", short.MaxValue, IncludeTypes = new[] { typeof(Stsfld_Field) })]
    [TestCase(int.MaxValue, "Int32", int.MaxValue, IncludeTypes = new[] { typeof(Stsfld_Field) })]
    [TestCase(long.MaxValue, "Int64", long.MaxValue, IncludeTypes = new[] { typeof(Stsfld_Field) })]
    [TestCase(sbyte.MaxValue, "SByte", sbyte.MaxValue, IncludeTypes = new[] { typeof(Stsfld_Field) })]
    [TestCase(ushort.MaxValue, "UInt16", ushort.MaxValue, IncludeTypes = new[] { typeof(Stsfld_Field) })]
    [TestCase(uint.MaxValue, "UInt32", uint.MaxValue, IncludeTypes = new[] { typeof(Stsfld_Field) })]
    [TestCase(ulong.MaxValue, "UInt64", ulong.MaxValue, IncludeTypes = new[] { typeof(Stsfld_Field) })]
    [TestCase(int.MaxValue, "IntPtr", int.MaxValue, IncludeTypes = new[] { typeof(Stsfld_Field) })]
    [TestCase(uint.MaxValue, "UIntPtr", uint.MaxValue, IncludeTypes = new[] { typeof(Stsfld_Field) })]
    [TestCase(3.14159274f, "Single", 3.14159274f, IncludeTypes = new[] { typeof(Stsfld_Field) })]
    [TestCase(3.1415926535897931, "Double", 3.1415926535897931, IncludeTypes = new[] { typeof(Stsfld_Field) })]
    [TestCase('A', "Char", 'A', IncludeTypes = new[] { typeof(Stsfld_Field) })]
    [TestCase("ABC", "String", "ABC", IncludeTypes = new[] { typeof(Stsfld_Field) })]
    public sealed class Stsfld
    {
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern bool Boolean(bool value);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern byte Byte(byte value);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern short Int16(short value);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern int Int32(int value);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern long Int64(long value);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern sbyte SByte(sbyte value);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern ushort UInt16(ushort value);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern uint UInt32(uint value);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern ulong UInt64(ulong value);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern IntPtr IntPtr(IntPtr value);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern UIntPtr UIntPtr(UIntPtr value);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern float Single(float value);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern double Double(double value);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern char Char(char value);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern string String(string value);
    }
}
