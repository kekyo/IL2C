.class public IL2C.BasicTypes.System_IntPtr
{
    .method public static bool IsValueType() cil managed
    {
        .maxstack 2
        ldc.i4 1234567
        conv.i
        box native int
        isinst [netstandard]System.ValueType
        brnull.s F1
        ldc.i4.1
        ret
    F1:
        ldc.i4.0
        ret
    }

    .method public static int32 SizeOf() cil managed
    {
        .maxstack 1
        sizeof native int
        ret
    }
}
