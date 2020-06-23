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

namespace IL2C.ILConverters
{
    [TestCase("ABCDEF", "ConcatIfString", "ABC")]
    [TestCase(null, "ConcatIfString", 123)]
    [TestCase(null, "ToStringIfInt32", "ABC")]
    [TestCase("123", "ToStringIfInt32", 123)]
    public sealed class Isinst
    {
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern string ConcatIfString(object value);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern string ToStringIfInt32(object value);
    }
}
