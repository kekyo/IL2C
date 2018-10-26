.class public IL2C.ILConverters.Call
{
	.method public static int32 Static_Int32_Int32(int32 lhs, int32 rhs) cil managed
	{
		.maxstack 2
        ldarg.0
        ldarg.1
        call int32 IL2C.ILConverters.Call::Add_Static_Int32_Int32(int32, int32)
		ret
	}

	.method public static string Static_String_String(string lhs, string rhs) cil managed
	{
		.maxstack 2
        ldarg.0
        ldarg.1
        call string IL2C.ILConverters.Call::Concat_Static_String_String(string, string)
		ret
	}

	.method public static int32 Static_RefInt_RefInt() cil managed
	{
		.maxstack 2
        .locals init (
            [0] int32,
            [1] int32
        )
        ldloca.s 0
        ldloca.s 1
        call void IL2C.ILConverters.Call::Store_Static_RefInt_RefInt(int32&, int32&)
        ldloc.0
        ldloc.1
        add
		ret
	}

	.method public static int32 Instance_Int32_ThisInt32(int32 v1, int32 v2) cil managed
	{
		.maxstack 3
        newobj instance void class IL2C.ILConverters.Call::.ctor()
        ldarg.0
        ldarg.1
        call instance int32 IL2C.ILConverters.Call::Add_Instance_Int32_ThisInt32(int32, int32)
		ret
	}

	.method public static string Instance_String_ThisString(string v1, string v2) cil managed
	{
		.maxstack 3
        .locals init (
            [0] class IL2C.ILConverters.Call
        )
        newobj instance void class IL2C.ILConverters.Call::.ctor()
        stloc.0
        ldloc.0
        ldarg.0
        call instance string IL2C.ILConverters.Call::Concat_Instance_String_ThisString(string)
        ldloc.0
        ldarg.1
        call instance string IL2C.ILConverters.Call::Concat_Instance_String_ThisString(string)
		call string System.String::Concat(string, string)
		ret
	}
}
