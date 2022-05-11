////////////////////////////////////////////////////////////////////////////
//
// IL2C - A translator for ECMA-335 CIL/MSIL to C language.
// Copyright (c) Kouji Matsui (@kozy_kekyo, @kekyo@mastodon.cloud)
//
// Licensed under Apache-v2: https://opensource.org/licenses/Apache-2.0
//
////////////////////////////////////////////////////////////////////////////

using System;

namespace System.Runtime.InteropServices
{
    public struct NativePointer
    {
        private readonly IntPtr pointer;

        private NativePointer(IntPtr value) => this.pointer = value;

        public static implicit operator NativePointer(IntPtr value) => new NativePointer(value);
        public static implicit operator IntPtr(NativePointer value) => value.pointer;
    }
}
