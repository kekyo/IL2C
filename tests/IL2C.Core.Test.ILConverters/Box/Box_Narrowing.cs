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
    public sealed class Box_Narrowing
    {
            [MethodImpl(MethodImplOptions.ForwardRef)]
            private static extern object Box_Int32ToByte(int value);

        [TestCase(124, new[] { "Int32ToByte", "Box_Int32ToByte" }, 123)]
        public static byte Int32ToByte(int value)
        {
            return (byte)((byte)Box_Int32ToByte(value) + 1);
        }

            [MethodImpl(MethodImplOptions.ForwardRef)]
            private static extern object Box_Int32ToInt16(int value);

        [TestCase(12346, new[] { "Int32ToInt16", "Box_Int32ToInt16" }, 12345)]
        public static short Int32ToInt16(int value)
        {
            return (short)((short)Box_Int32ToInt16(value) + 1);
        }

            [MethodImpl(MethodImplOptions.ForwardRef)]
            private static extern object Box_Int32ToBool(int value);

        [TestCase(true, new[] { "Int32ToBool", "Box_Int32ToBool" }, 1)]
        [TestCase(false, new[] { "Int32ToBool", "Box_Int32ToBool" }, 0)]
        public static bool Int32ToBool(int value)
        {
            return (bool)Box_Int32ToBool(value);
        }

            [MethodImpl(MethodImplOptions.ForwardRef)]
            private static extern object Box_Int32ToChar(int value);

        [TestCase('A', new[] { "Int32ToChar", "Box_Int32ToChar" }, 0x41)]
        public static char Int32ToChar(int value)
        {
            return (char)Box_Int32ToChar(value);
        }

            [MethodImpl(MethodImplOptions.ForwardRef)]
            private static extern object Box_Int64ToUInt32(long value);

        // TODO: Unknown failure on mono linux x64
        //   System.InvalidProgramException : Invalid IL code in IL2C.ILConverters.Box_Narrowing:Box_Int64ToUInt32 (long): IL_0001: box       0x01000028
        [TestCase(12345678U, new[] { "Int64ToUInt32", "Box_Int64ToUInt32" }, 12345678L,
            RunOnPlatforms = RunOnPlatforms.DotNet)]
        public static uint Int64ToUInt32(long value)
        {
            return (uint)Box_Int64ToUInt32(value);
        }
    }
}
