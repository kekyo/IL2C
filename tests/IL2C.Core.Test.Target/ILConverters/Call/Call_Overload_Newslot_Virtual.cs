using System;
using System.Runtime.CompilerServices;

namespace IL2C.ILConverters
{
    [TestId("Call")]
    [TestCase("IL2C.ILConverters.Call_Overload_Newslot_Virtual", new[] { "Instance_Overload_Newslot_Virtual_ToString_System_Object", "ToString" })]
    [TestCase("CallTestABC", new[] { "Instance_Overload_Newslot_Virtual_ToString_IL2C_ILConverters_Call", "ToString" }, "ABC")]
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

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern string Instance_Overload_Newslot_Virtual_ToString_System_Object();

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern string Instance_Overload_Newslot_Virtual_ToString_NoArgument_IL2C_ILConverters_Call();

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern string Instance_Overload_Newslot_Virtual_ToString_IL2C_ILConverters_Call(string value);
    }
}
