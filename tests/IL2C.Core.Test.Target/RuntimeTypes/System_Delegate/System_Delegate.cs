using System.Runtime.CompilerServices;

namespace IL2C.RuntimeTypes
{
    public delegate void IntRefDelegate(ref int value);

    [TestCase(10100, new[] { "Remove_DelegateInstance", "IntRefImpl1", "IntRefImpl2" }, 1000, IncludeTypes = new[] { typeof(IntRefDelegate) })]
    [TestCase(10100, new[] { "Remove_DelegateTarget", "IntRefImpl1", "IntRefImpl2" }, 1000, IncludeTypes = new[] { typeof(IntRefDelegate) })]
    public sealed class System_Delegate
    {
        private static void IntRefImpl1(ref int value)
        {
            value += 10;
        }

        private static void IntRefImpl2(ref int value)
        {
            value *= 10;
        }

        public static int Remove_DelegateInstance(int value)
        {
            var dlg1 = new IntRefDelegate(IntRefImpl1);
            var dlg2 = new IntRefDelegate(IntRefImpl2);

            var dlg = dlg1 + dlg2;
            dlg += dlg1;

            // Remove only a tail delegate.
            dlg -= dlg1;

            var v = value;
            dlg(ref v);

            return v;
        }

        public static int Remove_DelegateTarget(int value)
        {
            var dlg1 = new IntRefDelegate(IntRefImpl1);
            var dlg2 = new IntRefDelegate(IntRefImpl2);
            var dlg3 = new IntRefDelegate(IntRefImpl1);

            var dlg = dlg1 + dlg2;
            dlg += dlg3;

            // Remove only a tail delegate.
            dlg -= dlg1;

            var v = value;
            dlg(ref v);

            return v;
        }
    }
}
