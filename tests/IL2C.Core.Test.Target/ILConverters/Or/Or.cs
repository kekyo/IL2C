using System;
using System.Runtime.CompilerServices;

namespace IL2C.ILConverters
{
    [Case(0x12345678 | 0x55555555, "Int32_Int32", 0x12345678, 0x55555555)]
    [Case(0x12345678 | 0x55555555, typeof(IntPtr), "Int32_IntPtr", typeof(int), 0x12345678, typeof(IntPtr), 0x55555555)]
    [Case(0x123456789abcdef | 0x55555555aaaaaaaa, "Int64_Int64", 0x123456789abcdef, 0x55555555aaaaaaaa)]
    [Case(0x12345678 | 0x55555555, typeof(IntPtr), "IntPtr_Int32", typeof(IntPtr), 0x12345678, typeof(int), 0x55555555)]
    [Case(0x12345678 | 0x55555555, typeof(IntPtr), "IntPtr_IntPtr", typeof(IntPtr), 0x12345678, typeof(IntPtr), 0x55555555)]
    public sealed class Or
    {
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern int Int32_Int32(int lhs, int rhs);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern IntPtr Int32_IntPtr(int lhs, IntPtr rhs);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern long Int64_Int64(long lhs, long rhs);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern IntPtr IntPtr_Int32(IntPtr lhs, int rhs);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern IntPtr IntPtr_IntPtr(IntPtr lhs, IntPtr rhs);
    }
}
