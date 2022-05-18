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
    public abstract class Callvirt_Derived2_Base
    {
        protected Callvirt_Derived2_Base()
        {
        }

        public override string ToString()
        {
            return "Callvirt_Derived_Base";
        }
    }

    [TestId("Callvirt")]
    public sealed class Callvirt_Derived2 : Callvirt_Derived2_Base
    {
        public override string ToString()
        {
            return "CallvirtTest";
        }

        [TestCase("CallvirtTest", new[] { "Derived2_ToString_System_Object", "ToString" }, IncludeBaseTypes = true)]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern string Derived2_ToString_System_Object();

        [TestCase("CallvirtTest", new[] { "Derived2_ToString_IL2C_ILConverters_Callvirt", "ToString" }, IncludeBaseTypes = true)]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern string Derived2_ToString_IL2C_ILConverters_Callvirt();
    }
}
