using System;
using System.Runtime.CompilerServices;

namespace IL2C.ILConverters
{
    [Case((byte)123, "Int32", 123)]
    [Case(unchecked ((byte)456), "Int32", 456)]
    [Case((byte)123, "Int64", 123L)]
    [Case(unchecked((byte)456), "Int64", 456L)]
    [Case((byte)123, "IntPtr", 123)]
    [Case(unchecked((byte)456), "IntPtr", 456)]
    [Case((byte)123, "Single", 123.45f)]
    [Case(unchecked((byte)456), "Single", 456.78f)]
    [Case((byte)123, "Double", 123.45)]
    [Case(unchecked((byte)456), "Double", 456.78)]
    public sealed class Conv_u1
    {
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern byte Int32(int value);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern byte Int64(long value);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern byte IntPtr(IntPtr value);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern byte Single(float value);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern byte Double(double value);
    }
}
