using System.Runtime.CompilerServices;

namespace IL2C.ILConverters
{
    [Case(true, "Boolean", 123, 45, false)]
    [Case(false, "Boolean", 123, 45, true)]
    [Case((byte)(byte.MaxValue - 1), "Byte", 123, 45, byte.MaxValue)]
    [Case((short)(short.MaxValue - 1), "Int16", 123, 45, short.MaxValue)]
    [Case(int.MaxValue - 1, "Int32", 123, 45, int.MaxValue)]
    [Case(long.MaxValue - 1, "Int64", 123, 45, long.MaxValue)]
    [Case((float)223.45, "Single", 123, 45, (float)123.45)]
    [Case(223.45, "Double", 123, 45, 123.45)]
    [Case("ABCD", "String", 123, 45, "ABC")]
    public static class Ldarg_2
    {
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern bool Boolean(int arg0, int arg1, bool value);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern byte Byte(int arg0, int arg1, byte num);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern short Int16(int arg0, int arg1, short num);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern int Int32(int arg0, int arg1, int num);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern long Int64(int arg0, int arg1, long num);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern float Single(int arg0, int arg1, float num);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern double Double(int arg0, int arg1, double num);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern string String(int arg0, int arg1, string v);
    }
}
