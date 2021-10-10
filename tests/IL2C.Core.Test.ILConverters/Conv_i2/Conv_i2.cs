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
    [TestCase((short)123, "SByte", (sbyte)123)]
    [TestCase((short)-123, "SByte", (sbyte)-123)]
    [TestCase((short)12345, "Int16", (short)12345)]
    [TestCase((short)-12345, "Int16", (short)-12345)]
    [TestCase((short)12345, "Int32", 12345)]
    [TestCase(unchecked ((short)45678), "Int32", 45678)]
    [TestCase((short)12345, "Int64", 12345L)]
    [TestCase(unchecked((short)45678), "Int64", 45678L)]
    [TestCase((short)12345, "IntPtr", 12345)]
    [TestCase(unchecked((short)45678), "IntPtr", 45678)]
    [TestCase((short)123, "Byte", (byte)123)]
    [TestCase((short)12345, "UInt16", (ushort)12345)]
    [TestCase(unchecked((short)0x8000), "UInt16", (ushort)0x8000)]
    [TestCase(unchecked((short)456789012), "UInt32", (uint)456789012)]
    [TestCase(unchecked((short)0x80000000), "UInt32", (uint)0x80000000)]
    [TestCase(unchecked((short)456789012), "UInt64", 456789012UL)]
    [TestCase(unchecked((short)0x8000000000000000UL), "UInt64", 0x8000000000000000UL)]
    [TestCase(unchecked((short)456789012), "UIntPtr", (uint)456789012)]
    [TestCase((short)12345, "Single", 12345.67f)]
    [TestCase(unchecked((short)45678), "Single", 45678.91f)]
    [TestCase((short)12345, "Double", 12345.67)]
    [TestCase(unchecked((short)45678), "Double", 45678.91)]
    public sealed class Conv_i2
    {
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern short SByte(sbyte value);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern short Int16(short value);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern short Int32(int value);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern short Int64(long value);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern short IntPtr(IntPtr value);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern short Byte(byte value);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern short UInt16(ushort value);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern short UInt32(uint value);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern short UInt64(ulong value);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern short UIntPtr(UIntPtr value);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern short Single(float value);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern short Double(double value);
    }
}
