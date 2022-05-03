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
    [TestCase("IL2C.ILConverters.Call_Overload_Virtual", new[] { "Instance_Overload_Virtual_ToString_System_Object", "ToString" }, IgnoreILErrors = new[] { "ThisMismatch" })]
    [TestCase("CallTest", new[] { "Instance_Overload_Virtual_ToString_NoArgument_IL2C_ILConverters_Call", "ToString" })]
    [TestCase("CallTestABC", new[] { "Instance_Overload_Virtual_ToString_IL2C_ILConverters_Call", "ToString" }, "ABC")]
    public class Call_Overload_Virtual
    {
        public override string ToString()
        {
            return "CallTest";
        }

        public string ToString(string value)
        {
            return "CallTest" + value;
        }

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern string Instance_Overload_Virtual_ToString_System_Object();

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern string Instance_Overload_Virtual_ToString_NoArgument_IL2C_ILConverters_Call();

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern string Instance_Overload_Virtual_ToString_IL2C_ILConverters_Call(string value);
    }
}
