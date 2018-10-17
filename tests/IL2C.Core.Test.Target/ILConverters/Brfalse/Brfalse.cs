using System;
using System.Runtime.CompilerServices;

namespace IL2C.ILConverters
{
    [Case("ABC", "FlagValue", true)]
    [Case("DEF", "FlagValue", false)]
    [Case("ABC", "Int32Value", 100)]
    [Case("DEF", "Int32Value", 0)]
    [Case("ABC", "Int32Value", -100)]
    public sealed class Brfalse
    {
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern string FlagValue(bool v);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern string Int32Value(int v);
    }
}
