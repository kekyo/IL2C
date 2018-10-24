using System.Runtime.CompilerServices;

namespace IL2C.RuntimeTypes
{
    [TestCase(true, "IsValueType")]
    [TestCase(1, "SizeOf")]
    [TestCase("255", "ToString", byte.MaxValue)]
    [TestCase("0", "ToString", byte.MinValue)]
    [TestCase(byte.MaxValue, "TryParse", "255")]
    [TestCase(byte.MinValue, "TryParse", "0")]
    public sealed class System_Byte
    {
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern bool IsValueType();

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern int SizeOf();

        public static string ToString(byte value)
        {
            return value.ToString();
        }

        public static byte TryParse(string str)
        {
            byte.TryParse(str, out var value);
            return value;
        }
    }
}
