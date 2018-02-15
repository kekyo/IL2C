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
/* D:\\PROJECT\\IL2C\\samples\\WDM\\WDM.Code\\InterceptCDRomDevice.cs(13): */
    /* Path=1, Unique=0: IL_0006: ldstr "Hello driver constructor called!!
" */
    stack0_1__ = string0__;
    /* Path=1, Unique=0: IL_000b: call System.Void WDM.Code.Wdm::DbgPrint(System.String) */
    WDM_Code_Wdm_DbgPrint(stack0_1__);
/* D:\\PROJECT\\IL2C\\samples\\WDM\\WDM.Code\\InterceptCDRomDevice.cs(15): */
    /* Path=1, Unique=0: IL_0010: ldarg.0 */
    stack0_0__ = this__;
    /* Path=1, Unique=0: IL_0011: ldarg.1 */
    stack1_0__ = pFrom;
    /* Path=1, Unique=0: IL_0012: stfld System.IntPtr WDM.Code.InterceptCDRomDevice::pFrom */
    stack0_0__->pFrom = stack1_0__;
/* D:\\PROJECT\\IL2C\\samples\\WDM\\WDM.Code\\InterceptCDRomDevice.cs(16): */
    /* Path=1, Unique=0: IL_0017: ldarg.0 */
    stack0_0__ = this__;
    /* Path=1, Unique=0: IL_0018: ldarg.2 */
    stack1_0__ = pTo;
    /* Path=1, Unique=0: IL_0019: stfld System.IntPtr WDM.Code.InterceptCDRomDevice::pTo */
    stack0_0__->pTo = stack1_0__;
/* D:\\PROJECT\\IL2C\\samples\\WDM\\WDM.Code\\InterceptCDRomDevice.cs(17): */
    /* Path=1, Unique=0: IL_001e: ldarg.0 */
    stack0_0__ = this__;
    /* Path=1, Unique=0: IL_001f: ldarg.3 */
    stack1_1__ = size;
    /* Path=1, Unique=0: IL_0020: stfld System.Int32 WDM.Code.InterceptCDRomDevice::size */
    stack0_0__->size = stack1_1__;
/* D:\\PROJECT\\IL2C\\samples\\WDM\\WDM.Code\\InterceptCDRomDevice.cs(18): */
    /* Path=1, Unique=0: IL_0025: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return;
}

///////////////////////////////////////
// ReadCompleted

uint32_t WDM_Code_InterceptCDRomDevice_ReadCompleted(WDM_Code_InterceptCDRomDevice* this__, intptr_t pBuffer, int32_t offset, int32_t size)
{
    //-------------------
    // Local variables:

    intptr_t result;

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

/* D:\\PROJECT\\IL2C\\samples\\WDM\\WDM.Code\\InterceptCDRomDevice.cs(22): */
    /* Path=1, Unique=0: IL_0000: ldarg.1 */
    stack0_0__ = pBuffer;
    /* Path=1, Unique=0: IL_0001: ldarg.2 */
    stack1_0__ = offset;
    /* Path=1, Unique=0: IL_0002: call System.IntPtr System.IntPtr::op_Addition(System.IntPtr,System.Int32) */
    stack0_0__ = System_IntPtr_op_Addition(stack0_0__, stack1_0__);
    /* Path=1, Unique=0: IL_0007: ldarg.3 */
    stack1_0__ = size;
    /* Path=1, Unique=0: IL_0008: ldarg.0 */
    stack2_0__ = this__;
    /* Path=1, Unique=0: IL_0009: ldfld System.IntPtr WDM.Code.InterceptCDRomDevice::pFrom */
    stack2_1__ = stack2_0__->pFrom;
    /* Path=1, Unique=0: IL_000e: ldarg.0 */
    stack3_0__ = this__;
    /* Path=1, Unique=0: IL_000f: ldfld System.Int32 WDM.Code.InterceptCDRomDevice::size */
    stack3_1__ = stack3_0__->size;
    /* Path=1, Unique=0: IL_0014: call System.IntPtr WDM.Code.Wdm::memmem(System.IntPtr,System.Int32,System.IntPtr,System.Int32) */
    stack0_0__ = WDM_Code_Wdm_memmem(stack0_0__, stack1_0__, stack2_1__, stack3_1__);
    /* Path=1, Unique=0: IL_0019: stloc.0 */
    result = stack0_0__;
/* D:\\PROJECT\\IL2C\\samples\\WDM\\WDM.Code\\InterceptCDRomDevice.cs(23): */
    /* Path=1, Unique=0: IL_001a: ldloc.0 */
    stack0_0__ = result;
    /* Path=1, Unique=0: IL_001b: ldsfld System.IntPtr System.IntPtr::Zero */
    stack1_1__ = System_IntPtr_Zero;
    /* Path=1, Unique=0: IL_0020: call System.Boolean System.IntPtr::op_Inequality(System.IntPtr,System.IntPtr) */
    stack0_1__ = System_IntPtr_op_Inequality(stack0_0__, stack1_1__);
    /* Path=1, Unique=0: IL_0025: brfalse.s IL_0043 */
    if (stack0_1__ == 0) goto IL_0043;
/* D:\\PROJECT\\IL2C\\samples\\WDM\\WDM.Code\\InterceptCDRomDevice.cs(25): */
    /* Path=1, Unique=0: IL_0027: ldstr "Draw BABEL!!
" */
    stack0_2__ = string1__;
    /* Path=1, Unique=0: IL_002c: call System.Void WDM.Code.Wdm::DbgPrint(System.String) */
    WDM_Code_Wdm_DbgPrint(stack0_2__);
/* D:\\PROJECT\\IL2C\\samples\\WDM\\WDM.Code\\InterceptCDRomDevice.cs(27): */
    /* Path=1, Unique=0: IL_0031: ldloc.0 */
    stack0_0__ = result;
    /* Path=1, Unique=0: IL_0032: ldarg.0 */
    stack1_2__ = this__;
    /* Path=1, Unique=0: IL_0033: ldfld System.IntPtr WDM.Code.InterceptCDRomDevice::pTo */
    stack1_1__ = stack1_2__->pTo;
    /* Path=1, Unique=0: IL_0038: ldarg.0 */
    stack2_0__ = this__;
    /* Path=1, Unique=0: IL_0039: ldfld System.Int32 WDM.Code.InterceptCDRomDevice::size */
    stack2_2__ = stack2_0__->size;
    /* Path=1, Unique=0: IL_003e: call System.Void WDM.Code.Wdm::memcpy(System.IntPtr,System.IntPtr,System.Int32) */
    WDM_Code_Wdm_memcpy(stack0_0__, stack1_1__, stack2_2__);
IL_0043:
/* D:\\PROJECT\\IL2C\\samples\\WDM\\WDM.Code\\InterceptCDRomDevice.cs(30): */
    /* Path=1, Unique=0: IL_0043: ldc.i4.0 */
    stack0_1__ = 0;
    /* Path=1, Unique=0: IL_0044: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return (uint32_t)stack0_1__;
}

//////////////////////
// Runtime helpers:

// Runtime cast
void* __WDM_Code_InterceptCDRomDevice_IL2C_RuntimeCast__(WDM_Code_InterceptCDRomDevice* this__, IL2C_RUNTIME_TYPE_DECL* type)
{
    if (type == il2c_typeof(System_Object)) return this__;
    return __System_Object_IL2C_RuntimeCast__((System_Object*)this__, type);
}

// GC's mark handler
void __WDM_Code_InterceptCDRomDevice_IL2C_MarkHandler__(WDM_Code_InterceptCDRomDevice* this__)
{
    /* Suppressed invoke base mark handler */
}

static __WDM_Code_InterceptCDRomDevice_VTABLE_DECL__ __WDM_Code_InterceptCDRomDevice_VTABLE__ = {
    /* internalcall */ __WDM_Code_InterceptCDRomDevice_IL2C_RuntimeCast__,
    (void*)__System_Object_ToString__,
    (void*)__System_Object_GetHashCode__,
    (void*)__System_Object_Finalize__,
    (void*)__System_Object_Equals__,
};

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

/* D:\\PROJECT\\IL2C\\samples\\WDM\\WDM.Code\\Wdm.cs(11): */
    /* Path=1, Unique=0: IL_0000: ret */
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

/* D:\\PROJECT\\IL2C\\samples\\WDM\\WDM.Code\\Wdm.cs(15): */
    /* Path=1, Unique=0: IL_0000: ret */
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
    /* Path=1, Unique=0: IL_0006: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return;
}

//////////////////////
// Runtime helpers:

// Runtime cast
void* __WDM_Code_Wdm_IL2C_RuntimeCast__(WDM_Code_Wdm* this__, IL2C_RUNTIME_TYPE_DECL* type)
{
    if (type == il2c_typeof(System_Object)) return this__;
    return __System_Object_IL2C_RuntimeCast__((System_Object*)this__, type);
}

// GC's mark handler
void __WDM_Code_Wdm_IL2C_MarkHandler__(WDM_Code_Wdm* this__)
{
    /* Suppressed invoke base mark handler */
}

static __WDM_Code_Wdm_VTABLE_DECL__ __WDM_Code_Wdm_VTABLE__ = {
    /* internalcall */ __WDM_Code_Wdm_IL2C_RuntimeCast__,
    (void*)__System_Object_ToString__,
    (void*)__System_Object_GetHashCode__,
    (void*)__System_Object_Finalize__,
    (void*)__System_Object_Equals__,
};

IL2C_RUNTIME_TYPE_DECL __WDM_Code_Wdm_RUNTIME_TYPE__ = {
    "WDM.Code.Wdm",
    sizeof(WDM_Code_Wdm),
    /* internalcall */ (void*)__WDM_Code_Wdm_IL2C_MarkHandler__,
};
