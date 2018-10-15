using System;
using System.Runtime.CompilerServices;

namespace IL2C.ILConverters
{
    [Case(true, "Boolean", false)]
    [Case(false, "Boolean", true)]
    [Case((byte)(byte.MaxValue - 1), "Byte", byte.MaxValue)]
    [Case((short)(short.MaxValue - 1), "Int16", short.MaxValue)]
    [Case(int.MaxValue - 1, "Int32", int.MaxValue)]
    [Case(long.MaxValue - 1, "Int64", long.MaxValue)]
    [Case((sbyte)(sbyte.MaxValue - 1), "SByte", sbyte.MaxValue)]
    [Case((ushort)(ushort.MaxValue - 1), "UInt16", ushort.MaxValue)]
    [Case((uint)(uint.MaxValue - 1), "UInt32", uint.MaxValue)]
    [Case((ulong)(ulong.MaxValue - 1), "UInt64", ulong.MaxValue)]
    [Case(int.MaxValue - 1, typeof(IntPtr), "IntPtr", typeof(IntPtr), int.MaxValue)]
    [Case(uint.MaxValue - 1, typeof(UIntPtr), "UIntPtr", typeof(UIntPtr), uint.MaxValue)]
    [Case((float)((double)123.45f + (double)3.14159274f), "Single", 123.45f)]
    [Case(123.45 + 3.1415926535897931, "Double", 123.45)]
    [Case('B', "Char", 'A')]
    [Case("ABCD", "String", "ABC")]
    public sealed class Ldarg_0
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
        public static extern sbyte SByte(sbyte num);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern ushort UInt16(ushort num);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern uint UInt32(uint num);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern ulong UInt64(ulong num);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern IntPtr IntPtr(IntPtr num);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern UIntPtr UIntPtr(UIntPtr num);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern float Single(float num);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern double Double(double num);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern char Char(char ch);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern string String(string v);
    }
}
