using System;
using System.Runtime.CompilerServices;

namespace IL2C.ILConverters
{
    [Case(0, "IntPtrZero")]
    [Case((uint)0, "UIntPtrZero")]
    [Case(null, "NullReference")]
    public sealed class Ldnull
    {
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern IntPtr IntPtrZero();

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern UIntPtr UIntPtrZero();

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern object NullReference();
    }
}
