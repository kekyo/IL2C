#include <wdm.h>
#include "WDM.Code.h"

//////////////////////////////////////////////////////////////////////////////////
// Const strings:

__DEFINE_CONST_STRING__(__string0, "Hello driver constructor called!!");

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
    0,
    __WDM_Code_InterceptCDRomDevice_MARK_HANDLER__ };
const __RUNTIME_TYPE__ __WDM_Code_InterceptCDRomDevice_RUNTIME_TYPE__ = &__WDM_Code_InterceptCDRomDevice_RUNTIME_TYPE_DEF__;

///////////////////////////////////////
// .ctor

void WDM_Code_InterceptCDRomDevice__ctor(WDM_Code_InterceptCDRomDevice* __this)
{
    //-------------------
    // Local variables:


    //-------------------
    // Evaluation stacks:

    WDM_Code_InterceptCDRomDevice* __stack0_0 = NULL;
    System_String* __stack0_1 = NULL;

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

    __stack0_0 = __this;
    System_Object__ctor((System_Object*)__stack0_0);
    __stack0_1 = __string0 /* "Hello driver constructor called!!" */;
    WDM_Code_Wdm_DbgPrint(__stack0_1);
    __gc_unlink_execution_frame__(&__executionFrame__);
    return;
}

///////////////////////////////////////
// ReadCompleted

uint32_t WDM_Code_InterceptCDRomDevice_ReadCompleted(WDM_Code_InterceptCDRomDevice* __this, intptr_t pIrp)
{
    //-------------------
    // Local variables:

    uint32_t local0;

    //-------------------
    // Evaluation stacks:

    int32_t __stack0_0;

    //-------------------
    // IL body:

    __stack0_0 = 0;
    local0 = (uint32_t)__stack0_0;
    goto L_0000;
L_0000:
    __stack0_0 = local0;
    return (uint32_t)__stack0_0;
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
