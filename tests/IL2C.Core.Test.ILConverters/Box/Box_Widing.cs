////////////////////////////////////////////////////////////////////////////
//
// IL2C - A translator for ECMA-335 CIL/MSIL to C language.
// Copyright (c) Kouji Matsui (@kozy_kekyo, @kekyo@mastodon.cloud)
//
// Licensed under Apache-v2: https://opensource.org/licenses/Apache-2.0
//
////////////////////////////////////////////////////////////////////////////

using System;
using System.Runtime.CompilerServices;

namespace IL2C.ILConverters
{
    [TestId("Box")]
    public sealed class Box_Widing
    {
            [MethodImpl(MethodImplOptions.ForwardRef)]
            private static extern object Box_ByteToInt32(byte value);

        [TestCase(1000123, new[] { "ByteToInt32", "Box_ByteToInt32" }, 123)]
        public static int ByteToInt32(byte value)
        {
            return (int)Box_ByteToInt32(value) + 1000000;
        }

            [MethodImpl(MethodImplOptions.ForwardRef)]
            private static extern object Box_Int16ToInt32(short value);

        [TestCase(1012345, new[] { "Int16ToInt32", "Box_Int16ToInt32" }, 12345)]
        public static int Int16ToInt32(short value)
        {
            return (int)Box_Int16ToInt32(value) + 1000000;
        }

            [MethodImpl(MethodImplOptions.ForwardRef)]
            private static extern object Box_SByteToInt32(sbyte value);

        [TestCase(1000123, new[] { "SByteToInt32", "Box_SByteToInt32" }, 123)]
        public static int SByteToInt32(sbyte value)
        {
            return (int)Box_SByteToInt32(value) + 1000000;
        }

            [MethodImpl(MethodImplOptions.ForwardRef)]
            private static extern object Box_UInt16ToInt32(ushort value);

        [TestCase(1012345, new[] { "UInt16ToInt32", "Box_UInt16ToInt32" }, 12345)]
        public static int UInt16ToInt32(ushort value)
        {
            return (int)Box_UInt16ToInt32(value) + 1000000;
        }

            [MethodImpl(MethodImplOptions.ForwardRef)]
            private static extern object Box_BoolToInt32(bool value);

        [TestCase(1, new[] { "BoolToInt32", "Box_BoolToInt32" }, true)]
        [TestCase(0, new[] { "BoolToInt32", "Box_BoolToInt32" }, false)]
        public static int BoolToInt32(bool value)
        {
            return (int)Box_BoolToInt32(value);
        }

            [MethodImpl(MethodImplOptions.ForwardRef)]
            private static extern object Box_CharToInt32(char value);

        [TestCase(0x41, new[] { "CharToInt32", "Box_CharToInt32" }, 'A')]
        public static int CharToInt32(char value)
        {
            return (int)Box_CharToInt32(value);
        }
    }
}
