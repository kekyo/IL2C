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
    public sealed class System_Int16
    {
        [TestCase(true, "IsValueType")]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern bool IsValueType();

        [TestCase(2, "SizeOf")]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern int SizeOf();

        [TestCase("32767", "ToString", short.MaxValue)]
        [TestCase("-32768", "ToString", short.MinValue)]
        public static string ToString(short value)
        {
            return value.ToString();
        }

        [TestCase(short.MaxValue, "TryParse", "32767")]
        [TestCase(short.MinValue, "TryParse", "-32768")]
        public static short TryParse(string str)
        {
            short.TryParse(str, out var value);
            return value;
        }
    }
}
