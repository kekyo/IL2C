using System.Runtime.CompilerServices;

namespace IL2C.TypeSystems
{
    [TestCase(true, "IsValueType")]
    [TestCase(4, "SizeOf")]
    public sealed class Int32
    {
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern bool IsValueType();

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern int SizeOf();
    }
}
