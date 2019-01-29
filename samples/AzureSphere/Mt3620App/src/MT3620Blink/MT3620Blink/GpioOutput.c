// [15-2] This is MT3620Blink native code translated by IL2C, do not edit.

#include <MT3620Blink.h>
#include <MT3620Blink_internal.h>

#ifdef __cplusplus
extern "C" {
#endif

//////////////////////////////////////////////////////////////////////////////////
// [9-1] Type: MT3620Blink.GpioOutput

//////////////////////////////////////////////////////////////////////////////////
// [9-2] File scope prototypes:

//////////////////////////////////////////////////////////////////////////////////
// [9-3] Static field instances:

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
#line 6 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\GpioOutput.cs"
    il2c_assert(this__ != NULL);

    //-------------------
    // [3-4] Evaluation stacks (!objref):

#line 6 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\GpioOutput.cs"
    int32_t stack1_0__;
#line 6 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\GpioOutput.cs"
    MT3620Blink_GPIO_OutputMode_Type stack2_0__;
#line 6 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\GpioOutput.cs"
    bool stack3_0__;
#line 6 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\GpioOutput.cs"
    int32_t stack3_1__;

    //-------------------
    // [3-5] Setup execution frame:

#line 6 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\GpioOutput.cs"
    MT3620Blink_GpioOutput__ctor_EXECUTION_FRAME__ frame__ =
        { NULL, 1 };
#line 6 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\GpioOutput.cs"
    il2c_link_execution_frame(&frame__);

    //-------------------
    // [3-6] IL body:

    /* IL_0000: ldarg.0  */
#line 6 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\GpioOutput.cs"
    frame__.stack0_0__ = this__;
    /* IL_0001: ldarg.1  */
#line 6 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\GpioOutput.cs"
    stack1_0__ = gpioId;
    /* IL_0002: ldarg.2  */
#line 6 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\GpioOutput.cs"
    stack2_0__ = type;
    /* IL_0003: ldarg.3  */
#line 6 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\GpioOutput.cs"
    stack3_0__ = initialValue;
    /* IL_0004: brtrue.s IL_0009 */
#line 6 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\GpioOutput.cs"
    if (stack3_0__ != false) goto IL_0009;
    /* IL_0006: ldc.i4.0  */
#line 6 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\GpioOutput.cs"
    stack3_1__ = 0;
    /* IL_0007: br.s IL_000a */
#line 6 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\GpioOutput.cs"
    goto IL_000a;
IL_0009:
    /* IL_0009: ldc.i4.1  */
#line 6 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\GpioOutput.cs"
    stack3_1__ = 1;
IL_000a:
    /* IL_000a: call MT3620Blink.Interops.GPIO_OpenAsOutput */
#line 6 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\GpioOutput.cs"
    stack1_0__ = MT3620Blink_Interops_GPIO_OpenAsOutput(stack1_0__, stack2_0__, (MT3620Blink_GPIO_Value_Type)stack3_1__);
    /* IL_000f: call MT3620Blink.Descriptor..ctor */
#line 6 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\GpioOutput.cs"
    MT3620Blink_Descriptor__ctor((MT3620Blink_Descriptor*)frame__.stack0_0__, stack1_0__);
    /* IL_0014: nop  */
    /* IL_0015: nop  */
    /* IL_0016: ret  */
#line 11 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\GpioOutput.cs"
    il2c_unlink_execution_frame(&frame__);
#line 11 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\GpioOutput.cs"
    return;
#line 11 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\GpioOutput.cs"
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
#line 14 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\GpioOutput.cs"
    il2c_assert(this__ != NULL);

    //-------------------
    // [3-4] Evaluation stacks (!objref):

#line 14 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\GpioOutput.cs"
    int32_t stack0_1__;
#line 14 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\GpioOutput.cs"
    bool stack1_0__;
#line 14 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\GpioOutput.cs"
    int32_t stack1_1__;

    //-------------------
    // [3-5] Setup execution frame:

#line 14 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\GpioOutput.cs"
    MT3620Blink_GpioOutput_SetValue_EXECUTION_FRAME__ frame__ =
        { NULL, 1 };
#line 14 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\GpioOutput.cs"
    il2c_link_execution_frame(&frame__);

    //-------------------
    // [3-6] IL body:

    /* IL_0000: ldarg.0  */
#line 14 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\GpioOutput.cs"
    frame__.stack0_0__ = this__;
    /* IL_0001: call MT3620Blink.Descriptor.get_Identity */
#line 14 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\GpioOutput.cs"
    stack0_1__ = MT3620Blink_Descriptor_get_Identity((MT3620Blink_Descriptor*)frame__.stack0_0__);
    /* IL_0006: ldarg.1  */
#line 14 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\GpioOutput.cs"
    stack1_0__ = value;
    /* IL_0007: brtrue.s IL_000c */
#line 14 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\GpioOutput.cs"
    if (stack1_0__ != false) goto IL_000c;
    /* IL_0009: ldc.i4.0  */
#line 14 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\GpioOutput.cs"
    stack1_1__ = 0;
    /* IL_000a: br.s IL_000d */
#line 14 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\GpioOutput.cs"
    goto IL_000d;
IL_000c:
    /* IL_000c: ldc.i4.1  */
#line 14 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\GpioOutput.cs"
    stack1_1__ = 1;
IL_000d:
    /* IL_000d: call MT3620Blink.Interops.GPIO_SetValue */
#line 14 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\GpioOutput.cs"
    stack0_1__ = MT3620Blink_Interops_GPIO_SetValue(stack0_1__, (MT3620Blink_GPIO_Value_Type)stack1_1__);
    /* IL_0012: pop  */
    /* IL_0013: ret  */
#line 14 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\GpioOutput.cs"
    il2c_unlink_execution_frame(&frame__);
#line 14 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\GpioOutput.cs"
    return;
#line 14 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\GpioOutput.cs"
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

#ifdef __cplusplus
}
#endif
