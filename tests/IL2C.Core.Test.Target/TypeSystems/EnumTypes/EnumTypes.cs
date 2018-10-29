namespace IL2C.TypeSystems
{
    public enum Int32EnumType
    {
        MinusOne = -1,
        Zero = 0,
        One = 1,
        Two = 2
    }

    [TestCase(Int32EnumType.MinusOne, "Int32", -1, IncludeTypes = new[] { typeof(Int32EnumType) })]
    [TestCase(Int32EnumType.Zero, "Int32", 0, IncludeTypes = new[] { typeof(Int32EnumType) })]
    [TestCase(Int32EnumType.One, "Int32", 1, IncludeTypes = new[] { typeof(Int32EnumType) })]
    [TestCase(Int32EnumType.Two, "Int32", 2, IncludeTypes = new[] { typeof(Int32EnumType) })]
    public sealed class EnumTypes
    {
        public static Int32EnumType Int32(int value)
        {
            return (Int32EnumType)value;
        }
    }
}
