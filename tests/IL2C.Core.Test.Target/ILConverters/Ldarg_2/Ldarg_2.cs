using System.Runtime.CompilerServices;

namespace IL2C.ILConverters
{
    [Case("Boolean", true, 123, 45, false)]
    [Case("Boolean", false, 123, 45, true)]
    [Case("Byte", (byte)(byte.MaxValue - 1), 123, 45, byte.MaxValue)]
    [Case("Int16", (short)(short.MaxValue - 1), 123, 45, short.MaxValue)]
    [Case("Int32", int.MaxValue - 1, 123, 45, int.MaxValue)]
    [Case("Int64", long.MaxValue - 1, 123, 45, long.MaxValue)]
    [Case("Single", (float)223.45, 123, 45, (float)123.45)]
    [Case("Double", 223.45, 123, 45, 123.45)]
    [Case("String", "ABCD", 123, 45, "ABC")]
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
