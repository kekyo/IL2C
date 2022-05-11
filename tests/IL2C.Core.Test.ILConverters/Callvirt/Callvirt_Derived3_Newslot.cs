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
    public abstract class Callvirt_Derived3_Newslot_Base1
    {
        protected Callvirt_Derived3_Newslot_Base1()
        {
        }

        public override string ToString()
        {
            return "Callvirt_Derived_Base1";
        }
    }

    public abstract class Callvirt_Derived3_Newslot_Base2 : Callvirt_Derived3_Newslot_Base1
    {
        protected Callvirt_Derived3_Newslot_Base2()
        {
        }

        public new string ToString()
        {
            return "Callvirt_Derived_Base2";
        }
    }

    [TestId("Callvirt")]
    [TestCase("Callvirt_Derived_Base1", new[] { "Derived3_Newslot_ToString_System_Object", "ToString" }, IncludeBaseTypes = true)]
    [TestCase("Callvirt_Derived_Base1", new[] { "Derived3_Newslot_ToString_IL2C_ILConverters_Callvirt_Base1", "ToString" }, IncludeBaseTypes = true)]
    [TestCase("Callvirt_Derived_Base2", new[] { "Derived3_Newslot_ToString_IL2C_ILConverters_Callvirt_Base2", "ToString" }, IncludeBaseTypes = true)]
    [TestCase("CallvirtTest", new[] { "Derived3_Newslot_ToString_IL2C_ILConverters_Callvirt", "ToString" }, IncludeBaseTypes = true)]
    public sealed class Callvirt_Derived3_Newslot : Callvirt_Derived3_Newslot_Base2
    {
        public new string ToString()
        {
            return "CallvirtTest";
        }

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern string Derived3_Newslot_ToString_System_Object();

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern string Derived3_Newslot_ToString_IL2C_ILConverters_Callvirt_Base1();

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern string Derived3_Newslot_ToString_IL2C_ILConverters_Callvirt_Base2();

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern string Derived3_Newslot_ToString_IL2C_ILConverters_Callvirt();
    }
}
