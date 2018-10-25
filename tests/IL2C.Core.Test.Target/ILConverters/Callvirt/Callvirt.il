.class public IL2C.ILConverters.Callvirt
{
	.method public static string Instance_ToString_System_Object() cil managed
	{
		.maxstack 1
        newobj instance void class IL2C.ILConverters.Callvirt::.ctor()
        callvirt instance string [mscorlib]System.Object::ToString()
		ret
	}

	.method public static string Instance_ToString_IL2C_ILConverters_Callvirt() cil managed
	{
		.maxstack 1
        newobj instance void class IL2C.ILConverters.Callvirt::.ctor()
        callvirt instance string IL2C.ILConverters.Callvirt::ToString()
		ret
	}
}
