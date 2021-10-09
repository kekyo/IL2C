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
    [TestCase(123, "SByte", (sbyte)123)]
    [TestCase(-123, "SByte", (sbyte)-123)]
    [TestCase(12345, "Int16", (short)12345)]
    [TestCase(-12345, "Int16", (short)-12345)]
    [TestCase(456789012, "Int32", 456789012)]
    [TestCase(-456789012, "Int32", -456789012)]
    [TestCase(456789012, "Int64", 456789012L)]
    [TestCase(unchecked((int)4567890123L), "Int64", 4567890123L)]
    [TestCase(456789012, "IntPtr", 456789012)]
    //[TestCase(unchecked((int)4567890123L), "IntPtr", 4567890123L)]  // Will cause overflow on 32bit test environment (IntPtr.Size == 4)
    [TestCase(456789, "Single", 456789.012f)]
    [TestCase(unchecked((int)456789.012f), "Single", 456789.012f)]
    [TestCase(456789, "Double", 456789.012)]
    [TestCase(unchecked((int)456789.012), "Double", 456789.012)]
    public sealed class Conv_i4
    {
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern int SByte(sbyte value);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern int Int16(short value);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern int Int32(int value);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern int Int64(long value);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern int IntPtr(IntPtr value);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern int Single(float value);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern int Double(double value);
    }
}
