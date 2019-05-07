.class public IL2C.ILConverters.Ldc_i4
{
	.method public static int32 MaxValue() cil managed
	{
		.maxstack 2
		ldc.i4 2147483647
		ret
	}

	.method public static int32 MinValue() cil managed
	{
		.maxstack 2
		ldc.i4 -2147483648
		ret
	}
}
