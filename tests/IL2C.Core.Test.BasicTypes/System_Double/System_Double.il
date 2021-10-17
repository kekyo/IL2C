.class public IL2C.BasicTypes.System_Double
{
	.method public static bool IsValueType() cil managed
	{
		.maxstack 2
		ldc.r8 1234567.890123
		box [netstandard]System.Double
		isinst [netstandard]System.ValueType
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
        sizeof [netstandard]System.Double
        ret
	}
}
