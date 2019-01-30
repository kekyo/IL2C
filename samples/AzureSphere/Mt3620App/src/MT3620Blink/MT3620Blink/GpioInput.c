// [15-2] This is MT3620Blink native code translated by IL2C, do not edit.

#include <MT3620Blink.h>
#include <MT3620Blink_internal.h>

#include <mscorlib.h>

#ifdef __cplusplus
extern "C" {
#endif

//////////////////////////////////////////////////////////////////////////////////
// [9-1] Type: MT3620Blink.GpioInput

//////////////////////////////////////////////////////////////////////////////////
// [9-2] File scope prototypes:

//////////////////////////////////////////////////////////////////////////////////
// [9-3] Static field instances:

//////////////////////////////////////////////////////////////////////////////////
// [9-4] Type: MT3620Blink.GpioInput

///////////////////////////////////////
// [3] MT3620Blink.GpioInput..ctor(MT3620Blink.GpioInput this__, System.Int32 gpioId)

//-------------------
// [3-7] Declare execution frame:

typedef struct MT3620Blink_GpioInput__ctor_EXECUTION_FRAME_DECL
{
    const IL2C_EXECUTION_FRAME* pNext__;
    const uint16_t objRefCount__;
    const uint16_t valueCount__;
    //-------------------- objref
    MT3620Blink_GpioInput* stack0_0__;
} MT3620Blink_GpioInput__ctor_EXECUTION_FRAME__;

//-------------------
// [3-2] Function body:

void MT3620Blink_GpioInput__ctor(MT3620Blink_GpioInput* this__, int32_t gpioId)
{
#line 6 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\GpioInput.cs"
    il2c_assert(this__ != NULL);

    //-------------------
    // [3-4] Evaluation stacks (!objref):

#line 6 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\GpioInput.cs"
    int32_t stack1_0__;

    //-------------------
    // [3-5] Setup execution frame:

#line 6 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\GpioInput.cs"
    MT3620Blink_GpioInput__ctor_EXECUTION_FRAME__ frame__ =
        { NULL, 1 };
#line 6 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\GpioInput.cs"
    il2c_link_execution_frame(&frame__);

    //-------------------
    // [3-6] IL body:

    /* IL_0000: ldarg.0  */
#line 6 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\GpioInput.cs"
    frame__.stack0_0__ = this__;
    /* IL_0001: ldarg.1  */
#line 6 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\GpioInput.cs"
    stack1_0__ = gpioId;
    /* IL_0002: call MT3620Blink.Interops.GPIO_OpenAsInput */
#line 6 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\GpioInput.cs"
    stack1_0__ = MT3620Blink_Interops_GPIO_OpenAsInput(stack1_0__);
    /* IL_0007: call MT3620Blink.Descriptor..ctor */
#line 6 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\GpioInput.cs"
    MT3620Blink_Descriptor__ctor((MT3620Blink_Descriptor*)frame__.stack0_0__, stack1_0__);
    /* IL_000c: nop  */
    /* IL_000d: nop  */
    /* IL_000e: ret  */
#line 8 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\GpioInput.cs"
    il2c_unlink_execution_frame(&frame__);
#line 8 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\GpioInput.cs"
    return;
#line 8 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\GpioInput.cs"
}

///////////////////////////////////////
// [3] MT3620Blink.GpioInput.get_Value(MT3620Blink.GpioInput this__)

//-------------------
// [3-7] Declare execution frame:

typedef struct MT3620Blink_GpioInput_get_Value_EXECUTION_FRAME_DECL
{
    const IL2C_EXECUTION_FRAME* pNext__;
    const uint16_t objRefCount__;
    const uint16_t valueCount__;
    //-------------------- objref
    MT3620Blink_GpioInput* stack0_0__;
} MT3620Blink_GpioInput_get_Value_EXECUTION_FRAME__;

//-------------------
// [3-2] Function body:

bool MT3620Blink_GpioInput_get_Value(MT3620Blink_GpioInput* this__)
{
#line 13 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\GpioInput.cs"
    il2c_assert(this__ != NULL);

    //-------------------
    // [3-3] Local variables (!objref):

#line 13 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\GpioInput.cs"
    MT3620Blink_GPIO_Value_Type value;
#line 13 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\GpioInput.cs"
    il2c_memset(&value, 0x00, sizeof value);
#line 13 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\GpioInput.cs"
    bool local1__ = false;

    //-------------------
    // [3-4] Evaluation stacks (!objref):

#line 13 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\GpioInput.cs"
    int32_t stack0_1__;
#line 13 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\GpioInput.cs"
    MT3620Blink_GPIO_Value_Type stack0_2__;
#line 13 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\GpioInput.cs"
    bool stack0_3__;
#line 13 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\GpioInput.cs"
    MT3620Blink_GPIO_Value_Type* stack1_0__;
#line 13 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\GpioInput.cs"
    int32_t stack1_1__;

    //-------------------
    // [3-5] Setup execution frame:

#line 13 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\GpioInput.cs"
    MT3620Blink_GpioInput_get_Value_EXECUTION_FRAME__ frame__ =
        { NULL, 1 };
#line 13 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\GpioInput.cs"
    il2c_link_execution_frame(&frame__);

    //-------------------
    // [3-6] IL body:

    /* IL_0000: nop  */
    /* IL_0001: ldarg.0  */
#line 14 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\GpioInput.cs"
    frame__.stack0_0__ = this__;
    /* IL_0002: call MT3620Blink.Descriptor.get_Identity */
#line 14 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\GpioInput.cs"
    stack0_1__ = MT3620Blink_Descriptor_get_Identity((MT3620Blink_Descriptor*)frame__.stack0_0__);
    /* IL_0007: ldloca.s value */
#line 14 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\GpioInput.cs"
    stack1_0__ = &value;
    /* IL_0009: call MT3620Blink.Interops.GPIO_GetValue */
#line 14 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\GpioInput.cs"
    stack0_1__ = MT3620Blink_Interops_GPIO_GetValue(stack0_1__, stack1_0__);
    /* IL_000e: pop  */
    /* IL_000f: ldloc.0  */
#line 15 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\GpioInput.cs"
    stack0_2__ = value;
    /* IL_0010: ldc.i4.1  */
#line 15 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\GpioInput.cs"
    stack1_1__ = 1;
    /* IL_0011: ceq  */
#line 15 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\GpioInput.cs"
    stack0_1__ = (int32_t)stack0_2__ == (int32_t)stack1_1__;
    /* IL_0013: stloc.1  */
#line 15 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\GpioInput.cs"
    local1__ = (bool)stack0_1__;
    /* IL_0014: br.s IL_0016 */
#line 15 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\GpioInput.cs"
    goto IL_0016;
IL_0016:
    /* IL_0016: ldloc.1  */
#line 16 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\GpioInput.cs"
    stack0_3__ = local1__;
    /* IL_0017: ret  */
#line 16 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\GpioInput.cs"
    il2c_unlink_execution_frame(&frame__);
#line 16 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\GpioInput.cs"
    return stack0_3__;
#line 16 "D:\\PROJECT\\IL2C\\samples\\AzureSphere\\MT3620Blink\\GpioInput.cs"
}

//////////////////////
// [7] Runtime helpers:

// [7-10-1] VTable (Not defined, same as MT3620Blink.Descriptor)

// [7-13] VTable for System.IDisposable
System_IDisposable_VTABLE_DECL__ MT3620Blink_GpioInput_System_IDisposable_VTABLE__ = {
    il2c_adjustor_offset(MT3620Blink_GpioInput, System_IDisposable),
    (void (*)(void*))MT3620Blink_Descriptor_Dispose,
};

// [7-8] Runtime type information
IL2C_RUNTIME_TYPE_BEGIN(MT3620Blink_GpioInput, "MT3620Blink.GpioInput", IL2C_TYPE_REFERENCE, sizeof(MT3620Blink_GpioInput), MT3620Blink_Descriptor, 0, 1)
    IL2C_RUNTIME_TYPE_INTERFACE(MT3620Blink_GpioInput, System_IDisposable)
IL2C_RUNTIME_TYPE_END();

#ifdef __cplusplus
}
#endif
