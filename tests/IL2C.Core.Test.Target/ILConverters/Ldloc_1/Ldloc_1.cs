using System;
using System.Runtime.CompilerServices;

namespace IL2C.ILConverters
{
    [Case(true, "True")]
    [Case(false, "False")]
    [Case(byte.MaxValue, "Byte")]
    [Case(short.MaxValue, "Int16")]
    [Case(int.MaxValue, "Int32")]
    [Case(long.MaxValue, "Int64")]
    [Case(sbyte.MaxValue, "SByte")]
    [Case(ushort.MaxValue, "UInt16")]
    [Case(uint.MaxValue, "UInt32")]
    [Case(ulong.MaxValue, "UInt64")]
    [Case(int.MaxValue, typeof(IntPtr), "IntPtr")]
    [Case(uint.MaxValue, typeof(UIntPtr), "UIntPtr")]
    [Case(3.14159274f, "Single")]
    [Case(3.1415926535897931, "Double")]
    [Case('A', "Char")]
    [Case("ABC", "String")]
    public sealed class Ldloc_1
    {
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern bool True();

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern bool False();

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern byte Byte();

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern short Int16();

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern int Int32();

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern long Int64();

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern sbyte SByte();

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern ushort UInt16();

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern uint UInt32();

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern ulong UInt64();

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern IntPtr IntPtr();

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern UIntPtr UIntPtr();

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern float Single();

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern double Double();

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern char Char();

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern string String();
    }
}
