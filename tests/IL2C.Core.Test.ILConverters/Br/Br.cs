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
    [TestCase(5, "Rem2", 12345, 47, 26)]
    public sealed class Br
    {
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern int Rem2(int v, int d1, int d2);
    }
}
