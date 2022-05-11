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
    [TestCase(123, "Int32Value")]
    [TestCase("ABC", "StringValue")]
    [TestCase(null, "NullValue")]
    [TestCase(123, new[] { "RefIntValue", "Return_RefInt" }, true)]
    [TestCase(456, new[] { "RefIntValue", "Return_RefInt" }, false)]
    [TestCase(null, "Void")]
    public sealed class Ret
    {
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern int Int32Value();

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern string StringValue();

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern object NullValue();

        [MethodImpl(MethodImplOptions.ForwardRef)]
        private static extern ref int Return_RefInt(ref int a, ref int b, bool select);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern int RefIntValue(bool select);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern void Void();
    }
}
