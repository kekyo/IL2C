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
    public abstract class Callvirt_Derived3_Newslot_Virtual_Base1
    {
        protected Callvirt_Derived3_Newslot_Virtual_Base1()
        {
        }

        public override string ToString()
        {
            return "Callvirt_Derived_Base1";
        }
    }

    public abstract class Callvirt_Derived3_Newslot_Virtual_Base2 : Callvirt_Derived3_Newslot_Virtual_Base1
    {
        protected Callvirt_Derived3_Newslot_Virtual_Base2()
        {
        }

        public new virtual string ToString()
        {
            return "Callvirt_Derived_Base2";
        }
    }

    [TestId("Callvirt")]
    public sealed class Callvirt_Derived3_Newslot_Virtual : Callvirt_Derived3_Newslot_Virtual_Base2
    {
        public override string ToString()
        {
            return "CallvirtTest";
        }

        [TestCase("Callvirt_Derived_Base1", new[] { "Derived3_Newslot_Virtual_ToString_System_Object", "ToString" }, IncludeBaseTypes = true)]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern string Derived3_Newslot_Virtual_ToString_System_Object();

        [TestCase("Callvirt_Derived_Base1", new[] { "Derived3_Newslot_Virtual_ToString_IL2C_ILConverters_Callvirt_Base1", "ToString" }, IncludeBaseTypes = true)]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern string Derived3_Newslot_Virtual_ToString_IL2C_ILConverters_Callvirt_Base1();

        [TestCase("CallvirtTest", new[] { "Derived3_Newslot_Virtual_ToString_IL2C_ILConverters_Callvirt_Base2", "ToString" }, IncludeBaseTypes = true)]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern string Derived3_Newslot_Virtual_ToString_IL2C_ILConverters_Callvirt_Base2();

        [TestCase("CallvirtTest", new[] { "Derived3_Newslot_Virtual_ToString_IL2C_ILConverters_Callvirt", "ToString" }, IncludeBaseTypes = true)]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern string Derived3_Newslot_Virtual_ToString_IL2C_ILConverters_Callvirt();
    }
}
