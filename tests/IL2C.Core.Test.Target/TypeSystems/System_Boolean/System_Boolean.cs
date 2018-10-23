using System.Runtime.CompilerServices;

namespace IL2C.TypeSystems
{
    [TestCase(true, "IsValueType")]
    [TestCase(1, "SizeOf")]
    [TestCase("True", "ToString", true)]
    [TestCase("False", "ToString", false)]
    [TestCase(true, "TryParse", "True")]
    [TestCase(false, "TryParse", "False")]
    public sealed class System_Boolean
    {
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern bool IsValueType();

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern int SizeOf();

        public static string ToString(bool value)
        {
            return value.ToString();
        }

        public static bool TryParse(string str)
        {
            bool.TryParse(str, out var value);
            return value;
        }
    }
}
