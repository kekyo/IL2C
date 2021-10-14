.class public IL2C.ILConverters.Ldobj
{
    .method public static int32 Ldobj_test_int32i(int32 v, int32[] vs) cil managed
    {
        .maxstack 2
        .locals init (
            int32[] pinned int32Values
        )
        ldarg.1
        stloc.0
        ldloc.0
        ldarg.0
        add
        ldc.i4.8
        add
        ldobj [mscorlib]System.Int32
        ret
    }
}
