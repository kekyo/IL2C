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
    public sealed class Format41_CustomProducer
    {
        public override string ToString() => "FGH";
    }

    public sealed class Format42_CustomProducer : IFormattable
    {
        public string ToString(string format, IFormatProvider formatProvider)
        {
            switch (format)
            {
                case "N": return "XXX";
                case "": return "YYY";
                case null: return "ZZZ";
                default: throw new Exception();
            }
        }
    }

    [TestId("System_String")]
    [TestCase("A123BC124DE125FG126H", "Format_Params", "A{0}BC{1}DE{2}FG{3}H", (byte)123, (byte)124, (byte)125, (byte)126)]
    [TestCase("A-123BC-124DE-125FG-126H", "Format_Params", "A{0}BC{1}DE{2}FG{3}H", (sbyte)-123, (sbyte)-124, (sbyte)-125, (sbyte)-126)]
    [TestCase("A-12345BC-12346DE-12347FG-12348H", "Format_Params", "A{0}BC{1}DE{2}FG{3}H", (short)-12345, (short)-12346, (short)-12347, (short)-12348)]
    [TestCase("A12345BC12346DE12347FG12348H", "Format_Params", "A{0}BC{1}DE{2}FG{3}H", (ushort)12345, (ushort)12346, (ushort)12347, (ushort)12348)]
    [TestCase("A1234567BC1234568DE1234569FG1234570H", "Format_Params", "A{0}BC{1}DE{2}FG{3}H", 1234567, 1234568, 1234569, 1234570)]
    [TestCase("A-1234567BC-1234568DE-1234569FG-1234570H", "Format_Params", "A{0}BC{1}DE{2}FG{3}H", -1234567, -1234568, -1234569, -1234570)]
    [TestCase("A1234567890123BC1234567890124DE1234567890125FG1234567890126H", "Format_Params", "A{0}BC{1}DE{2}FG{3}H", 1234567890123, 1234567890124, 1234567890125, 1234567890126)]
    [TestCase("A-1234567890123BC-1234567890124DE-1234567890125FG-1234567890126H", "Format_Params", "A{0}BC{1}DE{2}FG{3}H", -1234567890123, -1234567890124, -1234567890125, -1234567890126)]
    [TestCase("A123.456BC123.457DE123.458FG123.459H", "Format_Params", "A{0}BC{1}DE{2}FG{3}H", 123.456f, 123.457f, 123.458f, 123.459f)]
    [TestCase("A123.456789BC123.456788DE123.456787FG123.456786H", "Format_Params", "A{0}BC{1}DE{2}FG{3}H", 123.456789, 123.456788, 123.456787, 123.456786)]
    [TestCase("ATrueBCFalseDETrueFGFalseH", "Format_Params", "A{0}BC{1}DE{2}FG{3}H", true, false, true, false)]
    [TestCase("AXBCYDEZFGPH", "Format_Params", "A{0}BC{1}DE{2}FG{3}H", 'X', 'Y', 'Z', 'P')]
    [TestCase("AXYZBCPQRDESTUFGFGHH", "Format_Params", "A{0}BC{1}DE{2}FG{3}H", "XYZ", "PQR", "STU", "FGH")]
    [TestCase("AXYZBCPQRDESTUFGFGHH", "Format_Params_Custom1", "A{0}BC{1}DE{2}FG{3}H", IncludeTypes = new[] { typeof(Format11_CustomProducer), typeof(Format21_CustomProducer), typeof(Format31_CustomProducer), typeof(Format41_CustomProducer) })]
    [TestCase("AXYZBCPQRDESTUFGFGHH", "Format_Params_Custom1", "A{0:}BC{1:}DE{2:}FG{3:}H", IncludeTypes = new[] { typeof(Format11_CustomProducer), typeof(Format21_CustomProducer), typeof(Format31_CustomProducer), typeof(Format41_CustomProducer) })]
    [TestCase("AXYZBCPQRDESTUFGFGHH", "Format_Params_Custom1", "A{0:N}BC{1:N}DE{2:N}FG{3:N}H", IncludeTypes = new[] { typeof(Format11_CustomProducer), typeof(Format21_CustomProducer), typeof(Format31_CustomProducer), typeof(Format41_CustomProducer) })]
    [TestCase("A333BC666DE999FGZZZH", "Format_Params_Custom2", "A{0}BC{1}DE{2}FG{3}H", IncludeTypes = new[] { typeof(Format12_CustomProducer), typeof(Format22_CustomProducer), typeof(Format32_CustomProducer), typeof(Format42_CustomProducer) })]
    [TestCase("A333BC666DE999FGZZZH", "Format_Params_Custom2", "A{0:}BC{1:}DE{2:}FG{3:}H", IncludeTypes = new[] { typeof(Format12_CustomProducer), typeof(Format22_CustomProducer), typeof(Format32_CustomProducer), typeof(Format42_CustomProducer) })]
    [TestCase("A111BC444DE777FGXXXH", "Format_Params_Custom2", "A{0:N}BC{1:N}DE{2:N}FG{3:N}H", IncludeTypes = new[] { typeof(Format12_CustomProducer), typeof(Format22_CustomProducer), typeof(Format32_CustomProducer), typeof(Format42_CustomProducer) })]
    [TestCase("123A123B124C124D125E125F126", "Format_Params", "{0}A{0}B{1}C{1}D{2}E{2}F{3}", 123, 124, 125, 126)]
    [TestCase("A126BC125DE124FG123H", "Format_Params", "A{3}BC{2}DE{1}FG{0}H", 123, 124, 125, 126)]
    [TestCase("A333B111C666D444E999F777GZZZHXXXI", "Format_Params_Custom2", "A{0}B{0:N}C{1}D{1:N}E{2}F{2:N}G{3}H{3:N}I", IncludeTypes = new[] { typeof(Format12_CustomProducer), typeof(Format22_CustomProducer), typeof(Format32_CustomProducer), typeof(Format42_CustomProducer) })]
    [TestCase("ABCDEF", "Format_Params", "ABCDEF", 123, 124, 125, 126)]
    [TestCase("ABCDEFGH", "Format_Params", "A{0}BC{1}DE{2}FG{3}H", "", "", "", "")]
    [TestCase("ABCDEFGH", "Format_Params", "A{0}BC{1}DE{2}FG{3}H", null, null, null, null)]
    [TestCase(true, "Format_Params_Exception", "ABC{4}DEF", 123, 124, 125, 126)]
    public sealed class System_String_Format_Params
    {
        public static string Format_Params(string format, object value0, object value1, object value2, object value3)
        {
            return string.Format(format, value0, value1, value2, value3);
        }

        public static string Format_Params_Custom1(string format)
        {
            var cp1 = new Format11_CustomProducer();
            var cp2 = new Format21_CustomProducer();
            var cp3 = new Format31_CustomProducer();
            var cp4 = new Format41_CustomProducer();
            return string.Format(format, cp1, cp2, cp3, cp4);
        }

        public static string Format_Params_Custom2(string format)
        {
            var cp1 = new Format12_CustomProducer();
            var cp2 = new Format22_CustomProducer();
            var cp3 = new Format32_CustomProducer();
            var cp4 = new Format42_CustomProducer();
            return string.Format(format, cp1, cp2, cp3, cp4);
        }

        public static bool Format_Params_Exception(string format, object value0, object value1, object value2, object value3)
        {
            try
            {
                var s = string.Format(format, value0, value1, value2, value3);
            }
            catch (FormatException)
            {
                return true;
            }
            return false;
        }
    }
}
