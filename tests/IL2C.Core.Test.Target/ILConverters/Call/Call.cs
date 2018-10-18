using System;
using System.Runtime.CompilerServices;

namespace IL2C.ILConverters
{
    [Case(123, new[] { "Static_Int32_Int32", "Add_Static_Int32_Int32" }, 100, 23)]
    [Case("ABCDEF", new[] { "Static_String_String", "Concat_Static_String_String" }, "ABC", "DEF")]
    [Case(123, new[] { "Static_RefInt_RefInt", "Store_Static_RefInt_RefInt" })]
    public sealed class Call
    {
        private static int Add_Static_Int32_Int32(int lhs, int rhs)
        {
            return lhs + rhs;
        }

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern int Static_Int32_Int32(int lhs, int rhs);

        private static string Concat_Static_String_String(string lhs, string rhs)
        {
            return lhs + rhs;
        }

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern string Static_String_String(string lhs, string rhs);

        private static void Store_Static_RefInt_RefInt(ref int lhs, ref int rhs)
        {
            lhs = 100;
            rhs = 23;
        }

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern int Static_RefInt_RefInt();
    }
}
