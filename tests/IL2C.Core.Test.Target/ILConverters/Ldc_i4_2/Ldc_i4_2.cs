using System.Runtime.CompilerServices;

namespace IL2C.ILConverters
{
    [Case(2, "RawValue")]
    [Case(6, "Add", 4)]
    public sealed class Ldc_i4_2
    {
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern int RawValue();

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern int Add(int num);
    }
}
