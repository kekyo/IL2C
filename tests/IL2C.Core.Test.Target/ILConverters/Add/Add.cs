using System;
using System.Runtime.CompilerServices;

namespace IL2C.ILConverters
{
    [Case(36, "Int32_Int32", 12, 24)]
    [Case(36, typeof(IntPtr), "IntPtr_IntPtr", typeof(IntPtr), 12, typeof(IntPtr), 24)]
    [Case(36, typeof(IntPtr), "IntPtr_Int32", typeof(IntPtr), 12, typeof(int), 24)]
    [Case(36L, "Int64_Int64", 12L, 24L)]
    [Case(36L, typeof(long), "Int64_IntPtr", typeof(long), 12L, typeof(IntPtr), 24)]
    [Case(36L, "Int64_Int32", 12L, 24)]
    [Case(123, new[] { "IntRef_IntPtr", "Add_IntRef_IntPtr" }, 123)]
    [Case(123, new[] { "IntRef_Int32", "Add_IntRef_Int32" }, 123)]
    [Case(123.45, "Double_Double", 0.45, 123.0)]
    // These cases are declared at ".NET IL Assembler" Serge Lidin's book.
    // It can handle by IL2C, but .NET 4.0 CLR causes InvalidProgramException.
    //[Case(123.45, "Double_Int32", 0.45, 123)]
    //[Case(123.45, typeof(double), "Double_IntPtr", typeof(double), 0.45, typeof(IntPtr), 123)]
    //[Case(123.45, "Double_Int64", 0.45, 123L)]
    public sealed class Add
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
        public static extern ref int Add_IntRef_IntPtr(ref int lhs, IntPtr rhs);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern int IntRef_IntPtr(int value);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern ref int Add_IntRef_Int32(ref int lhs, int rhs);

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
