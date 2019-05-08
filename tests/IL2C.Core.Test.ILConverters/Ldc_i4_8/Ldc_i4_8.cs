using System.Runtime.CompilerServices;

namespace IL2C.ILConverters
{
    [TestCase(8, "RawValue")]
    [TestCase(12, "Add", 4)]
    public sealed class Ldc_i4_8
    {
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern int RawValue();

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern int Add(int num);
    }
}
