using System.Runtime.CompilerServices;

namespace IL2C.ILConverters
{
    [Case("RawValue", 2)]
    [Case("Add", 6, 4)]
    public static class Ldc_i4_2
    {
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern int RawValue();

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern int Add(int num);
    }
}
