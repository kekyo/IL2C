.class public IL2C.ILConverters.Box_Enum_Narrowing
{
    .method public static object Box_Enum_Byte_From_Int32(int32 v) cil managed
    {
        .maxstack 1
        ldarg.0
        box IL2C.ILConverters.Box_Enum_Byte_Type
        ret
    }

    .method public static object Box_Enum_Int16_From_Int32(int32 v) cil managed
    {
        .maxstack 1
        ldarg.0
        box IL2C.ILConverters.Box_Enum_Int16_Type
        ret
    }

    .method public static object Box_Enum_SByte_From_Int32(int32 v) cil managed
    {
        .maxstack 1
        ldarg.0
        box IL2C.ILConverters.Box_Enum_SByte_Type
        ret
    }

    .method public static object Box_Enum_UInt16_From_Int32(int32 v) cil managed
    {
        .maxstack 1
        ldarg.0
        box IL2C.ILConverters.Box_Enum_UInt16_Type
        ret
    }

}
