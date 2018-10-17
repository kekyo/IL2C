.class public IL2C.ILConverters.Conv_i
{
    .method public static native int Int32(int32 v) cil managed
    {
        .maxstack 1
        ldarg.0
        conv.i
        ret
    }

    .method public static native int Int64(int64 v) cil managed
    {
        .maxstack 1
        ldarg.0
        conv.i
        ret
    }

    .method public static native int IntPtr(native int v) cil managed
    {
        .maxstack 1
        ldarg.0
        conv.i
        ret
    }

    .method public static native int Single(float32 v) cil managed
    {
        .maxstack 1
        ldarg.0
        conv.i
        ret
    }

    .method public static native int Double(float64 v) cil managed
    {
        .maxstack 1
        ldarg.0
        conv.i
        ret
    }
}
