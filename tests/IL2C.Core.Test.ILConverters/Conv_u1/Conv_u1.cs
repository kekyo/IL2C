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
    [TestCase((byte)123, "Byte", (byte)123)]
    [TestCase((byte)123, "Int16", (short)123)]
    [TestCase(unchecked((byte)456), "Int16", (short)456)]
    [TestCase(unchecked((byte)-456), "Int16", (short)-456)]
    [TestCase((byte)123, "Int32", 123)]
    [TestCase(unchecked((byte)456), "Int32", 456)]
    [TestCase(unchecked((byte)-456), "Int32", -456)]
    [TestCase((byte)123L, "Int64", 123L)]
    [TestCase(unchecked((byte)456L), "Int64", 456L)]
    [TestCase(unchecked((byte)-456L), "Int64", -456L)]
    [TestCase((byte)123, "IntPtr", 123)]
    [TestCase(unchecked((byte)456), "IntPtr", 456)]
    [TestCase((byte)123, "SByte", (sbyte)123)]
    [TestCase(unchecked((byte)-123), "SByte", (sbyte)-123)]
    [TestCase((byte)123, "UInt16", (ushort)123)]
    [TestCase((byte)123, "UInt32", (uint)123)]
    [TestCase((byte)123, "UInt64", (ulong)123)]
    [TestCase((byte)123, "UIntPtr", (uint)123)]
    [TestCase((byte)123, "Single", 123.45f)]
    [TestCase(unchecked((byte)456), "Single", 456.78f)]
    [TestCase((byte)123, "Double", 123.45)]
    [TestCase(unchecked((byte)456), "Double", 456.78)]
    public sealed class Conv_u1
    {
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern byte Byte(byte value);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern byte Int16(short value);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern byte Int32(int value);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern byte Int64(long value);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern byte IntPtr(IntPtr value);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern byte SByte(sbyte value);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern byte UInt16(ushort value);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern byte UInt32(uint value);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern byte UInt64(ulong value);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern byte UIntPtr(UIntPtr value);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern byte Single(float value);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern byte Double(double value);
    }
}
