using System.Runtime.CompilerServices;

namespace IL2C.ILConverters
{
    [TestCase(6, "RawValue")]
    [TestCase(10, "Add", 4)]
    public sealed class Ldc_i4_6
    {
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern int RawValue();

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern int Add(int num);
    }
}
