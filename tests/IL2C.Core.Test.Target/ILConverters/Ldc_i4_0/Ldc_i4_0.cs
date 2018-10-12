using System.Runtime.CompilerServices;

namespace IL2C.ILConverters
{
    [Case("RawValue", 0)]
    [Case("Add", 4, 4)]
    public static class Ldc_i4_0
    {
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern int RawValue();

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern int Add(int num);
    }
}
