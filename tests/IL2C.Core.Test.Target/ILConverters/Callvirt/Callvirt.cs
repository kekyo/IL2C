using System;
using System.Runtime.CompilerServices;

namespace IL2C.ILConverters
{
    [TestCase("CallvirtTest", new[] { "Instance_ToString_System_Object", "ToString" })]
    [TestCase("CallvirtTest", new[] { "Instance_ToString_IL2C_ILConverters_Callvirt", "ToString" })]
    public sealed class Callvirt
    {
        public override string ToString()
        {
            return "CallvirtTest";
        }

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern string Instance_ToString_System_Object();

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern string Instance_ToString_IL2C_ILConverters_Callvirt();
    }
}
