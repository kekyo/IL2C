using System;
using System.Runtime.CompilerServices;

namespace IL2C.RuntimeTypes
{
    [TestCase(true, "IsValueType")]
    [TestCase(4, "SizeOf", Assert = TestCaseAsserts.IgnoreValidateInvokeResult)]    // Unit test environment is unknown, gcc is 32bit
    [TestCase("2147483647", "ToString", int.MaxValue)]
    [TestCase("-2147483648", "ToString", int.MinValue)]
    public sealed class System_IntPtr
    {
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern bool IsValueType();

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern int SizeOf();

        public static string ToString(IntPtr value)
        {
            return value.ToString();
        }
    }
}
