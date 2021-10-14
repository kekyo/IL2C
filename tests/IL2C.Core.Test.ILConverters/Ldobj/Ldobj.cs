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
    [TestCase(4, "Ldobj_test_int32", 4)]
    [TestCase(1, "Ldobj_test_int32", 1)]
    [TestCase(0, "Ldobj_test_int32", 0)]
    [TestCase(int.MinValue, "Ldobj_test_int32", int.MinValue)]
    [TestCase(int.MaxValue, "Ldobj_test_int32", int.MaxValue)]

    //[TestCase("1:2 C(3,4,5)", "Ldobj_test_PointSer", "1:2 C(3,4,5)", IncludeTypes = new[] { typeof(Point) })]
    //[TestCase("20:20 C(255,255,255)", "Ldobj_test_PointSer", "20:20 C(255,255,255)", IncludeTypes = new[] { typeof(Point) })]
    public sealed class Ldobj
    {
        //public struct Point
        //{
        //    public int X, Y;
        //    public int R, G, B;

        //    public override string ToString()
        //    {
        //        return $"{X}:{Y} C({R},{G},{B})";
        //    }

        //    public static Point Parse(string v)
        //    {
        //        var result = new Point();
        //        var coo = v.Split(' ')[0];
        //        result.X = Int32.Parse(coo.Split(':')[0]);
        //        result.Y = Int32.Parse(coo.Split(':')[1]);
        //        var col = v.Split(' ')[1].Trim(new char[] { 'C', '(', ')' });
        //        result.R = Int32.Parse(col.Split(',')[0]);
        //        result.G = Int32.Parse(col.Split(',')[1]);
        //        result.B = Int32.Parse(col.Split(',')[2]);
        //        return result;
        //    }
        //}

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern int Ldobj_test_int32(int v);

        //[MethodImpl(MethodImplOptions.ForwardRef)]
        //public static extern Point Ldobj_test_Point(Point v);

        //public static string Ldobj_test_PointSer(string val)
        //{
        //    var v = Point.Parse(val);
        //    return Ldobj_test_Point(v).ToString();
        //}
    }
}
