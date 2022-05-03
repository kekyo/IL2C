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
    [TestId("Call")]
    [TestCase("IL2C.ILConverters.Call_Virtual", new[] { "Instance_ToString_System_Object", "ToString" }, IgnoreILErrors = new[] { "ThisMismatch" })]
    [TestCase("CallTest", new[] { "Instance_ToString_IL2C_ILConverters_Call", "ToString" })]
    public sealed class Call_Virtual
    {
        // NOTE: Splitted these tests from Call class because it contains virtual method, cause undefined ToString function in this case.
        // The TestFramework generates translated source code only required (declared in TestCase attribute) methods.
        // Another case for Call class, there aren't contained ToString method at attribute.

        public override string ToString()
        {
            return "CallTest";
        }

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern string Instance_ToString_System_Object();

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern string Instance_ToString_IL2C_ILConverters_Call();
    }
}
