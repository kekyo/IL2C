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
using System.Runtime.CompilerServices;

namespace IL2C.ILConverters
{
    [TestCase(byte.MinValue, "Stobj_test_uint8Tst", byte.MinValue, IncludeTypes = new[] { typeof(Stobj), typeof(Point) })]
    [TestCase(byte.MaxValue, "Stobj_test_uint8Tst", byte.MaxValue, IncludeTypes = new[] { typeof(Stobj), typeof(Point) })]

    [TestCase(ushort.MinValue, "Stobj_test_uint16Tst", ushort.MinValue, IncludeTypes = new[] { typeof(Stobj), typeof(Point) })]
    [TestCase(ushort.MaxValue, "Stobj_test_uint16Tst", ushort.MaxValue, IncludeTypes = new[] { typeof(Stobj), typeof(Point) })]
    
    [TestCase(4, "Stobj_test_int32Tst", 4, IncludeTypes = new[] { typeof(Stobj), typeof(Point) })]
    [TestCase(1, "Stobj_test_int32Tst", 1, IncludeTypes = new[] { typeof(Stobj), typeof(Point) })]
    [TestCase(0, "Stobj_test_int32Tst", 0, IncludeTypes = new[] { typeof(Stobj), typeof(Point) })]
    [TestCase(int.MinValue, "Stobj_test_int32Tst", int.MinValue, IncludeTypes = new[] { typeof(Stobj), typeof(Point) })]
    [TestCase(int.MaxValue, "Stobj_test_int32Tst", int.MaxValue, IncludeTypes = new[] { typeof(Stobj), typeof(Point) })]

    [TestCase(4L, "Stobj_test_int64Tst", 4L, IncludeTypes = new[] { typeof(Stobj), typeof(Point) })]
    [TestCase(1L, "Stobj_test_int64Tst", 1L, IncludeTypes = new[] { typeof(Stobj), typeof(Point) })]
    [TestCase(0L, "Stobj_test_int64Tst", 0L, IncludeTypes = new[] { typeof(Stobj), typeof(Point) })]
    [TestCase(long.MinValue, "Stobj_test_int64Tst", long.MinValue, IncludeTypes = new[] { typeof(Stobj), typeof(Point) })]
    [TestCase(long.MaxValue, "Stobj_test_int64Tst", long.MaxValue, IncludeTypes = new[] { typeof(Stobj), typeof(Point) })]

    [TestCase(ulong.MinValue, "Stobj_test_uint64Tst", ulong.MinValue, IncludeTypes = new[] { typeof(Stobj), typeof(Point) })]
    [TestCase(ulong.MaxValue, "Stobj_test_uint64Tst", ulong.MaxValue, IncludeTypes = new[] { typeof(Stobj), typeof(Point) })]

    [TestCase(0.0F, "Stobj_test_floatTst", 0.0F, IncludeTypes = new[] { typeof(Stobj), typeof(Point) })]
    [TestCase(-0.001F, "Stobj_test_floatTst", -0.001F, IncludeTypes = new[] { typeof(Stobj), typeof(Point) })]
    [TestCase(float.MinValue, "Stobj_test_floatTst", float.MinValue, IncludeTypes = new[] { typeof(Stobj), typeof(Point) })]
    [TestCase(float.MaxValue, "Stobj_test_floatTst", float.MaxValue, IncludeTypes = new[] { typeof(Stobj), typeof(Point) })]

    [TestCase(0.0, "Stobj_test_doubleTst", 0.0, IncludeTypes = new[] { typeof(Stobj), typeof(Point) })]
    [TestCase(-0.001, "Stobj_test_doubleTst", -0.001, IncludeTypes = new[] { typeof(Stobj), typeof(Point) })]
    [TestCase(double.MinValue, "Stobj_test_doubleTst", double.MinValue, IncludeTypes = new[] { typeof(Stobj), typeof(Point) })]
    [TestCase(double.MaxValue, "Stobj_test_doubleTst", double.MaxValue, IncludeTypes = new[] { typeof(Stobj), typeof(Point) })]

    [TestCase("1:2 C(3,4,5)", "Stobj_test_PointSer", 1, 2, 3, 4, 5, IncludeTypes = new[] { typeof(Stobj), typeof(Point), typeof(Int32), typeof(Char), typeof(String) })]
    [TestCase("20:20 C(255,255,255)", "Stobj_test_PointSer", 20, 20, 255, 255, 255, IncludeTypes = new[] { typeof(Stobj), typeof(Point), typeof(Int32), typeof(Char), typeof(String) })]
    public sealed class Stobj
    {
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern void Stobj_test_uint8(byte v, out byte result);

        public static byte Stobj_test_uint8Tst(byte v)
        {
            Stobj_test_uint8(v, out byte result);
            return result;
        }
        
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern void Stobj_test_uint16(ushort v, out ushort result);

        public static ushort Stobj_test_uint16Tst(ushort v)
        {
            Stobj_test_uint16(v, out ushort result);
            return result;
        }

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern void Stobj_test_int32(int v, out int result);

        public static int Stobj_test_int32Tst(int v)
        {
            Stobj_test_int32(v, out int result);
            return result;
        }

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern void Stobj_test_int64(long v, out long result);

        public static long Stobj_test_int64Tst(long v)
        {
            Stobj_test_int64(v, out long result);
            return result;
        }

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern void Stobj_test_uint64(ulong v, out ulong result);

        public static ulong Stobj_test_uint64Tst(ulong v)
        {
            Stobj_test_uint64(v, out ulong result);
            return result;
        }

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern void Stobj_test_float(float v, out float result);

        public static float Stobj_test_floatTst(float v)
        {
            Stobj_test_float(v, out float result);
            return result;
        }

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern void Stobj_test_double(double v, out double result);

        public static double Stobj_test_doubleTst(double v)
        {
            Stobj_test_double(v, out double result);
            return result;
        }

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern void Stobj_test_Point(Point v, out Point result);

        public static string Stobj_test_PointSer(int x, int y, int r, int g, int b)
        {
            var v = new Point() { X = x, Y = y, R = r, G = g, B = b };
            Stobj_test_Point(v, out Point result);
            return result.ToString();
        }
        
    }
}
