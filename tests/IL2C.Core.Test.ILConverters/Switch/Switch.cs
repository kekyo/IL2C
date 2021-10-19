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
    [TestCase((string)"0", "TestSwitch", (int)0)]
    [TestCase((string)"1", "TestSwitch", (int)1)]
    [TestCase((string)"2", "TestSwitch", (int)2)]
    [TestCase((string)"3", "TestSwitch", (int)3)]
    [TestCase((string)"Out of range", "TestSwitch", (int)-1)]
    [TestCase((string)"Out of range", "TestSwitch", (int)4)]
    [TestCase((string)"Out of range", "TestSwitch", (int)int.MinValue)]
    [TestCase((string)"Out of range", "TestSwitch", (int)int.MaxValue)]
    public sealed class Switch
    {
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern string TestSwitch(int v);
    }
}
