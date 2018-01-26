#include <windows.h>
#include "Win32.Code.h"

//////////////////////////////////////////////////////////////////////////////////
// Const strings:

__DEFINE_CONST_STRING__(__string0, L"ABC");
__DEFINE_CONST_STRING__(__string1, L"DEF");
__DEFINE_CONST_STRING__(__string2, L"ABCDEFGHIJKLMN");

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

    /* Path=1, Unique=0: IL_0000: nop */
    /* Path=1, Unique=0: IL_0001: ldarg.0 */
    __stack0_0 = a;
    /* Path=1, Unique=0: IL_0002: box System.Int32 */
    __stack0_1 = __box__(&__stack0_0, __typeof__(System_Int32));
    /* Path=1, Unique=0: IL_0007: stloc.0 */
    local0 = __stack0_1;
    /* Path=1, Unique=0: IL_0008: ldloc.0 */
    __stack0_1 = local0;
    /* Path=1, Unique=0: IL_0009: unbox.any System.Int32 */
    __stack0_2 = *((int32_t*)__unbox__(__stack0_1, __typeof__(System_Int32)));
    /* Path=1, Unique=0: IL_000e: stloc.1 */
    local1 = __stack0_2;
    /* Path=1, Unique=0: IL_000f: ret */
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

    /* Path=1, Unique=0: IL_0000: ldarg.0 */
    __stack0_0 = __this;
    /* Path=1, Unique=0: IL_0001: call System.Void System.Object::.ctor() */
    System_Object__ctor((System_Object*)__stack0_0);
    /* Path=1, Unique=0: IL_0006: nop */
    /* Path=1, Unique=0: IL_0007: ret */
    __gc_unlink_execution_frame__(&__executionFrame__);
    return;
}

//////////////////////
// Runtime helpers:

static void __Win32_Code_BoxingTest_MARK_HANDLER__(void* pReference)
{
    __typeof__(System_Object)->pMarkHandler(pReference);
}

static __Win32_Code_BoxingTest_TYPE_DEF_TYPE__ __Win32_Code_BoxingTest_RUNTIME_TYPE_DEF__ = {
    "Win32.Code.BoxingTest",
    0,
    __Win32_Code_BoxingTest_MARK_HANDLER__,
    __System_Object_ToString__,
    __System_Object_GetHashCode__,
    __System_Object_Finalize__,
    __System_Object_Equals__,
};
const __RUNTIME_TYPE__ __Win32_Code_BoxingTest_RUNTIME_TYPE__ =
   (const __RUNTIME_TYPE_DEF__*)&__Win32_Code_BoxingTest_RUNTIME_TYPE_DEF__;

////////////////////////////////////////////////////////////
// Type: Win32.Code.ClassTypeTestTarget

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

    /* Path=1, Unique=0: IL_0000: ldarg.0 */
    __stack0_0 = __this;
    /* Path=1, Unique=0: IL_0001: call System.Void System.Object::.ctor() */
    System_Object__ctor((System_Object*)__stack0_0);
    /* Path=1, Unique=0: IL_0006: nop */
    /* Path=1, Unique=0: IL_0007: nop */
    /* Path=1, Unique=0: IL_0008: ret */
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

    /* Path=1, Unique=0: IL_0000: ldarg.0 */
    __stack0_0 = __this;
    /* Path=1, Unique=0: IL_0001: call System.Void System.Object::.ctor() */
    System_Object__ctor((System_Object*)__stack0_0);
    /* Path=1, Unique=0: IL_0006: nop */
    /* Path=1, Unique=0: IL_0007: nop */
    /* Path=1, Unique=0: IL_0008: ldarg.0 */
    __stack0_0 = __this;
    /* Path=1, Unique=0: IL_0009: ldarg.1 */
    __stack1_0 = value;
    /* Path=1, Unique=0: IL_000a: stfld System.Int32 Win32.Code.ClassTypeTestTarget::Value2 */
    __stack0_0->Value2 = __stack1_0;
    /* Path=1, Unique=0: IL_000f: ret */
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

    /* Path=1, Unique=0: IL_0000: nop */
    /* Path=1, Unique=0: IL_0001: ldarg.0 */
    __stack0_0 = __this;
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
    /* Path=2, Unique=0: IL_000e: ldloc.0 */
    __stack0_1 = local0;
    /* Path=2, Unique=0: IL_000f: ret */
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

    /* Path=1, Unique=0: IL_0000: nop */
    /* Path=1, Unique=0: IL_0001: ldarg.0 */
    __stack0_0 = __this;
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
    /* Path=2, Unique=0: IL_0010: ldloc.0 */
    __stack0_1 = local0;
    /* Path=2, Unique=0: IL_0011: ret */
    __gc_unlink_execution_frame__(&__executionFrame__);
    return __stack0_1;
}

//////////////////////
// Runtime helpers:

static void __Win32_Code_ClassTypeTestTarget_MARK_HANDLER__(void* pReference)
{
    __TRY_MARK_FROM_HANDLER__(((Win32_Code_ClassTypeTestTarget*)pReference)->OR2);
    __typeof__(System_Object)->pMarkHandler(pReference);
}

static __Win32_Code_ClassTypeTestTarget_TYPE_DEF_TYPE__ __Win32_Code_ClassTypeTestTarget_RUNTIME_TYPE_DEF__ = {
    "Win32.Code.ClassTypeTestTarget",
    sizeof(Win32_Code_ClassTypeTestTarget),
    __Win32_Code_ClassTypeTestTarget_MARK_HANDLER__,
    __System_Object_ToString__,
    __System_Object_GetHashCode__,
    __System_Object_Finalize__,
    __System_Object_Equals__,
};
const __RUNTIME_TYPE__ __Win32_Code_ClassTypeTestTarget_RUNTIME_TYPE__ =
   (const __RUNTIME_TYPE_DEF__*)&__Win32_Code_ClassTypeTestTarget_RUNTIME_TYPE_DEF__;

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

    /* Path=1, Unique=0: IL_0000: nop */
    /* Path=1, Unique=0: IL_0001: newobj System.Void Win32.Code.ClassTypeTestTarget::.ctor() */
    __stack0_0 = __gc_get_uninitialized_object__(__typeof__(Win32_Code_ClassTypeTestTarget));
    Win32_Code_ClassTypeTestTarget__ctor(__stack0_0);
    /* Path=1, Unique=0: IL_0006: stloc.0 */
    local0 = __stack0_0;
    /* Path=1, Unique=0: IL_0007: ldloc.0 */
    __stack0_0 = local0;
    /* Path=1, Unique=0: IL_0008: ldc.i4 456 */
    __stack1_0 = 456;
    /* Path=1, Unique=0: IL_000d: stfld System.Int32 Win32.Code.ClassTypeTestTarget::Value2 */
    __stack0_0->Value2 = __stack1_0;
    /* Path=1, Unique=0: IL_0012: ldloc.0 */
    __stack0_0 = local0;
    /* Path=1, Unique=0: IL_0013: ldfld System.Int32 Win32.Code.ClassTypeTestTarget::Value2 */
    __stack0_1 = __stack0_0->Value2;
    /* Path=1, Unique=0: IL_0018: stloc.1 */
    local1 = __stack0_1;
    /* Path=1, Unique=0: IL_0019: br.s IL_001b */
    goto IL_001b;
IL_001b:
    /* Path=2, Unique=0: IL_001b: ldloc.1 */
    __stack0_1 = local1;
    /* Path=2, Unique=0: IL_001c: ret */
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

    /* Path=1, Unique=0: IL_0000: nop */
    /* Path=1, Unique=0: IL_0001: newobj System.Void Win32.Code.ClassTypeTestTarget::.ctor() */
    __stack0_0 = __gc_get_uninitialized_object__(__typeof__(Win32_Code_ClassTypeTestTarget));
    Win32_Code_ClassTypeTestTarget__ctor(__stack0_0);
    /* Path=1, Unique=0: IL_0006: stloc.0 */
    local0 = __stack0_0;
    /* Path=1, Unique=0: IL_0007: ldloc.0 */
    __stack0_0 = local0;
    /* Path=1, Unique=0: IL_0008: ldc.i4 789 */
    __stack1_0 = 789;
    /* Path=1, Unique=0: IL_000d: stfld System.Int32 Win32.Code.ClassTypeTestTarget::Value2 */
    __stack0_0->Value2 = __stack1_0;
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
    /* Path=1, Unique=0: IL_0020: ldloc.1 */
    __stack0_1 = local1;
    /* Path=1, Unique=0: IL_0021: stloc.2 */
    local2 = __stack0_1;
    /* Path=1, Unique=0: IL_0022: br.s IL_0024 */
    goto IL_0024;
IL_0024:
    /* Path=2, Unique=0: IL_0024: ldloc.2 */
    __stack0_1 = local2;
    /* Path=2, Unique=0: IL_0025: ret */
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

    /* Path=1, Unique=0: IL_0000: nop */
    /* Path=1, Unique=0: IL_0001: newobj System.Void Win32.Code.ClassTypeTestTarget::.ctor() */
    __stack0_0 = __gc_get_uninitialized_object__(__typeof__(Win32_Code_ClassTypeTestTarget));
    Win32_Code_ClassTypeTestTarget__ctor(__stack0_0);
    /* Path=1, Unique=0: IL_0006: stloc.0 */
    local0 = __stack0_0;
    /* Path=1, Unique=0: IL_0007: ldloc.0 */
    __stack0_0 = local0;
    /* Path=1, Unique=0: IL_0008: ldc.i4 789 */
    __stack1_0 = 789;
    /* Path=1, Unique=0: IL_000d: stfld System.Int32 Win32.Code.ClassTypeTestTarget::Value2 */
    __stack0_0->Value2 = __stack1_0;
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
    /* Path=1, Unique=0: IL_0025: ldloc.1 */
    __stack0_1 = local1;
    /* Path=1, Unique=0: IL_0026: stloc.2 */
    local2 = __stack0_1;
    /* Path=1, Unique=0: IL_0027: br.s IL_0029 */
    goto IL_0029;
IL_0029:
    /* Path=2, Unique=0: IL_0029: ldloc.2 */
    __stack0_1 = local2;
    /* Path=2, Unique=0: IL_002a: ret */
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

    /* Path=1, Unique=0: IL_0000: nop */
    /* Path=1, Unique=0: IL_0001: ldc.i4.s 123 */
    __stack0_0 = 123;
    /* Path=1, Unique=0: IL_0003: newobj System.Void Win32.Code.ClassTypeTestTarget::.ctor(System.Int32) */
    __stack0_1 = __gc_get_uninitialized_object__(__typeof__(Win32_Code_ClassTypeTestTarget));
    Win32_Code_ClassTypeTestTarget__ctor_1(__stack0_1, __stack0_0);
    /* Path=1, Unique=0: IL_0008: stloc.0 */
    local0 = __stack0_1;
    /* Path=1, Unique=0: IL_0009: ldloc.0 */
    __stack0_1 = local0;
    /* Path=1, Unique=0: IL_000a: ldfld System.Int32 Win32.Code.ClassTypeTestTarget::Value2 */
    __stack0_0 = __stack0_1->Value2;
    /* Path=1, Unique=0: IL_000f: stloc.1 */
    local1 = __stack0_0;
    /* Path=1, Unique=0: IL_0010: br.s IL_0012 */
    goto IL_0012;
IL_0012:
    /* Path=2, Unique=0: IL_0012: ldloc.1 */
    __stack0_0 = local1;
    /* Path=2, Unique=0: IL_0013: ret */
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

    /* Path=1, Unique=0: IL_0000: ldarg.0 */
    __stack0_0 = __this;
    /* Path=1, Unique=0: IL_0001: call System.Void System.Object::.ctor() */
    System_Object__ctor((System_Object*)__stack0_0);
    /* Path=1, Unique=0: IL_0006: nop */
    /* Path=1, Unique=0: IL_0007: ret */
    __gc_unlink_execution_frame__(&__executionFrame__);
    return;
}

//////////////////////
// Runtime helpers:

static void __Win32_Code_ClassTypeTest_MARK_HANDLER__(void* pReference)
{
    __typeof__(System_Object)->pMarkHandler(pReference);
}

static __Win32_Code_ClassTypeTest_TYPE_DEF_TYPE__ __Win32_Code_ClassTypeTest_RUNTIME_TYPE_DEF__ = {
    "Win32.Code.ClassTypeTest",
    0,
    __Win32_Code_ClassTypeTest_MARK_HANDLER__,
    __System_Object_ToString__,
    __System_Object_GetHashCode__,
    __System_Object_Finalize__,
    __System_Object_Equals__,
};
const __RUNTIME_TYPE__ __Win32_Code_ClassTypeTest_RUNTIME_TYPE__ =
   (const __RUNTIME_TYPE_DEF__*)&__Win32_Code_ClassTypeTest_RUNTIME_TYPE_DEF__;

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
    /* Path=3, Unique=0: IL_000e: ldloc.0 */
    __stack0_0 = local0;
    /* Path=3, Unique=0: IL_000f: ret */
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

    /* Path=1, Unique=0: IL_0000: ldarg.0 */
    __stack0_0 = __this;
    /* Path=1, Unique=0: IL_0001: call System.Void System.Object::.ctor() */
    System_Object__ctor((System_Object*)__stack0_0);
    /* Path=1, Unique=0: IL_0006: nop */
    /* Path=1, Unique=0: IL_0007: ret */
    __gc_unlink_execution_frame__(&__executionFrame__);
    return;
}

//////////////////////
// Runtime helpers:

static void __Win32_Code_Hoge1_MARK_HANDLER__(void* pReference)
{
    __typeof__(System_Object)->pMarkHandler(pReference);
}

static __Win32_Code_Hoge1_TYPE_DEF_TYPE__ __Win32_Code_Hoge1_RUNTIME_TYPE_DEF__ = {
    "Win32.Code.Hoge1",
    0,
    __Win32_Code_Hoge1_MARK_HANDLER__,
    __System_Object_ToString__,
    __System_Object_GetHashCode__,
    __System_Object_Finalize__,
    __System_Object_Equals__,
};
const __RUNTIME_TYPE__ __Win32_Code_Hoge1_RUNTIME_TYPE__ =
   (const __RUNTIME_TYPE_DEF__*)&__Win32_Code_Hoge1_RUNTIME_TYPE_DEF__;

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
    /* Path=3, Unique=0: IL_000e: ldloc.0 */
    __stack0_0 = local0;
    /* Path=3, Unique=0: IL_000f: ret */
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

    /* Path=1, Unique=0: IL_0000: ldarg.0 */
    __stack0_0 = __this;
    /* Path=1, Unique=0: IL_0001: call System.Void System.Object::.ctor() */
    System_Object__ctor((System_Object*)__stack0_0);
    /* Path=1, Unique=0: IL_0006: nop */
    /* Path=1, Unique=0: IL_0007: ret */
    __gc_unlink_execution_frame__(&__executionFrame__);
    return;
}

//////////////////////
// Runtime helpers:

static void __Win32_Code_Hoge2_MARK_HANDLER__(void* pReference)
{
    __typeof__(System_Object)->pMarkHandler(pReference);
}

static __Win32_Code_Hoge2_TYPE_DEF_TYPE__ __Win32_Code_Hoge2_RUNTIME_TYPE_DEF__ = {
    "Win32.Code.Hoge2",
    0,
    __Win32_Code_Hoge2_MARK_HANDLER__,
    __System_Object_ToString__,
    __System_Object_GetHashCode__,
    __System_Object_Finalize__,
    __System_Object_Equals__,
};
const __RUNTIME_TYPE__ __Win32_Code_Hoge2_RUNTIME_TYPE__ =
   (const __RUNTIME_TYPE_DEF__*)&__Win32_Code_Hoge2_RUNTIME_TYPE_DEF__;

////////////////////////////////////////////////////////////
// Type: Win32.Code.InheritTestTargetBase1

///////////////////////////////////////
// .ctor

void Win32_Code_InheritTestTargetBase1__ctor(Win32_Code_InheritTestTargetBase1* __this)
{
    //-------------------
    // Local variables:


    //-------------------
    // Evaluation stacks:

    Win32_Code_InheritTestTargetBase1* __stack0_0 = NULL;

    //-------------------
    // Setup stack frame:

    struct /* __EXECUTION_FRAME__ */
    {
        __EXECUTION_FRAME__* pNext;
        uint8_t targetCount;
        Win32_Code_InheritTestTargetBase1** p__stack0_0;
    } __executionFrame__;

    __executionFrame__.targetCount = 1;
    __executionFrame__.p__stack0_0 = &__stack0_0;
    __gc_link_execution_frame__(&__executionFrame__);

    //-------------------
    // IL body:

    /* Path=1, Unique=0: IL_0000: ldarg.0 */
    __stack0_0 = __this;
    /* Path=1, Unique=0: IL_0001: call System.Void System.Object::.ctor() */
    System_Object__ctor((System_Object*)__stack0_0);
    /* Path=1, Unique=0: IL_0006: nop */
    /* Path=1, Unique=0: IL_0007: nop */
    /* Path=1, Unique=0: IL_0008: ret */
    __gc_unlink_execution_frame__(&__executionFrame__);
    return;
}

///////////////////////////////////////
// .ctor

void Win32_Code_InheritTestTargetBase1__ctor_1(Win32_Code_InheritTestTargetBase1* __this, int32_t value)
{
    //-------------------
    // Local variables:


    //-------------------
    // Evaluation stacks:

    Win32_Code_InheritTestTargetBase1* __stack0_0 = NULL;
    int32_t __stack1_0;

    //-------------------
    // Setup stack frame:

    struct /* __EXECUTION_FRAME__ */
    {
        __EXECUTION_FRAME__* pNext;
        uint8_t targetCount;
        Win32_Code_InheritTestTargetBase1** p__stack0_0;
    } __executionFrame__;

    __executionFrame__.targetCount = 1;
    __executionFrame__.p__stack0_0 = &__stack0_0;
    __gc_link_execution_frame__(&__executionFrame__);

    //-------------------
    // IL body:

    /* Path=1, Unique=0: IL_0000: ldarg.0 */
    __stack0_0 = __this;
    /* Path=1, Unique=0: IL_0001: call System.Void System.Object::.ctor() */
    System_Object__ctor((System_Object*)__stack0_0);
    /* Path=1, Unique=0: IL_0006: nop */
    /* Path=1, Unique=0: IL_0007: nop */
    /* Path=1, Unique=0: IL_0008: ldarg.0 */
    __stack0_0 = __this;
    /* Path=1, Unique=0: IL_0009: ldarg.1 */
    __stack1_0 = value;
    /* Path=1, Unique=0: IL_000a: stfld System.Int32 Win32.Code.InheritTestTargetBase1::Value2 */
    __stack0_0->Value2 = __stack1_0;
    /* Path=1, Unique=0: IL_000f: ret */
    __gc_unlink_execution_frame__(&__executionFrame__);
    return;
}

///////////////////////////////////////
// Calc

int32_t Win32_Code_InheritTestTargetBase1_Calc(Win32_Code_InheritTestTargetBase1* __this, int32_t a)
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

    struct /* __EXECUTION_FRAME__ */
    {
        __EXECUTION_FRAME__* pNext;
        uint8_t targetCount;
        Win32_Code_InheritTestTargetBase1** p__stack0_0;
    } __executionFrame__;

    __executionFrame__.targetCount = 1;
    __executionFrame__.p__stack0_0 = &__stack0_0;
    __gc_link_execution_frame__(&__executionFrame__);

    //-------------------
    // IL body:

    /* Path=1, Unique=0: IL_0000: nop */
    /* Path=1, Unique=0: IL_0001: ldarg.0 */
    __stack0_0 = __this;
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
    /* Path=2, Unique=0: IL_000c: ldloc.0 */
    __stack0_1 = local0;
    /* Path=2, Unique=0: IL_000d: ret */
    __gc_unlink_execution_frame__(&__executionFrame__);
    return __stack0_1;
}

///////////////////////////////////////
// Virtual: Calc

int32_t __Win32_Code_InheritTestTargetBase1_Calc_1__(Win32_Code_InheritTestTargetBase1* __this, int32_t a, int32_t b)
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

    struct /* __EXECUTION_FRAME__ */
    {
        __EXECUTION_FRAME__* pNext;
        uint8_t targetCount;
        Win32_Code_InheritTestTargetBase1** p__stack0_0;
    } __executionFrame__;

    __executionFrame__.targetCount = 1;
    __executionFrame__.p__stack0_0 = &__stack0_0;
    __gc_link_execution_frame__(&__executionFrame__);

    //-------------------
    // IL body:

    /* Path=1, Unique=0: IL_0000: nop */
    /* Path=1, Unique=0: IL_0001: ldarg.0 */
    __stack0_0 = __this;
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
    /* Path=2, Unique=0: IL_000e: ldloc.0 */
    __stack0_1 = local0;
    /* Path=2, Unique=0: IL_000f: ret */
    __gc_unlink_execution_frame__(&__executionFrame__);
    return __stack0_1;
}

//////////////////////
// Runtime helpers:

static void __Win32_Code_InheritTestTargetBase1_MARK_HANDLER__(void* pReference)
{
    __TRY_MARK_FROM_HANDLER__(((Win32_Code_InheritTestTargetBase1*)pReference)->OR2);
    __typeof__(System_Object)->pMarkHandler(pReference);
}

static __Win32_Code_InheritTestTargetBase1_TYPE_DEF_TYPE__ __Win32_Code_InheritTestTargetBase1_RUNTIME_TYPE_DEF__ = {
    "Win32.Code.InheritTestTargetBase1",
    sizeof(Win32_Code_InheritTestTargetBase1),
    __Win32_Code_InheritTestTargetBase1_MARK_HANDLER__,
    __System_Object_ToString__,
    __System_Object_GetHashCode__,
    __System_Object_Finalize__,
    __System_Object_Equals__,
    __Win32_Code_InheritTestTargetBase1_Calc_1__,
};
const __RUNTIME_TYPE__ __Win32_Code_InheritTestTargetBase1_RUNTIME_TYPE__ =
   (const __RUNTIME_TYPE_DEF__*)&__Win32_Code_InheritTestTargetBase1_RUNTIME_TYPE_DEF__;

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

    struct /* __EXECUTION_FRAME__ */
    {
        __EXECUTION_FRAME__* pNext;
        uint8_t targetCount;
        Win32_Code_InheritTestTargetBase1** plocal0;
        Win32_Code_InheritTestTargetBase1** p__stack0_0;
    } __executionFrame__;

    __executionFrame__.targetCount = 2;
    __executionFrame__.plocal0 = &local0;
    __executionFrame__.p__stack0_0 = &__stack0_0;
    __gc_link_execution_frame__(&__executionFrame__);

    //-------------------
    // IL body:

    /* Path=1, Unique=0: IL_0000: nop */
    /* Path=1, Unique=0: IL_0001: newobj System.Void Win32.Code.InheritTestTargetBase1::.ctor() */
    __stack0_0 = __gc_get_uninitialized_object__(__typeof__(Win32_Code_InheritTestTargetBase1));
    Win32_Code_InheritTestTargetBase1__ctor(__stack0_0);
    /* Path=1, Unique=0: IL_0006: stloc.0 */
    local0 = __stack0_0;
    /* Path=1, Unique=0: IL_0007: ldloc.0 */
    __stack0_0 = local0;
    /* Path=1, Unique=0: IL_0008: ldc.i4.s 123 */
    __stack1_0 = 123;
    /* Path=1, Unique=0: IL_000a: stfld System.Int32 Win32.Code.InheritTestTargetBase1::Value2 */
    __stack0_0->Value2 = __stack1_0;
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
    /* Path=2, Unique=0: IL_0019: ldloc.1 */
    __stack0_1 = local1;
    /* Path=2, Unique=0: IL_001a: ret */
    __gc_unlink_execution_frame__(&__executionFrame__);
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

    struct /* __EXECUTION_FRAME__ */
    {
        __EXECUTION_FRAME__* pNext;
        uint8_t targetCount;
        Win32_Code_InheritTestTargetBase1** plocal0;
        Win32_Code_InheritTestTargetBase1** p__stack0_0;
    } __executionFrame__;

    __executionFrame__.targetCount = 2;
    __executionFrame__.plocal0 = &local0;
    __executionFrame__.p__stack0_0 = &__stack0_0;
    __gc_link_execution_frame__(&__executionFrame__);

    //-------------------
    // IL body:

    /* Path=1, Unique=0: IL_0000: nop */
    /* Path=1, Unique=0: IL_0001: newobj System.Void Win32.Code.InheritTestTargetBase1::.ctor() */
    __stack0_0 = __gc_get_uninitialized_object__(__typeof__(Win32_Code_InheritTestTargetBase1));
    Win32_Code_InheritTestTargetBase1__ctor(__stack0_0);
    /* Path=1, Unique=0: IL_0006: stloc.0 */
    local0 = __stack0_0;
    /* Path=1, Unique=0: IL_0007: ldloc.0 */
    __stack0_0 = local0;
    /* Path=1, Unique=0: IL_0008: ldc.i4.s 123 */
    __stack1_0 = 123;
    /* Path=1, Unique=0: IL_000a: stfld System.Int32 Win32.Code.InheritTestTargetBase1::Value2 */
    __stack0_0->Value2 = __stack1_0;
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
    /* Path=2, Unique=0: IL_001a: ldloc.1 */
    __stack0_1 = local1;
    /* Path=2, Unique=0: IL_001b: ret */
    __gc_unlink_execution_frame__(&__executionFrame__);
    return __stack0_1;
}

///////////////////////////////////////
// .ctor

void Win32_Code_InheritTypeTest__ctor(Win32_Code_InheritTypeTest* __this)
{
    //-------------------
    // Local variables:


    //-------------------
    // Evaluation stacks:

    Win32_Code_InheritTypeTest* __stack0_0 = NULL;

    //-------------------
    // Setup stack frame:

    struct /* __EXECUTION_FRAME__ */
    {
        __EXECUTION_FRAME__* pNext;
        uint8_t targetCount;
        Win32_Code_InheritTypeTest** p__stack0_0;
    } __executionFrame__;

    __executionFrame__.targetCount = 1;
    __executionFrame__.p__stack0_0 = &__stack0_0;
    __gc_link_execution_frame__(&__executionFrame__);

    //-------------------
    // IL body:

    /* Path=1, Unique=0: IL_0000: ldarg.0 */
    __stack0_0 = __this;
    /* Path=1, Unique=0: IL_0001: call System.Void System.Object::.ctor() */
    System_Object__ctor((System_Object*)__stack0_0);
    /* Path=1, Unique=0: IL_0006: nop */
    /* Path=1, Unique=0: IL_0007: ret */
    __gc_unlink_execution_frame__(&__executionFrame__);
    return;
}

//////////////////////
// Runtime helpers:

static void __Win32_Code_InheritTypeTest_MARK_HANDLER__(void* pReference)
{
    __typeof__(System_Object)->pMarkHandler(pReference);
}

static __Win32_Code_InheritTypeTest_TYPE_DEF_TYPE__ __Win32_Code_InheritTypeTest_RUNTIME_TYPE_DEF__ = {
    "Win32.Code.InheritTypeTest",
    0,
    __Win32_Code_InheritTypeTest_MARK_HANDLER__,
    __System_Object_ToString__,
    __System_Object_GetHashCode__,
    __System_Object_Finalize__,
    __System_Object_Equals__,
};
const __RUNTIME_TYPE__ __Win32_Code_InheritTypeTest_RUNTIME_TYPE__ =
   (const __RUNTIME_TYPE_DEF__*)&__Win32_Code_InheritTypeTest_RUNTIME_TYPE_DEF__;

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
    OutputDebugStringW(message->pBody);
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

    /* Path=1, Unique=0: IL_0000: ldarg.0 */
    __stack0_0 = __this;
    /* Path=1, Unique=0: IL_0001: call System.Void System.Object::.ctor() */
    System_Object__ctor((System_Object*)__stack0_0);
    /* Path=1, Unique=0: IL_0006: nop */
    /* Path=1, Unique=0: IL_0007: ret */
    __gc_unlink_execution_frame__(&__executionFrame__);
    return;
}

//////////////////////
// Runtime helpers:

static void __Win32_Code_Win32_MARK_HANDLER__(void* pReference)
{
    __typeof__(System_Object)->pMarkHandler(pReference);
}

static __Win32_Code_Win32_TYPE_DEF_TYPE__ __Win32_Code_Win32_RUNTIME_TYPE_DEF__ = {
    "Win32.Code.Win32",
    0,
    __Win32_Code_Win32_MARK_HANDLER__,
    __System_Object_ToString__,
    __System_Object_GetHashCode__,
    __System_Object_Finalize__,
    __System_Object_Equals__,
};
const __RUNTIME_TYPE__ __Win32_Code_Win32_RUNTIME_TYPE__ =
   (const __RUNTIME_TYPE_DEF__*)&__Win32_Code_Win32_RUNTIME_TYPE_DEF__;

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

    /* Path=1, Unique=0: IL_0000: nop */
    /* Path=1, Unique=0: IL_0001: ldstr "ABC" */
    __stack0_0 = __string0;
    /* Path=1, Unique=0: IL_0006: stloc.0 */
    local0 = __stack0_0;
    /* Path=1, Unique=0: IL_0007: ret */
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

    /* Path=1, Unique=0: IL_0000: nop */
    /* Path=1, Unique=0: IL_0001: ldarg.0 */
    __stack0_0 = a;
    /* Path=1, Unique=0: IL_0002: stloc.0 */
    local0 = __stack0_0;
    /* Path=1, Unique=0: IL_0003: br.s IL_0005 */
    goto IL_0005;
IL_0005:
    /* Path=2, Unique=0: IL_0005: ldloc.0 */
    __stack0_0 = local0;
    /* Path=2, Unique=0: IL_0006: ret */
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

    /* Path=1, Unique=0: IL_0000: nop */
    /* Path=1, Unique=0: IL_0001: ldstr "ABC" */
    __stack0_0 = __string0;
    /* Path=1, Unique=0: IL_0006: stloc.0 */
    local0 = __stack0_0;
    /* Path=1, Unique=0: IL_0007: ldstr "DEF" */
    __stack0_0 = __string1;
    /* Path=1, Unique=0: IL_000c: stloc.1 */
    local1 = __stack0_0;
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
    /* Path=2, Unique=0: IL_0017: ldloc.2 */
    __stack0_0 = local2;
    /* Path=2, Unique=0: IL_0018: ret */
    __gc_unlink_execution_frame__(&__executionFrame__);
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

    struct /* __EXECUTION_FRAME__ */
    {
        __EXECUTION_FRAME__* pNext;
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
    __gc_link_execution_frame__(&__executionFrame__);

    //-------------------
    // IL body:

    /* Path=1, Unique=0: IL_0000: nop */
    /* Path=1, Unique=0: IL_0001: ldstr "ABCDEFGHIJKLMN" */
    __stack0_0 = __string2;
    /* Path=1, Unique=0: IL_0006: stloc.0 */
    local0 = __stack0_0;
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
    /* Path=2, Unique=0: IL_0011: ldloc.1 */
    __stack0_0 = local1;
    /* Path=2, Unique=0: IL_0012: ret */
    __gc_unlink_execution_frame__(&__executionFrame__);
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

    /* Path=1, Unique=0: IL_0000: nop */
    /* Path=1, Unique=0: IL_0001: ldc.i4.s 65 */
    __stack0_0 = 65;
    /* Path=1, Unique=0: IL_0003: stloc.0 */
    local0 = (wchar_t)__stack0_0;
    /* Path=1, Unique=0: IL_0004: br.s IL_0006 */
    goto IL_0006;
IL_0006:
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

    struct /* __EXECUTION_FRAME__ */
    {
        __EXECUTION_FRAME__* pNext;
        uint8_t targetCount;
        System_String** p__stack0_0;
    } __executionFrame__;

    __executionFrame__.targetCount = 1;
    __executionFrame__.p__stack0_0 = &__stack0_0;
    __gc_link_execution_frame__(&__executionFrame__);

    //-------------------
    // IL body:

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
    /* Path=2, Unique=0: IL_000b: ldloc.0 */
    __stack0_2 = local0;
    /* Path=2, Unique=0: IL_000c: ret */
    __gc_unlink_execution_frame__(&__executionFrame__);
    return (wchar_t)__stack0_2;
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

    /* Path=1, Unique=0: IL_0000: ldarg.0 */
    __stack0_0 = __this;
    /* Path=1, Unique=0: IL_0001: call System.Void System.Object::.ctor() */
    System_Object__ctor((System_Object*)__stack0_0);
    /* Path=1, Unique=0: IL_0006: nop */
    /* Path=1, Unique=0: IL_0007: ret */
    __gc_unlink_execution_frame__(&__executionFrame__);
    return;
}

//////////////////////
// Runtime helpers:

static void __Win32_Code_StringTest_MARK_HANDLER__(void* pReference)
{
    __typeof__(System_Object)->pMarkHandler(pReference);
}

static __Win32_Code_StringTest_TYPE_DEF_TYPE__ __Win32_Code_StringTest_RUNTIME_TYPE_DEF__ = {
    "Win32.Code.StringTest",
    0,
    __Win32_Code_StringTest_MARK_HANDLER__,
    __System_Object_ToString__,
    __System_Object_GetHashCode__,
    __System_Object_Finalize__,
    __System_Object_Equals__,
};
const __RUNTIME_TYPE__ __Win32_Code_StringTest_RUNTIME_TYPE__ =
   (const __RUNTIME_TYPE_DEF__*)&__Win32_Code_StringTest_RUNTIME_TYPE_DEF__;

////////////////////////////////////////////////////////////
// Type: Win32.Code.UnsafeTest

///////////////////////////////////////
// .ctor

void Win32_Code_UnsafeTest__ctor(Win32_Code_UnsafeTest* __this)
{
    //-------------------
    // Local variables:


    //-------------------
    // Evaluation stacks:

    Win32_Code_UnsafeTest* __stack0_0 = NULL;

    //-------------------
    // Setup stack frame:

    struct /* __EXECUTION_FRAME__ */
    {
        __EXECUTION_FRAME__* pNext;
        uint8_t targetCount;
        Win32_Code_UnsafeTest** p__stack0_0;
    } __executionFrame__;

    __executionFrame__.targetCount = 1;
    __executionFrame__.p__stack0_0 = &__stack0_0;
    __gc_link_execution_frame__(&__executionFrame__);

    //-------------------
    // IL body:

    /* Path=1, Unique=0: IL_0000: ldarg.0 */
    __stack0_0 = __this;
    /* Path=1, Unique=0: IL_0001: call System.Void System.Object::.ctor() */
    System_Object__ctor((System_Object*)__stack0_0);
    /* Path=1, Unique=0: IL_0006: nop */
    /* Path=1, Unique=0: IL_0007: ret */
    __gc_unlink_execution_frame__(&__executionFrame__);
    return;
}

//////////////////////
// Runtime helpers:

static void __Win32_Code_UnsafeTest_MARK_HANDLER__(void* pReference)
{
    __typeof__(System_Object)->pMarkHandler(pReference);
}

static __Win32_Code_UnsafeTest_TYPE_DEF_TYPE__ __Win32_Code_UnsafeTest_RUNTIME_TYPE_DEF__ = {
    "Win32.Code.UnsafeTest",
    0,
    __Win32_Code_UnsafeTest_MARK_HANDLER__,
    __System_Object_ToString__,
    __System_Object_GetHashCode__,
    __System_Object_Finalize__,
    __System_Object_Equals__,
};
const __RUNTIME_TYPE__ __Win32_Code_UnsafeTest_RUNTIME_TYPE__ =
   (const __RUNTIME_TYPE_DEF__*)&__Win32_Code_UnsafeTest_RUNTIME_TYPE_DEF__;

////////////////////////////////////////////////////////////
// Type: Win32.Code.ValueTypeTestTarget

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

    /* Path=1, Unique=0: IL_0000: nop */
    /* Path=1, Unique=0: IL_0001: ldarg.0 */
    __stack0_0 = __this;
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
    /* Path=2, Unique=0: IL_000e: ldloc.0 */
    __stack0_1 = local0;
    /* Path=2, Unique=0: IL_000f: ret */
    __gc_unlink_execution_frame__(&__executionFrame__);
    return __stack0_1;
}

//////////////////////
// Runtime helpers:

static void __Win32_Code_ValueTypeTestTarget_MARK_HANDLER__(void* pReference)
{
    __TRY_MARK_FROM_HANDLER__(((Win32_Code_ValueTypeTestTarget*)pReference)->OR2);
    __typeof__(System_ValueType)->pMarkHandler(pReference);
}

static __Win32_Code_ValueTypeTestTarget_TYPE_DEF_TYPE__ __Win32_Code_ValueTypeTestTarget_RUNTIME_TYPE_DEF__ = {
    "Win32.Code.ValueTypeTestTarget",
    sizeof(Win32_Code_ValueTypeTestTarget),
    __Win32_Code_ValueTypeTestTarget_MARK_HANDLER__,
    __System_Object_ToString__,
    __System_Object_GetHashCode__,
    __System_Object_Finalize__,
    __System_Object_Equals__,
    __System_ValueType_GetHashCode__,
    __System_ValueType_ToString__,
    __System_ValueType_Equals__,
};
const __RUNTIME_TYPE__ __Win32_Code_ValueTypeTestTarget_RUNTIME_TYPE__ =
   (const __RUNTIME_TYPE_DEF__*)&__Win32_Code_ValueTypeTestTarget_RUNTIME_TYPE_DEF__;

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

    /* Path=1, Unique=0: IL_0000: nop */
    /* Path=1, Unique=0: IL_0001: ldloca.s local0 */
    __stack0_0 = &local0;
    /* Path=1, Unique=0: IL_0003: initobj Win32.Code.ValueTypeTestTarget */
    memset(__stack0_0, 0x00, sizeof(Win32_Code_ValueTypeTestTarget));
    /* Path=1, Unique=0: IL_0009: ldloca.s local0 */
    __stack0_1 = &local0;
    /* Path=1, Unique=0: IL_000b: ldc.i4 456 */
    __stack1_0 = 456;
    /* Path=1, Unique=0: IL_0010: stfld System.Int32 Win32.Code.ValueTypeTestTarget::Value2 */
    __stack0_1->Value2 = __stack1_0;
    /* Path=1, Unique=0: IL_0015: ldloc.0 */
    __stack0_2 = local0;
    /* Path=1, Unique=0: IL_0016: ldfld System.Int32 Win32.Code.ValueTypeTestTarget::Value2 */
    __stack0_3 = __stack0_2.Value2;
    /* Path=1, Unique=0: IL_001b: stloc.1 */
    local1 = __stack0_3;
    /* Path=1, Unique=0: IL_001c: br.s IL_001e */
    goto IL_001e;
IL_001e:
    /* Path=2, Unique=0: IL_001e: ldloc.1 */
    __stack0_3 = local1;
    /* Path=2, Unique=0: IL_001f: ret */
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

    /* Path=1, Unique=0: IL_0000: nop */
    /* Path=1, Unique=0: IL_0001: ldloca.s local0 */
    __stack0_0 = &local0;
    /* Path=1, Unique=0: IL_0003: initobj Win32.Code.ValueTypeTestTarget */
    memset(__stack0_0, 0x00, sizeof(Win32_Code_ValueTypeTestTarget));
    /* Path=1, Unique=0: IL_0009: ldloca.s local0 */
    __stack0_1 = &local0;
    /* Path=1, Unique=0: IL_000b: ldc.i4 789 */
    __stack1_0 = 789;
    /* Path=1, Unique=0: IL_0010: stfld System.Int32 Win32.Code.ValueTypeTestTarget::Value2 */
    __stack0_1->Value2 = __stack1_0;
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
    /* Path=1, Unique=0: IL_0024: ldloc.1 */
    __stack0_3 = local1;
    /* Path=1, Unique=0: IL_0025: stloc.2 */
    local2 = __stack0_3;
    /* Path=1, Unique=0: IL_0026: br.s IL_0028 */
    goto IL_0028;
IL_0028:
    /* Path=2, Unique=0: IL_0028: ldloc.2 */
    __stack0_3 = local2;
    /* Path=2, Unique=0: IL_0029: ret */
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

    /* Path=1, Unique=0: IL_0000: ldarg.0 */
    __stack0_0 = __this;
    /* Path=1, Unique=0: IL_0001: call System.Void System.Object::.ctor() */
    System_Object__ctor((System_Object*)__stack0_0);
    /* Path=1, Unique=0: IL_0006: nop */
    /* Path=1, Unique=0: IL_0007: ret */
    __gc_unlink_execution_frame__(&__executionFrame__);
    return;
}

//////////////////////
// Runtime helpers:

static void __Win32_Code_ValueTypeTest_MARK_HANDLER__(void* pReference)
{
    __typeof__(System_Object)->pMarkHandler(pReference);
}

static __Win32_Code_ValueTypeTest_TYPE_DEF_TYPE__ __Win32_Code_ValueTypeTest_RUNTIME_TYPE_DEF__ = {
    "Win32.Code.ValueTypeTest",
    0,
    __Win32_Code_ValueTypeTest_MARK_HANDLER__,
    __System_Object_ToString__,
    __System_Object_GetHashCode__,
    __System_Object_Finalize__,
    __System_Object_Equals__,
};
const __RUNTIME_TYPE__ __Win32_Code_ValueTypeTest_RUNTIME_TYPE__ =
   (const __RUNTIME_TYPE_DEF__*)&__Win32_Code_ValueTypeTest_RUNTIME_TYPE_DEF__;
