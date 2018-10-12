using System.Runtime.CompilerServices;

namespace IL2C.ILConverters
{
    [Case(int.MaxValue, "MaxValue")]
    [Case(int.MinValue, "MinValue")]
    public static class Ldc_i4
    {
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern int MaxValue();

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern int MinValue();
    }
}
