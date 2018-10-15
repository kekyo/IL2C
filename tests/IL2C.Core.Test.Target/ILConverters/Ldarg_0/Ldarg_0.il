.class public IL2C.ILConverters.Ldarg_0
{
    .method public static bool Boolean(bool v) cil managed
    {
        .maxstack 2
        ldarg.0
        ldc.i4.0
        ceq
        brfalse.s end
        ldc.i4.1
        ret
    end:ldc.i4.0
        ret
    }

    .method public static uint8 Byte(uint8 num) cil managed
    {
        .maxstack 2
        ldarg.0
        ldc.i4.1
        sub
        ret
    }

    .method public static int16 Int16(int16 num) cil managed
    {
        .maxstack 2
        ldarg.0
        ldc.i4.1
        sub
        ret
    }

    .method public static int32 Int32(int32 num) cil managed
    {
        .maxstack 2
        ldarg.0
        ldc.i4.1
        sub
        ret
    }

    .method public static int64 Int64(int64 num) cil managed
    {
        .maxstack 2
        ldarg.0
        ldc.i8 1
        sub
        ret
    }
        
    .method public static int8 SByte(int8 num) cil managed
    {
        .maxstack 2
        ldarg.0
        ldc.i4.1
        sub
        ret
    }

    .method public static uint16 UInt16(uint16 num) cil managed
    {
        .maxstack 2
        ldarg.0
        ldc.i4.1
        sub
        ret
    }
    
    .method public static uint32 UInt32(uint32 num) cil managed
    {
        .maxstack 2
        ldarg.0
        ldc.i4.1
        sub
        conv.u4
        ret
    }
        
    .method public static uint64 UInt64(uint64 num) cil managed
    {
        .maxstack 2
        ldarg.0
        ldc.i8 1
        sub
        conv.u8
        ret
    }
        
    .method public static native int IntPtr(native int num) cil managed
    {
        .maxstack 2
        ldarg.0
        ldc.i4 1
        sub
        ret
    }
        
    .method public static native uint UIntPtr(native uint num) cil managed
    {
        .maxstack 2
        ldarg.0
        ldc.i4 1
        sub
        ret
    }

    .method public static float32 Single(float32 num) cil managed
    {
        .maxstack 2
        ldarg.0
        ldc.r4 3.14159274
        add
        ret
    }

    .method public static float64 Double(float64 num) cil managed
    {
        .maxstack 2
        ldarg.0
        ldc.r8 3.1415926535897931
        add
        ret
    }

    .method public static char Char(char ch) cil managed
    {
        .maxstack 2
        ldarg.0
        ldc.i4.1
        add
        conv.u2
        ret
    }

    .method public static string String(string str) cil managed
    {
        .maxstack 2
        ldarg.0
        ldstr "D"
        call string System.String::Concat(string, string)
        ret
    }
}
