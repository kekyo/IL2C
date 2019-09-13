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
    [TestCase(8, "SizeOf")]
    [TestCase("9223372036854775807", "ToString", long.MaxValue)]
    [TestCase("-9223372036854775807", "ToString", long.MinValue + 1)]
    [TestCase("-9223372036854775808", "ToString", long.MinValue)]        // It's special case for internal
    [TestCase(long.MaxValue, "TryParse", "9223372036854775807")]
    [TestCase(long.MinValue, "TryParse", "-9223372036854775808")]
    public sealed class System_Int64
    {
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern bool IsValueType();

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern int SizeOf();

        public static string ToString(long value)
        {
            return value.ToString();
        }

        public static long TryParse(string str)
        {
            long.TryParse(str, out var value);
            return value;
        }
    }
}
