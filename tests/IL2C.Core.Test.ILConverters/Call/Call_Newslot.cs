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
    public sealed class Call_Newslot
    {
        public new string ToString()
        {
            return "CallTest";
        }

        [TestCase("IL2C.ILConverters.Call_Newslot", new[] { "Instance_Newslot_ToString_System_Object", "ToString" })]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern string Instance_Newslot_ToString_System_Object();

        [TestCase("CallTest", new[] { "Instance_Newslot_ToString_IL2C_ILConverters_Call", "ToString" })]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern string Instance_Newslot_ToString_IL2C_ILConverters_Call();
    }
}
