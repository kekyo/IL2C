.class public IL2C.ILConverters.Ldc_i4_7
{
	.method public static int32 RawValue() cil managed
	{
		.maxstack 2
		ldc.i4.7
		ret
	}

	.method public static int32 Add(int32 num) cil managed
	{
		.maxstack 2
		ldarg.0
		ldc.i4.7
        add
		ret
	}
}
