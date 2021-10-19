.class public IL2C.ILConverters.Stobj
{
    .method public static void Stobj_test_uint8(uint8 v, [out] uint8& result) cil managed
    {
        .maxstack 2
        ldarg.s 1
        ldarg.s 0
        stobj [mscorlib]System.Byte
        ret
    }

    .method public static void Stobj_test_uint16(uint16 v, [out] uint16& result) cil managed
    {
        .maxstack 2
        ldarg.s 1
        ldarg.s 0
        stobj [mscorlib]System.UInt16
        ret
    }

    .method public static void Stobj_test_int32(int32 v, [out] int32& result) cil managed
    {
        .maxstack 2
        ldarg.s 1
        ldarg.s 0
        stobj [mscorlib]System.Int32
        ret
    }

    .method public static void Stobj_test_int64(int64 v, [out] int64& result) cil managed
    {
        .maxstack 2
        ldarg.s 1
        ldarg.s 0
        stobj [mscorlib]System.Int64
        ret
    }

    .method public static void Stobj_test_uint64(uint64 v, [out] uint64& result) cil managed
    {
        .maxstack 2
        ldarg.s 1
        ldarg.s 0
        stobj [mscorlib]System.UInt64
        ret
    }

    .method public static void Stobj_test_float(float32 v, [out] float32& result) cil managed
    {
        .maxstack 2
        ldarg.s 1
        ldarg.s 0
        stobj [mscorlib]System.Single
        ret
    }

    .method public static void Stobj_test_double(float64 v, [out] float64& result) cil managed
    {
        .maxstack 2
        ldarg.s 1
        ldarg.s 0
        stobj [mscorlib]System.Double
        ret
    }

    .method public static void Stobj_test_Point(valuetype IL2C.ILConverters.Point v, [out] valuetype IL2C.ILConverters.Point& result) cil managed
    {
        .maxstack 2
        ldarg.s 1
        ldarg.s 0
        stobj IL2C.ILConverters.Point
        ret
    }
}
