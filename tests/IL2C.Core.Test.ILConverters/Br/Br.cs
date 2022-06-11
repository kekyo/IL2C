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
    public sealed class Br
    {
        // TODO: Unknown failure on mono linux x64
        //   System.InvalidProgramException : System.InvalidProgramException : Invalid IL code in IL2C.ILConverters.Br:Rem2 (int,int,int): IL_0007: rem
        [TestCase(5, "Rem2", 12345, 47, 26,
            RunOnPlatforms = RunOnPlatforms.DotNet)]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern int Rem2(int v, int d1, int d2);
    }
}
