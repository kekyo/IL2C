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
    [TestCase(true, "True")]
    [TestCase(false, "False")]
    [TestCase(byte.MaxValue, "Byte")]
    [TestCase(short.MaxValue, "Int16")]
    [TestCase(int.MaxValue, "Int32")]
    [TestCase(long.MaxValue, "Int64")]
    [TestCase(sbyte.MaxValue, "SByte")]
    [TestCase(ushort.MaxValue, "UInt16")]
    [TestCase(uint.MaxValue, "UInt32")]
    [TestCase(ulong.MaxValue, "UInt64")]
    [TestCase(int.MaxValue, "IntPtr")]
    [TestCase(uint.MaxValue, "UIntPtr")]
    [TestCase(3.14159274f, "Single")]
    [TestCase(3.1415926535897931, "Double")]
    [TestCase('A', "Char")]
    [TestCase("ABC", "String")]
    public sealed class Stloc_2
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
