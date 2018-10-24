using System.Runtime.CompilerServices;

namespace IL2C.RuntimeTypes
{
    [TestCase(true, "IsValueType")]
    [TestCase(8, "SizeOf")]
    [TestCase("9223372036854775807", "ToString", long.MaxValue)]
    [TestCase("-9223372036854775808", "ToString", long.MinValue)]
    [TestCase(long.MaxValue, "TryParse", "9223372036854775807")]
    [TestCase(long.MinValue, "TryParse", "-9223372036854775808")]
    public sealed class System_Int64
    {
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern bool IsValueType();

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern int SizeOf();

        public static string ToString(long value)
        {
            return value.ToString();
        }

        public static long TryParse(string str)
        {
            long.TryParse(str, out var value);
            return value;
        }
    }
}
