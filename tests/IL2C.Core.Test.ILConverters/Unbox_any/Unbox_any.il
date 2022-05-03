.class public IL2C.ILConverters.Unbox_any
{
    .method public static int32 Unbox_Int32(object v) cil managed
    {
        .maxstack 1
        ldarg.0
        unbox.any int32
        ret
    }
}
