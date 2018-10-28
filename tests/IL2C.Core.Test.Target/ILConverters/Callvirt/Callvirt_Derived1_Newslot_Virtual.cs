using System;
using System.Runtime.CompilerServices;

namespace IL2C.ILConverters
{
    [TestId("Callvirt")]
    [TestCase("IL2C.ILConverters.Callvirt_Derived1_Newslot_Virtual", new[] { "Derived1_Newslot_Virtual_ToString_System_Object", "ToString" })]
    [TestCase("CallvirtTest", new[] { "Derived1_Newslot_Virtual_ToString_IL2C_ILConverters_Callvirt", "ToString" })]
    public class Callvirt_Derived1_Newslot_Virtual
    {
        public new virtual string ToString()
        {
            return "CallvirtTest";
        }

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern string Derived1_Newslot_Virtual_ToString_System_Object();

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern string Derived1_Newslot_Virtual_ToString_IL2C_ILConverters_Callvirt();
    }
}
