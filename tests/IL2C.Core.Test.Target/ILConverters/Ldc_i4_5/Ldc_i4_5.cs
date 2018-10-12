using System.Runtime.CompilerServices;

namespace IL2C.ILConverters
{
    [Case(5, "RawValue")]
    [Case(9, "Add", 4)]
    public static class Ldc_i4_5
    {
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern int RawValue();

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern int Add(int num);
    }
}
