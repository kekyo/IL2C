// [15-2] This is MT3620Blink native code translated by IL2C, do not edit.

#include <MT3620Blink.h>
#include <MT3620Blink_internal.h>

#include <mscorlib.h>

#ifdef __cplusplus
extern "C" {
#endif

//////////////////////////////////////////////////////////////////////////////////
// [9-1] Type: MT3620Blink.Application

//////////////////////////////////////////////////////////////////////////////////
// [9-2] File scope prototypes:

//////////////////////////////////////////////////////////////////////////////////
// [9-4] Type: MT3620Blink.Application

///////////////////////////////////////
// [3] MT3620Blink.Application..ctor(MT3620Blink.Application this__)

//-------------------
// [3-7] Declare execution frame:

typedef struct MT3620Blink_Application__ctor_EXECUTION_FRAME_DECL
{
    const IL2C_EXECUTION_FRAME* pNext__;
    const uint16_t objRefCount__;
    const uint16_t valueCount__;
    //-------------------- objref
    MT3620Blink_Application* stack0_0__;
    MT3620Blink_Application* stack1_1__;
    MT3620Blink_Application_AbortEvent* stack1_2__;
} MT3620Blink_Application__ctor_EXECUTION_FRAME__;

//-------------------
// [3-2] Function body:

void MT3620Blink_Application__ctor(MT3620Blink_Application* this__)
{
    il2c_assert(this__ != NULL);

    //-------------------
    // [3-4] Evaluation stacks (!objref):

    int32_t stack1_0__;

    //-------------------
    // [3-5] Setup execution frame:

    MT3620Blink_Application__ctor_EXECUTION_FRAME__ frame__ =
        { NULL, 3 };
    il2c_link_execution_frame(&frame__);

    //-------------------
    // [3-6] IL body:

    /* IL_0000: ldarg.0                         : Application.cs(28) */
    frame__.stack0_0__ = this__;
    /* IL_0001: ldc.i4.0                        : Application.cs(28) */
    stack1_0__ = 0;
    /* IL_0002: call MT3620Blink.Interops.epoll_create1 : Application.cs(28) */
    stack1_0__ = MT3620Blink_Interops_epoll_create1(stack1_0__);
    /* IL_0007: call MT3620Blink.Descriptor..ctor : Application.cs(28) */
    MT3620Blink_Descriptor__ctor((MT3620Blink_Descriptor*)frame__.stack0_0__, stack1_0__);
    /* IL_000c: ldarg.0                         : Application.cs(30) */
    frame__.stack0_0__ = this__;
    /* IL_000d: ldarg.0                         : Application.cs(30) */
    frame__.stack1_1__ = this__;
    /* IL_000e: newobj MT3620Blink.Application.AbortEvent..ctor : Application.cs(30) */
    frame__.stack1_2__ = il2c_get_uninitialized_object(MT3620Blink_Application_AbortEvent);
    MT3620Blink_Application_AbortEvent__ctor(frame__.stack1_2__, frame__.stack1_1__);
    /* IL_0013: stfld MT3620Blink.Application.abort : Application.cs(30) */
    frame__.stack0_0__->abort = frame__.stack1_2__;
    /* IL_0018: ldarg.0                         : Application.cs(31) */
    frame__.stack0_0__ = this__;
    /* IL_0019: ldarg.0                         : Application.cs(31) */
    frame__.stack1_1__ = this__;
    /* IL_001a: ldfld MT3620Blink.Application.abort : Application.cs(31) */
    frame__.stack1_2__ = frame__.stack1_1__->abort;
    /* IL_001f: call MT3620Blink.Application.RegisterDescriptor : Application.cs(31) */
    MT3620Blink_Application_RegisterDescriptor(frame__.stack0_0__, il2c_cast_to_interface(MT3620Blink_IEPollListener, MT3620Blink_Application_AbortEvent, frame__.stack1_2__));
    /* IL_0024: ret                             : Application.cs(32) */
    il2c_unlink_execution_frame(&frame__);
    return;
}

///////////////////////////////////////
// [3] Virtual: MT3620Blink.Application.Dispose(MT3620Blink.Application this__)

//-------------------
// [3-7] Declare execution frame:

typedef struct MT3620Blink_Application_Dispose_EXECUTION_FRAME_DECL
{
    const IL2C_EXECUTION_FRAME* pNext__;
    const uint16_t objRefCount__;
    const uint16_t valueCount__;
    //-------------------- objref
    MT3620Blink_Application* stack0_0__;
    MT3620Blink_Application_AbortEvent* stack0_1__;
} MT3620Blink_Application_Dispose_EXECUTION_FRAME__;

//-------------------
// [3-2] Function body:

void MT3620Blink_Application_Dispose(MT3620Blink_Application* this__)
{
    il2c_assert(this__ != NULL);

    //-------------------
    // [3-4] Evaluation stacks (!objref):

    untyped_ptr stack1_0__;

    //-------------------
    // [3-5] Setup execution frame:

    MT3620Blink_Application_Dispose_EXECUTION_FRAME__ frame__ =
        { NULL, 2 };
    il2c_link_execution_frame(&frame__);

    //-------------------
    // [3-6] IL body:

    /* IL_0000: ldarg.0                         : Application.cs(36) */
    frame__.stack0_0__ = this__;
    /* IL_0001: call MT3620Blink.Descriptor.Dispose : Application.cs(36) */
    MT3620Blink_Descriptor_Dispose((MT3620Blink_Descriptor*)frame__.stack0_0__);
    /* IL_0006: ldarg.0                         : Application.cs(38) */
    frame__.stack0_0__ = this__;
    /* IL_0007: ldfld MT3620Blink.Application.abort : Application.cs(38) */
    frame__.stack0_1__ = frame__.stack0_0__->abort;
    /* IL_000c: brfalse.s IL_0020               : Application.cs(38) */
    if (frame__.stack0_1__ == NULL) goto IL_0020;
    /* IL_000e: ldarg.0                         : Application.cs(40) */
    frame__.stack0_0__ = this__;
    /* IL_000f: ldfld MT3620Blink.Application.abort : Application.cs(40) */
    frame__.stack0_1__ = frame__.stack0_0__->abort;
    /* IL_0014: callvirt MT3620Blink.Descriptor.Dispose : Application.cs(40) */
    frame__.stack0_1__->vptr0__->Dispose((MT3620Blink_Descriptor*)frame__.stack0_1__);
    /* IL_0019: ldarg.0                         : Application.cs(41) */
    frame__.stack0_0__ = this__;
    /* IL_001a: ldnull                          : Application.cs(41) */
    stack1_0__ = NULL;
    /* IL_001b: stfld MT3620Blink.Application.abort : Application.cs(41) */
    frame__.stack0_0__->abort = (MT3620Blink_Application_AbortEvent*)stack1_0__;
IL_0020:
    /* IL_0020: ret                             : Application.cs(43) */
    il2c_unlink_execution_frame(&frame__);
    return;
}

///////////////////////////////////////
// [3] MT3620Blink.Application.RegisterDescriptor(MT3620Blink.Application this__, MT3620Blink.IEPollListener target)

//-------------------
// [3-7] Declare execution frame:

typedef struct MT3620Blink_Application_RegisterDescriptor_EXECUTION_FRAME_DECL
{
    const IL2C_EXECUTION_FRAME* pNext__;
    const uint16_t objRefCount__;
    const uint16_t valueCount__;
    //-------------------- objref
    MT3620Blink_IEPollListener* stack0_0__;
    MT3620Blink_Application* stack0_4__;
    MT3620Blink_IEPollListener* stack2_3__;
} MT3620Blink_Application_RegisterDescriptor_EXECUTION_FRAME__;

//-------------------
// [3-2] Function body:

void MT3620Blink_Application_RegisterDescriptor(MT3620Blink_Application* this__, MT3620Blink_IEPollListener* target)
{
    il2c_assert(this__ != NULL);

    //-------------------
    // [3-3] Local variables (!objref):

    System_Runtime_InteropServices_GCHandle handle;
    memset(&handle, 0x00, sizeof handle);
    MT3620Blink_epoll_event ev;
    memset(&ev, 0x00, sizeof ev);
    MT3620Blink_epoll_event local2__;
    memset(&local2__, 0x00, sizeof local2__);
    MT3620Blink_epoll_data_t local3__;
    memset(&local3__, 0x00, sizeof local3__);

    //-------------------
    // [3-4] Evaluation stacks (!objref):

    System_Runtime_InteropServices_GCHandle stack0_1__;
    MT3620Blink_epoll_event* stack0_2__;
    MT3620Blink_epoll_event stack0_3__;
    int32_t stack0_5__;
    int32_t stack1_0__;
    uint32_t stack1_1__;
    MT3620Blink_epoll_data_t* stack1_2__;
    MT3620Blink_epoll_data_t stack1_3__;
    System_Runtime_InteropServices_GCHandle stack2_0__;
    intptr_t stack2_1__;
    System_Runtime_InteropServices_NativePointer stack2_2__;
    int32_t stack2_4__;
    MT3620Blink_epoll_event* stack3_0__;

    //-------------------
    // [3-5] Setup execution frame:

    MT3620Blink_Application_RegisterDescriptor_EXECUTION_FRAME__ frame__ =
        { NULL, 3 };
    il2c_link_execution_frame(&frame__);

    //-------------------
    // [3-6] IL body:

    /* IL_0000: ldarg.1                         : Application.cs(47) */
    frame__.stack0_0__ = target;
    /* IL_0001: ldc.i4.3                        : Application.cs(47) */
    stack1_0__ = 3;
    /* IL_0002: call System.Runtime.InteropServices.GCHandle.Alloc : Application.cs(47) */
    stack0_1__ = System_Runtime_InteropServices_GCHandle_Alloc_1(il2c_adjusted_reference(frame__.stack0_0__), (System_Runtime_InteropServices_GCHandleType)stack1_0__);
    /* IL_0007: stloc.0                         : Application.cs(47) */
    handle = stack0_1__;
    /* IL_0008: ldloca.s local2__               : Application.cs(49) */
    stack0_2__ = &local2__;
    /* IL_000a: initobj MT3620Blink.epoll_event : Application.cs(49) */
    memset(stack0_2__, 0x00, sizeof *stack0_2__);
    /* IL_0010: ldloca.s local2__               : Application.cs(49) */
    stack0_2__ = &local2__;
    /* IL_0012: ldsfld MT3620Blink.Interops.EPOLLIN : Application.cs(49) */
    stack1_1__ = MT3620Blink_Interops_EPOLLIN;
    /* IL_0017: stfld MT3620Blink.epoll_event.events : Application.cs(49) */
    stack0_2__->events = stack1_1__;
    /* IL_001c: ldloca.s local2__               : Application.cs(49) */
    stack0_2__ = &local2__;
    /* IL_001e: ldloca.s local3__               : Application.cs(49) */
    stack1_2__ = &local3__;
    /* IL_0020: initobj MT3620Blink.epoll_data_t : Application.cs(49) */
    memset(stack1_2__, 0x00, sizeof *stack1_2__);
    /* IL_0026: ldloca.s local3__               : Application.cs(49) */
    stack1_2__ = &local3__;
    /* IL_0028: ldloc.0                         : Application.cs(49) */
    stack2_0__ = handle;
    /* IL_0029: call System.Runtime.InteropServices.GCHandle.ToIntPtr : Application.cs(49) */
    stack2_1__ = System_Runtime_InteropServices_GCHandle_ToIntPtr(stack2_0__);
    /* IL_002e: call System.Runtime.InteropServices.NativePointer.op_Implicit : Application.cs(49) */
    stack2_2__ = System_Runtime_InteropServices_NativePointer_op_Implicit(stack2_1__);
    /* IL_0033: stfld MT3620Blink.epoll_data_t.ptr : Application.cs(49) */
    stack1_2__->ptr = stack2_2__;
    /* IL_0038: ldloc.3                         : Application.cs(49) */
    stack1_3__ = local3__;
    /* IL_0039: stfld MT3620Blink.epoll_event.data : Application.cs(49) */
    stack0_2__->data = stack1_3__;
    /* IL_003e: ldloc.2                         : Application.cs(49) */
    stack0_3__ = local2__;
    /* IL_003f: stloc.1                         : Application.cs(49) */
    ev = stack0_3__;
    /* IL_0040: ldarg.0                         : Application.cs(54) */
    frame__.stack0_4__ = this__;
    /* IL_0041: call MT3620Blink.Descriptor.get_Identity : Application.cs(54) */
    stack0_5__ = MT3620Blink_Descriptor_get_Identity((MT3620Blink_Descriptor*)frame__.stack0_4__);
    /* IL_0046: ldsfld MT3620Blink.Interops.EPOLL_CTL_ADD : Application.cs(54) */
    stack1_0__ = MT3620Blink_Interops_EPOLL_CTL_ADD;
    /* IL_004b: ldarg.1                         : Application.cs(54) */
    frame__.stack2_3__ = target;
    /* IL_004c: callvirt MT3620Blink.IEPollListener.get_Identity : Application.cs(54) */
    stack2_4__ = frame__.stack2_3__->vptr0__->get_Identity(il2c_adjusted_reference(frame__.stack2_3__));
    /* IL_0051: ldloca.s ev                     : Application.cs(54) */
    stack3_0__ = &ev;
    /* IL_0053: call MT3620Blink.Interops.epoll_ctl : Application.cs(54) */
    stack0_5__ = MT3620Blink_Interops_epoll_ctl(stack0_5__, stack1_0__, stack2_4__, stack3_0__);
    /* IL_0058: pop                             : Application.cs(54) */
    /* IL_0059: ret  */
    il2c_unlink_execution_frame(&frame__);
    return;
}

///////////////////////////////////////
// [3] MT3620Blink.Application.UnregisterDescriptor(MT3620Blink.Application this__, MT3620Blink.IEPollListener target)

//-------------------
// [3-7] Declare execution frame:

typedef struct MT3620Blink_Application_UnregisterDescriptor_EXECUTION_FRAME_DECL
{
    const IL2C_EXECUTION_FRAME* pNext__;
    const uint16_t objRefCount__;
    const uint16_t valueCount__;
    //-------------------- objref
    MT3620Blink_IEPollListener* stack0_0__;
    MT3620Blink_Application* stack0_4__;
    MT3620Blink_IEPollListener* stack2_0__;
} MT3620Blink_Application_UnregisterDescriptor_EXECUTION_FRAME__;

//-------------------
// [3-2] Function body:

void MT3620Blink_Application_UnregisterDescriptor(MT3620Blink_Application* this__, MT3620Blink_IEPollListener* target)
{
    il2c_assert(this__ != NULL);

    //-------------------
    // [3-3] Local variables (!objref):

    System_Runtime_InteropServices_GCHandle handle;
    memset(&handle, 0x00, sizeof handle);
    MT3620Blink_epoll_event ev;
    memset(&ev, 0x00, sizeof ev);

    //-------------------
    // [3-4] Evaluation stacks (!objref):

    System_Runtime_InteropServices_GCHandle stack0_1__;
    System_Runtime_InteropServices_GCHandle* stack0_2__;
    MT3620Blink_epoll_event* stack0_3__;
    int32_t stack0_5__;
    int32_t stack1_0__;
    int32_t stack2_1__;
    MT3620Blink_epoll_event* stack3_0__;

    //-------------------
    // [3-5] Setup execution frame:

    MT3620Blink_Application_UnregisterDescriptor_EXECUTION_FRAME__ frame__ =
        { NULL, 3 };
    il2c_link_execution_frame(&frame__);

    //-------------------
    // [3-6] IL body:

    /* IL_0000: ldarg.1                         : Application.cs(63) */
    frame__.stack0_0__ = target;
    /* IL_0001: ldc.i4.3                        : Application.cs(63) */
    stack1_0__ = 3;
    /* IL_0002: call System.Runtime.InteropServices.GCHandle.Alloc : Application.cs(63) */
    stack0_1__ = System_Runtime_InteropServices_GCHandle_Alloc_1(il2c_adjusted_reference(frame__.stack0_0__), (System_Runtime_InteropServices_GCHandleType)stack1_0__);
    /* IL_0007: stloc.0                         : Application.cs(63) */
    handle = stack0_1__;
    /* IL_0008: ldloca.s handle                 : Application.cs(64) */
    stack0_2__ = &handle;
    /* IL_000a: call System.Runtime.InteropServices.GCHandle.Free : Application.cs(64) */
    System_Runtime_InteropServices_GCHandle_Free(stack0_2__);
    /* IL_000f: ldloca.s ev                     : Application.cs(66) */
    stack0_3__ = &ev;
    /* IL_0011: initobj MT3620Blink.epoll_event : Application.cs(66) */
    memset(stack0_3__, 0x00, sizeof *stack0_3__);
    /* IL_0017: ldarg.0                         : Application.cs(68) */
    frame__.stack0_4__ = this__;
    /* IL_0018: call MT3620Blink.Descriptor.get_Identity : Application.cs(68) */
    stack0_5__ = MT3620Blink_Descriptor_get_Identity((MT3620Blink_Descriptor*)frame__.stack0_4__);
    /* IL_001d: ldsfld MT3620Blink.Interops.EPOLL_CTL_DEL : Application.cs(68) */
    stack1_0__ = MT3620Blink_Interops_EPOLL_CTL_DEL;
    /* IL_0022: ldarg.1                         : Application.cs(68) */
    frame__.stack2_0__ = target;
    /* IL_0023: callvirt MT3620Blink.IEPollListener.get_Identity : Application.cs(68) */
    stack2_1__ = frame__.stack2_0__->vptr0__->get_Identity(il2c_adjusted_reference(frame__.stack2_0__));
    /* IL_0028: ldloca.s ev                     : Application.cs(68) */
    stack3_0__ = &ev;
    /* IL_002a: call MT3620Blink.Interops.epoll_ctl : Application.cs(68) */
    stack0_5__ = MT3620Blink_Interops_epoll_ctl(stack0_5__, stack1_0__, stack2_1__, stack3_0__);
    /* IL_002f: pop                             : Application.cs(68) */
    /* IL_0030: ret  */
    il2c_unlink_execution_frame(&frame__);
    return;
}

///////////////////////////////////////
// [3] MT3620Blink.Application.Abort(MT3620Blink.Application this__)

//-------------------
// [3-7] Declare execution frame:

typedef struct MT3620Blink_Application_Abort_EXECUTION_FRAME_DECL
{
    const IL2C_EXECUTION_FRAME* pNext__;
    const uint16_t objRefCount__;
    const uint16_t valueCount__;
    //-------------------- objref
    MT3620Blink_Application* stack0_0__;
    MT3620Blink_Application_AbortEvent* stack0_1__;
} MT3620Blink_Application_Abort_EXECUTION_FRAME__;

//-------------------
// [3-2] Function body:

void MT3620Blink_Application_Abort(MT3620Blink_Application* this__)
{
    il2c_assert(this__ != NULL);

    //-------------------
    // [3-5] Setup execution frame:

    MT3620Blink_Application_Abort_EXECUTION_FRAME__ frame__ =
        { NULL, 2 };
    il2c_link_execution_frame(&frame__);

    //-------------------
    // [3-6] IL body:

    /* IL_0000: ldarg.0                         : Application.cs(76) */
    frame__.stack0_0__ = this__;
    /* IL_0001: ldfld MT3620Blink.Application.abort : Application.cs(76) */
    frame__.stack0_1__ = frame__.stack0_0__->abort;
    /* IL_0006: callvirt MT3620Blink.Event.Pulse : Application.cs(76) */
    MT3620Blink_Event_Pulse((MT3620Blink_Event*)frame__.stack0_1__);
    /* IL_000b: ret                             : Application.cs(76) */
    il2c_unlink_execution_frame(&frame__);
    return;
}

///////////////////////////////////////
// [3] MT3620Blink.Application.Run(MT3620Blink.Application this__)

//-------------------
// [3-7] Declare execution frame:

typedef struct MT3620Blink_Application_Run_EXECUTION_FRAME_DECL
{
    const IL2C_EXECUTION_FRAME* pNext__;
    const uint16_t objRefCount__;
    const uint16_t valueCount__;
    //-------------------- objref
    MT3620Blink_IEPollListener* target;
    MT3620Blink_Application* stack0_0__;
    System_Object* stack0_10__;
    MT3620Blink_IEPollListener* stack0_11__;
} MT3620Blink_Application_Run_EXECUTION_FRAME__;

//-------------------
// [3-2] Function body:

void MT3620Blink_Application_Run(MT3620Blink_Application* this__)
{
    il2c_assert(this__ != NULL);

    //-------------------
    // [3-3] Local variables (!objref):

    MT3620Blink_epoll_event ev;
    memset(&ev, 0x00, sizeof ev);
    int32_t numEventsOccurred = 0;
    System_Runtime_InteropServices_GCHandle handle;
    memset(&handle, 0x00, sizeof handle);

    //-------------------
    // [3-4] Evaluation stacks (!objref):

    bool stack0_1__;
    MT3620Blink_epoll_event* stack0_2__;
    int32_t stack0_3__;
    MT3620Blink_epoll_event stack0_4__;
    MT3620Blink_epoll_data_t stack0_5__;
    System_Runtime_InteropServices_NativePointer stack0_6__;
    intptr_t stack0_7__;
    System_Runtime_InteropServices_GCHandle stack0_8__;
    System_Runtime_InteropServices_GCHandle* stack0_9__;
    MT3620Blink_epoll_event* stack1_0__;
    int32_t stack1_1__;
    int32_t stack2_0__;
    int32_t stack3_0__;

    //-------------------
    // [3-5] Setup execution frame:

    MT3620Blink_Application_Run_EXECUTION_FRAME__ frame__ =
        { NULL, 4 };
    il2c_link_execution_frame(&frame__);

    //-------------------
    // [3-6] IL body:

    /* IL_0000: br.s IL_004b */
    goto IL_004b;
IL_0002:
    /* IL_0002: ldloca.s ev                     : Application.cs(82) */
    stack0_2__ = &ev;
    /* IL_0004: initobj MT3620Blink.epoll_event : Application.cs(82) */
    memset(stack0_2__, 0x00, sizeof *stack0_2__);
    /* IL_000a: ldarg.0                         : Application.cs(83) */
    frame__.stack0_0__ = this__;
    /* IL_000b: call MT3620Blink.Descriptor.get_Identity : Application.cs(83) */
    stack0_3__ = MT3620Blink_Descriptor_get_Identity((MT3620Blink_Descriptor*)frame__.stack0_0__);
    /* IL_0010: ldloca.s ev                     : Application.cs(83) */
    stack1_0__ = &ev;
    /* IL_0012: ldc.i4.1                        : Application.cs(83) */
    stack2_0__ = 1;
    /* IL_0013: ldc.i4.m1                       : Application.cs(83) */
    stack3_0__ = -1;
    /* IL_0014: call MT3620Blink.Interops.epoll_wait : Application.cs(83) */
    stack0_3__ = MT3620Blink_Interops_epoll_wait(stack0_3__, stack1_0__, stack2_0__, stack3_0__);
    /* IL_0019: stloc.1                         : Application.cs(83) */
    numEventsOccurred = stack0_3__;
    /* IL_001a: ldloc.1                         : Application.cs(85) */
    stack0_3__ = numEventsOccurred;
    /* IL_001b: ldc.i4.m1                       : Application.cs(85) */
    stack1_1__ = -1;
    /* IL_001c: beq.s IL_0053                   : Application.cs(85) */
    if (stack0_3__ == stack1_1__) goto IL_0053;
    /* IL_001e: ldloc.1                         : Application.cs(89) */
    stack0_3__ = numEventsOccurred;
    /* IL_001f: ldc.i4.1                        : Application.cs(89) */
    stack1_1__ = 1;
    /* IL_0020: bne.un.s IL_004b                : Application.cs(89) */
    if (stack0_3__ != stack1_1__) goto IL_004b;
    /* IL_0022: ldloc.0                         : Application.cs(91) */
    stack0_4__ = ev;
    /* IL_0023: ldfld MT3620Blink.epoll_event.data : Application.cs(91) */
    stack0_5__ = stack0_4__.data;
    /* IL_0028: ldfld MT3620Blink.epoll_data_t.ptr : Application.cs(91) */
    stack0_6__ = stack0_5__.ptr;
    /* IL_002d: call System.Runtime.InteropServices.NativePointer.op_Implicit : Application.cs(91) */
    stack0_7__ = System_Runtime_InteropServices_NativePointer_op_Implicit_1(stack0_6__);
    /* IL_0032: call System.Runtime.InteropServices.GCHandle.FromIntPtr : Application.cs(91) */
    stack0_8__ = System_Runtime_InteropServices_GCHandle_FromIntPtr(stack0_7__);
    /* IL_0037: stloc.2                         : Application.cs(91) */
    handle = stack0_8__;
    /* IL_0038: ldloca.s handle                 : Application.cs(92) */
    stack0_9__ = &handle;
    /* IL_003a: call System.Runtime.InteropServices.GCHandle.get_Target : Application.cs(92) */
    frame__.stack0_10__ = System_Runtime_InteropServices_GCHandle_get_Target(stack0_9__);
    /* IL_003f: castclass MT3620Blink.IEPollListener : Application.cs(92) */
    frame__.stack0_11__ = il2c_castclass(frame__.stack0_10__, MT3620Blink_IEPollListener);
    /* IL_0044: stloc.3                         : Application.cs(92) */
    frame__.target = frame__.stack0_11__;
    /* IL_0045: ldloc.3                         : Application.cs(93) */
    frame__.stack0_11__ = frame__.target;
    /* IL_0046: callvirt MT3620Blink.IEPollListener.OnRaised : Application.cs(93) */
    frame__.stack0_11__->vptr0__->OnRaised(il2c_adjusted_reference(frame__.stack0_11__));
IL_004b:
    /* IL_004b: ldarg.0                         : Application.cs(80) */
    frame__.stack0_0__ = this__;
    /* IL_004c: ldfld MT3620Blink.Application.abortFlag : Application.cs(80) */
    stack0_1__ = frame__.stack0_0__->abortFlag;
    /* IL_0051: brfalse.s IL_0002               : Application.cs(80) */
    if (stack0_1__ == false) goto IL_0002;
IL_0053:
    /* IL_0053: ret                             : Application.cs(96) */
    il2c_unlink_execution_frame(&frame__);
    return;
}

//////////////////////
// [7] Runtime helpers:

// [7-10-2] VTable
MT3620Blink_Application_VTABLE_DECL__ MT3620Blink_Application_VTABLE__ = {
    0, // Adjustor offset
    (bool (*)(void*, System_Object*))System_Object_Equals,
    (void (*)(void*))System_Object_Finalize,
    (int32_t (*)(void*))System_Object_GetHashCode,
    (System_String* (*)(void*))System_Object_ToString,
    (void (*)(void*))MT3620Blink_Application_Dispose,
};

// [7-13] VTable for System.IDisposable
System_IDisposable_VTABLE_DECL__ MT3620Blink_Application_System_IDisposable_VTABLE__ = {
    il2c_adjustor_offset(MT3620Blink_Application, System_IDisposable),
    (void (*)(void*))MT3620Blink_Application_Dispose,
};

// [7-8] Runtime type information
IL2C_RUNTIME_TYPE_BEGIN(MT3620Blink_Application, "MT3620Blink.Application", IL2C_TYPE_REFERENCE, sizeof(MT3620Blink_Application), MT3620Blink_Descriptor, 1, 1)
    IL2C_RUNTIME_TYPE_MARK_TARGET_FOR_REFERENCE(MT3620Blink_Application, abort)
    IL2C_RUNTIME_TYPE_INTERFACE(MT3620Blink_Application, System_IDisposable)
IL2C_RUNTIME_TYPE_END();

//////////////////////////////////////////////////////////////////////////////////
// [9-1] Type: MT3620Blink.Application

//////////////////////////////////////////////////////////////////////////////////
// [9-2] File scope prototypes:

//////////////////////////////////////////////////////////////////////////////////
// [2-3] Methods: MT3620Blink.Application.AbortEvent

extern /* public sealed */ void MT3620Blink_Application_AbortEvent__ctor(MT3620Blink_Application_AbortEvent* this__, MT3620Blink_Application* parent);
extern /* protected override sealed */ void MT3620Blink_Application_AbortEvent_Received(MT3620Blink_Application_AbortEvent* this__);

//////////////////////////////////////////////////////////////////////////////////
// [9-4] Type: MT3620Blink.Application.AbortEvent

///////////////////////////////////////
// [3] MT3620Blink.Application.AbortEvent..ctor(MT3620Blink.Application.AbortEvent this__, MT3620Blink.Application parent)

//-------------------
// [3-7] Declare execution frame:

typedef struct MT3620Blink_Application_AbortEvent__ctor_EXECUTION_FRAME_DECL
{
    const IL2C_EXECUTION_FRAME* pNext__;
    const uint16_t objRefCount__;
    const uint16_t valueCount__;
    //-------------------- objref
    MT3620Blink_Application_AbortEvent* stack0_0__;
    MT3620Blink_Application* stack1_0__;
} MT3620Blink_Application_AbortEvent__ctor_EXECUTION_FRAME__;

//-------------------
// [3-2] Function body:

void MT3620Blink_Application_AbortEvent__ctor(MT3620Blink_Application_AbortEvent* this__, MT3620Blink_Application* parent)
{
    il2c_assert(this__ != NULL);

    //-------------------
    // [3-5] Setup execution frame:

    MT3620Blink_Application_AbortEvent__ctor_EXECUTION_FRAME__ frame__ =
        { NULL, 2 };
    il2c_link_execution_frame(&frame__);

    //-------------------
    // [3-6] IL body:

    /* IL_0000: ldarg.0                         : Application.cs(17) */
    frame__.stack0_0__ = this__;
    /* IL_0001: call MT3620Blink.Event..ctor    : Application.cs(17) */
    MT3620Blink_Event__ctor((MT3620Blink_Event*)frame__.stack0_0__);
    /* IL_0006: ldarg.0                         : Application.cs(18) */
    frame__.stack0_0__ = this__;
    /* IL_0007: ldarg.1                         : Application.cs(18) */
    frame__.stack1_0__ = parent;
    /* IL_0008: stfld MT3620Blink.Application.AbortEvent.parent : Application.cs(18) */
    frame__.stack0_0__->parent = frame__.stack1_0__;
    /* IL_000d: ret                             : Application.cs(18) */
    il2c_unlink_execution_frame(&frame__);
    return;
}

///////////////////////////////////////
// [3] Virtual: MT3620Blink.Application.AbortEvent.Received(MT3620Blink.Application.AbortEvent this__)

//-------------------
// [3-7] Declare execution frame:

typedef struct MT3620Blink_Application_AbortEvent_Received_EXECUTION_FRAME_DECL
{
    const IL2C_EXECUTION_FRAME* pNext__;
    const uint16_t objRefCount__;
    const uint16_t valueCount__;
    //-------------------- objref
    MT3620Blink_Application_AbortEvent* stack0_0__;
    MT3620Blink_Application* stack0_1__;
} MT3620Blink_Application_AbortEvent_Received_EXECUTION_FRAME__;

//-------------------
// [3-2] Function body:

void MT3620Blink_Application_AbortEvent_Received(MT3620Blink_Application_AbortEvent* this__)
{
    il2c_assert(this__ != NULL);

    //-------------------
    // [3-4] Evaluation stacks (!objref):

    int32_t stack1_0__;

    //-------------------
    // [3-5] Setup execution frame:

    MT3620Blink_Application_AbortEvent_Received_EXECUTION_FRAME__ frame__ =
        { NULL, 2 };
    il2c_link_execution_frame(&frame__);

    //-------------------
    // [3-6] IL body:

    /* IL_0000: ldarg.0                         : Application.cs(21) */
    frame__.stack0_0__ = this__;
    /* IL_0001: ldfld MT3620Blink.Application.AbortEvent.parent : Application.cs(21) */
    frame__.stack0_1__ = frame__.stack0_0__->parent;
    /* IL_0006: ldc.i4.1                        : Application.cs(21) */
    stack1_0__ = 1;
    /* IL_0007: stfld MT3620Blink.Application.abortFlag : Application.cs(21) */
    frame__.stack0_1__->abortFlag = (bool)stack1_0__;
    /* IL_000c: ret                             : Application.cs(21) */
    il2c_unlink_execution_frame(&frame__);
    return;
}

//////////////////////
// [7] Runtime helpers:

// [7-10-2] VTable
MT3620Blink_Application_AbortEvent_VTABLE_DECL__ MT3620Blink_Application_AbortEvent_VTABLE__ = {
    0, // Adjustor offset
    (bool (*)(void*, System_Object*))System_Object_Equals,
    (void (*)(void*))System_Object_Finalize,
    (int32_t (*)(void*))System_Object_GetHashCode,
    (System_String* (*)(void*))System_Object_ToString,
    (void (*)(void*))MT3620Blink_Descriptor_Dispose,
    (void (*)(void*))MT3620Blink_Application_AbortEvent_Received,
};

// [7-13] VTable for System.IDisposable
System_IDisposable_VTABLE_DECL__ MT3620Blink_Application_AbortEvent_System_IDisposable_VTABLE__ = {
    il2c_adjustor_offset(MT3620Blink_Application_AbortEvent, System_IDisposable),
    (void (*)(void*))MT3620Blink_Descriptor_Dispose,
};

// [7-13] VTable for MT3620Blink.IEPollListener
MT3620Blink_IEPollListener_VTABLE_DECL__ MT3620Blink_Application_AbortEvent_MT3620Blink_IEPollListener_VTABLE__ = {
    il2c_adjustor_offset(MT3620Blink_Application_AbortEvent, MT3620Blink_IEPollListener),
    (int32_t (*)(void*))MT3620Blink_Event_MT3620Blink_IEPollListener_get_Identity,
    (void (*)(void*))MT3620Blink_Event_MT3620Blink_IEPollListener_OnRaised,
};

// [7-8] Runtime type information
IL2C_RUNTIME_TYPE_BEGIN(MT3620Blink_Application_AbortEvent, "MT3620Blink.Application.AbortEvent", IL2C_TYPE_REFERENCE, sizeof(MT3620Blink_Application_AbortEvent), MT3620Blink_Event, 1, 2)
    IL2C_RUNTIME_TYPE_MARK_TARGET_FOR_REFERENCE(MT3620Blink_Application_AbortEvent, parent)
    IL2C_RUNTIME_TYPE_INTERFACE(MT3620Blink_Application_AbortEvent, System_IDisposable)
    IL2C_RUNTIME_TYPE_INTERFACE(MT3620Blink_Application_AbortEvent, MT3620Blink_IEPollListener)
IL2C_RUNTIME_TYPE_END();

#ifdef __cplusplus
}
#endif
