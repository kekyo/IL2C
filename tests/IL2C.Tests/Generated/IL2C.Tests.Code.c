#include <windows.h>
#include "IL2C.Tests.Code.h"

//////////////////////////////////////////////////////////////////////////////////
// Const strings:

IL2C_CONST_STRING(string0__, L"ABC");
IL2C_CONST_STRING(string1__, L"DEF");
IL2C_CONST_STRING(string2__, L"ABCDEFGHIJKLMN");

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

int32_t IL2C_Tests_BoxingTest_x = 0;

int32_t IL2C_Tests_ClassTypeTestTarget_Value1 = 0;
IL2C_Tests_ClassTypeTestTarget* IL2C_Tests_ClassTypeTestTarget_OR1 = NULL;














int32_t IL2C_Tests_ValueTypeTestTarget_Value1 = 0;


//////////////////////////////////////////////////////////////////////////////////
// Methods:

////////////////////////////////////////////////////////////
// Type: IL2C.Tests.BoxingTest

///////////////////////////////////////
// BoxingInt32

void IL2C_Tests_BoxingTest_BoxingInt32(int32_t a)
{
    //-------------------
    // Local variables:

    System_Object* value__ = NULL;
    int32_t r__;

    //-------------------
    // Evaluation stacks:

    int32_t stack0_0__;
    System_Object* stack0_1__ = NULL;
    int32_t stack0_2__;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        System_Object** pvalue__;
        System_Object** pstack0_1__;
    } __executionFrame__;

    __executionFrame__.targetCount = 2;
    __executionFrame__.pvalue__ = &value__;
    __executionFrame__.pstack0_1__ = &stack0_1__;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

/* D:\\PROJECT\\IL2C\\tests\\IL2C.Tests.Code\\BoxingTest.cs(13): */
    /* Path=1, Unique=0: IL_0000: nop */
    /* Path=1, Unique=0: IL_0001: ldarg.0 */
    stack0_0__ = a;
    /* Path=1, Unique=0: IL_0002: box System.Int32 */
    stack0_1__ = il2c_box(&stack0_0__, il2c_typeof(System_Int32));
    /* Path=1, Unique=0: IL_0007: stloc.0 */
    value__ = stack0_1__;
/* D:\\PROJECT\\IL2C\\tests\\IL2C.Tests.Code\\BoxingTest.cs(16): */
    /* Path=1, Unique=0: IL_0008: ldloc.0 */
    stack0_1__ = value__;
    /* Path=1, Unique=0: IL_0009: unbox.any System.Int32 */
    stack0_2__ = *((int32_t*)il2c_unbox(stack0_1__, il2c_typeof(System_Int32)));
    /* Path=1, Unique=0: IL_000e: stloc.1 */
    r__ = stack0_2__;
/* D:\\PROJECT\\IL2C\\tests\\IL2C.Tests.Code\\BoxingTest.cs(17): */
    /* Path=1, Unique=0: IL_000f: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return;
}

///////////////////////////////////////
// .ctor

void IL2C_Tests_BoxingTest__ctor(IL2C_Tests_BoxingTest* this__)
{
    //-------------------
    // Local variables:


    //-------------------
    // Evaluation stacks:

    IL2C_Tests_BoxingTest* stack0_0__ = NULL;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        IL2C_Tests_BoxingTest** pstack0_0__;
    } __executionFrame__;

    __executionFrame__.targetCount = 1;
    __executionFrame__.pstack0_0__ = &stack0_0__;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

    /* Path=1, Unique=0: IL_0000: ldarg.0 */
    stack0_0__ = this__;
    /* Path=1, Unique=0: IL_0001: call System.Void System.Object::.ctor() */
    /* Path=1, Unique=0: IL_0006: nop */
    /* Path=1, Unique=0: IL_0007: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return;
}

//////////////////////
// Runtime helpers:

// Runtime cast
void* __IL2C_Tests_BoxingTest_IL2C_RuntimeCast__(IL2C_Tests_BoxingTest* this__, IL2C_RUNTIME_TYPE_DECL* type)
{
    // This type
    if (type == il2c_typeof(IL2C_Tests_BoxingTest)) return this__;

    // Delegate checking base types
    return __System_Object_IL2C_RuntimeCast__((System_Object*)this__, type);
}

// GC's mark handler
void __IL2C_Tests_BoxingTest_IL2C_MarkHandler__(IL2C_Tests_BoxingTest* this__)
{

    /* Suppressed invoke base mark handler */
}

// Runtime type information
IL2C_RUNTIME_TYPE_DECL __IL2C_Tests_BoxingTest_RUNTIME_TYPE__ = {
    "IL2C.Tests.BoxingTest",
    sizeof(IL2C_Tests_BoxingTest),
    /* internalcall */ (void*)__IL2C_Tests_BoxingTest_IL2C_MarkHandler__,
};

//////////////////////
// VTables:

// Vtable of IL2C.Tests.BoxingTest
__IL2C_Tests_BoxingTest_VTABLE_DECL__ __IL2C_Tests_BoxingTest_VTABLE__ = {
    (void*)__IL2C_Tests_BoxingTest_IL2C_RuntimeCast__,
    (void*)__System_Object_ToString__,
    (void*)__System_Object_GetHashCode__,
    (void*)__System_Object_Finalize__,
    (void*)__System_Object_Equals__,
};

////////////////////////////////////////////////////////////
// Type: IL2C.Tests.ClassTypeTestTarget

///////////////////////////////////////
// .ctor

void IL2C_Tests_ClassTypeTestTarget__ctor(IL2C_Tests_ClassTypeTestTarget* this__)
{
    //-------------------
    // Local variables:


    //-------------------
    // Evaluation stacks:

    IL2C_Tests_ClassTypeTestTarget* stack0_0__ = NULL;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        IL2C_Tests_ClassTypeTestTarget** pstack0_0__;
    } __executionFrame__;

    __executionFrame__.targetCount = 1;
    __executionFrame__.pstack0_0__ = &stack0_0__;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

/* D:\\PROJECT\\IL2C\\tests\\IL2C.Tests.Code\\ClassTypeTest.cs(16): */
    /* Path=1, Unique=0: IL_0000: ldarg.0 */
    stack0_0__ = this__;
    /* Path=1, Unique=0: IL_0001: call System.Void System.Object::.ctor() */
    /* Path=1, Unique=0: IL_0006: nop */
/* D:\\PROJECT\\IL2C\\tests\\IL2C.Tests.Code\\ClassTypeTest.cs(17): */
    /* Path=1, Unique=0: IL_0007: nop */
    /* Path=1, Unique=0: IL_0008: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return;
}

///////////////////////////////////////
// .ctor

void IL2C_Tests_ClassTypeTestTarget__ctor_1(IL2C_Tests_ClassTypeTestTarget* this__, int32_t value)
{
    //-------------------
    // Local variables:


    //-------------------
    // Evaluation stacks:

    IL2C_Tests_ClassTypeTestTarget* stack0_0__ = NULL;
    int32_t stack1_0__;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        IL2C_Tests_ClassTypeTestTarget** pstack0_0__;
    } __executionFrame__;

    __executionFrame__.targetCount = 1;
    __executionFrame__.pstack0_0__ = &stack0_0__;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

/* D:\\PROJECT\\IL2C\\tests\\IL2C.Tests.Code\\ClassTypeTest.cs(20): */
    /* Path=1, Unique=0: IL_0000: ldarg.0 */
    stack0_0__ = this__;
    /* Path=1, Unique=0: IL_0001: call System.Void System.Object::.ctor() */
    /* Path=1, Unique=0: IL_0006: nop */
/* D:\\PROJECT\\IL2C\\tests\\IL2C.Tests.Code\\ClassTypeTest.cs(21): */
    /* Path=1, Unique=0: IL_0007: nop */
    /* Path=1, Unique=0: IL_0008: ldarg.0 */
    stack0_0__ = this__;
    /* Path=1, Unique=0: IL_0009: ldarg.1 */
    stack1_0__ = value;
    /* Path=1, Unique=0: IL_000a: stfld System.Int32 IL2C.Tests.ClassTypeTestTarget::Value2 */
    stack0_0__->Value2 = stack1_0__;
/* D:\\PROJECT\\IL2C\\tests\\IL2C.Tests.Code\\ClassTypeTest.cs(23): */
    /* Path=1, Unique=0: IL_000f: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return;
}

///////////////////////////////////////
// GetValue2

int32_t IL2C_Tests_ClassTypeTestTarget_GetValue2(IL2C_Tests_ClassTypeTestTarget* this__, int32_t a, int32_t b)
{
    //-------------------
    // Local variables:

    int32_t local__;

    //-------------------
    // Evaluation stacks:

    IL2C_Tests_ClassTypeTestTarget* stack0_0__ = NULL;
    int32_t stack0_1__;
    int32_t stack1_0__;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        IL2C_Tests_ClassTypeTestTarget** pstack0_0__;
    } __executionFrame__;

    __executionFrame__.targetCount = 1;
    __executionFrame__.pstack0_0__ = &stack0_0__;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

/* D:\\PROJECT\\IL2C\\tests\\IL2C.Tests.Code\\ClassTypeTest.cs(26): */
    /* Path=1, Unique=0: IL_0000: nop */
    /* Path=1, Unique=0: IL_0001: ldarg.0 */
    stack0_0__ = this__;
    /* Path=1, Unique=0: IL_0002: ldfld System.Int32 IL2C.Tests.ClassTypeTestTarget::Value2 */
    stack0_1__ = stack0_0__->Value2;
    /* Path=1, Unique=0: IL_0007: ldarg.1 */
    stack1_0__ = a;
    /* Path=1, Unique=0: IL_0008: add */
    stack0_1__ = stack0_1__ + stack1_0__;
    /* Path=1, Unique=0: IL_0009: ldarg.2 */
    stack1_0__ = b;
    /* Path=1, Unique=0: IL_000a: add */
    stack0_1__ = stack0_1__ + stack1_0__;
    /* Path=1, Unique=0: IL_000b: stloc.0 */
    local__ = stack0_1__;
    /* Path=1, Unique=0: IL_000c: br.s IL_000e */
    goto IL_000e;
IL_000e:
/* D:\\PROJECT\\IL2C\\tests\\IL2C.Tests.Code\\ClassTypeTest.cs(28): */
    /* Path=2, Unique=0: IL_000e: ldloc.0 */
    stack0_1__ = local__;
    /* Path=2, Unique=0: IL_000f: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return stack0_1__;
}

///////////////////////////////////////
// GetValue2

int32_t IL2C_Tests_ClassTypeTestTarget_GetValue2_1(IL2C_Tests_ClassTypeTestTarget* this__, int32_t a, int32_t b, int32_t c)
{
    //-------------------
    // Local variables:

    int32_t local__;

    //-------------------
    // Evaluation stacks:

    IL2C_Tests_ClassTypeTestTarget* stack0_0__ = NULL;
    int32_t stack0_1__;
    int32_t stack1_0__;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        IL2C_Tests_ClassTypeTestTarget** pstack0_0__;
    } __executionFrame__;

    __executionFrame__.targetCount = 1;
    __executionFrame__.pstack0_0__ = &stack0_0__;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

/* D:\\PROJECT\\IL2C\\tests\\IL2C.Tests.Code\\ClassTypeTest.cs(31): */
    /* Path=1, Unique=0: IL_0000: nop */
    /* Path=1, Unique=0: IL_0001: ldarg.0 */
    stack0_0__ = this__;
    /* Path=1, Unique=0: IL_0002: ldfld System.Int32 IL2C.Tests.ClassTypeTestTarget::Value2 */
    stack0_1__ = stack0_0__->Value2;
    /* Path=1, Unique=0: IL_0007: ldarg.1 */
    stack1_0__ = a;
    /* Path=1, Unique=0: IL_0008: add */
    stack0_1__ = stack0_1__ + stack1_0__;
    /* Path=1, Unique=0: IL_0009: ldarg.2 */
    stack1_0__ = b;
    /* Path=1, Unique=0: IL_000a: add */
    stack0_1__ = stack0_1__ + stack1_0__;
    /* Path=1, Unique=0: IL_000b: ldarg.3 */
    stack1_0__ = c;
    /* Path=1, Unique=0: IL_000c: add */
    stack0_1__ = stack0_1__ + stack1_0__;
    /* Path=1, Unique=0: IL_000d: stloc.0 */
    local__ = stack0_1__;
    /* Path=1, Unique=0: IL_000e: br.s IL_0010 */
    goto IL_0010;
IL_0010:
/* D:\\PROJECT\\IL2C\\tests\\IL2C.Tests.Code\\ClassTypeTest.cs(33): */
    /* Path=2, Unique=0: IL_0010: ldloc.0 */
    stack0_1__ = local__;
    /* Path=2, Unique=0: IL_0011: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return stack0_1__;
}

//////////////////////
// Runtime helpers:

// Runtime cast
void* __IL2C_Tests_ClassTypeTestTarget_IL2C_RuntimeCast__(IL2C_Tests_ClassTypeTestTarget* this__, IL2C_RUNTIME_TYPE_DECL* type)
{
    // This type
    if (type == il2c_typeof(IL2C_Tests_ClassTypeTestTarget)) return this__;

    // Delegate checking base types
    return __System_Object_IL2C_RuntimeCast__((System_Object*)this__, type);
}

// GC's mark handler
void __IL2C_Tests_ClassTypeTestTarget_IL2C_MarkHandler__(IL2C_Tests_ClassTypeTestTarget* this__)
{
    // Try marking each object reference fields
    il2c_try_mark_from_handler(this__->OR2);

    /* Suppressed invoke base mark handler */
}

// Runtime type information
IL2C_RUNTIME_TYPE_DECL __IL2C_Tests_ClassTypeTestTarget_RUNTIME_TYPE__ = {
    "IL2C.Tests.ClassTypeTestTarget",
    sizeof(IL2C_Tests_ClassTypeTestTarget),
    /* internalcall */ (void*)__IL2C_Tests_ClassTypeTestTarget_IL2C_MarkHandler__,
};

//////////////////////
// VTables:

// Vtable of IL2C.Tests.ClassTypeTestTarget
__IL2C_Tests_ClassTypeTestTarget_VTABLE_DECL__ __IL2C_Tests_ClassTypeTestTarget_VTABLE__ = {
    (void*)__IL2C_Tests_ClassTypeTestTarget_IL2C_RuntimeCast__,
    (void*)__System_Object_ToString__,
    (void*)__System_Object_GetHashCode__,
    (void*)__System_Object_Finalize__,
    (void*)__System_Object_Equals__,
};

////////////////////////////////////////////////////////////
// Type: IL2C.Tests.ClassTypeTest

///////////////////////////////////////
// Test4

int32_t IL2C_Tests_ClassTypeTest_Test4(void)
{
    //-------------------
    // Local variables:

    IL2C_Tests_ClassTypeTestTarget* hoge3__ = NULL;
    int32_t local__;

    //-------------------
    // Evaluation stacks:

    IL2C_Tests_ClassTypeTestTarget* stack0_0__ = NULL;
    int32_t stack0_1__;
    int32_t stack1_0__;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        IL2C_Tests_ClassTypeTestTarget** phoge3__;
        IL2C_Tests_ClassTypeTestTarget** pstack0_0__;
    } __executionFrame__;

    __executionFrame__.targetCount = 2;
    __executionFrame__.phoge3__ = &hoge3__;
    __executionFrame__.pstack0_0__ = &stack0_0__;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

/* D:\\PROJECT\\IL2C\\tests\\IL2C.Tests.Code\\ClassTypeTest.cs(39): */
    /* Path=1, Unique=0: IL_0000: nop */
    /* Path=1, Unique=0: IL_0001: newobj System.Void IL2C.Tests.ClassTypeTestTarget::.ctor() */
    stack0_0__ = il2c_get_uninitialized_object(il2c_typeof(IL2C_Tests_ClassTypeTestTarget));
    stack0_0__->vptr0__ = &__IL2C_Tests_ClassTypeTestTarget_VTABLE__;
    IL2C_Tests_ClassTypeTestTarget__ctor(stack0_0__);
    /* Path=1, Unique=0: IL_0006: stloc.0 */
    hoge3__ = stack0_0__;
/* D:\\PROJECT\\IL2C\\tests\\IL2C.Tests.Code\\ClassTypeTest.cs(41): */
    /* Path=1, Unique=0: IL_0007: ldloc.0 */
    stack0_0__ = hoge3__;
    /* Path=1, Unique=0: IL_0008: ldc.i4 456 */
    stack1_0__ = 456;
    /* Path=1, Unique=0: IL_000d: stfld System.Int32 IL2C.Tests.ClassTypeTestTarget::Value2 */
    stack0_0__->Value2 = stack1_0__;
/* D:\\PROJECT\\IL2C\\tests\\IL2C.Tests.Code\\ClassTypeTest.cs(43): */
    /* Path=1, Unique=0: IL_0012: ldloc.0 */
    stack0_0__ = hoge3__;
    /* Path=1, Unique=0: IL_0013: ldfld System.Int32 IL2C.Tests.ClassTypeTestTarget::Value2 */
    stack0_1__ = stack0_0__->Value2;
    /* Path=1, Unique=0: IL_0018: stloc.1 */
    local__ = stack0_1__;
    /* Path=1, Unique=0: IL_0019: br.s IL_001b */
    goto IL_001b;
IL_001b:
/* D:\\PROJECT\\IL2C\\tests\\IL2C.Tests.Code\\ClassTypeTest.cs(44): */
    /* Path=2, Unique=0: IL_001b: ldloc.1 */
    stack0_1__ = local__;
    /* Path=2, Unique=0: IL_001c: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return stack0_1__;
}

///////////////////////////////////////
// Test5

int32_t IL2C_Tests_ClassTypeTest_Test5(void)
{
    //-------------------
    // Local variables:

    IL2C_Tests_ClassTypeTestTarget* hoge3__ = NULL;
    int32_t result__;
    int32_t local__;

    //-------------------
    // Evaluation stacks:

    IL2C_Tests_ClassTypeTestTarget* stack0_0__ = NULL;
    int32_t stack0_1__;
    int32_t stack1_0__;
    int32_t stack2_0__;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        IL2C_Tests_ClassTypeTestTarget** phoge3__;
        IL2C_Tests_ClassTypeTestTarget** pstack0_0__;
    } __executionFrame__;

    __executionFrame__.targetCount = 2;
    __executionFrame__.phoge3__ = &hoge3__;
    __executionFrame__.pstack0_0__ = &stack0_0__;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

/* D:\\PROJECT\\IL2C\\tests\\IL2C.Tests.Code\\ClassTypeTest.cs(47): */
    /* Path=1, Unique=0: IL_0000: nop */
    /* Path=1, Unique=0: IL_0001: newobj System.Void IL2C.Tests.ClassTypeTestTarget::.ctor() */
    stack0_0__ = il2c_get_uninitialized_object(il2c_typeof(IL2C_Tests_ClassTypeTestTarget));
    stack0_0__->vptr0__ = &__IL2C_Tests_ClassTypeTestTarget_VTABLE__;
    IL2C_Tests_ClassTypeTestTarget__ctor(stack0_0__);
    /* Path=1, Unique=0: IL_0006: stloc.0 */
    hoge3__ = stack0_0__;
/* D:\\PROJECT\\IL2C\\tests\\IL2C.Tests.Code\\ClassTypeTest.cs(49): */
    /* Path=1, Unique=0: IL_0007: ldloc.0 */
    stack0_0__ = hoge3__;
    /* Path=1, Unique=0: IL_0008: ldc.i4 789 */
    stack1_0__ = 789;
    /* Path=1, Unique=0: IL_000d: stfld System.Int32 IL2C.Tests.ClassTypeTestTarget::Value2 */
    stack0_0__->Value2 = stack1_0__;
/* D:\\PROJECT\\IL2C\\tests\\IL2C.Tests.Code\\ClassTypeTest.cs(51): */
    /* Path=1, Unique=0: IL_0012: ldloc.0 */
    stack0_0__ = hoge3__;
    /* Path=1, Unique=0: IL_0013: ldc.i4.s 123 */
    stack1_0__ = 123;
    /* Path=1, Unique=0: IL_0015: ldc.i4 456 */
    stack2_0__ = 456;
    /* Path=1, Unique=0: IL_001a: callvirt System.Int32 IL2C.Tests.ClassTypeTestTarget::GetValue2(System.Int32,System.Int32) */
    stack0_1__ = IL2C_Tests_ClassTypeTestTarget_GetValue2(stack0_0__, stack1_0__, stack2_0__);
    /* Path=1, Unique=0: IL_001f: stloc.1 */
    result__ = stack0_1__;
/* D:\\PROJECT\\IL2C\\tests\\IL2C.Tests.Code\\ClassTypeTest.cs(52): */
    /* Path=1, Unique=0: IL_0020: ldloc.1 */
    stack0_1__ = result__;
    /* Path=1, Unique=0: IL_0021: stloc.2 */
    local__ = stack0_1__;
    /* Path=1, Unique=0: IL_0022: br.s IL_0024 */
    goto IL_0024;
IL_0024:
/* D:\\PROJECT\\IL2C\\tests\\IL2C.Tests.Code\\ClassTypeTest.cs(53): */
    /* Path=2, Unique=0: IL_0024: ldloc.2 */
    stack0_1__ = local__;
    /* Path=2, Unique=0: IL_0025: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return stack0_1__;
}

///////////////////////////////////////
// Test6

int32_t IL2C_Tests_ClassTypeTest_Test6(void)
{
    //-------------------
    // Local variables:

    IL2C_Tests_ClassTypeTestTarget* hoge3__ = NULL;
    int32_t result__;
    int32_t local__;

    //-------------------
    // Evaluation stacks:

    IL2C_Tests_ClassTypeTestTarget* stack0_0__ = NULL;
    int32_t stack0_1__;
    int32_t stack1_0__;
    int32_t stack2_0__;
    int32_t stack3_0__;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        IL2C_Tests_ClassTypeTestTarget** phoge3__;
        IL2C_Tests_ClassTypeTestTarget** pstack0_0__;
    } __executionFrame__;

    __executionFrame__.targetCount = 2;
    __executionFrame__.phoge3__ = &hoge3__;
    __executionFrame__.pstack0_0__ = &stack0_0__;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

/* D:\\PROJECT\\IL2C\\tests\\IL2C.Tests.Code\\ClassTypeTest.cs(56): */
    /* Path=1, Unique=0: IL_0000: nop */
    /* Path=1, Unique=0: IL_0001: newobj System.Void IL2C.Tests.ClassTypeTestTarget::.ctor() */
    stack0_0__ = il2c_get_uninitialized_object(il2c_typeof(IL2C_Tests_ClassTypeTestTarget));
    stack0_0__->vptr0__ = &__IL2C_Tests_ClassTypeTestTarget_VTABLE__;
    IL2C_Tests_ClassTypeTestTarget__ctor(stack0_0__);
    /* Path=1, Unique=0: IL_0006: stloc.0 */
    hoge3__ = stack0_0__;
/* D:\\PROJECT\\IL2C\\tests\\IL2C.Tests.Code\\ClassTypeTest.cs(58): */
    /* Path=1, Unique=0: IL_0007: ldloc.0 */
    stack0_0__ = hoge3__;
    /* Path=1, Unique=0: IL_0008: ldc.i4 789 */
    stack1_0__ = 789;
    /* Path=1, Unique=0: IL_000d: stfld System.Int32 IL2C.Tests.ClassTypeTestTarget::Value2 */
    stack0_0__->Value2 = stack1_0__;
/* D:\\PROJECT\\IL2C\\tests\\IL2C.Tests.Code\\ClassTypeTest.cs(60): */
    /* Path=1, Unique=0: IL_0012: ldloc.0 */
    stack0_0__ = hoge3__;
    /* Path=1, Unique=0: IL_0013: ldc.i4.s 123 */
    stack1_0__ = 123;
    /* Path=1, Unique=0: IL_0015: ldc.i4 456 */
    stack2_0__ = 456;
    /* Path=1, Unique=0: IL_001a: ldc.i4 789 */
    stack3_0__ = 789;
    /* Path=1, Unique=0: IL_001f: callvirt System.Int32 IL2C.Tests.ClassTypeTestTarget::GetValue2(System.Int32,System.Int32,System.Int32) */
    stack0_1__ = IL2C_Tests_ClassTypeTestTarget_GetValue2_1(stack0_0__, stack1_0__, stack2_0__, stack3_0__);
    /* Path=1, Unique=0: IL_0024: stloc.1 */
    result__ = stack0_1__;
/* D:\\PROJECT\\IL2C\\tests\\IL2C.Tests.Code\\ClassTypeTest.cs(61): */
    /* Path=1, Unique=0: IL_0025: ldloc.1 */
    stack0_1__ = result__;
    /* Path=1, Unique=0: IL_0026: stloc.2 */
    local__ = stack0_1__;
    /* Path=1, Unique=0: IL_0027: br.s IL_0029 */
    goto IL_0029;
IL_0029:
/* D:\\PROJECT\\IL2C\\tests\\IL2C.Tests.Code\\ClassTypeTest.cs(62): */
    /* Path=2, Unique=0: IL_0029: ldloc.2 */
    stack0_1__ = local__;
    /* Path=2, Unique=0: IL_002a: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return stack0_1__;
}

///////////////////////////////////////
// Test7

int32_t IL2C_Tests_ClassTypeTest_Test7(void)
{
    //-------------------
    // Local variables:

    IL2C_Tests_ClassTypeTestTarget* hoge3__ = NULL;
    int32_t local__;

    //-------------------
    // Evaluation stacks:

    int32_t stack0_0__;
    IL2C_Tests_ClassTypeTestTarget* stack0_1__ = NULL;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        IL2C_Tests_ClassTypeTestTarget** phoge3__;
        IL2C_Tests_ClassTypeTestTarget** pstack0_1__;
    } __executionFrame__;

    __executionFrame__.targetCount = 2;
    __executionFrame__.phoge3__ = &hoge3__;
    __executionFrame__.pstack0_1__ = &stack0_1__;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

/* D:\\PROJECT\\IL2C\\tests\\IL2C.Tests.Code\\ClassTypeTest.cs(65): */
    /* Path=1, Unique=0: IL_0000: nop */
    /* Path=1, Unique=0: IL_0001: ldc.i4.s 123 */
    stack0_0__ = 123;
    /* Path=1, Unique=0: IL_0003: newobj System.Void IL2C.Tests.ClassTypeTestTarget::.ctor(System.Int32) */
    stack0_1__ = il2c_get_uninitialized_object(il2c_typeof(IL2C_Tests_ClassTypeTestTarget));
    stack0_1__->vptr0__ = &__IL2C_Tests_ClassTypeTestTarget_VTABLE__;
    IL2C_Tests_ClassTypeTestTarget__ctor_1(stack0_1__, stack0_0__);
    /* Path=1, Unique=0: IL_0008: stloc.0 */
    hoge3__ = stack0_1__;
/* D:\\PROJECT\\IL2C\\tests\\IL2C.Tests.Code\\ClassTypeTest.cs(68): */
    /* Path=1, Unique=0: IL_0009: ldloc.0 */
    stack0_1__ = hoge3__;
    /* Path=1, Unique=0: IL_000a: ldfld System.Int32 IL2C.Tests.ClassTypeTestTarget::Value2 */
    stack0_0__ = stack0_1__->Value2;
    /* Path=1, Unique=0: IL_000f: stloc.1 */
    local__ = stack0_0__;
    /* Path=1, Unique=0: IL_0010: br.s IL_0012 */
    goto IL_0012;
IL_0012:
/* D:\\PROJECT\\IL2C\\tests\\IL2C.Tests.Code\\ClassTypeTest.cs(69): */
    /* Path=2, Unique=0: IL_0012: ldloc.1 */
    stack0_0__ = local__;
    /* Path=2, Unique=0: IL_0013: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return stack0_0__;
}

///////////////////////////////////////
// .ctor

void IL2C_Tests_ClassTypeTest__ctor(IL2C_Tests_ClassTypeTest* this__)
{
    //-------------------
    // Local variables:


    //-------------------
    // Evaluation stacks:

    IL2C_Tests_ClassTypeTest* stack0_0__ = NULL;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        IL2C_Tests_ClassTypeTest** pstack0_0__;
    } __executionFrame__;

    __executionFrame__.targetCount = 1;
    __executionFrame__.pstack0_0__ = &stack0_0__;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

    /* Path=1, Unique=0: IL_0000: ldarg.0 */
    stack0_0__ = this__;
    /* Path=1, Unique=0: IL_0001: call System.Void System.Object::.ctor() */
    /* Path=1, Unique=0: IL_0006: nop */
    /* Path=1, Unique=0: IL_0007: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return;
}

//////////////////////
// Runtime helpers:

// Runtime cast
void* __IL2C_Tests_ClassTypeTest_IL2C_RuntimeCast__(IL2C_Tests_ClassTypeTest* this__, IL2C_RUNTIME_TYPE_DECL* type)
{
    // This type
    if (type == il2c_typeof(IL2C_Tests_ClassTypeTest)) return this__;

    // Delegate checking base types
    return __System_Object_IL2C_RuntimeCast__((System_Object*)this__, type);
}

// GC's mark handler
void __IL2C_Tests_ClassTypeTest_IL2C_MarkHandler__(IL2C_Tests_ClassTypeTest* this__)
{

    /* Suppressed invoke base mark handler */
}

// Runtime type information
IL2C_RUNTIME_TYPE_DECL __IL2C_Tests_ClassTypeTest_RUNTIME_TYPE__ = {
    "IL2C.Tests.ClassTypeTest",
    sizeof(IL2C_Tests_ClassTypeTest),
    /* internalcall */ (void*)__IL2C_Tests_ClassTypeTest_IL2C_MarkHandler__,
};

//////////////////////
// VTables:

// Vtable of IL2C.Tests.ClassTypeTest
__IL2C_Tests_ClassTypeTest_VTABLE_DECL__ __IL2C_Tests_ClassTypeTest_VTABLE__ = {
    (void*)__IL2C_Tests_ClassTypeTest_IL2C_RuntimeCast__,
    (void*)__System_Object_ToString__,
    (void*)__System_Object_GetHashCode__,
    (void*)__System_Object_Finalize__,
    (void*)__System_Object_Equals__,
};

////////////////////////////////////////////////////////////
// Type: IL2C.Tests.Hoge1

///////////////////////////////////////
// Add1

int32_t IL2C_Tests_Hoge1_Add1(int32_t a, bool isTwo)
{
    //-------------------
    // Local variables:

    int32_t local__;

    //-------------------
    // Evaluation stacks:

    int32_t stack0_0__;
    int32_t stack1_0__;

    //-------------------
    // IL body:

/* D:\\PROJECT\\IL2C\\tests\\IL2C.Tests.Code\\Hoge1.cs(11): */
    /* Path=1, Unique=0: IL_0000: nop */
    /* Path=1, Unique=0: IL_0001: ldarg.0 */
    stack0_0__ = a;
    /* Path=1, Unique=0: IL_0002: ldarg.1 */
    stack1_0__ = (isTwo) ? 1 : 0;
    /* Path=1, Unique=0: IL_0003: brtrue.s IL_0008 */
    if (stack1_0__ != 0) goto IL_0008;
    /* Path=1, Unique=0: IL_0005: ldc.i4.1 */
    stack1_0__ = 1;
    /* Path=1, Unique=0: IL_0006: br.s IL_0009 */
    goto IL_0009;
IL_0008:
    /* Path=2, Unique=0: IL_0008: ldc.i4.2 */
    stack1_0__ = 2;
IL_0009:
    /* Path=2, Unique=0: IL_0009: add */
    stack0_0__ = stack0_0__ + stack1_0__;
    /* Path=2, Unique=0: IL_000a: stloc.0 */
    local__ = stack0_0__;
    /* Path=2, Unique=0: IL_000b: br.s IL_000d */
    goto IL_000d;
IL_000d:
/* D:\\PROJECT\\IL2C\\tests\\IL2C.Tests.Code\\Hoge1.cs(13): */
    /* Path=3, Unique=0: IL_000d: ldloc.0 */
    stack0_0__ = local__;
    /* Path=3, Unique=0: IL_000e: ret */
    return stack0_0__;
}

///////////////////////////////////////
// Add2

int64_t IL2C_Tests_Hoge1_Add2(int64_t a, bool isTwo)
{
    //-------------------
    // Local variables:

    int64_t local__;

    //-------------------
    // Evaluation stacks:

    int64_t stack0_0__;
    int32_t stack1_0__;
    int64_t stack1_1__;

    //-------------------
    // IL body:

/* D:\\PROJECT\\IL2C\\tests\\IL2C.Tests.Code\\Hoge1.cs(16): */
    /* Path=1, Unique=0: IL_0000: nop */
    /* Path=1, Unique=0: IL_0001: ldarg.0 */
    stack0_0__ = a;
    /* Path=1, Unique=0: IL_0002: ldarg.1 */
    stack1_0__ = (isTwo) ? 1 : 0;
    /* Path=1, Unique=0: IL_0003: brtrue.s IL_0008 */
    if (stack1_0__ != 0) goto IL_0008;
    /* Path=1, Unique=0: IL_0005: ldc.i4.1 */
    stack1_0__ = 1;
    /* Path=1, Unique=0: IL_0006: br.s IL_0009 */
    goto IL_0009;
IL_0008:
    /* Path=2, Unique=0: IL_0008: ldc.i4.2 */
    stack1_0__ = 2;
IL_0009:
    /* Path=2, Unique=0: IL_0009: conv.i8 */
    stack1_1__ = (int64_t)stack1_0__;
    /* Path=2, Unique=0: IL_000a: add */
    stack0_0__ = stack0_0__ + stack1_1__;
    /* Path=2, Unique=0: IL_000b: stloc.0 */
    local__ = stack0_0__;
    /* Path=2, Unique=0: IL_000c: br.s IL_000e */
    goto IL_000e;
IL_000e:
/* D:\\PROJECT\\IL2C\\tests\\IL2C.Tests.Code\\Hoge1.cs(18): */
    /* Path=3, Unique=0: IL_000e: ldloc.0 */
    stack0_0__ = local__;
    /* Path=3, Unique=0: IL_000f: ret */
    return stack0_0__;
}

///////////////////////////////////////
// .ctor

void IL2C_Tests_Hoge1__ctor(IL2C_Tests_Hoge1* this__)
{
    //-------------------
    // Local variables:


    //-------------------
    // Evaluation stacks:

    IL2C_Tests_Hoge1* stack0_0__ = NULL;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        IL2C_Tests_Hoge1** pstack0_0__;
    } __executionFrame__;

    __executionFrame__.targetCount = 1;
    __executionFrame__.pstack0_0__ = &stack0_0__;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

    /* Path=1, Unique=0: IL_0000: ldarg.0 */
    stack0_0__ = this__;
    /* Path=1, Unique=0: IL_0001: call System.Void System.Object::.ctor() */
    /* Path=1, Unique=0: IL_0006: nop */
    /* Path=1, Unique=0: IL_0007: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return;
}

//////////////////////
// Runtime helpers:

// Runtime cast
void* __IL2C_Tests_Hoge1_IL2C_RuntimeCast__(IL2C_Tests_Hoge1* this__, IL2C_RUNTIME_TYPE_DECL* type)
{
    // This type
    if (type == il2c_typeof(IL2C_Tests_Hoge1)) return this__;

    // Delegate checking base types
    return __System_Object_IL2C_RuntimeCast__((System_Object*)this__, type);
}

// GC's mark handler
void __IL2C_Tests_Hoge1_IL2C_MarkHandler__(IL2C_Tests_Hoge1* this__)
{

    /* Suppressed invoke base mark handler */
}

// Runtime type information
IL2C_RUNTIME_TYPE_DECL __IL2C_Tests_Hoge1_RUNTIME_TYPE__ = {
    "IL2C.Tests.Hoge1",
    sizeof(IL2C_Tests_Hoge1),
    /* internalcall */ (void*)__IL2C_Tests_Hoge1_IL2C_MarkHandler__,
};

//////////////////////
// VTables:

// Vtable of IL2C.Tests.Hoge1
__IL2C_Tests_Hoge1_VTABLE_DECL__ __IL2C_Tests_Hoge1_VTABLE__ = {
    (void*)__IL2C_Tests_Hoge1_IL2C_RuntimeCast__,
    (void*)__System_Object_ToString__,
    (void*)__System_Object_GetHashCode__,
    (void*)__System_Object_Finalize__,
    (void*)__System_Object_Equals__,
};

////////////////////////////////////////////////////////////
// Type: IL2C.Tests.Hoge2

///////////////////////////////////////
// Add3

uint8_t IL2C_Tests_Hoge2_Add3(uint8_t a, bool isTwo)
{
    //-------------------
    // Local variables:

    uint8_t local__;

    //-------------------
    // Evaluation stacks:

    int32_t stack0_0__;
    int32_t stack1_0__;

    //-------------------
    // IL body:

/* D:\\PROJECT\\IL2C\\tests\\IL2C.Tests.Code\\Hoge2.cs(11): */
    /* Path=1, Unique=0: IL_0000: nop */
    /* Path=1, Unique=0: IL_0001: ldarg.0 */
    stack0_0__ = (int32_t)(a);
    /* Path=1, Unique=0: IL_0002: ldarg.1 */
    stack1_0__ = (isTwo) ? 1 : 0;
    /* Path=1, Unique=0: IL_0003: brtrue.s IL_0008 */
    if (stack1_0__ != 0) goto IL_0008;
    /* Path=1, Unique=0: IL_0005: ldc.i4.1 */
    stack1_0__ = 1;
    /* Path=1, Unique=0: IL_0006: br.s IL_0009 */
    goto IL_0009;
IL_0008:
    /* Path=2, Unique=0: IL_0008: ldc.i4.2 */
    stack1_0__ = 2;
IL_0009:
    /* Path=2, Unique=0: IL_0009: add */
    stack0_0__ = stack0_0__ + stack1_0__;
    /* Path=2, Unique=0: IL_000a: conv.u1 */
    stack0_0__ = (uint8_t)stack0_0__;
    /* Path=2, Unique=0: IL_000b: stloc.0 */
    local__ = (uint8_t)stack0_0__;
    /* Path=2, Unique=0: IL_000c: br.s IL_000e */
    goto IL_000e;
IL_000e:
/* D:\\PROJECT\\IL2C\\tests\\IL2C.Tests.Code\\Hoge2.cs(13): */
    /* Path=3, Unique=0: IL_000e: ldloc.0 */
    stack0_0__ = local__;
    /* Path=3, Unique=0: IL_000f: ret */
    return (uint8_t)stack0_0__;
}

///////////////////////////////////////
// Add4

uint16_t IL2C_Tests_Hoge2_Add4(uint16_t a, bool isTwo)
{
    //-------------------
    // Local variables:

    uint16_t local__;

    //-------------------
    // Evaluation stacks:

    int32_t stack0_0__;
    int32_t stack1_0__;

    //-------------------
    // IL body:

/* D:\\PROJECT\\IL2C\\tests\\IL2C.Tests.Code\\Hoge2.cs(16): */
    /* Path=1, Unique=0: IL_0000: nop */
    /* Path=1, Unique=0: IL_0001: ldarg.0 */
    stack0_0__ = (int32_t)(a);
    /* Path=1, Unique=0: IL_0002: ldarg.1 */
    stack1_0__ = (isTwo) ? 1 : 0;
    /* Path=1, Unique=0: IL_0003: brtrue.s IL_0008 */
    if (stack1_0__ != 0) goto IL_0008;
    /* Path=1, Unique=0: IL_0005: ldc.i4.1 */
    stack1_0__ = 1;
    /* Path=1, Unique=0: IL_0006: br.s IL_0009 */
    goto IL_0009;
IL_0008:
    /* Path=2, Unique=0: IL_0008: ldc.i4.2 */
    stack1_0__ = 2;
IL_0009:
    /* Path=2, Unique=0: IL_0009: add */
    stack0_0__ = stack0_0__ + stack1_0__;
    /* Path=2, Unique=0: IL_000a: conv.u2 */
    stack0_0__ = (uint16_t)stack0_0__;
    /* Path=2, Unique=0: IL_000b: stloc.0 */
    local__ = (uint16_t)stack0_0__;
    /* Path=2, Unique=0: IL_000c: br.s IL_000e */
    goto IL_000e;
IL_000e:
/* D:\\PROJECT\\IL2C\\tests\\IL2C.Tests.Code\\Hoge2.cs(18): */
    /* Path=3, Unique=0: IL_000e: ldloc.0 */
    stack0_0__ = local__;
    /* Path=3, Unique=0: IL_000f: ret */
    return (uint16_t)stack0_0__;
}

///////////////////////////////////////
// .ctor

void IL2C_Tests_Hoge2__ctor(IL2C_Tests_Hoge2* this__)
{
    //-------------------
    // Local variables:


    //-------------------
    // Evaluation stacks:

    IL2C_Tests_Hoge2* stack0_0__ = NULL;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        IL2C_Tests_Hoge2** pstack0_0__;
    } __executionFrame__;

    __executionFrame__.targetCount = 1;
    __executionFrame__.pstack0_0__ = &stack0_0__;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

    /* Path=1, Unique=0: IL_0000: ldarg.0 */
    stack0_0__ = this__;
    /* Path=1, Unique=0: IL_0001: call System.Void System.Object::.ctor() */
    /* Path=1, Unique=0: IL_0006: nop */
    /* Path=1, Unique=0: IL_0007: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return;
}

//////////////////////
// Runtime helpers:

// Runtime cast
void* __IL2C_Tests_Hoge2_IL2C_RuntimeCast__(IL2C_Tests_Hoge2* this__, IL2C_RUNTIME_TYPE_DECL* type)
{
    // This type
    if (type == il2c_typeof(IL2C_Tests_Hoge2)) return this__;

    // Delegate checking base types
    return __System_Object_IL2C_RuntimeCast__((System_Object*)this__, type);
}

// GC's mark handler
void __IL2C_Tests_Hoge2_IL2C_MarkHandler__(IL2C_Tests_Hoge2* this__)
{

    /* Suppressed invoke base mark handler */
}

// Runtime type information
IL2C_RUNTIME_TYPE_DECL __IL2C_Tests_Hoge2_RUNTIME_TYPE__ = {
    "IL2C.Tests.Hoge2",
    sizeof(IL2C_Tests_Hoge2),
    /* internalcall */ (void*)__IL2C_Tests_Hoge2_IL2C_MarkHandler__,
};

//////////////////////
// VTables:

// Vtable of IL2C.Tests.Hoge2
__IL2C_Tests_Hoge2_VTABLE_DECL__ __IL2C_Tests_Hoge2_VTABLE__ = {
    (void*)__IL2C_Tests_Hoge2_IL2C_RuntimeCast__,
    (void*)__System_Object_ToString__,
    (void*)__System_Object_GetHashCode__,
    (void*)__System_Object_Finalize__,
    (void*)__System_Object_Equals__,
};

////////////////////////////////////////////////////////////
// Type: IL2C.Tests.InheritTestTargetBase1

///////////////////////////////////////
// .ctor

void IL2C_Tests_InheritTestTargetBase1__ctor(IL2C_Tests_InheritTestTargetBase1* this__)
{
    //-------------------
    // Local variables:


    //-------------------
    // Evaluation stacks:

    IL2C_Tests_InheritTestTargetBase1* stack0_0__ = NULL;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        IL2C_Tests_InheritTestTargetBase1** pstack0_0__;
    } __executionFrame__;

    __executionFrame__.targetCount = 1;
    __executionFrame__.pstack0_0__ = &stack0_0__;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

/* D:\\PROJECT\\IL2C\\tests\\IL2C.Tests.Code\\InheritTest.cs(13): */
    /* Path=1, Unique=0: IL_0000: ldarg.0 */
    stack0_0__ = this__;
    /* Path=1, Unique=0: IL_0001: call System.Void System.Object::.ctor() */
    /* Path=1, Unique=0: IL_0006: nop */
/* D:\\PROJECT\\IL2C\\tests\\IL2C.Tests.Code\\InheritTest.cs(14): */
    /* Path=1, Unique=0: IL_0007: nop */
    /* Path=1, Unique=0: IL_0008: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return;
}

///////////////////////////////////////
// .ctor

void IL2C_Tests_InheritTestTargetBase1__ctor_1(IL2C_Tests_InheritTestTargetBase1* this__, int32_t value)
{
    //-------------------
    // Local variables:


    //-------------------
    // Evaluation stacks:

    IL2C_Tests_InheritTestTargetBase1* stack0_0__ = NULL;
    int32_t stack1_0__;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        IL2C_Tests_InheritTestTargetBase1** pstack0_0__;
    } __executionFrame__;

    __executionFrame__.targetCount = 1;
    __executionFrame__.pstack0_0__ = &stack0_0__;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

/* D:\\PROJECT\\IL2C\\tests\\IL2C.Tests.Code\\InheritTest.cs(17): */
    /* Path=1, Unique=0: IL_0000: ldarg.0 */
    stack0_0__ = this__;
    /* Path=1, Unique=0: IL_0001: call System.Void System.Object::.ctor() */
    /* Path=1, Unique=0: IL_0006: nop */
/* D:\\PROJECT\\IL2C\\tests\\IL2C.Tests.Code\\InheritTest.cs(18): */
    /* Path=1, Unique=0: IL_0007: nop */
    /* Path=1, Unique=0: IL_0008: ldarg.0 */
    stack0_0__ = this__;
    /* Path=1, Unique=0: IL_0009: ldarg.1 */
    stack1_0__ = value;
    /* Path=1, Unique=0: IL_000a: stfld System.Int32 IL2C.Tests.InheritTestTargetBase1::Value2 */
    stack0_0__->Value2 = stack1_0__;
/* D:\\PROJECT\\IL2C\\tests\\IL2C.Tests.Code\\InheritTest.cs(20): */
    /* Path=1, Unique=0: IL_000f: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return;
}

///////////////////////////////////////
// Calc

int32_t IL2C_Tests_InheritTestTargetBase1_Calc(IL2C_Tests_InheritTestTargetBase1* this__, int32_t a)
{
    //-------------------
    // Local variables:

    int32_t local__;

    //-------------------
    // Evaluation stacks:

    IL2C_Tests_InheritTestTargetBase1* stack0_0__ = NULL;
    int32_t stack0_1__;
    int32_t stack1_0__;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        IL2C_Tests_InheritTestTargetBase1** pstack0_0__;
    } __executionFrame__;

    __executionFrame__.targetCount = 1;
    __executionFrame__.pstack0_0__ = &stack0_0__;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

/* D:\\PROJECT\\IL2C\\tests\\IL2C.Tests.Code\\InheritTest.cs(23): */
    /* Path=1, Unique=0: IL_0000: nop */
    /* Path=1, Unique=0: IL_0001: ldarg.0 */
    stack0_0__ = this__;
    /* Path=1, Unique=0: IL_0002: ldfld System.Int32 IL2C.Tests.InheritTestTargetBase1::Value2 */
    stack0_1__ = stack0_0__->Value2;
    /* Path=1, Unique=0: IL_0007: ldarg.1 */
    stack1_0__ = a;
    /* Path=1, Unique=0: IL_0008: add */
    stack0_1__ = stack0_1__ + stack1_0__;
    /* Path=1, Unique=0: IL_0009: stloc.0 */
    local__ = stack0_1__;
    /* Path=1, Unique=0: IL_000a: br.s IL_000c */
    goto IL_000c;
IL_000c:
/* D:\\PROJECT\\IL2C\\tests\\IL2C.Tests.Code\\InheritTest.cs(25): */
    /* Path=2, Unique=0: IL_000c: ldloc.0 */
    stack0_1__ = local__;
    /* Path=2, Unique=0: IL_000d: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return stack0_1__;
}

///////////////////////////////////////
// Virtual: Calc

int32_t __IL2C_Tests_InheritTestTargetBase1_Calc_1__(IL2C_Tests_InheritTestTargetBase1* this__, int32_t a, int32_t b)
{
    //-------------------
    // Local variables:

    int32_t local__;

    //-------------------
    // Evaluation stacks:

    IL2C_Tests_InheritTestTargetBase1* stack0_0__ = NULL;
    int32_t stack0_1__;
    int32_t stack1_0__;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        IL2C_Tests_InheritTestTargetBase1** pstack0_0__;
    } __executionFrame__;

    __executionFrame__.targetCount = 1;
    __executionFrame__.pstack0_0__ = &stack0_0__;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

/* D:\\PROJECT\\IL2C\\tests\\IL2C.Tests.Code\\InheritTest.cs(28): */
    /* Path=1, Unique=0: IL_0000: nop */
    /* Path=1, Unique=0: IL_0001: ldarg.0 */
    stack0_0__ = this__;
    /* Path=1, Unique=0: IL_0002: ldfld System.Int32 IL2C.Tests.InheritTestTargetBase1::Value2 */
    stack0_1__ = stack0_0__->Value2;
    /* Path=1, Unique=0: IL_0007: ldarg.1 */
    stack1_0__ = a;
    /* Path=1, Unique=0: IL_0008: add */
    stack0_1__ = stack0_1__ + stack1_0__;
    /* Path=1, Unique=0: IL_0009: ldarg.2 */
    stack1_0__ = b;
    /* Path=1, Unique=0: IL_000a: add */
    stack0_1__ = stack0_1__ + stack1_0__;
    /* Path=1, Unique=0: IL_000b: stloc.0 */
    local__ = stack0_1__;
    /* Path=1, Unique=0: IL_000c: br.s IL_000e */
    goto IL_000e;
IL_000e:
/* D:\\PROJECT\\IL2C\\tests\\IL2C.Tests.Code\\InheritTest.cs(30): */
    /* Path=2, Unique=0: IL_000e: ldloc.0 */
    stack0_1__ = local__;
    /* Path=2, Unique=0: IL_000f: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return stack0_1__;
}

//////////////////////
// Runtime helpers:

// Runtime cast
void* __IL2C_Tests_InheritTestTargetBase1_IL2C_RuntimeCast__(IL2C_Tests_InheritTestTargetBase1* this__, IL2C_RUNTIME_TYPE_DECL* type)
{
    // This type
    if (type == il2c_typeof(IL2C_Tests_InheritTestTargetBase1)) return this__;

    // Delegate checking base types
    return __System_Object_IL2C_RuntimeCast__((System_Object*)this__, type);
}

// GC's mark handler
void __IL2C_Tests_InheritTestTargetBase1_IL2C_MarkHandler__(IL2C_Tests_InheritTestTargetBase1* this__)
{
    // Try marking each object reference fields
    il2c_try_mark_from_handler(this__->OR2);

    /* Suppressed invoke base mark handler */
}

// Runtime type information
IL2C_RUNTIME_TYPE_DECL __IL2C_Tests_InheritTestTargetBase1_RUNTIME_TYPE__ = {
    "IL2C.Tests.InheritTestTargetBase1",
    sizeof(IL2C_Tests_InheritTestTargetBase1),
    /* internalcall */ (void*)__IL2C_Tests_InheritTestTargetBase1_IL2C_MarkHandler__,
};

//////////////////////
// VTables:

// Vtable of IL2C.Tests.InheritTestTargetBase1
__IL2C_Tests_InheritTestTargetBase1_VTABLE_DECL__ __IL2C_Tests_InheritTestTargetBase1_VTABLE__ = {
    (void*)__IL2C_Tests_InheritTestTargetBase1_IL2C_RuntimeCast__,
    (void*)__System_Object_ToString__,
    (void*)__System_Object_GetHashCode__,
    (void*)__System_Object_Finalize__,
    (void*)__System_Object_Equals__,
    (void*)__IL2C_Tests_InheritTestTargetBase1_Calc_1__,
};

////////////////////////////////////////////////////////////
// Type: IL2C.Tests.InheritTestTarget2

///////////////////////////////////////
// .ctor

void IL2C_Tests_InheritTestTarget2__ctor(IL2C_Tests_InheritTestTarget2* this__)
{
    //-------------------
    // Local variables:


    //-------------------
    // Evaluation stacks:

    IL2C_Tests_InheritTestTarget2* stack0_0__ = NULL;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        IL2C_Tests_InheritTestTarget2** pstack0_0__;
    } __executionFrame__;

    __executionFrame__.targetCount = 1;
    __executionFrame__.pstack0_0__ = &stack0_0__;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

/* D:\\PROJECT\\IL2C\\tests\\IL2C.Tests.Code\\InheritTest.cs(35): */
    /* Path=1, Unique=0: IL_0000: ldarg.0 */
    stack0_0__ = this__;
    /* Path=1, Unique=0: IL_0001: call System.Void IL2C.Tests.InheritTestTargetBase1::.ctor() */
    IL2C_Tests_InheritTestTargetBase1__ctor((IL2C_Tests_InheritTestTargetBase1*)stack0_0__);
    /* Path=1, Unique=0: IL_0006: nop */
/* D:\\PROJECT\\IL2C\\tests\\IL2C.Tests.Code\\InheritTest.cs(36): */
    /* Path=1, Unique=0: IL_0007: nop */
    /* Path=1, Unique=0: IL_0008: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return;
}

///////////////////////////////////////
// .ctor

void IL2C_Tests_InheritTestTarget2__ctor_1(IL2C_Tests_InheritTestTarget2* this__, int32_t value)
{
    //-------------------
    // Local variables:


    //-------------------
    // Evaluation stacks:

    IL2C_Tests_InheritTestTarget2* stack0_0__ = NULL;
    int32_t stack1_0__;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        IL2C_Tests_InheritTestTarget2** pstack0_0__;
    } __executionFrame__;

    __executionFrame__.targetCount = 1;
    __executionFrame__.pstack0_0__ = &stack0_0__;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

/* D:\\PROJECT\\IL2C\\tests\\IL2C.Tests.Code\\InheritTest.cs(40): */
    /* Path=1, Unique=0: IL_0000: ldarg.0 */
    stack0_0__ = this__;
    /* Path=1, Unique=0: IL_0001: ldarg.1 */
    stack1_0__ = value;
    /* Path=1, Unique=0: IL_0002: call System.Void IL2C.Tests.InheritTestTargetBase1::.ctor(System.Int32) */
    IL2C_Tests_InheritTestTargetBase1__ctor_1((IL2C_Tests_InheritTestTargetBase1*)stack0_0__, stack1_0__);
    /* Path=1, Unique=0: IL_0007: nop */
/* D:\\PROJECT\\IL2C\\tests\\IL2C.Tests.Code\\InheritTest.cs(41): */
    /* Path=1, Unique=0: IL_0008: nop */
    /* Path=1, Unique=0: IL_0009: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return;
}

///////////////////////////////////////
// Calc

int32_t IL2C_Tests_InheritTestTarget2_Calc(IL2C_Tests_InheritTestTarget2* this__, int32_t a)
{
    //-------------------
    // Local variables:

    int32_t local__;

    //-------------------
    // Evaluation stacks:

    IL2C_Tests_InheritTestTarget2* stack0_0__ = NULL;
    int32_t stack0_1__;
    int32_t stack1_0__;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        IL2C_Tests_InheritTestTarget2** pstack0_0__;
    } __executionFrame__;

    __executionFrame__.targetCount = 1;
    __executionFrame__.pstack0_0__ = &stack0_0__;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

/* D:\\PROJECT\\IL2C\\tests\\IL2C.Tests.Code\\InheritTest.cs(45): */
    /* Path=1, Unique=0: IL_0000: nop */
    /* Path=1, Unique=0: IL_0001: ldarg.0 */
    stack0_0__ = this__;
    /* Path=1, Unique=0: IL_0002: ldfld System.Int32 IL2C.Tests.InheritTestTargetBase1::Value2 */
    stack0_1__ = stack0_0__->Value2;
    /* Path=1, Unique=0: IL_0007: ldarg.1 */
    stack1_0__ = a;
    /* Path=1, Unique=0: IL_0008: add */
    stack0_1__ = stack0_1__ + stack1_0__;
    /* Path=1, Unique=0: IL_0009: ldc.i4 10000 */
    stack1_0__ = 10000;
    /* Path=1, Unique=0: IL_000e: add */
    stack0_1__ = stack0_1__ + stack1_0__;
    /* Path=1, Unique=0: IL_000f: stloc.0 */
    local__ = stack0_1__;
    /* Path=1, Unique=0: IL_0010: br.s IL_0012 */
    goto IL_0012;
IL_0012:
/* D:\\PROJECT\\IL2C\\tests\\IL2C.Tests.Code\\InheritTest.cs(47): */
    /* Path=2, Unique=0: IL_0012: ldloc.0 */
    stack0_1__ = local__;
    /* Path=2, Unique=0: IL_0013: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return stack0_1__;
}

///////////////////////////////////////
// Virtual: Calc

int32_t __IL2C_Tests_InheritTestTarget2_Calc_1__(IL2C_Tests_InheritTestTarget2* this__, int32_t a, int32_t b)
{
    //-------------------
    // Local variables:

    int32_t local__;

    //-------------------
    // Evaluation stacks:

    IL2C_Tests_InheritTestTarget2* stack0_0__ = NULL;
    int32_t stack0_1__;
    int32_t stack1_0__;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        IL2C_Tests_InheritTestTarget2** pstack0_0__;
    } __executionFrame__;

    __executionFrame__.targetCount = 1;
    __executionFrame__.pstack0_0__ = &stack0_0__;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

/* D:\\PROJECT\\IL2C\\tests\\IL2C.Tests.Code\\InheritTest.cs(50): */
    /* Path=1, Unique=0: IL_0000: nop */
    /* Path=1, Unique=0: IL_0001: ldarg.0 */
    stack0_0__ = this__;
    /* Path=1, Unique=0: IL_0002: ldfld System.Int32 IL2C.Tests.InheritTestTargetBase1::Value2 */
    stack0_1__ = stack0_0__->Value2;
    /* Path=1, Unique=0: IL_0007: ldarg.1 */
    stack1_0__ = a;
    /* Path=1, Unique=0: IL_0008: add */
    stack0_1__ = stack0_1__ + stack1_0__;
    /* Path=1, Unique=0: IL_0009: ldarg.2 */
    stack1_0__ = b;
    /* Path=1, Unique=0: IL_000a: add */
    stack0_1__ = stack0_1__ + stack1_0__;
    /* Path=1, Unique=0: IL_000b: ldc.i4 10000 */
    stack1_0__ = 10000;
    /* Path=1, Unique=0: IL_0010: add */
    stack0_1__ = stack0_1__ + stack1_0__;
    /* Path=1, Unique=0: IL_0011: stloc.0 */
    local__ = stack0_1__;
    /* Path=1, Unique=0: IL_0012: br.s IL_0014 */
    goto IL_0014;
IL_0014:
/* D:\\PROJECT\\IL2C\\tests\\IL2C.Tests.Code\\InheritTest.cs(52): */
    /* Path=2, Unique=0: IL_0014: ldloc.0 */
    stack0_1__ = local__;
    /* Path=2, Unique=0: IL_0015: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return stack0_1__;
}

//////////////////////
// Runtime helpers:

// Runtime cast
void* __IL2C_Tests_InheritTestTarget2_IL2C_RuntimeCast__(IL2C_Tests_InheritTestTarget2* this__, IL2C_RUNTIME_TYPE_DECL* type)
{
    // This type
    if (type == il2c_typeof(IL2C_Tests_InheritTestTarget2)) return this__;

    // Delegate checking base types
    return __IL2C_Tests_InheritTestTargetBase1_IL2C_RuntimeCast__((IL2C_Tests_InheritTestTargetBase1*)this__, type);
}

// GC's mark handler
void __IL2C_Tests_InheritTestTarget2_IL2C_MarkHandler__(IL2C_Tests_InheritTestTarget2* this__)
{

    // Delegate checking base types
    __IL2C_Tests_InheritTestTargetBase1_IL2C_MarkHandler__((IL2C_Tests_InheritTestTargetBase1*)this__);
}

// Runtime type information
IL2C_RUNTIME_TYPE_DECL __IL2C_Tests_InheritTestTarget2_RUNTIME_TYPE__ = {
    "IL2C.Tests.InheritTestTarget2",
    sizeof(IL2C_Tests_InheritTestTarget2),
    /* internalcall */ (void*)__IL2C_Tests_InheritTestTarget2_IL2C_MarkHandler__,
};

//////////////////////
// VTables:

// Vtable of IL2C.Tests.InheritTestTarget2
__IL2C_Tests_InheritTestTarget2_VTABLE_DECL__ __IL2C_Tests_InheritTestTarget2_VTABLE__ = {
    (void*)__IL2C_Tests_InheritTestTarget2_IL2C_RuntimeCast__,
    (void*)__System_Object_ToString__,
    (void*)__System_Object_GetHashCode__,
    (void*)__System_Object_Finalize__,
    (void*)__System_Object_Equals__,
    (void*)__IL2C_Tests_InheritTestTarget2_Calc_1__,
};

////////////////////////////////////////////////////////////
// Type: IL2C.Tests.InheritTypeTest

///////////////////////////////////////
// Test1

int32_t IL2C_Tests_InheritTypeTest_Test1(void)
{
    //-------------------
    // Local variables:

    IL2C_Tests_InheritTestTargetBase1* hoge__ = NULL;
    int32_t local__;

    //-------------------
    // Evaluation stacks:

    IL2C_Tests_InheritTestTargetBase1* stack0_0__ = NULL;
    int32_t stack0_1__;
    int32_t stack1_0__;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        IL2C_Tests_InheritTestTargetBase1** phoge__;
        IL2C_Tests_InheritTestTargetBase1** pstack0_0__;
    } __executionFrame__;

    __executionFrame__.targetCount = 2;
    __executionFrame__.phoge__ = &hoge__;
    __executionFrame__.pstack0_0__ = &stack0_0__;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

/* D:\\PROJECT\\IL2C\\tests\\IL2C.Tests.Code\\InheritTest.cs(58): */
    /* Path=1, Unique=0: IL_0000: nop */
    /* Path=1, Unique=0: IL_0001: newobj System.Void IL2C.Tests.InheritTestTargetBase1::.ctor() */
    stack0_0__ = il2c_get_uninitialized_object(il2c_typeof(IL2C_Tests_InheritTestTargetBase1));
    stack0_0__->vptr0__ = &__IL2C_Tests_InheritTestTargetBase1_VTABLE__;
    IL2C_Tests_InheritTestTargetBase1__ctor(stack0_0__);
    /* Path=1, Unique=0: IL_0006: stloc.0 */
    hoge__ = stack0_0__;
/* D:\\PROJECT\\IL2C\\tests\\IL2C.Tests.Code\\InheritTest.cs(60): */
    /* Path=1, Unique=0: IL_0007: ldloc.0 */
    stack0_0__ = hoge__;
    /* Path=1, Unique=0: IL_0008: ldc.i4.s 123 */
    stack1_0__ = 123;
    /* Path=1, Unique=0: IL_000a: stfld System.Int32 IL2C.Tests.InheritTestTargetBase1::Value2 */
    stack0_0__->Value2 = stack1_0__;
/* D:\\PROJECT\\IL2C\\tests\\IL2C.Tests.Code\\InheritTest.cs(62): */
    /* Path=1, Unique=0: IL_000f: ldloc.0 */
    stack0_0__ = hoge__;
    /* Path=1, Unique=0: IL_0010: ldc.i4.1 */
    stack1_0__ = 1;
    /* Path=1, Unique=0: IL_0011: callvirt System.Int32 IL2C.Tests.InheritTestTargetBase1::Calc(System.Int32) */
    stack0_1__ = IL2C_Tests_InheritTestTargetBase1_Calc(stack0_0__, stack1_0__);
    /* Path=1, Unique=0: IL_0016: stloc.1 */
    local__ = stack0_1__;
    /* Path=1, Unique=0: IL_0017: br.s IL_0019 */
    goto IL_0019;
IL_0019:
/* D:\\PROJECT\\IL2C\\tests\\IL2C.Tests.Code\\InheritTest.cs(63): */
    /* Path=2, Unique=0: IL_0019: ldloc.1 */
    stack0_1__ = local__;
    /* Path=2, Unique=0: IL_001a: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return stack0_1__;
}

///////////////////////////////////////
// Test2

int32_t IL2C_Tests_InheritTypeTest_Test2(void)
{
    //-------------------
    // Local variables:

    IL2C_Tests_InheritTestTargetBase1* hoge__ = NULL;
    int32_t local__;

    //-------------------
    // Evaluation stacks:

    IL2C_Tests_InheritTestTargetBase1* stack0_0__ = NULL;
    int32_t stack0_1__;
    int32_t stack1_0__;
    int32_t stack2_0__;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        IL2C_Tests_InheritTestTargetBase1** phoge__;
        IL2C_Tests_InheritTestTargetBase1** pstack0_0__;
    } __executionFrame__;

    __executionFrame__.targetCount = 2;
    __executionFrame__.phoge__ = &hoge__;
    __executionFrame__.pstack0_0__ = &stack0_0__;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

/* D:\\PROJECT\\IL2C\\tests\\IL2C.Tests.Code\\InheritTest.cs(66): */
    /* Path=1, Unique=0: IL_0000: nop */
    /* Path=1, Unique=0: IL_0001: newobj System.Void IL2C.Tests.InheritTestTargetBase1::.ctor() */
    stack0_0__ = il2c_get_uninitialized_object(il2c_typeof(IL2C_Tests_InheritTestTargetBase1));
    stack0_0__->vptr0__ = &__IL2C_Tests_InheritTestTargetBase1_VTABLE__;
    IL2C_Tests_InheritTestTargetBase1__ctor(stack0_0__);
    /* Path=1, Unique=0: IL_0006: stloc.0 */
    hoge__ = stack0_0__;
/* D:\\PROJECT\\IL2C\\tests\\IL2C.Tests.Code\\InheritTest.cs(68): */
    /* Path=1, Unique=0: IL_0007: ldloc.0 */
    stack0_0__ = hoge__;
    /* Path=1, Unique=0: IL_0008: ldc.i4.s 123 */
    stack1_0__ = 123;
    /* Path=1, Unique=0: IL_000a: stfld System.Int32 IL2C.Tests.InheritTestTargetBase1::Value2 */
    stack0_0__->Value2 = stack1_0__;
/* D:\\PROJECT\\IL2C\\tests\\IL2C.Tests.Code\\InheritTest.cs(70): */
    /* Path=1, Unique=0: IL_000f: ldloc.0 */
    stack0_0__ = hoge__;
    /* Path=1, Unique=0: IL_0010: ldc.i4.1 */
    stack1_0__ = 1;
    /* Path=1, Unique=0: IL_0011: ldc.i4.2 */
    stack2_0__ = 2;
    /* Path=1, Unique=0: IL_0012: callvirt System.Int32 IL2C.Tests.InheritTestTargetBase1::Calc(System.Int32,System.Int32) */
    stack0_1__ = IL2C_Tests_InheritTestTargetBase1_Calc_1(stack0_0__, stack1_0__, stack2_0__);
    /* Path=1, Unique=0: IL_0017: stloc.1 */
    local__ = stack0_1__;
    /* Path=1, Unique=0: IL_0018: br.s IL_001a */
    goto IL_001a;
IL_001a:
/* D:\\PROJECT\\IL2C\\tests\\IL2C.Tests.Code\\InheritTest.cs(71): */
    /* Path=2, Unique=0: IL_001a: ldloc.1 */
    stack0_1__ = local__;
    /* Path=2, Unique=0: IL_001b: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return stack0_1__;
}

///////////////////////////////////////
// Test3

int32_t IL2C_Tests_InheritTypeTest_Test3(void)
{
    //-------------------
    // Local variables:

    IL2C_Tests_InheritTestTarget2* hoge__ = NULL;
    int32_t local__;

    //-------------------
    // Evaluation stacks:

    IL2C_Tests_InheritTestTarget2* stack0_0__ = NULL;
    int32_t stack0_1__;
    int32_t stack1_0__;
    int32_t stack2_0__;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        IL2C_Tests_InheritTestTarget2** phoge__;
        IL2C_Tests_InheritTestTarget2** pstack0_0__;
    } __executionFrame__;

    __executionFrame__.targetCount = 2;
    __executionFrame__.phoge__ = &hoge__;
    __executionFrame__.pstack0_0__ = &stack0_0__;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

/* D:\\PROJECT\\IL2C\\tests\\IL2C.Tests.Code\\InheritTest.cs(74): */
    /* Path=1, Unique=0: IL_0000: nop */
    /* Path=1, Unique=0: IL_0001: newobj System.Void IL2C.Tests.InheritTestTarget2::.ctor() */
    stack0_0__ = il2c_get_uninitialized_object(il2c_typeof(IL2C_Tests_InheritTestTarget2));
    stack0_0__->vptr0__ = &__IL2C_Tests_InheritTestTarget2_VTABLE__;
    IL2C_Tests_InheritTestTarget2__ctor(stack0_0__);
    /* Path=1, Unique=0: IL_0006: stloc.0 */
    hoge__ = stack0_0__;
/* D:\\PROJECT\\IL2C\\tests\\IL2C.Tests.Code\\InheritTest.cs(76): */
    /* Path=1, Unique=0: IL_0007: ldloc.0 */
    stack0_0__ = hoge__;
    /* Path=1, Unique=0: IL_0008: ldc.i4.s 123 */
    stack1_0__ = 123;
    /* Path=1, Unique=0: IL_000a: stfld System.Int32 IL2C.Tests.InheritTestTargetBase1::Value2 */
    stack0_0__->Value2 = stack1_0__;
/* D:\\PROJECT\\IL2C\\tests\\IL2C.Tests.Code\\InheritTest.cs(78): */
    /* Path=1, Unique=0: IL_000f: ldloc.0 */
    stack0_0__ = hoge__;
    /* Path=1, Unique=0: IL_0010: ldc.i4.1 */
    stack1_0__ = 1;
    /* Path=1, Unique=0: IL_0011: ldc.i4.2 */
    stack2_0__ = 2;
    /* Path=1, Unique=0: IL_0012: callvirt System.Int32 IL2C.Tests.InheritTestTargetBase1::Calc(System.Int32,System.Int32) */
    stack0_1__ = IL2C_Tests_InheritTestTargetBase1_Calc_1((IL2C_Tests_InheritTestTargetBase1*)stack0_0__, stack1_0__, stack2_0__);
    /* Path=1, Unique=0: IL_0017: stloc.1 */
    local__ = stack0_1__;
    /* Path=1, Unique=0: IL_0018: br.s IL_001a */
    goto IL_001a;
IL_001a:
/* D:\\PROJECT\\IL2C\\tests\\IL2C.Tests.Code\\InheritTest.cs(79): */
    /* Path=2, Unique=0: IL_001a: ldloc.1 */
    stack0_1__ = local__;
    /* Path=2, Unique=0: IL_001b: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return stack0_1__;
}

///////////////////////////////////////
// Test4

int32_t IL2C_Tests_InheritTypeTest_Test4(void)
{
    //-------------------
    // Local variables:

    IL2C_Tests_InheritTestTargetBase1* hoge__ = NULL;
    int32_t local__;

    //-------------------
    // Evaluation stacks:

    IL2C_Tests_InheritTestTarget2* stack0_0__ = NULL;
    IL2C_Tests_InheritTestTargetBase1* stack0_1__ = NULL;
    int32_t stack0_2__;
    int32_t stack1_0__;
    int32_t stack2_0__;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        IL2C_Tests_InheritTestTargetBase1** phoge__;
        IL2C_Tests_InheritTestTarget2** pstack0_0__;
        IL2C_Tests_InheritTestTargetBase1** pstack0_1__;
    } __executionFrame__;

    __executionFrame__.targetCount = 3;
    __executionFrame__.phoge__ = &hoge__;
    __executionFrame__.pstack0_0__ = &stack0_0__;
    __executionFrame__.pstack0_1__ = &stack0_1__;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

/* D:\\PROJECT\\IL2C\\tests\\IL2C.Tests.Code\\InheritTest.cs(82): */
    /* Path=1, Unique=0: IL_0000: nop */
    /* Path=1, Unique=0: IL_0001: newobj System.Void IL2C.Tests.InheritTestTarget2::.ctor() */
    stack0_0__ = il2c_get_uninitialized_object(il2c_typeof(IL2C_Tests_InheritTestTarget2));
    stack0_0__->vptr0__ = &__IL2C_Tests_InheritTestTarget2_VTABLE__;
    IL2C_Tests_InheritTestTarget2__ctor(stack0_0__);
    /* Path=1, Unique=0: IL_0006: stloc.0 */
    hoge__ = (IL2C_Tests_InheritTestTargetBase1*)stack0_0__;
/* D:\\PROJECT\\IL2C\\tests\\IL2C.Tests.Code\\InheritTest.cs(84): */
    /* Path=1, Unique=0: IL_0007: ldloc.0 */
    stack0_1__ = hoge__;
    /* Path=1, Unique=0: IL_0008: ldc.i4.s 123 */
    stack1_0__ = 123;
    /* Path=1, Unique=0: IL_000a: stfld System.Int32 IL2C.Tests.InheritTestTargetBase1::Value2 */
    stack0_1__->Value2 = stack1_0__;
/* D:\\PROJECT\\IL2C\\tests\\IL2C.Tests.Code\\InheritTest.cs(86): */
    /* Path=1, Unique=0: IL_000f: ldloc.0 */
    stack0_1__ = hoge__;
    /* Path=1, Unique=0: IL_0010: ldc.i4.1 */
    stack1_0__ = 1;
    /* Path=1, Unique=0: IL_0011: ldc.i4.2 */
    stack2_0__ = 2;
    /* Path=1, Unique=0: IL_0012: callvirt System.Int32 IL2C.Tests.InheritTestTargetBase1::Calc(System.Int32,System.Int32) */
    stack0_2__ = IL2C_Tests_InheritTestTargetBase1_Calc_1(stack0_1__, stack1_0__, stack2_0__);
    /* Path=1, Unique=0: IL_0017: stloc.1 */
    local__ = stack0_2__;
    /* Path=1, Unique=0: IL_0018: br.s IL_001a */
    goto IL_001a;
IL_001a:
/* D:\\PROJECT\\IL2C\\tests\\IL2C.Tests.Code\\InheritTest.cs(87): */
    /* Path=2, Unique=0: IL_001a: ldloc.1 */
    stack0_2__ = local__;
    /* Path=2, Unique=0: IL_001b: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return stack0_2__;
}

///////////////////////////////////////
// Test5

int32_t IL2C_Tests_InheritTypeTest_Test5(void)
{
    //-------------------
    // Local variables:

    System_Object* hoge__ = NULL;
    IL2C_Tests_InheritTestTarget2* hoge2__ = NULL;
    int32_t local__;

    //-------------------
    // Evaluation stacks:

    IL2C_Tests_InheritTestTarget2* stack0_0__ = NULL;
    System_Object* stack0_1__ = NULL;
    int32_t stack0_2__;
    int32_t stack1_0__;
    int32_t stack2_0__;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        System_Object** phoge__;
        IL2C_Tests_InheritTestTarget2** phoge2__;
        IL2C_Tests_InheritTestTarget2** pstack0_0__;
        System_Object** pstack0_1__;
    } __executionFrame__;

    __executionFrame__.targetCount = 4;
    __executionFrame__.phoge__ = &hoge__;
    __executionFrame__.phoge2__ = &hoge2__;
    __executionFrame__.pstack0_0__ = &stack0_0__;
    __executionFrame__.pstack0_1__ = &stack0_1__;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

/* D:\\PROJECT\\IL2C\\tests\\IL2C.Tests.Code\\InheritTest.cs(90): */
    /* Path=1, Unique=0: IL_0000: nop */
    /* Path=1, Unique=0: IL_0001: newobj System.Void IL2C.Tests.InheritTestTarget2::.ctor() */
    stack0_0__ = il2c_get_uninitialized_object(il2c_typeof(IL2C_Tests_InheritTestTarget2));
    stack0_0__->vptr0__ = &__IL2C_Tests_InheritTestTarget2_VTABLE__;
    IL2C_Tests_InheritTestTarget2__ctor(stack0_0__);
    /* Path=1, Unique=0: IL_0006: stloc.0 */
    hoge__ = (System_Object*)stack0_0__;
/* D:\\PROJECT\\IL2C\\tests\\IL2C.Tests.Code\\InheritTest.cs(92): */
    /* Path=1, Unique=0: IL_0007: ldloc.0 */
    stack0_1__ = hoge__;
    /* Path=1, Unique=0: IL_0008: castclass IL2C.Tests.InheritTestTarget2 */
    stack0_0__ = il2c_runtime_cast(stack0_1__, IL2C_Tests_InheritTestTarget2);
    /* Path=1, Unique=0: IL_000d: stloc.1 */
    hoge2__ = stack0_0__;
/* D:\\PROJECT\\IL2C\\tests\\IL2C.Tests.Code\\InheritTest.cs(93): */
    /* Path=1, Unique=0: IL_000e: ldloc.1 */
    stack0_0__ = hoge2__;
    /* Path=1, Unique=0: IL_000f: ldc.i4.s 123 */
    stack1_0__ = 123;
    /* Path=1, Unique=0: IL_0011: stfld System.Int32 IL2C.Tests.InheritTestTargetBase1::Value2 */
    stack0_0__->Value2 = stack1_0__;
/* D:\\PROJECT\\IL2C\\tests\\IL2C.Tests.Code\\InheritTest.cs(95): */
    /* Path=1, Unique=0: IL_0016: ldloc.1 */
    stack0_0__ = hoge2__;
    /* Path=1, Unique=0: IL_0017: ldc.i4.1 */
    stack1_0__ = 1;
    /* Path=1, Unique=0: IL_0018: ldc.i4.2 */
    stack2_0__ = 2;
    /* Path=1, Unique=0: IL_0019: callvirt System.Int32 IL2C.Tests.InheritTestTargetBase1::Calc(System.Int32,System.Int32) */
    stack0_2__ = IL2C_Tests_InheritTestTargetBase1_Calc_1((IL2C_Tests_InheritTestTargetBase1*)stack0_0__, stack1_0__, stack2_0__);
    /* Path=1, Unique=0: IL_001e: stloc.2 */
    local__ = stack0_2__;
    /* Path=1, Unique=0: IL_001f: br.s IL_0021 */
    goto IL_0021;
IL_0021:
/* D:\\PROJECT\\IL2C\\tests\\IL2C.Tests.Code\\InheritTest.cs(96): */
    /* Path=2, Unique=0: IL_0021: ldloc.2 */
    stack0_2__ = local__;
    /* Path=2, Unique=0: IL_0022: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return stack0_2__;
}

///////////////////////////////////////
// .ctor

void IL2C_Tests_InheritTypeTest__ctor(IL2C_Tests_InheritTypeTest* this__)
{
    //-------------------
    // Local variables:


    //-------------------
    // Evaluation stacks:

    IL2C_Tests_InheritTypeTest* stack0_0__ = NULL;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        IL2C_Tests_InheritTypeTest** pstack0_0__;
    } __executionFrame__;

    __executionFrame__.targetCount = 1;
    __executionFrame__.pstack0_0__ = &stack0_0__;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

    /* Path=1, Unique=0: IL_0000: ldarg.0 */
    stack0_0__ = this__;
    /* Path=1, Unique=0: IL_0001: call System.Void System.Object::.ctor() */
    /* Path=1, Unique=0: IL_0006: nop */
    /* Path=1, Unique=0: IL_0007: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return;
}

//////////////////////
// Runtime helpers:

// Runtime cast
void* __IL2C_Tests_InheritTypeTest_IL2C_RuntimeCast__(IL2C_Tests_InheritTypeTest* this__, IL2C_RUNTIME_TYPE_DECL* type)
{
    // This type
    if (type == il2c_typeof(IL2C_Tests_InheritTypeTest)) return this__;

    // Delegate checking base types
    return __System_Object_IL2C_RuntimeCast__((System_Object*)this__, type);
}

// GC's mark handler
void __IL2C_Tests_InheritTypeTest_IL2C_MarkHandler__(IL2C_Tests_InheritTypeTest* this__)
{

    /* Suppressed invoke base mark handler */
}

// Runtime type information
IL2C_RUNTIME_TYPE_DECL __IL2C_Tests_InheritTypeTest_RUNTIME_TYPE__ = {
    "IL2C.Tests.InheritTypeTest",
    sizeof(IL2C_Tests_InheritTypeTest),
    /* internalcall */ (void*)__IL2C_Tests_InheritTypeTest_IL2C_MarkHandler__,
};

//////////////////////
// VTables:

// Vtable of IL2C.Tests.InheritTypeTest
__IL2C_Tests_InheritTypeTest_VTABLE_DECL__ __IL2C_Tests_InheritTypeTest_VTABLE__ = {
    (void*)__IL2C_Tests_InheritTypeTest_IL2C_RuntimeCast__,
    (void*)__System_Object_ToString__,
    (void*)__System_Object_GetHashCode__,
    (void*)__System_Object_Finalize__,
    (void*)__System_Object_Equals__,
};

////////////////////////////////////////////////////////////
// Type: IL2C.Tests.IInterfaceTestTarget

//////////////////////
// Runtime helpers:

// Runtime type information
IL2C_RUNTIME_TYPE_DECL __IL2C_Tests_IInterfaceTestTarget_RUNTIME_TYPE__ = {
    "IL2C.Tests.IInterfaceTestTarget", 0, NULL
};

////////////////////////////////////////////////////////////
// Type: IL2C.Tests.IInterfaceTestTarget2

//////////////////////
// Runtime helpers:

// Runtime type information
IL2C_RUNTIME_TYPE_DECL __IL2C_Tests_IInterfaceTestTarget2_RUNTIME_TYPE__ = {
    "IL2C.Tests.IInterfaceTestTarget2", 0, NULL
};

////////////////////////////////////////////////////////////
// Type: IL2C.Tests.InterfaceTestTargetClass

///////////////////////////////////////
// .ctor

void IL2C_Tests_InterfaceTestTargetClass__ctor(IL2C_Tests_InterfaceTestTargetClass* this__)
{
    //-------------------
    // Local variables:


    //-------------------
    // Evaluation stacks:

    IL2C_Tests_InterfaceTestTargetClass* stack0_0__ = NULL;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        IL2C_Tests_InterfaceTestTargetClass** pstack0_0__;
    } __executionFrame__;

    __executionFrame__.targetCount = 1;
    __executionFrame__.pstack0_0__ = &stack0_0__;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

/* D:\\PROJECT\\IL2C\\tests\\IL2C.Tests.Code\\InterfaceTest.cs(23): */
    /* Path=1, Unique=0: IL_0000: ldarg.0 */
    stack0_0__ = this__;
    /* Path=1, Unique=0: IL_0001: call System.Void System.Object::.ctor() */
    /* Path=1, Unique=0: IL_0006: nop */
/* D:\\PROJECT\\IL2C\\tests\\IL2C.Tests.Code\\InterfaceTest.cs(24): */
    /* Path=1, Unique=0: IL_0007: nop */
    /* Path=1, Unique=0: IL_0008: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return;
}

///////////////////////////////////////
// Virtual: Calc

int32_t __IL2C_Tests_InterfaceTestTargetClass_Calc__(IL2C_Tests_InterfaceTestTargetClass* this__, int32_t a, int32_t b)
{
    //-------------------
    // Local variables:

    int32_t local__;

    //-------------------
    // Evaluation stacks:

    int32_t stack0_0__;
    int32_t stack1_0__;
    IL2C_Tests_InterfaceTestTargetClass* stack1_1__ = NULL;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        IL2C_Tests_InterfaceTestTargetClass** pstack1_1__;
    } __executionFrame__;

    __executionFrame__.targetCount = 1;
    __executionFrame__.pstack1_1__ = &stack1_1__;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

/* D:\\PROJECT\\IL2C\\tests\\IL2C.Tests.Code\\InterfaceTest.cs(28): */
    /* Path=1, Unique=0: IL_0000: nop */
    /* Path=1, Unique=0: IL_0001: ldarg.1 */
    stack0_0__ = a;
    /* Path=1, Unique=0: IL_0002: ldarg.2 */
    stack1_0__ = b;
    /* Path=1, Unique=0: IL_0003: add */
    stack0_0__ = stack0_0__ + stack1_0__;
    /* Path=1, Unique=0: IL_0004: ldarg.0 */
    stack1_1__ = this__;
    /* Path=1, Unique=0: IL_0005: ldfld System.Int32 IL2C.Tests.InterfaceTestTargetClass::Value2 */
    stack1_0__ = stack1_1__->Value2;
    /* Path=1, Unique=0: IL_000a: add */
    stack0_0__ = stack0_0__ + stack1_0__;
    /* Path=1, Unique=0: IL_000b: stloc.0 */
    local__ = stack0_0__;
    /* Path=1, Unique=0: IL_000c: br.s IL_000e */
    goto IL_000e;
IL_000e:
/* D:\\PROJECT\\IL2C\\tests\\IL2C.Tests.Code\\InterfaceTest.cs(30): */
    /* Path=2, Unique=0: IL_000e: ldloc.0 */
    stack0_0__ = local__;
    /* Path=2, Unique=0: IL_000f: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return stack0_0__;
}

///////////////////////////////////////
// Virtual: Calc2

int32_t __IL2C_Tests_InterfaceTestTargetClass_Calc2__(IL2C_Tests_InterfaceTestTargetClass* this__, int32_t a, int32_t b)
{
    //-------------------
    // Local variables:

    int32_t local__;

    //-------------------
    // Evaluation stacks:

    int32_t stack0_0__;
    int32_t stack1_0__;
    IL2C_Tests_InterfaceTestTargetClass* stack1_1__ = NULL;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        IL2C_Tests_InterfaceTestTargetClass** pstack1_1__;
    } __executionFrame__;

    __executionFrame__.targetCount = 1;
    __executionFrame__.pstack1_1__ = &stack1_1__;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

/* D:\\PROJECT\\IL2C\\tests\\IL2C.Tests.Code\\InterfaceTest.cs(33): */
    /* Path=1, Unique=0: IL_0000: nop */
    /* Path=1, Unique=0: IL_0001: ldarg.1 */
    stack0_0__ = a;
    /* Path=1, Unique=0: IL_0002: ldarg.2 */
    stack1_0__ = b;
    /* Path=1, Unique=0: IL_0003: sub */
    stack0_0__ = stack0_0__ - stack1_0__;
    /* Path=1, Unique=0: IL_0004: ldarg.0 */
    stack1_1__ = this__;
    /* Path=1, Unique=0: IL_0005: ldfld System.Int32 IL2C.Tests.InterfaceTestTargetClass::Value2 */
    stack1_0__ = stack1_1__->Value2;
    /* Path=1, Unique=0: IL_000a: add */
    stack0_0__ = stack0_0__ + stack1_0__;
    /* Path=1, Unique=0: IL_000b: stloc.0 */
    local__ = stack0_0__;
    /* Path=1, Unique=0: IL_000c: br.s IL_000e */
    goto IL_000e;
IL_000e:
/* D:\\PROJECT\\IL2C\\tests\\IL2C.Tests.Code\\InterfaceTest.cs(35): */
    /* Path=2, Unique=0: IL_000e: ldloc.0 */
    stack0_0__ = local__;
    /* Path=2, Unique=0: IL_000f: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return stack0_0__;
}

//////////////////////
// Runtime helpers:

// Runtime cast
void* __IL2C_Tests_InterfaceTestTargetClass_IL2C_RuntimeCast__(IL2C_Tests_InterfaceTestTargetClass* this__, IL2C_RUNTIME_TYPE_DECL* type)
{
    // This type
    if (type == il2c_typeof(IL2C_Tests_InterfaceTestTargetClass)) return this__;

    // Interface types
    if (type == il2c_typeof(IL2C_Tests_IInterfaceTestTarget)) return (void*)&(this__->vptr_IL2C_Tests_IInterfaceTestTarget__);
    if (type == il2c_typeof(IL2C_Tests_IInterfaceTestTarget2)) return (void*)&(this__->vptr_IL2C_Tests_IInterfaceTestTarget2__);

    // Delegate checking base types
    return __System_Object_IL2C_RuntimeCast__((System_Object*)this__, type);
}

// GC's mark handler
void __IL2C_Tests_InterfaceTestTargetClass_IL2C_MarkHandler__(IL2C_Tests_InterfaceTestTargetClass* this__)
{
    // Try marking each object reference fields
    il2c_try_mark_from_handler(this__->OR2);

    /* Suppressed invoke base mark handler */
}

// Runtime type information
IL2C_RUNTIME_TYPE_DECL __IL2C_Tests_InterfaceTestTargetClass_RUNTIME_TYPE__ = {
    "IL2C.Tests.InterfaceTestTargetClass",
    sizeof(IL2C_Tests_InterfaceTestTargetClass),
    /* internalcall */ (void*)__IL2C_Tests_InterfaceTestTargetClass_IL2C_MarkHandler__,
};

//////////////////////
// VTables:

// Vtable of IL2C.Tests.InterfaceTestTargetClass
__IL2C_Tests_InterfaceTestTargetClass_VTABLE_DECL__ __IL2C_Tests_InterfaceTestTargetClass_VTABLE__ = {
    (void*)__IL2C_Tests_InterfaceTestTargetClass_IL2C_RuntimeCast__,
    (void*)__System_Object_ToString__,
    (void*)__System_Object_GetHashCode__,
    (void*)__System_Object_Finalize__,
    (void*)__System_Object_Equals__,
    (void*)__IL2C_Tests_InterfaceTestTargetClass_Calc__,
    (void*)__IL2C_Tests_InterfaceTestTargetClass_Calc2__,
};

// Adjustor thunk: IL2C_Tests_InterfaceTestTargetClass.IL2C_RuntimeCast
static void* __IL2C_Tests_InterfaceTestTargetClass_IL2C_RuntimeCast_AT_IL2C_Tests_IInterfaceTestTarget__(
    IL2C_Tests_IInterfaceTestTarget* this__, IL2C_RUNTIME_TYPE_DECL* type)
{
    return __IL2C_Tests_InterfaceTestTargetClass_IL2C_RuntimeCast__((IL2C_Tests_InterfaceTestTargetClass*)il2c_cast_from_interface(IL2C_Tests_InterfaceTestTargetClass, IL2C_Tests_IInterfaceTestTarget, this__), type);
}

// Adjustor thunk: System_Object.ToString
static System_String* __System_Object_ToString_AT_IL2C_Tests_IInterfaceTestTarget__(
    IL2C_Tests_IInterfaceTestTarget* this__)
{
    return __System_Object_ToString__((System_Object*)il2c_cast_from_interface(IL2C_Tests_InterfaceTestTargetClass, IL2C_Tests_IInterfaceTestTarget, this__));
}

// Adjustor thunk: System_Object.GetHashCode
static int32_t __System_Object_GetHashCode_AT_IL2C_Tests_IInterfaceTestTarget__(
    IL2C_Tests_IInterfaceTestTarget* this__)
{
    return __System_Object_GetHashCode__((System_Object*)il2c_cast_from_interface(IL2C_Tests_InterfaceTestTargetClass, IL2C_Tests_IInterfaceTestTarget, this__));
}

// Adjustor thunk: System_Object.Finalize
static void __System_Object_Finalize_AT_IL2C_Tests_IInterfaceTestTarget__(
    IL2C_Tests_IInterfaceTestTarget* this__)
{
    __System_Object_Finalize__((System_Object*)il2c_cast_from_interface(IL2C_Tests_InterfaceTestTargetClass, IL2C_Tests_IInterfaceTestTarget, this__));
}

// Adjustor thunk: System_Object.Equals
static bool __System_Object_Equals_AT_IL2C_Tests_IInterfaceTestTarget__(
    IL2C_Tests_IInterfaceTestTarget* this__, System_Object* obj)
{
    return __System_Object_Equals__((System_Object*)il2c_cast_from_interface(IL2C_Tests_InterfaceTestTargetClass, IL2C_Tests_IInterfaceTestTarget, this__), obj);
}

// Adjustor thunk: IL2C_Tests_InterfaceTestTargetClass.Calc
static int32_t __IL2C_Tests_InterfaceTestTargetClass_Calc_AT_IL2C_Tests_IInterfaceTestTarget__(
    IL2C_Tests_IInterfaceTestTarget* this__, int32_t a, int32_t b)
{
    return __IL2C_Tests_InterfaceTestTargetClass_Calc__((IL2C_Tests_InterfaceTestTargetClass*)il2c_cast_from_interface(IL2C_Tests_InterfaceTestTargetClass, IL2C_Tests_IInterfaceTestTarget, this__), a, b);
}

// Vtable of IL2C.Tests.IInterfaceTestTarget (with adjustor thunk)
__IL2C_Tests_IInterfaceTestTarget_VTABLE_DECL__ __IL2C_Tests_InterfaceTestTargetClass_IL2C_Tests_IInterfaceTestTarget_VTABLE__ = {
    __IL2C_Tests_InterfaceTestTargetClass_IL2C_RuntimeCast_AT_IL2C_Tests_IInterfaceTestTarget__,
    __System_Object_ToString_AT_IL2C_Tests_IInterfaceTestTarget__,
    __System_Object_GetHashCode_AT_IL2C_Tests_IInterfaceTestTarget__,
    __System_Object_Finalize_AT_IL2C_Tests_IInterfaceTestTarget__,
    __System_Object_Equals_AT_IL2C_Tests_IInterfaceTestTarget__,
    __IL2C_Tests_InterfaceTestTargetClass_Calc_AT_IL2C_Tests_IInterfaceTestTarget__,
};

// Adjustor thunk: IL2C_Tests_InterfaceTestTargetClass.IL2C_RuntimeCast
static void* __IL2C_Tests_InterfaceTestTargetClass_IL2C_RuntimeCast_AT_IL2C_Tests_IInterfaceTestTarget2__(
    IL2C_Tests_IInterfaceTestTarget2* this__, IL2C_RUNTIME_TYPE_DECL* type)
{
    return __IL2C_Tests_InterfaceTestTargetClass_IL2C_RuntimeCast__((IL2C_Tests_InterfaceTestTargetClass*)il2c_cast_from_interface(IL2C_Tests_InterfaceTestTargetClass, IL2C_Tests_IInterfaceTestTarget2, this__), type);
}

// Adjustor thunk: System_Object.ToString
static System_String* __System_Object_ToString_AT_IL2C_Tests_IInterfaceTestTarget2__(
    IL2C_Tests_IInterfaceTestTarget2* this__)
{
    return __System_Object_ToString__((System_Object*)il2c_cast_from_interface(IL2C_Tests_InterfaceTestTargetClass, IL2C_Tests_IInterfaceTestTarget2, this__));
}

// Adjustor thunk: System_Object.GetHashCode
static int32_t __System_Object_GetHashCode_AT_IL2C_Tests_IInterfaceTestTarget2__(
    IL2C_Tests_IInterfaceTestTarget2* this__)
{
    return __System_Object_GetHashCode__((System_Object*)il2c_cast_from_interface(IL2C_Tests_InterfaceTestTargetClass, IL2C_Tests_IInterfaceTestTarget2, this__));
}

// Adjustor thunk: System_Object.Finalize
static void __System_Object_Finalize_AT_IL2C_Tests_IInterfaceTestTarget2__(
    IL2C_Tests_IInterfaceTestTarget2* this__)
{
    __System_Object_Finalize__((System_Object*)il2c_cast_from_interface(IL2C_Tests_InterfaceTestTargetClass, IL2C_Tests_IInterfaceTestTarget2, this__));
}

// Adjustor thunk: System_Object.Equals
static bool __System_Object_Equals_AT_IL2C_Tests_IInterfaceTestTarget2__(
    IL2C_Tests_IInterfaceTestTarget2* this__, System_Object* obj)
{
    return __System_Object_Equals__((System_Object*)il2c_cast_from_interface(IL2C_Tests_InterfaceTestTargetClass, IL2C_Tests_IInterfaceTestTarget2, this__), obj);
}

// Adjustor thunk: IL2C_Tests_InterfaceTestTargetClass.Calc2
static int32_t __IL2C_Tests_InterfaceTestTargetClass_Calc2_AT_IL2C_Tests_IInterfaceTestTarget2__(
    IL2C_Tests_IInterfaceTestTarget2* this__, int32_t a, int32_t b)
{
    return __IL2C_Tests_InterfaceTestTargetClass_Calc2__((IL2C_Tests_InterfaceTestTargetClass*)il2c_cast_from_interface(IL2C_Tests_InterfaceTestTargetClass, IL2C_Tests_IInterfaceTestTarget2, this__), a, b);
}

// Vtable of IL2C.Tests.IInterfaceTestTarget2 (with adjustor thunk)
__IL2C_Tests_IInterfaceTestTarget2_VTABLE_DECL__ __IL2C_Tests_InterfaceTestTargetClass_IL2C_Tests_IInterfaceTestTarget2_VTABLE__ = {
    __IL2C_Tests_InterfaceTestTargetClass_IL2C_RuntimeCast_AT_IL2C_Tests_IInterfaceTestTarget2__,
    __System_Object_ToString_AT_IL2C_Tests_IInterfaceTestTarget2__,
    __System_Object_GetHashCode_AT_IL2C_Tests_IInterfaceTestTarget2__,
    __System_Object_Finalize_AT_IL2C_Tests_IInterfaceTestTarget2__,
    __System_Object_Equals_AT_IL2C_Tests_IInterfaceTestTarget2__,
    __IL2C_Tests_InterfaceTestTargetClass_Calc2_AT_IL2C_Tests_IInterfaceTestTarget2__,
};

////////////////////////////////////////////////////////////
// Type: IL2C.Tests.InterfaceTypeTest

///////////////////////////////////////
// Test1

int32_t IL2C_Tests_InterfaceTypeTest_Test1(void)
{
    //-------------------
    // Local variables:

    IL2C_Tests_InterfaceTestTargetClass* hoge__ = NULL;
    int32_t local__;

    //-------------------
    // Evaluation stacks:

    IL2C_Tests_InterfaceTestTargetClass* stack0_0__ = NULL;
    int32_t stack0_1__;
    int32_t stack1_0__;
    int32_t stack2_0__;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        IL2C_Tests_InterfaceTestTargetClass** phoge__;
        IL2C_Tests_InterfaceTestTargetClass** pstack0_0__;
    } __executionFrame__;

    __executionFrame__.targetCount = 2;
    __executionFrame__.phoge__ = &hoge__;
    __executionFrame__.pstack0_0__ = &stack0_0__;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

/* D:\\PROJECT\\IL2C\\tests\\IL2C.Tests.Code\\InterfaceTest.cs(41): */
    /* Path=1, Unique=0: IL_0000: nop */
    /* Path=1, Unique=0: IL_0001: newobj System.Void IL2C.Tests.InterfaceTestTargetClass::.ctor() */
    stack0_0__ = il2c_get_uninitialized_object(il2c_typeof(IL2C_Tests_InterfaceTestTargetClass));
    stack0_0__->vptr0__ = &__IL2C_Tests_InterfaceTestTargetClass_VTABLE__;
    stack0_0__->vptr_IL2C_Tests_IInterfaceTestTarget__ = &__IL2C_Tests_InterfaceTestTargetClass_IL2C_Tests_IInterfaceTestTarget_VTABLE__;
    stack0_0__->vptr_IL2C_Tests_IInterfaceTestTarget2__ = &__IL2C_Tests_InterfaceTestTargetClass_IL2C_Tests_IInterfaceTestTarget2_VTABLE__;
    IL2C_Tests_InterfaceTestTargetClass__ctor(stack0_0__);
    /* Path=1, Unique=0: IL_0006: stloc.0 */
    hoge__ = stack0_0__;
/* D:\\PROJECT\\IL2C\\tests\\IL2C.Tests.Code\\InterfaceTest.cs(43): */
    /* Path=1, Unique=0: IL_0007: ldloc.0 */
    stack0_0__ = hoge__;
    /* Path=1, Unique=0: IL_0008: ldc.i4.s 123 */
    stack1_0__ = 123;
    /* Path=1, Unique=0: IL_000a: stfld System.Int32 IL2C.Tests.InterfaceTestTargetClass::Value2 */
    stack0_0__->Value2 = stack1_0__;
/* D:\\PROJECT\\IL2C\\tests\\IL2C.Tests.Code\\InterfaceTest.cs(45): */
    /* Path=1, Unique=0: IL_000f: ldloc.0 */
    stack0_0__ = hoge__;
    /* Path=1, Unique=0: IL_0010: ldc.i4.1 */
    stack1_0__ = 1;
    /* Path=1, Unique=0: IL_0011: ldc.i4.2 */
    stack2_0__ = 2;
    /* Path=1, Unique=0: IL_0012: callvirt System.Int32 IL2C.Tests.InterfaceTestTargetClass::Calc(System.Int32,System.Int32) */
    stack0_1__ = IL2C_Tests_InterfaceTestTargetClass_Calc(stack0_0__, stack1_0__, stack2_0__);
    /* Path=1, Unique=0: IL_0017: stloc.1 */
    local__ = stack0_1__;
    /* Path=1, Unique=0: IL_0018: br.s IL_001a */
    goto IL_001a;
IL_001a:
/* D:\\PROJECT\\IL2C\\tests\\IL2C.Tests.Code\\InterfaceTest.cs(46): */
    /* Path=2, Unique=0: IL_001a: ldloc.1 */
    stack0_1__ = local__;
    /* Path=2, Unique=0: IL_001b: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return stack0_1__;
}

///////////////////////////////////////
// Test2

int32_t IL2C_Tests_InterfaceTypeTest_Test2(void)
{
    //-------------------
    // Local variables:

    IL2C_Tests_InterfaceTestTargetClass* hoge__ = NULL;
    IL2C_Tests_IInterfaceTestTarget* hoge1__ = NULL;
    int32_t local__;

    //-------------------
    // Evaluation stacks:

    IL2C_Tests_InterfaceTestTargetClass* stack0_0__ = NULL;
    IL2C_Tests_IInterfaceTestTarget* stack0_1__ = NULL;
    int32_t stack0_2__;
    int32_t stack1_0__;
    int32_t stack2_0__;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        IL2C_Tests_InterfaceTestTargetClass** phoge__;
        IL2C_Tests_IInterfaceTestTarget** phoge1__;
        IL2C_Tests_InterfaceTestTargetClass** pstack0_0__;
        IL2C_Tests_IInterfaceTestTarget** pstack0_1__;
    } __executionFrame__;

    __executionFrame__.targetCount = 4;
    __executionFrame__.phoge__ = &hoge__;
    __executionFrame__.phoge1__ = &hoge1__;
    __executionFrame__.pstack0_0__ = &stack0_0__;
    __executionFrame__.pstack0_1__ = &stack0_1__;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

/* D:\\PROJECT\\IL2C\\tests\\IL2C.Tests.Code\\InterfaceTest.cs(49): */
    /* Path=1, Unique=0: IL_0000: nop */
    /* Path=1, Unique=0: IL_0001: newobj System.Void IL2C.Tests.InterfaceTestTargetClass::.ctor() */
    stack0_0__ = il2c_get_uninitialized_object(il2c_typeof(IL2C_Tests_InterfaceTestTargetClass));
    stack0_0__->vptr0__ = &__IL2C_Tests_InterfaceTestTargetClass_VTABLE__;
    stack0_0__->vptr_IL2C_Tests_IInterfaceTestTarget__ = &__IL2C_Tests_InterfaceTestTargetClass_IL2C_Tests_IInterfaceTestTarget_VTABLE__;
    stack0_0__->vptr_IL2C_Tests_IInterfaceTestTarget2__ = &__IL2C_Tests_InterfaceTestTargetClass_IL2C_Tests_IInterfaceTestTarget2_VTABLE__;
    IL2C_Tests_InterfaceTestTargetClass__ctor(stack0_0__);
    /* Path=1, Unique=0: IL_0006: stloc.0 */
    hoge__ = stack0_0__;
/* D:\\PROJECT\\IL2C\\tests\\IL2C.Tests.Code\\InterfaceTest.cs(51): */
    /* Path=1, Unique=0: IL_0007: ldloc.0 */
    stack0_0__ = hoge__;
    /* Path=1, Unique=0: IL_0008: ldc.i4.s 123 */
    stack1_0__ = 123;
    /* Path=1, Unique=0: IL_000a: stfld System.Int32 IL2C.Tests.InterfaceTestTargetClass::Value2 */
    stack0_0__->Value2 = stack1_0__;
/* D:\\PROJECT\\IL2C\\tests\\IL2C.Tests.Code\\InterfaceTest.cs(53): */
    /* Path=1, Unique=0: IL_000f: ldloc.0 */
    stack0_0__ = hoge__;
    /* Path=1, Unique=0: IL_0010: stloc.1 */
    hoge1__ = il2c_cast_to_interface(IL2C_Tests_IInterfaceTestTarget, IL2C_Tests_InterfaceTestTargetClass, stack0_0__);
/* D:\\PROJECT\\IL2C\\tests\\IL2C.Tests.Code\\InterfaceTest.cs(55): */
    /* Path=1, Unique=0: IL_0011: ldloc.1 */
    stack0_1__ = hoge1__;
    /* Path=1, Unique=0: IL_0012: ldc.i4.1 */
    stack1_0__ = 1;
    /* Path=1, Unique=0: IL_0013: ldc.i4.2 */
    stack2_0__ = 2;
    /* Path=1, Unique=0: IL_0014: callvirt System.Int32 IL2C.Tests.IInterfaceTestTarget::Calc(System.Int32,System.Int32) */
    stack0_2__ = IL2C_Tests_IInterfaceTestTarget_Calc(stack0_1__, stack1_0__, stack2_0__);
    /* Path=1, Unique=0: IL_0019: stloc.2 */
    local__ = stack0_2__;
    /* Path=1, Unique=0: IL_001a: br.s IL_001c */
    goto IL_001c;
IL_001c:
/* D:\\PROJECT\\IL2C\\tests\\IL2C.Tests.Code\\InterfaceTest.cs(56): */
    /* Path=2, Unique=0: IL_001c: ldloc.2 */
    stack0_2__ = local__;
    /* Path=2, Unique=0: IL_001d: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return stack0_2__;
}

///////////////////////////////////////
// Test3

int32_t IL2C_Tests_InterfaceTypeTest_Test3(void)
{
    //-------------------
    // Local variables:

    IL2C_Tests_InterfaceTestTargetClass* hoge__ = NULL;
    IL2C_Tests_IInterfaceTestTarget* hoge1__ = NULL;
    IL2C_Tests_IInterfaceTestTarget2* hoge2__ = NULL;
    int32_t local__;

    //-------------------
    // Evaluation stacks:

    IL2C_Tests_InterfaceTestTargetClass* stack0_0__ = NULL;
    IL2C_Tests_IInterfaceTestTarget* stack0_1__ = NULL;
    IL2C_Tests_IInterfaceTestTarget2* stack0_2__ = NULL;
    int32_t stack0_3__;
    int32_t stack1_0__;
    int32_t stack2_0__;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        IL2C_Tests_InterfaceTestTargetClass** phoge__;
        IL2C_Tests_IInterfaceTestTarget** phoge1__;
        IL2C_Tests_IInterfaceTestTarget2** phoge2__;
        IL2C_Tests_InterfaceTestTargetClass** pstack0_0__;
        IL2C_Tests_IInterfaceTestTarget** pstack0_1__;
        IL2C_Tests_IInterfaceTestTarget2** pstack0_2__;
    } __executionFrame__;

    __executionFrame__.targetCount = 6;
    __executionFrame__.phoge__ = &hoge__;
    __executionFrame__.phoge1__ = &hoge1__;
    __executionFrame__.phoge2__ = &hoge2__;
    __executionFrame__.pstack0_0__ = &stack0_0__;
    __executionFrame__.pstack0_1__ = &stack0_1__;
    __executionFrame__.pstack0_2__ = &stack0_2__;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

/* D:\\PROJECT\\IL2C\\tests\\IL2C.Tests.Code\\InterfaceTest.cs(59): */
    /* Path=1, Unique=0: IL_0000: nop */
    /* Path=1, Unique=0: IL_0001: newobj System.Void IL2C.Tests.InterfaceTestTargetClass::.ctor() */
    stack0_0__ = il2c_get_uninitialized_object(il2c_typeof(IL2C_Tests_InterfaceTestTargetClass));
    stack0_0__->vptr0__ = &__IL2C_Tests_InterfaceTestTargetClass_VTABLE__;
    stack0_0__->vptr_IL2C_Tests_IInterfaceTestTarget__ = &__IL2C_Tests_InterfaceTestTargetClass_IL2C_Tests_IInterfaceTestTarget_VTABLE__;
    stack0_0__->vptr_IL2C_Tests_IInterfaceTestTarget2__ = &__IL2C_Tests_InterfaceTestTargetClass_IL2C_Tests_IInterfaceTestTarget2_VTABLE__;
    IL2C_Tests_InterfaceTestTargetClass__ctor(stack0_0__);
    /* Path=1, Unique=0: IL_0006: stloc.0 */
    hoge__ = stack0_0__;
/* D:\\PROJECT\\IL2C\\tests\\IL2C.Tests.Code\\InterfaceTest.cs(61): */
    /* Path=1, Unique=0: IL_0007: ldloc.0 */
    stack0_0__ = hoge__;
    /* Path=1, Unique=0: IL_0008: ldc.i4.s 123 */
    stack1_0__ = 123;
    /* Path=1, Unique=0: IL_000a: stfld System.Int32 IL2C.Tests.InterfaceTestTargetClass::Value2 */
    stack0_0__->Value2 = stack1_0__;
/* D:\\PROJECT\\IL2C\\tests\\IL2C.Tests.Code\\InterfaceTest.cs(63): */
    /* Path=1, Unique=0: IL_000f: ldloc.0 */
    stack0_0__ = hoge__;
    /* Path=1, Unique=0: IL_0010: stloc.1 */
    hoge1__ = il2c_cast_to_interface(IL2C_Tests_IInterfaceTestTarget, IL2C_Tests_InterfaceTestTargetClass, stack0_0__);
/* D:\\PROJECT\\IL2C\\tests\\IL2C.Tests.Code\\InterfaceTest.cs(64): */
    /* Path=1, Unique=0: IL_0011: ldloc.1 */
    stack0_1__ = hoge1__;
    /* Path=1, Unique=0: IL_0012: castclass IL2C.Tests.IInterfaceTestTarget2 */
    stack0_2__ = il2c_runtime_cast(stack0_1__, IL2C_Tests_IInterfaceTestTarget2);
    /* Path=1, Unique=0: IL_0017: stloc.2 */
    hoge2__ = stack0_2__;
/* D:\\PROJECT\\IL2C\\tests\\IL2C.Tests.Code\\InterfaceTest.cs(66): */
    /* Path=1, Unique=0: IL_0018: ldloc.2 */
    stack0_2__ = hoge2__;
    /* Path=1, Unique=0: IL_0019: ldc.i4.1 */
    stack1_0__ = 1;
    /* Path=1, Unique=0: IL_001a: ldc.i4.2 */
    stack2_0__ = 2;
    /* Path=1, Unique=0: IL_001b: callvirt System.Int32 IL2C.Tests.IInterfaceTestTarget2::Calc2(System.Int32,System.Int32) */
    stack0_3__ = IL2C_Tests_IInterfaceTestTarget2_Calc2(stack0_2__, stack1_0__, stack2_0__);
    /* Path=1, Unique=0: IL_0020: stloc.3 */
    local__ = stack0_3__;
    /* Path=1, Unique=0: IL_0021: br.s IL_0023 */
    goto IL_0023;
IL_0023:
/* D:\\PROJECT\\IL2C\\tests\\IL2C.Tests.Code\\InterfaceTest.cs(67): */
    /* Path=2, Unique=0: IL_0023: ldloc.3 */
    stack0_3__ = local__;
    /* Path=2, Unique=0: IL_0024: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return stack0_3__;
}

///////////////////////////////////////
// .ctor

void IL2C_Tests_InterfaceTypeTest__ctor(IL2C_Tests_InterfaceTypeTest* this__)
{
    //-------------------
    // Local variables:


    //-------------------
    // Evaluation stacks:

    IL2C_Tests_InterfaceTypeTest* stack0_0__ = NULL;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        IL2C_Tests_InterfaceTypeTest** pstack0_0__;
    } __executionFrame__;

    __executionFrame__.targetCount = 1;
    __executionFrame__.pstack0_0__ = &stack0_0__;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

    /* Path=1, Unique=0: IL_0000: ldarg.0 */
    stack0_0__ = this__;
    /* Path=1, Unique=0: IL_0001: call System.Void System.Object::.ctor() */
    /* Path=1, Unique=0: IL_0006: nop */
    /* Path=1, Unique=0: IL_0007: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return;
}

//////////////////////
// Runtime helpers:

// Runtime cast
void* __IL2C_Tests_InterfaceTypeTest_IL2C_RuntimeCast__(IL2C_Tests_InterfaceTypeTest* this__, IL2C_RUNTIME_TYPE_DECL* type)
{
    // This type
    if (type == il2c_typeof(IL2C_Tests_InterfaceTypeTest)) return this__;

    // Delegate checking base types
    return __System_Object_IL2C_RuntimeCast__((System_Object*)this__, type);
}

// GC's mark handler
void __IL2C_Tests_InterfaceTypeTest_IL2C_MarkHandler__(IL2C_Tests_InterfaceTypeTest* this__)
{

    /* Suppressed invoke base mark handler */
}

// Runtime type information
IL2C_RUNTIME_TYPE_DECL __IL2C_Tests_InterfaceTypeTest_RUNTIME_TYPE__ = {
    "IL2C.Tests.InterfaceTypeTest",
    sizeof(IL2C_Tests_InterfaceTypeTest),
    /* internalcall */ (void*)__IL2C_Tests_InterfaceTypeTest_IL2C_MarkHandler__,
};

//////////////////////
// VTables:

// Vtable of IL2C.Tests.InterfaceTypeTest
__IL2C_Tests_InterfaceTypeTest_VTABLE_DECL__ __IL2C_Tests_InterfaceTypeTest_VTABLE__ = {
    (void*)__IL2C_Tests_InterfaceTypeTest_IL2C_RuntimeCast__,
    (void*)__System_Object_ToString__,
    (void*)__System_Object_GetHashCode__,
    (void*)__System_Object_Finalize__,
    (void*)__System_Object_Equals__,
};

////////////////////////////////////////////////////////////
// Type: IL2C.Tests.Win32

///////////////////////////////////////
// P/Invoke: GetCurrentProcessId

int32_t IL2C_Tests_Win32_GetCurrentProcessId(void)
{
    return GetCurrentProcessId();
}

///////////////////////////////////////
// P/Invoke: GetCurrentThreadId

int32_t IL2C_Tests_Win32_GetCurrentThreadId(void)
{
    return GetCurrentThreadId();
}

///////////////////////////////////////
// P/Invoke: OutputDebugString

void IL2C_Tests_Win32_OutputDebugString(System_String* message)
{
    OutputDebugStringW(message->string_body__);
}

///////////////////////////////////////
// .ctor

void IL2C_Tests_Win32__ctor(IL2C_Tests_Win32* this__)
{
    //-------------------
    // Local variables:


    //-------------------
    // Evaluation stacks:

    IL2C_Tests_Win32* stack0_0__ = NULL;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        IL2C_Tests_Win32** pstack0_0__;
    } __executionFrame__;

    __executionFrame__.targetCount = 1;
    __executionFrame__.pstack0_0__ = &stack0_0__;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

    /* Path=1, Unique=0: IL_0000: ldarg.0 */
    stack0_0__ = this__;
    /* Path=1, Unique=0: IL_0001: call System.Void System.Object::.ctor() */
    /* Path=1, Unique=0: IL_0006: nop */
    /* Path=1, Unique=0: IL_0007: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return;
}

//////////////////////
// Runtime helpers:

// Runtime cast
void* __IL2C_Tests_Win32_IL2C_RuntimeCast__(IL2C_Tests_Win32* this__, IL2C_RUNTIME_TYPE_DECL* type)
{
    // This type
    if (type == il2c_typeof(IL2C_Tests_Win32)) return this__;

    // Delegate checking base types
    return __System_Object_IL2C_RuntimeCast__((System_Object*)this__, type);
}

// GC's mark handler
void __IL2C_Tests_Win32_IL2C_MarkHandler__(IL2C_Tests_Win32* this__)
{

    /* Suppressed invoke base mark handler */
}

// Runtime type information
IL2C_RUNTIME_TYPE_DECL __IL2C_Tests_Win32_RUNTIME_TYPE__ = {
    "IL2C.Tests.Win32",
    sizeof(IL2C_Tests_Win32),
    /* internalcall */ (void*)__IL2C_Tests_Win32_IL2C_MarkHandler__,
};

//////////////////////
// VTables:

// Vtable of IL2C.Tests.Win32
__IL2C_Tests_Win32_VTABLE_DECL__ __IL2C_Tests_Win32_VTABLE__ = {
    (void*)__IL2C_Tests_Win32_IL2C_RuntimeCast__,
    (void*)__System_Object_ToString__,
    (void*)__System_Object_GetHashCode__,
    (void*)__System_Object_Finalize__,
    (void*)__System_Object_Equals__,
};

////////////////////////////////////////////////////////////
// Type: IL2C.Tests.StringTest

///////////////////////////////////////
// LiteralString

void IL2C_Tests_StringTest_LiteralString(void)
{
    //-------------------
    // Local variables:

    System_String* a__ = NULL;

    //-------------------
    // Evaluation stacks:

    System_String* stack0_0__ = NULL;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        System_String** pa__;
        System_String** pstack0_0__;
    } __executionFrame__;

    __executionFrame__.targetCount = 2;
    __executionFrame__.pa__ = &a__;
    __executionFrame__.pstack0_0__ = &stack0_0__;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

/* D:\\PROJECT\\IL2C\\tests\\IL2C.Tests.Code\\StringTest.cs(12): */
    /* Path=1, Unique=0: IL_0000: nop */
    /* Path=1, Unique=0: IL_0001: ldstr "ABC" */
    stack0_0__ = string0__;
    /* Path=1, Unique=0: IL_0006: stloc.0 */
    a__ = stack0_0__;
/* D:\\PROJECT\\IL2C\\tests\\IL2C.Tests.Code\\StringTest.cs(14): */
    /* Path=1, Unique=0: IL_0007: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return;
}

///////////////////////////////////////
// InOutString

System_String* IL2C_Tests_StringTest_InOutString(System_String* a)
{
    //-------------------
    // Local variables:

    System_String* local__ = NULL;

    //-------------------
    // Evaluation stacks:

    System_String* stack0_0__ = NULL;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        System_String** plocal__;
        System_String** pstack0_0__;
    } __executionFrame__;

    __executionFrame__.targetCount = 2;
    __executionFrame__.plocal__ = &local__;
    __executionFrame__.pstack0_0__ = &stack0_0__;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

/* D:\\PROJECT\\IL2C\\tests\\IL2C.Tests.Code\\StringTest.cs(17): */
    /* Path=1, Unique=0: IL_0000: nop */
    /* Path=1, Unique=0: IL_0001: ldarg.0 */
    stack0_0__ = a;
    /* Path=1, Unique=0: IL_0002: stloc.0 */
    local__ = stack0_0__;
    /* Path=1, Unique=0: IL_0003: br.s IL_0005 */
    goto IL_0005;
IL_0005:
/* D:\\PROJECT\\IL2C\\tests\\IL2C.Tests.Code\\StringTest.cs(19): */
    /* Path=2, Unique=0: IL_0005: ldloc.0 */
    stack0_0__ = local__;
    /* Path=2, Unique=0: IL_0006: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return stack0_0__;
}

///////////////////////////////////////
// LiteralCombinedString

System_String* IL2C_Tests_StringTest_LiteralCombinedString(void)
{
    //-------------------
    // Local variables:

    System_String* a__ = NULL;
    System_String* b__ = NULL;
    System_String* local__ = NULL;

    //-------------------
    // Evaluation stacks:

    System_String* stack0_0__ = NULL;
    System_String* stack1_0__ = NULL;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        System_String** pa__;
        System_String** pb__;
        System_String** plocal__;
        System_String** pstack0_0__;
        System_String** pstack1_0__;
    } __executionFrame__;

    __executionFrame__.targetCount = 5;
    __executionFrame__.pa__ = &a__;
    __executionFrame__.pb__ = &b__;
    __executionFrame__.plocal__ = &local__;
    __executionFrame__.pstack0_0__ = &stack0_0__;
    __executionFrame__.pstack1_0__ = &stack1_0__;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

/* D:\\PROJECT\\IL2C\\tests\\IL2C.Tests.Code\\StringTest.cs(22): */
    /* Path=1, Unique=0: IL_0000: nop */
    /* Path=1, Unique=0: IL_0001: ldstr "ABC" */
    stack0_0__ = string0__;
    /* Path=1, Unique=0: IL_0006: stloc.0 */
    a__ = stack0_0__;
/* D:\\PROJECT\\IL2C\\tests\\IL2C.Tests.Code\\StringTest.cs(24): */
    /* Path=1, Unique=0: IL_0007: ldstr "DEF" */
    stack0_0__ = string1__;
    /* Path=1, Unique=0: IL_000c: stloc.1 */
    b__ = stack0_0__;
/* D:\\PROJECT\\IL2C\\tests\\IL2C.Tests.Code\\StringTest.cs(25): */
    /* Path=1, Unique=0: IL_000d: ldloc.0 */
    stack0_0__ = a__;
    /* Path=1, Unique=0: IL_000e: ldloc.1 */
    stack1_0__ = b__;
    /* Path=1, Unique=0: IL_000f: call System.String System.String::Concat(System.String,System.String) */
    stack0_0__ = System_String_Concat_6(stack0_0__, stack1_0__);
    /* Path=1, Unique=0: IL_0014: stloc.2 */
    local__ = stack0_0__;
    /* Path=1, Unique=0: IL_0015: br.s IL_0017 */
    goto IL_0017;
IL_0017:
/* D:\\PROJECT\\IL2C\\tests\\IL2C.Tests.Code\\StringTest.cs(26): */
    /* Path=2, Unique=0: IL_0017: ldloc.2 */
    stack0_0__ = local__;
    /* Path=2, Unique=0: IL_0018: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return stack0_0__;
}

///////////////////////////////////////
// LiteralSubstring

System_String* IL2C_Tests_StringTest_LiteralSubstring(void)
{
    //-------------------
    // Local variables:

    System_String* a__ = NULL;
    System_String* local__ = NULL;

    //-------------------
    // Evaluation stacks:

    System_String* stack0_0__ = NULL;
    System_String* stack0_1__ = NULL;
    int32_t stack1_0__;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        System_String** pa__;
        System_String** plocal__;
        System_String** pstack0_0__;
        System_String** pstack0_1__;
    } __executionFrame__;

    __executionFrame__.targetCount = 4;
    __executionFrame__.pa__ = &a__;
    __executionFrame__.plocal__ = &local__;
    __executionFrame__.pstack0_0__ = &stack0_0__;
    __executionFrame__.pstack0_1__ = &stack0_1__;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

/* D:\\PROJECT\\IL2C\\tests\\IL2C.Tests.Code\\StringTest.cs(29): */
    /* Path=1, Unique=0: IL_0000: nop */
    /* Path=1, Unique=0: IL_0001: ldstr "ABCDEFGHIJKLMN" */
    stack0_0__ = string2__;
    /* Path=1, Unique=0: IL_0006: stloc.0 */
    a__ = stack0_0__;
/* D:\\PROJECT\\IL2C\\tests\\IL2C.Tests.Code\\StringTest.cs(31): */
    /* Path=1, Unique=0: IL_0007: ldloc.0 */
    stack0_0__ = a__;
    /* Path=1, Unique=0: IL_0008: ldc.i4.3 */
    stack1_0__ = 3;
    /* Path=1, Unique=0: IL_0009: callvirt System.String System.String::Substring(System.Int32) */
    stack0_1__ = System_String_Substring(stack0_0__, stack1_0__);
    /* Path=1, Unique=0: IL_000e: stloc.1 */
    local__ = stack0_1__;
    /* Path=1, Unique=0: IL_000f: br.s IL_0011 */
    goto IL_0011;
IL_0011:
/* D:\\PROJECT\\IL2C\\tests\\IL2C.Tests.Code\\StringTest.cs(32): */
    /* Path=2, Unique=0: IL_0011: ldloc.1 */
    stack0_0__ = local__;
    /* Path=2, Unique=0: IL_0012: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return stack0_0__;
}

///////////////////////////////////////
// GetChar

wchar_t IL2C_Tests_StringTest_GetChar(void)
{
    //-------------------
    // Local variables:

    wchar_t local__;

    //-------------------
    // Evaluation stacks:

    int32_t stack0_0__;

    //-------------------
    // IL body:

/* D:\\PROJECT\\IL2C\\tests\\IL2C.Tests.Code\\StringTest.cs(35): */
    /* Path=1, Unique=0: IL_0000: nop */
    /* Path=1, Unique=0: IL_0001: ldc.i4.s 65 */
    stack0_0__ = 65;
    /* Path=1, Unique=0: IL_0003: stloc.0 */
    local__ = (wchar_t)stack0_0__;
    /* Path=1, Unique=0: IL_0004: br.s IL_0006 */
    goto IL_0006;
IL_0006:
/* D:\\PROJECT\\IL2C\\tests\\IL2C.Tests.Code\\StringTest.cs(37): */
    /* Path=2, Unique=0: IL_0006: ldloc.0 */
    stack0_0__ = local__;
    /* Path=2, Unique=0: IL_0007: ret */
    return (wchar_t)stack0_0__;
}

///////////////////////////////////////
// GetCharByIndex

wchar_t IL2C_Tests_StringTest_GetCharByIndex(System_String* str, int32_t index)
{
    //-------------------
    // Local variables:

    wchar_t local__;

    //-------------------
    // Evaluation stacks:

    System_String* stack0_0__ = NULL;
    int32_t stack0_1__;
    int32_t stack0_2__;
    int32_t stack1_0__;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        System_String** pstack0_0__;
    } __executionFrame__;

    __executionFrame__.targetCount = 1;
    __executionFrame__.pstack0_0__ = &stack0_0__;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

/* D:\\PROJECT\\IL2C\\tests\\IL2C.Tests.Code\\StringTest.cs(40): */
    /* Path=1, Unique=0: IL_0000: nop */
    /* Path=1, Unique=0: IL_0001: ldarg.0 */
    stack0_0__ = str;
    /* Path=1, Unique=0: IL_0002: ldarg.1 */
    stack1_0__ = index;
    /* Path=1, Unique=0: IL_0003: callvirt System.Char System.String::get_Chars(System.Int32) */
    stack0_1__ = System_String_get_Chars(stack0_0__, stack1_0__);
    /* Path=1, Unique=0: IL_0008: stloc.0 */
    local__ = (wchar_t)stack0_1__;
    /* Path=1, Unique=0: IL_0009: br.s IL_000b */
    goto IL_000b;
IL_000b:
/* D:\\PROJECT\\IL2C\\tests\\IL2C.Tests.Code\\StringTest.cs(42): */
    /* Path=2, Unique=0: IL_000b: ldloc.0 */
    stack0_2__ = local__;
    /* Path=2, Unique=0: IL_000c: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return (wchar_t)stack0_2__;
}

///////////////////////////////////////
// GetString

System_String* IL2C_Tests_StringTest_GetString(void)
{
    //-------------------
    // Local variables:

    System_String* local__ = NULL;

    //-------------------
    // Evaluation stacks:

    System_String* stack0_0__ = NULL;
    System_String* stack0_1__ = NULL;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        System_String** plocal__;
        System_String** pstack0_0__;
        System_String** pstack0_1__;
    } __executionFrame__;

    __executionFrame__.targetCount = 3;
    __executionFrame__.plocal__ = &local__;
    __executionFrame__.pstack0_0__ = &stack0_0__;
    __executionFrame__.pstack0_1__ = &stack0_1__;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

/* D:\\PROJECT\\IL2C\\tests\\IL2C.Tests.Code\\StringTest.cs(45): */
    /* Path=1, Unique=0: IL_0000: nop */
    /* Path=1, Unique=0: IL_0001: ldstr "ABC" */
    stack0_0__ = string0__;
    /* Path=1, Unique=0: IL_0006: callvirt System.String System.Object::ToString() */
    stack0_1__ = System_Object_ToString((System_Object*)stack0_0__);
    /* Path=1, Unique=0: IL_000b: stloc.0 */
    local__ = stack0_1__;
    /* Path=1, Unique=0: IL_000c: br.s IL_000e */
    goto IL_000e;
IL_000e:
/* D:\\PROJECT\\IL2C\\tests\\IL2C.Tests.Code\\StringTest.cs(47): */
    /* Path=2, Unique=0: IL_000e: ldloc.0 */
    stack0_0__ = local__;
    /* Path=2, Unique=0: IL_000f: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return stack0_0__;
}

///////////////////////////////////////
// .ctor

void IL2C_Tests_StringTest__ctor(IL2C_Tests_StringTest* this__)
{
    //-------------------
    // Local variables:


    //-------------------
    // Evaluation stacks:

    IL2C_Tests_StringTest* stack0_0__ = NULL;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        IL2C_Tests_StringTest** pstack0_0__;
    } __executionFrame__;

    __executionFrame__.targetCount = 1;
    __executionFrame__.pstack0_0__ = &stack0_0__;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

    /* Path=1, Unique=0: IL_0000: ldarg.0 */
    stack0_0__ = this__;
    /* Path=1, Unique=0: IL_0001: call System.Void System.Object::.ctor() */
    /* Path=1, Unique=0: IL_0006: nop */
    /* Path=1, Unique=0: IL_0007: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return;
}

//////////////////////
// Runtime helpers:

// Runtime cast
void* __IL2C_Tests_StringTest_IL2C_RuntimeCast__(IL2C_Tests_StringTest* this__, IL2C_RUNTIME_TYPE_DECL* type)
{
    // This type
    if (type == il2c_typeof(IL2C_Tests_StringTest)) return this__;

    // Delegate checking base types
    return __System_Object_IL2C_RuntimeCast__((System_Object*)this__, type);
}

// GC's mark handler
void __IL2C_Tests_StringTest_IL2C_MarkHandler__(IL2C_Tests_StringTest* this__)
{

    /* Suppressed invoke base mark handler */
}

// Runtime type information
IL2C_RUNTIME_TYPE_DECL __IL2C_Tests_StringTest_RUNTIME_TYPE__ = {
    "IL2C.Tests.StringTest",
    sizeof(IL2C_Tests_StringTest),
    /* internalcall */ (void*)__IL2C_Tests_StringTest_IL2C_MarkHandler__,
};

//////////////////////
// VTables:

// Vtable of IL2C.Tests.StringTest
__IL2C_Tests_StringTest_VTABLE_DECL__ __IL2C_Tests_StringTest_VTABLE__ = {
    (void*)__IL2C_Tests_StringTest_IL2C_RuntimeCast__,
    (void*)__System_Object_ToString__,
    (void*)__System_Object_GetHashCode__,
    (void*)__System_Object_Finalize__,
    (void*)__System_Object_Equals__,
};

////////////////////////////////////////////////////////////
// Type: IL2C.Tests.UnsafeTest

///////////////////////////////////////
// .ctor

void IL2C_Tests_UnsafeTest__ctor(IL2C_Tests_UnsafeTest* this__)
{
    //-------------------
    // Local variables:


    //-------------------
    // Evaluation stacks:

    IL2C_Tests_UnsafeTest* stack0_0__ = NULL;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        IL2C_Tests_UnsafeTest** pstack0_0__;
    } __executionFrame__;

    __executionFrame__.targetCount = 1;
    __executionFrame__.pstack0_0__ = &stack0_0__;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

    /* Path=1, Unique=0: IL_0000: ldarg.0 */
    stack0_0__ = this__;
    /* Path=1, Unique=0: IL_0001: call System.Void System.Object::.ctor() */
    /* Path=1, Unique=0: IL_0006: nop */
    /* Path=1, Unique=0: IL_0007: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return;
}

//////////////////////
// Runtime helpers:

// Runtime cast
void* __IL2C_Tests_UnsafeTest_IL2C_RuntimeCast__(IL2C_Tests_UnsafeTest* this__, IL2C_RUNTIME_TYPE_DECL* type)
{
    // This type
    if (type == il2c_typeof(IL2C_Tests_UnsafeTest)) return this__;

    // Delegate checking base types
    return __System_Object_IL2C_RuntimeCast__((System_Object*)this__, type);
}

// GC's mark handler
void __IL2C_Tests_UnsafeTest_IL2C_MarkHandler__(IL2C_Tests_UnsafeTest* this__)
{

    /* Suppressed invoke base mark handler */
}

// Runtime type information
IL2C_RUNTIME_TYPE_DECL __IL2C_Tests_UnsafeTest_RUNTIME_TYPE__ = {
    "IL2C.Tests.UnsafeTest",
    sizeof(IL2C_Tests_UnsafeTest),
    /* internalcall */ (void*)__IL2C_Tests_UnsafeTest_IL2C_MarkHandler__,
};

//////////////////////
// VTables:

// Vtable of IL2C.Tests.UnsafeTest
__IL2C_Tests_UnsafeTest_VTABLE_DECL__ __IL2C_Tests_UnsafeTest_VTABLE__ = {
    (void*)__IL2C_Tests_UnsafeTest_IL2C_RuntimeCast__,
    (void*)__System_Object_ToString__,
    (void*)__System_Object_GetHashCode__,
    (void*)__System_Object_Finalize__,
    (void*)__System_Object_Equals__,
};

////////////////////////////////////////////////////////////
// Type: IL2C.Tests.ValueTypeTestTarget

///////////////////////////////////////
// GetValue2

int32_t IL2C_Tests_ValueTypeTestTarget_GetValue2(IL2C_Tests_ValueTypeTestTarget* this__, int32_t a, int32_t b)
{
    //-------------------
    // Local variables:

    int32_t local__;

    //-------------------
    // Evaluation stacks:

    IL2C_Tests_ValueTypeTestTarget* stack0_0__ = NULL;
    int32_t stack0_1__;
    int32_t stack1_0__;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        IL2C_Tests_ValueTypeTestTarget** pstack0_0__;
    } __executionFrame__;

    __executionFrame__.targetCount = 1;
    __executionFrame__.pstack0_0__ = &stack0_0__;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

/* D:\\PROJECT\\IL2C\\tests\\IL2C.Tests.Code\\ValueTypeTest.cs(15): */
    /* Path=1, Unique=0: IL_0000: nop */
    /* Path=1, Unique=0: IL_0001: ldarg.0 */
    stack0_0__ = this__;
    /* Path=1, Unique=0: IL_0002: ldfld System.Int32 IL2C.Tests.ValueTypeTestTarget::Value2 */
    stack0_1__ = stack0_0__->Value2;
    /* Path=1, Unique=0: IL_0007: ldarg.1 */
    stack1_0__ = a;
    /* Path=1, Unique=0: IL_0008: add */
    stack0_1__ = stack0_1__ + stack1_0__;
    /* Path=1, Unique=0: IL_0009: ldarg.2 */
    stack1_0__ = b;
    /* Path=1, Unique=0: IL_000a: add */
    stack0_1__ = stack0_1__ + stack1_0__;
    /* Path=1, Unique=0: IL_000b: stloc.0 */
    local__ = stack0_1__;
    /* Path=1, Unique=0: IL_000c: br.s IL_000e */
    goto IL_000e;
IL_000e:
/* D:\\PROJECT\\IL2C\\tests\\IL2C.Tests.Code\\ValueTypeTest.cs(17): */
    /* Path=2, Unique=0: IL_000e: ldloc.0 */
    stack0_1__ = local__;
    /* Path=2, Unique=0: IL_000f: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return stack0_1__;
}

//////////////////////
// Runtime helpers:

// Runtime cast
void* __IL2C_Tests_ValueTypeTestTarget_IL2C_RuntimeCast__(IL2C_Tests_ValueTypeTestTarget* this__, IL2C_RUNTIME_TYPE_DECL* type)
{
    // This type
    if (type == il2c_typeof(IL2C_Tests_ValueTypeTestTarget)) return this__;

    // Delegate checking base types
    return __System_ValueType_IL2C_RuntimeCast__((System_ValueType*)this__, type);
}

// GC's mark handler
void __IL2C_Tests_ValueTypeTestTarget_IL2C_MarkHandler__(IL2C_Tests_ValueTypeTestTarget* this__)
{
    // Try marking each object reference fields
    il2c_try_mark_from_handler(this__->OR2);

    /* Suppressed invoke base mark handler */
}

// Runtime type information
IL2C_RUNTIME_TYPE_DECL __IL2C_Tests_ValueTypeTestTarget_RUNTIME_TYPE__ = {
    "IL2C.Tests.ValueTypeTestTarget",
    sizeof(IL2C_Tests_ValueTypeTestTarget),
    /* internalcall */ (void*)__IL2C_Tests_ValueTypeTestTarget_IL2C_MarkHandler__,
};

//////////////////////
// VTables:

// Vtable of IL2C.Tests.ValueTypeTestTarget
__IL2C_Tests_ValueTypeTestTarget_VTABLE_DECL__ __IL2C_Tests_ValueTypeTestTarget_VTABLE__ = {
    (void*)__IL2C_Tests_ValueTypeTestTarget_IL2C_RuntimeCast__,
    (void*)__System_ValueType_ToString__,
    (void*)__System_ValueType_GetHashCode__,
    (void*)__System_Object_Finalize__,
    (void*)__System_ValueType_Equals__,
};

////////////////////////////////////////////////////////////
// Type: IL2C.Tests.ValueTypeTest

///////////////////////////////////////
// Test4

int32_t IL2C_Tests_ValueTypeTest_Test4(void)
{
    //-------------------
    // Local variables:

    IL2C_Tests_ValueTypeTestTarget hoge3__;
    int32_t local__;

    //-------------------
    // Evaluation stacks:

    IL2C_Tests_ValueTypeTestTarget* stack0_0__ = NULL;
    IL2C_Tests_ValueTypeTestTarget* stack0_1__ = NULL;
    IL2C_Tests_ValueTypeTestTarget stack0_2__;
    int32_t stack0_3__;
    int32_t stack1_0__;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        IL2C_Tests_ValueTypeTestTarget** pstack0_0__;
        IL2C_Tests_ValueTypeTestTarget** pstack0_1__;
    } __executionFrame__;

    __executionFrame__.targetCount = 2;
    __executionFrame__.pstack0_0__ = &stack0_0__;
    __executionFrame__.pstack0_1__ = &stack0_1__;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

/* D:\\PROJECT\\IL2C\\tests\\IL2C.Tests.Code\\ValueTypeTest.cs(23): */
    /* Path=1, Unique=0: IL_0000: nop */
    /* Path=1, Unique=0: IL_0001: ldloca.s local0 */
    stack0_0__ = &hoge3__;
    /* Path=1, Unique=0: IL_0003: initobj IL2C.Tests.ValueTypeTestTarget */
    memset(stack0_0__, 0x00, sizeof(IL2C_Tests_ValueTypeTestTarget));
/* D:\\PROJECT\\IL2C\\tests\\IL2C.Tests.Code\\ValueTypeTest.cs(25): */
    /* Path=1, Unique=0: IL_0009: ldloca.s local0 */
    stack0_1__ = &hoge3__;
    /* Path=1, Unique=0: IL_000b: ldc.i4 456 */
    stack1_0__ = 456;
    /* Path=1, Unique=0: IL_0010: stfld System.Int32 IL2C.Tests.ValueTypeTestTarget::Value2 */
    stack0_1__->Value2 = stack1_0__;
/* D:\\PROJECT\\IL2C\\tests\\IL2C.Tests.Code\\ValueTypeTest.cs(27): */
    /* Path=1, Unique=0: IL_0015: ldloc.0 */
    stack0_2__ = hoge3__;
    /* Path=1, Unique=0: IL_0016: ldfld System.Int32 IL2C.Tests.ValueTypeTestTarget::Value2 */
    stack0_3__ = stack0_2__.Value2;
    /* Path=1, Unique=0: IL_001b: stloc.1 */
    local__ = stack0_3__;
    /* Path=1, Unique=0: IL_001c: br.s IL_001e */
    goto IL_001e;
IL_001e:
/* D:\\PROJECT\\IL2C\\tests\\IL2C.Tests.Code\\ValueTypeTest.cs(28): */
    /* Path=2, Unique=0: IL_001e: ldloc.1 */
    stack0_3__ = local__;
    /* Path=2, Unique=0: IL_001f: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return stack0_3__;
}

///////////////////////////////////////
// Test5

int32_t IL2C_Tests_ValueTypeTest_Test5(void)
{
    //-------------------
    // Local variables:

    IL2C_Tests_ValueTypeTestTarget hoge3__;
    int32_t result__;
    int32_t local__;

    //-------------------
    // Evaluation stacks:

    IL2C_Tests_ValueTypeTestTarget* stack0_0__ = NULL;
    IL2C_Tests_ValueTypeTestTarget* stack0_1__ = NULL;
    IL2C_Tests_ValueTypeTestTarget* stack0_2__ = NULL;
    int32_t stack0_3__;
    int32_t stack1_0__;
    int32_t stack2_0__;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        IL2C_Tests_ValueTypeTestTarget** pstack0_0__;
        IL2C_Tests_ValueTypeTestTarget** pstack0_1__;
        IL2C_Tests_ValueTypeTestTarget** pstack0_2__;
    } __executionFrame__;

    __executionFrame__.targetCount = 3;
    __executionFrame__.pstack0_0__ = &stack0_0__;
    __executionFrame__.pstack0_1__ = &stack0_1__;
    __executionFrame__.pstack0_2__ = &stack0_2__;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

/* D:\\PROJECT\\IL2C\\tests\\IL2C.Tests.Code\\ValueTypeTest.cs(31): */
    /* Path=1, Unique=0: IL_0000: nop */
    /* Path=1, Unique=0: IL_0001: ldloca.s local0 */
    stack0_0__ = &hoge3__;
    /* Path=1, Unique=0: IL_0003: initobj IL2C.Tests.ValueTypeTestTarget */
    memset(stack0_0__, 0x00, sizeof(IL2C_Tests_ValueTypeTestTarget));
/* D:\\PROJECT\\IL2C\\tests\\IL2C.Tests.Code\\ValueTypeTest.cs(33): */
    /* Path=1, Unique=0: IL_0009: ldloca.s local0 */
    stack0_1__ = &hoge3__;
    /* Path=1, Unique=0: IL_000b: ldc.i4 789 */
    stack1_0__ = 789;
    /* Path=1, Unique=0: IL_0010: stfld System.Int32 IL2C.Tests.ValueTypeTestTarget::Value2 */
    stack0_1__->Value2 = stack1_0__;
/* D:\\PROJECT\\IL2C\\tests\\IL2C.Tests.Code\\ValueTypeTest.cs(35): */
    /* Path=1, Unique=0: IL_0015: ldloca.s local0 */
    stack0_2__ = &hoge3__;
    /* Path=1, Unique=0: IL_0017: ldc.i4.s 123 */
    stack1_0__ = 123;
    /* Path=1, Unique=0: IL_0019: ldc.i4 456 */
    stack2_0__ = 456;
    /* Path=1, Unique=0: IL_001e: call System.Int32 IL2C.Tests.ValueTypeTestTarget::GetValue2(System.Int32,System.Int32) */
    stack0_3__ = IL2C_Tests_ValueTypeTestTarget_GetValue2(stack0_2__, stack1_0__, stack2_0__);
    /* Path=1, Unique=0: IL_0023: stloc.1 */
    result__ = stack0_3__;
/* D:\\PROJECT\\IL2C\\tests\\IL2C.Tests.Code\\ValueTypeTest.cs(36): */
    /* Path=1, Unique=0: IL_0024: ldloc.1 */
    stack0_3__ = result__;
    /* Path=1, Unique=0: IL_0025: stloc.2 */
    local__ = stack0_3__;
    /* Path=1, Unique=0: IL_0026: br.s IL_0028 */
    goto IL_0028;
IL_0028:
/* D:\\PROJECT\\IL2C\\tests\\IL2C.Tests.Code\\ValueTypeTest.cs(37): */
    /* Path=2, Unique=0: IL_0028: ldloc.2 */
    stack0_3__ = local__;
    /* Path=2, Unique=0: IL_0029: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return stack0_3__;
}

///////////////////////////////////////
// .ctor

void IL2C_Tests_ValueTypeTest__ctor(IL2C_Tests_ValueTypeTest* this__)
{
    //-------------------
    // Local variables:


    //-------------------
    // Evaluation stacks:

    IL2C_Tests_ValueTypeTest* stack0_0__ = NULL;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        IL2C_Tests_ValueTypeTest** pstack0_0__;
    } __executionFrame__;

    __executionFrame__.targetCount = 1;
    __executionFrame__.pstack0_0__ = &stack0_0__;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

    /* Path=1, Unique=0: IL_0000: ldarg.0 */
    stack0_0__ = this__;
    /* Path=1, Unique=0: IL_0001: call System.Void System.Object::.ctor() */
    /* Path=1, Unique=0: IL_0006: nop */
    /* Path=1, Unique=0: IL_0007: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return;
}

//////////////////////
// Runtime helpers:

// Runtime cast
void* __IL2C_Tests_ValueTypeTest_IL2C_RuntimeCast__(IL2C_Tests_ValueTypeTest* this__, IL2C_RUNTIME_TYPE_DECL* type)
{
    // This type
    if (type == il2c_typeof(IL2C_Tests_ValueTypeTest)) return this__;

    // Delegate checking base types
    return __System_Object_IL2C_RuntimeCast__((System_Object*)this__, type);
}

// GC's mark handler
void __IL2C_Tests_ValueTypeTest_IL2C_MarkHandler__(IL2C_Tests_ValueTypeTest* this__)
{

    /* Suppressed invoke base mark handler */
}

// Runtime type information
IL2C_RUNTIME_TYPE_DECL __IL2C_Tests_ValueTypeTest_RUNTIME_TYPE__ = {
    "IL2C.Tests.ValueTypeTest",
    sizeof(IL2C_Tests_ValueTypeTest),
    /* internalcall */ (void*)__IL2C_Tests_ValueTypeTest_IL2C_MarkHandler__,
};

//////////////////////
// VTables:

// Vtable of IL2C.Tests.ValueTypeTest
__IL2C_Tests_ValueTypeTest_VTABLE_DECL__ __IL2C_Tests_ValueTypeTest_VTABLE__ = {
    (void*)__IL2C_Tests_ValueTypeTest_IL2C_RuntimeCast__,
    (void*)__System_Object_ToString__,
    (void*)__System_Object_GetHashCode__,
    (void*)__System_Object_Finalize__,
    (void*)__System_Object_Equals__,
};
