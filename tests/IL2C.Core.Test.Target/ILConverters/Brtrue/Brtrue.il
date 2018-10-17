.class public IL2C.ILConverters.Brtrue
{
	.method public static string FlagValue(bool v) cil managed
	{
		.maxstack 2
		ldarg.0
		brtrue T1
		ldstr "DEF"
		ret
	T1:
		ldstr "ABC"
		ret
	}

	.method public static string Int32Value(int32 v) cil managed
	{
		.maxstack 2
		ldarg.0
		brtrue T1
		ldstr "DEF"
		ret
	T1:
		ldstr "ABC"
		ret
	}

	.method public static string IntPtrValue(native int v) cil managed
	{
		.maxstack 2
		ldarg.0
		brtrue T1
		ldstr "DEF"
		ret
	T1:
		ldstr "ABC"
		ret
	}

	.method public static string ObjectValue(object v) cil managed
	{
		.maxstack 2
		ldarg.0
		brtrue T1
		ldstr "DEF"
		ret
	T1:
		ldstr "ABC"
		ret
	}
}
