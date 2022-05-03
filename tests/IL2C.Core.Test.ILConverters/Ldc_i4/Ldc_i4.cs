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
    [TestCase(int.MaxValue, "MaxValue")]
    [TestCase(int.MinValue, "MinValue")]
    public sealed class Ldc_i4
    {
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern int MaxValue();

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern int MinValue();
    }
}
