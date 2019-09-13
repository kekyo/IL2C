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

namespace IL2C.BasicTypes
{
    [TestCase("System.Int32", "FullName", 123)]
    [TestCase("System.String", "FullName", "ABC")]
    // System.Type.ToString() implementation has concatenation for "Type: " header, but the System.RuntimeType do not.
    [TestCase("System.Int32", "ToString", 123)]
    [TestCase("System.String", "ToString", "ABC")]
    [TestCase("System.ValueType", "BaseType", 123)]
    [TestCase("System.Object", "BaseType", "ABC")]
    [TestCase(null, "Object_BaseType")]
    public sealed class System_Type
    {
        public static string ToString(object value)
        {
            return value.GetType().ToString();
        }

        public static string FullName(object value)
        {
            return value.GetType().FullName;
        }

        public static string BaseType(object value)
        {
            return value.GetType().BaseType.FullName;
        }

        public static Type Object_BaseType()
        {
            // TODO: We have to handle GetTypeFromHandle.
            //return typeof(object).BaseType;
            return 123.GetType().BaseType.BaseType.BaseType;
        }
    }
}
