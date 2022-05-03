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

using System.Runtime.CompilerServices;

namespace IL2C.BasicTypes
{
    [TestCase(true, "IsValueType", 123)]
    [TestCase(false, "IsValueType", "ABC")]
    [TestCase("System.Int32", "ToString", int.MaxValue, IgnoreILErrors = new[] { "ThisMismatch" })]
    [TestCase("System.String", "ToString", "ABC", IgnoreILErrors = new[] { "ThisMismatch" })]
    [TestCase("System.Int32", "GetType", int.MaxValue)]
    [TestCase("System.String", "GetType", "ABC")]
    [TestCase(true, "RefEquals_Same")]
    [TestCase(false, "RefEquals_NotSame")]
    [TestCase(false, "RefEquals", "ABC", "DEF")]
    [TestCase(false, "RefEquals", 123, "ABC")]
    [TestCase(false, "RefEquals", null, "ABC")]
    [TestCase(true, "RefEquals", null, null)]
    public sealed class System_Object
    {
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern bool IsValueType(object value);

        // This is non virtual calling test.
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern string ToString(object value);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern string GetType(object value);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern bool RefEquals_Same();

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern bool RefEquals_NotSame();

        public static bool RefEquals(object value1, object value2)
        {
            return object.ReferenceEquals(value1, value2);
        }
    }
}
