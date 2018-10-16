using System.Runtime.CompilerServices;

namespace IL2C.ILConverters
{
    [Case(float.MaxValue, "MaxValue")]
    [Case(float.MinValue, "MinValue")]
    public sealed class Ldc_r4
    {
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern float MaxValue();

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern float MinValue();
    }
}
