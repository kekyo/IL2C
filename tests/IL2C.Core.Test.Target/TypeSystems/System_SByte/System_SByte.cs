using System.Runtime.CompilerServices;

namespace IL2C.TypeSystems
{
    [TestCase(true, "IsValueType")]
    [TestCase(1, "SizeOf")]
    public sealed class System_SByte
    {
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern bool IsValueType();

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern int SizeOf();
    }
}
