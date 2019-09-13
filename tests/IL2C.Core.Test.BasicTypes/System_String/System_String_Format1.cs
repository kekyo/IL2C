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
    public sealed class Format11_CustomProducer
    {
        public override string ToString() => "XYZ";
    }

    public sealed class Format12_CustomProducer : IFormattable
    {
        public string ToString(string format, IFormatProvider formatProvider)
        {
            switch (format)
            {
                case "N": return "111";
                case "": return "222";
                case null: return "333";
                default: throw new Exception();
            }
        }
    }

    [TestId("System_String")]
    [TestCase("ABC123DEF", "Format1", "ABC{0}DEF", (byte)123)]
    [TestCase("ABC-123DEF", "Format1", "ABC{0}DEF", (sbyte)-123)]
    [TestCase("ABC-12345DEF", "Format1", "ABC{0}DEF", (short)-12345)]
    [TestCase("ABC12345DEF", "Format1", "ABC{0}DEF", (ushort)12345)]
    [TestCase("ABC1234567DEF", "Format1", "ABC{0}DEF", 1234567)]
    [TestCase("ABC-1234567DEF", "Format1", "ABC{0}DEF", -1234567)]
    [TestCase("ABC1234567890123DEF", "Format1", "ABC{0}DEF", 1234567890123)]
    [TestCase("ABC-1234567890123DEF", "Format1", "ABC{0}DEF", -1234567890123)]
    [TestCase("ABC123.456DEF", "Format1", "ABC{0}DEF", 123.456f)]
    [TestCase("ABC123.456789DEF", "Format1", "ABC{0}DEF", 123.456789)]
    [TestCase("ABCTrueDEF", "Format1", "ABC{0}DEF", true)]
    [TestCase("ABCFalseDEF", "Format1", "ABC{0}DEF", false)]
    [TestCase("ABCXDEF", "Format1", "ABC{0}DEF", 'X')]
    [TestCase("ABCXYZDEF", "Format1", "ABC{0}DEF", "XYZ")]
    [TestCase("ABCXYZDEF", "Format11_Custom", "ABC{0}DEF", IncludeTypes = new[] { typeof(Format11_CustomProducer) })]
    [TestCase("ABCXYZDEF", "Format11_Custom", "ABC{0:}DEF", IncludeTypes = new[] { typeof(Format11_CustomProducer) })]
    [TestCase("ABCXYZDEF", "Format11_Custom", "ABC{0:N}DEF", IncludeTypes = new[] { typeof(Format11_CustomProducer) })]
    [TestCase("ABC333DEF", "Format12_Custom", "ABC{0}DEF", IncludeTypes = new[] { typeof(Format12_CustomProducer) })]
    [TestCase("ABC333DEF", "Format12_Custom", "ABC{0:}DEF", IncludeTypes = new[] { typeof(Format12_CustomProducer) })]
    [TestCase("ABC111DEF", "Format12_Custom", "ABC{0:N}DEF", IncludeTypes = new[] { typeof(Format12_CustomProducer) })]
    [TestCase("123ABCDEF", "Format1", "{0}ABCDEF", 123)]
    [TestCase("ABCDEF123", "Format1", "ABCDEF{0}", 123)]
    [TestCase("123ABC123DEF123", "Format1", "{0}ABC{0}DEF{0}", 123)]
    [TestCase("ABCDEF", "Format1", "ABCDEF", 123)]
    [TestCase("ABCDEF", "Format1", "ABC{0}DEF", "")]
    [TestCase("ABCDEF", "Format1", "ABC{0}DEF", null)]
    [TestCase(true, "Format1_Exception", "ABC{", 123)]
    [TestCase(true, "Format1_Exception", "ABC{0", 123)]
    [TestCase(true, "Format1_Exception", "ABC{0:", 123)]
    [TestCase(true, "Format1_Exception", "ABC{}DEF", 123)]
    [TestCase(true, "Format1_Exception", "ABC{A}DEF", 123)]
    [TestCase(true, "Format1_Exception", "ABC{:}DEF", 123)]
    [TestCase(true, "Format1_Exception", "ABC{12345678901234}DEF", 123)]
    [TestCase(true, "Format1_Exception", "ABC{1}DEF", 123)]
    public sealed class System_String_Format1
    {
        public static string Format1(string format, object value0)
        {
            return string.Format(format, value0);
        }

        public static string Format11_Custom(string format)
        {
            var cp = new Format11_CustomProducer();
            return string.Format(format, cp);
        }

        public static string Format12_Custom(string format)
        {
            var cp = new Format12_CustomProducer();
            return string.Format(format, cp);
        }

        public static bool Format1_Exception(string format, object value0)
        {
            try
            {
                var s = string.Format(format, value0);
            }
            catch (FormatException)
            {
                return true;
            }
            return false;
        }
    }
}
