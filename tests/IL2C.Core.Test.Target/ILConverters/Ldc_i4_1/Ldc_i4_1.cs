using System.Runtime.CompilerServices;

namespace IL2C.ILConverters
{
    [Case(1, "RawValue")]
    [Case(5, "Add", 4)]
    public sealed class Ldc_i4_1
    {
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern int RawValue();

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern int Add(int num);
    }
}
