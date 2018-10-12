using System.Runtime.CompilerServices;

namespace IL2C.ILConverters
{
    [Case("RawValue", 4)]
    [Case("Add", 8, 4)]
    public static class Ldc_i4_4
    {
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern int RawValue();

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern int Add(int num);
    }
}
