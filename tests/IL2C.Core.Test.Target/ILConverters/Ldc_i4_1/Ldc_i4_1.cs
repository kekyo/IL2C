using System.Runtime.CompilerServices;

namespace IL2C.ILConverters
{
    [Case("RawValue", 1)]
    [Case("Add", 5, 4)]
    public static class Ldc_i4_1
    {
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern int RawValue();

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern int Add(int num);
    }
}
