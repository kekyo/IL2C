.class public IL2C.BasicTypes.System_Char
{
	.method public static bool IsValueType() cil managed
	{
		.maxstack 2
		ldc.i4 12345
		box [mscorlib]System.Char
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
        sizeof [mscorlib]System.Char
        ret
	}
}
