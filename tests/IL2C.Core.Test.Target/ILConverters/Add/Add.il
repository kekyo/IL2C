.class public IL2C.ILConverters.Add
{
	.method public static int32 Int32_Int32(int32 lhs, int32 rhs) cil managed
	{
		.maxstack 2
		ldarg.0
		ldarg.1
		add
		ret
	}

	.method public static native int IntPtr_IntPtr(native int lhs, native int rhs) cil managed
	{
		.maxstack 2
		ldarg.0
		ldarg.1
		add
		ret
	}

	.method public static native int IntPtr_Int32(native int lhs, int32 rhs) cil managed
	{
		.maxstack 2
		ldarg.0
		ldarg.1
		add
		ret
	}

	.method public static int64 Int64_Int64(int64 lhs, int64 rhs) cil managed
	{
		.maxstack 2
		ldarg.0
		ldarg.1
		add
		ret
	}

	.method public static int64 Int64_IntPtr(int64 lhs, native int rhs) cil managed
	{
		.maxstack 2
		ldarg.0
		ldarg.1
		add
		ret
	}

	.method public static int64 Int64_Int32(int64 lhs, int32 rhs) cil managed
	{
		.maxstack 2
		ldarg.0
		ldarg.1
		add
		ret
	}

    .method public static int32& Add_IntRef_IntPtr(int32& r, native int adder) cil managed
	{
		.maxstack 2
        ldarg.0
	    ldarg.1
		add
		ret
	}

    .method public static int32 IntRef_IntPtr(int32 v) cil managed
	{
		.maxstack 2
        .locals init (
            [0] int32
        )
        ldarg.0
        stloc.0
        ldloca.s 0
        ldc.i4.1
        conv.i
        call int32& IL2C.ILConverters.Add::Add_IntRef_IntPtr(int32&, native int)
        ldc.i4.m1
        conv.i
        call int32& IL2C.ILConverters.Add::Add_IntRef_IntPtr(int32&, native int)
        ldind.i4
		ret
	}

    .method public static int32& Add_IntRef_Int32(int32& r, int32 adder) cil managed
	{
		.maxstack 2
        ldarg.0
	    ldarg.1
		add
		ret
	}

    .method public static int32 IntRef_Int32(int32 v) cil managed
	{
		.maxstack 2
        .locals init (
            [0] int32
        )
        ldarg.0
        stloc.0
        ldloca.s 0
        ldc.i4.1
        call int32& IL2C.ILConverters.Add::Add_IntRef_Int32(int32&, int32)
        ldc.i4.m1
        call int32& IL2C.ILConverters.Add::Add_IntRef_Int32(int32&, int32)
        ldind.i4
		ret
	}

	.method public static float64 Double_Double(float64 lhs, float64 rhs) cil managed
	{
		.maxstack 2
		ldarg.0
		ldarg.1
		add
		ret
	}

	.method public static float64 Double_Int32(float64 lhs, int32 rhs) cil managed
	{
		.maxstack 2
		ldarg.0
		ldarg.1
		add
		ret
	}

	.method public static float64 Double_IntPtr(float64 lhs, native int rhs) cil managed
	{
		.maxstack 2
		ldarg.0
		ldarg.1
		add
		ret
	}

	.method public static float64 Double_Int64(float64 lhs, int64 rhs) cil managed
	{
		.maxstack 2
		ldarg.0
		ldarg.1
        conv.r8
		add
		ret
	}
}
