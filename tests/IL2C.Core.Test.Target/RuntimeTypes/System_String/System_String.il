.class public IL2C.RuntimeTypes.System_String
{
	.method public static bool IsValueType() cil managed
	{
		.maxstack 2
		ldstr "ABC"
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
        sizeof [mscorlib]System.Int32
        ret
	}
}
