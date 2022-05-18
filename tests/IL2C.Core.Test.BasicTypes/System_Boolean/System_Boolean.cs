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
    public sealed class System_Boolean
    {
        [TestCase(true, "IsValueType")]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern bool IsValueType();

        [TestCase(1, "SizeOf")]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern int SizeOf();

        [TestCase("True", "ToString", true)]
        [TestCase("False", "ToString", false)]
        public static string ToString(bool value)
        {
            return value.ToString();
        }

        [TestCase(true, "TryParse", "True")]
        [TestCase(false, "TryParse", "False")]
        public static bool TryParse(string str)
        {
            bool.TryParse(str, out var value);
            return value;
        }
    }
}
