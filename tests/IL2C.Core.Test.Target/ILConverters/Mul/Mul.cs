using System;
using System.Runtime.CompilerServices;

namespace IL2C.ILConverters
{
    [Case(288, "Int32_Int32", 12, 24)]
    [Case(288, typeof(IntPtr), "IntPtr_IntPtr", typeof(IntPtr), 12, typeof(IntPtr), 24)]
    [Case(288, typeof(IntPtr), "IntPtr_Int32", typeof(IntPtr), 12, typeof(int), 24)]
    [Case(288L, "Int64_Int64", 12L, 24L)]
    [Case(288L, typeof(long), "Int64_IntPtr", typeof(long), 12L, typeof(IntPtr), 24)]
    [Case(288L, "Int64_Int32", 12L, 24)]
    [Case(12.12 * 34.34, "Double_Double", 12.12, 34.34)]
    // It cases isn't written in MSDN document, but .NET 4.0 CLR can handle.
    [Case(12.12 * 34, "Double_Int32", 12.12, 34)]
    // These cases are declared at ".NET IL Assembler" Serge Lidin's book.
    // It can handle by IL2C, but .NET 4.0 CLR causes InvalidProgramException.
    //[Case(12.12 * 34, typeof(double), "Double_IntPtr", typeof(double), 12.12, typeof(IntPtr), 34)]
    //[Case(12.12 * 34L, "Double_Int64", 12.12, 34L)]
    public sealed class Mul
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
