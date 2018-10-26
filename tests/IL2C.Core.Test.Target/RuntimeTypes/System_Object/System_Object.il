.class public IL2C.RuntimeTypes.System_Object
{
	.method public static bool IsValueType(object v) cil managed
	{
		.maxstack 2
		ldarg.0
		isinst [mscorlib]System.ValueType
        brnull.s F1
        ldc.i4.1
		ret
    F1:
        ldc.i4.0
        ret
	}

	.method public static string ToString(object v) cil managed
	{
		.maxstack 1
        ldarg.0
        call instance string [mscorlib]System.Object::ToString()    // non virtual call
        ret
	}

	.method public static string GetType(object v) cil managed
	{
		.maxstack 1
        ldarg.0
        call instance class [mscorlib]System.Type [mscorlib]System.Object::GetType()
        callvirt instance string [mscorlib]System.Type::get_FullName()
        ret
	}
}
