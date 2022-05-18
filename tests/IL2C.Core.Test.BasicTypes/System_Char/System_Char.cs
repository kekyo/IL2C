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
    public sealed class System_Char
    {
        [TestCase(true, "IsValueType")]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern bool IsValueType();

        [TestCase(2, "SizeOf")]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern int SizeOf();

        ///////////////////////////////
        // NUnit (or visual studio test engine) problem:
        //   Will apply unique test case names with overload arguments.
        //   (ex: ToString("\u0000") and ToString("\uffff") if apply sets for test methods)
        //   But cause failed conflicting both these test case names (maybe contains invalid char).

        [TestCase("\u0000", "ToStringMin")]
        public static string ToStringMin()
        {
            char value = char.MinValue;
            return value.ToString();
        }

        [TestCase("\uffff", "ToStringMax")]
        public static string ToStringMax()
        {
            char value = char.MaxValue;
            return value.ToString();
        }

        [TestCase(char.MinValue, "TryParseMin")]
        public static char TryParseMin()
        {
            char.TryParse("\u0000", out var value);
            return value;
        }

        [TestCase(char.MaxValue, "TryParseMax")]
        public static char TryParseMax()
        {
            char.TryParse("\uffff", out var value);
            return value;
        }
    }
}
