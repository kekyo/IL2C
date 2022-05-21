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
    public sealed class Format21_CustomProducer
    {
        public override string ToString() => "PQR";
    }

    public sealed class Format22_CustomProducer : IFormattable
    {
        public string ToString(string? format, IFormatProvider? formatProvider)
        {
            switch (format)
            {
                case "N": return "444";
                case "": return "555";
                case null: return "666";
                default: throw new Exception();
            }
        }
    }

    [TestId("System_String")]
    public sealed class System_String_Format2
    {
        [TestCase("AB123CD124EF", "Format2", "AB{0}CD{1}EF", (byte)123, (byte)124)]
        [TestCase("AB-123CD-124EF", "Format2", "AB{0}CD{1}EF", (sbyte)-123, (sbyte)-124)]
        [TestCase("AB-12345CD-12346EF", "Format2", "AB{0}CD{1}EF", (short)-12345, (short)-12346)]
        [TestCase("AB12345CD12346EF", "Format2", "AB{0}CD{1}EF", (ushort)12345, (ushort)12346)]
        [TestCase("AB1234567CD1234568EF", "Format2", "AB{0}CD{1}EF", 1234567, 1234568)]
        [TestCase("AB-1234567CD-1234568EF", "Format2", "AB{0}CD{1}EF", -1234567, -1234568)]
        [TestCase("AB1234567890123CD1234567890124EF", "Format2", "AB{0}CD{1}EF", 1234567890123, 1234567890124)]
        [TestCase("AB-1234567890123CD-1234567890124EF", "Format2", "AB{0}CD{1}EF", -1234567890123, -1234567890124)]
        [TestCase("AB123.456CD123.457EF", "Format2", "AB{0}CD{1}EF", 123.456f, 123.457f)]
        [TestCase("AB123.456789CD123.456788EF", "Format2", "AB{0}CD{1}EF", 123.456789, 123.456788)]
        [TestCase("ABTrueCDFalseEF", "Format2", "AB{0}CD{1}EF", true, false)]
        [TestCase("ABXCDYEF", "Format2", "AB{0}CD{1}EF", 'X', 'Y')]
        [TestCase("ABXYZCDPQREF", "Format2", "AB{0}CD{1}EF", "XYZ", "PQR")]
        [TestCase("123ABCDEF124", "Format2", "{0}ABCDEF{1}", 123, 124)]
        [TestCase("123ABC124DEF123", "Format2", "{0}ABC{1}DEF{0}", 123, 124)]
        [TestCase("ABCDEF", "Format2", "ABCDEF", 123, 124)]
        [TestCase("ABCDEF", "Format2", "AB{0}CD{1}EF", "", "")]
        [TestCase("ABCDEF", "Format2", "AB{0}CD{1}EF", null, null)]
        public static string Format2(string format, object value0, object value1)
        {
            return string.Format(format, value0, value1);
        }

        [TestCase("ABXYZCDPQREF", "Format21_Custom", "AB{0}CD{1}EF", IncludeTypes = new[] { typeof(Format11_CustomProducer), typeof(Format21_CustomProducer) })]
        [TestCase("ABXYZCDPQREF", "Format21_Custom", "AB{0:}CD{1:}EF", IncludeTypes = new[] { typeof(Format11_CustomProducer), typeof(Format21_CustomProducer) })]
        [TestCase("ABXYZCDPQREF", "Format21_Custom", "AB{0:N}CD{1:N}EF", IncludeTypes = new[] { typeof(Format11_CustomProducer), typeof(Format21_CustomProducer) })]
        public static string Format21_Custom(string format)
        {
            var cp1 = new Format11_CustomProducer();
            var cp2 = new Format21_CustomProducer();
            return string.Format(format, cp1, cp2);
        }

        [TestCase("AB333CD666EF", "Format22_Custom", "AB{0}CD{1}EF", IncludeTypes = new[] { typeof(Format12_CustomProducer), typeof(Format22_CustomProducer) })]
        [TestCase("AB333CD666EF", "Format22_Custom", "AB{0:}CD{1:}EF", IncludeTypes = new[] { typeof(Format12_CustomProducer), typeof(Format22_CustomProducer) })]
        [TestCase("AB111CD444EF", "Format22_Custom", "AB{0:N}CD{1:N}EF", IncludeTypes = new[] { typeof(Format12_CustomProducer), typeof(Format22_CustomProducer) })]
        [TestCase("A333B111C666D444E", "Format22_Custom", "A{0}B{0:N}C{1}D{1:N}E", IncludeTypes = new[] { typeof(Format12_CustomProducer), typeof(Format22_CustomProducer) })]
        public static string Format22_Custom(string format)
        {
            var cp1 = new Format12_CustomProducer();
            var cp2 = new Format22_CustomProducer();
            return string.Format(format, cp1, cp2);
        }

        [TestCase(true, "Format2_Exception", "ABC{2}DEF", 123, 124)]
        public static bool Format2_Exception(string format, object value0, object value1)
        {
            try
            {
                var s = string.Format(format, value0, value1);
            }
            catch (FormatException)
            {
                return true;
            }
            return false;
        }
    }
}
