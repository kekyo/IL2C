using System;
using System.Runtime.CompilerServices;

namespace IL2C.ILConverters
{
    [Case(123, "Nothing")]
    public sealed class Nop
    {
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern int Nothing();
    }
}
