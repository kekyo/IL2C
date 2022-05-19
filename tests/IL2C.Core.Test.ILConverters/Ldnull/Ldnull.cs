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
        [TestCase(0, "IntPtrZero")]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern IntPtr IntPtrZero();

        [TestCase((uint)0, "UIntPtrZero")]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern UIntPtr UIntPtrZero();

        [TestCase(null, "NullReference")]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern object NullReference();
    }
}
