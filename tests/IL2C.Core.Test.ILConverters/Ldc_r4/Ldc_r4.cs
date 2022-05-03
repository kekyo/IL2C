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
    [TestCase(float.MaxValue, "MaxValue")]
    [TestCase(float.MinValue, "MinValue")]
    public sealed class Ldc_r4
    {
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern float MaxValue();

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern float MinValue();
    }
}
