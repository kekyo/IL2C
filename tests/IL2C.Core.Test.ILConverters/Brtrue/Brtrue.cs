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
    [TestCase("ABC", "FlagValue", true)]
    [TestCase("DEF", "FlagValue", false)]
    [TestCase("ABC", "Int32Value", 100)]
    [TestCase("DEF", "Int32Value", 0)]
    [TestCase("ABC", "Int32Value", -100)]
    [TestCase("ABC", "IntPtrValue", 100)]
    [TestCase("DEF", "IntPtrValue", 0)]
    [TestCase("ABC", "IntPtrValue", -100)]
    [TestCase("ABC", "ObjectValue", "")]
    [TestCase("DEF", "ObjectValue", null)]
    public sealed class Brtrue
    {
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern string FlagValue(bool v);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern string Int32Value(int v);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern string IntPtrValue(IntPtr v);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern string ObjectValue(object v);
    }
}
