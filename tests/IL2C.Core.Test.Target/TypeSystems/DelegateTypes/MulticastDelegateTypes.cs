namespace IL2C.TypeSystems
{
    public delegate void RefIntDelegate(ref int value);

    [TestId("DelegateTypes")]
    [TestCase(1333, new[] { "Static_Int_Multicast", "Static_RefIntImpl1", "Static_RefIntImpl2" }, 1000, IncludeTypes = new[] { typeof(RefIntDelegate) })]
    public sealed class MulticastDelegateTypes
    {
        private static void Static_RefIntImpl1(ref int value)
        {
            value += 111;
        }

        private static void Static_RefIntImpl2(ref int value)
        {
            value += 222;
        }

        public static int Static_Int_Multicast(int value)
        {
            var dlg1 = new RefIntDelegate(Static_RefIntImpl1);
            var dlg2 = new RefIntDelegate(Static_RefIntImpl2);
            dlg1 += dlg2;

            var v = value;
            dlg1(ref v);

            return v;
        }
    }
}
