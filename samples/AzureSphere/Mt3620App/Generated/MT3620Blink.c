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

int32_t System_Int32_MT3620Blink_Program__MT3620_RDB_LED1_RED;

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
    il2c_boxedtype(System_Int32)* stack1_1__;
} MT3620Blink_Program_Main_EXECUTION_FRAME__;

//-------------------
// [3-2] Function body:

int32_t MT3620Blink_Program_Main(void)
{
    //-------------------
    // [3-3] Local variables (!objref):

    int32_t fd = 0;
    MT3620Blink_timespec sleepTime;
    il2c_memset(&sleepTime, 0, sizeof sleepTime);
    MT3620Blink_timespec dummy;
    il2c_memset(&dummy, 0, sizeof dummy);
    MT3620Blink_timespec local3__;
    il2c_memset(&local3__, 0, sizeof local3__);
    int32_t index = 0;
    bool local5__ = false;
    bool local6__ = false;

    //-------------------
    // [3-4] Evaluation stacks (!objref):

    int32_t stack0_0__;
    MT3620Blink_timespec* stack0_1__;
    MT3620Blink_timespec stack0_2__;
    bool stack0_3__;
    int32_t stack1_0__;
    MT3620Blink_timespec* stack1_2__;
    int32_t stack2_0__;

    //-------------------
    // [3-5] Setup execution frame:

    MT3620Blink_Program_Main_EXECUTION_FRAME__ frame__ =
        { NULL, 2 };
    il2c_link_execution_frame(&frame__);

    //-------------------
    // [3-6] IL body:
/* D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs(47): */

    /* IL_0000: nop  */
    /* IL_0001: ldsfld MT3620Blink.Program.MT3620_RDB_LED1_RED */
    stack0_0__ = System_Int32_MT3620Blink_Program__MT3620_RDB_LED1_RED;
    /* IL_0006: ldc.i4.0  */
    stack1_0__ = 0;
    /* IL_0007: ldc.i4.0  */
    stack2_0__ = 0;
    /* IL_0008: call MT3620Blink.Program.GPIO_OpenAsOutput */
    stack0_0__ = MT3620Blink_Program_GPIO_OpenAsOutput(stack0_0__, (MT3620Blink_GPIO_OutputMode_Type)stack1_0__, (MT3620Blink_GPIO_Value_Type)stack2_0__);
    /* IL_000d: stloc.0  */
    fd = stack0_0__;
/* D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs(53): */
    /* IL_000e: ldloca.s local3__ */
    stack0_1__ = &local3__;
    /* IL_0010: initobj MT3620Blink.timespec */
    il2c_memset(stack0_1__, 0x00, sizeof(MT3620Blink_timespec));
    /* IL_0016: ldloca.s local3__ */
    stack0_1__ = &local3__;
    /* IL_0018: ldc.i4.1  */
    stack1_0__ = 1;
    /* IL_0019: stfld MT3620Blink.timespec.tv_sec */
    stack0_1__->tv_sec = stack1_0__;
    /* IL_001e: ldloc.3  */
    stack0_2__ = local3__;
    /* IL_001f: stloc.1  */
    sleepTime = stack0_2__;
/* D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs(54): */
    /* IL_0020: ldloca.s dummy */
    stack0_1__ = &dummy;
    /* IL_0022: initobj MT3620Blink.timespec */
    il2c_memset(stack0_1__, 0x00, sizeof(MT3620Blink_timespec));
    /* IL_0028: br.s IL_0069 */
    goto IL_0069;
IL_002a:
/* D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs(57): */
    /* IL_002a: nop  */
    /* IL_002b: ldc.i4.0  */
    stack0_0__ = 0;
    /* IL_002c: stloc.s index */
    index = stack0_0__;
    /* IL_002e: br.s IL_0059 */
    goto IL_0059;
IL_0030:
/* D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs(59): */
    /* IL_0030: nop  */
    /* IL_0031: ldstr "Hello Azure Sphere with C#! " */
    frame__.stack0_4__ = string0__;
    /* IL_0036: ldloc.s index */
    stack1_0__ = index;
    /* IL_0038: box System.Int32 */
    frame__.stack1_1__ = il2c_box(&stack1_0__, System_Int32);
    /* IL_003d: call System.String.Concat */
    frame__.stack0_4__ = System_String_Concat_4((System_Object*)frame__.stack0_4__, (System_Object*)frame__.stack1_1__);
    /* IL_0042: call System.Console.WriteLine */
    System_Console_WriteLine_10(frame__.stack0_4__);
    /* IL_0047: nop  */
/* D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs(61): */
    /* IL_0048: ldloca.s sleepTime */
    stack0_1__ = &sleepTime;
    /* IL_004a: ldloca.s dummy */
    stack1_2__ = &dummy;
    /* IL_004c: call MT3620Blink.Program.nanosleep */
    MT3620Blink_Program_nanosleep(stack0_1__, stack1_2__);
    /* IL_0051: nop  */
/* D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs(62): */
    /* IL_0052: nop  */
    /* IL_0053: ldloc.s index */
    stack0_0__ = index;
    /* IL_0055: ldc.i4.1  */
    stack1_0__ = 1;
    /* IL_0056: add  */
    stack0_0__ = stack0_0__ + stack1_0__;
    /* IL_0057: stloc.s index */
    index = stack0_0__;
IL_0059:
/* D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs(58): */
    /* IL_0059: ldloc.s index */
    stack0_0__ = index;
    /* IL_005b: ldc.i4 10000 */
    stack1_0__ = 10000;
    /* IL_0060: clt  */
    stack0_0__ = ((int32_t)stack0_0__ < (int32_t)stack1_0__) ? 1 : 0;
    /* IL_0062: stloc.s local5__ */
    local5__ = (stack0_0__) ? true : false;
    /* IL_0064: ldloc.s local5__ */
    stack0_3__ = local5__;
    /* IL_0066: brtrue.s IL_0030 */
    if (stack0_3__) goto IL_0030;
/* D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs(63): */
    /* IL_0068: nop  */
IL_0069:
    /* IL_0069: ldc.i4.1  */
    stack0_0__ = 1;
    /* IL_006a: stloc.s local6__ */
    local6__ = (stack0_0__) ? true : false;
    /* IL_006c: br.s IL_002a */
    goto IL_002a;
}

//////////////////////
// [7] Runtime helpers:

// [7-10-1] VTable (Not defined, same as System.Object)

// [7-8] Runtime type information
IL2C_RUNTIME_TYPE_BEGIN(MT3620Blink_Program, "MT3620Blink.Program", IL2C_TYPE_REFERENCE, sizeof(MT3620Blink_Program), System_Object, 0, 0)
IL2C_RUNTIME_TYPE_END();
