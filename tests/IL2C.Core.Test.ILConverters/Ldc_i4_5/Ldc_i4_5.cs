using System.Runtime.CompilerServices;

namespace IL2C.ILConverters
{
    [TestCase(5, "RawValue")]
    [TestCase(9, "Add", 4)]
    public sealed class Ldc_i4_5
    {
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern int RawValue();

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern int Add(int num);
    }
}
