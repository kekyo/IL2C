using System.Runtime.CompilerServices;

namespace IL2C.RuntimeTypes
{
    [TestCase(true, "IsValueType")]
    [TestCase(2, "SizeOf")]
    [TestCase("\uffff", "ToString", char.MaxValue)]
    [TestCase("\u0000", "ToString", char.MinValue)]
    [TestCase(char.MaxValue, "TryParse", "\uffff")]
    [TestCase(char.MinValue, "TryParse", "\u0000")]
    public sealed class System_Char
    {
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern bool IsValueType();

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern int SizeOf();

        public static string ToString(char value)
        {
            return value.ToString();
        }

        public static char TryParse(string str)
        {
            char.TryParse(str, out var value);
            return value;
        }
    }
}
