using System;
using System.Runtime.CompilerServices;

namespace IL2C.ILConverters
{
    [Case((ushort)12345, "Int32", 12345)]
    [Case(unchecked ((ushort)45678), "Int32", 45678)]
    [Case((ushort)12345, "Int64", 12345L)]
    [Case(unchecked((ushort)45678), "Int64", 45678L)]
    [Case((ushort)12345, typeof(ushort), "IntPtr", typeof(IntPtr), 12345)]
    [Case(unchecked((ushort)45678), typeof(ushort), "IntPtr", typeof(IntPtr), 45678)]
    [Case((ushort)12345, "Single", 12345.67f)]
    [Case(unchecked((ushort)45678), "Single", 45678.91f)]
    [Case((ushort)12345, "Double", 12345.67)]
    [Case(unchecked((ushort)45678), "Double", 45678.91)]
    public sealed class Conv_u2
    {
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern ushort Int32(int value);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern ushort Int64(long value);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern ushort IntPtr(IntPtr value);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern ushort Single(float value);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern ushort Double(double value);
    }
}
