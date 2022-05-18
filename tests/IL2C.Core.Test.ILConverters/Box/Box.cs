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
    public struct Box_Target_ValueType
    {
        public int Int32Value;
        public string StringValue;

        public override string ToString()
        {
            return Int32Value.ToString() + StringValue;
        }
    }

    public sealed class Box
    {
            [MethodImpl(MethodImplOptions.ForwardRef)]
            private static extern object Box_Byte(byte value);

        [TestCase("124", new[] { "Byte", "Box_Byte" }, 123)]
        public static string Byte(byte value)
        {
            return Box_Byte((byte)(value + 1)).ToString();
        }

            [MethodImpl(MethodImplOptions.ForwardRef)]
            private static extern object Box_Int16(short value);

        [TestCase("12346", new[] { "Int16", "Box_Int16" }, 12345)]
        public static string Int16(short value)
        {
            return Box_Int16((short)(value + 1)).ToString();
        }

            [MethodImpl(MethodImplOptions.ForwardRef)]
                private static extern object Box_Int32(int value);

        [TestCase("1234568", new[] { "Int32", "Box_Int32" }, 1234567)]
        public static string Int32(int value)
        {
            return Box_Int32(value + 1).ToString();
        }

            [MethodImpl(MethodImplOptions.ForwardRef)]
            private static extern object Box_Int64(long value);

        [TestCase("12345678901235", new[] { "Int64", "Box_Int64" }, 12345678901234)]
        public static string Int64(long value)
        {
            return Box_Int64(value + 1).ToString();
        }

            [MethodImpl(MethodImplOptions.ForwardRef)]
            private static extern object Box_SByte(sbyte value);

        [TestCase("124", new[] { "SByte", "Box_SByte" }, 123)]
        public static string SByte(sbyte value)
        {
            return Box_SByte((sbyte)(value + 1)).ToString();
        }

            [MethodImpl(MethodImplOptions.ForwardRef)]
            private static extern object Box_UInt16(ushort value);

        [TestCase("12346", new[] { "UInt16", "Box_UInt16" }, 12345)]
        public static string UInt16(ushort value)
        {
            return Box_UInt16((ushort)(value + 1)).ToString();
        }

            [MethodImpl(MethodImplOptions.ForwardRef)]
            private static extern object Box_UInt32(uint value);

        [TestCase("1234568", new[] { "UInt32", "Box_UInt32" }, 1234567)]
        public static string UInt32(uint value)
        {
            return Box_UInt32(value + 1).ToString();
        }

            [MethodImpl(MethodImplOptions.ForwardRef)]
            private static extern object Box_UInt64(ulong value);

        [TestCase("12345678901235", new[] { "UInt64", "Box_UInt64" }, 12345678901234)]
        public static string UInt64(ulong value)
        {
            return Box_UInt64(value + 1).ToString();
        }

            [MethodImpl(MethodImplOptions.ForwardRef)]
            private static extern object Box_IntPtr(IntPtr value);

        [TestCase("1234567", new[] { "IntPtr", "Box_IntPtr" }, 1234567)]
        public static string IntPtr(IntPtr value)
        {
            return Box_IntPtr(value).ToString();
        }

            [MethodImpl(MethodImplOptions.ForwardRef)]
            private static extern object Box_UIntPtr(UIntPtr value);

        [TestCase("1234567", new[] { "UIntPtr", "Box_UIntPtr" }, 1234567U)]
        public static string UIntPtr(UIntPtr value)
        {
            return Box_UIntPtr(value).ToString();
        }

            [MethodImpl(MethodImplOptions.ForwardRef)]
            private static extern object Box_Single(float value);

        [TestCase("123.456", new[] { "Single", "Box_Single" }, 123.456f)]
        public static string Single(float value)
        {
            return Box_Single(value).ToString();
        }

            [MethodImpl(MethodImplOptions.ForwardRef)]
            private static extern object Box_Double(double value);

        [TestCase("123.45678901234", new[] { "Double", "Box_Double" }, 123.45678901234)]
        public static string Double(double value)
        {
            return Box_Double(value).ToString();
        }

            [MethodImpl(MethodImplOptions.ForwardRef)]
            private static extern object Box_Boolean(bool value);

        [TestCase("True", new[] { "Boolean", "Box_Boolean" }, true)]
        [TestCase("False", new[] { "Boolean", "Box_Boolean" }, false)]
        public static string Boolean(bool value)
        {
            return Box_Boolean(value).ToString();
        }

            [MethodImpl(MethodImplOptions.ForwardRef)]
            private static extern object Box_Char(char value);

        [TestCase("A", new[] { "Char", "Box_Char" }, 'A')]
        public static string Char(char value)
        {
            return Box_Char(value).ToString();
        }

            [MethodImpl(MethodImplOptions.ForwardRef)]
            private static extern object Box_UInt64ToInt64(ulong value);

        [TestCase("12345679901234", new[] { "UInt64ToInt64", "Box_UInt64ToInt64" }, 12345678901234)]
        public static long UInt64ToInt64(ulong value)
        {
            return (long)Box_UInt64ToInt64(value) + 1000000;
        }

        [TestCase("123ABC", new[] { "ValueType", "ToString" }, 123, "ABC", IncludeTypes = new[] { typeof(Box_Target_ValueType) })]
        public static string ValueType(int value1, string value2)
        {
            var v = new Box_Target_ValueType();
            v.Int32Value = value1;
            v.StringValue = value2;
            object ov = v;
            return ov.ToString();
        }
    }
}
