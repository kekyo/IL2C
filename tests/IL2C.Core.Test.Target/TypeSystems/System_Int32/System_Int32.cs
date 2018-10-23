using System.Runtime.CompilerServices;

namespace IL2C.TypeSystems
{
    [TestCase(true, "IsValueType")]
    [TestCase(4, "SizeOf")]
    [TestCase("12345678", "ToString", 12345678)]
    [TestCase(12345678, "TryParse", "12345678")]
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
            int.TryParse("12345678", out var value);
            return value;
        }
    }
}
