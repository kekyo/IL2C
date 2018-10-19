using System;
using System.Runtime.CompilerServices;

namespace IL2C.ILConverters
{
    [TestCase(246, "Mul2Int32", 123)]
    [TestCase("ABCABC", "Mul2String", "ABC")]
    public sealed class Dup
    {
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern int Mul2Int32(int value);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern string Mul2String(string value);
    }
}
