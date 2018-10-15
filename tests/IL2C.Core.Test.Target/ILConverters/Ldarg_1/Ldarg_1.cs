using System.Runtime.CompilerServices;

namespace IL2C.ILConverters
{
    [Case(true, "Boolean", 123, false)]
    [Case(false, "Boolean", 123, true)]
    [Case((byte)(byte.MaxValue - 1), "Byte", 123, byte.MaxValue)]
    [Case((short)(short.MaxValue - 1), "Int16", 123, short.MaxValue)]
    [Case(int.MaxValue - 1, "Int32", 123, int.MaxValue)]
    [Case(long.MaxValue - 1, "Int64", 123, long.MaxValue)]
    [Case((sbyte)(sbyte.MaxValue - 1), "SByte", 123, sbyte.MaxValue)]
    [Case((ushort)(ushort.MaxValue - 1), "UInt16", 123, ushort.MaxValue)]
    [Case((uint)(uint.MaxValue - 1), "UInt32", 123, uint.MaxValue)]
    [Case((ulong)(ulong.MaxValue - 1), "UInt64", 123, ulong.MaxValue)]
    [Case((float)((double)123.45f + (double)3.14159274f), "Single", 123, 123.45f)]
    [Case(123.45 + 3.1415926535897931, "Double", 123, 123.45)]
    [Case('B', "Char", 123, 'A')]
    [Case("ABCD", "String", 123, "ABC")]
    public sealed class Ldarg_1
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
        public static extern char Char(int arg0, char ch);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern string String(int arg0, string v);
    }
}
