using System;
using System.Runtime.CompilerServices;

namespace IL2C.ILConverters
{
    [TestCase("123ABC", new[] { "NonVirtual_Callvirt", "NonVirtual" }, 123, "ABC")]
    public sealed class Callvirt
    {
        private string NonVirtual(int value1, string value2)
        {
            return value1 + value2;
        }

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern string NonVirtual_Callvirt(int value1, string value2);
    }
}
