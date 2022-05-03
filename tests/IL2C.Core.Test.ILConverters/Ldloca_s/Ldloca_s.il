.class public IL2C.ILConverters.Ldloca_s
{
    .method public static string True() cil managed
    {
        .maxstack 1
        .locals init (
            [0] bool
        )
        ldc.i4.1
        stloc.s 0
        ldloca.s 0
        call instance string bool::ToString()
        ret
    }

    .method public static string False() cil managed
    {
        .maxstack 1
        .locals init (
            [0] bool
        )
        ldc.i4.0
        stloc.s 0
        ldloca.s 0
        call instance string bool::ToString()
        ret
    }

    .method public static string Byte() cil managed
    {
        .maxstack 1
        .locals init (
            [0] uint8
        )
        ldc.i4 255
        stloc.s 0
        ldloca.s 0
        call instance string uint8::ToString()
        ret
    }

    .method public static string Int16() cil managed
    {
        .maxstack 1
        .locals init (
            [0] int16
        )
        ldc.i4 32767
        stloc.s 0
        ldloca.s 0
        call instance string int16::ToString()
        ret
    }

    .method public static string Int32() cil managed
    {
        .maxstack 1
        .locals init (
            [0] int32
        )
        ldc.i4 2147483647
        stloc.s 0
        ldloca.s 0
        call instance string int32::ToString()
        ret
    }

    .method public static string Int64() cil managed
    {
        .maxstack 1
        .locals init (
            [0] int64
        )
        ldc.i8 9223372036854775807
        stloc.s 0
        ldloca.s 0
        call instance string int64::ToString()
        ret
    }

    .method public static string SByte() cil managed
    {
        .maxstack 1
        .locals init (
            [0] int8
        )
        ldc.i4 127
        stloc.s 0
        ldloca.s 0
        call instance string int8::ToString()
        ret
    }

    .method public static string UInt16() cil managed
    {
        .maxstack 1
        .locals init (
            [0] uint16
        )
        ldc.i4 65535
        stloc.s 0
        ldloca.s 0
        call instance string uint16::ToString()
        ret
    }

    .method public static string UInt32() cil managed
    {
        .maxstack 1
        .locals init (
            [0] uint32
        )
        ldc.i4 4294967295
        conv.u4
        stloc.s 0
        ldloca.s 0
        call instance string uint32::ToString()
        ret
    }

    .method public static string UInt64() cil managed
    {
        .maxstack 1
        .locals init (
            [0] uint64
        )
        ldc.i8 18446744073709551615
        conv.u8
        stloc.s 0
        ldloca.s 0
        call instance string uint64::ToString()
        ret
    }
    
    .method public static string IntPtr() cil managed
    {
        .maxstack 1
        .locals init (
            [0] native int
        )
        ldc.i4 2147483647
        conv.i
        stloc.s 0
        ldloca.s 0
        call instance string native int::ToString()
        ret
    }
    
    .method public static string UIntPtr() cil managed
    {
        .maxstack 1
        .locals init (
            [0] native uint
        )
        ldc.i4 4294967295
        conv.u
        stloc.s 0
        ldloca.s 0
        call instance string native uint::ToString()
        ret
    }

    .method public static string Single() cil managed
    {
        .maxstack 1
        .locals init (
            [0] float32
        )
        ldc.r4 3.14159274
        stloc.s 0
        ldloca.s 0
        call instance string float32::ToString()
        ret
    }

    .method public static string Double() cil managed
    {
        .maxstack 1
        .locals init (
            [0] float64
        )
        ldc.r8 3.1415926535897931
        stloc.s 0
        ldloca.s 0
        call instance string float64::ToString()
        ret
    }

    .method public static string Char() cil managed
    {
        .maxstack 1
        .locals init (
            [0] char
        )
        ldc.i4.s 0x41
        stloc.s 0
        ldloca.s 0
        call instance string char::ToString()
        ret
    }

    .method public static string String() cil managed
    {
        .maxstack 1
        .locals init (
            [0] string
        )
        ldloca.s 0
        call void IL2C.ILConverters.Ldloca_s::UpdateString(string&)
        ldloc.0
        ret
    }

    .method public static string LocalVariable_255() cil managed
    {
        .maxstack 1
        .locals init (
            [0x00] int32, [0x01] int32, [0x02] int32, [0x03] int32, [0x04] int32, [0x05] int32, [0x06] int32, [0x07] int32,
            [0x08] int32, [0x09] int32, [0x0a] int32, [0x0b] int32, [0x0c] int32, [0x0d] int32, [0x0e] int32, [0x0f] int32,
            [0x10] int32, [0x11] int32, [0x12] int32, [0x13] int32, [0x14] int32, [0x15] int32, [0x16] int32, [0x17] int32,
            [0x18] int32, [0x19] int32, [0x1a] int32, [0x1b] int32, [0x1c] int32, [0x1d] int32, [0x1e] int32, [0x1f] int32,
            [0x20] int32, [0x21] int32, [0x22] int32, [0x23] int32, [0x24] int32, [0x25] int32, [0x26] int32, [0x27] int32,
            [0x28] int32, [0x29] int32, [0x2a] int32, [0x2b] int32, [0x2c] int32, [0x2d] int32, [0x2e] int32, [0x2f] int32,
            [0x30] int32, [0x31] int32, [0x32] int32, [0x33] int32, [0x34] int32, [0x35] int32, [0x36] int32, [0x37] int32,
            [0x38] int32, [0x39] int32, [0x3a] int32, [0x3b] int32, [0x3c] int32, [0x3d] int32, [0x3e] int32, [0x3f] int32,
            [0x40] int32, [0x41] int32, [0x42] int32, [0x43] int32, [0x44] int32, [0x45] int32, [0x46] int32, [0x47] int32,
            [0x48] int32, [0x49] int32, [0x4a] int32, [0x4b] int32, [0x4c] int32, [0x4d] int32, [0x4e] int32, [0x4f] int32,
            [0x50] int32, [0x51] int32, [0x52] int32, [0x53] int32, [0x54] int32, [0x55] int32, [0x56] int32, [0x57] int32,
            [0x58] int32, [0x59] int32, [0x5a] int32, [0x5b] int32, [0x5c] int32, [0x5d] int32, [0x5e] int32, [0x5f] int32,
            [0x60] int32, [0x61] int32, [0x62] int32, [0x63] int32, [0x64] int32, [0x65] int32, [0x66] int32, [0x67] int32,
            [0x68] int32, [0x69] int32, [0x6a] int32, [0x6b] int32, [0x6c] int32, [0x6d] int32, [0x6e] int32, [0x6f] int32,
            [0x70] int32, [0x71] int32, [0x72] int32, [0x73] int32, [0x74] int32, [0x75] int32, [0x76] int32, [0x77] int32,
            [0x78] int32, [0x79] int32, [0x7a] int32, [0x7b] int32, [0x7c] int32, [0x7d] int32, [0x7e] int32, [0x7f] int32,
            [0x80] int32, [0x81] int32, [0x82] int32, [0x83] int32, [0x84] int32, [0x85] int32, [0x86] int32, [0x87] int32,
            [0x88] int32, [0x89] int32, [0x8a] int32, [0x8b] int32, [0x8c] int32, [0x8d] int32, [0x8e] int32, [0x8f] int32,
            [0x90] int32, [0x91] int32, [0x92] int32, [0x93] int32, [0x94] int32, [0x95] int32, [0x96] int32, [0x97] int32,
            [0x98] int32, [0x99] int32, [0x9a] int32, [0x9b] int32, [0x9c] int32, [0x9d] int32, [0x9e] int32, [0x9f] int32,
            [0xa0] int32, [0xa1] int32, [0xa2] int32, [0xa3] int32, [0xa4] int32, [0xa5] int32, [0xa6] int32, [0xa7] int32,
            [0xa8] int32, [0xa9] int32, [0xaa] int32, [0xab] int32, [0xac] int32, [0xad] int32, [0xae] int32, [0xaf] int32,
            [0xb0] int32, [0xb1] int32, [0xb2] int32, [0xb3] int32, [0xb4] int32, [0xb5] int32, [0xb6] int32, [0xb7] int32,
            [0xb8] int32, [0xb9] int32, [0xba] int32, [0xbb] int32, [0xbc] int32, [0xbd] int32, [0xbe] int32, [0xbf] int32,
            [0xc0] int32, [0xc1] int32, [0xc2] int32, [0xc3] int32, [0xc4] int32, [0xc5] int32, [0xc6] int32, [0xc7] int32,
            [0xc8] int32, [0xc9] int32, [0xca] int32, [0xcb] int32, [0xcc] int32, [0xcd] int32, [0xce] int32, [0xcf] int32,
            [0xd0] int32, [0xd1] int32, [0xd2] int32, [0xd3] int32, [0xd4] int32, [0xd5] int32, [0xd6] int32, [0xd7] int32,
            [0xd8] int32, [0xd9] int32, [0xda] int32, [0xdb] int32, [0xdc] int32, [0xdd] int32, [0xde] int32, [0xdf] int32,
            [0xe0] int32, [0xe1] int32, [0xe2] int32, [0xe3] int32, [0xe4] int32, [0xe5] int32, [0xe6] int32, [0xe7] int32,
            [0xe8] int32, [0xe9] int32, [0xea] int32, [0xeb] int32, [0xec] int32, [0xed] int32, [0xee] int32, [0xef] int32,
            [0xf0] int32, [0xf1] int32, [0xf2] int32, [0xf3] int32, [0xf4] int32, [0xf5] int32, [0xf6] int32, [0xf7] int32,
            [0xf8] int32, [0xf9] int32, [0xfa] int32, [0xfb] int32, [0xfc] int32, [0xfd] int32, [0xfe] int32,
            [0xff] string
        )
        ldloca.s 255
        call void IL2C.ILConverters.Ldloca_s::UpdateString(string&)
        ldloc.s 255
        ret
    }
}
