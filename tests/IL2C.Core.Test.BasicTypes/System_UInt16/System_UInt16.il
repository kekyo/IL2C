.class public IL2C.BasicTypes.System_UInt16
{
	.method public static bool IsValueType() cil managed
	{
		.maxstack 2
		ldc.i4 42345
		box [netstandard]System.UInt16
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
        sizeof [netstandard]System.UInt16
        ret
	}
}
