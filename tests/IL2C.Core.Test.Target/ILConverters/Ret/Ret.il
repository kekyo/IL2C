.class public IL2C.ILConverters.Ret
{
	.method public static int32 Int32Value() cil managed
	{
		.maxstack 1
		ldc.i4.s 123
		ret
	}

	.method public static string StringValue() cil managed
	{
		.maxstack 1
		ldstr "ABC"
		ret
	}

	.method public static object NullValue() cil managed
	{
		.maxstack 1
		ldnull
		ret
	}

	.method private static int32& Return_RefInt(int32& a, int32& b, bool select) cil managed
	{
		.maxstack 1
        ldarg.2
        brfalse.s F1
        ldarg.0
		ret
    F1:
        ldarg.1
        ret
	}

	.method public static int32 RefIntValue(bool select) cil managed
	{
		.maxstack 3
        .locals init (
            [0] int32,
            [1] int32
        )
		ldc.i4.s 123
        stloc.0
        ldc.i4 456
        stloc.1
        ldloca.s 0
        ldloca.s 1
        ldarg.0
        call int32& IL2C.ILConverters.Ret::Return_RefInt(int32&, int32&, bool)
        ldind.i4
		ret
	}

	.method public static void Void() cil managed
	{
		.maxstack 1
		ret
	}
}
