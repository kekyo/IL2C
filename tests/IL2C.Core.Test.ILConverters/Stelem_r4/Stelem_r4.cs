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
    [TestCase(123f, new[] { "Single", "SingleInner" }, 0, 123f)]
    [TestCase(456f, new[] { "Single", "SingleInner" }, 1, 456f)]
    [TestCase(789f, new[] { "Single", "SingleInner" }, 2, 789f)]
    [TestCase(123f, new[] { "SingleIntPtrIndex", "SingleIntPtrIndexInner" }, 0, 123f)]
    [TestCase(456f, new[] { "SingleIntPtrIndex", "SingleIntPtrIndexInner" }, 1, 456f)]
    [TestCase(789f, new[] { "SingleIntPtrIndex", "SingleIntPtrIndexInner" }, 2, 789f)]
    public sealed class Stelem_r4
    {
        public static float Single(int index, float value)
        {
            var values = new[] { 1f, 2f, 3f };
            SingleInner(values, index, value);
            return values[index];
        }

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern void SingleInner(float[] values, int index, float value);

        public static float SingleIntPtrIndex(int index, float value)
        {
            var values = new[] { 1f, 2f, 3f };
            SingleIntPtrIndexInner(values, index, value);
            return values[index];
        }

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern void SingleIntPtrIndexInner(float[] values, int index, float value);
    }
}
