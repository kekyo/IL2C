#include <windows.h>
#include "Win32.Code.h"

//////////////////////////////////////////////////////////////////////////////////
// Const strings:

IL2C_CONST_STRING(__string0, L"PN> ");
IL2C_CONST_STRING(__string1, L"exit");
IL2C_CONST_STRING(__string2, L"Syntax error.");
IL2C_CONST_STRING(__string3, L"Reuslt=");
IL2C_CONST_STRING(__string4, L"ABC");
IL2C_CONST_STRING(__string5, L"DEF");
IL2C_CONST_STRING(__string6, L"ABCDEFGHIJKLMN");

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

    System_Object* local0 = NULL;
    int32_t local1;

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
        System_Object** plocal0;
        System_Object** p__stack0_1;
    } __executionFrame__;

    __executionFrame__.targetCount = 2;
    __executionFrame__.plocal0 = &local0;
    __executionFrame__.p__stack0_1 = &__stack0_1;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\BoxingTest.cs(13): */
    /* Path=1, Unique=0: IL_0000: nop */
    /* Path=1, Unique=0: IL_0001: ldarg.0 */
    __stack0_0 = a;
    /* Path=1, Unique=0: IL_0002: box System.Int32 */
    __stack0_1 = il2c_box(&__stack0_0, il2c_typeof(System_Int32));
    /* Path=1, Unique=0: IL_0007: stloc.0 */
    local0 = __stack0_1;
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\BoxingTest.cs(16): */
    /* Path=1, Unique=0: IL_0008: ldloc.0 */
    __stack0_1 = local0;
    /* Path=1, Unique=0: IL_0009: unbox.any System.Int32 */
    __stack0_2 = *((int32_t*)il2c_unbox(__stack0_1, il2c_typeof(System_Int32)));
    /* Path=1, Unique=0: IL_000e: stloc.1 */
    local1 = __stack0_2;
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\BoxingTest.cs(17): */
    /* Path=1, Unique=0: IL_000f: ret */
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
    /* Path=1, Unique=0: IL_0006: nop */
    /* Path=1, Unique=0: IL_0007: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return;
}

//////////////////////
// Runtime helpers:

void* __Win32_Code_BoxingTest_IL2C_RuntimeCast__(Win32_Code_BoxingTest* this__, IL2C_RUNTIME_TYPE_DECL* type)
{
    if (type == il2c_typeof(System_Object)) return this__;
    return __System_Object_IL2C_RuntimeCast__((System_Object*)this__, type);
}

static void __Win32_Code_BoxingTest_MARK_HANDLER__(void* pReference)
{
    il2c_typeof(System_Object)->pMarkHandler(pReference);
}

static __Win32_Code_BoxingTest_VTABLE_DECL__ __Win32_Code_BoxingTest_VTABLE__ = {
    __Win32_Code_BoxingTest_IL2C_RuntimeCast__,
    (void*)__System_Object_ToString__,
    (void*)__System_Object_GetHashCode__,
    (void*)__System_Object_Finalize__,
    (void*)__System_Object_Equals__,
};

IL2C_RUNTIME_TYPE_DECL __Win32_Code_BoxingTest_RUNTIME_TYPE__ = {
    "Win32.Code.BoxingTest",
    sizeof(Win32_Code_BoxingTest),
    __Win32_Code_BoxingTest_MARK_HANDLER__,
};

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

/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\ClassTypeTest.cs(16): */
    /* Path=1, Unique=0: IL_0000: ldarg.0 */
    __stack0_0 = this__;
    /* Path=1, Unique=0: IL_0001: call System.Void System.Object::.ctor() */
    System_Object__ctor((System_Object*)__stack0_0);
    /* Path=1, Unique=0: IL_0006: nop */
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\ClassTypeTest.cs(17): */
    /* Path=1, Unique=0: IL_0007: nop */
    /* Path=1, Unique=0: IL_0008: ret */
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

/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\ClassTypeTest.cs(20): */
    /* Path=1, Unique=0: IL_0000: ldarg.0 */
    __stack0_0 = this__;
    /* Path=1, Unique=0: IL_0001: call System.Void System.Object::.ctor() */
    System_Object__ctor((System_Object*)__stack0_0);
    /* Path=1, Unique=0: IL_0006: nop */
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\ClassTypeTest.cs(21): */
    /* Path=1, Unique=0: IL_0007: nop */
    /* Path=1, Unique=0: IL_0008: ldarg.0 */
    __stack0_0 = this__;
    /* Path=1, Unique=0: IL_0009: ldarg.1 */
    __stack1_0 = value;
    /* Path=1, Unique=0: IL_000a: stfld System.Int32 Win32.Code.ClassTypeTestTarget::Value2 */
    __stack0_0->Value2 = __stack1_0;
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\ClassTypeTest.cs(23): */
    /* Path=1, Unique=0: IL_000f: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return;
}

///////////////////////////////////////
// GetValue2

int32_t Win32_Code_ClassTypeTestTarget_GetValue2(Win32_Code_ClassTypeTestTarget* this__, int32_t a, int32_t b)
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

/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\ClassTypeTest.cs(26): */
    /* Path=1, Unique=0: IL_0000: nop */
    /* Path=1, Unique=0: IL_0001: ldarg.0 */
    __stack0_0 = this__;
    /* Path=1, Unique=0: IL_0002: ldfld System.Int32 Win32.Code.ClassTypeTestTarget::Value2 */
    __stack0_1 = __stack0_0->Value2;
    /* Path=1, Unique=0: IL_0007: ldarg.1 */
    __stack1_0 = a;
    /* Path=1, Unique=0: IL_0008: add */
    __stack0_1 = __stack0_1 + __stack1_0;
    /* Path=1, Unique=0: IL_0009: ldarg.2 */
    __stack1_0 = b;
    /* Path=1, Unique=0: IL_000a: add */
    __stack0_1 = __stack0_1 + __stack1_0;
    /* Path=1, Unique=0: IL_000b: stloc.0 */
    local0 = __stack0_1;
    /* Path=1, Unique=0: IL_000c: br.s IL_000e */
    goto IL_000e;
IL_000e:
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\ClassTypeTest.cs(28): */
    /* Path=2, Unique=0: IL_000e: ldloc.0 */
    __stack0_1 = local0;
    /* Path=2, Unique=0: IL_000f: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return __stack0_1;
}

///////////////////////////////////////
// GetValue2

int32_t Win32_Code_ClassTypeTestTarget_GetValue2_1(Win32_Code_ClassTypeTestTarget* this__, int32_t a, int32_t b, int32_t c)
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

/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\ClassTypeTest.cs(31): */
    /* Path=1, Unique=0: IL_0000: nop */
    /* Path=1, Unique=0: IL_0001: ldarg.0 */
    __stack0_0 = this__;
    /* Path=1, Unique=0: IL_0002: ldfld System.Int32 Win32.Code.ClassTypeTestTarget::Value2 */
    __stack0_1 = __stack0_0->Value2;
    /* Path=1, Unique=0: IL_0007: ldarg.1 */
    __stack1_0 = a;
    /* Path=1, Unique=0: IL_0008: add */
    __stack0_1 = __stack0_1 + __stack1_0;
    /* Path=1, Unique=0: IL_0009: ldarg.2 */
    __stack1_0 = b;
    /* Path=1, Unique=0: IL_000a: add */
    __stack0_1 = __stack0_1 + __stack1_0;
    /* Path=1, Unique=0: IL_000b: ldarg.3 */
    __stack1_0 = c;
    /* Path=1, Unique=0: IL_000c: add */
    __stack0_1 = __stack0_1 + __stack1_0;
    /* Path=1, Unique=0: IL_000d: stloc.0 */
    local0 = __stack0_1;
    /* Path=1, Unique=0: IL_000e: br.s IL_0010 */
    goto IL_0010;
IL_0010:
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\ClassTypeTest.cs(33): */
    /* Path=2, Unique=0: IL_0010: ldloc.0 */
    __stack0_1 = local0;
    /* Path=2, Unique=0: IL_0011: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return __stack0_1;
}

//////////////////////
// Runtime helpers:

void* __Win32_Code_ClassTypeTestTarget_IL2C_RuntimeCast__(Win32_Code_ClassTypeTestTarget* this__, IL2C_RUNTIME_TYPE_DECL* type)
{
    if (type == il2c_typeof(System_Object)) return this__;
    return __System_Object_IL2C_RuntimeCast__((System_Object*)this__, type);
}

static void __Win32_Code_ClassTypeTestTarget_MARK_HANDLER__(void* pReference)
{
    il2c_try_mark_from_handler(((Win32_Code_ClassTypeTestTarget*)pReference)->OR2);
    il2c_typeof(System_Object)->pMarkHandler(pReference);
}

static __Win32_Code_ClassTypeTestTarget_VTABLE_DECL__ __Win32_Code_ClassTypeTestTarget_VTABLE__ = {
    __Win32_Code_ClassTypeTestTarget_IL2C_RuntimeCast__,
    (void*)__System_Object_ToString__,
    (void*)__System_Object_GetHashCode__,
    (void*)__System_Object_Finalize__,
    (void*)__System_Object_Equals__,
};

IL2C_RUNTIME_TYPE_DECL __Win32_Code_ClassTypeTestTarget_RUNTIME_TYPE__ = {
    "Win32.Code.ClassTypeTestTarget",
    sizeof(Win32_Code_ClassTypeTestTarget),
    __Win32_Code_ClassTypeTestTarget_MARK_HANDLER__,
};

////////////////////////////////////////////////////////////
// Type: Win32.Code.ClassTypeTest

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

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        Win32_Code_ClassTypeTestTarget** plocal0;
        Win32_Code_ClassTypeTestTarget** p__stack0_0;
    } __executionFrame__;

    __executionFrame__.targetCount = 2;
    __executionFrame__.plocal0 = &local0;
    __executionFrame__.p__stack0_0 = &__stack0_0;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\ClassTypeTest.cs(39): */
    /* Path=1, Unique=0: IL_0000: nop */
    /* Path=1, Unique=0: IL_0001: newobj System.Void Win32.Code.ClassTypeTestTarget::.ctor() */
    __stack0_0 = il2c_get_uninitialized_object(il2c_typeof(Win32_Code_ClassTypeTestTarget));
    Win32_Code_ClassTypeTestTarget__ctor(__stack0_0);
    /* Path=1, Unique=0: IL_0006: stloc.0 */
    local0 = __stack0_0;
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\ClassTypeTest.cs(41): */
    /* Path=1, Unique=0: IL_0007: ldloc.0 */
    __stack0_0 = local0;
    /* Path=1, Unique=0: IL_0008: ldc.i4 456 */
    __stack1_0 = 456;
    /* Path=1, Unique=0: IL_000d: stfld System.Int32 Win32.Code.ClassTypeTestTarget::Value2 */
    __stack0_0->Value2 = __stack1_0;
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\ClassTypeTest.cs(43): */
    /* Path=1, Unique=0: IL_0012: ldloc.0 */
    __stack0_0 = local0;
    /* Path=1, Unique=0: IL_0013: ldfld System.Int32 Win32.Code.ClassTypeTestTarget::Value2 */
    __stack0_1 = __stack0_0->Value2;
    /* Path=1, Unique=0: IL_0018: stloc.1 */
    local1 = __stack0_1;
    /* Path=1, Unique=0: IL_0019: br.s IL_001b */
    goto IL_001b;
IL_001b:
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\ClassTypeTest.cs(44): */
    /* Path=2, Unique=0: IL_001b: ldloc.1 */
    __stack0_1 = local1;
    /* Path=2, Unique=0: IL_001c: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
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

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        Win32_Code_ClassTypeTestTarget** plocal0;
        Win32_Code_ClassTypeTestTarget** p__stack0_0;
    } __executionFrame__;

    __executionFrame__.targetCount = 2;
    __executionFrame__.plocal0 = &local0;
    __executionFrame__.p__stack0_0 = &__stack0_0;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\ClassTypeTest.cs(47): */
    /* Path=1, Unique=0: IL_0000: nop */
    /* Path=1, Unique=0: IL_0001: newobj System.Void Win32.Code.ClassTypeTestTarget::.ctor() */
    __stack0_0 = il2c_get_uninitialized_object(il2c_typeof(Win32_Code_ClassTypeTestTarget));
    Win32_Code_ClassTypeTestTarget__ctor(__stack0_0);
    /* Path=1, Unique=0: IL_0006: stloc.0 */
    local0 = __stack0_0;
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\ClassTypeTest.cs(49): */
    /* Path=1, Unique=0: IL_0007: ldloc.0 */
    __stack0_0 = local0;
    /* Path=1, Unique=0: IL_0008: ldc.i4 789 */
    __stack1_0 = 789;
    /* Path=1, Unique=0: IL_000d: stfld System.Int32 Win32.Code.ClassTypeTestTarget::Value2 */
    __stack0_0->Value2 = __stack1_0;
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\ClassTypeTest.cs(51): */
    /* Path=1, Unique=0: IL_0012: ldloc.0 */
    __stack0_0 = local0;
    /* Path=1, Unique=0: IL_0013: ldc.i4.s 123 */
    __stack1_0 = 123;
    /* Path=1, Unique=0: IL_0015: ldc.i4 456 */
    __stack2_0 = 456;
    /* Path=1, Unique=0: IL_001a: callvirt System.Int32 Win32.Code.ClassTypeTestTarget::GetValue2(System.Int32,System.Int32) */
    __stack0_1 = Win32_Code_ClassTypeTestTarget_GetValue2(__stack0_0, __stack1_0, __stack2_0);
    /* Path=1, Unique=0: IL_001f: stloc.1 */
    local1 = __stack0_1;
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\ClassTypeTest.cs(52): */
    /* Path=1, Unique=0: IL_0020: ldloc.1 */
    __stack0_1 = local1;
    /* Path=1, Unique=0: IL_0021: stloc.2 */
    local2 = __stack0_1;
    /* Path=1, Unique=0: IL_0022: br.s IL_0024 */
    goto IL_0024;
IL_0024:
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\ClassTypeTest.cs(53): */
    /* Path=2, Unique=0: IL_0024: ldloc.2 */
    __stack0_1 = local2;
    /* Path=2, Unique=0: IL_0025: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
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

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        Win32_Code_ClassTypeTestTarget** plocal0;
        Win32_Code_ClassTypeTestTarget** p__stack0_0;
    } __executionFrame__;

    __executionFrame__.targetCount = 2;
    __executionFrame__.plocal0 = &local0;
    __executionFrame__.p__stack0_0 = &__stack0_0;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\ClassTypeTest.cs(56): */
    /* Path=1, Unique=0: IL_0000: nop */
    /* Path=1, Unique=0: IL_0001: newobj System.Void Win32.Code.ClassTypeTestTarget::.ctor() */
    __stack0_0 = il2c_get_uninitialized_object(il2c_typeof(Win32_Code_ClassTypeTestTarget));
    Win32_Code_ClassTypeTestTarget__ctor(__stack0_0);
    /* Path=1, Unique=0: IL_0006: stloc.0 */
    local0 = __stack0_0;
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\ClassTypeTest.cs(58): */
    /* Path=1, Unique=0: IL_0007: ldloc.0 */
    __stack0_0 = local0;
    /* Path=1, Unique=0: IL_0008: ldc.i4 789 */
    __stack1_0 = 789;
    /* Path=1, Unique=0: IL_000d: stfld System.Int32 Win32.Code.ClassTypeTestTarget::Value2 */
    __stack0_0->Value2 = __stack1_0;
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\ClassTypeTest.cs(60): */
    /* Path=1, Unique=0: IL_0012: ldloc.0 */
    __stack0_0 = local0;
    /* Path=1, Unique=0: IL_0013: ldc.i4.s 123 */
    __stack1_0 = 123;
    /* Path=1, Unique=0: IL_0015: ldc.i4 456 */
    __stack2_0 = 456;
    /* Path=1, Unique=0: IL_001a: ldc.i4 789 */
    __stack3_0 = 789;
    /* Path=1, Unique=0: IL_001f: callvirt System.Int32 Win32.Code.ClassTypeTestTarget::GetValue2(System.Int32,System.Int32,System.Int32) */
    __stack0_1 = Win32_Code_ClassTypeTestTarget_GetValue2_1(__stack0_0, __stack1_0, __stack2_0, __stack3_0);
    /* Path=1, Unique=0: IL_0024: stloc.1 */
    local1 = __stack0_1;
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\ClassTypeTest.cs(61): */
    /* Path=1, Unique=0: IL_0025: ldloc.1 */
    __stack0_1 = local1;
    /* Path=1, Unique=0: IL_0026: stloc.2 */
    local2 = __stack0_1;
    /* Path=1, Unique=0: IL_0027: br.s IL_0029 */
    goto IL_0029;
IL_0029:
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\ClassTypeTest.cs(62): */
    /* Path=2, Unique=0: IL_0029: ldloc.2 */
    __stack0_1 = local2;
    /* Path=2, Unique=0: IL_002a: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
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

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        Win32_Code_ClassTypeTestTarget** plocal0;
        Win32_Code_ClassTypeTestTarget** p__stack0_1;
    } __executionFrame__;

    __executionFrame__.targetCount = 2;
    __executionFrame__.plocal0 = &local0;
    __executionFrame__.p__stack0_1 = &__stack0_1;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\ClassTypeTest.cs(65): */
    /* Path=1, Unique=0: IL_0000: nop */
    /* Path=1, Unique=0: IL_0001: ldc.i4.s 123 */
    __stack0_0 = 123;
    /* Path=1, Unique=0: IL_0003: newobj System.Void Win32.Code.ClassTypeTestTarget::.ctor(System.Int32) */
    __stack0_1 = il2c_get_uninitialized_object(il2c_typeof(Win32_Code_ClassTypeTestTarget));
    Win32_Code_ClassTypeTestTarget__ctor_1(__stack0_1, __stack0_0);
    /* Path=1, Unique=0: IL_0008: stloc.0 */
    local0 = __stack0_1;
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\ClassTypeTest.cs(68): */
    /* Path=1, Unique=0: IL_0009: ldloc.0 */
    __stack0_1 = local0;
    /* Path=1, Unique=0: IL_000a: ldfld System.Int32 Win32.Code.ClassTypeTestTarget::Value2 */
    __stack0_0 = __stack0_1->Value2;
    /* Path=1, Unique=0: IL_000f: stloc.1 */
    local1 = __stack0_0;
    /* Path=1, Unique=0: IL_0010: br.s IL_0012 */
    goto IL_0012;
IL_0012:
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\ClassTypeTest.cs(69): */
    /* Path=2, Unique=0: IL_0012: ldloc.1 */
    __stack0_0 = local1;
    /* Path=2, Unique=0: IL_0013: ret */
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
    /* Path=1, Unique=0: IL_0006: nop */
    /* Path=1, Unique=0: IL_0007: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return;
}

//////////////////////
// Runtime helpers:

void* __Win32_Code_ClassTypeTest_IL2C_RuntimeCast__(Win32_Code_ClassTypeTest* this__, IL2C_RUNTIME_TYPE_DECL* type)
{
    if (type == il2c_typeof(System_Object)) return this__;
    return __System_Object_IL2C_RuntimeCast__((System_Object*)this__, type);
}

static void __Win32_Code_ClassTypeTest_MARK_HANDLER__(void* pReference)
{
    il2c_typeof(System_Object)->pMarkHandler(pReference);
}

static __Win32_Code_ClassTypeTest_VTABLE_DECL__ __Win32_Code_ClassTypeTest_VTABLE__ = {
    __Win32_Code_ClassTypeTest_IL2C_RuntimeCast__,
    (void*)__System_Object_ToString__,
    (void*)__System_Object_GetHashCode__,
    (void*)__System_Object_Finalize__,
    (void*)__System_Object_Equals__,
};

IL2C_RUNTIME_TYPE_DECL __Win32_Code_ClassTypeTest_RUNTIME_TYPE__ = {
    "Win32.Code.ClassTypeTest",
    sizeof(Win32_Code_ClassTypeTest),
    __Win32_Code_ClassTypeTest_MARK_HANDLER__,
};

////////////////////////////////////////////////////////////
// Type: Win32.Code.Hoge1

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

/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\Hoge1.cs(11): */
    /* Path=1, Unique=0: IL_0000: nop */
    /* Path=1, Unique=0: IL_0001: ldarg.0 */
    __stack0_0 = a;
    /* Path=1, Unique=0: IL_0002: ldarg.1 */
    __stack1_0 = (isTwo) ? 1 : 0;
    /* Path=1, Unique=0: IL_0003: brtrue.s IL_0008 */
    if (__stack1_0 != 0) goto IL_0008;
    /* Path=1, Unique=0: IL_0005: ldc.i4.1 */
    __stack1_0 = 1;
    /* Path=1, Unique=0: IL_0006: br.s IL_0009 */
    goto IL_0009;
IL_0008:
    /* Path=2, Unique=0: IL_0008: ldc.i4.2 */
    __stack1_0 = 2;
IL_0009:
    /* Path=2, Unique=0: IL_0009: add */
    __stack0_0 = __stack0_0 + __stack1_0;
    /* Path=2, Unique=0: IL_000a: stloc.0 */
    local0 = __stack0_0;
    /* Path=2, Unique=0: IL_000b: br.s IL_000d */
    goto IL_000d;
IL_000d:
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\Hoge1.cs(13): */
    /* Path=3, Unique=0: IL_000d: ldloc.0 */
    __stack0_0 = local0;
    /* Path=3, Unique=0: IL_000e: ret */
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

/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\Hoge1.cs(16): */
    /* Path=1, Unique=0: IL_0000: nop */
    /* Path=1, Unique=0: IL_0001: ldarg.0 */
    __stack0_0 = a;
    /* Path=1, Unique=0: IL_0002: ldarg.1 */
    __stack1_0 = (isTwo) ? 1 : 0;
    /* Path=1, Unique=0: IL_0003: brtrue.s IL_0008 */
    if (__stack1_0 != 0) goto IL_0008;
    /* Path=1, Unique=0: IL_0005: ldc.i4.1 */
    __stack1_0 = 1;
    /* Path=1, Unique=0: IL_0006: br.s IL_0009 */
    goto IL_0009;
IL_0008:
    /* Path=2, Unique=0: IL_0008: ldc.i4.2 */
    __stack1_0 = 2;
IL_0009:
    /* Path=2, Unique=0: IL_0009: conv.i8 */
    __stack1_1 = (int64_t)__stack1_0;
    /* Path=2, Unique=0: IL_000a: add */
    __stack0_0 = __stack0_0 + __stack1_1;
    /* Path=2, Unique=0: IL_000b: stloc.0 */
    local0 = __stack0_0;
    /* Path=2, Unique=0: IL_000c: br.s IL_000e */
    goto IL_000e;
IL_000e:
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\Hoge1.cs(18): */
    /* Path=3, Unique=0: IL_000e: ldloc.0 */
    __stack0_0 = local0;
    /* Path=3, Unique=0: IL_000f: ret */
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
    /* Path=1, Unique=0: IL_0006: nop */
    /* Path=1, Unique=0: IL_0007: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return;
}

//////////////////////
// Runtime helpers:

void* __Win32_Code_Hoge1_IL2C_RuntimeCast__(Win32_Code_Hoge1* this__, IL2C_RUNTIME_TYPE_DECL* type)
{
    if (type == il2c_typeof(System_Object)) return this__;
    return __System_Object_IL2C_RuntimeCast__((System_Object*)this__, type);
}

static void __Win32_Code_Hoge1_MARK_HANDLER__(void* pReference)
{
    il2c_typeof(System_Object)->pMarkHandler(pReference);
}

static __Win32_Code_Hoge1_VTABLE_DECL__ __Win32_Code_Hoge1_VTABLE__ = {
    __Win32_Code_Hoge1_IL2C_RuntimeCast__,
    (void*)__System_Object_ToString__,
    (void*)__System_Object_GetHashCode__,
    (void*)__System_Object_Finalize__,
    (void*)__System_Object_Equals__,
};

IL2C_RUNTIME_TYPE_DECL __Win32_Code_Hoge1_RUNTIME_TYPE__ = {
    "Win32.Code.Hoge1",
    sizeof(Win32_Code_Hoge1),
    __Win32_Code_Hoge1_MARK_HANDLER__,
};

////////////////////////////////////////////////////////////
// Type: Win32.Code.Hoge2

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

/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\Hoge2.cs(11): */
    /* Path=1, Unique=0: IL_0000: nop */
    /* Path=1, Unique=0: IL_0001: ldarg.0 */
    __stack0_0 = (int32_t)(a);
    /* Path=1, Unique=0: IL_0002: ldarg.1 */
    __stack1_0 = (isTwo) ? 1 : 0;
    /* Path=1, Unique=0: IL_0003: brtrue.s IL_0008 */
    if (__stack1_0 != 0) goto IL_0008;
    /* Path=1, Unique=0: IL_0005: ldc.i4.1 */
    __stack1_0 = 1;
    /* Path=1, Unique=0: IL_0006: br.s IL_0009 */
    goto IL_0009;
IL_0008:
    /* Path=2, Unique=0: IL_0008: ldc.i4.2 */
    __stack1_0 = 2;
IL_0009:
    /* Path=2, Unique=0: IL_0009: add */
    __stack0_0 = __stack0_0 + __stack1_0;
    /* Path=2, Unique=0: IL_000a: conv.u1 */
    __stack0_0 = (uint8_t)__stack0_0;
    /* Path=2, Unique=0: IL_000b: stloc.0 */
    local0 = (uint8_t)__stack0_0;
    /* Path=2, Unique=0: IL_000c: br.s IL_000e */
    goto IL_000e;
IL_000e:
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\Hoge2.cs(13): */
    /* Path=3, Unique=0: IL_000e: ldloc.0 */
    __stack0_0 = local0;
    /* Path=3, Unique=0: IL_000f: ret */
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

/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\Hoge2.cs(16): */
    /* Path=1, Unique=0: IL_0000: nop */
    /* Path=1, Unique=0: IL_0001: ldarg.0 */
    __stack0_0 = (int32_t)(a);
    /* Path=1, Unique=0: IL_0002: ldarg.1 */
    __stack1_0 = (isTwo) ? 1 : 0;
    /* Path=1, Unique=0: IL_0003: brtrue.s IL_0008 */
    if (__stack1_0 != 0) goto IL_0008;
    /* Path=1, Unique=0: IL_0005: ldc.i4.1 */
    __stack1_0 = 1;
    /* Path=1, Unique=0: IL_0006: br.s IL_0009 */
    goto IL_0009;
IL_0008:
    /* Path=2, Unique=0: IL_0008: ldc.i4.2 */
    __stack1_0 = 2;
IL_0009:
    /* Path=2, Unique=0: IL_0009: add */
    __stack0_0 = __stack0_0 + __stack1_0;
    /* Path=2, Unique=0: IL_000a: conv.u2 */
    __stack0_0 = (uint16_t)__stack0_0;
    /* Path=2, Unique=0: IL_000b: stloc.0 */
    local0 = (uint16_t)__stack0_0;
    /* Path=2, Unique=0: IL_000c: br.s IL_000e */
    goto IL_000e;
IL_000e:
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\Hoge2.cs(18): */
    /* Path=3, Unique=0: IL_000e: ldloc.0 */
    __stack0_0 = local0;
    /* Path=3, Unique=0: IL_000f: ret */
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
    /* Path=1, Unique=0: IL_0006: nop */
    /* Path=1, Unique=0: IL_0007: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return;
}

//////////////////////
// Runtime helpers:

void* __Win32_Code_Hoge2_IL2C_RuntimeCast__(Win32_Code_Hoge2* this__, IL2C_RUNTIME_TYPE_DECL* type)
{
    if (type == il2c_typeof(System_Object)) return this__;
    return __System_Object_IL2C_RuntimeCast__((System_Object*)this__, type);
}

static void __Win32_Code_Hoge2_MARK_HANDLER__(void* pReference)
{
    il2c_typeof(System_Object)->pMarkHandler(pReference);
}

static __Win32_Code_Hoge2_VTABLE_DECL__ __Win32_Code_Hoge2_VTABLE__ = {
    __Win32_Code_Hoge2_IL2C_RuntimeCast__,
    (void*)__System_Object_ToString__,
    (void*)__System_Object_GetHashCode__,
    (void*)__System_Object_Finalize__,
    (void*)__System_Object_Equals__,
};

IL2C_RUNTIME_TYPE_DECL __Win32_Code_Hoge2_RUNTIME_TYPE__ = {
    "Win32.Code.Hoge2",
    sizeof(Win32_Code_Hoge2),
    __Win32_Code_Hoge2_MARK_HANDLER__,
};

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

/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\InheritTest.cs(13): */
    /* Path=1, Unique=0: IL_0000: ldarg.0 */
    __stack0_0 = this__;
    /* Path=1, Unique=0: IL_0001: call System.Void System.Object::.ctor() */
    System_Object__ctor((System_Object*)__stack0_0);
    /* Path=1, Unique=0: IL_0006: nop */
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\InheritTest.cs(14): */
    /* Path=1, Unique=0: IL_0007: nop */
    /* Path=1, Unique=0: IL_0008: ret */
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

/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\InheritTest.cs(17): */
    /* Path=1, Unique=0: IL_0000: ldarg.0 */
    __stack0_0 = this__;
    /* Path=1, Unique=0: IL_0001: call System.Void System.Object::.ctor() */
    System_Object__ctor((System_Object*)__stack0_0);
    /* Path=1, Unique=0: IL_0006: nop */
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\InheritTest.cs(18): */
    /* Path=1, Unique=0: IL_0007: nop */
    /* Path=1, Unique=0: IL_0008: ldarg.0 */
    __stack0_0 = this__;
    /* Path=1, Unique=0: IL_0009: ldarg.1 */
    __stack1_0 = value;
    /* Path=1, Unique=0: IL_000a: stfld System.Int32 Win32.Code.InheritTestTargetBase1::Value2 */
    __stack0_0->Value2 = __stack1_0;
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\InheritTest.cs(20): */
    /* Path=1, Unique=0: IL_000f: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return;
}

///////////////////////////////////////
// Calc

int32_t Win32_Code_InheritTestTargetBase1_Calc(Win32_Code_InheritTestTargetBase1* this__, int32_t a)
{
    //-------------------
    // Local variables:

    int32_t local0;

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

/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\InheritTest.cs(23): */
    /* Path=1, Unique=0: IL_0000: nop */
    /* Path=1, Unique=0: IL_0001: ldarg.0 */
    __stack0_0 = this__;
    /* Path=1, Unique=0: IL_0002: ldfld System.Int32 Win32.Code.InheritTestTargetBase1::Value2 */
    __stack0_1 = __stack0_0->Value2;
    /* Path=1, Unique=0: IL_0007: ldarg.1 */
    __stack1_0 = a;
    /* Path=1, Unique=0: IL_0008: add */
    __stack0_1 = __stack0_1 + __stack1_0;
    /* Path=1, Unique=0: IL_0009: stloc.0 */
    local0 = __stack0_1;
    /* Path=1, Unique=0: IL_000a: br.s IL_000c */
    goto IL_000c;
IL_000c:
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\InheritTest.cs(25): */
    /* Path=2, Unique=0: IL_000c: ldloc.0 */
    __stack0_1 = local0;
    /* Path=2, Unique=0: IL_000d: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return __stack0_1;
}

///////////////////////////////////////
// Virtual: Calc

int32_t __Win32_Code_InheritTestTargetBase1_Calc_1__(Win32_Code_InheritTestTargetBase1* this__, int32_t a, int32_t b)
{
    //-------------------
    // Local variables:

    int32_t local0;

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

/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\InheritTest.cs(28): */
    /* Path=1, Unique=0: IL_0000: nop */
    /* Path=1, Unique=0: IL_0001: ldarg.0 */
    __stack0_0 = this__;
    /* Path=1, Unique=0: IL_0002: ldfld System.Int32 Win32.Code.InheritTestTargetBase1::Value2 */
    __stack0_1 = __stack0_0->Value2;
    /* Path=1, Unique=0: IL_0007: ldarg.1 */
    __stack1_0 = a;
    /* Path=1, Unique=0: IL_0008: add */
    __stack0_1 = __stack0_1 + __stack1_0;
    /* Path=1, Unique=0: IL_0009: ldarg.2 */
    __stack1_0 = b;
    /* Path=1, Unique=0: IL_000a: add */
    __stack0_1 = __stack0_1 + __stack1_0;
    /* Path=1, Unique=0: IL_000b: stloc.0 */
    local0 = __stack0_1;
    /* Path=1, Unique=0: IL_000c: br.s IL_000e */
    goto IL_000e;
IL_000e:
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\InheritTest.cs(30): */
    /* Path=2, Unique=0: IL_000e: ldloc.0 */
    __stack0_1 = local0;
    /* Path=2, Unique=0: IL_000f: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return __stack0_1;
}

//////////////////////
// Runtime helpers:

void* __Win32_Code_InheritTestTargetBase1_IL2C_RuntimeCast__(Win32_Code_InheritTestTargetBase1* this__, IL2C_RUNTIME_TYPE_DECL* type)
{
    if (type == il2c_typeof(System_Object)) return this__;
    return __System_Object_IL2C_RuntimeCast__((System_Object*)this__, type);
}

static void __Win32_Code_InheritTestTargetBase1_MARK_HANDLER__(void* pReference)
{
    il2c_try_mark_from_handler(((Win32_Code_InheritTestTargetBase1*)pReference)->OR2);
    il2c_typeof(System_Object)->pMarkHandler(pReference);
}

static __Win32_Code_InheritTestTargetBase1_VTABLE_DECL__ __Win32_Code_InheritTestTargetBase1_VTABLE__ = {
    __Win32_Code_InheritTestTargetBase1_IL2C_RuntimeCast__,
    (void*)__System_Object_ToString__,
    (void*)__System_Object_GetHashCode__,
    (void*)__System_Object_Finalize__,
    (void*)__System_Object_Equals__,
    (void*)__Win32_Code_InheritTestTargetBase1_Calc_1__,
};

IL2C_RUNTIME_TYPE_DECL __Win32_Code_InheritTestTargetBase1_RUNTIME_TYPE__ = {
    "Win32.Code.InheritTestTargetBase1",
    sizeof(Win32_Code_InheritTestTargetBase1),
    __Win32_Code_InheritTestTargetBase1_MARK_HANDLER__,
};

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

/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\InheritTest.cs(35): */
    /* Path=1, Unique=0: IL_0000: ldarg.0 */
    __stack0_0 = this__;
    /* Path=1, Unique=0: IL_0001: call System.Void Win32.Code.InheritTestTargetBase1::.ctor() */
    Win32_Code_InheritTestTargetBase1__ctor((Win32_Code_InheritTestTargetBase1*)__stack0_0);
    /* Path=1, Unique=0: IL_0006: nop */
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\InheritTest.cs(36): */
    /* Path=1, Unique=0: IL_0007: nop */
    /* Path=1, Unique=0: IL_0008: ret */
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

/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\InheritTest.cs(40): */
    /* Path=1, Unique=0: IL_0000: ldarg.0 */
    __stack0_0 = this__;
    /* Path=1, Unique=0: IL_0001: ldarg.1 */
    __stack1_0 = value;
    /* Path=1, Unique=0: IL_0002: call System.Void Win32.Code.InheritTestTargetBase1::.ctor(System.Int32) */
    Win32_Code_InheritTestTargetBase1__ctor_1((Win32_Code_InheritTestTargetBase1*)__stack0_0, __stack1_0);
    /* Path=1, Unique=0: IL_0007: nop */
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\InheritTest.cs(41): */
    /* Path=1, Unique=0: IL_0008: nop */
    /* Path=1, Unique=0: IL_0009: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return;
}

///////////////////////////////////////
// Calc

int32_t Win32_Code_InheritTestTarget2_Calc(Win32_Code_InheritTestTarget2* this__, int32_t a)
{
    //-------------------
    // Local variables:

    int32_t local0;

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

/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\InheritTest.cs(45): */
    /* Path=1, Unique=0: IL_0000: nop */
    /* Path=1, Unique=0: IL_0001: ldarg.0 */
    __stack0_0 = this__;
    /* Path=1, Unique=0: IL_0002: ldfld System.Int32 Win32.Code.InheritTestTargetBase1::Value2 */
    __stack0_1 = __stack0_0->Value2;
    /* Path=1, Unique=0: IL_0007: ldarg.1 */
    __stack1_0 = a;
    /* Path=1, Unique=0: IL_0008: add */
    __stack0_1 = __stack0_1 + __stack1_0;
    /* Path=1, Unique=0: IL_0009: ldc.i4 10000 */
    __stack1_0 = 10000;
    /* Path=1, Unique=0: IL_000e: add */
    __stack0_1 = __stack0_1 + __stack1_0;
    /* Path=1, Unique=0: IL_000f: stloc.0 */
    local0 = __stack0_1;
    /* Path=1, Unique=0: IL_0010: br.s IL_0012 */
    goto IL_0012;
IL_0012:
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\InheritTest.cs(47): */
    /* Path=2, Unique=0: IL_0012: ldloc.0 */
    __stack0_1 = local0;
    /* Path=2, Unique=0: IL_0013: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return __stack0_1;
}

///////////////////////////////////////
// Virtual: Calc

int32_t __Win32_Code_InheritTestTarget2_Calc_1__(Win32_Code_InheritTestTarget2* this__, int32_t a, int32_t b)
{
    //-------------------
    // Local variables:

    int32_t local0;

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

/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\InheritTest.cs(50): */
    /* Path=1, Unique=0: IL_0000: nop */
    /* Path=1, Unique=0: IL_0001: ldarg.0 */
    __stack0_0 = this__;
    /* Path=1, Unique=0: IL_0002: ldfld System.Int32 Win32.Code.InheritTestTargetBase1::Value2 */
    __stack0_1 = __stack0_0->Value2;
    /* Path=1, Unique=0: IL_0007: ldarg.1 */
    __stack1_0 = a;
    /* Path=1, Unique=0: IL_0008: add */
    __stack0_1 = __stack0_1 + __stack1_0;
    /* Path=1, Unique=0: IL_0009: ldarg.2 */
    __stack1_0 = b;
    /* Path=1, Unique=0: IL_000a: add */
    __stack0_1 = __stack0_1 + __stack1_0;
    /* Path=1, Unique=0: IL_000b: ldc.i4 10000 */
    __stack1_0 = 10000;
    /* Path=1, Unique=0: IL_0010: add */
    __stack0_1 = __stack0_1 + __stack1_0;
    /* Path=1, Unique=0: IL_0011: stloc.0 */
    local0 = __stack0_1;
    /* Path=1, Unique=0: IL_0012: br.s IL_0014 */
    goto IL_0014;
IL_0014:
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\InheritTest.cs(52): */
    /* Path=2, Unique=0: IL_0014: ldloc.0 */
    __stack0_1 = local0;
    /* Path=2, Unique=0: IL_0015: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return __stack0_1;
}

//////////////////////
// Runtime helpers:

void* __Win32_Code_InheritTestTarget2_IL2C_RuntimeCast__(Win32_Code_InheritTestTarget2* this__, IL2C_RUNTIME_TYPE_DECL* type)
{
    if (type == il2c_typeof(Win32_Code_InheritTestTargetBase1)) return this__;
    return __Win32_Code_InheritTestTargetBase1_IL2C_RuntimeCast__((Win32_Code_InheritTestTargetBase1*)this__, type);
}

static void __Win32_Code_InheritTestTarget2_MARK_HANDLER__(void* pReference)
{
    il2c_typeof(Win32_Code_InheritTestTargetBase1)->pMarkHandler(pReference);
}

static __Win32_Code_InheritTestTarget2_VTABLE_DECL__ __Win32_Code_InheritTestTarget2_VTABLE__ = {
    __Win32_Code_InheritTestTarget2_IL2C_RuntimeCast__,
    (void*)__System_Object_ToString__,
    (void*)__System_Object_GetHashCode__,
    (void*)__System_Object_Finalize__,
    (void*)__System_Object_Equals__,
    (void*)__Win32_Code_InheritTestTarget2_Calc_1__,
};

IL2C_RUNTIME_TYPE_DECL __Win32_Code_InheritTestTarget2_RUNTIME_TYPE__ = {
    "Win32.Code.InheritTestTarget2",
    sizeof(Win32_Code_InheritTestTarget2),
    __Win32_Code_InheritTestTarget2_MARK_HANDLER__,
};

////////////////////////////////////////////////////////////
// Type: Win32.Code.InheritTypeTest

///////////////////////////////////////
// Test1

int32_t Win32_Code_InheritTypeTest_Test1(void)
{
    //-------------------
    // Local variables:

    Win32_Code_InheritTestTargetBase1* local0 = NULL;
    int32_t local1;

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
        Win32_Code_InheritTestTargetBase1** plocal0;
        Win32_Code_InheritTestTargetBase1** p__stack0_0;
    } __executionFrame__;

    __executionFrame__.targetCount = 2;
    __executionFrame__.plocal0 = &local0;
    __executionFrame__.p__stack0_0 = &__stack0_0;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\InheritTest.cs(58): */
    /* Path=1, Unique=0: IL_0000: nop */
    /* Path=1, Unique=0: IL_0001: newobj System.Void Win32.Code.InheritTestTargetBase1::.ctor() */
    __stack0_0 = il2c_get_uninitialized_object(il2c_typeof(Win32_Code_InheritTestTargetBase1));
    Win32_Code_InheritTestTargetBase1__ctor(__stack0_0);
    /* Path=1, Unique=0: IL_0006: stloc.0 */
    local0 = __stack0_0;
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\InheritTest.cs(60): */
    /* Path=1, Unique=0: IL_0007: ldloc.0 */
    __stack0_0 = local0;
    /* Path=1, Unique=0: IL_0008: ldc.i4.s 123 */
    __stack1_0 = 123;
    /* Path=1, Unique=0: IL_000a: stfld System.Int32 Win32.Code.InheritTestTargetBase1::Value2 */
    __stack0_0->Value2 = __stack1_0;
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\InheritTest.cs(62): */
    /* Path=1, Unique=0: IL_000f: ldloc.0 */
    __stack0_0 = local0;
    /* Path=1, Unique=0: IL_0010: ldc.i4.1 */
    __stack1_0 = 1;
    /* Path=1, Unique=0: IL_0011: callvirt System.Int32 Win32.Code.InheritTestTargetBase1::Calc(System.Int32) */
    __stack0_1 = Win32_Code_InheritTestTargetBase1_Calc(__stack0_0, __stack1_0);
    /* Path=1, Unique=0: IL_0016: stloc.1 */
    local1 = __stack0_1;
    /* Path=1, Unique=0: IL_0017: br.s IL_0019 */
    goto IL_0019;
IL_0019:
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\InheritTest.cs(63): */
    /* Path=2, Unique=0: IL_0019: ldloc.1 */
    __stack0_1 = local1;
    /* Path=2, Unique=0: IL_001a: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return __stack0_1;
}

///////////////////////////////////////
// Test2

int32_t Win32_Code_InheritTypeTest_Test2(void)
{
    //-------------------
    // Local variables:

    Win32_Code_InheritTestTargetBase1* local0 = NULL;
    int32_t local1;

    //-------------------
    // Evaluation stacks:

    Win32_Code_InheritTestTargetBase1* __stack0_0 = NULL;
    int32_t __stack0_1;
    int32_t __stack1_0;
    int32_t __stack2_0;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        Win32_Code_InheritTestTargetBase1** plocal0;
        Win32_Code_InheritTestTargetBase1** p__stack0_0;
    } __executionFrame__;

    __executionFrame__.targetCount = 2;
    __executionFrame__.plocal0 = &local0;
    __executionFrame__.p__stack0_0 = &__stack0_0;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\InheritTest.cs(66): */
    /* Path=1, Unique=0: IL_0000: nop */
    /* Path=1, Unique=0: IL_0001: newobj System.Void Win32.Code.InheritTestTargetBase1::.ctor() */
    __stack0_0 = il2c_get_uninitialized_object(il2c_typeof(Win32_Code_InheritTestTargetBase1));
    Win32_Code_InheritTestTargetBase1__ctor(__stack0_0);
    /* Path=1, Unique=0: IL_0006: stloc.0 */
    local0 = __stack0_0;
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\InheritTest.cs(68): */
    /* Path=1, Unique=0: IL_0007: ldloc.0 */
    __stack0_0 = local0;
    /* Path=1, Unique=0: IL_0008: ldc.i4.s 123 */
    __stack1_0 = 123;
    /* Path=1, Unique=0: IL_000a: stfld System.Int32 Win32.Code.InheritTestTargetBase1::Value2 */
    __stack0_0->Value2 = __stack1_0;
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\InheritTest.cs(70): */
    /* Path=1, Unique=0: IL_000f: ldloc.0 */
    __stack0_0 = local0;
    /* Path=1, Unique=0: IL_0010: ldc.i4.1 */
    __stack1_0 = 1;
    /* Path=1, Unique=0: IL_0011: ldc.i4.2 */
    __stack2_0 = 2;
    /* Path=1, Unique=0: IL_0012: callvirt System.Int32 Win32.Code.InheritTestTargetBase1::Calc(System.Int32,System.Int32) */
    __stack0_1 = Win32_Code_InheritTestTargetBase1_Calc_1(__stack0_0, __stack1_0, __stack2_0);
    /* Path=1, Unique=0: IL_0017: stloc.1 */
    local1 = __stack0_1;
    /* Path=1, Unique=0: IL_0018: br.s IL_001a */
    goto IL_001a;
IL_001a:
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\InheritTest.cs(71): */
    /* Path=2, Unique=0: IL_001a: ldloc.1 */
    __stack0_1 = local1;
    /* Path=2, Unique=0: IL_001b: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return __stack0_1;
}

///////////////////////////////////////
// Test3

int32_t Win32_Code_InheritTypeTest_Test3(void)
{
    //-------------------
    // Local variables:

    Win32_Code_InheritTestTarget2* local0 = NULL;
    int32_t local1;

    //-------------------
    // Evaluation stacks:

    Win32_Code_InheritTestTarget2* __stack0_0 = NULL;
    int32_t __stack0_1;
    int32_t __stack1_0;
    int32_t __stack2_0;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        Win32_Code_InheritTestTarget2** plocal0;
        Win32_Code_InheritTestTarget2** p__stack0_0;
    } __executionFrame__;

    __executionFrame__.targetCount = 2;
    __executionFrame__.plocal0 = &local0;
    __executionFrame__.p__stack0_0 = &__stack0_0;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\InheritTest.cs(74): */
    /* Path=1, Unique=0: IL_0000: nop */
    /* Path=1, Unique=0: IL_0001: newobj System.Void Win32.Code.InheritTestTarget2::.ctor() */
    __stack0_0 = il2c_get_uninitialized_object(il2c_typeof(Win32_Code_InheritTestTarget2));
    Win32_Code_InheritTestTarget2__ctor(__stack0_0);
    /* Path=1, Unique=0: IL_0006: stloc.0 */
    local0 = __stack0_0;
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\InheritTest.cs(76): */
    /* Path=1, Unique=0: IL_0007: ldloc.0 */
    __stack0_0 = local0;
    /* Path=1, Unique=0: IL_0008: ldc.i4.s 123 */
    __stack1_0 = 123;
    /* Path=1, Unique=0: IL_000a: stfld System.Int32 Win32.Code.InheritTestTargetBase1::Value2 */
    __stack0_0->Value2 = __stack1_0;
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\InheritTest.cs(78): */
    /* Path=1, Unique=0: IL_000f: ldloc.0 */
    __stack0_0 = local0;
    /* Path=1, Unique=0: IL_0010: ldc.i4.1 */
    __stack1_0 = 1;
    /* Path=1, Unique=0: IL_0011: ldc.i4.2 */
    __stack2_0 = 2;
    /* Path=1, Unique=0: IL_0012: callvirt System.Int32 Win32.Code.InheritTestTargetBase1::Calc(System.Int32,System.Int32) */
    __stack0_1 = Win32_Code_InheritTestTargetBase1_Calc_1((Win32_Code_InheritTestTargetBase1*)__stack0_0, __stack1_0, __stack2_0);
    /* Path=1, Unique=0: IL_0017: stloc.1 */
    local1 = __stack0_1;
    /* Path=1, Unique=0: IL_0018: br.s IL_001a */
    goto IL_001a;
IL_001a:
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\InheritTest.cs(79): */
    /* Path=2, Unique=0: IL_001a: ldloc.1 */
    __stack0_1 = local1;
    /* Path=2, Unique=0: IL_001b: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return __stack0_1;
}

///////////////////////////////////////
// Test4

int32_t Win32_Code_InheritTypeTest_Test4(void)
{
    //-------------------
    // Local variables:

    Win32_Code_InheritTestTargetBase1* local0 = NULL;
    int32_t local1;

    //-------------------
    // Evaluation stacks:

    Win32_Code_InheritTestTarget2* __stack0_0 = NULL;
    Win32_Code_InheritTestTargetBase1* __stack0_1 = NULL;
    int32_t __stack0_2;
    int32_t __stack1_0;
    int32_t __stack2_0;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        Win32_Code_InheritTestTargetBase1** plocal0;
        Win32_Code_InheritTestTarget2** p__stack0_0;
        Win32_Code_InheritTestTargetBase1** p__stack0_1;
    } __executionFrame__;

    __executionFrame__.targetCount = 3;
    __executionFrame__.plocal0 = &local0;
    __executionFrame__.p__stack0_0 = &__stack0_0;
    __executionFrame__.p__stack0_1 = &__stack0_1;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\InheritTest.cs(82): */
    /* Path=1, Unique=0: IL_0000: nop */
    /* Path=1, Unique=0: IL_0001: newobj System.Void Win32.Code.InheritTestTarget2::.ctor() */
    __stack0_0 = il2c_get_uninitialized_object(il2c_typeof(Win32_Code_InheritTestTarget2));
    Win32_Code_InheritTestTarget2__ctor(__stack0_0);
    /* Path=1, Unique=0: IL_0006: stloc.0 */
    local0 = (Win32_Code_InheritTestTargetBase1*)__stack0_0;
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\InheritTest.cs(84): */
    /* Path=1, Unique=0: IL_0007: ldloc.0 */
    __stack0_1 = local0;
    /* Path=1, Unique=0: IL_0008: ldc.i4.s 123 */
    __stack1_0 = 123;
    /* Path=1, Unique=0: IL_000a: stfld System.Int32 Win32.Code.InheritTestTargetBase1::Value2 */
    __stack0_1->Value2 = __stack1_0;
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\InheritTest.cs(86): */
    /* Path=1, Unique=0: IL_000f: ldloc.0 */
    __stack0_1 = local0;
    /* Path=1, Unique=0: IL_0010: ldc.i4.1 */
    __stack1_0 = 1;
    /* Path=1, Unique=0: IL_0011: ldc.i4.2 */
    __stack2_0 = 2;
    /* Path=1, Unique=0: IL_0012: callvirt System.Int32 Win32.Code.InheritTestTargetBase1::Calc(System.Int32,System.Int32) */
    __stack0_2 = Win32_Code_InheritTestTargetBase1_Calc_1(__stack0_1, __stack1_0, __stack2_0);
    /* Path=1, Unique=0: IL_0017: stloc.1 */
    local1 = __stack0_2;
    /* Path=1, Unique=0: IL_0018: br.s IL_001a */
    goto IL_001a;
IL_001a:
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\InheritTest.cs(87): */
    /* Path=2, Unique=0: IL_001a: ldloc.1 */
    __stack0_2 = local1;
    /* Path=2, Unique=0: IL_001b: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return __stack0_2;
}

///////////////////////////////////////
// Test5

int32_t Win32_Code_InheritTypeTest_Test5(void)
{
    //-------------------
    // Local variables:

    System_Object* local0 = NULL;
    Win32_Code_InheritTestTarget2* local1 = NULL;
    int32_t local2;

    //-------------------
    // Evaluation stacks:

    Win32_Code_InheritTestTarget2* __stack0_0 = NULL;
    System_Object* __stack0_1 = NULL;
    int32_t __stack0_2;
    int32_t __stack1_0;
    int32_t __stack2_0;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        System_Object** plocal0;
        Win32_Code_InheritTestTarget2** plocal1;
        Win32_Code_InheritTestTarget2** p__stack0_0;
        System_Object** p__stack0_1;
    } __executionFrame__;

    __executionFrame__.targetCount = 4;
    __executionFrame__.plocal0 = &local0;
    __executionFrame__.plocal1 = &local1;
    __executionFrame__.p__stack0_0 = &__stack0_0;
    __executionFrame__.p__stack0_1 = &__stack0_1;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\InheritTest.cs(90): */
    /* Path=1, Unique=0: IL_0000: nop */
    /* Path=1, Unique=0: IL_0001: newobj System.Void Win32.Code.InheritTestTarget2::.ctor() */
    __stack0_0 = il2c_get_uninitialized_object(il2c_typeof(Win32_Code_InheritTestTarget2));
    Win32_Code_InheritTestTarget2__ctor(__stack0_0);
    /* Path=1, Unique=0: IL_0006: stloc.0 */
    local0 = (System_Object*)__stack0_0;
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\InheritTest.cs(92): */
    /* Path=1, Unique=0: IL_0007: ldloc.0 */
    __stack0_1 = local0;
    /* Path=1, Unique=0: IL_0008: castclass Win32.Code.InheritTestTarget2 */
    __stack0_0 = il2c_runtime_cast(__stack0_1, Win32_Code_InheritTestTarget2);
    /* Path=1, Unique=0: IL_000d: stloc.1 */
    local1 = __stack0_0;
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\InheritTest.cs(93): */
    /* Path=1, Unique=0: IL_000e: ldloc.1 */
    __stack0_0 = local1;
    /* Path=1, Unique=0: IL_000f: ldc.i4.s 123 */
    __stack1_0 = 123;
    /* Path=1, Unique=0: IL_0011: stfld System.Int32 Win32.Code.InheritTestTargetBase1::Value2 */
    __stack0_0->Value2 = __stack1_0;
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\InheritTest.cs(95): */
    /* Path=1, Unique=0: IL_0016: ldloc.1 */
    __stack0_0 = local1;
    /* Path=1, Unique=0: IL_0017: ldc.i4.1 */
    __stack1_0 = 1;
    /* Path=1, Unique=0: IL_0018: ldc.i4.2 */
    __stack2_0 = 2;
    /* Path=1, Unique=0: IL_0019: callvirt System.Int32 Win32.Code.InheritTestTargetBase1::Calc(System.Int32,System.Int32) */
    __stack0_2 = Win32_Code_InheritTestTargetBase1_Calc_1((Win32_Code_InheritTestTargetBase1*)__stack0_0, __stack1_0, __stack2_0);
    /* Path=1, Unique=0: IL_001e: stloc.2 */
    local2 = __stack0_2;
    /* Path=1, Unique=0: IL_001f: br.s IL_0021 */
    goto IL_0021;
IL_0021:
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\InheritTest.cs(96): */
    /* Path=2, Unique=0: IL_0021: ldloc.2 */
    __stack0_2 = local2;
    /* Path=2, Unique=0: IL_0022: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return __stack0_2;
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
    /* Path=1, Unique=0: IL_0006: nop */
    /* Path=1, Unique=0: IL_0007: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return;
}

//////////////////////
// Runtime helpers:

void* __Win32_Code_InheritTypeTest_IL2C_RuntimeCast__(Win32_Code_InheritTypeTest* this__, IL2C_RUNTIME_TYPE_DECL* type)
{
    if (type == il2c_typeof(System_Object)) return this__;
    return __System_Object_IL2C_RuntimeCast__((System_Object*)this__, type);
}

static void __Win32_Code_InheritTypeTest_MARK_HANDLER__(void* pReference)
{
    il2c_typeof(System_Object)->pMarkHandler(pReference);
}

static __Win32_Code_InheritTypeTest_VTABLE_DECL__ __Win32_Code_InheritTypeTest_VTABLE__ = {
    __Win32_Code_InheritTypeTest_IL2C_RuntimeCast__,
    (void*)__System_Object_ToString__,
    (void*)__System_Object_GetHashCode__,
    (void*)__System_Object_Finalize__,
    (void*)__System_Object_Equals__,
};

IL2C_RUNTIME_TYPE_DECL __Win32_Code_InheritTypeTest_RUNTIME_TYPE__ = {
    "Win32.Code.InheritTypeTest",
    sizeof(Win32_Code_InheritTypeTest),
    __Win32_Code_InheritTypeTest_MARK_HANDLER__,
};

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
    /* Path=1, Unique=0: IL_0006: nop */
    /* Path=1, Unique=0: IL_0007: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return;
}

//////////////////////
// Runtime helpers:

void* __Win32_Code_Win32_IL2C_RuntimeCast__(Win32_Code_Win32* this__, IL2C_RUNTIME_TYPE_DECL* type)
{
    if (type == il2c_typeof(System_Object)) return this__;
    return __System_Object_IL2C_RuntimeCast__((System_Object*)this__, type);
}

static void __Win32_Code_Win32_MARK_HANDLER__(void* pReference)
{
    il2c_typeof(System_Object)->pMarkHandler(pReference);
}

static __Win32_Code_Win32_VTABLE_DECL__ __Win32_Code_Win32_VTABLE__ = {
    __Win32_Code_Win32_IL2C_RuntimeCast__,
    (void*)__System_Object_ToString__,
    (void*)__System_Object_GetHashCode__,
    (void*)__System_Object_Finalize__,
    (void*)__System_Object_Equals__,
};

IL2C_RUNTIME_TYPE_DECL __Win32_Code_Win32_RUNTIME_TYPE__ = {
    "Win32.Code.Win32",
    sizeof(Win32_Code_Win32),
    __Win32_Code_Win32_MARK_HANDLER__,
};

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

/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(13): */
    /* Path=1, Unique=0: IL_0000: ldarg.0 */
    __stack0_0 = this__;
    /* Path=1, Unique=0: IL_0001: call System.Void System.Object::.ctor() */
    System_Object__ctor((System_Object*)__stack0_0);
    /* Path=1, Unique=0: IL_0006: nop */
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(14): */
    /* Path=1, Unique=0: IL_0007: nop */
    /* Path=1, Unique=0: IL_0008: ldarg.0 */
    __stack0_0 = this__;
    /* Path=1, Unique=0: IL_0009: ldarg.1 */
    __stack1_0 = nextIndex;
    /* Path=1, Unique=0: IL_000a: stfld System.Int32 Win32.Code.AbstractNode::NextIndex */
    __stack0_0->NextIndex = __stack1_0;
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(16): */
    /* Path=1, Unique=0: IL_000f: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return;
}

//////////////////////
// Runtime helpers:

void* __Win32_Code_AbstractNode_IL2C_RuntimeCast__(Win32_Code_AbstractNode* this__, IL2C_RUNTIME_TYPE_DECL* type)
{
    if (type == il2c_typeof(System_Object)) return this__;
    return __System_Object_IL2C_RuntimeCast__((System_Object*)this__, type);
}

static void __Win32_Code_AbstractNode_MARK_HANDLER__(void* pReference)
{
    il2c_typeof(System_Object)->pMarkHandler(pReference);
}

static __Win32_Code_AbstractNode_VTABLE_DECL__ __Win32_Code_AbstractNode_VTABLE__ = {
    __Win32_Code_AbstractNode_IL2C_RuntimeCast__,
    (void*)__System_Object_ToString__,
    (void*)__System_Object_GetHashCode__,
    (void*)__System_Object_Finalize__,
    (void*)__System_Object_Equals__,
};

IL2C_RUNTIME_TYPE_DECL __Win32_Code_AbstractNode_RUNTIME_TYPE__ = {
    "Win32.Code.AbstractNode",
    sizeof(Win32_Code_AbstractNode),
    __Win32_Code_AbstractNode_MARK_HANDLER__,
};

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

/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(23): */
    /* Path=1, Unique=0: IL_0000: ldarg.0 */
    __stack0_0 = this__;
    /* Path=1, Unique=0: IL_0001: ldarg.2 */
    __stack1_0 = nextIndex;
    /* Path=1, Unique=0: IL_0002: call System.Void Win32.Code.AbstractNode::.ctor(System.Int32) */
    Win32_Code_AbstractNode__ctor((Win32_Code_AbstractNode*)__stack0_0, __stack1_0);
    /* Path=1, Unique=0: IL_0007: nop */
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(24): */
    /* Path=1, Unique=0: IL_0008: nop */
    /* Path=1, Unique=0: IL_0009: ldarg.0 */
    __stack0_0 = this__;
    /* Path=1, Unique=0: IL_000a: ldarg.1 */
    __stack1_0 = (int32_t)(oper);
    /* Path=1, Unique=0: IL_000b: stfld System.Char Win32.Code.OperatorNode::Operator */
    __stack0_0->Operator = (wchar_t)__stack1_0;
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(26): */
    /* Path=1, Unique=0: IL_0010: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return;
}

//////////////////////
// Runtime helpers:

void* __Win32_Code_OperatorNode_IL2C_RuntimeCast__(Win32_Code_OperatorNode* this__, IL2C_RUNTIME_TYPE_DECL* type)
{
    if (type == il2c_typeof(Win32_Code_AbstractNode)) return this__;
    return __Win32_Code_AbstractNode_IL2C_RuntimeCast__((Win32_Code_AbstractNode*)this__, type);
}

static void __Win32_Code_OperatorNode_MARK_HANDLER__(void* pReference)
{
    il2c_typeof(Win32_Code_AbstractNode)->pMarkHandler(pReference);
}

static __Win32_Code_OperatorNode_VTABLE_DECL__ __Win32_Code_OperatorNode_VTABLE__ = {
    __Win32_Code_OperatorNode_IL2C_RuntimeCast__,
    (void*)__System_Object_ToString__,
    (void*)__System_Object_GetHashCode__,
    (void*)__System_Object_Finalize__,
    (void*)__System_Object_Equals__,
};

IL2C_RUNTIME_TYPE_DECL __Win32_Code_OperatorNode_RUNTIME_TYPE__ = {
    "Win32.Code.OperatorNode",
    sizeof(Win32_Code_OperatorNode),
    __Win32_Code_OperatorNode_MARK_HANDLER__,
};

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

/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(31): */
    /* Path=1, Unique=0: IL_0000: ldarg.0 */
    __stack0_0 = this__;
    /* Path=1, Unique=0: IL_0001: ldarg.1 */
    __stack1_0 = nextIndex;
    /* Path=1, Unique=0: IL_0002: call System.Void Win32.Code.AbstractNode::.ctor(System.Int32) */
    Win32_Code_AbstractNode__ctor((Win32_Code_AbstractNode*)__stack0_0, __stack1_0);
    /* Path=1, Unique=0: IL_0007: nop */
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(32): */
    /* Path=1, Unique=0: IL_0008: nop */
    /* Path=1, Unique=0: IL_0009: ret */
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

void* __Win32_Code_ReducibleNode_IL2C_RuntimeCast__(Win32_Code_ReducibleNode* this__, IL2C_RUNTIME_TYPE_DECL* type)
{
    if (type == il2c_typeof(Win32_Code_AbstractNode)) return this__;
    return __Win32_Code_AbstractNode_IL2C_RuntimeCast__((Win32_Code_AbstractNode*)this__, type);
}

static void __Win32_Code_ReducibleNode_MARK_HANDLER__(void* pReference)
{
    il2c_typeof(Win32_Code_AbstractNode)->pMarkHandler(pReference);
}

static __Win32_Code_ReducibleNode_VTABLE_DECL__ __Win32_Code_ReducibleNode_VTABLE__ = {
    __Win32_Code_ReducibleNode_IL2C_RuntimeCast__,
    (void*)__System_Object_ToString__,
    (void*)__System_Object_GetHashCode__,
    (void*)__System_Object_Finalize__,
    (void*)__System_Object_Equals__,
    (void*)__Win32_Code_ReducibleNode_Reduce__,
};

IL2C_RUNTIME_TYPE_DECL __Win32_Code_ReducibleNode_RUNTIME_TYPE__ = {
    "Win32.Code.ReducibleNode",
    sizeof(Win32_Code_ReducibleNode),
    __Win32_Code_ReducibleNode_MARK_HANDLER__,
};

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

/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(42): */
    /* Path=1, Unique=0: IL_0000: ldarg.0 */
    __stack0_0 = this__;
    /* Path=1, Unique=0: IL_0001: ldarg.2 */
    __stack1_0 = nextIndex;
    /* Path=1, Unique=0: IL_0002: call System.Void Win32.Code.ReducibleNode::.ctor(System.Int32) */
    Win32_Code_ReducibleNode__ctor((Win32_Code_ReducibleNode*)__stack0_0, __stack1_0);
    /* Path=1, Unique=0: IL_0007: nop */
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(43): */
    /* Path=1, Unique=0: IL_0008: nop */
    /* Path=1, Unique=0: IL_0009: ldarg.0 */
    __stack0_0 = this__;
    /* Path=1, Unique=0: IL_000a: ldarg.1 */
    __stack1_0 = numeric;
    /* Path=1, Unique=0: IL_000b: stfld System.Int32 Win32.Code.NumericNode::Numeric */
    __stack0_0->Numeric = __stack1_0;
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(45): */
    /* Path=1, Unique=0: IL_0010: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return;
}

///////////////////////////////////////
// Virtual: Reduce

int32_t __Win32_Code_NumericNode_Reduce__(Win32_Code_NumericNode* this__)
{
    //-------------------
    // Local variables:

    int32_t local0;

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

/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(48): */
    /* Path=1, Unique=0: IL_0000: nop */
    /* Path=1, Unique=0: IL_0001: ldarg.0 */
    __stack0_0 = this__;
    /* Path=1, Unique=0: IL_0002: ldfld System.Int32 Win32.Code.NumericNode::Numeric */
    __stack0_1 = __stack0_0->Numeric;
    /* Path=1, Unique=0: IL_0007: stloc.0 */
    local0 = __stack0_1;
    /* Path=1, Unique=0: IL_0008: br.s IL_000a */
    goto IL_000a;
IL_000a:
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(50): */
    /* Path=2, Unique=0: IL_000a: ldloc.0 */
    __stack0_1 = local0;
    /* Path=2, Unique=0: IL_000b: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return __stack0_1;
}

//////////////////////
// Runtime helpers:

void* __Win32_Code_NumericNode_IL2C_RuntimeCast__(Win32_Code_NumericNode* this__, IL2C_RUNTIME_TYPE_DECL* type)
{
    if (type == il2c_typeof(Win32_Code_ReducibleNode)) return this__;
    return __Win32_Code_ReducibleNode_IL2C_RuntimeCast__((Win32_Code_ReducibleNode*)this__, type);
}

static void __Win32_Code_NumericNode_MARK_HANDLER__(void* pReference)
{
    il2c_typeof(Win32_Code_ReducibleNode)->pMarkHandler(pReference);
}

static __Win32_Code_NumericNode_VTABLE_DECL__ __Win32_Code_NumericNode_VTABLE__ = {
    __Win32_Code_NumericNode_IL2C_RuntimeCast__,
    (void*)__System_Object_ToString__,
    (void*)__System_Object_GetHashCode__,
    (void*)__System_Object_Finalize__,
    (void*)__System_Object_Equals__,
    (void*)__Win32_Code_NumericNode_Reduce__,
};

IL2C_RUNTIME_TYPE_DECL __Win32_Code_NumericNode_RUNTIME_TYPE__ = {
    "Win32.Code.NumericNode",
    sizeof(Win32_Code_NumericNode),
    __Win32_Code_NumericNode_MARK_HANDLER__,
};

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

/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(59): */
    /* Path=1, Unique=0: IL_0000: ldarg.0 */
    __stack0_0 = this__;
    /* Path=1, Unique=0: IL_0001: ldarg.s nextIndex */
    __stack1_0 = nextIndex;
    /* Path=1, Unique=0: IL_0003: call System.Void Win32.Code.ReducibleNode::.ctor(System.Int32) */
    Win32_Code_ReducibleNode__ctor((Win32_Code_ReducibleNode*)__stack0_0, __stack1_0);
    /* Path=1, Unique=0: IL_0008: nop */
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(60): */
    /* Path=1, Unique=0: IL_0009: nop */
    /* Path=1, Unique=0: IL_000a: ldarg.0 */
    __stack0_0 = this__;
    /* Path=1, Unique=0: IL_000b: ldarg.1 */
    __stack1_1 = oper;
    /* Path=1, Unique=0: IL_000c: stfld Win32.Code.OperatorNode Win32.Code.ExpressionNode::Operator */
    __stack0_0->Operator = __stack1_1;
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(62): */
    /* Path=1, Unique=0: IL_0011: ldarg.0 */
    __stack0_0 = this__;
    /* Path=1, Unique=0: IL_0012: ldarg.2 */
    __stack1_2 = left;
    /* Path=1, Unique=0: IL_0013: stfld Win32.Code.ReducibleNode Win32.Code.ExpressionNode::Left */
    __stack0_0->Left = __stack1_2;
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(63): */
    /* Path=1, Unique=0: IL_0018: ldarg.0 */
    __stack0_0 = this__;
    /* Path=1, Unique=0: IL_0019: ldarg.3 */
    __stack1_2 = right;
    /* Path=1, Unique=0: IL_001a: stfld Win32.Code.ReducibleNode Win32.Code.ExpressionNode::Right */
    __stack0_0->Right = __stack1_2;
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(64): */
    /* Path=1, Unique=0: IL_001f: ret */
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
    bool local2;
    int32_t local3;
    bool local4;
    bool local5;
    bool local6;

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

/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(67): */
    /* Path=1, Unique=0: IL_0000: nop */
    /* Path=1, Unique=0: IL_0001: ldarg.0 */
    __stack0_0 = this__;
    /* Path=1, Unique=0: IL_0002: ldfld Win32.Code.ReducibleNode Win32.Code.ExpressionNode::Left */
    __stack0_1 = __stack0_0->Left;
    /* Path=1, Unique=0: IL_0007: callvirt System.Int32 Win32.Code.ReducibleNode::Reduce() */
    __stack0_2 = Win32_Code_ReducibleNode_Reduce(__stack0_1);
    /* Path=1, Unique=0: IL_000c: stloc.0 */
    local0 = __stack0_2;
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(69): */
    /* Path=1, Unique=0: IL_000d: ldarg.0 */
    __stack0_0 = this__;
    /* Path=1, Unique=0: IL_000e: ldfld Win32.Code.ReducibleNode Win32.Code.ExpressionNode::Right */
    __stack0_1 = __stack0_0->Right;
    /* Path=1, Unique=0: IL_0013: callvirt System.Int32 Win32.Code.ReducibleNode::Reduce() */
    __stack0_2 = Win32_Code_ReducibleNode_Reduce(__stack0_1);
    /* Path=1, Unique=0: IL_0018: stloc.1 */
    local1 = __stack0_2;
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(70): */
    /* Path=1, Unique=0: IL_0019: ldarg.0 */
    __stack0_0 = this__;
    /* Path=1, Unique=0: IL_001a: ldfld Win32.Code.OperatorNode Win32.Code.ExpressionNode::Operator */
    __stack0_3 = __stack0_0->Operator;
    /* Path=1, Unique=0: IL_001f: ldfld System.Char Win32.Code.OperatorNode::Operator */
    __stack0_2 = (int32_t)(__stack0_3->Operator);
    /* Path=1, Unique=0: IL_0024: ldc.i4.s 43 */
    __stack1_0 = 43;
    /* Path=1, Unique=0: IL_0026: ceq */
    __stack0_2 = (__stack0_2 == __stack1_0) ? 1 : 0;
    /* Path=1, Unique=0: IL_0028: stloc.2 */
    local2 = __stack0_2 ? true : false;
    /* Path=1, Unique=0: IL_0029: ldloc.2 */
    __stack0_2 = local2;
    /* Path=1, Unique=0: IL_002a: brfalse.s IL_0033 */
    if (__stack0_2 == 0) goto IL_0033;
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(71): */
    /* Path=1, Unique=0: IL_002c: nop */
    /* Path=1, Unique=0: IL_002d: ldloc.0 */
    __stack0_2 = local0;
    /* Path=1, Unique=0: IL_002e: ldloc.1 */
    __stack1_0 = local1;
    /* Path=1, Unique=0: IL_002f: add */
    __stack0_2 = __stack0_2 + __stack1_0;
    /* Path=1, Unique=0: IL_0030: stloc.3 */
    local3 = __stack0_2;
    /* Path=1, Unique=0: IL_0031: br.s IL_008b */
    goto IL_008b;
IL_0033:
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(74): */
    /* Path=2, Unique=0: IL_0033: ldarg.0 */
    __stack0_0 = this__;
    /* Path=2, Unique=0: IL_0034: ldfld Win32.Code.OperatorNode Win32.Code.ExpressionNode::Operator */
    __stack0_3 = __stack0_0->Operator;
    /* Path=2, Unique=0: IL_0039: ldfld System.Char Win32.Code.OperatorNode::Operator */
    __stack0_2 = (int32_t)(__stack0_3->Operator);
    /* Path=2, Unique=0: IL_003e: ldc.i4.s 45 */
    __stack1_0 = 45;
    /* Path=2, Unique=0: IL_0040: ceq */
    __stack0_2 = (__stack0_2 == __stack1_0) ? 1 : 0;
    /* Path=2, Unique=0: IL_0042: stloc.s local4 */
    local4 = __stack0_2 ? true : false;
    /* Path=2, Unique=0: IL_0044: ldloc.s local4 */
    __stack0_2 = local4;
    /* Path=2, Unique=0: IL_0046: brfalse.s IL_004f */
    if (__stack0_2 == 0) goto IL_004f;
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(75): */
    /* Path=2, Unique=0: IL_0048: nop */
    /* Path=2, Unique=0: IL_0049: ldloc.0 */
    __stack0_2 = local0;
    /* Path=2, Unique=0: IL_004a: ldloc.1 */
    __stack1_0 = local1;
    /* Path=2, Unique=0: IL_004b: sub */
    __stack0_2 = __stack0_2 - __stack1_0;
    /* Path=2, Unique=0: IL_004c: stloc.3 */
    local3 = __stack0_2;
    /* Path=2, Unique=0: IL_004d: br.s IL_008b */
    goto IL_008b;
IL_004f:
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(78): */
    /* Path=4, Unique=0: IL_004f: ldarg.0 */
    __stack0_0 = this__;
    /* Path=4, Unique=0: IL_0050: ldfld Win32.Code.OperatorNode Win32.Code.ExpressionNode::Operator */
    __stack0_3 = __stack0_0->Operator;
    /* Path=4, Unique=0: IL_0055: ldfld System.Char Win32.Code.OperatorNode::Operator */
    __stack0_2 = (int32_t)(__stack0_3->Operator);
    /* Path=4, Unique=0: IL_005a: ldc.i4.s 42 */
    __stack1_0 = 42;
    /* Path=4, Unique=0: IL_005c: ceq */
    __stack0_2 = (__stack0_2 == __stack1_0) ? 1 : 0;
    /* Path=4, Unique=0: IL_005e: stloc.s local5 */
    local5 = __stack0_2 ? true : false;
    /* Path=4, Unique=0: IL_0060: ldloc.s local5 */
    __stack0_2 = local5;
    /* Path=4, Unique=0: IL_0062: brfalse.s IL_006b */
    if (__stack0_2 == 0) goto IL_006b;
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(79): */
    /* Path=4, Unique=0: IL_0064: nop */
    /* Path=4, Unique=0: IL_0065: ldloc.0 */
    __stack0_2 = local0;
    /* Path=4, Unique=0: IL_0066: ldloc.1 */
    __stack1_0 = local1;
    /* Path=4, Unique=0: IL_0067: mul */
    __stack0_2 = __stack0_2 * __stack1_0;
    /* Path=4, Unique=0: IL_0068: stloc.3 */
    local3 = __stack0_2;
    /* Path=4, Unique=0: IL_0069: br.s IL_008b */
    goto IL_008b;
IL_006b:
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(82): */
    /* Path=5, Unique=0: IL_006b: ldarg.0 */
    __stack0_0 = this__;
    /* Path=5, Unique=0: IL_006c: ldfld Win32.Code.OperatorNode Win32.Code.ExpressionNode::Operator */
    __stack0_3 = __stack0_0->Operator;
    /* Path=5, Unique=0: IL_0071: ldfld System.Char Win32.Code.OperatorNode::Operator */
    __stack0_2 = (int32_t)(__stack0_3->Operator);
    /* Path=5, Unique=0: IL_0076: ldc.i4.s 47 */
    __stack1_0 = 47;
    /* Path=5, Unique=0: IL_0078: ceq */
    __stack0_2 = (__stack0_2 == __stack1_0) ? 1 : 0;
    /* Path=5, Unique=0: IL_007a: stloc.s local6 */
    local6 = __stack0_2 ? true : false;
    /* Path=5, Unique=0: IL_007c: ldloc.s local6 */
    __stack0_2 = local6;
    /* Path=5, Unique=0: IL_007e: brfalse.s IL_0087 */
    if (__stack0_2 == 0) goto IL_0087;
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(83): */
    /* Path=5, Unique=0: IL_0080: nop */
    /* Path=5, Unique=0: IL_0081: ldloc.0 */
    __stack0_2 = local0;
    /* Path=5, Unique=0: IL_0082: ldloc.1 */
    __stack1_0 = local1;
    /* Path=5, Unique=0: IL_0083: div */
    __stack0_2 = __stack0_2 / __stack1_0;
    /* Path=5, Unique=0: IL_0084: stloc.3 */
    local3 = __stack0_2;
    /* Path=5, Unique=0: IL_0085: br.s IL_008b */
    goto IL_008b;
IL_0087:
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(88): */
    /* Path=6, Unique=0: IL_0087: ldc.i4.0 */
    __stack0_2 = 0;
    /* Path=6, Unique=0: IL_0088: stloc.3 */
    local3 = __stack0_2;
    /* Path=6, Unique=0: IL_0089: br.s IL_008b */
    goto IL_008b;
IL_008b:
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(89): */
    /* Path=3, Unique=0: IL_008b: ldloc.3 */
    __stack0_2 = local3;
    /* Path=3, Unique=0: IL_008c: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return __stack0_2;
}

//////////////////////
// Runtime helpers:

void* __Win32_Code_ExpressionNode_IL2C_RuntimeCast__(Win32_Code_ExpressionNode* this__, IL2C_RUNTIME_TYPE_DECL* type)
{
    if (type == il2c_typeof(Win32_Code_ReducibleNode)) return this__;
    return __Win32_Code_ReducibleNode_IL2C_RuntimeCast__((Win32_Code_ReducibleNode*)this__, type);
}

static void __Win32_Code_ExpressionNode_MARK_HANDLER__(void* pReference)
{
    il2c_try_mark_from_handler(((Win32_Code_ExpressionNode*)pReference)->Operator);
    il2c_try_mark_from_handler(((Win32_Code_ExpressionNode*)pReference)->Left);
    il2c_try_mark_from_handler(((Win32_Code_ExpressionNode*)pReference)->Right);
    il2c_typeof(Win32_Code_ReducibleNode)->pMarkHandler(pReference);
}

static __Win32_Code_ExpressionNode_VTABLE_DECL__ __Win32_Code_ExpressionNode_VTABLE__ = {
    __Win32_Code_ExpressionNode_IL2C_RuntimeCast__,
    (void*)__System_Object_ToString__,
    (void*)__System_Object_GetHashCode__,
    (void*)__System_Object_Finalize__,
    (void*)__System_Object_Equals__,
    (void*)__Win32_Code_ExpressionNode_Reduce__,
};

IL2C_RUNTIME_TYPE_DECL __Win32_Code_ExpressionNode_RUNTIME_TYPE__ = {
    "Win32.Code.ExpressionNode",
    sizeof(Win32_Code_ExpressionNode),
    __Win32_Code_ExpressionNode_MARK_HANDLER__,
};

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
    bool local2;
    bool local3;
    int32_t local4;

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

/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(95): */
    /* Path=1, Unique=0: IL_0000: nop */
    /* Path=1, Unique=0: IL_0001: ldarg.1 */
    __stack0_0 = startIndex;
    /* Path=1, Unique=0: IL_0002: stloc.0 */
    local0 = __stack0_0;
    /* Path=1, Unique=0: IL_0003: br.s IL_002a */
    goto IL_002a;
IL_0005:
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(98): */
    /* Path=3, Unique=0: IL_0005: nop */
    /* Path=3, Unique=0: IL_0006: ldarg.0 */
    __stack0_1 = line;
    /* Path=3, Unique=0: IL_0007: ldloc.0 */
    __stack1_2 = local0;
    /* Path=3, Unique=0: IL_0008: callvirt System.Char System.String::get_Chars(System.Int32) */
    __stack0_2 = System_String_get_Chars(__stack0_1, __stack1_2);
    /* Path=3, Unique=0: IL_000d: stloc.1 */
    local1 = (wchar_t)__stack0_2;
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(100): */
    /* Path=3, Unique=0: IL_000e: ldloc.1 */
    __stack0_0 = local1;
    /* Path=3, Unique=0: IL_000f: ldc.i4.s 32 */
    __stack1_2 = 32;
    /* Path=3, Unique=0: IL_0011: beq.s IL_001d */
    if (__stack0_0 == __stack1_2) goto IL_001d;
    /* Path=3, Unique=0: IL_0013: ldloc.1 */
    __stack0_0 = local1;
    /* Path=3, Unique=0: IL_0014: ldc.i4.s 9 */
    __stack1_2 = 9;
    /* Path=3, Unique=0: IL_0016: ceq */
    __stack0_0 = (__stack0_0 == __stack1_2) ? 1 : 0;
    /* Path=3, Unique=0: IL_0018: ldc.i4.0 */
    __stack1_2 = 0;
    /* Path=3, Unique=0: IL_0019: ceq */
    __stack0_0 = (__stack0_0 == __stack1_2) ? 1 : 0;
    /* Path=3, Unique=0: IL_001b: br.s IL_001e */
    goto IL_001e;
IL_001d:
    /* Path=5, Unique=0: IL_001d: ldc.i4.0 */
    __stack0_0 = 0;
IL_001e:
    /* Path=5, Unique=0: IL_001e: stloc.2 */
    local2 = __stack0_0 ? true : false;
    /* Path=5, Unique=0: IL_001f: ldloc.2 */
    __stack0_0 = local2;
    /* Path=5, Unique=0: IL_0020: brfalse.s IL_0025 */
    if (__stack0_0 == 0) goto IL_0025;
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(101): */
    /* Path=5, Unique=0: IL_0022: nop */
    /* Path=5, Unique=0: IL_0023: br.s IL_0037 */
    goto IL_0037;
IL_0025:
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(104): */
    /* Path=6, Unique=0: IL_0025: ldloc.0 */
    __stack0_0 = local0;
    /* Path=6, Unique=0: IL_0026: ldc.i4.1 */
    __stack1_2 = 1;
    /* Path=6, Unique=0: IL_0027: add */
    __stack0_0 = __stack0_0 + __stack1_2;
    /* Path=6, Unique=0: IL_0028: stloc.0 */
    local0 = __stack0_0;
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(105): */
    /* Path=6, Unique=0: IL_0029: nop */
IL_002a:
    /* Path=2, Unique=0: IL_002a: ldloc.0 */
    __stack0_0 = local0;
    /* Path=2, Unique=0: IL_002b: ldarg.0 */
    __stack1_0 = line;
    /* Path=2, Unique=0: IL_002c: callvirt System.Int32 System.String::get_Length() */
    __stack1_1 = System_String_get_Length(__stack1_0);
    /* Path=2, Unique=0: IL_0031: clt */
    __stack0_0 = (__stack0_0 < __stack1_1) ? 1 : 0;
    /* Path=2, Unique=0: IL_0033: stloc.3 */
    local3 = __stack0_0 ? true : false;
    /* Path=2, Unique=0: IL_0034: ldloc.3 */
    __stack0_0 = local3;
    /* Path=2, Unique=0: IL_0035: brtrue.s IL_0005 */
    if (__stack0_0 != 0) goto IL_0005;
IL_0037:
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(107): */
    /* Path=2, Unique=0: IL_0037: ldloc.0 */
    __stack0_0 = local0;
    /* Path=2, Unique=0: IL_0038: stloc.s local4 */
    local4 = __stack0_0;
    /* Path=2, Unique=0: IL_003a: br.s IL_003c */
    goto IL_003c;
IL_003c:
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(108): */
    /* Path=4, Unique=0: IL_003c: ldloc.s local4 */
    __stack0_0 = local4;
    /* Path=4, Unique=0: IL_003e: ret */
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
    bool local2;
    Win32_Code_OperatorNode* local3 = NULL;
    bool local4;

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
        Win32_Code_OperatorNode** plocal3;
        IL2C_CecilHelper_PseudoZeroType** p__stack0_1;
        System_String** p__stack0_2;
        Win32_Code_OperatorNode** p__stack0_4;
        System_String** p__stack1_0;
    } __executionFrame__;

    __executionFrame__.targetCount = 5;
    __executionFrame__.plocal3 = &local3;
    __executionFrame__.p__stack0_1 = &__stack0_1;
    __executionFrame__.p__stack0_2 = &__stack0_2;
    __executionFrame__.p__stack0_4 = &__stack0_4;
    __executionFrame__.p__stack1_0 = &__stack1_0;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(111): */
    /* Path=1, Unique=0: IL_0000: nop */
    /* Path=1, Unique=0: IL_0001: ldarg.1 */
    __stack0_0 = startIndex;
    /* Path=1, Unique=0: IL_0002: ldarg.0 */
    __stack1_0 = line;
    /* Path=1, Unique=0: IL_0003: callvirt System.Int32 System.String::get_Length() */
    __stack1_1 = System_String_get_Length(__stack1_0);
    /* Path=1, Unique=0: IL_0008: clt */
    __stack0_0 = (__stack0_0 < __stack1_1) ? 1 : 0;
    /* Path=1, Unique=0: IL_000a: ldc.i4.0 */
    __stack1_2 = 0;
    /* Path=1, Unique=0: IL_000b: ceq */
    __stack0_0 = (__stack0_0 == __stack1_2) ? 1 : 0;
    /* Path=1, Unique=0: IL_000d: stloc.2 */
    local2 = __stack0_0 ? true : false;
    /* Path=1, Unique=0: IL_000e: ldloc.2 */
    __stack0_0 = local2;
    /* Path=1, Unique=0: IL_000f: brfalse.s IL_0016 */
    if (__stack0_0 == 0) goto IL_0016;
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(113): */
    /* Path=1, Unique=0: IL_0011: nop */
    /* Path=1, Unique=0: IL_0012: ldnull */
    __stack0_1 = NULL;
    /* Path=1, Unique=0: IL_0013: stloc.3 */
    local3 = (Win32_Code_OperatorNode*)__stack0_1;
    /* Path=1, Unique=0: IL_0014: br.s IL_005b */
    goto IL_005b;
IL_0016:
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(117): */
    /* Path=2, Unique=0: IL_0016: ldarg.1 */
    __stack0_0 = startIndex;
    /* Path=2, Unique=0: IL_0017: stloc.0 */
    local0 = __stack0_0;
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(118): */
    /* Path=2, Unique=0: IL_0018: ldarg.0 */
    __stack0_2 = line;
    /* Path=2, Unique=0: IL_0019: ldloc.0 */
    __stack1_2 = local0;
    /* Path=2, Unique=0: IL_001a: callvirt System.Char System.String::get_Chars(System.Int32) */
    __stack0_3 = System_String_get_Chars(__stack0_2, __stack1_2);
    /* Path=2, Unique=0: IL_001f: stloc.1 */
    local1 = (wchar_t)__stack0_3;
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(119): */
    /* Path=2, Unique=0: IL_0020: ldloc.1 */
    __stack0_0 = local1;
    /* Path=2, Unique=0: IL_0021: ldc.i4.s 43 */
    __stack1_2 = 43;
    /* Path=2, Unique=0: IL_0023: beq.s IL_0039 */
    if (__stack0_0 == __stack1_2) goto IL_0039;
    /* Path=2, Unique=0: IL_0025: ldloc.1 */
    __stack0_0 = local1;
    /* Path=2, Unique=0: IL_0026: ldc.i4.s 45 */
    __stack1_2 = 45;
    /* Path=2, Unique=0: IL_0028: beq.s IL_0039 */
    if (__stack0_0 == __stack1_2) goto IL_0039;
    /* Path=2, Unique=0: IL_002a: ldloc.1 */
    __stack0_0 = local1;
    /* Path=2, Unique=0: IL_002b: ldc.i4.s 42 */
    __stack1_2 = 42;
    /* Path=2, Unique=0: IL_002d: beq.s IL_0039 */
    if (__stack0_0 == __stack1_2) goto IL_0039;
    /* Path=2, Unique=0: IL_002f: ldloc.1 */
    __stack0_0 = local1;
    /* Path=2, Unique=0: IL_0030: ldc.i4.s 47 */
    __stack1_2 = 47;
    /* Path=2, Unique=0: IL_0032: ceq */
    __stack0_0 = (__stack0_0 == __stack1_2) ? 1 : 0;
    /* Path=2, Unique=0: IL_0034: ldc.i4.0 */
    __stack1_2 = 0;
    /* Path=2, Unique=0: IL_0035: ceq */
    __stack0_0 = (__stack0_0 == __stack1_2) ? 1 : 0;
    /* Path=2, Unique=0: IL_0037: br.s IL_003a */
    goto IL_003a;
IL_0039:
    /* Path=4, Unique=0: IL_0039: ldc.i4.0 */
    __stack0_0 = 0;
IL_003a:
    /* Path=4, Unique=0: IL_003a: stloc.s local4 */
    local4 = __stack0_0 ? true : false;
    /* Path=4, Unique=0: IL_003c: ldloc.s local4 */
    __stack0_0 = local4;
    /* Path=4, Unique=0: IL_003e: brfalse.s IL_0045 */
    if (__stack0_0 == 0) goto IL_0045;
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(120): */
    /* Path=4, Unique=0: IL_0040: nop */
    /* Path=4, Unique=0: IL_0041: ldnull */
    __stack0_1 = NULL;
    /* Path=4, Unique=0: IL_0042: stloc.3 */
    local3 = (Win32_Code_OperatorNode*)__stack0_1;
    /* Path=4, Unique=0: IL_0043: br.s IL_005b */
    goto IL_005b;
IL_0045:
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(123): */
    /* Path=5, Unique=0: IL_0045: ldloc.0 */
    __stack0_0 = local0;
    /* Path=5, Unique=0: IL_0046: ldc.i4.1 */
    __stack1_2 = 1;
    /* Path=5, Unique=0: IL_0047: add */
    __stack0_0 = __stack0_0 + __stack1_2;
    /* Path=5, Unique=0: IL_0048: stloc.0 */
    local0 = __stack0_0;
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(125): */
    /* Path=5, Unique=0: IL_0049: ldarg.0 */
    __stack0_2 = line;
    /* Path=5, Unique=0: IL_004a: ldloc.0 */
    __stack1_2 = local0;
    /* Path=5, Unique=0: IL_004b: call System.Int32 Win32.Code.PolishNotation::SkipWhiteSpace(System.String,System.Int32) */
    __stack0_0 = Win32_Code_PolishNotation_SkipWhiteSpace(__stack0_2, __stack1_2);
    /* Path=5, Unique=0: IL_0050: stloc.0 */
    local0 = __stack0_0;
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(126): */
    /* Path=5, Unique=0: IL_0051: ldloc.1 */
    __stack0_0 = local1;
    /* Path=5, Unique=0: IL_0052: ldloc.0 */
    __stack1_2 = local0;
    /* Path=5, Unique=0: IL_0053: newobj System.Void Win32.Code.OperatorNode::.ctor(System.Char,System.Int32) */
    __stack0_4 = il2c_get_uninitialized_object(il2c_typeof(Win32_Code_OperatorNode));
    Win32_Code_OperatorNode__ctor(__stack0_4, (wchar_t)__stack0_0, __stack1_2);
    /* Path=5, Unique=0: IL_0058: stloc.3 */
    local3 = __stack0_4;
    /* Path=5, Unique=0: IL_0059: br.s IL_005b */
    goto IL_005b;
IL_005b:
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(127): */
    /* Path=3, Unique=0: IL_005b: ldloc.3 */
    __stack0_4 = local3;
    /* Path=3, Unique=0: IL_005c: ret */
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
    System_String* local1 = NULL;
    int32_t local2;
    bool local3;
    Win32_Code_NumericNode* local4 = NULL;
    wchar_t local5;
    bool local6;
    bool local7;
    bool local8;
    bool local9;

    //-------------------
    // Evaluation stacks:

    int32_t __stack0_0;
    IL2C_CecilHelper_PseudoZeroType* __stack0_1 = NULL;
    Win32_Code_NumericNode* __stack0_2 = NULL;
    System_String* __stack0_3 = NULL;
    int32_t __stack0_4;
    System_String* __stack0_5 = NULL;
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
        System_String** plocal1;
        Win32_Code_NumericNode** plocal4;
        IL2C_CecilHelper_PseudoZeroType** p__stack0_1;
        Win32_Code_NumericNode** p__stack0_2;
        System_String** p__stack0_3;
        System_String** p__stack0_5;
        System_String** p__stack1_0;
        int32_t** p__stack1_3;
    } __executionFrame__;

    __executionFrame__.targetCount = 8;
    __executionFrame__.plocal1 = &local1;
    __executionFrame__.plocal4 = &local4;
    __executionFrame__.p__stack0_1 = &__stack0_1;
    __executionFrame__.p__stack0_2 = &__stack0_2;
    __executionFrame__.p__stack0_3 = &__stack0_3;
    __executionFrame__.p__stack0_5 = &__stack0_5;
    __executionFrame__.p__stack1_0 = &__stack1_0;
    __executionFrame__.p__stack1_3 = &__stack1_3;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(130): */
    /* Path=1, Unique=0: IL_0000: nop */
    /* Path=1, Unique=0: IL_0001: ldarg.1 */
    __stack0_0 = startIndex;
    /* Path=1, Unique=0: IL_0002: ldarg.0 */
    __stack1_0 = line;
    /* Path=1, Unique=0: IL_0003: callvirt System.Int32 System.String::get_Length() */
    __stack1_1 = System_String_get_Length(__stack1_0);
    /* Path=1, Unique=0: IL_0008: clt */
    __stack0_0 = (__stack0_0 < __stack1_1) ? 1 : 0;
    /* Path=1, Unique=0: IL_000a: ldc.i4.0 */
    __stack1_2 = 0;
    /* Path=1, Unique=0: IL_000b: ceq */
    __stack0_0 = (__stack0_0 == __stack1_2) ? 1 : 0;
    /* Path=1, Unique=0: IL_000d: stloc.3 */
    local3 = __stack0_0 ? true : false;
    /* Path=1, Unique=0: IL_000e: ldloc.3 */
    __stack0_0 = local3;
    /* Path=1, Unique=0: IL_000f: brfalse.s IL_0017 */
    if (__stack0_0 == 0) goto IL_0017;
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(132): */
    /* Path=1, Unique=0: IL_0011: nop */
    /* Path=1, Unique=0: IL_0012: ldnull */
    __stack0_1 = NULL;
    /* Path=1, Unique=0: IL_0013: stloc.s local4 */
    local4 = (Win32_Code_NumericNode*)__stack0_1;
    /* Path=1, Unique=0: IL_0015: br.s IL_008d */
    goto IL_008d;
IL_0017:
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(136): */
    /* Path=2, Unique=0: IL_0017: ldarg.1 */
    __stack0_0 = startIndex;
    /* Path=2, Unique=0: IL_0018: stloc.0 */
    local0 = __stack0_0;
    /* Path=2, Unique=0: IL_0019: br.s IL_0039 */
    goto IL_0039;
IL_001b:
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(138): */
    /* Path=5, Unique=0: IL_001b: nop */
    /* Path=5, Unique=0: IL_001c: ldarg.0 */
    __stack0_3 = line;
    /* Path=5, Unique=0: IL_001d: ldloc.0 */
    __stack1_2 = local0;
    /* Path=5, Unique=0: IL_001e: callvirt System.Char System.String::get_Chars(System.Int32) */
    __stack0_4 = System_String_get_Chars(__stack0_3, __stack1_2);
    /* Path=5, Unique=0: IL_0023: stloc.s local5 */
    local5 = (wchar_t)__stack0_4;
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(140): */
    /* Path=5, Unique=0: IL_0025: ldloc.s local5 */
    __stack0_0 = local5;
    /* Path=5, Unique=0: IL_0027: ldc.i4.s 32 */
    __stack1_2 = 32;
    /* Path=5, Unique=0: IL_0029: ceq */
    __stack0_0 = (__stack0_0 == __stack1_2) ? 1 : 0;
    /* Path=5, Unique=0: IL_002b: stloc.s local6 */
    local6 = __stack0_0 ? true : false;
    /* Path=5, Unique=0: IL_002d: ldloc.s local6 */
    __stack0_0 = local6;
    /* Path=5, Unique=0: IL_002f: brfalse.s IL_0034 */
    if (__stack0_0 == 0) goto IL_0034;
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(141): */
    /* Path=5, Unique=0: IL_0031: nop */
    /* Path=5, Unique=0: IL_0032: br.s IL_0048 */
    goto IL_0048;
IL_0034:
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(144): */
    /* Path=7, Unique=0: IL_0034: ldloc.0 */
    __stack0_0 = local0;
    /* Path=7, Unique=0: IL_0035: ldc.i4.1 */
    __stack1_2 = 1;
    /* Path=7, Unique=0: IL_0036: add */
    __stack0_0 = __stack0_0 + __stack1_2;
    /* Path=7, Unique=0: IL_0037: stloc.0 */
    local0 = __stack0_0;
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(145): */
    /* Path=7, Unique=0: IL_0038: nop */
IL_0039:
    /* Path=4, Unique=0: IL_0039: ldloc.0 */
    __stack0_0 = local0;
    /* Path=4, Unique=0: IL_003a: ldarg.0 */
    __stack1_0 = line;
    /* Path=4, Unique=0: IL_003b: callvirt System.Int32 System.String::get_Length() */
    __stack1_1 = System_String_get_Length(__stack1_0);
    /* Path=4, Unique=0: IL_0040: clt */
    __stack0_0 = (__stack0_0 < __stack1_1) ? 1 : 0;
    /* Path=4, Unique=0: IL_0042: stloc.s local7 */
    local7 = __stack0_0 ? true : false;
    /* Path=4, Unique=0: IL_0044: ldloc.s local7 */
    __stack0_0 = local7;
    /* Path=4, Unique=0: IL_0046: brtrue.s IL_001b */
    if (__stack0_0 != 0) goto IL_001b;
IL_0048:
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(147): */
    /* Path=4, Unique=0: IL_0048: ldloc.0 */
    __stack0_0 = local0;
    /* Path=4, Unique=0: IL_0049: ldarg.1 */
    __stack1_2 = startIndex;
    /* Path=4, Unique=0: IL_004a: ceq */
    __stack0_0 = (__stack0_0 == __stack1_2) ? 1 : 0;
    /* Path=4, Unique=0: IL_004c: stloc.s local8 */
    local8 = __stack0_0 ? true : false;
    /* Path=4, Unique=0: IL_004e: ldloc.s local8 */
    __stack0_0 = local8;
    /* Path=4, Unique=0: IL_0050: brfalse.s IL_0058 */
    if (__stack0_0 == 0) goto IL_0058;
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(148): */
    /* Path=4, Unique=0: IL_0052: nop */
    /* Path=4, Unique=0: IL_0053: ldnull */
    __stack0_1 = NULL;
    /* Path=4, Unique=0: IL_0054: stloc.s local4 */
    local4 = (Win32_Code_NumericNode*)__stack0_1;
    /* Path=4, Unique=0: IL_0056: br.s IL_008d */
    goto IL_008d;
IL_0058:
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(152): */
    /* Path=6, Unique=0: IL_0058: ldarg.0 */
    __stack0_3 = line;
    /* Path=6, Unique=0: IL_0059: ldarg.1 */
    __stack1_2 = startIndex;
    /* Path=6, Unique=0: IL_005a: ldloc.0 */
    __stack2_0 = local0;
    /* Path=6, Unique=0: IL_005b: ldarg.1 */
    __stack3_0 = startIndex;
    /* Path=6, Unique=0: IL_005c: sub */
    __stack2_0 = __stack2_0 - __stack3_0;
    /* Path=6, Unique=0: IL_005d: callvirt System.String System.String::Substring(System.Int32,System.Int32) */
    __stack0_5 = System_String_Substring_1(__stack0_3, __stack1_2, __stack2_0);
    /* Path=6, Unique=0: IL_0062: stloc.1 */
    local1 = __stack0_5;
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(153): */
    /* Path=6, Unique=0: IL_0063: ldloc.1 */
    __stack0_3 = local1;
    /* Path=6, Unique=0: IL_0064: ldloca.s local2 */
    __stack1_3 = &local2;
    /* Path=6, Unique=0: IL_0066: call System.Boolean System.Int32::TryParse(System.String,System.Int32&) */
    __stack0_0 = System_Int32_TryParse(__stack0_3, __stack1_3);
    /* Path=6, Unique=0: IL_006b: ldc.i4.0 */
    __stack1_2 = 0;
    /* Path=6, Unique=0: IL_006c: ceq */
    __stack0_0 = (__stack0_0 == __stack1_2) ? 1 : 0;
    /* Path=6, Unique=0: IL_006e: stloc.s local9 */
    local9 = __stack0_0 ? true : false;
    /* Path=6, Unique=0: IL_0070: ldloc.s local9 */
    __stack0_0 = local9;
    /* Path=6, Unique=0: IL_0072: brfalse.s IL_007a */
    if (__stack0_0 == 0) goto IL_007a;
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(154): */
    /* Path=6, Unique=0: IL_0074: nop */
    /* Path=6, Unique=0: IL_0075: ldnull */
    __stack0_1 = NULL;
    /* Path=6, Unique=0: IL_0076: stloc.s local4 */
    local4 = (Win32_Code_NumericNode*)__stack0_1;
    /* Path=6, Unique=0: IL_0078: br.s IL_008d */
    goto IL_008d;
IL_007a:
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(158): */
    /* Path=8, Unique=0: IL_007a: ldarg.0 */
    __stack0_3 = line;
    /* Path=8, Unique=0: IL_007b: ldloc.0 */
    __stack1_2 = local0;
    /* Path=8, Unique=0: IL_007c: call System.Int32 Win32.Code.PolishNotation::SkipWhiteSpace(System.String,System.Int32) */
    __stack0_0 = Win32_Code_PolishNotation_SkipWhiteSpace(__stack0_3, __stack1_2);
    /* Path=8, Unique=0: IL_0081: stloc.0 */
    local0 = __stack0_0;
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(159): */
    /* Path=8, Unique=0: IL_0082: ldloc.2 */
    __stack0_0 = local2;
    /* Path=8, Unique=0: IL_0083: ldloc.0 */
    __stack1_2 = local0;
    /* Path=8, Unique=0: IL_0084: newobj System.Void Win32.Code.NumericNode::.ctor(System.Int32,System.Int32) */
    __stack0_2 = il2c_get_uninitialized_object(il2c_typeof(Win32_Code_NumericNode));
    Win32_Code_NumericNode__ctor(__stack0_2, __stack0_0, __stack1_2);
    /* Path=8, Unique=0: IL_0089: stloc.s local4 */
    local4 = __stack0_2;
    /* Path=8, Unique=0: IL_008b: br.s IL_008d */
    goto IL_008d;
IL_008d:
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(160): */
    /* Path=3, Unique=0: IL_008d: ldloc.s local4 */
    __stack0_2 = local4;
    /* Path=3, Unique=0: IL_008f: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return __stack0_2;
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
    bool local4;
    Win32_Code_ExpressionNode* local5 = NULL;
    bool local6;
    bool local7;
    bool local8;
    bool local9;
    bool local10;

    //-------------------
    // Evaluation stacks:

    int32_t __stack0_0;
    IL2C_CecilHelper_PseudoZeroType* __stack0_1 = NULL;
    System_String* __stack0_2 = NULL;
    Win32_Code_OperatorNode* __stack0_3 = NULL;
    Win32_Code_ExpressionNode* __stack0_4 = NULL;
    Win32_Code_NumericNode* __stack0_5 = NULL;
    Win32_Code_ReducibleNode* __stack0_6 = NULL;
    System_String* __stack1_0 = NULL;
    int32_t __stack1_1;
    int32_t __stack1_2;
    IL2C_CecilHelper_PseudoZeroType* __stack1_3 = NULL;
    Win32_Code_OperatorNode* __stack1_4 = NULL;
    Win32_Code_ReducibleNode* __stack1_5 = NULL;
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
        Win32_Code_ExpressionNode** plocal5;
        IL2C_CecilHelper_PseudoZeroType** p__stack0_1;
        System_String** p__stack0_2;
        Win32_Code_OperatorNode** p__stack0_3;
        Win32_Code_ExpressionNode** p__stack0_4;
        Win32_Code_NumericNode** p__stack0_5;
        Win32_Code_ReducibleNode** p__stack0_6;
        System_String** p__stack1_0;
        IL2C_CecilHelper_PseudoZeroType** p__stack1_3;
        Win32_Code_OperatorNode** p__stack1_4;
        Win32_Code_ReducibleNode** p__stack1_5;
        Win32_Code_ReducibleNode** p__stack2_0;
    } __executionFrame__;

    __executionFrame__.targetCount = 15;
    __executionFrame__.plocal0 = &local0;
    __executionFrame__.plocal1 = &local1;
    __executionFrame__.plocal2 = &local2;
    __executionFrame__.plocal5 = &local5;
    __executionFrame__.p__stack0_1 = &__stack0_1;
    __executionFrame__.p__stack0_2 = &__stack0_2;
    __executionFrame__.p__stack0_3 = &__stack0_3;
    __executionFrame__.p__stack0_4 = &__stack0_4;
    __executionFrame__.p__stack0_5 = &__stack0_5;
    __executionFrame__.p__stack0_6 = &__stack0_6;
    __executionFrame__.p__stack1_0 = &__stack1_0;
    __executionFrame__.p__stack1_3 = &__stack1_3;
    __executionFrame__.p__stack1_4 = &__stack1_4;
    __executionFrame__.p__stack1_5 = &__stack1_5;
    __executionFrame__.p__stack2_0 = &__stack2_0;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(163): */
    /* Path=1, Unique=0: IL_0000: nop */
    /* Path=1, Unique=0: IL_0001: ldarg.1 */
    __stack0_0 = startIndex;
    /* Path=1, Unique=0: IL_0002: ldarg.0 */
    __stack1_0 = line;
    /* Path=1, Unique=0: IL_0003: callvirt System.Int32 System.String::get_Length() */
    __stack1_1 = System_String_get_Length(__stack1_0);
    /* Path=1, Unique=0: IL_0008: clt */
    __stack0_0 = (__stack0_0 < __stack1_1) ? 1 : 0;
    /* Path=1, Unique=0: IL_000a: ldc.i4.0 */
    __stack1_2 = 0;
    /* Path=1, Unique=0: IL_000b: ceq */
    __stack0_0 = (__stack0_0 == __stack1_2) ? 1 : 0;
    /* Path=1, Unique=0: IL_000d: stloc.s local4 */
    local4 = __stack0_0 ? true : false;
    /* Path=1, Unique=0: IL_000f: ldloc.s local4 */
    __stack0_0 = local4;
    /* Path=1, Unique=0: IL_0011: brfalse.s IL_001c */
    if (__stack0_0 == 0) goto IL_001c;
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(165): */
    /* Path=1, Unique=0: IL_0013: nop */
    /* Path=1, Unique=0: IL_0014: ldnull */
    __stack0_1 = NULL;
    /* Path=1, Unique=0: IL_0015: stloc.s local5 */
    local5 = (Win32_Code_ExpressionNode*)__stack0_1;
    /* Path=1, Unique=0: IL_0017: br IL_00bd */
    goto IL_00bd;
IL_001c:
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(169): */
    /* Path=2, Unique=0: IL_001c: ldarg.0 */
    __stack0_2 = line;
    /* Path=2, Unique=0: IL_001d: ldarg.1 */
    __stack1_2 = startIndex;
    /* Path=2, Unique=0: IL_001e: call Win32.Code.OperatorNode Win32.Code.PolishNotation::ParseOperator(System.String,System.Int32) */
    __stack0_3 = Win32_Code_PolishNotation_ParseOperator(__stack0_2, __stack1_2);
    /* Path=2, Unique=0: IL_0023: stloc.0 */
    local0 = __stack0_3;
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(170): */
    /* Path=2, Unique=0: IL_0024: ldloc.0 */
    __stack0_3 = local0;
    /* Path=2, Unique=0: IL_0025: ldnull */
    __stack1_3 = NULL;
    /* Path=2, Unique=0: IL_0026: ceq */
    __stack0_0 = (__stack0_3 == ((Win32_Code_OperatorNode*)__stack1_3)) ? 1 : 0;
    /* Path=2, Unique=0: IL_0028: stloc.s local6 */
    local6 = __stack0_0 ? true : false;
    /* Path=2, Unique=0: IL_002a: ldloc.s local6 */
    __stack0_0 = local6;
    /* Path=2, Unique=0: IL_002c: brfalse.s IL_0037 */
    if (__stack0_0 == 0) goto IL_0037;
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(171): */
    /* Path=2, Unique=0: IL_002e: nop */
    /* Path=2, Unique=0: IL_002f: ldnull */
    __stack0_1 = NULL;
    /* Path=2, Unique=0: IL_0030: stloc.s local5 */
    local5 = (Win32_Code_ExpressionNode*)__stack0_1;
    /* Path=2, Unique=0: IL_0032: br IL_00bd */
    goto IL_00bd;
IL_0037:
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(175): */
    /* Path=4, Unique=0: IL_0037: ldarg.0 */
    __stack0_2 = line;
    /* Path=4, Unique=0: IL_0038: ldloc.0 */
    __stack1_4 = local0;
    /* Path=4, Unique=0: IL_0039: ldfld System.Int32 Win32.Code.AbstractNode::NextIndex */
    __stack1_2 = __stack1_4->NextIndex;
    /* Path=4, Unique=0: IL_003e: call Win32.Code.NumericNode Win32.Code.PolishNotation::ParseNumeric(System.String,System.Int32) */
    __stack0_5 = Win32_Code_PolishNotation_ParseNumeric(__stack0_2, __stack1_2);
    /* Path=4, Unique=0: IL_0043: stloc.1 */
    local1 = (Win32_Code_ReducibleNode*)__stack0_5;
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(176): */
    /* Path=4, Unique=0: IL_0044: ldloc.1 */
    __stack0_6 = local1;
    /* Path=4, Unique=0: IL_0045: ldnull */
    __stack1_3 = NULL;
    /* Path=4, Unique=0: IL_0046: ceq */
    __stack0_0 = (__stack0_6 == ((Win32_Code_ReducibleNode*)__stack1_3)) ? 1 : 0;
    /* Path=4, Unique=0: IL_0048: stloc.s local7 */
    local7 = __stack0_0 ? true : false;
    /* Path=4, Unique=0: IL_004a: ldloc.s local7 */
    __stack0_0 = local7;
    /* Path=4, Unique=0: IL_004c: brfalse.s IL_006d */
    if (__stack0_0 == 0) goto IL_006d;
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(177): */
    /* Path=4, Unique=0: IL_004e: nop */
    /* Path=4, Unique=0: IL_004f: ldarg.0 */
    __stack0_2 = line;
    /* Path=4, Unique=0: IL_0050: ldloc.0 */
    __stack1_4 = local0;
    /* Path=4, Unique=0: IL_0051: ldfld System.Int32 Win32.Code.AbstractNode::NextIndex */
    __stack1_2 = __stack1_4->NextIndex;
    /* Path=4, Unique=0: IL_0056: call Win32.Code.ExpressionNode Win32.Code.PolishNotation::ParseExpression(System.String,System.Int32) */
    __stack0_4 = Win32_Code_PolishNotation_ParseExpression(__stack0_2, __stack1_2);
    /* Path=4, Unique=0: IL_005b: stloc.1 */
    local1 = (Win32_Code_ReducibleNode*)__stack0_4;
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(179): */
    /* Path=4, Unique=0: IL_005c: ldloc.1 */
    __stack0_6 = local1;
    /* Path=4, Unique=0: IL_005d: ldnull */
    __stack1_3 = NULL;
    /* Path=4, Unique=0: IL_005e: ceq */
    __stack0_0 = (__stack0_6 == ((Win32_Code_ReducibleNode*)__stack1_3)) ? 1 : 0;
    /* Path=4, Unique=0: IL_0060: stloc.s local8 */
    local8 = __stack0_0 ? true : false;
    /* Path=4, Unique=0: IL_0062: ldloc.s local8 */
    __stack0_0 = local8;
    /* Path=4, Unique=0: IL_0064: brfalse.s IL_006c */
    if (__stack0_0 == 0) goto IL_006c;
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(180): */
    /* Path=4, Unique=0: IL_0066: nop */
    /* Path=4, Unique=0: IL_0067: ldnull */
    __stack0_1 = NULL;
    /* Path=4, Unique=0: IL_0068: stloc.s local5 */
    local5 = (Win32_Code_ExpressionNode*)__stack0_1;
    /* Path=4, Unique=0: IL_006a: br.s IL_00bd */
    goto IL_00bd;
IL_006c:
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(183): */
    /* Path=6, Unique=0: IL_006c: nop */
IL_006d:
    /* Path=5, Unique=0: IL_006d: ldarg.0 */
    __stack0_2 = line;
    /* Path=5, Unique=0: IL_006e: ldloc.1 */
    __stack1_5 = local1;
    /* Path=5, Unique=0: IL_006f: ldfld System.Int32 Win32.Code.AbstractNode::NextIndex */
    __stack1_2 = __stack1_5->NextIndex;
    /* Path=5, Unique=0: IL_0074: call Win32.Code.NumericNode Win32.Code.PolishNotation::ParseNumeric(System.String,System.Int32) */
    __stack0_5 = Win32_Code_PolishNotation_ParseNumeric(__stack0_2, __stack1_2);
    /* Path=5, Unique=0: IL_0079: stloc.2 */
    local2 = (Win32_Code_ReducibleNode*)__stack0_5;
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(186): */
    /* Path=5, Unique=0: IL_007a: ldloc.2 */
    __stack0_6 = local2;
    /* Path=5, Unique=0: IL_007b: ldnull */
    __stack1_3 = NULL;
    /* Path=5, Unique=0: IL_007c: ceq */
    __stack0_0 = (__stack0_6 == ((Win32_Code_ReducibleNode*)__stack1_3)) ? 1 : 0;
    /* Path=5, Unique=0: IL_007e: stloc.s local9 */
    local9 = __stack0_0 ? true : false;
    /* Path=5, Unique=0: IL_0080: ldloc.s local9 */
    __stack0_0 = local9;
    /* Path=5, Unique=0: IL_0082: brfalse.s IL_00a3 */
    if (__stack0_0 == 0) goto IL_00a3;
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(187): */
    /* Path=5, Unique=0: IL_0084: nop */
    /* Path=5, Unique=0: IL_0085: ldarg.0 */
    __stack0_2 = line;
    /* Path=5, Unique=0: IL_0086: ldloc.1 */
    __stack1_5 = local1;
    /* Path=5, Unique=0: IL_0087: ldfld System.Int32 Win32.Code.AbstractNode::NextIndex */
    __stack1_2 = __stack1_5->NextIndex;
    /* Path=5, Unique=0: IL_008c: call Win32.Code.ExpressionNode Win32.Code.PolishNotation::ParseExpression(System.String,System.Int32) */
    __stack0_4 = Win32_Code_PolishNotation_ParseExpression(__stack0_2, __stack1_2);
    /* Path=5, Unique=0: IL_0091: stloc.2 */
    local2 = (Win32_Code_ReducibleNode*)__stack0_4;
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(189): */
    /* Path=5, Unique=0: IL_0092: ldloc.2 */
    __stack0_6 = local2;
    /* Path=5, Unique=0: IL_0093: ldnull */
    __stack1_3 = NULL;
    /* Path=5, Unique=0: IL_0094: ceq */
    __stack0_0 = (__stack0_6 == ((Win32_Code_ReducibleNode*)__stack1_3)) ? 1 : 0;
    /* Path=5, Unique=0: IL_0096: stloc.s local10 */
    local10 = __stack0_0 ? true : false;
    /* Path=5, Unique=0: IL_0098: ldloc.s local10 */
    __stack0_0 = local10;
    /* Path=5, Unique=0: IL_009a: brfalse.s IL_00a2 */
    if (__stack0_0 == 0) goto IL_00a2;
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(190): */
    /* Path=5, Unique=0: IL_009c: nop */
    /* Path=5, Unique=0: IL_009d: ldnull */
    __stack0_1 = NULL;
    /* Path=5, Unique=0: IL_009e: stloc.s local5 */
    local5 = (Win32_Code_ExpressionNode*)__stack0_1;
    /* Path=5, Unique=0: IL_00a0: br.s IL_00bd */
    goto IL_00bd;
IL_00a2:
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(193): */
    /* Path=8, Unique=0: IL_00a2: nop */
IL_00a3:
    /* Path=7, Unique=0: IL_00a3: ldarg.0 */
    __stack0_2 = line;
    /* Path=7, Unique=0: IL_00a4: ldloc.2 */
    __stack1_5 = local2;
    /* Path=7, Unique=0: IL_00a5: ldfld System.Int32 Win32.Code.AbstractNode::NextIndex */
    __stack1_2 = __stack1_5->NextIndex;
    /* Path=7, Unique=0: IL_00aa: call System.Int32 Win32.Code.PolishNotation::SkipWhiteSpace(System.String,System.Int32) */
    __stack0_0 = Win32_Code_PolishNotation_SkipWhiteSpace(__stack0_2, __stack1_2);
    /* Path=7, Unique=0: IL_00af: stloc.3 */
    local3 = __stack0_0;
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(196): */
    /* Path=7, Unique=0: IL_00b0: ldloc.0 */
    __stack0_3 = local0;
    /* Path=7, Unique=0: IL_00b1: ldloc.1 */
    __stack1_5 = local1;
    /* Path=7, Unique=0: IL_00b2: ldloc.2 */
    __stack2_0 = local2;
    /* Path=7, Unique=0: IL_00b3: ldloc.3 */
    __stack3_0 = local3;
    /* Path=7, Unique=0: IL_00b4: newobj System.Void Win32.Code.ExpressionNode::.ctor(Win32.Code.OperatorNode,Win32.Code.ReducibleNode,Win32.Code.ReducibleNode,System.Int32) */
    __stack0_4 = il2c_get_uninitialized_object(il2c_typeof(Win32_Code_ExpressionNode));
    Win32_Code_ExpressionNode__ctor(__stack0_4, __stack0_3, __stack1_5, __stack2_0, __stack3_0);
    /* Path=7, Unique=0: IL_00b9: stloc.s local5 */
    local5 = __stack0_4;
    /* Path=7, Unique=0: IL_00bb: br.s IL_00bd */
    goto IL_00bd;
IL_00bd:
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(197): */
    /* Path=3, Unique=0: IL_00bd: ldloc.s local5 */
    __stack0_4 = local5;
    /* Path=3, Unique=0: IL_00bf: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return __stack0_4;
}

///////////////////////////////////////
// Main

void Win32_Code_PolishNotation_Main(void)
{
    //-------------------
    // Local variables:

    System_String* local0 = NULL;
    bool local1;
    Win32_Code_ExpressionNode* local2 = NULL;
    int32_t local3;
    bool local4;
    bool local5;
    bool local6;

    //-------------------
    // Evaluation stacks:

    int32_t __stack0_0;
    System_String* __stack0_1 = NULL;
    Win32_Code_ExpressionNode* __stack0_2 = NULL;
    int32_t __stack1_0;
    System_String* __stack1_1 = NULL;
    IL2C_CecilHelper_PseudoZeroType* __stack1_2 = NULL;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        System_String** plocal0;
        Win32_Code_ExpressionNode** plocal2;
        System_String** p__stack0_1;
        Win32_Code_ExpressionNode** p__stack0_2;
        System_String** p__stack1_1;
        IL2C_CecilHelper_PseudoZeroType** p__stack1_2;
    } __executionFrame__;

    __executionFrame__.targetCount = 6;
    __executionFrame__.plocal0 = &local0;
    __executionFrame__.plocal2 = &local2;
    __executionFrame__.p__stack0_1 = &__stack0_1;
    __executionFrame__.p__stack0_2 = &__stack0_2;
    __executionFrame__.p__stack1_1 = &__stack1_1;
    __executionFrame__.p__stack1_2 = &__stack1_2;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(200): */
    /* Path=1, Unique=0: IL_0000: nop */
    /* Path=1, Unique=0: IL_0001: br.s IL_0078 */
    goto IL_0078;
IL_0003:
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(202): */
    /* Path=3, Unique=0: IL_0003: nop */
    /* Path=3, Unique=0: IL_0004: call System.Void System.Console::WriteLine() */
    System_Console_WriteLine();
    /* Path=3, Unique=0: IL_0009: nop */
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(204): */
    /* Path=3, Unique=0: IL_000a: ldstr "PN> " */
    __stack0_1 = __string0;
    /* Path=3, Unique=0: IL_000f: call System.Void System.Console::Write(System.String) */
    System_Console_Write_9(__stack0_1);
    /* Path=3, Unique=0: IL_0014: nop */
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(205): */
    /* Path=3, Unique=0: IL_0015: call System.String System.Console::ReadLine() */
    __stack0_1 = System_Console_ReadLine();
    /* Path=3, Unique=0: IL_001a: stloc.0 */
    local0 = __stack0_1;
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(206): */
    /* Path=3, Unique=0: IL_001b: ldloc.0 */
    __stack0_1 = local0;
    /* Path=3, Unique=0: IL_001c: call System.Boolean System.String::IsNullOrWhiteSpace(System.String) */
    __stack0_0 = System_String_IsNullOrWhiteSpace(__stack0_1);
    /* Path=3, Unique=0: IL_0021: ldc.i4.0 */
    __stack1_0 = 0;
    /* Path=3, Unique=0: IL_0022: ceq */
    __stack0_0 = (__stack0_0 == __stack1_0) ? 1 : 0;
    /* Path=3, Unique=0: IL_0024: stloc.1 */
    local1 = __stack0_0 ? true : false;
    /* Path=3, Unique=0: IL_0025: ldloc.1 */
    __stack0_0 = local1;
    /* Path=3, Unique=0: IL_0026: brfalse.s IL_0077 */
    if (__stack0_0 == 0) goto IL_0077;
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(207): */
    /* Path=3, Unique=0: IL_0028: nop */
    /* Path=3, Unique=0: IL_0029: ldloc.0 */
    __stack0_1 = local0;
    /* Path=3, Unique=0: IL_002a: ldstr "exit" */
    __stack1_1 = __string1;
    /* Path=3, Unique=0: IL_002f: call System.Boolean System.String::op_Equality(System.String,System.String) */
    __stack0_0 = System_String_op_Equality(__stack0_1, __stack1_1);
    /* Path=3, Unique=0: IL_0034: stloc.s local4 */
    local4 = __stack0_0 ? true : false;
    /* Path=3, Unique=0: IL_0036: ldloc.s local4 */
    __stack0_0 = local4;
    /* Path=3, Unique=0: IL_0038: brfalse.s IL_003d */
    if (__stack0_0 == 0) goto IL_003d;
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(209): */
    /* Path=3, Unique=0: IL_003a: nop */
    /* Path=3, Unique=0: IL_003b: br.s IL_007d */
    goto IL_007d;
IL_003d:
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(213): */
    /* Path=5, Unique=0: IL_003d: ldloc.0 */
    __stack0_1 = local0;
    /* Path=5, Unique=0: IL_003e: ldc.i4.0 */
    __stack1_0 = 0;
    /* Path=5, Unique=0: IL_003f: call Win32.Code.ExpressionNode Win32.Code.PolishNotation::ParseExpression(System.String,System.Int32) */
    __stack0_2 = Win32_Code_PolishNotation_ParseExpression(__stack0_1, __stack1_0);
    /* Path=5, Unique=0: IL_0044: stloc.2 */
    local2 = __stack0_2;
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(214): */
    /* Path=5, Unique=0: IL_0045: ldloc.2 */
    __stack0_2 = local2;
    /* Path=5, Unique=0: IL_0046: ldnull */
    __stack1_2 = NULL;
    /* Path=5, Unique=0: IL_0047: ceq */
    __stack0_0 = (__stack0_2 == ((Win32_Code_ExpressionNode*)__stack1_2)) ? 1 : 0;
    /* Path=5, Unique=0: IL_0049: stloc.s local5 */
    local5 = __stack0_0 ? true : false;
    /* Path=5, Unique=0: IL_004b: ldloc.s local5 */
    __stack0_0 = local5;
    /* Path=5, Unique=0: IL_004d: brfalse.s IL_005d */
    if (__stack0_0 == 0) goto IL_005d;
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(215): */
    /* Path=5, Unique=0: IL_004f: nop */
    /* Path=5, Unique=0: IL_0050: ldstr "Syntax error." */
    __stack0_1 = __string2;
    /* Path=5, Unique=0: IL_0055: call System.Void System.Console::WriteLine(System.String) */
    System_Console_WriteLine_10(__stack0_1);
    /* Path=5, Unique=0: IL_005a: nop */
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(217): */
    /* Path=5, Unique=0: IL_005b: br.s IL_0078 */
    goto IL_0078;
IL_005d:
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(220): */
    /* Path=7, Unique=0: IL_005d: ldloc.2 */
    __stack0_2 = local2;
    /* Path=7, Unique=0: IL_005e: callvirt System.Int32 Win32.Code.ReducibleNode::Reduce() */
    __stack0_0 = Win32_Code_ReducibleNode_Reduce((Win32_Code_ReducibleNode*)__stack0_2);
    /* Path=7, Unique=0: IL_0063: stloc.3 */
    local3 = __stack0_0;
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(222): */
    /* Path=7, Unique=0: IL_0064: ldstr "Reuslt=" */
    __stack0_1 = __string3;
    /* Path=7, Unique=0: IL_0069: call System.Void System.Console::Write(System.String) */
    System_Console_Write_9(__stack0_1);
    /* Path=7, Unique=0: IL_006e: nop */
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(223): */
    /* Path=7, Unique=0: IL_006f: ldloc.3 */
    __stack0_0 = local3;
    /* Path=7, Unique=0: IL_0070: call System.Void System.Console::WriteLine(System.Int32) */
    System_Console_WriteLine_6(__stack0_0);
    /* Path=7, Unique=0: IL_0075: nop */
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(224): */
    /* Path=7, Unique=0: IL_0076: nop */
IL_0077:
    /* Path=4, Unique=0: IL_0077: nop */
IL_0078:
    /* Path=2, Unique=0: IL_0078: ldc.i4.1 */
    __stack0_0 = 1;
    /* Path=2, Unique=0: IL_0079: stloc.s local6 */
    local6 = __stack0_0 ? true : false;
    /* Path=2, Unique=0: IL_007b: br.s IL_0003 */
    goto IL_0003;
IL_007d:
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(226): */
    /* Path=6, Unique=0: IL_007d: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return;
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
    /* Path=1, Unique=0: IL_0006: nop */
    /* Path=1, Unique=0: IL_0007: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return;
}

//////////////////////
// Runtime helpers:

void* __Win32_Code_PolishNotation_IL2C_RuntimeCast__(Win32_Code_PolishNotation* this__, IL2C_RUNTIME_TYPE_DECL* type)
{
    if (type == il2c_typeof(System_Object)) return this__;
    return __System_Object_IL2C_RuntimeCast__((System_Object*)this__, type);
}

static void __Win32_Code_PolishNotation_MARK_HANDLER__(void* pReference)
{
    il2c_typeof(System_Object)->pMarkHandler(pReference);
}

static __Win32_Code_PolishNotation_VTABLE_DECL__ __Win32_Code_PolishNotation_VTABLE__ = {
    __Win32_Code_PolishNotation_IL2C_RuntimeCast__,
    (void*)__System_Object_ToString__,
    (void*)__System_Object_GetHashCode__,
    (void*)__System_Object_Finalize__,
    (void*)__System_Object_Equals__,
};

IL2C_RUNTIME_TYPE_DECL __Win32_Code_PolishNotation_RUNTIME_TYPE__ = {
    "Win32.Code.PolishNotation",
    sizeof(Win32_Code_PolishNotation),
    __Win32_Code_PolishNotation_MARK_HANDLER__,
};

////////////////////////////////////////////////////////////
// Type: Win32.Code.StringTest

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

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        System_String** plocal0;
        System_String** p__stack0_0;
    } __executionFrame__;

    __executionFrame__.targetCount = 2;
    __executionFrame__.plocal0 = &local0;
    __executionFrame__.p__stack0_0 = &__stack0_0;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\StringTest.cs(12): */
    /* Path=1, Unique=0: IL_0000: nop */
    /* Path=1, Unique=0: IL_0001: ldstr "ABC" */
    __stack0_0 = __string4;
    /* Path=1, Unique=0: IL_0006: stloc.0 */
    local0 = __stack0_0;
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\StringTest.cs(14): */
    /* Path=1, Unique=0: IL_0007: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
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

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        System_String** plocal0;
        System_String** p__stack0_0;
    } __executionFrame__;

    __executionFrame__.targetCount = 2;
    __executionFrame__.plocal0 = &local0;
    __executionFrame__.p__stack0_0 = &__stack0_0;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\StringTest.cs(17): */
    /* Path=1, Unique=0: IL_0000: nop */
    /* Path=1, Unique=0: IL_0001: ldarg.0 */
    __stack0_0 = a;
    /* Path=1, Unique=0: IL_0002: stloc.0 */
    local0 = __stack0_0;
    /* Path=1, Unique=0: IL_0003: br.s IL_0005 */
    goto IL_0005;
IL_0005:
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\StringTest.cs(19): */
    /* Path=2, Unique=0: IL_0005: ldloc.0 */
    __stack0_0 = local0;
    /* Path=2, Unique=0: IL_0006: ret */
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
    System_String* local1 = NULL;
    System_String* local2 = NULL;

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
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\StringTest.cs(22): */
    /* Path=1, Unique=0: IL_0000: nop */
    /* Path=1, Unique=0: IL_0001: ldstr "ABC" */
    __stack0_0 = __string4;
    /* Path=1, Unique=0: IL_0006: stloc.0 */
    local0 = __stack0_0;
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\StringTest.cs(24): */
    /* Path=1, Unique=0: IL_0007: ldstr "DEF" */
    __stack0_0 = __string5;
    /* Path=1, Unique=0: IL_000c: stloc.1 */
    local1 = __stack0_0;
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\StringTest.cs(25): */
    /* Path=1, Unique=0: IL_000d: ldloc.0 */
    __stack0_0 = local0;
    /* Path=1, Unique=0: IL_000e: ldloc.1 */
    __stack1_0 = local1;
    /* Path=1, Unique=0: IL_000f: call System.String System.String::Concat(System.String,System.String) */
    __stack0_0 = System_String_Concat_6(__stack0_0, __stack1_0);
    /* Path=1, Unique=0: IL_0014: stloc.2 */
    local2 = __stack0_0;
    /* Path=1, Unique=0: IL_0015: br.s IL_0017 */
    goto IL_0017;
IL_0017:
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\StringTest.cs(26): */
    /* Path=2, Unique=0: IL_0017: ldloc.2 */
    __stack0_0 = local2;
    /* Path=2, Unique=0: IL_0018: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return __stack0_0;
}

///////////////////////////////////////
// LiteralSubstring

System_String* Win32_Code_StringTest_LiteralSubstring(void)
{
    //-------------------
    // Local variables:

    System_String* local0 = NULL;
    System_String* local1 = NULL;

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
        System_String** plocal0;
        System_String** plocal1;
        System_String** p__stack0_0;
        System_String** p__stack0_1;
    } __executionFrame__;

    __executionFrame__.targetCount = 4;
    __executionFrame__.plocal0 = &local0;
    __executionFrame__.plocal1 = &local1;
    __executionFrame__.p__stack0_0 = &__stack0_0;
    __executionFrame__.p__stack0_1 = &__stack0_1;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\StringTest.cs(29): */
    /* Path=1, Unique=0: IL_0000: nop */
    /* Path=1, Unique=0: IL_0001: ldstr "ABCDEFGHIJKLMN" */
    __stack0_0 = __string6;
    /* Path=1, Unique=0: IL_0006: stloc.0 */
    local0 = __stack0_0;
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\StringTest.cs(31): */
    /* Path=1, Unique=0: IL_0007: ldloc.0 */
    __stack0_0 = local0;
    /* Path=1, Unique=0: IL_0008: ldc.i4.3 */
    __stack1_0 = 3;
    /* Path=1, Unique=0: IL_0009: callvirt System.String System.String::Substring(System.Int32) */
    __stack0_1 = System_String_Substring(__stack0_0, __stack1_0);
    /* Path=1, Unique=0: IL_000e: stloc.1 */
    local1 = __stack0_1;
    /* Path=1, Unique=0: IL_000f: br.s IL_0011 */
    goto IL_0011;
IL_0011:
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\StringTest.cs(32): */
    /* Path=2, Unique=0: IL_0011: ldloc.1 */
    __stack0_0 = local1;
    /* Path=2, Unique=0: IL_0012: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return __stack0_0;
}

///////////////////////////////////////
// GetChar

wchar_t Win32_Code_StringTest_GetChar(void)
{
    //-------------------
    // Local variables:

    wchar_t local0;

    //-------------------
    // Evaluation stacks:

    int32_t __stack0_0;

    //-------------------
    // IL body:

/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\StringTest.cs(35): */
    /* Path=1, Unique=0: IL_0000: nop */
    /* Path=1, Unique=0: IL_0001: ldc.i4.s 65 */
    __stack0_0 = 65;
    /* Path=1, Unique=0: IL_0003: stloc.0 */
    local0 = (wchar_t)__stack0_0;
    /* Path=1, Unique=0: IL_0004: br.s IL_0006 */
    goto IL_0006;
IL_0006:
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\StringTest.cs(37): */
    /* Path=2, Unique=0: IL_0006: ldloc.0 */
    __stack0_0 = local0;
    /* Path=2, Unique=0: IL_0007: ret */
    return (wchar_t)__stack0_0;
}

///////////////////////////////////////
// GetCharByIndex

wchar_t Win32_Code_StringTest_GetCharByIndex(System_String* str, int32_t index)
{
    //-------------------
    // Local variables:

    wchar_t local0;

    //-------------------
    // Evaluation stacks:

    System_String* __stack0_0 = NULL;
    int32_t __stack0_1;
    int32_t __stack0_2;
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

/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\StringTest.cs(40): */
    /* Path=1, Unique=0: IL_0000: nop */
    /* Path=1, Unique=0: IL_0001: ldarg.0 */
    __stack0_0 = str;
    /* Path=1, Unique=0: IL_0002: ldarg.1 */
    __stack1_0 = index;
    /* Path=1, Unique=0: IL_0003: callvirt System.Char System.String::get_Chars(System.Int32) */
    __stack0_1 = System_String_get_Chars(__stack0_0, __stack1_0);
    /* Path=1, Unique=0: IL_0008: stloc.0 */
    local0 = (wchar_t)__stack0_1;
    /* Path=1, Unique=0: IL_0009: br.s IL_000b */
    goto IL_000b;
IL_000b:
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\StringTest.cs(42): */
    /* Path=2, Unique=0: IL_000b: ldloc.0 */
    __stack0_2 = local0;
    /* Path=2, Unique=0: IL_000c: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return (wchar_t)__stack0_2;
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
    /* Path=1, Unique=0: IL_0006: nop */
    /* Path=1, Unique=0: IL_0007: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return;
}

//////////////////////
// Runtime helpers:

void* __Win32_Code_StringTest_IL2C_RuntimeCast__(Win32_Code_StringTest* this__, IL2C_RUNTIME_TYPE_DECL* type)
{
    if (type == il2c_typeof(System_Object)) return this__;
    return __System_Object_IL2C_RuntimeCast__((System_Object*)this__, type);
}

static void __Win32_Code_StringTest_MARK_HANDLER__(void* pReference)
{
    il2c_typeof(System_Object)->pMarkHandler(pReference);
}

static __Win32_Code_StringTest_VTABLE_DECL__ __Win32_Code_StringTest_VTABLE__ = {
    __Win32_Code_StringTest_IL2C_RuntimeCast__,
    (void*)__System_Object_ToString__,
    (void*)__System_Object_GetHashCode__,
    (void*)__System_Object_Finalize__,
    (void*)__System_Object_Equals__,
};

IL2C_RUNTIME_TYPE_DECL __Win32_Code_StringTest_RUNTIME_TYPE__ = {
    "Win32.Code.StringTest",
    sizeof(Win32_Code_StringTest),
    __Win32_Code_StringTest_MARK_HANDLER__,
};

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
    /* Path=1, Unique=0: IL_0006: nop */
    /* Path=1, Unique=0: IL_0007: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return;
}

//////////////////////
// Runtime helpers:

void* __Win32_Code_UnsafeTest_IL2C_RuntimeCast__(Win32_Code_UnsafeTest* this__, IL2C_RUNTIME_TYPE_DECL* type)
{
    if (type == il2c_typeof(System_Object)) return this__;
    return __System_Object_IL2C_RuntimeCast__((System_Object*)this__, type);
}

static void __Win32_Code_UnsafeTest_MARK_HANDLER__(void* pReference)
{
    il2c_typeof(System_Object)->pMarkHandler(pReference);
}

static __Win32_Code_UnsafeTest_VTABLE_DECL__ __Win32_Code_UnsafeTest_VTABLE__ = {
    __Win32_Code_UnsafeTest_IL2C_RuntimeCast__,
    (void*)__System_Object_ToString__,
    (void*)__System_Object_GetHashCode__,
    (void*)__System_Object_Finalize__,
    (void*)__System_Object_Equals__,
};

IL2C_RUNTIME_TYPE_DECL __Win32_Code_UnsafeTest_RUNTIME_TYPE__ = {
    "Win32.Code.UnsafeTest",
    sizeof(Win32_Code_UnsafeTest),
    __Win32_Code_UnsafeTest_MARK_HANDLER__,
};

////////////////////////////////////////////////////////////
// Type: Win32.Code.ValueTypeTestTarget

///////////////////////////////////////
// GetValue2

int32_t Win32_Code_ValueTypeTestTarget_GetValue2(Win32_Code_ValueTypeTestTarget* this__, int32_t a, int32_t b)
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

/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\ValueTypeTest.cs(15): */
    /* Path=1, Unique=0: IL_0000: nop */
    /* Path=1, Unique=0: IL_0001: ldarg.0 */
    __stack0_0 = this__;
    /* Path=1, Unique=0: IL_0002: ldfld System.Int32 Win32.Code.ValueTypeTestTarget::Value2 */
    __stack0_1 = __stack0_0->Value2;
    /* Path=1, Unique=0: IL_0007: ldarg.1 */
    __stack1_0 = a;
    /* Path=1, Unique=0: IL_0008: add */
    __stack0_1 = __stack0_1 + __stack1_0;
    /* Path=1, Unique=0: IL_0009: ldarg.2 */
    __stack1_0 = b;
    /* Path=1, Unique=0: IL_000a: add */
    __stack0_1 = __stack0_1 + __stack1_0;
    /* Path=1, Unique=0: IL_000b: stloc.0 */
    local0 = __stack0_1;
    /* Path=1, Unique=0: IL_000c: br.s IL_000e */
    goto IL_000e;
IL_000e:
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\ValueTypeTest.cs(17): */
    /* Path=2, Unique=0: IL_000e: ldloc.0 */
    __stack0_1 = local0;
    /* Path=2, Unique=0: IL_000f: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return __stack0_1;
}

//////////////////////
// Runtime helpers:

void* __Win32_Code_ValueTypeTestTarget_IL2C_RuntimeCast__(Win32_Code_ValueTypeTestTarget* this__, IL2C_RUNTIME_TYPE_DECL* type)
{
    if (type == il2c_typeof(System_ValueType)) return this__;
    return __System_ValueType_IL2C_RuntimeCast__((System_ValueType*)this__, type);
}

static void __Win32_Code_ValueTypeTestTarget_MARK_HANDLER__(void* pReference)
{
    il2c_try_mark_from_handler(((Win32_Code_ValueTypeTestTarget*)pReference)->OR2);
    il2c_typeof(System_ValueType)->pMarkHandler(pReference);
}

static __Win32_Code_ValueTypeTestTarget_VTABLE_DECL__ __Win32_Code_ValueTypeTestTarget_VTABLE__ = {
    __Win32_Code_ValueTypeTestTarget_IL2C_RuntimeCast__,
    (void*)__System_ValueType_ToString__,
    (void*)__System_ValueType_GetHashCode__,
    (void*)__System_Object_Finalize__,
    (void*)__System_ValueType_Equals__,
};

IL2C_RUNTIME_TYPE_DECL __Win32_Code_ValueTypeTestTarget_RUNTIME_TYPE__ = {
    "Win32.Code.ValueTypeTestTarget",
    sizeof(Win32_Code_ValueTypeTestTarget),
    __Win32_Code_ValueTypeTestTarget_MARK_HANDLER__,
};

////////////////////////////////////////////////////////////
// Type: Win32.Code.ValueTypeTest

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

/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\ValueTypeTest.cs(23): */
    /* Path=1, Unique=0: IL_0000: nop */
    /* Path=1, Unique=0: IL_0001: ldloca.s local0 */
    __stack0_0 = &local0;
    /* Path=1, Unique=0: IL_0003: initobj Win32.Code.ValueTypeTestTarget */
    memset(__stack0_0, 0x00, sizeof(Win32_Code_ValueTypeTestTarget));
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\ValueTypeTest.cs(25): */
    /* Path=1, Unique=0: IL_0009: ldloca.s local0 */
    __stack0_1 = &local0;
    /* Path=1, Unique=0: IL_000b: ldc.i4 456 */
    __stack1_0 = 456;
    /* Path=1, Unique=0: IL_0010: stfld System.Int32 Win32.Code.ValueTypeTestTarget::Value2 */
    __stack0_1->Value2 = __stack1_0;
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\ValueTypeTest.cs(27): */
    /* Path=1, Unique=0: IL_0015: ldloc.0 */
    __stack0_2 = local0;
    /* Path=1, Unique=0: IL_0016: ldfld System.Int32 Win32.Code.ValueTypeTestTarget::Value2 */
    __stack0_3 = __stack0_2.Value2;
    /* Path=1, Unique=0: IL_001b: stloc.1 */
    local1 = __stack0_3;
    /* Path=1, Unique=0: IL_001c: br.s IL_001e */
    goto IL_001e;
IL_001e:
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\ValueTypeTest.cs(28): */
    /* Path=2, Unique=0: IL_001e: ldloc.1 */
    __stack0_3 = local1;
    /* Path=2, Unique=0: IL_001f: ret */
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

/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\ValueTypeTest.cs(31): */
    /* Path=1, Unique=0: IL_0000: nop */
    /* Path=1, Unique=0: IL_0001: ldloca.s local0 */
    __stack0_0 = &local0;
    /* Path=1, Unique=0: IL_0003: initobj Win32.Code.ValueTypeTestTarget */
    memset(__stack0_0, 0x00, sizeof(Win32_Code_ValueTypeTestTarget));
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\ValueTypeTest.cs(33): */
    /* Path=1, Unique=0: IL_0009: ldloca.s local0 */
    __stack0_1 = &local0;
    /* Path=1, Unique=0: IL_000b: ldc.i4 789 */
    __stack1_0 = 789;
    /* Path=1, Unique=0: IL_0010: stfld System.Int32 Win32.Code.ValueTypeTestTarget::Value2 */
    __stack0_1->Value2 = __stack1_0;
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\ValueTypeTest.cs(35): */
    /* Path=1, Unique=0: IL_0015: ldloca.s local0 */
    __stack0_2 = &local0;
    /* Path=1, Unique=0: IL_0017: ldc.i4.s 123 */
    __stack1_0 = 123;
    /* Path=1, Unique=0: IL_0019: ldc.i4 456 */
    __stack2_0 = 456;
    /* Path=1, Unique=0: IL_001e: call System.Int32 Win32.Code.ValueTypeTestTarget::GetValue2(System.Int32,System.Int32) */
    __stack0_3 = Win32_Code_ValueTypeTestTarget_GetValue2(__stack0_2, __stack1_0, __stack2_0);
    /* Path=1, Unique=0: IL_0023: stloc.1 */
    local1 = __stack0_3;
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\ValueTypeTest.cs(36): */
    /* Path=1, Unique=0: IL_0024: ldloc.1 */
    __stack0_3 = local1;
    /* Path=1, Unique=0: IL_0025: stloc.2 */
    local2 = __stack0_3;
    /* Path=1, Unique=0: IL_0026: br.s IL_0028 */
    goto IL_0028;
IL_0028:
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\ValueTypeTest.cs(37): */
    /* Path=2, Unique=0: IL_0028: ldloc.2 */
    __stack0_3 = local2;
    /* Path=2, Unique=0: IL_0029: ret */
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
    /* Path=1, Unique=0: IL_0006: nop */
    /* Path=1, Unique=0: IL_0007: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return;
}

//////////////////////
// Runtime helpers:

void* __Win32_Code_ValueTypeTest_IL2C_RuntimeCast__(Win32_Code_ValueTypeTest* this__, IL2C_RUNTIME_TYPE_DECL* type)
{
    if (type == il2c_typeof(System_Object)) return this__;
    return __System_Object_IL2C_RuntimeCast__((System_Object*)this__, type);
}

static void __Win32_Code_ValueTypeTest_MARK_HANDLER__(void* pReference)
{
    il2c_typeof(System_Object)->pMarkHandler(pReference);
}

static __Win32_Code_ValueTypeTest_VTABLE_DECL__ __Win32_Code_ValueTypeTest_VTABLE__ = {
    __Win32_Code_ValueTypeTest_IL2C_RuntimeCast__,
    (void*)__System_Object_ToString__,
    (void*)__System_Object_GetHashCode__,
    (void*)__System_Object_Finalize__,
    (void*)__System_Object_Equals__,
};

IL2C_RUNTIME_TYPE_DECL __Win32_Code_ValueTypeTest_RUNTIME_TYPE__ = {
    "Win32.Code.ValueTypeTest",
    sizeof(Win32_Code_ValueTypeTest),
    __Win32_Code_ValueTypeTest_MARK_HANDLER__,
};
