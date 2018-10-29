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
