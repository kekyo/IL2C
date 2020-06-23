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
    public abstract class Callvirt_Derived2_Newslot_Virtual_Base
    {
        protected Callvirt_Derived2_Newslot_Virtual_Base()
        {
        }

        public new virtual string ToString()
        {
            return "Callvirt_Derived_Base";
        }
    }

    [TestId("Callvirt")]
    [TestCase("IL2C.ILConverters.Callvirt_Derived2_Newslot_Virtual", new[] { "Derived2_Newslot_Virtual_ToString_System_Object", "ToString" }, IncludeBaseTypes = true)]
    [TestCase("CallvirtTest", new[] { "Derived2_Newslot_Virtual_ToString_IL2C_ILConverters_Callvirt_Base", "ToString" }, IncludeBaseTypes = true)]
    [TestCase("CallvirtTest", new[] { "Derived2_Newslot_Virtual_ToString_IL2C_ILConverters_Callvirt", "ToString" }, IncludeBaseTypes = true)]
    public class Callvirt_Derived2_Newslot_Virtual : Callvirt_Derived2_Newslot_Virtual_Base
    {
        public override string ToString()
        {
            return "CallvirtTest";
        }

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern string Derived2_Newslot_Virtual_ToString_System_Object();

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern string Derived2_Newslot_Virtual_ToString_IL2C_ILConverters_Callvirt_Base();

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern string Derived2_Newslot_Virtual_ToString_IL2C_ILConverters_Callvirt();
    }
}
