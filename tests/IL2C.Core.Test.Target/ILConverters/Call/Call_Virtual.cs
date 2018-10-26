using System;
using System.Runtime.CompilerServices;

namespace IL2C.ILConverters
{
    [TestId("Call")]
    [TestCase("IL2C.ILConverters.Call_Virtual", new[] { "Instance_ToString_System_Object", "ToString" })]
    [TestCase("CallTest", new[] { "Instance_ToString_IL2C_ILConverters_Call", "ToString" })]
    public sealed class Call_Virtual
    {
        // MEMO: Splitted these tests from Call class because it contains virtual method, cause undefined ToString function in this case.
        // The TestFramework generates translated source code only required (declared in TestCase attribute) methods.
        // Another case for Call class, there aren't contained ToString method at attribute.

        public override string ToString()
        {
            return "CallTest";
        }

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern string Instance_ToString_System_Object();

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern string Instance_ToString_IL2C_ILConverters_Call();
    }
}
