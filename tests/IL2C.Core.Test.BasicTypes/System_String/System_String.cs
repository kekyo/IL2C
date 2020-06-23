/////////////////////////////////////////////////////////////////////////////////////////////////
//
// IL2C - A translator for ECMA-335 CIL/MSIL to C language.
// Copyright (c) 2016-2019 Kouji Matsui (@kozy_kekyo, @kekyo2)
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//	http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
/////////////////////////////////////////////////////////////////////////////////////////////////

using System;
using System.Runtime.CompilerServices;

namespace IL2C.BasicTypes
{
    [TestCase(false, "IsValueType")]
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
    [TestCase(false, "Equals1", "ABC", "ABCDEF")]
    [TestCase(false, "Equals1", "ABC", "DEF")]
    [TestCase(false, "IndexOutOfRange", "ABC", 0)]
    [TestCase(false, "IndexOutOfRange", "ABC", 2)]
    [TestCase(true, "IndexOutOfRange", "ABC", -1)]
    [TestCase(true, "IndexOutOfRange", "ABC", 3)]
    [TestCase(true, "Equality", "ABC", "ABC")]
    [TestCase(false, "Equality", "ABC", "ABCDEF")]
    [TestCase(false, "Equality", "ABC", "DEF")]
    [TestCase(false, "Equality", "ABC", null)]
    [TestCase(false, "Equality", null, "DEF")]
    [TestCase(true, "Equality", null, null)]
    [TestCase(false, "Inequality", "ABC", "ABC")]
    [TestCase(true, "Inequality", "ABC", "ABCDEF")]
    [TestCase(true, "Inequality", "ABC", "DEF")]
    [TestCase(true, "Inequality", "ABC", null)]
    [TestCase(true, "Inequality", null, "DEF")]
    [TestCase(false, "Inequality", null, null)]
    public sealed class System_String
    {
        // NOTE: ToString and Equals are written by IL.
        //   Because they are compiled with callvirt opcode from Roslyn.

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern bool IsValueType();

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

        public static bool Equality(string value1, string value2)
        {
            return value1 == value2;
        }

        public static bool Inequality(string value1, string value2)
        {
            return value1 != value2;
        }
    }
}
