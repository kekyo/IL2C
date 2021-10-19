using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading.Tasks;

namespace IL2C.ILConverters
{
    [TestCase(~(sbyte)0x12, "Not_int8", (sbyte)0x12)]
    [TestCase(~(byte)0x12, "Not_uint8", (byte)0x12)]
    [TestCase(~(short)0x1234, "Not_int16", (short)0x1234)]
    [TestCase(~(ushort)0x1234, "Not_uint16", (ushort)0x1234)]
    [TestCase(~(int)0x12345678, "Not_int32", (int)0x12345678)]
    [TestCase(~(uint)0x12345678, "Not_uint32", (uint)0x12345678)]
    [TestCase(~(long)0x12345678, "Not_int64", (long)0x12345678)]
    [TestCase(~(ulong)0x12345678, "Not_uint64", (ulong)0x12345678)]
    [TestCase(-1, "Not_IntPtr", 0)]
    [TestCase(-1, "Not_UIntPtr", 0)]
    public sealed class Not
    {
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern sbyte Not_int8(sbyte v);
        
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern byte Not_uin8(byte v);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern short Not_int16(short v);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern ushort Not_uint16(short v);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern int Not_int32(int v);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern uint Not_uint32(uint v);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern long Not_int64(long v);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern ulong Not_uint64(ulong v);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern IntPtr Not_IntPtr(IntPtr v);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern UIntPtr Not_UIntPtr(UIntPtr v);
    }
}
