#include <memmem.h>
#include "WDM.Code.h"

//////////////////////////////////////////////////////////////////////////////////
// Const strings:

IL2C_CONST_STRING(__string0, L"Hello driver constructor called!!\r\n");
IL2C_CONST_STRING(__string1, L"Draw BABEL!!\r\n");

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

    WDM_Code_InterceptCDRomDevice* __stack0_0 = NULL;
    System_String* __stack0_1 = NULL;
    intptr_t __stack1_0;
    int32_t __stack1_1;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        WDM_Code_InterceptCDRomDevice** p__stack0_0;
        System_String** p__stack0_1;
    } __executionFrame__;

    __executionFrame__.targetCount = 2;
    __executionFrame__.p__stack0_0 = &__stack0_0;
    __executionFrame__.p__stack0_1 = &__stack0_1;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

#line 11 "D:\\PROJECT\\IL2C\\tests\\WDM\\WDM.Code\\InterceptCDRomDevice.cs"
    /* Path=1, Unique=0: IL_0000: ldarg.0 */
    __stack0_0 = this__;
    /* Path=1, Unique=0: IL_0001: call System.Void System.Object::.ctor() */
    System_Object__ctor((System_Object*)__stack0_0);
#line 13 "D:\\PROJECT\\IL2C\\tests\\WDM\\WDM.Code\\InterceptCDRomDevice.cs"
    /* Path=1, Unique=0: IL_0006: ldstr "Hello driver constructor called!!
" */
    __stack0_1 = __string0;
    /* Path=1, Unique=0: IL_000b: call System.Void WDM.Code.Wdm::DbgPrint(System.String) */
    WDM_Code_Wdm_DbgPrint(__stack0_1);
#line 15 "D:\\PROJECT\\IL2C\\tests\\WDM\\WDM.Code\\InterceptCDRomDevice.cs"
    /* Path=1, Unique=0: IL_0010: ldarg.0 */
    __stack0_0 = this__;
    /* Path=1, Unique=0: IL_0011: ldarg.1 */
    __stack1_0 = pFrom;
    /* Path=1, Unique=0: IL_0012: stfld System.IntPtr WDM.Code.InterceptCDRomDevice::pFrom */
    __stack0_0->pFrom = __stack1_0;
#line 16 "D:\\PROJECT\\IL2C\\tests\\WDM\\WDM.Code\\InterceptCDRomDevice.cs"
    /* Path=1, Unique=0: IL_0017: ldarg.0 */
    __stack0_0 = this__;
    /* Path=1, Unique=0: IL_0018: ldarg.2 */
    __stack1_0 = pTo;
    /* Path=1, Unique=0: IL_0019: stfld System.IntPtr WDM.Code.InterceptCDRomDevice::pTo */
    __stack0_0->pTo = __stack1_0;
#line 17 "D:\\PROJECT\\IL2C\\tests\\WDM\\WDM.Code\\InterceptCDRomDevice.cs"
    /* Path=1, Unique=0: IL_001e: ldarg.0 */
    __stack0_0 = this__;
    /* Path=1, Unique=0: IL_001f: ldarg.3 */
    __stack1_1 = size;
    /* Path=1, Unique=0: IL_0020: stfld System.Int32 WDM.Code.InterceptCDRomDevice::size */
    __stack0_0->size = __stack1_1;
#line 18 "D:\\PROJECT\\IL2C\\tests\\WDM\\WDM.Code\\InterceptCDRomDevice.cs"
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

    intptr_t local0;

    //-------------------
    // Evaluation stacks:

    intptr_t __stack0_0;
    int32_t __stack0_1;
    System_String* __stack0_2 = NULL;
    int32_t __stack1_0;
    intptr_t __stack1_1;
    WDM_Code_InterceptCDRomDevice* __stack1_2 = NULL;
    WDM_Code_InterceptCDRomDevice* __stack2_0 = NULL;
    intptr_t __stack2_1;
    int32_t __stack2_2;
    WDM_Code_InterceptCDRomDevice* __stack3_0 = NULL;
    int32_t __stack3_1;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        System_String** p__stack0_2;
        WDM_Code_InterceptCDRomDevice** p__stack1_2;
        WDM_Code_InterceptCDRomDevice** p__stack2_0;
        WDM_Code_InterceptCDRomDevice** p__stack3_0;
    } __executionFrame__;

    __executionFrame__.targetCount = 4;
    __executionFrame__.p__stack0_2 = &__stack0_2;
    __executionFrame__.p__stack1_2 = &__stack1_2;
    __executionFrame__.p__stack2_0 = &__stack2_0;
    __executionFrame__.p__stack3_0 = &__stack3_0;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

#line 22 "D:\\PROJECT\\IL2C\\tests\\WDM\\WDM.Code\\InterceptCDRomDevice.cs"
    /* Path=1, Unique=0: IL_0000: ldarg.1 */
    __stack0_0 = pBuffer;
    /* Path=1, Unique=0: IL_0001: ldarg.2 */
    __stack1_0 = offset;
    /* Path=1, Unique=0: IL_0002: call System.IntPtr System.IntPtr::op_Addition(System.IntPtr,System.Int32) */
    __stack0_0 = System_IntPtr_op_Addition(__stack0_0, __stack1_0);
    /* Path=1, Unique=0: IL_0007: ldarg.3 */
    __stack1_0 = size;
    /* Path=1, Unique=0: IL_0008: ldarg.0 */
    __stack2_0 = this__;
    /* Path=1, Unique=0: IL_0009: ldfld System.IntPtr WDM.Code.InterceptCDRomDevice::pFrom */
    __stack2_1 = __stack2_0->pFrom;
    /* Path=1, Unique=0: IL_000e: ldarg.0 */
    __stack3_0 = this__;
    /* Path=1, Unique=0: IL_000f: ldfld System.Int32 WDM.Code.InterceptCDRomDevice::size */
    __stack3_1 = __stack3_0->size;
    /* Path=1, Unique=0: IL_0014: call System.IntPtr WDM.Code.Wdm::memmem(System.IntPtr,System.Int32,System.IntPtr,System.Int32) */
    __stack0_0 = WDM_Code_Wdm_memmem(__stack0_0, __stack1_0, __stack2_1, __stack3_1);
    /* Path=1, Unique=0: IL_0019: stloc.0 */
    local0 = __stack0_0;
#line 23 "D:\\PROJECT\\IL2C\\tests\\WDM\\WDM.Code\\InterceptCDRomDevice.cs"
    /* Path=1, Unique=0: IL_001a: ldloc.0 */
    __stack0_0 = local0;
    /* Path=1, Unique=0: IL_001b: ldsfld System.IntPtr System.IntPtr::Zero */
    __stack1_1 = System_IntPtr_Zero;
    /* Path=1, Unique=0: IL_0020: call System.Boolean System.IntPtr::op_Inequality(System.IntPtr,System.IntPtr) */
    __stack0_1 = System_IntPtr_op_Inequality(__stack0_0, __stack1_1);
    /* Path=1, Unique=0: IL_0025: brfalse.s IL_0043 */
    if (__stack0_1 == 0) goto IL_0043;
#line 25 "D:\\PROJECT\\IL2C\\tests\\WDM\\WDM.Code\\InterceptCDRomDevice.cs"
    /* Path=1, Unique=0: IL_0027: ldstr "Draw BABEL!!
" */
    __stack0_2 = __string1;
    /* Path=1, Unique=0: IL_002c: call System.Void WDM.Code.Wdm::DbgPrint(System.String) */
    WDM_Code_Wdm_DbgPrint(__stack0_2);
#line 27 "D:\\PROJECT\\IL2C\\tests\\WDM\\WDM.Code\\InterceptCDRomDevice.cs"
    /* Path=1, Unique=0: IL_0031: ldloc.0 */
    __stack0_0 = local0;
    /* Path=1, Unique=0: IL_0032: ldarg.0 */
    __stack1_2 = this__;
    /* Path=1, Unique=0: IL_0033: ldfld System.IntPtr WDM.Code.InterceptCDRomDevice::pTo */
    __stack1_1 = __stack1_2->pTo;
    /* Path=1, Unique=0: IL_0038: ldarg.0 */
    __stack2_0 = this__;
    /* Path=1, Unique=0: IL_0039: ldfld System.Int32 WDM.Code.InterceptCDRomDevice::size */
    __stack2_2 = __stack2_0->size;
    /* Path=1, Unique=0: IL_003e: call System.Void WDM.Code.Wdm::memcpy(System.IntPtr,System.IntPtr,System.Int32) */
    WDM_Code_Wdm_memcpy(__stack0_0, __stack1_1, __stack2_2);
IL_0043:
#line 30 "D:\\PROJECT\\IL2C\\tests\\WDM\\WDM.Code\\InterceptCDRomDevice.cs"
    /* Path=1, Unique=0: IL_0043: ldc.i4.0 */
    __stack0_1 = 0;
    /* Path=1, Unique=0: IL_0044: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return (uint32_t)__stack0_1;
}

//////////////////////
// Runtime helpers:

static void __WDM_Code_InterceptCDRomDevice_MARK_HANDLER__(void* pReference)
{
    il2c_typeof(System_Object)->pMarkHandler(pReference);
}

static __WDM_Code_InterceptCDRomDevice_TYPE_DEF_TYPE__ __WDM_Code_InterceptCDRomDevice_RUNTIME_TYPE_DEF__ = {
    (intptr_t)"WDM.Code.InterceptCDRomDevice",
    (intptr_t)sizeof(WDM_Code_InterceptCDRomDevice),
    (intptr_t)__WDM_Code_InterceptCDRomDevice_MARK_HANDLER__,
    __System_Object_ToString__,
    __System_Object_GetHashCode__,
    __System_Object_Finalize__,
    __System_Object_Equals__,
};
const IL2C_RUNTIME_TYPE __WDM_Code_InterceptCDRomDevice_RUNTIME_TYPE__ =
   (const IL2C_RUNTIME_TYPE)(&__WDM_Code_InterceptCDRomDevice_RUNTIME_TYPE_DEF__);

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

#line 11 "D:\\PROJECT\\IL2C\\tests\\WDM\\WDM.Code\\Wdm.cs"
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

#line 15 "D:\\PROJECT\\IL2C\\tests\\WDM\\WDM.Code\\Wdm.cs"
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

    WDM_Code_Wdm* __stack0_0 = NULL;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        WDM_Code_Wdm** p__stack0_0;
    } __executionFrame__;

    __executionFrame__.targetCount = 1;
    __executionFrame__.p__stack0_0 = &__stack0_0;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

    /* Path=1, Unique=0: IL_0000: ldarg.0 */
    __stack0_0 = this__;
    /* Path=1, Unique=0: IL_0001: call System.Void System.Object::.ctor() */
    System_Object__ctor((System_Object*)__stack0_0);
    /* Path=1, Unique=0: IL_0006: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return;
}

//////////////////////
// Runtime helpers:

static void __WDM_Code_Wdm_MARK_HANDLER__(void* pReference)
{
    il2c_typeof(System_Object)->pMarkHandler(pReference);
}

static __WDM_Code_Wdm_TYPE_DEF_TYPE__ __WDM_Code_Wdm_RUNTIME_TYPE_DEF__ = {
    (intptr_t)"WDM.Code.Wdm",
    (intptr_t)0,
    (intptr_t)__WDM_Code_Wdm_MARK_HANDLER__,
    __System_Object_ToString__,
    __System_Object_GetHashCode__,
    __System_Object_Finalize__,
    __System_Object_Equals__,
};
const IL2C_RUNTIME_TYPE __WDM_Code_Wdm_RUNTIME_TYPE__ =
   (const IL2C_RUNTIME_TYPE)(&__WDM_Code_Wdm_RUNTIME_TYPE_DEF__);
