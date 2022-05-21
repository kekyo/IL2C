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
    public sealed class Stloc_0
    {
        [TestCase(true, "True")]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern bool True();

        [TestCase(false, "False")]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern bool False();

        [TestCase(byte.MaxValue, "Byte")]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern byte Byte();

        [TestCase(short.MaxValue, "Int16")]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern short Int16();

        [TestCase(int.MaxValue, "Int32")]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern int Int32();

        [TestCase(long.MaxValue, "Int64")]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern long Int64();

        [TestCase(sbyte.MaxValue, "SByte")]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern sbyte SByte();

        [TestCase(ushort.MaxValue, "UInt16")]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern ushort UInt16();

        [TestCase(uint.MaxValue, "UInt32")]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern uint UInt32();

        [TestCase(ulong.MaxValue, "UInt64")]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern ulong UInt64();

        [TestCase(int.MaxValue, "IntPtr")]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern IntPtr IntPtr();

        [TestCase(uint.MaxValue, "UIntPtr")]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern UIntPtr UIntPtr();

        [TestCase(3.14159274f, "Single")]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern float Single();

        [TestCase(3.1415926535897931, "Double")]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern double Double();

        [TestCase('A', "Char")]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern char Char();

        [TestCase("ABC", "String")]
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern string String();
    }
}
