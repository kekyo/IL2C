using System.Runtime.CompilerServices;

namespace IL2C.ILConverters
{
    [Case("RawValue", 3)]
    [Case("Add", 7, 4)]
    public static class Ldc_i4_3
    {
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern int RawValue();

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern int Add(int num);
    }
}
