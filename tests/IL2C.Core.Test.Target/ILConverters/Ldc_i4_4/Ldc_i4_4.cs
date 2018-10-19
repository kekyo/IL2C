using System.Runtime.CompilerServices;

namespace IL2C.ILConverters
{
    [TestCase(4, "RawValue")]
    [TestCase(8, "Add", 4)]
    public sealed class Ldc_i4_4
    {
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern int RawValue();

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern int Add(int num);
    }
}
