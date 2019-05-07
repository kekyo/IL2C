.class public IL2C.ILConverters.Ldsflda
{
    .method public static bool True() cil managed
    {
        .maxstack 1
        ldsflda bool IL2C.ILConverters.Ldsfld_Field::TrueValue
        ldind.u1
        ret
    }

    .method public static bool False() cil managed
    {
        .maxstack 1
        ldsflda bool IL2C.ILConverters.Ldsfld_Field::FalseValue
        ldind.u1
        ret
    }

    .method public static uint8 Byte() cil managed
    {
        .maxstack 1
        ldsflda uint8 IL2C.ILConverters.Ldsfld_Field::ByteValue
        ldind.u1
        ret
    }

    .method public static int16 Int16() cil managed
    {
        .maxstack 1
        ldsflda int16 IL2C.ILConverters.Ldsfld_Field::Int16Value
        ldind.i2
        ret
    }

    .method public static int32 Int32() cil managed
    {
        .maxstack 1
        ldsflda int32 IL2C.ILConverters.Ldsfld_Field::Int32Value
        ldind.i4
        ret
    }

    .method public static int64 Int64() cil managed
    {
        .maxstack 1
        ldsflda int64 IL2C.ILConverters.Ldsfld_Field::Int64Value
        ldind.i8
        ret
    }

    .method public static int8 SByte() cil managed
    {
        .maxstack 1
        ldsflda int8 IL2C.ILConverters.Ldsfld_Field::SByteValue
        ldind.i1
        ret
    }

    .method public static uint16 UInt16() cil managed
    {
        .maxstack 1
        ldsflda uint16 IL2C.ILConverters.Ldsfld_Field::UInt16Value
        ldind.u2
        ret
    }

    .method public static uint32 UInt32() cil managed
    {
        .maxstack 1
        ldsflda uint32 IL2C.ILConverters.Ldsfld_Field::UInt32Value
        ldind.u4
        ret
    }

    .method public static uint64 UInt64() cil managed
    {
        .maxstack 1
        ldsflda uint64 IL2C.ILConverters.Ldsfld_Field::UInt64Value
        ldind.i8
        ret
    }
    
    .method public static native int IntPtr() cil managed
    {
        .maxstack 1
        ldsflda native int IL2C.ILConverters.Ldsfld_Field::IntPtrValue
        ldind.i
        ret
    }
    
    .method public static native uint UIntPtr() cil managed
    {
        .maxstack 1
        ldsflda native uint IL2C.ILConverters.Ldsfld_Field::UIntPtrValue
        ldind.i
        ret
    }

    .method public static float32 Single() cil managed
    {
        .maxstack 1
        ldsflda float32 IL2C.ILConverters.Ldsfld_Field::SingleValue
        ldind.r4
        ret
    }

    .method public static float64 Double() cil managed
    {
        .maxstack 1
        ldsflda float64 IL2C.ILConverters.Ldsfld_Field::DoubleValue
        ldind.r8
        ret
    }

    .method public static char Char() cil managed
    {
        .maxstack 1
        ldsflda char IL2C.ILConverters.Ldsfld_Field::CharValue
        ldind.u2
        ret
    }

    .method public static string String() cil managed
    {
        .maxstack 1
        ldsflda string IL2C.ILConverters.Ldsfld_Field::StringValue
        ldind.ref
        ret
    }
}
