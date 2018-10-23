using System;
using System.Runtime.CompilerServices;

namespace IL2C.ILConverters
{
    [TestCase(0, "CauseBreak", 100, 23, Assert = TestCaseAsserts.CauseBreak)]
    public sealed class Break
    {
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern int CauseBreak(int v1, int v2);
    }
}
