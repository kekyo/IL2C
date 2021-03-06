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
    [TestCase((ushort)12345, "Int32", 12345)]
    [TestCase(unchecked ((ushort)45678), "Int32", 45678)]
    [TestCase((ushort)12345, "Int64", 12345L)]
    [TestCase(unchecked((ushort)45678), "Int64", 45678L)]
    [TestCase((ushort)12345, "IntPtr", 12345)]
    [TestCase(unchecked((ushort)45678), "IntPtr", 45678)]
    [TestCase((ushort)12345, "Single", 12345.67f)]
    [TestCase(unchecked((ushort)45678), "Single", 45678.91f)]
    [TestCase((ushort)12345, "Double", 12345.67)]
    [TestCase(unchecked((ushort)45678), "Double", 45678.91)]
    public sealed class Conv_u2
    {
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern ushort Int32(int value);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern ushort Int64(long value);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern ushort IntPtr(IntPtr value);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern ushort Single(float value);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern ushort Double(double value);
    }
}
