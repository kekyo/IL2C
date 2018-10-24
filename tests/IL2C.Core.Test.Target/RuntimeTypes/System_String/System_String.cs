using System.Runtime.CompilerServices;

namespace IL2C.RuntimeTypes
{
    [TestCase(false, "IsValueType")]
    [TestCase(4, "SizeOf")]     // vptr
    [TestCase("ABC", "ToString", "ABC")]
    [TestCase("ABCDEF", "Concat", "ABC", "DEF")]
    [TestCase("CDEFGH", "Substring", "ABCDEFGH", 2)]
    [TestCase("CDE", "Substring1", "ABCDEFGH", 2, 3)]
    [TestCase('A', "Indexer", "ABCDEFGH", 0)]
    [TestCase('H', "Indexer", "ABCDEFGH", 7)]
    [TestCase(8, "Length", "ABCDEFGH")]
    [TestCase(false, "IsNullOrWhiteSpace", "ABCDEFGH")]
    [TestCase(true, "IsNullOrWhiteSpace", "")]
    [TestCase(true, "IsNullOrWhiteSpace", null)]
    [TestCase(true, "Equals1", "ABC", "ABC")]
    public sealed class System_String
    {
        // MEMO: ToString and Equals are written by IL.
        //   Because they are compiled with callvirt opcode from Roslyn.

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern bool IsValueType();

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern int SizeOf();

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern string ToString(string value);

        public static string Concat(string value1, string value2)
        {
            return string.Concat(value1, value2);
        }

        public static string Substring(string str, int index)
        {
            return str.Substring(index);
        }

        public static string Substring1(string str, int index, int count)
        {
            return str.Substring(index, count);
        }

        public static char Indexer(string str, int index)
        {
            return str[index];
        }

        public static int Length(string str)
        {
            return str.Length;
        }

        public static bool IsNullOrWhiteSpace(string str)
        {
            return string.IsNullOrWhiteSpace(str);
        }

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern bool Equals1(string value1, string value2);
    }
}
