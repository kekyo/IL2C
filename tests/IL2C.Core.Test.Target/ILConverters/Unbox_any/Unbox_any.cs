using System;
using System.Runtime.CompilerServices;

namespace IL2C.ILConverters
{
    [TestCase(true, new[] { "Int32", "Unbox_Int32" }, 123)]
    [TestCase(124, "FromValueType", 123)]
    public sealed class Unbox_any
    {
        [MethodImpl(MethodImplOptions.ForwardRef)]
        private static extern int Unbox_Int32(object value);

        public static bool Int32(object value)
        {
            var ub = Unbox_Int32(value);
            return ub == 123;
        }

        // https://github.com/kekyo/IL2C/issues/37
        public static int FromValueType(int value)
        {
            ValueType v = value + 1;    // boxed
            return (int)v;
        }
    }
}
