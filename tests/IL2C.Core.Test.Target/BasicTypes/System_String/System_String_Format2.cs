using System;
using System.Runtime.CompilerServices;

namespace IL2C.BasicTypes
{
    public sealed class Format2_CustomProducer
    {
        public override string ToString() => "PQR";
    }

    [TestId("System_String")]
    [TestCase("AB123CD124EF", "Format2", "AB{0}CD{1}EF", (byte)123, (byte)124)]
    [TestCase("AB-123CD-124EF", "Format2", "AB{0}CD{1}EF", (sbyte)-123, (sbyte)-124)]
    [TestCase("AB-12345CD-12346EF", "Format2", "AB{0}CD{1}EF", (short)-12345, (short)-12346)]
    [TestCase("AB12345CD12346EF", "Format2", "AB{0}CD{1}EF", (ushort)12345, (ushort)12346)]
    [TestCase("AB1234567CD1234568EF", "Format2", "AB{0}CD{1}EF", 1234567, 1234568)]
    [TestCase("AB-1234567CD-1234568EF", "Format2", "AB{0}CD{1}EF", -1234567, -1234568)]
    [TestCase("AB1234567890123CD1234567890124EF", "Format2", "AB{0}CD{1}EF", 1234567890123, 1234567890124)]
    [TestCase("AB-1234567890123CD-1234567890124EF", "Format2", "AB{0}CD{1}EF", -1234567890123, -1234567890124)]
    [TestCase("AB123.456CD123.457EF", "Format2", "AB{0}CD{1}EF", 123.456f, 123.457f)]
    [TestCase("AB123.456CD123.457EF", "Format2", "AB{0}CD{1}EF", 123.456, 123.457)]
    [TestCase("ABTrueCDFalseEF", "Format2", "AB{0}CD{1}EF", true, false)]
    [TestCase("ABXCDYEF", "Format2", "AB{0}CD{1}EF", 'X', 'Y')]
    [TestCase("ABXYZCDPQREF", "Format2", "AB{0}CD{1}EF", "XYZ", "PQR")]
    [TestCase("ABXYZCDPQREF", "Format2_Custom", "AB{0}CD{1}EF", IncludeTypes = new[] { typeof(Format1_CustomProducer), typeof(Format2_CustomProducer) })]
    [TestCase("123ABCDEF124", "Format2", "{0}ABCDEF{1}", 123, 124)]
    [TestCase("123ABC124DEF123", "Format2", "{0}ABC{1}DEF{0}", 123, 124)]
    [TestCase("ABCDEF", "Format2", "ABCDEF", 123, 124)]
    [TestCase("ABCDEF", "Format2", "AB{0}CD{1}EF", "", "")]
    [TestCase("ABCDEF", "Format2", "AB{0}CD{1}EF", null, null)]
    [TestCase(true, "Format2_Exception", "ABC{2}DEF", 123, 124)]
    public sealed class System_String_Format2
    {
        public static string Format2(string format, object value0, object value1)
        {
            return string.Format(format, value0, value1);
        }

        public static string Format2_Custom(string format)
        {
            var cp1 = new Format1_CustomProducer();
            var cp2 = new Format2_CustomProducer();
            return string.Format(format, cp1, cp2);
        }

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
