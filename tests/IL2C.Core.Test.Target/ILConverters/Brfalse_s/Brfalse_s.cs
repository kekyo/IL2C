using System;
using System.Runtime.CompilerServices;

namespace IL2C.ILConverters
{
    [TestCase("ABC", "FlagValue", true)]
    [TestCase("DEF", "FlagValue", false)]
    [TestCase("ABC", "Int32Value", 100)]
    [TestCase("DEF", "Int32Value", 0)]
    [TestCase("ABC", "Int32Value", -100)]
    [TestCase("ABC", "IntPtrValue", 100)]
    [TestCase("DEF", "IntPtrValue", 0)]
    [TestCase("ABC", "IntPtrValue", -100)]
    [TestCase("ABC", "ObjectValue", "")]
    [TestCase("DEF", "ObjectValue", new object[] { null })]
    public sealed class Brfalse_s
    {
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern string FlagValue(bool v);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern string Int32Value(int v);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern string IntPtrValue(IntPtr v);
    }
}
