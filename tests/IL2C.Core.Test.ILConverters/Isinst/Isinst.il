.class public IL2C.ILConverters.Isinst
{
    .method public static string ConcatIfString(object v) cil managed
    {
        .maxstack 2
        ldarg.0
        isinst string
        dup
        brnull.s N1
        ldstr "DEF"
        call string string::Concat(string, string)
    N1:
        ret
    }

    .method public static string ToStringIfInt32(object v) cil managed
    {
        .maxstack 2
        ldarg.0
        isinst int32
        dup
        brnull.s N1
        callvirt instance string object::ToString()
    N1:
        ret
    }
}
