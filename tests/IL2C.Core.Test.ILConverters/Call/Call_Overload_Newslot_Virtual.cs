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
    public class Call_Overload_Newslot_Virtual
    {
        public new virtual string ToString()
        {
            return "CallTest";
        }

        public string ToString(string value)
        {
            return "CallTest" + value;
        }

        [TestCase("IL2C.ILConverters.Call_Overload_Newslot_Virtual", new[] { "Instance_Overload_Newslot_Virtual_ToString_System_Object", "ToString" }, IgnoreILErrors = new[] { "ThisMismatch" })]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern string Instance_Overload_Newslot_Virtual_ToString_System_Object();

        [TestCase("CallTest", new[] { "Instance_Overload_Newslot_Virtual_ToString_NoArgument_IL2C_ILConverters_Call", "ToString" })]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern string Instance_Overload_Newslot_Virtual_ToString_NoArgument_IL2C_ILConverters_Call();

        [TestCase("CallTestABC", new[] { "Instance_Overload_Newslot_Virtual_ToString_IL2C_ILConverters_Call", "ToString" }, "ABC")]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern string Instance_Overload_Newslot_Virtual_ToString_IL2C_ILConverters_Call(string value);
    }
}
