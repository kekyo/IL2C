using System;
using System.Runtime.InteropServices;

namespace IL2C.TypeSystems
{
    [TestCase(1111111, "FromInt32", 0)]
    [TestCase(2222222, "FromInt32", 1)]
    [TestCase(3333333, "FromInt32", 2)]
    [TestCase(11, "FromByteResource", 0)]
    [TestCase(22, "FromByteResource", 1)]
    [TestCase(33, "FromByteResource", 2)]
    [TestCase(1111, "FromInt16Resource", 0)]
    [TestCase(2222, "FromInt16Resource", 1)]
    [TestCase(3333, "FromInt16Resource", 2)]
    [TestCase(1111111, "FromInt32Resource", 0)]
    [TestCase(2222222, "FromInt32Resource", 1)]
    [TestCase(3333333, "FromInt32Resource", 2)]
    [TestCase(11111111111111, "FromInt64Resource", 0)]
    [TestCase(22222222222222, "FromInt64Resource", 1)]
    [TestCase(33333333333333, "FromInt64Resource", 2)]
    [TestCase(0, "Length", 0)]
    [TestCase(1, "Length", 1)]
    [TestCase(1000, "Length", 1000)]
    public sealed class ArrayTypes
    {
        public static int FromInt32(int index)
        {
            var arr = new int[3];
            arr[0] = 1111111;
            arr[1] = 2222222;
            arr[2] = 3333333;

            return arr[index];
        }

        public static byte FromByteResource(int index)
        {
            // This expression invokes to System.Runtime.CompilerServices.RuntimeHelpers::InitializeArray().
            var arr = new byte[] { 11, 22, 33 };

            return arr[index];
        }

        public static short FromInt16Resource(int index)
        {
            // This expression invokes to System.Runtime.CompilerServices.RuntimeHelpers::InitializeArray().
            var arr = new short[] { 1111, 2222, 3333 };

            return arr[index];
        }

        public static int FromInt32Resource(int index)
        {
            // This expression invokes to System.Runtime.CompilerServices.RuntimeHelpers::InitializeArray().
            var arr = new int[] { 1111111, 2222222, 3333333 };

            return arr[index];
        }

        public static long FromInt64Resource(int index)
        {
            // This expression invokes to System.Runtime.CompilerServices.RuntimeHelpers::InitializeArray().
            var arr = new long[] { 11111111111111, 22222222222222, 33333333333333 };

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
