.class public IL2C.BasicTypes.System_Object
{
    .method public static bool IsValueType(object v) cil managed
    {
        .maxstack 2
        ldarg.0
        isinst [netstandard]System.ValueType
        brnull.s F1
        ldc.i4.1
        ret
    F1:
        ldc.i4.0
        ret
    }

    .method public static string ToString(object v) cil managed
    {
        .maxstack 1
        ldarg.0
        call instance string object::ToString()    // non virtual call
        ret
    }

    .method public static string GetType(object v) cil managed
    {
        .maxstack 1
        ldarg.0
        call instance class [netstandard]System.Type object::GetType()
        callvirt instance string [netstandard]System.Type::get_FullName()
        ret
    }

    .method public static bool RefEquals_Same() cil managed
    {
        .maxstack 2
        newobj instance void object::.ctor()
        dup
        call bool object::ReferenceEquals(object, object)
        ret
    }

    .method public static bool RefEquals_NotSame() cil managed
    {
        .maxstack 2
        newobj instance void object::.ctor()
        newobj instance void object::.ctor()
        call bool object::ReferenceEquals(object, object)
        ret
    }
}
