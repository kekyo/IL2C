// [15-2] This is MT3620Blink native code translated by IL2C, do not edit.

#include <MT3620Blink.h>
#include <MT3620Blink_internal.h>

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
    /* IL_001d: ldarg.0                         : Program.cs(16) */
    frame__.stack0_0__ = this__;
    /* IL_001e: ldarg.1                         : Program.cs(16) */
    stack1_0__ = gpioId;
    /* IL_001f: ldc.i4.0                        : Program.cs(16) */
    stack2_1__ = 0;
    /* IL_0020: ldc.i4.1                        : Program.cs(16) */
    stack3_1__ = 1;
    /* IL_0021: newobj MT3620Blink.GpioOutput..ctor : Program.cs(16) */
    frame__.stack1_2__ = il2c_get_uninitialized_object(MT3620Blink_GpioOutput);
    MT3620Blink_GpioOutput__ctor(frame__.stack1_2__, stack1_0__, (MT3620Blink_GPIO_OutputMode_Type)stack2_1__, (bool)stack3_1__);
    /* IL_0026: stfld MT3620Blink.Program.GpioBlinker.output : Program.cs(16) */
    frame__.stack0_0__->output = frame__.stack1_2__;
    /* IL_002b: ldarg.0                         : Program.cs(20) */
    frame__.stack0_0__ = this__;
    /* IL_002c: call MT3620Blink.Program.GpioBlinker.NextInterval : Program.cs(20) */
    MT3620Blink_Program_GpioBlinker_NextInterval(frame__.stack0_0__);
    /* IL_0031: ret                             : Program.cs(21) */
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

    /* IL_0000: ldarg.0                         : Program.cs(25) */
    frame__.stack0_0__ = this__;
    /* IL_0001: call MT3620Blink.Descriptor.Dispose : Program.cs(25) */
    MT3620Blink_Descriptor_Dispose((MT3620Blink_Descriptor*)frame__.stack0_0__);
    /* IL_0006: ldarg.0                         : Program.cs(26) */
    frame__.stack0_0__ = this__;
    /* IL_0007: ldfld MT3620Blink.Program.GpioBlinker.output : Program.cs(26) */
    frame__.stack0_1__ = frame__.stack0_0__->output;
    /* IL_000c: callvirt MT3620Blink.Descriptor.Dispose : Program.cs(26) */
    frame__.stack0_1__->vptr0__->Dispose((MT3620Blink_Descriptor*)frame__.stack0_1__);
    /* IL_0011: ret                             : Program.cs(27) */
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

    /* IL_0000: ldarg.0                         : Program.cs(31) */
    frame__.stack0_0__ = this__;
    /* IL_0001: ldfld MT3620Blink.Program.GpioBlinker.output : Program.cs(31) */
    frame__.stack0_1__ = frame__.stack0_0__->output;
    /* IL_0006: ldarg.0                         : Program.cs(31) */
    frame__.stack1_0__ = this__;
    /* IL_0007: ldfld MT3620Blink.Program.GpioBlinker.flag : Program.cs(31) */
    stack1_1__ = frame__.stack1_0__->flag;
    /* IL_000c: callvirt MT3620Blink.GpioOutput.SetValue : Program.cs(31) */
    MT3620Blink_GpioOutput_SetValue(frame__.stack0_1__, stack1_1__);
    /* IL_0011: ldarg.0                         : Program.cs(32) */
    frame__.stack0_0__ = this__;
    /* IL_0012: ldarg.0                         : Program.cs(32) */
    frame__.stack1_0__ = this__;
    /* IL_0013: ldfld MT3620Blink.Program.GpioBlinker.flag : Program.cs(32) */
    stack1_1__ = frame__.stack1_0__->flag;
    /* IL_0018: ldc.i4.0                        : Program.cs(32) */
    stack2_0__ = 0;
    /* IL_0019: ceq                             : Program.cs(32) */
    stack1_2__ = (int32_t)stack1_1__ == (int32_t)stack2_0__;
    /* IL_001b: stfld MT3620Blink.Program.GpioBlinker.flag : Program.cs(32) */
    frame__.stack0_0__->flag = (bool)stack1_2__;
    /* IL_0020: ret                             : Program.cs(33) */
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

    /* IL_0000: ldarg.0                         : Program.cs(37) */
    frame__.stack0_0__ = this__;
    /* IL_0001: ldarg.0                         : Program.cs(37) */
    frame__.stack1_0__ = this__;
    /* IL_0002: ldfld MT3620Blink.Program.GpioBlinker.blinkIntervals : Program.cs(37) */
    frame__.stack1_1__ = frame__.stack1_0__->blinkIntervals;
    /* IL_0007: ldarg.0                         : Program.cs(37) */
    frame__.stack2_0__ = this__;
    /* IL_0008: ldfld MT3620Blink.Program.GpioBlinker.blinkIntervalIndex : Program.cs(37) */
    stack2_1__ = frame__.stack2_0__->blinkIntervalIndex;
    /* IL_000d: ldelem.i8                       : Program.cs(37) */
    stack1_2__ = il2c_array_item(frame__.stack1_1__, int64_t, stack2_1__);
    /* IL_000e: call MT3620Blink.Timer.SetInterval : Program.cs(37) */
    MT3620Blink_Timer_SetInterval((MT3620Blink_Timer*)frame__.stack0_0__, stack1_2__);
    /* IL_0013: ldarg.0                         : Program.cs(39) */
    frame__.stack0_0__ = this__;
    /* IL_0014: ldarg.0                         : Program.cs(39) */
    frame__.stack1_0__ = this__;
    /* IL_0015: ldfld MT3620Blink.Program.GpioBlinker.blinkIntervalIndex : Program.cs(39) */
    stack1_3__ = frame__.stack1_0__->blinkIntervalIndex;
    /* IL_001a: ldc.i4.1                        : Program.cs(39) */
    stack2_1__ = 1;
    /* IL_001b: add                             : Program.cs(39) */
    stack1_3__ = stack1_3__ + stack2_1__;
    /* IL_001c: stfld MT3620Blink.Program.GpioBlinker.blinkIntervalIndex : Program.cs(39) */
    frame__.stack0_0__->blinkIntervalIndex = stack1_3__;
    /* IL_0021: ldarg.0                         : Program.cs(40) */
    frame__.stack0_0__ = this__;
    /* IL_0022: ldarg.0                         : Program.cs(40) */
    frame__.stack1_0__ = this__;
    /* IL_0023: ldfld MT3620Blink.Program.GpioBlinker.blinkIntervalIndex : Program.cs(40) */
    stack1_3__ = frame__.stack1_0__->blinkIntervalIndex;
    /* IL_0028: ldc.i4.3                        : Program.cs(40) */
    stack2_1__ = 3;
    /* IL_0029: rem                             : Program.cs(40) */
    stack1_3__ = stack1_3__ % stack2_1__;
    /* IL_002a: stfld MT3620Blink.Program.GpioBlinker.blinkIntervalIndex : Program.cs(40) */
    frame__.stack0_0__->blinkIntervalIndex = stack1_3__;
    /* IL_002f: ret                             : Program.cs(41) */
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
    il2c_assert(this__ != NULL);

    //-------------------
    // [3-4] Evaluation stacks (!objref):

    int32_t stack1_0__;
    bool stack1_3__;
    int64_t stack1_6__;

    //-------------------
    // [3-5] Setup execution frame:

    MT3620Blink_Program_GpioPoller__ctor_EXECUTION_FRAME__ frame__ =
        { NULL, 5 };
    il2c_link_execution_frame(&frame__);

    //-------------------
    // [3-6] IL body:

    /* IL_0000: ldarg.0                         : Program.cs(53) */
    frame__.stack0_0__ = this__;
    /* IL_0001: call MT3620Blink.Timer..ctor    : Program.cs(53) */
    MT3620Blink_Timer__ctor((MT3620Blink_Timer*)frame__.stack0_0__);
    /* IL_0006: ldarg.0                         : Program.cs(57) */
    frame__.stack0_0__ = this__;
    /* IL_0007: ldarg.1                         : Program.cs(57) */
    stack1_0__ = changeInputGpioId;
    /* IL_0008: newobj MT3620Blink.GpioInput..ctor : Program.cs(57) */
    frame__.stack1_1__ = il2c_get_uninitialized_object(MT3620Blink_GpioInput);
    MT3620Blink_GpioInput__ctor(frame__.stack1_1__, stack1_0__);
    /* IL_000d: stfld MT3620Blink.Program.GpioPoller.changeInput : Program.cs(57) */
    frame__.stack0_0__->changeInput = frame__.stack1_1__;
    /* IL_0012: ldarg.0                         : Program.cs(58) */
    frame__.stack0_0__ = this__;
    /* IL_0013: ldarg.0                         : Program.cs(58) */
    frame__.stack1_2__ = this__;
    /* IL_0014: ldfld MT3620Blink.Program.GpioPoller.changeInput : Program.cs(58) */
    frame__.stack1_1__ = frame__.stack1_2__->changeInput;
    /* IL_0019: callvirt MT3620Blink.GpioInput.get_Value : Program.cs(58) */
    stack1_3__ = MT3620Blink_GpioInput_get_Value(frame__.stack1_1__);
    /* IL_001e: stfld MT3620Blink.Program.GpioPoller.lastChangeInput : Program.cs(58) */
    frame__.stack0_0__->lastChangeInput = stack1_3__;
    /* IL_0023: ldarg.0                         : Program.cs(60) */
    frame__.stack0_0__ = this__;
    /* IL_0024: ldarg.2                         : Program.cs(60) */
    stack1_0__ = exitInputGpioId;
    /* IL_0025: newobj MT3620Blink.GpioInput..ctor : Program.cs(60) */
    frame__.stack1_1__ = il2c_get_uninitialized_object(MT3620Blink_GpioInput);
    MT3620Blink_GpioInput__ctor(frame__.stack1_1__, stack1_0__);
    /* IL_002a: stfld MT3620Blink.Program.GpioPoller.exitInput : Program.cs(60) */
    frame__.stack0_0__->exitInput = frame__.stack1_1__;
    /* IL_002f: ldarg.0                         : Program.cs(61) */
    frame__.stack0_0__ = this__;
    /* IL_0030: ldarg.0                         : Program.cs(61) */
    frame__.stack1_2__ = this__;
    /* IL_0031: ldfld MT3620Blink.Program.GpioPoller.exitInput : Program.cs(61) */
    frame__.stack1_1__ = frame__.stack1_2__->exitInput;
    /* IL_0036: callvirt MT3620Blink.GpioInput.get_Value : Program.cs(61) */
    stack1_3__ = MT3620Blink_GpioInput_get_Value(frame__.stack1_1__);
    /* IL_003b: stfld MT3620Blink.Program.GpioPoller.lastExitInput : Program.cs(61) */
    frame__.stack0_0__->lastExitInput = stack1_3__;
    /* IL_0040: ldarg.0                         : Program.cs(63) */
    frame__.stack0_0__ = this__;
    /* IL_0041: ldarg.3                         : Program.cs(63) */
    frame__.stack1_4__ = blinker;
    /* IL_0042: stfld MT3620Blink.Program.GpioPoller.blinker : Program.cs(63) */
    frame__.stack0_0__->blinker = frame__.stack1_4__;
    /* IL_0047: ldarg.0                         : Program.cs(64) */
    frame__.stack0_0__ = this__;
    /* IL_0048: ldarg.s app                     : Program.cs(64) */
    frame__.stack1_5__ = app;
    /* IL_004a: stfld MT3620Blink.Program.GpioPoller.app : Program.cs(64) */
    frame__.stack0_0__->app = frame__.stack1_5__;
    /* IL_004f: ldarg.0                         : Program.cs(65) */
    frame__.stack0_0__ = this__;
    /* IL_0050: ldc.i4 100000000                : Program.cs(65) */
    stack1_0__ = 100000000;
    /* IL_0055: conv.i8                         : Program.cs(65) */
    stack1_6__ = (int64_t)stack1_0__;
    /* IL_0056: call MT3620Blink.Timer.SetInterval : Program.cs(65) */
    MT3620Blink_Timer_SetInterval((MT3620Blink_Timer*)frame__.stack0_0__, stack1_6__);
    /* IL_005b: ret                             : Program.cs(66) */
    il2c_unlink_execution_frame(&frame__);
    return;
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
    il2c_assert(this__ != NULL);

    //-------------------
    // [3-5] Setup execution frame:

    MT3620Blink_Program_GpioPoller_Dispose_EXECUTION_FRAME__ frame__ =
        { NULL, 2 };
    il2c_link_execution_frame(&frame__);

    //-------------------
    // [3-6] IL body:

    /* IL_0000: ldarg.0                         : Program.cs(70) */
    frame__.stack0_0__ = this__;
    /* IL_0001: call MT3620Blink.Descriptor.Dispose : Program.cs(70) */
    MT3620Blink_Descriptor_Dispose((MT3620Blink_Descriptor*)frame__.stack0_0__);
    /* IL_0006: ldarg.0                         : Program.cs(71) */
    frame__.stack0_0__ = this__;
    /* IL_0007: ldfld MT3620Blink.Program.GpioPoller.changeInput : Program.cs(71) */
    frame__.stack0_1__ = frame__.stack0_0__->changeInput;
    /* IL_000c: callvirt MT3620Blink.Descriptor.Dispose : Program.cs(71) */
    frame__.stack0_1__->vptr0__->Dispose((MT3620Blink_Descriptor*)frame__.stack0_1__);
    /* IL_0011: ldarg.0                         : Program.cs(72) */
    frame__.stack0_0__ = this__;
    /* IL_0012: ldfld MT3620Blink.Program.GpioPoller.exitInput : Program.cs(72) */
    frame__.stack0_1__ = frame__.stack0_0__->exitInput;
    /* IL_0017: callvirt MT3620Blink.Descriptor.Dispose : Program.cs(72) */
    frame__.stack0_1__->vptr0__->Dispose((MT3620Blink_Descriptor*)frame__.stack0_1__);
    /* IL_001c: ret                             : Program.cs(73) */
    il2c_unlink_execution_frame(&frame__);
    return;
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
    MT3620Blink_Program_GpioBlinker* stack0_3__;
    MT3620Blink_Application* stack0_4__;
    MT3620Blink_Program_GpioPoller* stack1_0__;
} MT3620Blink_Program_GpioPoller_Raised_EXECUTION_FRAME__;

//-------------------
// [3-2] Function body:

void MT3620Blink_Program_GpioPoller_Raised(MT3620Blink_Program_GpioPoller* this__)
{
    il2c_assert(this__ != NULL);

    //-------------------
    // [3-3] Local variables (!objref):

    bool current = false;

    //-------------------
    // [3-4] Evaluation stacks (!objref):

    bool stack0_2__;
    bool stack1_1__;

    //-------------------
    // [3-5] Setup execution frame:

    MT3620Blink_Program_GpioPoller_Raised_EXECUTION_FRAME__ frame__ =
        { NULL, 5 };
    il2c_link_execution_frame(&frame__);

    //-------------------
    // [3-6] IL body:

    /* IL_0000: ldarg.0                         : Program.cs(77) */
    frame__.stack0_0__ = this__;
    /* IL_0001: ldfld MT3620Blink.Program.GpioPoller.changeInput : Program.cs(77) */
    frame__.stack0_1__ = frame__.stack0_0__->changeInput;
    /* IL_0006: callvirt MT3620Blink.GpioInput.get_Value : Program.cs(77) */
    stack0_2__ = MT3620Blink_GpioInput_get_Value(frame__.stack0_1__);
    /* IL_000b: stloc.0                         : Program.cs(77) */
    current = stack0_2__;
    /* IL_000c: ldloc.0                         : Program.cs(78) */
    stack0_2__ = current;
    /* IL_000d: ldarg.0                         : Program.cs(78) */
    frame__.stack1_0__ = this__;
    /* IL_000e: ldfld MT3620Blink.Program.GpioPoller.lastChangeInput : Program.cs(78) */
    stack1_1__ = frame__.stack1_0__->lastChangeInput;
    /* IL_0013: beq.s IL_0023                   : Program.cs(78) */
    if (stack0_2__ == stack1_1__) goto IL_0023;
    /* IL_0015: ldloc.0                         : Program.cs(80) */
    stack0_2__ = current;
    /* IL_0016: brtrue.s IL_0023                : Program.cs(80) */
    if (stack0_2__ != false) goto IL_0023;
    /* IL_0018: ldarg.0                         : Program.cs(82) */
    frame__.stack0_0__ = this__;
    /* IL_0019: ldfld MT3620Blink.Program.GpioPoller.blinker : Program.cs(82) */
    frame__.stack0_3__ = frame__.stack0_0__->blinker;
    /* IL_001e: callvirt MT3620Blink.Program.GpioBlinker.NextInterval : Program.cs(82) */
    MT3620Blink_Program_GpioBlinker_NextInterval(frame__.stack0_3__);
IL_0023:
    /* IL_0023: ldarg.0                         : Program.cs(85) */
    frame__.stack0_0__ = this__;
    /* IL_0024: ldloc.0                         : Program.cs(85) */
    stack1_1__ = current;
    /* IL_0025: stfld MT3620Blink.Program.GpioPoller.lastChangeInput : Program.cs(85) */
    frame__.stack0_0__->lastChangeInput = stack1_1__;
    /* IL_002a: ldarg.0                         : Program.cs(87) */
    frame__.stack0_0__ = this__;
    /* IL_002b: ldfld MT3620Blink.Program.GpioPoller.exitInput : Program.cs(87) */
    frame__.stack0_1__ = frame__.stack0_0__->exitInput;
    /* IL_0030: callvirt MT3620Blink.GpioInput.get_Value : Program.cs(87) */
    stack0_2__ = MT3620Blink_GpioInput_get_Value(frame__.stack0_1__);
    /* IL_0035: stloc.0                         : Program.cs(87) */
    current = stack0_2__;
    /* IL_0036: ldloc.0                         : Program.cs(88) */
    stack0_2__ = current;
    /* IL_0037: ldarg.0                         : Program.cs(88) */
    frame__.stack1_0__ = this__;
    /* IL_0038: ldfld MT3620Blink.Program.GpioPoller.lastExitInput : Program.cs(88) */
    stack1_1__ = frame__.stack1_0__->lastExitInput;
    /* IL_003d: beq.s IL_004d                   : Program.cs(88) */
    if (stack0_2__ == stack1_1__) goto IL_004d;
    /* IL_003f: ldloc.0                         : Program.cs(90) */
    stack0_2__ = current;
    /* IL_0040: brtrue.s IL_004d                : Program.cs(90) */
    if (stack0_2__ != false) goto IL_004d;
    /* IL_0042: ldarg.0                         : Program.cs(92) */
    frame__.stack0_0__ = this__;
    /* IL_0043: ldfld MT3620Blink.Program.GpioPoller.app : Program.cs(92) */
    frame__.stack0_4__ = frame__.stack0_0__->app;
    /* IL_0048: callvirt MT3620Blink.Application.Abort : Program.cs(92) */
    MT3620Blink_Application_Abort(frame__.stack0_4__);
IL_004d:
    /* IL_004d: ldarg.0                         : Program.cs(95) */
    frame__.stack0_0__ = this__;
    /* IL_004e: ldloc.0                         : Program.cs(95) */
    stack1_1__ = current;
    /* IL_004f: stfld MT3620Blink.Program.GpioPoller.lastExitInput : Program.cs(95) */
    frame__.stack0_0__->lastExitInput = stack1_1__;
    /* IL_0054: ret                             : Program.cs(96) */
    il2c_unlink_execution_frame(&frame__);
    return;
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
    // [3-4] Evaluation stacks (!objref):

    int32_t stack0_1__;
    int32_t stack1_0__;

    //-------------------
    // [3-5] Setup execution frame:

    MT3620Blink_Program_Main_EXECUTION_FRAME__ frame__ =
        { NULL, 10 };
    il2c_link_execution_frame(&frame__);

    //-------------------
    // [3-6] IL body:

    /* IL_0000: newobj MT3620Blink.Application..ctor : Program.cs(101) */
    frame__.stack0_0__ = il2c_get_uninitialized_object(MT3620Blink_Application);
    MT3620Blink_Application__ctor(frame__.stack0_0__);
    /* IL_0005: stloc.0                         : Program.cs(101) */
    frame__.app = frame__.stack0_0__;
    il2c_try(nest0, MT3620Blink_Program_Main_ExceptionFilter0__)
    {
        /* IL_0006: ldsfld MT3620Blink.Interops.MT3620_RDB_LED1_RED : Program.cs(103) */
        stack0_1__ = MT3620Blink_Interops_MT3620_RDB_LED1_RED;
        /* IL_000b: newobj MT3620Blink.Program.GpioBlinker..ctor : Program.cs(103) */
        frame__.stack0_2__ = il2c_get_uninitialized_object(MT3620Blink_Program_GpioBlinker);
        MT3620Blink_Program_GpioBlinker__ctor(frame__.stack0_2__, stack0_1__);
        /* IL_0010: stloc.1                         : Program.cs(103) */
        frame__.ledBlinker = frame__.stack0_2__;
        il2c_try(nest1, MT3620Blink_Program_Main_ExceptionFilter1__)
        {
            /* IL_0011: ldsfld MT3620Blink.Interops.MT3620_RDB_BUTTON_A : Program.cs(105) */
            stack0_1__ = MT3620Blink_Interops_MT3620_RDB_BUTTON_A;
            /* IL_0016: ldsfld MT3620Blink.Interops.MT3620_RDB_BUTTON_B : Program.cs(105) */
            stack1_0__ = MT3620Blink_Interops_MT3620_RDB_BUTTON_B;
            /* IL_001b: ldloc.1                         : Program.cs(105) */
            frame__.stack2_0__ = frame__.ledBlinker;
            /* IL_001c: ldloc.0                         : Program.cs(105) */
            frame__.stack3_0__ = frame__.app;
            /* IL_001d: newobj MT3620Blink.Program.GpioPoller..ctor : Program.cs(105) */
            frame__.stack0_3__ = il2c_get_uninitialized_object(MT3620Blink_Program_GpioPoller);
            MT3620Blink_Program_GpioPoller__ctor(frame__.stack0_3__, stack0_1__, stack1_0__, frame__.stack2_0__, frame__.stack3_0__);
            /* IL_0022: stloc.2                         : Program.cs(105) */
            frame__.buttonPoller = frame__.stack0_3__;
            il2c_try(nest2, MT3620Blink_Program_Main_ExceptionFilter2__)
            {
                /* IL_0023: ldloc.0                         : Program.cs(111) */
                frame__.stack0_0__ = frame__.app;
                /* IL_0024: ldloc.1                         : Program.cs(111) */
                frame__.stack1_1__ = frame__.ledBlinker;
                /* IL_0025: callvirt MT3620Blink.Application.RegisterDescriptor : Program.cs(111) */
                MT3620Blink_Application_RegisterDescriptor(frame__.stack0_0__, il2c_cast_to_interface(MT3620Blink_IEPollListener, MT3620Blink_Program_GpioBlinker, frame__.stack1_1__));
                /* IL_002a: ldloc.0                         : Program.cs(112) */
                frame__.stack0_0__ = frame__.app;
                /* IL_002b: ldloc.2                         : Program.cs(112) */
                frame__.stack1_2__ = frame__.buttonPoller;
                /* IL_002c: callvirt MT3620Blink.Application.RegisterDescriptor : Program.cs(112) */
                MT3620Blink_Application_RegisterDescriptor(frame__.stack0_0__, il2c_cast_to_interface(MT3620Blink_IEPollListener, MT3620Blink_Program_GpioPoller, frame__.stack1_2__));
                /* IL_0031: ldloc.0                         : Program.cs(114) */
                frame__.stack0_0__ = frame__.app;
                /* IL_0032: callvirt MT3620Blink.Application.Run : Program.cs(114) */
                MT3620Blink_Application_Run(frame__.stack0_0__);
                /* IL_0037: leave.s IL_0057                 : Program.cs(115) */
                il2c_leave(nest2, 0);
            }
            il2c_finally(nest2)
            {
                /* IL_0039: ldloc.2                         : Program.cs(115) */
                frame__.stack0_3__ = frame__.buttonPoller;
                /* IL_003a: brfalse.s IL_0042               : Program.cs(115) */
                if (frame__.stack0_3__ == NULL) goto IL_0042;
                /* IL_003c: ldloc.2                         : Program.cs(115) */
                frame__.stack0_3__ = frame__.buttonPoller;
                /* IL_003d: callvirt System.IDisposable.Dispose : Program.cs(115) */
                MT3620Blink_Program_GpioPoller_Dispose(il2c_adjusted_reference(frame__.stack0_3__));
            IL_0042:
                /* IL_0042: endfinally                      : Program.cs(115) */
                il2c_endfinally(nest2);
            }
            il2c_leave_to(nest2)
            {
                il2c_leave_through(nest2, 0, nest1);
            }
            il2c_end_try(nest2);
        }
        il2c_finally(nest1)
        {
            /* IL_0043: ldloc.1                         : Program.cs(115) */
            frame__.stack0_2__ = frame__.ledBlinker;
            /* IL_0044: brfalse.s IL_004c               : Program.cs(115) */
            if (frame__.stack0_2__ == NULL) goto IL_004c;
            /* IL_0046: ldloc.1                         : Program.cs(115) */
            frame__.stack0_2__ = frame__.ledBlinker;
            /* IL_0047: callvirt System.IDisposable.Dispose : Program.cs(115) */
            MT3620Blink_Program_GpioBlinker_Dispose(il2c_adjusted_reference(frame__.stack0_2__));
        IL_004c:
            /* IL_004c: endfinally                      : Program.cs(115) */
            il2c_endfinally(nest1);
        }
        il2c_leave_to(nest1)
        {
            il2c_leave_through(nest1, 0, nest0);
        }
        il2c_end_try(nest1);
    }
    il2c_finally(nest0)
    {
        /* IL_004d: ldloc.0                         : Program.cs(115) */
        frame__.stack0_0__ = frame__.app;
        /* IL_004e: brfalse.s IL_0056               : Program.cs(115) */
        if (frame__.stack0_0__ == NULL) goto IL_0056;
        /* IL_0050: ldloc.0                         : Program.cs(115) */
        frame__.stack0_0__ = frame__.app;
        /* IL_0051: callvirt System.IDisposable.Dispose : Program.cs(115) */
        MT3620Blink_Application_Dispose(il2c_adjusted_reference(frame__.stack0_0__));
    IL_0056:
        /* IL_0056: endfinally                      : Program.cs(115) */
        il2c_endfinally(nest0);
    }
    il2c_leave_to(nest0)
    {
        il2c_leave_bind(nest0, 0, IL_0057);
    }
    il2c_end_try(nest0);
IL_0057:
    /* IL_0057: ldc.i4.0                        : Program.cs(119) */
    stack0_1__ = 0;
    /* IL_0058: ret                             : Program.cs(119) */
    il2c_unlink_execution_frame(&frame__);
    return stack0_1__;
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
