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
    [TestCase(true, "IsValueType")]
    [TestCase(2, "SizeOf")]
    [TestCase("\u0000", "ToStringMin")]
    [TestCase("\uffff", "ToStringMax")]
    [TestCase(char.MinValue, "TryParseMin")]
    [TestCase(char.MaxValue, "TryParseMax")]
    public sealed class System_Char
    {
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern bool IsValueType();

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern int SizeOf();

        ///////////////////////////////
        // NUnit (or visual studio test engine) problem:
        //   Will apply unique test case names with overload arguments.
        //   (ex: ToString("\u0000") and ToString("\uffff") if apply sets for test methods)
        //   But cause failed conflicting both these test case names (maybe contains invalid char).

        public static string ToStringMin()
        {
            char value = char.MinValue;
            return value.ToString();
        }

        public static string ToStringMax()
        {
            char value = char.MaxValue;
            return value.ToString();
        }

        public static char TryParseMin()
        {
            char.TryParse("\u0000", out var value);
            return value;
        }

        public static char TryParseMax()
        {
            char.TryParse("\uffff", out var value);
            return value;
        }
    }
}
