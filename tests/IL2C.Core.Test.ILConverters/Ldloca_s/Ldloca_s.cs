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
    public sealed class Ldloca_s
    {
        [TestCase("True", "True")]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern string True();

        [TestCase("False", "False")]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern string False();

        [TestCase("255", "Byte")]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern string Byte();

        [TestCase("32767", "Int16")]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern string Int16();

        [TestCase("2147483647", "Int32")]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern string Int32();

        [TestCase("9223372036854775807", "Int64")]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern string Int64();

        [TestCase("127", "SByte")]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern string SByte();

        [TestCase("65535", "UInt16")]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern string UInt16();

        [TestCase("4294967295", "UInt32")]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern string UInt32();

        [TestCase("18446744073709551615", "UInt64")]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern string UInt64();

        [TestCase("2147483647", "IntPtr")]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern string IntPtr();

        [TestCase("4294967295", "UIntPtr")]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern string UIntPtr();

            [MethodImpl(MethodImplOptions.ForwardRef)]
            private static extern string SingleImpl();

        [TestCase("3.1415927", "Single")]
        public static string Single() =>
#if NETFRAMEWORK
            // Ignore validation because .NET Framework CLR precision is poor.
            IL2CServices.IsInNativeExecution ? SingleImpl() : "3.1415927";
#else
            SingleImpl();
#endif

            [MethodImpl(MethodImplOptions.ForwardRef)]
            private static extern string DoubleImpl();

        [TestCase("3.141592653589793", "Double")]   // Lost last 1 digits via ToString conversion.
        public static string Double() =>
#if NETFRAMEWORK
            // Ignore validation because .NET Framework CLR precision is poor.
            IL2CServices.IsInNativeExecution ? DoubleImpl() : "3.141592653589793";
#else
            DoubleImpl();
#endif

        [TestCase("A", "Char")]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern string Char();

        public static void UpdateString(ref string value)
        {
            value = "ABC";
        }

        [TestCase("ABC", new[] { "String", "UpdateString" })]               // Translation will include UpdateString method
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern string String();

        [TestCase("ABC", new[] { "LocalVariable_255", "UpdateString" })]    // Translation will include UpdateString method
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern string LocalVariable_255();
    }
}
