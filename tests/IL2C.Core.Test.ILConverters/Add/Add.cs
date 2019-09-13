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
    [TestCase(36, "Int32_Int32", 12, 24)]
    [TestCase(36, "Int32_IntPtr", 12, 24)]
    [TestCase(123, new[] { "Int32_IntRef", "Add_Int32_IntRef" }, 123)]
    [TestCase(36L, "Int64_Int64", 12L, 24L)]
    [TestCase(36, "IntPtr_Int32", 12, 24)]
    [TestCase(36, "IntPtr_IntPtr", 12, 24)]
    [TestCase(123, new[] { "IntPtr_IntRef", "Add_IntPtr_IntRef" }, 123)]
    [TestCase(0.45f + 123.0f, "Single_Single", 0.45f, 123.0f)]
    [TestCase(0.45f + 123.0, "Single_Double", 0.45f, 123.0)]
    [TestCase(0.45 + 123.0f, "Double_Single", 0.45, 123.0f)]
    [TestCase(0.45 + 123.0, "Double_Double", 0.45, 123.0)]
    [TestCase(123, new[] { "IntRef_Int32", "Add_IntRef_Int32" }, 123)]
    [TestCase(123, new[] { "IntRef_IntPtr", "Add_IntRef_IntPtr" }, 123)]
    public sealed class Add
    {
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern int Int32_Int32(int lhs, int rhs);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern IntPtr Int32_IntPtr(int lhs, IntPtr rhs);

            [MethodImpl(MethodImplOptions.ForwardRef)]
            private static extern ref int Add_Int32_IntRef(int lhs, ref int rhs);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern int Int32_IntRef(int value);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern long Int64_Int64(long lhs, long rhs);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern IntPtr IntPtr_Int32(IntPtr lhs, int rhs);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern IntPtr IntPtr_IntPtr(IntPtr lhs, IntPtr rhs);

            [MethodImpl(MethodImplOptions.ForwardRef)]
            private static extern ref int Add_IntPtr_IntRef(IntPtr lhs, ref int rhs);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern int IntPtr_IntRef(int value);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern float Single_Single(float lhs, float rhs);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern double Single_Double(float lhs, double rhs);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern double Double_Single(double lhs, float rhs);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern double Double_Double(double lhs, double rhs);

            [MethodImpl(MethodImplOptions.ForwardRef)]
            private static extern ref int Add_IntRef_Int32(ref int lhs, int rhs);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern int IntRef_Int32(int value);

            [MethodImpl(MethodImplOptions.ForwardRef)]
            private static extern ref int Add_IntRef_IntPtr(ref int lhs, IntPtr rhs);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern int IntRef_IntPtr(int value);
    }
}
