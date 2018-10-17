using System;
using System.Runtime.CompilerServices;

namespace IL2C.ILConverters
{
    [Case(123, "Value")]
    [Case(null, "Void")]
    public sealed class Ret
    {
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern int Value();

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern void Void();
    }
}
