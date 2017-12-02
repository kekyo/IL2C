#include <Arduino.h>
#include <WioLTE.h>
#include "il2c_test_target.h"

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

int32_t il2c_test_target_ClassTypeTestTarget_Value1 = 0;
il2c_test_target_ClassTypeTestTarget* il2c_test_target_ClassTypeTestTarget_OR1 = NULL;


int32_t il2c_test_target_BoxingTest_x = 0;



int32_t il2c_test_target_ValueTypeTestTarget_Value1 = 0;




//////////////////////////////////////////////////////////////////////////////////
// Methods:

////////////////////////////////////////////////////////////
// Type: il2c_test_target.ClassTypeTestTarget

///////////////////////////////////////
// GetValue2

int32_t il2c_test_target_ClassTypeTestTarget_GetValue2(il2c_test_target_ClassTypeTestTarget* __this, int32_t a, int32_t b)
{
    //-------------------
    // Local variables:

    int32_t local0;

    //-------------------
    // Evaluation stacks:

    il2c_test_target_ClassTypeTestTarget* __stack0_0 = NULL;
    int32_t __stack0_1;
    int32_t __stack1_0;

    //-------------------
    // Setup stack frame:

    struct /* __EXECUTION_FRAME__ */
    {
        __EXECUTION_FRAME__* pNext;
        uint8_t targetCount;
        il2c_test_target_ClassTypeTestTarget** p__stack0_0;
    } __executionFrame__;

    __executionFrame__.targetCount = 1;
    __executionFrame__.p__stack0_0 = &__stack0_0;
    __gc_link_execution_frame__(&__executionFrame__);

    //-------------------
    // IL body:

    __stack0_0 = __this;
    __stack0_1 = __stack0_0->Value2;
    __stack1_0 = a;
    __stack0_1 = __stack0_1 + __stack1_0;
    __stack1_0 = b;
    __stack0_1 = __stack0_1 + __stack1_0;
    local0 = __stack0_1;
    goto L_0000;
L_0000:
    __stack0_1 = local0;
    __gc_unlink_execution_frame__(&__executionFrame__);
    return __stack0_1;
}

///////////////////////////////////////
// .ctor

void il2c_test_target_ClassTypeTestTarget__ctor(il2c_test_target_ClassTypeTestTarget* __this)
{
    //-------------------
    // Local variables:


    //-------------------
    // Evaluation stacks:

    il2c_test_target_ClassTypeTestTarget* __stack0_0 = NULL;

    //-------------------
    // Setup stack frame:

    struct /* __EXECUTION_FRAME__ */
    {
        __EXECUTION_FRAME__* pNext;
        uint8_t targetCount;
        il2c_test_target_ClassTypeTestTarget** p__stack0_0;
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

//////////////////////
// Runtime helpers:

static void __il2c_test_target_ClassTypeTestTarget_MARK_HANDLER__(void* pReference)
{
    __TRY_MARK_FROM_HANDLER__(((il2c_test_target_ClassTypeTestTarget*)pReference)->OR2);
    __typeof__(System_Object)->pMarkHandler(pReference);
}

static const __RUNTIME_TYPE_DEF__ __il2c_test_target_ClassTypeTestTarget_RUNTIME_TYPE_DEF__ = {
    "il2c_test_target.ClassTypeTestTarget",
    sizeof(il2c_test_target_ClassTypeTestTarget),
    __il2c_test_target_ClassTypeTestTarget_MARK_HANDLER__ };
__RUNTIME_TYPE__ __il2c_test_target_ClassTypeTestTarget_RUNTIME_TYPE__ = &__il2c_test_target_ClassTypeTestTarget_RUNTIME_TYPE_DEF__;

////////////////////////////////////////////////////////////
// Type: il2c_test_target.ClassTypeTest

///////////////////////////////////////
// Test4

int32_t il2c_test_target_ClassTypeTest_Test4(void)
{
    //-------------------
    // Local variables:

    il2c_test_target_ClassTypeTestTarget* local0 = NULL;
    int32_t local1;

    //-------------------
    // Evaluation stacks:

    il2c_test_target_ClassTypeTestTarget* __stack0_0 = NULL;
    int32_t __stack0_1;
    int32_t __stack1_0;

    //-------------------
    // Setup stack frame:

    struct /* __EXECUTION_FRAME__ */
    {
        __EXECUTION_FRAME__* pNext;
        uint8_t targetCount;
        il2c_test_target_ClassTypeTestTarget** plocal0;
        il2c_test_target_ClassTypeTestTarget** p__stack0_0;
    } __executionFrame__;

    __executionFrame__.targetCount = 2;
    __executionFrame__.plocal0 = &local0;
    __executionFrame__.p__stack0_0 = &__stack0_0;
    __gc_link_execution_frame__(&__executionFrame__);

    //-------------------
    // IL body:

    __new__(&__stack0_0, il2c_test_target_ClassTypeTestTarget)(__stack0_0);
    local0 = __stack0_0;
    __stack0_0 = local0;
    __stack1_0 = 456;
    __stack0_0->Value2 = __stack1_0;
    __stack0_0 = local0;
    __stack0_1 = __stack0_0->Value2;
    local1 = __stack0_1;
    goto L_0000;
L_0000:
    __stack0_1 = local1;
    __gc_unlink_execution_frame__(&__executionFrame__);
    return __stack0_1;
}

///////////////////////////////////////
// Test5

int32_t il2c_test_target_ClassTypeTest_Test5(void)
{
    //-------------------
    // Local variables:

    il2c_test_target_ClassTypeTestTarget* local0 = NULL;
    int32_t local1;
    int32_t local2;

    //-------------------
    // Evaluation stacks:

    il2c_test_target_ClassTypeTestTarget* __stack0_0 = NULL;
    int32_t __stack0_1;
    int32_t __stack1_0;
    int32_t __stack2_0;

    //-------------------
    // Setup stack frame:

    struct /* __EXECUTION_FRAME__ */
    {
        __EXECUTION_FRAME__* pNext;
        uint8_t targetCount;
        il2c_test_target_ClassTypeTestTarget** plocal0;
        il2c_test_target_ClassTypeTestTarget** p__stack0_0;
    } __executionFrame__;

    __executionFrame__.targetCount = 2;
    __executionFrame__.plocal0 = &local0;
    __executionFrame__.p__stack0_0 = &__stack0_0;
    __gc_link_execution_frame__(&__executionFrame__);

    //-------------------
    // IL body:

    __new__(&__stack0_0, il2c_test_target_ClassTypeTestTarget)(__stack0_0);
    local0 = __stack0_0;
    __stack0_0 = local0;
    __stack1_0 = 789;
    __stack0_0->Value2 = __stack1_0;
    __stack0_0 = local0;
    __stack1_0 = 123;
    __stack2_0 = 456;
    __stack0_1 = il2c_test_target_ClassTypeTestTarget_GetValue2(__stack0_0, __stack1_0, __stack2_0);
    local1 = __stack0_1;
    __stack0_1 = local1;
    local2 = __stack0_1;
    goto L_0000;
L_0000:
    __stack0_1 = local2;
    __gc_unlink_execution_frame__(&__executionFrame__);
    return __stack0_1;
}

///////////////////////////////////////
// .ctor

void il2c_test_target_ClassTypeTest__ctor(il2c_test_target_ClassTypeTest* __this)
{
    //-------------------
    // Local variables:


    //-------------------
    // Evaluation stacks:

    il2c_test_target_ClassTypeTest* __stack0_0 = NULL;

    //-------------------
    // Setup stack frame:

    struct /* __EXECUTION_FRAME__ */
    {
        __EXECUTION_FRAME__* pNext;
        uint8_t targetCount;
        il2c_test_target_ClassTypeTest** p__stack0_0;
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

//////////////////////
// Runtime helpers:

static void __il2c_test_target_ClassTypeTest_MARK_HANDLER__(void* pReference)
{
    __typeof__(System_Object)->pMarkHandler(pReference);
}

static const __RUNTIME_TYPE_DEF__ __il2c_test_target_ClassTypeTest_RUNTIME_TYPE_DEF__ = {
    "il2c_test_target.ClassTypeTest",
    0,
    __il2c_test_target_ClassTypeTest_MARK_HANDLER__ };
__RUNTIME_TYPE__ __il2c_test_target_ClassTypeTest_RUNTIME_TYPE__ = &__il2c_test_target_ClassTypeTest_RUNTIME_TYPE_DEF__;

////////////////////////////////////////////////////////////
// Type: il2c_test_target.BoxingTest

///////////////////////////////////////
// BoxingInt32

void il2c_test_target_BoxingTest_BoxingInt32(int32_t a)
{
    //-------------------
    // Local variables:

    System_Object* local0 = NULL;
    int32_t local1;

    //-------------------
    // Evaluation stacks:

    int32_t __stack0_0;
    System_Object* __stack0_1 = NULL;
    int32_t __stack0_2;

    //-------------------
    // Setup stack frame:

    struct /* __EXECUTION_FRAME__ */
    {
        __EXECUTION_FRAME__* pNext;
        uint8_t targetCount;
        System_Object** plocal0;
        System_Object** p__stack0_1;
    } __executionFrame__;

    __executionFrame__.targetCount = 2;
    __executionFrame__.plocal0 = &local0;
    __executionFrame__.p__stack0_1 = &__stack0_1;
    __gc_link_execution_frame__(&__executionFrame__);

    //-------------------
    // IL body:

    __stack0_0 = a;
    __stack0_1 = __box__(&__stack0_0, __typeof__(System_Int32));
    local0 = __stack0_1;
    __stack0_1 = local0;
    __stack0_2 = *((int32_t*)__unbox__(__stack0_1, __typeof__(System_Int32)));
    local1 = __stack0_2;
    __gc_unlink_execution_frame__(&__executionFrame__);
    return;
}

///////////////////////////////////////
// .ctor

void il2c_test_target_BoxingTest__ctor(il2c_test_target_BoxingTest* __this)
{
    //-------------------
    // Local variables:


    //-------------------
    // Evaluation stacks:

    il2c_test_target_BoxingTest* __stack0_0 = NULL;

    //-------------------
    // Setup stack frame:

    struct /* __EXECUTION_FRAME__ */
    {
        __EXECUTION_FRAME__* pNext;
        uint8_t targetCount;
        il2c_test_target_BoxingTest** p__stack0_0;
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

//////////////////////
// Runtime helpers:

static void __il2c_test_target_BoxingTest_MARK_HANDLER__(void* pReference)
{
    __typeof__(System_Object)->pMarkHandler(pReference);
}

static const __RUNTIME_TYPE_DEF__ __il2c_test_target_BoxingTest_RUNTIME_TYPE_DEF__ = {
    "il2c_test_target.BoxingTest",
    0,
    __il2c_test_target_BoxingTest_MARK_HANDLER__ };
__RUNTIME_TYPE__ __il2c_test_target_BoxingTest_RUNTIME_TYPE__ = &__il2c_test_target_BoxingTest_RUNTIME_TYPE_DEF__;

////////////////////////////////////////////////////////////
// Type: il2c_test_target.Arduino

///////////////////////////////////////
// P/Invoke: DigitalRead

int32_t il2c_test_target_Arduino_DigitalRead(uint8_t pin)
{
    return digitalRead(pin);
}

///////////////////////////////////////
// P/Invoke: DigitalWrite

void il2c_test_target_Arduino_DigitalWrite(uint8_t pin, uint8_t val)
{
    digitalWrite(pin, val);
}

///////////////////////////////////////
// P/Invoke: Delay

void il2c_test_target_Arduino_Delay(int32_t milliseconds)
{
    delay(milliseconds);
}

///////////////////////////////////////
// .ctor

void il2c_test_target_Arduino__ctor(il2c_test_target_Arduino* __this)
{
    //-------------------
    // Local variables:


    //-------------------
    // Evaluation stacks:

    il2c_test_target_Arduino* __stack0_0 = NULL;

    //-------------------
    // Setup stack frame:

    struct /* __EXECUTION_FRAME__ */
    {
        __EXECUTION_FRAME__* pNext;
        uint8_t targetCount;
        il2c_test_target_Arduino** p__stack0_0;
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

//////////////////////
// Runtime helpers:

static void __il2c_test_target_Arduino_MARK_HANDLER__(void* pReference)
{
    __typeof__(System_Object)->pMarkHandler(pReference);
}

static const __RUNTIME_TYPE_DEF__ __il2c_test_target_Arduino_RUNTIME_TYPE_DEF__ = {
    "il2c_test_target.Arduino",
    0,
    __il2c_test_target_Arduino_MARK_HANDLER__ };
__RUNTIME_TYPE__ __il2c_test_target_Arduino_RUNTIME_TYPE__ = &__il2c_test_target_Arduino_RUNTIME_TYPE_DEF__;

////////////////////////////////////////////////////////////
// Type: il2c_test_target.Wio

///////////////////////////////////////
// P/Invoke: Init

void il2c_test_target_Wio_Init(void)
{
    Wio.Init();
}

///////////////////////////////////////
// P/Invoke: LedSetRGB

void il2c_test_target_Wio_LedSetRGB(int32_t r, int32_t g, int32_t b)
{
    Wio.LedSetRGB(r, g, b);
}

///////////////////////////////////////
// .ctor

void il2c_test_target_Wio__ctor(il2c_test_target_Wio* __this)
{
    //-------------------
    // Local variables:


    //-------------------
    // Evaluation stacks:

    il2c_test_target_Wio* __stack0_0 = NULL;

    //-------------------
    // Setup stack frame:

    struct /* __EXECUTION_FRAME__ */
    {
        __EXECUTION_FRAME__* pNext;
        uint8_t targetCount;
        il2c_test_target_Wio** p__stack0_0;
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

//////////////////////
// Runtime helpers:

static void __il2c_test_target_Wio_MARK_HANDLER__(void* pReference)
{
    __typeof__(System_Object)->pMarkHandler(pReference);
}

static const __RUNTIME_TYPE_DEF__ __il2c_test_target_Wio_RUNTIME_TYPE_DEF__ = {
    "il2c_test_target.Wio",
    0,
    __il2c_test_target_Wio_MARK_HANDLER__ };
__RUNTIME_TYPE__ __il2c_test_target_Wio_RUNTIME_TYPE__ = &__il2c_test_target_Wio_RUNTIME_TYPE_DEF__;

////////////////////////////////////////////////////////////
// Type: il2c_test_target.ValueTypeTestTarget

///////////////////////////////////////
// GetValue2

int32_t il2c_test_target_ValueTypeTestTarget_GetValue2(il2c_test_target_ValueTypeTestTarget* __this, int32_t a, int32_t b)
{
    //-------------------
    // Local variables:

    int32_t local0;

    //-------------------
    // Evaluation stacks:

    il2c_test_target_ValueTypeTestTarget* __stack0_0 = NULL;
    int32_t __stack0_1;
    int32_t __stack1_0;

    //-------------------
    // Setup stack frame:

    struct /* __EXECUTION_FRAME__ */
    {
        __EXECUTION_FRAME__* pNext;
        uint8_t targetCount;
        il2c_test_target_ValueTypeTestTarget** p__stack0_0;
    } __executionFrame__;

    __executionFrame__.targetCount = 1;
    __executionFrame__.p__stack0_0 = &__stack0_0;
    __gc_link_execution_frame__(&__executionFrame__);

    //-------------------
    // IL body:

    __stack0_0 = __this;
    __stack0_1 = __stack0_0->Value2;
    __stack1_0 = a;
    __stack0_1 = __stack0_1 + __stack1_0;
    __stack1_0 = b;
    __stack0_1 = __stack0_1 + __stack1_0;
    local0 = __stack0_1;
    goto L_0000;
L_0000:
    __stack0_1 = local0;
    __gc_unlink_execution_frame__(&__executionFrame__);
    return __stack0_1;
}

////////////////////////////////////////////////////////////
// Type: il2c_test_target.ValueTypeTest

///////////////////////////////////////
// Test4

int32_t il2c_test_target_ValueTypeTest_Test4(void)
{
    //-------------------
    // Local variables:

    il2c_test_target_ValueTypeTestTarget local0;
    int32_t local1;

    //-------------------
    // Evaluation stacks:

    il2c_test_target_ValueTypeTestTarget* __stack0_0 = NULL;
    il2c_test_target_ValueTypeTestTarget* __stack0_1 = NULL;
    il2c_test_target_ValueTypeTestTarget __stack0_2;
    int32_t __stack0_3;
    int32_t __stack1_0;

    //-------------------
    // Setup stack frame:

    struct /* __EXECUTION_FRAME__ */
    {
        __EXECUTION_FRAME__* pNext;
        uint8_t targetCount;
        il2c_test_target_ValueTypeTestTarget** p__stack0_0;
        il2c_test_target_ValueTypeTestTarget** p__stack0_1;
    } __executionFrame__;

    __executionFrame__.targetCount = 2;
    __executionFrame__.p__stack0_0 = &__stack0_0;
    __executionFrame__.p__stack0_1 = &__stack0_1;
    __gc_link_execution_frame__(&__executionFrame__);

    //-------------------
    // IL body:

    __stack0_0 = &local0;
    memset(__stack0_0, 0x00, sizeof(il2c_test_target_ValueTypeTestTarget));
    __stack0_1 = &local0;
    __stack1_0 = 456;
    __stack0_1->Value2 = __stack1_0;
    __stack0_2 = local0;
    __stack0_3 = __stack0_2.Value2;
    local1 = __stack0_3;
    goto L_0000;
L_0000:
    __stack0_3 = local1;
    __gc_unlink_execution_frame__(&__executionFrame__);
    return __stack0_3;
}

///////////////////////////////////////
// Test5

int32_t il2c_test_target_ValueTypeTest_Test5(void)
{
    //-------------------
    // Local variables:

    il2c_test_target_ValueTypeTestTarget local0;
    int32_t local1;
    int32_t local2;

    //-------------------
    // Evaluation stacks:

    il2c_test_target_ValueTypeTestTarget* __stack0_0 = NULL;
    il2c_test_target_ValueTypeTestTarget* __stack0_1 = NULL;
    il2c_test_target_ValueTypeTestTarget* __stack0_2 = NULL;
    int32_t __stack0_3;
    int32_t __stack1_0;
    int32_t __stack2_0;

    //-------------------
    // Setup stack frame:

    struct /* __EXECUTION_FRAME__ */
    {
        __EXECUTION_FRAME__* pNext;
        uint8_t targetCount;
        il2c_test_target_ValueTypeTestTarget** p__stack0_0;
        il2c_test_target_ValueTypeTestTarget** p__stack0_1;
        il2c_test_target_ValueTypeTestTarget** p__stack0_2;
    } __executionFrame__;

    __executionFrame__.targetCount = 3;
    __executionFrame__.p__stack0_0 = &__stack0_0;
    __executionFrame__.p__stack0_1 = &__stack0_1;
    __executionFrame__.p__stack0_2 = &__stack0_2;
    __gc_link_execution_frame__(&__executionFrame__);

    //-------------------
    // IL body:

    __stack0_0 = &local0;
    memset(__stack0_0, 0x00, sizeof(il2c_test_target_ValueTypeTestTarget));
    __stack0_1 = &local0;
    __stack1_0 = 789;
    __stack0_1->Value2 = __stack1_0;
    __stack0_2 = &local0;
    __stack1_0 = 123;
    __stack2_0 = 456;
    __stack0_3 = il2c_test_target_ValueTypeTestTarget_GetValue2(__stack0_2, __stack1_0, __stack2_0);
    local1 = __stack0_3;
    __stack0_3 = local1;
    local2 = __stack0_3;
    goto L_0000;
L_0000:
    __stack0_3 = local2;
    __gc_unlink_execution_frame__(&__executionFrame__);
    return __stack0_3;
}

///////////////////////////////////////
// .ctor

void il2c_test_target_ValueTypeTest__ctor(il2c_test_target_ValueTypeTest* __this)
{
    //-------------------
    // Local variables:


    //-------------------
    // Evaluation stacks:

    il2c_test_target_ValueTypeTest* __stack0_0 = NULL;

    //-------------------
    // Setup stack frame:

    struct /* __EXECUTION_FRAME__ */
    {
        __EXECUTION_FRAME__* pNext;
        uint8_t targetCount;
        il2c_test_target_ValueTypeTest** p__stack0_0;
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

//////////////////////
// Runtime helpers:

static void __il2c_test_target_ValueTypeTest_MARK_HANDLER__(void* pReference)
{
    __typeof__(System_Object)->pMarkHandler(pReference);
}

static const __RUNTIME_TYPE_DEF__ __il2c_test_target_ValueTypeTest_RUNTIME_TYPE_DEF__ = {
    "il2c_test_target.ValueTypeTest",
    0,
    __il2c_test_target_ValueTypeTest_MARK_HANDLER__ };
__RUNTIME_TYPE__ __il2c_test_target_ValueTypeTest_RUNTIME_TYPE__ = &__il2c_test_target_ValueTypeTest_RUNTIME_TYPE_DEF__;

////////////////////////////////////////////////////////////
// Type: il2c_test_target.Hoge2

///////////////////////////////////////
// Add3

uint8_t il2c_test_target_Hoge2_Add3(uint8_t a, bool isTwo)
{
    //-------------------
    // Local variables:

    uint8_t local0;

    //-------------------
    // Evaluation stacks:

    int32_t __stack0_0;
    int32_t __stack1_0;

    //-------------------
    // IL body:

    __stack0_0 = a;
    __stack1_0 = isTwo ? 1 : 0;
    if (__stack1_0 != 0) goto L_0000;
    __stack1_0 = 1;
    goto L_0001;
L_0000:
    __stack1_0 = 2;
L_0001:
    __stack0_0 = __stack0_0 + __stack1_0;
    __stack0_0 = (uint8_t)__stack0_0;
    local0 = (uint8_t)__stack0_0;
    goto L_0002;
L_0002:
    __stack0_0 = local0;
    return (uint8_t)__stack0_0;
}

///////////////////////////////////////
// Add4

uint16_t il2c_test_target_Hoge2_Add4(uint16_t a, bool isTwo)
{
    //-------------------
    // Local variables:

    uint16_t local0;

    //-------------------
    // Evaluation stacks:

    int32_t __stack0_0;
    int32_t __stack1_0;

    //-------------------
    // IL body:

    __stack0_0 = a;
    __stack1_0 = isTwo ? 1 : 0;
    if (__stack1_0 != 0) goto L_0000;
    __stack1_0 = 1;
    goto L_0001;
L_0000:
    __stack1_0 = 2;
L_0001:
    __stack0_0 = __stack0_0 + __stack1_0;
    __stack0_0 = (uint16_t)__stack0_0;
    local0 = (uint16_t)__stack0_0;
    goto L_0002;
L_0002:
    __stack0_0 = local0;
    return (uint16_t)__stack0_0;
}

///////////////////////////////////////
// .ctor

void il2c_test_target_Hoge2__ctor(il2c_test_target_Hoge2* __this)
{
    //-------------------
    // Local variables:


    //-------------------
    // Evaluation stacks:

    il2c_test_target_Hoge2* __stack0_0 = NULL;

    //-------------------
    // Setup stack frame:

    struct /* __EXECUTION_FRAME__ */
    {
        __EXECUTION_FRAME__* pNext;
        uint8_t targetCount;
        il2c_test_target_Hoge2** p__stack0_0;
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

//////////////////////
// Runtime helpers:

static void __il2c_test_target_Hoge2_MARK_HANDLER__(void* pReference)
{
    __typeof__(System_Object)->pMarkHandler(pReference);
}

static const __RUNTIME_TYPE_DEF__ __il2c_test_target_Hoge2_RUNTIME_TYPE_DEF__ = {
    "il2c_test_target.Hoge2",
    0,
    __il2c_test_target_Hoge2_MARK_HANDLER__ };
__RUNTIME_TYPE__ __il2c_test_target_Hoge2_RUNTIME_TYPE__ = &__il2c_test_target_Hoge2_RUNTIME_TYPE_DEF__;

////////////////////////////////////////////////////////////
// Type: il2c_test_target.Hoge1

///////////////////////////////////////
// Add1

int32_t il2c_test_target_Hoge1_Add1(int32_t a, bool isTwo)
{
    //-------------------
    // Local variables:

    int32_t local0;

    //-------------------
    // Evaluation stacks:

    int32_t __stack0_0;
    int32_t __stack1_0;

    //-------------------
    // IL body:

    __stack0_0 = a;
    __stack1_0 = isTwo ? 1 : 0;
    if (__stack1_0 != 0) goto L_0000;
    __stack1_0 = 1;
    goto L_0001;
L_0000:
    __stack1_0 = 2;
L_0001:
    __stack0_0 = __stack0_0 + __stack1_0;
    local0 = __stack0_0;
    goto L_0002;
L_0002:
    __stack0_0 = local0;
    return __stack0_0;
}

///////////////////////////////////////
// Add2

int64_t il2c_test_target_Hoge1_Add2(int64_t a, bool isTwo)
{
    //-------------------
    // Local variables:

    int64_t local0;

    //-------------------
    // Evaluation stacks:

    int64_t __stack0_0;
    int32_t __stack1_0;
    int64_t __stack1_1;

    //-------------------
    // IL body:

    __stack0_0 = a;
    __stack1_0 = isTwo ? 1 : 0;
    if (__stack1_0 != 0) goto L_0000;
    __stack1_0 = 1;
    goto L_0001;
L_0000:
    __stack1_0 = 2;
L_0001:
    __stack1_1 = __stack1_0;
    __stack0_0 = __stack0_0 + __stack1_1;
    local0 = __stack0_0;
    goto L_0002;
L_0002:
    __stack0_0 = local0;
    return __stack0_0;
}

///////////////////////////////////////
// .ctor

void il2c_test_target_Hoge1__ctor(il2c_test_target_Hoge1* __this)
{
    //-------------------
    // Local variables:


    //-------------------
    // Evaluation stacks:

    il2c_test_target_Hoge1* __stack0_0 = NULL;

    //-------------------
    // Setup stack frame:

    struct /* __EXECUTION_FRAME__ */
    {
        __EXECUTION_FRAME__* pNext;
        uint8_t targetCount;
        il2c_test_target_Hoge1** p__stack0_0;
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

//////////////////////
// Runtime helpers:

static void __il2c_test_target_Hoge1_MARK_HANDLER__(void* pReference)
{
    __typeof__(System_Object)->pMarkHandler(pReference);
}

static const __RUNTIME_TYPE_DEF__ __il2c_test_target_Hoge1_RUNTIME_TYPE_DEF__ = {
    "il2c_test_target.Hoge1",
    0,
    __il2c_test_target_Hoge1_MARK_HANDLER__ };
__RUNTIME_TYPE__ __il2c_test_target_Hoge1_RUNTIME_TYPE__ = &__il2c_test_target_Hoge1_RUNTIME_TYPE_DEF__;
