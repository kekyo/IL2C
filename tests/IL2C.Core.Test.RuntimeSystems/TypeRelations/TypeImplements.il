.class public IL2C.RuntimeSystems.TypeImplements
{
    .method public static string InstanceImplementExplicitlyTypeFromInterfaceByClass(int32 v) cil managed
    {
        .maxstack 2
        newobj instance void IL2C.RuntimeSystems.InstanceImplementExplicitlyType::.ctor()
        ldarg.0
        callvirt instance string IL2C.RuntimeSystems.IInterfaceType1::GetStringFromInt32(int32)
        ret
    }
}
