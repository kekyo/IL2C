using System.Runtime.CompilerServices;

namespace IL2C.RuntimeTypes
{
    [TestCase(true, "IsValueType", 123)]
    [TestCase(false, "IsValueType", "ABC")]
    //[TestCase("System.Int32", "ToString", int.MaxValue)]  // TODO: we have to strict implementation for System_Object_ToString.
    //[TestCase("System.String", "ToString", "ABC")]
    public sealed class System_Object
    {
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern bool IsValueType(object value);

        // This is non virtual calling test.
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern string ToString(object value);
    }
}
