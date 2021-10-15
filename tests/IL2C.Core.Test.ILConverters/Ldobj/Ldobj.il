.class public IL2C.ILConverters.Ldobj
{
    .method public static uint8 Ldobj_test_uint8(uint8 v) cil managed
    {
        .maxstack 1
        ldarga.s 0
        ldobj [mscorlib]System.Byte
        ret
    }
    .method public static uint16 Ldobj_test_uint16(uint16 v) cil managed
    {
        .maxstack 1
        ldarga.s 0
        ldobj [mscorlib]System.UInt16
        ret
    }

    .method public static int32 Ldobj_test_int32(int32 v) cil managed
    {
        .maxstack 1
        ldarga.s 0
        ldobj [mscorlib]System.Int32
        ret
    }

    .method public static int64 Ldobj_test_int64(int64 v) cil managed
    {
        .maxstack 1
        ldarga.s 0
        ldobj [mscorlib]System.Int64
        ret
    }

    .method public static uint64 Ldobj_test_uint64(uint64 v) cil managed
    {
        .maxstack 1
        ldarga.s 0
        ldobj [mscorlib]System.UInt64
        ret
    }
    
    .method public static valuetype IL2C.ILConverters.Point Ldobj_test_Point(valuetype IL2C.ILConverters.Point v) cil managed
    {
        .maxstack 1
        ldarga.s 0
        ldobj valuetype IL2C.ILConverters.Point
        ret
    }
    
}
