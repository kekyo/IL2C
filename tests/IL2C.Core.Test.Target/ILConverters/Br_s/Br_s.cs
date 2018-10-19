using System;
using System.Runtime.CompilerServices;

namespace IL2C.ILConverters
{
    [TestCase(5, "Rem2", 12345, 47, 26)]
    public sealed class Br_s
    {
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern int Rem2(int v, int d1, int d2);
    }
}
