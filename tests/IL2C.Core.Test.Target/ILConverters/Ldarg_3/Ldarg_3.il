.class public IL2C.ILConverters.Ldarg_3
{
    .method public static bool Boolean(int32 arg0, int32 arg1, int32 arg2, bool v) cil managed
    {
        .maxstack 2
        ldarg.3
        ldc.i4.0
        ceq
        brfalse.s end
        ldc.i4.1
        ret
    end:ldc.i4.0
        ret
    }

    .method public static uint8 Byte(int32 arg0, int32 arg1, int32 arg2, uint8 num) cil managed
    {
        .maxstack 2
        ldarg.3
        ldc.i4.1
        sub
        ret
    }

    .method public static int16 Int16(int32 arg0, int32 arg1, int32 arg2, int16 num) cil managed
    {
        .maxstack 2
        ldarg.3
        ldc.i4.1
        sub
        ret
    }

    .method public static int32 Int32(int32 arg0, int32 arg1, int32 arg2, int32 num) cil managed
    {
        .maxstack 2
        ldarg.3
        ldc.i4.1
        sub
        ret
    }

    .method public static int64 Int64(int32 arg0, int32 arg1, int32 arg2, int64 num) cil managed
    {
        .maxstack 2
        ldarg.3
        ldc.i8 1
        sub
        ret
    }
                    
    .method public static int8 SByte(int32 arg0, int32 arg1, int32 arg2, int8 num) cil managed
    {
        .maxstack 2
        ldarg.3
        ldc.i4.1
        sub
        ret
    }

    .method public static uint16 UInt16(int32 arg0, int32 arg1, int32 arg2, uint16 num) cil managed
    {
        .maxstack 2
        ldarg.3
        ldc.i4.1
        sub
        ret
    }
    
    .method public static uint32 UInt32(int32 arg0, int32 arg1, int32 arg2, uint32 num) cil managed
    {
        .maxstack 2
        ldarg.3
        ldc.i4.1
        sub
        conv.u4
        ret
    }
        
    .method public static uint64 UInt64(int32 arg0, int32 arg1, int32 arg2, uint64 num) cil managed
    {
        .maxstack 2
        ldarg.3
        ldc.i8 1
        sub
        conv.u8
        ret
    }
        
    .method public static native int IntPtr(int32 arg0, int32 arg1, int32 arg2, native int num) cil managed
    {
        .maxstack 2
        ldarg.3
        ldc.i4.1
        sub
        ret
    }

    .method public static native uint UIntPtr(int32 arg0, int32 arg1, int32 arg2, native uint num) cil managed
    {
        .maxstack 2
        ldarg.3
        ldc.i4.1
        sub
        ret
    }

    .method public static float32 Single(int32 arg0, int32 arg1, int32 arg2, float32 num) cil managed
    {
        .maxstack 2
        ldarg.3
        ldc.r4 3.14159274
        add
        ret
    }

    .method public static float64 Double(int32 arg0, int32 arg1, int32 arg2, float64 num) cil managed
    {
        .maxstack 2
        ldarg.3
        ldc.r8 3.1415926535897931
        add
        ret
    }
            
    .method public static char Char(int32 arg0, int32 arg1, int32 arg2, char ch) cil managed
    {
        .maxstack 2
        ldarg.3
        ldc.i4.1
        add
        conv.u2
        ret
    }

    .method public static string String(int32 arg0, int32 arg1, int32 arg2, string str) cil managed
    {
        .maxstack 2
        ldarg.3
        ldstr "D"
        call string System.String::Concat(string, string)
        ret
    }
}
