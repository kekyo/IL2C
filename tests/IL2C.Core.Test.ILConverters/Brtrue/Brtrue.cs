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
    public sealed class Brtrue
    {
        [TestCase("ABC", "FlagValue", true)]
        [TestCase("DEF", "FlagValue", false)]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern string FlagValue(bool v);

        [TestCase("ABC", "Int32Value", 100)]
        [TestCase("DEF", "Int32Value", 0)]
        [TestCase("ABC", "Int32Value", -100)]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern string Int32Value(int v);

            [MethodImpl(MethodImplOptions.ForwardRef)]
            private static extern string IntPtrValueImpl(IntPtr v);

        [TestCase("ABC", "IntPtrValue", 100)]
        [TestCase("DEF", "IntPtrValue", 0)]
        [TestCase("ABC", "IntPtrValue", -100)]
        public static string IntPtrValue(int v) =>
            IntPtrValueImpl((IntPtr)v);

        [TestCase("ABC", "ObjectValue", "")]
        [TestCase("DEF", "ObjectValue", null!)]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern string ObjectValue(object v);
    }
}
