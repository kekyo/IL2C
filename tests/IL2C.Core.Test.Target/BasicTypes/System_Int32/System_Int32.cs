using System.Runtime.CompilerServices;

namespace IL2C.BasicTypes
{
    [TestCase(true, "IsValueType")]
    [TestCase(4, "SizeOf")]
    [TestCase("2147483647", "ToString", int.MaxValue)]
    [TestCase("-2147483648", "ToString", int.MinValue)]
    [TestCase(int.MaxValue, "TryParse", "2147483647")]
    [TestCase(int.MinValue, "TryParse", "-2147483648")]
    public sealed class System_Int32
    {
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern bool IsValueType();

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern int SizeOf();

        public static string ToString(int value)
        {
            return value.ToString();
        }

        public static int TryParse(string str)
        {
            int.TryParse(str, out var value);
            return value;
        }
    }
}
