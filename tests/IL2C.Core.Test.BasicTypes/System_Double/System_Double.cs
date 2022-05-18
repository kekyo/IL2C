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
    public sealed class System_Double
    {
        [TestCase(true, "IsValueType")]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern bool IsValueType();

        [TestCase(8, "SizeOf")]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern int SizeOf();

        [TestCase("1.797693134862316e+308", "ToString", double.MaxValue, Assert = TestCaseAsserts.IgnoreValidateInvokeResult)]    // Real value is 1.7976931348623157E+308
        [TestCase("-1.797693134862316e+308", "ToString", double.MinValue, Assert = TestCaseAsserts.IgnoreValidateInvokeResult)]   // Real value is -1.7976931348623157E+308
        public static string ToString(double value)
        {
            return value.ToString();
        }

        [TestCase(double.MaxValue, "TryParse", "1.7976931348623157E+308")]
        [TestCase(double.MinValue, "TryParse", "-1.7976931348623157E+308")]
        public static double TryParse(string str)
        {
            double.TryParse(str, out var value);
            return value;
        }
    }
}
