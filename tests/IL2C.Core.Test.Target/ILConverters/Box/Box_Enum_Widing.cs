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
    [TestCase((Box_Enum_Int64_Type)int.MinValue, new[] { "Enum_Int64_From_Int32", "Box_Enum_Int64_From_Int32" }, int.MinValue, IncludeTypes = new[] { typeof(Box_Enum_Int64_Type) })]
    [TestCase(Box_Enum_Int64_Type.Zero, new[] { "Enum_Int64_From_Int32", "Box_Enum_Int64_From_Int32" }, 0, IncludeTypes = new[] { typeof(Box_Enum_Int64_Type) })]
    [TestCase((Box_Enum_Int64_Type)int.MaxValue, new[] { "Enum_Int64_From_Int32", "Box_Enum_Int64_From_Int32" }, int.MaxValue, IncludeTypes = new[] { typeof(Box_Enum_Int64_Type) })]
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

            [MethodImpl(MethodImplOptions.ForwardRef)]
            private static extern object Box_Enum_Int64_From_Int32(int value);

        public static Box_Enum_Int64_Type Enum_Int64_From_Int32(int value)
        {
            return (Box_Enum_Int64_Type)Box_Enum_Int64_From_Int32(value);
        }
    }
}
