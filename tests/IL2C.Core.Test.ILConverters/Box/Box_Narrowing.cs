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
    [TestId("Box")]
    [TestCase(124, new[] { "Int32ToByte", "Box_Int32ToByte" }, 123)]
    [TestCase(12346, new[] { "Int32ToInt16", "Box_Int32ToInt16" }, 12345)]
    [TestCase(true, new[] { "Int32ToBool", "Box_Int32ToBool" }, 1)]
    [TestCase(false, new[] { "Int32ToBool", "Box_Int32ToBool" }, 0)]
    [TestCase('A', new[] { "Int32ToChar", "Box_Int32ToChar" }, 0x41)]
    [TestCase(12345678U, new[] { "Int64ToUInt32", "Box_Int64ToUInt32" }, 12345678L)]
    public sealed class Box_Narrowing
    {
            [MethodImpl(MethodImplOptions.ForwardRef)]
            private static extern object Box_Int32ToByte(int value);

        public static byte Int32ToByte(int value)
        {
            return (byte)((byte)Box_Int32ToByte(value) + 1);
        }

            [MethodImpl(MethodImplOptions.ForwardRef)]
            private static extern object Box_Int32ToInt16(int value);

        public static short Int32ToInt16(int value)
        {
            return (short)((short)Box_Int32ToInt16(value) + 1);
        }

            [MethodImpl(MethodImplOptions.ForwardRef)]
            private static extern object Box_Int32ToBool(int value);

        public static bool Int32ToBool(int value)
        {
            return (bool)Box_Int32ToBool(value);
        }

            [MethodImpl(MethodImplOptions.ForwardRef)]
            private static extern object Box_Int32ToChar(int value);

        public static char Int32ToChar(int value)
        {
            return (char)Box_Int32ToChar(value);
        }

            [MethodImpl(MethodImplOptions.ForwardRef)]
            private static extern object Box_Int64ToUInt32(long value);

        public static uint Int64ToUInt32(long value)
        {
            return (uint)Box_Int64ToUInt32(value);
        }
    }
}
