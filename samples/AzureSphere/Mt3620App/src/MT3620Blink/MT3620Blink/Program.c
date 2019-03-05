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
    il2c_assert(this__ != NULL);

    //-------------------
    // [3-4] Evaluation stacks (!objref):

    int32_t stack1_0__;
    int32_t stack2_1__;
    System_RuntimeFieldHandle stack3_0__;
    int32_t stack3_1__;

    //-------------------
    // [3-5] Setup execution frame:

    MT3620Blink_Program_GpioBlinker__ctor_EXECUTION_FRAME__ frame__ =
        { NULL, 4 };
    il2c_link_execution_frame(&frame__);

    //-------------------
    // [3-6] IL body:

    /* IL_0000: ldarg.0                         : Program.cs(9) */
    frame__.stack0_0__ = this__;
    /* IL_0001: ldc.i4.3                        : Program.cs(9) */
    stack1_0__ = 3;
    /* IL_0002: newarr System.Int64             : Program.cs(9) */
    frame__.stack1_1__ = il2c_new_array(System_Int64, stack1_0__);
    /* IL_0007: dup                             : Program.cs(9) */
    frame__.stack2_0__ = frame__.stack1_1__;
    /* IL_0008: ldtoken .<PrivateImplementationDetails>.E902362F9BEE92BBA97ECE5B88B94AF4A8D3201D : Program.cs(9) */
    stack3_0__.size__ = 24;
    stack3_0__.field__ = MT3620Blink_declaredValue0__;
    /* IL_000d: call System.Runtime.CompilerServices.RuntimeHelpers.InitializeArray : Program.cs(9) */
    System_Runtime_CompilerServices_RuntimeHelpers_InitializeArray((System_Array*)frame__.stack2_0__, stack3_0__);
    /* IL_0012: stfld MT3620Blink.Program.GpioBlinker.blinkIntervals : Program.cs(9) */
    frame__.stack0_0__->blinkIntervals = frame__.stack1_1__;
    /* IL_0017: ldarg.0                         : Program.cs(14) */
    frame__.stack0_0__ = this__;
    /* IL_0018: call MT3620Blink.Timer..ctor    : Program.cs(14) */
    MT3620Blink_Timer__ctor((MT3620Blink_Timer*)frame__.stack0_0__);
    /* IL_001d: nop                             : Program.cs(14) */
    /* IL_001e: nop  */
    /* IL_001f: ldarg.0  */
    frame__.stack0_0__ = this__;
    /* IL_0020: ldarg.1                         : Program.cs(16) */
    stack1_0__ = gpioId;
    /* IL_0021: ldc.i4.0                        : Program.cs(16) */
    stack2_1__ = 0;
    /* IL_0022: ldc.i4.1                        : Program.cs(16) */
    stack3_1__ = 1;
    /* IL_0023: newobj MT3620Blink.GpioOutput..ctor : Program.cs(16) */
    frame__.stack1_2__ = il2c_get_uninitialized_object(MT3620Blink_GpioOutput);
    MT3620Blink_GpioOutput__ctor(frame__.stack1_2__, stack1_0__, (MT3620Blink_GPIO_OutputMode_Type)stack2_1__, (bool)stack3_1__);
    /* IL_0028: stfld MT3620Blink.Program.GpioBlinker.output : Program.cs(16) */
    frame__.stack0_0__->output = frame__.stack1_2__;
    /* IL_002d: ldarg.0                         : Program.cs(20) */
    frame__.stack0_0__ = this__;
    /* IL_002e: call MT3620Blink.Program.GpioBlinker.NextInterval : Program.cs(20) */
    MT3620Blink_Program_GpioBlinker_NextInterval(frame__.stack0_0__);
    /* IL_0033: nop                             : Program.cs(20) */
    /* IL_0034: ret  */
    il2c_unlink_execution_frame(&frame__);
    return;
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
    il2c_assert(this__ != NULL);

    //-------------------
    // [3-5] Setup execution frame:

    MT3620Blink_Program_GpioBlinker_Dispose_EXECUTION_FRAME__ frame__ =
        { NULL, 2 };
    il2c_link_execution_frame(&frame__);

    //-------------------
    // [3-6] IL body:

    /* IL_0000: nop                             : Program.cs(24) */
    /* IL_0001: ldarg.0  */
    frame__.stack0_0__ = this__;
    /* IL_0002: call MT3620Blink.Descriptor.Dispose : Program.cs(25) */
    MT3620Blink_Descriptor_Dispose((MT3620Blink_Descriptor*)frame__.stack0_0__);
    /* IL_0007: nop                             : Program.cs(25) */
    /* IL_0008: ldarg.0  */
    frame__.stack0_0__ = this__;
    /* IL_0009: ldfld MT3620Blink.Program.GpioBlinker.output : Program.cs(26) */
    frame__.stack0_1__ = frame__.stack0_0__->output;
    /* IL_000e: callvirt MT3620Blink.Descriptor.Dispose : Program.cs(26) */
    frame__.stack0_1__->vptr0__->Dispose((MT3620Blink_Descriptor*)frame__.stack0_1__);
    /* IL_0013: nop                             : Program.cs(26) */
    /* IL_0014: ret  */
    il2c_unlink_execution_frame(&frame__);
    return;
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
    il2c_assert(this__ != NULL);

    //-------------------
    // [3-4] Evaluation stacks (!objref):

    bool stack1_1__;
    int32_t stack1_2__;
    int32_t stack2_0__;

    //-------------------
    // [3-5] Setup execution frame:

    MT3620Blink_Program_GpioBlinker_Raised_EXECUTION_FRAME__ frame__ =
        { NULL, 3 };
    il2c_link_execution_frame(&frame__);

    //-------------------
    // [3-6] IL body:

    /* IL_0000: nop                             : Program.cs(30) */
    /* IL_0001: ldarg.0  */
    frame__.stack0_0__ = this__;
    /* IL_0002: ldfld MT3620Blink.Program.GpioBlinker.output : Program.cs(31) */
    frame__.stack0_1__ = frame__.stack0_0__->output;
    /* IL_0007: ldarg.0                         : Program.cs(31) */
    frame__.stack1_0__ = this__;
    /* IL_0008: ldfld MT3620Blink.Program.GpioBlinker.flag : Program.cs(31) */
    stack1_1__ = frame__.stack1_0__->flag;
    /* IL_000d: callvirt MT3620Blink.GpioOutput.SetValue : Program.cs(31) */
    MT3620Blink_GpioOutput_SetValue(frame__.stack0_1__, stack1_1__);
    /* IL_0012: nop                             : Program.cs(31) */
    /* IL_0013: ldarg.0  */
    frame__.stack0_0__ = this__;
    /* IL_0014: ldarg.0                         : Program.cs(32) */
    frame__.stack1_0__ = this__;
    /* IL_0015: ldfld MT3620Blink.Program.GpioBlinker.flag : Program.cs(32) */
    stack1_1__ = frame__.stack1_0__->flag;
    /* IL_001a: ldc.i4.0                        : Program.cs(32) */
    stack2_0__ = 0;
    /* IL_001b: ceq                             : Program.cs(32) */
    stack1_2__ = (int32_t)stack1_1__ == (int32_t)stack2_0__;
    /* IL_001d: stfld MT3620Blink.Program.GpioBlinker.flag : Program.cs(32) */
    frame__.stack0_0__->flag = (bool)stack1_2__;
    /* IL_0022: ret                             : Program.cs(33) */
    il2c_unlink_execution_frame(&frame__);
    return;
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
    il2c_assert(this__ != NULL);

    //-------------------
    // [3-4] Evaluation stacks (!objref):

    int64_t stack1_2__;
    int32_t stack1_3__;
    int32_t stack2_1__;

    //-------------------
    // [3-5] Setup execution frame:

    MT3620Blink_Program_GpioBlinker_NextInterval_EXECUTION_FRAME__ frame__ =
        { NULL, 4 };
    il2c_link_execution_frame(&frame__);

    //-------------------
    // [3-6] IL body:

    /* IL_0000: nop                             : Program.cs(36) */
    /* IL_0001: ldarg.0  */
    frame__.stack0_0__ = this__;
    /* IL_0002: ldarg.0                         : Program.cs(37) */
    frame__.stack1_0__ = this__;
    /* IL_0003: ldfld MT3620Blink.Program.GpioBlinker.blinkIntervals : Program.cs(37) */
    frame__.stack1_1__ = frame__.stack1_0__->blinkIntervals;
    /* IL_0008: ldarg.0                         : Program.cs(37) */
    frame__.stack2_0__ = this__;
    /* IL_0009: ldfld MT3620Blink.Program.GpioBlinker.blinkIntervalIndex : Program.cs(37) */
    stack2_1__ = frame__.stack2_0__->blinkIntervalIndex;
    /* IL_000e: ldelem.i8                       : Program.cs(37) */
    stack1_2__ = il2c_array_item(frame__.stack1_1__, int64_t, stack2_1__);
    /* IL_000f: call MT3620Blink.Timer.SetInterval : Program.cs(37) */
    MT3620Blink_Timer_SetInterval((MT3620Blink_Timer*)frame__.stack0_0__, stack1_2__);
    /* IL_0014: nop                             : Program.cs(37) */
    /* IL_0015: ldarg.0  */
    frame__.stack0_0__ = this__;
    /* IL_0016: ldarg.0                         : Program.cs(39) */
    frame__.stack1_0__ = this__;
    /* IL_0017: ldfld MT3620Blink.Program.GpioBlinker.blinkIntervalIndex : Program.cs(39) */
    stack1_3__ = frame__.stack1_0__->blinkIntervalIndex;
    /* IL_001c: ldc.i4.1                        : Program.cs(39) */
    stack2_1__ = 1;
    /* IL_001d: add                             : Program.cs(39) */
    stack1_3__ = stack1_3__ + stack2_1__;
    /* IL_001e: stfld MT3620Blink.Program.GpioBlinker.blinkIntervalIndex : Program.cs(39) */
    frame__.stack0_0__->blinkIntervalIndex = stack1_3__;
    /* IL_0023: ldarg.0                         : Program.cs(40) */
    frame__.stack0_0__ = this__;
    /* IL_0024: ldarg.0                         : Program.cs(40) */
    frame__.stack1_0__ = this__;
    /* IL_0025: ldfld MT3620Blink.Program.GpioBlinker.blinkIntervalIndex : Program.cs(40) */
    stack1_3__ = frame__.stack1_0__->blinkIntervalIndex;
    /* IL_002a: ldc.i4.3                        : Program.cs(40) */
    stack2_1__ = 3;
    /* IL_002b: rem                             : Program.cs(40) */
    stack1_3__ = stack1_3__ % stack2_1__;
    /* IL_002c: stfld MT3620Blink.Program.GpioBlinker.blinkIntervalIndex : Program.cs(40) */
    frame__.stack0_0__->blinkIntervalIndex = stack1_3__;
    /* IL_0031: ret                             : Program.cs(41) */
    il2c_unlink_execution_frame(&frame__);
    return;
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

extern /* public sealed */ void MT3620Blink_Program_GpioPoller__ctor(MT3620Blink_Program_GpioPoller* this__, int32_t changeInputGpioId, int32_t exitInputGpioId, MT3620Blink_Program_GpioBlinker* blinker, MT3620Blink_Application* app);
extern /* public override sealed */ void MT3620Blink_Program_GpioPoller_Dispose(MT3620Blink_Program_GpioPoller* this__);
extern /* protected override sealed */ void MT3620Blink_Program_GpioPoller_Raised(MT3620Blink_Program_GpioPoller* this__);

//////////////////////////////////////////////////////////////////////////////////
// [9-4] Type: MT3620Blink.Program.GpioPoller

///////////////////////////////////////
// [3] MT3620Blink.Program.GpioPoller..ctor(MT3620Blink.Program.GpioPoller this__, System.Int32 changeInputGpioId, System.Int32 exitInputGpioId, MT3620Blink.Program.GpioBlinker blinker, MT3620Blink.Application app)

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
    MT3620Blink_Application* stack1_5__;
} MT3620Blink_Program_GpioPoller__ctor_EXECUTION_FRAME__;

//-------------------
// [3-2] Function body:

void MT3620Blink_Program_GpioPoller__ctor(MT3620Blink_Program_GpioPoller* this__, int32_t changeInputGpioId, int32_t exitInputGpioId, MT3620Blink_Program_GpioBlinker* blinker, MT3620Blink_Application* app)
{
#line 53 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    il2c_assert(this__ != NULL);

    //-------------------
    // [3-4] Evaluation stacks (!objref):

#line 53 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    int32_t stack1_0__;
#line 53 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    bool stack1_3__;
#line 53 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    int64_t stack1_6__;

    //-------------------
    // [3-5] Setup execution frame:

#line 53 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    MT3620Blink_Program_GpioPoller__ctor_EXECUTION_FRAME__ frame__ =
        { NULL, 5 };
#line 53 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    il2c_link_execution_frame(&frame__);

    //-------------------
    // [3-6] IL body:

    /* IL_0000: ldarg.0  */
#line 53 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    frame__.stack0_0__ = this__;
    /* IL_0001: call MT3620Blink.Timer..ctor */
#line 53 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    MT3620Blink_Timer__ctor((MT3620Blink_Timer*)frame__.stack0_0__);
    /* IL_0006: nop                             : Program.cs(50) */
    /* IL_0007: nop  */
    /* IL_0008: ldarg.0  */
#line 57 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    frame__.stack0_0__ = this__;
    /* IL_0009: ldarg.1  */
#line 57 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    stack1_0__ = changeInputGpioId;
    /* IL_000a: newobj MT3620Blink.GpioInput..ctor */
#line 57 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    frame__.stack1_1__ = il2c_get_uninitialized_object(MT3620Blink_GpioInput);
#line 57 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    MT3620Blink_GpioInput__ctor(frame__.stack1_1__, stack1_0__);
    /* IL_000f: stfld MT3620Blink.Program.GpioPoller.changeInput */
#line 57 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    frame__.stack0_0__->changeInput = frame__.stack1_1__;
    /* IL_0014: ldarg.0  */
#line 58 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    frame__.stack0_0__ = this__;
    /* IL_0015: ldarg.0  */
#line 58 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    frame__.stack1_2__ = this__;
    /* IL_0016: ldfld MT3620Blink.Program.GpioPoller.changeInput */
#line 58 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    frame__.stack1_1__ = frame__.stack1_2__->changeInput;
    /* IL_001b: callvirt MT3620Blink.GpioInput.get_Value */
#line 58 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    stack1_3__ = MT3620Blink_GpioInput_get_Value(frame__.stack1_1__);
    /* IL_0020: stfld MT3620Blink.Program.GpioPoller.lastChangeInput */
#line 58 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    frame__.stack0_0__->lastChangeInput = stack1_3__;
    /* IL_0025: ldarg.0  */
#line 60 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    frame__.stack0_0__ = this__;
    /* IL_0026: ldarg.2  */
#line 60 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    stack1_0__ = exitInputGpioId;
    /* IL_0027: newobj MT3620Blink.GpioInput..ctor */
#line 60 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    frame__.stack1_1__ = il2c_get_uninitialized_object(MT3620Blink_GpioInput);
#line 60 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    MT3620Blink_GpioInput__ctor(frame__.stack1_1__, stack1_0__);
    /* IL_002c: stfld MT3620Blink.Program.GpioPoller.exitInput */
#line 60 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    frame__.stack0_0__->exitInput = frame__.stack1_1__;
    /* IL_0031: ldarg.0  */
#line 61 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    frame__.stack0_0__ = this__;
    /* IL_0032: ldarg.0  */
#line 61 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    frame__.stack1_2__ = this__;
    /* IL_0033: ldfld MT3620Blink.Program.GpioPoller.exitInput */
#line 61 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    frame__.stack1_1__ = frame__.stack1_2__->exitInput;
    /* IL_0038: callvirt MT3620Blink.GpioInput.get_Value */
#line 61 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    stack1_3__ = MT3620Blink_GpioInput_get_Value(frame__.stack1_1__);
    /* IL_003d: stfld MT3620Blink.Program.GpioPoller.lastExitInput */
#line 61 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    frame__.stack0_0__->lastExitInput = stack1_3__;
    /* IL_0042: ldarg.0  */
#line 63 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    frame__.stack0_0__ = this__;
    /* IL_0043: ldarg.3  */
#line 63 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    frame__.stack1_4__ = blinker;
    /* IL_0044: stfld MT3620Blink.Program.GpioPoller.blinker */
#line 63 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    frame__.stack0_0__->blinker = frame__.stack1_4__;
    /* IL_0049: ldarg.0  */
#line 64 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    frame__.stack0_0__ = this__;
    /* IL_004a: ldarg.s app */
#line 64 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    frame__.stack1_5__ = app;
    /* IL_004c: stfld MT3620Blink.Program.GpioPoller.app */
#line 64 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    frame__.stack0_0__->app = frame__.stack1_5__;
    /* IL_0051: ldarg.0  */
#line 65 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    frame__.stack0_0__ = this__;
    /* IL_0052: ldc.i4 100000000 */
#line 65 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    stack1_0__ = 100000000;
    /* IL_0057: conv.i8  */
#line 65 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    stack1_6__ = (int64_t)stack1_0__;
    /* IL_0058: call MT3620Blink.Timer.SetInterval */
#line 65 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    MT3620Blink_Timer_SetInterval((MT3620Blink_Timer*)frame__.stack0_0__, stack1_6__);
    /* IL_005d: nop  */
    /* IL_005e: ret  */
#line 66 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    il2c_unlink_execution_frame(&frame__);
#line 66 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    return;
#line 66 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
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
#line 69 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    il2c_assert(this__ != NULL);

    //-------------------
    // [3-5] Setup execution frame:

#line 69 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    MT3620Blink_Program_GpioPoller_Dispose_EXECUTION_FRAME__ frame__ =
        { NULL, 2 };
#line 69 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    il2c_link_execution_frame(&frame__);

    //-------------------
    // [3-6] IL body:

    /* IL_0000: nop                             : Program.cs(59) */
    /* IL_0001: ldarg.0  */
#line 70 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    frame__.stack0_0__ = this__;
    /* IL_0002: call MT3620Blink.Descriptor.Dispose */
#line 70 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    MT3620Blink_Descriptor_Dispose((MT3620Blink_Descriptor*)frame__.stack0_0__);
    /* IL_0007: nop                             : Program.cs(60) */
    /* IL_0008: ldarg.0  */
#line 71 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    frame__.stack0_0__ = this__;
    /* IL_0009: ldfld MT3620Blink.Program.GpioPoller.changeInput */
#line 71 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    frame__.stack0_1__ = frame__.stack0_0__->changeInput;
    /* IL_000e: callvirt MT3620Blink.Descriptor.Dispose */
#line 71 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    frame__.stack0_1__->vptr0__->Dispose((MT3620Blink_Descriptor*)frame__.stack0_1__);
    /* IL_0013: nop  */
    /* IL_0014: ldarg.0  */
#line 72 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    frame__.stack0_0__ = this__;
    /* IL_0015: ldfld MT3620Blink.Program.GpioPoller.exitInput */
#line 72 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    frame__.stack0_1__ = frame__.stack0_0__->exitInput;
    /* IL_001a: callvirt MT3620Blink.Descriptor.Dispose */
#line 72 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    frame__.stack0_1__->vptr0__->Dispose((MT3620Blink_Descriptor*)frame__.stack0_1__);
    /* IL_001f: nop  */
    /* IL_0020: ret  */
#line 73 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    il2c_unlink_execution_frame(&frame__);
#line 73 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    return;
#line 73 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
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
    MT3620Blink_Application* stack0_5__;
    MT3620Blink_Program_GpioPoller* stack1_0__;
} MT3620Blink_Program_GpioPoller_Raised_EXECUTION_FRAME__;

//-------------------
// [3-2] Function body:

void MT3620Blink_Program_GpioPoller_Raised(MT3620Blink_Program_GpioPoller* this__)
{
#line 76 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    il2c_assert(this__ != NULL);

    //-------------------
    // [3-3] Local variables (!objref):

#line 76 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    bool current = false;
#line 76 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    bool local1__ = false;
#line 76 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    bool local2__ = false;
#line 76 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    bool local3__ = false;
#line 76 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    bool local4__ = false;

    //-------------------
    // [3-4] Evaluation stacks (!objref):

#line 76 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    bool stack0_2__;
#line 76 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    int32_t stack0_3__;
#line 76 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    bool stack1_1__;
#line 76 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    int32_t stack1_2__;

    //-------------------
    // [3-5] Setup execution frame:

#line 76 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    MT3620Blink_Program_GpioPoller_Raised_EXECUTION_FRAME__ frame__ =
        { NULL, 5 };
#line 76 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    il2c_link_execution_frame(&frame__);

    //-------------------
    // [3-6] IL body:

    /* IL_0000: nop                             : Program.cs(65) */
    /* IL_0001: ldarg.0  */
#line 77 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    frame__.stack0_0__ = this__;
    /* IL_0002: ldfld MT3620Blink.Program.GpioPoller.changeInput */
#line 77 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    frame__.stack0_1__ = frame__.stack0_0__->changeInput;
    /* IL_0007: callvirt MT3620Blink.GpioInput.get_Value */
#line 77 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    stack0_2__ = MT3620Blink_GpioInput_get_Value(frame__.stack0_1__);
    /* IL_000c: stloc.0  */
#line 77 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    current = stack0_2__;
    /* IL_000d: ldloc.0  */
#line 78 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    stack0_2__ = current;
    /* IL_000e: ldarg.0  */
#line 78 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    frame__.stack1_0__ = this__;
    /* IL_000f: ldfld MT3620Blink.Program.GpioPoller.lastChangeInput */
#line 78 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    stack1_1__ = frame__.stack1_0__->lastChangeInput;
    /* IL_0014: ceq  */
#line 78 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    stack0_3__ = (int32_t)stack0_2__ == (int32_t)stack1_1__;
    /* IL_0016: ldc.i4.0  */
#line 78 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    stack1_2__ = 0;
    /* IL_0017: ceq  */
#line 78 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    stack0_3__ = (int32_t)stack0_3__ == (int32_t)stack1_2__;
    /* IL_0019: stloc.1  */
#line 78 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    local1__ = (bool)stack0_3__;
    /* IL_001a: ldloc.1  */
#line 78 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    stack0_2__ = local1__;
    /* IL_001b: brfalse.s IL_0035 */
#line 78 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    if (stack0_2__ == false) goto IL_0035;
    /* IL_001d: nop                             : Program.cs(68) */
    /* IL_001e: ldloc.0  */
#line 80 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    stack0_2__ = current;
    /* IL_001f: ldc.i4.0  */
#line 80 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    stack1_2__ = 0;
    /* IL_0020: ceq  */
#line 80 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    stack0_3__ = (int32_t)stack0_2__ == (int32_t)stack1_2__;
    /* IL_0022: stloc.2  */
#line 80 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    local2__ = (bool)stack0_3__;
    /* IL_0023: ldloc.2  */
#line 80 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    stack0_2__ = local2__;
    /* IL_0024: brfalse.s IL_0034 */
#line 80 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    if (stack0_2__ == false) goto IL_0034;
    /* IL_0026: nop                             : Program.cs(70) */
    /* IL_0027: ldarg.0  */
#line 82 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    frame__.stack0_0__ = this__;
    /* IL_0028: ldfld MT3620Blink.Program.GpioPoller.blinker */
#line 82 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    frame__.stack0_4__ = frame__.stack0_0__->blinker;
    /* IL_002d: callvirt MT3620Blink.Program.GpioBlinker.NextInterval */
#line 82 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    MT3620Blink_Program_GpioBlinker_NextInterval(frame__.stack0_4__);
    /* IL_0032: nop                             : Program.cs(71) */
    /* IL_0033: nop  */
IL_0034:
    /* IL_0034: nop  */
IL_0035:
    /* IL_0035: ldarg.0  */
#line 85 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    frame__.stack0_0__ = this__;
    /* IL_0036: ldloc.0  */
#line 85 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    stack1_1__ = current;
    /* IL_0037: stfld MT3620Blink.Program.GpioPoller.lastChangeInput */
#line 85 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    frame__.stack0_0__->lastChangeInput = stack1_1__;
    /* IL_003c: ldarg.0  */
#line 87 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    frame__.stack0_0__ = this__;
    /* IL_003d: ldfld MT3620Blink.Program.GpioPoller.exitInput */
#line 87 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    frame__.stack0_1__ = frame__.stack0_0__->exitInput;
    /* IL_0042: callvirt MT3620Blink.GpioInput.get_Value */
#line 87 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    stack0_2__ = MT3620Blink_GpioInput_get_Value(frame__.stack0_1__);
    /* IL_0047: stloc.0  */
#line 87 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    current = stack0_2__;
    /* IL_0048: ldloc.0  */
#line 88 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    stack0_2__ = current;
    /* IL_0049: ldarg.0  */
#line 88 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    frame__.stack1_0__ = this__;
    /* IL_004a: ldfld MT3620Blink.Program.GpioPoller.lastExitInput */
#line 88 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    stack1_1__ = frame__.stack1_0__->lastExitInput;
    /* IL_004f: ceq  */
#line 88 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    stack0_3__ = (int32_t)stack0_2__ == (int32_t)stack1_1__;
    /* IL_0051: ldc.i4.0  */
#line 88 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    stack1_2__ = 0;
    /* IL_0052: ceq  */
#line 88 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    stack0_3__ = (int32_t)stack0_3__ == (int32_t)stack1_2__;
    /* IL_0054: stloc.3  */
#line 88 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    local3__ = (bool)stack0_3__;
    /* IL_0055: ldloc.3  */
#line 88 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    stack0_2__ = local3__;
    /* IL_0056: brfalse.s IL_0072 */
#line 88 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    if (stack0_2__ == false) goto IL_0072;
    /* IL_0058: nop  */
    /* IL_0059: ldloc.0  */
#line 90 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    stack0_2__ = current;
    /* IL_005a: ldc.i4.0  */
#line 90 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    stack1_2__ = 0;
    /* IL_005b: ceq  */
#line 90 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    stack0_3__ = (int32_t)stack0_2__ == (int32_t)stack1_2__;
    /* IL_005d: stloc.s local4__ */
#line 90 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    local4__ = (bool)stack0_3__;
    /* IL_005f: ldloc.s local4__ */
#line 90 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    stack0_2__ = local4__;
    /* IL_0061: brfalse.s IL_0071 */
#line 90 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    if (stack0_2__ == false) goto IL_0071;
    /* IL_0063: nop  */
    /* IL_0064: ldarg.0  */
#line 92 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    frame__.stack0_0__ = this__;
    /* IL_0065: ldfld MT3620Blink.Program.GpioPoller.app */
#line 92 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    frame__.stack0_5__ = frame__.stack0_0__->app;
    /* IL_006a: callvirt MT3620Blink.Application.Abort */
#line 92 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    MT3620Blink_Application_Abort(frame__.stack0_5__);
    /* IL_006f: nop  */
    /* IL_0070: nop  */
IL_0071:
    /* IL_0071: nop  */
IL_0072:
    /* IL_0072: ldarg.0  */
#line 95 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    frame__.stack0_0__ = this__;
    /* IL_0073: ldloc.0  */
#line 95 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    stack1_1__ = current;
    /* IL_0074: stfld MT3620Blink.Program.GpioPoller.lastExitInput */
#line 95 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    frame__.stack0_0__->lastExitInput = stack1_1__;
    /* IL_0079: ret  */
#line 96 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    il2c_unlink_execution_frame(&frame__);
#line 96 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    return;
#line 96 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
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
IL2C_RUNTIME_TYPE_BEGIN(MT3620Blink_Program_GpioPoller, "MT3620Blink.Program.GpioPoller", IL2C_TYPE_REFERENCE, sizeof(MT3620Blink_Program_GpioPoller), MT3620Blink_Timer, 4, 2)
    IL2C_RUNTIME_TYPE_MARK_TARGET_FOR_REFERENCE(MT3620Blink_Program_GpioPoller, changeInput)
    IL2C_RUNTIME_TYPE_MARK_TARGET_FOR_REFERENCE(MT3620Blink_Program_GpioPoller, exitInput)
    IL2C_RUNTIME_TYPE_MARK_TARGET_FOR_REFERENCE(MT3620Blink_Program_GpioPoller, blinker)
    IL2C_RUNTIME_TYPE_MARK_TARGET_FOR_REFERENCE(MT3620Blink_Program_GpioPoller, app)
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
    MT3620Blink_Application* app;
    MT3620Blink_Program_GpioBlinker* ledBlinker;
    MT3620Blink_Program_GpioPoller* buttonPoller;
    MT3620Blink_Application* stack0_0__;
    MT3620Blink_Program_GpioBlinker* stack0_2__;
    MT3620Blink_Program_GpioPoller* stack0_3__;
    MT3620Blink_Program_GpioBlinker* stack1_1__;
    MT3620Blink_Program_GpioPoller* stack1_2__;
    MT3620Blink_Program_GpioBlinker* stack2_0__;
    MT3620Blink_Application* stack3_0__;
} MT3620Blink_Program_Main_EXECUTION_FRAME__;

//-------------------
// [3-2] Function body:

int32_t MT3620Blink_Program_Main(void)
{
    //-------------------
    // [3-3] Local variables (!objref):

#line 100 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    volatile int32_t local3__ = 0;

    //-------------------
    // [3-4] Evaluation stacks (!objref):

#line 100 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    int32_t stack0_1__;
#line 100 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    int32_t stack1_0__;

    //-------------------
    // [3-5] Setup execution frame:

#line 100 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    MT3620Blink_Program_Main_EXECUTION_FRAME__ frame__ =
        { NULL, 10 };
#line 100 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    il2c_link_execution_frame(&frame__);

    //-------------------
    // [3-6] IL body:

    /* IL_0000: nop                             : Program.cs(79) */
    /* IL_0001: newobj MT3620Blink.Application..ctor */
#line 101 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    frame__.stack0_0__ = il2c_get_uninitialized_object(MT3620Blink_Application);
#line 101 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    MT3620Blink_Application__ctor(frame__.stack0_0__);
    /* IL_0006: stloc.0  */
#line 101 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    frame__.app = frame__.stack0_0__;
#line 102 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    il2c_try(nest0, MT3620Blink_Program_Main_ExceptionFilter0__)
#line 102 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    {
        /* IL_0007: nop                             : Program.cs(81) */
        /* IL_0008: ldsfld MT3620Blink.Interops.MT3620_RDB_LED1_RED */
#line 103 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
        stack0_1__ = MT3620Blink_Interops_MT3620_RDB_LED1_RED;
        /* IL_000d: newobj MT3620Blink.Program.GpioBlinker..ctor */
#line 103 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
        frame__.stack0_2__ = il2c_get_uninitialized_object(MT3620Blink_Program_GpioBlinker);
#line 103 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
        MT3620Blink_Program_GpioBlinker__ctor(frame__.stack0_2__, stack0_1__);
        /* IL_0012: stloc.1  */
#line 103 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
        frame__.ledBlinker = frame__.stack0_2__;
#line 104 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
        il2c_try(nest1, MT3620Blink_Program_Main_ExceptionFilter1__)
#line 104 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
        {
            /* IL_0013: nop                             : Program.cs(83) */
            /* IL_0014: ldsfld MT3620Blink.Interops.MT3620_RDB_BUTTON_A */
#line 105 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
            stack0_1__ = MT3620Blink_Interops_MT3620_RDB_BUTTON_A;
            /* IL_0019: ldsfld MT3620Blink.Interops.MT3620_RDB_BUTTON_B */
#line 105 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
            stack1_0__ = MT3620Blink_Interops_MT3620_RDB_BUTTON_B;
            /* IL_001e: ldloc.1  */
#line 105 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
            frame__.stack2_0__ = frame__.ledBlinker;
            /* IL_001f: ldloc.0  */
#line 105 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
            frame__.stack3_0__ = frame__.app;
            /* IL_0020: newobj MT3620Blink.Program.GpioPoller..ctor */
#line 105 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
            frame__.stack0_3__ = il2c_get_uninitialized_object(MT3620Blink_Program_GpioPoller);
#line 105 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
            MT3620Blink_Program_GpioPoller__ctor(frame__.stack0_3__, stack0_1__, stack1_0__, frame__.stack2_0__, frame__.stack3_0__);
            /* IL_0025: stloc.2  */
#line 105 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
            frame__.buttonPoller = frame__.stack0_3__;
#line 110 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
            il2c_try(nest2, MT3620Blink_Program_Main_ExceptionFilter2__)
#line 110 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
            {
                /* IL_0026: nop  */
                /* IL_0027: ldloc.0  */
#line 111 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
                frame__.stack0_0__ = frame__.app;
                /* IL_0028: ldloc.1  */
#line 111 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
                frame__.stack1_1__ = frame__.ledBlinker;
                /* IL_0029: callvirt MT3620Blink.Application.RegisterDescriptor */
#line 111 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
                MT3620Blink_Application_RegisterDescriptor(frame__.stack0_0__, il2c_cast_to_interface(MT3620Blink_IEPollListener, MT3620Blink_Program_GpioBlinker, frame__.stack1_1__));
                /* IL_002e: nop  */
                /* IL_002f: ldloc.0  */
#line 112 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
                frame__.stack0_0__ = frame__.app;
                /* IL_0030: ldloc.2  */
#line 112 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
                frame__.stack1_2__ = frame__.buttonPoller;
                /* IL_0031: callvirt MT3620Blink.Application.RegisterDescriptor */
#line 112 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
                MT3620Blink_Application_RegisterDescriptor(frame__.stack0_0__, il2c_cast_to_interface(MT3620Blink_IEPollListener, MT3620Blink_Program_GpioPoller, frame__.stack1_2__));
                /* IL_0036: nop  */
                /* IL_0037: ldloc.0  */
#line 114 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
                frame__.stack0_0__ = frame__.app;
                /* IL_0038: callvirt MT3620Blink.Application.Run */
#line 114 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
                MT3620Blink_Application_Run(frame__.stack0_0__);
                /* IL_003d: nop  */
                /* IL_003e: nop  */
                /* IL_003f: leave.s IL_004c */
#line 115 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
                il2c_leave(nest2, 0);
#line 115 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
            }
#line 115 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
            il2c_finally(nest2)
#line 115 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
            {
                /* IL_0041: ldloc.2  */
#line 115 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
                frame__.stack0_3__ = frame__.buttonPoller;
                /* IL_0042: brfalse.s IL_004b */
#line 115 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
                if (frame__.stack0_3__ == NULL) goto IL_004b;
                /* IL_0044: ldloc.2  */
#line 115 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
                frame__.stack0_3__ = frame__.buttonPoller;
                /* IL_0045: callvirt System.IDisposable.Dispose */
#line 115 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
                MT3620Blink_Program_GpioPoller_Dispose(il2c_adjusted_reference(frame__.stack0_3__));
                /* IL_004a: nop  */
            IL_004b:
                /* IL_004b: endfinally  */
#line 115 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
                il2c_endfinally(nest2);
#line 116 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
            }
#line 116 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
            il2c_leave_to(nest2)
#line 116 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
            {
#line 116 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
                il2c_leave_bind(nest2, 0, IL_004c);
#line 116 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
            }
#line 116 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
            il2c_end_try(nest2);
        IL_004c:
            /* IL_004c: nop  */
            /* IL_004d: leave.s IL_005a */
#line 116 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
            il2c_leave(nest1, 1);
#line 116 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
        }
#line 116 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
        il2c_finally(nest1)
#line 116 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
        {
            /* IL_004f: ldloc.1  */
#line 116 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
            frame__.stack0_2__ = frame__.ledBlinker;
            /* IL_0050: brfalse.s IL_0059 */
#line 116 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
            if (frame__.stack0_2__ == NULL) goto IL_0059;
            /* IL_0052: ldloc.1  */
#line 116 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
            frame__.stack0_2__ = frame__.ledBlinker;
            /* IL_0053: callvirt System.IDisposable.Dispose */
#line 116 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
            MT3620Blink_Program_GpioBlinker_Dispose(il2c_adjusted_reference(frame__.stack0_2__));
            /* IL_0058: nop  */
        IL_0059:
            /* IL_0059: endfinally  */
#line 116 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
            il2c_endfinally(nest1);
#line 117 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
        }
#line 117 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
        il2c_leave_to(nest1)
#line 117 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
        {
#line 117 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
            il2c_leave_bind(nest1, 0, IL_004c);
#line 117 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
            il2c_leave_bind(nest1, 1, IL_005a);
#line 117 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
        }
#line 117 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
        il2c_end_try(nest1);
    IL_005a:
        /* IL_005a: nop  */
        /* IL_005b: leave.s IL_0068 */
#line 117 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
        il2c_leave(nest0, 2);
#line 117 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    }
#line 117 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    il2c_finally(nest0)
#line 117 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    {
        /* IL_005d: ldloc.0  */
#line 117 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
        frame__.stack0_0__ = frame__.app;
        /* IL_005e: brfalse.s IL_0067 */
#line 117 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
        if (frame__.stack0_0__ == NULL) goto IL_0067;
        /* IL_0060: ldloc.0  */
#line 117 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
        frame__.stack0_0__ = frame__.app;
        /* IL_0061: callvirt System.IDisposable.Dispose */
#line 117 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
        MT3620Blink_Application_Dispose(il2c_adjusted_reference(frame__.stack0_0__));
        /* IL_0066: nop  */
    IL_0067:
        /* IL_0067: endfinally  */
#line 117 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
        il2c_endfinally(nest0);
#line 119 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    }
#line 119 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    il2c_leave_to(nest0)
#line 119 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    {
#line 119 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
        il2c_leave_bind(nest0, 0, IL_004c);
#line 119 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
        il2c_leave_bind(nest0, 1, IL_005a);
#line 119 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
        il2c_leave_bind(nest0, 2, IL_0068);
#line 119 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    }
#line 119 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    il2c_end_try(nest0);
IL_0068:
    /* IL_0068: ldc.i4.0  */
#line 119 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    stack0_1__ = 0;
    /* IL_0069: stloc.3  */
#line 119 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    local3__ = stack0_1__;
    /* IL_006a: br.s IL_006c */
#line 119 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    goto IL_006c;
IL_006c:
    /* IL_006c: ldloc.3  */
#line 120 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    stack0_1__ = local3__;
    /* IL_006d: ret  */
#line 120 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    il2c_unlink_execution_frame(&frame__);
#line 120 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    return stack0_1__;
#line 120 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
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
