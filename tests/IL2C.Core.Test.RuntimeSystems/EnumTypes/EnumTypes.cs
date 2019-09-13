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

using System.ComponentModel;

namespace IL2C.RuntimeSystems
{
    public enum Int32EnumType
    {
        Min = int.MinValue,
        MinusOne = -1,
        Zero = 0,
        One = 1,
        Max = int.MaxValue
    }

    public enum Int64EnumType : long
    {
        Min = long.MinValue,
        MinusOne = -1,
        Zero = 0,
        One = 1,
        Max = long.MaxValue
    }

    [Description("The enum types have the underlying primitive integer types. These tests are verified the IL2C can manage enum underlying types at the boxing-unboxing conversion with narrowing-widing combinations.")]
    [TestCase(Int32EnumType.Min, "Int32", int.MinValue, IncludeTypes = new[] { typeof(Int32EnumType) })]
    [TestCase(Int32EnumType.MinusOne, "Int32", -1, IncludeTypes = new[] { typeof(Int32EnumType) })]
    [TestCase(Int32EnumType.Zero, "Int32", 0, IncludeTypes = new[] { typeof(Int32EnumType) })]
    [TestCase(Int32EnumType.One, "Int32", 1, IncludeTypes = new[] { typeof(Int32EnumType) })]
    [TestCase(Int32EnumType.Max, "Int32", int.MaxValue, IncludeTypes = new[] { typeof(Int32EnumType) })]
    [TestCase(Int32EnumType.Zero, "ByteToInt32", 0, IncludeTypes = new[] { typeof(Int32EnumType) })]
    [TestCase(Int32EnumType.One, "ByteToInt32", 1, IncludeTypes = new[] { typeof(Int32EnumType) })]
    [TestCase((Int32EnumType)255, "ByteToInt32", 255, IncludeTypes = new[] { typeof(Int32EnumType) })]
    [TestCase(Int64EnumType.Min, "Int64", long.MinValue, IncludeTypes = new[] { typeof(Int64EnumType) })]
    [TestCase(Int64EnumType.MinusOne, "Int64", -1L, IncludeTypes = new[] { typeof(Int64EnumType) })]
    [TestCase(Int64EnumType.Zero, "Int64", 0L, IncludeTypes = new[] { typeof(Int64EnumType) })]
    [TestCase(Int64EnumType.One, "Int64", 1L, IncludeTypes = new[] { typeof(Int64EnumType) })]
    [TestCase(Int64EnumType.Max, "Int64", long.MaxValue, IncludeTypes = new[] { typeof(Int64EnumType) })]
    [TestCase((Int64EnumType)int.MinValue, "Int32ToInt64", int.MinValue, IncludeTypes = new[] { typeof(Int64EnumType) })]
    [TestCase(Int64EnumType.MinusOne, "Int32ToInt64", -1, IncludeTypes = new[] { typeof(Int64EnumType) })]
    [TestCase(Int64EnumType.Zero, "Int32ToInt64", 0, IncludeTypes = new[] { typeof(Int64EnumType) })]
    [TestCase(Int64EnumType.One, "Int32ToInt64", 1, IncludeTypes = new[] { typeof(Int64EnumType) })]
    [TestCase((Int64EnumType)int.MaxValue, "Int32ToInt64", int.MaxValue, IncludeTypes = new[] { typeof(Int64EnumType) })]
    public sealed class EnumTypes
    {
        public static Int32EnumType Int32(int value)
        {
            return (Int32EnumType)value;
        }

        // Expanding
        public static Int32EnumType ByteToInt32(byte value)
        {
            return (Int32EnumType)value;
        }

        public static Int64EnumType Int64(long value)
        {
            return (Int64EnumType)value;
        }

        // Expanding
        public static Int64EnumType Int32ToInt64(int value)
        {
            return (Int64EnumType)value;
        }
    }
}
