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
    public sealed class Ldnull
    {
            [MethodImpl(MethodImplOptions.ForwardRef)]
            private static extern IntPtr IntPtrZeroImpl();

        // TODO: Unknown failure on mono linux x64
        //   System.InvalidProgramException : Invalid IL code in IL2C.ILConverters.Ldnull:IntPtrZeroImpl (): IL_0001: ret
        [TestCase(0, "IntPtrZero",
            RunOnPlatforms = RunOnPlatforms.DotNet)]
        public static int IntPtrZero() =>
            IntPtrZeroImpl().ToInt32();

            [MethodImpl(MethodImplOptions.ForwardRef)]
            public static extern UIntPtr UIntPtrZeroImpl();

        // TODO: Unknown failure on mono linux x64
        //   System.InvalidProgramException : Invalid IL code in IL2C.ILConverters.Ldnull:UIntPtrZeroImpl (): IL_0001: ret
        [TestCase((uint)0, "UIntPtrZero",
            RunOnPlatforms = RunOnPlatforms.DotNet)]
        public static uint UIntPtrZero() =>
            UIntPtrZeroImpl().ToUInt32();

        [TestCase(null, "NullReference", Assert = TestCaseAsserts.PerfectMatch)]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern object NullReference();
    }
}
