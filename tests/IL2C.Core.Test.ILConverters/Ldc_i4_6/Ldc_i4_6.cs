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
    public sealed class Ldc_i4_6
    {
        [TestCase(6, "RawValue")]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern int RawValue();

        [TestCase(10, "Add", 4)]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern int Add(int num);
    }
}
