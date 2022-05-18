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
    [TestId("Call")]
    public class Call_Newslot_Virtual
    {
        public new virtual string ToString()
        {
            return "CallTest";
        }

        [TestCase("IL2C.ILConverters.Call_Newslot_Virtual", new[] { "Instance_Newslot_Virtual_ToString_System_Object", "ToString" })]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern string Instance_Newslot_Virtual_ToString_System_Object();

        [TestCase("CallTest", new[] { "Instance_Newslot_Virtual_ToString_IL2C_ILConverters_Call", "ToString" })]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern string Instance_Newslot_Virtual_ToString_IL2C_ILConverters_Call();
    }
}
