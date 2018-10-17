using System;
using System.Runtime.CompilerServices;

namespace IL2C.ILConverters
{
    [Case("ABC", "FlagValue", true)]
    [Case("DEF", "FlagValue", false)]
    [Case("ABC", "Int32Value", 100)]
    [Case("DEF", "Int32Value", 0)]
    [Case("ABC", "Int32Value", -100)]
    [Case("ABC", "IntPtrValue", 100)]
    [Case("DEF", "IntPtrValue", 0)]
    [Case("ABC", "IntPtrValue", -100)]
    [Case("ABC", "ObjectValue", "")]
    [Case("DEF", "ObjectValue", new object[] { null })]
    public sealed class Brtrue
    {
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern string FlagValue(bool v);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern string Int32Value(int v);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern string IntPtrValue(IntPtr v);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern string ObjectValue(object v);
    }
}
