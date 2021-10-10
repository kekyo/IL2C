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
    [TestCase((uint)123, "Byte", (byte)123)]
    [TestCase((uint)12345, "Int16", (short)12345)]
    [TestCase(unchecked((uint)-12345), "Int16", (short)-12345)]
    [TestCase((uint)12345, "Int32", 12345)]
    [TestCase(unchecked ((uint)-45678), "Int32", -45678)]
    [TestCase((uint)12345, "Int64", 12345L)]
    [TestCase(unchecked((uint)-45678L), "Int64", -45678L)]
    [TestCase((uint)12345, "IntPtr", 12345)]
    [TestCase(unchecked((uint)-45678), "IntPtr", -45678)]
    [TestCase((uint)123, "SByte", (sbyte)123)]
    [TestCase(unchecked((uint)-123), "SByte", (sbyte)-123)]
    [TestCase((uint)12345, "UInt16", (ushort)12345)]
    [TestCase((uint)12345, "UInt32", (uint)12345)]
    [TestCase((uint)12345, "UInt64", (ulong)12345)]
    [TestCase((uint)12345, "UIntPtr", (uint)12345)]
    [TestCase((uint)12345.67f, "Single", 12345.67f)]
    [TestCase(unchecked((uint)(int)-45678.91f), "Single", -45678.91f)]
    [TestCase((uint)12345.6789, "Double", 12345.6789)]
    [TestCase(unchecked((uint)45678.90123), "Double", 45678.90123)]
    public sealed class Conv_u4
    {
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern uint Byte(byte value);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern uint Int16(short value);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern uint Int32(int value);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern uint Int64(long value);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern uint IntPtr(IntPtr value);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern uint SByte(sbyte value);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern uint UInt16(ushort value);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern uint UInt32(uint value);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern uint UInt64(ulong value);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern uint UIntPtr(UIntPtr value);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern uint Single(float value);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern uint Double(double value);
    }
}
