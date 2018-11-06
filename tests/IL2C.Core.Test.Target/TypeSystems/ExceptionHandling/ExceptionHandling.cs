using System;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;

namespace IL2C.TypeSystems
{
    [TestCase(123, "RaiseAndCaughtLocal", false)]
    [TestCase(456, "RaiseAndCaughtLocal", true)]
    public sealed class ExceptionHandling
    {
        public static int RaiseAndCaughtLocal(bool sw)
        {
            try
            {
                if (sw) throw new Exception();
            }
            catch (Exception)
            {
                return 456;
            }
            return 123;
        }
    }
}
