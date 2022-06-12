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
    public sealed class System_UInt64
    {
        [TestCase(true, "IsValueType")]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern bool IsValueType();

        [TestCase(8, "SizeOf")]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern int SizeOf();

        [TestCase("18446744073709551615", "ToString", ulong.MaxValue)]
        [TestCase("0", "ToString", ulong.MinValue)]
        public static string ToString(ulong value)
        {
            return value.ToString();
        }

        [TestCase(ulong.MaxValue, "TryParse", "18446744073709551615")]
        [TestCase(ulong.MinValue, "TryParse", "0")]
        public static ulong TryParse(string str)
        {
            ulong.TryParse(str, out var value);
            return value;
        }
    }
}
