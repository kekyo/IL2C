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
    [TestCase(4, "SizeOf")]
    [TestCase("2147483647", "ToString", int.MaxValue)]
    [TestCase("-2147483647", "ToString", int.MinValue + 1)]
    [TestCase("-2147483648", "ToString", int.MinValue)]        // It's special case for internal
    [TestCase(int.MaxValue, "TryParse", "2147483647")]
    [TestCase(int.MinValue, "TryParse", "-2147483648")]
    public sealed class System_Int32
    {
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern bool IsValueType();

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern int SizeOf();

        public static string ToString(int value)
        {
            return value.ToString();
        }

        public static int TryParse(string str)
        {
            int.TryParse(str, out var value);
            return value;
        }
    }
}
