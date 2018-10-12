using System.Runtime.CompilerServices;

namespace IL2C.ILConverters
{
    [Case("RawValue", 7)]
    [Case("Add", 11, 4)]
    public static class Ldc_i4_7
    {
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern int RawValue();

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern int Add(int num);
    }
}
