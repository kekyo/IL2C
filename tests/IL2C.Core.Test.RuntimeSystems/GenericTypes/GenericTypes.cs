using System.ComponentModel;

namespace IL2C.RuntimeSystems
{
    public sealed class ContainsGenericFieldClassType<T>
    {
        public T Value;
    }

    [Description("These tests are verified the IL2C can handle closed generic types.")]
    [TestCase(12345678, "Int32FieldClassType", 12345678, IncludeTypes =new[] { typeof(ContainsGenericFieldClassType<int>) })]
    public sealed class GenericTypes
    {
        public static int Int32FieldClassType(int value)
        {
            var target = new ContainsGenericFieldClassType<int>();
            target.Value = value;
            return target.Value;
        }
    }
}
