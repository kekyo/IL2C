.class public IL2C.ILConverters.Callvirt
{
	.method public static string NonVirtual_Callvirt(int32 value1, string value2) cil managed
	{
		.maxstack 3
        newobj instance void class IL2C.ILConverters.Callvirt::.ctor()
        ldarg.0
        ldarg.1
        callvirt instance string IL2C.ILConverters.Callvirt::NonVirtual(int32, string)
		ret
	}
}
