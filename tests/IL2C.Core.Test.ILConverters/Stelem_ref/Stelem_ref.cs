////////////////////////////////////////////////////////////////////////////
//
// IL2C - A translator for ECMA-335 CIL/MSIL to C language.
// Copyright (c) Kouji Matsui (@kozy_kekyo, @kekyo@mastodon.cloud)
//
// Licensed under Apache-v2: https://opensource.org/licenses/Apache-2.0
//
////////////////////////////////////////////////////////////////////////////

using System;
using System.Runtime.CompilerServices;

namespace IL2C.ILConverters
{
    public sealed class Stelem_ref
    {
        [TestCase("123", new[] { "Object", "ObjectInner" }, 0, "123")]
        [TestCase("456", new[] { "Object", "ObjectInner" }, 1, "456")]
        [TestCase("789", new[] { "Object", "ObjectInner" }, 2, "789")]
        public static string Object(int index, string value)
        {
            var values = new[] { "1", "2", "3" };
            ObjectInner(values, index, value);
            return values[index];
        }

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern void ObjectInner(string[] values, int index, string value);

        [TestCase("123", new[] { "ObjectIntPtrIndex", "ObjectIntPtrIndexInner" }, 0, "123")]
        [TestCase("456", new[] { "ObjectIntPtrIndex", "ObjectIntPtrIndexInner" }, 1, "456")]
        [TestCase("789", new[] { "ObjectIntPtrIndex", "ObjectIntPtrIndexInner" }, 2, "789")]
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
