using System.Runtime.CompilerServices;

namespace IL2C.ILConverters
{
    [Case("RawValue", 8)]
    [Case("Add", 12, 4)]
    public static class Ldc_i4_8
    {
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern int RawValue();

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern int Add(int num);
    }
}
