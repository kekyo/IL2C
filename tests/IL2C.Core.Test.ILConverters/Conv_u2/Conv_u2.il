.class public IL2C.ILConverters.Conv_u2
{
    .method public static uint16 Int32(int32 v) cil managed
    {
        .maxstack 1
        ldarg.0
        conv.u2
        ret
    }

    .method public static uint16 Int64(int64 v) cil managed
    {
        .maxstack 1
        ldarg.0
        conv.u2
        ret
    }

    .method public static uint16 IntPtr(native int v) cil managed
    {
        .maxstack 1
        ldarg.0
        conv.u2
        ret
    }

    .method public static uint16 Single(float32 v) cil managed
    {
        .maxstack 1
        ldarg.0
        conv.u2
        ret
    }

    .method public static uint16 Double(float64 v) cil managed
    {
        .maxstack 1
        ldarg.0
        conv.u2
        ret
    }
}
