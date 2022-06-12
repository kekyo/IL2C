////////////////////////////////////////////////////////////////////////////
//
// IL2C - A translator for ECMA-335 CIL/MSIL to C language.
// Copyright (c) Kouji Matsui (@kozy_kekyo, @kekyo@mastodon.cloud)
//
// Licensed under Apache-v2: https://opensource.org/licenses/Apache-2.0
//
////////////////////////////////////////////////////////////////////////////

using System.Runtime.CompilerServices;

namespace IL2C.BasicTypes
{
    public sealed class System_Byte
    {
        [TestCase(true, "IsValueType")]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern bool IsValueType();

        [TestCase(1, "SizeOf")]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern int SizeOf();

        [TestCase("255", "ToString", byte.MaxValue)]
        [TestCase("0", "ToString", byte.MinValue)]
        public static string ToString(byte value)
        {
            return value.ToString();
        }

        [TestCase(byte.MaxValue, "TryParse", "255")]
        [TestCase(byte.MinValue, "TryParse", "0")]
        public static byte TryParse(string str)
        {
            byte.TryParse(str, out var value);
            return value;
        }
    }
}
