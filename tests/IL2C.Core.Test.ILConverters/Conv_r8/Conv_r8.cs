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
    [TestCase(123.0, "SByte", (sbyte)123)]
    [TestCase(-123.0, "SByte", (sbyte)-123)]
    [TestCase(12345.0, "Int16", (short)12345)]
    [TestCase(-12345.0, "Int16", (short)-12345)]
    [TestCase(456789012.0, "Int32", 456789012)]
    [TestCase(-456789012.0, "Int32", -456789012)]
    [TestCase(45678901234.0, "Int64", 45678901234L)]
    [TestCase(-45678901234.0, "Int64", -45678901234L)]
    [TestCase(456789012.0, "IntPtr", 456789012)]
    //[TestCase(unchecked(4567890123.0), "IntPtr", 4567890123L)]  // Will cause overflow on 32bit test environment (IntPtr.Size == 4)
    [TestCase(-456789012.0, "IntPtr", -456789012)]
    [TestCase(123.0, "Byte", (byte)123)]
    [TestCase(12345.0, "UInt16", (ushort)12345)]
    [TestCase(456789012.0, "UInt32", (uint)456789012)]
    [TestCase(45678901234.0, "UInt64", 45678901234UL)]
    [TestCase(456789012.0, "UIntPtr", (uint)456789012)]
    [TestCase((double)456789.012f, "Single", 456789.012f)]
    [TestCase((double)-456789.012f, "Single", -456789.012f)]
    [TestCase(456789.01234, "Double", 456789.01234)]
    [TestCase(-456789.01234, "Double", -456789.01234)]
    public sealed class Conv_r8
    {
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern double SByte(sbyte value);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern double Int16(short value);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern double Int32(int value);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern double Int64(long value);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern double IntPtr(IntPtr value);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern double Byte(byte value);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern double UInt16(ushort value);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern double UInt32(uint value);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern double UInt64(ulong value);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern double UIntPtr(UIntPtr value);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern double Single(float value);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern double Double(double value);
    }
}
