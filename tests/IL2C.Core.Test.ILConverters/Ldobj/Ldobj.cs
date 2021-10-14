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
    [TestCase(4, "Ldobj_test_int32", 0 * 4)]
    [TestCase(3, "Ldobj_test_int32", 1 * 4)]
    [TestCase(2, "Ldobj_test_int32", 2 * 4)]
    [TestCase(1, "Ldobj_test_int32", 3 * 4)]
    [TestCase(0, "Ldobj_test_int32", 4 * 4)]
    public sealed class Ldobj
    {
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern int Ldobj_test_int32i(int v, int[] vs);

        public static int Ldobj_test_int32(int v)
        {
            var TestInt32Values = new int[5];
            TestInt32Values[0] = 4;
            TestInt32Values[1] = 3;
            TestInt32Values[2] = 2;
            TestInt32Values[3] = 1;
            TestInt32Values[4] = 0;
            return Ldobj_test_int32i(v, TestInt32Values);
        }
    }
}
