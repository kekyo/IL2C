.class public IL2C.ILConverters.Ldc_i8
{
	.method public static int64 MaxValue() cil managed
	{
		.maxstack 2
		ldc.i8 9223372036854775807
		ret
	}

	.method public static int64 MinValue() cil managed
	{
		.maxstack 2
		ldc.i8 -9223372036854775808
		ret
	}
}
