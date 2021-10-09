.class public IL2C.ILConverters.Stelem_i2
{
    // Section 4.27: The stelem.<type> instruction replaces the value of the element
    //   with zero-based index index
    //   (of type int32 or native int) in the one-dimensional array array with value.

    .method public static void Int16Inner(int16[] values, int32 index, int16 _value) cil managed
    {
        .maxstack 3
        ldarg.0
        ldarg.1
        ldarg.2
        stelem.i2
        ret
    }

    .method public static void Int16IntPtrIndexInner(int16[] values, int32 index, int16 _value) cil managed
    {
        .maxstack 3
        ldarg.0
        ldarg.1
        conv.i     // make native int
        ldarg.2
        stelem.i2
        ret
    }
}
