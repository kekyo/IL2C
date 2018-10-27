using System;
using System.Runtime.CompilerServices;

namespace IL2C.ILConverters
{
    [TestId("Call")]
    [TestCase("IL2C.ILConverters.Call_Newslot_Virtual", new[] { "Instance_Newslot_Virtual_ToString_System_Object", "ToString" })]
    [TestCase("CallTest", new[] { "Instance_Newslot_Virtual_ToString_IL2C_ILConverters_Call", "ToString" })]
    public class Call_Newslot_Virtual
    {
        public new virtual string ToString()
        {
            return "CallTest";
        }

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern string Instance_Newslot_Virtual_ToString_System_Object();

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern string Instance_Newslot_Virtual_ToString_IL2C_ILConverters_Call();
    }
}
