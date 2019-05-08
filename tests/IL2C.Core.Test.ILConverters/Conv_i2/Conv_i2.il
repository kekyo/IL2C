.class public IL2C.ILConverters.Conv_i2
{
    .method public static int16 Int32(int32 v) cil managed
    {
        .maxstack 1
        ldarg.0
        conv.i2
        ret
    }

    .method public static int16 Int64(int64 v) cil managed
    {
        .maxstack 1
        ldarg.0
        conv.i2
        ret
    }

    .method public static int16 IntPtr(native int v) cil managed
    {
        .maxstack 1
        ldarg.0
        conv.i2
        ret
    }

    .method public static int16 Single(float32 v) cil managed
    {
        .maxstack 1
        ldarg.0
        conv.i2
        ret
    }

    .method public static int16 Double(float64 v) cil managed
    {
        .maxstack 1
        ldarg.0
        conv.i2
        ret
    }
}
