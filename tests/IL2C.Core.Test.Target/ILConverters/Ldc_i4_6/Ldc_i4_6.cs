using System.Runtime.CompilerServices;

namespace IL2C.ILConverters
{
    [Case(6, "RawValue")]
    [Case(10, "Add", 4)]
    public sealed class Ldc_i4_6
    {
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern int RawValue();

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern int Add(int num);
    }
}
