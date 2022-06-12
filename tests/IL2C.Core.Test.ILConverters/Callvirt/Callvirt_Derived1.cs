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
    [TestId("Callvirt")]
    public sealed class Callvirt_Derived1
    {
        public override string ToString()
        {
            return "CallvirtTest";
        }

        [TestCase("CallvirtTest", new[] { "Derived1_ToString_System_Object", "ToString" })]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern string Derived1_ToString_System_Object();

        [TestCase("CallvirtTest", new[] { "Derived1_ToString_IL2C_ILConverters_Callvirt", "ToString" })]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern string Derived1_ToString_IL2C_ILConverters_Callvirt();
    }
}
