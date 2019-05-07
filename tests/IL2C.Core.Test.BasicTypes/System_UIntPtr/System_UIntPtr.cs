using System;
using System.Runtime.CompilerServices;

namespace IL2C.BasicTypes
{
    [TestCase(true, "IsValueType")]
    [TestCase(4, "SizeOf", Assert = TestCaseAsserts.IgnoreValidateInvokeResult)]    // Unit test environment is unknown, gcc is 32bit
    [TestCase("4294967295", "ToString", uint.MaxValue)]
    [TestCase("0", "ToString", uint.MinValue)]
    public sealed class System_UIntPtr
    {
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern bool IsValueType();

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern int SizeOf();

        public static string ToString(UIntPtr value)
        {
            return value.ToString();
        }
    }
}
