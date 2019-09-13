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
    public enum Box_Enum_Byte_Type : byte
    {
        Min = byte.MinValue,
        One = 1,
        Max = byte.MaxValue
    }

    public enum Box_Enum_Int16_Type : short
    {
        Min = short.MinValue,
        Zero = 0,
        Max = short.MaxValue
    }

    public enum Box_Enum_Int32_Type : int
    {
        Min = int.MinValue,
        Zero = 0,
        Max = int.MaxValue
    }

    public enum Box_Enum_Int64_Type : long
    {
        Min = long.MinValue,
        Zero = 0,
        Max = long.MaxValue
    }

    public enum Box_Enum_SByte_Type : sbyte
    {
        Min = sbyte.MinValue,
        Zero = 0,
        Max = sbyte.MaxValue
    }

    public enum Box_Enum_UInt16_Type : ushort
    {
        Min = ushort.MinValue,
        One = 1,
        Max = ushort.MaxValue
    }

    public enum Box_Enum_UInt32_Type : uint
    {
        Min = uint.MinValue,
        One = 1,
        Max = uint.MaxValue
    }

    public enum Box_Enum_UInt64_Type : ulong
    {
        Min = ulong.MinValue,
        One = 1,
        Max = ulong.MaxValue
    }

    [TestId("Box")]
    [TestCase(Box_Enum_Byte_Type.Min, new[] { "Enum_Byte", "Box_Enum_Byte" }, byte.MinValue, IncludeTypes = new[] { typeof(Box_Enum_Byte_Type) })]
    [TestCase(Box_Enum_Byte_Type.One, new[] { "Enum_Byte", "Box_Enum_Byte" }, 1, IncludeTypes = new[] { typeof(Box_Enum_Byte_Type) })]
    [TestCase(Box_Enum_Byte_Type.Max, new[] { "Enum_Byte", "Box_Enum_Byte" }, byte.MaxValue, IncludeTypes = new[] { typeof(Box_Enum_Byte_Type) })]
    [TestCase(Box_Enum_Int16_Type.Min, new[] { "Enum_Int16", "Box_Enum_Int16" }, short.MinValue, IncludeTypes = new[] { typeof(Box_Enum_Int16_Type) })]
    [TestCase(Box_Enum_Int16_Type.Zero, new[] { "Enum_Int16", "Box_Enum_Int16" }, 0, IncludeTypes = new[] { typeof(Box_Enum_Int16_Type) })]
    [TestCase(Box_Enum_Int16_Type.Max, new[] { "Enum_Int16", "Box_Enum_Int16" }, short.MaxValue, IncludeTypes = new[] { typeof(Box_Enum_Int16_Type) })]
    [TestCase(Box_Enum_Int32_Type.Min, new[] { "Enum_Int32", "Box_Enum_Int32" }, int.MinValue, IncludeTypes = new[] { typeof(Box_Enum_Int32_Type) })]
    [TestCase(Box_Enum_Int32_Type.Zero, new[] { "Enum_Int32", "Box_Enum_Int32" }, 0, IncludeTypes = new[] { typeof(Box_Enum_Int32_Type) })]
    [TestCase(Box_Enum_Int32_Type.Max, new[] { "Enum_Int32", "Box_Enum_Int32" }, int.MaxValue, IncludeTypes = new[] { typeof(Box_Enum_Int32_Type) })]
    [TestCase(Box_Enum_Int64_Type.Min, new[] { "Enum_Int64", "Box_Enum_Int64" }, long.MinValue, IncludeTypes = new[] { typeof(Box_Enum_Int64_Type) })]
    [TestCase(Box_Enum_Int64_Type.Zero, new[] { "Enum_Int64", "Box_Enum_Int64" }, 0L, IncludeTypes = new[] { typeof(Box_Enum_Int64_Type) })]
    [TestCase(Box_Enum_Int64_Type.Max, new[] { "Enum_Int64", "Box_Enum_Int64" }, long.MaxValue, IncludeTypes = new[] { typeof(Box_Enum_Int64_Type) })]
    [TestCase(Box_Enum_SByte_Type.Min, new[] { "Enum_SByte", "Box_Enum_SByte" }, sbyte.MinValue, IncludeTypes = new[] { typeof(Box_Enum_SByte_Type) })]
    [TestCase(Box_Enum_SByte_Type.Zero, new[] { "Enum_SByte", "Box_Enum_SByte" }, 0, IncludeTypes = new[] { typeof(Box_Enum_SByte_Type) })]
    [TestCase(Box_Enum_SByte_Type.Max, new[] { "Enum_SByte", "Box_Enum_SByte" }, sbyte.MaxValue, IncludeTypes = new[] { typeof(Box_Enum_SByte_Type) })]
    [TestCase(Box_Enum_UInt16_Type.Min, new[] { "Enum_UInt16", "Box_Enum_UInt16" }, ushort.MinValue, IncludeTypes = new[] { typeof(Box_Enum_UInt16_Type) })]
    [TestCase(Box_Enum_UInt16_Type.One, new[] { "Enum_UInt16", "Box_Enum_UInt16" }, 1, IncludeTypes = new[] { typeof(Box_Enum_UInt16_Type) })]
    [TestCase(Box_Enum_UInt16_Type.Max, new[] { "Enum_UInt16", "Box_Enum_UInt16" }, ushort.MaxValue, IncludeTypes = new[] { typeof(Box_Enum_UInt16_Type) })]
    [TestCase(Box_Enum_UInt32_Type.Min, new[] { "Enum_UInt32", "Box_Enum_UInt32" }, uint.MinValue, IncludeTypes = new[] { typeof(Box_Enum_UInt32_Type) })]
    [TestCase(Box_Enum_UInt32_Type.One, new[] { "Enum_UInt32", "Box_Enum_UInt32" }, 1, IncludeTypes = new[] { typeof(Box_Enum_UInt32_Type) })]
    [TestCase(Box_Enum_UInt32_Type.Max, new[] { "Enum_UInt32", "Box_Enum_UInt32" }, uint.MaxValue, IncludeTypes = new[] { typeof(Box_Enum_UInt32_Type) })]
    [TestCase(Box_Enum_UInt64_Type.Min, new[] { "Enum_UInt64", "Box_Enum_UInt64" }, ulong.MinValue, IncludeTypes = new[] { typeof(Box_Enum_UInt64_Type) })]
    [TestCase(Box_Enum_UInt64_Type.One, new[] { "Enum_UInt64", "Box_Enum_UInt64" }, 1UL, IncludeTypes = new[] { typeof(Box_Enum_UInt64_Type) })]
    [TestCase(Box_Enum_UInt64_Type.Max, new[] { "Enum_UInt64", "Box_Enum_UInt64" }, ulong.MaxValue, IncludeTypes = new[] { typeof(Box_Enum_UInt64_Type) })]
    public sealed class Box_Enum
    {
            [MethodImpl(MethodImplOptions.ForwardRef)]
            private static extern object Box_Enum_Byte(byte value);

        public static Box_Enum_Byte_Type Enum_Byte(byte value)
        {
            return (Box_Enum_Byte_Type)Box_Enum_Byte(value);
        }

            [MethodImpl(MethodImplOptions.ForwardRef)]
            private static extern object Box_Enum_Int16(short value);

        public static Box_Enum_Int16_Type Enum_Int16(short value)
        {
            return (Box_Enum_Int16_Type)Box_Enum_Int16(value);
        }

            [MethodImpl(MethodImplOptions.ForwardRef)]
            private static extern object Box_Enum_Int32(int value);

        public static Box_Enum_Int32_Type Enum_Int32(int value)
        {
            return (Box_Enum_Int32_Type)Box_Enum_Int32(value);
        }

            [MethodImpl(MethodImplOptions.ForwardRef)]
            private static extern object Box_Enum_Int64(long value);

        public static Box_Enum_Int64_Type Enum_Int64(long value)
        {
            return (Box_Enum_Int64_Type)Box_Enum_Int64(value);
        }

            [MethodImpl(MethodImplOptions.ForwardRef)]
            private static extern object Box_Enum_SByte(sbyte value);

        public static Box_Enum_SByte_Type Enum_SByte(sbyte value)
        {
            return (Box_Enum_SByte_Type)Box_Enum_SByte(value);
        }

            [MethodImpl(MethodImplOptions.ForwardRef)]
            private static extern object Box_Enum_UInt16(ushort value);

        public static Box_Enum_UInt16_Type Enum_UInt16(ushort value)
        {
            return (Box_Enum_UInt16_Type)Box_Enum_UInt16(value);
        }

            [MethodImpl(MethodImplOptions.ForwardRef)]
            private static extern object Box_Enum_UInt32(uint value);

        public static Box_Enum_UInt32_Type Enum_UInt32(uint value)
        {
            return (Box_Enum_UInt32_Type)Box_Enum_UInt32(value);
        }

            [MethodImpl(MethodImplOptions.ForwardRef)]
            private static extern object Box_Enum_UInt64(ulong value);

        public static Box_Enum_UInt64_Type Enum_UInt64(ulong value)
        {
            return (Box_Enum_UInt64_Type)Box_Enum_UInt64(value);
        }
    }
}
