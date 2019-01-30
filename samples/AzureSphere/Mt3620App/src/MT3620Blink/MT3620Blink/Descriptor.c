// [15-2] This is MT3620Blink native code translated by IL2C, do not edit.

#include <MT3620Blink.h>
#include <MT3620Blink_internal.h>

#include <mscorlib.h>

#ifdef __cplusplus
extern "C" {
#endif

//////////////////////////////////////////////////////////////////////////////////
// [9-1] Type: MT3620Blink.Descriptor

//////////////////////////////////////////////////////////////////////////////////
// [9-2] File scope prototypes:

//////////////////////////////////////////////////////////////////////////////////
// [2-3] Methods: MT3620Blink.Descriptor

extern /* private */ void MT3620Blink_Descriptor_set_Identity(MT3620Blink_Descriptor* this__, int32_t value);

//////////////////////////////////////////////////////////////////////////////////
// [9-3] Static field instances:

//////////////////////////////////////////////////////////////////////////////////
// [9-4] Type: MT3620Blink.Descriptor

///////////////////////////////////////
// [3] MT3620Blink.Descriptor..ctor(MT3620Blink.Descriptor this__, System.Int32 fd)

//-------------------
// [3-7] Declare execution frame:

typedef struct MT3620Blink_Descriptor__ctor_EXECUTION_FRAME_DECL
{
    const IL2C_EXECUTION_FRAME* pNext__;
    const uint16_t objRefCount__;
    const uint16_t valueCount__;
    //-------------------- objref
    MT3620Blink_Descriptor* stack0_0__;
    System_String* stack0_3__;
    System_Exception* stack0_4__;
    il2c_boxedtype(System_Int32)* stack1_1__;
} MT3620Blink_Descriptor__ctor_EXECUTION_FRAME__;

//-------------------
// [3-2] Function body:

void MT3620Blink_Descriptor__ctor(MT3620Blink_Descriptor* this__, int32_t fd)
{
#line 7 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Descriptor.cs"
    il2c_assert(this__ != NULL);

    //-------------------
    // [3-3] Local variables (!objref):

#line 7 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Descriptor.cs"
    bool local0__ = false;

    //-------------------
    // [3-4] Evaluation stacks (!objref):

#line 7 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Descriptor.cs"
    int32_t stack0_1__;
#line 7 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Descriptor.cs"
    bool stack0_2__;
#line 7 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Descriptor.cs"
    int32_t stack1_0__;

    //-------------------
    // [3-5] Setup execution frame:

#line 7 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Descriptor.cs"
    MT3620Blink_Descriptor__ctor_EXECUTION_FRAME__ frame__ =
        { NULL, 4 };
#line 7 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Descriptor.cs"
    il2c_link_execution_frame(&frame__);

    //-------------------
    // [3-6] IL body:

    /* IL_0000: ldarg.0  */
#line 7 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Descriptor.cs"
    frame__.stack0_0__ = this__;
    /* IL_0001: call System.Object..ctor */
#line 7 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Descriptor.cs"
    System_Object__ctor((System_Object*)frame__.stack0_0__);
    /* IL_0006: nop  */
    /* IL_0007: nop  */
    /* IL_0008: ldarg.1  */
#line 9 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Descriptor.cs"
    stack0_1__ = fd;
    /* IL_0009: ldc.i4.0  */
#line 9 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Descriptor.cs"
    stack1_0__ = 0;
    /* IL_000a: clt  */
#line 9 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Descriptor.cs"
    stack0_1__ = (int32_t)stack0_1__ < (int32_t)stack1_0__;
    /* IL_000c: stloc.0  */
#line 9 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Descriptor.cs"
    local0__ = (bool)stack0_1__;
    /* IL_000d: ldloc.0  */
#line 9 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Descriptor.cs"
    stack0_2__ = local0__;
    /* IL_000e: brfalse.s IL_0027 */
#line 9 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Descriptor.cs"
    if (stack0_2__ == false) goto IL_0027;
    /* IL_0010: nop  */
    /* IL_0011: ldstr "Invalid descriptor: " */
#line 11 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Descriptor.cs"
    frame__.stack0_3__ = MT3620Blink_string0__;
    /* IL_0016: ldarg.1  */
#line 11 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Descriptor.cs"
    stack1_0__ = fd;
    /* IL_0017: box System.Int32 */
#line 11 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Descriptor.cs"
    frame__.stack1_1__ = il2c_box(&stack1_0__, System_Int32);
    /* IL_001c: call System.String.Concat */
#line 11 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Descriptor.cs"
    frame__.stack0_3__ = System_String_Concat_4((System_Object*)frame__.stack0_3__, (System_Object*)frame__.stack1_1__);
    /* IL_0021: newobj System.Exception..ctor */
#line 11 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Descriptor.cs"
    frame__.stack0_4__ = il2c_get_uninitialized_object(System_Exception);
#line 11 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Descriptor.cs"
    System_Exception__ctor_1(frame__.stack0_4__, frame__.stack0_3__);
    /* IL_0026: throw  */
#line 11 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Descriptor.cs"
    il2c_throw(frame__.stack0_4__);
IL_0027:
    /* IL_0027: ldarg.0  */
#line 13 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Descriptor.cs"
    frame__.stack0_0__ = this__;
    /* IL_0028: ldarg.1  */
#line 13 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Descriptor.cs"
    stack1_0__ = fd;
    /* IL_0029: call MT3620Blink.Descriptor.set_Identity */
#line 13 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Descriptor.cs"
    MT3620Blink_Descriptor_set_Identity(frame__.stack0_0__, stack1_0__);
    /* IL_002e: nop  */
    /* IL_002f: ret  */
#line 14 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Descriptor.cs"
    il2c_unlink_execution_frame(&frame__);
#line 14 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Descriptor.cs"
    return;
#line 14 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Descriptor.cs"
}

///////////////////////////////////////
// [3] Virtual: MT3620Blink.Descriptor.Dispose(MT3620Blink.Descriptor this__)

//-------------------
// [3-7] Declare execution frame:

typedef struct MT3620Blink_Descriptor_Dispose_EXECUTION_FRAME_DECL
{
    const IL2C_EXECUTION_FRAME* pNext__;
    const uint16_t objRefCount__;
    const uint16_t valueCount__;
    //-------------------- objref
    MT3620Blink_Descriptor* stack0_0__;
} MT3620Blink_Descriptor_Dispose_EXECUTION_FRAME__;

//-------------------
// [3-2] Function body:

void MT3620Blink_Descriptor_Dispose(MT3620Blink_Descriptor* this__)
{
#line 17 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Descriptor.cs"
    il2c_assert(this__ != NULL);

    //-------------------
    // [3-3] Local variables (!objref):

#line 17 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Descriptor.cs"
    bool local0__ = false;

    //-------------------
    // [3-4] Evaluation stacks (!objref):

#line 17 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Descriptor.cs"
    int32_t stack0_1__;
#line 17 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Descriptor.cs"
    bool stack0_2__;
#line 17 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Descriptor.cs"
    int32_t stack1_0__;

    //-------------------
    // [3-5] Setup execution frame:

#line 17 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Descriptor.cs"
    MT3620Blink_Descriptor_Dispose_EXECUTION_FRAME__ frame__ =
        { NULL, 1 };
#line 17 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Descriptor.cs"
    il2c_link_execution_frame(&frame__);

    //-------------------
    // [3-6] IL body:

    /* IL_0000: nop  */
    /* IL_0001: ldarg.0  */
#line 18 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Descriptor.cs"
    frame__.stack0_0__ = this__;
    /* IL_0002: call MT3620Blink.Descriptor.get_Identity */
#line 18 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Descriptor.cs"
    stack0_1__ = MT3620Blink_Descriptor_get_Identity(frame__.stack0_0__);
    /* IL_0007: ldc.i4.0  */
#line 18 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Descriptor.cs"
    stack1_0__ = 0;
    /* IL_0008: clt  */
#line 18 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Descriptor.cs"
    stack0_1__ = (int32_t)stack0_1__ < (int32_t)stack1_0__;
    /* IL_000a: ldc.i4.0  */
#line 18 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Descriptor.cs"
    stack1_0__ = 0;
    /* IL_000b: ceq  */
#line 18 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Descriptor.cs"
    stack0_1__ = (int32_t)stack0_1__ == (int32_t)stack1_0__;
    /* IL_000d: stloc.0  */
#line 18 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Descriptor.cs"
    local0__ = (bool)stack0_1__;
    /* IL_000e: ldloc.0  */
#line 18 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Descriptor.cs"
    stack0_2__ = local0__;
    /* IL_000f: brfalse.s IL_0027 */
#line 18 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Descriptor.cs"
    if (stack0_2__ == false) goto IL_0027;
    /* IL_0011: nop  */
    /* IL_0012: ldarg.0  */
#line 20 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Descriptor.cs"
    frame__.stack0_0__ = this__;
    /* IL_0013: call MT3620Blink.Descriptor.get_Identity */
#line 20 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Descriptor.cs"
    stack0_1__ = MT3620Blink_Descriptor_get_Identity(frame__.stack0_0__);
    /* IL_0018: call MT3620Blink.Interops.close */
#line 20 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Descriptor.cs"
    stack0_1__ = MT3620Blink_Interops_close(stack0_1__);
    /* IL_001d: pop  */
    /* IL_001e: ldarg.0  */
#line 21 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Descriptor.cs"
    frame__.stack0_0__ = this__;
    /* IL_001f: ldc.i4.m1  */
#line 21 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Descriptor.cs"
    stack1_0__ = -1;
    /* IL_0020: call MT3620Blink.Descriptor.set_Identity */
#line 21 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Descriptor.cs"
    MT3620Blink_Descriptor_set_Identity(frame__.stack0_0__, stack1_0__);
    /* IL_0025: nop  */
    /* IL_0026: nop  */
IL_0027:
    /* IL_0027: ret  */
#line 23 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Descriptor.cs"
    il2c_unlink_execution_frame(&frame__);
#line 23 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Descriptor.cs"
    return;
#line 23 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Descriptor.cs"
}

///////////////////////////////////////
// [3] MT3620Blink.Descriptor.get_Identity(MT3620Blink.Descriptor this__)

//-------------------
// [3-7] Declare execution frame:

typedef struct MT3620Blink_Descriptor_get_Identity_EXECUTION_FRAME_DECL
{
    const IL2C_EXECUTION_FRAME* pNext__;
    const uint16_t objRefCount__;
    const uint16_t valueCount__;
    //-------------------- objref
    MT3620Blink_Descriptor* stack0_0__;
} MT3620Blink_Descriptor_get_Identity_EXECUTION_FRAME__;

//-------------------
// [3-2] Function body:

int32_t MT3620Blink_Descriptor_get_Identity(MT3620Blink_Descriptor* this__)
{
#line 25 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Descriptor.cs"
    il2c_assert(this__ != NULL);

    //-------------------
    // [3-4] Evaluation stacks (!objref):

#line 25 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Descriptor.cs"
    int32_t stack0_1__;

    //-------------------
    // [3-5] Setup execution frame:

#line 25 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Descriptor.cs"
    MT3620Blink_Descriptor_get_Identity_EXECUTION_FRAME__ frame__ =
        { NULL, 1 };
#line 25 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Descriptor.cs"
    il2c_link_execution_frame(&frame__);

    //-------------------
    // [3-6] IL body:

    /* IL_0000: ldarg.0  */
#line 25 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Descriptor.cs"
    frame__.stack0_0__ = this__;
    /* IL_0001: ldfld MT3620Blink.Descriptor.<Identity>k__BackingField */
#line 25 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Descriptor.cs"
    stack0_1__ = frame__.stack0_0__->_Identity_k__BackingField;
    /* IL_0006: ret  */
#line 25 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Descriptor.cs"
    il2c_unlink_execution_frame(&frame__);
#line 25 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Descriptor.cs"
    return stack0_1__;
#line 25 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Descriptor.cs"
}

///////////////////////////////////////
// [3] MT3620Blink.Descriptor.set_Identity(MT3620Blink.Descriptor this__, System.Int32 value)

//-------------------
// [3-7] Declare execution frame:

typedef struct MT3620Blink_Descriptor_set_Identity_EXECUTION_FRAME_DECL
{
    const IL2C_EXECUTION_FRAME* pNext__;
    const uint16_t objRefCount__;
    const uint16_t valueCount__;
    //-------------------- objref
    MT3620Blink_Descriptor* stack0_0__;
} MT3620Blink_Descriptor_set_Identity_EXECUTION_FRAME__;

//-------------------
// [3-2] Function body:

void MT3620Blink_Descriptor_set_Identity(MT3620Blink_Descriptor* this__, int32_t value)
{
#line 25 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Descriptor.cs"
    il2c_assert(this__ != NULL);

    //-------------------
    // [3-4] Evaluation stacks (!objref):

#line 25 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Descriptor.cs"
    int32_t stack1_0__;

    //-------------------
    // [3-5] Setup execution frame:

#line 25 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Descriptor.cs"
    MT3620Blink_Descriptor_set_Identity_EXECUTION_FRAME__ frame__ =
        { NULL, 1 };
#line 25 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Descriptor.cs"
    il2c_link_execution_frame(&frame__);

    //-------------------
    // [3-6] IL body:

    /* IL_0000: ldarg.0  */
#line 25 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Descriptor.cs"
    frame__.stack0_0__ = this__;
    /* IL_0001: ldarg.1  */
#line 25 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Descriptor.cs"
    stack1_0__ = value;
    /* IL_0002: stfld MT3620Blink.Descriptor.<Identity>k__BackingField */
#line 25 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Descriptor.cs"
    frame__.stack0_0__->_Identity_k__BackingField = stack1_0__;
    /* IL_0007: ret  */
#line 25 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Descriptor.cs"
    il2c_unlink_execution_frame(&frame__);
#line 25 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Descriptor.cs"
    return;
#line 25 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Descriptor.cs"
}

//////////////////////
// [7] Runtime helpers:

// [7-10-2] VTable
MT3620Blink_Descriptor_VTABLE_DECL__ MT3620Blink_Descriptor_VTABLE__ = {
    0, // Adjustor offset
    (bool (*)(void*, System_Object*))System_Object_Equals,
    (void (*)(void*))System_Object_Finalize,
    (int32_t (*)(void*))System_Object_GetHashCode,
    (System_String* (*)(void*))System_Object_ToString,
    (void (*)(void*))MT3620Blink_Descriptor_Dispose,
};

// [7-13] VTable for System.IDisposable
System_IDisposable_VTABLE_DECL__ MT3620Blink_Descriptor_System_IDisposable_VTABLE__ = {
    il2c_adjustor_offset(MT3620Blink_Descriptor, System_IDisposable),
    (void (*)(void*))MT3620Blink_Descriptor_Dispose,
};

// [7-8] Runtime type information
IL2C_RUNTIME_TYPE_BEGIN(MT3620Blink_Descriptor, "MT3620Blink.Descriptor", IL2C_TYPE_REFERENCE, sizeof(MT3620Blink_Descriptor), System_Object, 0, 1)
    IL2C_RUNTIME_TYPE_INTERFACE(MT3620Blink_Descriptor, System_IDisposable)
IL2C_RUNTIME_TYPE_END();

#ifdef __cplusplus
}
#endif
