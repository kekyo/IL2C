#include <memmem.h>
#include "WDM.Code.h"

//////////////////////////////////////////////////////////////////////////////////
// Const strings:

IL2C_CONST_STRING(string0__, L"Hello driver constructor called!!\r\n");
IL2C_CONST_STRING(string1__, L"Draw BABEL!!\r\n");

#ifdef __cplusplus
extern "C" {
#endif

//////////////////////////////////////////////////////////////////////////////////
// Types:


//////////////////////////////////////////////////////////////////////////////////
// Public static fields:

//////////////////////////////////////////////////////////////////////////////////
// Methods:

#ifdef __cplusplus
}
#endif

//////////////////////////////////////////////////////////////////////////////////
// Static fields:



//////////////////////////////////////////////////////////////////////////////////
// Methods:

////////////////////////////////////////////////////////////
// Type: WDM.Code.InterceptCDRomDevice

///////////////////////////////////////
// .ctor

void WDM_Code_InterceptCDRomDevice__ctor(WDM_Code_InterceptCDRomDevice* this__, intptr_t pFrom, intptr_t pTo, int32_t size)
{
    //-------------------
    // Local variables:


    //-------------------
    // Evaluation stacks:

    WDM_Code_InterceptCDRomDevice* stack0_0__ = NULL;
    System_String* stack0_1__ = NULL;
    intptr_t stack1_0__;
    int32_t stack1_1__;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        WDM_Code_InterceptCDRomDevice** pstack0_0__;
        System_String** pstack0_1__;
    } __executionFrame__;

    __executionFrame__.targetCount = 2;
    __executionFrame__.pstack0_0__ = &stack0_0__;
    __executionFrame__.pstack0_1__ = &stack0_1__;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

/* D:\\PROJECT\\IL2C\\samples\\WDM\\WDM.Code\\InterceptCDRomDevice.cs(11): */
    /* Path=1, Unique=0: IL_0000: ldarg.0 */
    stack0_0__ = this__;
    /* Path=1, Unique=0: IL_0001: call System.Void System.Object::.ctor() */
    /* Path=1, Unique=0: IL_0006: nop */
/* D:\\PROJECT\\IL2C\\samples\\WDM\\WDM.Code\\InterceptCDRomDevice.cs(12): */
    /* Path=1, Unique=0: IL_0007: nop */
    /* Path=1, Unique=0: IL_0008: ldstr "Hello driver constructor called!!
" */
    stack0_1__ = string0__;
    /* Path=1, Unique=0: IL_000d: call System.Void WDM.Code.Wdm::DbgPrint(System.String) */
    WDM_Code_Wdm_DbgPrint(stack0_1__);
    /* Path=1, Unique=0: IL_0012: nop */
/* D:\\PROJECT\\IL2C\\samples\\WDM\\WDM.Code\\InterceptCDRomDevice.cs(15): */
    /* Path=1, Unique=0: IL_0013: ldarg.0 */
    stack0_0__ = this__;
    /* Path=1, Unique=0: IL_0014: ldarg.1 */
    stack1_0__ = pFrom;
    /* Path=1, Unique=0: IL_0015: stfld System.IntPtr WDM.Code.InterceptCDRomDevice::pFrom */
    stack0_0__->pFrom = stack1_0__;
/* D:\\PROJECT\\IL2C\\samples\\WDM\\WDM.Code\\InterceptCDRomDevice.cs(16): */
    /* Path=1, Unique=0: IL_001a: ldarg.0 */
    stack0_0__ = this__;
    /* Path=1, Unique=0: IL_001b: ldarg.2 */
    stack1_0__ = pTo;
    /* Path=1, Unique=0: IL_001c: stfld System.IntPtr WDM.Code.InterceptCDRomDevice::pTo */
    stack0_0__->pTo = stack1_0__;
/* D:\\PROJECT\\IL2C\\samples\\WDM\\WDM.Code\\InterceptCDRomDevice.cs(17): */
    /* Path=1, Unique=0: IL_0021: ldarg.0 */
    stack0_0__ = this__;
    /* Path=1, Unique=0: IL_0022: ldarg.3 */
    stack1_1__ = size;
    /* Path=1, Unique=0: IL_0023: stfld System.Int32 WDM.Code.InterceptCDRomDevice::size */
    stack0_0__->size = stack1_1__;
/* D:\\PROJECT\\IL2C\\samples\\WDM\\WDM.Code\\InterceptCDRomDevice.cs(18): */
    /* Path=1, Unique=0: IL_0028: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return;
}

///////////////////////////////////////
// ReadCompleted

uint32_t WDM_Code_InterceptCDRomDevice_ReadCompleted(WDM_Code_InterceptCDRomDevice* this__, intptr_t pBuffer, int32_t offset, int32_t size)
{
    //-------------------
    // Local variables:

    intptr_t result__;
    bool local0__;
    uint32_t local1__;

    //-------------------
    // Evaluation stacks:

    intptr_t stack0_0__;
    int32_t stack0_1__;
    System_String* stack0_2__ = NULL;
    int32_t stack1_0__;
    intptr_t stack1_1__;
    WDM_Code_InterceptCDRomDevice* stack1_2__ = NULL;
    WDM_Code_InterceptCDRomDevice* stack2_0__ = NULL;
    intptr_t stack2_1__;
    int32_t stack2_2__;
    WDM_Code_InterceptCDRomDevice* stack3_0__ = NULL;
    int32_t stack3_1__;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        System_String** pstack0_2__;
        WDM_Code_InterceptCDRomDevice** pstack1_2__;
        WDM_Code_InterceptCDRomDevice** pstack2_0__;
        WDM_Code_InterceptCDRomDevice** pstack3_0__;
    } __executionFrame__;

    __executionFrame__.targetCount = 4;
    __executionFrame__.pstack0_2__ = &stack0_2__;
    __executionFrame__.pstack1_2__ = &stack1_2__;
    __executionFrame__.pstack2_0__ = &stack2_0__;
    __executionFrame__.pstack3_0__ = &stack3_0__;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

/* D:\\PROJECT\\IL2C\\samples\\WDM\\WDM.Code\\InterceptCDRomDevice.cs(21): */
    /* Path=1, Unique=0: IL_0000: nop */
    /* Path=1, Unique=0: IL_0001: ldarg.1 */
    stack0_0__ = pBuffer;
    /* Path=1, Unique=0: IL_0002: ldarg.2 */
    stack1_0__ = offset;
    /* Path=1, Unique=0: IL_0003: call System.IntPtr System.IntPtr::op_Addition(System.IntPtr,System.Int32) */
    stack0_0__ = System_IntPtr_op_Addition(stack0_0__, stack1_0__);
    /* Path=1, Unique=0: IL_0008: ldarg.3 */
    stack1_0__ = size;
    /* Path=1, Unique=0: IL_0009: ldarg.0 */
    stack2_0__ = this__;
    /* Path=1, Unique=0: IL_000a: ldfld System.IntPtr WDM.Code.InterceptCDRomDevice::pFrom */
    stack2_1__ = stack2_0__->pFrom;
    /* Path=1, Unique=0: IL_000f: ldarg.0 */
    stack3_0__ = this__;
    /* Path=1, Unique=0: IL_0010: ldfld System.Int32 WDM.Code.InterceptCDRomDevice::size */
    stack3_1__ = stack3_0__->size;
    /* Path=1, Unique=0: IL_0015: call System.IntPtr WDM.Code.Wdm::memmem(System.IntPtr,System.Int32,System.IntPtr,System.Int32) */
    stack0_0__ = WDM_Code_Wdm_memmem(stack0_0__, stack1_0__, stack2_1__, stack3_1__);
    /* Path=1, Unique=0: IL_001a: stloc.0 */
    result__ = stack0_0__;
/* D:\\PROJECT\\IL2C\\samples\\WDM\\WDM.Code\\InterceptCDRomDevice.cs(23): */
    /* Path=1, Unique=0: IL_001b: ldloc.0 */
    stack0_0__ = result__;
    /* Path=1, Unique=0: IL_001c: ldsfld System.IntPtr System.IntPtr::Zero */
    stack1_1__ = System_IntPtr_Zero;
    /* Path=1, Unique=0: IL_0021: call System.Boolean System.IntPtr::op_Inequality(System.IntPtr,System.IntPtr) */
    stack0_1__ = System_IntPtr_op_Inequality(stack0_0__, stack1_1__);
    /* Path=1, Unique=0: IL_0026: stloc.1 */
    local0__ = stack0_1__ ? true : false;
    /* Path=1, Unique=0: IL_0027: ldloc.1 */
    stack0_1__ = local0__;
    /* Path=1, Unique=0: IL_0028: brfalse.s IL_004a */
    if (stack0_1__ == 0) goto IL_004a;
/* D:\\PROJECT\\IL2C\\samples\\WDM\\WDM.Code\\InterceptCDRomDevice.cs(24): */
    /* Path=1, Unique=0: IL_002a: nop */
    /* Path=1, Unique=0: IL_002b: ldstr "Draw BABEL!!
" */
    stack0_2__ = string1__;
    /* Path=1, Unique=0: IL_0030: call System.Void WDM.Code.Wdm::DbgPrint(System.String) */
    WDM_Code_Wdm_DbgPrint(stack0_2__);
    /* Path=1, Unique=0: IL_0035: nop */
/* D:\\PROJECT\\IL2C\\samples\\WDM\\WDM.Code\\InterceptCDRomDevice.cs(27): */
    /* Path=1, Unique=0: IL_0036: ldloc.0 */
    stack0_0__ = result__;
    /* Path=1, Unique=0: IL_0037: ldarg.0 */
    stack1_2__ = this__;
    /* Path=1, Unique=0: IL_0038: ldfld System.IntPtr WDM.Code.InterceptCDRomDevice::pTo */
    stack1_1__ = stack1_2__->pTo;
    /* Path=1, Unique=0: IL_003d: ldarg.0 */
    stack2_0__ = this__;
    /* Path=1, Unique=0: IL_003e: ldfld System.Int32 WDM.Code.InterceptCDRomDevice::size */
    stack2_2__ = stack2_0__->size;
    /* Path=1, Unique=0: IL_0043: call System.Void WDM.Code.Wdm::memcpy(System.IntPtr,System.IntPtr,System.Int32) */
    WDM_Code_Wdm_memcpy(stack0_0__, stack1_1__, stack2_2__);
    /* Path=1, Unique=0: IL_0048: nop */
/* D:\\PROJECT\\IL2C\\samples\\WDM\\WDM.Code\\InterceptCDRomDevice.cs(28): */
    /* Path=1, Unique=0: IL_0049: nop */
IL_004a:
    /* Path=1, Unique=0: IL_004a: ldc.i4.0 */
    stack0_1__ = 0;
    /* Path=1, Unique=0: IL_004b: stloc.2 */
    local1__ = (uint32_t)stack0_1__;
    /* Path=1, Unique=0: IL_004c: br.s IL_004e */
    goto IL_004e;
IL_004e:
/* D:\\PROJECT\\IL2C\\samples\\WDM\\WDM.Code\\InterceptCDRomDevice.cs(31): */
    /* Path=2, Unique=0: IL_004e: ldloc.2 */
    stack0_1__ = local1__;
    /* Path=2, Unique=0: IL_004f: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return (uint32_t)stack0_1__;
}

//////////////////////
// Runtime helpers:

// Runtime cast
void* __WDM_Code_InterceptCDRomDevice_IL2C_RuntimeCast__(WDM_Code_InterceptCDRomDevice* this__, IL2C_RUNTIME_TYPE_DECL* type)
{
    // This type
    if (type == il2c_typeof(WDM_Code_InterceptCDRomDevice)) return this__;

    // Delegate checking base types
    return __System_Object_IL2C_RuntimeCast__((System_Object*)this__, type);
}

// GC's mark handler
void __WDM_Code_InterceptCDRomDevice_IL2C_MarkHandler__(WDM_Code_InterceptCDRomDevice* this__)
{

    /* Suppressed invoke base mark handler */
}

// Vtable of instance type
__WDM_Code_InterceptCDRomDevice_VTABLE_DECL__ __WDM_Code_InterceptCDRomDevice_VTABLE__ = {
    /* internalcall */ __WDM_Code_InterceptCDRomDevice_IL2C_RuntimeCast__,
    (void*)__System_Object_ToString__,
    (void*)__System_Object_GetHashCode__,
    (void*)__System_Object_Finalize__,
    (void*)__System_Object_Equals__,
};

// Runtime type information
IL2C_RUNTIME_TYPE_DECL __WDM_Code_InterceptCDRomDevice_RUNTIME_TYPE__ = {
    "WDM.Code.InterceptCDRomDevice",
    sizeof(WDM_Code_InterceptCDRomDevice),
    /* internalcall */ (void*)__WDM_Code_InterceptCDRomDevice_IL2C_MarkHandler__,
};

////////////////////////////////////////////////////////////
// Type: WDM.Code.Wdm

///////////////////////////////////////
// DbgPrint

void WDM_Code_Wdm_DbgPrint(System_String* message)
{
    //-------------------
    // Local variables:


    //-------------------
    // Evaluation stacks:


    //-------------------
    // IL body:

/* D:\\PROJECT\\IL2C\\samples\\WDM\\WDM.Code\\Wdm.cs(10): */
    /* Path=1, Unique=0: IL_0000: nop */
    /* Path=1, Unique=0: IL_0001: ret */
    return;
}

///////////////////////////////////////
// DbgPrint

void WDM_Code_Wdm_DbgPrint_1(uint32_t componentId, uint32_t level, System_String* message)
{
    //-------------------
    // Local variables:


    //-------------------
    // Evaluation stacks:


    //-------------------
    // IL body:

/* D:\\PROJECT\\IL2C\\samples\\WDM\\WDM.Code\\Wdm.cs(14): */
    /* Path=1, Unique=0: IL_0000: nop */
    /* Path=1, Unique=0: IL_0001: ret */
    return;
}

///////////////////////////////////////
// P/Invoke: memmem

intptr_t WDM_Code_Wdm_memmem(intptr_t p1, int32_t s1, intptr_t p2, int32_t s2)
{
    return __memmem(p1, s1, p2, s2);
}

///////////////////////////////////////
// P/Invoke: memcpy

void WDM_Code_Wdm_memcpy(intptr_t pDest, intptr_t pSource, int32_t size)
{
    __memcpy(pDest, pSource, size);
}

///////////////////////////////////////
// .ctor

void WDM_Code_Wdm__ctor(WDM_Code_Wdm* this__)
{
    //-------------------
    // Local variables:


    //-------------------
    // Evaluation stacks:

    WDM_Code_Wdm* stack0_0__ = NULL;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        WDM_Code_Wdm** pstack0_0__;
    } __executionFrame__;

    __executionFrame__.targetCount = 1;
    __executionFrame__.pstack0_0__ = &stack0_0__;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

    /* Path=1, Unique=0: IL_0000: ldarg.0 */
    stack0_0__ = this__;
    /* Path=1, Unique=0: IL_0001: call System.Void System.Object::.ctor() */
    /* Path=1, Unique=0: IL_0006: nop */
    /* Path=1, Unique=0: IL_0007: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return;
}

//////////////////////
// Runtime helpers:

// Runtime cast
void* __WDM_Code_Wdm_IL2C_RuntimeCast__(WDM_Code_Wdm* this__, IL2C_RUNTIME_TYPE_DECL* type)
{
    // This type
    if (type == il2c_typeof(WDM_Code_Wdm)) return this__;

    // Delegate checking base types
    return __System_Object_IL2C_RuntimeCast__((System_Object*)this__, type);
}

// GC's mark handler
void __WDM_Code_Wdm_IL2C_MarkHandler__(WDM_Code_Wdm* this__)
{

    /* Suppressed invoke base mark handler */
}

// Vtable of instance type
__WDM_Code_Wdm_VTABLE_DECL__ __WDM_Code_Wdm_VTABLE__ = {
    /* internalcall */ __WDM_Code_Wdm_IL2C_RuntimeCast__,
    (void*)__System_Object_ToString__,
    (void*)__System_Object_GetHashCode__,
    (void*)__System_Object_Finalize__,
    (void*)__System_Object_Equals__,
};

// Runtime type information
IL2C_RUNTIME_TYPE_DECL __WDM_Code_Wdm_RUNTIME_TYPE__ = {
    "WDM.Code.Wdm",
    sizeof(WDM_Code_Wdm),
    /* internalcall */ (void*)__WDM_Code_Wdm_IL2C_MarkHandler__,
};
