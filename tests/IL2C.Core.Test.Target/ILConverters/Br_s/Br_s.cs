using System;
using System.Runtime.CompilerServices;

namespace IL2C.ILConverters
{
    [Case(6, "ValidValue")]
    public sealed class Br_s
    {
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern int ValidValue();
    }
}
