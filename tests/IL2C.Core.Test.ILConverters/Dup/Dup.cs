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
    public sealed class Dup
    {
        [TestCase(246, "Mul2Int32", 123)]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern int Mul2Int32(int value);

        [TestCase("ABCABC", "Mul2String", "ABC")]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern string Mul2String(string value);
    }
}
