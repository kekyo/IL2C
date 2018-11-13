using System;
using System.ComponentModel;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;

namespace IL2C.RuntimeSystems
{
    [TestId("ExceptionThrownByCLI")]
    [TestCase(false, "ArrayIndexOutOfRangeByLoad", 0)]
    [TestCase(false, "ArrayIndexOutOfRangeByLoad", 6)]
    [TestCase(true, "ArrayIndexOutOfRangeByLoad", -1)]
    [TestCase(true, "ArrayIndexOutOfRangeByLoad", 7)]
    [TestCase(false, "ArrayIndexOutOfRangeByStore", 0)]
    [TestCase(false, "ArrayIndexOutOfRangeByStore", 6)]
    [TestCase(true, "ArrayIndexOutOfRangeByStore", -1)]
    [TestCase(true, "ArrayIndexOutOfRangeByStore", 7)]
    public sealed class ArrayIndexOutOfRangeExceptions
    {
        public static bool ArrayIndexOutOfRangeByLoad(int index)
        {
            try
            {
                var arr = new int[7];
                var v = arr[index];
            }
            catch (IndexOutOfRangeException)
            {
                return true;
            }
            return false;
        }

        public static bool ArrayIndexOutOfRangeByStore(int index)
        {
            try
            {
                var arr = new int[7];
                arr[index] = 123;
            }
            catch (IndexOutOfRangeException)
            {
                return true;
            }
            return false;
        }
    }
}
