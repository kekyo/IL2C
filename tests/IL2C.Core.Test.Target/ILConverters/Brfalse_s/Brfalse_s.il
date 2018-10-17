.class public IL2C.ILConverters.Brfalse_s
{
	.method public static string FlagValue(bool v) cil managed
	{
		.maxstack 2
		ldarg.0
		brfalse.s F1
		ldstr "ABC"
		ret
	F1:
		ldstr "DEF"
		ret
	}

	.method public static string Int32Value(int32 v) cil managed
	{
		.maxstack 2
		ldarg.0
		brfalse.s F1
		ldstr "ABC"
		ret
	F1:
		ldstr "DEF"
		ret
	}

	.method public static string IntPtrValue(native int v) cil managed
	{
		.maxstack 2
		ldarg.0
		brfalse.s F1
		ldstr "ABC"
		ret
	F1:
		ldstr "DEF"
		ret
	}

	.method public static string ObjectValue(object v) cil managed
	{
		.maxstack 2
		ldarg.0
		brfalse.s F1
		ldstr "ABC"
		ret
	F1:
		ldstr "DEF"
		ret
	}
}
