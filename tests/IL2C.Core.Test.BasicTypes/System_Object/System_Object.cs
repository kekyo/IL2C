using System.Runtime.CompilerServices;

namespace IL2C.BasicTypes
{
    [TestCase(true, "IsValueType", 123)]
    [TestCase(false, "IsValueType", "ABC")]
    [TestCase("System.Int32", "ToString", int.MaxValue)]
    [TestCase("System.String", "ToString", "ABC")]
    [TestCase("System.Int32", "GetType", int.MaxValue)]
    [TestCase("System.String", "GetType", "ABC")]
    [TestCase(true, "RefEquals_Same")]
    [TestCase(false, "RefEquals_NotSame")]
    [TestCase(false, "RefEquals", "ABC", "DEF")]
    [TestCase(false, "RefEquals", 123, "ABC")]
    [TestCase(false, "RefEquals", null, "ABC")]
    [TestCase(true, "RefEquals", null, null)]
    public sealed class System_Object
    {
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern bool IsValueType(object value);

        // This is non virtual calling test.
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern string ToString(object value);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern string GetType(object value);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern bool RefEquals_Same();

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern bool RefEquals_NotSame();

        public static bool RefEquals(object value1, object value2)
        {
            return object.ReferenceEquals(value1, value2);
        }
    }
}
