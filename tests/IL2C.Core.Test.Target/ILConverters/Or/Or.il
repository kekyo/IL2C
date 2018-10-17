.class public IL2C.ILConverters.Or
{
	.method public static int32 Int32_Int32(int32 lhs, int32 rhs) cil managed
	{
		.maxstack 2
		ldarg.0
		ldarg.1
		or
		ret
	}

	.method public static native int Int32_IntPtr(int32 lhs, native int rhs) cil managed
	{
		.maxstack 2
		ldarg.0
		ldarg.1
		or
		ret
	}

    .method public static int64 Int64_Int64(int64 lhs, int64 rhs) cil managed
	{
		.maxstack 2
		ldarg.0
		ldarg.1
		or
		ret
	}

	.method public static native int IntPtr_Int32(native int lhs, int32 rhs) cil managed
	{
		.maxstack 2
		ldarg.0
		ldarg.1
		or
		ret
	}

	.method public static native int IntPtr_IntPtr(native int lhs, native int rhs) cil managed
	{
		.maxstack 2
		ldarg.0
		ldarg.1
		or
		ret
	}
}
