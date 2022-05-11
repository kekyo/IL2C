////////////////////////////////////////////////////////////////////////////
//
// IL2C - A translator for ECMA-335 CIL/MSIL to C language.
// Copyright (c) Kouji Matsui (@kozy_kekyo, @kekyo@mastodon.cloud)
//
// Licensed under Apache-v2: https://opensource.org/licenses/Apache-2.0
//
////////////////////////////////////////////////////////////////////////////

using System;
using System.Runtime.CompilerServices;

namespace IL2C.ILConverters
{
    [TestCase(123, new[] { "Static_Int32_Int32", "Add_Static_Int32_Int32" }, 100, 23)]
    [TestCase("ABCDEF", new[] { "Static_String_String", "Concat_Static_String_String" }, "ABC", "DEF")]
    [TestCase(123, new[] { "Static_RefInt_RefInt", "Store_Static_RefInt_RefInt" })]
    [TestCase(679, new[] { "Instance_Int32_ThisInt32", "Add_Instance_Int32_ThisInt32" }, 123, 456)]
    [TestCase("ABCGHIDEFGHI", new[] { "Instance_String_ThisString", "Concat_Instance_String_ThisString" }, "ABC", "DEF")]
    public sealed class Call
    {
        #region Static
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
        #endregion

        #region Instance
        private readonly int v0 = 100;

        private int Add_Instance_Int32_ThisInt32(int v1, int v2)
        {
            return v0 + v1 + v2;
        }

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern int Instance_Int32_ThisInt32(int v1, int v2);

        private readonly string v3 = "GHI";

        private string Concat_Instance_String_ThisString(string v)
        {
            return v + v3;
        }

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern string Instance_String_ThisString(string v1, string v2);
        #endregion
    }
}
