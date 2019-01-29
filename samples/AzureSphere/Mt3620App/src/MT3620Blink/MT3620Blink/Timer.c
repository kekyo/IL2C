// [15-2] This is MT3620Blink native code translated by IL2C, do not edit.

#include <MT3620Blink.h>
#include <MT3620Blink_internal.h>

#include <mscorlib.h>

#ifdef __cplusplus
extern "C" {
#endif

//////////////////////////////////////////////////////////////////////////////////
// [9-1] Type: MT3620Blink.Timer

//////////////////////////////////////////////////////////////////////////////////
// [9-2] File scope prototypes:

//////////////////////////////////////////////////////////////////////////////////
// [2-2] Static fields: MT3620Blink.Timer

#define MT3620Blink_Timer_CLOCK_MONOTONIC CLOCK_MONOTONIC
#define MT3620Blink_Timer_TFD_NONBLOCK TFD_NONBLOCK

//////////////////////////////////////////////////////////////////////////////////
// [9-3] Static field instances:

//////////////////////////////////////////////////////////////////////////////////
// [9-4] Type: MT3620Blink.Timer

///////////////////////////////////////
// [3] MT3620Blink.Timer..ctor(MT3620Blink.Timer this__)

//-------------------
// [3-7] Declare execution frame:

typedef struct MT3620Blink_Timer__ctor_EXECUTION_FRAME_DECL
{
    const IL2C_EXECUTION_FRAME* pNext__;
    const uint16_t objRefCount__;
    const uint16_t valueCount__;
    //-------------------- objref
    MT3620Blink_Timer* stack0_0__;
} MT3620Blink_Timer__ctor_EXECUTION_FRAME__;

//-------------------
// [3-2] Function body:

void MT3620Blink_Timer__ctor(MT3620Blink_Timer* this__)
{
    il2c_assert(this__ != NULL);

    //-------------------
    // [3-4] Evaluation stacks (!objref):

    int32_t stack1_0__;
    int32_t stack2_0__;

    //-------------------
    // [3-5] Setup execution frame:

    MT3620Blink_Timer__ctor_EXECUTION_FRAME__ frame__ =
        { NULL, 1 };
    il2c_link_execution_frame(&frame__);

    //-------------------
    // [3-6] IL body:

    /* IL_0000: ldarg.0                         : Timer.cs(14) */
    frame__.stack0_0__ = this__;
    /* IL_0001: ldsfld MT3620Blink.Timer.CLOCK_MONOTONIC : Timer.cs(14) */
    stack1_0__ = MT3620Blink_Timer_CLOCK_MONOTONIC;
    /* IL_0006: ldsfld MT3620Blink.Timer.TFD_NONBLOCK : Timer.cs(14) */
    stack2_0__ = MT3620Blink_Timer_TFD_NONBLOCK;
    /* IL_000b: call MT3620Blink.Interops.timerfd_create : Timer.cs(14) */
    stack1_0__ = MT3620Blink_Interops_timerfd_create(stack1_0__, stack2_0__);
    /* IL_0010: call MT3620Blink.Descriptor..ctor : Timer.cs(14) */
    MT3620Blink_Descriptor__ctor((MT3620Blink_Descriptor*)frame__.stack0_0__, stack1_0__);
    /* IL_0015: nop                             : Timer.cs(14) */
    /* IL_0016: nop  */
    /* IL_0017: ret  */
    il2c_unlink_execution_frame(&frame__);
    return;
}

///////////////////////////////////////
// [3] MT3620Blink.Timer.SetInterval(MT3620Blink.Timer this__, System.Int64 nsec)

//-------------------
// [3-7] Declare execution frame:

typedef struct MT3620Blink_Timer_SetInterval_EXECUTION_FRAME_DECL
{
    const IL2C_EXECUTION_FRAME* pNext__;
    const uint16_t objRefCount__;
    const uint16_t valueCount__;
    //-------------------- objref
    MT3620Blink_Timer* stack0_4__;
} MT3620Blink_Timer_SetInterval_EXECUTION_FRAME__;

//-------------------
// [3-2] Function body:

void MT3620Blink_Timer_SetInterval(MT3620Blink_Timer* this__, int64_t nsec)
{
    il2c_assert(this__ != NULL);

    //-------------------
    // [3-3] Local variables (!objref):

    MT3620Blink_timespec tm;
    il2c_memset(&tm, 0x00, sizeof tm);
    MT3620Blink_itimerspec newValue;
    il2c_memset(&newValue, 0x00, sizeof newValue);
    MT3620Blink_itimerspec dummy;
    il2c_memset(&dummy, 0x00, sizeof dummy);
    MT3620Blink_timespec local3__;
    il2c_memset(&local3__, 0x00, sizeof local3__);
    MT3620Blink_itimerspec local4__;
    il2c_memset(&local4__, 0x00, sizeof local4__);

    //-------------------
    // [3-4] Evaluation stacks (!objref):

    MT3620Blink_timespec* stack0_0__;
    MT3620Blink_timespec stack0_1__;
    MT3620Blink_itimerspec* stack0_2__;
    MT3620Blink_itimerspec stack0_3__;
    int32_t stack0_5__;
    int64_t stack1_0__;
    int32_t stack1_1__;
    MT3620Blink_timespec stack1_2__;
    int32_t stack2_0__;
    int64_t stack2_1__;
    MT3620Blink_itimerspec* stack2_2__;
    MT3620Blink_itimerspec* stack3_0__;

    //-------------------
    // [3-5] Setup execution frame:

    MT3620Blink_Timer_SetInterval_EXECUTION_FRAME__ frame__ =
        { NULL, 1 };
    il2c_link_execution_frame(&frame__);

    //-------------------
    // [3-6] IL body:

    /* IL_0000: nop                             : Timer.cs(19) */
    /* IL_0001: ldloca.s local3__ */
    stack0_0__ = &local3__;
    /* IL_0003: initobj MT3620Blink.timespec    : Timer.cs(20) */
    il2c_memset(stack0_0__, 0x00, sizeof *stack0_0__);
    /* IL_0009: ldloca.s local3__               : Timer.cs(20) */
    stack0_0__ = &local3__;
    /* IL_000b: ldarg.1                         : Timer.cs(20) */
    stack1_0__ = nsec;
    /* IL_000c: ldc.i4 1000000000               : Timer.cs(20) */
    stack2_0__ = 1000000000;
    /* IL_0011: conv.i8                         : Timer.cs(20) */
    stack2_1__ = (int64_t)stack2_0__;
    /* IL_0012: div                             : Timer.cs(20) */
    stack1_0__ = stack1_0__ / stack2_1__;
    /* IL_0013: conv.i4                         : Timer.cs(20) */
    stack1_1__ = (int32_t)stack1_0__;
    /* IL_0014: stfld MT3620Blink.timespec.tv_sec : Timer.cs(20) */
    stack0_0__->tv_sec = stack1_1__;
    /* IL_0019: ldloca.s local3__               : Timer.cs(20) */
    stack0_0__ = &local3__;
    /* IL_001b: ldarg.1                         : Timer.cs(20) */
    stack1_0__ = nsec;
    /* IL_001c: ldc.i4 1000000000               : Timer.cs(20) */
    stack2_0__ = 1000000000;
    /* IL_0021: conv.i8                         : Timer.cs(20) */
    stack2_1__ = (int64_t)stack2_0__;
    /* IL_0022: rem                             : Timer.cs(20) */
    stack1_0__ = stack1_0__ % stack2_1__;
    /* IL_0023: conv.i4                         : Timer.cs(20) */
    stack1_1__ = (int32_t)stack1_0__;
    /* IL_0024: stfld MT3620Blink.timespec.tv_nsec : Timer.cs(20) */
    stack0_0__->tv_nsec = stack1_1__;
    /* IL_0029: ldloc.3                         : Timer.cs(20) */
    stack0_1__ = local3__;
    /* IL_002a: stloc.0                         : Timer.cs(20) */
    tm = stack0_1__;
    /* IL_002b: ldloca.s local4__               : Timer.cs(25) */
    stack0_2__ = &local4__;
    /* IL_002d: initobj MT3620Blink.itimerspec  : Timer.cs(25) */
    il2c_memset(stack0_2__, 0x00, sizeof *stack0_2__);
    /* IL_0033: ldloca.s local4__               : Timer.cs(25) */
    stack0_2__ = &local4__;
    /* IL_0035: ldloc.0                         : Timer.cs(25) */
    stack1_2__ = tm;
    /* IL_0036: stfld MT3620Blink.itimerspec.it_value : Timer.cs(25) */
    stack0_2__->it_value = stack1_2__;
    /* IL_003b: ldloca.s local4__               : Timer.cs(25) */
    stack0_2__ = &local4__;
    /* IL_003d: ldloc.0                         : Timer.cs(25) */
    stack1_2__ = tm;
    /* IL_003e: stfld MT3620Blink.itimerspec.it_interval : Timer.cs(25) */
    stack0_2__->it_interval = stack1_2__;
    /* IL_0043: ldloc.s local4__                : Timer.cs(25) */
    stack0_3__ = local4__;
    /* IL_0045: stloc.1                         : Timer.cs(25) */
    newValue = stack0_3__;
    /* IL_0046: ldarg.0                         : Timer.cs(31) */
    frame__.stack0_4__ = this__;
    /* IL_0047: call MT3620Blink.Descriptor.get_Identity : Timer.cs(31) */
    stack0_5__ = MT3620Blink_Descriptor_get_Identity((MT3620Blink_Descriptor*)frame__.stack0_4__);
    /* IL_004c: ldc.i4.0                        : Timer.cs(31) */
    stack1_1__ = 0;
    /* IL_004d: ldloca.s newValue               : Timer.cs(31) */
    stack2_2__ = &newValue;
    /* IL_004f: ldloca.s dummy                  : Timer.cs(31) */
    stack3_0__ = &dummy;
    /* IL_0051: call MT3620Blink.Interops.timerfd_settime : Timer.cs(31) */
    stack0_5__ = MT3620Blink_Interops_timerfd_settime(stack0_5__, stack1_1__, stack2_2__, stack3_0__);
    /* IL_0056: pop                             : Timer.cs(31) */
    /* IL_0057: ret  */
    il2c_unlink_execution_frame(&frame__);
    return;
}

///////////////////////////////////////
// [3] MT3620Blink.Timer.MT3620Blink.IEPollListener.get_Identity(MT3620Blink.Timer this__)

//-------------------
// [3-7] Declare execution frame:

typedef struct MT3620Blink_Timer_MT3620Blink_IEPollListener_get_Identity_EXECUTION_FRAME_DECL
{
    const IL2C_EXECUTION_FRAME* pNext__;
    const uint16_t objRefCount__;
    const uint16_t valueCount__;
    //-------------------- objref
    MT3620Blink_Timer* stack0_0__;
} MT3620Blink_Timer_MT3620Blink_IEPollListener_get_Identity_EXECUTION_FRAME__;

//-------------------
// [3-2] Function body:

int32_t MT3620Blink_Timer_MT3620Blink_IEPollListener_get_Identity(MT3620Blink_Timer* this__)
{
    il2c_assert(this__ != NULL);

    //-------------------
    // [3-4] Evaluation stacks (!objref):

    int32_t stack0_1__;

    //-------------------
    // [3-5] Setup execution frame:

    MT3620Blink_Timer_MT3620Blink_IEPollListener_get_Identity_EXECUTION_FRAME__ frame__ =
        { NULL, 1 };
    il2c_link_execution_frame(&frame__);

    //-------------------
    // [3-6] IL body:

    /* IL_0000: ldarg.0                         : Timer.cs(34) */
    frame__.stack0_0__ = this__;
    /* IL_0001: call MT3620Blink.Descriptor.get_Identity : Timer.cs(34) */
    stack0_1__ = MT3620Blink_Descriptor_get_Identity((MT3620Blink_Descriptor*)frame__.stack0_0__);
    /* IL_0006: ret                             : Timer.cs(34) */
    il2c_unlink_execution_frame(&frame__);
    return stack0_1__;
}

///////////////////////////////////////
// [3] MT3620Blink.Timer.MT3620Blink.IEPollListener.OnRaised(MT3620Blink.Timer this__)

//-------------------
// [3-7] Declare execution frame:

typedef struct MT3620Blink_Timer_MT3620Blink_IEPollListener_OnRaised_EXECUTION_FRAME_DECL
{
    const IL2C_EXECUTION_FRAME* pNext__;
    const uint16_t objRefCount__;
    const uint16_t valueCount__;
    //-------------------- objref
    MT3620Blink_Timer* stack0_0__;
} MT3620Blink_Timer_MT3620Blink_IEPollListener_OnRaised_EXECUTION_FRAME__;

//-------------------
// [3-2] Function body:

void MT3620Blink_Timer_MT3620Blink_IEPollListener_OnRaised(MT3620Blink_Timer* this__)
{
    il2c_assert(this__ != NULL);

    //-------------------
    // [3-3] Local variables (!objref):

    uint64_t timerData = 0ULL;

    //-------------------
    // [3-4] Evaluation stacks (!objref):

    int32_t stack0_1__;
    uint64_t* stack1_0__;
    int32_t stack2_0__;
    int64_t stack2_1__;
    uintptr_t stack2_2__;

    //-------------------
    // [3-5] Setup execution frame:

    MT3620Blink_Timer_MT3620Blink_IEPollListener_OnRaised_EXECUTION_FRAME__ frame__ =
        { NULL, 1 };
    il2c_link_execution_frame(&frame__);

    //-------------------
    // [3-6] IL body:

    /* IL_0000: nop                             : Timer.cs(37) */
    /* IL_0001: ldarg.0  */
    frame__.stack0_0__ = this__;
    /* IL_0002: call MT3620Blink.Descriptor.get_Identity : Timer.cs(38) */
    stack0_1__ = MT3620Blink_Descriptor_get_Identity((MT3620Blink_Descriptor*)frame__.stack0_0__);
    /* IL_0007: ldloca.s timerData              : Timer.cs(38) */
    stack1_0__ = &timerData;
    /* IL_0009: ldc.i4.8                        : Timer.cs(38) */
    stack2_0__ = 8;
    /* IL_000a: conv.i8                         : Timer.cs(38) */
    stack2_1__ = (int64_t)stack2_0__;
    /* IL_000b: call System.UIntPtr.op_Explicit : Timer.cs(38) */
    stack2_2__ = System_UIntPtr_op_Explicit_2((uint64_t)stack2_1__);
    /* IL_0010: call MT3620Blink.Interops.timerfd_read : Timer.cs(38) */
    stack0_1__ = MT3620Blink_Interops_timerfd_read(stack0_1__, stack1_0__, stack2_2__);
    /* IL_0015: pop                             : Timer.cs(38) */
    /* IL_0016: ldarg.0  */
    frame__.stack0_0__ = this__;
    /* IL_0017: callvirt MT3620Blink.Timer.Raised : Timer.cs(39) */
    frame__.stack0_0__->vptr0__->Raised(il2c_adjusted_reference(frame__.stack0_0__));
    /* IL_001c: nop                             : Timer.cs(39) */
    /* IL_001d: ret  */
    il2c_unlink_execution_frame(&frame__);
    return;
}

//////////////////////
// [7] Runtime helpers:

// [7-13] VTable for System.IDisposable
System_IDisposable_VTABLE_DECL__ MT3620Blink_Timer_System_IDisposable_VTABLE__ = {
    il2c_adjustor_offset(MT3620Blink_Timer, System_IDisposable),
    (void (*)(void*))MT3620Blink_Descriptor_Dispose,
};

// [7-13] VTable for MT3620Blink.IEPollListener
MT3620Blink_IEPollListener_VTABLE_DECL__ MT3620Blink_Timer_MT3620Blink_IEPollListener_VTABLE__ = {
    il2c_adjustor_offset(MT3620Blink_Timer, MT3620Blink_IEPollListener),
    (int32_t (*)(void*))MT3620Blink_Timer_MT3620Blink_IEPollListener_get_Identity,
    (void (*)(void*))MT3620Blink_Timer_MT3620Blink_IEPollListener_OnRaised,
};

// [7-8] Runtime type information
IL2C_RUNTIME_TYPE_ABSTRACT_BEGIN(MT3620Blink_Timer, "MT3620Blink.Timer", sizeof(MT3620Blink_Timer), MT3620Blink_Descriptor, 0, 2)
    IL2C_RUNTIME_TYPE_INTERFACE(MT3620Blink_Timer, System_IDisposable)
    IL2C_RUNTIME_TYPE_INTERFACE(MT3620Blink_Timer, MT3620Blink_IEPollListener)
IL2C_RUNTIME_TYPE_END();

#ifdef __cplusplus
}
#endif
