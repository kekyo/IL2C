using System.Runtime.CompilerServices;

namespace IL2C.ILConverters
{
    [Case("RawValue", -1)]
    [Case("Add", 3, 4)]
    public static class Ldc_i4_m1
    {
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern int RawValue();

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern int Add(int num);
    }
}
