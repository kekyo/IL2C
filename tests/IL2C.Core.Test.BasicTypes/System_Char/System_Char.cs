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
    [TestCase(2, "SizeOf")]
    [TestCase("\u0000", "ToStringMin")]
    [TestCase("\uffff", "ToStringMax")]
    [TestCase(char.MinValue, "TryParseMin")]
    [TestCase(char.MaxValue, "TryParseMax")]
    public sealed class System_Char
    {
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern bool IsValueType();

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern int SizeOf();

        ///////////////////////////////
        // NUnit (or visual studio test engine) problem:
        //   Will apply unique test case names with overload arguments.
        //   (ex: ToString("\u0000") and ToString("\uffff") if apply sets for test methods)
        //   But cause failed conflicting both these test case names (maybe contains invalid char).

        public static string ToStringMin()
        {
            char value = char.MinValue;
            return value.ToString();
        }

        public static string ToStringMax()
        {
            char value = char.MaxValue;
            return value.ToString();
        }

        public static char TryParseMin()
        {
            char.TryParse("\u0000", out var value);
            return value;
        }

        public static char TryParseMax()
        {
            char.TryParse("\uffff", out var value);
            return value;
        }
    }
}
