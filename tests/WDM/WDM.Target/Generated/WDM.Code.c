#include <wdm.h>
#include <memmem.h>
#include "WDM.Code.h"

//////////////////////////////////////////////////////////////////////////////////
// Const strings:

__DEFINE_CONST_STRING__(__string0, "Hello driver constructor called!!\r\n");
__DEFINE_CONST_STRING__(__string1, "Draw BABEL!!\r\n");

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

//////////////////////
// Runtime helpers:

static void __WDM_Code_InterceptCDRomDevice_MARK_HANDLER__(void* pReference)
{
    __typeof__(System_Object)->pMarkHandler(pReference);
}

static __RUNTIME_TYPE_DEF__ __WDM_Code_InterceptCDRomDevice_RUNTIME_TYPE_DEF__ = {
    "WDM.Code.InterceptCDRomDevice",
    sizeof(WDM_Code_InterceptCDRomDevice),
    __WDM_Code_InterceptCDRomDevice_MARK_HANDLER__ };
const __RUNTIME_TYPE__ __WDM_Code_InterceptCDRomDevice_RUNTIME_TYPE__ = &__WDM_Code_InterceptCDRomDevice_RUNTIME_TYPE_DEF__;

///////////////////////////////////////
// .ctor

void WDM_Code_InterceptCDRomDevice__ctor(WDM_Code_InterceptCDRomDevice* __this, intptr_t pFrom, intptr_t pTo, int32_t size)
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

    struct /* __EXECUTION_FRAME__ */
    {
        __EXECUTION_FRAME__* pNext;
        uint8_t targetCount;
        WDM_Code_InterceptCDRomDevice** p__stack0_0;
        System_String** p__stack0_1;
    } __executionFrame__;

    __executionFrame__.targetCount = 2;
    __executionFrame__.p__stack0_0 = &__stack0_0;
    __executionFrame__.p__stack0_1 = &__stack0_1;
    __gc_link_execution_frame__(&__executionFrame__);

    //-------------------
    // IL body:

#line 11 "D:\\PROJECT\\IL2C\\tests\\WDM\\WDM.Code\\InterceptCDRomDevice.cs"
    __stack0_0 = __this;
    System_Object__ctor((System_Object*)__stack0_0);
#line 12 "D:\\PROJECT\\IL2C\\tests\\WDM\\WDM.Code\\InterceptCDRomDevice.cs"
#line 13 "D:\\PROJECT\\IL2C\\tests\\WDM\\WDM.Code\\InterceptCDRomDevice.cs"
    __stack0_1 = __string0 /* "Hello driver constructor called!!
" */;
    WDM_Code_Wdm_DbgPrint(__stack0_1);
#line 15 "D:\\PROJECT\\IL2C\\tests\\WDM\\WDM.Code\\InterceptCDRomDevice.cs"
    __stack0_0 = __this;
    __stack1_0 = pFrom;
    __stack0_0->pFrom = __stack1_0;
#line 16 "D:\\PROJECT\\IL2C\\tests\\WDM\\WDM.Code\\InterceptCDRomDevice.cs"
    __stack0_0 = __this;
    __stack1_0 = pTo;
    __stack0_0->pTo = __stack1_0;
#line 17 "D:\\PROJECT\\IL2C\\tests\\WDM\\WDM.Code\\InterceptCDRomDevice.cs"
    __stack0_0 = __this;
    __stack1_1 = size;
    __stack0_0->size = __stack1_1;
#line 18 "D:\\PROJECT\\IL2C\\tests\\WDM\\WDM.Code\\InterceptCDRomDevice.cs"
    __gc_unlink_execution_frame__(&__executionFrame__);
    return;
}

///////////////////////////////////////
// ReadCompleted

uint32_t WDM_Code_InterceptCDRomDevice_ReadCompleted(WDM_Code_InterceptCDRomDevice* __this, intptr_t pBuffer, int32_t offset, int32_t size)
{
    //-------------------
    // Local variables:

    intptr_t local0;
    bool local1;
    uint32_t local2;

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

    struct /* __EXECUTION_FRAME__ */
    {
        __EXECUTION_FRAME__* pNext;
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
    __gc_link_execution_frame__(&__executionFrame__);

    //-------------------
    // IL body:

#line 21 "D:\\PROJECT\\IL2C\\tests\\WDM\\WDM.Code\\InterceptCDRomDevice.cs"
#line 22 "D:\\PROJECT\\IL2C\\tests\\WDM\\WDM.Code\\InterceptCDRomDevice.cs"
    __stack0_0 = pBuffer;
    __stack1_0 = offset;
    __stack0_0 = System_IntPtr_op_Addition(__stack0_0, __stack1_0);
    __stack1_0 = size;
    __stack2_0 = __this;
    __stack2_1 = __stack2_0->pFrom;
    __stack3_0 = __this;
    __stack3_1 = __stack3_0->size;
    __stack0_0 = WDM_Code_Wdm_memmem(__stack0_0, __stack1_0, __stack2_1, __stack3_1);
    local0 = __stack0_0;
#line 23 "D:\\PROJECT\\IL2C\\tests\\WDM\\WDM.Code\\InterceptCDRomDevice.cs"
    __stack0_0 = local0;
    __stack1_1 = System_IntPtr_Zero;
    __stack0_1 = System_IntPtr_op_Inequality(__stack0_0, __stack1_1);
    local1 = __stack0_1 ? true : false;
    __stack0_1 = local1;
    if (__stack0_1 == 0) goto L_0000;
#line 24 "D:\\PROJECT\\IL2C\\tests\\WDM\\WDM.Code\\InterceptCDRomDevice.cs"
#line 25 "D:\\PROJECT\\IL2C\\tests\\WDM\\WDM.Code\\InterceptCDRomDevice.cs"
    __stack0_2 = __string1 /* "Draw BABEL!!
" */;
    WDM_Code_Wdm_DbgPrint(__stack0_2);
#line 27 "D:\\PROJECT\\IL2C\\tests\\WDM\\WDM.Code\\InterceptCDRomDevice.cs"
    __stack0_0 = local0;
    __stack1_2 = __this;
    __stack1_1 = __stack1_2->pTo;
    __stack2_0 = __this;
    __stack2_2 = __stack2_0->size;
    WDM_Code_Wdm_memcpy(__stack0_0, __stack1_1, __stack2_2);
#line 28 "D:\\PROJECT\\IL2C\\tests\\WDM\\WDM.Code\\InterceptCDRomDevice.cs"
#line 30 "D:\\PROJECT\\IL2C\\tests\\WDM\\WDM.Code\\InterceptCDRomDevice.cs"
L_0000:
    __stack0_1 = 0;
    local2 = (uint32_t)__stack0_1;
    goto L_0001;
#line 31 "D:\\PROJECT\\IL2C\\tests\\WDM\\WDM.Code\\InterceptCDRomDevice.cs"
L_0001:
    __stack0_1 = local2;
    __gc_unlink_execution_frame__(&__executionFrame__);
    return (uint32_t)__stack0_1;
}

////////////////////////////////////////////////////////////
// Type: WDM.Code.Wdm

//////////////////////
// Runtime helpers:

static void __WDM_Code_Wdm_MARK_HANDLER__(void* pReference)
{
    __typeof__(System_Object)->pMarkHandler(pReference);
}

static __RUNTIME_TYPE_DEF__ __WDM_Code_Wdm_RUNTIME_TYPE_DEF__ = {
    "WDM.Code.Wdm",
    0,
    __WDM_Code_Wdm_MARK_HANDLER__ };
const __RUNTIME_TYPE__ __WDM_Code_Wdm_RUNTIME_TYPE__ = &__WDM_Code_Wdm_RUNTIME_TYPE_DEF__;

///////////////////////////////////////
// P/Invoke: DbgPrint

void WDM_Code_Wdm_DbgPrint(System_String* message)
{
    DbgPrint(message->pString);
}

///////////////////////////////////////
// P/Invoke: DbgPrint

void WDM_Code_Wdm_DbgPrint_1(uint32_t componentId, uint32_t level, System_String* message)
{
    DbgPrintEx(componentId, level, message->pString);
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

void WDM_Code_Wdm__ctor(WDM_Code_Wdm* __this)
{
    //-------------------
    // Local variables:


    //-------------------
    // Evaluation stacks:

    WDM_Code_Wdm* __stack0_0 = NULL;

    //-------------------
    // Setup stack frame:

    struct /* __EXECUTION_FRAME__ */
    {
        __EXECUTION_FRAME__* pNext;
        uint8_t targetCount;
        WDM_Code_Wdm** p__stack0_0;
    } __executionFrame__;

    __executionFrame__.targetCount = 1;
    __executionFrame__.p__stack0_0 = &__stack0_0;
    __gc_link_execution_frame__(&__executionFrame__);

    //-------------------
    // IL body:

    __stack0_0 = __this;
    System_Object__ctor((System_Object*)__stack0_0);
    __gc_unlink_execution_frame__(&__executionFrame__);
    return;
}
