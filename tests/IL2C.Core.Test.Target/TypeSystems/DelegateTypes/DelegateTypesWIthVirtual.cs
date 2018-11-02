namespace IL2C.TypeSystems
{
    [TestId("DelegateTypes")]
    [TestCase("87654321ABC123", new[] { "Virtual_Int32ToString", "Virtual_Int32ToStringImpl" }, 87654321, IncludeTypes = new[] { typeof(Int32ToStringDelegate) })]
    public class DelegateTypesWithVirtual1
    {
        private int v1 = 123;

        public virtual string Virtual_Int32ToStringImpl(int value)
        {
            return value.ToString() + "ABC" + v1.ToString();
        }

        public static string Virtual_Int32ToString(int value)
        {
            var inst = new DelegateTypesWithVirtual1();
            var dlg = new Int32ToStringDelegate(inst.Virtual_Int32ToStringImpl);
            return dlg(value);
        }
    }

    public class DelegateTypesWithVirtual_Base
    {
        private int v0 = 111;

        public virtual string Override_Int32ToStringImpl(int value)
        {
            return value.ToString() + "DEF" + v0.ToString();
        }
    }

    [TestId("DelegateTypes")]
    [TestCase("87654321ABC123", new[] { "Override_Int32ToString", "Override_Int32ToStringImpl" }, 87654321, IncludeBaseTypes = true, IncludeTypes = new[] { typeof(Int32ToStringDelegate) })]
    [TestCase("87654321ABC123", new[] { "Base_Int32ToString", "Override_Int32ToStringImpl" }, 87654321, IncludeBaseTypes = true, IncludeTypes = new[] { typeof(Int32ToStringDelegate) })]
    public class DelegateTypesWithVirtual2 : DelegateTypesWithVirtual_Base
    {
        private int v1 = 123;

        public override string Override_Int32ToStringImpl(int value)
        {
            return value.ToString() + "ABC" + v1.ToString();
        }

        public static string Override_Int32ToString(int value)
        {
            var inst = new DelegateTypesWithVirtual2();
            var dlg = new Int32ToStringDelegate(inst.Override_Int32ToStringImpl);
            return dlg(value);
        }

        public static string Base_Int32ToString(int value)
        {
            DelegateTypesWithVirtual_Base inst = new DelegateTypesWithVirtual2();
            var dlg = new Int32ToStringDelegate(inst.Override_Int32ToStringImpl);
            return dlg(value);
        }
    }
}
