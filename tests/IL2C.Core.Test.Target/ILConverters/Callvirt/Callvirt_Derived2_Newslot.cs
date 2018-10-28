using System;
using System.Runtime.CompilerServices;

namespace IL2C.ILConverters
{
    public abstract class Callvirt_Derived2_Newslot_Base
    {
        protected Callvirt_Derived2_Newslot_Base()
        {
        }

        public new virtual string ToString()
        {
            return "Callvirt_Derived_Base";
        }
    }

    [TestId("Callvirt")]
    [TestCase("IL2C.ILConverters.Callvirt_Derived2_Newslot", new[] { "Derived2_Newslot_ToString_System_Object", "ToString" }, IncludeBaseTypes = true)]
    [TestCase("CallvirtTest", new[] { "Derived2_Newslot_ToString_IL2C_ILConverters_Callvirt_Base", "ToString" }, IncludeBaseTypes = true)]
    [TestCase("CallvirtTest", new[] { "Derived2_Newslot_ToString_IL2C_ILConverters_Callvirt", "ToString" }, IncludeBaseTypes = true)]
    public sealed class Callvirt_Derived2_Newslot : Callvirt_Derived2_Newslot_Base
    {
        public override string ToString()
        {
            return "CallvirtTest";
        }

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern string Derived2_Newslot_ToString_System_Object();

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern string Derived2_Newslot_ToString_IL2C_ILConverters_Callvirt_Base();

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern string Derived2_Newslot_ToString_IL2C_ILConverters_Callvirt();
    }
}
