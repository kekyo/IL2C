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
    public struct Point
    {
        public int X, Y;
        public int R, G, B;

        public override string ToString()
        {
            return $"{X}:{Y} C({R},{G},{B})";
        }
    }
    [TestCase(byte.MinValue, "Ldobj_test_uint8", byte.MinValue)]
    [TestCase(byte.MaxValue, "Ldobj_test_uint8", byte.MaxValue)]

    [TestCase(ushort.MinValue, "Ldobj_test_uint16", ushort.MinValue)]
    [TestCase(ushort.MaxValue, "Ldobj_test_uint16", ushort.MaxValue)]
    
    [TestCase(4, "Ldobj_test_int32", 4)]
    [TestCase(1, "Ldobj_test_int32", 1)]
    [TestCase(0, "Ldobj_test_int32", 0)]
    [TestCase(int.MinValue, "Ldobj_test_int32", int.MinValue)]
    [TestCase(int.MaxValue, "Ldobj_test_int32", int.MaxValue)]

    [TestCase(4L, "Ldobj_test_int64", 4L)]
    [TestCase(1L, "Ldobj_test_int64", 1L)]
    [TestCase(0L, "Ldobj_test_int64", 0L)]
    [TestCase(long.MinValue, "Ldobj_test_int64", long.MinValue)]
    [TestCase(long.MaxValue, "Ldobj_test_int64", long.MaxValue)]

    [TestCase(ulong.MinValue, "Ldobj_test_uint64", ulong.MinValue)]
    [TestCase(ulong.MaxValue, "Ldobj_test_uint64", ulong.MaxValue)]

    [TestCase(0.0F, "Ldobj_test_float", 0.0F)]
    [TestCase(-0.001F, "Ldobj_test_float", -0.001F)]
    [TestCase(float.MinValue, "Ldobj_test_float", float.MinValue)]
    [TestCase(float.MaxValue, "Ldobj_test_float", float.MaxValue)]

    [TestCase(0.0, "Ldobj_test_double", 0.0)]
    [TestCase(-0.001, "Ldobj_test_double", -0.001)]
    [TestCase(double.MinValue, "Ldobj_test_double", double.MinValue)]
    [TestCase(double.MaxValue, "Ldobj_test_double", double.MaxValue)]

    [TestCase("1:2 C(3,4,5)", "Ldobj_test_PointSer", 1, 2, 3, 4, 5, IncludeTypes = new[] { typeof(Ldobj), typeof(Point), typeof(Int32), typeof(Char), typeof(String) })]
    [TestCase("20:20 C(255,255,255)", "Ldobj_test_PointSer", 20, 20, 255, 255, 255, IncludeTypes = new[] { typeof(Ldobj), typeof(Point), typeof(Int32), typeof(Char), typeof(String) })]
    public sealed class Ldobj
    {
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern byte Ldobj_test_uint8(byte v);
        
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern ushort Ldobj_test_uint16(ushort v);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern int Ldobj_test_int32(int v);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern long Ldobj_test_int64(long v);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern ulong Ldobj_test_uint64(ulong v);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern float Ldobj_test_float(float v);
        
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern double Ldobj_test_double(double v);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern Point Ldobj_test_Point(Point v);

        public static string Ldobj_test_PointSer(int x, int y, int r, int g, int b)
        {
            var v = new Point() { X = x, Y = y, R = r, G = g, B = b };
            return Ldobj_test_Point(v).ToString();
        }
    }
}
