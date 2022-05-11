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
    [TestCase(0, "CauseBreak", 100, 23, Assert = TestCaseAsserts.CauseBreak)]
    public sealed class Break
    {
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern int CauseBreak(int v1, int v2);
    }
}
