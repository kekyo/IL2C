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
    public sealed class System_Int64
    {
        [TestCase(true, "IsValueType")]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern bool IsValueType();

        [TestCase(8, "SizeOf")]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern int SizeOf();

        [TestCase("9223372036854775807", "ToString", long.MaxValue)]
        [TestCase("-9223372036854775807", "ToString", long.MinValue + 1)]
        [TestCase("-9223372036854775808", "ToString", long.MinValue)]        // It's special case for internal
        public static string ToString(long value)
        {
            return value.ToString();
        }

        [TestCase(long.MaxValue, "TryParse", "9223372036854775807")]
        [TestCase(long.MinValue, "TryParse", "-9223372036854775808")]
        public static long TryParse(string str)
        {
            long.TryParse(str, out var value);
            return value;
        }
    }
}
