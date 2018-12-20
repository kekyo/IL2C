#include <mt3620_rdb.h>
#include <sys/epoll.h>
#include <time.h>
#include <applibs/gpio.h>
#include "MT3620Blink.h"

//////////////////////////////////////////////////////////////////////////////////
// [9-2] File scope prototypes:

#ifdef __cplusplus
extern "C" {
#endif

//////////////////////////////////////////////////////////////////////////////////
// [2-1] Types:

typedef struct timespec MT3620Blink_timespec;
typedef GPIO_OutputMode_Type MT3620Blink_GPIO_OutputMode_Type;
typedef GPIO_Value_Type MT3620Blink_GPIO_Value_Type;
typedef epoll_data_t MT3620Blink_epoll_data_t;
typedef struct epoll_event MT3620Blink_epoll_event;
typedef struct MT3620Blink_Interops MT3620Blink_Interops;

////////////////////////////////////////////////////////////
// [1] MT3620Blink.timespec

// [1-2-1] Struct VTable layout (Same as System.ValueType)
typedef System_ValueType_VTABLE_DECL__ MT3620Blink_timespec_VTABLE_DECL__;

// [1-5-1] VTable (Same as System.ValueType)
#define MT3620Blink_timespec_VTABLE__ System_ValueType_VTABLE__

// [1-4] Runtime type information
IL2C_DECLARE_RUNTIME_TYPE(MT3620Blink_timespec);

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

// [2-4] Member methods: MT3620Blink.Interops

extern /* static */ void MT3620Blink_Interops_nanosleep(MT3620Blink_timespec* time, MT3620Blink_timespec* dummy);
extern /* static */ int32_t MT3620Blink_Interops_GPIO_OpenAsOutput(int32_t gpioId, MT3620Blink_GPIO_OutputMode_Type outputMode, MT3620Blink_GPIO_Value_Type initialValue);
extern /* static */ int32_t MT3620Blink_Interops_GPIO_SetValue(int32_t gpioFd, MT3620Blink_GPIO_Value_Type value);
extern /* static */ int32_t MT3620Blink_Interops_epoll_create1(int32_t flags);
extern /* static */ int32_t MT3620Blink_Interops_epoll_ctl(int32_t epollfd, int32_t op, int32_t fd, MT3620Blink_epoll_event* ev);
extern /* static */ int32_t MT3620Blink_Interops_epoll_wait(int32_t epollfd, MT3620Blink_epoll_event* ev, int32_t maxevents, int32_t timeout);

#ifdef __cplusplus
}
#endif

//////////////////////////////////////////////////////////////////////////////////
// [9-3] Declare static fields:

#define MT3620Blink_Interops_MT3620_RDB_LED1_RED MT3620_RDB_LED1_RED
#define MT3620Blink_Interops_EPOLL_CTL_ADD EPOLL_CTL_ADD
#define MT3620Blink_Interops_EPOLLIN EPOLLIN

//////////////////////////////////////////////////////////////////////////////////
// [9-4] Type: MT3620Blink.timespec

//////////////////////
// [7] Runtime helpers:

// [7-10-1] VTable (Not defined, same as System.ValueType)

// [7-8] Runtime type information
IL2C_RUNTIME_TYPE_BEGIN(MT3620Blink_timespec, "MT3620Blink.timespec", IL2C_TYPE_VALUE, sizeof(MT3620Blink_timespec), System_ValueType, 0, 0)
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
// [6] InternalCall: MT3620Blink.Interops.nanosleep(MT3620Blink.timespec& time, MT3620Blink.timespec& dummy)

void MT3620Blink_Interops_nanosleep(MT3620Blink_timespec* time, MT3620Blink_timespec* dummy)
{
    nanosleep(time, dummy);
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
// [3] MT3620Blink.Program.sleep()

//-------------------
// [3-2] Function body:

void MT3620Blink_Program_sleep(void)
{
    //-------------------
    // [3-3] Local variables (!objref):

    MT3620Blink_timespec sleepTime;
    il2c_memset(&sleepTime, 0, sizeof sleepTime);
    MT3620Blink_timespec dummy;
    il2c_memset(&dummy, 0, sizeof dummy);
    MT3620Blink_timespec local2__;
    il2c_memset(&local2__, 0, sizeof local2__);

    //-------------------
    // [3-4] Evaluation stacks (!objref):

    MT3620Blink_timespec* stack0_0__;
    MT3620Blink_timespec stack0_1__;
    int32_t stack1_0__;
    MT3620Blink_timespec* stack1_1__;

    //-------------------
    // [3-6] IL body:
/* D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs(16): */

    /* IL_0000: nop  */
    /* IL_0001: ldloca.s local2__ */
    stack0_0__ = &local2__;
    /* IL_0003: initobj MT3620Blink.timespec */
    il2c_memset(stack0_0__, 0x00, sizeof(MT3620Blink_timespec));
    /* IL_0009: ldloca.s local2__ */
    stack0_0__ = &local2__;
    /* IL_000b: ldc.i4.1  */
    stack1_0__ = 1;
    /* IL_000c: stfld MT3620Blink.timespec.tv_sec */
    stack0_0__->tv_sec = stack1_0__;
    /* IL_0011: ldloc.2  */
    stack0_1__ = local2__;
    /* IL_0012: stloc.0  */
    sleepTime = stack0_1__;
/* D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs(18): */
    /* IL_0013: ldloca.s dummy */
    stack0_0__ = &dummy;
    /* IL_0015: initobj MT3620Blink.timespec */
    il2c_memset(stack0_0__, 0x00, sizeof(MT3620Blink_timespec));
/* D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs(20): */
    /* IL_001b: ldloca.s sleepTime */
    stack0_0__ = &sleepTime;
    /* IL_001d: ldloca.s dummy */
    stack1_1__ = &dummy;
    /* IL_001f: call MT3620Blink.Interops.nanosleep */
    MT3620Blink_Interops_nanosleep(stack0_0__, stack1_1__);
    /* IL_0024: nop  */
/* D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs(21): */
    /* IL_0025: ret  */
    return;
}

///////////////////////////////////////
// [3] MT3620Blink.Program.Main()

//-------------------
// [3-2] Function body:

int32_t MT3620Blink_Program_Main(void)
{
    //-------------------
    // [3-3] Local variables (!objref):

    int32_t ledFd = 0;
    int32_t epollFd = 0;
    bool flag = false;
    int32_t index = 0;
    bool local4__ = false;
    bool local5__ = false;

    //-------------------
    // [3-4] Evaluation stacks (!objref):

    int32_t stack0_0__;
    bool stack0_1__;
    int32_t stack1_0__;
    bool stack1_1__;
    int32_t stack2_0__;

    //-------------------
    // [3-6] IL body:
/* D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs(24): */

    /* IL_0000: nop  */
    /* IL_0001: ldsfld MT3620Blink.Interops.MT3620_RDB_LED1_RED */
    stack0_0__ = MT3620Blink_Interops_MT3620_RDB_LED1_RED;
    /* IL_0006: ldc.i4.0  */
    stack1_0__ = 0;
    /* IL_0007: ldc.i4.1  */
    stack2_0__ = 1;
    /* IL_0008: call MT3620Blink.Interops.GPIO_OpenAsOutput */
    stack0_0__ = MT3620Blink_Interops_GPIO_OpenAsOutput(stack0_0__, (MT3620Blink_GPIO_OutputMode_Type)stack1_0__, (MT3620Blink_GPIO_Value_Type)stack2_0__);
    /* IL_000d: stloc.0  */
    ledFd = stack0_0__;
/* D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs(30): */
    /* IL_000e: ldc.i4.0  */
    stack0_0__ = 0;
    /* IL_000f: call MT3620Blink.Interops.epoll_create1 */
    stack0_0__ = MT3620Blink_Interops_epoll_create1(stack0_0__);
    /* IL_0014: stloc.1  */
    epollFd = stack0_0__;
/* D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs(32): */
    /* IL_0015: ldc.i4.0  */
    stack0_0__ = 0;
    /* IL_0016: stloc.2  */
    flag = (stack0_0__) ? true : false;
    /* IL_0017: br.s IL_004c */
    goto IL_004c;
IL_0019:
/* D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs(35): */
    /* IL_0019: nop  */
    /* IL_001a: ldc.i4.0  */
    stack0_0__ = 0;
    /* IL_001b: stloc.3  */
    index = stack0_0__;
    /* IL_001c: br.s IL_003d */
    goto IL_003d;
IL_001e:
/* D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs(37): */
    /* IL_001e: nop  */
    /* IL_001f: ldloc.0  */
    stack0_0__ = ledFd;
    /* IL_0020: ldloc.2  */
    stack1_1__ = flag;
    /* IL_0021: brtrue.s IL_0026 */
    if (stack1_1__) goto IL_0026;
    /* IL_0023: ldc.i4.0  */
    stack1_0__ = 0;
    /* IL_0024: br.s IL_0027 */
    goto IL_0027;
IL_0026:
    /* IL_0026: ldc.i4.1  */
    stack1_0__ = 1;
IL_0027:
    /* IL_0027: call MT3620Blink.Interops.GPIO_SetValue */
    stack0_0__ = MT3620Blink_Interops_GPIO_SetValue(stack0_0__, (MT3620Blink_GPIO_Value_Type)stack1_0__);
    /* IL_002c: pop  */
/* D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs(39): */
    /* IL_002d: ldloc.2  */
    stack0_1__ = flag;
    /* IL_002e: ldc.i4.0  */
    stack1_0__ = 0;
    /* IL_002f: ceq  */
    stack0_0__ = ((int32_t)stack0_1__ == (int32_t)stack1_0__) ? 1 : 0;
    /* IL_0031: stloc.2  */
    flag = (stack0_0__) ? true : false;
/* D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs(41): */
    /* IL_0032: call MT3620Blink.Program.sleep */
    MT3620Blink_Program_sleep();
    /* IL_0037: nop  */
/* D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs(42): */
    /* IL_0038: nop  */
    /* IL_0039: ldloc.3  */
    stack0_0__ = index;
    /* IL_003a: ldc.i4.1  */
    stack1_0__ = 1;
    /* IL_003b: add  */
    stack0_0__ = stack0_0__ + stack1_0__;
    /* IL_003c: stloc.3  */
    index = stack0_0__;
IL_003d:
/* D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs(36): */
    /* IL_003d: ldloc.3  */
    stack0_0__ = index;
    /* IL_003e: ldc.i4 10000 */
    stack1_0__ = 10000;
    /* IL_0043: clt  */
    stack0_0__ = ((int32_t)stack0_0__ < (int32_t)stack1_0__) ? 1 : 0;
    /* IL_0045: stloc.s local4__ */
    local4__ = (stack0_0__) ? true : false;
    /* IL_0047: ldloc.s local4__ */
    stack0_1__ = local4__;
    /* IL_0049: brtrue.s IL_001e */
    if (stack0_1__) goto IL_001e;
/* D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs(43): */
    /* IL_004b: nop  */
IL_004c:
    /* IL_004c: ldc.i4.1  */
    stack0_0__ = 1;
    /* IL_004d: stloc.s local5__ */
    local5__ = (stack0_0__) ? true : false;
    /* IL_004f: br.s IL_0019 */
    goto IL_0019;
}

//////////////////////
// [7] Runtime helpers:

// [7-10-1] VTable (Not defined, same as System.Object)

// [7-8] Runtime type information
IL2C_RUNTIME_TYPE_BEGIN(MT3620Blink_Program, "MT3620Blink.Program", IL2C_TYPE_REFERENCE, sizeof(MT3620Blink_Program), System_Object, 0, 0)
IL2C_RUNTIME_TYPE_END();
