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
    // Some tests are using the IgnoreInvokeResult flag, because float string format is bit different (but no problem.)
    public sealed class System_Single
    {
        [TestCase(true, "IsValueType")]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern bool IsValueType();

        [TestCase(4, "SizeOf")]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern int SizeOf();

#if NET6_0_OR_GREATER
        [TestCase("3.4028235E+38", "ToString", float.MaxValue)]
        [TestCase("-3.4028235E+38", "ToString", float.MinValue)]
#else
        [TestCase("3.402823E+38", "ToString", float.MaxValue)]
        [TestCase("-3.402823E+38", "ToString", float.MinValue)]
#endif
        public static string ToString(float value)
        {
            return value.ToString();
        }

        [TestCase(float.MaxValue, "TryParse", "3.40282347E+38")]
        [TestCase(float.MinValue, "TryParse", "-3.40282347E+38")]
        public static float TryParse(string str)
        {
            float.TryParse(str, out var value);
            return value;
        }
    }
}
