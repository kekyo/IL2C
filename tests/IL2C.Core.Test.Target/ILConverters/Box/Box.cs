using System;
using System.Runtime.CompilerServices;

namespace IL2C.ILConverters
{
    [TestCase("124", new[] { "Int32", "Box_Int32" }, 123)]
    public sealed class Box
    {
        [MethodImpl(MethodImplOptions.ForwardRef)]
        private static extern object Box_Int32(int value);

        public static string Int32(int value)
        {
            return Box_Int32(value + 1).ToString();
        }
    }
}
