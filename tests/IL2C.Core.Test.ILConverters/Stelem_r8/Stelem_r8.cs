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
    [TestCase(123.111, new[] { "Double", "DoubleInner" }, 0, 123.111)]
    [TestCase(456.222, new[] { "Double", "DoubleInner" }, 1, 456.222)]
    [TestCase(789.333, new[] { "Double", "DoubleInner" }, 2, 789.333)]
    [TestCase(123.111, new[] { "DoubleIntPtrIndex", "DoubleIntPtrIndexInner" }, 0, 123.111)]
    [TestCase(456.222, new[] { "DoubleIntPtrIndex", "DoubleIntPtrIndexInner" }, 1, 456.222)]
    [TestCase(789.333, new[] { "DoubleIntPtrIndex", "DoubleIntPtrIndexInner" }, 2, 789.333)]
    public sealed class Stelem_r8
    {
        public static double Double(int index, double value)
        {
            var values = new double[] { 1, 2, 3 };
            DoubleInner(values, index, value);
            return values[index];
        }

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern void DoubleInner(double[] values, int index, double value);

        public static double DoubleIntPtrIndex(int index, double value)
        {
            var values = new double[] { 1, 2, 3 };
            DoubleIntPtrIndexInner(values, index, value);
            return values[index];
        }

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern void DoubleIntPtrIndexInner(double[] values, int index, double value);
    }
}
