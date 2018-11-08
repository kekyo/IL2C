using System;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;

namespace IL2C.TypeSystems
{
    [TestCase(123, "RaiseAndCaughtLocal", false)]
    [TestCase(456, "RaiseAndCaughtLocal", true)]
    [TestCase(123, "RaiseAndCaughtMultipleHandlerLocal", 0)]
    [TestCase(456, "RaiseAndCaughtMultipleHandlerLocal", 1)]
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

        public static int RaiseAndCaughtMultipleHandlerLocal(int sw)
        {
            try
            {
                if (sw == 1) throw new Exception();
                if (sw == 2) throw new InvalidCastException();
            }
            catch (InvalidCastException)
            {
                return 789;
            }
            catch (Exception)
            {
                return 456;
            }
            return 123;
        }
    }
}
