using System.Runtime.CompilerServices;

namespace IL2C.ILConverters
{
    [Case("Byte", byte.MaxValue - 1, byte.MaxValue)]
    [Case("Int16", short.MaxValue - 1, short.MaxValue)]
    [Case("Int32", int.MaxValue - 1, int.MaxValue)]
    [Case("Int64", long.MaxValue - 1, long.MaxValue)]
    [Case("String", "ABCD", "ABC")]
    public static class Ldarg_0
    {
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern byte Byte(byte num);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern short Int16(short num);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern int Int32(int num);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern long Int64(long num);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern string String(string str);
    }
}
