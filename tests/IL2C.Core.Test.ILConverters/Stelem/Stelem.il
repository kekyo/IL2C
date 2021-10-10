.class public IL2C.ILConverters.Stelem
{
    // Section 4.27: The stelem.<type> instruction replaces the value of the element
    //   with zero-based index index
    //   (of type int32 or native int) in the one-dimensional array array with value.

    .method public static void ByteInner(uint8[] values, int32 index, uint8 _value) cil managed
    {
        .maxstack 3
        ldarg.0
        ldarg.1
        ldarg.2
        stelem uint8
        ret
    }

    .method public static void ByteIntPtrIndexInner(uint8[] values, int32 index, uint8 _value) cil managed
    {
        .maxstack 3
        ldarg.0
        ldarg.1
        conv.i     // make native int
        ldarg.2
        stelem uint8
        ret
    }

    ////////////////////////////////////////////////////////////////

    .method public static void Int16Inner(int16[] values, int32 index, int16 _value) cil managed
    {
        .maxstack 3
        ldarg.0
        ldarg.1
        ldarg.2
        stelem int16
        ret
    }

    .method public static void Int16IntPtrIndexInner(int16[] values, int32 index, int16 _value) cil managed
    {
        .maxstack 3
        ldarg.0
        ldarg.1
        conv.i     // make native int
        ldarg.2
        stelem int16
        ret
    }
    
    ////////////////////////////////////////////////////////////////

    .method public static void Int32Inner(int32[] values, int32 index, int32 _value) cil managed
    {
        .maxstack 3
        ldarg.0
        ldarg.1
        ldarg.2
        stelem int32
        ret
    }

    .method public static void Int32IntPtrIndexInner(int32[] values, int32 index, int32 _value) cil managed
    {
        .maxstack 3
        ldarg.0
        ldarg.1
        conv.i     // make native int
        ldarg.2
        stelem int32
        ret
    }
    
    ////////////////////////////////////////////////////////////////

    .method public static void Int64Inner(int64[] values, int32 index, int64 _value) cil managed
    {
        .maxstack 3
        ldarg.0
        ldarg.1
        ldarg.2
        stelem int64
        ret
    }

    .method public static void Int64IntPtrIndexInner(int64[] values, int32 index, int64 _value) cil managed
    {
        .maxstack 3
        ldarg.0
        ldarg.1
        conv.i     // make native int
        ldarg.2
        stelem int64
        ret
    }
    
    ////////////////////////////////////////////////////////////////

    .method public static void SingleInner(float32[] values, int32 index, float32 _value) cil managed
    {
        .maxstack 3
        ldarg.0
        ldarg.1
        ldarg.2
        stelem float32
        ret
    }

    .method public static void SingleIntPtrIndexInner(float32[] values, int32 index, float32 _value) cil managed
    {
        .maxstack 3
        ldarg.0
        ldarg.1
        conv.i     // make native int
        ldarg.2
        stelem float32
        ret
    }
        
    ////////////////////////////////////////////////////////////////

    .method public static void DoubleInner(float64[] values, int32 index, float64 _value) cil managed
    {
        .maxstack 3
        ldarg.0
        ldarg.1
        ldarg.2
        stelem float64
        ret
    }

    .method public static void DoubleIntPtrIndexInner(float64[] values, int32 index, float64 _value) cil managed
    {
        .maxstack 3
        ldarg.0
        ldarg.1
        conv.i     // make native int
        ldarg.2
        stelem float64
        ret
    }
        
    ////////////////////////////////////////////////////////////////

    .method public static void ObjectInner(string[] values, int32 index, string _value) cil managed
    {
        .maxstack 3
        ldarg.0
        ldarg.1
        ldarg.2
        stelem string
        ret
    }

    .method public static void ObjectIntPtrIndexInner(string[] values, int32 index, string _value) cil managed
    {
        .maxstack 3
        ldarg.0
        ldarg.1
        conv.i     // make native int
        ldarg.2
        stelem string
        ret
    }
}
