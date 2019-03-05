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
#line 14 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Event.cs"
    il2c_assert(this__ != NULL);

    //-------------------
    // [3-4] Evaluation stacks (!objref):

#line 14 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Event.cs"
    int32_t stack1_0__;
#line 14 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Event.cs"
    int32_t stack2_0__;
#line 14 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Event.cs"
    int32_t stack3_0__;

    //-------------------
    // [3-5] Setup execution frame:

#line 14 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Event.cs"
    MT3620Blink_Event__ctor_EXECUTION_FRAME__ frame__ =
        { NULL, 1 };
#line 14 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Event.cs"
    il2c_link_execution_frame(&frame__);

    //-------------------
    // [3-6] IL body:

    /* IL_0000: ldarg.0  */
#line 14 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Event.cs"
    frame__.stack0_0__ = this__;
    /* IL_0001: ldc.i4.0  */
#line 14 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Event.cs"
    stack1_0__ = 0;
    /* IL_0002: ldsfld MT3620Blink.Event.EFD_NONBLOCK */
#line 14 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Event.cs"
    stack2_0__ = MT3620Blink_Event_EFD_NONBLOCK;
    /* IL_0007: ldsfld MT3620Blink.Event.EFD_SEMAPHORE */
#line 14 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Event.cs"
    stack3_0__ = MT3620Blink_Event_EFD_SEMAPHORE;
    /* IL_000c: or  */
#line 14 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Event.cs"
    stack2_0__ = stack2_0__ | stack3_0__;
    /* IL_000d: call MT3620Blink.Interops.eventfd */
#line 14 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Event.cs"
    stack1_0__ = MT3620Blink_Interops_eventfd((uint32_t)stack1_0__, stack2_0__);
    /* IL_0012: call MT3620Blink.Descriptor..ctor */
#line 14 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Event.cs"
    MT3620Blink_Descriptor__ctor((MT3620Blink_Descriptor*)frame__.stack0_0__, stack1_0__);
    /* IL_0017: nop  */
    /* IL_0018: nop  */
    /* IL_0019: ret  */
#line 16 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Event.cs"
    il2c_unlink_execution_frame(&frame__);
#line 16 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Event.cs"
    return;
#line 16 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Event.cs"
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
#line 19 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Event.cs"
    il2c_assert(this__ != NULL);

    //-------------------
    // [3-4] Evaluation stacks (!objref):

#line 19 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Event.cs"
    int32_t stack0_1__;
#line 19 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Event.cs"
    int32_t stack1_0__;
#line 19 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Event.cs"
    int64_t stack1_1__;

    //-------------------
    // [3-5] Setup execution frame:

#line 19 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Event.cs"
    MT3620Blink_Event_Pulse_EXECUTION_FRAME__ frame__ =
        { NULL, 1 };
#line 19 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Event.cs"
    il2c_link_execution_frame(&frame__);

    //-------------------
    // [3-6] IL body:

    /* IL_0000: nop  */
    /* IL_0001: ldarg.0  */
#line 20 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Event.cs"
    frame__.stack0_0__ = this__;
    /* IL_0002: call MT3620Blink.Descriptor.get_Identity */
#line 20 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Event.cs"
    stack0_1__ = MT3620Blink_Descriptor_get_Identity((MT3620Blink_Descriptor*)frame__.stack0_0__);
    /* IL_0007: ldc.i4.1  */
#line 20 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Event.cs"
    stack1_0__ = 1;
    /* IL_0008: conv.i8  */
#line 20 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Event.cs"
    stack1_1__ = (int64_t)stack1_0__;
    /* IL_0009: call MT3620Blink.Interops.eventfd_write */
#line 20 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Event.cs"
    stack0_1__ = MT3620Blink_Interops_eventfd_write(stack0_1__, (uint64_t)stack1_1__);
    /* IL_000e: pop  */
    /* IL_000f: ret  */
#line 21 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Event.cs"
    il2c_unlink_execution_frame(&frame__);
#line 21 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Event.cs"
    return;
#line 21 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Event.cs"
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
#line 23 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Event.cs"
    il2c_assert(this__ != NULL);

    //-------------------
    // [3-4] Evaluation stacks (!objref):

#line 23 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Event.cs"
    int32_t stack0_1__;

    //-------------------
    // [3-5] Setup execution frame:

#line 23 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Event.cs"
    MT3620Blink_Event_MT3620Blink_IEPollListener_get_Identity_EXECUTION_FRAME__ frame__ =
        { NULL, 1 };
#line 23 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Event.cs"
    il2c_link_execution_frame(&frame__);

    //-------------------
    // [3-6] IL body:

    /* IL_0000: ldarg.0  */
#line 23 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Event.cs"
    frame__.stack0_0__ = this__;
    /* IL_0001: call MT3620Blink.Descriptor.get_Identity */
#line 23 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Event.cs"
    stack0_1__ = MT3620Blink_Descriptor_get_Identity((MT3620Blink_Descriptor*)frame__.stack0_0__);
    /* IL_0006: ret  */
#line 23 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Event.cs"
    il2c_unlink_execution_frame(&frame__);
#line 23 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Event.cs"
    return stack0_1__;
#line 23 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Event.cs"
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
#line 26 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Event.cs"
    il2c_assert(this__ != NULL);

    //-------------------
    // [3-3] Local variables (!objref):

#line 26 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Event.cs"
    uint64_t value = 0ULL;

    //-------------------
    // [3-4] Evaluation stacks (!objref):

#line 26 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Event.cs"
    int32_t stack0_1__;
#line 26 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Event.cs"
    uint64_t* stack1_0__;

    //-------------------
    // [3-5] Setup execution frame:

#line 26 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Event.cs"
    MT3620Blink_Event_MT3620Blink_IEPollListener_OnRaised_EXECUTION_FRAME__ frame__ =
        { NULL, 1 };
#line 26 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Event.cs"
    il2c_link_execution_frame(&frame__);

    //-------------------
    // [3-6] IL body:

    /* IL_0000: nop  */
    /* IL_0001: ldarg.0  */
#line 27 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Event.cs"
    frame__.stack0_0__ = this__;
    /* IL_0002: call MT3620Blink.Descriptor.get_Identity */
#line 27 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Event.cs"
    stack0_1__ = MT3620Blink_Descriptor_get_Identity((MT3620Blink_Descriptor*)frame__.stack0_0__);
    /* IL_0007: ldloca.s value */
#line 27 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Event.cs"
    stack1_0__ = &value;
    /* IL_0009: call MT3620Blink.Interops.eventfd_read */
#line 27 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Event.cs"
    stack0_1__ = MT3620Blink_Interops_eventfd_read(stack0_1__, stack1_0__);
    /* IL_000e: pop  */
    /* IL_000f: ldarg.0  */
#line 28 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Event.cs"
    frame__.stack0_0__ = this__;
    /* IL_0010: callvirt MT3620Blink.Event.Received */
#line 28 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Event.cs"
    frame__.stack0_0__->vptr0__->Received(frame__.stack0_0__);
    /* IL_0015: nop  */
    /* IL_0016: ret  */
#line 29 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Event.cs"
    il2c_unlink_execution_frame(&frame__);
#line 29 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Event.cs"
    return;
#line 29 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Event.cs"
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
