.class public IL2C.ILConverters.Ldarg_0
{
	.method public static uint8 Byte(uint8 num) cil managed
	{
		.maxstack 2
		ldarg.0
		ldc.i4.1
		sub
		ret
	}

	.method public static int16 Int16(int16 num) cil managed
	{
		.maxstack 2
		ldarg.0
		ldc.i4.1
		sub
		ret
	}

	.method public static int32 Int32(int32 num) cil managed
	{
		.maxstack 2
		ldarg.0
		ldc.i4.1
		sub
		ret
	}

	.method public static int64 Int64(int64 num) cil managed
	{
		.maxstack 2
		ldarg.0
		ldc.i8 1
		sub
		ret
	}

	.method public static string String(string num) cil managed
	{
		.maxstack 2
		ldarg.0
		ldstr "D"
		call string System.String::Concat(string, string)
		ret
	}
}
