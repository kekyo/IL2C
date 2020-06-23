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
    [TestCase((Box_Enum_Int32_Type)byte.MinValue, new[] { "Enum_Int32_From_Byte", "Box_Enum_Int32_From_Byte" }, byte.MinValue, IncludeTypes = new[] { typeof(Box_Enum_Int32_Type) })]
    [TestCase((Box_Enum_Int32_Type)1, new[] { "Enum_Int32_From_Byte", "Box_Enum_Int32_From_Byte" }, 1, IncludeTypes = new[] { typeof(Box_Enum_Int32_Type) })]
    [TestCase((Box_Enum_Int32_Type)byte.MaxValue, new[] { "Enum_Int32_From_Byte", "Box_Enum_Int32_From_Byte" }, byte.MaxValue, IncludeTypes = new[] { typeof(Box_Enum_Int32_Type) })]
    [TestCase((Box_Enum_Int32_Type)short.MinValue, new[] { "Enum_Int32_From_Int16", "Box_Enum_Int32_From_Int16" }, short.MinValue, IncludeTypes = new[] { typeof(Box_Enum_Int32_Type) })]
    [TestCase((Box_Enum_Int32_Type)0, new[] { "Enum_Int32_From_Int16", "Box_Enum_Int32_From_Int16" }, 0, IncludeTypes = new[] { typeof(Box_Enum_Int32_Type) })]
    [TestCase((Box_Enum_Int32_Type)short.MaxValue, new[] { "Enum_Int32_From_Int16", "Box_Enum_Int32_From_Int16" }, short.MaxValue, IncludeTypes = new[] { typeof(Box_Enum_Int32_Type) })]
    [TestCase((Box_Enum_Int32_Type)sbyte.MinValue, new[] { "Enum_Int32_From_SByte", "Box_Enum_Int32_From_SByte" }, sbyte.MinValue, IncludeTypes = new[] { typeof(Box_Enum_Int32_Type) })]
    [TestCase((Box_Enum_Int32_Type)0, new[] { "Enum_Int32_From_SByte", "Box_Enum_Int32_From_SByte" }, 0, IncludeTypes = new[] { typeof(Box_Enum_Int32_Type) })]
    [TestCase((Box_Enum_Int32_Type)sbyte.MaxValue, new[] { "Enum_Int32_From_SByte", "Box_Enum_Int32_From_SByte" }, sbyte.MaxValue, IncludeTypes = new[] { typeof(Box_Enum_Int32_Type) })]
    [TestCase((Box_Enum_Int32_Type)ushort.MinValue, new[] { "Enum_Int32_From_UInt16", "Box_Enum_Int32_From_UInt16" }, ushort.MinValue, IncludeTypes = new[] { typeof(Box_Enum_Int32_Type) })]
    [TestCase((Box_Enum_Int32_Type)1, new[] { "Enum_Int32_From_UInt16", "Box_Enum_Int32_From_UInt16" }, 1, IncludeTypes = new[] { typeof(Box_Enum_Int32_Type) })]
    [TestCase((Box_Enum_Int32_Type)ushort.MaxValue, new[] { "Enum_Int32_From_UInt16", "Box_Enum_Int32_From_UInt16" }, ushort.MaxValue, IncludeTypes = new[] { typeof(Box_Enum_Int32_Type) })]
    public sealed class Box_Enum_Widing
    {
            [MethodImpl(MethodImplOptions.ForwardRef)]
            private static extern object Box_Enum_Int32_From_Byte(byte value);

        public static Box_Enum_Int32_Type Enum_Int32_From_Byte(byte value)
        {
            return (Box_Enum_Int32_Type)Box_Enum_Int32_From_Byte(value);
        }

            [MethodImpl(MethodImplOptions.ForwardRef)]
            private static extern object Box_Enum_Int32_From_Int16(short value);

        public static Box_Enum_Int32_Type Enum_Int32_From_Int16(short value)
        {
            return (Box_Enum_Int32_Type)Box_Enum_Int32_From_Int16(value);
        }

            [MethodImpl(MethodImplOptions.ForwardRef)]
            private static extern object Box_Enum_Int32_From_SByte(sbyte value);

        public static Box_Enum_Int32_Type Enum_Int32_From_SByte(sbyte value)
        {
            return (Box_Enum_Int32_Type)Box_Enum_Int32_From_SByte(value);
        }

            [MethodImpl(MethodImplOptions.ForwardRef)]
            private static extern object Box_Enum_Int32_From_UInt16(ushort value);

        public static Box_Enum_Int32_Type Enum_Int32_From_UInt16(ushort value)
        {
            return (Box_Enum_Int32_Type)Box_Enum_Int32_From_UInt16(value);
        }
    }
}
