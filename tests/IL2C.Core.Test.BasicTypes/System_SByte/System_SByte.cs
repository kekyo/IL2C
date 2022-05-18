////////////////////////////////////////////////////////////////////////////
//
// IL2C - A translator for ECMA-335 CIL/MSIL to C language.
// Copyright (c) Kouji Matsui (@kozy_kekyo, @kekyo@mastodon.cloud)
//
// Licensed under Apache-v2: https://opensource.org/licenses/Apache-2.0
//
////////////////////////////////////////////////////////////////////////////

using System.Runtime.CompilerServices;

namespace IL2C.BasicTypes
{
    public sealed class System_SByte
    {
        [TestCase(true, "IsValueType")]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern bool IsValueType();

        [TestCase(1, "SizeOf")]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern int SizeOf();

        [TestCase("127", "ToString", sbyte.MaxValue)]
        [TestCase("-128", "ToString", sbyte.MinValue)]
        public static string ToString(sbyte value)
        {
            return value.ToString();
        }

        [TestCase(sbyte.MaxValue, "TryParse", "127")]
        [TestCase(sbyte.MinValue, "TryParse", "-128")]
        public static sbyte TryParse(string str)
        {
            sbyte.TryParse(str, out var value);
            return value;
        }
    }
}
