using System;

namespace System.Runtime.InteropServices
{
    public struct NativePointer
    {
        public readonly IntPtr Pointer;

        private NativePointer(IntPtr value) => this.Pointer = value;

        public override bool Equals(object obj)
        {
            return this.Pointer.Equals(obj);
        }

        public override int GetHashCode()
        {
            return this.Pointer.GetHashCode();
        }

        public override string ToString()
        {
            return this.Pointer.ToString();
        }

        public static bool operator !(NativePointer pointer) => pointer.Pointer == IntPtr.Zero;
        public static implicit operator bool(NativePointer pointer) => pointer.Pointer != IntPtr.Zero;
        public static implicit operator NativePointer(IntPtr value) => new NativePointer(value);
        public static implicit operator IntPtr(NativePointer pointer) => new NativePointer(pointer);
    }
}
