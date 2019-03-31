// [15-2] This is MT3620Blink native code translated by IL2C, do not edit.

#include <MT3620Blink.h>
#include <MT3620Blink_internal.h>

#include <mscorlib.h>

#ifdef __cplusplus
extern "C" {
#endif

//////////////////////////////////////////////////////////////////////////////////
// [9-1] Type: MT3620Blink.Event

//////////////////////////////////////////////////////////////////////////////////
// [9-2] File scope prototypes:

//////////////////////////////////////////////////////////////////////////////////
// [2-2] Static fields: MT3620Blink.Event

/* private static readonly */ #define MT3620Blink_Event_EFD_NONBLOCK EFD_NONBLOCK

/* private static readonly */ #define MT3620Blink_Event_EFD_SEMAPHORE EFD_SEMAPHORE

//////////////////////////////////////////////////////////////////////////////////
// [9-4] Type: MT3620Blink.Event

///////////////////////////////////////
// [3] MT3620Blink.Event..ctor(MT3620Blink.Event this__)

//-------------------
// [3-7] Declare execution frame:

typedef struct MT3620Blink_Event__ctor_EXECUTION_FRAME_DECL
{
    const IL2C_EXECUTION_FRAME* pNext__;
    const uint16_t objRefCount__;
    const uint16_t valueCount__;
    //-------------------- objref
    MT3620Blink_Event* stack0_0__;
} MT3620Blink_Event__ctor_EXECUTION_FRAME__;

//-------------------
// [3-2] Function body:

void MT3620Blink_Event__ctor(MT3620Blink_Event* this__)
{
    il2c_assert(this__ != NULL);

    //-------------------
    // [3-4] Evaluation stacks (!objref):

    int32_t stack1_0__;
    int32_t stack2_0__;
    int32_t stack3_0__;

    //-------------------
    // [3-5] Setup execution frame:

    MT3620Blink_Event__ctor_EXECUTION_FRAME__ frame__ =
        { NULL, 1 };
    il2c_link_execution_frame(&frame__);

    //-------------------
    // [3-6] IL body:

    /* IL_0000: ldarg.0                         : Event.cs(14) */
    frame__.stack0_0__ = this__;
    /* IL_0001: ldc.i4.0                        : Event.cs(14) */
    stack1_0__ = 0;
    /* IL_0002: ldsfld MT3620Blink.Event.EFD_NONBLOCK : Event.cs(14) */
    stack2_0__ = MT3620Blink_Event_EFD_NONBLOCK;
    /* IL_0007: ldsfld MT3620Blink.Event.EFD_SEMAPHORE : Event.cs(14) */
    stack3_0__ = MT3620Blink_Event_EFD_SEMAPHORE;
    /* IL_000c: or                              : Event.cs(14) */
    stack2_0__ = stack2_0__ | stack3_0__;
    /* IL_000d: call MT3620Blink.Interops.eventfd : Event.cs(14) */
    stack1_0__ = MT3620Blink_Interops_eventfd((uint32_t)stack1_0__, stack2_0__);
    /* IL_0012: call MT3620Blink.Descriptor..ctor : Event.cs(14) */
    MT3620Blink_Descriptor__ctor((MT3620Blink_Descriptor*)frame__.stack0_0__, stack1_0__);
    /* IL_0017: ret                             : Event.cs(16) */
    il2c_unlink_execution_frame(&frame__);
    return;
}

///////////////////////////////////////
// [3] MT3620Blink.Event.Pulse(MT3620Blink.Event this__)

//-------------------
// [3-7] Declare execution frame:

typedef struct MT3620Blink_Event_Pulse_EXECUTION_FRAME_DECL
{
    const IL2C_EXECUTION_FRAME* pNext__;
    const uint16_t objRefCount__;
    const uint16_t valueCount__;
    //-------------------- objref
    MT3620Blink_Event* stack0_0__;
} MT3620Blink_Event_Pulse_EXECUTION_FRAME__;

//-------------------
// [3-2] Function body:

void MT3620Blink_Event_Pulse(MT3620Blink_Event* this__)
{
    il2c_assert(this__ != NULL);

    //-------------------
    // [3-4] Evaluation stacks (!objref):

    int32_t stack0_1__;
    int32_t stack1_0__;
    int64_t stack1_1__;

    //-------------------
    // [3-5] Setup execution frame:

    MT3620Blink_Event_Pulse_EXECUTION_FRAME__ frame__ =
        { NULL, 1 };
    il2c_link_execution_frame(&frame__);

    //-------------------
    // [3-6] IL body:

    /* IL_0000: ldarg.0                         : Event.cs(20) */
    frame__.stack0_0__ = this__;
    /* IL_0001: call MT3620Blink.Descriptor.get_Identity : Event.cs(20) */
    stack0_1__ = MT3620Blink_Descriptor_get_Identity((MT3620Blink_Descriptor*)frame__.stack0_0__);
    /* IL_0006: ldc.i4.1                        : Event.cs(20) */
    stack1_0__ = 1;
    /* IL_0007: conv.i8                         : Event.cs(20) */
    stack1_1__ = (int64_t)stack1_0__;
    /* IL_0008: call MT3620Blink.Interops.eventfd_write : Event.cs(20) */
    stack0_1__ = MT3620Blink_Interops_eventfd_write(stack0_1__, (uint64_t)stack1_1__);
    /* IL_000d: pop                             : Event.cs(20) */
    /* IL_000e: ret  */
    il2c_unlink_execution_frame(&frame__);
    return;
}

///////////////////////////////////////
// [3] MT3620Blink.Event.MT3620Blink.IEPollListener.get_Identity(MT3620Blink.Event this__)

//-------------------
// [3-7] Declare execution frame:

typedef struct MT3620Blink_Event_MT3620Blink_IEPollListener_get_Identity_EXECUTION_FRAME_DECL
{
    const IL2C_EXECUTION_FRAME* pNext__;
    const uint16_t objRefCount__;
    const uint16_t valueCount__;
    //-------------------- objref
    MT3620Blink_Event* stack0_0__;
} MT3620Blink_Event_MT3620Blink_IEPollListener_get_Identity_EXECUTION_FRAME__;

//-------------------
// [3-2] Function body:

int32_t MT3620Blink_Event_MT3620Blink_IEPollListener_get_Identity(MT3620Blink_Event* this__)
{
    il2c_assert(this__ != NULL);

    //-------------------
    // [3-4] Evaluation stacks (!objref):

    int32_t stack0_1__;

    //-------------------
    // [3-5] Setup execution frame:

    MT3620Blink_Event_MT3620Blink_IEPollListener_get_Identity_EXECUTION_FRAME__ frame__ =
        { NULL, 1 };
    il2c_link_execution_frame(&frame__);

    //-------------------
    // [3-6] IL body:

    /* IL_0000: ldarg.0                         : Event.cs(23) */
    frame__.stack0_0__ = this__;
    /* IL_0001: call MT3620Blink.Descriptor.get_Identity : Event.cs(23) */
    stack0_1__ = MT3620Blink_Descriptor_get_Identity((MT3620Blink_Descriptor*)frame__.stack0_0__);
    /* IL_0006: ret                             : Event.cs(23) */
    il2c_unlink_execution_frame(&frame__);
    return stack0_1__;
}

///////////////////////////////////////
// [3] MT3620Blink.Event.MT3620Blink.IEPollListener.OnRaised(MT3620Blink.Event this__)

//-------------------
// [3-7] Declare execution frame:

typedef struct MT3620Blink_Event_MT3620Blink_IEPollListener_OnRaised_EXECUTION_FRAME_DECL
{
    const IL2C_EXECUTION_FRAME* pNext__;
    const uint16_t objRefCount__;
    const uint16_t valueCount__;
    //-------------------- objref
    MT3620Blink_Event* stack0_0__;
} MT3620Blink_Event_MT3620Blink_IEPollListener_OnRaised_EXECUTION_FRAME__;

//-------------------
// [3-2] Function body:

void MT3620Blink_Event_MT3620Blink_IEPollListener_OnRaised(MT3620Blink_Event* this__)
{
    il2c_assert(this__ != NULL);

    //-------------------
    // [3-3] Local variables (!objref):

    uint64_t value = 0ULL;

    //-------------------
    // [3-4] Evaluation stacks (!objref):

    int32_t stack0_1__;
    uint64_t* stack1_0__;

    //-------------------
    // [3-5] Setup execution frame:

    MT3620Blink_Event_MT3620Blink_IEPollListener_OnRaised_EXECUTION_FRAME__ frame__ =
        { NULL, 1 };
    il2c_link_execution_frame(&frame__);

    //-------------------
    // [3-6] IL body:

    /* IL_0000: ldarg.0                         : Event.cs(27) */
    frame__.stack0_0__ = this__;
    /* IL_0001: call MT3620Blink.Descriptor.get_Identity : Event.cs(27) */
    stack0_1__ = MT3620Blink_Descriptor_get_Identity((MT3620Blink_Descriptor*)frame__.stack0_0__);
    /* IL_0006: ldloca.s value                  : Event.cs(27) */
    stack1_0__ = &value;
    /* IL_0008: call MT3620Blink.Interops.eventfd_read : Event.cs(27) */
    stack0_1__ = MT3620Blink_Interops_eventfd_read(stack0_1__, stack1_0__);
    /* IL_000d: pop                             : Event.cs(27) */
    /* IL_000e: ldarg.0  */
    frame__.stack0_0__ = this__;
    /* IL_000f: callvirt MT3620Blink.Event.Received : Event.cs(28) */
    frame__.stack0_0__->vptr0__->Received(frame__.stack0_0__);
    /* IL_0014: ret                             : Event.cs(29) */
    il2c_unlink_execution_frame(&frame__);
    return;
}

//////////////////////
// [7] Runtime helpers:

// [7-13] VTable for System.IDisposable
System_IDisposable_VTABLE_DECL__ MT3620Blink_Event_System_IDisposable_VTABLE__ = {
    il2c_adjustor_offset(MT3620Blink_Event, System_IDisposable),
    (void (*)(void*))MT3620Blink_Descriptor_Dispose,
};

// [7-13] VTable for MT3620Blink.IEPollListener
MT3620Blink_IEPollListener_VTABLE_DECL__ MT3620Blink_Event_MT3620Blink_IEPollListener_VTABLE__ = {
    il2c_adjustor_offset(MT3620Blink_Event, MT3620Blink_IEPollListener),
    (int32_t (*)(void*))MT3620Blink_Event_MT3620Blink_IEPollListener_get_Identity,
    (void (*)(void*))MT3620Blink_Event_MT3620Blink_IEPollListener_OnRaised,
};

// [7-8] Runtime type information
IL2C_RUNTIME_TYPE_ABSTRACT_BEGIN(MT3620Blink_Event, "MT3620Blink.Event", sizeof(MT3620Blink_Event), MT3620Blink_Descriptor, 0, 2)
    IL2C_RUNTIME_TYPE_INTERFACE(MT3620Blink_Event, System_IDisposable)
    IL2C_RUNTIME_TYPE_INTERFACE(MT3620Blink_Event, MT3620Blink_IEPollListener)
IL2C_RUNTIME_TYPE_END();

#ifdef __cplusplus
}
#endif
