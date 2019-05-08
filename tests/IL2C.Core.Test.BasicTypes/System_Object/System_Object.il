.class public IL2C.BasicTypes.System_Object
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

	.method public static bool RefEquals_Same() cil managed
	{
		.maxstack 2
        newobj instance void class [mscorlib]System.Object::.ctor()
        dup
        call bool [mscorlib]System.Object::ReferenceEquals(object, object)
        ret
	}

	.method public static bool RefEquals_NotSame() cil managed
	{
		.maxstack 2
        newobj instance void class [mscorlib]System.Object::.ctor()
        newobj instance void class [mscorlib]System.Object::.ctor()
        call bool [mscorlib]System.Object::ReferenceEquals(object, object)
        ret
	}
}
