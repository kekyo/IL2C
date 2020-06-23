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
    [TestCase(true, new[] { "Int32", "Unbox_Int32" }, 123)]
    [TestCase(124, "FromValueType", 123)]
    public sealed class Unbox_any
    {
        [MethodImpl(MethodImplOptions.ForwardRef)]
        private static extern int Unbox_Int32(object value);

        public static bool Int32(object value)
        {
            var ub = Unbox_Int32(value);
            return ub == 123;
        }

        // https://github.com/kekyo/IL2C/issues/37
        public static int FromValueType(int value)
        {
            ValueType v = value + 1;    // boxed
            return (int)v;
        }
    }
}
