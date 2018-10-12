using System.Runtime.CompilerServices;

namespace IL2C.ILConverters
{
    [Case("Boolean", true, 123, false)]
    [Case("Boolean", false, 123, true)]
    [Case("Byte", (byte)(byte.MaxValue - 1), 123, byte.MaxValue)]
    [Case("Int16", (short)(short.MaxValue - 1), 123, short.MaxValue)]
    [Case("Int32", int.MaxValue - 1, 123, int.MaxValue)]
    [Case("Int64", long.MaxValue - 1, 123, long.MaxValue)]
    [Case("Single", (float)223.45, 123, (float)123.45)]
    [Case("Double", 223.45, 123, 123.45)]
    [Case("String", "ABCD", 123, "ABC")]
    public static class Ldarg_1
    {
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern bool Boolean(int arg0, bool value);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern byte Byte(int arg0, byte num);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern short Int16(int arg0, short num);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern int Int32(int arg0, int num);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern long Int64(int arg0, long num);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern float Single(int arg0, float num);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern double Double(int arg0, double num);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern string String(int arg0, string v);
    }
}
