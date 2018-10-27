using System;
using System.Runtime.CompilerServices;

namespace IL2C.ILConverters
{
    public abstract class Callvirt_Derived_Base
    {
        protected Callvirt_Derived_Base()
        {
        }

        public override string ToString()
        {
            return "Callvirt_Derived_Base";
        }
    }

    [TestId("Callvirt")]
    [TestCase("CallvirtTest", new[] { "Derived2_ToString_System_Object", "ToString" }, IncludeBaseTypes = true)]
    [TestCase("CallvirtTest", new[] { "Derived2_ToString_IL2C_ILConverters_Callvirt", "ToString" }, IncludeBaseTypes = true)]
    public sealed class Callvirt_Derived2 : Callvirt_Derived_Base
    {
        public override string ToString()
        {
            return "CallvirtTest";
        }

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern string Derived2_ToString_System_Object();

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern string Derived2_ToString_IL2C_ILConverters_Callvirt();
    }
}
