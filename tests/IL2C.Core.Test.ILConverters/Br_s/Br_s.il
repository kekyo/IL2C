.class public IL2C.ILConverters.Br_s
{
	.method public static int32 Rem2(int32 v, int32 d1, int32 d2) cil managed
	{
		.maxstack 2
        ldarg.0
		br.s next1
	next2:
        ldarg.2
        rem
		ret
	next1:
        ldarg.1
        rem
		br.s next2
	}
}
