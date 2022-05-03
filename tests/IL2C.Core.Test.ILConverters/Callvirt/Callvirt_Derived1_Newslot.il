.class public IL2C.ILConverters.Callvirt_Derived1_Newslot
{
    .method public static string Derived1_Newslot_ToString_System_Object() cil managed
    {
        .maxstack 1
        newobj instance void class IL2C.ILConverters.Callvirt_Derived1_Newslot::.ctor()
        callvirt instance string object::ToString()
        ret
    }

    .method public static string Derived1_Newslot_ToString_IL2C_ILConverters_Callvirt() cil managed
    {
        .maxstack 1
        newobj instance void class IL2C.ILConverters.Callvirt_Derived1_Newslot::.ctor()
        callvirt instance string IL2C.ILConverters.Callvirt_Derived1_Newslot::ToString()
        ret
    }
}
