using System.Runtime.CompilerServices;

namespace IL2C.RuntimeTypes
{
    [TestCase(false, "IsValueType")]
    [TestCase(0, "SizeOf")]
    [TestCase("ABC", "ToString", "ABC")]
    public sealed class System_String
    {
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern bool IsValueType();

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern int SizeOf();

        public static string ToString(string value)
        {
            return value.ToString();
        }
    }
}
