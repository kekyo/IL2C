.class public IL2C.ILConverters.Isinst
{
	.method public static string ConcatIfString(object v) cil managed
	{
		.maxstack 2
        ldarg.0
		isinst [mscorlib]System.String
		dup
		brnull.s N1
		ldstr "DEF"
		call string [mscorlib]System.String::Concat(string, string)
	N1:
		ret
	}

	.method public static string ToStringIfInt32(object v) cil managed
	{
		.maxstack 2
        ldarg.0
		isinst [mscorlib]System.Int32
		dup
		brnull.s N1
		callvirt instance string [mscorlib]System.Object::ToString()
	N1:
		ret
	}
}
