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
    [TestCase(8, "SizeOf")]
    [TestCase("18446744073709551615", "ToString", ulong.MaxValue)]
    [TestCase("0", "ToString", ulong.MinValue)]
    [TestCase(ulong.MaxValue, "TryParse", "18446744073709551615")]
    [TestCase(ulong.MinValue, "TryParse", "0")]
    public sealed class System_UInt64
    {
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern bool IsValueType();

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern int SizeOf();

        public static string ToString(ulong value)
        {
            return value.ToString();
        }

        public static ulong TryParse(string str)
        {
            ulong.TryParse(str, out var value);
            return value;
        }
    }
}
