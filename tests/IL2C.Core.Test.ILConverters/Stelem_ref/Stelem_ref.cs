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
    [TestCase("123", new[] { "Object", "ObjectInner" }, 0, "123")]
    [TestCase("456", new[] { "Object", "ObjectInner" }, 1, "456")]
    [TestCase("789", new[] { "Object", "ObjectInner" }, 2, "789")]
    [TestCase("123", new[] { "ObjectIntPtrIndex", "ObjectIntPtrIndexInner" }, 0, "123")]
    [TestCase("456", new[] { "ObjectIntPtrIndex", "ObjectIntPtrIndexInner" }, 1, "456")]
    [TestCase("789", new[] { "ObjectIntPtrIndex", "ObjectIntPtrIndexInner" }, 2, "789")]
    public sealed class Stelem_ref
    {
        public static string Object(int index, string value)
        {
            var values = new[] { "1", "2", "3" };
            ObjectInner(values, index, value);
            return values[index];
        }

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern void ObjectInner(string[] values, int index, string value);

        public static string ObjectIntPtrIndex(int index, string value)
        {
            var values = new[] { "1", "2", "3" };
            ObjectIntPtrIndexInner(values, index, value);
            return values[index];
        }

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern void ObjectIntPtrIndexInner(string[] values, int index, string value);
    }
}
