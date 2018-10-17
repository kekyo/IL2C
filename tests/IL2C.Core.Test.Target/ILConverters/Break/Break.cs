using System;
using System.Runtime.CompilerServices;

namespace IL2C.ILConverters
{
    [Case(Case.TrapBreak, "CauseBreak", 100, 23)]
    public sealed class Break
    {
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern int CauseBreak(int v1, int v2);
    }
}
