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
using System.ComponentModel;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;

namespace IL2C.RuntimeSystems
{
    [TestId("ExceptionThrownByCLI")]
    [TestCase(false, "ArrayIndexOutOfRangeByLoad", 0)]
    [TestCase(false, "ArrayIndexOutOfRangeByLoad", 6)]
    [TestCase(true, "ArrayIndexOutOfRangeByLoad", -1)]
    [TestCase(true, "ArrayIndexOutOfRangeByLoad", 7)]
    [TestCase(false, "ArrayIndexOutOfRangeByStore", 0)]
    [TestCase(false, "ArrayIndexOutOfRangeByStore", 6)]
    [TestCase(true, "ArrayIndexOutOfRangeByStore", -1)]
    [TestCase(true, "ArrayIndexOutOfRangeByStore", 7)]
    public sealed class ArrayIndexOutOfRangeExceptions
    {
        public static bool ArrayIndexOutOfRangeByLoad(int index)
        {
            try
            {
                var arr = new int[7];
                var v = arr[index];
            }
            catch (IndexOutOfRangeException)
            {
                return true;
            }
            return false;
        }

        public static bool ArrayIndexOutOfRangeByStore(int index)
        {
            try
            {
                var arr = new int[7];
                arr[index] = 123;
            }
            catch (IndexOutOfRangeException)
            {
                return true;
            }
            return false;
        }
    }
}
