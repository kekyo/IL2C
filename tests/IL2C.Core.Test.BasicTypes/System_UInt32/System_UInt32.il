.class public IL2C.BasicTypes.System_UInt32
{
	.method public static bool IsValueType() cil managed
	{
		.maxstack 2
		ldc.i4 1234567
		box [mscorlib]System.UInt32
		isinst [mscorlib]System.ValueType
        brnull.s F1
        ldc.i4.1
		ret
    F1:
        ldc.i4.0
        ret
	}

	.method public static int32 SizeOf() cil managed
	{
		.maxstack 1
        sizeof [mscorlib]System.UInt32
        ret
	}
}
