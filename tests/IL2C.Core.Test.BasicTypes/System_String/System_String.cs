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

namespace IL2C.BasicTypes
{
    public sealed class System_String
    {
        // NOTE: ToString and Equals are written by IL.
        //   Because they are compiled with callvirt opcode from Roslyn.

        [TestCase(false, "IsValueType")]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern bool IsValueType();

        [TestCase("ABC", "ToString", "ABC")]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern string ToString(string value);

        [TestCase("ABCDEF", "Concat", "ABC", "DEF")]
        public static string Concat(string value1, string value2)
        {
            return string.Concat(value1, value2);
        }

        [TestCase("CDEFGH", "Substring", "ABCDEFGH", 2)]
        public static string Substring(string str, int index)
        {
            return str.Substring(index);
        }

        [TestCase("CDE", "Substring1", "ABCDEFGH", 2, 3)]
        public static string Substring1(string str, int index, int count)
        {
            return str.Substring(index, count);
        }

        [TestCase('A', "Indexer", "ABCDEFGH", 0)]
        [TestCase('H', "Indexer", "ABCDEFGH", 7)]
        public static char Indexer(string str, int index)
        {
            return str[index];
        }

        [TestCase(8, "Length", "ABCDEFGH")]
        public static int Length(string str)
        {
            return str.Length;
        }

        [TestCase(false, "IsNullOrWhiteSpace", "ABCDEFGH")]
        [TestCase(true, "IsNullOrWhiteSpace", "")]
        [TestCase(true, "IsNullOrWhiteSpace", null!)]
        public static bool IsNullOrWhiteSpace(string str)
        {
            return string.IsNullOrWhiteSpace(str);
        }

        [TestCase(true, "Equals1", "ABC", "ABC")]
        [TestCase(false, "Equals1", "ABC", "ABCDEF")]
        [TestCase(false, "Equals1", "ABC", "DEF")]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern bool Equals1(string value1, string value2);

        [TestCase(false, "IndexOutOfRange", "ABC", 0)]
        [TestCase(false, "IndexOutOfRange", "ABC", 2)]
        [TestCase(true, "IndexOutOfRange", "ABC", -1)]
        [TestCase(true, "IndexOutOfRange", "ABC", 3)]
        public static bool IndexOutOfRange(string str, int index)
        {
            try
            {
                var ch = str[index];
            }
            catch (IndexOutOfRangeException ex)
            {
                return ex.Message == "Index was outside the bounds of the array.";
            }
            return false;
        }

        [TestCase(true, "Equality", "ABC", "ABC")]
        [TestCase(false, "Equality", "ABC", "ABCDEF")]
        [TestCase(false, "Equality", "ABC", "DEF")]
        [TestCase(false, "Equality", "ABC", null)]
        [TestCase(false, "Equality", null, "DEF")]
        [TestCase(true, "Equality", null, null)]
        public static bool Equality(string value1, string value2)
        {
            return value1 == value2;
        }

        [TestCase(false, "Inequality", "ABC", "ABC")]
        [TestCase(true, "Inequality", "ABC", "ABCDEF")]
        [TestCase(true, "Inequality", "ABC", "DEF")]
        [TestCase(true, "Inequality", "ABC", null)]
        [TestCase(true, "Inequality", null, "DEF")]
        [TestCase(false, "Inequality", null, null)]
        public static bool Inequality(string value1, string value2)
        {
            return value1 != value2;
        }
    }
}
