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
    // Some tests are using the IgnoreInvokeResult flag, because float string format is bit different (but no problem.)
    [TestCase(true, "IsValueType")]
    [TestCase(8, "SizeOf")]
    [TestCase("1.79769313486232e+308", "ToString", double.MaxValue, Assert = TestCaseAsserts.IgnoreValidateInvokeResult)]    // Real value is 1.7976931348623157E+308
    [TestCase("-1.79769313486232e+308", "ToString", double.MinValue, Assert = TestCaseAsserts.IgnoreValidateInvokeResult)]   // Real value is -1.7976931348623157E+308
    [TestCase(double.MaxValue, "TryParse", "1.7976931348623157E+308")]
    [TestCase(double.MinValue, "TryParse", "-1.7976931348623157E+308")]
    public sealed class System_Double
    {
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern bool IsValueType();

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern int SizeOf();

        public static string ToString(double value)
        {
            return value.ToString();
        }

        public static double TryParse(string str)
        {
            double.TryParse(str, out var value);
            return value;
        }
    }
}
