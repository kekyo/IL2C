using System.Runtime.CompilerServices;

namespace IL2C.ILConverters
{
    [Case(127, "Plus127Value")]
    [Case(-128, "Minus128Value")]
    public sealed class Ldc_i4_s
    {
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern int Plus127Value();

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern int Minus128Value();
    }
}
