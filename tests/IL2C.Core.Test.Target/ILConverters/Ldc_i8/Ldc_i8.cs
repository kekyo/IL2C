using System.Runtime.CompilerServices;

namespace IL2C.ILConverters
{
    [Case(long.MaxValue, "MaxValue")]
    [Case(long.MinValue, "MinValue")]
    public static class Ldc_i8
    {
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern long MaxValue();

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern long MinValue();
    }
}
