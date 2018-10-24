using System.Runtime.CompilerServices;

namespace IL2C.RuntimeTypes
{
    [TestCase(true, "IsValueType")]
    [TestCase(2, "SizeOf")]
    [TestCase("32767", "ToString", short.MaxValue)]
    [TestCase("-32768", "ToString", short.MinValue)]
    [TestCase(short.MaxValue, "TryParse", "32767")]
    [TestCase(short.MinValue, "TryParse", "-32768")]
    public sealed class System_Int16
    {
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern bool IsValueType();

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern int SizeOf();

        public static string ToString(short value)
        {
            return value.ToString();
        }

        public static short TryParse(string str)
        {
            short.TryParse(str, out var value);
            return value;
        }
    }
}
