using System;
using System.Runtime.CompilerServices;

namespace IL2C.ILConverters
{
    [TestCase(0, "IntPtrZero")]
    [TestCase((uint)0, "UIntPtrZero")]
    [TestCase(null, "NullReference")]
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
