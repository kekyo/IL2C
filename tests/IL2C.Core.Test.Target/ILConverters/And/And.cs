using System;
using System.Runtime.CompilerServices;

namespace IL2C.ILConverters
{
    [Case(288, "Int32_Int32", 12, 24)]
    [Case(288, typeof(IntPtr), "Int32_IntPtr", typeof(int), 12, typeof(IntPtr), 24)]
    [Case(288L, "Int64_Int64", 12L, 24L)]
    [Case(288, typeof(IntPtr), "IntPtr_Int32", typeof(IntPtr), 12, typeof(int), 24)]
    [Case(288, typeof(IntPtr), "IntPtr_IntPtr", typeof(IntPtr), 12, typeof(IntPtr), 24)]
    public sealed class And
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
