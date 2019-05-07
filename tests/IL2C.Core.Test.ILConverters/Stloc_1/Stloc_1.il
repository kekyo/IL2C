.class public IL2C.ILConverters.Stloc_1
{
    .method public static bool True() cil managed
    {
        .maxstack 1
        .locals init (
            [0] int32,
            [1] bool
        )
        ldc.i4.1
        stloc.1
        ldloc.1
        ret
    }

    .method public static bool False() cil managed
    {
        .maxstack 1
        .locals init (
            [0] int32,
            [1] bool
        )
        ldc.i4.0
        stloc.1
        ldloc.1
        ret
    }

    .method public static uint8 Byte() cil managed
    {
        .maxstack 1
        .locals init (
            [0] int32,
            [1] uint8
        )
        ldc.i4 255
        stloc.1
        ldloc.1
        ret
    }

    .method public static int16 Int16() cil managed
    {
        .maxstack 1
        .locals init (
            [0] int32,
            [1] int16
        )
        ldc.i4 32767
        stloc.1
        ldloc.1
        ret
    }

    .method public static int32 Int32() cil managed
    {
        .maxstack 1
        .locals init (
            [0] int32,
            [1] int32
        )
        ldc.i4 2147483647
        stloc.1
        ldloc.1
        ret
    }

    .method public static int64 Int64() cil managed
    {
        .maxstack 1
        .locals init (
            [0] int32,
            [1] int64
        )
        ldc.i8 9223372036854775807
        stloc.1
        ldloc.1
        ret
    }

    .method public static int8 SByte() cil managed
    {
        .maxstack 1
        .locals init (
            [0] int32,
            [1] int8
        )
        ldc.i4 127
        stloc.1
        ldloc.1
        ret
    }

    .method public static uint16 UInt16() cil managed
    {
        .maxstack 1
        .locals init (
            [0] int32,
            [1] uint16
        )
        ldc.i4 65535
        stloc.1
        ldloc.1
        ret
    }

    .method public static uint32 UInt32() cil managed
    {
        .maxstack 1
        .locals init (
            [0] int32,
            [1] uint32
        )
        ldc.i4 4294967295
        conv.u4
        stloc.1
        ldloc.1
        ret
    }

    .method public static uint64 UInt64() cil managed
    {
        .maxstack 1
        .locals init (
            [0] int32,
            [1] uint64
        )
        ldc.i8 18446744073709551615
        conv.u8
        stloc.1
        ldloc.1
        ret
    }
    
    .method public static native int IntPtr() cil managed
    {
        .maxstack 1
        .locals init (
            [0] int32,
            [1] native int
        )
        ldc.i4 2147483647
        conv.i
        stloc.1
        ldloc.1
        ret
    }
    
    .method public static native uint UIntPtr() cil managed
    {
        .maxstack 1
        .locals init (
            [0] int32,
            [1] native uint
        )
        ldc.i4 4294967295
        conv.u
        stloc.1
        ldloc.1
        ret
    }

    .method public static float32 Single() cil managed
    {
        .maxstack 1
        .locals init (
            [0] int32,
            [1] float32
        )
        ldc.r4 3.14159274
        stloc.1
        ldloc.1
        ret
    }

    .method public static float64 Double() cil managed
    {
        .maxstack 1
        .locals init (
            [0] int32,
            [1] float64
        )
        ldc.r8 3.1415926535897931
        stloc.1
        ldloc.1
        ret
    }

    .method public static char Char() cil managed
    {
        .maxstack 1
        .locals init (
            [0] int32,
            [1] char
        )
        ldc.i4.s 0x41
        stloc.1
        ldloc.1
        ret
    }

    .method public static string String() cil managed
    {
        .maxstack 1
        .locals init (
            [0] int32,
            [1] string
        )
        ldstr "ABC"
        stloc.1
        ldloc.1
        ret
    }
}
