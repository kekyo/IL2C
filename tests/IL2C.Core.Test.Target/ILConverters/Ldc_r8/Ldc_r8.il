.class public IL2C.ILConverters.Ldc_r8
{
	.method public static float64 MaxValue() cil managed
	{
		.maxstack 1
		ldc.r8 1.7976931348623157E+308
		ret
	}

	.method public static float64 MinValue() cil managed
	{
		.maxstack 1
		ldc.r8 -1.7976931348623157E+308
		ret
	}
}
