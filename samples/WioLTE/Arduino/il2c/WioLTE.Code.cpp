#include <Arduino.h>
#include <WioLTE.h>
#include "WioLTE.Code.h"

//////////////////////////////////////////////////////////////////////////////////
// Const strings:


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
// Type: WioLTE.Code.Arduino

//////////////////////
// Runtime helpers:

static void __WioLTE_Code_Arduino_MARK_HANDLER__(void* pReference)
{
    __typeof__(System_Object)->pMarkHandler(pReference);
}

static __RUNTIME_TYPE_DEF__ __WioLTE_Code_Arduino_RUNTIME_TYPE_DEF__ = {
    "WioLTE.Code.Arduino",
    0,
    __WioLTE_Code_Arduino_MARK_HANDLER__ };
const __RUNTIME_TYPE__ __WioLTE_Code_Arduino_RUNTIME_TYPE__ = &__WioLTE_Code_Arduino_RUNTIME_TYPE_DEF__;

///////////////////////////////////////
// P/Invoke: DigitalRead

int32_t WioLTE_Code_Arduino_DigitalRead(uint8_t pin)
{
    return digitalRead(pin);
}

///////////////////////////////////////
// P/Invoke: DigitalWrite

void WioLTE_Code_Arduino_DigitalWrite(uint8_t pin, uint8_t val)
{
    digitalWrite(pin, val);
}

///////////////////////////////////////
// P/Invoke: Delay

void WioLTE_Code_Arduino_Delay(int32_t milliseconds)
{
    delay(milliseconds);
}

///////////////////////////////////////
// P/Invoke: PrintLn

void WioLTE_Code_Arduino_PrintLn(System_String* message)
{
    SerialUSB.println(message->pString);
}

///////////////////////////////////////
// .ctor

void WioLTE_Code_Arduino__ctor(WioLTE_Code_Arduino* __this)
{
    //-------------------
    // Local variables:


    //-------------------
    // Evaluation stacks:

    WioLTE_Code_Arduino* __stack0_0 = NULL;

    //-------------------
    // Setup stack frame:

    struct /* __EXECUTION_FRAME__ */
    {
        __EXECUTION_FRAME__* pNext;
        uint8_t targetCount;
        WioLTE_Code_Arduino** p__stack0_0;
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

////////////////////////////////////////////////////////////
// Type: WioLTE.Code.Wio

//////////////////////
// Runtime helpers:

static void __WioLTE_Code_Wio_MARK_HANDLER__(void* pReference)
{
    __typeof__(System_Object)->pMarkHandler(pReference);
}

static __RUNTIME_TYPE_DEF__ __WioLTE_Code_Wio_RUNTIME_TYPE_DEF__ = {
    "WioLTE.Code.Wio",
    0,
    __WioLTE_Code_Wio_MARK_HANDLER__ };
const __RUNTIME_TYPE__ __WioLTE_Code_Wio_RUNTIME_TYPE__ = &__WioLTE_Code_Wio_RUNTIME_TYPE_DEF__;

///////////////////////////////////////
// P/Invoke: Init

void WioLTE_Code_Wio_Init(void)
{
    Wio.Init();
}

///////////////////////////////////////
// P/Invoke: LedSetRGB

void WioLTE_Code_Wio_LedSetRGB(int32_t r, int32_t g, int32_t b)
{
    Wio.LedSetRGB(r, g, b);
}

///////////////////////////////////////
// .ctor

void WioLTE_Code_Wio__ctor(WioLTE_Code_Wio* __this)
{
    //-------------------
    // Local variables:


    //-------------------
    // Evaluation stacks:

    WioLTE_Code_Wio* __stack0_0 = NULL;

    //-------------------
    // Setup stack frame:

    struct /* __EXECUTION_FRAME__ */
    {
        __EXECUTION_FRAME__* pNext;
        uint8_t targetCount;
        WioLTE_Code_Wio** p__stack0_0;
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
