.class public IL2C.ILConverters.Conv_u1
{
    .method public static uint8 Int32(int32 v) cil managed
    {
        .maxstack 1
        ldarg.0
        conv.u1
        ret
    }

    .method public static uint8 Int64(int64 v) cil managed
    {
        .maxstack 1
        ldarg.0
        conv.u1
        ret
    }

    .method public static uint8 IntPtr(native int v) cil managed
    {
        .maxstack 1
        ldarg.0
        conv.u1
        ret
    }

    .method public static uint8 Single(float32 v) cil managed
    {
        .maxstack 1
        ldarg.0
        conv.u1
        ret
    }

    .method public static uint8 Double(float64 v) cil managed
    {
        .maxstack 1
        ldarg.0
        conv.u1
        ret
    }
}
