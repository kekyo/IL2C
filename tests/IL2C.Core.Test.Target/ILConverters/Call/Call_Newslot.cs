using System;
using System.Runtime.CompilerServices;

namespace IL2C.ILConverters
{
    [TestId("Call")]
    [TestCase("IL2C.ILConverters.Call_Newslot", new[] { "Instance_Newslot_ToString_System_Object", "ToString" })]
    [TestCase("CallTest", new[] { "Instance_Newslot_ToString_IL2C_ILConverters_Call", "ToString" })]
    public sealed class Call_Newslot
    {
        public new string ToString()
        {
            return "CallTest";
        }

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern string Instance_Newslot_ToString_System_Object();

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern string Instance_Newslot_ToString_IL2C_ILConverters_Call();
    }
}
