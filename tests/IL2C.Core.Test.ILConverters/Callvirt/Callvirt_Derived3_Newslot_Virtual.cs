using System;
using System.Runtime.CompilerServices;

namespace IL2C.ILConverters
{
    public abstract class Callvirt_Derived3_Newslot_Virtual_Base1
    {
        protected Callvirt_Derived3_Newslot_Virtual_Base1()
        {
        }

        public override string ToString()
        {
            return "Callvirt_Derived_Base1";
        }
    }

    public abstract class Callvirt_Derived3_Newslot_Virtual_Base2 : Callvirt_Derived3_Newslot_Virtual_Base1
    {
        protected Callvirt_Derived3_Newslot_Virtual_Base2()
        {
        }

        public new virtual string ToString()
        {
            return "Callvirt_Derived_Base2";
        }
    }

    [TestId("Callvirt")]
    [TestCase("Callvirt_Derived_Base1", new[] { "Derived3_Newslot_Virtual_ToString_System_Object", "ToString" }, IncludeBaseTypes = true)]
    [TestCase("Callvirt_Derived_Base1", new[] { "Derived3_Newslot_Virtual_ToString_IL2C_ILConverters_Callvirt_Base1", "ToString" }, IncludeBaseTypes = true)]
    [TestCase("CallvirtTest", new[] { "Derived3_Newslot_Virtual_ToString_IL2C_ILConverters_Callvirt_Base2", "ToString" }, IncludeBaseTypes = true)]
    [TestCase("CallvirtTest", new[] { "Derived3_Newslot_Virtual_ToString_IL2C_ILConverters_Callvirt", "ToString" }, IncludeBaseTypes = true)]
    public sealed class Callvirt_Derived3_Newslot_Virtual : Callvirt_Derived3_Newslot_Virtual_Base2
    {
        public override string ToString()
        {
            return "CallvirtTest";
        }

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern string Derived3_Newslot_Virtual_ToString_System_Object();

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern string Derived3_Newslot_Virtual_ToString_IL2C_ILConverters_Callvirt_Base1();

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern string Derived3_Newslot_Virtual_ToString_IL2C_ILConverters_Callvirt_Base2();

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern string Derived3_Newslot_Virtual_ToString_IL2C_ILConverters_Callvirt();
    }
}
