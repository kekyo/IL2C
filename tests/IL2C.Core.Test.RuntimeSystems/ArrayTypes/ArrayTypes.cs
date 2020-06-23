/////////////////////////////////////////////////////////////////////////////////////////////////
//
// IL2C - A translator for ECMA-335 CIL/MSIL to C language.
// Copyright (c) 2016-2019 Kouji Matsui (@kozy_kekyo, @kekyo2)
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//	http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
/////////////////////////////////////////////////////////////////////////////////////////////////

using System;
using System.ComponentModel;
using System.Runtime.InteropServices;

namespace IL2C.RuntimeSystems
{
    [Description("Array type generates on the runtime. Example: System.Int32[] isn't declared anything assembly. These tests are verified the IL2C can handle runtime array types and initialize array items from resources.")]
    [TestCase(1111111, "FromInt32", 0)]
    [TestCase(2222222, "FromInt32", 1)]
    [TestCase(3333333, "FromInt32", 2)]
    [TestCase(11, "FromByteResource", 0)]
    [TestCase(22, "FromByteResource", 1)]
    [TestCase(33, "FromByteResource", 2)]
    [TestCase(1111, "FromInt16Resource", 0)]
    [TestCase(-2222, "FromInt16Resource", 1)]
    [TestCase(3333, "FromInt16Resource", 2)]
    [TestCase(1111111, "FromInt32Resource", 0)]
    [TestCase(-2222222, "FromInt32Resource", 1)]
    [TestCase(3333333, "FromInt32Resource", 2)]
    [TestCase(11111111111111, "FromInt64Resource", 0)]
    [TestCase(-22222222222222, "FromInt64Resource", 1)]
    [TestCase(33333333333333, "FromInt64Resource", 2)]
    [TestCase(11, "FromSByteResource", 0)]
    [TestCase(-22, "FromSByteResource", 1)]
    [TestCase(33, "FromSByteResource", 2)]
    [TestCase(11111, "FromUInt16Resource", 0)]
    [TestCase(22222, "FromUInt16Resource", 1)]
    [TestCase(33333, "FromUInt16Resource", 2)]
    [TestCase(1111111, "FromUInt32Resource", 0)]
    [TestCase(2222222, "FromUInt32Resource", 1)]
    [TestCase(3333333, "FromUInt32Resource", 2)]
    [TestCase(11111111111111, "FromUInt64Resource", 0)]
    [TestCase(22222222222222, "FromUInt64Resource", 1)]
    [TestCase(33333333333333, "FromUInt64Resource", 2)]
    [TestCase(111.2222f, "FromSingleResource", 0)]
    [TestCase(-333.4444f, "FromSingleResource", 1)]
    [TestCase(555.6666f, "FromSingleResource", 2)]
    [TestCase(111.2222, "FromDoubleResource", 0)]
    [TestCase(-333.4444, "FromDoubleResource", 1)]
    [TestCase(555.6666, "FromDoubleResource", 2)]
    [TestCase('A', "FromCharResource", 0)]
    [TestCase('B', "FromCharResource", 1)]
    [TestCase('C', "FromCharResource", 2)]
    [TestCase(1, "FromString", 0)]
    [TestCase(22, "FromString", 1)]
    [TestCase(333, "FromString", 2)]
    [TestCase(0, "Length", 0)]
    [TestCase(1, "Length", 1)]
    [TestCase(1000, "Length", 1000)]
    [TestCase(55, "Enumerator")]
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
            var arr = new short[] { 1111, -2222, 3333 };

            return arr[index];
        }

        public static int FromInt32Resource(int index)
        {
            // This expression invokes to System.Runtime.CompilerServices.RuntimeHelpers::InitializeArray().
            var arr = new int[] { 1111111, -2222222, 3333333 };

            return arr[index];
        }

        public static long FromInt64Resource(int index)
        {
            // This expression invokes to System.Runtime.CompilerServices.RuntimeHelpers::InitializeArray().
            var arr = new long[] { 11111111111111, -22222222222222, 33333333333333 };

            return arr[index];
        }

        public static sbyte FromSByteResource(int index)
        {
            // This expression invokes to System.Runtime.CompilerServices.RuntimeHelpers::InitializeArray().
            var arr = new sbyte[] { 11, -22, 33 };

            return arr[index];
        }

        public static ushort FromUInt16Resource(int index)
        {
            // This expression invokes to System.Runtime.CompilerServices.RuntimeHelpers::InitializeArray().
            var arr = new ushort[] { 11111, 22222, 33333 };

            return arr[index];
        }

        public static uint FromUInt32Resource(int index)
        {
            // This expression invokes to System.Runtime.CompilerServices.RuntimeHelpers::InitializeArray().
            var arr = new uint[] { 1111111, 2222222, 3333333 };

            return arr[index];
        }

        public static ulong FromUInt64Resource(int index)
        {
            // This expression invokes to System.Runtime.CompilerServices.RuntimeHelpers::InitializeArray().
            var arr = new ulong[] { 11111111111111, 22222222222222, 33333333333333 };

            return arr[index];
        }

        public static float FromSingleResource(int index)
        {
            // This expression invokes to System.Runtime.CompilerServices.RuntimeHelpers::InitializeArray().
            var arr = new float[] { 111.2222f, -333.4444f, 555.6666f };

            return arr[index];
        }

        public static double FromDoubleResource(int index)
        {
            // This expression invokes to System.Runtime.CompilerServices.RuntimeHelpers::InitializeArray().
            var arr = new double[] { 111.2222, -333.4444, 555.6666 };

            return arr[index];
        }

        public static char FromCharResource(int index)
        {
            // This expression invokes to System.Runtime.CompilerServices.RuntimeHelpers::InitializeArray().
            var arr = new char[] { 'A', 'B', 'C' };

            return arr[index];
        }

        public static int FromString(int index)
        {
            // Not use InitializeArray()
            var arr = new string[] { "1", "22", "333" };
            int.TryParse(arr[index], out var r);
            return r;
        }

        public static int Length(int length)
        {
            var arr = new int[length];

            return arr.Length;
        }

        public static int Enumerator()
        {
            var arr = new int[] { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

            // TODO: It auto translated using "for" loop by Roslyn.
            //   We have to change it after full support for interface type system.
            int result = 0;
            foreach (var value in arr)
            {
                result += value;
            }

            return result;
        }
    }
}
