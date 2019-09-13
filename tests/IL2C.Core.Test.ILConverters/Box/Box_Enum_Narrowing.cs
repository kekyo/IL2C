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
    [TestCase((Box_Enum_Byte_Type)byte.MinValue, new[] { "Enum_Byte_From_Int32", "Box_Enum_Byte_From_Int32" }, byte.MinValue, IncludeTypes = new[] { typeof(Box_Enum_Byte_Type) })]
    [TestCase((Box_Enum_Byte_Type)1, new[] { "Enum_Byte_From_Int32", "Box_Enum_Byte_From_Int32" }, 1, IncludeTypes = new[] { typeof(Box_Enum_Byte_Type) })]
    [TestCase((Box_Enum_Byte_Type)byte.MaxValue, new[] { "Enum_Byte_From_Int32", "Box_Enum_Byte_From_Int32" }, byte.MaxValue, IncludeTypes = new[] { typeof(Box_Enum_Byte_Type) })]
    [TestCase((Box_Enum_Int16_Type)short.MinValue, new[] { "Enum_Int16_From_Int32", "Box_Enum_Int16_From_Int32" }, short.MinValue, IncludeTypes = new[] { typeof(Box_Enum_Int16_Type) })]
    [TestCase((Box_Enum_Int16_Type)0, new[] { "Enum_Int16_From_Int32", "Box_Enum_Int16_From_Int32" }, 0, IncludeTypes = new[] { typeof(Box_Enum_Int16_Type) })]
    [TestCase((Box_Enum_Int16_Type)short.MaxValue, new[] { "Enum_Int16_From_Int32", "Box_Enum_Int16_From_Int32" }, short.MaxValue, IncludeTypes = new[] { typeof(Box_Enum_Int16_Type) })]
    [TestCase((Box_Enum_SByte_Type)sbyte.MinValue, new[] { "Enum_SByte_From_Int32", "Box_Enum_SByte_From_Int32" }, sbyte.MinValue, IncludeTypes = new[] { typeof(Box_Enum_SByte_Type) })]
    [TestCase((Box_Enum_SByte_Type)0, new[] { "Enum_SByte_From_Int32", "Box_Enum_SByte_From_Int32" }, 0, IncludeTypes = new[] { typeof(Box_Enum_SByte_Type) })]
    [TestCase((Box_Enum_SByte_Type)sbyte.MaxValue, new[] { "Enum_SByte_From_Int32", "Box_Enum_SByte_From_Int32" }, sbyte.MaxValue, IncludeTypes = new[] { typeof(Box_Enum_SByte_Type) })]
    [TestCase((Box_Enum_UInt16_Type)ushort.MinValue, new[] { "Enum_UInt16_From_Int32", "Box_Enum_UInt16_From_Int32" }, ushort.MinValue, IncludeTypes = new[] { typeof(Box_Enum_UInt16_Type) })]
    [TestCase((Box_Enum_UInt16_Type)1, new[] { "Enum_UInt16_From_Int32", "Box_Enum_UInt16_From_Int32" }, 1, IncludeTypes = new[] { typeof(Box_Enum_UInt16_Type) })]
    [TestCase((Box_Enum_UInt16_Type)ushort.MaxValue, new[] { "Enum_UInt16_From_Int32", "Box_Enum_UInt16_From_Int32" }, ushort.MaxValue, IncludeTypes = new[] { typeof(Box_Enum_UInt16_Type) })]
    public sealed class Box_Enum_Narrowing
    {
            [MethodImpl(MethodImplOptions.ForwardRef)]
            private static extern object Box_Enum_Byte_From_Int32(int value);

        public static Box_Enum_Byte_Type Enum_Byte_From_Int32(int value)
        {
            return (Box_Enum_Byte_Type)Box_Enum_Byte_From_Int32(value);
        }

            [MethodImpl(MethodImplOptions.ForwardRef)]
            private static extern object Box_Enum_Int16_From_Int32(int value);

        public static Box_Enum_Int16_Type Enum_Int16_From_Int32(int value)
        {
            return (Box_Enum_Int16_Type)Box_Enum_Int16_From_Int32(value);
        }

            [MethodImpl(MethodImplOptions.ForwardRef)]
            private static extern object Box_Enum_SByte_From_Int32(int value);

        public static Box_Enum_SByte_Type Enum_SByte_From_Int32(int value)
        {
            return (Box_Enum_SByte_Type)Box_Enum_SByte_From_Int32(value);
        }

            [MethodImpl(MethodImplOptions.ForwardRef)]
            private static extern object Box_Enum_UInt16_From_Int32(int value);

        public static Box_Enum_UInt16_Type Enum_UInt16_From_Int32(int value)
        {
            return (Box_Enum_UInt16_Type)Box_Enum_UInt16_From_Int32(value);
        }
    }
}
