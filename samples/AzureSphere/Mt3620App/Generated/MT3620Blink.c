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

typedef struct MT3620Blink_timespec MT3620Blink_timespec;

////////////////////////////////////////////////////////////
// [1] MT3620Blink.timespec

// [1-2-1] Struct VTable layout (Same as System.ValueType)
typedef System_ValueType_VTABLE_DECL__ MT3620Blink_timespec_VTABLE_DECL__;

// [1-1-2] Struct layout
struct MT3620Blink_timespec
{
    int32_t tv_sec;
    int32_t tv_nsec;
};

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
// [6] InternalCall: MT3620Blink.Program.nanosleep(MT3620Blink.timespec& time, System.IntPtr dummy)

void MT3620Blink_Program_nanosleep(MT3620Blink_timespec* time, intptr_t dummy)
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
    MT3620Blink_timespec local1__;
    il2c_memset(&local1__, 0, sizeof local1__);
    int32_t index = 0;
    bool local3__ = false;
    bool local4__ = false;

    //-------------------
    // [3-4] Evaluation stacks (!objref):

    MT3620Blink_timespec* stack0_0__;
    MT3620Blink_timespec stack0_1__;
    int32_t stack0_2__;
    bool stack0_3__;
    int32_t stack1_0__;
    intptr_t stack1_2__;

    //-------------------
    // [3-5] Setup execution frame:

    MT3620Blink_Program_Main_EXECUTION_FRAME__ frame__ =
        { NULL, 2 };
    il2c_link_execution_frame(&frame__);

    //-------------------
    // [3-6] IL body:
/* D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs(26): */

    /* IL_0000: nop  */
    /* IL_0001: ldloca.s local1__ */
    stack0_0__ = &local1__;
    /* IL_0003: initobj MT3620Blink.timespec */
    il2c_memset(stack0_0__, 0x00, sizeof(MT3620Blink_timespec));
    /* IL_0009: ldloca.s local1__ */
    stack0_0__ = &local1__;
    /* IL_000b: ldc.i4.1  */
    stack1_0__ = 1;
    /* IL_000c: stfld MT3620Blink.timespec.tv_sec */
    stack0_0__->tv_sec = stack1_0__;
    /* IL_0011: ldloc.1  */
    stack0_1__ = local1__;
    /* IL_0012: stloc.0  */
    sleepTime = stack0_1__;
    /* IL_0013: br.s IL_0050 */
    goto IL_0050;
IL_0015:
/* D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs(30): */
    /* IL_0015: nop  */
    /* IL_0016: ldc.i4.0  */
    stack0_2__ = 0;
    /* IL_0017: stloc.2  */
    index = stack0_2__;
    /* IL_0018: br.s IL_0043 */
    goto IL_0043;
IL_001a:
/* D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs(32): */
    /* IL_001a: nop  */
    /* IL_001b: ldstr "Hello Azure Sphere with C#! " */
    frame__.stack0_4__ = string0__;
    /* IL_0020: ldloc.2  */
    stack1_0__ = index;
    /* IL_0021: box System.Int32 */
    frame__.stack1_1__ = il2c_box(&stack1_0__, System_Int32);
    /* IL_0026: call System.String.Concat */
    frame__.stack0_4__ = System_String_Concat_4((System_Object*)frame__.stack0_4__, (System_Object*)frame__.stack1_1__);
    /* IL_002b: call System.Console.WriteLine */
    System_Console_WriteLine_10(frame__.stack0_4__);
    /* IL_0030: nop  */
/* D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs(34): */
    /* IL_0031: ldloca.s sleepTime */
    stack0_0__ = &sleepTime;
    /* IL_0033: ldsfld System.IntPtr.Zero */
    stack1_2__ = System_IntPtr_System_IntPtr__Zero;
    /* IL_0038: call MT3620Blink.Program.nanosleep */
    MT3620Blink_Program_nanosleep(stack0_0__, stack1_2__);
    /* IL_003d: nop  */
/* D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs(35): */
    /* IL_003e: nop  */
    /* IL_003f: ldloc.2  */
    stack0_2__ = index;
    /* IL_0040: ldc.i4.1  */
    stack1_0__ = 1;
    /* IL_0041: add  */
    stack0_2__ = stack0_2__ + stack1_0__;
    /* IL_0042: stloc.2  */
    index = stack0_2__;
IL_0043:
/* D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs(31): */
    /* IL_0043: ldloc.2  */
    stack0_2__ = index;
    /* IL_0044: ldc.i4 10000 */
    stack1_0__ = 10000;
    /* IL_0049: clt  */
    stack0_2__ = ((int32_t)stack0_2__ < (int32_t)stack1_0__) ? 1 : 0;
    /* IL_004b: stloc.3  */
    local3__ = (stack0_2__) ? true : false;
    /* IL_004c: ldloc.3  */
    stack0_3__ = local3__;
    /* IL_004d: brtrue.s IL_001a */
    if (stack0_3__) goto IL_001a;
/* D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs(36): */
    /* IL_004f: nop  */
IL_0050:
    /* IL_0050: ldc.i4.1  */
    stack0_2__ = 1;
    /* IL_0051: stloc.s local4__ */
    local4__ = (stack0_2__) ? true : false;
    /* IL_0053: br.s IL_0015 */
    goto IL_0015;
}

//////////////////////
// [7] Runtime helpers:

// [7-10-1] VTable (Not defined, same as System.Object)

// [7-8] Runtime type information
IL2C_RUNTIME_TYPE_BEGIN(MT3620Blink_Program, "MT3620Blink.Program", IL2C_TYPE_REFERENCE, sizeof(MT3620Blink_Program), System_Object, 0, 0)
IL2C_RUNTIME_TYPE_END();
