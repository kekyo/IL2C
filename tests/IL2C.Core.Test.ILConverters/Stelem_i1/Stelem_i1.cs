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
    [TestCase((byte)123, new[] { "Byte", "ByteInner" }, 0, (byte)123)]
    [TestCase((byte)125, new[] { "Byte", "ByteInner" }, 1, (byte)125)]
    [TestCase((byte)127, new[] { "Byte", "ByteInner" }, 2, (byte)127)]
    [TestCase((byte)123, new[] { "ByteIntPtrIndex", "ByteIntPtrIndexInner" }, 0, (byte)123)]
    [TestCase((byte)125, new[] { "ByteIntPtrIndex", "ByteIntPtrIndexInner" }, 1, (byte)125)]
    [TestCase((byte)127, new[] { "ByteIntPtrIndex", "ByteIntPtrIndexInner" }, 2, (byte)127)]
    public sealed class Stelem_i1
    {
        public static byte Byte(int index, byte value)
        {
            var values = new byte[] { 1, 2, 3 };
            ByteInner(values, index, value);
            return values[index];
        }

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern void ByteInner(byte[] values, int index, byte value);

        public static byte ByteIntPtrIndex(int index, byte value)
        {
            var values = new byte[] { 1, 2, 3 };
            ByteIntPtrIndexInner(values, index, value);
            return values[index];
        }

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern void ByteIntPtrIndexInner(byte[] values, int index, byte value);
    }
}
