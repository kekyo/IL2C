#include <windows.h>
#include "Win32.Code.h"

//////////////////////////////////////////////////////////////////////////////////
// Const strings:

__DEFINE_CONST_STRING__(__string0, L"ABC");
__DEFINE_CONST_STRING__(__string1, L"DEF");

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

int32_t Win32_Code_BoxingTest_x = 0;

int32_t Win32_Code_ClassTypeTestTarget_Value1 = 0;
Win32_Code_ClassTypeTestTarget* Win32_Code_ClassTypeTestTarget_OR1 = NULL;






int32_t Win32_Code_ValueTypeTestTarget_Value1 = 0;


//////////////////////////////////////////////////////////////////////////////////
// Methods:

////////////////////////////////////////////////////////////
// Type: Win32.Code.BoxingTest

//////////////////////
// Runtime helpers:

static void __Win32_Code_BoxingTest_MARK_HANDLER__(void* pReference)
{
    __typeof__(System_Object)->pMarkHandler(pReference);
}

static __RUNTIME_TYPE_DEF__ __Win32_Code_BoxingTest_RUNTIME_TYPE_DEF__ = {
    "Win32.Code.BoxingTest",
    0,
    __Win32_Code_BoxingTest_MARK_HANDLER__ };
const __RUNTIME_TYPE__ __Win32_Code_BoxingTest_RUNTIME_TYPE__ = &__Win32_Code_BoxingTest_RUNTIME_TYPE_DEF__;

///////////////////////////////////////
// BoxingInt32

void Win32_Code_BoxingTest_BoxingInt32(int32_t a)
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

#line 13 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\BoxingTest.cs"
#line 14 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\BoxingTest.cs"
    __stack0_0 = a;
    __stack0_1 = __box__(&__stack0_0, __typeof__(System_Int32));
    local0 = __stack0_1;
#line 16 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\BoxingTest.cs"
    __stack0_1 = local0;
    __stack0_2 = *((int32_t*)__unbox__(__stack0_1, __typeof__(System_Int32)));
    local1 = __stack0_2;
#line 17 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\BoxingTest.cs"
    __gc_unlink_execution_frame__(&__executionFrame__);
    return;
}

///////////////////////////////////////
// .ctor

void Win32_Code_BoxingTest__ctor(Win32_Code_BoxingTest* __this)
{
    //-------------------
    // Local variables:


    //-------------------
    // Evaluation stacks:

    Win32_Code_BoxingTest* __stack0_0 = NULL;

    //-------------------
    // Setup stack frame:

    struct /* __EXECUTION_FRAME__ */
    {
        __EXECUTION_FRAME__* pNext;
        uint8_t targetCount;
        Win32_Code_BoxingTest** p__stack0_0;
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
// Type: Win32.Code.ClassTypeTestTarget

//////////////////////
// Runtime helpers:

static void __Win32_Code_ClassTypeTestTarget_MARK_HANDLER__(void* pReference)
{
    __TRY_MARK_FROM_HANDLER__(((Win32_Code_ClassTypeTestTarget*)pReference)->OR2);
    __typeof__(System_Object)->pMarkHandler(pReference);
}

static __RUNTIME_TYPE_DEF__ __Win32_Code_ClassTypeTestTarget_RUNTIME_TYPE_DEF__ = {
    "Win32.Code.ClassTypeTestTarget",
    sizeof(Win32_Code_ClassTypeTestTarget),
    __Win32_Code_ClassTypeTestTarget_MARK_HANDLER__ };
const __RUNTIME_TYPE__ __Win32_Code_ClassTypeTestTarget_RUNTIME_TYPE__ = &__Win32_Code_ClassTypeTestTarget_RUNTIME_TYPE_DEF__;

///////////////////////////////////////
// .ctor

void Win32_Code_ClassTypeTestTarget__ctor(Win32_Code_ClassTypeTestTarget* __this)
{
    //-------------------
    // Local variables:


    //-------------------
    // Evaluation stacks:

    Win32_Code_ClassTypeTestTarget* __stack0_0 = NULL;

    //-------------------
    // Setup stack frame:

    struct /* __EXECUTION_FRAME__ */
    {
        __EXECUTION_FRAME__* pNext;
        uint8_t targetCount;
        Win32_Code_ClassTypeTestTarget** p__stack0_0;
    } __executionFrame__;

    __executionFrame__.targetCount = 1;
    __executionFrame__.p__stack0_0 = &__stack0_0;
    __gc_link_execution_frame__(&__executionFrame__);

    //-------------------
    // IL body:

#line 16 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\ClassTypeTest.cs"
    __stack0_0 = __this;
    System_Object__ctor((System_Object*)__stack0_0);
#line 17 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\ClassTypeTest.cs"
#line 18 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\ClassTypeTest.cs"
    __gc_unlink_execution_frame__(&__executionFrame__);
    return;
}

///////////////////////////////////////
// .ctor

void Win32_Code_ClassTypeTestTarget__ctor_1(Win32_Code_ClassTypeTestTarget* __this, int32_t value)
{
    //-------------------
    // Local variables:


    //-------------------
    // Evaluation stacks:

    Win32_Code_ClassTypeTestTarget* __stack0_0 = NULL;
    int32_t __stack1_0;

    //-------------------
    // Setup stack frame:

    struct /* __EXECUTION_FRAME__ */
    {
        __EXECUTION_FRAME__* pNext;
        uint8_t targetCount;
        Win32_Code_ClassTypeTestTarget** p__stack0_0;
    } __executionFrame__;

    __executionFrame__.targetCount = 1;
    __executionFrame__.p__stack0_0 = &__stack0_0;
    __gc_link_execution_frame__(&__executionFrame__);

    //-------------------
    // IL body:

#line 20 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\ClassTypeTest.cs"
    __stack0_0 = __this;
    System_Object__ctor((System_Object*)__stack0_0);
#line 21 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\ClassTypeTest.cs"
#line 22 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\ClassTypeTest.cs"
    __stack0_0 = __this;
    __stack1_0 = value;
    __stack0_0->Value2 = __stack1_0;
#line 23 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\ClassTypeTest.cs"
    __gc_unlink_execution_frame__(&__executionFrame__);
    return;
}

///////////////////////////////////////
// GetValue2

int32_t Win32_Code_ClassTypeTestTarget_GetValue2(Win32_Code_ClassTypeTestTarget* __this, int32_t a, int32_t b)
{
    //-------------------
    // Local variables:

    int32_t local0;

    //-------------------
    // Evaluation stacks:

    Win32_Code_ClassTypeTestTarget* __stack0_0 = NULL;
    int32_t __stack0_1;
    int32_t __stack1_0;

    //-------------------
    // Setup stack frame:

    struct /* __EXECUTION_FRAME__ */
    {
        __EXECUTION_FRAME__* pNext;
        uint8_t targetCount;
        Win32_Code_ClassTypeTestTarget** p__stack0_0;
    } __executionFrame__;

    __executionFrame__.targetCount = 1;
    __executionFrame__.p__stack0_0 = &__stack0_0;
    __gc_link_execution_frame__(&__executionFrame__);

    //-------------------
    // IL body:

#line 26 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\ClassTypeTest.cs"
#line 27 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\ClassTypeTest.cs"
    __stack0_0 = __this;
    __stack0_1 = __stack0_0->Value2;
    __stack1_0 = a;
    __stack0_1 = __stack0_1 + __stack1_0;
    __stack1_0 = b;
    __stack0_1 = __stack0_1 + __stack1_0;
    local0 = __stack0_1;
    goto L_0000;
#line 28 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\ClassTypeTest.cs"
L_0000:
    __stack0_1 = local0;
    __gc_unlink_execution_frame__(&__executionFrame__);
    return __stack0_1;
}

///////////////////////////////////////
// GetValue2

int32_t Win32_Code_ClassTypeTestTarget_GetValue2_1(Win32_Code_ClassTypeTestTarget* __this, int32_t a, int32_t b, int32_t c)
{
    //-------------------
    // Local variables:

    int32_t local0;

    //-------------------
    // Evaluation stacks:

    Win32_Code_ClassTypeTestTarget* __stack0_0 = NULL;
    int32_t __stack0_1;
    int32_t __stack1_0;

    //-------------------
    // Setup stack frame:

    struct /* __EXECUTION_FRAME__ */
    {
        __EXECUTION_FRAME__* pNext;
        uint8_t targetCount;
        Win32_Code_ClassTypeTestTarget** p__stack0_0;
    } __executionFrame__;

    __executionFrame__.targetCount = 1;
    __executionFrame__.p__stack0_0 = &__stack0_0;
    __gc_link_execution_frame__(&__executionFrame__);

    //-------------------
    // IL body:

#line 31 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\ClassTypeTest.cs"
#line 32 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\ClassTypeTest.cs"
    __stack0_0 = __this;
    __stack0_1 = __stack0_0->Value2;
    __stack1_0 = a;
    __stack0_1 = __stack0_1 + __stack1_0;
    __stack1_0 = b;
    __stack0_1 = __stack0_1 + __stack1_0;
    __stack1_0 = c;
    __stack0_1 = __stack0_1 + __stack1_0;
    local0 = __stack0_1;
    goto L_0000;
#line 33 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\ClassTypeTest.cs"
L_0000:
    __stack0_1 = local0;
    __gc_unlink_execution_frame__(&__executionFrame__);
    return __stack0_1;
}

////////////////////////////////////////////////////////////
// Type: Win32.Code.ClassTypeTest

//////////////////////
// Runtime helpers:

static void __Win32_Code_ClassTypeTest_MARK_HANDLER__(void* pReference)
{
    __typeof__(System_Object)->pMarkHandler(pReference);
}

static __RUNTIME_TYPE_DEF__ __Win32_Code_ClassTypeTest_RUNTIME_TYPE_DEF__ = {
    "Win32.Code.ClassTypeTest",
    0,
    __Win32_Code_ClassTypeTest_MARK_HANDLER__ };
const __RUNTIME_TYPE__ __Win32_Code_ClassTypeTest_RUNTIME_TYPE__ = &__Win32_Code_ClassTypeTest_RUNTIME_TYPE_DEF__;

///////////////////////////////////////
// Test4

int32_t Win32_Code_ClassTypeTest_Test4(void)
{
    //-------------------
    // Local variables:

    Win32_Code_ClassTypeTestTarget* local0 = NULL;
    int32_t local1;

    //-------------------
    // Evaluation stacks:

    Win32_Code_ClassTypeTestTarget* __stack0_0 = NULL;
    int32_t __stack0_1;
    int32_t __stack1_0;

    //-------------------
    // Setup stack frame:

    struct /* __EXECUTION_FRAME__ */
    {
        __EXECUTION_FRAME__* pNext;
        uint8_t targetCount;
        Win32_Code_ClassTypeTestTarget** plocal0;
        Win32_Code_ClassTypeTestTarget** p__stack0_0;
    } __executionFrame__;

    __executionFrame__.targetCount = 2;
    __executionFrame__.plocal0 = &local0;
    __executionFrame__.p__stack0_0 = &__stack0_0;
    __gc_link_execution_frame__(&__executionFrame__);

    //-------------------
    // IL body:

#line 39 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\ClassTypeTest.cs"
#line 40 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\ClassTypeTest.cs"
    __new__(&__stack0_0, Win32_Code_ClassTypeTestTarget)(__stack0_0);
    local0 = __stack0_0;
#line 41 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\ClassTypeTest.cs"
    __stack0_0 = local0;
    __stack1_0 = 456;
    __stack0_0->Value2 = __stack1_0;
#line 43 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\ClassTypeTest.cs"
    __stack0_0 = local0;
    __stack0_1 = __stack0_0->Value2;
    local1 = __stack0_1;
    goto L_0000;
#line 44 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\ClassTypeTest.cs"
L_0000:
    __stack0_1 = local1;
    __gc_unlink_execution_frame__(&__executionFrame__);
    return __stack0_1;
}

///////////////////////////////////////
// Test5

int32_t Win32_Code_ClassTypeTest_Test5(void)
{
    //-------------------
    // Local variables:

    Win32_Code_ClassTypeTestTarget* local0 = NULL;
    int32_t local1;
    int32_t local2;

    //-------------------
    // Evaluation stacks:

    Win32_Code_ClassTypeTestTarget* __stack0_0 = NULL;
    int32_t __stack0_1;
    int32_t __stack1_0;
    int32_t __stack2_0;

    //-------------------
    // Setup stack frame:

    struct /* __EXECUTION_FRAME__ */
    {
        __EXECUTION_FRAME__* pNext;
        uint8_t targetCount;
        Win32_Code_ClassTypeTestTarget** plocal0;
        Win32_Code_ClassTypeTestTarget** p__stack0_0;
    } __executionFrame__;

    __executionFrame__.targetCount = 2;
    __executionFrame__.plocal0 = &local0;
    __executionFrame__.p__stack0_0 = &__stack0_0;
    __gc_link_execution_frame__(&__executionFrame__);

    //-------------------
    // IL body:

#line 47 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\ClassTypeTest.cs"
#line 48 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\ClassTypeTest.cs"
    __new__(&__stack0_0, Win32_Code_ClassTypeTestTarget)(__stack0_0);
    local0 = __stack0_0;
#line 49 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\ClassTypeTest.cs"
    __stack0_0 = local0;
    __stack1_0 = 789;
    __stack0_0->Value2 = __stack1_0;
#line 51 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\ClassTypeTest.cs"
    __stack0_0 = local0;
    __stack1_0 = 123;
    __stack2_0 = 456;
    __stack0_1 = Win32_Code_ClassTypeTestTarget_GetValue2(__stack0_0, __stack1_0, __stack2_0);
    local1 = __stack0_1;
#line 52 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\ClassTypeTest.cs"
    __stack0_1 = local1;
    local2 = __stack0_1;
    goto L_0000;
#line 53 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\ClassTypeTest.cs"
L_0000:
    __stack0_1 = local2;
    __gc_unlink_execution_frame__(&__executionFrame__);
    return __stack0_1;
}

///////////////////////////////////////
// Test6

int32_t Win32_Code_ClassTypeTest_Test6(void)
{
    //-------------------
    // Local variables:

    Win32_Code_ClassTypeTestTarget* local0 = NULL;
    int32_t local1;
    int32_t local2;

    //-------------------
    // Evaluation stacks:

    Win32_Code_ClassTypeTestTarget* __stack0_0 = NULL;
    int32_t __stack0_1;
    int32_t __stack1_0;
    int32_t __stack2_0;
    int32_t __stack3_0;

    //-------------------
    // Setup stack frame:

    struct /* __EXECUTION_FRAME__ */
    {
        __EXECUTION_FRAME__* pNext;
        uint8_t targetCount;
        Win32_Code_ClassTypeTestTarget** plocal0;
        Win32_Code_ClassTypeTestTarget** p__stack0_0;
    } __executionFrame__;

    __executionFrame__.targetCount = 2;
    __executionFrame__.plocal0 = &local0;
    __executionFrame__.p__stack0_0 = &__stack0_0;
    __gc_link_execution_frame__(&__executionFrame__);

    //-------------------
    // IL body:

#line 56 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\ClassTypeTest.cs"
#line 57 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\ClassTypeTest.cs"
    __new__(&__stack0_0, Win32_Code_ClassTypeTestTarget)(__stack0_0);
    local0 = __stack0_0;
#line 58 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\ClassTypeTest.cs"
    __stack0_0 = local0;
    __stack1_0 = 789;
    __stack0_0->Value2 = __stack1_0;
#line 60 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\ClassTypeTest.cs"
    __stack0_0 = local0;
    __stack1_0 = 123;
    __stack2_0 = 456;
    __stack3_0 = 789;
    __stack0_1 = Win32_Code_ClassTypeTestTarget_GetValue2_1(__stack0_0, __stack1_0, __stack2_0, __stack3_0);
    local1 = __stack0_1;
#line 61 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\ClassTypeTest.cs"
    __stack0_1 = local1;
    local2 = __stack0_1;
    goto L_0000;
#line 62 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\ClassTypeTest.cs"
L_0000:
    __stack0_1 = local2;
    __gc_unlink_execution_frame__(&__executionFrame__);
    return __stack0_1;
}

///////////////////////////////////////
// Test7

int32_t Win32_Code_ClassTypeTest_Test7(void)
{
    //-------------------
    // Local variables:

    Win32_Code_ClassTypeTestTarget* local0 = NULL;
    int32_t local1;

    //-------------------
    // Evaluation stacks:

    int32_t __stack0_0;
    Win32_Code_ClassTypeTestTarget* __stack0_1 = NULL;

    //-------------------
    // Setup stack frame:

    struct /* __EXECUTION_FRAME__ */
    {
        __EXECUTION_FRAME__* pNext;
        uint8_t targetCount;
        Win32_Code_ClassTypeTestTarget** plocal0;
        Win32_Code_ClassTypeTestTarget** p__stack0_1;
    } __executionFrame__;

    __executionFrame__.targetCount = 2;
    __executionFrame__.plocal0 = &local0;
    __executionFrame__.p__stack0_1 = &__stack0_1;
    __gc_link_execution_frame__(&__executionFrame__);

    //-------------------
    // IL body:

#line 65 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\ClassTypeTest.cs"
#line 66 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\ClassTypeTest.cs"
    __stack0_0 = 123;
    __new_ovl__(&__stack0_1, Win32_Code_ClassTypeTestTarget, 1)(__stack0_1, __stack0_0);
    local0 = __stack0_1;
#line 68 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\ClassTypeTest.cs"
    __stack0_1 = local0;
    __stack0_0 = __stack0_1->Value2;
    local1 = __stack0_0;
    goto L_0000;
#line 69 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\ClassTypeTest.cs"
L_0000:
    __stack0_0 = local1;
    __gc_unlink_execution_frame__(&__executionFrame__);
    return __stack0_0;
}

///////////////////////////////////////
// .ctor

void Win32_Code_ClassTypeTest__ctor(Win32_Code_ClassTypeTest* __this)
{
    //-------------------
    // Local variables:


    //-------------------
    // Evaluation stacks:

    Win32_Code_ClassTypeTest* __stack0_0 = NULL;

    //-------------------
    // Setup stack frame:

    struct /* __EXECUTION_FRAME__ */
    {
        __EXECUTION_FRAME__* pNext;
        uint8_t targetCount;
        Win32_Code_ClassTypeTest** p__stack0_0;
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
// Type: Win32.Code.Hoge1

//////////////////////
// Runtime helpers:

static void __Win32_Code_Hoge1_MARK_HANDLER__(void* pReference)
{
    __typeof__(System_Object)->pMarkHandler(pReference);
}

static __RUNTIME_TYPE_DEF__ __Win32_Code_Hoge1_RUNTIME_TYPE_DEF__ = {
    "Win32.Code.Hoge1",
    0,
    __Win32_Code_Hoge1_MARK_HANDLER__ };
const __RUNTIME_TYPE__ __Win32_Code_Hoge1_RUNTIME_TYPE__ = &__Win32_Code_Hoge1_RUNTIME_TYPE_DEF__;

///////////////////////////////////////
// Add1

int32_t Win32_Code_Hoge1_Add1(int32_t a, bool isTwo)
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

#line 11 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\Hoge1.cs"
#line 12 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\Hoge1.cs"
    __stack0_0 = a;
    __stack1_0 = (isTwo) ? 1 : 0;
    if (__stack1_0 != 0) goto L_0000;
    __stack1_0 = 1;
    goto L_0001;
L_0000:
    __stack1_0 = 2;
L_0001:
    __stack0_0 = __stack0_0 + __stack1_0;
    local0 = __stack0_0;
    goto L_0002;
#line 13 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\Hoge1.cs"
L_0002:
    __stack0_0 = local0;
    return __stack0_0;
}

///////////////////////////////////////
// Add2

int64_t Win32_Code_Hoge1_Add2(int64_t a, bool isTwo)
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

#line 16 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\Hoge1.cs"
#line 17 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\Hoge1.cs"
    __stack0_0 = a;
    __stack1_0 = (isTwo) ? 1 : 0;
    if (__stack1_0 != 0) goto L_0000;
    __stack1_0 = 1;
    goto L_0001;
L_0000:
    __stack1_0 = 2;
L_0001:
    __stack1_1 = (int64_t)__stack1_0;
    __stack0_0 = __stack0_0 + __stack1_1;
    local0 = __stack0_0;
    goto L_0002;
#line 18 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\Hoge1.cs"
L_0002:
    __stack0_0 = local0;
    return __stack0_0;
}

///////////////////////////////////////
// .ctor

void Win32_Code_Hoge1__ctor(Win32_Code_Hoge1* __this)
{
    //-------------------
    // Local variables:


    //-------------------
    // Evaluation stacks:

    Win32_Code_Hoge1* __stack0_0 = NULL;

    //-------------------
    // Setup stack frame:

    struct /* __EXECUTION_FRAME__ */
    {
        __EXECUTION_FRAME__* pNext;
        uint8_t targetCount;
        Win32_Code_Hoge1** p__stack0_0;
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
// Type: Win32.Code.Hoge2

//////////////////////
// Runtime helpers:

static void __Win32_Code_Hoge2_MARK_HANDLER__(void* pReference)
{
    __typeof__(System_Object)->pMarkHandler(pReference);
}

static __RUNTIME_TYPE_DEF__ __Win32_Code_Hoge2_RUNTIME_TYPE_DEF__ = {
    "Win32.Code.Hoge2",
    0,
    __Win32_Code_Hoge2_MARK_HANDLER__ };
const __RUNTIME_TYPE__ __Win32_Code_Hoge2_RUNTIME_TYPE__ = &__Win32_Code_Hoge2_RUNTIME_TYPE_DEF__;

///////////////////////////////////////
// Add3

uint8_t Win32_Code_Hoge2_Add3(uint8_t a, bool isTwo)
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

#line 11 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\Hoge2.cs"
#line 12 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\Hoge2.cs"
    __stack0_0 = (int32_t)(a);
    __stack1_0 = (isTwo) ? 1 : 0;
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
#line 13 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\Hoge2.cs"
L_0002:
    __stack0_0 = local0;
    return (uint8_t)__stack0_0;
}

///////////////////////////////////////
// Add4

uint16_t Win32_Code_Hoge2_Add4(uint16_t a, bool isTwo)
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

#line 16 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\Hoge2.cs"
#line 17 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\Hoge2.cs"
    __stack0_0 = (int32_t)(a);
    __stack1_0 = (isTwo) ? 1 : 0;
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
#line 18 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\Hoge2.cs"
L_0002:
    __stack0_0 = local0;
    return (uint16_t)__stack0_0;
}

///////////////////////////////////////
// .ctor

void Win32_Code_Hoge2__ctor(Win32_Code_Hoge2* __this)
{
    //-------------------
    // Local variables:


    //-------------------
    // Evaluation stacks:

    Win32_Code_Hoge2* __stack0_0 = NULL;

    //-------------------
    // Setup stack frame:

    struct /* __EXECUTION_FRAME__ */
    {
        __EXECUTION_FRAME__* pNext;
        uint8_t targetCount;
        Win32_Code_Hoge2** p__stack0_0;
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
// Type: Win32.Code.Win32

//////////////////////
// Runtime helpers:

static void __Win32_Code_Win32_MARK_HANDLER__(void* pReference)
{
    __typeof__(System_Object)->pMarkHandler(pReference);
}

static __RUNTIME_TYPE_DEF__ __Win32_Code_Win32_RUNTIME_TYPE_DEF__ = {
    "Win32.Code.Win32",
    0,
    __Win32_Code_Win32_MARK_HANDLER__ };
const __RUNTIME_TYPE__ __Win32_Code_Win32_RUNTIME_TYPE__ = &__Win32_Code_Win32_RUNTIME_TYPE_DEF__;

///////////////////////////////////////
// P/Invoke: GetCurrentProcessId

int32_t Win32_Code_Win32_GetCurrentProcessId(void)
{
    return GetCurrentProcessId();
}

///////////////////////////////////////
// P/Invoke: GetCurrentThreadId

int32_t Win32_Code_Win32_GetCurrentThreadId(void)
{
    return GetCurrentThreadId();
}

///////////////////////////////////////
// P/Invoke: OutputDebugString

void Win32_Code_Win32_OutputDebugString(System_String* message)
{
    OutputDebugStringA(message->pString);
}

///////////////////////////////////////
// .ctor

void Win32_Code_Win32__ctor(Win32_Code_Win32* __this)
{
    //-------------------
    // Local variables:


    //-------------------
    // Evaluation stacks:

    Win32_Code_Win32* __stack0_0 = NULL;

    //-------------------
    // Setup stack frame:

    struct /* __EXECUTION_FRAME__ */
    {
        __EXECUTION_FRAME__* pNext;
        uint8_t targetCount;
        Win32_Code_Win32** p__stack0_0;
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
// Type: Win32.Code.StringTest

//////////////////////
// Runtime helpers:

static void __Win32_Code_StringTest_MARK_HANDLER__(void* pReference)
{
    __typeof__(System_Object)->pMarkHandler(pReference);
}

static __RUNTIME_TYPE_DEF__ __Win32_Code_StringTest_RUNTIME_TYPE_DEF__ = {
    "Win32.Code.StringTest",
    0,
    __Win32_Code_StringTest_MARK_HANDLER__ };
const __RUNTIME_TYPE__ __Win32_Code_StringTest_RUNTIME_TYPE__ = &__Win32_Code_StringTest_RUNTIME_TYPE_DEF__;

///////////////////////////////////////
// LiteralString

void Win32_Code_StringTest_LiteralString(void)
{
    //-------------------
    // Local variables:

    System_String* local0 = NULL;

    //-------------------
    // Evaluation stacks:

    System_String* __stack0_0 = NULL;

    //-------------------
    // Setup stack frame:

    struct /* __EXECUTION_FRAME__ */
    {
        __EXECUTION_FRAME__* pNext;
        uint8_t targetCount;
        System_String** plocal0;
        System_String** p__stack0_0;
    } __executionFrame__;

    __executionFrame__.targetCount = 2;
    __executionFrame__.plocal0 = &local0;
    __executionFrame__.p__stack0_0 = &__stack0_0;
    __gc_link_execution_frame__(&__executionFrame__);

    //-------------------
    // IL body:

#line 12 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\StringTest.cs"
#line 13 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\StringTest.cs"
    __stack0_0 = __string0 /* "ABC" */;
    local0 = __stack0_0;
#line 14 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\StringTest.cs"
    __gc_unlink_execution_frame__(&__executionFrame__);
    return;
}

///////////////////////////////////////
// InOutString

System_String* Win32_Code_StringTest_InOutString(System_String* a)
{
    //-------------------
    // Local variables:

    System_String* local0 = NULL;

    //-------------------
    // Evaluation stacks:

    System_String* __stack0_0 = NULL;

    //-------------------
    // Setup stack frame:

    struct /* __EXECUTION_FRAME__ */
    {
        __EXECUTION_FRAME__* pNext;
        uint8_t targetCount;
        System_String** plocal0;
        System_String** p__stack0_0;
    } __executionFrame__;

    __executionFrame__.targetCount = 2;
    __executionFrame__.plocal0 = &local0;
    __executionFrame__.p__stack0_0 = &__stack0_0;
    __gc_link_execution_frame__(&__executionFrame__);

    //-------------------
    // IL body:

#line 17 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\StringTest.cs"
#line 18 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\StringTest.cs"
    __stack0_0 = a;
    local0 = __stack0_0;
    goto L_0000;
#line 19 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\StringTest.cs"
L_0000:
    __stack0_0 = local0;
    __gc_unlink_execution_frame__(&__executionFrame__);
    return __stack0_0;
}

///////////////////////////////////////
// LiteralCombinedString

System_String* Win32_Code_StringTest_LiteralCombinedString(void)
{
    //-------------------
    // Local variables:

    System_String* local0 = NULL;
    System_String* local1 = NULL;
    System_String* local2 = NULL;

    //-------------------
    // Evaluation stacks:

    System_String* __stack0_0 = NULL;
    System_String* __stack1_0 = NULL;

    //-------------------
    // Setup stack frame:

    struct /* __EXECUTION_FRAME__ */
    {
        __EXECUTION_FRAME__* pNext;
        uint8_t targetCount;
        System_String** plocal0;
        System_String** plocal1;
        System_String** plocal2;
        System_String** p__stack0_0;
        System_String** p__stack1_0;
    } __executionFrame__;

    __executionFrame__.targetCount = 5;
    __executionFrame__.plocal0 = &local0;
    __executionFrame__.plocal1 = &local1;
    __executionFrame__.plocal2 = &local2;
    __executionFrame__.p__stack0_0 = &__stack0_0;
    __executionFrame__.p__stack1_0 = &__stack1_0;
    __gc_link_execution_frame__(&__executionFrame__);

    //-------------------
    // IL body:

#line 22 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\StringTest.cs"
#line 23 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\StringTest.cs"
    __stack0_0 = __string0 /* "ABC" */;
    local0 = __stack0_0;
#line 24 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\StringTest.cs"
    __stack0_0 = __string1 /* "DEF" */;
    local1 = __stack0_0;
#line 25 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\StringTest.cs"
    __stack0_0 = local0;
    __stack1_0 = local1;
    __stack0_0 = System_String_Concat_6(__stack0_0, __stack1_0);
    local2 = __stack0_0;
    goto L_0000;
#line 26 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\StringTest.cs"
L_0000:
    __stack0_0 = local2;
    __gc_unlink_execution_frame__(&__executionFrame__);
    return __stack0_0;
}

///////////////////////////////////////
// .ctor

void Win32_Code_StringTest__ctor(Win32_Code_StringTest* __this)
{
    //-------------------
    // Local variables:


    //-------------------
    // Evaluation stacks:

    Win32_Code_StringTest* __stack0_0 = NULL;

    //-------------------
    // Setup stack frame:

    struct /* __EXECUTION_FRAME__ */
    {
        __EXECUTION_FRAME__* pNext;
        uint8_t targetCount;
        Win32_Code_StringTest** p__stack0_0;
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
// Type: Win32.Code.ValueTypeTestTarget

//////////////////////
// Runtime helpers:

static void __Win32_Code_ValueTypeTestTarget_MARK_HANDLER__(void* pReference)
{
    __TRY_MARK_FROM_HANDLER__(((Win32_Code_ValueTypeTestTarget*)pReference)->OR2);
    __typeof__(System_ValueType)->pMarkHandler(pReference);
}

static __RUNTIME_TYPE_DEF__ __Win32_Code_ValueTypeTestTarget_RUNTIME_TYPE_DEF__ = {
    "Win32.Code.ValueTypeTestTarget",
    sizeof(Win32_Code_ValueTypeTestTarget),
    __Win32_Code_ValueTypeTestTarget_MARK_HANDLER__ };
const __RUNTIME_TYPE__ __Win32_Code_ValueTypeTestTarget_RUNTIME_TYPE__ = &__Win32_Code_ValueTypeTestTarget_RUNTIME_TYPE_DEF__;

///////////////////////////////////////
// GetValue2

int32_t Win32_Code_ValueTypeTestTarget_GetValue2(Win32_Code_ValueTypeTestTarget* __this, int32_t a, int32_t b)
{
    //-------------------
    // Local variables:

    int32_t local0;

    //-------------------
    // Evaluation stacks:

    Win32_Code_ValueTypeTestTarget* __stack0_0 = NULL;
    int32_t __stack0_1;
    int32_t __stack1_0;

    //-------------------
    // Setup stack frame:

    struct /* __EXECUTION_FRAME__ */
    {
        __EXECUTION_FRAME__* pNext;
        uint8_t targetCount;
        Win32_Code_ValueTypeTestTarget** p__stack0_0;
    } __executionFrame__;

    __executionFrame__.targetCount = 1;
    __executionFrame__.p__stack0_0 = &__stack0_0;
    __gc_link_execution_frame__(&__executionFrame__);

    //-------------------
    // IL body:

#line 15 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\ValueTypeTest.cs"
#line 16 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\ValueTypeTest.cs"
    __stack0_0 = __this;
    __stack0_1 = __stack0_0->Value2;
    __stack1_0 = a;
    __stack0_1 = __stack0_1 + __stack1_0;
    __stack1_0 = b;
    __stack0_1 = __stack0_1 + __stack1_0;
    local0 = __stack0_1;
    goto L_0000;
#line 17 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\ValueTypeTest.cs"
L_0000:
    __stack0_1 = local0;
    __gc_unlink_execution_frame__(&__executionFrame__);
    return __stack0_1;
}

////////////////////////////////////////////////////////////
// Type: Win32.Code.ValueTypeTest

//////////////////////
// Runtime helpers:

static void __Win32_Code_ValueTypeTest_MARK_HANDLER__(void* pReference)
{
    __typeof__(System_Object)->pMarkHandler(pReference);
}

static __RUNTIME_TYPE_DEF__ __Win32_Code_ValueTypeTest_RUNTIME_TYPE_DEF__ = {
    "Win32.Code.ValueTypeTest",
    0,
    __Win32_Code_ValueTypeTest_MARK_HANDLER__ };
const __RUNTIME_TYPE__ __Win32_Code_ValueTypeTest_RUNTIME_TYPE__ = &__Win32_Code_ValueTypeTest_RUNTIME_TYPE_DEF__;

///////////////////////////////////////
// Test4

int32_t Win32_Code_ValueTypeTest_Test4(void)
{
    //-------------------
    // Local variables:

    Win32_Code_ValueTypeTestTarget local0;
    int32_t local1;

    //-------------------
    // Evaluation stacks:

    Win32_Code_ValueTypeTestTarget* __stack0_0 = NULL;
    Win32_Code_ValueTypeTestTarget* __stack0_1 = NULL;
    Win32_Code_ValueTypeTestTarget __stack0_2;
    int32_t __stack0_3;
    int32_t __stack1_0;

    //-------------------
    // Setup stack frame:

    struct /* __EXECUTION_FRAME__ */
    {
        __EXECUTION_FRAME__* pNext;
        uint8_t targetCount;
        Win32_Code_ValueTypeTestTarget** p__stack0_0;
        Win32_Code_ValueTypeTestTarget** p__stack0_1;
    } __executionFrame__;

    __executionFrame__.targetCount = 2;
    __executionFrame__.p__stack0_0 = &__stack0_0;
    __executionFrame__.p__stack0_1 = &__stack0_1;
    __gc_link_execution_frame__(&__executionFrame__);

    //-------------------
    // IL body:

#line 23 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\ValueTypeTest.cs"
#line 24 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\ValueTypeTest.cs"
    __stack0_0 = &local0;
    memset(__stack0_0, 0x00, sizeof(Win32_Code_ValueTypeTestTarget));
#line 25 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\ValueTypeTest.cs"
    __stack0_1 = &local0;
    __stack1_0 = 456;
    __stack0_1->Value2 = __stack1_0;
#line 27 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\ValueTypeTest.cs"
    __stack0_2 = local0;
    __stack0_3 = __stack0_2.Value2;
    local1 = __stack0_3;
    goto L_0000;
#line 28 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\ValueTypeTest.cs"
L_0000:
    __stack0_3 = local1;
    __gc_unlink_execution_frame__(&__executionFrame__);
    return __stack0_3;
}

///////////////////////////////////////
// Test5

int32_t Win32_Code_ValueTypeTest_Test5(void)
{
    //-------------------
    // Local variables:

    Win32_Code_ValueTypeTestTarget local0;
    int32_t local1;
    int32_t local2;

    //-------------------
    // Evaluation stacks:

    Win32_Code_ValueTypeTestTarget* __stack0_0 = NULL;
    Win32_Code_ValueTypeTestTarget* __stack0_1 = NULL;
    Win32_Code_ValueTypeTestTarget* __stack0_2 = NULL;
    int32_t __stack0_3;
    int32_t __stack1_0;
    int32_t __stack2_0;

    //-------------------
    // Setup stack frame:

    struct /* __EXECUTION_FRAME__ */
    {
        __EXECUTION_FRAME__* pNext;
        uint8_t targetCount;
        Win32_Code_ValueTypeTestTarget** p__stack0_0;
        Win32_Code_ValueTypeTestTarget** p__stack0_1;
        Win32_Code_ValueTypeTestTarget** p__stack0_2;
    } __executionFrame__;

    __executionFrame__.targetCount = 3;
    __executionFrame__.p__stack0_0 = &__stack0_0;
    __executionFrame__.p__stack0_1 = &__stack0_1;
    __executionFrame__.p__stack0_2 = &__stack0_2;
    __gc_link_execution_frame__(&__executionFrame__);

    //-------------------
    // IL body:

#line 31 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\ValueTypeTest.cs"
#line 32 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\ValueTypeTest.cs"
    __stack0_0 = &local0;
    memset(__stack0_0, 0x00, sizeof(Win32_Code_ValueTypeTestTarget));
#line 33 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\ValueTypeTest.cs"
    __stack0_1 = &local0;
    __stack1_0 = 789;
    __stack0_1->Value2 = __stack1_0;
#line 35 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\ValueTypeTest.cs"
    __stack0_2 = &local0;
    __stack1_0 = 123;
    __stack2_0 = 456;
    __stack0_3 = Win32_Code_ValueTypeTestTarget_GetValue2(__stack0_2, __stack1_0, __stack2_0);
    local1 = __stack0_3;
#line 36 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\ValueTypeTest.cs"
    __stack0_3 = local1;
    local2 = __stack0_3;
    goto L_0000;
#line 37 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\ValueTypeTest.cs"
L_0000:
    __stack0_3 = local2;
    __gc_unlink_execution_frame__(&__executionFrame__);
    return __stack0_3;
}

///////////////////////////////////////
// .ctor

void Win32_Code_ValueTypeTest__ctor(Win32_Code_ValueTypeTest* __this)
{
    //-------------------
    // Local variables:


    //-------------------
    // Evaluation stacks:

    Win32_Code_ValueTypeTest* __stack0_0 = NULL;

    //-------------------
    // Setup stack frame:

    struct /* __EXECUTION_FRAME__ */
    {
        __EXECUTION_FRAME__* pNext;
        uint8_t targetCount;
        Win32_Code_ValueTypeTest** p__stack0_0;
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
