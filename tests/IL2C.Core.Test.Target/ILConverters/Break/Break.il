.class public IL2C.ILConverters.Break
{
	.method public static int32 CauseBreak(int32 v1, int32 v2) cil managed
	{
		.maxstack 2
		ldarg.0
		ldarg.1
		break
		add
		ret
	}
}
