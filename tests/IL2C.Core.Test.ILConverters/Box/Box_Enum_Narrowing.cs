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
