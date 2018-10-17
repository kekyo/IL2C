using System;
using System.Runtime.CompilerServices;

namespace IL2C.ILConverters
{
    [Case(12345, "Int32", 12345)]
    [Case(12345, "Int64", 12345L)]
    [Case(12345, "IntPtr", 12345)]
    [Case(12345, "Single", 12345.67f)]
    [Case(12345, "Double", 12345.67)]
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
