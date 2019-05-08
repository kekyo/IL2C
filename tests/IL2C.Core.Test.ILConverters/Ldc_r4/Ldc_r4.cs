using System.Runtime.CompilerServices;

namespace IL2C.ILConverters
{
    [TestCase(float.MaxValue, "MaxValue")]
    [TestCase(float.MinValue, "MinValue")]
    public sealed class Ldc_r4
    {
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern float MaxValue();

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern float MinValue();
    }
}
