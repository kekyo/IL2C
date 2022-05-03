.class public IL2C.ILConverters.Call_Overload
{
	.method public static string Instance_Overload_ToString_System_Object() cil managed
	{
		.maxstack 1
        newobj instance void class IL2C.ILConverters.Call_Overload::.ctor()
        call instance string object::ToString()
		ret
	}

	.method public static string Instance_Overload_ToString_IL2C_ILConverters_Call(string v) cil managed
	{
		.maxstack 2
        newobj instance void class IL2C.ILConverters.Call_Overload::.ctor()
		ldarg.0
        call instance string IL2C.ILConverters.Call_Overload::ToString(string v)
		ret
	}
}
