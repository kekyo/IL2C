////////////////////////////////////////////////////////////////////////////
//
// IL2C - A translator for ECMA-335 CIL/MSIL to C language.
// Copyright (c) Kouji Matsui (@kozy_kekyo, @kekyo@mastodon.cloud)
//
// Licensed under Apache-v2: https://opensource.org/licenses/Apache-2.0
//
////////////////////////////////////////////////////////////////////////////

using System.Runtime.CompilerServices;

namespace IL2C.ILConverters
{
    public sealed class Ldc_i4_s
    {
        [TestCase(127, "Plus127Value")]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern int Plus127Value();

        [TestCase(-128, "Minus128Value")]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern int Minus128Value();
    }
}
