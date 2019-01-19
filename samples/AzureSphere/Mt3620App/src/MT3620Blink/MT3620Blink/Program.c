// This is MT3620Blink native code translated by IL2C, do not edit.

#include <MT3620Blink.h>
#include <MT3620Blink_internal.h>

#ifdef __cplusplus
extern "C" {
#endif

//////////////////////////////////////////////////////////////////////////////////
// [9-2] File scope prototypes:

//////////////////////////////////////////////////////////////////////////////////
// [9-3] Static field instances:

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
    il2c_memset(stack0_0__, 0x00, sizeof *stack0_0__);
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
    /* IL_0013: ldloca.s dummy */
#line 14 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    stack0_0__ = &dummy;
    /* IL_0015: initobj MT3620Blink.timespec */
#line 14 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    il2c_memset(stack0_0__, 0x00, sizeof *stack0_0__);
    /* IL_001b: ldloca.s sleepTime */
#line 16 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    stack0_0__ = &sleepTime;
    /* IL_001d: ldloca.s dummy */
#line 16 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    stack1_1__ = &dummy;
    /* IL_001f: call MT3620Blink.Interops.nanosleep */
#line 16 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    MT3620Blink_Interops_nanosleep(stack0_0__, stack1_1__);
    /* IL_0024: nop  */
    /* IL_0025: ret  */
#line 17 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    return;
#line 17 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
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

#line 20 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    int32_t ledFd = 0;
#line 20 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    int32_t buttonFd = 0;
#line 20 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    bool flag = false;
#line 20 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    int32_t blinkIntervalIndex = 0;
#line 20 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    MT3620Blink_GPIO_Value_Type lastButtonValue;
#line 20 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    il2c_memset(&lastButtonValue, 0x00, sizeof lastButtonValue);
#line 20 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    MT3620Blink_GPIO_Value_Type buttonValue;
#line 20 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    il2c_memset(&buttonValue, 0x00, sizeof buttonValue);
#line 20 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    bool local7__ = false;
#line 20 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    bool local8__ = false;
#line 20 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    bool local9__ = false;

    //-------------------
    // [3-4] Evaluation stacks (!objref):

#line 20 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    int32_t stack0_0__;
#line 20 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    bool stack0_2__;
#line 20 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    MT3620Blink_GPIO_Value_Type stack0_3__;
#line 20 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    int32_t stack1_0__;
#line 20 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    bool stack1_2__;
#line 20 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    MT3620Blink_GPIO_Value_Type* stack1_3__;
#line 20 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    MT3620Blink_GPIO_Value_Type stack1_4__;
#line 20 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    uintptr_t stack1_5__;
#line 20 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    int32_t stack2_0__;
#line 20 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    System_RuntimeFieldHandle stack2_1__;

    //-------------------
    // [3-5] Setup execution frame:

#line 20 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    MT3620Blink_Program_Main_EXECUTION_FRAME__ frame__ =
        { NULL, 3 };
#line 20 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    il2c_link_execution_frame(&frame__);

    //-------------------
    // [3-6] IL body:

    /* IL_0000: nop  */
    /* IL_0001: ldsfld MT3620Blink.Interops.MT3620_RDB_LED1_RED */
#line 21 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    stack0_0__ = MT3620Blink_Interops_MT3620_RDB_LED1_RED;
    /* IL_0006: ldc.i4.0  */
#line 21 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    stack1_0__ = 0;
    /* IL_0007: ldc.i4.1  */
#line 21 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    stack2_0__ = 1;
    /* IL_0008: call MT3620Blink.Interops.GPIO_OpenAsOutput */
#line 21 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    stack0_0__ = MT3620Blink_Interops_GPIO_OpenAsOutput(stack0_0__, (MT3620Blink_GPIO_OutputMode_Type)stack1_0__, (MT3620Blink_GPIO_Value_Type)stack2_0__);
    /* IL_000d: stloc.0  */
#line 21 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    ledFd = stack0_0__;
    /* IL_000e: ldsfld MT3620Blink.Interops.MT3620_RDB_BUTTON_A */
#line 26 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    stack0_0__ = MT3620Blink_Interops_MT3620_RDB_BUTTON_A;
    /* IL_0013: call MT3620Blink.Interops.GPIO_OpenAsInput */
#line 26 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    stack0_0__ = MT3620Blink_Interops_GPIO_OpenAsInput(stack0_0__);
    /* IL_0018: stloc.1  */
#line 26 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    buttonFd = stack0_0__;
    /* IL_0019: ldc.i4.0  */
#line 29 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    stack0_0__ = 0;
    /* IL_001a: stloc.2  */
#line 29 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    flag = (bool)stack0_0__;
    /* IL_001b: ldc.i4.3  */
#line 30 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    stack0_0__ = 3;
    /* IL_001c: newarr System.Int32 */
#line 30 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    frame__.stack0_1__ = il2c_new_array(System_Int32, stack0_0__);
    /* IL_0021: dup  */
#line 30 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    frame__.stack1_1__ = frame__.stack0_1__;
    /* IL_0022: ldtoken .<PrivateImplementationDetails>.C55E5D2E10ACF1F04C09C95EC16BC769B727C58F */
#line 30 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    stack2_1__.size__ = 12;
#line 30 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    stack2_1__.field__ = MT3620Blink_declaredValue0__;
    /* IL_0027: call System.Runtime.CompilerServices.RuntimeHelpers.InitializeArray */
#line 30 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    System_Runtime_CompilerServices_RuntimeHelpers_InitializeArray((System_Array*)frame__.stack1_1__, stack2_1__);
    /* IL_002c: stloc.3  */
#line 30 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    frame__.blinkIntervals = frame__.stack0_1__;
    /* IL_002d: ldc.i4.0  */
#line 31 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    stack0_0__ = 0;
    /* IL_002e: stloc.s blinkIntervalIndex */
#line 31 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    blinkIntervalIndex = stack0_0__;
    /* IL_0030: ldc.i4.1  */
#line 32 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    stack0_0__ = 1;
    /* IL_0031: stloc.s lastButtonValue */
#line 32 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    lastButtonValue = (MT3620Blink_GPIO_Value_Type)stack0_0__;
    /* IL_0033: br.s IL_0089 */
#line 32 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    goto IL_0089;
IL_0035:
    /* IL_0035: nop  */
    /* IL_0036: ldloc.0  */
#line 36 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    stack0_0__ = ledFd;
    /* IL_0037: ldloc.2  */
#line 36 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    stack1_2__ = flag;
    /* IL_0038: brtrue.s IL_003d */
#line 36 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    if (stack1_2__ != false) goto IL_003d;
    /* IL_003a: ldc.i4.0  */
#line 36 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    stack1_0__ = 0;
    /* IL_003b: br.s IL_003e */
#line 36 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    goto IL_003e;
IL_003d:
    /* IL_003d: ldc.i4.1  */
#line 36 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    stack1_0__ = 1;
IL_003e:
    /* IL_003e: call MT3620Blink.Interops.GPIO_SetValue */
#line 36 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    stack0_0__ = MT3620Blink_Interops_GPIO_SetValue(stack0_0__, (MT3620Blink_GPIO_Value_Type)stack1_0__);
    /* IL_0043: pop  */
    /* IL_0044: ldloc.2  */
#line 39 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    stack0_2__ = flag;
    /* IL_0045: ldc.i4.0  */
#line 39 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    stack1_0__ = 0;
    /* IL_0046: ceq  */
#line 39 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    stack0_0__ = (int32_t)stack0_2__ == (int32_t)stack1_0__;
    /* IL_0048: stloc.2  */
#line 39 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    flag = (bool)stack0_0__;
    /* IL_0049: ldloc.1  */
#line 41 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    stack0_0__ = buttonFd;
    /* IL_004a: ldloca.s buttonValue */
#line 41 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    stack1_3__ = &buttonValue;
    /* IL_004c: call MT3620Blink.Interops.GPIO_GetValue */
#line 41 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    stack0_0__ = MT3620Blink_Interops_GPIO_GetValue(stack0_0__, stack1_3__);
    /* IL_0051: pop  */
    /* IL_0052: ldloc.s buttonValue */
#line 42 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    stack0_3__ = buttonValue;
    /* IL_0054: ldloc.s lastButtonValue */
#line 42 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    stack1_4__ = lastButtonValue;
    /* IL_0056: ceq  */
#line 42 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    stack0_0__ = (int32_t)stack0_3__ == (int32_t)stack1_4__;
    /* IL_0058: ldc.i4.0  */
#line 42 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    stack1_0__ = 0;
    /* IL_0059: ceq  */
#line 42 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    stack0_0__ = (int32_t)stack0_0__ == (int32_t)stack1_0__;
    /* IL_005b: stloc.s local7__ */
#line 42 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    local7__ = (bool)stack0_0__;
    /* IL_005d: ldloc.s local7__ */
#line 42 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    stack0_2__ = local7__;
    /* IL_005f: brfalse.s IL_007a */
#line 42 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    if (stack0_2__ == false) goto IL_007a;
    /* IL_0061: nop  */
    /* IL_0062: ldloc.s buttonValue */
#line 44 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    stack0_3__ = buttonValue;
    /* IL_0064: ldc.i4.0  */
#line 44 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    stack1_0__ = 0;
    /* IL_0065: ceq  */
#line 44 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    stack0_0__ = (int32_t)stack0_3__ == (int32_t)stack1_0__;
    /* IL_0067: stloc.s local8__ */
#line 44 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    local8__ = (bool)stack0_0__;
    /* IL_0069: ldloc.s local8__ */
#line 44 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    stack0_2__ = local8__;
    /* IL_006b: brfalse.s IL_0079 */
#line 44 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    if (stack0_2__ == false) goto IL_0079;
    /* IL_006d: nop  */
    /* IL_006e: ldloc.s blinkIntervalIndex */
#line 46 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    stack0_0__ = blinkIntervalIndex;
    /* IL_0070: ldc.i4.1  */
#line 46 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    stack1_0__ = 1;
    /* IL_0071: add  */
#line 46 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    stack0_0__ = stack0_0__ + stack1_0__;
    /* IL_0072: ldloc.3  */
#line 46 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    frame__.stack1_1__ = frame__.blinkIntervals;
    /* IL_0073: ldlen  */
#line 46 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    stack1_5__ = (uintptr_t)frame__.stack1_1__->Length;
    /* IL_0074: conv.i4  */
#line 46 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    stack1_0__ = (int32_t)stack1_5__;
    /* IL_0075: rem  */
#line 46 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    stack0_0__ = stack0_0__ % stack1_0__;
    /* IL_0076: stloc.s blinkIntervalIndex */
#line 46 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    blinkIntervalIndex = stack0_0__;
    /* IL_0078: nop  */
IL_0079:
    /* IL_0079: nop  */
IL_007a:
    /* IL_007a: ldloc.s buttonValue */
#line 49 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    stack0_3__ = buttonValue;
    /* IL_007c: stloc.s lastButtonValue */
#line 49 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    lastButtonValue = stack0_3__;
    /* IL_007e: ldloc.3  */
#line 51 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    frame__.stack0_1__ = frame__.blinkIntervals;
    /* IL_007f: ldloc.s blinkIntervalIndex */
#line 51 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    stack1_0__ = blinkIntervalIndex;
    /* IL_0081: ldelem.i4  */
#line 51 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    stack0_0__ = il2c_array_item(frame__.stack0_1__, int32_t, stack1_0__);
    /* IL_0082: call MT3620Blink.Program.sleep */
#line 51 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    MT3620Blink_Program_sleep(stack0_0__);
    /* IL_0087: nop  */
    /* IL_0088: nop  */
IL_0089:
    /* IL_0089: ldc.i4.1  */
#line 34 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    stack0_0__ = 1;
    /* IL_008a: stloc.s local9__ */
#line 34 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    local9__ = (bool)stack0_0__;
    /* IL_008c: br.s IL_0035 */
#line 34 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
    goto IL_0035;
#line 34 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\Program.cs"
}

//////////////////////
// [7] Runtime helpers:

// [7-10-1] VTable (Not defined, same as System.Object)

// [7-8] Runtime type information
IL2C_RUNTIME_TYPE_BEGIN(MT3620Blink_Program, "MT3620Blink.Program", IL2C_TYPE_REFERENCE, sizeof(MT3620Blink_Program), System_Object, 0, 0)
IL2C_RUNTIME_TYPE_END();

#ifdef __cplusplus
}
#endif
