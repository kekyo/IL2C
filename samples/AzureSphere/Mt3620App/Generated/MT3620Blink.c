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
// [9-4] Type: MT3620Blink.Program

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
    System_String* stack0_2__;
    il2c_boxedtype(System_Int32)* stack1_1__;
} MT3620Blink_Program_Main_EXECUTION_FRAME__;

//-------------------
// [3-2] Function body:

int32_t MT3620Blink_Program_Main(void)
{
    //-------------------
    // [3-3] Local variables (!objref):

    int32_t index = 0;
    bool local1__ = false;
    bool local2__ = false;

    //-------------------
    // [3-4] Evaluation stacks (!objref):

    int32_t stack0_0__;
    bool stack0_1__;
    int32_t stack1_0__;

    //-------------------
    // [3-5] Setup execution frame:

    MT3620Blink_Program_Main_EXECUTION_FRAME__ frame__ =
        { NULL, 2 };
    il2c_link_execution_frame(&frame__);

    //-------------------
    // [3-6] IL body:
/* D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs(13): */

    /* IL_0000: nop  */
    /* IL_0001: br.s IL_0031 */
    goto IL_0031;
IL_0003:
/* D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs(15): */
    /* IL_0003: nop  */
    /* IL_0004: ldc.i4.0  */
    stack0_0__ = 0;
    /* IL_0005: stloc.0  */
    index = stack0_0__;
    /* IL_0006: br.s IL_0024 */
    goto IL_0024;
IL_0008:
/* D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs(17): */
    /* IL_0008: nop  */
    /* IL_0009: ldstr "Hello Azure Sphere with C#! " */
    frame__.stack0_2__ = string0__;
    /* IL_000e: ldloc.0  */
    stack1_0__ = index;
    /* IL_000f: box System.Int32 */
    frame__.stack1_1__ = il2c_box(&stack1_0__, System_Int32);
    /* IL_0014: call System.String.Concat */
    frame__.stack0_2__ = System_String_Concat_4((System_Object*)frame__.stack0_2__, (System_Object*)frame__.stack1_1__);
    /* IL_0019: call System.Console.WriteLine */
    System_Console_WriteLine_10(frame__.stack0_2__);
    /* IL_001e: nop  */
/* D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs(19): */
    /* IL_001f: nop  */
    /* IL_0020: ldloc.0  */
    stack0_0__ = index;
    /* IL_0021: ldc.i4.1  */
    stack1_0__ = 1;
    /* IL_0022: add  */
    stack0_0__ = stack0_0__ + stack1_0__;
    /* IL_0023: stloc.0  */
    index = stack0_0__;
IL_0024:
/* D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs(16): */
    /* IL_0024: ldloc.0  */
    stack0_0__ = index;
    /* IL_0025: ldc.i4 10000 */
    stack1_0__ = 10000;
    /* IL_002a: clt  */
    stack0_0__ = ((int32_t)stack0_0__ < (int32_t)stack1_0__) ? 1 : 0;
    /* IL_002c: stloc.1  */
    local1__ = (stack0_0__) ? true : false;
    /* IL_002d: ldloc.1  */
    stack0_1__ = local1__;
    /* IL_002e: brtrue.s IL_0008 */
    if (stack0_1__) goto IL_0008;
/* D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs(20): */
    /* IL_0030: nop  */
IL_0031:
    /* IL_0031: ldc.i4.1  */
    stack0_0__ = 1;
    /* IL_0032: stloc.2  */
    local2__ = (stack0_0__) ? true : false;
    /* IL_0033: br.s IL_0003 */
    goto IL_0003;
}

//////////////////////
// [7] Runtime helpers:

// [7-10-1] VTable (Not defined, same as System.Object)

// [7-8] Runtime type information
IL2C_RUNTIME_TYPE_BEGIN(MT3620Blink_Program, "MT3620Blink.Program", IL2C_TYPE_REFERENCE, sizeof(MT3620Blink_Program), System_Object, 0, 0)
IL2C_RUNTIME_TYPE_END();
