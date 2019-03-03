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

    //-------------------
    // [3-5] Setup execution frame:

    MT3620Blink_Event__ctor_EXECUTION_FRAME__ frame__ =
        { NULL, 1 };
    il2c_link_execution_frame(&frame__);

    //-------------------
    // [3-6] IL body:

    /* IL_0000: ldarg.0                         : Event.cs(9) */
    frame__.stack0_0__ = this__;
    /* IL_0001: ldc.i4.0                        : Event.cs(9) */
    stack1_0__ = 0;
    /* IL_0002: ldc.i4.0                        : Event.cs(9) */
    stack2_0__ = 0;
    /* IL_0003: call MT3620Blink.Interops.eventfd : Event.cs(9) */
    stack1_0__ = MT3620Blink_Interops_eventfd((uint32_t)stack1_0__, stack2_0__);
    /* IL_0008: call MT3620Blink.Descriptor..ctor : Event.cs(9) */
    MT3620Blink_Descriptor__ctor((MT3620Blink_Descriptor*)frame__.stack0_0__, stack1_0__);
    /* IL_000d: nop                             : Event.cs(9) */
    /* IL_000e: nop  */
    /* IL_000f: ret  */
    il2c_unlink_execution_frame(&frame__);
    return;
}

///////////////////////////////////////
// [3] MT3620Blink.Event.Send(MT3620Blink.Event this__, System.UInt64 value)

//-------------------
// [3-7] Declare execution frame:

typedef struct MT3620Blink_Event_Send_EXECUTION_FRAME_DECL
{
    const IL2C_EXECUTION_FRAME* pNext__;
    const uint16_t objRefCount__;
    const uint16_t valueCount__;
    //-------------------- objref
    MT3620Blink_Event* stack0_0__;
} MT3620Blink_Event_Send_EXECUTION_FRAME__;

//-------------------
// [3-2] Function body:

void MT3620Blink_Event_Send(MT3620Blink_Event* this__, uint64_t value)
{
    il2c_assert(this__ != NULL);

    //-------------------
    // [3-4] Evaluation stacks (!objref):

    int32_t stack0_1__;
    uint64_t stack1_0__;

    //-------------------
    // [3-5] Setup execution frame:

    MT3620Blink_Event_Send_EXECUTION_FRAME__ frame__ =
        { NULL, 1 };
    il2c_link_execution_frame(&frame__);

    //-------------------
    // [3-6] IL body:

    /* IL_0000: nop                             : Event.cs(14) */
    /* IL_0001: ldarg.0  */
    frame__.stack0_0__ = this__;
    /* IL_0002: call MT3620Blink.Descriptor.get_Identity : Event.cs(15) */
    stack0_1__ = MT3620Blink_Descriptor_get_Identity((MT3620Blink_Descriptor*)frame__.stack0_0__);
    /* IL_0007: ldarg.1                         : Event.cs(15) */
    stack1_0__ = value;
    /* IL_0008: call MT3620Blink.Interops.eventfd_write : Event.cs(15) */
    stack0_1__ = MT3620Blink_Interops_eventfd_write(stack0_1__, stack1_0__);
    /* IL_000d: pop                             : Event.cs(15) */
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

    /* IL_0000: ldarg.0                         : Event.cs(18) */
    frame__.stack0_0__ = this__;
    /* IL_0001: call MT3620Blink.Descriptor.get_Identity : Event.cs(18) */
    stack0_1__ = MT3620Blink_Descriptor_get_Identity((MT3620Blink_Descriptor*)frame__.stack0_0__);
    /* IL_0006: ret                             : Event.cs(18) */
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
    uint64_t stack1_1__;

    //-------------------
    // [3-5] Setup execution frame:

    MT3620Blink_Event_MT3620Blink_IEPollListener_OnRaised_EXECUTION_FRAME__ frame__ =
        { NULL, 1 };
    il2c_link_execution_frame(&frame__);

    //-------------------
    // [3-6] IL body:

    /* IL_0000: nop                             : Event.cs(21) */
    /* IL_0001: ldarg.0  */
    frame__.stack0_0__ = this__;
    /* IL_0002: call MT3620Blink.Descriptor.get_Identity : Event.cs(22) */
    stack0_1__ = MT3620Blink_Descriptor_get_Identity((MT3620Blink_Descriptor*)frame__.stack0_0__);
    /* IL_0007: ldloca.s value                  : Event.cs(22) */
    stack1_0__ = &value;
    /* IL_0009: call MT3620Blink.Interops.eventfd_read : Event.cs(22) */
    stack0_1__ = MT3620Blink_Interops_eventfd_read(stack0_1__, stack1_0__);
    /* IL_000e: pop                             : Event.cs(22) */
    /* IL_000f: ldarg.0  */
    frame__.stack0_0__ = this__;
    /* IL_0010: ldloc.0                         : Event.cs(23) */
    stack1_1__ = value;
    /* IL_0011: callvirt MT3620Blink.Event.Received : Event.cs(23) */
    frame__.stack0_0__->vptr0__->Received(frame__.stack0_0__, stack1_1__);
    /* IL_0016: nop                             : Event.cs(23) */
    /* IL_0017: ret  */
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
