using System;
using System.Runtime.CompilerServices;

namespace IL2C.ILConverters
{
    [Case(3, "Int32_Int32", 36, 12)]
    [Case(3, typeof(IntPtr), "IntPtr_IntPtr", typeof(IntPtr), 36, typeof(IntPtr), 12)]
    [Case(3, typeof(IntPtr), "IntPtr_Int32", typeof(IntPtr), 36, typeof(int), 12)]
    [Case(3L, "Int64_Int64", 36L, 12L)]
    [Case(3L, typeof(long), "Int64_IntPtr", typeof(long), 36L, typeof(IntPtr), 12)]
    [Case(3L, "Int64_Int32", 36L, 12)]
    [Case(36.36 / 12.12, "Double_Double", 36.36, 12.12)]
    // It cases isn't written in MSDN document, but .NET 4.0 CLR can handle.
    [Case(36.36 / 12, "Double_Int32", 36.36, 12)]
    // These cases are declared at ".NET IL Assembler" Serge Lidin's book.
    // It can handle by IL2C, but .NET 4.0 CLR causes InvalidProgramException.
    //[Case(36.36 / 12, typeof(double), "Double_IntPtr", typeof(double), 36.36, typeof(IntPtr), 12)]
    //[Case(36.36 / 12L, "Double_Int64", 36.36, 12L)]
    public sealed class Div
    {
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern int Int32_Int32(int lhs, int rhs);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern IntPtr IntPtr_IntPtr(IntPtr lhs, IntPtr rhs);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern IntPtr IntPtr_Int32(IntPtr lhs, int rhs);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern long Int64_Int64(long lhs, long rhs);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern long Int64_IntPtr(long lhs, IntPtr rhs);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern long Int64_Int32(long lhs, int rhs);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern double Double_Double(double lhs, double rhs);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern double Double_Int32(double lhs, int rhs);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern double Double_IntPtr(double lhs, IntPtr rhs);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern double Double_Int64(double lhs, long rhs);
    }
}
