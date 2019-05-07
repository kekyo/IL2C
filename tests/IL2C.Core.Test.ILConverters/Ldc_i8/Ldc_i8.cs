using System.Runtime.CompilerServices;

namespace IL2C.ILConverters
{
    [TestCase(long.MaxValue, "MaxValue")]
    [TestCase(long.MinValue, "MinValue")]
    public sealed class Ldc_i8
    {
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern long MaxValue();

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern long MinValue();
    }
}
