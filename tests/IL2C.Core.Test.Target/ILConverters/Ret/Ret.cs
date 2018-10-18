using System;
using System.Runtime.CompilerServices;

namespace IL2C.ILConverters
{
    [Case(123, "Int32Value")]
    [Case("ABC", "StringValue")]
    [Case(null, "NullValue")]
    [Case(123, new[] { "RefIntValue", "Return_RefInt" }, true)]
    [Case(456, new[] { "RefIntValue", "Return_RefInt" }, false)]
    [Case(null, "Void")]
    public sealed class Ret
    {
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern int Int32Value();

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern string StringValue();

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern object NullValue();

        [MethodImpl(MethodImplOptions.ForwardRef)]
        private static extern ref int Return_RefInt(ref int a, ref int b, bool select);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern int RefIntValue(bool select);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern void Void();
    }
}
