.class public IL2C.ILConverters.Ldobj
{
    .method public static int32 Ldobj_test_int32(int32 v) cil managed
    {
        .maxstack 1
        ldarga.s 0
        ldobj [mscorlib]System.Int32
        ret
    }

    /*
    .method public static valuetype Point Ldobj_test_Point(valuetype Point v) cil managed
    {
        .maxstack 1
        ldarga.s 0
        ldobj valuetype Point
        ret
    }
    */
}
