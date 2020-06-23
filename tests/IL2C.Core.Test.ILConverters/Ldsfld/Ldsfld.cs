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
    public static class Ldsfld_Field
    {
        public static readonly bool TrueValue = true;
        public static readonly bool FalseValue = false;
        public static readonly byte ByteValue = byte.MaxValue;
        public static readonly short Int16Value = short.MaxValue;
        public static readonly int Int32Value = int.MaxValue;
        public static readonly long Int64Value = long.MaxValue;
        public static readonly sbyte SByteValue = sbyte.MaxValue;
        public static readonly ushort UInt16Value = ushort.MaxValue;
        public static readonly uint UInt32Value = uint.MaxValue;
        public static readonly ulong UInt64Value = ulong.MaxValue;
        public static readonly IntPtr IntPtrValue = (IntPtr)int.MaxValue;
        public static readonly UIntPtr UIntPtrValue = (UIntPtr)uint.MaxValue;
        public static readonly float SingleValue = 3.14159274f;
        public static readonly double DoubleValue = 3.1415926535897931;
        public static readonly char CharValue = 'A';
        public static readonly string StringValue = "ABC";
    }

    [TestCase(true, "True", IncludeTypes = new[] { typeof(Ldsfld_Field) })]
    [TestCase(false, "False", IncludeTypes = new[] { typeof(Ldsfld_Field) })]
    [TestCase(byte.MaxValue, "Byte", IncludeTypes = new[] { typeof(Ldsfld_Field) })]
    [TestCase(short.MaxValue, "Int16", IncludeTypes = new[] { typeof(Ldsfld_Field) })]
    [TestCase(int.MaxValue, "Int32", IncludeTypes = new[] { typeof(Ldsfld_Field) })]
    [TestCase(long.MaxValue, "Int64", IncludeTypes = new[] { typeof(Ldsfld_Field) })]
    [TestCase(sbyte.MaxValue, "SByte", IncludeTypes = new[] { typeof(Ldsfld_Field) })]
    [TestCase(ushort.MaxValue, "UInt16", IncludeTypes = new[] { typeof(Ldsfld_Field) })]
    [TestCase(uint.MaxValue, "UInt32", IncludeTypes = new[] { typeof(Ldsfld_Field) })]
    [TestCase(ulong.MaxValue, "UInt64", IncludeTypes = new[] { typeof(Ldsfld_Field) })]
    [TestCase(int.MaxValue, "IntPtr", IncludeTypes = new[] { typeof(Ldsfld_Field) })]
    [TestCase(uint.MaxValue, "UIntPtr", IncludeTypes = new[] { typeof(Ldsfld_Field) })]
    [TestCase(3.14159274f, "Single", IncludeTypes = new[] { typeof(Ldsfld_Field) })]
    [TestCase(3.1415926535897931, "Double", IncludeTypes = new[] { typeof(Ldsfld_Field) })]
    [TestCase('A', "Char", IncludeTypes = new[] { typeof(Ldsfld_Field) })]
    [TestCase("ABC", "String", IncludeTypes = new[] { typeof(Ldsfld_Field) })]
    public sealed class Ldsfld
    {
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern bool True();

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern bool False();

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern byte Byte();

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern short Int16();

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern int Int32();

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern long Int64();

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern sbyte SByte();

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern ushort UInt16();

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern uint UInt32();

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern ulong UInt64();

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern IntPtr IntPtr();

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern UIntPtr UIntPtr();

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern float Single();

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern double Double();

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern char Char();

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern string String();
    }
}
