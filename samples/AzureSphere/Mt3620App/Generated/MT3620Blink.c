#include <mt3620_rdb.h>
#include <applibs/gpio.h>
#include <time.h>
#include "MT3620Blink.h"

//////////////////////////////////////////////////////////////////////////////////
// [9-1] Const strings:

IL2C_CONST_STRING(string0__, L"Hello Azure Sphere with C#! ");

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

//////////////////////////////////////////////////////////////////////////////////
// [2-2] Public static fields:

//////////////////////////////////////////////////////////////////////////////////
// [2-3] Methods:

// [2-4] Member methods: MT3620Blink.Program

extern /* static */ int32_t MT3620Blink_Program_Main(void);

#ifdef __cplusplus
}
#endif

//////////////////////////////////////////////////////////////////////////////////
// [9-3] Declare static fields:

#define MT3620Blink_Program_MT3620_RDB_LED1_RED MT3620_RDB_LED1_RED

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
// [9-4] Type: MT3620Blink.Program

///////////////////////////////////////
// [6] InternalCall: MT3620Blink.Program.GPIO_OpenAsOutput(System.Int32 gpioId, MT3620Blink.GPIO_OutputMode_Type outputMode, MT3620Blink.GPIO_Value_Type initialValue)

int32_t MT3620Blink_Program_GPIO_OpenAsOutput(int32_t gpioId, MT3620Blink_GPIO_OutputMode_Type outputMode, MT3620Blink_GPIO_Value_Type initialValue)
{
    return GPIO_OpenAsOutput(gpioId, outputMode, initialValue);
}

///////////////////////////////////////
// [6] InternalCall: MT3620Blink.Program.GPIO_SetValue(System.Int32 gpioFd, MT3620Blink.GPIO_Value_Type value)

int32_t MT3620Blink_Program_GPIO_SetValue(int32_t gpioFd, MT3620Blink_GPIO_Value_Type value)
{
    return GPIO_SetValue(gpioFd, value);
}

///////////////////////////////////////
// [6] InternalCall: MT3620Blink.Program.nanosleep(MT3620Blink.timespec& time, MT3620Blink.timespec& dummy)

void MT3620Blink_Program_nanosleep(MT3620Blink_timespec* time, MT3620Blink_timespec* dummy)
{
    nanosleep(time, dummy);
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
    System_String* stack0_4__;
    il2c_boxedtype(System_Int32)* stack1_2__;
} MT3620Blink_Program_Main_EXECUTION_FRAME__;

//-------------------
// [3-2] Function body:

int32_t MT3620Blink_Program_Main(void)
{
    //-------------------
    // [3-3] Local variables (!objref):

    int32_t fd = 0;
    bool flag = false;
    MT3620Blink_timespec sleepTime;
    il2c_memset(&sleepTime, 0, sizeof sleepTime);
    MT3620Blink_timespec dummy;
    il2c_memset(&dummy, 0, sizeof dummy);
    MT3620Blink_timespec local4__;
    il2c_memset(&local4__, 0, sizeof local4__);
    int32_t index = 0;
    bool local6__ = false;
    bool local7__ = false;

    //-------------------
    // [3-4] Evaluation stacks (!objref):

    int32_t stack0_0__;
    MT3620Blink_timespec* stack0_1__;
    MT3620Blink_timespec stack0_2__;
    bool stack0_3__;
    int32_t stack1_0__;
    bool stack1_1__;
    MT3620Blink_timespec* stack1_3__;
    int32_t stack2_0__;

    //-------------------
    // [3-5] Setup execution frame:

    MT3620Blink_Program_Main_EXECUTION_FRAME__ frame__ =
        { NULL, 2 };
    il2c_link_execution_frame(&frame__);

    //-------------------
    // [3-6] IL body:
/* D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs(54): */

    /* IL_0000: nop  */
    /* IL_0001: ldsfld MT3620Blink.Program.MT3620_RDB_LED1_RED */
    stack0_0__ = MT3620Blink_Program_MT3620_RDB_LED1_RED;
    /* IL_0006: ldc.i4.0  */
    stack1_0__ = 0;
    /* IL_0007: ldc.i4.1  */
    stack2_0__ = 1;
    /* IL_0008: call MT3620Blink.Program.GPIO_OpenAsOutput */
    stack0_0__ = MT3620Blink_Program_GPIO_OpenAsOutput(stack0_0__, (MT3620Blink_GPIO_OutputMode_Type)stack1_0__, (MT3620Blink_GPIO_Value_Type)stack2_0__);
    /* IL_000d: stloc.0  */
    fd = stack0_0__;
/* D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs(60): */
    /* IL_000e: ldc.i4.0  */
    stack0_0__ = 0;
    /* IL_000f: stloc.1  */
    flag = (stack0_0__) ? true : false;
/* D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs(61): */
    /* IL_0010: ldloca.s local4__ */
    stack0_1__ = &local4__;
    /* IL_0012: initobj MT3620Blink.timespec */
    il2c_memset(stack0_1__, 0x00, sizeof(MT3620Blink_timespec));
    /* IL_0018: ldloca.s local4__ */
    stack0_1__ = &local4__;
    /* IL_001a: ldc.i4.1  */
    stack1_0__ = 1;
    /* IL_001b: stfld MT3620Blink.timespec.tv_sec */
    stack0_1__->tv_sec = stack1_0__;
    /* IL_0020: ldloc.s local4__ */
    stack0_2__ = local4__;
    /* IL_0022: stloc.2  */
    sleepTime = stack0_2__;
/* D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs(62): */
    /* IL_0023: ldloca.s dummy */
    stack0_1__ = &dummy;
    /* IL_0025: initobj MT3620Blink.timespec */
    il2c_memset(stack0_1__, 0x00, sizeof(MT3620Blink_timespec));
    /* IL_002b: br.s IL_007f */
    goto IL_007f;
IL_002d:
/* D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs(65): */
    /* IL_002d: nop  */
    /* IL_002e: ldc.i4.0  */
    stack0_0__ = 0;
    /* IL_002f: stloc.s index */
    index = stack0_0__;
    /* IL_0031: br.s IL_006f */
    goto IL_006f;
IL_0033:
/* D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs(67): */
    /* IL_0033: nop  */
    /* IL_0034: ldloc.0  */
    stack0_0__ = fd;
    /* IL_0035: ldloc.1  */
    stack1_1__ = flag;
    /* IL_0036: brtrue.s IL_003b */
    if (stack1_1__) goto IL_003b;
    /* IL_0038: ldc.i4.0  */
    stack1_0__ = 0;
    /* IL_0039: br.s IL_003c */
    goto IL_003c;
IL_003b:
    /* IL_003b: ldc.i4.1  */
    stack1_0__ = 1;
IL_003c:
    /* IL_003c: call MT3620Blink.Program.GPIO_SetValue */
    stack0_0__ = MT3620Blink_Program_GPIO_SetValue(stack0_0__, (MT3620Blink_GPIO_Value_Type)stack1_0__);
    /* IL_0041: pop  */
/* D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs(69): */
    /* IL_0042: ldloc.1  */
    stack0_3__ = flag;
    /* IL_0043: ldc.i4.0  */
    stack1_0__ = 0;
    /* IL_0044: ceq  */
    stack0_0__ = ((int32_t)stack0_3__ == (int32_t)stack1_0__) ? 1 : 0;
    /* IL_0046: stloc.1  */
    flag = (stack0_0__) ? true : false;
/* D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs(71): */
    /* IL_0047: ldstr "Hello Azure Sphere with C#! " */
    frame__.stack0_4__ = string0__;
    /* IL_004c: ldloc.s index */
    stack1_0__ = index;
    /* IL_004e: box System.Int32 */
    frame__.stack1_2__ = il2c_box(&stack1_0__, System_Int32);
    /* IL_0053: call System.String.Concat */
    frame__.stack0_4__ = System_String_Concat_4((System_Object*)frame__.stack0_4__, (System_Object*)frame__.stack1_2__);
    /* IL_0058: call System.Console.WriteLine */
    System_Console_WriteLine_10(frame__.stack0_4__);
    /* IL_005d: nop  */
/* D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs(73): */
    /* IL_005e: ldloca.s sleepTime */
    stack0_1__ = &sleepTime;
    /* IL_0060: ldloca.s dummy */
    stack1_3__ = &dummy;
    /* IL_0062: call MT3620Blink.Program.nanosleep */
    MT3620Blink_Program_nanosleep(stack0_1__, stack1_3__);
    /* IL_0067: nop  */
/* D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs(74): */
    /* IL_0068: nop  */
    /* IL_0069: ldloc.s index */
    stack0_0__ = index;
    /* IL_006b: ldc.i4.1  */
    stack1_0__ = 1;
    /* IL_006c: add  */
    stack0_0__ = stack0_0__ + stack1_0__;
    /* IL_006d: stloc.s index */
    index = stack0_0__;
IL_006f:
/* D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs(66): */
    /* IL_006f: ldloc.s index */
    stack0_0__ = index;
    /* IL_0071: ldc.i4 10000 */
    stack1_0__ = 10000;
    /* IL_0076: clt  */
    stack0_0__ = ((int32_t)stack0_0__ < (int32_t)stack1_0__) ? 1 : 0;
    /* IL_0078: stloc.s local6__ */
    local6__ = (stack0_0__) ? true : false;
    /* IL_007a: ldloc.s local6__ */
    stack0_3__ = local6__;
    /* IL_007c: brtrue.s IL_0033 */
    if (stack0_3__) goto IL_0033;
/* D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs(75): */
    /* IL_007e: nop  */
IL_007f:
    /* IL_007f: ldc.i4.1  */
    stack0_0__ = 1;
    /* IL_0080: stloc.s local7__ */
    local7__ = (stack0_0__) ? true : false;
    /* IL_0082: br.s IL_002d */
    goto IL_002d;
}

//////////////////////
// [7] Runtime helpers:

// [7-10-1] VTable (Not defined, same as System.Object)

// [7-8] Runtime type information
IL2C_RUNTIME_TYPE_BEGIN(MT3620Blink_Program, "MT3620Blink.Program", IL2C_TYPE_REFERENCE, sizeof(MT3620Blink_Program), System_Object, 0, 0)
IL2C_RUNTIME_TYPE_END();
