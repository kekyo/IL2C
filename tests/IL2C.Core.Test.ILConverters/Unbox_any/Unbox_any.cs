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
    public sealed class Unbox_any
    {
        [MethodImpl(MethodImplOptions.ForwardRef)]
        private static extern int Unbox_Int32(object value);

        [TestCase(true, new[] { "Int32", "Unbox_Int32" }, 123)]
        public static bool Int32(object value)
        {
            var ub = Unbox_Int32(value);
            return ub == 123;
        }

        // https://github.com/kekyo/IL2C/issues/37
        [TestCase(124, "FromValueType", 123)]
        public static int FromValueType(int value)
        {
            ValueType v = value + 1;    // boxed
            return (int)v;
        }
    }
}
