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

////////////////////////////////////////////////////////////
// [1] MT3620Blink.timespec

// [1-2-1] Struct VTable layout (Same as System.ValueType)
typedef System_ValueType_VTABLE_DECL__ MT3620Blink_timespec_VTABLE_DECL__;

// [1-5-1] VTable (Same as System.ValueType)
#define MT3620Blink_timespec_VTABLE__ System_ValueType_VTABLE__

// [1-4] Runtime type information
IL2C_DECLARE_RUNTIME_TYPE(MT3620Blink_timespec);

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

//////////////////////////////////////////////////////////////////////////////////
// [9-4] Type: MT3620Blink.timespec

//////////////////////
// [7] Runtime helpers:

// [7-10-1] VTable (Not defined, same as System.ValueType)

// [7-8] Runtime type information
IL2C_RUNTIME_TYPE_BEGIN(MT3620Blink_timespec, "MT3620Blink.timespec", IL2C_TYPE_VALUE, sizeof(MT3620Blink_timespec), System_ValueType, 0, 0)
IL2C_RUNTIME_TYPE_END();

//////////////////////////////////////////////////////////////////////////////////
// [9-4] Type: MT3620Blink.Program

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

    MT3620Blink_timespec sleepTime;
    il2c_memset(&sleepTime, 0, sizeof sleepTime);
    MT3620Blink_timespec dummy;
    il2c_memset(&dummy, 0, sizeof dummy);
    MT3620Blink_timespec local2__;
    il2c_memset(&local2__, 0, sizeof local2__);
    int32_t index = 0;
    bool local4__ = false;
    bool local5__ = false;

    //-------------------
    // [3-4] Evaluation stacks (!objref):

    MT3620Blink_timespec* stack0_0__;
    MT3620Blink_timespec stack0_1__;
    int32_t stack0_2__;
    bool stack0_3__;
    int32_t stack1_0__;
    MT3620Blink_timespec* stack1_2__;

    //-------------------
    // [3-5] Setup execution frame:

    MT3620Blink_Program_Main_EXECUTION_FRAME__ frame__ =
        { NULL, 2 };
    il2c_link_execution_frame(&frame__);

    //-------------------
    // [3-6] IL body:
/* D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs(27): */

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
/* D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs(29): */
    /* IL_0013: ldloca.s dummy */
    stack0_0__ = &dummy;
    /* IL_0015: initobj MT3620Blink.timespec */
    il2c_memset(stack0_0__, 0x00, sizeof(MT3620Blink_timespec));
    /* IL_001b: br.s IL_0057 */
    goto IL_0057;
IL_001d:
/* D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs(32): */
    /* IL_001d: nop  */
    /* IL_001e: ldc.i4.0  */
    stack0_2__ = 0;
    /* IL_001f: stloc.3  */
    index = stack0_2__;
    /* IL_0020: br.s IL_0048 */
    goto IL_0048;
IL_0022:
/* D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs(34): */
    /* IL_0022: nop  */
    /* IL_0023: ldstr "Hello Azure Sphere with C#! " */
    frame__.stack0_4__ = string0__;
    /* IL_0028: ldloc.3  */
    stack1_0__ = index;
    /* IL_0029: box System.Int32 */
    frame__.stack1_1__ = il2c_box(&stack1_0__, System_Int32);
    /* IL_002e: call System.String.Concat */
    frame__.stack0_4__ = System_String_Concat_4((System_Object*)frame__.stack0_4__, (System_Object*)frame__.stack1_1__);
    /* IL_0033: call System.Console.WriteLine */
    System_Console_WriteLine_10(frame__.stack0_4__);
    /* IL_0038: nop  */
/* D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs(36): */
    /* IL_0039: ldloca.s sleepTime */
    stack0_0__ = &sleepTime;
    /* IL_003b: ldloca.s dummy */
    stack1_2__ = &dummy;
    /* IL_003d: call MT3620Blink.Program.nanosleep */
    MT3620Blink_Program_nanosleep(stack0_0__, stack1_2__);
    /* IL_0042: nop  */
/* D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs(37): */
    /* IL_0043: nop  */
    /* IL_0044: ldloc.3  */
    stack0_2__ = index;
    /* IL_0045: ldc.i4.1  */
    stack1_0__ = 1;
    /* IL_0046: add  */
    stack0_2__ = stack0_2__ + stack1_0__;
    /* IL_0047: stloc.3  */
    index = stack0_2__;
IL_0048:
/* D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs(33): */
    /* IL_0048: ldloc.3  */
    stack0_2__ = index;
    /* IL_0049: ldc.i4 10000 */
    stack1_0__ = 10000;
    /* IL_004e: clt  */
    stack0_2__ = ((int32_t)stack0_2__ < (int32_t)stack1_0__) ? 1 : 0;
    /* IL_0050: stloc.s local4__ */
    local4__ = (stack0_2__) ? true : false;
    /* IL_0052: ldloc.s local4__ */
    stack0_3__ = local4__;
    /* IL_0054: brtrue.s IL_0022 */
    if (stack0_3__) goto IL_0022;
/* D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs(38): */
    /* IL_0056: nop  */
IL_0057:
    /* IL_0057: ldc.i4.1  */
    stack0_2__ = 1;
    /* IL_0058: stloc.s local5__ */
    local5__ = (stack0_2__) ? true : false;
    /* IL_005a: br.s IL_001d */
    goto IL_001d;
}

//////////////////////
// [7] Runtime helpers:

// [7-10-1] VTable (Not defined, same as System.Object)

// [7-8] Runtime type information
IL2C_RUNTIME_TYPE_BEGIN(MT3620Blink_Program, "MT3620Blink.Program", IL2C_TYPE_REFERENCE, sizeof(MT3620Blink_Program), System_Object, 0, 0)
IL2C_RUNTIME_TYPE_END();
