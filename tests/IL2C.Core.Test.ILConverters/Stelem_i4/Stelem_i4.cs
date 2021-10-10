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
    [TestCase(123, new[] { "Int32", "Int32Inner" }, 0, 123)]
    [TestCase(456, new[] { "Int32", "Int32Inner" }, 1, 456)]
    [TestCase(789, new[] { "Int32", "Int32Inner" }, 2, 789)]
    [TestCase(123, new[] { "Int32IntPtrIndex", "Int32IntPtrIndexInner" }, 0, 123)]
    [TestCase(456, new[] { "Int32IntPtrIndex", "Int32IntPtrIndexInner" }, 1, 456)]
    [TestCase(789, new[] { "Int32IntPtrIndex", "Int32IntPtrIndexInner" }, 2, 789)]
    public sealed class Stelem_i4
    {
        public static int Int32(int index, int value)
        {
            var values = new[] { 1, 2, 3 };
            Int32Inner(values, index, value);
            return values[index];
        }

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern void Int32Inner(int[] values, int index, int value);

        public static int Int32IntPtrIndex(int index, int value)
        {
            var values = new[] { 1, 2, 3 };
            Int32IntPtrIndexInner(values, index, value);
            return values[index];
        }

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern void Int32IntPtrIndexInner(int[] values, int index, int value);
    }
}
