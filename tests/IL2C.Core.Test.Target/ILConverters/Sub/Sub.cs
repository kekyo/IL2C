using System;
using System.Runtime.CompilerServices;

namespace IL2C.ILConverters
{
    [Case(15, "Int32_Int32", 26, 11)]
    [Case(15, typeof(IntPtr), "IntPtr_IntPtr", typeof(IntPtr), 26, typeof(IntPtr), 11)]
    [Case(15, typeof(IntPtr), "IntPtr_Int32", typeof(IntPtr), 26, typeof(int), 11)]
    [Case(15L, "Int64_Int64", 26L, 11L)]
    [Case(15L, typeof(long), "Int64_IntPtr", typeof(long), 26L, typeof(IntPtr), 11)]
    [Case(15L, "Int64_Int32", 26L, 11)]
    [Case(123, new[] { "IntRef_IntPtr", "Sub_IntRef_IntPtr" }, 123)]
    [Case(123, new[] { "IntRef_Int32", "Sub_IntRef_Int32" }, 123)]
    [Case(123.45 - 120.0, "Double_Double", 123.45, 120.0)]
    // It cases isn't written in MSDN document, but .NET 4.0 CLR can handle.
    [Case(123.45 - 120, "Double_Int32", 123.45, 120)]
    // These cases are declared at ".NET IL Assembler" Serge Lidin's book.
    // It can handle by IL2C, but .NET 4.0 CLR causes InvalidProgramException.
    //[Case(123.45 - 120, typeof(double), "Double_IntPtr", typeof(double), 123.45, typeof(IntPtr), 120)]
    //[Case(123.45 - 120L, "Double_Int64", 123.45, 120L)]
    public sealed class Sub
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
        public static extern ref int Sub_IntRef_IntPtr(ref int lhs, IntPtr rhs);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern int IntRef_IntPtr(int value);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern ref int Sub_IntRef_Int32(ref int lhs, int rhs);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern int IntRef_Int32(int value);

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
