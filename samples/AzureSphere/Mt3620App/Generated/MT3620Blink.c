#include <mt3620_rdb.h>
#include <sys/epoll.h>
#include <unistd.h>
#include <time.h>
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

extern /* static */ int32_t MT3620Blink_Interops_close(int32_t fd);
extern /* static */ void MT3620Blink_Interops_nanosleep(MT3620Blink_timespec* time, MT3620Blink_timespec* dummy);
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
// [6] InternalCall: MT3620Blink.Interops.close(System.Int32 fd)

int32_t MT3620Blink_Interops_close(int32_t fd)
{
    return close(fd);
}

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
/* D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs(12): */

    /* IL_0000: nop  */
    /* IL_0001: ldloca.s local2__ */
    stack0_0__ = &local2__;
    /* IL_0003: initobj MT3620Blink.timespec */
    il2c_memset(stack0_0__, 0x00, sizeof(MT3620Blink_timespec));
    /* IL_0009: ldloca.s local2__ */
    stack0_0__ = &local2__;
    /* IL_000b: ldarg.0  */
    stack1_0__ = nsec;
    /* IL_000c: stfld MT3620Blink.timespec.tv_nsec */
    stack0_0__->tv_nsec = stack1_0__;
    /* IL_0011: ldloc.2  */
    stack0_1__ = local2__;
    /* IL_0012: stloc.0  */
    sleepTime = stack0_1__;
/* D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs(14): */
    /* IL_0013: ldloca.s dummy */
    stack0_0__ = &dummy;
    /* IL_0015: initobj MT3620Blink.timespec */
    il2c_memset(stack0_0__, 0x00, sizeof(MT3620Blink_timespec));
/* D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs(16): */
    /* IL_001b: ldloca.s sleepTime */
    stack0_0__ = &sleepTime;
    /* IL_001d: ldloca.s dummy */
    stack1_1__ = &dummy;
    /* IL_001f: call MT3620Blink.Interops.nanosleep */
    MT3620Blink_Interops_nanosleep(stack0_0__, stack1_1__);
    /* IL_0024: nop  */
/* D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs(17): */
    /* IL_0025: ret  */
    return;
}

///////////////////////////////////////
// [3] MT3620Blink.Program.Main()

//-------------------
// [3-7] Declare execution frame:

typedef struct MT3620Blink_Program_Main_EXECUTION_FRAME_DECL
{
    const IL2C_EXECUTION_FRAME* pNext__;
    const uint16_t objRefCount__;
    const uint16_t valueCount__;
    //-------------------- objref
    il2c_arraytype(System_Int32)* blinkIntervals;
    il2c_arraytype(System_Int32)* stack0_1__;
    il2c_arraytype(System_Int32)* stack1_1__;
} MT3620Blink_Program_Main_EXECUTION_FRAME__;

//-------------------
// [3-2] Function body:

int32_t MT3620Blink_Program_Main(void)
{
    //-------------------
    // [3-3] Local variables (!objref):

    int32_t ledFd = 0;
    int32_t buttonFd = 0;
    bool flag = false;
    int32_t blinkIntervalIndex = 0;
    MT3620Blink_GPIO_Value_Type lastButtonValue;
    il2c_memset(&lastButtonValue, 0, sizeof lastButtonValue);
    MT3620Blink_GPIO_Value_Type buttonValue;
    il2c_memset(&buttonValue, 0, sizeof buttonValue);
    bool local7__ = false;
    bool local8__ = false;
    bool local9__ = false;

    //-------------------
    // [3-4] Evaluation stacks (!objref):

    int32_t stack0_0__;
    bool stack0_2__;
    MT3620Blink_GPIO_Value_Type stack0_3__;
    int32_t stack1_0__;
    bool stack1_2__;
    MT3620Blink_GPIO_Value_Type* stack1_3__;
    MT3620Blink_GPIO_Value_Type stack1_4__;
    uintptr_t stack1_5__;
    int32_t stack2_0__;
    System_RuntimeFieldHandle stack2_1__;

    //-------------------
    // [3-5] Setup execution frame:

    MT3620Blink_Program_Main_EXECUTION_FRAME__ frame__ =
        { NULL, 3 };
    il2c_link_execution_frame(&frame__);

    //-------------------
    // [3-6] IL body:
/* D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs(20): */

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
/* D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs(26): */
    /* IL_000e: ldsfld MT3620Blink.Interops.MT3620_RDB_BUTTON_A */
    stack0_0__ = MT3620Blink_Interops_MT3620_RDB_BUTTON_A;
    /* IL_0013: call MT3620Blink.Interops.GPIO_OpenAsInput */
    stack0_0__ = MT3620Blink_Interops_GPIO_OpenAsInput(stack0_0__);
    /* IL_0018: stloc.1  */
    buttonFd = stack0_0__;
/* D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs(29): */
    /* IL_0019: ldc.i4.0  */
    stack0_0__ = 0;
    /* IL_001a: stloc.2  */
    flag = (stack0_0__) ? true : false;
/* D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs(30): */
    /* IL_001b: ldc.i4.3  */
    stack0_0__ = 3;
    /* IL_001c: newarr System.Int32 */
    frame__.stack0_1__ = il2c_new_array(System_Int32, stack0_0__);
    /* IL_0021: dup  */
    frame__.stack1_1__ = frame__.stack0_1__;
    /* IL_0022: ldtoken .<PrivateImplementationDetails>.C55E5D2E10ACF1F04C09C95EC16BC769B727C58F */
    stack2_1__.size__ = sizeof(declaredValue0__);
    stack2_1__.field__ = declaredValue0__;
    /* IL_0027: call System.Runtime.CompilerServices.RuntimeHelpers.InitializeArray */
    System_Runtime_CompilerServices_RuntimeHelpers_InitializeArray((System_Array*)frame__.stack1_1__, stack2_1__);
    /* IL_002c: stloc.3  */
    frame__.blinkIntervals = frame__.stack0_1__;
/* D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs(31): */
    /* IL_002d: ldc.i4.0  */
    stack0_0__ = 0;
    /* IL_002e: stloc.s blinkIntervalIndex */
    blinkIntervalIndex = stack0_0__;
/* D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs(32): */
    /* IL_0030: ldc.i4.1  */
    stack0_0__ = 1;
    /* IL_0031: stloc.s lastButtonValue */
    lastButtonValue = (MT3620Blink_GPIO_Value_Type)stack0_0__;
    /* IL_0033: br.s IL_0089 */
    goto IL_0089;
IL_0035:
/* D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs(35): */
    /* IL_0035: nop  */
    /* IL_0036: ldloc.0  */
    stack0_0__ = ledFd;
    /* IL_0037: ldloc.2  */
    stack1_2__ = flag;
    /* IL_0038: brtrue.s IL_003d */
    if (stack1_2__) goto IL_003d;
    /* IL_003a: ldc.i4.0  */
    stack1_0__ = 0;
    /* IL_003b: br.s IL_003e */
    goto IL_003e;
IL_003d:
    /* IL_003d: ldc.i4.1  */
    stack1_0__ = 1;
IL_003e:
    /* IL_003e: call MT3620Blink.Interops.GPIO_SetValue */
    stack0_0__ = MT3620Blink_Interops_GPIO_SetValue(stack0_0__, (MT3620Blink_GPIO_Value_Type)stack1_0__);
    /* IL_0043: pop  */
/* D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs(39): */
    /* IL_0044: ldloc.2  */
    stack0_2__ = flag;
    /* IL_0045: ldc.i4.0  */
    stack1_0__ = 0;
    /* IL_0046: ceq  */
    stack0_0__ = ((int32_t)stack0_2__ == (int32_t)stack1_0__) ? 1 : 0;
    /* IL_0048: stloc.2  */
    flag = (stack0_0__) ? true : false;
/* D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs(41): */
    /* IL_0049: ldloc.1  */
    stack0_0__ = buttonFd;
    /* IL_004a: ldloca.s buttonValue */
    stack1_3__ = &buttonValue;
    /* IL_004c: call MT3620Blink.Interops.GPIO_GetValue */
    stack0_0__ = MT3620Blink_Interops_GPIO_GetValue(stack0_0__, stack1_3__);
    /* IL_0051: pop  */
/* D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs(42): */
    /* IL_0052: ldloc.s buttonValue */
    stack0_3__ = buttonValue;
    /* IL_0054: ldloc.s lastButtonValue */
    stack1_4__ = lastButtonValue;
    /* IL_0056: ceq  */
    stack0_0__ = ((int32_t)stack0_3__ == (int32_t)stack1_4__) ? 1 : 0;
    /* IL_0058: ldc.i4.0  */
    stack1_0__ = 0;
    /* IL_0059: ceq  */
    stack0_0__ = ((int32_t)stack0_0__ == (int32_t)stack1_0__) ? 1 : 0;
    /* IL_005b: stloc.s local7__ */
    local7__ = (stack0_0__) ? true : false;
    /* IL_005d: ldloc.s local7__ */
    stack0_2__ = local7__;
    /* IL_005f: brfalse.s IL_007a */
    if (!(stack0_2__)) goto IL_007a;
/* D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs(43): */
    /* IL_0061: nop  */
    /* IL_0062: ldloc.s buttonValue */
    stack0_3__ = buttonValue;
    /* IL_0064: ldc.i4.0  */
    stack1_0__ = 0;
    /* IL_0065: ceq  */
    stack0_0__ = ((int32_t)stack0_3__ == (int32_t)stack1_0__) ? 1 : 0;
    /* IL_0067: stloc.s local8__ */
    local8__ = (stack0_0__) ? true : false;
    /* IL_0069: ldloc.s local8__ */
    stack0_2__ = local8__;
    /* IL_006b: brfalse.s IL_0079 */
    if (!(stack0_2__)) goto IL_0079;
/* D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs(45): */
    /* IL_006d: nop  */
    /* IL_006e: ldloc.s blinkIntervalIndex */
    stack0_0__ = blinkIntervalIndex;
    /* IL_0070: ldc.i4.1  */
    stack1_0__ = 1;
    /* IL_0071: add  */
    stack0_0__ = stack0_0__ + stack1_0__;
    /* IL_0072: ldloc.3  */
    frame__.stack1_1__ = frame__.blinkIntervals;
    /* IL_0073: ldlen  */
    stack1_5__ = (uintptr_t)frame__.stack1_1__->Length;
    /* IL_0074: conv.i4  */
    stack1_0__ = (int32_t)stack1_5__;
    /* IL_0075: rem  */
    stack0_0__ = stack0_0__ % stack1_0__;
    /* IL_0076: stloc.s blinkIntervalIndex */
    blinkIntervalIndex = stack0_0__;
/* D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs(47): */
    /* IL_0078: nop  */
IL_0079:
    /* IL_0079: nop  */
IL_007a:
    /* IL_007a: ldloc.s buttonValue */
    stack0_3__ = buttonValue;
    /* IL_007c: stloc.s lastButtonValue */
    lastButtonValue = stack0_3__;
/* D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs(51): */
    /* IL_007e: ldloc.3  */
    frame__.stack0_1__ = frame__.blinkIntervals;
    /* IL_007f: ldloc.s blinkIntervalIndex */
    stack1_0__ = blinkIntervalIndex;
    /* IL_0081: ldelem.i4  */
    stack0_0__ = il2c_array_item(frame__.stack0_1__, int32_t, stack1_0__);
    /* IL_0082: call MT3620Blink.Program.sleep */
    MT3620Blink_Program_sleep(stack0_0__);
    /* IL_0087: nop  */
/* D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs(52): */
    /* IL_0088: nop  */
IL_0089:
    /* IL_0089: ldc.i4.1  */
    stack0_0__ = 1;
    /* IL_008a: stloc.s local9__ */
    local9__ = (stack0_0__) ? true : false;
    /* IL_008c: br.s IL_0035 */
    goto IL_0035;
}

//////////////////////
// [7] Runtime helpers:

// [7-10-1] VTable (Not defined, same as System.Object)

// [7-8] Runtime type information
IL2C_RUNTIME_TYPE_BEGIN(MT3620Blink_Program, "MT3620Blink.Program", IL2C_TYPE_REFERENCE, sizeof(MT3620Blink_Program), System_Object, 0, 0)
IL2C_RUNTIME_TYPE_END();
