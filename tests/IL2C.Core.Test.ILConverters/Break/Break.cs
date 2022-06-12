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
using System.Runtime.InteropServices;

namespace IL2C.ILConverters
{
    public sealed class Break
    {
        [MethodImpl(MethodImplOptions.ForwardRef)]
        private static extern int CauseBreakImpl(int v1, int v2);

        [TestCase(0, "CauseBreak", 100, 23, Assert = TestCaseAsserts.CauseBreak)]
        public static int CauseBreak(int v1, int v2) =>
            // In CoreCLR, break opcode will be ignored.
            IL2CServices.IsInNativeExecution ? CauseBreakImpl(v1, v2) : 0;
    }
}
