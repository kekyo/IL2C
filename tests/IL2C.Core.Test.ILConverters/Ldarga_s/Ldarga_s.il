.class public IL2C.ILConverters.Ldarga_s
{
    .method public static string Boolean_4(
        int32 arg0, int32 arg1, int32 arg2, int32 arg3, bool v) cil managed
    {
        .maxstack 1
        ldarga.s 4
        call instance string bool::ToString()
        ret
    }

    .method public static string Byte_4(
        int32 arg0, int32 arg1, int32 arg2, int32 arg3, uint8 num) cil managed
    {
        .maxstack 1
        ldarga.s 4
        call instance string uint8::ToString()
        ret
    }

    .method public static string Int16_4(
        int32 arg0, int32 arg1, int32 arg2, int32 arg3, int16 num) cil managed
    {
        .maxstack 1
        ldarga.s 4
        call instance string int16::ToString()
        ret
    }

    .method public static string Int32_4(
        int32 arg0, int32 arg1, int32 arg2, int32 arg3, int32 num) cil managed
    {
        .maxstack 1
        ldarga.s 4
        call instance string int32::ToString()
        ret
    }

    .method public static string Int64_4(
        int32 arg0, int32 arg1, int32 arg2, int32 arg3, int64 num) cil managed
    {
        .maxstack 1
        ldarga.s 4
        call instance string int64::ToString()
        ret
    }
                        
    .method public static string SByte_4(
        int32 arg0, int32 arg1, int32 arg2, int32 arg3, int8 num) cil managed
    {
        .maxstack 1
        ldarga.s 4
        call instance string int8::ToString()
        ret
    }

    .method public static string UInt16_4(
        int32 arg0, int32 arg1, int32 arg2, int32 arg3, uint16 num) cil managed
    {
        .maxstack 1
        ldarga.s 4
        call instance string uint16::ToString()
        ret
    }
    
    .method public static string UInt32_4(
        int32 arg0, int32 arg1, int32 arg2, int32 arg3, uint32 num) cil managed
    {
        .maxstack 1
        ldarga.s 4
        call instance string uint32::ToString()
        ret
    }
        
    .method public static string UInt64_4(
        int32 arg0, int32 arg1, int32 arg2, int32 arg3, uint64 num) cil managed
    {
        .maxstack 1
        ldarga.s 4
        call instance string uint64::ToString()
        ret
    }
            
    .method public static string IntPtr_4(
        int32 arg0, int32 arg1, int32 arg2, int32 arg3, native int num) cil managed
    {
        .maxstack 1
        ldarga.s 4
        call instance string native int::ToString()
        ret
    }

    .method public static string UIntPtr_4(
        int32 arg0, int32 arg1, int32 arg2, int32 arg3, native uint num) cil managed
    {
        .maxstack 1
        ldarga.s 4
        call instance string native uint::ToString()
        ret
    }

    .method public static string Single_4(
        int32 arg0, int32 arg1, int32 arg2, int32 arg3, float32 num) cil managed
    {
        .maxstack 1
        ldarga.s 4
        call instance string float32::ToString()
        ret
    }

    .method public static string Double_4(
        int32 arg0, int32 arg1, int32 arg2, int32 arg3, float64 num) cil managed
    {
        .maxstack 1
        ldarga.s 4
        call instance string float64::ToString()
        ret
    }
                
    .method public static string Char_4(
        int32 arg0, int32 arg1, int32 arg2, int32 arg3, char ch) cil managed
    {
        .maxstack 1
        ldarga.s 4
        call instance string char::ToString()
        ret
    }

    .method public static string String_4(
        int32 arg0, int32 arg1, int32 arg2, int32 arg3, string str) cil managed
    {
        .maxstack 1
        ldarga.s 4
        call string IL2C.ILConverters.Ldarga_s::GetUnrefString(string&)
        ret
    }

    .method public static string Argument_255(
        int32 arg0, int32 arg1, int32 arg2, int32 arg3, int32 arg4, int32 arg5, int32 arg6, int32 arg7,
        int32 arg8, int32 arg9, int32 arga, int32 argb, int32 argc, int32 argd, int32 arge, int32 argf,
        int32 arg10, int32 arg11, int32 arg12, int32 arg13, int32 arg14, int32 arg15, int32 arg16, int32 arg17,
        int32 arg18, int32 arg19, int32 arg1a, int32 arg1b, int32 arg1c, int32 arg1d, int32 arg1e, int32 arg1f,
        int32 arg20, int32 arg21, int32 arg22, int32 arg23, int32 arg24, int32 arg25, int32 arg26, int32 arg27,
        int32 arg28, int32 arg29, int32 arg2a, int32 arg2b, int32 arg2c, int32 arg2d, int32 arg2e, int32 arg2f,
        int32 arg30, int32 arg31, int32 arg32, int32 arg33, int32 arg34, int32 arg35, int32 arg36, int32 arg37,
        int32 arg38, int32 arg39, int32 arg3a, int32 arg3b, int32 arg3c, int32 arg3d, int32 arg3e, int32 arg3f,
        int32 arg40, int32 arg41, int32 arg42, int32 arg43, int32 arg44, int32 arg45, int32 arg46, int32 arg47,
        int32 arg48, int32 arg49, int32 arg4a, int32 arg4b, int32 arg4c, int32 arg4d, int32 arg4e, int32 arg4f,
        int32 arg50, int32 arg51, int32 arg52, int32 arg53, int32 arg54, int32 arg55, int32 arg56, int32 arg57,
        int32 arg58, int32 arg59, int32 arg5a, int32 arg5b, int32 arg5c, int32 arg5d, int32 arg5e, int32 arg5f,
        int32 arg60, int32 arg61, int32 arg62, int32 arg63, int32 arg64, int32 arg65, int32 arg66, int32 arg67,
        int32 arg68, int32 arg69, int32 arg6a, int32 arg6b, int32 arg6c, int32 arg6d, int32 arg6e, int32 arg6f,
        int32 arg70, int32 arg71, int32 arg72, int32 arg73, int32 arg74, int32 arg75, int32 arg76, int32 arg77,
        int32 arg78, int32 arg79, int32 arg7a, int32 arg7b, int32 arg7c, int32 arg7d, int32 arg7e, int32 arg7f,
        int32 arg80, int32 arg81, int32 arg82, int32 arg83, int32 arg84, int32 arg85, int32 arg86, int32 arg87,
        int32 arg88, int32 arg89, int32 arg8a, int32 arg8b, int32 arg8c, int32 arg8d, int32 arg8e, int32 arg8f,
        int32 arg90, int32 arg91, int32 arg92, int32 arg93, int32 arg94, int32 arg95, int32 arg96, int32 arg97,
        int32 arg98, int32 arg99, int32 arg9a, int32 arg9b, int32 arg9c, int32 arg9d, int32 arg9e, int32 arg9f,
        int32 arga0, int32 arga1, int32 arga2, int32 arga3, int32 arga4, int32 arga5, int32 arga6, int32 arga7,
        int32 arga8, int32 arga9, int32 argaa, int32 argab, int32 argac, int32 argad, int32 argae, int32 argaf,
        int32 argb0, int32 argb1, int32 argb2, int32 argb3, int32 argb4, int32 argb5, int32 argb6, int32 argb7,
        int32 argb8, int32 argb9, int32 argba, int32 argbb, int32 argbc, int32 argbd, int32 argbe, int32 argbf,
        int32 argc0, int32 argc1, int32 argc2, int32 argc3, int32 argc4, int32 argc5, int32 argc6, int32 argc7,
        int32 argc8, int32 argc9, int32 argca, int32 argcb, int32 argcc, int32 argcd, int32 argce, int32 argcf,
        int32 argd0, int32 argd1, int32 argd2, int32 argd3, int32 argd4, int32 argd5, int32 argd6, int32 argd7,
        int32 argd8, int32 argd9, int32 argda, int32 argdb, int32 argdc, int32 argdd, int32 argde, int32 argdf,
        int32 arge0, int32 arge1, int32 arge2, int32 arge3, int32 arge4, int32 arge5, int32 arge6, int32 arge7,
        int32 arge8, int32 arge9, int32 argea, int32 argeb, int32 argec, int32 arged, int32 argee, int32 argef,
        int32 argf0, int32 argf1, int32 argf2, int32 argf3, int32 argf4, int32 argf5, int32 argf6, int32 argf7,
        int32 argf8, int32 argf9, int32 argfa, int32 argfb, int32 argfc, int32 argfd, int32 argfe,
        string str) cil managed
    {
        .maxstack 1
        ldarga.s 255
        call string IL2C.ILConverters.Ldarga_s::GetUnrefString(string&)
        ret
    }
}
