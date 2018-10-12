using System.Runtime.CompilerServices;

namespace IL2C.ILConverters
{
    [Case(true, "Boolean", false)]
    [Case(false, "Boolean", true)]
    [Case((byte)(byte.MaxValue - 1), "Byte", byte.MaxValue)]
    [Case((short)(short.MaxValue - 1), "Int16", short.MaxValue)]
    [Case(int.MaxValue - 1, "Int32", int.MaxValue)]
    [Case(long.MaxValue - 1, "Int64", long.MaxValue)]
    [Case((float)223.45, "Single", (float)123.45)]
    [Case(223.45, "Double", 123.45)]
    [Case("ABCD", "String", "ABC")]
    public static class Ldarg_0
    {
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern bool Boolean(bool value);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern byte Byte(byte num);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern short Int16(short num);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern int Int32(int num);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern long Int64(long num);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern float Single(float num);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern double Double(double num);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern string String(string v);
    }
}
