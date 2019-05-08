using System.Runtime.CompilerServices;

namespace IL2C.ILConverters
{
    [TestCase(3, "RawValue")]
    [TestCase(7, "Add", 4)]
    public sealed class Ldc_i4_3
    {
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern int RawValue();

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern int Add(int num);
    }
}
