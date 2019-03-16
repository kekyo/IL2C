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

/* private static readonly */ #define MT3620Blink_Timer_CLOCK_MONOTONIC CLOCK_MONOTONIC

/* private static readonly */ #define MT3620Blink_Timer_TFD_NONBLOCK TFD_NONBLOCK

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
    /* IL_0015: ret                             : Timer.cs(16) */
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
    memset(&tm, 0x00, sizeof tm);
    MT3620Blink_itimerspec newValue;
    memset(&newValue, 0x00, sizeof newValue);
    MT3620Blink_itimerspec dummy;
    memset(&dummy, 0x00, sizeof dummy);
    MT3620Blink_timespec local3__;
    memset(&local3__, 0x00, sizeof local3__);
    MT3620Blink_itimerspec local4__;
    memset(&local4__, 0x00, sizeof local4__);

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

    /* IL_0000: ldloca.s local3__               : Timer.cs(20) */
    stack0_0__ = &local3__;
    /* IL_0002: initobj MT3620Blink.timespec    : Timer.cs(20) */
    memset(stack0_0__, 0x00, sizeof *stack0_0__);
    /* IL_0008: ldloca.s local3__               : Timer.cs(20) */
    stack0_0__ = &local3__;
    /* IL_000a: ldarg.1                         : Timer.cs(20) */
    stack1_0__ = nsec;
    /* IL_000b: ldc.i4 1000000000               : Timer.cs(20) */
    stack2_0__ = 1000000000;
    /* IL_0010: conv.i8                         : Timer.cs(20) */
    stack2_1__ = (int64_t)stack2_0__;
    /* IL_0011: div                             : Timer.cs(20) */
    stack1_0__ = stack1_0__ / stack2_1__;
    /* IL_0012: conv.i4                         : Timer.cs(20) */
    stack1_1__ = (int32_t)stack1_0__;
    /* IL_0013: stfld MT3620Blink.timespec.tv_sec : Timer.cs(20) */
    stack0_0__->tv_sec = stack1_1__;
    /* IL_0018: ldloca.s local3__               : Timer.cs(20) */
    stack0_0__ = &local3__;
    /* IL_001a: ldarg.1                         : Timer.cs(20) */
    stack1_0__ = nsec;
    /* IL_001b: ldc.i4 1000000000               : Timer.cs(20) */
    stack2_0__ = 1000000000;
    /* IL_0020: conv.i8                         : Timer.cs(20) */
    stack2_1__ = (int64_t)stack2_0__;
    /* IL_0021: rem                             : Timer.cs(20) */
    stack1_0__ = stack1_0__ % stack2_1__;
    /* IL_0022: conv.i4                         : Timer.cs(20) */
    stack1_1__ = (int32_t)stack1_0__;
    /* IL_0023: stfld MT3620Blink.timespec.tv_nsec : Timer.cs(20) */
    stack0_0__->tv_nsec = stack1_1__;
    /* IL_0028: ldloc.3                         : Timer.cs(20) */
    stack0_1__ = local3__;
    /* IL_0029: stloc.0                         : Timer.cs(20) */
    tm = stack0_1__;
    /* IL_002a: ldloca.s local4__               : Timer.cs(25) */
    stack0_2__ = &local4__;
    /* IL_002c: initobj MT3620Blink.itimerspec  : Timer.cs(25) */
    memset(stack0_2__, 0x00, sizeof *stack0_2__);
    /* IL_0032: ldloca.s local4__               : Timer.cs(25) */
    stack0_2__ = &local4__;
    /* IL_0034: ldloc.0                         : Timer.cs(25) */
    stack1_2__ = tm;
    /* IL_0035: stfld MT3620Blink.itimerspec.it_value : Timer.cs(25) */
    stack0_2__->it_value = stack1_2__;
    /* IL_003a: ldloca.s local4__               : Timer.cs(25) */
    stack0_2__ = &local4__;
    /* IL_003c: ldloc.0                         : Timer.cs(25) */
    stack1_2__ = tm;
    /* IL_003d: stfld MT3620Blink.itimerspec.it_interval : Timer.cs(25) */
    stack0_2__->it_interval = stack1_2__;
    /* IL_0042: ldloc.s local4__                : Timer.cs(25) */
    stack0_3__ = local4__;
    /* IL_0044: stloc.1                         : Timer.cs(25) */
    newValue = stack0_3__;
    /* IL_0045: ldarg.0                         : Timer.cs(31) */
    frame__.stack0_4__ = this__;
    /* IL_0046: call MT3620Blink.Descriptor.get_Identity : Timer.cs(31) */
    stack0_5__ = MT3620Blink_Descriptor_get_Identity((MT3620Blink_Descriptor*)frame__.stack0_4__);
    /* IL_004b: ldc.i4.0                        : Timer.cs(31) */
    stack1_1__ = 0;
    /* IL_004c: ldloca.s newValue               : Timer.cs(31) */
    stack2_2__ = &newValue;
    /* IL_004e: ldloca.s dummy                  : Timer.cs(31) */
    stack3_0__ = &dummy;
    /* IL_0050: call MT3620Blink.Interops.timerfd_settime : Timer.cs(31) */
    stack0_5__ = MT3620Blink_Interops_timerfd_settime(stack0_5__, stack1_1__, stack2_2__, stack3_0__);
    /* IL_0055: pop                             : Timer.cs(31) */
    /* IL_0056: ret  */
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

    /* IL_0000: ldarg.0                         : Timer.cs(38) */
    frame__.stack0_0__ = this__;
    /* IL_0001: call MT3620Blink.Descriptor.get_Identity : Timer.cs(38) */
    stack0_1__ = MT3620Blink_Descriptor_get_Identity((MT3620Blink_Descriptor*)frame__.stack0_0__);
    /* IL_0006: ldloca.s timerData              : Timer.cs(38) */
    stack1_0__ = &timerData;
    /* IL_0008: ldc.i4.8                        : Timer.cs(38) */
    stack2_0__ = 8;
    /* IL_0009: conv.i8                         : Timer.cs(38) */
    stack2_1__ = (int64_t)stack2_0__;
    /* IL_000a: call System.UIntPtr.op_Explicit : Timer.cs(38) */
    stack2_2__ = System_UIntPtr_op_Explicit_2((uint64_t)stack2_1__);
    /* IL_000f: call MT3620Blink.Interops.timerfd_read : Timer.cs(38) */
    stack0_1__ = MT3620Blink_Interops_timerfd_read(stack0_1__, stack1_0__, stack2_2__);
    /* IL_0014: pop                             : Timer.cs(38) */
    /* IL_0015: ldarg.0  */
    frame__.stack0_0__ = this__;
    /* IL_0016: callvirt MT3620Blink.Timer.Raised : Timer.cs(39) */
    frame__.stack0_0__->vptr0__->Raised(frame__.stack0_0__);
    /* IL_001b: ret                             : Timer.cs(40) */
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
