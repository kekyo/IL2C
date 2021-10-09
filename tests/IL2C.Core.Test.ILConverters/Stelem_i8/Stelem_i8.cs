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
    [TestCase(123L, new[] { "Int64", "Int64Inner" }, 0, 123L)]
    [TestCase(456L, new[] { "Int64", "Int64Inner" }, 1, 456L)]
    [TestCase(789L, new[] { "Int64", "Int64Inner" }, 2, 789L)]
    [TestCase(123L, new[] { "Int64IntPtrIndex", "Int64IntPtrIndexInner" }, 0, 123L)]
    [TestCase(456L, new[] { "Int64IntPtrIndex", "Int64IntPtrIndexInner" }, 1, 456L)]
    [TestCase(789L, new[] { "Int64IntPtrIndex", "Int64IntPtrIndexInner" }, 2, 789L)]
    public sealed class Stelem_i8
    {
        public static long Int64(int index, long value)
        {
            var values = new long[] { 1, 2, 3 };
            Int64Inner(values, index, value);
            return values[index];
        }

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern void Int64Inner(long[] values, int index, long value);

        public static long Int64IntPtrIndex(int index, long value)
        {
            var values = new long[] { 1, 2, 3 };
            Int64IntPtrIndexInner(values, index, value);
            return values[index];
        }

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern void Int64IntPtrIndexInner(long[] values, int index, long value);
    }
}
