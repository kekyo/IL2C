////////////////////////////////////////////////////////////////////////////
//
// IL2C - A translator for ECMA-335 CIL/MSIL to C language.
// Copyright (c) Kouji Matsui (@kozy_kekyo, @kekyo@mastodon.cloud)
//
// Licensed under Apache-v2: https://opensource.org/licenses/Apache-2.0
//
////////////////////////////////////////////////////////////////////////////

using System;
using System.Runtime.CompilerServices;

namespace IL2C.ILConverters
{
    public abstract class Callvirt_Derived2_Newslot_Base
    {
        protected Callvirt_Derived2_Newslot_Base()
        {
        }

        public new string ToString()
        {
            return "Callvirt_Derived_Base";
        }
    }

    [TestId("Callvirt")]
    public sealed class Callvirt_Derived2_Newslot : Callvirt_Derived2_Newslot_Base
    {
        public new string ToString()
        {
            return "CallvirtTest";
        }

        [TestCase("IL2C.ILConverters.Callvirt_Derived2_Newslot", new[] { "Derived2_Newslot_ToString_System_Object", "ToString" }, IncludeBaseTypes = true)]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern string Derived2_Newslot_ToString_System_Object();

        [TestCase("Callvirt_Derived_Base", new[] { "Derived2_Newslot_ToString_IL2C_ILConverters_Callvirt_Base", "ToString" }, IncludeBaseTypes = true)]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern string Derived2_Newslot_ToString_IL2C_ILConverters_Callvirt_Base();

        [TestCase("CallvirtTest", new[] { "Derived2_Newslot_ToString_IL2C_ILConverters_Callvirt", "ToString" }, IncludeBaseTypes = true)]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern string Derived2_Newslot_ToString_IL2C_ILConverters_Callvirt();
    }
}
