using System.Runtime.CompilerServices;

namespace IL2C.ILConverters
{
    [Case("RawValue", 5)]
    [Case("Add", 9, 4)]
    public static class Ldc_i4_5
    {
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern int RawValue();

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern int Add(int num);
    }
}