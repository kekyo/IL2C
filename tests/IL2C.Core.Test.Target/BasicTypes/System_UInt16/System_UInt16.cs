using System.Runtime.CompilerServices;

namespace IL2C.BasicTypes
{
    [TestCase(true, "IsValueType")]
    [TestCase(2, "SizeOf")]
    [TestCase("65535", "ToString", ushort.MaxValue)]
    [TestCase("0", "ToString", ushort.MinValue)]
    [TestCase(ushort.MaxValue, "TryParse", "65535")]
    [TestCase(ushort.MinValue, "TryParse", "0")]
    public sealed class System_UInt16
    {
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern bool IsValueType();

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern int SizeOf();

        public static string ToString(ushort value)
        {
            return value.ToString();
        }

        public static ushort TryParse(string str)
        {
            ushort.TryParse(str, out var value);
            return value;
        }
    }
}
