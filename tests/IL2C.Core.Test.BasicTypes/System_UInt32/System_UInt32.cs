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
    [TestCase(true, "IsValueType")]
    [TestCase(4, "SizeOf")]
    [TestCase("4294967295", "ToString", uint.MaxValue)]
    [TestCase("0", "ToString", uint.MinValue)]
    [TestCase(uint.MaxValue, "TryParse", "4294967295")]
    [TestCase(uint.MinValue, "TryParse", "0")]
    public sealed class System_UInt32
    {
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern bool IsValueType();

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern int SizeOf();

        public static string ToString(uint value)
        {
            return value.ToString();
        }

        public static uint TryParse(string str)
        {
            uint.TryParse(str, out var value);
            return value;
        }
    }
}
