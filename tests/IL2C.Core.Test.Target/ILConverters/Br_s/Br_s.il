.class public IL2C.ILConverters.Br_s
{
	.method public static int32 ValidValue() cil managed
	{
		.maxstack 2
        ldc.i4.1
		br.s next1
	next2:
        ldc.i4.3
        add
		ret
	next1:
        ldc.i4.2
        add
		br.s next2
	}
}
