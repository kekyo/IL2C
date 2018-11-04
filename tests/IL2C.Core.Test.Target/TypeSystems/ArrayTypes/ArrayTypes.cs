using System;
using System.Runtime.InteropServices;

namespace IL2C.TypeSystems
{
    [TestCase(111, "FromInt32", 0)]
    [TestCase(222, "FromInt32", 1)]
    [TestCase(333, "FromInt32", 2)]
    [TestCase(111, "FromInt32Resource", 0)]
    [TestCase(222, "FromInt32Resource", 1)]
    [TestCase(333, "FromInt32Resource", 2)]
    [TestCase(0, "Length", 0)]
    [TestCase(1, "Length", 1)]
    [TestCase(1000, "Length", 1000)]
    public sealed class ArrayTypes
    {
        public static int FromInt32(int index)
        {
            // This expression invokes to System.Runtime.CompilerServices.RuntimeHelpers::InitializeArray().
            // var arr = new int[] { 111, 222, 333 };

            var arr = new int[3];
            arr[0] = 111;
            arr[1] = 222;
            arr[2] = 333;

            return arr[index];
        }

        public static int FromInt32Resource(int index)
        {
            // This expression invokes to System.Runtime.CompilerServices.RuntimeHelpers::InitializeArray().
            var arr = new int[] { 111, 222, 333 };

            return arr[index];
        }

        public static int FromStringResource(int index)
        {
            // Not use InitializeArray()
            var arr = new string[] { "1", "22", "333" };
            return int.Parse(arr[index]);
        }

        public static int Length(int length)
        {
            var arr = new int[length];

            return arr.Length;
        }
    }
}
