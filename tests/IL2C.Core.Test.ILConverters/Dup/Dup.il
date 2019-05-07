.class public IL2C.ILConverters.Dup
{
	.method public static int32 Mul2Int32(int32 v) cil managed
	{
		.maxstack 2
		ldarg.0
		dup
		add
		ret
	}

	.method public static string Mul2String(string v) cil managed
	{
		.maxstack 2
		ldarg.0
		dup
		call string System.String::Concat(string, string)
		ret
	}
}
