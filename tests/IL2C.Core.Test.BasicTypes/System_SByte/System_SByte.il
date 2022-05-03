.class public IL2C.BasicTypes.System_SByte
{
    .method public static bool IsValueType() cil managed
    {
        .maxstack 2
        ldc.i4.s 123
        box int8
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
        sizeof int8
        ret
    }
}
