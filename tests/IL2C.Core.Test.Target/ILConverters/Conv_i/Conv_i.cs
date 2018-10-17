using System;
using System.Runtime.CompilerServices;

namespace IL2C.ILConverters
{
    [Case(12345, typeof(IntPtr), "Int32", typeof(int), 12345)]
    [Case(12345, typeof(IntPtr), "Int64", typeof(long), 12345L)]
    [Case(12345, typeof(IntPtr), "IntPtr", typeof(IntPtr), 12345)]
    [Case(12345, typeof(IntPtr), "Single", typeof(float), 12345.67f)]
    [Case(12345, typeof(IntPtr), "Double", typeof(double), 12345.67)]
    public sealed class Conv_i
    {
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern IntPtr Int32(int value);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern IntPtr Int64(long value);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern IntPtr IntPtr(IntPtr value);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern IntPtr Single(float value);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern IntPtr Double(double value);
    }
}
