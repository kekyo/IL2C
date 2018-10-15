using System;
using System.Runtime.CompilerServices;

namespace IL2C.ILConverters
{
    [Case(true, "Boolean", 123, 45, false)]
    [Case(false, "Boolean", 123, 45, true)]
    [Case((byte)(byte.MaxValue - 1), "Byte", 123, 45, byte.MaxValue)]
    [Case((short)(short.MaxValue - 1), "Int16", 123, 45, short.MaxValue)]
    [Case(int.MaxValue - 1, "Int32", 123, 45, int.MaxValue)]
    [Case(long.MaxValue - 1, "Int64", 123, 45, long.MaxValue)]
    [Case((sbyte)(sbyte.MaxValue - 1), "SByte", 123, 45, sbyte.MaxValue)]
    [Case((ushort)(ushort.MaxValue - 1), "UInt16", 123, 45, ushort.MaxValue)]
    [Case((uint)(uint.MaxValue - 1), "UInt32", 123, 45, uint.MaxValue)]
    [Case((ulong)(ulong.MaxValue - 1), "UInt64", 123, 45, ulong.MaxValue)]
    [Case(int.MaxValue - 1, typeof(IntPtr), "IntPtr", typeof(int), 123, typeof(int), 45, typeof(IntPtr), int.MaxValue)]
    [Case(uint.MaxValue - 1, typeof(UIntPtr), "UIntPtr", typeof(int), 123, typeof(int), 45, typeof(UIntPtr), uint.MaxValue)]
    [Case((float)((double)123.45f + (double)3.14159274f), "Single", 123, 45, 123.45f)]
    [Case(123.45 + 3.1415926535897931, "Double", 123, 45, 123.45)]
    [Case('B', "Char", 123, 45, 'A')]
    [Case("ABCD", "String", 123, 45, "ABC")]
    public sealed class Ldarg_2
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
        public static extern sbyte SByte(int arg0, int arg1, sbyte num);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern ushort UInt16(int arg0, int arg1, ushort num);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern uint UInt32(int arg0, int arg1, uint num);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern ulong UInt64(int arg0, int arg1, ulong num);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern IntPtr IntPtr(int arg0, int arg1, IntPtr num);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern UIntPtr UIntPtr(int arg0, int arg1, UIntPtr num);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern float Single(int arg0, int arg1, float num);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern double Double(int arg0, int arg1, double num);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern char Char(int arg0, int arg1, char ch);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern string String(int arg0, int arg1, string v);
    }
}
