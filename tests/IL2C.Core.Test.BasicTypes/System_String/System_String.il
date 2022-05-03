.class public IL2C.BasicTypes.System_String
{
    .method public static bool IsValueType() cil managed
    {
        .maxstack 2
        ldstr "ABC"
        isinst [netstandard]System.ValueType
        brnull.s F1
        ldc.i4.1
        ret
    F1:
        ldc.i4.0
        ret
    }

    .method public static string ToString(string str) cil managed
    {
        .maxstack 1
        ldarg.0
        call instance string string::ToString()
        ret
    }

    .method public static bool Equals1(string value1, string value2) cil managed
    {
        .maxstack 2
        ldarg.0
        ldarg.1
        call instance bool string::Equals(string)
        ret
    }
}
