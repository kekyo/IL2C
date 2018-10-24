using System.Runtime.CompilerServices;

namespace IL2C.RuntimeTypes
{
    // Some tests are using the IgnoreInvokeResult flag, because float string format is bit different (but no problem.)
    [TestCase(true, "IsValueType")]
    [TestCase(8, "SizeOf")]
    [TestCase("1.79769313486232e+308", "ToString", double.MaxValue, Assert = TestCaseAsserts.IgnoreInvokeResult)]    // Real value is 1.7976931348623157E+308
    [TestCase("-1.79769313486232e+308", "ToString", double.MinValue, Assert = TestCaseAsserts.IgnoreInvokeResult)]   // Real value is -1.7976931348623157E+308
    [TestCase(double.MaxValue, "TryParse", "1.7976931348623157E+308")]
    [TestCase(double.MinValue, "TryParse", "-1.7976931348623157E+308")]
    public sealed class System_Double
    {
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern bool IsValueType();

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern int SizeOf();

        public static string ToString(double value)
        {
            return value.ToString();
        }

        public static double TryParse(string str)
        {
            double.TryParse(str, out var value);
            return value;
        }
    }
}
