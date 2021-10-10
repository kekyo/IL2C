.class public IL2C.ILConverters.Stelem_r4
{
    // Section 4.27: The stelem.<type> instruction replaces the value of the element
    //   with zero-based index index
    //   (of type int32 or native int) in the one-dimensional array array with value.

    .method public static void SingleInner(float32[] values, int32 index, float32 _value) cil managed
    {
        .maxstack 3
        ldarg.0
        ldarg.1
        ldarg.2
        stelem.r4
        ret
    }

    .method public static void SingleIntPtrIndexInner(float32[] values, int32 index, float32 _value) cil managed
    {
        .maxstack 3
        ldarg.0
        ldarg.1
        conv.i     // make native int
        ldarg.2
        stelem.r4
        ret
    }
}
