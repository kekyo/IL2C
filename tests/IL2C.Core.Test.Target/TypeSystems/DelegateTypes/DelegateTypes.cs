namespace IL2C.TypeSystems
{
    public delegate string Int32ToStringDelegate(int value);

    public sealed class AnotherDelegateTypes
    {
        private int v1 = 456;

        public string AnotherInstance_Int32ToStringImpl(int value)
        {
            return value.ToString() + "DEF" + v1.ToString();
        }
    }

    [TestCase("12345678ABC", new[] { "Static_Int32ToString", "Static_Int32ToStringImpl" }, 12345678, IncludeTypes = new[] { typeof(Int32ToStringDelegate) })]
    [TestCase("87654321ABC123", new[] { "Instance_Int32ToString", "Instance_Int32ToStringImpl" }, 87654321, IncludeTypes = new[] { typeof(Int32ToStringDelegate) })]
    [TestCase("11223344DEF456", new[] { "AnotherInstance_Int32ToString", "AnotherInstance_Int32ToStringImpl" }, 11223344, IncludeTypes = new[] { typeof(Int32ToStringDelegate), typeof(AnotherDelegateTypes) })]
    public sealed class DelegateTypes
    {
        private static string Static_Int32ToStringImpl(int value)
        {
            return value.ToString() + "ABC";
        }

        public static string Static_Int32ToString(int value)
        {
            var dlg = new Int32ToStringDelegate(Static_Int32ToStringImpl);
            return dlg(value);
        }

        private int v1 = 123;

        private string Instance_Int32ToStringImpl(int value)
        {
            return value.ToString() + "ABC" + v1.ToString();
        }

        public static string Instance_Int32ToString(int value)
        {
            var inst = new DelegateTypes();
            var dlg = new Int32ToStringDelegate(inst.Instance_Int32ToStringImpl);
            return dlg(value);
        }

        public static string AnotherInstance_Int32ToString(int value)
        {
            var inst = new AnotherDelegateTypes();
            var dlg = new Int32ToStringDelegate(inst.AnotherInstance_Int32ToStringImpl);
            return dlg(value);
        }
    }
}
