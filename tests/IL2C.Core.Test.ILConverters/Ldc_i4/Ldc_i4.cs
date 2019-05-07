using System.Runtime.CompilerServices;

namespace IL2C.ILConverters
{
    [TestCase(int.MaxValue, "MaxValue")]
    [TestCase(int.MinValue, "MinValue")]
    public sealed class Ldc_i4
    {
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern int MaxValue();

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern int MinValue();
    }
}
