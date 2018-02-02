#include <windows.h>
#include "Win32.Code.h"

//////////////////////////////////////////////////////////////////////////////////
// Const strings:

IL2C_CONST_STRING(__string0, L"PN> ");
IL2C_CONST_STRING(__string1, L"Syntax error.");
IL2C_CONST_STRING(__string2, L"Reuslt=");
IL2C_CONST_STRING(__string3, L"ABC");
IL2C_CONST_STRING(__string4, L"DEF");
IL2C_CONST_STRING(__string5, L"ABCDEFGHIJKLMN");

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

///////////////////////////////////////
// BoxingInt32

void Win32_Code_BoxingTest_BoxingInt32(int32_t a)
{
    //-------------------
    // Local variables:


    //-------------------
    // Evaluation stacks:

    int32_t __stack0_0;
    System_Object* __stack0_1 = NULL;
    int32_t __stack0_2;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        System_Object** p__stack0_1;
    } __executionFrame__;

    __executionFrame__.targetCount = 1;
    __executionFrame__.p__stack0_1 = &__stack0_1;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

#line 14 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\BoxingTest.cs"
    /* Path=1, Unique=0: IL_0000: ldarg.0 */
    __stack0_0 = a;
    /* Path=1, Unique=0: IL_0001: box System.Int32 */
    __stack0_1 = il2c_box(&__stack0_0, il2c_typeof(System_Int32));
#line 16 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\BoxingTest.cs"
    /* Path=1, Unique=0: IL_0006: unbox.any System.Int32 */
    __stack0_2 = *((int32_t*)il2c_unbox(__stack0_1, il2c_typeof(System_Int32)));
    /* Path=1, Unique=0: IL_000b: pop */
#line 17 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\BoxingTest.cs"
    /* Path=1, Unique=0: IL_000c: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return;
}

///////////////////////////////////////
// .ctor

void Win32_Code_BoxingTest__ctor(Win32_Code_BoxingTest* this__)
{
    //-------------------
    // Local variables:


    //-------------------
    // Evaluation stacks:

    Win32_Code_BoxingTest* __stack0_0 = NULL;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        Win32_Code_BoxingTest** p__stack0_0;
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

static void __Win32_Code_BoxingTest_MARK_HANDLER__(void* pReference)
{
    il2c_typeof(System_Object)->pMarkHandler(pReference);
}

static __Win32_Code_BoxingTest_TYPE_DEF_TYPE__ __Win32_Code_BoxingTest_RUNTIME_TYPE_DEF__ = {
    (intptr_t)"Win32.Code.BoxingTest",
    (intptr_t)0,
    (intptr_t)__Win32_Code_BoxingTest_MARK_HANDLER__,
    __System_Object_ToString__,
    __System_Object_GetHashCode__,
    __System_Object_Finalize__,
    __System_Object_Equals__,
};
const IL2C_RUNTIME_TYPE __Win32_Code_BoxingTest_RUNTIME_TYPE__ =
   (const IL2C_RUNTIME_TYPE)(&__Win32_Code_BoxingTest_RUNTIME_TYPE_DEF__);

////////////////////////////////////////////////////////////
// Type: Win32.Code.ClassTypeTestTarget

///////////////////////////////////////
// .ctor

void Win32_Code_ClassTypeTestTarget__ctor(Win32_Code_ClassTypeTestTarget* this__)
{
    //-------------------
    // Local variables:


    //-------------------
    // Evaluation stacks:

    Win32_Code_ClassTypeTestTarget* __stack0_0 = NULL;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        Win32_Code_ClassTypeTestTarget** p__stack0_0;
    } __executionFrame__;

    __executionFrame__.targetCount = 1;
    __executionFrame__.p__stack0_0 = &__stack0_0;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

#line 16 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\ClassTypeTest.cs"
    /* Path=1, Unique=0: IL_0000: ldarg.0 */
    __stack0_0 = this__;
    /* Path=1, Unique=0: IL_0001: call System.Void System.Object::.ctor() */
    System_Object__ctor((System_Object*)__stack0_0);
#line 18 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\ClassTypeTest.cs"
    /* Path=1, Unique=0: IL_0006: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return;
}

///////////////////////////////////////
// .ctor

void Win32_Code_ClassTypeTestTarget__ctor_1(Win32_Code_ClassTypeTestTarget* this__, int32_t value)
{
    //-------------------
    // Local variables:


    //-------------------
    // Evaluation stacks:

    Win32_Code_ClassTypeTestTarget* __stack0_0 = NULL;
    int32_t __stack1_0;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        Win32_Code_ClassTypeTestTarget** p__stack0_0;
    } __executionFrame__;

    __executionFrame__.targetCount = 1;
    __executionFrame__.p__stack0_0 = &__stack0_0;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

#line 20 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\ClassTypeTest.cs"
    /* Path=1, Unique=0: IL_0000: ldarg.0 */
    __stack0_0 = this__;
    /* Path=1, Unique=0: IL_0001: call System.Void System.Object::.ctor() */
    System_Object__ctor((System_Object*)__stack0_0);
#line 22 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\ClassTypeTest.cs"
    /* Path=1, Unique=0: IL_0006: ldarg.0 */
    __stack0_0 = this__;
    /* Path=1, Unique=0: IL_0007: ldarg.1 */
    __stack1_0 = value;
    /* Path=1, Unique=0: IL_0008: stfld System.Int32 Win32.Code.ClassTypeTestTarget::Value2 */
    __stack0_0->Value2 = __stack1_0;
#line 23 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\ClassTypeTest.cs"
    /* Path=1, Unique=0: IL_000d: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return;
}

///////////////////////////////////////
// GetValue2

int32_t Win32_Code_ClassTypeTestTarget_GetValue2(Win32_Code_ClassTypeTestTarget* this__, int32_t a, int32_t b)
{
    //-------------------
    // Local variables:


    //-------------------
    // Evaluation stacks:

    Win32_Code_ClassTypeTestTarget* __stack0_0 = NULL;
    int32_t __stack0_1;
    int32_t __stack1_0;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        Win32_Code_ClassTypeTestTarget** p__stack0_0;
    } __executionFrame__;

    __executionFrame__.targetCount = 1;
    __executionFrame__.p__stack0_0 = &__stack0_0;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

#line 27 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\ClassTypeTest.cs"
    /* Path=1, Unique=0: IL_0000: ldarg.0 */
    __stack0_0 = this__;
    /* Path=1, Unique=0: IL_0001: ldfld System.Int32 Win32.Code.ClassTypeTestTarget::Value2 */
    __stack0_1 = __stack0_0->Value2;
    /* Path=1, Unique=0: IL_0006: ldarg.1 */
    __stack1_0 = a;
    /* Path=1, Unique=0: IL_0007: add */
    __stack0_1 = __stack0_1 + __stack1_0;
    /* Path=1, Unique=0: IL_0008: ldarg.2 */
    __stack1_0 = b;
    /* Path=1, Unique=0: IL_0009: add */
    __stack0_1 = __stack0_1 + __stack1_0;
    /* Path=1, Unique=0: IL_000a: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return __stack0_1;
}

///////////////////////////////////////
// GetValue2

int32_t Win32_Code_ClassTypeTestTarget_GetValue2_1(Win32_Code_ClassTypeTestTarget* this__, int32_t a, int32_t b, int32_t c)
{
    //-------------------
    // Local variables:


    //-------------------
    // Evaluation stacks:

    Win32_Code_ClassTypeTestTarget* __stack0_0 = NULL;
    int32_t __stack0_1;
    int32_t __stack1_0;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        Win32_Code_ClassTypeTestTarget** p__stack0_0;
    } __executionFrame__;

    __executionFrame__.targetCount = 1;
    __executionFrame__.p__stack0_0 = &__stack0_0;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

#line 32 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\ClassTypeTest.cs"
    /* Path=1, Unique=0: IL_0000: ldarg.0 */
    __stack0_0 = this__;
    /* Path=1, Unique=0: IL_0001: ldfld System.Int32 Win32.Code.ClassTypeTestTarget::Value2 */
    __stack0_1 = __stack0_0->Value2;
    /* Path=1, Unique=0: IL_0006: ldarg.1 */
    __stack1_0 = a;
    /* Path=1, Unique=0: IL_0007: add */
    __stack0_1 = __stack0_1 + __stack1_0;
    /* Path=1, Unique=0: IL_0008: ldarg.2 */
    __stack1_0 = b;
    /* Path=1, Unique=0: IL_0009: add */
    __stack0_1 = __stack0_1 + __stack1_0;
    /* Path=1, Unique=0: IL_000a: ldarg.3 */
    __stack1_0 = c;
    /* Path=1, Unique=0: IL_000b: add */
    __stack0_1 = __stack0_1 + __stack1_0;
    /* Path=1, Unique=0: IL_000c: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return __stack0_1;
}

//////////////////////
// Runtime helpers:

static void __Win32_Code_ClassTypeTestTarget_MARK_HANDLER__(void* pReference)
{
    il2c_try_mark_from_handler(((Win32_Code_ClassTypeTestTarget*)pReference)->OR2);
    il2c_typeof(System_Object)->pMarkHandler(pReference);
}

static __Win32_Code_ClassTypeTestTarget_TYPE_DEF_TYPE__ __Win32_Code_ClassTypeTestTarget_RUNTIME_TYPE_DEF__ = {
    (intptr_t)"Win32.Code.ClassTypeTestTarget",
    (intptr_t)sizeof(Win32_Code_ClassTypeTestTarget),
    (intptr_t)__Win32_Code_ClassTypeTestTarget_MARK_HANDLER__,
    __System_Object_ToString__,
    __System_Object_GetHashCode__,
    __System_Object_Finalize__,
    __System_Object_Equals__,
};
const IL2C_RUNTIME_TYPE __Win32_Code_ClassTypeTestTarget_RUNTIME_TYPE__ =
   (const IL2C_RUNTIME_TYPE)(&__Win32_Code_ClassTypeTestTarget_RUNTIME_TYPE_DEF__);

////////////////////////////////////////////////////////////
// Type: Win32.Code.ClassTypeTest

///////////////////////////////////////
// Test4

int32_t Win32_Code_ClassTypeTest_Test4(void)
{
    //-------------------
    // Local variables:


    //-------------------
    // Evaluation stacks:

    Win32_Code_ClassTypeTestTarget* __stack0_0 = NULL;
    int32_t __stack0_1;
    Win32_Code_ClassTypeTestTarget* __stack1_0 = NULL;
    int32_t __stack2_0;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        Win32_Code_ClassTypeTestTarget** p__stack0_0;
        Win32_Code_ClassTypeTestTarget** p__stack1_0;
    } __executionFrame__;

    __executionFrame__.targetCount = 2;
    __executionFrame__.p__stack0_0 = &__stack0_0;
    __executionFrame__.p__stack1_0 = &__stack1_0;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

#line 40 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\ClassTypeTest.cs"
    /* Path=1, Unique=0: IL_0000: newobj System.Void Win32.Code.ClassTypeTestTarget::.ctor() */
    __stack0_0 = il2c_get_uninitialized_object(il2c_typeof(Win32_Code_ClassTypeTestTarget));
    Win32_Code_ClassTypeTestTarget__ctor(__stack0_0);
#line 41 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\ClassTypeTest.cs"
    /* Path=1, Unique=0: IL_0005: dup */
    __stack1_0 = __stack0_0;
    /* Path=1, Unique=0: IL_0006: ldc.i4 456 */
    __stack2_0 = 456;
    /* Path=1, Unique=0: IL_000b: stfld System.Int32 Win32.Code.ClassTypeTestTarget::Value2 */
    __stack1_0->Value2 = __stack2_0;
#line 43 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\ClassTypeTest.cs"
    /* Path=1, Unique=0: IL_0010: ldfld System.Int32 Win32.Code.ClassTypeTestTarget::Value2 */
    __stack0_1 = __stack0_0->Value2;
    /* Path=1, Unique=0: IL_0015: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return __stack0_1;
}

///////////////////////////////////////
// Test5

int32_t Win32_Code_ClassTypeTest_Test5(void)
{
    //-------------------
    // Local variables:


    //-------------------
    // Evaluation stacks:

    Win32_Code_ClassTypeTestTarget* __stack0_0 = NULL;
    int32_t __stack0_1;
    Win32_Code_ClassTypeTestTarget* __stack1_0 = NULL;
    int32_t __stack1_1;
    int32_t __stack2_0;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        Win32_Code_ClassTypeTestTarget** p__stack0_0;
        Win32_Code_ClassTypeTestTarget** p__stack1_0;
    } __executionFrame__;

    __executionFrame__.targetCount = 2;
    __executionFrame__.p__stack0_0 = &__stack0_0;
    __executionFrame__.p__stack1_0 = &__stack1_0;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

#line 48 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\ClassTypeTest.cs"
    /* Path=1, Unique=0: IL_0000: newobj System.Void Win32.Code.ClassTypeTestTarget::.ctor() */
    __stack0_0 = il2c_get_uninitialized_object(il2c_typeof(Win32_Code_ClassTypeTestTarget));
    Win32_Code_ClassTypeTestTarget__ctor(__stack0_0);
#line 49 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\ClassTypeTest.cs"
    /* Path=1, Unique=0: IL_0005: dup */
    __stack1_0 = __stack0_0;
    /* Path=1, Unique=0: IL_0006: ldc.i4 789 */
    __stack2_0 = 789;
    /* Path=1, Unique=0: IL_000b: stfld System.Int32 Win32.Code.ClassTypeTestTarget::Value2 */
    __stack1_0->Value2 = __stack2_0;
#line 51 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\ClassTypeTest.cs"
    /* Path=1, Unique=0: IL_0010: ldc.i4.s 123 */
    __stack1_1 = 123;
    /* Path=1, Unique=0: IL_0012: ldc.i4 456 */
    __stack2_0 = 456;
    /* Path=1, Unique=0: IL_0017: callvirt System.Int32 Win32.Code.ClassTypeTestTarget::GetValue2(System.Int32,System.Int32) */
    __stack0_1 = Win32_Code_ClassTypeTestTarget_GetValue2(__stack0_0, __stack1_1, __stack2_0);
#line 52 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\ClassTypeTest.cs"
    /* Path=1, Unique=0: IL_001c: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return __stack0_1;
}

///////////////////////////////////////
// Test6

int32_t Win32_Code_ClassTypeTest_Test6(void)
{
    //-------------------
    // Local variables:


    //-------------------
    // Evaluation stacks:

    Win32_Code_ClassTypeTestTarget* __stack0_0 = NULL;
    int32_t __stack0_1;
    Win32_Code_ClassTypeTestTarget* __stack1_0 = NULL;
    int32_t __stack1_1;
    int32_t __stack2_0;
    int32_t __stack3_0;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        Win32_Code_ClassTypeTestTarget** p__stack0_0;
        Win32_Code_ClassTypeTestTarget** p__stack1_0;
    } __executionFrame__;

    __executionFrame__.targetCount = 2;
    __executionFrame__.p__stack0_0 = &__stack0_0;
    __executionFrame__.p__stack1_0 = &__stack1_0;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

#line 57 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\ClassTypeTest.cs"
    /* Path=1, Unique=0: IL_0000: newobj System.Void Win32.Code.ClassTypeTestTarget::.ctor() */
    __stack0_0 = il2c_get_uninitialized_object(il2c_typeof(Win32_Code_ClassTypeTestTarget));
    Win32_Code_ClassTypeTestTarget__ctor(__stack0_0);
#line 58 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\ClassTypeTest.cs"
    /* Path=1, Unique=0: IL_0005: dup */
    __stack1_0 = __stack0_0;
    /* Path=1, Unique=0: IL_0006: ldc.i4 789 */
    __stack2_0 = 789;
    /* Path=1, Unique=0: IL_000b: stfld System.Int32 Win32.Code.ClassTypeTestTarget::Value2 */
    __stack1_0->Value2 = __stack2_0;
#line 60 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\ClassTypeTest.cs"
    /* Path=1, Unique=0: IL_0010: ldc.i4.s 123 */
    __stack1_1 = 123;
    /* Path=1, Unique=0: IL_0012: ldc.i4 456 */
    __stack2_0 = 456;
    /* Path=1, Unique=0: IL_0017: ldc.i4 789 */
    __stack3_0 = 789;
    /* Path=1, Unique=0: IL_001c: callvirt System.Int32 Win32.Code.ClassTypeTestTarget::GetValue2(System.Int32,System.Int32,System.Int32) */
    __stack0_1 = Win32_Code_ClassTypeTestTarget_GetValue2_1(__stack0_0, __stack1_1, __stack2_0, __stack3_0);
#line 61 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\ClassTypeTest.cs"
    /* Path=1, Unique=0: IL_0021: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return __stack0_1;
}

///////////////////////////////////////
// Test7

int32_t Win32_Code_ClassTypeTest_Test7(void)
{
    //-------------------
    // Local variables:


    //-------------------
    // Evaluation stacks:

    int32_t __stack0_0;
    Win32_Code_ClassTypeTestTarget* __stack0_1 = NULL;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        Win32_Code_ClassTypeTestTarget** p__stack0_1;
    } __executionFrame__;

    __executionFrame__.targetCount = 1;
    __executionFrame__.p__stack0_1 = &__stack0_1;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

#line 66 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\ClassTypeTest.cs"
    /* Path=1, Unique=0: IL_0000: ldc.i4.s 123 */
    __stack0_0 = 123;
    /* Path=1, Unique=0: IL_0002: newobj System.Void Win32.Code.ClassTypeTestTarget::.ctor(System.Int32) */
    __stack0_1 = il2c_get_uninitialized_object(il2c_typeof(Win32_Code_ClassTypeTestTarget));
    Win32_Code_ClassTypeTestTarget__ctor_1(__stack0_1, __stack0_0);
#line 68 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\ClassTypeTest.cs"
    /* Path=1, Unique=0: IL_0007: ldfld System.Int32 Win32.Code.ClassTypeTestTarget::Value2 */
    __stack0_0 = __stack0_1->Value2;
    /* Path=1, Unique=0: IL_000c: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return __stack0_0;
}

///////////////////////////////////////
// .ctor

void Win32_Code_ClassTypeTest__ctor(Win32_Code_ClassTypeTest* this__)
{
    //-------------------
    // Local variables:


    //-------------------
    // Evaluation stacks:

    Win32_Code_ClassTypeTest* __stack0_0 = NULL;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        Win32_Code_ClassTypeTest** p__stack0_0;
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

static void __Win32_Code_ClassTypeTest_MARK_HANDLER__(void* pReference)
{
    il2c_typeof(System_Object)->pMarkHandler(pReference);
}

static __Win32_Code_ClassTypeTest_TYPE_DEF_TYPE__ __Win32_Code_ClassTypeTest_RUNTIME_TYPE_DEF__ = {
    (intptr_t)"Win32.Code.ClassTypeTest",
    (intptr_t)0,
    (intptr_t)__Win32_Code_ClassTypeTest_MARK_HANDLER__,
    __System_Object_ToString__,
    __System_Object_GetHashCode__,
    __System_Object_Finalize__,
    __System_Object_Equals__,
};
const IL2C_RUNTIME_TYPE __Win32_Code_ClassTypeTest_RUNTIME_TYPE__ =
   (const IL2C_RUNTIME_TYPE)(&__Win32_Code_ClassTypeTest_RUNTIME_TYPE_DEF__);

////////////////////////////////////////////////////////////
// Type: Win32.Code.Hoge1

///////////////////////////////////////
// Add1

int32_t Win32_Code_Hoge1_Add1(int32_t a, bool isTwo)
{
    //-------------------
    // Local variables:


    //-------------------
    // Evaluation stacks:

    int32_t __stack0_0;
    int32_t __stack1_0;

    //-------------------
    // IL body:

#line 12 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\Hoge1.cs"
    /* Path=1, Unique=0: IL_0000: ldarg.0 */
    __stack0_0 = a;
    /* Path=1, Unique=0: IL_0001: ldarg.1 */
    __stack1_0 = (isTwo) ? 1 : 0;
    /* Path=1, Unique=0: IL_0002: brtrue.s IL_0007 */
    if (__stack1_0 != 0) goto IL_0007;
    /* Path=1, Unique=0: IL_0004: ldc.i4.1 */
    __stack1_0 = 1;
    /* Path=1, Unique=0: IL_0005: br.s IL_0008 */
    goto IL_0008;
IL_0007:
    /* Path=2, Unique=0: IL_0007: ldc.i4.2 */
    __stack1_0 = 2;
IL_0008:
    /* Path=2, Unique=0: IL_0008: add */
    __stack0_0 = __stack0_0 + __stack1_0;
    /* Path=2, Unique=0: IL_0009: ret */
    return __stack0_0;
}

///////////////////////////////////////
// Add2

int64_t Win32_Code_Hoge1_Add2(int64_t a, bool isTwo)
{
    //-------------------
    // Local variables:


    //-------------------
    // Evaluation stacks:

    int64_t __stack0_0;
    int32_t __stack1_0;
    int64_t __stack1_1;

    //-------------------
    // IL body:

#line 17 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\Hoge1.cs"
    /* Path=1, Unique=0: IL_0000: ldarg.0 */
    __stack0_0 = a;
    /* Path=1, Unique=0: IL_0001: ldarg.1 */
    __stack1_0 = (isTwo) ? 1 : 0;
    /* Path=1, Unique=0: IL_0002: brtrue.s IL_0007 */
    if (__stack1_0 != 0) goto IL_0007;
    /* Path=1, Unique=0: IL_0004: ldc.i4.1 */
    __stack1_0 = 1;
    /* Path=1, Unique=0: IL_0005: br.s IL_0008 */
    goto IL_0008;
IL_0007:
    /* Path=2, Unique=0: IL_0007: ldc.i4.2 */
    __stack1_0 = 2;
IL_0008:
    /* Path=2, Unique=0: IL_0008: conv.i8 */
    __stack1_1 = (int64_t)__stack1_0;
    /* Path=2, Unique=0: IL_0009: add */
    __stack0_0 = __stack0_0 + __stack1_1;
    /* Path=2, Unique=0: IL_000a: ret */
    return __stack0_0;
}

///////////////////////////////////////
// .ctor

void Win32_Code_Hoge1__ctor(Win32_Code_Hoge1* this__)
{
    //-------------------
    // Local variables:


    //-------------------
    // Evaluation stacks:

    Win32_Code_Hoge1* __stack0_0 = NULL;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        Win32_Code_Hoge1** p__stack0_0;
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

static void __Win32_Code_Hoge1_MARK_HANDLER__(void* pReference)
{
    il2c_typeof(System_Object)->pMarkHandler(pReference);
}

static __Win32_Code_Hoge1_TYPE_DEF_TYPE__ __Win32_Code_Hoge1_RUNTIME_TYPE_DEF__ = {
    (intptr_t)"Win32.Code.Hoge1",
    (intptr_t)0,
    (intptr_t)__Win32_Code_Hoge1_MARK_HANDLER__,
    __System_Object_ToString__,
    __System_Object_GetHashCode__,
    __System_Object_Finalize__,
    __System_Object_Equals__,
};
const IL2C_RUNTIME_TYPE __Win32_Code_Hoge1_RUNTIME_TYPE__ =
   (const IL2C_RUNTIME_TYPE)(&__Win32_Code_Hoge1_RUNTIME_TYPE_DEF__);

////////////////////////////////////////////////////////////
// Type: Win32.Code.Hoge2

///////////////////////////////////////
// Add3

uint8_t Win32_Code_Hoge2_Add3(uint8_t a, bool isTwo)
{
    //-------------------
    // Local variables:


    //-------------------
    // Evaluation stacks:

    int32_t __stack0_0;
    int32_t __stack1_0;

    //-------------------
    // IL body:

#line 12 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\Hoge2.cs"
    /* Path=1, Unique=0: IL_0000: ldarg.0 */
    __stack0_0 = (int32_t)(a);
    /* Path=1, Unique=0: IL_0001: ldarg.1 */
    __stack1_0 = (isTwo) ? 1 : 0;
    /* Path=1, Unique=0: IL_0002: brtrue.s IL_0007 */
    if (__stack1_0 != 0) goto IL_0007;
    /* Path=1, Unique=0: IL_0004: ldc.i4.1 */
    __stack1_0 = 1;
    /* Path=1, Unique=0: IL_0005: br.s IL_0008 */
    goto IL_0008;
IL_0007:
    /* Path=2, Unique=0: IL_0007: ldc.i4.2 */
    __stack1_0 = 2;
IL_0008:
    /* Path=2, Unique=0: IL_0008: add */
    __stack0_0 = __stack0_0 + __stack1_0;
    /* Path=2, Unique=0: IL_0009: conv.u1 */
    __stack0_0 = (uint8_t)__stack0_0;
    /* Path=2, Unique=0: IL_000a: ret */
    return (uint8_t)__stack0_0;
}

///////////////////////////////////////
// Add4

uint16_t Win32_Code_Hoge2_Add4(uint16_t a, bool isTwo)
{
    //-------------------
    // Local variables:


    //-------------------
    // Evaluation stacks:

    int32_t __stack0_0;
    int32_t __stack1_0;

    //-------------------
    // IL body:

#line 17 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\Hoge2.cs"
    /* Path=1, Unique=0: IL_0000: ldarg.0 */
    __stack0_0 = (int32_t)(a);
    /* Path=1, Unique=0: IL_0001: ldarg.1 */
    __stack1_0 = (isTwo) ? 1 : 0;
    /* Path=1, Unique=0: IL_0002: brtrue.s IL_0007 */
    if (__stack1_0 != 0) goto IL_0007;
    /* Path=1, Unique=0: IL_0004: ldc.i4.1 */
    __stack1_0 = 1;
    /* Path=1, Unique=0: IL_0005: br.s IL_0008 */
    goto IL_0008;
IL_0007:
    /* Path=2, Unique=0: IL_0007: ldc.i4.2 */
    __stack1_0 = 2;
IL_0008:
    /* Path=2, Unique=0: IL_0008: add */
    __stack0_0 = __stack0_0 + __stack1_0;
    /* Path=2, Unique=0: IL_0009: conv.u2 */
    __stack0_0 = (uint16_t)__stack0_0;
    /* Path=2, Unique=0: IL_000a: ret */
    return (uint16_t)__stack0_0;
}

///////////////////////////////////////
// .ctor

void Win32_Code_Hoge2__ctor(Win32_Code_Hoge2* this__)
{
    //-------------------
    // Local variables:


    //-------------------
    // Evaluation stacks:

    Win32_Code_Hoge2* __stack0_0 = NULL;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        Win32_Code_Hoge2** p__stack0_0;
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

static void __Win32_Code_Hoge2_MARK_HANDLER__(void* pReference)
{
    il2c_typeof(System_Object)->pMarkHandler(pReference);
}

static __Win32_Code_Hoge2_TYPE_DEF_TYPE__ __Win32_Code_Hoge2_RUNTIME_TYPE_DEF__ = {
    (intptr_t)"Win32.Code.Hoge2",
    (intptr_t)0,
    (intptr_t)__Win32_Code_Hoge2_MARK_HANDLER__,
    __System_Object_ToString__,
    __System_Object_GetHashCode__,
    __System_Object_Finalize__,
    __System_Object_Equals__,
};
const IL2C_RUNTIME_TYPE __Win32_Code_Hoge2_RUNTIME_TYPE__ =
   (const IL2C_RUNTIME_TYPE)(&__Win32_Code_Hoge2_RUNTIME_TYPE_DEF__);

////////////////////////////////////////////////////////////
// Type: Win32.Code.InheritTestTargetBase1

///////////////////////////////////////
// .ctor

void Win32_Code_InheritTestTargetBase1__ctor(Win32_Code_InheritTestTargetBase1* this__)
{
    //-------------------
    // Local variables:


    //-------------------
    // Evaluation stacks:

    Win32_Code_InheritTestTargetBase1* __stack0_0 = NULL;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        Win32_Code_InheritTestTargetBase1** p__stack0_0;
    } __executionFrame__;

    __executionFrame__.targetCount = 1;
    __executionFrame__.p__stack0_0 = &__stack0_0;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

#line 13 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\InheritTest.cs"
    /* Path=1, Unique=0: IL_0000: ldarg.0 */
    __stack0_0 = this__;
    /* Path=1, Unique=0: IL_0001: call System.Void System.Object::.ctor() */
    System_Object__ctor((System_Object*)__stack0_0);
#line 15 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\InheritTest.cs"
    /* Path=1, Unique=0: IL_0006: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return;
}

///////////////////////////////////////
// .ctor

void Win32_Code_InheritTestTargetBase1__ctor_1(Win32_Code_InheritTestTargetBase1* this__, int32_t value)
{
    //-------------------
    // Local variables:


    //-------------------
    // Evaluation stacks:

    Win32_Code_InheritTestTargetBase1* __stack0_0 = NULL;
    int32_t __stack1_0;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        Win32_Code_InheritTestTargetBase1** p__stack0_0;
    } __executionFrame__;

    __executionFrame__.targetCount = 1;
    __executionFrame__.p__stack0_0 = &__stack0_0;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

#line 17 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\InheritTest.cs"
    /* Path=1, Unique=0: IL_0000: ldarg.0 */
    __stack0_0 = this__;
    /* Path=1, Unique=0: IL_0001: call System.Void System.Object::.ctor() */
    System_Object__ctor((System_Object*)__stack0_0);
#line 19 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\InheritTest.cs"
    /* Path=1, Unique=0: IL_0006: ldarg.0 */
    __stack0_0 = this__;
    /* Path=1, Unique=0: IL_0007: ldarg.1 */
    __stack1_0 = value;
    /* Path=1, Unique=0: IL_0008: stfld System.Int32 Win32.Code.InheritTestTargetBase1::Value2 */
    __stack0_0->Value2 = __stack1_0;
#line 20 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\InheritTest.cs"
    /* Path=1, Unique=0: IL_000d: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return;
}

///////////////////////////////////////
// Calc

int32_t Win32_Code_InheritTestTargetBase1_Calc(Win32_Code_InheritTestTargetBase1* this__, int32_t a)
{
    //-------------------
    // Local variables:


    //-------------------
    // Evaluation stacks:

    Win32_Code_InheritTestTargetBase1* __stack0_0 = NULL;
    int32_t __stack0_1;
    int32_t __stack1_0;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        Win32_Code_InheritTestTargetBase1** p__stack0_0;
    } __executionFrame__;

    __executionFrame__.targetCount = 1;
    __executionFrame__.p__stack0_0 = &__stack0_0;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

#line 24 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\InheritTest.cs"
    /* Path=1, Unique=0: IL_0000: ldarg.0 */
    __stack0_0 = this__;
    /* Path=1, Unique=0: IL_0001: ldfld System.Int32 Win32.Code.InheritTestTargetBase1::Value2 */
    __stack0_1 = __stack0_0->Value2;
    /* Path=1, Unique=0: IL_0006: ldarg.1 */
    __stack1_0 = a;
    /* Path=1, Unique=0: IL_0007: add */
    __stack0_1 = __stack0_1 + __stack1_0;
    /* Path=1, Unique=0: IL_0008: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return __stack0_1;
}

///////////////////////////////////////
// Virtual: Calc

int32_t __Win32_Code_InheritTestTargetBase1_Calc_1__(Win32_Code_InheritTestTargetBase1* this__, int32_t a, int32_t b)
{
    //-------------------
    // Local variables:


    //-------------------
    // Evaluation stacks:

    Win32_Code_InheritTestTargetBase1* __stack0_0 = NULL;
    int32_t __stack0_1;
    int32_t __stack1_0;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        Win32_Code_InheritTestTargetBase1** p__stack0_0;
    } __executionFrame__;

    __executionFrame__.targetCount = 1;
    __executionFrame__.p__stack0_0 = &__stack0_0;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

#line 29 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\InheritTest.cs"
    /* Path=1, Unique=0: IL_0000: ldarg.0 */
    __stack0_0 = this__;
    /* Path=1, Unique=0: IL_0001: ldfld System.Int32 Win32.Code.InheritTestTargetBase1::Value2 */
    __stack0_1 = __stack0_0->Value2;
    /* Path=1, Unique=0: IL_0006: ldarg.1 */
    __stack1_0 = a;
    /* Path=1, Unique=0: IL_0007: add */
    __stack0_1 = __stack0_1 + __stack1_0;
    /* Path=1, Unique=0: IL_0008: ldarg.2 */
    __stack1_0 = b;
    /* Path=1, Unique=0: IL_0009: add */
    __stack0_1 = __stack0_1 + __stack1_0;
    /* Path=1, Unique=0: IL_000a: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return __stack0_1;
}

//////////////////////
// Runtime helpers:

static void __Win32_Code_InheritTestTargetBase1_MARK_HANDLER__(void* pReference)
{
    il2c_try_mark_from_handler(((Win32_Code_InheritTestTargetBase1*)pReference)->OR2);
    il2c_typeof(System_Object)->pMarkHandler(pReference);
}

static __Win32_Code_InheritTestTargetBase1_TYPE_DEF_TYPE__ __Win32_Code_InheritTestTargetBase1_RUNTIME_TYPE_DEF__ = {
    (intptr_t)"Win32.Code.InheritTestTargetBase1",
    (intptr_t)sizeof(Win32_Code_InheritTestTargetBase1),
    (intptr_t)__Win32_Code_InheritTestTargetBase1_MARK_HANDLER__,
    __System_Object_ToString__,
    __System_Object_GetHashCode__,
    __System_Object_Finalize__,
    __System_Object_Equals__,
    __Win32_Code_InheritTestTargetBase1_Calc_1__,
};
const IL2C_RUNTIME_TYPE __Win32_Code_InheritTestTargetBase1_RUNTIME_TYPE__ =
   (const IL2C_RUNTIME_TYPE)(&__Win32_Code_InheritTestTargetBase1_RUNTIME_TYPE_DEF__);

////////////////////////////////////////////////////////////
// Type: Win32.Code.InheritTestTarget2

///////////////////////////////////////
// .ctor

void Win32_Code_InheritTestTarget2__ctor(Win32_Code_InheritTestTarget2* this__)
{
    //-------------------
    // Local variables:


    //-------------------
    // Evaluation stacks:

    Win32_Code_InheritTestTarget2* __stack0_0 = NULL;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        Win32_Code_InheritTestTarget2** p__stack0_0;
    } __executionFrame__;

    __executionFrame__.targetCount = 1;
    __executionFrame__.p__stack0_0 = &__stack0_0;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

#line 35 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\InheritTest.cs"
    /* Path=1, Unique=0: IL_0000: ldarg.0 */
    __stack0_0 = this__;
    /* Path=1, Unique=0: IL_0001: call System.Void Win32.Code.InheritTestTargetBase1::.ctor() */
    Win32_Code_InheritTestTargetBase1__ctor((Win32_Code_InheritTestTargetBase1*)__stack0_0);
#line 37 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\InheritTest.cs"
    /* Path=1, Unique=0: IL_0006: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return;
}

///////////////////////////////////////
// .ctor

void Win32_Code_InheritTestTarget2__ctor_1(Win32_Code_InheritTestTarget2* this__, int32_t value)
{
    //-------------------
    // Local variables:


    //-------------------
    // Evaluation stacks:

    Win32_Code_InheritTestTarget2* __stack0_0 = NULL;
    int32_t __stack1_0;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        Win32_Code_InheritTestTarget2** p__stack0_0;
    } __executionFrame__;

    __executionFrame__.targetCount = 1;
    __executionFrame__.p__stack0_0 = &__stack0_0;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

#line 40 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\InheritTest.cs"
    /* Path=1, Unique=0: IL_0000: ldarg.0 */
    __stack0_0 = this__;
    /* Path=1, Unique=0: IL_0001: ldarg.1 */
    __stack1_0 = value;
    /* Path=1, Unique=0: IL_0002: call System.Void Win32.Code.InheritTestTargetBase1::.ctor(System.Int32) */
    Win32_Code_InheritTestTargetBase1__ctor_1((Win32_Code_InheritTestTargetBase1*)__stack0_0, __stack1_0);
#line 42 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\InheritTest.cs"
    /* Path=1, Unique=0: IL_0007: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return;
}

///////////////////////////////////////
// Calc

int32_t Win32_Code_InheritTestTarget2_Calc(Win32_Code_InheritTestTarget2* this__, int32_t a)
{
    //-------------------
    // Local variables:


    //-------------------
    // Evaluation stacks:

    Win32_Code_InheritTestTarget2* __stack0_0 = NULL;
    int32_t __stack0_1;
    int32_t __stack1_0;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        Win32_Code_InheritTestTarget2** p__stack0_0;
    } __executionFrame__;

    __executionFrame__.targetCount = 1;
    __executionFrame__.p__stack0_0 = &__stack0_0;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

#line 46 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\InheritTest.cs"
    /* Path=1, Unique=0: IL_0000: ldarg.0 */
    __stack0_0 = this__;
    /* Path=1, Unique=0: IL_0001: ldfld System.Int32 Win32.Code.InheritTestTargetBase1::Value2 */
    __stack0_1 = __stack0_0->Value2;
    /* Path=1, Unique=0: IL_0006: ldarg.1 */
    __stack1_0 = a;
    /* Path=1, Unique=0: IL_0007: add */
    __stack0_1 = __stack0_1 + __stack1_0;
    /* Path=1, Unique=0: IL_0008: ldc.i4 10000 */
    __stack1_0 = 10000;
    /* Path=1, Unique=0: IL_000d: add */
    __stack0_1 = __stack0_1 + __stack1_0;
    /* Path=1, Unique=0: IL_000e: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return __stack0_1;
}

///////////////////////////////////////
// Virtual: Calc

int32_t __Win32_Code_InheritTestTarget2_Calc_1__(Win32_Code_InheritTestTarget2* this__, int32_t a, int32_t b)
{
    //-------------------
    // Local variables:


    //-------------------
    // Evaluation stacks:

    Win32_Code_InheritTestTarget2* __stack0_0 = NULL;
    int32_t __stack0_1;
    int32_t __stack1_0;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        Win32_Code_InheritTestTarget2** p__stack0_0;
    } __executionFrame__;

    __executionFrame__.targetCount = 1;
    __executionFrame__.p__stack0_0 = &__stack0_0;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

#line 51 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\InheritTest.cs"
    /* Path=1, Unique=0: IL_0000: ldarg.0 */
    __stack0_0 = this__;
    /* Path=1, Unique=0: IL_0001: ldfld System.Int32 Win32.Code.InheritTestTargetBase1::Value2 */
    __stack0_1 = __stack0_0->Value2;
    /* Path=1, Unique=0: IL_0006: ldarg.1 */
    __stack1_0 = a;
    /* Path=1, Unique=0: IL_0007: add */
    __stack0_1 = __stack0_1 + __stack1_0;
    /* Path=1, Unique=0: IL_0008: ldarg.2 */
    __stack1_0 = b;
    /* Path=1, Unique=0: IL_0009: add */
    __stack0_1 = __stack0_1 + __stack1_0;
    /* Path=1, Unique=0: IL_000a: ldc.i4 10000 */
    __stack1_0 = 10000;
    /* Path=1, Unique=0: IL_000f: add */
    __stack0_1 = __stack0_1 + __stack1_0;
    /* Path=1, Unique=0: IL_0010: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return __stack0_1;
}

//////////////////////
// Runtime helpers:

static void __Win32_Code_InheritTestTarget2_MARK_HANDLER__(void* pReference)
{
    il2c_typeof(Win32_Code_InheritTestTargetBase1)->pMarkHandler(pReference);
}

static __Win32_Code_InheritTestTarget2_TYPE_DEF_TYPE__ __Win32_Code_InheritTestTarget2_RUNTIME_TYPE_DEF__ = {
    (intptr_t)"Win32.Code.InheritTestTarget2",
    (intptr_t)sizeof(Win32_Code_InheritTestTarget2),
    (intptr_t)__Win32_Code_InheritTestTarget2_MARK_HANDLER__,
    __System_Object_ToString__,
    __System_Object_GetHashCode__,
    __System_Object_Finalize__,
    __System_Object_Equals__,
    __Win32_Code_InheritTestTarget2_Calc_1__,
};
const IL2C_RUNTIME_TYPE __Win32_Code_InheritTestTarget2_RUNTIME_TYPE__ =
   (const IL2C_RUNTIME_TYPE)(&__Win32_Code_InheritTestTarget2_RUNTIME_TYPE_DEF__);

////////////////////////////////////////////////////////////
// Type: Win32.Code.InheritTypeTest

///////////////////////////////////////
// Test1

int32_t Win32_Code_InheritTypeTest_Test1(void)
{
    //-------------------
    // Local variables:


    //-------------------
    // Evaluation stacks:

    Win32_Code_InheritTestTargetBase1* __stack0_0 = NULL;
    int32_t __stack0_1;
    Win32_Code_InheritTestTargetBase1* __stack1_0 = NULL;
    int32_t __stack1_1;
    int32_t __stack2_0;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        Win32_Code_InheritTestTargetBase1** p__stack0_0;
        Win32_Code_InheritTestTargetBase1** p__stack1_0;
    } __executionFrame__;

    __executionFrame__.targetCount = 2;
    __executionFrame__.p__stack0_0 = &__stack0_0;
    __executionFrame__.p__stack1_0 = &__stack1_0;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

#line 59 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\InheritTest.cs"
    /* Path=1, Unique=0: IL_0000: newobj System.Void Win32.Code.InheritTestTargetBase1::.ctor() */
    __stack0_0 = il2c_get_uninitialized_object(il2c_typeof(Win32_Code_InheritTestTargetBase1));
    Win32_Code_InheritTestTargetBase1__ctor(__stack0_0);
#line 60 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\InheritTest.cs"
    /* Path=1, Unique=0: IL_0005: dup */
    __stack1_0 = __stack0_0;
    /* Path=1, Unique=0: IL_0006: ldc.i4.s 123 */
    __stack2_0 = 123;
    /* Path=1, Unique=0: IL_0008: stfld System.Int32 Win32.Code.InheritTestTargetBase1::Value2 */
    __stack1_0->Value2 = __stack2_0;
#line 62 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\InheritTest.cs"
    /* Path=1, Unique=0: IL_000d: ldc.i4.1 */
    __stack1_1 = 1;
    /* Path=1, Unique=0: IL_000e: callvirt System.Int32 Win32.Code.InheritTestTargetBase1::Calc(System.Int32) */
    __stack0_1 = Win32_Code_InheritTestTargetBase1_Calc(__stack0_0, __stack1_1);
    /* Path=1, Unique=0: IL_0013: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return __stack0_1;
}

///////////////////////////////////////
// Test2

int32_t Win32_Code_InheritTypeTest_Test2(void)
{
    //-------------------
    // Local variables:


    //-------------------
    // Evaluation stacks:

    Win32_Code_InheritTestTargetBase1* __stack0_0 = NULL;
    int32_t __stack0_1;
    Win32_Code_InheritTestTargetBase1* __stack1_0 = NULL;
    int32_t __stack1_1;
    int32_t __stack2_0;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        Win32_Code_InheritTestTargetBase1** p__stack0_0;
        Win32_Code_InheritTestTargetBase1** p__stack1_0;
    } __executionFrame__;

    __executionFrame__.targetCount = 2;
    __executionFrame__.p__stack0_0 = &__stack0_0;
    __executionFrame__.p__stack1_0 = &__stack1_0;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

#line 67 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\InheritTest.cs"
    /* Path=1, Unique=0: IL_0000: newobj System.Void Win32.Code.InheritTestTargetBase1::.ctor() */
    __stack0_0 = il2c_get_uninitialized_object(il2c_typeof(Win32_Code_InheritTestTargetBase1));
    Win32_Code_InheritTestTargetBase1__ctor(__stack0_0);
#line 68 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\InheritTest.cs"
    /* Path=1, Unique=0: IL_0005: dup */
    __stack1_0 = __stack0_0;
    /* Path=1, Unique=0: IL_0006: ldc.i4.s 123 */
    __stack2_0 = 123;
    /* Path=1, Unique=0: IL_0008: stfld System.Int32 Win32.Code.InheritTestTargetBase1::Value2 */
    __stack1_0->Value2 = __stack2_0;
#line 70 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\InheritTest.cs"
    /* Path=1, Unique=0: IL_000d: ldc.i4.1 */
    __stack1_1 = 1;
    /* Path=1, Unique=0: IL_000e: ldc.i4.2 */
    __stack2_0 = 2;
    /* Path=1, Unique=0: IL_000f: callvirt System.Int32 Win32.Code.InheritTestTargetBase1::Calc(System.Int32,System.Int32) */
    __stack0_1 = Win32_Code_InheritTestTargetBase1_Calc_1(__stack0_0, __stack1_1, __stack2_0);
    /* Path=1, Unique=0: IL_0014: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return __stack0_1;
}

///////////////////////////////////////
// Test3

int32_t Win32_Code_InheritTypeTest_Test3(void)
{
    //-------------------
    // Local variables:


    //-------------------
    // Evaluation stacks:

    Win32_Code_InheritTestTarget2* __stack0_0 = NULL;
    int32_t __stack0_1;
    Win32_Code_InheritTestTarget2* __stack1_0 = NULL;
    int32_t __stack1_1;
    int32_t __stack2_0;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        Win32_Code_InheritTestTarget2** p__stack0_0;
        Win32_Code_InheritTestTarget2** p__stack1_0;
    } __executionFrame__;

    __executionFrame__.targetCount = 2;
    __executionFrame__.p__stack0_0 = &__stack0_0;
    __executionFrame__.p__stack1_0 = &__stack1_0;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

#line 75 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\InheritTest.cs"
    /* Path=1, Unique=0: IL_0000: newobj System.Void Win32.Code.InheritTestTarget2::.ctor() */
    __stack0_0 = il2c_get_uninitialized_object(il2c_typeof(Win32_Code_InheritTestTarget2));
    Win32_Code_InheritTestTarget2__ctor(__stack0_0);
#line 76 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\InheritTest.cs"
    /* Path=1, Unique=0: IL_0005: dup */
    __stack1_0 = __stack0_0;
    /* Path=1, Unique=0: IL_0006: ldc.i4.s 123 */
    __stack2_0 = 123;
    /* Path=1, Unique=0: IL_0008: stfld System.Int32 Win32.Code.InheritTestTargetBase1::Value2 */
    __stack1_0->Value2 = __stack2_0;
#line 78 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\InheritTest.cs"
    /* Path=1, Unique=0: IL_000d: ldc.i4.1 */
    __stack1_1 = 1;
    /* Path=1, Unique=0: IL_000e: ldc.i4.2 */
    __stack2_0 = 2;
    /* Path=1, Unique=0: IL_000f: callvirt System.Int32 Win32.Code.InheritTestTargetBase1::Calc(System.Int32,System.Int32) */
    __stack0_1 = Win32_Code_InheritTestTargetBase1_Calc_1((Win32_Code_InheritTestTargetBase1*)__stack0_0, __stack1_1, __stack2_0);
    /* Path=1, Unique=0: IL_0014: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return __stack0_1;
}

///////////////////////////////////////
// Test4

int32_t Win32_Code_InheritTypeTest_Test4(void)
{
    //-------------------
    // Local variables:


    //-------------------
    // Evaluation stacks:

    Win32_Code_InheritTestTarget2* __stack0_0 = NULL;
    int32_t __stack0_1;
    Win32_Code_InheritTestTarget2* __stack1_0 = NULL;
    int32_t __stack1_1;
    int32_t __stack2_0;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        Win32_Code_InheritTestTarget2** p__stack0_0;
        Win32_Code_InheritTestTarget2** p__stack1_0;
    } __executionFrame__;

    __executionFrame__.targetCount = 2;
    __executionFrame__.p__stack0_0 = &__stack0_0;
    __executionFrame__.p__stack1_0 = &__stack1_0;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

#line 83 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\InheritTest.cs"
    /* Path=1, Unique=0: IL_0000: newobj System.Void Win32.Code.InheritTestTarget2::.ctor() */
    __stack0_0 = il2c_get_uninitialized_object(il2c_typeof(Win32_Code_InheritTestTarget2));
    Win32_Code_InheritTestTarget2__ctor(__stack0_0);
#line 84 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\InheritTest.cs"
    /* Path=1, Unique=0: IL_0005: dup */
    __stack1_0 = __stack0_0;
    /* Path=1, Unique=0: IL_0006: ldc.i4.s 123 */
    __stack2_0 = 123;
    /* Path=1, Unique=0: IL_0008: stfld System.Int32 Win32.Code.InheritTestTargetBase1::Value2 */
    __stack1_0->Value2 = __stack2_0;
#line 86 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\InheritTest.cs"
    /* Path=1, Unique=0: IL_000d: ldc.i4.1 */
    __stack1_1 = 1;
    /* Path=1, Unique=0: IL_000e: ldc.i4.2 */
    __stack2_0 = 2;
    /* Path=1, Unique=0: IL_000f: callvirt System.Int32 Win32.Code.InheritTestTargetBase1::Calc(System.Int32,System.Int32) */
    __stack0_1 = Win32_Code_InheritTestTargetBase1_Calc_1((Win32_Code_InheritTestTargetBase1*)__stack0_0, __stack1_1, __stack2_0);
    /* Path=1, Unique=0: IL_0014: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return __stack0_1;
}

///////////////////////////////////////
// .ctor

void Win32_Code_InheritTypeTest__ctor(Win32_Code_InheritTypeTest* this__)
{
    //-------------------
    // Local variables:


    //-------------------
    // Evaluation stacks:

    Win32_Code_InheritTypeTest* __stack0_0 = NULL;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        Win32_Code_InheritTypeTest** p__stack0_0;
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

static void __Win32_Code_InheritTypeTest_MARK_HANDLER__(void* pReference)
{
    il2c_typeof(System_Object)->pMarkHandler(pReference);
}

static __Win32_Code_InheritTypeTest_TYPE_DEF_TYPE__ __Win32_Code_InheritTypeTest_RUNTIME_TYPE_DEF__ = {
    (intptr_t)"Win32.Code.InheritTypeTest",
    (intptr_t)0,
    (intptr_t)__Win32_Code_InheritTypeTest_MARK_HANDLER__,
    __System_Object_ToString__,
    __System_Object_GetHashCode__,
    __System_Object_Finalize__,
    __System_Object_Equals__,
};
const IL2C_RUNTIME_TYPE __Win32_Code_InheritTypeTest_RUNTIME_TYPE__ =
   (const IL2C_RUNTIME_TYPE)(&__Win32_Code_InheritTypeTest_RUNTIME_TYPE_DEF__);

////////////////////////////////////////////////////////////
// Type: Win32.Code.Win32

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
    OutputDebugStringW(message->string_body__);
}

///////////////////////////////////////
// .ctor

void Win32_Code_Win32__ctor(Win32_Code_Win32* this__)
{
    //-------------------
    // Local variables:


    //-------------------
    // Evaluation stacks:

    Win32_Code_Win32* __stack0_0 = NULL;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        Win32_Code_Win32** p__stack0_0;
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

static void __Win32_Code_Win32_MARK_HANDLER__(void* pReference)
{
    il2c_typeof(System_Object)->pMarkHandler(pReference);
}

static __Win32_Code_Win32_TYPE_DEF_TYPE__ __Win32_Code_Win32_RUNTIME_TYPE_DEF__ = {
    (intptr_t)"Win32.Code.Win32",
    (intptr_t)0,
    (intptr_t)__Win32_Code_Win32_MARK_HANDLER__,
    __System_Object_ToString__,
    __System_Object_GetHashCode__,
    __System_Object_Finalize__,
    __System_Object_Equals__,
};
const IL2C_RUNTIME_TYPE __Win32_Code_Win32_RUNTIME_TYPE__ =
   (const IL2C_RUNTIME_TYPE)(&__Win32_Code_Win32_RUNTIME_TYPE_DEF__);

////////////////////////////////////////////////////////////
// Type: Win32.Code.AbstractNode

///////////////////////////////////////
// .ctor

void Win32_Code_AbstractNode__ctor(Win32_Code_AbstractNode* this__, int32_t nextIndex)
{
    //-------------------
    // Local variables:


    //-------------------
    // Evaluation stacks:

    Win32_Code_AbstractNode* __stack0_0 = NULL;
    int32_t __stack1_0;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        Win32_Code_AbstractNode** p__stack0_0;
    } __executionFrame__;

    __executionFrame__.targetCount = 1;
    __executionFrame__.p__stack0_0 = &__stack0_0;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

#line 13 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\PolishNotation.cs"
    /* Path=1, Unique=0: IL_0000: ldarg.0 */
    __stack0_0 = this__;
    /* Path=1, Unique=0: IL_0001: call System.Void System.Object::.ctor() */
    System_Object__ctor((System_Object*)__stack0_0);
#line 15 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\PolishNotation.cs"
    /* Path=1, Unique=0: IL_0006: ldarg.0 */
    __stack0_0 = this__;
    /* Path=1, Unique=0: IL_0007: ldarg.1 */
    __stack1_0 = nextIndex;
    /* Path=1, Unique=0: IL_0008: stfld System.Int32 Win32.Code.AbstractNode::NextIndex */
    __stack0_0->NextIndex = __stack1_0;
#line 16 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\PolishNotation.cs"
    /* Path=1, Unique=0: IL_000d: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return;
}

//////////////////////
// Runtime helpers:

static void __Win32_Code_AbstractNode_MARK_HANDLER__(void* pReference)
{
    il2c_typeof(System_Object)->pMarkHandler(pReference);
}

static __Win32_Code_AbstractNode_TYPE_DEF_TYPE__ __Win32_Code_AbstractNode_RUNTIME_TYPE_DEF__ = {
    (intptr_t)"Win32.Code.AbstractNode",
    (intptr_t)sizeof(Win32_Code_AbstractNode),
    (intptr_t)__Win32_Code_AbstractNode_MARK_HANDLER__,
    __System_Object_ToString__,
    __System_Object_GetHashCode__,
    __System_Object_Finalize__,
    __System_Object_Equals__,
};
const IL2C_RUNTIME_TYPE __Win32_Code_AbstractNode_RUNTIME_TYPE__ =
   (const IL2C_RUNTIME_TYPE)(&__Win32_Code_AbstractNode_RUNTIME_TYPE_DEF__);

////////////////////////////////////////////////////////////
// Type: Win32.Code.OperatorNode

///////////////////////////////////////
// .ctor

void Win32_Code_OperatorNode__ctor(Win32_Code_OperatorNode* this__, wchar_t oper, int32_t nextIndex)
{
    //-------------------
    // Local variables:


    //-------------------
    // Evaluation stacks:

    Win32_Code_OperatorNode* __stack0_0 = NULL;
    int32_t __stack1_0;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        Win32_Code_OperatorNode** p__stack0_0;
    } __executionFrame__;

    __executionFrame__.targetCount = 1;
    __executionFrame__.p__stack0_0 = &__stack0_0;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

#line 23 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\PolishNotation.cs"
    /* Path=1, Unique=0: IL_0000: ldarg.0 */
    __stack0_0 = this__;
    /* Path=1, Unique=0: IL_0001: ldarg.2 */
    __stack1_0 = nextIndex;
    /* Path=1, Unique=0: IL_0002: call System.Void Win32.Code.AbstractNode::.ctor(System.Int32) */
    Win32_Code_AbstractNode__ctor((Win32_Code_AbstractNode*)__stack0_0, __stack1_0);
#line 25 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\PolishNotation.cs"
    /* Path=1, Unique=0: IL_0007: ldarg.0 */
    __stack0_0 = this__;
    /* Path=1, Unique=0: IL_0008: ldarg.1 */
    __stack1_0 = (int32_t)(oper);
    /* Path=1, Unique=0: IL_0009: stfld System.Char Win32.Code.OperatorNode::Operator */
    __stack0_0->Operator = (wchar_t)__stack1_0;
#line 26 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\PolishNotation.cs"
    /* Path=1, Unique=0: IL_000e: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return;
}

//////////////////////
// Runtime helpers:

static void __Win32_Code_OperatorNode_MARK_HANDLER__(void* pReference)
{
    il2c_typeof(Win32_Code_AbstractNode)->pMarkHandler(pReference);
}

static __Win32_Code_OperatorNode_TYPE_DEF_TYPE__ __Win32_Code_OperatorNode_RUNTIME_TYPE_DEF__ = {
    (intptr_t)"Win32.Code.OperatorNode",
    (intptr_t)sizeof(Win32_Code_OperatorNode),
    (intptr_t)__Win32_Code_OperatorNode_MARK_HANDLER__,
    __System_Object_ToString__,
    __System_Object_GetHashCode__,
    __System_Object_Finalize__,
    __System_Object_Equals__,
};
const IL2C_RUNTIME_TYPE __Win32_Code_OperatorNode_RUNTIME_TYPE__ =
   (const IL2C_RUNTIME_TYPE)(&__Win32_Code_OperatorNode_RUNTIME_TYPE_DEF__);

////////////////////////////////////////////////////////////
// Type: Win32.Code.ReducibleNode

///////////////////////////////////////
// .ctor

void Win32_Code_ReducibleNode__ctor(Win32_Code_ReducibleNode* this__, int32_t nextIndex)
{
    //-------------------
    // Local variables:


    //-------------------
    // Evaluation stacks:

    Win32_Code_ReducibleNode* __stack0_0 = NULL;
    int32_t __stack1_0;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        Win32_Code_ReducibleNode** p__stack0_0;
    } __executionFrame__;

    __executionFrame__.targetCount = 1;
    __executionFrame__.p__stack0_0 = &__stack0_0;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

#line 31 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\PolishNotation.cs"
    /* Path=1, Unique=0: IL_0000: ldarg.0 */
    __stack0_0 = this__;
    /* Path=1, Unique=0: IL_0001: ldarg.1 */
    __stack1_0 = nextIndex;
    /* Path=1, Unique=0: IL_0002: call System.Void Win32.Code.AbstractNode::.ctor(System.Int32) */
    Win32_Code_AbstractNode__ctor((Win32_Code_AbstractNode*)__stack0_0, __stack1_0);
#line 33 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\PolishNotation.cs"
    /* Path=1, Unique=0: IL_0007: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return;
}

///////////////////////////////////////
// Abstract: Reduce

int32_t __Win32_Code_ReducibleNode_Reduce__(Win32_Code_ReducibleNode* this__)
{
    // WARNING: Pure virtual function called.
    //TODO: throw : assert(0);
    return (int32_t)0;
}

//////////////////////
// Runtime helpers:

static void __Win32_Code_ReducibleNode_MARK_HANDLER__(void* pReference)
{
    il2c_typeof(Win32_Code_AbstractNode)->pMarkHandler(pReference);
}

static __Win32_Code_ReducibleNode_TYPE_DEF_TYPE__ __Win32_Code_ReducibleNode_RUNTIME_TYPE_DEF__ = {
    (intptr_t)"Win32.Code.ReducibleNode",
    (intptr_t)sizeof(Win32_Code_ReducibleNode),
    (intptr_t)__Win32_Code_ReducibleNode_MARK_HANDLER__,
    __System_Object_ToString__,
    __System_Object_GetHashCode__,
    __System_Object_Finalize__,
    __System_Object_Equals__,
    __Win32_Code_ReducibleNode_Reduce__,
};
const IL2C_RUNTIME_TYPE __Win32_Code_ReducibleNode_RUNTIME_TYPE__ =
   (const IL2C_RUNTIME_TYPE)(&__Win32_Code_ReducibleNode_RUNTIME_TYPE_DEF__);

////////////////////////////////////////////////////////////
// Type: Win32.Code.NumericNode

///////////////////////////////////////
// .ctor

void Win32_Code_NumericNode__ctor(Win32_Code_NumericNode* this__, int32_t numeric, int32_t nextIndex)
{
    //-------------------
    // Local variables:


    //-------------------
    // Evaluation stacks:

    Win32_Code_NumericNode* __stack0_0 = NULL;
    int32_t __stack1_0;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        Win32_Code_NumericNode** p__stack0_0;
    } __executionFrame__;

    __executionFrame__.targetCount = 1;
    __executionFrame__.p__stack0_0 = &__stack0_0;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

#line 42 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\PolishNotation.cs"
    /* Path=1, Unique=0: IL_0000: ldarg.0 */
    __stack0_0 = this__;
    /* Path=1, Unique=0: IL_0001: ldarg.2 */
    __stack1_0 = nextIndex;
    /* Path=1, Unique=0: IL_0002: call System.Void Win32.Code.ReducibleNode::.ctor(System.Int32) */
    Win32_Code_ReducibleNode__ctor((Win32_Code_ReducibleNode*)__stack0_0, __stack1_0);
#line 44 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\PolishNotation.cs"
    /* Path=1, Unique=0: IL_0007: ldarg.0 */
    __stack0_0 = this__;
    /* Path=1, Unique=0: IL_0008: ldarg.1 */
    __stack1_0 = numeric;
    /* Path=1, Unique=0: IL_0009: stfld System.Int32 Win32.Code.NumericNode::Numeric */
    __stack0_0->Numeric = __stack1_0;
#line 45 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\PolishNotation.cs"
    /* Path=1, Unique=0: IL_000e: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return;
}

///////////////////////////////////////
// Virtual: Reduce

int32_t __Win32_Code_NumericNode_Reduce__(Win32_Code_NumericNode* this__)
{
    //-------------------
    // Local variables:


    //-------------------
    // Evaluation stacks:

    Win32_Code_NumericNode* __stack0_0 = NULL;
    int32_t __stack0_1;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        Win32_Code_NumericNode** p__stack0_0;
    } __executionFrame__;

    __executionFrame__.targetCount = 1;
    __executionFrame__.p__stack0_0 = &__stack0_0;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

#line 49 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\PolishNotation.cs"
    /* Path=1, Unique=0: IL_0000: ldarg.0 */
    __stack0_0 = this__;
    /* Path=1, Unique=0: IL_0001: ldfld System.Int32 Win32.Code.NumericNode::Numeric */
    __stack0_1 = __stack0_0->Numeric;
    /* Path=1, Unique=0: IL_0006: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return __stack0_1;
}

//////////////////////
// Runtime helpers:

static void __Win32_Code_NumericNode_MARK_HANDLER__(void* pReference)
{
    il2c_typeof(Win32_Code_ReducibleNode)->pMarkHandler(pReference);
}

static __Win32_Code_NumericNode_TYPE_DEF_TYPE__ __Win32_Code_NumericNode_RUNTIME_TYPE_DEF__ = {
    (intptr_t)"Win32.Code.NumericNode",
    (intptr_t)sizeof(Win32_Code_NumericNode),
    (intptr_t)__Win32_Code_NumericNode_MARK_HANDLER__,
    __System_Object_ToString__,
    __System_Object_GetHashCode__,
    __System_Object_Finalize__,
    __System_Object_Equals__,
    __Win32_Code_NumericNode_Reduce__,
};
const IL2C_RUNTIME_TYPE __Win32_Code_NumericNode_RUNTIME_TYPE__ =
   (const IL2C_RUNTIME_TYPE)(&__Win32_Code_NumericNode_RUNTIME_TYPE_DEF__);

////////////////////////////////////////////////////////////
// Type: Win32.Code.ExpressionNode

///////////////////////////////////////
// .ctor

void Win32_Code_ExpressionNode__ctor(Win32_Code_ExpressionNode* this__, Win32_Code_OperatorNode* oper, Win32_Code_ReducibleNode* left, Win32_Code_ReducibleNode* right, int32_t nextIndex)
{
    //-------------------
    // Local variables:


    //-------------------
    // Evaluation stacks:

    Win32_Code_ExpressionNode* __stack0_0 = NULL;
    int32_t __stack1_0;
    Win32_Code_OperatorNode* __stack1_1 = NULL;
    Win32_Code_ReducibleNode* __stack1_2 = NULL;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        Win32_Code_ExpressionNode** p__stack0_0;
        Win32_Code_OperatorNode** p__stack1_1;
        Win32_Code_ReducibleNode** p__stack1_2;
    } __executionFrame__;

    __executionFrame__.targetCount = 3;
    __executionFrame__.p__stack0_0 = &__stack0_0;
    __executionFrame__.p__stack1_1 = &__stack1_1;
    __executionFrame__.p__stack1_2 = &__stack1_2;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

#line 59 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\PolishNotation.cs"
    /* Path=1, Unique=0: IL_0000: ldarg.0 */
    __stack0_0 = this__;
    /* Path=1, Unique=0: IL_0001: ldarg.s nextIndex */
    __stack1_0 = nextIndex;
    /* Path=1, Unique=0: IL_0003: call System.Void Win32.Code.ReducibleNode::.ctor(System.Int32) */
    Win32_Code_ReducibleNode__ctor((Win32_Code_ReducibleNode*)__stack0_0, __stack1_0);
#line 61 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\PolishNotation.cs"
    /* Path=1, Unique=0: IL_0008: ldarg.0 */
    __stack0_0 = this__;
    /* Path=1, Unique=0: IL_0009: ldarg.1 */
    __stack1_1 = oper;
    /* Path=1, Unique=0: IL_000a: stfld Win32.Code.OperatorNode Win32.Code.ExpressionNode::Operator */
    __stack0_0->Operator = __stack1_1;
#line 62 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\PolishNotation.cs"
    /* Path=1, Unique=0: IL_000f: ldarg.0 */
    __stack0_0 = this__;
    /* Path=1, Unique=0: IL_0010: ldarg.2 */
    __stack1_2 = left;
    /* Path=1, Unique=0: IL_0011: stfld Win32.Code.ReducibleNode Win32.Code.ExpressionNode::Left */
    __stack0_0->Left = __stack1_2;
#line 63 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\PolishNotation.cs"
    /* Path=1, Unique=0: IL_0016: ldarg.0 */
    __stack0_0 = this__;
    /* Path=1, Unique=0: IL_0017: ldarg.3 */
    __stack1_2 = right;
    /* Path=1, Unique=0: IL_0018: stfld Win32.Code.ReducibleNode Win32.Code.ExpressionNode::Right */
    __stack0_0->Right = __stack1_2;
#line 64 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\PolishNotation.cs"
    /* Path=1, Unique=0: IL_001d: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return;
}

///////////////////////////////////////
// Virtual: Reduce

int32_t __Win32_Code_ExpressionNode_Reduce__(Win32_Code_ExpressionNode* this__)
{
    //-------------------
    // Local variables:

    int32_t local0;
    int32_t local1;

    //-------------------
    // Evaluation stacks:

    Win32_Code_ExpressionNode* __stack0_0 = NULL;
    Win32_Code_ReducibleNode* __stack0_1 = NULL;
    int32_t __stack0_2;
    Win32_Code_OperatorNode* __stack0_3 = NULL;
    int32_t __stack1_0;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        Win32_Code_ExpressionNode** p__stack0_0;
        Win32_Code_ReducibleNode** p__stack0_1;
        Win32_Code_OperatorNode** p__stack0_3;
    } __executionFrame__;

    __executionFrame__.targetCount = 3;
    __executionFrame__.p__stack0_0 = &__stack0_0;
    __executionFrame__.p__stack0_1 = &__stack0_1;
    __executionFrame__.p__stack0_3 = &__stack0_3;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

#line 68 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\PolishNotation.cs"
    /* Path=1, Unique=0: IL_0000: ldarg.0 */
    __stack0_0 = this__;
    /* Path=1, Unique=0: IL_0001: ldfld Win32.Code.ReducibleNode Win32.Code.ExpressionNode::Left */
    __stack0_1 = __stack0_0->Left;
    /* Path=1, Unique=0: IL_0006: callvirt System.Int32 Win32.Code.ReducibleNode::Reduce() */
    __stack0_2 = Win32_Code_ReducibleNode_Reduce(__stack0_1);
    /* Path=1, Unique=0: IL_000b: stloc.0 */
    local0 = __stack0_2;
#line 69 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\PolishNotation.cs"
    /* Path=1, Unique=0: IL_000c: ldarg.0 */
    __stack0_0 = this__;
    /* Path=1, Unique=0: IL_000d: ldfld Win32.Code.ReducibleNode Win32.Code.ExpressionNode::Right */
    __stack0_1 = __stack0_0->Right;
    /* Path=1, Unique=0: IL_0012: callvirt System.Int32 Win32.Code.ReducibleNode::Reduce() */
    __stack0_2 = Win32_Code_ReducibleNode_Reduce(__stack0_1);
    /* Path=1, Unique=0: IL_0017: stloc.1 */
    local1 = __stack0_2;
#line 70 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\PolishNotation.cs"
    /* Path=1, Unique=0: IL_0018: ldarg.0 */
    __stack0_0 = this__;
    /* Path=1, Unique=0: IL_0019: ldfld Win32.Code.OperatorNode Win32.Code.ExpressionNode::Operator */
    __stack0_3 = __stack0_0->Operator;
    /* Path=1, Unique=0: IL_001e: ldfld System.Char Win32.Code.OperatorNode::Operator */
    __stack0_2 = (int32_t)(__stack0_3->Operator);
    /* Path=1, Unique=0: IL_0023: ldc.i4.s 43 */
    __stack1_0 = 43;
    /* Path=1, Unique=0: IL_0025: bne.un.s IL_002b */
    if (__stack0_2 != __stack1_0) goto IL_002b;
#line 72 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\PolishNotation.cs"
    /* Path=1, Unique=0: IL_0027: ldloc.0 */
    __stack0_2 = local0;
    /* Path=1, Unique=0: IL_0028: ldloc.1 */
    __stack1_0 = local1;
    /* Path=1, Unique=0: IL_0029: add */
    __stack0_2 = __stack0_2 + __stack1_0;
    /* Path=1, Unique=0: IL_002a: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return __stack0_2;
IL_002b:
#line 74 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\PolishNotation.cs"
    /* Path=2, Unique=0: IL_002b: ldarg.0 */
    __stack0_0 = this__;
    /* Path=2, Unique=0: IL_002c: ldfld Win32.Code.OperatorNode Win32.Code.ExpressionNode::Operator */
    __stack0_3 = __stack0_0->Operator;
    /* Path=2, Unique=0: IL_0031: ldfld System.Char Win32.Code.OperatorNode::Operator */
    __stack0_2 = (int32_t)(__stack0_3->Operator);
    /* Path=2, Unique=0: IL_0036: ldc.i4.s 45 */
    __stack1_0 = 45;
    /* Path=2, Unique=0: IL_0038: bne.un.s IL_003e */
    if (__stack0_2 != __stack1_0) goto IL_003e;
#line 76 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\PolishNotation.cs"
    /* Path=2, Unique=0: IL_003a: ldloc.0 */
    __stack0_2 = local0;
    /* Path=2, Unique=0: IL_003b: ldloc.1 */
    __stack1_0 = local1;
    /* Path=2, Unique=0: IL_003c: sub */
    __stack0_2 = __stack0_2 - __stack1_0;
    /* Path=2, Unique=0: IL_003d: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return __stack0_2;
IL_003e:
#line 78 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\PolishNotation.cs"
    /* Path=3, Unique=0: IL_003e: ldarg.0 */
    __stack0_0 = this__;
    /* Path=3, Unique=0: IL_003f: ldfld Win32.Code.OperatorNode Win32.Code.ExpressionNode::Operator */
    __stack0_3 = __stack0_0->Operator;
    /* Path=3, Unique=0: IL_0044: ldfld System.Char Win32.Code.OperatorNode::Operator */
    __stack0_2 = (int32_t)(__stack0_3->Operator);
    /* Path=3, Unique=0: IL_0049: ldc.i4.s 42 */
    __stack1_0 = 42;
    /* Path=3, Unique=0: IL_004b: bne.un.s IL_0051 */
    if (__stack0_2 != __stack1_0) goto IL_0051;
#line 80 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\PolishNotation.cs"
    /* Path=3, Unique=0: IL_004d: ldloc.0 */
    __stack0_2 = local0;
    /* Path=3, Unique=0: IL_004e: ldloc.1 */
    __stack1_0 = local1;
    /* Path=3, Unique=0: IL_004f: mul */
    __stack0_2 = __stack0_2 * __stack1_0;
    /* Path=3, Unique=0: IL_0050: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return __stack0_2;
IL_0051:
#line 82 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\PolishNotation.cs"
    /* Path=4, Unique=0: IL_0051: ldarg.0 */
    __stack0_0 = this__;
    /* Path=4, Unique=0: IL_0052: ldfld Win32.Code.OperatorNode Win32.Code.ExpressionNode::Operator */
    __stack0_3 = __stack0_0->Operator;
    /* Path=4, Unique=0: IL_0057: ldfld System.Char Win32.Code.OperatorNode::Operator */
    __stack0_2 = (int32_t)(__stack0_3->Operator);
    /* Path=4, Unique=0: IL_005c: ldc.i4.s 47 */
    __stack1_0 = 47;
    /* Path=4, Unique=0: IL_005e: bne.un.s IL_0064 */
    if (__stack0_2 != __stack1_0) goto IL_0064;
#line 84 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\PolishNotation.cs"
    /* Path=4, Unique=0: IL_0060: ldloc.0 */
    __stack0_2 = local0;
    /* Path=4, Unique=0: IL_0061: ldloc.1 */
    __stack1_0 = local1;
    /* Path=4, Unique=0: IL_0062: div */
    __stack0_2 = __stack0_2 / __stack1_0;
    /* Path=4, Unique=0: IL_0063: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return __stack0_2;
IL_0064:
#line 88 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\PolishNotation.cs"
    /* Path=5, Unique=0: IL_0064: ldc.i4.0 */
    __stack0_2 = 0;
    /* Path=5, Unique=0: IL_0065: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return __stack0_2;
}

//////////////////////
// Runtime helpers:

static void __Win32_Code_ExpressionNode_MARK_HANDLER__(void* pReference)
{
    il2c_try_mark_from_handler(((Win32_Code_ExpressionNode*)pReference)->Operator);
    il2c_try_mark_from_handler(((Win32_Code_ExpressionNode*)pReference)->Left);
    il2c_try_mark_from_handler(((Win32_Code_ExpressionNode*)pReference)->Right);
    il2c_typeof(Win32_Code_ReducibleNode)->pMarkHandler(pReference);
}

static __Win32_Code_ExpressionNode_TYPE_DEF_TYPE__ __Win32_Code_ExpressionNode_RUNTIME_TYPE_DEF__ = {
    (intptr_t)"Win32.Code.ExpressionNode",
    (intptr_t)sizeof(Win32_Code_ExpressionNode),
    (intptr_t)__Win32_Code_ExpressionNode_MARK_HANDLER__,
    __System_Object_ToString__,
    __System_Object_GetHashCode__,
    __System_Object_Finalize__,
    __System_Object_Equals__,
    __Win32_Code_ExpressionNode_Reduce__,
};
const IL2C_RUNTIME_TYPE __Win32_Code_ExpressionNode_RUNTIME_TYPE__ =
   (const IL2C_RUNTIME_TYPE)(&__Win32_Code_ExpressionNode_RUNTIME_TYPE_DEF__);

////////////////////////////////////////////////////////////
// Type: Win32.Code.PolishNotation

///////////////////////////////////////
// SkipWhiteSpace

int32_t Win32_Code_PolishNotation_SkipWhiteSpace(System_String* line, int32_t startIndex)
{
    //-------------------
    // Local variables:

    int32_t local0;
    wchar_t local1;

    //-------------------
    // Evaluation stacks:

    int32_t __stack0_0;
    System_String* __stack0_1 = NULL;
    int32_t __stack0_2;
    System_String* __stack1_0 = NULL;
    int32_t __stack1_1;
    int32_t __stack1_2;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        System_String** p__stack0_1;
        System_String** p__stack1_0;
    } __executionFrame__;

    __executionFrame__.targetCount = 2;
    __executionFrame__.p__stack0_1 = &__stack0_1;
    __executionFrame__.p__stack1_0 = &__stack1_0;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

#line 96 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\PolishNotation.cs"
    /* Path=1, Unique=0: IL_0000: ldarg.1 */
    __stack0_0 = startIndex;
    /* Path=1, Unique=0: IL_0001: stloc.0 */
    local0 = __stack0_0;
    /* Path=1, Unique=0: IL_0002: br.s IL_001a */
    goto IL_001a;
IL_0004:
#line 99 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\PolishNotation.cs"
    /* Path=3, Unique=0: IL_0004: ldarg.0 */
    __stack0_1 = line;
    /* Path=3, Unique=0: IL_0005: ldloc.0 */
    __stack1_2 = local0;
    /* Path=3, Unique=0: IL_0006: callvirt System.Char System.String::get_Chars(System.Int32) */
    __stack0_2 = System_String_get_Chars(__stack0_1, __stack1_2);
    /* Path=3, Unique=0: IL_000b: stloc.1 */
    local1 = (wchar_t)__stack0_2;
#line 100 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\PolishNotation.cs"
    /* Path=3, Unique=0: IL_000c: ldloc.1 */
    __stack0_0 = local1;
    /* Path=3, Unique=0: IL_000d: ldc.i4.s 32 */
    __stack1_2 = 32;
    /* Path=3, Unique=0: IL_000f: beq.s IL_0016 */
    if (__stack0_0 == __stack1_2) goto IL_0016;
    /* Path=3, Unique=0: IL_0011: ldloc.1 */
    __stack0_0 = local1;
    /* Path=3, Unique=0: IL_0012: ldc.i4.s 9 */
    __stack1_2 = 9;
    /* Path=3, Unique=0: IL_0014: bne.un.s IL_0023 */
    if (__stack0_0 != __stack1_2) goto IL_0023;
IL_0016:
#line 104 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\PolishNotation.cs"
    /* Path=3, Unique=0: IL_0016: ldloc.0 */
    __stack0_0 = local0;
    /* Path=3, Unique=0: IL_0017: ldc.i4.1 */
    __stack1_2 = 1;
    /* Path=3, Unique=0: IL_0018: add */
    __stack0_0 = __stack0_0 + __stack1_2;
    /* Path=3, Unique=0: IL_0019: stloc.0 */
    local0 = __stack0_0;
IL_001a:
#line 97 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\PolishNotation.cs"
    /* Path=2, Unique=0: IL_001a: ldloc.0 */
    __stack0_0 = local0;
    /* Path=2, Unique=0: IL_001b: ldarg.0 */
    __stack1_0 = line;
    /* Path=2, Unique=0: IL_001c: callvirt System.Int32 System.String::get_Length() */
    __stack1_1 = System_String_get_Length(__stack1_0);
    /* Path=2, Unique=0: IL_0021: blt.s IL_0004 */
    if (__stack0_0 < __stack1_1) goto IL_0004;
IL_0023:
#line 107 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\PolishNotation.cs"
    /* Path=2, Unique=0: IL_0023: ldloc.0 */
    __stack0_0 = local0;
    /* Path=2, Unique=0: IL_0024: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return __stack0_0;
}

///////////////////////////////////////
// ParseOperator

Win32_Code_OperatorNode* Win32_Code_PolishNotation_ParseOperator(System_String* line, int32_t startIndex)
{
    //-------------------
    // Local variables:

    int32_t local0;
    wchar_t local1;

    //-------------------
    // Evaluation stacks:

    int32_t __stack0_0;
    IL2C_CecilHelper_PseudoZeroType* __stack0_1 = NULL;
    System_String* __stack0_2 = NULL;
    int32_t __stack0_3;
    Win32_Code_OperatorNode* __stack0_4 = NULL;
    System_String* __stack1_0 = NULL;
    int32_t __stack1_1;
    int32_t __stack1_2;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        IL2C_CecilHelper_PseudoZeroType** p__stack0_1;
        System_String** p__stack0_2;
        Win32_Code_OperatorNode** p__stack0_4;
        System_String** p__stack1_0;
    } __executionFrame__;

    __executionFrame__.targetCount = 4;
    __executionFrame__.p__stack0_1 = &__stack0_1;
    __executionFrame__.p__stack0_2 = &__stack0_2;
    __executionFrame__.p__stack0_4 = &__stack0_4;
    __executionFrame__.p__stack1_0 = &__stack1_0;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

#line 112 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\PolishNotation.cs"
    /* Path=1, Unique=0: IL_0000: ldarg.1 */
    __stack0_0 = startIndex;
    /* Path=1, Unique=0: IL_0001: ldarg.0 */
    __stack1_0 = line;
    /* Path=1, Unique=0: IL_0002: callvirt System.Int32 System.String::get_Length() */
    __stack1_1 = System_String_get_Length(__stack1_0);
    /* Path=1, Unique=0: IL_0007: blt.s IL_000b */
    if (__stack0_0 < __stack1_1) goto IL_000b;
#line 114 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\PolishNotation.cs"
    /* Path=1, Unique=0: IL_0009: ldnull */
    __stack0_1 = NULL;
    /* Path=1, Unique=0: IL_000a: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return (Win32_Code_OperatorNode*)__stack0_1;
IL_000b:
#line 117 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\PolishNotation.cs"
    /* Path=2, Unique=0: IL_000b: ldarg.1 */
    __stack0_0 = startIndex;
    /* Path=2, Unique=0: IL_000c: stloc.0 */
    local0 = __stack0_0;
#line 118 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\PolishNotation.cs"
    /* Path=2, Unique=0: IL_000d: ldarg.0 */
    __stack0_2 = line;
    /* Path=2, Unique=0: IL_000e: ldloc.0 */
    __stack1_2 = local0;
    /* Path=2, Unique=0: IL_000f: callvirt System.Char System.String::get_Chars(System.Int32) */
    __stack0_3 = System_String_get_Chars(__stack0_2, __stack1_2);
    /* Path=2, Unique=0: IL_0014: stloc.1 */
    local1 = (wchar_t)__stack0_3;
#line 119 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\PolishNotation.cs"
    /* Path=2, Unique=0: IL_0015: ldloc.1 */
    __stack0_0 = local1;
    /* Path=2, Unique=0: IL_0016: ldc.i4.s 43 */
    __stack1_2 = 43;
    /* Path=2, Unique=0: IL_0018: beq.s IL_002b */
    if (__stack0_0 == __stack1_2) goto IL_002b;
    /* Path=2, Unique=0: IL_001a: ldloc.1 */
    __stack0_0 = local1;
    /* Path=2, Unique=0: IL_001b: ldc.i4.s 45 */
    __stack1_2 = 45;
    /* Path=2, Unique=0: IL_001d: beq.s IL_002b */
    if (__stack0_0 == __stack1_2) goto IL_002b;
    /* Path=2, Unique=0: IL_001f: ldloc.1 */
    __stack0_0 = local1;
    /* Path=2, Unique=0: IL_0020: ldc.i4.s 42 */
    __stack1_2 = 42;
    /* Path=2, Unique=0: IL_0022: beq.s IL_002b */
    if (__stack0_0 == __stack1_2) goto IL_002b;
    /* Path=2, Unique=0: IL_0024: ldloc.1 */
    __stack0_0 = local1;
    /* Path=2, Unique=0: IL_0025: ldc.i4.s 47 */
    __stack1_2 = 47;
    /* Path=2, Unique=0: IL_0027: beq.s IL_002b */
    if (__stack0_0 == __stack1_2) goto IL_002b;
#line 121 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\PolishNotation.cs"
    /* Path=2, Unique=0: IL_0029: ldnull */
    __stack0_1 = NULL;
    /* Path=2, Unique=0: IL_002a: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return (Win32_Code_OperatorNode*)__stack0_1;
IL_002b:
#line 123 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\PolishNotation.cs"
    /* Path=3, Unique=0: IL_002b: ldloc.0 */
    __stack0_0 = local0;
    /* Path=3, Unique=0: IL_002c: ldc.i4.1 */
    __stack1_2 = 1;
    /* Path=3, Unique=0: IL_002d: add */
    __stack0_0 = __stack0_0 + __stack1_2;
    /* Path=3, Unique=0: IL_002e: stloc.0 */
    local0 = __stack0_0;
#line 125 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\PolishNotation.cs"
    /* Path=3, Unique=0: IL_002f: ldarg.0 */
    __stack0_2 = line;
    /* Path=3, Unique=0: IL_0030: ldloc.0 */
    __stack1_2 = local0;
    /* Path=3, Unique=0: IL_0031: call System.Int32 Win32.Code.PolishNotation::SkipWhiteSpace(System.String,System.Int32) */
    __stack0_0 = Win32_Code_PolishNotation_SkipWhiteSpace(__stack0_2, __stack1_2);
    /* Path=3, Unique=0: IL_0036: stloc.0 */
    local0 = __stack0_0;
#line 126 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\PolishNotation.cs"
    /* Path=3, Unique=0: IL_0037: ldloc.1 */
    __stack0_0 = local1;
    /* Path=3, Unique=0: IL_0038: ldloc.0 */
    __stack1_2 = local0;
    /* Path=3, Unique=0: IL_0039: newobj System.Void Win32.Code.OperatorNode::.ctor(System.Char,System.Int32) */
    __stack0_4 = il2c_get_uninitialized_object(il2c_typeof(Win32_Code_OperatorNode));
    Win32_Code_OperatorNode__ctor(__stack0_4, (wchar_t)__stack0_0, __stack1_2);
    /* Path=3, Unique=0: IL_003e: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return __stack0_4;
}

///////////////////////////////////////
// ParseNumeric

Win32_Code_NumericNode* Win32_Code_PolishNotation_ParseNumeric(System_String* line, int32_t startIndex)
{
    //-------------------
    // Local variables:

    int32_t local0;
    int32_t local1;

    //-------------------
    // Evaluation stacks:

    int32_t __stack0_0;
    IL2C_CecilHelper_PseudoZeroType* __stack0_1 = NULL;
    System_String* __stack0_2 = NULL;
    int32_t __stack0_3;
    System_String* __stack0_4 = NULL;
    Win32_Code_NumericNode* __stack0_5 = NULL;
    System_String* __stack1_0 = NULL;
    int32_t __stack1_1;
    int32_t __stack1_2;
    int32_t* __stack1_3 = NULL;
    int32_t __stack2_0;
    int32_t __stack3_0;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        IL2C_CecilHelper_PseudoZeroType** p__stack0_1;
        System_String** p__stack0_2;
        System_String** p__stack0_4;
        Win32_Code_NumericNode** p__stack0_5;
        System_String** p__stack1_0;
        int32_t** p__stack1_3;
    } __executionFrame__;

    __executionFrame__.targetCount = 6;
    __executionFrame__.p__stack0_1 = &__stack0_1;
    __executionFrame__.p__stack0_2 = &__stack0_2;
    __executionFrame__.p__stack0_4 = &__stack0_4;
    __executionFrame__.p__stack0_5 = &__stack0_5;
    __executionFrame__.p__stack1_0 = &__stack1_0;
    __executionFrame__.p__stack1_3 = &__stack1_3;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

#line 131 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\PolishNotation.cs"
    /* Path=1, Unique=0: IL_0000: ldarg.1 */
    __stack0_0 = startIndex;
    /* Path=1, Unique=0: IL_0001: ldarg.0 */
    __stack1_0 = line;
    /* Path=1, Unique=0: IL_0002: callvirt System.Int32 System.String::get_Length() */
    __stack1_1 = System_String_get_Length(__stack1_0);
    /* Path=1, Unique=0: IL_0007: blt.s IL_000b */
    if (__stack0_0 < __stack1_1) goto IL_000b;
#line 133 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\PolishNotation.cs"
    /* Path=1, Unique=0: IL_0009: ldnull */
    __stack0_1 = NULL;
    /* Path=1, Unique=0: IL_000a: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return (Win32_Code_NumericNode*)__stack0_1;
IL_000b:
#line 136 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\PolishNotation.cs"
    /* Path=2, Unique=0: IL_000b: ldarg.1 */
    __stack0_0 = startIndex;
    /* Path=2, Unique=0: IL_000c: stloc.0 */
    local0 = __stack0_0;
    /* Path=2, Unique=0: IL_000d: br.s IL_001e */
    goto IL_001e;
IL_000f:
#line 139 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\PolishNotation.cs"
    /* Path=4, Unique=0: IL_000f: ldarg.0 */
    __stack0_2 = line;
    /* Path=4, Unique=0: IL_0010: ldloc.0 */
    __stack1_2 = local0;
    /* Path=4, Unique=0: IL_0011: callvirt System.Char System.String::get_Chars(System.Int32) */
    __stack0_3 = System_String_get_Chars(__stack0_2, __stack1_2);
#line 140 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\PolishNotation.cs"
    /* Path=4, Unique=0: IL_0016: ldc.i4.s 32 */
    __stack1_2 = 32;
    /* Path=4, Unique=0: IL_0018: beq.s IL_0027 */
    if (__stack0_3 == __stack1_2) goto IL_0027;
#line 144 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\PolishNotation.cs"
    /* Path=4, Unique=0: IL_001a: ldloc.0 */
    __stack0_0 = local0;
    /* Path=4, Unique=0: IL_001b: ldc.i4.1 */
    __stack1_2 = 1;
    /* Path=4, Unique=0: IL_001c: add */
    __stack0_0 = __stack0_0 + __stack1_2;
    /* Path=4, Unique=0: IL_001d: stloc.0 */
    local0 = __stack0_0;
IL_001e:
#line 137 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\PolishNotation.cs"
    /* Path=3, Unique=0: IL_001e: ldloc.0 */
    __stack0_0 = local0;
    /* Path=3, Unique=0: IL_001f: ldarg.0 */
    __stack1_0 = line;
    /* Path=3, Unique=0: IL_0020: callvirt System.Int32 System.String::get_Length() */
    __stack1_1 = System_String_get_Length(__stack1_0);
    /* Path=3, Unique=0: IL_0025: blt.s IL_000f */
    if (__stack0_0 < __stack1_1) goto IL_000f;
IL_0027:
#line 147 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\PolishNotation.cs"
    /* Path=3, Unique=0: IL_0027: ldloc.0 */
    __stack0_0 = local0;
    /* Path=3, Unique=0: IL_0028: ldarg.1 */
    __stack1_2 = startIndex;
    /* Path=3, Unique=0: IL_0029: bne.un.s IL_002d */
    if (__stack0_0 != __stack1_2) goto IL_002d;
#line 149 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\PolishNotation.cs"
    /* Path=3, Unique=0: IL_002b: ldnull */
    __stack0_1 = NULL;
    /* Path=3, Unique=0: IL_002c: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return (Win32_Code_NumericNode*)__stack0_1;
IL_002d:
#line 152 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\PolishNotation.cs"
    /* Path=5, Unique=0: IL_002d: ldarg.0 */
    __stack0_2 = line;
    /* Path=5, Unique=0: IL_002e: ldarg.1 */
    __stack1_2 = startIndex;
    /* Path=5, Unique=0: IL_002f: ldloc.0 */
    __stack2_0 = local0;
    /* Path=5, Unique=0: IL_0030: ldarg.1 */
    __stack3_0 = startIndex;
    /* Path=5, Unique=0: IL_0031: sub */
    __stack2_0 = __stack2_0 - __stack3_0;
    /* Path=5, Unique=0: IL_0032: callvirt System.String System.String::Substring(System.Int32,System.Int32) */
    __stack0_4 = System_String_Substring_1(__stack0_2, __stack1_2, __stack2_0);
#line 153 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\PolishNotation.cs"
    /* Path=5, Unique=0: IL_0037: ldloca.s local1 */
    __stack1_3 = &local1;
    /* Path=5, Unique=0: IL_0039: call System.Boolean System.Int32::TryParse(System.String,System.Int32&) */
    __stack0_0 = System_Int32_TryParse(__stack0_4, __stack1_3);
    /* Path=5, Unique=0: IL_003e: brtrue.s IL_0042 */
    if (__stack0_0 != 0) goto IL_0042;
#line 155 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\PolishNotation.cs"
    /* Path=5, Unique=0: IL_0040: ldnull */
    __stack0_1 = NULL;
    /* Path=5, Unique=0: IL_0041: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return (Win32_Code_NumericNode*)__stack0_1;
IL_0042:
#line 158 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\PolishNotation.cs"
    /* Path=6, Unique=0: IL_0042: ldarg.0 */
    __stack0_2 = line;
    /* Path=6, Unique=0: IL_0043: ldloc.0 */
    __stack1_2 = local0;
    /* Path=6, Unique=0: IL_0044: call System.Int32 Win32.Code.PolishNotation::SkipWhiteSpace(System.String,System.Int32) */
    __stack0_0 = Win32_Code_PolishNotation_SkipWhiteSpace(__stack0_2, __stack1_2);
    /* Path=6, Unique=0: IL_0049: stloc.0 */
    local0 = __stack0_0;
#line 159 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\PolishNotation.cs"
    /* Path=6, Unique=0: IL_004a: ldloc.1 */
    __stack0_0 = local1;
    /* Path=6, Unique=0: IL_004b: ldloc.0 */
    __stack1_2 = local0;
    /* Path=6, Unique=0: IL_004c: newobj System.Void Win32.Code.NumericNode::.ctor(System.Int32,System.Int32) */
    __stack0_5 = il2c_get_uninitialized_object(il2c_typeof(Win32_Code_NumericNode));
    Win32_Code_NumericNode__ctor(__stack0_5, __stack0_0, __stack1_2);
    /* Path=6, Unique=0: IL_0051: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return __stack0_5;
}

///////////////////////////////////////
// ParseExpression

Win32_Code_ExpressionNode* Win32_Code_PolishNotation_ParseExpression(System_String* line, int32_t startIndex)
{
    //-------------------
    // Local variables:

    Win32_Code_OperatorNode* local0 = NULL;
    Win32_Code_ReducibleNode* local1 = NULL;
    Win32_Code_ReducibleNode* local2 = NULL;
    int32_t local3;

    //-------------------
    // Evaluation stacks:

    int32_t __stack0_0;
    IL2C_CecilHelper_PseudoZeroType* __stack0_1 = NULL;
    System_String* __stack0_2 = NULL;
    Win32_Code_OperatorNode* __stack0_3 = NULL;
    Win32_Code_NumericNode* __stack0_4 = NULL;
    Win32_Code_ReducibleNode* __stack0_5 = NULL;
    Win32_Code_ExpressionNode* __stack0_6 = NULL;
    System_String* __stack1_0 = NULL;
    int32_t __stack1_1;
    int32_t __stack1_2;
    Win32_Code_OperatorNode* __stack1_3 = NULL;
    Win32_Code_ReducibleNode* __stack1_4 = NULL;
    Win32_Code_ReducibleNode* __stack2_0 = NULL;
    int32_t __stack3_0;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        Win32_Code_OperatorNode** plocal0;
        Win32_Code_ReducibleNode** plocal1;
        Win32_Code_ReducibleNode** plocal2;
        IL2C_CecilHelper_PseudoZeroType** p__stack0_1;
        System_String** p__stack0_2;
        Win32_Code_OperatorNode** p__stack0_3;
        Win32_Code_NumericNode** p__stack0_4;
        Win32_Code_ReducibleNode** p__stack0_5;
        Win32_Code_ExpressionNode** p__stack0_6;
        System_String** p__stack1_0;
        Win32_Code_OperatorNode** p__stack1_3;
        Win32_Code_ReducibleNode** p__stack1_4;
        Win32_Code_ReducibleNode** p__stack2_0;
    } __executionFrame__;

    __executionFrame__.targetCount = 13;
    __executionFrame__.plocal0 = &local0;
    __executionFrame__.plocal1 = &local1;
    __executionFrame__.plocal2 = &local2;
    __executionFrame__.p__stack0_1 = &__stack0_1;
    __executionFrame__.p__stack0_2 = &__stack0_2;
    __executionFrame__.p__stack0_3 = &__stack0_3;
    __executionFrame__.p__stack0_4 = &__stack0_4;
    __executionFrame__.p__stack0_5 = &__stack0_5;
    __executionFrame__.p__stack0_6 = &__stack0_6;
    __executionFrame__.p__stack1_0 = &__stack1_0;
    __executionFrame__.p__stack1_3 = &__stack1_3;
    __executionFrame__.p__stack1_4 = &__stack1_4;
    __executionFrame__.p__stack2_0 = &__stack2_0;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

#line 164 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\PolishNotation.cs"
    /* Path=1, Unique=0: IL_0000: ldarg.1 */
    __stack0_0 = startIndex;
    /* Path=1, Unique=0: IL_0001: ldarg.0 */
    __stack1_0 = line;
    /* Path=1, Unique=0: IL_0002: callvirt System.Int32 System.String::get_Length() */
    __stack1_1 = System_String_get_Length(__stack1_0);
    /* Path=1, Unique=0: IL_0007: blt.s IL_000b */
    if (__stack0_0 < __stack1_1) goto IL_000b;
#line 166 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\PolishNotation.cs"
    /* Path=1, Unique=0: IL_0009: ldnull */
    __stack0_1 = NULL;
    /* Path=1, Unique=0: IL_000a: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return (Win32_Code_ExpressionNode*)__stack0_1;
IL_000b:
#line 169 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\PolishNotation.cs"
    /* Path=2, Unique=0: IL_000b: ldarg.0 */
    __stack0_2 = line;
    /* Path=2, Unique=0: IL_000c: ldarg.1 */
    __stack1_2 = startIndex;
    /* Path=2, Unique=0: IL_000d: call Win32.Code.OperatorNode Win32.Code.PolishNotation::ParseOperator(System.String,System.Int32) */
    __stack0_3 = Win32_Code_PolishNotation_ParseOperator(__stack0_2, __stack1_2);
    /* Path=2, Unique=0: IL_0012: stloc.0 */
    local0 = __stack0_3;
#line 170 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\PolishNotation.cs"
    /* Path=2, Unique=0: IL_0013: ldloc.0 */
    __stack0_3 = local0;
    /* Path=2, Unique=0: IL_0014: brtrue.s IL_0018 */
    if (__stack0_3 != NULL) goto IL_0018;
#line 172 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\PolishNotation.cs"
    /* Path=2, Unique=0: IL_0016: ldnull */
    __stack0_1 = NULL;
    /* Path=2, Unique=0: IL_0017: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return (Win32_Code_ExpressionNode*)__stack0_1;
IL_0018:
#line 175 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\PolishNotation.cs"
    /* Path=3, Unique=0: IL_0018: ldarg.0 */
    __stack0_2 = line;
    /* Path=3, Unique=0: IL_0019: ldloc.0 */
    __stack1_3 = local0;
    /* Path=3, Unique=0: IL_001a: ldfld System.Int32 Win32.Code.AbstractNode::NextIndex */
    __stack1_2 = __stack1_3->NextIndex;
    /* Path=3, Unique=0: IL_001f: call Win32.Code.NumericNode Win32.Code.PolishNotation::ParseNumeric(System.String,System.Int32) */
    __stack0_4 = Win32_Code_PolishNotation_ParseNumeric(__stack0_2, __stack1_2);
    /* Path=3, Unique=0: IL_0024: stloc.1 */
    local1 = (Win32_Code_ReducibleNode*)__stack0_4;
#line 176 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\PolishNotation.cs"
    /* Path=3, Unique=0: IL_0025: ldloc.1 */
    __stack0_5 = local1;
    /* Path=3, Unique=0: IL_0026: brtrue.s IL_003a */
    if (__stack0_5 != NULL) goto IL_003a;
#line 178 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\PolishNotation.cs"
    /* Path=3, Unique=0: IL_0028: ldarg.0 */
    __stack0_2 = line;
    /* Path=3, Unique=0: IL_0029: ldloc.0 */
    __stack1_3 = local0;
    /* Path=3, Unique=0: IL_002a: ldfld System.Int32 Win32.Code.AbstractNode::NextIndex */
    __stack1_2 = __stack1_3->NextIndex;
    /* Path=3, Unique=0: IL_002f: call Win32.Code.ExpressionNode Win32.Code.PolishNotation::ParseExpression(System.String,System.Int32) */
    __stack0_6 = Win32_Code_PolishNotation_ParseExpression(__stack0_2, __stack1_2);
    /* Path=3, Unique=0: IL_0034: stloc.1 */
    local1 = (Win32_Code_ReducibleNode*)__stack0_6;
#line 179 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\PolishNotation.cs"
    /* Path=3, Unique=0: IL_0035: ldloc.1 */
    __stack0_5 = local1;
    /* Path=3, Unique=0: IL_0036: brtrue.s IL_003a */
    if (__stack0_5 != NULL) goto IL_003a;
#line 181 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\PolishNotation.cs"
    /* Path=3, Unique=0: IL_0038: ldnull */
    __stack0_1 = NULL;
    /* Path=3, Unique=0: IL_0039: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return (Win32_Code_ExpressionNode*)__stack0_1;
IL_003a:
#line 185 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\PolishNotation.cs"
    /* Path=4, Unique=0: IL_003a: ldarg.0 */
    __stack0_2 = line;
    /* Path=4, Unique=0: IL_003b: ldloc.1 */
    __stack1_4 = local1;
    /* Path=4, Unique=0: IL_003c: ldfld System.Int32 Win32.Code.AbstractNode::NextIndex */
    __stack1_2 = __stack1_4->NextIndex;
    /* Path=4, Unique=0: IL_0041: call Win32.Code.NumericNode Win32.Code.PolishNotation::ParseNumeric(System.String,System.Int32) */
    __stack0_4 = Win32_Code_PolishNotation_ParseNumeric(__stack0_2, __stack1_2);
    /* Path=4, Unique=0: IL_0046: stloc.2 */
    local2 = (Win32_Code_ReducibleNode*)__stack0_4;
#line 186 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\PolishNotation.cs"
    /* Path=4, Unique=0: IL_0047: ldloc.2 */
    __stack0_5 = local2;
    /* Path=4, Unique=0: IL_0048: brtrue.s IL_005c */
    if (__stack0_5 != NULL) goto IL_005c;
#line 188 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\PolishNotation.cs"
    /* Path=4, Unique=0: IL_004a: ldarg.0 */
    __stack0_2 = line;
    /* Path=4, Unique=0: IL_004b: ldloc.1 */
    __stack1_4 = local1;
    /* Path=4, Unique=0: IL_004c: ldfld System.Int32 Win32.Code.AbstractNode::NextIndex */
    __stack1_2 = __stack1_4->NextIndex;
    /* Path=4, Unique=0: IL_0051: call Win32.Code.ExpressionNode Win32.Code.PolishNotation::ParseExpression(System.String,System.Int32) */
    __stack0_6 = Win32_Code_PolishNotation_ParseExpression(__stack0_2, __stack1_2);
    /* Path=4, Unique=0: IL_0056: stloc.2 */
    local2 = (Win32_Code_ReducibleNode*)__stack0_6;
#line 189 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\PolishNotation.cs"
    /* Path=4, Unique=0: IL_0057: ldloc.2 */
    __stack0_5 = local2;
    /* Path=4, Unique=0: IL_0058: brtrue.s IL_005c */
    if (__stack0_5 != NULL) goto IL_005c;
#line 191 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\PolishNotation.cs"
    /* Path=4, Unique=0: IL_005a: ldnull */
    __stack0_1 = NULL;
    /* Path=4, Unique=0: IL_005b: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return (Win32_Code_ExpressionNode*)__stack0_1;
IL_005c:
#line 195 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\PolishNotation.cs"
    /* Path=5, Unique=0: IL_005c: ldarg.0 */
    __stack0_2 = line;
    /* Path=5, Unique=0: IL_005d: ldloc.2 */
    __stack1_4 = local2;
    /* Path=5, Unique=0: IL_005e: ldfld System.Int32 Win32.Code.AbstractNode::NextIndex */
    __stack1_2 = __stack1_4->NextIndex;
    /* Path=5, Unique=0: IL_0063: call System.Int32 Win32.Code.PolishNotation::SkipWhiteSpace(System.String,System.Int32) */
    __stack0_0 = Win32_Code_PolishNotation_SkipWhiteSpace(__stack0_2, __stack1_2);
    /* Path=5, Unique=0: IL_0068: stloc.3 */
    local3 = __stack0_0;
#line 196 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\PolishNotation.cs"
    /* Path=5, Unique=0: IL_0069: ldloc.0 */
    __stack0_3 = local0;
    /* Path=5, Unique=0: IL_006a: ldloc.1 */
    __stack1_4 = local1;
    /* Path=5, Unique=0: IL_006b: ldloc.2 */
    __stack2_0 = local2;
    /* Path=5, Unique=0: IL_006c: ldloc.3 */
    __stack3_0 = local3;
    /* Path=5, Unique=0: IL_006d: newobj System.Void Win32.Code.ExpressionNode::.ctor(Win32.Code.OperatorNode,Win32.Code.ReducibleNode,Win32.Code.ReducibleNode,System.Int32) */
    __stack0_6 = il2c_get_uninitialized_object(il2c_typeof(Win32_Code_ExpressionNode));
    Win32_Code_ExpressionNode__ctor(__stack0_6, __stack0_3, __stack1_4, __stack2_0, __stack3_0);
    /* Path=5, Unique=0: IL_0072: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return __stack0_6;
}

///////////////////////////////////////
// Main

void Win32_Code_PolishNotation_Main(void)
{
    //-------------------
    // Local variables:

    System_String* local0 = NULL;
    Win32_Code_ExpressionNode* local1 = NULL;

    //-------------------
    // Evaluation stacks:

    System_String* __stack0_0 = NULL;
    int32_t __stack0_1;
    Win32_Code_ExpressionNode* __stack0_2 = NULL;
    int32_t __stack1_0;
    System_String* __stack1_1 = NULL;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        System_String** plocal0;
        Win32_Code_ExpressionNode** plocal1;
        System_String** p__stack0_0;
        Win32_Code_ExpressionNode** p__stack0_2;
        System_String** p__stack1_1;
    } __executionFrame__;

    __executionFrame__.targetCount = 5;
    __executionFrame__.plocal0 = &local0;
    __executionFrame__.plocal1 = &local1;
    __executionFrame__.p__stack0_0 = &__stack0_0;
    __executionFrame__.p__stack0_2 = &__stack0_2;
    __executionFrame__.p__stack1_1 = &__stack1_1;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

IL_0000:
#line 203 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\PolishNotation.cs"
    /* Path=1, Unique=0: IL_0000: call System.Void System.Console::WriteLine() */
    System_Console_WriteLine();
#line 204 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\PolishNotation.cs"
    /* Path=1, Unique=0: IL_0005: ldstr "PN> " */
    __stack0_0 = __string0;
    /* Path=1, Unique=0: IL_000a: call System.Void System.Console::Write(System.String) */
    System_Console_Write_9(__stack0_0);
#line 205 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\PolishNotation.cs"
    /* Path=1, Unique=0: IL_000f: call System.String System.Console::ReadLine() */
    __stack0_0 = System_Console_ReadLine();
    /* Path=1, Unique=0: IL_0014: stloc.0 */
    local0 = __stack0_0;
#line 206 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\PolishNotation.cs"
    /* Path=1, Unique=0: IL_0015: ldloc.0 */
    __stack0_0 = local0;
    /* Path=1, Unique=0: IL_0016: call System.Boolean System.String::IsNullOrWhiteSpace(System.String) */
    __stack0_1 = System_String_IsNullOrWhiteSpace(__stack0_0);
    /* Path=1, Unique=0: IL_001b: brtrue.s IL_0000 */
    if (__stack0_1 != 0) goto IL_0000;
#line 208 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\PolishNotation.cs"
    /* Path=1, Unique=0: IL_001d: ldloc.0 */
    __stack0_0 = local0;
    /* Path=1, Unique=0: IL_001e: ldc.i4.0 */
    __stack1_0 = 0;
    /* Path=1, Unique=0: IL_001f: call Win32.Code.ExpressionNode Win32.Code.PolishNotation::ParseExpression(System.String,System.Int32) */
    __stack0_2 = Win32_Code_PolishNotation_ParseExpression(__stack0_0, __stack1_0);
    /* Path=1, Unique=0: IL_0024: stloc.1 */
    local1 = __stack0_2;
#line 209 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\PolishNotation.cs"
    /* Path=1, Unique=0: IL_0025: ldloc.1 */
    __stack0_2 = local1;
    /* Path=1, Unique=0: IL_0026: brtrue.s IL_0034 */
    if (__stack0_2 != NULL) goto IL_0034;
#line 211 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\PolishNotation.cs"
    /* Path=1, Unique=0: IL_0028: ldstr "Syntax error." */
    __stack0_0 = __string1;
    /* Path=1, Unique=0: IL_002d: call System.Void System.Console::WriteLine(System.String) */
    System_Console_WriteLine_10(__stack0_0);
#line 212 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\PolishNotation.cs"
    /* Path=1, Unique=0: IL_0032: br.s IL_0000 */
    goto IL_0000;
IL_0034:
#line 215 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\PolishNotation.cs"
    /* Path=2, Unique=0: IL_0034: ldloc.1 */
    __stack0_2 = local1;
    /* Path=2, Unique=0: IL_0035: callvirt System.Int32 Win32.Code.ReducibleNode::Reduce() */
    __stack0_1 = Win32_Code_ReducibleNode_Reduce((Win32_Code_ReducibleNode*)__stack0_2);
#line 217 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\PolishNotation.cs"
    /* Path=2, Unique=0: IL_003a: ldstr "Reuslt=" */
    __stack1_1 = __string2;
    /* Path=2, Unique=0: IL_003f: call System.Void System.Console::Write(System.String) */
    System_Console_Write_9(__stack1_1);
#line 218 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\PolishNotation.cs"
    /* Path=2, Unique=0: IL_0044: call System.Void System.Console::WriteLine(System.Int32) */
    System_Console_WriteLine_6(__stack0_1);
#line 201 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\PolishNotation.cs"
    /* Path=2, Unique=0: IL_0049: br.s IL_0000 */
    goto IL_0000;
}

///////////////////////////////////////
// .ctor

void Win32_Code_PolishNotation__ctor(Win32_Code_PolishNotation* this__)
{
    //-------------------
    // Local variables:


    //-------------------
    // Evaluation stacks:

    Win32_Code_PolishNotation* __stack0_0 = NULL;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        Win32_Code_PolishNotation** p__stack0_0;
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

static void __Win32_Code_PolishNotation_MARK_HANDLER__(void* pReference)
{
    il2c_typeof(System_Object)->pMarkHandler(pReference);
}

static __Win32_Code_PolishNotation_TYPE_DEF_TYPE__ __Win32_Code_PolishNotation_RUNTIME_TYPE_DEF__ = {
    (intptr_t)"Win32.Code.PolishNotation",
    (intptr_t)0,
    (intptr_t)__Win32_Code_PolishNotation_MARK_HANDLER__,
    __System_Object_ToString__,
    __System_Object_GetHashCode__,
    __System_Object_Finalize__,
    __System_Object_Equals__,
};
const IL2C_RUNTIME_TYPE __Win32_Code_PolishNotation_RUNTIME_TYPE__ =
   (const IL2C_RUNTIME_TYPE)(&__Win32_Code_PolishNotation_RUNTIME_TYPE_DEF__);

////////////////////////////////////////////////////////////
// Type: Win32.Code.StringTest

///////////////////////////////////////
// LiteralString

void Win32_Code_StringTest_LiteralString(void)
{
    //-------------------
    // Local variables:


    //-------------------
    // Evaluation stacks:


    //-------------------
    // IL body:

#line 14 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\StringTest.cs"
    /* Path=1, Unique=0: IL_0000: ret */
    return;
}

///////////////////////////////////////
// InOutString

System_String* Win32_Code_StringTest_InOutString(System_String* a)
{
    //-------------------
    // Local variables:


    //-------------------
    // Evaluation stacks:

    System_String* __stack0_0 = NULL;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        System_String** p__stack0_0;
    } __executionFrame__;

    __executionFrame__.targetCount = 1;
    __executionFrame__.p__stack0_0 = &__stack0_0;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

#line 18 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\StringTest.cs"
    /* Path=1, Unique=0: IL_0000: ldarg.0 */
    __stack0_0 = a;
    /* Path=1, Unique=0: IL_0001: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return __stack0_0;
}

///////////////////////////////////////
// LiteralCombinedString

System_String* Win32_Code_StringTest_LiteralCombinedString(void)
{
    //-------------------
    // Local variables:

    System_String* local0 = NULL;

    //-------------------
    // Evaluation stacks:

    System_String* __stack0_0 = NULL;
    System_String* __stack1_0 = NULL;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        System_String** plocal0;
        System_String** p__stack0_0;
        System_String** p__stack1_0;
    } __executionFrame__;

    __executionFrame__.targetCount = 3;
    __executionFrame__.plocal0 = &local0;
    __executionFrame__.p__stack0_0 = &__stack0_0;
    __executionFrame__.p__stack1_0 = &__stack1_0;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

#line 23 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\StringTest.cs"
    /* Path=1, Unique=0: IL_0000: ldstr "ABC" */
    __stack0_0 = __string3;
#line 24 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\StringTest.cs"
    /* Path=1, Unique=0: IL_0005: ldstr "DEF" */
    __stack1_0 = __string4;
    /* Path=1, Unique=0: IL_000a: stloc.0 */
    local0 = __stack1_0;
#line 25 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\StringTest.cs"
    /* Path=1, Unique=0: IL_000b: ldloc.0 */
    __stack1_0 = local0;
    /* Path=1, Unique=0: IL_000c: call System.String System.String::Concat(System.String,System.String) */
    __stack0_0 = System_String_Concat_6(__stack0_0, __stack1_0);
    /* Path=1, Unique=0: IL_0011: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return __stack0_0;
}

///////////////////////////////////////
// LiteralSubstring

System_String* Win32_Code_StringTest_LiteralSubstring(void)
{
    //-------------------
    // Local variables:


    //-------------------
    // Evaluation stacks:

    System_String* __stack0_0 = NULL;
    System_String* __stack0_1 = NULL;
    int32_t __stack1_0;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        System_String** p__stack0_0;
        System_String** p__stack0_1;
    } __executionFrame__;

    __executionFrame__.targetCount = 2;
    __executionFrame__.p__stack0_0 = &__stack0_0;
    __executionFrame__.p__stack0_1 = &__stack0_1;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

#line 30 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\StringTest.cs"
    /* Path=1, Unique=0: IL_0000: ldstr "ABCDEFGHIJKLMN" */
    __stack0_0 = __string5;
#line 31 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\StringTest.cs"
    /* Path=1, Unique=0: IL_0005: ldc.i4.3 */
    __stack1_0 = 3;
    /* Path=1, Unique=0: IL_0006: callvirt System.String System.String::Substring(System.Int32) */
    __stack0_1 = System_String_Substring(__stack0_0, __stack1_0);
    /* Path=1, Unique=0: IL_000b: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return __stack0_1;
}

///////////////////////////////////////
// GetChar

wchar_t Win32_Code_StringTest_GetChar(void)
{
    //-------------------
    // Local variables:


    //-------------------
    // Evaluation stacks:

    int32_t __stack0_0;

    //-------------------
    // IL body:

#line 36 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\StringTest.cs"
    /* Path=1, Unique=0: IL_0000: ldc.i4.s 65 */
    __stack0_0 = 65;
    /* Path=1, Unique=0: IL_0002: ret */
    return (wchar_t)__stack0_0;
}

///////////////////////////////////////
// GetCharByIndex

wchar_t Win32_Code_StringTest_GetCharByIndex(System_String* str, int32_t index)
{
    //-------------------
    // Local variables:


    //-------------------
    // Evaluation stacks:

    System_String* __stack0_0 = NULL;
    int32_t __stack0_1;
    int32_t __stack1_0;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        System_String** p__stack0_0;
    } __executionFrame__;

    __executionFrame__.targetCount = 1;
    __executionFrame__.p__stack0_0 = &__stack0_0;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

#line 41 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\StringTest.cs"
    /* Path=1, Unique=0: IL_0000: ldarg.0 */
    __stack0_0 = str;
    /* Path=1, Unique=0: IL_0001: ldarg.1 */
    __stack1_0 = index;
    /* Path=1, Unique=0: IL_0002: callvirt System.Char System.String::get_Chars(System.Int32) */
    __stack0_1 = System_String_get_Chars(__stack0_0, __stack1_0);
    /* Path=1, Unique=0: IL_0007: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return (wchar_t)__stack0_1;
}

///////////////////////////////////////
// .ctor

void Win32_Code_StringTest__ctor(Win32_Code_StringTest* this__)
{
    //-------------------
    // Local variables:


    //-------------------
    // Evaluation stacks:

    Win32_Code_StringTest* __stack0_0 = NULL;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        Win32_Code_StringTest** p__stack0_0;
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

static void __Win32_Code_StringTest_MARK_HANDLER__(void* pReference)
{
    il2c_typeof(System_Object)->pMarkHandler(pReference);
}

static __Win32_Code_StringTest_TYPE_DEF_TYPE__ __Win32_Code_StringTest_RUNTIME_TYPE_DEF__ = {
    (intptr_t)"Win32.Code.StringTest",
    (intptr_t)0,
    (intptr_t)__Win32_Code_StringTest_MARK_HANDLER__,
    __System_Object_ToString__,
    __System_Object_GetHashCode__,
    __System_Object_Finalize__,
    __System_Object_Equals__,
};
const IL2C_RUNTIME_TYPE __Win32_Code_StringTest_RUNTIME_TYPE__ =
   (const IL2C_RUNTIME_TYPE)(&__Win32_Code_StringTest_RUNTIME_TYPE_DEF__);

////////////////////////////////////////////////////////////
// Type: Win32.Code.UnsafeTest

///////////////////////////////////////
// .ctor

void Win32_Code_UnsafeTest__ctor(Win32_Code_UnsafeTest* this__)
{
    //-------------------
    // Local variables:


    //-------------------
    // Evaluation stacks:

    Win32_Code_UnsafeTest* __stack0_0 = NULL;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        Win32_Code_UnsafeTest** p__stack0_0;
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

static void __Win32_Code_UnsafeTest_MARK_HANDLER__(void* pReference)
{
    il2c_typeof(System_Object)->pMarkHandler(pReference);
}

static __Win32_Code_UnsafeTest_TYPE_DEF_TYPE__ __Win32_Code_UnsafeTest_RUNTIME_TYPE_DEF__ = {
    (intptr_t)"Win32.Code.UnsafeTest",
    (intptr_t)0,
    (intptr_t)__Win32_Code_UnsafeTest_MARK_HANDLER__,
    __System_Object_ToString__,
    __System_Object_GetHashCode__,
    __System_Object_Finalize__,
    __System_Object_Equals__,
};
const IL2C_RUNTIME_TYPE __Win32_Code_UnsafeTest_RUNTIME_TYPE__ =
   (const IL2C_RUNTIME_TYPE)(&__Win32_Code_UnsafeTest_RUNTIME_TYPE_DEF__);

////////////////////////////////////////////////////////////
// Type: Win32.Code.ValueTypeTestTarget

///////////////////////////////////////
// GetValue2

int32_t Win32_Code_ValueTypeTestTarget_GetValue2(Win32_Code_ValueTypeTestTarget* this__, int32_t a, int32_t b)
{
    //-------------------
    // Local variables:


    //-------------------
    // Evaluation stacks:

    Win32_Code_ValueTypeTestTarget* __stack0_0 = NULL;
    int32_t __stack0_1;
    int32_t __stack1_0;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        Win32_Code_ValueTypeTestTarget** p__stack0_0;
    } __executionFrame__;

    __executionFrame__.targetCount = 1;
    __executionFrame__.p__stack0_0 = &__stack0_0;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

#line 16 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\ValueTypeTest.cs"
    /* Path=1, Unique=0: IL_0000: ldarg.0 */
    __stack0_0 = this__;
    /* Path=1, Unique=0: IL_0001: ldfld System.Int32 Win32.Code.ValueTypeTestTarget::Value2 */
    __stack0_1 = __stack0_0->Value2;
    /* Path=1, Unique=0: IL_0006: ldarg.1 */
    __stack1_0 = a;
    /* Path=1, Unique=0: IL_0007: add */
    __stack0_1 = __stack0_1 + __stack1_0;
    /* Path=1, Unique=0: IL_0008: ldarg.2 */
    __stack1_0 = b;
    /* Path=1, Unique=0: IL_0009: add */
    __stack0_1 = __stack0_1 + __stack1_0;
    /* Path=1, Unique=0: IL_000a: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return __stack0_1;
}

//////////////////////
// Runtime helpers:

static void __Win32_Code_ValueTypeTestTarget_MARK_HANDLER__(void* pReference)
{
    il2c_try_mark_from_handler(((Win32_Code_ValueTypeTestTarget*)pReference)->OR2);
    il2c_typeof(System_ValueType)->pMarkHandler(pReference);
}

static __Win32_Code_ValueTypeTestTarget_TYPE_DEF_TYPE__ __Win32_Code_ValueTypeTestTarget_RUNTIME_TYPE_DEF__ = {
    (intptr_t)"Win32.Code.ValueTypeTestTarget",
    (intptr_t)sizeof(Win32_Code_ValueTypeTestTarget),
    (intptr_t)__Win32_Code_ValueTypeTestTarget_MARK_HANDLER__,
    __System_ValueType_ToString__,
    __System_ValueType_GetHashCode__,
    __System_Object_Finalize__,
    __System_ValueType_Equals__,
};
const IL2C_RUNTIME_TYPE __Win32_Code_ValueTypeTestTarget_RUNTIME_TYPE__ =
   (const IL2C_RUNTIME_TYPE)(&__Win32_Code_ValueTypeTestTarget_RUNTIME_TYPE_DEF__);

////////////////////////////////////////////////////////////
// Type: Win32.Code.ValueTypeTest

///////////////////////////////////////
// Test4

int32_t Win32_Code_ValueTypeTest_Test4(void)
{
    //-------------------
    // Local variables:

    Win32_Code_ValueTypeTestTarget local0;

    //-------------------
    // Evaluation stacks:

    Win32_Code_ValueTypeTestTarget* __stack0_0 = NULL;
    Win32_Code_ValueTypeTestTarget* __stack0_1 = NULL;
    Win32_Code_ValueTypeTestTarget __stack0_2;
    int32_t __stack0_3;
    int32_t __stack1_0;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        Win32_Code_ValueTypeTestTarget** p__stack0_0;
        Win32_Code_ValueTypeTestTarget** p__stack0_1;
    } __executionFrame__;

    __executionFrame__.targetCount = 2;
    __executionFrame__.p__stack0_0 = &__stack0_0;
    __executionFrame__.p__stack0_1 = &__stack0_1;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

#line 24 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\ValueTypeTest.cs"
    /* Path=1, Unique=0: IL_0000: ldloca.s local0 */
    __stack0_0 = &local0;
    /* Path=1, Unique=0: IL_0002: initobj Win32.Code.ValueTypeTestTarget */
    memset(__stack0_0, 0x00, sizeof(Win32_Code_ValueTypeTestTarget));
#line 25 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\ValueTypeTest.cs"
    /* Path=1, Unique=0: IL_0008: ldloca.s local0 */
    __stack0_1 = &local0;
    /* Path=1, Unique=0: IL_000a: ldc.i4 456 */
    __stack1_0 = 456;
    /* Path=1, Unique=0: IL_000f: stfld System.Int32 Win32.Code.ValueTypeTestTarget::Value2 */
    __stack0_1->Value2 = __stack1_0;
#line 27 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\ValueTypeTest.cs"
    /* Path=1, Unique=0: IL_0014: ldloc.0 */
    __stack0_2 = local0;
    /* Path=1, Unique=0: IL_0015: ldfld System.Int32 Win32.Code.ValueTypeTestTarget::Value2 */
    __stack0_3 = __stack0_2.Value2;
    /* Path=1, Unique=0: IL_001a: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return __stack0_3;
}

///////////////////////////////////////
// Test5

int32_t Win32_Code_ValueTypeTest_Test5(void)
{
    //-------------------
    // Local variables:

    Win32_Code_ValueTypeTestTarget local0;

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

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        Win32_Code_ValueTypeTestTarget** p__stack0_0;
        Win32_Code_ValueTypeTestTarget** p__stack0_1;
        Win32_Code_ValueTypeTestTarget** p__stack0_2;
    } __executionFrame__;

    __executionFrame__.targetCount = 3;
    __executionFrame__.p__stack0_0 = &__stack0_0;
    __executionFrame__.p__stack0_1 = &__stack0_1;
    __executionFrame__.p__stack0_2 = &__stack0_2;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

#line 32 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\ValueTypeTest.cs"
    /* Path=1, Unique=0: IL_0000: ldloca.s local0 */
    __stack0_0 = &local0;
    /* Path=1, Unique=0: IL_0002: initobj Win32.Code.ValueTypeTestTarget */
    memset(__stack0_0, 0x00, sizeof(Win32_Code_ValueTypeTestTarget));
#line 33 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\ValueTypeTest.cs"
    /* Path=1, Unique=0: IL_0008: ldloca.s local0 */
    __stack0_1 = &local0;
    /* Path=1, Unique=0: IL_000a: ldc.i4 789 */
    __stack1_0 = 789;
    /* Path=1, Unique=0: IL_000f: stfld System.Int32 Win32.Code.ValueTypeTestTarget::Value2 */
    __stack0_1->Value2 = __stack1_0;
#line 35 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\ValueTypeTest.cs"
    /* Path=1, Unique=0: IL_0014: ldloca.s local0 */
    __stack0_2 = &local0;
    /* Path=1, Unique=0: IL_0016: ldc.i4.s 123 */
    __stack1_0 = 123;
    /* Path=1, Unique=0: IL_0018: ldc.i4 456 */
    __stack2_0 = 456;
    /* Path=1, Unique=0: IL_001d: call System.Int32 Win32.Code.ValueTypeTestTarget::GetValue2(System.Int32,System.Int32) */
    __stack0_3 = Win32_Code_ValueTypeTestTarget_GetValue2(__stack0_2, __stack1_0, __stack2_0);
#line 36 "D:\\PROJECT\\IL2C\\tests\\Win32\\Win32.Code\\ValueTypeTest.cs"
    /* Path=1, Unique=0: IL_0022: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return __stack0_3;
}

///////////////////////////////////////
// .ctor

void Win32_Code_ValueTypeTest__ctor(Win32_Code_ValueTypeTest* this__)
{
    //-------------------
    // Local variables:


    //-------------------
    // Evaluation stacks:

    Win32_Code_ValueTypeTest* __stack0_0 = NULL;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        Win32_Code_ValueTypeTest** p__stack0_0;
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

static void __Win32_Code_ValueTypeTest_MARK_HANDLER__(void* pReference)
{
    il2c_typeof(System_Object)->pMarkHandler(pReference);
}

static __Win32_Code_ValueTypeTest_TYPE_DEF_TYPE__ __Win32_Code_ValueTypeTest_RUNTIME_TYPE_DEF__ = {
    (intptr_t)"Win32.Code.ValueTypeTest",
    (intptr_t)0,
    (intptr_t)__Win32_Code_ValueTypeTest_MARK_HANDLER__,
    __System_Object_ToString__,
    __System_Object_GetHashCode__,
    __System_Object_Finalize__,
    __System_Object_Equals__,
};
const IL2C_RUNTIME_TYPE __Win32_Code_ValueTypeTest_RUNTIME_TYPE__ =
   (const IL2C_RUNTIME_TYPE)(&__Win32_Code_ValueTypeTest_RUNTIME_TYPE_DEF__);
