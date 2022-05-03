.class public IL2C.ILConverters.Call_Virtual
{
    .method public static string Instance_ToString_System_Object() cil managed
    {
        .maxstack 1
        newobj instance void class IL2C.ILConverters.Call_Virtual::.ctor()
        call instance string object::ToString()
        ret
    }

    .method public static string Instance_ToString_IL2C_ILConverters_Call() cil managed
    {
        .maxstack 1
        newobj instance void class IL2C.ILConverters.Call_Virtual::.ctor()
        call instance string IL2C.ILConverters.Call_Virtual::ToString()
        ret
    }
}
