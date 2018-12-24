#include <mt3620_rdb.h>
#include <sys/epoll.h>
#include <time.h>
#include <unistd.h>
#include <sys/timerfd.h>
#include <applibs/gpio.h>
#include "MT3620Blink.h"

//////////////////////////////////////////////////////////////////////////////////
// [12-1] Declared values:

// .<PrivateImplementationDetails>.E902362F9BEE92BBA97ECE5B88B94AF4A8D3201D
static const int64_t declaredValue0__[] =
    { 125000000LL, 250000000LL, 500000000LL };

//////////////////////////////////////////////////////////////////////////////////
// [9-2] File scope prototypes:

#ifdef __cplusplus
extern "C" {
#endif

//////////////////////////////////////////////////////////////////////////////////
// [2-1] Types:

////////////////////////////////////////////////////////////
// [2-1-1] .NET types:

typedef epoll_data_t MT3620Blink_epoll_data_t;
typedef struct epoll_event MT3620Blink_epoll_event;
typedef GPIO_OutputMode_Type MT3620Blink_GPIO_OutputMode_Type;
typedef struct MT3620Blink_Descriptor MT3620Blink_Descriptor;
typedef struct MT3620Blink_GpioOutput MT3620Blink_GpioOutput;
typedef struct MT3620Blink_Program___c__DisplayClass1_0 MT3620Blink_Program___c__DisplayClass1_0;
typedef struct MT3620Blink_GpioInput MT3620Blink_GpioInput;
typedef System_MulticastDelegate MT3620Blink_DescriptorCallbackDelegate;
typedef struct MT3620Blink_Application MT3620Blink_Application;
typedef struct timespec MT3620Blink_timespec;
typedef struct itimerspec MT3620Blink_itimerspec;
typedef struct MT3620Blink_Timer MT3620Blink_Timer;
typedef struct MT3620Blink_Program___c__DisplayClass1_1 MT3620Blink_Program___c__DisplayClass1_1;
typedef struct MT3620Blink_Program___c__DisplayClass1_2 MT3620Blink_Program___c__DisplayClass1_2;
typedef GPIO_Value_Type MT3620Blink_GPIO_Value_Type;
typedef struct MT3620Blink_Interops MT3620Blink_Interops;

////////////////////////////////////////////////////////////
// [2-1-2] VTable types:

typedef System_ValueType_VTABLE_DECL__ MT3620Blink_epoll_data_t_VTABLE_DECL__;
typedef System_ValueType_VTABLE_DECL__ MT3620Blink_epoll_event_VTABLE_DECL__;
typedef System_Enum_VTABLE_DECL__ MT3620Blink_GPIO_OutputMode_Type_VTABLE_DECL__;
typedef System_Object_VTABLE_DECL__ MT3620Blink_Descriptor_VTABLE_DECL__;
typedef MT3620Blink_Descriptor_VTABLE_DECL__ MT3620Blink_GpioOutput_VTABLE_DECL__;
typedef System_Object_VTABLE_DECL__ MT3620Blink_Program___c__DisplayClass1_0_VTABLE_DECL__;
typedef MT3620Blink_Descriptor_VTABLE_DECL__ MT3620Blink_GpioInput_VTABLE_DECL__;
typedef System_MulticastDelegate_VTABLE_DECL__ MT3620Blink_DescriptorCallbackDelegate_VTABLE_DECL__;
typedef MT3620Blink_Descriptor_VTABLE_DECL__ MT3620Blink_Application_VTABLE_DECL__;
typedef System_ValueType_VTABLE_DECL__ MT3620Blink_timespec_VTABLE_DECL__;
typedef System_ValueType_VTABLE_DECL__ MT3620Blink_itimerspec_VTABLE_DECL__;
typedef MT3620Blink_Descriptor_VTABLE_DECL__ MT3620Blink_Timer_VTABLE_DECL__;
typedef System_Object_VTABLE_DECL__ MT3620Blink_Program___c__DisplayClass1_1_VTABLE_DECL__;
typedef System_Object_VTABLE_DECL__ MT3620Blink_Program___c__DisplayClass1_2_VTABLE_DECL__;
typedef System_Enum_VTABLE_DECL__ MT3620Blink_GPIO_Value_Type_VTABLE_DECL__;
typedef System_Object_VTABLE_DECL__ MT3620Blink_Interops_VTABLE_DECL__;

////////////////////////////////////////////////////////////
// [1] MT3620Blink.epoll_data_t

// [1-5-1] VTable (Same as System.ValueType)
#define MT3620Blink_epoll_data_t_VTABLE__ System_ValueType_VTABLE__

// [1-4] Runtime type information
IL2C_DECLARE_RUNTIME_TYPE(MT3620Blink_epoll_data_t);

////////////////////////////////////////////////////////////
// [1] MT3620Blink.epoll_event

// [1-5-1] VTable (Same as System.ValueType)
#define MT3620Blink_epoll_event_VTABLE__ System_ValueType_VTABLE__

// [1-4] Runtime type information
IL2C_DECLARE_RUNTIME_TYPE(MT3620Blink_epoll_event);

////////////////////////////////////////////////////////////
// [1] MT3620Blink.GPIO_OutputMode_Type

// [1-5-1] VTable (Same as System.Enum)
#define MT3620Blink_GPIO_OutputMode_Type_VTABLE__ System_Enum_VTABLE__

// [1-4] Runtime type information
IL2C_DECLARE_RUNTIME_TYPE(MT3620Blink_GPIO_OutputMode_Type);

////////////////////////////////////////////////////////////
// [1] MT3620Blink.Descriptor

// [1-1-2] Class layout
struct MT3620Blink_Descriptor
{
    MT3620Blink_Descriptor_VTABLE_DECL__* vptr0__;
    System_IDisposable_VTABLE_DECL__* vptr_System_IDisposable__;
    int32_t _Identity_k__BackingField;
};

// [1-5-1] VTable (Same as System.Object)
#define MT3620Blink_Descriptor_VTABLE__ System_Object_VTABLE__

// [1-4] Runtime type information
IL2C_DECLARE_RUNTIME_TYPE(MT3620Blink_Descriptor);

////////////////////////////////////////////////////////////
// [1] MT3620Blink.GpioOutput

// [1-1-2] Class layout
struct MT3620Blink_GpioOutput
{
    MT3620Blink_GpioOutput_VTABLE_DECL__* vptr0__;
    System_IDisposable_VTABLE_DECL__* vptr_System_IDisposable__;
    int32_t baseField1__;
};

// [1-5-1] VTable (Same as MT3620Blink.Descriptor)
#define MT3620Blink_GpioOutput_VTABLE__ MT3620Blink_Descriptor_VTABLE__

// [1-4] Runtime type information
IL2C_DECLARE_RUNTIME_TYPE(MT3620Blink_GpioOutput);

////////////////////////////////////////////////////////////
// [1] MT3620Blink.Program.<>c__DisplayClass1_0

// [1-1-2] Class layout
struct MT3620Blink_Program___c__DisplayClass1_0
{
    MT3620Blink_Program___c__DisplayClass1_0_VTABLE_DECL__* vptr0__;
    MT3620Blink_GpioOutput* led;
};

// [1-5-1] VTable (Same as System.Object)
#define MT3620Blink_Program___c__DisplayClass1_0_VTABLE__ System_Object_VTABLE__

// [1-4] Runtime type information
IL2C_DECLARE_RUNTIME_TYPE(MT3620Blink_Program___c__DisplayClass1_0);

////////////////////////////////////////////////////////////
// [1] MT3620Blink.GpioInput

// [1-1-2] Class layout
struct MT3620Blink_GpioInput
{
    MT3620Blink_GpioInput_VTABLE_DECL__* vptr0__;
    System_IDisposable_VTABLE_DECL__* vptr_System_IDisposable__;
    int32_t baseField1__;
};

// [1-5-1] VTable (Same as MT3620Blink.Descriptor)
#define MT3620Blink_GpioInput_VTABLE__ MT3620Blink_Descriptor_VTABLE__

// [1-4] Runtime type information
IL2C_DECLARE_RUNTIME_TYPE(MT3620Blink_GpioInput);

////////////////////////////////////////////////////////////
// [1] MT3620Blink.DescriptorCallbackDelegate

// [1-5-1] VTable (Same as System.MulticastDelegate)
#define MT3620Blink_DescriptorCallbackDelegate_VTABLE__ System_MulticastDelegate_VTABLE__

// [1-4] Runtime type information
IL2C_DECLARE_RUNTIME_TYPE(MT3620Blink_DescriptorCallbackDelegate);

////////////////////////////////////////////////////////////
// [1] MT3620Blink.Application

// [1-1-2] Class layout
struct MT3620Blink_Application
{
    MT3620Blink_Application_VTABLE_DECL__* vptr0__;
    System_IDisposable_VTABLE_DECL__* vptr_System_IDisposable__;
    int32_t baseField1__;
};

// [1-5-1] VTable (Same as MT3620Blink.Descriptor)
#define MT3620Blink_Application_VTABLE__ MT3620Blink_Descriptor_VTABLE__

// [1-4] Runtime type information
IL2C_DECLARE_RUNTIME_TYPE(MT3620Blink_Application);

////////////////////////////////////////////////////////////
// [1] MT3620Blink.timespec

// [1-5-1] VTable (Same as System.ValueType)
#define MT3620Blink_timespec_VTABLE__ System_ValueType_VTABLE__

// [1-4] Runtime type information
IL2C_DECLARE_RUNTIME_TYPE(MT3620Blink_timespec);

////////////////////////////////////////////////////////////
// [1] MT3620Blink.itimerspec

// [1-5-1] VTable (Same as System.ValueType)
#define MT3620Blink_itimerspec_VTABLE__ System_ValueType_VTABLE__

// [1-4] Runtime type information
IL2C_DECLARE_RUNTIME_TYPE(MT3620Blink_itimerspec);

////////////////////////////////////////////////////////////
// [1] MT3620Blink.Timer

// [1-1-2] Class layout
struct MT3620Blink_Timer
{
    MT3620Blink_Timer_VTABLE_DECL__* vptr0__;
    System_IDisposable_VTABLE_DECL__* vptr_System_IDisposable__;
    int32_t baseField1__;
};

// [1-5-1] VTable (Same as MT3620Blink.Descriptor)
#define MT3620Blink_Timer_VTABLE__ MT3620Blink_Descriptor_VTABLE__

// [1-4] Runtime type information
IL2C_DECLARE_RUNTIME_TYPE(MT3620Blink_Timer);

////////////////////////////////////////////////////////////
// [1] MT3620Blink.Program.<>c__DisplayClass1_1

// [1-1-2] Class layout
struct MT3620Blink_Program___c__DisplayClass1_1
{
    MT3620Blink_Program___c__DisplayClass1_1_VTABLE_DECL__* vptr0__;
    MT3620Blink_Timer* timer;
    MT3620Blink_Program___c__DisplayClass1_0* CS___8__locals1;
};

// [1-5-1] VTable (Same as System.Object)
#define MT3620Blink_Program___c__DisplayClass1_1_VTABLE__ System_Object_VTABLE__

// [1-4] Runtime type information
IL2C_DECLARE_RUNTIME_TYPE(MT3620Blink_Program___c__DisplayClass1_1);

////////////////////////////////////////////////////////////
// [1] MT3620Blink.Program.<>c__DisplayClass1_2

// [1-1-2] Class layout
struct MT3620Blink_Program___c__DisplayClass1_2
{
    MT3620Blink_Program___c__DisplayClass1_2_VTABLE_DECL__* vptr0__;
    bool flag;
    int32_t blinkIntervalIndex;
    il2c_arraytype(System_Int64)* blinkIntervals;
    MT3620Blink_Program___c__DisplayClass1_1* CS___8__locals2;
};

// [1-5-1] VTable (Same as System.Object)
#define MT3620Blink_Program___c__DisplayClass1_2_VTABLE__ System_Object_VTABLE__

// [1-4] Runtime type information
IL2C_DECLARE_RUNTIME_TYPE(MT3620Blink_Program___c__DisplayClass1_2);

////////////////////////////////////////////////////////////
// [1] MT3620Blink.GPIO_Value_Type

// [1-5-1] VTable (Same as System.Enum)
#define MT3620Blink_GPIO_Value_Type_VTABLE__ System_Enum_VTABLE__

// [1-4] Runtime type information
IL2C_DECLARE_RUNTIME_TYPE(MT3620Blink_GPIO_Value_Type);

////////////////////////////////////////////////////////////
// [1] MT3620Blink.Interops

// [1-1-2] Class layout
struct MT3620Blink_Interops
{
    MT3620Blink_Interops_VTABLE_DECL__* vptr0__;
};

// [1-5-1] VTable (Same as System.Object)
#define MT3620Blink_Interops_VTABLE__ System_Object_VTABLE__

// [1-4] Runtime type information
IL2C_DECLARE_RUNTIME_TYPE(MT3620Blink_Interops);

//////////////////////////////////////////////////////////////////////////////////
// [2-2] Static fields:

#define MT3620Blink_Timer_CLOCK_MONOTONIC CLOCK_MONOTONIC
#define MT3620Blink_Timer_TFD_NONBLOCK TFD_NONBLOCK

#define MT3620Blink_Interops_MT3620_RDB_LED1_RED MT3620_RDB_LED1_RED
#define MT3620Blink_Interops_MT3620_RDB_BUTTON_A MT3620_RDB_BUTTON_A
#define MT3620Blink_Interops_EPOLL_CTL_ADD EPOLL_CTL_ADD
#define MT3620Blink_Interops_EPOLLIN EPOLLIN

//////////////////////////////////////////////////////////////////////////////////
// [2-3] Methods:

// [2-4] Member methods: MT3620Blink.Descriptor

extern void MT3620Blink_Descriptor__ctor(MT3620Blink_Descriptor* this__, int32_t fd);
extern void MT3620Blink_Descriptor_Dispose(MT3620Blink_Descriptor* this__);
extern int32_t MT3620Blink_Descriptor_get_Identity(MT3620Blink_Descriptor* this__);
extern void MT3620Blink_Descriptor_set_Identity(MT3620Blink_Descriptor* this__, int32_t value);

// [2-4] Member methods: MT3620Blink.GpioOutput

extern void MT3620Blink_GpioOutput__ctor(MT3620Blink_GpioOutput* this__, int32_t gpioId, MT3620Blink_GPIO_OutputMode_Type type, bool initialValue);
extern void MT3620Blink_GpioOutput_SetValue(MT3620Blink_GpioOutput* this__, bool value);

// [2-4] Member methods: MT3620Blink.Program.<>c__DisplayClass1_0

extern void MT3620Blink_Program___c__DisplayClass1_0__ctor(MT3620Blink_Program___c__DisplayClass1_0* this__);

// [2-4] Member methods: MT3620Blink.GpioInput

extern void MT3620Blink_GpioInput__ctor(MT3620Blink_GpioInput* this__, int32_t gpioId);
extern bool MT3620Blink_GpioInput_get_Value(MT3620Blink_GpioInput* this__);

// [2-4] Member methods: MT3620Blink.DescriptorCallbackDelegate

extern void MT3620Blink_DescriptorCallbackDelegate_Invoke(MT3620Blink_DescriptorCallbackDelegate* this__);

// [2-4] Member methods: MT3620Blink.Application

extern void MT3620Blink_Application__ctor(MT3620Blink_Application* this__);
extern void MT3620Blink_Application_RegisterDescriptor(MT3620Blink_Application* this__, MT3620Blink_Descriptor* target, MT3620Blink_DescriptorCallbackDelegate* callback);
extern void MT3620Blink_Application_Run(MT3620Blink_Application* this__);

// [2-4] Member methods: MT3620Blink.Timer

extern void MT3620Blink_Timer__ctor(MT3620Blink_Timer* this__, int64_t nsec);
extern void MT3620Blink_Timer_SetInterval(MT3620Blink_Timer* this__, int64_t nsec);

// [2-4] Member methods: MT3620Blink.Program.<>c__DisplayClass1_1

extern void MT3620Blink_Program___c__DisplayClass1_1__ctor(MT3620Blink_Program___c__DisplayClass1_1* this__);

// [2-4] Member methods: MT3620Blink.Program.<>c__DisplayClass1_2

extern void MT3620Blink_Program___c__DisplayClass1_2__ctor(MT3620Blink_Program___c__DisplayClass1_2* this__);
extern void MT3620Blink_Program___c__DisplayClass1_2__Main_b__0(MT3620Blink_Program___c__DisplayClass1_2* this__);
extern void MT3620Blink_Program___c__DisplayClass1_2__Main_b__1(MT3620Blink_Program___c__DisplayClass1_2* this__);

// [2-4] Member methods: MT3620Blink.Interops

extern /* static */ int32_t MT3620Blink_Interops_close(int32_t fd);
extern /* static */ void MT3620Blink_Interops_nanosleep(MT3620Blink_timespec* req, MT3620Blink_timespec* rem);
extern /* static */ int32_t MT3620Blink_Interops_timerfd_create(int32_t clockid, int32_t flags);
extern /* static */ int32_t MT3620Blink_Interops_timerfd_settime(int32_t fd, int32_t flags, MT3620Blink_itimerspec* new_value, MT3620Blink_itimerspec* old_value);
extern /* static */ int32_t MT3620Blink_Interops_GPIO_OpenAsOutput(int32_t gpioId, MT3620Blink_GPIO_OutputMode_Type outputMode, MT3620Blink_GPIO_Value_Type initialValue);
extern /* static */ int32_t MT3620Blink_Interops_GPIO_SetValue(int32_t gpioFd, MT3620Blink_GPIO_Value_Type value);
extern /* static */ int32_t MT3620Blink_Interops_GPIO_OpenAsInput(int32_t gpioId);
extern /* static */ int32_t MT3620Blink_Interops_GPIO_GetValue(int32_t gpioFd, MT3620Blink_GPIO_Value_Type* value);
extern /* static */ int32_t MT3620Blink_Interops_epoll_create1(int32_t flags);
extern /* static */ int32_t MT3620Blink_Interops_epoll_ctl(int32_t epollfd, int32_t op, int32_t fd, MT3620Blink_epoll_event* ev);
extern /* static */ int32_t MT3620Blink_Interops_epoll_wait(int32_t epollfd, MT3620Blink_epoll_event* ev, int32_t maxevents, int32_t timeout);

#ifdef __cplusplus
}
#endif

//////////////////////////////////////////////////////////////////////////////////
// [9-3] Static field instances:

//////////////////////////////////////////////////////////////////////////////////
// [9-4] Type: MT3620Blink.DescriptorCallbackDelegate

///////////////////////////////////////
// [11-2] Delegate invoker: MT3620Blink.DescriptorCallbackDelegate.Invoke(MT3620Blink.DescriptorCallbackDelegate this__)

void MT3620Blink_DescriptorCallbackDelegate_Invoke(MT3620Blink_DescriptorCallbackDelegate* this__)
{
    il2c_assert(this__ != NULL);
    il2c_assert(this__->vptr0__ == &System_Delegate_VTABLE__);
    il2c_assert(this__->count__ >= 1);

    uintptr_t index = 0;
    do
    {
        IL2C_METHOD_TABLE* pMethodtbl = &this__->methodtbl__[index];
        if (pMethodtbl->target != NULL)
            ((void (*)(System_Object*))(pMethodtbl->methodPtr))(pMethodtbl->target);
        else
            ((void (*)(void))(pMethodtbl->methodPtr))();
        index++;
    }
    while (index < this__->count__);
}

//////////////////////
// [7] Runtime helpers:

// [7-10-1] VTable (Not defined, same as System.MulticastDelegate)

// [7-8] Runtime type information
IL2C_RUNTIME_TYPE_BEGIN(MT3620Blink_DescriptorCallbackDelegate, "MT3620Blink.DescriptorCallbackDelegate", IL2C_TYPE_VARIABLE, sizeof(MT3620Blink_DescriptorCallbackDelegate), System_MulticastDelegate, System_Delegate_MarkHandler__, 0)
IL2C_RUNTIME_TYPE_END();

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
        { NULL, 1 };
    il2c_link_execution_frame(&frame__);

    //-------------------
    // [3-6] IL body:

    /* IL_0000: ldarg.0                         : Application.cs(10) */
    frame__.stack0_0__ = this__;
    /* IL_0001: ldc.i4.0                        : Application.cs(10) */
    stack1_0__ = 0;
    /* IL_0002: call MT3620Blink.Interops.epoll_create1 : Application.cs(10) */
    stack1_0__ = MT3620Blink_Interops_epoll_create1(stack1_0__);
    /* IL_0007: call MT3620Blink.Descriptor..ctor : Application.cs(10) */
    MT3620Blink_Descriptor__ctor((MT3620Blink_Descriptor*)frame__.stack0_0__, stack1_0__);
    /* IL_000c: nop                             : Application.cs(10) */
    /* IL_000d: nop  */
    /* IL_000e: ret  */
    il2c_unlink_execution_frame(&frame__);
    return;
}

///////////////////////////////////////
// [3] MT3620Blink.Application.RegisterDescriptor(MT3620Blink.Application this__, MT3620Blink.Descriptor target, MT3620Blink.DescriptorCallbackDelegate callback)

//-------------------
// [3-7] Declare execution frame:

typedef struct MT3620Blink_Application_RegisterDescriptor_EXECUTION_FRAME_DECL
{
    const IL2C_EXECUTION_FRAME* pNext__;
    const uint16_t objRefCount__;
    const uint16_t valueCount__;
    //-------------------- objref
    MT3620Blink_DescriptorCallbackDelegate* stack0_0__;
    MT3620Blink_Application* stack0_4__;
    MT3620Blink_Descriptor* stack2_2__;
} MT3620Blink_Application_RegisterDescriptor_EXECUTION_FRAME__;

//-------------------
// [3-2] Function body:

void MT3620Blink_Application_RegisterDescriptor(MT3620Blink_Application* this__, MT3620Blink_Descriptor* target, MT3620Blink_DescriptorCallbackDelegate* callback)
{
    il2c_assert(this__ != NULL);

    //-------------------
    // [3-3] Local variables (!objref):

    System_Runtime_InteropServices_GCHandle handle;
    il2c_memset(&handle, 0x00, sizeof handle);
    MT3620Blink_epoll_event ev;
    il2c_memset(&ev, 0x00, sizeof ev);
    MT3620Blink_epoll_event local2__;
    il2c_memset(&local2__, 0x00, sizeof local2__);
    MT3620Blink_epoll_data_t local3__;
    il2c_memset(&local3__, 0x00, sizeof local3__);

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
    System_Runtime_InteropServices_GCHandle* stack2_0__;
    intptr_t stack2_1__;
    int32_t stack2_3__;
    MT3620Blink_epoll_event* stack3_0__;

    //-------------------
    // [3-5] Setup execution frame:

    MT3620Blink_Application_RegisterDescriptor_EXECUTION_FRAME__ frame__ =
        { NULL, 3 };
    il2c_link_execution_frame(&frame__);

    //-------------------
    // [3-6] IL body:

    /* IL_0000: nop                             : Application.cs(15) */
    /* IL_0001: ldarg.2  */
    frame__.stack0_0__ = callback;
    /* IL_0002: ldc.i4.3                        : Application.cs(16) */
    stack1_0__ = 3;
    /* IL_0003: call System.Runtime.InteropServices.GCHandle.Alloc : Application.cs(16) */
    stack0_1__ = System_Runtime_InteropServices_GCHandle_Alloc_1((System_Object*)frame__.stack0_0__, (System_Runtime_InteropServices_GCHandleType)stack1_0__);
    /* IL_0008: stloc.0                         : Application.cs(16) */
    handle = stack0_1__;
    /* IL_0009: ldloca.s local2__               : Application.cs(18) */
    stack0_2__ = &local2__;
    /* IL_000b: initobj MT3620Blink.epoll_event : Application.cs(18) */
    il2c_memset(stack0_2__, 0x00, sizeof(MT3620Blink_epoll_event));
    /* IL_0011: ldloca.s local2__               : Application.cs(18) */
    stack0_2__ = &local2__;
    /* IL_0013: ldsfld MT3620Blink.Interops.EPOLLIN : Application.cs(18) */
    stack1_1__ = MT3620Blink_Interops_EPOLLIN;
    /* IL_0018: stfld MT3620Blink.epoll_event.events : Application.cs(18) */
    stack0_2__->events = stack1_1__;
    /* IL_001d: ldloca.s local2__               : Application.cs(18) */
    stack0_2__ = &local2__;
    /* IL_001f: ldloca.s local3__               : Application.cs(18) */
    stack1_2__ = &local3__;
    /* IL_0021: initobj MT3620Blink.epoll_data_t : Application.cs(18) */
    il2c_memset(stack1_2__, 0x00, sizeof(MT3620Blink_epoll_data_t));
    /* IL_0027: ldloca.s local3__               : Application.cs(18) */
    stack1_2__ = &local3__;
    /* IL_0029: ldloca.s handle                 : Application.cs(18) */
    stack2_0__ = &handle;
    /* IL_002b: call System.Runtime.InteropServices.GCHandle.AddrOfPinnedObject : Application.cs(18) */
    stack2_1__ = System_Runtime_InteropServices_GCHandle_AddrOfPinnedObject(stack2_0__);
    /* IL_0030: stfld MT3620Blink.epoll_data_t.ptr : Application.cs(18) */
    stack1_2__->ptr = stack2_1__;
    /* IL_0035: ldloc.3                         : Application.cs(18) */
    stack1_3__ = local3__;
    /* IL_0036: stfld MT3620Blink.epoll_event.data : Application.cs(18) */
    stack0_2__->data = stack1_3__;
    /* IL_003b: ldloc.2                         : Application.cs(18) */
    stack0_3__ = local2__;
    /* IL_003c: stloc.1                         : Application.cs(18) */
    ev = stack0_3__;
    /* IL_003d: ldarg.0                         : Application.cs(23) */
    frame__.stack0_4__ = this__;
    /* IL_003e: call MT3620Blink.Descriptor.get_Identity : Application.cs(23) */
    stack0_5__ = MT3620Blink_Descriptor_get_Identity((MT3620Blink_Descriptor*)frame__.stack0_4__);
    /* IL_0043: ldsfld MT3620Blink.Interops.EPOLL_CTL_ADD : Application.cs(23) */
    stack1_0__ = MT3620Blink_Interops_EPOLL_CTL_ADD;
    /* IL_0048: ldarg.1                         : Application.cs(23) */
    frame__.stack2_2__ = target;
    /* IL_0049: callvirt MT3620Blink.Descriptor.get_Identity : Application.cs(23) */
    stack2_3__ = MT3620Blink_Descriptor_get_Identity(il2c_adjusted_reference(frame__.stack2_2__));
    /* IL_004e: ldloca.s ev                     : Application.cs(23) */
    stack3_0__ = &ev;
    /* IL_0050: call MT3620Blink.Interops.epoll_ctl : Application.cs(23) */
    stack0_5__ = MT3620Blink_Interops_epoll_ctl(stack0_5__, stack1_0__, stack2_3__, stack3_0__);
    /* IL_0055: pop                             : Application.cs(23) */
    /* IL_0056: ret  */
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
    MT3620Blink_DescriptorCallbackDelegate* callback;
    MT3620Blink_Application* stack0_2__;
    System_Object* stack0_9__;
    MT3620Blink_DescriptorCallbackDelegate* stack0_10__;
} MT3620Blink_Application_Run_EXECUTION_FRAME__;

//-------------------
// [3-2] Function body:

void MT3620Blink_Application_Run(MT3620Blink_Application* this__)
{
    il2c_assert(this__ != NULL);

    //-------------------
    // [3-3] Local variables (!objref):

    MT3620Blink_epoll_event ev;
    il2c_memset(&ev, 0x00, sizeof ev);
    int32_t numEventsOccurred = 0;
    bool local2__ = false;
    System_Runtime_InteropServices_GCHandle handle;
    il2c_memset(&handle, 0x00, sizeof handle);
    bool local5__ = false;

    //-------------------
    // [3-4] Evaluation stacks (!objref):

    int32_t stack0_0__;
    MT3620Blink_epoll_event* stack0_1__;
    bool stack0_3__;
    MT3620Blink_epoll_event stack0_4__;
    MT3620Blink_epoll_data_t stack0_5__;
    intptr_t stack0_6__;
    System_Runtime_InteropServices_GCHandle stack0_7__;
    System_Runtime_InteropServices_GCHandle* stack0_8__;
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

    /* IL_0000: nop                             : Application.cs(31) */
    /* IL_0001: br.s IL_004e */
    goto IL_004e;
IL_0003:
    /* IL_0003: nop                             : Application.cs(33) */
    /* IL_0004: ldloca.s ev */
    stack0_1__ = &ev;
    /* IL_0006: initobj MT3620Blink.epoll_event : Application.cs(34) */
    il2c_memset(stack0_1__, 0x00, sizeof(MT3620Blink_epoll_event));
    /* IL_000c: ldarg.0                         : Application.cs(35) */
    frame__.stack0_2__ = this__;
    /* IL_000d: call MT3620Blink.Descriptor.get_Identity : Application.cs(35) */
    stack0_0__ = MT3620Blink_Descriptor_get_Identity((MT3620Blink_Descriptor*)frame__.stack0_2__);
    /* IL_0012: ldloca.s ev                     : Application.cs(35) */
    stack1_0__ = &ev;
    /* IL_0014: ldc.i4.1                        : Application.cs(35) */
    stack2_0__ = 1;
    /* IL_0015: ldc.i4.m1                       : Application.cs(35) */
    stack3_0__ = -1;
    /* IL_0016: call MT3620Blink.Interops.epoll_wait : Application.cs(35) */
    stack0_0__ = MT3620Blink_Interops_epoll_wait(stack0_0__, stack1_0__, stack2_0__, stack3_0__);
    /* IL_001b: stloc.1                         : Application.cs(35) */
    numEventsOccurred = stack0_0__;
    /* IL_001c: ldloc.1                         : Application.cs(37) */
    stack0_0__ = numEventsOccurred;
    /* IL_001d: ldc.i4.1                        : Application.cs(37) */
    stack1_1__ = 1;
    /* IL_001e: ceq                             : Application.cs(37) */
    stack0_0__ = ((int32_t)stack0_0__ == (int32_t)stack1_1__) ? 1 : 0;
    /* IL_0020: stloc.2                         : Application.cs(37) */
    local2__ = (stack0_0__) ? true : false;
    /* IL_0021: ldloc.2                         : Application.cs(37) */
    stack0_3__ = local2__;
    /* IL_0022: brfalse.s IL_004d               : Application.cs(37) */
    if (!(stack0_3__)) goto IL_004d;
    /* IL_0024: nop                             : Application.cs(38) */
    /* IL_0025: ldloc.0  */
    stack0_4__ = ev;
    /* IL_0026: ldfld MT3620Blink.epoll_event.data : Application.cs(39) */
    stack0_5__ = stack0_4__.data;
    /* IL_002b: ldfld MT3620Blink.epoll_data_t.ptr : Application.cs(39) */
    stack0_6__ = stack0_5__.ptr;
    /* IL_0030: call System.Runtime.InteropServices.GCHandle.FromIntPtr : Application.cs(39) */
    stack0_7__ = System_Runtime_InteropServices_GCHandle_FromIntPtr(stack0_6__);
    /* IL_0035: stloc.3                         : Application.cs(39) */
    handle = stack0_7__;
    /* IL_0036: ldloca.s handle                 : Application.cs(40) */
    stack0_8__ = &handle;
    /* IL_0038: call System.Runtime.InteropServices.GCHandle.get_Target : Application.cs(40) */
    frame__.stack0_9__ = System_Runtime_InteropServices_GCHandle_get_Target(stack0_8__);
    /* IL_003d: castclass MT3620Blink.DescriptorCallbackDelegate : Application.cs(40) */
    frame__.stack0_10__ = il2c_castclass(frame__.stack0_9__, MT3620Blink_DescriptorCallbackDelegate);
    /* IL_0042: stloc.s callback                : Application.cs(40) */
    frame__.callback = frame__.stack0_10__;
    /* IL_0044: ldloc.s callback                : Application.cs(41) */
    frame__.stack0_10__ = frame__.callback;
    /* IL_0046: callvirt MT3620Blink.DescriptorCallbackDelegate.Invoke : Application.cs(41) */
    MT3620Blink_DescriptorCallbackDelegate_Invoke(il2c_adjusted_reference(frame__.stack0_10__));
    /* IL_004b: nop                             : Application.cs(41) */
    /* IL_004c: nop  */
IL_004d:
    /* IL_004d: nop  */
IL_004e:
    /* IL_004e: ldc.i4.1  */
    stack0_0__ = 1;
    /* IL_004f: stloc.s local5__                : Application.cs(32) */
    local5__ = (stack0_0__) ? true : false;
    /* IL_0051: br.s IL_0003                    : Application.cs(32) */
    goto IL_0003;
}

//////////////////////
// [7] Runtime helpers:

// [7-10-1] VTable (Not defined, same as MT3620Blink.Descriptor)

// [7-13] VTable for System.IDisposable
System_IDisposable_VTABLE_DECL__ MT3620Blink_Application_System_IDisposable_VTABLE__ = {
    il2c_adjustor_offset(MT3620Blink_Application, System_IDisposable),
    (void (*)(void*))MT3620Blink_Descriptor_Dispose,
};

// [7-8] Runtime type information
IL2C_RUNTIME_TYPE_BEGIN(MT3620Blink_Application, "MT3620Blink.Application", IL2C_TYPE_REFERENCE, sizeof(MT3620Blink_Application), MT3620Blink_Descriptor, 0, 1)
    IL2C_RUNTIME_TYPE_INTERFACE(MT3620Blink_Application, System_IDisposable)
IL2C_RUNTIME_TYPE_END();

//////////////////////////////////////////////////////////////////////////////////
// [9-4] Type: MT3620Blink.Descriptor

///////////////////////////////////////
// [3] MT3620Blink.Descriptor..ctor(MT3620Blink.Descriptor this__, System.Int32 fd)

//-------------------
// [3-7] Declare execution frame:

typedef struct MT3620Blink_Descriptor__ctor_EXECUTION_FRAME_DECL
{
    const IL2C_EXECUTION_FRAME* pNext__;
    const uint16_t objRefCount__;
    const uint16_t valueCount__;
    //-------------------- objref
    MT3620Blink_Descriptor* stack0_0__;
} MT3620Blink_Descriptor__ctor_EXECUTION_FRAME__;

//-------------------
// [3-2] Function body:

void MT3620Blink_Descriptor__ctor(MT3620Blink_Descriptor* this__, int32_t fd)
{
    il2c_assert(this__ != NULL);

    //-------------------
    // [3-4] Evaluation stacks (!objref):

    int32_t stack1_0__;

    //-------------------
    // [3-5] Setup execution frame:

    MT3620Blink_Descriptor__ctor_EXECUTION_FRAME__ frame__ =
        { NULL, 1 };
    il2c_link_execution_frame(&frame__);

    //-------------------
    // [3-6] IL body:

    /* IL_0000: ldarg.0                         : Descriptor.cs(7) */
    frame__.stack0_0__ = this__;
    /* IL_0001: call System.Object..ctor        : Descriptor.cs(7) */
    System_Object__ctor((System_Object*)frame__.stack0_0__);
    /* IL_0006: nop                             : Descriptor.cs(7) */
    /* IL_0007: nop  */
    /* IL_0008: ldarg.0  */
    frame__.stack0_0__ = this__;
    /* IL_0009: ldarg.1                         : Descriptor.cs(9) */
    stack1_0__ = fd;
    /* IL_000a: call MT3620Blink.Descriptor.set_Identity : Descriptor.cs(9) */
    MT3620Blink_Descriptor_set_Identity(frame__.stack0_0__, stack1_0__);
    /* IL_000f: nop                             : Descriptor.cs(9) */
    /* IL_0010: ret  */
    il2c_unlink_execution_frame(&frame__);
    return;
}

///////////////////////////////////////
// [3] MT3620Blink.Descriptor.Dispose(MT3620Blink.Descriptor this__)

//-------------------
// [3-7] Declare execution frame:

typedef struct MT3620Blink_Descriptor_Dispose_EXECUTION_FRAME_DECL
{
    const IL2C_EXECUTION_FRAME* pNext__;
    const uint16_t objRefCount__;
    const uint16_t valueCount__;
    //-------------------- objref
    MT3620Blink_Descriptor* stack0_0__;
} MT3620Blink_Descriptor_Dispose_EXECUTION_FRAME__;

//-------------------
// [3-2] Function body:

void MT3620Blink_Descriptor_Dispose(MT3620Blink_Descriptor* this__)
{
    il2c_assert(this__ != NULL);

    //-------------------
    // [3-3] Local variables (!objref):

    bool local0__ = false;

    //-------------------
    // [3-4] Evaluation stacks (!objref):

    int32_t stack0_1__;
    bool stack0_2__;
    int32_t stack1_0__;

    //-------------------
    // [3-5] Setup execution frame:

    MT3620Blink_Descriptor_Dispose_EXECUTION_FRAME__ frame__ =
        { NULL, 1 };
    il2c_link_execution_frame(&frame__);

    //-------------------
    // [3-6] IL body:

    /* IL_0000: nop                             : Descriptor.cs(13) */
    /* IL_0001: ldarg.0  */
    frame__.stack0_0__ = this__;
    /* IL_0002: call MT3620Blink.Descriptor.get_Identity : Descriptor.cs(14) */
    stack0_1__ = MT3620Blink_Descriptor_get_Identity(frame__.stack0_0__);
    /* IL_0007: ldc.i4.0                        : Descriptor.cs(14) */
    stack1_0__ = 0;
    /* IL_0008: clt                             : Descriptor.cs(14) */
    stack0_1__ = ((int32_t)stack0_1__ < (int32_t)stack1_0__) ? 1 : 0;
    /* IL_000a: ldc.i4.0                        : Descriptor.cs(14) */
    stack1_0__ = 0;
    /* IL_000b: ceq                             : Descriptor.cs(14) */
    stack0_1__ = ((int32_t)stack0_1__ == (int32_t)stack1_0__) ? 1 : 0;
    /* IL_000d: stloc.0                         : Descriptor.cs(14) */
    local0__ = (stack0_1__) ? true : false;
    /* IL_000e: ldloc.0                         : Descriptor.cs(14) */
    stack0_2__ = local0__;
    /* IL_000f: brfalse.s IL_0027               : Descriptor.cs(14) */
    if (!(stack0_2__)) goto IL_0027;
    /* IL_0011: nop                             : Descriptor.cs(15) */
    /* IL_0012: ldarg.0  */
    frame__.stack0_0__ = this__;
    /* IL_0013: call MT3620Blink.Descriptor.get_Identity : Descriptor.cs(16) */
    stack0_1__ = MT3620Blink_Descriptor_get_Identity(frame__.stack0_0__);
    /* IL_0018: call MT3620Blink.Interops.close : Descriptor.cs(16) */
    stack0_1__ = MT3620Blink_Interops_close(stack0_1__);
    /* IL_001d: pop                             : Descriptor.cs(16) */
    /* IL_001e: ldarg.0  */
    frame__.stack0_0__ = this__;
    /* IL_001f: ldc.i4.m1                       : Descriptor.cs(17) */
    stack1_0__ = -1;
    /* IL_0020: call MT3620Blink.Descriptor.set_Identity : Descriptor.cs(17) */
    MT3620Blink_Descriptor_set_Identity(frame__.stack0_0__, stack1_0__);
    /* IL_0025: nop                             : Descriptor.cs(17) */
    /* IL_0026: nop  */
IL_0027:
    /* IL_0027: ret  */
    il2c_unlink_execution_frame(&frame__);
    return;
}

///////////////////////////////////////
// [3] MT3620Blink.Descriptor.get_Identity(MT3620Blink.Descriptor this__)

//-------------------
// [3-7] Declare execution frame:

typedef struct MT3620Blink_Descriptor_get_Identity_EXECUTION_FRAME_DECL
{
    const IL2C_EXECUTION_FRAME* pNext__;
    const uint16_t objRefCount__;
    const uint16_t valueCount__;
    //-------------------- objref
    MT3620Blink_Descriptor* stack0_0__;
} MT3620Blink_Descriptor_get_Identity_EXECUTION_FRAME__;

//-------------------
// [3-2] Function body:

int32_t MT3620Blink_Descriptor_get_Identity(MT3620Blink_Descriptor* this__)
{
    il2c_assert(this__ != NULL);

    //-------------------
    // [3-4] Evaluation stacks (!objref):

    int32_t stack0_1__;

    //-------------------
    // [3-5] Setup execution frame:

    MT3620Blink_Descriptor_get_Identity_EXECUTION_FRAME__ frame__ =
        { NULL, 1 };
    il2c_link_execution_frame(&frame__);

    //-------------------
    // [3-6] IL body:

    /* IL_0000: ldarg.0                         : Descriptor.cs(21) */
    frame__.stack0_0__ = this__;
    /* IL_0001: ldfld MT3620Blink.Descriptor.<Identity>k__BackingField : Descriptor.cs(21) */
    stack0_1__ = frame__.stack0_0__->_Identity_k__BackingField;
    /* IL_0006: ret                             : Descriptor.cs(21) */
    il2c_unlink_execution_frame(&frame__);
    return stack0_1__;
}

///////////////////////////////////////
// [3] MT3620Blink.Descriptor.set_Identity(MT3620Blink.Descriptor this__, System.Int32 value)

//-------------------
// [3-7] Declare execution frame:

typedef struct MT3620Blink_Descriptor_set_Identity_EXECUTION_FRAME_DECL
{
    const IL2C_EXECUTION_FRAME* pNext__;
    const uint16_t objRefCount__;
    const uint16_t valueCount__;
    //-------------------- objref
    MT3620Blink_Descriptor* stack0_0__;
} MT3620Blink_Descriptor_set_Identity_EXECUTION_FRAME__;

//-------------------
// [3-2] Function body:

void MT3620Blink_Descriptor_set_Identity(MT3620Blink_Descriptor* this__, int32_t value)
{
    il2c_assert(this__ != NULL);

    //-------------------
    // [3-4] Evaluation stacks (!objref):

    int32_t stack1_0__;

    //-------------------
    // [3-5] Setup execution frame:

    MT3620Blink_Descriptor_set_Identity_EXECUTION_FRAME__ frame__ =
        { NULL, 1 };
    il2c_link_execution_frame(&frame__);

    //-------------------
    // [3-6] IL body:

    /* IL_0000: ldarg.0                         : Descriptor.cs(21) */
    frame__.stack0_0__ = this__;
    /* IL_0001: ldarg.1                         : Descriptor.cs(21) */
    stack1_0__ = value;
    /* IL_0002: stfld MT3620Blink.Descriptor.<Identity>k__BackingField : Descriptor.cs(21) */
    frame__.stack0_0__->_Identity_k__BackingField = stack1_0__;
    /* IL_0007: ret                             : Descriptor.cs(21) */
    il2c_unlink_execution_frame(&frame__);
    return;
}

//////////////////////
// [7] Runtime helpers:

// [7-10-1] VTable (Not defined, same as System.Object)

// [7-13] VTable for System.IDisposable
System_IDisposable_VTABLE_DECL__ MT3620Blink_Descriptor_System_IDisposable_VTABLE__ = {
    il2c_adjustor_offset(MT3620Blink_Descriptor, System_IDisposable),
    (void (*)(void*))MT3620Blink_Descriptor_Dispose,
};

// [7-8] Runtime type information
IL2C_RUNTIME_TYPE_BEGIN(MT3620Blink_Descriptor, "MT3620Blink.Descriptor", IL2C_TYPE_REFERENCE, sizeof(MT3620Blink_Descriptor), System_Object, 0, 1)
    IL2C_RUNTIME_TYPE_INTERFACE(MT3620Blink_Descriptor, System_IDisposable)
IL2C_RUNTIME_TYPE_END();

//////////////////////////////////////////////////////////////////////////////////
// [9-4] Type: MT3620Blink.GpioInput

///////////////////////////////////////
// [3] MT3620Blink.GpioInput..ctor(MT3620Blink.GpioInput this__, System.Int32 gpioId)

//-------------------
// [3-7] Declare execution frame:

typedef struct MT3620Blink_GpioInput__ctor_EXECUTION_FRAME_DECL
{
    const IL2C_EXECUTION_FRAME* pNext__;
    const uint16_t objRefCount__;
    const uint16_t valueCount__;
    //-------------------- objref
    MT3620Blink_GpioInput* stack0_0__;
} MT3620Blink_GpioInput__ctor_EXECUTION_FRAME__;

//-------------------
// [3-2] Function body:

void MT3620Blink_GpioInput__ctor(MT3620Blink_GpioInput* this__, int32_t gpioId)
{
    il2c_assert(this__ != NULL);

    //-------------------
    // [3-4] Evaluation stacks (!objref):

    int32_t stack1_0__;

    //-------------------
    // [3-5] Setup execution frame:

    MT3620Blink_GpioInput__ctor_EXECUTION_FRAME__ frame__ =
        { NULL, 1 };
    il2c_link_execution_frame(&frame__);

    //-------------------
    // [3-6] IL body:

    /* IL_0000: ldarg.0                         : GpioInput.cs(6) */
    frame__.stack0_0__ = this__;
    /* IL_0001: ldarg.1                         : GpioInput.cs(6) */
    stack1_0__ = gpioId;
    /* IL_0002: call MT3620Blink.Interops.GPIO_OpenAsInput : GpioInput.cs(6) */
    stack1_0__ = MT3620Blink_Interops_GPIO_OpenAsInput(stack1_0__);
    /* IL_0007: call MT3620Blink.Descriptor..ctor : GpioInput.cs(6) */
    MT3620Blink_Descriptor__ctor((MT3620Blink_Descriptor*)frame__.stack0_0__, stack1_0__);
    /* IL_000c: nop                             : GpioInput.cs(6) */
    /* IL_000d: nop  */
    /* IL_000e: ret  */
    il2c_unlink_execution_frame(&frame__);
    return;
}

///////////////////////////////////////
// [3] MT3620Blink.GpioInput.get_Value(MT3620Blink.GpioInput this__)

//-------------------
// [3-7] Declare execution frame:

typedef struct MT3620Blink_GpioInput_get_Value_EXECUTION_FRAME_DECL
{
    const IL2C_EXECUTION_FRAME* pNext__;
    const uint16_t objRefCount__;
    const uint16_t valueCount__;
    //-------------------- objref
    MT3620Blink_GpioInput* stack0_0__;
} MT3620Blink_GpioInput_get_Value_EXECUTION_FRAME__;

//-------------------
// [3-2] Function body:

bool MT3620Blink_GpioInput_get_Value(MT3620Blink_GpioInput* this__)
{
    il2c_assert(this__ != NULL);

    //-------------------
    // [3-3] Local variables (!objref):

    MT3620Blink_GPIO_Value_Type value;
    il2c_memset(&value, 0x00, sizeof value);
    bool local1__ = false;

    //-------------------
    // [3-4] Evaluation stacks (!objref):

    int32_t stack0_1__;
    MT3620Blink_GPIO_Value_Type stack0_2__;
    bool stack0_3__;
    MT3620Blink_GPIO_Value_Type* stack1_0__;
    int32_t stack1_1__;

    //-------------------
    // [3-5] Setup execution frame:

    MT3620Blink_GpioInput_get_Value_EXECUTION_FRAME__ frame__ =
        { NULL, 1 };
    il2c_link_execution_frame(&frame__);

    //-------------------
    // [3-6] IL body:

    /* IL_0000: nop                             : GpioInput.cs(13) */
    /* IL_0001: ldarg.0  */
    frame__.stack0_0__ = this__;
    /* IL_0002: call MT3620Blink.Descriptor.get_Identity : GpioInput.cs(14) */
    stack0_1__ = MT3620Blink_Descriptor_get_Identity((MT3620Blink_Descriptor*)frame__.stack0_0__);
    /* IL_0007: ldloca.s value                  : GpioInput.cs(14) */
    stack1_0__ = &value;
    /* IL_0009: call MT3620Blink.Interops.GPIO_GetValue : GpioInput.cs(14) */
    stack0_1__ = MT3620Blink_Interops_GPIO_GetValue(stack0_1__, stack1_0__);
    /* IL_000e: pop                             : GpioInput.cs(14) */
    /* IL_000f: ldloc.0  */
    stack0_2__ = value;
    /* IL_0010: ldc.i4.1                        : GpioInput.cs(15) */
    stack1_1__ = 1;
    /* IL_0011: ceq                             : GpioInput.cs(15) */
    stack0_1__ = ((int32_t)stack0_2__ == (int32_t)stack1_1__) ? 1 : 0;
    /* IL_0013: stloc.1                         : GpioInput.cs(15) */
    local1__ = (stack0_1__) ? true : false;
    /* IL_0014: br.s IL_0016                    : GpioInput.cs(15) */
    goto IL_0016;
IL_0016:
    /* IL_0016: ldloc.1                         : GpioInput.cs(16) */
    stack0_3__ = local1__;
    /* IL_0017: ret                             : GpioInput.cs(16) */
    il2c_unlink_execution_frame(&frame__);
    return stack0_3__;
}

//////////////////////
// [7] Runtime helpers:

// [7-10-1] VTable (Not defined, same as MT3620Blink.Descriptor)

// [7-13] VTable for System.IDisposable
System_IDisposable_VTABLE_DECL__ MT3620Blink_GpioInput_System_IDisposable_VTABLE__ = {
    il2c_adjustor_offset(MT3620Blink_GpioInput, System_IDisposable),
    (void (*)(void*))MT3620Blink_Descriptor_Dispose,
};

// [7-8] Runtime type information
IL2C_RUNTIME_TYPE_BEGIN(MT3620Blink_GpioInput, "MT3620Blink.GpioInput", IL2C_TYPE_REFERENCE, sizeof(MT3620Blink_GpioInput), MT3620Blink_Descriptor, 0, 1)
    IL2C_RUNTIME_TYPE_INTERFACE(MT3620Blink_GpioInput, System_IDisposable)
IL2C_RUNTIME_TYPE_END();

//////////////////////////////////////////////////////////////////////////////////
// [9-4] Type: MT3620Blink.GpioOutput

///////////////////////////////////////
// [3] MT3620Blink.GpioOutput..ctor(MT3620Blink.GpioOutput this__, System.Int32 gpioId, MT3620Blink.GPIO_OutputMode_Type type, System.Boolean initialValue)

//-------------------
// [3-7] Declare execution frame:

typedef struct MT3620Blink_GpioOutput__ctor_EXECUTION_FRAME_DECL
{
    const IL2C_EXECUTION_FRAME* pNext__;
    const uint16_t objRefCount__;
    const uint16_t valueCount__;
    //-------------------- objref
    MT3620Blink_GpioOutput* stack0_0__;
} MT3620Blink_GpioOutput__ctor_EXECUTION_FRAME__;

//-------------------
// [3-2] Function body:

void MT3620Blink_GpioOutput__ctor(MT3620Blink_GpioOutput* this__, int32_t gpioId, MT3620Blink_GPIO_OutputMode_Type type, bool initialValue)
{
    il2c_assert(this__ != NULL);

    //-------------------
    // [3-4] Evaluation stacks (!objref):

    int32_t stack1_0__;
    MT3620Blink_GPIO_OutputMode_Type stack2_0__;
    bool stack3_0__;
    int32_t stack3_1__;

    //-------------------
    // [3-5] Setup execution frame:

    MT3620Blink_GpioOutput__ctor_EXECUTION_FRAME__ frame__ =
        { NULL, 1 };
    il2c_link_execution_frame(&frame__);

    //-------------------
    // [3-6] IL body:

    /* IL_0000: ldarg.0                         : GpioOutput.cs(6) */
    frame__.stack0_0__ = this__;
    /* IL_0001: ldarg.1                         : GpioOutput.cs(6) */
    stack1_0__ = gpioId;
    /* IL_0002: ldarg.2                         : GpioOutput.cs(6) */
    stack2_0__ = type;
    /* IL_0003: ldarg.3                         : GpioOutput.cs(6) */
    stack3_0__ = initialValue;
    /* IL_0004: brtrue.s IL_0009                : GpioOutput.cs(6) */
    if (stack3_0__) goto IL_0009;
    /* IL_0006: ldc.i4.0                        : GpioOutput.cs(6) */
    stack3_1__ = 0;
    /* IL_0007: br.s IL_000a                    : GpioOutput.cs(6) */
    goto IL_000a;
IL_0009:
    /* IL_0009: ldc.i4.1                        : GpioOutput.cs(6) */
    stack3_1__ = 1;
IL_000a:
    /* IL_000a: call MT3620Blink.Interops.GPIO_OpenAsOutput : GpioOutput.cs(6) */
    stack1_0__ = MT3620Blink_Interops_GPIO_OpenAsOutput(stack1_0__, stack2_0__, (MT3620Blink_GPIO_Value_Type)stack3_1__);
    /* IL_000f: call MT3620Blink.Descriptor..ctor : GpioOutput.cs(6) */
    MT3620Blink_Descriptor__ctor((MT3620Blink_Descriptor*)frame__.stack0_0__, stack1_0__);
    /* IL_0014: nop                             : GpioOutput.cs(6) */
    /* IL_0015: nop  */
    /* IL_0016: ret  */
    il2c_unlink_execution_frame(&frame__);
    return;
}

///////////////////////////////////////
// [3] MT3620Blink.GpioOutput.SetValue(MT3620Blink.GpioOutput this__, System.Boolean value)

//-------------------
// [3-7] Declare execution frame:

typedef struct MT3620Blink_GpioOutput_SetValue_EXECUTION_FRAME_DECL
{
    const IL2C_EXECUTION_FRAME* pNext__;
    const uint16_t objRefCount__;
    const uint16_t valueCount__;
    //-------------------- objref
    MT3620Blink_GpioOutput* stack0_0__;
} MT3620Blink_GpioOutput_SetValue_EXECUTION_FRAME__;

//-------------------
// [3-2] Function body:

void MT3620Blink_GpioOutput_SetValue(MT3620Blink_GpioOutput* this__, bool value)
{
    il2c_assert(this__ != NULL);

    //-------------------
    // [3-4] Evaluation stacks (!objref):

    int32_t stack0_1__;
    bool stack1_0__;
    int32_t stack1_1__;

    //-------------------
    // [3-5] Setup execution frame:

    MT3620Blink_GpioOutput_SetValue_EXECUTION_FRAME__ frame__ =
        { NULL, 1 };
    il2c_link_execution_frame(&frame__);

    //-------------------
    // [3-6] IL body:

    /* IL_0000: ldarg.0                         : GpioOutput.cs(14) */
    frame__.stack0_0__ = this__;
    /* IL_0001: call MT3620Blink.Descriptor.get_Identity : GpioOutput.cs(14) */
    stack0_1__ = MT3620Blink_Descriptor_get_Identity((MT3620Blink_Descriptor*)frame__.stack0_0__);
    /* IL_0006: ldarg.1                         : GpioOutput.cs(14) */
    stack1_0__ = value;
    /* IL_0007: brtrue.s IL_000c                : GpioOutput.cs(14) */
    if (stack1_0__) goto IL_000c;
    /* IL_0009: ldc.i4.0                        : GpioOutput.cs(14) */
    stack1_1__ = 0;
    /* IL_000a: br.s IL_000d                    : GpioOutput.cs(14) */
    goto IL_000d;
IL_000c:
    /* IL_000c: ldc.i4.1                        : GpioOutput.cs(14) */
    stack1_1__ = 1;
IL_000d:
    /* IL_000d: call MT3620Blink.Interops.GPIO_SetValue : GpioOutput.cs(14) */
    stack0_1__ = MT3620Blink_Interops_GPIO_SetValue(stack0_1__, (MT3620Blink_GPIO_Value_Type)stack1_1__);
    /* IL_0012: pop                             : GpioOutput.cs(14) */
    /* IL_0013: ret  */
    il2c_unlink_execution_frame(&frame__);
    return;
}

//////////////////////
// [7] Runtime helpers:

// [7-10-1] VTable (Not defined, same as MT3620Blink.Descriptor)

// [7-13] VTable for System.IDisposable
System_IDisposable_VTABLE_DECL__ MT3620Blink_GpioOutput_System_IDisposable_VTABLE__ = {
    il2c_adjustor_offset(MT3620Blink_GpioOutput, System_IDisposable),
    (void (*)(void*))MT3620Blink_Descriptor_Dispose,
};

// [7-8] Runtime type information
IL2C_RUNTIME_TYPE_BEGIN(MT3620Blink_GpioOutput, "MT3620Blink.GpioOutput", IL2C_TYPE_REFERENCE, sizeof(MT3620Blink_GpioOutput), MT3620Blink_Descriptor, 0, 1)
    IL2C_RUNTIME_TYPE_INTERFACE(MT3620Blink_GpioOutput, System_IDisposable)
IL2C_RUNTIME_TYPE_END();

//////////////////////////////////////////////////////////////////////////////////
// [9-4] Type: MT3620Blink.timespec

//////////////////////
// [7] Runtime helpers:

// [7-10-1] VTable (Not defined, same as System.ValueType)

// [7-8] Runtime type information
IL2C_RUNTIME_TYPE_BEGIN(MT3620Blink_timespec, "MT3620Blink.timespec", IL2C_TYPE_VALUE, sizeof(MT3620Blink_timespec), System_ValueType, 0, 0)
IL2C_RUNTIME_TYPE_END();

//////////////////////////////////////////////////////////////////////////////////
// [9-4] Type: MT3620Blink.itimerspec

//////////////////////
// [7] Runtime helpers:

// [7-10-1] VTable (Not defined, same as System.ValueType)

// [7-8] Runtime type information
IL2C_RUNTIME_TYPE_BEGIN(MT3620Blink_itimerspec, "MT3620Blink.itimerspec", IL2C_TYPE_VALUE, sizeof(MT3620Blink_itimerspec), System_ValueType, 2, 0)
    IL2C_RUNTIME_TYPE_MARK_TARGET_FOR_VALUE(MT3620Blink_itimerspec, MT3620Blink_timespec, it_interval)
    IL2C_RUNTIME_TYPE_MARK_TARGET_FOR_VALUE(MT3620Blink_itimerspec, MT3620Blink_timespec, it_value)
IL2C_RUNTIME_TYPE_END();

//////////////////////////////////////////////////////////////////////////////////
// [9-4] Type: MT3620Blink.GPIO_OutputMode_Type

//////////////////////
// [7] Runtime helpers:

// [7-10-1] VTable (Not defined, same as System.Enum)

// [7-8] Runtime type information
IL2C_RUNTIME_TYPE_BEGIN(MT3620Blink_GPIO_OutputMode_Type, "MT3620Blink.GPIO_OutputMode_Type", IL2C_TYPE_INTEGER, sizeof(MT3620Blink_GPIO_OutputMode_Type), System_Enum, 0, 0)
IL2C_RUNTIME_TYPE_END();

//////////////////////////////////////////////////////////////////////////////////
// [9-4] Type: MT3620Blink.GPIO_Value_Type

//////////////////////
// [7] Runtime helpers:

// [7-10-1] VTable (Not defined, same as System.Enum)

// [7-8] Runtime type information
IL2C_RUNTIME_TYPE_BEGIN(MT3620Blink_GPIO_Value_Type, "MT3620Blink.GPIO_Value_Type", IL2C_TYPE_INTEGER, sizeof(MT3620Blink_GPIO_Value_Type), System_Enum, 0, 0)
IL2C_RUNTIME_TYPE_END();

//////////////////////////////////////////////////////////////////////////////////
// [9-4] Type: MT3620Blink.epoll_data_t

//////////////////////
// [7] Runtime helpers:

// [7-10-1] VTable (Not defined, same as System.ValueType)

// [7-8] Runtime type information
IL2C_RUNTIME_TYPE_BEGIN(MT3620Blink_epoll_data_t, "MT3620Blink.epoll_data_t", IL2C_TYPE_VALUE, sizeof(MT3620Blink_epoll_data_t), System_ValueType, 0, 0)
IL2C_RUNTIME_TYPE_END();

//////////////////////////////////////////////////////////////////////////////////
// [9-4] Type: MT3620Blink.epoll_event

//////////////////////
// [7] Runtime helpers:

// [7-10-1] VTable (Not defined, same as System.ValueType)

// [7-8] Runtime type information
IL2C_RUNTIME_TYPE_BEGIN(MT3620Blink_epoll_event, "MT3620Blink.epoll_event", IL2C_TYPE_VALUE, sizeof(MT3620Blink_epoll_event), System_ValueType, 1, 0)
    IL2C_RUNTIME_TYPE_MARK_TARGET_FOR_VALUE(MT3620Blink_epoll_event, MT3620Blink_epoll_data_t, data)
IL2C_RUNTIME_TYPE_END();

//////////////////////////////////////////////////////////////////////////////////
// [9-4] Type: MT3620Blink.Interops

///////////////////////////////////////
// [6] IL2C/Invoke: MT3620Blink.Interops.close(System.Int32 fd)

int32_t MT3620Blink_Interops_close(int32_t fd)
{
    return close(fd);
}

///////////////////////////////////////
// [6] IL2C/Invoke: MT3620Blink.Interops.nanosleep(MT3620Blink.timespec& req, MT3620Blink.timespec& rem)

void MT3620Blink_Interops_nanosleep(MT3620Blink_timespec* req, MT3620Blink_timespec* rem)
{
    nanosleep(req, rem);
}

///////////////////////////////////////
// [6] IL2C/Invoke: MT3620Blink.Interops.timerfd_create(System.Int32 clockid, System.Int32 flags)

int32_t MT3620Blink_Interops_timerfd_create(int32_t clockid, int32_t flags)
{
    return timerfd_create(clockid, flags);
}

///////////////////////////////////////
// [6] IL2C/Invoke: MT3620Blink.Interops.timerfd_settime(System.Int32 fd, System.Int32 flags, MT3620Blink.itimerspec& new_value, MT3620Blink.itimerspec& old_value)

int32_t MT3620Blink_Interops_timerfd_settime(int32_t fd, int32_t flags, MT3620Blink_itimerspec* new_value, MT3620Blink_itimerspec* old_value)
{
    return timerfd_settime(fd, flags, new_value, old_value);
}

///////////////////////////////////////
// [6] IL2C/Invoke: MT3620Blink.Interops.GPIO_OpenAsOutput(System.Int32 gpioId, MT3620Blink.GPIO_OutputMode_Type outputMode, MT3620Blink.GPIO_Value_Type initialValue)

int32_t MT3620Blink_Interops_GPIO_OpenAsOutput(int32_t gpioId, MT3620Blink_GPIO_OutputMode_Type outputMode, MT3620Blink_GPIO_Value_Type initialValue)
{
    return GPIO_OpenAsOutput(gpioId, outputMode, initialValue);
}

///////////////////////////////////////
// [6] IL2C/Invoke: MT3620Blink.Interops.GPIO_SetValue(System.Int32 gpioFd, MT3620Blink.GPIO_Value_Type value)

int32_t MT3620Blink_Interops_GPIO_SetValue(int32_t gpioFd, MT3620Blink_GPIO_Value_Type value)
{
    return GPIO_SetValue(gpioFd, value);
}

///////////////////////////////////////
// [6] IL2C/Invoke: MT3620Blink.Interops.GPIO_OpenAsInput(System.Int32 gpioId)

int32_t MT3620Blink_Interops_GPIO_OpenAsInput(int32_t gpioId)
{
    return GPIO_OpenAsInput(gpioId);
}

///////////////////////////////////////
// [6] IL2C/Invoke: MT3620Blink.Interops.GPIO_GetValue(System.Int32 gpioFd, MT3620Blink.GPIO_Value_Type& value)

int32_t MT3620Blink_Interops_GPIO_GetValue(int32_t gpioFd, MT3620Blink_GPIO_Value_Type* value)
{
    return GPIO_GetValue(gpioFd, value);
}

///////////////////////////////////////
// [6] IL2C/Invoke: MT3620Blink.Interops.epoll_create1(System.Int32 flags)

int32_t MT3620Blink_Interops_epoll_create1(int32_t flags)
{
    return epoll_create1(flags);
}

///////////////////////////////////////
// [6] IL2C/Invoke: MT3620Blink.Interops.epoll_ctl(System.Int32 epollfd, System.Int32 op, System.Int32 fd, MT3620Blink.epoll_event& ev)

int32_t MT3620Blink_Interops_epoll_ctl(int32_t epollfd, int32_t op, int32_t fd, MT3620Blink_epoll_event* ev)
{
    return epoll_ctl(epollfd, op, fd, ev);
}

///////////////////////////////////////
// [6] IL2C/Invoke: MT3620Blink.Interops.epoll_wait(System.Int32 epollfd, MT3620Blink.epoll_event& ev, System.Int32 maxevents, System.Int32 timeout)

int32_t MT3620Blink_Interops_epoll_wait(int32_t epollfd, MT3620Blink_epoll_event* ev, int32_t maxevents, int32_t timeout)
{
    return epoll_wait(epollfd, ev, maxevents, timeout);
}

//////////////////////
// [7] Runtime helpers:

// [7-10-1] VTable (Not defined, same as System.Object)

// [7-8] Runtime type information
IL2C_RUNTIME_TYPE_BEGIN(MT3620Blink_Interops, "MT3620Blink.Interops", IL2C_TYPE_REFERENCE, sizeof(MT3620Blink_Interops), System_Object, 0, 0)
IL2C_RUNTIME_TYPE_END();

//////////////////////////////////////////////////////////////////////////////////
// [9-4] Type: MT3620Blink.Program

///////////////////////////////////////
// [3] MT3620Blink.Program.sleep(System.Int32 nsec)

//-------------------
// [3-2] Function body:

void MT3620Blink_Program_sleep(int32_t nsec)
{
    //-------------------
    // [3-3] Local variables (!objref):

    MT3620Blink_timespec sleepTime;
    il2c_memset(&sleepTime, 0x00, sizeof sleepTime);
    MT3620Blink_timespec dummy;
    il2c_memset(&dummy, 0x00, sizeof dummy);
    MT3620Blink_timespec local2__;
    il2c_memset(&local2__, 0x00, sizeof local2__);

    //-------------------
    // [3-4] Evaluation stacks (!objref):

    MT3620Blink_timespec* stack0_0__;
    MT3620Blink_timespec stack0_1__;
    int32_t stack1_0__;
    MT3620Blink_timespec* stack1_1__;

    //-------------------
    // [3-6] IL body:

    /* IL_0000: nop                             : Program.cs(12) */
    /* IL_0001: ldloca.s local2__ */
    stack0_0__ = &local2__;
    /* IL_0003: initobj MT3620Blink.timespec    : Program.cs(13) */
    il2c_memset(stack0_0__, 0x00, sizeof(MT3620Blink_timespec));
    /* IL_0009: ldloca.s local2__               : Program.cs(13) */
    stack0_0__ = &local2__;
    /* IL_000b: ldarg.0                         : Program.cs(13) */
    stack1_0__ = nsec;
    /* IL_000c: stfld MT3620Blink.timespec.tv_nsec : Program.cs(13) */
    stack0_0__->tv_nsec = stack1_0__;
    /* IL_0011: ldloc.2                         : Program.cs(13) */
    stack0_1__ = local2__;
    /* IL_0012: stloc.0                         : Program.cs(13) */
    sleepTime = stack0_1__;
    /* IL_0013: ldloca.s sleepTime              : Program.cs(14) */
    stack0_0__ = &sleepTime;
    /* IL_0015: ldloca.s dummy                  : Program.cs(14) */
    stack1_1__ = &dummy;
    /* IL_0017: call MT3620Blink.Interops.nanosleep : Program.cs(14) */
    MT3620Blink_Interops_nanosleep(stack0_0__, stack1_1__);
    /* IL_001c: nop                             : Program.cs(14) */
    /* IL_001d: ret  */
    return;
}

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

static int16_t MT3620Blink_Program_Main_ExceptionFilter3__(System_Exception* ex)
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
    MT3620Blink_Program___c__DisplayClass1_0* CS___8__locals0;
    MT3620Blink_GpioInput* button;
    MT3620Blink_Program___c__DisplayClass1_1* CS___8__locals1;
    MT3620Blink_Program___c__DisplayClass1_2* CS___8__locals2;
    MT3620Blink_Application* stack0_0__;
    MT3620Blink_Program___c__DisplayClass1_0* stack0_1__;
    MT3620Blink_GpioInput* stack0_3__;
    MT3620Blink_Program___c__DisplayClass1_1* stack0_4__;
    MT3620Blink_Program___c__DisplayClass1_2* stack0_5__;
    MT3620Blink_GpioOutput* stack0_6__;
    MT3620Blink_Timer* stack0_7__;
    MT3620Blink_GpioOutput* stack1_1__;
    MT3620Blink_Program___c__DisplayClass1_0* stack1_2__;
    MT3620Blink_Timer* stack1_4__;
    MT3620Blink_Program___c__DisplayClass1_1* stack1_5__;
    MT3620Blink_Program___c__DisplayClass1_2* stack1_6__;
    il2c_arraytype(System_Int64)* stack1_7__;
    MT3620Blink_GpioInput* stack1_8__;
    MT3620Blink_Program___c__DisplayClass1_2* stack2_1__;
    MT3620Blink_DescriptorCallbackDelegate* stack2_2__;
    il2c_arraytype(System_Int64)* stack2_3__;
} MT3620Blink_Program_Main_EXECUTION_FRAME__;

//-------------------
// [3-2] Function body:

int32_t MT3620Blink_Program_Main(void)
{
    //-------------------
    // [3-3] Local variables (!objref):

    volatile int32_t local5__ = 0;

    //-------------------
    // [3-4] Evaluation stacks (!objref):

    int32_t stack0_2__;
    int32_t stack1_0__;
    int64_t stack1_3__;
    int32_t stack2_0__;
    int32_t stack3_0__;
    intptr_t stack3_1__;
    System_RuntimeFieldHandle stack3_2__;

    //-------------------
    // [3-5] Setup execution frame:

    MT3620Blink_Program_Main_EXECUTION_FRAME__ frame__ =
        { NULL, 22 };
    il2c_link_execution_frame(&frame__);

    //-------------------
    // [3-6] IL body:

    /* IL_0000: nop                             : Program.cs(18) */
    /* IL_0001: newobj MT3620Blink.Application..ctor */
    frame__.stack0_0__ = il2c_get_uninitialized_object(MT3620Blink_Application);
    MT3620Blink_Application__ctor(frame__.stack0_0__);
    /* IL_0006: stloc.0                         : Program.cs(19) */
    frame__.epoll = frame__.stack0_0__;
    il2c_try(nest0, MT3620Blink_Program_Main_ExceptionFilter0__)
    {
        /* IL_0007: nop                             : Program.cs(20) */
        /* IL_0008: newobj MT3620Blink.Program.<>c__DisplayClass1_0..ctor */
        frame__.stack0_1__ = il2c_get_uninitialized_object(MT3620Blink_Program___c__DisplayClass1_0);
        MT3620Blink_Program___c__DisplayClass1_0__ctor(frame__.stack0_1__);
        /* IL_000d: stloc.1                         : Program.cs(20) */
        frame__.CS___8__locals0 = frame__.stack0_1__;
        /* IL_000e: ldloc.1                         : Program.cs(21) */
        frame__.stack0_1__ = frame__.CS___8__locals0;
        /* IL_000f: ldsfld MT3620Blink.Interops.MT3620_RDB_LED1_RED : Program.cs(21) */
        stack1_0__ = MT3620Blink_Interops_MT3620_RDB_LED1_RED;
        /* IL_0014: ldc.i4.0                        : Program.cs(21) */
        stack2_0__ = 0;
        /* IL_0015: ldc.i4.1                        : Program.cs(21) */
        stack3_0__ = 1;
        /* IL_0016: newobj MT3620Blink.GpioOutput..ctor : Program.cs(21) */
        frame__.stack1_1__ = il2c_get_uninitialized_object(MT3620Blink_GpioOutput);
        MT3620Blink_GpioOutput__ctor(frame__.stack1_1__, stack1_0__, (MT3620Blink_GPIO_OutputMode_Type)stack2_0__, (stack3_0__) ? true : false);
        /* IL_001b: stfld MT3620Blink.Program.<>c__DisplayClass1_0.led : Program.cs(21) */
        frame__.stack0_1__->led = frame__.stack1_1__;
        il2c_try(nest1, MT3620Blink_Program_Main_ExceptionFilter1__)
        {
            /* IL_0020: nop                             : Program.cs(25) */
            /* IL_0021: ldsfld MT3620Blink.Interops.MT3620_RDB_BUTTON_A */
            stack0_2__ = MT3620Blink_Interops_MT3620_RDB_BUTTON_A;
            /* IL_0026: newobj MT3620Blink.GpioInput..ctor : Program.cs(26) */
            frame__.stack0_3__ = il2c_get_uninitialized_object(MT3620Blink_GpioInput);
            MT3620Blink_GpioInput__ctor(frame__.stack0_3__, stack0_2__);
            /* IL_002b: stloc.2                         : Program.cs(26) */
            frame__.button = frame__.stack0_3__;
            il2c_try(nest2, MT3620Blink_Program_Main_ExceptionFilter2__)
            {
                /* IL_002c: nop                             : Program.cs(28) */
                /* IL_002d: newobj MT3620Blink.Program.<>c__DisplayClass1_1..ctor */
                frame__.stack0_4__ = il2c_get_uninitialized_object(MT3620Blink_Program___c__DisplayClass1_1);
                MT3620Blink_Program___c__DisplayClass1_1__ctor(frame__.stack0_4__);
                /* IL_0032: stloc.3                         : Program.cs(28) */
                frame__.CS___8__locals1 = frame__.stack0_4__;
                /* IL_0033: ldloc.3                         : Program.cs(28) */
                frame__.stack0_4__ = frame__.CS___8__locals1;
                /* IL_0034: ldloc.1                         : Program.cs(28) */
                frame__.stack1_2__ = frame__.CS___8__locals0;
                /* IL_0035: stfld MT3620Blink.Program.<>c__DisplayClass1_1.CS$<>8__locals1 : Program.cs(28) */
                frame__.stack0_4__->CS___8__locals1 = frame__.stack1_2__;
                /* IL_003a: ldloc.3                         : Program.cs(29) */
                frame__.stack0_4__ = frame__.CS___8__locals1;
                /* IL_003b: ldc.i4 125000000                : Program.cs(29) */
                stack1_0__ = 125000000;
                /* IL_0040: conv.i8                         : Program.cs(29) */
                stack1_3__ = (int64_t)stack1_0__;
                /* IL_0041: newobj MT3620Blink.Timer..ctor  : Program.cs(29) */
                frame__.stack1_4__ = il2c_get_uninitialized_object(MT3620Blink_Timer);
                MT3620Blink_Timer__ctor(frame__.stack1_4__, stack1_3__);
                /* IL_0046: stfld MT3620Blink.Program.<>c__DisplayClass1_1.timer : Program.cs(29) */
                frame__.stack0_4__->timer = frame__.stack1_4__;
                il2c_try(nest3, MT3620Blink_Program_Main_ExceptionFilter3__)
                {
                    /* IL_004b: newobj MT3620Blink.Program.<>c__DisplayClass1_2..ctor : Program.cs(29) */
                    frame__.stack0_5__ = il2c_get_uninitialized_object(MT3620Blink_Program___c__DisplayClass1_2);
                    MT3620Blink_Program___c__DisplayClass1_2__ctor(frame__.stack0_5__);
                    /* IL_0050: stloc.s CS$<>8__locals2         : Program.cs(29) */
                    frame__.CS___8__locals2 = frame__.stack0_5__;
                    /* IL_0052: ldloc.s CS$<>8__locals2         : Program.cs(29) */
                    frame__.stack0_5__ = frame__.CS___8__locals2;
                    /* IL_0054: ldloc.3                         : Program.cs(29) */
                    frame__.stack1_5__ = frame__.CS___8__locals1;
                    /* IL_0055: stfld MT3620Blink.Program.<>c__DisplayClass1_2.CS$<>8__locals2 : Program.cs(29) */
                    frame__.stack0_5__->CS___8__locals2 = frame__.stack1_5__;
                    /* IL_005a: nop                             : Program.cs(30) */
                    /* IL_005b: ldloc.s CS$<>8__locals2 */
                    frame__.stack0_5__ = frame__.CS___8__locals2;
                    /* IL_005d: ldc.i4.0                        : Program.cs(31) */
                    stack1_0__ = 0;
                    /* IL_005e: stfld MT3620Blink.Program.<>c__DisplayClass1_2.flag : Program.cs(31) */
                    frame__.stack0_5__->flag = (stack1_0__) ? true : false;
                    /* IL_0063: ldloc.0                         : Program.cs(33) */
                    frame__.stack0_0__ = frame__.epoll;
                    /* IL_0064: ldloc.s CS$<>8__locals2         : Program.cs(33) */
                    frame__.stack1_6__ = frame__.CS___8__locals2;
                    /* IL_0066: ldfld MT3620Blink.Program.<>c__DisplayClass1_2.CS$<>8__locals2 : Program.cs(33) */
                    frame__.stack1_5__ = frame__.stack1_6__->CS___8__locals2;
                    /* IL_006b: ldfld MT3620Blink.Program.<>c__DisplayClass1_1.timer : Program.cs(33) */
                    frame__.stack1_4__ = frame__.stack1_5__->timer;
                    /* IL_0070: ldloc.s CS$<>8__locals2         : Program.cs(33) */
                    frame__.stack2_1__ = frame__.CS___8__locals2;
                    /* IL_0072: ldftn MT3620Blink.Program.<>c__DisplayClass1_2.<Main>b__0 : Program.cs(33) */
                    stack3_1__ = (intptr_t)MT3620Blink_Program___c__DisplayClass1_2__Main_b__0;
                    /* IL_0078: newobj MT3620Blink.DescriptorCallbackDelegate..ctor : Program.cs(33) */
                    frame__.stack2_2__ = il2c_new_delegate(MT3620Blink_DescriptorCallbackDelegate, (System_Object*)frame__.stack2_1__, stack3_1__);
                    /* IL_007d: callvirt MT3620Blink.Application.RegisterDescriptor : Program.cs(33) */
                    MT3620Blink_Application_RegisterDescriptor(il2c_adjusted_reference(frame__.stack0_0__), (MT3620Blink_Descriptor*)frame__.stack1_4__, frame__.stack2_2__);
                    /* IL_0082: nop                             : Program.cs(33) */
                    /* IL_0083: ldloc.s CS$<>8__locals2 */
                    frame__.stack0_5__ = frame__.CS___8__locals2;
                    /* IL_0085: ldc.i4.3                        : Program.cs(41) */
                    stack1_0__ = 3;
                    /* IL_0086: newarr System.Int64             : Program.cs(41) */
                    frame__.stack1_7__ = il2c_new_array(System_Int64, stack1_0__);
                    /* IL_008b: dup                             : Program.cs(41) */
                    frame__.stack2_3__ = frame__.stack1_7__;
                    /* IL_008c: ldtoken .<PrivateImplementationDetails>.E902362F9BEE92BBA97ECE5B88B94AF4A8D3201D : Program.cs(41) */
                    stack3_2__.size__ = sizeof(declaredValue0__);
                    stack3_2__.field__ = declaredValue0__;
                    /* IL_0091: call System.Runtime.CompilerServices.RuntimeHelpers.InitializeArray : Program.cs(41) */
                    System_Runtime_CompilerServices_RuntimeHelpers_InitializeArray((System_Array*)frame__.stack2_3__, stack3_2__);
                    /* IL_0096: stfld MT3620Blink.Program.<>c__DisplayClass1_2.blinkIntervals : Program.cs(41) */
                    frame__.stack0_5__->blinkIntervals = frame__.stack1_7__;
                    /* IL_009b: ldloc.s CS$<>8__locals2         : Program.cs(42) */
                    frame__.stack0_5__ = frame__.CS___8__locals2;
                    /* IL_009d: ldc.i4.0                        : Program.cs(42) */
                    stack1_0__ = 0;
                    /* IL_009e: stfld MT3620Blink.Program.<>c__DisplayClass1_2.blinkIntervalIndex : Program.cs(42) */
                    frame__.stack0_5__->blinkIntervalIndex = stack1_0__;
                    /* IL_00a3: ldloc.0                         : Program.cs(44) */
                    frame__.stack0_0__ = frame__.epoll;
                    /* IL_00a4: ldloc.2                         : Program.cs(44) */
                    frame__.stack1_8__ = frame__.button;
                    /* IL_00a5: ldloc.s CS$<>8__locals2         : Program.cs(44) */
                    frame__.stack2_1__ = frame__.CS___8__locals2;
                    /* IL_00a7: ldftn MT3620Blink.Program.<>c__DisplayClass1_2.<Main>b__1 : Program.cs(44) */
                    stack3_1__ = (intptr_t)MT3620Blink_Program___c__DisplayClass1_2__Main_b__1;
                    /* IL_00ad: newobj MT3620Blink.DescriptorCallbackDelegate..ctor : Program.cs(44) */
                    frame__.stack2_2__ = il2c_new_delegate(MT3620Blink_DescriptorCallbackDelegate, (System_Object*)frame__.stack2_1__, stack3_1__);
                    /* IL_00b2: callvirt MT3620Blink.Application.RegisterDescriptor : Program.cs(44) */
                    MT3620Blink_Application_RegisterDescriptor(il2c_adjusted_reference(frame__.stack0_0__), (MT3620Blink_Descriptor*)frame__.stack1_8__, frame__.stack2_2__);
                    /* IL_00b7: nop                             : Program.cs(44) */
                    /* IL_00b8: ldloc.0  */
                    frame__.stack0_0__ = frame__.epoll;
                    /* IL_00b9: callvirt MT3620Blink.Application.Run : Program.cs(52) */
                    MT3620Blink_Application_Run(il2c_adjusted_reference(frame__.stack0_0__));
                    /* IL_00be: nop                             : Program.cs(52) */
                    /* IL_00bf: nop  */
                    /* IL_00c0: leave.s IL_00d7 */
                    il2c_leave(nest3, 0);
                }
                il2c_finally(nest3)
                {
                    /* IL_00c2: ldloc.3                         : Program.cs(53) */
                    frame__.stack0_4__ = frame__.CS___8__locals1;
                    /* IL_00c3: ldfld MT3620Blink.Program.<>c__DisplayClass1_1.timer : Program.cs(53) */
                    frame__.stack0_7__ = frame__.stack0_4__->timer;
                    /* IL_00c8: brfalse.s IL_00d6               : Program.cs(53) */
                    if (frame__.stack0_7__ == NULL) goto IL_00d6;
                    /* IL_00ca: ldloc.3                         : Program.cs(53) */
                    frame__.stack0_4__ = frame__.CS___8__locals1;
                    /* IL_00cb: ldfld MT3620Blink.Program.<>c__DisplayClass1_1.timer : Program.cs(53) */
                    frame__.stack0_7__ = frame__.stack0_4__->timer;
                    /* IL_00d0: callvirt System.IDisposable.Dispose : Program.cs(53) */
                    MT3620Blink_Descriptor_Dispose(il2c_adjusted_reference(frame__.stack0_7__));
                    /* IL_00d5: nop                             : Program.cs(53) */
                IL_00d6:
                    /* IL_00d6: endfinally  */
                    il2c_endfinally(nest3);
                }
                il2c_leave_to(nest3)
                {
                    il2c_leave_bind(nest3, 0, IL_00d7);
                }
                il2c_end_try(nest3);
            IL_00d7:
                /* IL_00d7: nop                             : Program.cs(54) */
                /* IL_00d8: leave.s IL_00e5 */
                il2c_leave(nest2, 1);
            }
            il2c_finally(nest2)
            {
                /* IL_00da: ldloc.2                         : Program.cs(54) */
                frame__.stack0_3__ = frame__.button;
                /* IL_00db: brfalse.s IL_00e4               : Program.cs(54) */
                if (frame__.stack0_3__ == NULL) goto IL_00e4;
                /* IL_00dd: ldloc.2                         : Program.cs(54) */
                frame__.stack0_3__ = frame__.button;
                /* IL_00de: callvirt System.IDisposable.Dispose : Program.cs(54) */
                MT3620Blink_Descriptor_Dispose(il2c_adjusted_reference(frame__.stack0_3__));
                /* IL_00e3: nop                             : Program.cs(54) */
            IL_00e4:
                /* IL_00e4: endfinally  */
                il2c_endfinally(nest2);
            }
            il2c_leave_to(nest2)
            {
                il2c_leave_bind(nest2, 0, IL_00d7);
                il2c_leave_bind(nest2, 1, IL_00e5);
            }
            il2c_end_try(nest2);
        IL_00e5:
            /* IL_00e5: nop                             : Program.cs(55) */
            /* IL_00e6: leave.s IL_00fd */
            il2c_leave(nest1, 2);
        }
        il2c_finally(nest1)
        {
            /* IL_00e8: ldloc.1                         : Program.cs(55) */
            frame__.stack0_1__ = frame__.CS___8__locals0;
            /* IL_00e9: ldfld MT3620Blink.Program.<>c__DisplayClass1_0.led : Program.cs(55) */
            frame__.stack0_6__ = frame__.stack0_1__->led;
            /* IL_00ee: brfalse.s IL_00fc               : Program.cs(55) */
            if (frame__.stack0_6__ == NULL) goto IL_00fc;
            /* IL_00f0: ldloc.1                         : Program.cs(55) */
            frame__.stack0_1__ = frame__.CS___8__locals0;
            /* IL_00f1: ldfld MT3620Blink.Program.<>c__DisplayClass1_0.led : Program.cs(55) */
            frame__.stack0_6__ = frame__.stack0_1__->led;
            /* IL_00f6: callvirt System.IDisposable.Dispose : Program.cs(55) */
            MT3620Blink_Descriptor_Dispose(il2c_adjusted_reference(frame__.stack0_6__));
            /* IL_00fb: nop                             : Program.cs(55) */
        IL_00fc:
            /* IL_00fc: endfinally  */
            il2c_endfinally(nest1);
        }
        il2c_leave_to(nest1)
        {
            il2c_leave_bind(nest1, 0, IL_00d7);
            il2c_leave_bind(nest1, 1, IL_00e5);
            il2c_leave_bind(nest1, 2, IL_00fd);
        }
        il2c_end_try(nest1);
    IL_00fd:
        /* IL_00fd: nop                             : Program.cs(56) */
        /* IL_00fe: leave.s IL_010b */
        il2c_leave(nest0, 3);
    }
    il2c_finally(nest0)
    {
        /* IL_0100: ldloc.0                         : Program.cs(56) */
        frame__.stack0_0__ = frame__.epoll;
        /* IL_0101: brfalse.s IL_010a               : Program.cs(56) */
        if (frame__.stack0_0__ == NULL) goto IL_010a;
        /* IL_0103: ldloc.0                         : Program.cs(56) */
        frame__.stack0_0__ = frame__.epoll;
        /* IL_0104: callvirt System.IDisposable.Dispose : Program.cs(56) */
        MT3620Blink_Descriptor_Dispose(il2c_adjusted_reference(frame__.stack0_0__));
        /* IL_0109: nop                             : Program.cs(56) */
    IL_010a:
        /* IL_010a: endfinally  */
        il2c_endfinally(nest0);
    }
    il2c_leave_to(nest0)
    {
        il2c_leave_bind(nest0, 0, IL_00d7);
        il2c_leave_bind(nest0, 1, IL_00e5);
        il2c_leave_bind(nest0, 2, IL_00fd);
        il2c_leave_bind(nest0, 3, IL_010b);
    }
    il2c_end_try(nest0);
IL_010b:
    /* IL_010b: ldc.i4.0                        : Program.cs(58) */
    stack0_2__ = 0;
    /* IL_010c: stloc.s local5__                : Program.cs(58) */
    local5__ = stack0_2__;
    /* IL_010e: br.s IL_0110                    : Program.cs(58) */
    goto IL_0110;
IL_0110:
    /* IL_0110: ldloc.s local5__                : Program.cs(59) */
    stack0_2__ = local5__;
    /* IL_0112: ret                             : Program.cs(59) */
    il2c_unlink_execution_frame(&frame__);
    return stack0_2__;
}

//////////////////////
// [7] Runtime helpers:

// [7-10-1] VTable (Not defined, same as System.Object)

// [7-8] Runtime type information
IL2C_RUNTIME_TYPE_BEGIN(MT3620Blink_Program, "MT3620Blink.Program", IL2C_TYPE_REFERENCE, sizeof(MT3620Blink_Program), System_Object, 0, 0)
IL2C_RUNTIME_TYPE_END();

//////////////////////////////////////////////////////////////////////////////////
// [9-4] Type: MT3620Blink.Timer

///////////////////////////////////////
// [3] MT3620Blink.Timer..ctor(MT3620Blink.Timer this__, System.Int64 nsec)

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

void MT3620Blink_Timer__ctor(MT3620Blink_Timer* this__, int64_t nsec)
{
    il2c_assert(this__ != NULL);

    //-------------------
    // [3-4] Evaluation stacks (!objref):

    int32_t stack1_0__;
    int64_t stack1_1__;
    int32_t stack2_0__;

    //-------------------
    // [3-5] Setup execution frame:

    MT3620Blink_Timer__ctor_EXECUTION_FRAME__ frame__ =
        { NULL, 1 };
    il2c_link_execution_frame(&frame__);

    //-------------------
    // [3-6] IL body:

    /* IL_0000: ldarg.0                         : Timer.cs(13) */
    frame__.stack0_0__ = this__;
    /* IL_0001: ldsfld MT3620Blink.Timer.CLOCK_MONOTONIC : Timer.cs(13) */
    stack1_0__ = MT3620Blink_Timer_CLOCK_MONOTONIC;
    /* IL_0006: ldsfld MT3620Blink.Timer.TFD_NONBLOCK : Timer.cs(13) */
    stack2_0__ = MT3620Blink_Timer_TFD_NONBLOCK;
    /* IL_000b: call MT3620Blink.Interops.timerfd_create : Timer.cs(13) */
    stack1_0__ = MT3620Blink_Interops_timerfd_create(stack1_0__, stack2_0__);
    /* IL_0010: call MT3620Blink.Descriptor..ctor : Timer.cs(13) */
    MT3620Blink_Descriptor__ctor((MT3620Blink_Descriptor*)frame__.stack0_0__, stack1_0__);
    /* IL_0015: nop                             : Timer.cs(13) */
    /* IL_0016: nop  */
    /* IL_0017: ldarg.0  */
    frame__.stack0_0__ = this__;
    /* IL_0018: ldarg.1                         : Timer.cs(15) */
    stack1_1__ = nsec;
    /* IL_0019: call MT3620Blink.Timer.SetInterval : Timer.cs(15) */
    MT3620Blink_Timer_SetInterval(frame__.stack0_0__, stack1_1__);
    /* IL_001e: nop                             : Timer.cs(15) */
    /* IL_001f: ret  */
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
    il2c_memset(stack0_0__, 0x00, sizeof(MT3620Blink_timespec));
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
    il2c_memset(stack0_2__, 0x00, sizeof(MT3620Blink_itimerspec));
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

//////////////////////
// [7] Runtime helpers:

// [7-10-1] VTable (Not defined, same as MT3620Blink.Descriptor)

// [7-13] VTable for System.IDisposable
System_IDisposable_VTABLE_DECL__ MT3620Blink_Timer_System_IDisposable_VTABLE__ = {
    il2c_adjustor_offset(MT3620Blink_Timer, System_IDisposable),
    (void (*)(void*))MT3620Blink_Descriptor_Dispose,
};

// [7-8] Runtime type information
IL2C_RUNTIME_TYPE_BEGIN(MT3620Blink_Timer, "MT3620Blink.Timer", IL2C_TYPE_REFERENCE, sizeof(MT3620Blink_Timer), MT3620Blink_Descriptor, 0, 1)
    IL2C_RUNTIME_TYPE_INTERFACE(MT3620Blink_Timer, System_IDisposable)
IL2C_RUNTIME_TYPE_END();

//////////////////////////////////////////////////////////////////////////////////
// [9-4] Type: MT3620Blink.Program.<>c__DisplayClass1_0

///////////////////////////////////////
// [3] MT3620Blink.Program.<>c__DisplayClass1_0..ctor(MT3620Blink.Program.<>c__DisplayClass1_0 this__)

//-------------------
// [3-7] Declare execution frame:

typedef struct MT3620Blink_Program___c__DisplayClass1_0__ctor_EXECUTION_FRAME_DECL
{
    const IL2C_EXECUTION_FRAME* pNext__;
    const uint16_t objRefCount__;
    const uint16_t valueCount__;
    //-------------------- objref
    MT3620Blink_Program___c__DisplayClass1_0* stack0_0__;
} MT3620Blink_Program___c__DisplayClass1_0__ctor_EXECUTION_FRAME__;

//-------------------
// [3-2] Function body:

void MT3620Blink_Program___c__DisplayClass1_0__ctor(MT3620Blink_Program___c__DisplayClass1_0* this__)
{
    il2c_assert(this__ != NULL);

    //-------------------
    // [3-5] Setup execution frame:

    MT3620Blink_Program___c__DisplayClass1_0__ctor_EXECUTION_FRAME__ frame__ =
        { NULL, 1 };
    il2c_link_execution_frame(&frame__);

    //-------------------
    // [3-6] IL body:

    /* IL_0000: ldarg.0  */
    frame__.stack0_0__ = this__;
    /* IL_0001: call System.Object..ctor */
    System_Object__ctor((System_Object*)frame__.stack0_0__);
    /* IL_0006: nop  */
    /* IL_0007: ret  */
    il2c_unlink_execution_frame(&frame__);
    return;
}

//////////////////////
// [7] Runtime helpers:

// [7-10-1] VTable (Not defined, same as System.Object)

// [7-8] Runtime type information
IL2C_RUNTIME_TYPE_BEGIN(MT3620Blink_Program___c__DisplayClass1_0, "MT3620Blink.Program.<>c__DisplayClass1_0", IL2C_TYPE_REFERENCE, sizeof(MT3620Blink_Program___c__DisplayClass1_0), System_Object, 1, 0)
    IL2C_RUNTIME_TYPE_MARK_TARGET_FOR_REFERENCE(MT3620Blink_Program___c__DisplayClass1_0, led)
IL2C_RUNTIME_TYPE_END();

//////////////////////////////////////////////////////////////////////////////////
// [9-4] Type: MT3620Blink.Program.<>c__DisplayClass1_1

///////////////////////////////////////
// [3] MT3620Blink.Program.<>c__DisplayClass1_1..ctor(MT3620Blink.Program.<>c__DisplayClass1_1 this__)

//-------------------
// [3-7] Declare execution frame:

typedef struct MT3620Blink_Program___c__DisplayClass1_1__ctor_EXECUTION_FRAME_DECL
{
    const IL2C_EXECUTION_FRAME* pNext__;
    const uint16_t objRefCount__;
    const uint16_t valueCount__;
    //-------------------- objref
    MT3620Blink_Program___c__DisplayClass1_1* stack0_0__;
} MT3620Blink_Program___c__DisplayClass1_1__ctor_EXECUTION_FRAME__;

//-------------------
// [3-2] Function body:

void MT3620Blink_Program___c__DisplayClass1_1__ctor(MT3620Blink_Program___c__DisplayClass1_1* this__)
{
    il2c_assert(this__ != NULL);

    //-------------------
    // [3-5] Setup execution frame:

    MT3620Blink_Program___c__DisplayClass1_1__ctor_EXECUTION_FRAME__ frame__ =
        { NULL, 1 };
    il2c_link_execution_frame(&frame__);

    //-------------------
    // [3-6] IL body:

    /* IL_0000: ldarg.0  */
    frame__.stack0_0__ = this__;
    /* IL_0001: call System.Object..ctor */
    System_Object__ctor((System_Object*)frame__.stack0_0__);
    /* IL_0006: nop  */
    /* IL_0007: ret  */
    il2c_unlink_execution_frame(&frame__);
    return;
}

//////////////////////
// [7] Runtime helpers:

// [7-10-1] VTable (Not defined, same as System.Object)

// [7-8] Runtime type information
IL2C_RUNTIME_TYPE_BEGIN(MT3620Blink_Program___c__DisplayClass1_1, "MT3620Blink.Program.<>c__DisplayClass1_1", IL2C_TYPE_REFERENCE, sizeof(MT3620Blink_Program___c__DisplayClass1_1), System_Object, 2, 0)
    IL2C_RUNTIME_TYPE_MARK_TARGET_FOR_REFERENCE(MT3620Blink_Program___c__DisplayClass1_1, timer)
    IL2C_RUNTIME_TYPE_MARK_TARGET_FOR_REFERENCE(MT3620Blink_Program___c__DisplayClass1_1, CS___8__locals1)
IL2C_RUNTIME_TYPE_END();

//////////////////////////////////////////////////////////////////////////////////
// [9-4] Type: MT3620Blink.Program.<>c__DisplayClass1_2

///////////////////////////////////////
// [3] MT3620Blink.Program.<>c__DisplayClass1_2..ctor(MT3620Blink.Program.<>c__DisplayClass1_2 this__)

//-------------------
// [3-7] Declare execution frame:

typedef struct MT3620Blink_Program___c__DisplayClass1_2__ctor_EXECUTION_FRAME_DECL
{
    const IL2C_EXECUTION_FRAME* pNext__;
    const uint16_t objRefCount__;
    const uint16_t valueCount__;
    //-------------------- objref
    MT3620Blink_Program___c__DisplayClass1_2* stack0_0__;
} MT3620Blink_Program___c__DisplayClass1_2__ctor_EXECUTION_FRAME__;

//-------------------
// [3-2] Function body:

void MT3620Blink_Program___c__DisplayClass1_2__ctor(MT3620Blink_Program___c__DisplayClass1_2* this__)
{
    il2c_assert(this__ != NULL);

    //-------------------
    // [3-5] Setup execution frame:

    MT3620Blink_Program___c__DisplayClass1_2__ctor_EXECUTION_FRAME__ frame__ =
        { NULL, 1 };
    il2c_link_execution_frame(&frame__);

    //-------------------
    // [3-6] IL body:

    /* IL_0000: ldarg.0  */
    frame__.stack0_0__ = this__;
    /* IL_0001: call System.Object..ctor */
    System_Object__ctor((System_Object*)frame__.stack0_0__);
    /* IL_0006: nop  */
    /* IL_0007: ret  */
    il2c_unlink_execution_frame(&frame__);
    return;
}

///////////////////////////////////////
// [3] MT3620Blink.Program.<>c__DisplayClass1_2.<Main>b__0(MT3620Blink.Program.<>c__DisplayClass1_2 this__)

//-------------------
// [3-7] Declare execution frame:

typedef struct MT3620Blink_Program___c__DisplayClass1_2__Main_b__0_EXECUTION_FRAME_DECL
{
    const IL2C_EXECUTION_FRAME* pNext__;
    const uint16_t objRefCount__;
    const uint16_t valueCount__;
    //-------------------- objref
    MT3620Blink_Program___c__DisplayClass1_2* stack0_0__;
    MT3620Blink_Program___c__DisplayClass1_1* stack0_1__;
    MT3620Blink_Program___c__DisplayClass1_0* stack0_2__;
    MT3620Blink_GpioOutput* stack0_3__;
    MT3620Blink_Program___c__DisplayClass1_2* stack1_0__;
} MT3620Blink_Program___c__DisplayClass1_2__Main_b__0_EXECUTION_FRAME__;

//-------------------
// [3-2] Function body:

void MT3620Blink_Program___c__DisplayClass1_2__Main_b__0(MT3620Blink_Program___c__DisplayClass1_2* this__)
{
    il2c_assert(this__ != NULL);

    //-------------------
    // [3-4] Evaluation stacks (!objref):

    bool stack1_1__;
    int32_t stack1_2__;
    int32_t stack2_0__;

    //-------------------
    // [3-5] Setup execution frame:

    MT3620Blink_Program___c__DisplayClass1_2__Main_b__0_EXECUTION_FRAME__ frame__ =
        { NULL, 5 };
    il2c_link_execution_frame(&frame__);

    //-------------------
    // [3-6] IL body:

    /* IL_0000: nop                             : Program.cs(36) */
    /* IL_0001: ldarg.0  */
    frame__.stack0_0__ = this__;
    /* IL_0002: ldfld MT3620Blink.Program.<>c__DisplayClass1_2.CS$<>8__locals2 : Program.cs(37) */
    frame__.stack0_1__ = frame__.stack0_0__->CS___8__locals2;
    /* IL_0007: ldfld MT3620Blink.Program.<>c__DisplayClass1_1.CS$<>8__locals1 : Program.cs(37) */
    frame__.stack0_2__ = frame__.stack0_1__->CS___8__locals1;
    /* IL_000c: ldfld MT3620Blink.Program.<>c__DisplayClass1_0.led : Program.cs(37) */
    frame__.stack0_3__ = frame__.stack0_2__->led;
    /* IL_0011: ldarg.0                         : Program.cs(37) */
    frame__.stack1_0__ = this__;
    /* IL_0012: ldfld MT3620Blink.Program.<>c__DisplayClass1_2.flag : Program.cs(37) */
    stack1_1__ = frame__.stack1_0__->flag;
    /* IL_0017: callvirt MT3620Blink.GpioOutput.SetValue : Program.cs(37) */
    MT3620Blink_GpioOutput_SetValue(il2c_adjusted_reference(frame__.stack0_3__), stack1_1__);
    /* IL_001c: nop                             : Program.cs(37) */
    /* IL_001d: ldarg.0  */
    frame__.stack0_0__ = this__;
    /* IL_001e: ldarg.0                         : Program.cs(38) */
    frame__.stack1_0__ = this__;
    /* IL_001f: ldfld MT3620Blink.Program.<>c__DisplayClass1_2.flag : Program.cs(38) */
    stack1_1__ = frame__.stack1_0__->flag;
    /* IL_0024: ldc.i4.0                        : Program.cs(38) */
    stack2_0__ = 0;
    /* IL_0025: ceq                             : Program.cs(38) */
    stack1_2__ = ((int32_t)stack1_1__ == (int32_t)stack2_0__) ? 1 : 0;
    /* IL_0027: stfld MT3620Blink.Program.<>c__DisplayClass1_2.flag : Program.cs(38) */
    frame__.stack0_0__->flag = (stack1_2__) ? true : false;
    /* IL_002c: ret                             : Program.cs(39) */
    il2c_unlink_execution_frame(&frame__);
    return;
}

///////////////////////////////////////
// [3] MT3620Blink.Program.<>c__DisplayClass1_2.<Main>b__1(MT3620Blink.Program.<>c__DisplayClass1_2 this__)

//-------------------
// [3-7] Declare execution frame:

typedef struct MT3620Blink_Program___c__DisplayClass1_2__Main_b__1_EXECUTION_FRAME_DECL
{
    const IL2C_EXECUTION_FRAME* pNext__;
    const uint16_t objRefCount__;
    const uint16_t valueCount__;
    //-------------------- objref
    MT3620Blink_Program___c__DisplayClass1_2* stack0_0__;
    MT3620Blink_Program___c__DisplayClass1_1* stack0_1__;
    MT3620Blink_Timer* stack0_2__;
    MT3620Blink_Program___c__DisplayClass1_2* stack1_0__;
    il2c_arraytype(System_Int64)* stack1_2__;
    MT3620Blink_Program___c__DisplayClass1_2* stack2_1__;
    il2c_arraytype(System_Int64)* stack2_2__;
} MT3620Blink_Program___c__DisplayClass1_2__Main_b__1_EXECUTION_FRAME__;

//-------------------
// [3-2] Function body:

void MT3620Blink_Program___c__DisplayClass1_2__Main_b__1(MT3620Blink_Program___c__DisplayClass1_2* this__)
{
    il2c_assert(this__ != NULL);

    //-------------------
    // [3-4] Evaluation stacks (!objref):

    int32_t stack1_1__;
    int64_t stack1_3__;
    int32_t stack2_0__;
    uintptr_t stack2_3__;

    //-------------------
    // [3-5] Setup execution frame:

    MT3620Blink_Program___c__DisplayClass1_2__Main_b__1_EXECUTION_FRAME__ frame__ =
        { NULL, 7 };
    il2c_link_execution_frame(&frame__);

    //-------------------
    // [3-6] IL body:

    /* IL_0000: nop                             : Program.cs(47) */
    /* IL_0001: ldarg.0  */
    frame__.stack0_0__ = this__;
    /* IL_0002: ldarg.0                         : Program.cs(48) */
    frame__.stack1_0__ = this__;
    /* IL_0003: ldfld MT3620Blink.Program.<>c__DisplayClass1_2.blinkIntervalIndex : Program.cs(48) */
    stack1_1__ = frame__.stack1_0__->blinkIntervalIndex;
    /* IL_0008: ldc.i4.1                        : Program.cs(48) */
    stack2_0__ = 1;
    /* IL_0009: add                             : Program.cs(48) */
    stack1_1__ = stack1_1__ + stack2_0__;
    /* IL_000a: ldarg.0                         : Program.cs(48) */
    frame__.stack2_1__ = this__;
    /* IL_000b: ldfld MT3620Blink.Program.<>c__DisplayClass1_2.blinkIntervals : Program.cs(48) */
    frame__.stack2_2__ = frame__.stack2_1__->blinkIntervals;
    /* IL_0010: ldlen                           : Program.cs(48) */
    stack2_3__ = (uintptr_t)frame__.stack2_2__->Length;
    /* IL_0011: conv.i4                         : Program.cs(48) */
    stack2_0__ = (int32_t)stack2_3__;
    /* IL_0012: rem                             : Program.cs(48) */
    stack1_1__ = stack1_1__ % stack2_0__;
    /* IL_0013: stfld MT3620Blink.Program.<>c__DisplayClass1_2.blinkIntervalIndex : Program.cs(48) */
    frame__.stack0_0__->blinkIntervalIndex = stack1_1__;
    /* IL_0018: ldarg.0                         : Program.cs(49) */
    frame__.stack0_0__ = this__;
    /* IL_0019: ldfld MT3620Blink.Program.<>c__DisplayClass1_2.CS$<>8__locals2 : Program.cs(49) */
    frame__.stack0_1__ = frame__.stack0_0__->CS___8__locals2;
    /* IL_001e: ldfld MT3620Blink.Program.<>c__DisplayClass1_1.timer : Program.cs(49) */
    frame__.stack0_2__ = frame__.stack0_1__->timer;
    /* IL_0023: ldarg.0                         : Program.cs(49) */
    frame__.stack1_0__ = this__;
    /* IL_0024: ldfld MT3620Blink.Program.<>c__DisplayClass1_2.blinkIntervals : Program.cs(49) */
    frame__.stack1_2__ = frame__.stack1_0__->blinkIntervals;
    /* IL_0029: ldarg.0                         : Program.cs(49) */
    frame__.stack2_1__ = this__;
    /* IL_002a: ldfld MT3620Blink.Program.<>c__DisplayClass1_2.blinkIntervalIndex : Program.cs(49) */
    stack2_0__ = frame__.stack2_1__->blinkIntervalIndex;
    /* IL_002f: ldelem.i8                       : Program.cs(49) */
    stack1_3__ = il2c_array_item(frame__.stack1_2__, int64_t, stack2_0__);
    /* IL_0030: callvirt MT3620Blink.Timer.SetInterval : Program.cs(49) */
    MT3620Blink_Timer_SetInterval(il2c_adjusted_reference(frame__.stack0_2__), stack1_3__);
    /* IL_0035: nop                             : Program.cs(49) */
    /* IL_0036: ret  */
    il2c_unlink_execution_frame(&frame__);
    return;
}

//////////////////////
// [7] Runtime helpers:

// [7-10-1] VTable (Not defined, same as System.Object)

// [7-8] Runtime type information
IL2C_RUNTIME_TYPE_BEGIN(MT3620Blink_Program___c__DisplayClass1_2, "MT3620Blink.Program.<>c__DisplayClass1_2", IL2C_TYPE_REFERENCE, sizeof(MT3620Blink_Program___c__DisplayClass1_2), System_Object, 2, 0)
    IL2C_RUNTIME_TYPE_MARK_TARGET_FOR_REFERENCE(MT3620Blink_Program___c__DisplayClass1_2, blinkIntervals)
    IL2C_RUNTIME_TYPE_MARK_TARGET_FOR_REFERENCE(MT3620Blink_Program___c__DisplayClass1_2, CS___8__locals2)
IL2C_RUNTIME_TYPE_END();
