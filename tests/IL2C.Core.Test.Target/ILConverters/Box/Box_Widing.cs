using System;
using System.Runtime.CompilerServices;

namespace IL2C.ILConverters
{
    [TestId("Box")]
    [TestCase(1000123, new[] { "ByteToInt32", "Box_ByteToInt32" }, 123)]
    [TestCase(1012345, new[] { "Int16ToInt32", "Box_Int16ToInt32" }, 12345)]
    [TestCase(1000123, new[] { "SByteToInt32", "Box_SByteToInt32" }, 123)]
    [TestCase(1012345, new[] { "UInt16ToInt32", "Box_UInt16ToInt32" }, 12345)]
    [TestCase(100001234567L, new[] { "UInt32ToInt64", "Box_UInt32ToInt64" }, 1234567U)]  // Hmm, the ECMA-335 not contains this conversion but .NET CLR 4 can do it.
    [TestCase(1, new[] { "BoolToInt32", "Box_BoolToInt32" }, true)]
    [TestCase(0, new[] { "BoolToInt32", "Box_BoolToInt32" }, false)]
    [TestCase(0x41, new[] { "CharToInt32", "Box_CharToInt32" }, 'A')]
    public sealed class Box_Widing
    {
            [MethodImpl(MethodImplOptions.ForwardRef)]
            private static extern object Box_ByteToInt32(byte value);

        public static int ByteToInt32(byte value)
        {
            return (int)Box_ByteToInt32(value) + 1000000;
        }

            [MethodImpl(MethodImplOptions.ForwardRef)]
            private static extern object Box_Int16ToInt32(short value);

        public static int Int16ToInt32(short value)
        {
            return (int)Box_Int16ToInt32(value) + 1000000;
        }

            [MethodImpl(MethodImplOptions.ForwardRef)]
            private static extern object Box_SByteToInt32(sbyte value);

        public static int SByteToInt32(sbyte value)
        {
            return (int)Box_SByteToInt32(value) + 1000000;
        }

            [MethodImpl(MethodImplOptions.ForwardRef)]
            private static extern object Box_UInt16ToInt32(ushort value);

        public static int UInt16ToInt32(ushort value)
        {
            return (int)Box_UInt16ToInt32(value) + 1000000;
        }

            [MethodImpl(MethodImplOptions.ForwardRef)]
            private static extern object Box_UInt32ToInt64(uint value);

        public static long UInt32ToInt64(uint value)
        {
            return (long)Box_UInt32ToInt64(value) + 100000000000L;
        }

            [MethodImpl(MethodImplOptions.ForwardRef)]
            private static extern object Box_BoolToInt32(bool value);

        public static int BoolToInt32(bool value)
        {
            return (int)Box_BoolToInt32(value);
        }

            [MethodImpl(MethodImplOptions.ForwardRef)]
            private static extern object Box_CharToInt32(char value);

        public static int CharToInt32(char value)
        {
            return (int)Box_CharToInt32(value);
        }
    }
}
