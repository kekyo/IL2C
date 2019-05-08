using System;
using System.Runtime.CompilerServices;

namespace IL2C.ILConverters
{
    [TestCase("ABCDEF", "ConcatIfString", "ABC")]
    [TestCase(null, "ConcatIfString", 123)]
    [TestCase(null, "ToStringIfInt32", "ABC")]
    [TestCase("123", "ToStringIfInt32", 123)]
    public sealed class Isinst
    {
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern string ConcatIfString(object value);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern string ToStringIfInt32(object value);
    }
}
