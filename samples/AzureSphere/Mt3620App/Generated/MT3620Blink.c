#include <mt3620_rdb.h>
#include <sys/epoll.h>
#include <unistd.h>
#include <time.h>
#include <sys/timerfd.h>
#include <applibs/gpio.h>
#include "MT3620Blink.h"

//////////////////////////////////////////////////////////////////////////////////
// [12-1] Declared values:

// .<PrivateImplementationDetails>.C55E5D2E10ACF1F04C09C95EC16BC769B727C58F
static const int32_t declaredValue0__[] =
    { 125000000, 250000000, 500000000 };

//////////////////////////////////////////////////////////////////////////////////
// [9-2] File scope prototypes:

#ifdef __cplusplus
extern "C" {
#endif

//////////////////////////////////////////////////////////////////////////////////
// [2-1] Types:

typedef struct MT3620Blink_Descriptor MT3620Blink_Descriptor;
typedef struct timespec MT3620Blink_timespec;
typedef struct itimerspec MT3620Blink_itimerspec;
typedef GPIO_OutputMode_Type MT3620Blink_GPIO_OutputMode_Type;
typedef GPIO_Value_Type MT3620Blink_GPIO_Value_Type;
typedef epoll_data_t MT3620Blink_epoll_data_t;
typedef struct epoll_event MT3620Blink_epoll_event;
typedef struct MT3620Blink_Interops MT3620Blink_Interops;

////////////////////////////////////////////////////////////
// [1] MT3620Blink.Descriptor

// [1-2-1] Class VTable layout (Same as System.Object)
typedef System_Object_VTABLE_DECL__ MT3620Blink_Descriptor_VTABLE_DECL__;

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
// [1] MT3620Blink.timespec

// [1-2-1] Struct VTable layout (Same as System.ValueType)
typedef System_ValueType_VTABLE_DECL__ MT3620Blink_timespec_VTABLE_DECL__;

// [1-5-1] VTable (Same as System.ValueType)
#define MT3620Blink_timespec_VTABLE__ System_ValueType_VTABLE__

// [1-4] Runtime type information
IL2C_DECLARE_RUNTIME_TYPE(MT3620Blink_timespec);

////////////////////////////////////////////////////////////
// [1] MT3620Blink.itimerspec

// [1-2-1] Struct VTable layout (Same as System.ValueType)
typedef System_ValueType_VTABLE_DECL__ MT3620Blink_itimerspec_VTABLE_DECL__;

// [1-5-1] VTable (Same as System.ValueType)
#define MT3620Blink_itimerspec_VTABLE__ System_ValueType_VTABLE__

// [1-4] Runtime type information
IL2C_DECLARE_RUNTIME_TYPE(MT3620Blink_itimerspec);

////////////////////////////////////////////////////////////
// [1] MT3620Blink.GPIO_OutputMode_Type

// [1-2-1] Enum VTable layout (Same as System.Enum)
typedef System_Enum_VTABLE_DECL__ MT3620Blink_GPIO_OutputMode_Type_VTABLE_DECL__;

// [1-5-1] VTable (Same as System.Enum)
#define MT3620Blink_GPIO_OutputMode_Type_VTABLE__ System_Enum_VTABLE__

// [1-4] Runtime type information
IL2C_DECLARE_RUNTIME_TYPE(MT3620Blink_GPIO_OutputMode_Type);

////////////////////////////////////////////////////////////
// [1] MT3620Blink.GPIO_Value_Type

// [1-2-1] Enum VTable layout (Same as System.Enum)
typedef System_Enum_VTABLE_DECL__ MT3620Blink_GPIO_Value_Type_VTABLE_DECL__;

// [1-5-1] VTable (Same as System.Enum)
#define MT3620Blink_GPIO_Value_Type_VTABLE__ System_Enum_VTABLE__

// [1-4] Runtime type information
IL2C_DECLARE_RUNTIME_TYPE(MT3620Blink_GPIO_Value_Type);

////////////////////////////////////////////////////////////
// [1] MT3620Blink.epoll_data_t

// [1-2-1] Struct VTable layout (Same as System.ValueType)
typedef System_ValueType_VTABLE_DECL__ MT3620Blink_epoll_data_t_VTABLE_DECL__;

// [1-5-1] VTable (Same as System.ValueType)
#define MT3620Blink_epoll_data_t_VTABLE__ System_ValueType_VTABLE__

// [1-4] Runtime type information
IL2C_DECLARE_RUNTIME_TYPE(MT3620Blink_epoll_data_t);

////////////////////////////////////////////////////////////
// [1] MT3620Blink.epoll_event

// [1-2-1] Struct VTable layout (Same as System.ValueType)
typedef System_ValueType_VTABLE_DECL__ MT3620Blink_epoll_event_VTABLE_DECL__;

// [1-5-1] VTable (Same as System.ValueType)
#define MT3620Blink_epoll_event_VTABLE__ System_ValueType_VTABLE__

// [1-4] Runtime type information
IL2C_DECLARE_RUNTIME_TYPE(MT3620Blink_epoll_event);

////////////////////////////////////////////////////////////
// [1] MT3620Blink.Interops

// [1-2-1] Class VTable layout (Same as System.Object)
typedef System_Object_VTABLE_DECL__ MT3620Blink_Interops_VTABLE_DECL__;

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
// [2-2] Public static fields:

//////////////////////////////////////////////////////////////////////////////////
// [2-3] Methods:

// [2-4] Member methods: MT3620Blink.Descriptor

extern void MT3620Blink_Descriptor__ctor(MT3620Blink_Descriptor* this__, int32_t fd);
extern void MT3620Blink_Descriptor_Dispose(MT3620Blink_Descriptor* this__);
extern int32_t MT3620Blink_Descriptor_get_Identity(MT3620Blink_Descriptor* this__);

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
// [9-3] Declare static fields:

#define MT3620Blink_Interops_MT3620_RDB_LED1_RED MT3620_RDB_LED1_RED
#define MT3620Blink_Interops_MT3620_RDB_BUTTON_A MT3620_RDB_BUTTON_A
#define MT3620Blink_Interops_EPOLL_CTL_ADD EPOLL_CTL_ADD
#define MT3620Blink_Interops_EPOLLIN EPOLLIN

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
#line 7 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Descriptor.cs"
    il2c_assert(this__ != NULL);

    //-------------------
    // [3-4] Evaluation stacks (!objref):

#line 7 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Descriptor.cs"
    int32_t stack1_0__;

    //-------------------
    // [3-5] Setup execution frame:

    MT3620Blink_Descriptor__ctor_EXECUTION_FRAME__ frame__ =
        { NULL, 1 };
    il2c_link_execution_frame(&frame__);

    //-------------------
    // [3-6] IL body:

    /* IL_0000: ldarg.0  */
#line 7 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Descriptor.cs"
    frame__.stack0_0__ = this__;
    /* IL_0001: call System.Object..ctor */
#line 7 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Descriptor.cs"
    System_Object__ctor((System_Object*)frame__.stack0_0__);
    /* IL_0006: nop  */
    /* IL_0007: nop  */
    /* IL_0008: ldarg.0  */
#line 9 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Descriptor.cs"
    frame__.stack0_0__ = this__;
    /* IL_0009: ldarg.1  */
#line 9 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Descriptor.cs"
    stack1_0__ = fd;
    /* IL_000a: call MT3620Blink.Descriptor.set_Identity */
#line 9 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Descriptor.cs"
    MT3620Blink_Descriptor_set_Identity(frame__.stack0_0__, stack1_0__);
    /* IL_000f: nop  */
    /* IL_0010: ret  */
#line 10 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Descriptor.cs"
    il2c_unlink_execution_frame(&frame__);
#line 10 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Descriptor.cs"
    return;
#line 10 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Descriptor.cs"
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
#line 13 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Descriptor.cs"
    il2c_assert(this__ != NULL);

    //-------------------
    // [3-3] Local variables (!objref):

#line 13 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Descriptor.cs"
    bool local0__ = false;

    //-------------------
    // [3-4] Evaluation stacks (!objref):

#line 13 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Descriptor.cs"
    int32_t stack0_1__;
#line 13 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Descriptor.cs"
    bool stack0_2__;
#line 13 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Descriptor.cs"
    int32_t stack1_0__;

    //-------------------
    // [3-5] Setup execution frame:

    MT3620Blink_Descriptor_Dispose_EXECUTION_FRAME__ frame__ =
        { NULL, 1 };
    il2c_link_execution_frame(&frame__);

    //-------------------
    // [3-6] IL body:

    /* IL_0000: nop  */
    /* IL_0001: ldarg.0  */
#line 14 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Descriptor.cs"
    frame__.stack0_0__ = this__;
    /* IL_0002: call MT3620Blink.Descriptor.get_Identity */
#line 14 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Descriptor.cs"
    stack0_1__ = MT3620Blink_Descriptor_get_Identity(frame__.stack0_0__);
    /* IL_0007: ldc.i4.0  */
#line 14 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Descriptor.cs"
    stack1_0__ = 0;
    /* IL_0008: clt  */
#line 14 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Descriptor.cs"
    stack0_1__ = ((int32_t)stack0_1__ < (int32_t)stack1_0__) ? 1 : 0;
    /* IL_000a: ldc.i4.0  */
#line 14 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Descriptor.cs"
    stack1_0__ = 0;
    /* IL_000b: ceq  */
#line 14 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Descriptor.cs"
    stack0_1__ = ((int32_t)stack0_1__ == (int32_t)stack1_0__) ? 1 : 0;
    /* IL_000d: stloc.0  */
#line 14 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Descriptor.cs"
    local0__ = (stack0_1__) ? true : false;
    /* IL_000e: ldloc.0  */
#line 14 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Descriptor.cs"
    stack0_2__ = local0__;
    /* IL_000f: brfalse.s IL_0027 */
#line 14 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Descriptor.cs"
    if (!(stack0_2__)) goto IL_0027;
    /* IL_0011: nop  */
    /* IL_0012: ldarg.0  */
#line 16 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Descriptor.cs"
    frame__.stack0_0__ = this__;
    /* IL_0013: call MT3620Blink.Descriptor.get_Identity */
#line 16 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Descriptor.cs"
    stack0_1__ = MT3620Blink_Descriptor_get_Identity(frame__.stack0_0__);
    /* IL_0018: call MT3620Blink.Interops.close */
#line 16 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Descriptor.cs"
    stack0_1__ = MT3620Blink_Interops_close(stack0_1__);
    /* IL_001d: pop  */
    /* IL_001e: ldarg.0  */
#line 17 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Descriptor.cs"
    frame__.stack0_0__ = this__;
    /* IL_001f: ldc.i4.m1  */
#line 17 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Descriptor.cs"
    stack1_0__ = -1;
    /* IL_0020: call MT3620Blink.Descriptor.set_Identity */
#line 17 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Descriptor.cs"
    MT3620Blink_Descriptor_set_Identity(frame__.stack0_0__, stack1_0__);
    /* IL_0025: nop  */
    /* IL_0026: nop  */
IL_0027:
    /* IL_0027: ret  */
#line 19 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Descriptor.cs"
    il2c_unlink_execution_frame(&frame__);
#line 19 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Descriptor.cs"
    return;
#line 19 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Descriptor.cs"
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
#line 21 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Descriptor.cs"
    il2c_assert(this__ != NULL);

    //-------------------
    // [3-4] Evaluation stacks (!objref):

#line 21 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Descriptor.cs"
    int32_t stack0_1__;

    //-------------------
    // [3-5] Setup execution frame:

    MT3620Blink_Descriptor_get_Identity_EXECUTION_FRAME__ frame__ =
        { NULL, 1 };
    il2c_link_execution_frame(&frame__);

    //-------------------
    // [3-6] IL body:

    /* IL_0000: ldarg.0  */
#line 21 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Descriptor.cs"
    frame__.stack0_0__ = this__;
    /* IL_0001: ldfld MT3620Blink.Descriptor.<Identity>k__BackingField */
#line 21 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Descriptor.cs"
    stack0_1__ = frame__.stack0_0__->_Identity_k__BackingField;
    /* IL_0006: ret  */
#line 21 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Descriptor.cs"
    il2c_unlink_execution_frame(&frame__);
#line 21 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Descriptor.cs"
    return stack0_1__;
#line 21 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Descriptor.cs"
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
#line 21 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Descriptor.cs"
    il2c_assert(this__ != NULL);

    //-------------------
    // [3-4] Evaluation stacks (!objref):

#line 21 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Descriptor.cs"
    int32_t stack1_0__;

    //-------------------
    // [3-5] Setup execution frame:

    MT3620Blink_Descriptor_set_Identity_EXECUTION_FRAME__ frame__ =
        { NULL, 1 };
    il2c_link_execution_frame(&frame__);

    //-------------------
    // [3-6] IL body:

    /* IL_0000: ldarg.0  */
#line 21 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Descriptor.cs"
    frame__.stack0_0__ = this__;
    /* IL_0001: ldarg.1  */
#line 21 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Descriptor.cs"
    stack1_0__ = value;
    /* IL_0002: stfld MT3620Blink.Descriptor.<Identity>k__BackingField */
#line 21 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Descriptor.cs"
    frame__.stack0_0__->_Identity_k__BackingField = stack1_0__;
    /* IL_0007: ret  */
#line 21 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Descriptor.cs"
    il2c_unlink_execution_frame(&frame__);
#line 21 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Descriptor.cs"
    return;
#line 21 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Descriptor.cs"
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
// [6] InternalCall: MT3620Blink.Interops.close(System.Int32 fd)

int32_t MT3620Blink_Interops_close(int32_t fd)
{
    return close(fd);
}

///////////////////////////////////////
// [6] InternalCall: MT3620Blink.Interops.nanosleep(MT3620Blink.timespec& req, MT3620Blink.timespec& rem)

void MT3620Blink_Interops_nanosleep(MT3620Blink_timespec* req, MT3620Blink_timespec* rem)
{
    nanosleep(req, rem);
}

///////////////////////////////////////
// [6] InternalCall: MT3620Blink.Interops.timerfd_create(System.Int32 clockid, System.Int32 flags)

int32_t MT3620Blink_Interops_timerfd_create(int32_t clockid, int32_t flags)
{
    return timerfd_create(clockid, flags);
}

///////////////////////////////////////
// [6] InternalCall: MT3620Blink.Interops.timerfd_settime(System.Int32 fd, System.Int32 flags, MT3620Blink.itimerspec& new_value, MT3620Blink.itimerspec& old_value)

int32_t MT3620Blink_Interops_timerfd_settime(int32_t fd, int32_t flags, MT3620Blink_itimerspec* new_value, MT3620Blink_itimerspec* old_value)
{
    return timerfd_settime(fd, flags, new_value, old_value);
}

///////////////////////////////////////
// [6] InternalCall: MT3620Blink.Interops.GPIO_OpenAsOutput(System.Int32 gpioId, MT3620Blink.GPIO_OutputMode_Type outputMode, MT3620Blink.GPIO_Value_Type initialValue)

int32_t MT3620Blink_Interops_GPIO_OpenAsOutput(int32_t gpioId, MT3620Blink_GPIO_OutputMode_Type outputMode, MT3620Blink_GPIO_Value_Type initialValue)
{
    return GPIO_OpenAsOutput(gpioId, outputMode, initialValue);
}

///////////////////////////////////////
// [6] InternalCall: MT3620Blink.Interops.GPIO_SetValue(System.Int32 gpioFd, MT3620Blink.GPIO_Value_Type value)

int32_t MT3620Blink_Interops_GPIO_SetValue(int32_t gpioFd, MT3620Blink_GPIO_Value_Type value)
{
    return GPIO_SetValue(gpioFd, value);
}

///////////////////////////////////////
// [6] InternalCall: MT3620Blink.Interops.GPIO_OpenAsInput(System.Int32 gpioId)

int32_t MT3620Blink_Interops_GPIO_OpenAsInput(int32_t gpioId)
{
    return GPIO_OpenAsInput(gpioId);
}

///////////////////////////////////////
// [6] InternalCall: MT3620Blink.Interops.GPIO_GetValue(System.Int32 gpioFd, MT3620Blink.GPIO_Value_Type& value)

int32_t MT3620Blink_Interops_GPIO_GetValue(int32_t gpioFd, MT3620Blink_GPIO_Value_Type* value)
{
    return GPIO_GetValue(gpioFd, value);
}

///////////////////////////////////////
// [6] InternalCall: MT3620Blink.Interops.epoll_create1(System.Int32 flags)

int32_t MT3620Blink_Interops_epoll_create1(int32_t flags)
{
    return epoll_create1(flags);
}

///////////////////////////////////////
// [6] InternalCall: MT3620Blink.Interops.epoll_ctl(System.Int32 epollfd, System.Int32 op, System.Int32 fd, MT3620Blink.epoll_event& ev)

int32_t MT3620Blink_Interops_epoll_ctl(int32_t epollfd, int32_t op, int32_t fd, MT3620Blink_epoll_event* ev)
{
    return epoll_ctl(epollfd, op, fd, ev);
}

///////////////////////////////////////
// [6] InternalCall: MT3620Blink.Interops.epoll_wait(System.Int32 epollfd, MT3620Blink.epoll_event& ev, System.Int32 maxevents, System.Int32 timeout)

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

#line 12 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    MT3620Blink_timespec sleepTime;
#line 12 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    il2c_memset(&sleepTime, 0x00, sizeof sleepTime);
#line 12 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    MT3620Blink_timespec dummy;
#line 12 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    il2c_memset(&dummy, 0x00, sizeof dummy);
#line 12 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    MT3620Blink_timespec local2__;
#line 12 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    il2c_memset(&local2__, 0x00, sizeof local2__);

    //-------------------
    // [3-4] Evaluation stacks (!objref):

#line 12 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    MT3620Blink_timespec* stack0_0__;
#line 12 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    MT3620Blink_timespec stack0_1__;
#line 12 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    int32_t stack1_0__;
#line 12 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    MT3620Blink_timespec* stack1_1__;

    //-------------------
    // [3-6] IL body:

    /* IL_0000: nop  */
    /* IL_0001: ldloca.s local2__ */
#line 13 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    stack0_0__ = &local2__;
    /* IL_0003: initobj MT3620Blink.timespec */
#line 13 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    il2c_memset(stack0_0__, 0x00, sizeof(MT3620Blink_timespec));
    /* IL_0009: ldloca.s local2__ */
#line 13 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    stack0_0__ = &local2__;
    /* IL_000b: ldarg.0  */
#line 13 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    stack1_0__ = nsec;
    /* IL_000c: stfld MT3620Blink.timespec.tv_nsec */
#line 13 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    stack0_0__->tv_nsec = stack1_0__;
    /* IL_0011: ldloc.2  */
#line 13 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    stack0_1__ = local2__;
    /* IL_0012: stloc.0  */
#line 13 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    sleepTime = stack0_1__;
    /* IL_0013: ldloca.s sleepTime */
#line 14 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    stack0_0__ = &sleepTime;
    /* IL_0015: ldloca.s dummy */
#line 14 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    stack1_1__ = &dummy;
    /* IL_0017: call MT3620Blink.Interops.nanosleep */
#line 14 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    MT3620Blink_Interops_nanosleep(stack0_0__, stack1_1__);
    /* IL_001c: nop  */
    /* IL_001d: ret  */
#line 15 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    return;
#line 15 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
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

//-------------------
// [3-7] Declare execution frame:

typedef struct MT3620Blink_Program_Main_EXECUTION_FRAME_DECL
{
    const IL2C_EXECUTION_FRAME* pNext__;
    const uint16_t objRefCount__;
    const uint16_t valueCount__;
    //-------------------- objref
    MT3620Blink_Descriptor* led;
    il2c_arraytype(System_Int32)* blinkIntervals;
    MT3620Blink_Descriptor* stack0_1__;
    il2c_arraytype(System_Int32)* stack0_2__;
    il2c_arraytype(System_Int32)* stack1_1__;
} MT3620Blink_Program_Main_EXECUTION_FRAME__;

//-------------------
// [3-2] Function body:

int32_t MT3620Blink_Program_Main(void)
{
    //-------------------
    // [3-3] Local variables (!objref):

#line 18 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    volatile int32_t buttonFd = 0;
#line 18 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    volatile bool flag = false;
#line 18 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    volatile int32_t blinkIntervalIndex = 0;
#line 18 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    volatile MT3620Blink_GPIO_Value_Type lastButtonValue;
#line 18 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    il2c_memset(&lastButtonValue, 0x00, sizeof lastButtonValue);
#line 18 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    volatile MT3620Blink_GPIO_Value_Type buttonValue;
#line 18 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    il2c_memset(&buttonValue, 0x00, sizeof buttonValue);
#line 18 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    volatile bool local7__ = false;
#line 18 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    volatile bool local8__ = false;
#line 18 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    volatile bool local9__ = false;

    //-------------------
    // [3-4] Evaluation stacks (!objref):

#line 18 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    int32_t stack0_0__;
#line 18 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    bool stack0_3__;
#line 18 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    MT3620Blink_GPIO_Value_Type stack0_4__;
#line 18 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    int32_t stack1_0__;
#line 18 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    bool stack1_2__;
#line 18 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    MT3620Blink_GPIO_Value_Type* stack1_3__;
#line 18 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    MT3620Blink_GPIO_Value_Type stack1_4__;
#line 18 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    uintptr_t stack1_5__;
#line 18 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    int32_t stack2_0__;
#line 18 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    System_RuntimeFieldHandle stack2_1__;

    //-------------------
    // [3-5] Setup execution frame:

    MT3620Blink_Program_Main_EXECUTION_FRAME__ frame__ =
        { NULL, 5 };
    il2c_link_execution_frame(&frame__);

    //-------------------
    // [3-6] IL body:

    /* IL_0000: nop  */
    /* IL_0001: ldsfld MT3620Blink.Interops.MT3620_RDB_LED1_RED */
#line 19 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    stack0_0__ = MT3620Blink_Interops_MT3620_RDB_LED1_RED;
    /* IL_0006: ldc.i4.0  */
#line 19 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    stack1_0__ = 0;
    /* IL_0007: ldc.i4.1  */
#line 19 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    stack2_0__ = 1;
    /* IL_0008: call MT3620Blink.Interops.GPIO_OpenAsOutput */
#line 19 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    stack0_0__ = MT3620Blink_Interops_GPIO_OpenAsOutput(stack0_0__, (MT3620Blink_GPIO_OutputMode_Type)stack1_0__, (MT3620Blink_GPIO_Value_Type)stack2_0__);
    /* IL_000d: newobj MT3620Blink.Descriptor..ctor */
#line 19 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    frame__.stack0_1__ = il2c_get_uninitialized_object(MT3620Blink_Descriptor);
#line 19 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    MT3620Blink_Descriptor__ctor(frame__.stack0_1__, stack0_0__);
    /* IL_0012: stloc.0  */
#line 19 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    frame__.led = frame__.stack0_1__;
#line 24 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    il2c_try(nest0, MT3620Blink_Program_Main_ExceptionFilter0__)
#line 24 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    {
        /* IL_0013: nop  */
        /* IL_0014: ldsfld MT3620Blink.Interops.MT3620_RDB_BUTTON_A */
#line 25 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
        stack0_0__ = MT3620Blink_Interops_MT3620_RDB_BUTTON_A;
        /* IL_0019: call MT3620Blink.Interops.GPIO_OpenAsInput */
#line 25 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
        stack0_0__ = MT3620Blink_Interops_GPIO_OpenAsInput(stack0_0__);
        /* IL_001e: stloc.1  */
#line 25 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
        buttonFd = stack0_0__;
        /* IL_001f: ldc.i4.0  */
#line 28 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
        stack0_0__ = 0;
        /* IL_0020: stloc.2  */
#line 28 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
        flag = (stack0_0__) ? true : false;
        /* IL_0021: ldc.i4.3  */
#line 29 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
        stack0_0__ = 3;
        /* IL_0022: newarr System.Int32 */
#line 29 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
        frame__.stack0_2__ = il2c_new_array(System_Int32, stack0_0__);
        /* IL_0027: dup  */
#line 29 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
        frame__.stack1_1__ = frame__.stack0_2__;
        /* IL_0028: ldtoken .<PrivateImplementationDetails>.C55E5D2E10ACF1F04C09C95EC16BC769B727C58F */
#line 29 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
        stack2_1__.size__ = sizeof(declaredValue0__);
#line 29 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
        stack2_1__.field__ = declaredValue0__;
        /* IL_002d: call System.Runtime.CompilerServices.RuntimeHelpers.InitializeArray */
#line 29 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
        System_Runtime_CompilerServices_RuntimeHelpers_InitializeArray((System_Array*)frame__.stack1_1__, stack2_1__);
        /* IL_0032: stloc.3  */
#line 29 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
        frame__.blinkIntervals = frame__.stack0_2__;
        /* IL_0033: ldc.i4.0  */
#line 30 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
        stack0_0__ = 0;
        /* IL_0034: stloc.s blinkIntervalIndex */
#line 30 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
        blinkIntervalIndex = stack0_0__;
        /* IL_0036: ldc.i4.1  */
#line 31 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
        stack0_0__ = 1;
        /* IL_0037: stloc.s lastButtonValue */
#line 31 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
        lastButtonValue = (MT3620Blink_GPIO_Value_Type)stack0_0__;
        /* IL_0039: br.s IL_0094 */
#line 31 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
        goto IL_0094;
    IL_003b:
        /* IL_003b: nop  */
        /* IL_003c: ldloc.0  */
#line 35 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
        frame__.stack0_1__ = frame__.led;
        /* IL_003d: callvirt MT3620Blink.Descriptor.get_Identity */
#line 35 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
        stack0_0__ = MT3620Blink_Descriptor_get_Identity(il2c_adjusted_reference(frame__.stack0_1__));
        /* IL_0042: ldloc.2  */
#line 35 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
        stack1_2__ = flag;
        /* IL_0043: brtrue.s IL_0048 */
#line 35 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
        if (stack1_2__) goto IL_0048;
        /* IL_0045: ldc.i4.0  */
#line 35 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
        stack1_0__ = 0;
        /* IL_0046: br.s IL_0049 */
#line 35 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
        goto IL_0049;
    IL_0048:
        /* IL_0048: ldc.i4.1  */
#line 35 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
        stack1_0__ = 1;
    IL_0049:
        /* IL_0049: call MT3620Blink.Interops.GPIO_SetValue */
#line 35 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
        stack0_0__ = MT3620Blink_Interops_GPIO_SetValue(stack0_0__, (MT3620Blink_GPIO_Value_Type)stack1_0__);
        /* IL_004e: pop  */
        /* IL_004f: ldloc.2  */
#line 38 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
        stack0_3__ = flag;
        /* IL_0050: ldc.i4.0  */
#line 38 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
        stack1_0__ = 0;
        /* IL_0051: ceq  */
#line 38 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
        stack0_0__ = ((int32_t)stack0_3__ == (int32_t)stack1_0__) ? 1 : 0;
        /* IL_0053: stloc.2  */
#line 38 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
        flag = (stack0_0__) ? true : false;
        /* IL_0054: ldloc.1  */
#line 40 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
        stack0_0__ = buttonFd;
        /* IL_0055: ldloca.s buttonValue */
#line 40 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
        stack1_3__ = &buttonValue;
        /* IL_0057: call MT3620Blink.Interops.GPIO_GetValue */
#line 40 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
        stack0_0__ = MT3620Blink_Interops_GPIO_GetValue(stack0_0__, stack1_3__);
        /* IL_005c: pop  */
        /* IL_005d: ldloc.s buttonValue */
#line 41 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
        stack0_4__ = buttonValue;
        /* IL_005f: ldloc.s lastButtonValue */
#line 41 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
        stack1_4__ = lastButtonValue;
        /* IL_0061: ceq  */
#line 41 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
        stack0_0__ = ((int32_t)stack0_4__ == (int32_t)stack1_4__) ? 1 : 0;
        /* IL_0063: ldc.i4.0  */
#line 41 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
        stack1_0__ = 0;
        /* IL_0064: ceq  */
#line 41 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
        stack0_0__ = ((int32_t)stack0_0__ == (int32_t)stack1_0__) ? 1 : 0;
        /* IL_0066: stloc.s local7__ */
#line 41 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
        local7__ = (stack0_0__) ? true : false;
        /* IL_0068: ldloc.s local7__ */
#line 41 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
        stack0_3__ = local7__;
        /* IL_006a: brfalse.s IL_0085 */
#line 41 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
        if (!(stack0_3__)) goto IL_0085;
        /* IL_006c: nop  */
        /* IL_006d: ldloc.s buttonValue */
#line 43 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
        stack0_4__ = buttonValue;
        /* IL_006f: ldc.i4.0  */
#line 43 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
        stack1_0__ = 0;
        /* IL_0070: ceq  */
#line 43 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
        stack0_0__ = ((int32_t)stack0_4__ == (int32_t)stack1_0__) ? 1 : 0;
        /* IL_0072: stloc.s local8__ */
#line 43 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
        local8__ = (stack0_0__) ? true : false;
        /* IL_0074: ldloc.s local8__ */
#line 43 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
        stack0_3__ = local8__;
        /* IL_0076: brfalse.s IL_0084 */
#line 43 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
        if (!(stack0_3__)) goto IL_0084;
        /* IL_0078: nop  */
        /* IL_0079: ldloc.s blinkIntervalIndex */
#line 45 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
        stack0_0__ = blinkIntervalIndex;
        /* IL_007b: ldc.i4.1  */
#line 45 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
        stack1_0__ = 1;
        /* IL_007c: add  */
#line 45 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
        stack0_0__ = stack0_0__ + stack1_0__;
        /* IL_007d: ldloc.3  */
#line 45 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
        frame__.stack1_1__ = frame__.blinkIntervals;
        /* IL_007e: ldlen  */
#line 45 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
        stack1_5__ = (uintptr_t)frame__.stack1_1__->Length;
        /* IL_007f: conv.i4  */
#line 45 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
        stack1_0__ = (int32_t)stack1_5__;
        /* IL_0080: rem  */
#line 45 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
        stack0_0__ = stack0_0__ % stack1_0__;
        /* IL_0081: stloc.s blinkIntervalIndex */
#line 45 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
        blinkIntervalIndex = stack0_0__;
        /* IL_0083: nop  */
    IL_0084:
        /* IL_0084: nop  */
    IL_0085:
        /* IL_0085: ldloc.s buttonValue */
#line 48 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
        stack0_4__ = buttonValue;
        /* IL_0087: stloc.s lastButtonValue */
#line 48 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
        lastButtonValue = stack0_4__;
        /* IL_0089: ldloc.3  */
#line 50 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
        frame__.stack0_2__ = frame__.blinkIntervals;
        /* IL_008a: ldloc.s blinkIntervalIndex */
#line 50 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
        stack1_0__ = blinkIntervalIndex;
        /* IL_008c: ldelem.i4  */
#line 50 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
        stack0_0__ = il2c_array_item(frame__.stack0_2__, int32_t, stack1_0__);
        /* IL_008d: call MT3620Blink.Program.sleep */
#line 50 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
        MT3620Blink_Program_sleep(stack0_0__);
        /* IL_0092: nop  */
        /* IL_0093: nop  */
    IL_0094:
        /* IL_0094: ldc.i4.1  */
#line 33 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
        stack0_0__ = 1;
        /* IL_0095: stloc.s local9__ */
#line 33 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
        local9__ = (stack0_0__) ? true : false;
        /* IL_0097: br.s IL_003b */
#line 33 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
        goto IL_003b;
#line 33 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    }
#line 33 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    il2c_finally(nest0)
#line 33 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    {
        /* IL_0099: ldloc.0  */
#line 33 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
        frame__.stack0_1__ = frame__.led;
        /* IL_009a: brfalse.s IL_00a3 */
#line 33 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
        if (frame__.stack0_1__ == NULL) goto IL_00a3;
        /* IL_009c: ldloc.0  */
#line 33 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
        frame__.stack0_1__ = frame__.led;
        /* IL_009d: callvirt System.IDisposable.Dispose */
#line 33 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
        MT3620Blink_Descriptor_Dispose(il2c_adjusted_reference(frame__.stack0_1__));
        /* IL_00a2: nop  */
    IL_00a3:
        /* IL_00a3: endfinally  */
#line 33 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
        il2c_endfinally(nest0);
#line 33 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    }
#line 33 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    il2c_end_try(nest0);
#line 33 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
}

//////////////////////
// [7] Runtime helpers:

// [7-10-1] VTable (Not defined, same as System.Object)

// [7-8] Runtime type information
IL2C_RUNTIME_TYPE_BEGIN(MT3620Blink_Program, "MT3620Blink.Program", IL2C_TYPE_REFERENCE, sizeof(MT3620Blink_Program), System_Object, 0, 0)
IL2C_RUNTIME_TYPE_END();
