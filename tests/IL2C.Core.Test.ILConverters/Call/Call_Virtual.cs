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
    public sealed class Call_Virtual
    {
        // NOTE: Splitted these tests from Call class because it contains virtual method, cause undefined ToString function in this case.
        // The TestFramework generates translated source code only required (declared in TestCase attribute) methods.
        // Another case for Call class, there aren't contained ToString method at attribute.

        public override string ToString()
        {
            return "CallTest";
        }

        [TestCase("IL2C.ILConverters.Call_Virtual", new[] { "Instance_ToString_System_Object", "ToString" }, IgnoreILErrors = new[] { "ThisMismatch" })]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern string Instance_ToString_System_Object();

        [TestCase("CallTest", new[] { "Instance_ToString_IL2C_ILConverters_Call", "ToString" })]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern string Instance_ToString_IL2C_ILConverters_Call();
    }
}
