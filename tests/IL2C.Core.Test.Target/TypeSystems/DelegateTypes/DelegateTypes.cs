namespace IL2C.TypeSystems
{
    public delegate string Int32ToStringDelegate(int value);

    [TestCase("12345678ABC", new[] { "Int32ToString", "Int32ToStringImpl", ".ctor" }, 12345678, IncludeTypes = new[] { typeof(Int32ToStringDelegate) })]
    public sealed class DelegateTypes
    {
        private static string Int32ToStringImpl(int value)
        {
            return value.ToString() + "ABC";
        }

        public static string Int32ToString(int value)
        {
            var dlg = new Int32ToStringDelegate(Int32ToStringImpl);
            return dlg(value);
        }
    }
}
