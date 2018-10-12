using System.Runtime.CompilerServices;

namespace IL2C.ILConverters
{
    [Case(4, "RawValue")]
    [Case(8, "Add", 4)]
    public static class Ldc_i4_4
    {
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern int RawValue();

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern int Add(int num);
    }
}
