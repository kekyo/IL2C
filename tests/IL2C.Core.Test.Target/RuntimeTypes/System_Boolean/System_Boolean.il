.class public IL2C.RuntimeTypes.System_Boolean
{
	.method public static bool IsValueType() cil managed
	{
		.maxstack 2
		ldc.i4.s 123
		box [mscorlib]System.Boolean
		castclass [mscorlib]System.ValueType
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
        sizeof [mscorlib]System.Boolean
        ret
	}
}
