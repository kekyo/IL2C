// This is MT3620Blink native code translated by IL2C, do not edit.

#include <MT3620Blink.h>
#include <MT3620Blink_internal.h>

#include <mscorlib.h>

#ifdef __cplusplus
extern "C" {
#endif

//////////////////////////////////////////////////////////////////////////////////
// [9-2] File scope prototypes:

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
#line 14 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Timer.cs"
    il2c_assert(this__ != NULL);

    //-------------------
    // [3-4] Evaluation stacks (!objref):

#line 14 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Timer.cs"
    int32_t stack1_0__;
#line 14 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Timer.cs"
    int32_t stack2_0__;

    //-------------------
    // [3-5] Setup execution frame:

#line 14 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Timer.cs"
    MT3620Blink_Timer__ctor_EXECUTION_FRAME__ frame__ =
        { NULL, 1 };
#line 14 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Timer.cs"
    il2c_link_execution_frame(&frame__);

    //-------------------
    // [3-6] IL body:

    /* IL_0000: ldarg.0  */
#line 14 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Timer.cs"
    frame__.stack0_0__ = this__;
    /* IL_0001: ldsfld MT3620Blink.Timer.CLOCK_MONOTONIC */
#line 14 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Timer.cs"
    stack1_0__ = MT3620Blink_Timer_CLOCK_MONOTONIC;
    /* IL_0006: ldsfld MT3620Blink.Timer.TFD_NONBLOCK */
#line 14 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Timer.cs"
    stack2_0__ = MT3620Blink_Timer_TFD_NONBLOCK;
    /* IL_000b: call MT3620Blink.Interops.timerfd_create */
#line 14 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Timer.cs"
    stack1_0__ = MT3620Blink_Interops_timerfd_create(stack1_0__, stack2_0__);
    /* IL_0010: call MT3620Blink.Descriptor..ctor */
#line 14 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Timer.cs"
    MT3620Blink_Descriptor__ctor((MT3620Blink_Descriptor*)frame__.stack0_0__, stack1_0__);
    /* IL_0015: nop  */
    /* IL_0016: nop  */
    /* IL_0017: ret  */
#line 16 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Timer.cs"
    il2c_unlink_execution_frame(&frame__);
#line 16 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Timer.cs"
    return;
#line 16 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Timer.cs"
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
#line 19 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Timer.cs"
    il2c_assert(this__ != NULL);

    //-------------------
    // [3-3] Local variables (!objref):

#line 19 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Timer.cs"
    MT3620Blink_timespec tm;
#line 19 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Timer.cs"
    il2c_memset(&tm, 0x00, sizeof tm);
#line 19 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Timer.cs"
    MT3620Blink_itimerspec newValue;
#line 19 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Timer.cs"
    il2c_memset(&newValue, 0x00, sizeof newValue);
#line 19 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Timer.cs"
    MT3620Blink_itimerspec dummy;
#line 19 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Timer.cs"
    il2c_memset(&dummy, 0x00, sizeof dummy);
#line 19 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Timer.cs"
    MT3620Blink_timespec local3__;
#line 19 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Timer.cs"
    il2c_memset(&local3__, 0x00, sizeof local3__);
#line 19 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Timer.cs"
    MT3620Blink_itimerspec local4__;
#line 19 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Timer.cs"
    il2c_memset(&local4__, 0x00, sizeof local4__);

    //-------------------
    // [3-4] Evaluation stacks (!objref):

#line 19 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Timer.cs"
    MT3620Blink_timespec* stack0_0__;
#line 19 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Timer.cs"
    MT3620Blink_timespec stack0_1__;
#line 19 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Timer.cs"
    MT3620Blink_itimerspec* stack0_2__;
#line 19 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Timer.cs"
    MT3620Blink_itimerspec stack0_3__;
#line 19 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Timer.cs"
    int32_t stack0_5__;
#line 19 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Timer.cs"
    int64_t stack1_0__;
#line 19 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Timer.cs"
    int32_t stack1_1__;
#line 19 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Timer.cs"
    MT3620Blink_timespec stack1_2__;
#line 19 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Timer.cs"
    int32_t stack2_0__;
#line 19 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Timer.cs"
    int64_t stack2_1__;
#line 19 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Timer.cs"
    MT3620Blink_itimerspec* stack2_2__;
#line 19 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Timer.cs"
    MT3620Blink_itimerspec* stack3_0__;

    //-------------------
    // [3-5] Setup execution frame:

#line 19 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Timer.cs"
    MT3620Blink_Timer_SetInterval_EXECUTION_FRAME__ frame__ =
        { NULL, 1 };
#line 19 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Timer.cs"
    il2c_link_execution_frame(&frame__);

    //-------------------
    // [3-6] IL body:

    /* IL_0000: nop  */
    /* IL_0001: ldloca.s local3__ */
#line 20 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Timer.cs"
    stack0_0__ = &local3__;
    /* IL_0003: initobj MT3620Blink.timespec */
#line 20 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Timer.cs"
    il2c_memset(stack0_0__, 0x00, sizeof *stack0_0__);
    /* IL_0009: ldloca.s local3__ */
#line 20 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Timer.cs"
    stack0_0__ = &local3__;
    /* IL_000b: ldarg.1  */
#line 20 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Timer.cs"
    stack1_0__ = nsec;
    /* IL_000c: ldc.i4 1000000000 */
#line 20 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Timer.cs"
    stack2_0__ = 1000000000;
    /* IL_0011: conv.i8  */
#line 20 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Timer.cs"
    stack2_1__ = (int64_t)stack2_0__;
    /* IL_0012: div  */
#line 20 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Timer.cs"
    stack1_0__ = stack1_0__ / stack2_1__;
    /* IL_0013: conv.i4  */
#line 20 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Timer.cs"
    stack1_1__ = (int32_t)stack1_0__;
    /* IL_0014: stfld MT3620Blink.timespec.tv_sec */
#line 20 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Timer.cs"
    stack0_0__->tv_sec = stack1_1__;
    /* IL_0019: ldloca.s local3__ */
#line 20 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Timer.cs"
    stack0_0__ = &local3__;
    /* IL_001b: ldarg.1  */
#line 20 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Timer.cs"
    stack1_0__ = nsec;
    /* IL_001c: ldc.i4 1000000000 */
#line 20 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Timer.cs"
    stack2_0__ = 1000000000;
    /* IL_0021: conv.i8  */
#line 20 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Timer.cs"
    stack2_1__ = (int64_t)stack2_0__;
    /* IL_0022: rem  */
#line 20 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Timer.cs"
    stack1_0__ = stack1_0__ % stack2_1__;
    /* IL_0023: conv.i4  */
#line 20 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Timer.cs"
    stack1_1__ = (int32_t)stack1_0__;
    /* IL_0024: stfld MT3620Blink.timespec.tv_nsec */
#line 20 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Timer.cs"
    stack0_0__->tv_nsec = stack1_1__;
    /* IL_0029: ldloc.3  */
#line 20 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Timer.cs"
    stack0_1__ = local3__;
    /* IL_002a: stloc.0  */
#line 20 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Timer.cs"
    tm = stack0_1__;
    /* IL_002b: ldloca.s local4__ */
#line 25 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Timer.cs"
    stack0_2__ = &local4__;
    /* IL_002d: initobj MT3620Blink.itimerspec */
#line 25 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Timer.cs"
    il2c_memset(stack0_2__, 0x00, sizeof *stack0_2__);
    /* IL_0033: ldloca.s local4__ */
#line 25 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Timer.cs"
    stack0_2__ = &local4__;
    /* IL_0035: ldloc.0  */
#line 25 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Timer.cs"
    stack1_2__ = tm;
    /* IL_0036: stfld MT3620Blink.itimerspec.it_value */
#line 25 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Timer.cs"
    stack0_2__->it_value = stack1_2__;
    /* IL_003b: ldloca.s local4__ */
#line 25 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Timer.cs"
    stack0_2__ = &local4__;
    /* IL_003d: ldloc.0  */
#line 25 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Timer.cs"
    stack1_2__ = tm;
    /* IL_003e: stfld MT3620Blink.itimerspec.it_interval */
#line 25 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Timer.cs"
    stack0_2__->it_interval = stack1_2__;
    /* IL_0043: ldloc.s local4__ */
#line 25 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Timer.cs"
    stack0_3__ = local4__;
    /* IL_0045: stloc.1  */
#line 25 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Timer.cs"
    newValue = stack0_3__;
    /* IL_0046: ldarg.0  */
#line 31 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Timer.cs"
    frame__.stack0_4__ = this__;
    /* IL_0047: call MT3620Blink.Descriptor.get_Identity */
#line 31 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Timer.cs"
    stack0_5__ = MT3620Blink_Descriptor_get_Identity((MT3620Blink_Descriptor*)frame__.stack0_4__);
    /* IL_004c: ldc.i4.0  */
#line 31 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Timer.cs"
    stack1_1__ = 0;
    /* IL_004d: ldloca.s newValue */
#line 31 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Timer.cs"
    stack2_2__ = &newValue;
    /* IL_004f: ldloca.s dummy */
#line 31 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Timer.cs"
    stack3_0__ = &dummy;
    /* IL_0051: call MT3620Blink.Interops.timerfd_settime */
#line 31 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Timer.cs"
    stack0_5__ = MT3620Blink_Interops_timerfd_settime(stack0_5__, stack1_1__, stack2_2__, stack3_0__);
    /* IL_0056: pop  */
    /* IL_0057: ret  */
#line 32 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Timer.cs"
    il2c_unlink_execution_frame(&frame__);
#line 32 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Timer.cs"
    return;
#line 32 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Timer.cs"
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
#line 34 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Timer.cs"
    il2c_assert(this__ != NULL);

    //-------------------
    // [3-4] Evaluation stacks (!objref):

#line 34 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Timer.cs"
    int32_t stack0_1__;

    //-------------------
    // [3-5] Setup execution frame:

#line 34 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Timer.cs"
    MT3620Blink_Timer_MT3620Blink_IEPollListener_get_Identity_EXECUTION_FRAME__ frame__ =
        { NULL, 1 };
#line 34 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Timer.cs"
    il2c_link_execution_frame(&frame__);

    //-------------------
    // [3-6] IL body:

    /* IL_0000: ldarg.0  */
#line 34 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Timer.cs"
    frame__.stack0_0__ = this__;
    /* IL_0001: call MT3620Blink.Descriptor.get_Identity */
#line 34 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Timer.cs"
    stack0_1__ = MT3620Blink_Descriptor_get_Identity((MT3620Blink_Descriptor*)frame__.stack0_0__);
    /* IL_0006: ret  */
#line 34 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Timer.cs"
    il2c_unlink_execution_frame(&frame__);
#line 34 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Timer.cs"
    return stack0_1__;
#line 34 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Timer.cs"
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
#line 37 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Timer.cs"
    il2c_assert(this__ != NULL);

    //-------------------
    // [3-3] Local variables (!objref):

#line 37 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Timer.cs"
    uint64_t timerData = 0ULL;

    //-------------------
    // [3-4] Evaluation stacks (!objref):

#line 37 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Timer.cs"
    int32_t stack0_1__;
#line 37 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Timer.cs"
    uint64_t* stack1_0__;
#line 37 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Timer.cs"
    int32_t stack2_0__;
#line 37 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Timer.cs"
    int64_t stack2_1__;
#line 37 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Timer.cs"
    uintptr_t stack2_2__;

    //-------------------
    // [3-5] Setup execution frame:

#line 37 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Timer.cs"
    MT3620Blink_Timer_MT3620Blink_IEPollListener_OnRaised_EXECUTION_FRAME__ frame__ =
        { NULL, 1 };
#line 37 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Timer.cs"
    il2c_link_execution_frame(&frame__);

    //-------------------
    // [3-6] IL body:

    /* IL_0000: nop  */
    /* IL_0001: ldarg.0  */
#line 38 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Timer.cs"
    frame__.stack0_0__ = this__;
    /* IL_0002: call MT3620Blink.Descriptor.get_Identity */
#line 38 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Timer.cs"
    stack0_1__ = MT3620Blink_Descriptor_get_Identity((MT3620Blink_Descriptor*)frame__.stack0_0__);
    /* IL_0007: ldloca.s timerData */
#line 38 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Timer.cs"
    stack1_0__ = &timerData;
    /* IL_0009: ldc.i4.8  */
#line 38 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Timer.cs"
    stack2_0__ = 8;
    /* IL_000a: conv.i8  */
#line 38 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Timer.cs"
    stack2_1__ = (int64_t)stack2_0__;
    /* IL_000b: call System.UIntPtr.op_Explicit */
#line 38 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Timer.cs"
    stack2_2__ = System_UIntPtr_op_Explicit_2((uint64_t)stack2_1__);
    /* IL_0010: call MT3620Blink.Interops.timerfd_read */
#line 38 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Timer.cs"
    stack0_1__ = MT3620Blink_Interops_timerfd_read(stack0_1__, stack1_0__, stack2_2__);
    /* IL_0015: pop  */
    /* IL_0016: ldarg.0  */
#line 39 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Timer.cs"
    frame__.stack0_0__ = this__;
    /* IL_0017: callvirt MT3620Blink.Timer.Raised */
#line 39 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Timer.cs"
    frame__.stack0_0__->vptr0__->Raised(il2c_adjusted_reference(frame__.stack0_0__));
    /* IL_001c: nop  */
    /* IL_001d: ret  */
#line 40 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Timer.cs"
    il2c_unlink_execution_frame(&frame__);
#line 40 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Timer.cs"
    return;
#line 40 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Timer.cs"
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
