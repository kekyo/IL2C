using System;
using System.Runtime.CompilerServices;

namespace IL2C.ILConverters
{
    public struct Box_Target_ValueType
    {
        public int Int32Value;
        public string StringValue;

        public override string ToString()
        {
            return Int32Value.ToString() + StringValue;
        }
    }

    [TestCase("124", new[] { "Int32", "Box_Int32" }, 123)]
    [TestCase("123ABC", new[] { "ValueType", "ToString" }, 123, "ABC", IncludeTypes = new[] { typeof(Box_Target_ValueType) })]
    public sealed class Box
    {
        [MethodImpl(MethodImplOptions.ForwardRef)]
        private static extern object Box_Int32(int value);

        public static string Int32(int value)
        {
            return Box_Int32(value + 1).ToString();
        }

        public static string ValueType(int value1, string value2)
        {
            var v = new Box_Target_ValueType();
            v.Int32Value = value1;
            v.StringValue = value2;
            object ov = v;
            return ov.ToString();
        }
    }
}
