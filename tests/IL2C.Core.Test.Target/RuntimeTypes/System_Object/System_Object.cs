using System.Runtime.CompilerServices;

namespace IL2C.RuntimeTypes
{
    [TestCase(true, "IsValueType", 123)]
    [TestCase(false, "IsValueType", "ABC")]
    [TestCase("System.Int32", "ToString", int.MaxValue)]
    [TestCase("System.String", "ToString", "ABC")]
    [TestCase("System.Int32", "GetType", int.MaxValue)]
    [TestCase("System.String", "GetType", "ABC")]
    public sealed class System_Object
    {
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern bool IsValueType(object value);

        // This is non virtual calling test.
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern string ToString(object value);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern string GetType(object value);
    }
}
