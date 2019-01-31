// [15-2] This is MT3620Blink native code translated by IL2C, do not edit.

#include <MT3620Blink.h>
#include <MT3620Blink_internal.h>

#include <mscorlib.h>

#ifdef __cplusplus
extern "C" {
#endif

//////////////////////////////////////////////////////////////////////////////////
// [9-1] Type: MT3620Blink.Program

//////////////////////////////////////////////////////////////////////////////////
// [9-2] File scope prototypes:

//////////////////////////////////////////////////////////////////////////////////
// [2-3] Methods: MT3620Blink.Program.GpioBlinker

extern /* public sealed */ void MT3620Blink_Program_GpioBlinker__ctor(MT3620Blink_Program_GpioBlinker* this__, int32_t gpioId);
extern /* public override sealed */ void MT3620Blink_Program_GpioBlinker_Dispose(MT3620Blink_Program_GpioBlinker* this__);
extern /* protected override sealed */ void MT3620Blink_Program_GpioBlinker_Raised(MT3620Blink_Program_GpioBlinker* this__);
extern /* public sealed */ void MT3620Blink_Program_GpioBlinker_NextInterval(MT3620Blink_Program_GpioBlinker* this__);

//////////////////////////////////////////////////////////////////////////////////
// [9-4] Type: MT3620Blink.Program.GpioBlinker

///////////////////////////////////////
// [3] MT3620Blink.Program.GpioBlinker..ctor(MT3620Blink.Program.GpioBlinker this__, System.Int32 gpioId)

//-------------------
// [3-7] Declare execution frame:

typedef struct MT3620Blink_Program_GpioBlinker__ctor_EXECUTION_FRAME_DECL
{
    const IL2C_EXECUTION_FRAME* pNext__;
    const uint16_t objRefCount__;
    const uint16_t valueCount__;
    //-------------------- objref
    MT3620Blink_Program_GpioBlinker* stack0_0__;
    il2c_arraytype(System_Int64)* stack1_1__;
    MT3620Blink_GpioOutput* stack1_2__;
    il2c_arraytype(System_Int64)* stack2_0__;
} MT3620Blink_Program_GpioBlinker__ctor_EXECUTION_FRAME__;

//-------------------
// [3-2] Function body:

void MT3620Blink_Program_GpioBlinker__ctor(MT3620Blink_Program_GpioBlinker* this__, int32_t gpioId)
{
#line 9 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    il2c_assert(this__ != NULL);

    //-------------------
    // [3-4] Evaluation stacks (!objref):

#line 9 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    int32_t stack1_0__;
#line 9 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    int32_t stack2_1__;
#line 9 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    System_RuntimeFieldHandle stack3_0__;
#line 9 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    int32_t stack3_1__;

    //-------------------
    // [3-5] Setup execution frame:

#line 9 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    MT3620Blink_Program_GpioBlinker__ctor_EXECUTION_FRAME__ frame__ =
        { NULL, 4 };
#line 9 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    il2c_link_execution_frame(&frame__);

    //-------------------
    // [3-6] IL body:

    /* IL_0000: ldarg.0  */
#line 9 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    frame__.stack0_0__ = this__;
    /* IL_0001: ldc.i4.3  */
#line 9 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    stack1_0__ = 3;
    /* IL_0002: newarr System.Int64 */
#line 9 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    frame__.stack1_1__ = il2c_new_array(System_Int64, stack1_0__);
    /* IL_0007: dup  */
#line 9 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    frame__.stack2_0__ = frame__.stack1_1__;
    /* IL_0008: ldtoken .<PrivateImplementationDetails>.E902362F9BEE92BBA97ECE5B88B94AF4A8D3201D */
#line 9 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    stack3_0__.size__ = 24;
#line 9 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    stack3_0__.field__ = MT3620Blink_declaredValue0__;
    /* IL_000d: call System.Runtime.CompilerServices.RuntimeHelpers.InitializeArray */
#line 9 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    System_Runtime_CompilerServices_RuntimeHelpers_InitializeArray((System_Array*)frame__.stack2_0__, stack3_0__);
    /* IL_0012: stfld MT3620Blink.Program.GpioBlinker.blinkIntervals */
#line 9 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    frame__.stack0_0__->blinkIntervals = frame__.stack1_1__;
    /* IL_0017: ldarg.0  */
#line 14 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    frame__.stack0_0__ = this__;
    /* IL_0018: call MT3620Blink.Timer..ctor */
#line 14 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    MT3620Blink_Timer__ctor((MT3620Blink_Timer*)frame__.stack0_0__);
    /* IL_001d: nop  */
    /* IL_001e: nop  */
    /* IL_001f: ldarg.0  */
#line 16 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    frame__.stack0_0__ = this__;
    /* IL_0020: ldarg.1  */
#line 16 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    stack1_0__ = gpioId;
    /* IL_0021: ldc.i4.0  */
#line 16 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    stack2_1__ = 0;
    /* IL_0022: ldc.i4.1  */
#line 16 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    stack3_1__ = 1;
    /* IL_0023: newobj MT3620Blink.GpioOutput..ctor */
#line 16 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    frame__.stack1_2__ = il2c_get_uninitialized_object(MT3620Blink_GpioOutput);
#line 16 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    MT3620Blink_GpioOutput__ctor(frame__.stack1_2__, stack1_0__, (MT3620Blink_GPIO_OutputMode_Type)stack2_1__, (bool)stack3_1__);
    /* IL_0028: stfld MT3620Blink.Program.GpioBlinker.output */
#line 16 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    frame__.stack0_0__->output = frame__.stack1_2__;
    /* IL_002d: ldarg.0  */
#line 20 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    frame__.stack0_0__ = this__;
    /* IL_002e: call MT3620Blink.Program.GpioBlinker.NextInterval */
#line 20 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    MT3620Blink_Program_GpioBlinker_NextInterval(frame__.stack0_0__);
    /* IL_0033: nop  */
    /* IL_0034: ret  */
#line 21 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    il2c_unlink_execution_frame(&frame__);
#line 21 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    return;
#line 21 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
}

///////////////////////////////////////
// [3] Virtual: MT3620Blink.Program.GpioBlinker.Dispose(MT3620Blink.Program.GpioBlinker this__)

//-------------------
// [3-7] Declare execution frame:

typedef struct MT3620Blink_Program_GpioBlinker_Dispose_EXECUTION_FRAME_DECL
{
    const IL2C_EXECUTION_FRAME* pNext__;
    const uint16_t objRefCount__;
    const uint16_t valueCount__;
    //-------------------- objref
    MT3620Blink_Program_GpioBlinker* stack0_0__;
    MT3620Blink_GpioOutput* stack0_1__;
} MT3620Blink_Program_GpioBlinker_Dispose_EXECUTION_FRAME__;

//-------------------
// [3-2] Function body:

void MT3620Blink_Program_GpioBlinker_Dispose(MT3620Blink_Program_GpioBlinker* this__)
{
#line 24 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    il2c_assert(this__ != NULL);

    //-------------------
    // [3-5] Setup execution frame:

#line 24 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    MT3620Blink_Program_GpioBlinker_Dispose_EXECUTION_FRAME__ frame__ =
        { NULL, 2 };
#line 24 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    il2c_link_execution_frame(&frame__);

    //-------------------
    // [3-6] IL body:

    /* IL_0000: nop  */
    /* IL_0001: ldarg.0  */
#line 25 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    frame__.stack0_0__ = this__;
    /* IL_0002: call MT3620Blink.Descriptor.Dispose */
#line 25 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    MT3620Blink_Descriptor_Dispose((MT3620Blink_Descriptor*)frame__.stack0_0__);
    /* IL_0007: nop  */
    /* IL_0008: ldarg.0  */
#line 26 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    frame__.stack0_0__ = this__;
    /* IL_0009: ldfld MT3620Blink.Program.GpioBlinker.output */
#line 26 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    frame__.stack0_1__ = frame__.stack0_0__->output;
    /* IL_000e: callvirt MT3620Blink.Descriptor.Dispose */
#line 26 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    frame__.stack0_1__->vptr0__->Dispose((MT3620Blink_Descriptor*)frame__.stack0_1__);
    /* IL_0013: nop  */
    /* IL_0014: ret  */
#line 27 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    il2c_unlink_execution_frame(&frame__);
#line 27 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    return;
#line 27 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
}

///////////////////////////////////////
// [3] Virtual: MT3620Blink.Program.GpioBlinker.Raised(MT3620Blink.Program.GpioBlinker this__)

//-------------------
// [3-7] Declare execution frame:

typedef struct MT3620Blink_Program_GpioBlinker_Raised_EXECUTION_FRAME_DECL
{
    const IL2C_EXECUTION_FRAME* pNext__;
    const uint16_t objRefCount__;
    const uint16_t valueCount__;
    //-------------------- objref
    MT3620Blink_Program_GpioBlinker* stack0_0__;
    MT3620Blink_GpioOutput* stack0_1__;
    MT3620Blink_Program_GpioBlinker* stack1_0__;
} MT3620Blink_Program_GpioBlinker_Raised_EXECUTION_FRAME__;

//-------------------
// [3-2] Function body:

void MT3620Blink_Program_GpioBlinker_Raised(MT3620Blink_Program_GpioBlinker* this__)
{
#line 30 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    il2c_assert(this__ != NULL);

    //-------------------
    // [3-4] Evaluation stacks (!objref):

#line 30 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    bool stack1_1__;
#line 30 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    int32_t stack1_2__;
#line 30 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    int32_t stack2_0__;

    //-------------------
    // [3-5] Setup execution frame:

#line 30 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    MT3620Blink_Program_GpioBlinker_Raised_EXECUTION_FRAME__ frame__ =
        { NULL, 3 };
#line 30 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    il2c_link_execution_frame(&frame__);

    //-------------------
    // [3-6] IL body:

    /* IL_0000: nop  */
    /* IL_0001: ldarg.0  */
#line 31 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    frame__.stack0_0__ = this__;
    /* IL_0002: ldfld MT3620Blink.Program.GpioBlinker.output */
#line 31 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    frame__.stack0_1__ = frame__.stack0_0__->output;
    /* IL_0007: ldarg.0  */
#line 31 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    frame__.stack1_0__ = this__;
    /* IL_0008: ldfld MT3620Blink.Program.GpioBlinker.flag */
#line 31 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    stack1_1__ = frame__.stack1_0__->flag;
    /* IL_000d: callvirt MT3620Blink.GpioOutput.SetValue */
#line 31 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    MT3620Blink_GpioOutput_SetValue(frame__.stack0_1__, stack1_1__);
    /* IL_0012: nop  */
    /* IL_0013: ldarg.0  */
#line 32 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    frame__.stack0_0__ = this__;
    /* IL_0014: ldarg.0  */
#line 32 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    frame__.stack1_0__ = this__;
    /* IL_0015: ldfld MT3620Blink.Program.GpioBlinker.flag */
#line 32 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    stack1_1__ = frame__.stack1_0__->flag;
    /* IL_001a: ldc.i4.0  */
#line 32 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    stack2_0__ = 0;
    /* IL_001b: ceq  */
#line 32 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    stack1_2__ = (int32_t)stack1_1__ == (int32_t)stack2_0__;
    /* IL_001d: stfld MT3620Blink.Program.GpioBlinker.flag */
#line 32 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    frame__.stack0_0__->flag = (bool)stack1_2__;
    /* IL_0022: ret  */
#line 33 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    il2c_unlink_execution_frame(&frame__);
#line 33 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    return;
#line 33 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
}

///////////////////////////////////////
// [3] MT3620Blink.Program.GpioBlinker.NextInterval(MT3620Blink.Program.GpioBlinker this__)

//-------------------
// [3-7] Declare execution frame:

typedef struct MT3620Blink_Program_GpioBlinker_NextInterval_EXECUTION_FRAME_DECL
{
    const IL2C_EXECUTION_FRAME* pNext__;
    const uint16_t objRefCount__;
    const uint16_t valueCount__;
    //-------------------- objref
    MT3620Blink_Program_GpioBlinker* stack0_0__;
    MT3620Blink_Program_GpioBlinker* stack1_0__;
    il2c_arraytype(System_Int64)* stack1_1__;
    MT3620Blink_Program_GpioBlinker* stack2_0__;
} MT3620Blink_Program_GpioBlinker_NextInterval_EXECUTION_FRAME__;

//-------------------
// [3-2] Function body:

void MT3620Blink_Program_GpioBlinker_NextInterval(MT3620Blink_Program_GpioBlinker* this__)
{
#line 36 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    il2c_assert(this__ != NULL);

    //-------------------
    // [3-4] Evaluation stacks (!objref):

#line 36 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    int64_t stack1_2__;
#line 36 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    int32_t stack1_3__;
#line 36 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    int32_t stack2_1__;

    //-------------------
    // [3-5] Setup execution frame:

#line 36 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    MT3620Blink_Program_GpioBlinker_NextInterval_EXECUTION_FRAME__ frame__ =
        { NULL, 4 };
#line 36 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    il2c_link_execution_frame(&frame__);

    //-------------------
    // [3-6] IL body:

    /* IL_0000: nop  */
    /* IL_0001: ldarg.0  */
#line 37 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    frame__.stack0_0__ = this__;
    /* IL_0002: ldarg.0  */
#line 37 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    frame__.stack1_0__ = this__;
    /* IL_0003: ldfld MT3620Blink.Program.GpioBlinker.blinkIntervals */
#line 37 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    frame__.stack1_1__ = frame__.stack1_0__->blinkIntervals;
    /* IL_0008: ldarg.0  */
#line 37 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    frame__.stack2_0__ = this__;
    /* IL_0009: ldfld MT3620Blink.Program.GpioBlinker.blinkIntervalIndex */
#line 37 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    stack2_1__ = frame__.stack2_0__->blinkIntervalIndex;
    /* IL_000e: ldelem.i8  */
#line 37 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    stack1_2__ = il2c_array_item(frame__.stack1_1__, int64_t, stack2_1__);
    /* IL_000f: call MT3620Blink.Timer.SetInterval */
#line 37 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    MT3620Blink_Timer_SetInterval((MT3620Blink_Timer*)frame__.stack0_0__, stack1_2__);
    /* IL_0014: nop  */
    /* IL_0015: ldarg.0  */
#line 39 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    frame__.stack0_0__ = this__;
    /* IL_0016: ldarg.0  */
#line 39 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    frame__.stack1_0__ = this__;
    /* IL_0017: ldfld MT3620Blink.Program.GpioBlinker.blinkIntervalIndex */
#line 39 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    stack1_3__ = frame__.stack1_0__->blinkIntervalIndex;
    /* IL_001c: ldc.i4.1  */
#line 39 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    stack2_1__ = 1;
    /* IL_001d: add  */
#line 39 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    stack1_3__ = stack1_3__ + stack2_1__;
    /* IL_001e: stfld MT3620Blink.Program.GpioBlinker.blinkIntervalIndex */
#line 39 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    frame__.stack0_0__->blinkIntervalIndex = stack1_3__;
    /* IL_0023: ldarg.0  */
#line 40 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    frame__.stack0_0__ = this__;
    /* IL_0024: ldarg.0  */
#line 40 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    frame__.stack1_0__ = this__;
    /* IL_0025: ldfld MT3620Blink.Program.GpioBlinker.blinkIntervalIndex */
#line 40 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    stack1_3__ = frame__.stack1_0__->blinkIntervalIndex;
    /* IL_002a: ldc.i4.3  */
#line 40 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    stack2_1__ = 3;
    /* IL_002b: rem  */
#line 40 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    stack1_3__ = stack1_3__ % stack2_1__;
    /* IL_002c: stfld MT3620Blink.Program.GpioBlinker.blinkIntervalIndex */
#line 40 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    frame__.stack0_0__->blinkIntervalIndex = stack1_3__;
    /* IL_0031: ret  */
#line 41 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    il2c_unlink_execution_frame(&frame__);
#line 41 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    return;
#line 41 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
}

//////////////////////
// [7] Runtime helpers:

// [7-10-2] VTable
MT3620Blink_Program_GpioBlinker_VTABLE_DECL__ MT3620Blink_Program_GpioBlinker_VTABLE__ = {
    0, // Adjustor offset
    (bool (*)(void*, System_Object*))System_Object_Equals,
    (void (*)(void*))System_Object_Finalize,
    (int32_t (*)(void*))System_Object_GetHashCode,
    (System_String* (*)(void*))System_Object_ToString,
    (void (*)(void*))MT3620Blink_Program_GpioBlinker_Dispose,
    (void (*)(void*))MT3620Blink_Program_GpioBlinker_Raised,
};

// [7-13] VTable for System.IDisposable
System_IDisposable_VTABLE_DECL__ MT3620Blink_Program_GpioBlinker_System_IDisposable_VTABLE__ = {
    il2c_adjustor_offset(MT3620Blink_Program_GpioBlinker, System_IDisposable),
    (void (*)(void*))MT3620Blink_Program_GpioBlinker_Dispose,
};

// [7-13] VTable for MT3620Blink.IEPollListener
MT3620Blink_IEPollListener_VTABLE_DECL__ MT3620Blink_Program_GpioBlinker_MT3620Blink_IEPollListener_VTABLE__ = {
    il2c_adjustor_offset(MT3620Blink_Program_GpioBlinker, MT3620Blink_IEPollListener),
    (int32_t (*)(void*))MT3620Blink_Timer_MT3620Blink_IEPollListener_get_Identity,
    (void (*)(void*))MT3620Blink_Timer_MT3620Blink_IEPollListener_OnRaised,
};

// [7-8] Runtime type information
IL2C_RUNTIME_TYPE_BEGIN(MT3620Blink_Program_GpioBlinker, "MT3620Blink.Program.GpioBlinker", IL2C_TYPE_REFERENCE, sizeof(MT3620Blink_Program_GpioBlinker), MT3620Blink_Timer, 2, 2)
    IL2C_RUNTIME_TYPE_MARK_TARGET_FOR_REFERENCE(MT3620Blink_Program_GpioBlinker, blinkIntervals)
    IL2C_RUNTIME_TYPE_MARK_TARGET_FOR_REFERENCE(MT3620Blink_Program_GpioBlinker, output)
    IL2C_RUNTIME_TYPE_INTERFACE(MT3620Blink_Program_GpioBlinker, System_IDisposable)
    IL2C_RUNTIME_TYPE_INTERFACE(MT3620Blink_Program_GpioBlinker, MT3620Blink_IEPollListener)
IL2C_RUNTIME_TYPE_END();

//////////////////////////////////////////////////////////////////////////////////
// [9-1] Type: MT3620Blink.Program

//////////////////////////////////////////////////////////////////////////////////
// [9-2] File scope prototypes:

//////////////////////////////////////////////////////////////////////////////////
// [2-3] Methods: MT3620Blink.Program.GpioPoller

extern /* public sealed */ void MT3620Blink_Program_GpioPoller__ctor(MT3620Blink_Program_GpioPoller* this__, int32_t gpioId, MT3620Blink_Program_GpioBlinker* blinker);
extern /* public override sealed */ void MT3620Blink_Program_GpioPoller_Dispose(MT3620Blink_Program_GpioPoller* this__);
extern /* protected override sealed */ void MT3620Blink_Program_GpioPoller_Raised(MT3620Blink_Program_GpioPoller* this__);

//////////////////////////////////////////////////////////////////////////////////
// [9-4] Type: MT3620Blink.Program.GpioPoller

///////////////////////////////////////
// [3] MT3620Blink.Program.GpioPoller..ctor(MT3620Blink.Program.GpioPoller this__, System.Int32 gpioId, MT3620Blink.Program.GpioBlinker blinker)

//-------------------
// [3-7] Declare execution frame:

typedef struct MT3620Blink_Program_GpioPoller__ctor_EXECUTION_FRAME_DECL
{
    const IL2C_EXECUTION_FRAME* pNext__;
    const uint16_t objRefCount__;
    const uint16_t valueCount__;
    //-------------------- objref
    MT3620Blink_Program_GpioPoller* stack0_0__;
    MT3620Blink_GpioInput* stack1_1__;
    MT3620Blink_Program_GpioPoller* stack1_2__;
    MT3620Blink_Program_GpioBlinker* stack1_4__;
} MT3620Blink_Program_GpioPoller__ctor_EXECUTION_FRAME__;

//-------------------
// [3-2] Function body:

void MT3620Blink_Program_GpioPoller__ctor(MT3620Blink_Program_GpioPoller* this__, int32_t gpioId, MT3620Blink_Program_GpioBlinker* blinker)
{
#line 50 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    il2c_assert(this__ != NULL);

    //-------------------
    // [3-4] Evaluation stacks (!objref):

#line 50 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    int32_t stack1_0__;
#line 50 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    bool stack1_3__;
#line 50 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    int64_t stack1_5__;

    //-------------------
    // [3-5] Setup execution frame:

#line 50 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    MT3620Blink_Program_GpioPoller__ctor_EXECUTION_FRAME__ frame__ =
        { NULL, 4 };
#line 50 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    il2c_link_execution_frame(&frame__);

    //-------------------
    // [3-6] IL body:

    /* IL_0000: ldarg.0  */
#line 50 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    frame__.stack0_0__ = this__;
    /* IL_0001: call MT3620Blink.Timer..ctor */
#line 50 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    MT3620Blink_Timer__ctor((MT3620Blink_Timer*)frame__.stack0_0__);
    /* IL_0006: nop  */
    /* IL_0007: nop  */
    /* IL_0008: ldarg.0  */
#line 52 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    frame__.stack0_0__ = this__;
    /* IL_0009: ldarg.1  */
#line 52 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    stack1_0__ = gpioId;
    /* IL_000a: newobj MT3620Blink.GpioInput..ctor */
#line 52 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    frame__.stack1_1__ = il2c_get_uninitialized_object(MT3620Blink_GpioInput);
#line 52 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    MT3620Blink_GpioInput__ctor(frame__.stack1_1__, stack1_0__);
    /* IL_000f: stfld MT3620Blink.Program.GpioPoller.input */
#line 52 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    frame__.stack0_0__->input = frame__.stack1_1__;
    /* IL_0014: ldarg.0  */
#line 53 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    frame__.stack0_0__ = this__;
    /* IL_0015: ldarg.0  */
#line 53 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    frame__.stack1_2__ = this__;
    /* IL_0016: ldfld MT3620Blink.Program.GpioPoller.input */
#line 53 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    frame__.stack1_1__ = frame__.stack1_2__->input;
    /* IL_001b: callvirt MT3620Blink.GpioInput.get_Value */
#line 53 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    stack1_3__ = MT3620Blink_GpioInput_get_Value(frame__.stack1_1__);
    /* IL_0020: stfld MT3620Blink.Program.GpioPoller.last */
#line 53 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    frame__.stack0_0__->last = stack1_3__;
    /* IL_0025: ldarg.0  */
#line 54 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    frame__.stack0_0__ = this__;
    /* IL_0026: ldarg.2  */
#line 54 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    frame__.stack1_4__ = blinker;
    /* IL_0027: stfld MT3620Blink.Program.GpioPoller.blinker */
#line 54 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    frame__.stack0_0__->blinker = frame__.stack1_4__;
    /* IL_002c: ldarg.0  */
#line 55 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    frame__.stack0_0__ = this__;
    /* IL_002d: ldc.i4 100000000 */
#line 55 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    stack1_0__ = 100000000;
    /* IL_0032: conv.i8  */
#line 55 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    stack1_5__ = (int64_t)stack1_0__;
    /* IL_0033: call MT3620Blink.Timer.SetInterval */
#line 55 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    MT3620Blink_Timer_SetInterval((MT3620Blink_Timer*)frame__.stack0_0__, stack1_5__);
    /* IL_0038: nop  */
    /* IL_0039: ret  */
#line 56 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    il2c_unlink_execution_frame(&frame__);
#line 56 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    return;
#line 56 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
}

///////////////////////////////////////
// [3] Virtual: MT3620Blink.Program.GpioPoller.Dispose(MT3620Blink.Program.GpioPoller this__)

//-------------------
// [3-7] Declare execution frame:

typedef struct MT3620Blink_Program_GpioPoller_Dispose_EXECUTION_FRAME_DECL
{
    const IL2C_EXECUTION_FRAME* pNext__;
    const uint16_t objRefCount__;
    const uint16_t valueCount__;
    //-------------------- objref
    MT3620Blink_Program_GpioPoller* stack0_0__;
    MT3620Blink_GpioInput* stack0_1__;
} MT3620Blink_Program_GpioPoller_Dispose_EXECUTION_FRAME__;

//-------------------
// [3-2] Function body:

void MT3620Blink_Program_GpioPoller_Dispose(MT3620Blink_Program_GpioPoller* this__)
{
#line 59 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    il2c_assert(this__ != NULL);

    //-------------------
    // [3-5] Setup execution frame:

#line 59 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    MT3620Blink_Program_GpioPoller_Dispose_EXECUTION_FRAME__ frame__ =
        { NULL, 2 };
#line 59 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    il2c_link_execution_frame(&frame__);

    //-------------------
    // [3-6] IL body:

    /* IL_0000: nop  */
    /* IL_0001: ldarg.0  */
#line 60 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    frame__.stack0_0__ = this__;
    /* IL_0002: call MT3620Blink.Descriptor.Dispose */
#line 60 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    MT3620Blink_Descriptor_Dispose((MT3620Blink_Descriptor*)frame__.stack0_0__);
    /* IL_0007: nop  */
    /* IL_0008: ldarg.0  */
#line 61 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    frame__.stack0_0__ = this__;
    /* IL_0009: ldfld MT3620Blink.Program.GpioPoller.input */
#line 61 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    frame__.stack0_1__ = frame__.stack0_0__->input;
    /* IL_000e: callvirt MT3620Blink.Descriptor.Dispose */
#line 61 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    frame__.stack0_1__->vptr0__->Dispose((MT3620Blink_Descriptor*)frame__.stack0_1__);
    /* IL_0013: nop  */
    /* IL_0014: ret  */
#line 62 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    il2c_unlink_execution_frame(&frame__);
#line 62 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    return;
#line 62 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
}

///////////////////////////////////////
// [3] Virtual: MT3620Blink.Program.GpioPoller.Raised(MT3620Blink.Program.GpioPoller this__)

//-------------------
// [3-7] Declare execution frame:

typedef struct MT3620Blink_Program_GpioPoller_Raised_EXECUTION_FRAME_DECL
{
    const IL2C_EXECUTION_FRAME* pNext__;
    const uint16_t objRefCount__;
    const uint16_t valueCount__;
    //-------------------- objref
    MT3620Blink_Program_GpioPoller* stack0_0__;
    MT3620Blink_GpioInput* stack0_1__;
    MT3620Blink_Program_GpioBlinker* stack0_4__;
    MT3620Blink_Program_GpioPoller* stack1_0__;
} MT3620Blink_Program_GpioPoller_Raised_EXECUTION_FRAME__;

//-------------------
// [3-2] Function body:

void MT3620Blink_Program_GpioPoller_Raised(MT3620Blink_Program_GpioPoller* this__)
{
#line 65 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    il2c_assert(this__ != NULL);

    //-------------------
    // [3-3] Local variables (!objref):

#line 65 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    bool current = false;
#line 65 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    bool local1__ = false;
#line 65 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    bool local2__ = false;

    //-------------------
    // [3-4] Evaluation stacks (!objref):

#line 65 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    bool stack0_2__;
#line 65 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    int32_t stack0_3__;
#line 65 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    bool stack1_1__;
#line 65 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    int32_t stack1_2__;

    //-------------------
    // [3-5] Setup execution frame:

#line 65 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    MT3620Blink_Program_GpioPoller_Raised_EXECUTION_FRAME__ frame__ =
        { NULL, 4 };
#line 65 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    il2c_link_execution_frame(&frame__);

    //-------------------
    // [3-6] IL body:

    /* IL_0000: nop  */
    /* IL_0001: ldarg.0  */
#line 66 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    frame__.stack0_0__ = this__;
    /* IL_0002: ldfld MT3620Blink.Program.GpioPoller.input */
#line 66 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    frame__.stack0_1__ = frame__.stack0_0__->input;
    /* IL_0007: callvirt MT3620Blink.GpioInput.get_Value */
#line 66 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    stack0_2__ = MT3620Blink_GpioInput_get_Value(frame__.stack0_1__);
    /* IL_000c: stloc.0  */
#line 66 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    current = stack0_2__;
    /* IL_000d: ldloc.0  */
#line 67 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    stack0_2__ = current;
    /* IL_000e: ldarg.0  */
#line 67 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    frame__.stack1_0__ = this__;
    /* IL_000f: ldfld MT3620Blink.Program.GpioPoller.last */
#line 67 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    stack1_1__ = frame__.stack1_0__->last;
    /* IL_0014: ceq  */
#line 67 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    stack0_3__ = (int32_t)stack0_2__ == (int32_t)stack1_1__;
    /* IL_0016: ldc.i4.0  */
#line 67 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    stack1_2__ = 0;
    /* IL_0017: ceq  */
#line 67 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    stack0_3__ = (int32_t)stack0_3__ == (int32_t)stack1_2__;
    /* IL_0019: stloc.1  */
#line 67 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    local1__ = (bool)stack0_3__;
    /* IL_001a: ldloc.1  */
#line 67 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    stack0_2__ = local1__;
    /* IL_001b: brfalse.s IL_0035 */
#line 67 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    if (stack0_2__ == false) goto IL_0035;
    /* IL_001d: nop  */
    /* IL_001e: ldloc.0  */
#line 69 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    stack0_2__ = current;
    /* IL_001f: ldc.i4.0  */
#line 69 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    stack1_2__ = 0;
    /* IL_0020: ceq  */
#line 69 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    stack0_3__ = (int32_t)stack0_2__ == (int32_t)stack1_2__;
    /* IL_0022: stloc.2  */
#line 69 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    local2__ = (bool)stack0_3__;
    /* IL_0023: ldloc.2  */
#line 69 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    stack0_2__ = local2__;
    /* IL_0024: brfalse.s IL_0034 */
#line 69 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    if (stack0_2__ == false) goto IL_0034;
    /* IL_0026: nop  */
    /* IL_0027: ldarg.0  */
#line 71 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    frame__.stack0_0__ = this__;
    /* IL_0028: ldfld MT3620Blink.Program.GpioPoller.blinker */
#line 71 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    frame__.stack0_4__ = frame__.stack0_0__->blinker;
    /* IL_002d: callvirt MT3620Blink.Program.GpioBlinker.NextInterval */
#line 71 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    MT3620Blink_Program_GpioBlinker_NextInterval(frame__.stack0_4__);
    /* IL_0032: nop  */
    /* IL_0033: nop  */
IL_0034:
    /* IL_0034: nop  */
IL_0035:
    /* IL_0035: ldarg.0  */
#line 74 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    frame__.stack0_0__ = this__;
    /* IL_0036: ldloc.0  */
#line 74 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    stack1_1__ = current;
    /* IL_0037: stfld MT3620Blink.Program.GpioPoller.last */
#line 74 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    frame__.stack0_0__->last = stack1_1__;
    /* IL_003c: ret  */
#line 75 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    il2c_unlink_execution_frame(&frame__);
#line 75 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    return;
#line 75 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
}

//////////////////////
// [7] Runtime helpers:

// [7-10-2] VTable
MT3620Blink_Program_GpioPoller_VTABLE_DECL__ MT3620Blink_Program_GpioPoller_VTABLE__ = {
    0, // Adjustor offset
    (bool (*)(void*, System_Object*))System_Object_Equals,
    (void (*)(void*))System_Object_Finalize,
    (int32_t (*)(void*))System_Object_GetHashCode,
    (System_String* (*)(void*))System_Object_ToString,
    (void (*)(void*))MT3620Blink_Program_GpioPoller_Dispose,
    (void (*)(void*))MT3620Blink_Program_GpioPoller_Raised,
};

// [7-13] VTable for System.IDisposable
System_IDisposable_VTABLE_DECL__ MT3620Blink_Program_GpioPoller_System_IDisposable_VTABLE__ = {
    il2c_adjustor_offset(MT3620Blink_Program_GpioPoller, System_IDisposable),
    (void (*)(void*))MT3620Blink_Program_GpioPoller_Dispose,
};

// [7-13] VTable for MT3620Blink.IEPollListener
MT3620Blink_IEPollListener_VTABLE_DECL__ MT3620Blink_Program_GpioPoller_MT3620Blink_IEPollListener_VTABLE__ = {
    il2c_adjustor_offset(MT3620Blink_Program_GpioPoller, MT3620Blink_IEPollListener),
    (int32_t (*)(void*))MT3620Blink_Timer_MT3620Blink_IEPollListener_get_Identity,
    (void (*)(void*))MT3620Blink_Timer_MT3620Blink_IEPollListener_OnRaised,
};

// [7-8] Runtime type information
IL2C_RUNTIME_TYPE_BEGIN(MT3620Blink_Program_GpioPoller, "MT3620Blink.Program.GpioPoller", IL2C_TYPE_REFERENCE, sizeof(MT3620Blink_Program_GpioPoller), MT3620Blink_Timer, 2, 2)
    IL2C_RUNTIME_TYPE_MARK_TARGET_FOR_REFERENCE(MT3620Blink_Program_GpioPoller, input)
    IL2C_RUNTIME_TYPE_MARK_TARGET_FOR_REFERENCE(MT3620Blink_Program_GpioPoller, blinker)
    IL2C_RUNTIME_TYPE_INTERFACE(MT3620Blink_Program_GpioPoller, System_IDisposable)
    IL2C_RUNTIME_TYPE_INTERFACE(MT3620Blink_Program_GpioPoller, MT3620Blink_IEPollListener)
IL2C_RUNTIME_TYPE_END();

//////////////////////////////////////////////////////////////////////////////////
// [9-1] Type: MT3620Blink.Program

//////////////////////////////////////////////////////////////////////////////////
// [9-2] File scope prototypes:

//////////////////////////////////////////////////////////////////////////////////
// [9-4] Type: MT3620Blink.Program

///////////////////////////////////////
// [3] MT3620Blink.Program.Main()

//-------------------
// [3-1] Exception filters:

static int16_t MT3620Blink_Program_Main_ExceptionFilter0__(System_Exception* ex)
{
    il2c_assert(ex != NULL);
    return IL2C_FILTER_FINALLY;  // Not matched (will go to finally)
}

static int16_t MT3620Blink_Program_Main_ExceptionFilter1__(System_Exception* ex)
{
    il2c_assert(ex != NULL);
    return IL2C_FILTER_FINALLY;  // Not matched (will go to finally)
}

static int16_t MT3620Blink_Program_Main_ExceptionFilter2__(System_Exception* ex)
{
    il2c_assert(ex != NULL);
    return IL2C_FILTER_FINALLY;  // Not matched (will go to finally)
}

//-------------------
// [3-7] Declare execution frame:

typedef struct MT3620Blink_Program_Main_EXECUTION_FRAME_DECL
{
    const IL2C_EXECUTION_FRAME* pNext__;
    const uint16_t objRefCount__;
    const uint16_t valueCount__;
    //-------------------- objref
    MT3620Blink_Application* epoll;
    MT3620Blink_Program_GpioBlinker* ledBlinker;
    MT3620Blink_Program_GpioPoller* buttonPoller;
    MT3620Blink_Application* stack0_0__;
    MT3620Blink_Program_GpioBlinker* stack0_2__;
    MT3620Blink_Program_GpioPoller* stack0_3__;
    MT3620Blink_Program_GpioBlinker* stack1_0__;
    MT3620Blink_Program_GpioPoller* stack1_1__;
} MT3620Blink_Program_Main_EXECUTION_FRAME__;

//-------------------
// [3-2] Function body:

int32_t MT3620Blink_Program_Main(void)
{
    //-------------------
    // [3-3] Local variables (!objref):

#line 79 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    volatile int32_t local3__ = 0;

    //-------------------
    // [3-4] Evaluation stacks (!objref):

#line 79 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    int32_t stack0_1__;

    //-------------------
    // [3-5] Setup execution frame:

#line 79 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    MT3620Blink_Program_Main_EXECUTION_FRAME__ frame__ =
        { NULL, 8 };
#line 79 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    il2c_link_execution_frame(&frame__);

    //-------------------
    // [3-6] IL body:

    /* IL_0000: nop  */
    /* IL_0001: newobj MT3620Blink.Application..ctor */
#line 80 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    frame__.stack0_0__ = il2c_get_uninitialized_object(MT3620Blink_Application);
#line 80 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    MT3620Blink_Application__ctor(frame__.stack0_0__);
    /* IL_0006: stloc.0  */
#line 80 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    frame__.epoll = frame__.stack0_0__;
#line 81 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    il2c_try(nest0, MT3620Blink_Program_Main_ExceptionFilter0__)
#line 81 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    {
        /* IL_0007: nop  */
        /* IL_0008: ldsfld MT3620Blink.Interops.MT3620_RDB_LED1_RED */
#line 82 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
        stack0_1__ = MT3620Blink_Interops_MT3620_RDB_LED1_RED;
        /* IL_000d: newobj MT3620Blink.Program.GpioBlinker..ctor */
#line 82 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
        frame__.stack0_2__ = il2c_get_uninitialized_object(MT3620Blink_Program_GpioBlinker);
#line 82 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
        MT3620Blink_Program_GpioBlinker__ctor(frame__.stack0_2__, stack0_1__);
        /* IL_0012: stloc.1  */
#line 82 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
        frame__.ledBlinker = frame__.stack0_2__;
#line 83 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
        il2c_try(nest1, MT3620Blink_Program_Main_ExceptionFilter1__)
#line 83 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
        {
            /* IL_0013: nop  */
            /* IL_0014: ldsfld MT3620Blink.Interops.MT3620_RDB_BUTTON_A */
#line 84 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
            stack0_1__ = MT3620Blink_Interops_MT3620_RDB_BUTTON_A;
            /* IL_0019: ldloc.1  */
#line 84 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
            frame__.stack1_0__ = frame__.ledBlinker;
            /* IL_001a: newobj MT3620Blink.Program.GpioPoller..ctor */
#line 84 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
            frame__.stack0_3__ = il2c_get_uninitialized_object(MT3620Blink_Program_GpioPoller);
#line 84 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
            MT3620Blink_Program_GpioPoller__ctor(frame__.stack0_3__, stack0_1__, frame__.stack1_0__);
            /* IL_001f: stloc.2  */
#line 84 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
            frame__.buttonPoller = frame__.stack0_3__;
#line 85 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
            il2c_try(nest2, MT3620Blink_Program_Main_ExceptionFilter2__)
#line 85 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
            {
                /* IL_0020: nop  */
                /* IL_0021: ldloc.0  */
#line 86 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
                frame__.stack0_0__ = frame__.epoll;
                /* IL_0022: ldloc.1  */
#line 86 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
                frame__.stack1_0__ = frame__.ledBlinker;
                /* IL_0023: callvirt MT3620Blink.Application.RegisterDescriptor */
#line 86 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
                MT3620Blink_Application_RegisterDescriptor(frame__.stack0_0__, il2c_cast_to_interface(MT3620Blink_IEPollListener, MT3620Blink_Program_GpioBlinker, frame__.stack1_0__));
                /* IL_0028: nop  */
                /* IL_0029: ldloc.0  */
#line 87 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
                frame__.stack0_0__ = frame__.epoll;
                /* IL_002a: ldloc.2  */
#line 87 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
                frame__.stack1_1__ = frame__.buttonPoller;
                /* IL_002b: callvirt MT3620Blink.Application.RegisterDescriptor */
#line 87 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
                MT3620Blink_Application_RegisterDescriptor(frame__.stack0_0__, il2c_cast_to_interface(MT3620Blink_IEPollListener, MT3620Blink_Program_GpioPoller, frame__.stack1_1__));
                /* IL_0030: nop  */
                /* IL_0031: ldloc.0  */
#line 89 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
                frame__.stack0_0__ = frame__.epoll;
                /* IL_0032: callvirt MT3620Blink.Application.Run */
#line 89 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
                MT3620Blink_Application_Run(frame__.stack0_0__);
                /* IL_0037: nop  */
                /* IL_0038: nop  */
                /* IL_0039: leave.s IL_0046 */
#line 90 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
                il2c_leave(nest2, 0);
#line 90 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
            }
#line 90 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
            il2c_finally(nest2)
#line 90 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
            {
                /* IL_003b: ldloc.2  */
#line 90 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
                frame__.stack0_3__ = frame__.buttonPoller;
                /* IL_003c: brfalse.s IL_0045 */
#line 90 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
                if (frame__.stack0_3__ == NULL) goto IL_0045;
                /* IL_003e: ldloc.2  */
#line 90 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
                frame__.stack0_3__ = frame__.buttonPoller;
                /* IL_003f: callvirt System.IDisposable.Dispose */
#line 90 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
                MT3620Blink_Program_GpioPoller_Dispose(il2c_adjusted_reference(frame__.stack0_3__));
                /* IL_0044: nop  */
            IL_0045:
                /* IL_0045: endfinally  */
#line 90 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
                il2c_endfinally(nest2);
#line 91 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
            }
#line 91 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
            il2c_leave_to(nest2)
#line 91 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
            {
#line 91 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
                il2c_leave_bind(nest2, 0, IL_0046);
#line 91 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
            }
#line 91 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
            il2c_end_try(nest2);
        IL_0046:
            /* IL_0046: nop  */
            /* IL_0047: leave.s IL_0054 */
#line 91 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
            il2c_leave(nest1, 1);
#line 91 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
        }
#line 91 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
        il2c_finally(nest1)
#line 91 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
        {
            /* IL_0049: ldloc.1  */
#line 91 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
            frame__.stack0_2__ = frame__.ledBlinker;
            /* IL_004a: brfalse.s IL_0053 */
#line 91 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
            if (frame__.stack0_2__ == NULL) goto IL_0053;
            /* IL_004c: ldloc.1  */
#line 91 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
            frame__.stack0_2__ = frame__.ledBlinker;
            /* IL_004d: callvirt System.IDisposable.Dispose */
#line 91 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
            MT3620Blink_Program_GpioBlinker_Dispose(il2c_adjusted_reference(frame__.stack0_2__));
            /* IL_0052: nop  */
        IL_0053:
            /* IL_0053: endfinally  */
#line 91 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
            il2c_endfinally(nest1);
#line 92 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
        }
#line 92 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
        il2c_leave_to(nest1)
#line 92 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
        {
#line 92 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
            il2c_leave_bind(nest1, 0, IL_0046);
#line 92 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
            il2c_leave_bind(nest1, 1, IL_0054);
#line 92 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
        }
#line 92 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
        il2c_end_try(nest1);
    IL_0054:
        /* IL_0054: nop  */
        /* IL_0055: leave.s IL_0062 */
#line 92 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
        il2c_leave(nest0, 2);
#line 92 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    }
#line 92 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    il2c_finally(nest0)
#line 92 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    {
        /* IL_0057: ldloc.0  */
#line 92 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
        frame__.stack0_0__ = frame__.epoll;
        /* IL_0058: brfalse.s IL_0061 */
#line 92 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
        if (frame__.stack0_0__ == NULL) goto IL_0061;
        /* IL_005a: ldloc.0  */
#line 92 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
        frame__.stack0_0__ = frame__.epoll;
        /* IL_005b: callvirt System.IDisposable.Dispose */
#line 92 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
        MT3620Blink_Descriptor_Dispose(il2c_adjusted_reference(frame__.stack0_0__));
        /* IL_0060: nop  */
    IL_0061:
        /* IL_0061: endfinally  */
#line 92 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
        il2c_endfinally(nest0);
#line 94 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    }
#line 94 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    il2c_leave_to(nest0)
#line 94 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    {
#line 94 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
        il2c_leave_bind(nest0, 0, IL_0046);
#line 94 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
        il2c_leave_bind(nest0, 1, IL_0054);
#line 94 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
        il2c_leave_bind(nest0, 2, IL_0062);
#line 94 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    }
#line 94 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    il2c_end_try(nest0);
IL_0062:
    /* IL_0062: ldc.i4.0  */
#line 94 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    stack0_1__ = 0;
    /* IL_0063: stloc.3  */
#line 94 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    local3__ = stack0_1__;
    /* IL_0064: br.s IL_0066 */
#line 94 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    goto IL_0066;
IL_0066:
    /* IL_0066: ldloc.3  */
#line 95 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    stack0_1__ = local3__;
    /* IL_0067: ret  */
#line 95 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    il2c_unlink_execution_frame(&frame__);
#line 95 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    return stack0_1__;
#line 95 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
}

//////////////////////
// [7] Runtime helpers:

// [7-10-1] VTable (Not defined, same as System.Object)

// [7-8] Runtime type information
IL2C_RUNTIME_TYPE_BEGIN(MT3620Blink_Program, "MT3620Blink.Program", IL2C_TYPE_REFERENCE, sizeof(MT3620Blink_Program), System_Object, 0, 0)
IL2C_RUNTIME_TYPE_END();

#ifdef __cplusplus
}
#endif
