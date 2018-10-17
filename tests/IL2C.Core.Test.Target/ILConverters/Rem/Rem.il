.class public IL2C.ILConverters.Rem
{
	.method public static int32 Int32_Int32(int32 lhs, int32 rhs) cil managed
	{
		.maxstack 2
		ldarg.0
		ldarg.1
		rem
		ret
	}

	.method public static native int Int32_IntPtr(int32 lhs, native int rhs) cil managed
	{
		.maxstack 2
		ldarg.0
		ldarg.1
		rem
		ret
	}

    .method public static int64 Int64_Int64(int64 lhs, int64 rhs) cil managed
	{
		.maxstack 2
		ldarg.0
		ldarg.1
		rem
		ret
	}

	.method public static native int IntPtr_Int32(native int lhs, int32 rhs) cil managed
	{
		.maxstack 2
		ldarg.0
		ldarg.1
		rem
		ret
	}

	.method public static native int IntPtr_IntPtr(native int lhs, native int rhs) cil managed
	{
		.maxstack 2
		ldarg.0
		ldarg.1
		rem
		ret
	}
    
	.method public static float32 Single_Single(float32 lhs, float32 rhs) cil managed
	{
		.maxstack 2
		ldarg.0
		ldarg.1
		rem
		ret
	}
    
	.method public static float64 Single_Double(float32 lhs, float64 rhs) cil managed
	{
		.maxstack 2
		ldarg.0
		ldarg.1
		rem
		ret
	}
        
	.method public static float64 Double_Single(float64 lhs, float32 rhs) cil managed
	{
		.maxstack 2
		ldarg.0
		ldarg.1
		rem
		ret
	}

	.method public static float64 Double_Double(float64 lhs, float64 rhs) cil managed
	{
		.maxstack 2
		ldarg.0
		ldarg.1
		rem
		ret
	}
}
