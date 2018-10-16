using System.Runtime.CompilerServices;

namespace IL2C.ILConverters
{
    [Case(double.MaxValue, "MaxValue")]
    [Case(double.MinValue, "MinValue")]
    public sealed class Ldc_r8
    {
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern double MaxValue();

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern double MinValue();
    }
}
