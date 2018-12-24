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
