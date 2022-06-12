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
    public sealed class System_Int32
    {
        [TestCase(true, "IsValueType")]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern bool IsValueType();

        [TestCase(4, "SizeOf")]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern int SizeOf();

        [TestCase("2147483647", "ToString", int.MaxValue)]
        [TestCase("-2147483647", "ToString", int.MinValue + 1)]
        [TestCase("-2147483648", "ToString", int.MinValue)]        // It's special case for internal
        public static string ToString(int value)
        {
            return value.ToString();
        }

        [TestCase(int.MaxValue, "TryParse", "2147483647")]
        [TestCase(int.MinValue, "TryParse", "-2147483648")]
        public static int TryParse(string str)
        {
            int.TryParse(str, out var value);
            return value;
        }
    }
}
