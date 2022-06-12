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
    public sealed class Ldc_r8
    {
        [TestCase(double.MaxValue, "MaxValue")]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern double MaxValue();

        [TestCase(double.MinValue, "MinValue")]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern double MinValue();
    }
}
