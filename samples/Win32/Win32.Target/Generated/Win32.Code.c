#include <windows.h>
#include "Win32.Code.h"

//////////////////////////////////////////////////////////////////////////////////
// Const strings:

IL2C_CONST_STRING(string0__, L"PN> ");
IL2C_CONST_STRING(string1__, L"exit");
IL2C_CONST_STRING(string2__, L"Syntax error.");
IL2C_CONST_STRING(string3__, L"Reuslt=");
IL2C_CONST_STRING(string4__, L"ABC");
IL2C_CONST_STRING(string5__, L"DEF");
IL2C_CONST_STRING(string6__, L"ABCDEFGHIJKLMN");

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

/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\BoxingTest.cs(13): */
    /* Path=1, Unique=0: IL_0000: nop */
    /* Path=1, Unique=0: IL_0001: ldarg.0 */
    stack0_0__ = a;
    /* Path=1, Unique=0: IL_0002: box System.Int32 */
    stack0_1__ = il2c_box(&stack0_0__, il2c_typeof(System_Int32));
    /* Path=1, Unique=0: IL_0007: stloc.0 */
    value__ = stack0_1__;
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\BoxingTest.cs(16): */
    /* Path=1, Unique=0: IL_0008: ldloc.0 */
    stack0_1__ = value__;
    /* Path=1, Unique=0: IL_0009: unbox.any System.Int32 */
    stack0_2__ = *((int32_t*)il2c_unbox(stack0_1__, il2c_typeof(System_Int32)));
    /* Path=1, Unique=0: IL_000e: stloc.1 */
    r__ = stack0_2__;
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

    Win32_Code_BoxingTest* stack0_0__ = NULL;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        Win32_Code_BoxingTest** pstack0_0__;
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
void* __Win32_Code_BoxingTest_IL2C_RuntimeCast__(Win32_Code_BoxingTest* this__, IL2C_RUNTIME_TYPE_DECL* type)
{
    // This type
    if (type == il2c_typeof(Win32_Code_BoxingTest)) return this__;

    // Delegate checking base types
    return __System_Object_IL2C_RuntimeCast__((System_Object*)this__, type);
}

// GC's mark handler
void __Win32_Code_BoxingTest_IL2C_MarkHandler__(Win32_Code_BoxingTest* this__)
{

    /* Suppressed invoke base mark handler */
}

// Vtable of Win32.Code.BoxingTest
__Win32_Code_BoxingTest_VTABLE_DECL__ __Win32_Code_BoxingTest_VTABLE__ = {
    /* internalcall */ __Win32_Code_BoxingTest_IL2C_RuntimeCast__,
    (void*)__System_Object_ToString__,
    (void*)__System_Object_GetHashCode__,
    (void*)__System_Object_Finalize__,
    (void*)__System_Object_Equals__,
};

// Runtime type information
IL2C_RUNTIME_TYPE_DECL __Win32_Code_BoxingTest_RUNTIME_TYPE__ = {
    "Win32.Code.BoxingTest",
    sizeof(Win32_Code_BoxingTest),
    /* internalcall */ (void*)__Win32_Code_BoxingTest_IL2C_MarkHandler__,
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

    Win32_Code_ClassTypeTestTarget* stack0_0__ = NULL;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        Win32_Code_ClassTypeTestTarget** pstack0_0__;
    } __executionFrame__;

    __executionFrame__.targetCount = 1;
    __executionFrame__.pstack0_0__ = &stack0_0__;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\ClassTypeTest.cs(16): */
    /* Path=1, Unique=0: IL_0000: ldarg.0 */
    stack0_0__ = this__;
    /* Path=1, Unique=0: IL_0001: call System.Void System.Object::.ctor() */
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

    Win32_Code_ClassTypeTestTarget* stack0_0__ = NULL;
    int32_t stack1_0__;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        Win32_Code_ClassTypeTestTarget** pstack0_0__;
    } __executionFrame__;

    __executionFrame__.targetCount = 1;
    __executionFrame__.pstack0_0__ = &stack0_0__;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\ClassTypeTest.cs(20): */
    /* Path=1, Unique=0: IL_0000: ldarg.0 */
    stack0_0__ = this__;
    /* Path=1, Unique=0: IL_0001: call System.Void System.Object::.ctor() */
    /* Path=1, Unique=0: IL_0006: nop */
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\ClassTypeTest.cs(21): */
    /* Path=1, Unique=0: IL_0007: nop */
    /* Path=1, Unique=0: IL_0008: ldarg.0 */
    stack0_0__ = this__;
    /* Path=1, Unique=0: IL_0009: ldarg.1 */
    stack1_0__ = value;
    /* Path=1, Unique=0: IL_000a: stfld System.Int32 Win32.Code.ClassTypeTestTarget::Value2 */
    stack0_0__->Value2 = stack1_0__;
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

    int32_t local__;

    //-------------------
    // Evaluation stacks:

    Win32_Code_ClassTypeTestTarget* stack0_0__ = NULL;
    int32_t stack0_1__;
    int32_t stack1_0__;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        Win32_Code_ClassTypeTestTarget** pstack0_0__;
    } __executionFrame__;

    __executionFrame__.targetCount = 1;
    __executionFrame__.pstack0_0__ = &stack0_0__;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\ClassTypeTest.cs(26): */
    /* Path=1, Unique=0: IL_0000: nop */
    /* Path=1, Unique=0: IL_0001: ldarg.0 */
    stack0_0__ = this__;
    /* Path=1, Unique=0: IL_0002: ldfld System.Int32 Win32.Code.ClassTypeTestTarget::Value2 */
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
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\ClassTypeTest.cs(28): */
    /* Path=2, Unique=0: IL_000e: ldloc.0 */
    stack0_1__ = local__;
    /* Path=2, Unique=0: IL_000f: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return stack0_1__;
}

///////////////////////////////////////
// GetValue2

int32_t Win32_Code_ClassTypeTestTarget_GetValue2_1(Win32_Code_ClassTypeTestTarget* this__, int32_t a, int32_t b, int32_t c)
{
    //-------------------
    // Local variables:

    int32_t local__;

    //-------------------
    // Evaluation stacks:

    Win32_Code_ClassTypeTestTarget* stack0_0__ = NULL;
    int32_t stack0_1__;
    int32_t stack1_0__;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        Win32_Code_ClassTypeTestTarget** pstack0_0__;
    } __executionFrame__;

    __executionFrame__.targetCount = 1;
    __executionFrame__.pstack0_0__ = &stack0_0__;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\ClassTypeTest.cs(31): */
    /* Path=1, Unique=0: IL_0000: nop */
    /* Path=1, Unique=0: IL_0001: ldarg.0 */
    stack0_0__ = this__;
    /* Path=1, Unique=0: IL_0002: ldfld System.Int32 Win32.Code.ClassTypeTestTarget::Value2 */
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
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\ClassTypeTest.cs(33): */
    /* Path=2, Unique=0: IL_0010: ldloc.0 */
    stack0_1__ = local__;
    /* Path=2, Unique=0: IL_0011: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return stack0_1__;
}

//////////////////////
// Runtime helpers:

// Runtime cast
void* __Win32_Code_ClassTypeTestTarget_IL2C_RuntimeCast__(Win32_Code_ClassTypeTestTarget* this__, IL2C_RUNTIME_TYPE_DECL* type)
{
    // This type
    if (type == il2c_typeof(Win32_Code_ClassTypeTestTarget)) return this__;

    // Delegate checking base types
    return __System_Object_IL2C_RuntimeCast__((System_Object*)this__, type);
}

// GC's mark handler
void __Win32_Code_ClassTypeTestTarget_IL2C_MarkHandler__(Win32_Code_ClassTypeTestTarget* this__)
{
    // Try marking each object reference fields
    il2c_try_mark_from_handler(this__->OR2);

    /* Suppressed invoke base mark handler */
}

// Vtable of Win32.Code.ClassTypeTestTarget
__Win32_Code_ClassTypeTestTarget_VTABLE_DECL__ __Win32_Code_ClassTypeTestTarget_VTABLE__ = {
    /* internalcall */ __Win32_Code_ClassTypeTestTarget_IL2C_RuntimeCast__,
    (void*)__System_Object_ToString__,
    (void*)__System_Object_GetHashCode__,
    (void*)__System_Object_Finalize__,
    (void*)__System_Object_Equals__,
};

// Runtime type information
IL2C_RUNTIME_TYPE_DECL __Win32_Code_ClassTypeTestTarget_RUNTIME_TYPE__ = {
    "Win32.Code.ClassTypeTestTarget",
    sizeof(Win32_Code_ClassTypeTestTarget),
    /* internalcall */ (void*)__Win32_Code_ClassTypeTestTarget_IL2C_MarkHandler__,
};

////////////////////////////////////////////////////////////
// Type: Win32.Code.ClassTypeTest

///////////////////////////////////////
// Test4

int32_t Win32_Code_ClassTypeTest_Test4(void)
{
    //-------------------
    // Local variables:

    Win32_Code_ClassTypeTestTarget* hoge3__ = NULL;
    int32_t local__;

    //-------------------
    // Evaluation stacks:

    Win32_Code_ClassTypeTestTarget* stack0_0__ = NULL;
    int32_t stack0_1__;
    int32_t stack1_0__;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        Win32_Code_ClassTypeTestTarget** phoge3__;
        Win32_Code_ClassTypeTestTarget** pstack0_0__;
    } __executionFrame__;

    __executionFrame__.targetCount = 2;
    __executionFrame__.phoge3__ = &hoge3__;
    __executionFrame__.pstack0_0__ = &stack0_0__;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\ClassTypeTest.cs(39): */
    /* Path=1, Unique=0: IL_0000: nop */
    /* Path=1, Unique=0: IL_0001: newobj System.Void Win32.Code.ClassTypeTestTarget::.ctor() */
    stack0_0__ = il2c_get_uninitialized_object(il2c_typeof(Win32_Code_ClassTypeTestTarget));
    stack0_0__->vptr0__ = &__Win32_Code_ClassTypeTestTarget_VTABLE__;
    Win32_Code_ClassTypeTestTarget__ctor(stack0_0__);
    /* Path=1, Unique=0: IL_0006: stloc.0 */
    hoge3__ = stack0_0__;
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\ClassTypeTest.cs(41): */
    /* Path=1, Unique=0: IL_0007: ldloc.0 */
    stack0_0__ = hoge3__;
    /* Path=1, Unique=0: IL_0008: ldc.i4 456 */
    stack1_0__ = 456;
    /* Path=1, Unique=0: IL_000d: stfld System.Int32 Win32.Code.ClassTypeTestTarget::Value2 */
    stack0_0__->Value2 = stack1_0__;
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\ClassTypeTest.cs(43): */
    /* Path=1, Unique=0: IL_0012: ldloc.0 */
    stack0_0__ = hoge3__;
    /* Path=1, Unique=0: IL_0013: ldfld System.Int32 Win32.Code.ClassTypeTestTarget::Value2 */
    stack0_1__ = stack0_0__->Value2;
    /* Path=1, Unique=0: IL_0018: stloc.1 */
    local__ = stack0_1__;
    /* Path=1, Unique=0: IL_0019: br.s IL_001b */
    goto IL_001b;
IL_001b:
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\ClassTypeTest.cs(44): */
    /* Path=2, Unique=0: IL_001b: ldloc.1 */
    stack0_1__ = local__;
    /* Path=2, Unique=0: IL_001c: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return stack0_1__;
}

///////////////////////////////////////
// Test5

int32_t Win32_Code_ClassTypeTest_Test5(void)
{
    //-------------------
    // Local variables:

    Win32_Code_ClassTypeTestTarget* hoge3__ = NULL;
    int32_t result__;
    int32_t local__;

    //-------------------
    // Evaluation stacks:

    Win32_Code_ClassTypeTestTarget* stack0_0__ = NULL;
    int32_t stack0_1__;
    int32_t stack1_0__;
    int32_t stack2_0__;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        Win32_Code_ClassTypeTestTarget** phoge3__;
        Win32_Code_ClassTypeTestTarget** pstack0_0__;
    } __executionFrame__;

    __executionFrame__.targetCount = 2;
    __executionFrame__.phoge3__ = &hoge3__;
    __executionFrame__.pstack0_0__ = &stack0_0__;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\ClassTypeTest.cs(47): */
    /* Path=1, Unique=0: IL_0000: nop */
    /* Path=1, Unique=0: IL_0001: newobj System.Void Win32.Code.ClassTypeTestTarget::.ctor() */
    stack0_0__ = il2c_get_uninitialized_object(il2c_typeof(Win32_Code_ClassTypeTestTarget));
    stack0_0__->vptr0__ = &__Win32_Code_ClassTypeTestTarget_VTABLE__;
    Win32_Code_ClassTypeTestTarget__ctor(stack0_0__);
    /* Path=1, Unique=0: IL_0006: stloc.0 */
    hoge3__ = stack0_0__;
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\ClassTypeTest.cs(49): */
    /* Path=1, Unique=0: IL_0007: ldloc.0 */
    stack0_0__ = hoge3__;
    /* Path=1, Unique=0: IL_0008: ldc.i4 789 */
    stack1_0__ = 789;
    /* Path=1, Unique=0: IL_000d: stfld System.Int32 Win32.Code.ClassTypeTestTarget::Value2 */
    stack0_0__->Value2 = stack1_0__;
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\ClassTypeTest.cs(51): */
    /* Path=1, Unique=0: IL_0012: ldloc.0 */
    stack0_0__ = hoge3__;
    /* Path=1, Unique=0: IL_0013: ldc.i4.s 123 */
    stack1_0__ = 123;
    /* Path=1, Unique=0: IL_0015: ldc.i4 456 */
    stack2_0__ = 456;
    /* Path=1, Unique=0: IL_001a: callvirt System.Int32 Win32.Code.ClassTypeTestTarget::GetValue2(System.Int32,System.Int32) */
    stack0_1__ = Win32_Code_ClassTypeTestTarget_GetValue2(stack0_0__, stack1_0__, stack2_0__);
    /* Path=1, Unique=0: IL_001f: stloc.1 */
    result__ = stack0_1__;
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\ClassTypeTest.cs(52): */
    /* Path=1, Unique=0: IL_0020: ldloc.1 */
    stack0_1__ = result__;
    /* Path=1, Unique=0: IL_0021: stloc.2 */
    local__ = stack0_1__;
    /* Path=1, Unique=0: IL_0022: br.s IL_0024 */
    goto IL_0024;
IL_0024:
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\ClassTypeTest.cs(53): */
    /* Path=2, Unique=0: IL_0024: ldloc.2 */
    stack0_1__ = local__;
    /* Path=2, Unique=0: IL_0025: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return stack0_1__;
}

///////////////////////////////////////
// Test6

int32_t Win32_Code_ClassTypeTest_Test6(void)
{
    //-------------------
    // Local variables:

    Win32_Code_ClassTypeTestTarget* hoge3__ = NULL;
    int32_t result__;
    int32_t local__;

    //-------------------
    // Evaluation stacks:

    Win32_Code_ClassTypeTestTarget* stack0_0__ = NULL;
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
        Win32_Code_ClassTypeTestTarget** phoge3__;
        Win32_Code_ClassTypeTestTarget** pstack0_0__;
    } __executionFrame__;

    __executionFrame__.targetCount = 2;
    __executionFrame__.phoge3__ = &hoge3__;
    __executionFrame__.pstack0_0__ = &stack0_0__;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\ClassTypeTest.cs(56): */
    /* Path=1, Unique=0: IL_0000: nop */
    /* Path=1, Unique=0: IL_0001: newobj System.Void Win32.Code.ClassTypeTestTarget::.ctor() */
    stack0_0__ = il2c_get_uninitialized_object(il2c_typeof(Win32_Code_ClassTypeTestTarget));
    stack0_0__->vptr0__ = &__Win32_Code_ClassTypeTestTarget_VTABLE__;
    Win32_Code_ClassTypeTestTarget__ctor(stack0_0__);
    /* Path=1, Unique=0: IL_0006: stloc.0 */
    hoge3__ = stack0_0__;
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\ClassTypeTest.cs(58): */
    /* Path=1, Unique=0: IL_0007: ldloc.0 */
    stack0_0__ = hoge3__;
    /* Path=1, Unique=0: IL_0008: ldc.i4 789 */
    stack1_0__ = 789;
    /* Path=1, Unique=0: IL_000d: stfld System.Int32 Win32.Code.ClassTypeTestTarget::Value2 */
    stack0_0__->Value2 = stack1_0__;
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\ClassTypeTest.cs(60): */
    /* Path=1, Unique=0: IL_0012: ldloc.0 */
    stack0_0__ = hoge3__;
    /* Path=1, Unique=0: IL_0013: ldc.i4.s 123 */
    stack1_0__ = 123;
    /* Path=1, Unique=0: IL_0015: ldc.i4 456 */
    stack2_0__ = 456;
    /* Path=1, Unique=0: IL_001a: ldc.i4 789 */
    stack3_0__ = 789;
    /* Path=1, Unique=0: IL_001f: callvirt System.Int32 Win32.Code.ClassTypeTestTarget::GetValue2(System.Int32,System.Int32,System.Int32) */
    stack0_1__ = Win32_Code_ClassTypeTestTarget_GetValue2_1(stack0_0__, stack1_0__, stack2_0__, stack3_0__);
    /* Path=1, Unique=0: IL_0024: stloc.1 */
    result__ = stack0_1__;
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\ClassTypeTest.cs(61): */
    /* Path=1, Unique=0: IL_0025: ldloc.1 */
    stack0_1__ = result__;
    /* Path=1, Unique=0: IL_0026: stloc.2 */
    local__ = stack0_1__;
    /* Path=1, Unique=0: IL_0027: br.s IL_0029 */
    goto IL_0029;
IL_0029:
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\ClassTypeTest.cs(62): */
    /* Path=2, Unique=0: IL_0029: ldloc.2 */
    stack0_1__ = local__;
    /* Path=2, Unique=0: IL_002a: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return stack0_1__;
}

///////////////////////////////////////
// Test7

int32_t Win32_Code_ClassTypeTest_Test7(void)
{
    //-------------------
    // Local variables:

    Win32_Code_ClassTypeTestTarget* hoge3__ = NULL;
    int32_t local__;

    //-------------------
    // Evaluation stacks:

    int32_t stack0_0__;
    Win32_Code_ClassTypeTestTarget* stack0_1__ = NULL;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        Win32_Code_ClassTypeTestTarget** phoge3__;
        Win32_Code_ClassTypeTestTarget** pstack0_1__;
    } __executionFrame__;

    __executionFrame__.targetCount = 2;
    __executionFrame__.phoge3__ = &hoge3__;
    __executionFrame__.pstack0_1__ = &stack0_1__;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\ClassTypeTest.cs(65): */
    /* Path=1, Unique=0: IL_0000: nop */
    /* Path=1, Unique=0: IL_0001: ldc.i4.s 123 */
    stack0_0__ = 123;
    /* Path=1, Unique=0: IL_0003: newobj System.Void Win32.Code.ClassTypeTestTarget::.ctor(System.Int32) */
    stack0_1__ = il2c_get_uninitialized_object(il2c_typeof(Win32_Code_ClassTypeTestTarget));
    stack0_1__->vptr0__ = &__Win32_Code_ClassTypeTestTarget_VTABLE__;
    Win32_Code_ClassTypeTestTarget__ctor_1(stack0_1__, stack0_0__);
    /* Path=1, Unique=0: IL_0008: stloc.0 */
    hoge3__ = stack0_1__;
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\ClassTypeTest.cs(68): */
    /* Path=1, Unique=0: IL_0009: ldloc.0 */
    stack0_1__ = hoge3__;
    /* Path=1, Unique=0: IL_000a: ldfld System.Int32 Win32.Code.ClassTypeTestTarget::Value2 */
    stack0_0__ = stack0_1__->Value2;
    /* Path=1, Unique=0: IL_000f: stloc.1 */
    local__ = stack0_0__;
    /* Path=1, Unique=0: IL_0010: br.s IL_0012 */
    goto IL_0012;
IL_0012:
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\ClassTypeTest.cs(69): */
    /* Path=2, Unique=0: IL_0012: ldloc.1 */
    stack0_0__ = local__;
    /* Path=2, Unique=0: IL_0013: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return stack0_0__;
}

///////////////////////////////////////
// .ctor

void Win32_Code_ClassTypeTest__ctor(Win32_Code_ClassTypeTest* this__)
{
    //-------------------
    // Local variables:


    //-------------------
    // Evaluation stacks:

    Win32_Code_ClassTypeTest* stack0_0__ = NULL;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        Win32_Code_ClassTypeTest** pstack0_0__;
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
void* __Win32_Code_ClassTypeTest_IL2C_RuntimeCast__(Win32_Code_ClassTypeTest* this__, IL2C_RUNTIME_TYPE_DECL* type)
{
    // This type
    if (type == il2c_typeof(Win32_Code_ClassTypeTest)) return this__;

    // Delegate checking base types
    return __System_Object_IL2C_RuntimeCast__((System_Object*)this__, type);
}

// GC's mark handler
void __Win32_Code_ClassTypeTest_IL2C_MarkHandler__(Win32_Code_ClassTypeTest* this__)
{

    /* Suppressed invoke base mark handler */
}

// Vtable of Win32.Code.ClassTypeTest
__Win32_Code_ClassTypeTest_VTABLE_DECL__ __Win32_Code_ClassTypeTest_VTABLE__ = {
    /* internalcall */ __Win32_Code_ClassTypeTest_IL2C_RuntimeCast__,
    (void*)__System_Object_ToString__,
    (void*)__System_Object_GetHashCode__,
    (void*)__System_Object_Finalize__,
    (void*)__System_Object_Equals__,
};

// Runtime type information
IL2C_RUNTIME_TYPE_DECL __Win32_Code_ClassTypeTest_RUNTIME_TYPE__ = {
    "Win32.Code.ClassTypeTest",
    sizeof(Win32_Code_ClassTypeTest),
    /* internalcall */ (void*)__Win32_Code_ClassTypeTest_IL2C_MarkHandler__,
};

////////////////////////////////////////////////////////////
// Type: Win32.Code.Hoge1

///////////////////////////////////////
// Add1

int32_t Win32_Code_Hoge1_Add1(int32_t a, bool isTwo)
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

/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\Hoge1.cs(11): */
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
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\Hoge1.cs(13): */
    /* Path=3, Unique=0: IL_000d: ldloc.0 */
    stack0_0__ = local__;
    /* Path=3, Unique=0: IL_000e: ret */
    return stack0_0__;
}

///////////////////////////////////////
// Add2

int64_t Win32_Code_Hoge1_Add2(int64_t a, bool isTwo)
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

/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\Hoge1.cs(16): */
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
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\Hoge1.cs(18): */
    /* Path=3, Unique=0: IL_000e: ldloc.0 */
    stack0_0__ = local__;
    /* Path=3, Unique=0: IL_000f: ret */
    return stack0_0__;
}

///////////////////////////////////////
// .ctor

void Win32_Code_Hoge1__ctor(Win32_Code_Hoge1* this__)
{
    //-------------------
    // Local variables:


    //-------------------
    // Evaluation stacks:

    Win32_Code_Hoge1* stack0_0__ = NULL;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        Win32_Code_Hoge1** pstack0_0__;
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
void* __Win32_Code_Hoge1_IL2C_RuntimeCast__(Win32_Code_Hoge1* this__, IL2C_RUNTIME_TYPE_DECL* type)
{
    // This type
    if (type == il2c_typeof(Win32_Code_Hoge1)) return this__;

    // Delegate checking base types
    return __System_Object_IL2C_RuntimeCast__((System_Object*)this__, type);
}

// GC's mark handler
void __Win32_Code_Hoge1_IL2C_MarkHandler__(Win32_Code_Hoge1* this__)
{

    /* Suppressed invoke base mark handler */
}

// Vtable of Win32.Code.Hoge1
__Win32_Code_Hoge1_VTABLE_DECL__ __Win32_Code_Hoge1_VTABLE__ = {
    /* internalcall */ __Win32_Code_Hoge1_IL2C_RuntimeCast__,
    (void*)__System_Object_ToString__,
    (void*)__System_Object_GetHashCode__,
    (void*)__System_Object_Finalize__,
    (void*)__System_Object_Equals__,
};

// Runtime type information
IL2C_RUNTIME_TYPE_DECL __Win32_Code_Hoge1_RUNTIME_TYPE__ = {
    "Win32.Code.Hoge1",
    sizeof(Win32_Code_Hoge1),
    /* internalcall */ (void*)__Win32_Code_Hoge1_IL2C_MarkHandler__,
};

////////////////////////////////////////////////////////////
// Type: Win32.Code.Hoge2

///////////////////////////////////////
// Add3

uint8_t Win32_Code_Hoge2_Add3(uint8_t a, bool isTwo)
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

/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\Hoge2.cs(11): */
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
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\Hoge2.cs(13): */
    /* Path=3, Unique=0: IL_000e: ldloc.0 */
    stack0_0__ = local__;
    /* Path=3, Unique=0: IL_000f: ret */
    return (uint8_t)stack0_0__;
}

///////////////////////////////////////
// Add4

uint16_t Win32_Code_Hoge2_Add4(uint16_t a, bool isTwo)
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

/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\Hoge2.cs(16): */
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
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\Hoge2.cs(18): */
    /* Path=3, Unique=0: IL_000e: ldloc.0 */
    stack0_0__ = local__;
    /* Path=3, Unique=0: IL_000f: ret */
    return (uint16_t)stack0_0__;
}

///////////////////////////////////////
// .ctor

void Win32_Code_Hoge2__ctor(Win32_Code_Hoge2* this__)
{
    //-------------------
    // Local variables:


    //-------------------
    // Evaluation stacks:

    Win32_Code_Hoge2* stack0_0__ = NULL;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        Win32_Code_Hoge2** pstack0_0__;
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
void* __Win32_Code_Hoge2_IL2C_RuntimeCast__(Win32_Code_Hoge2* this__, IL2C_RUNTIME_TYPE_DECL* type)
{
    // This type
    if (type == il2c_typeof(Win32_Code_Hoge2)) return this__;

    // Delegate checking base types
    return __System_Object_IL2C_RuntimeCast__((System_Object*)this__, type);
}

// GC's mark handler
void __Win32_Code_Hoge2_IL2C_MarkHandler__(Win32_Code_Hoge2* this__)
{

    /* Suppressed invoke base mark handler */
}

// Vtable of Win32.Code.Hoge2
__Win32_Code_Hoge2_VTABLE_DECL__ __Win32_Code_Hoge2_VTABLE__ = {
    /* internalcall */ __Win32_Code_Hoge2_IL2C_RuntimeCast__,
    (void*)__System_Object_ToString__,
    (void*)__System_Object_GetHashCode__,
    (void*)__System_Object_Finalize__,
    (void*)__System_Object_Equals__,
};

// Runtime type information
IL2C_RUNTIME_TYPE_DECL __Win32_Code_Hoge2_RUNTIME_TYPE__ = {
    "Win32.Code.Hoge2",
    sizeof(Win32_Code_Hoge2),
    /* internalcall */ (void*)__Win32_Code_Hoge2_IL2C_MarkHandler__,
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

    Win32_Code_InheritTestTargetBase1* stack0_0__ = NULL;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        Win32_Code_InheritTestTargetBase1** pstack0_0__;
    } __executionFrame__;

    __executionFrame__.targetCount = 1;
    __executionFrame__.pstack0_0__ = &stack0_0__;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\InheritTest.cs(13): */
    /* Path=1, Unique=0: IL_0000: ldarg.0 */
    stack0_0__ = this__;
    /* Path=1, Unique=0: IL_0001: call System.Void System.Object::.ctor() */
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

    Win32_Code_InheritTestTargetBase1* stack0_0__ = NULL;
    int32_t stack1_0__;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        Win32_Code_InheritTestTargetBase1** pstack0_0__;
    } __executionFrame__;

    __executionFrame__.targetCount = 1;
    __executionFrame__.pstack0_0__ = &stack0_0__;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\InheritTest.cs(17): */
    /* Path=1, Unique=0: IL_0000: ldarg.0 */
    stack0_0__ = this__;
    /* Path=1, Unique=0: IL_0001: call System.Void System.Object::.ctor() */
    /* Path=1, Unique=0: IL_0006: nop */
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\InheritTest.cs(18): */
    /* Path=1, Unique=0: IL_0007: nop */
    /* Path=1, Unique=0: IL_0008: ldarg.0 */
    stack0_0__ = this__;
    /* Path=1, Unique=0: IL_0009: ldarg.1 */
    stack1_0__ = value;
    /* Path=1, Unique=0: IL_000a: stfld System.Int32 Win32.Code.InheritTestTargetBase1::Value2 */
    stack0_0__->Value2 = stack1_0__;
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

    int32_t local__;

    //-------------------
    // Evaluation stacks:

    Win32_Code_InheritTestTargetBase1* stack0_0__ = NULL;
    int32_t stack0_1__;
    int32_t stack1_0__;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        Win32_Code_InheritTestTargetBase1** pstack0_0__;
    } __executionFrame__;

    __executionFrame__.targetCount = 1;
    __executionFrame__.pstack0_0__ = &stack0_0__;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\InheritTest.cs(23): */
    /* Path=1, Unique=0: IL_0000: nop */
    /* Path=1, Unique=0: IL_0001: ldarg.0 */
    stack0_0__ = this__;
    /* Path=1, Unique=0: IL_0002: ldfld System.Int32 Win32.Code.InheritTestTargetBase1::Value2 */
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
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\InheritTest.cs(25): */
    /* Path=2, Unique=0: IL_000c: ldloc.0 */
    stack0_1__ = local__;
    /* Path=2, Unique=0: IL_000d: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return stack0_1__;
}

///////////////////////////////////////
// Virtual: Calc

int32_t __Win32_Code_InheritTestTargetBase1_Calc_1__(Win32_Code_InheritTestTargetBase1* this__, int32_t a, int32_t b)
{
    //-------------------
    // Local variables:

    int32_t local__;

    //-------------------
    // Evaluation stacks:

    Win32_Code_InheritTestTargetBase1* stack0_0__ = NULL;
    int32_t stack0_1__;
    int32_t stack1_0__;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        Win32_Code_InheritTestTargetBase1** pstack0_0__;
    } __executionFrame__;

    __executionFrame__.targetCount = 1;
    __executionFrame__.pstack0_0__ = &stack0_0__;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\InheritTest.cs(28): */
    /* Path=1, Unique=0: IL_0000: nop */
    /* Path=1, Unique=0: IL_0001: ldarg.0 */
    stack0_0__ = this__;
    /* Path=1, Unique=0: IL_0002: ldfld System.Int32 Win32.Code.InheritTestTargetBase1::Value2 */
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
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\InheritTest.cs(30): */
    /* Path=2, Unique=0: IL_000e: ldloc.0 */
    stack0_1__ = local__;
    /* Path=2, Unique=0: IL_000f: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return stack0_1__;
}

//////////////////////
// Runtime helpers:

// Runtime cast
void* __Win32_Code_InheritTestTargetBase1_IL2C_RuntimeCast__(Win32_Code_InheritTestTargetBase1* this__, IL2C_RUNTIME_TYPE_DECL* type)
{
    // This type
    if (type == il2c_typeof(Win32_Code_InheritTestTargetBase1)) return this__;

    // Delegate checking base types
    return __System_Object_IL2C_RuntimeCast__((System_Object*)this__, type);
}

// GC's mark handler
void __Win32_Code_InheritTestTargetBase1_IL2C_MarkHandler__(Win32_Code_InheritTestTargetBase1* this__)
{
    // Try marking each object reference fields
    il2c_try_mark_from_handler(this__->OR2);

    /* Suppressed invoke base mark handler */
}

// Vtable of Win32.Code.InheritTestTargetBase1
__Win32_Code_InheritTestTargetBase1_VTABLE_DECL__ __Win32_Code_InheritTestTargetBase1_VTABLE__ = {
    /* internalcall */ __Win32_Code_InheritTestTargetBase1_IL2C_RuntimeCast__,
    (void*)__System_Object_ToString__,
    (void*)__System_Object_GetHashCode__,
    (void*)__System_Object_Finalize__,
    (void*)__System_Object_Equals__,
    (void*)__Win32_Code_InheritTestTargetBase1_Calc_1__,
};

// Runtime type information
IL2C_RUNTIME_TYPE_DECL __Win32_Code_InheritTestTargetBase1_RUNTIME_TYPE__ = {
    "Win32.Code.InheritTestTargetBase1",
    sizeof(Win32_Code_InheritTestTargetBase1),
    /* internalcall */ (void*)__Win32_Code_InheritTestTargetBase1_IL2C_MarkHandler__,
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

    Win32_Code_InheritTestTarget2* stack0_0__ = NULL;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        Win32_Code_InheritTestTarget2** pstack0_0__;
    } __executionFrame__;

    __executionFrame__.targetCount = 1;
    __executionFrame__.pstack0_0__ = &stack0_0__;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\InheritTest.cs(35): */
    /* Path=1, Unique=0: IL_0000: ldarg.0 */
    stack0_0__ = this__;
    /* Path=1, Unique=0: IL_0001: call System.Void Win32.Code.InheritTestTargetBase1::.ctor() */
    Win32_Code_InheritTestTargetBase1__ctor((Win32_Code_InheritTestTargetBase1*)stack0_0__);
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

    Win32_Code_InheritTestTarget2* stack0_0__ = NULL;
    int32_t stack1_0__;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        Win32_Code_InheritTestTarget2** pstack0_0__;
    } __executionFrame__;

    __executionFrame__.targetCount = 1;
    __executionFrame__.pstack0_0__ = &stack0_0__;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\InheritTest.cs(40): */
    /* Path=1, Unique=0: IL_0000: ldarg.0 */
    stack0_0__ = this__;
    /* Path=1, Unique=0: IL_0001: ldarg.1 */
    stack1_0__ = value;
    /* Path=1, Unique=0: IL_0002: call System.Void Win32.Code.InheritTestTargetBase1::.ctor(System.Int32) */
    Win32_Code_InheritTestTargetBase1__ctor_1((Win32_Code_InheritTestTargetBase1*)stack0_0__, stack1_0__);
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

    int32_t local__;

    //-------------------
    // Evaluation stacks:

    Win32_Code_InheritTestTarget2* stack0_0__ = NULL;
    int32_t stack0_1__;
    int32_t stack1_0__;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        Win32_Code_InheritTestTarget2** pstack0_0__;
    } __executionFrame__;

    __executionFrame__.targetCount = 1;
    __executionFrame__.pstack0_0__ = &stack0_0__;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\InheritTest.cs(45): */
    /* Path=1, Unique=0: IL_0000: nop */
    /* Path=1, Unique=0: IL_0001: ldarg.0 */
    stack0_0__ = this__;
    /* Path=1, Unique=0: IL_0002: ldfld System.Int32 Win32.Code.InheritTestTargetBase1::Value2 */
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
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\InheritTest.cs(47): */
    /* Path=2, Unique=0: IL_0012: ldloc.0 */
    stack0_1__ = local__;
    /* Path=2, Unique=0: IL_0013: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return stack0_1__;
}

///////////////////////////////////////
// Virtual: Calc

int32_t __Win32_Code_InheritTestTarget2_Calc_1__(Win32_Code_InheritTestTarget2* this__, int32_t a, int32_t b)
{
    //-------------------
    // Local variables:

    int32_t local__;

    //-------------------
    // Evaluation stacks:

    Win32_Code_InheritTestTarget2* stack0_0__ = NULL;
    int32_t stack0_1__;
    int32_t stack1_0__;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        Win32_Code_InheritTestTarget2** pstack0_0__;
    } __executionFrame__;

    __executionFrame__.targetCount = 1;
    __executionFrame__.pstack0_0__ = &stack0_0__;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\InheritTest.cs(50): */
    /* Path=1, Unique=0: IL_0000: nop */
    /* Path=1, Unique=0: IL_0001: ldarg.0 */
    stack0_0__ = this__;
    /* Path=1, Unique=0: IL_0002: ldfld System.Int32 Win32.Code.InheritTestTargetBase1::Value2 */
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
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\InheritTest.cs(52): */
    /* Path=2, Unique=0: IL_0014: ldloc.0 */
    stack0_1__ = local__;
    /* Path=2, Unique=0: IL_0015: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return stack0_1__;
}

//////////////////////
// Runtime helpers:

// Runtime cast
void* __Win32_Code_InheritTestTarget2_IL2C_RuntimeCast__(Win32_Code_InheritTestTarget2* this__, IL2C_RUNTIME_TYPE_DECL* type)
{
    // This type
    if (type == il2c_typeof(Win32_Code_InheritTestTarget2)) return this__;

    // Delegate checking base types
    return __Win32_Code_InheritTestTargetBase1_IL2C_RuntimeCast__((Win32_Code_InheritTestTargetBase1*)this__, type);
}

// GC's mark handler
void __Win32_Code_InheritTestTarget2_IL2C_MarkHandler__(Win32_Code_InheritTestTarget2* this__)
{

    // Delegate checking base types
    __Win32_Code_InheritTestTargetBase1_IL2C_MarkHandler__((Win32_Code_InheritTestTargetBase1*)this__);
}

// Vtable of Win32.Code.InheritTestTarget2
__Win32_Code_InheritTestTarget2_VTABLE_DECL__ __Win32_Code_InheritTestTarget2_VTABLE__ = {
    /* internalcall */ __Win32_Code_InheritTestTarget2_IL2C_RuntimeCast__,
    (void*)__System_Object_ToString__,
    (void*)__System_Object_GetHashCode__,
    (void*)__System_Object_Finalize__,
    (void*)__System_Object_Equals__,
    (void*)__Win32_Code_InheritTestTarget2_Calc_1__,
};

// Runtime type information
IL2C_RUNTIME_TYPE_DECL __Win32_Code_InheritTestTarget2_RUNTIME_TYPE__ = {
    "Win32.Code.InheritTestTarget2",
    sizeof(Win32_Code_InheritTestTarget2),
    /* internalcall */ (void*)__Win32_Code_InheritTestTarget2_IL2C_MarkHandler__,
};

////////////////////////////////////////////////////////////
// Type: Win32.Code.InheritTypeTest

///////////////////////////////////////
// Test1

int32_t Win32_Code_InheritTypeTest_Test1(void)
{
    //-------------------
    // Local variables:

    Win32_Code_InheritTestTargetBase1* hoge__ = NULL;
    int32_t local__;

    //-------------------
    // Evaluation stacks:

    Win32_Code_InheritTestTargetBase1* stack0_0__ = NULL;
    int32_t stack0_1__;
    int32_t stack1_0__;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        Win32_Code_InheritTestTargetBase1** phoge__;
        Win32_Code_InheritTestTargetBase1** pstack0_0__;
    } __executionFrame__;

    __executionFrame__.targetCount = 2;
    __executionFrame__.phoge__ = &hoge__;
    __executionFrame__.pstack0_0__ = &stack0_0__;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\InheritTest.cs(58): */
    /* Path=1, Unique=0: IL_0000: nop */
    /* Path=1, Unique=0: IL_0001: newobj System.Void Win32.Code.InheritTestTargetBase1::.ctor() */
    stack0_0__ = il2c_get_uninitialized_object(il2c_typeof(Win32_Code_InheritTestTargetBase1));
    stack0_0__->vptr0__ = &__Win32_Code_InheritTestTargetBase1_VTABLE__;
    Win32_Code_InheritTestTargetBase1__ctor(stack0_0__);
    /* Path=1, Unique=0: IL_0006: stloc.0 */
    hoge__ = stack0_0__;
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\InheritTest.cs(60): */
    /* Path=1, Unique=0: IL_0007: ldloc.0 */
    stack0_0__ = hoge__;
    /* Path=1, Unique=0: IL_0008: ldc.i4.s 123 */
    stack1_0__ = 123;
    /* Path=1, Unique=0: IL_000a: stfld System.Int32 Win32.Code.InheritTestTargetBase1::Value2 */
    stack0_0__->Value2 = stack1_0__;
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\InheritTest.cs(62): */
    /* Path=1, Unique=0: IL_000f: ldloc.0 */
    stack0_0__ = hoge__;
    /* Path=1, Unique=0: IL_0010: ldc.i4.1 */
    stack1_0__ = 1;
    /* Path=1, Unique=0: IL_0011: callvirt System.Int32 Win32.Code.InheritTestTargetBase1::Calc(System.Int32) */
    stack0_1__ = Win32_Code_InheritTestTargetBase1_Calc(stack0_0__, stack1_0__);
    /* Path=1, Unique=0: IL_0016: stloc.1 */
    local__ = stack0_1__;
    /* Path=1, Unique=0: IL_0017: br.s IL_0019 */
    goto IL_0019;
IL_0019:
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\InheritTest.cs(63): */
    /* Path=2, Unique=0: IL_0019: ldloc.1 */
    stack0_1__ = local__;
    /* Path=2, Unique=0: IL_001a: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return stack0_1__;
}

///////////////////////////////////////
// Test2

int32_t Win32_Code_InheritTypeTest_Test2(void)
{
    //-------------------
    // Local variables:

    Win32_Code_InheritTestTargetBase1* hoge__ = NULL;
    int32_t local__;

    //-------------------
    // Evaluation stacks:

    Win32_Code_InheritTestTargetBase1* stack0_0__ = NULL;
    int32_t stack0_1__;
    int32_t stack1_0__;
    int32_t stack2_0__;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        Win32_Code_InheritTestTargetBase1** phoge__;
        Win32_Code_InheritTestTargetBase1** pstack0_0__;
    } __executionFrame__;

    __executionFrame__.targetCount = 2;
    __executionFrame__.phoge__ = &hoge__;
    __executionFrame__.pstack0_0__ = &stack0_0__;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\InheritTest.cs(66): */
    /* Path=1, Unique=0: IL_0000: nop */
    /* Path=1, Unique=0: IL_0001: newobj System.Void Win32.Code.InheritTestTargetBase1::.ctor() */
    stack0_0__ = il2c_get_uninitialized_object(il2c_typeof(Win32_Code_InheritTestTargetBase1));
    stack0_0__->vptr0__ = &__Win32_Code_InheritTestTargetBase1_VTABLE__;
    Win32_Code_InheritTestTargetBase1__ctor(stack0_0__);
    /* Path=1, Unique=0: IL_0006: stloc.0 */
    hoge__ = stack0_0__;
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\InheritTest.cs(68): */
    /* Path=1, Unique=0: IL_0007: ldloc.0 */
    stack0_0__ = hoge__;
    /* Path=1, Unique=0: IL_0008: ldc.i4.s 123 */
    stack1_0__ = 123;
    /* Path=1, Unique=0: IL_000a: stfld System.Int32 Win32.Code.InheritTestTargetBase1::Value2 */
    stack0_0__->Value2 = stack1_0__;
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\InheritTest.cs(70): */
    /* Path=1, Unique=0: IL_000f: ldloc.0 */
    stack0_0__ = hoge__;
    /* Path=1, Unique=0: IL_0010: ldc.i4.1 */
    stack1_0__ = 1;
    /* Path=1, Unique=0: IL_0011: ldc.i4.2 */
    stack2_0__ = 2;
    /* Path=1, Unique=0: IL_0012: callvirt System.Int32 Win32.Code.InheritTestTargetBase1::Calc(System.Int32,System.Int32) */
    stack0_1__ = Win32_Code_InheritTestTargetBase1_Calc_1(stack0_0__, stack1_0__, stack2_0__);
    /* Path=1, Unique=0: IL_0017: stloc.1 */
    local__ = stack0_1__;
    /* Path=1, Unique=0: IL_0018: br.s IL_001a */
    goto IL_001a;
IL_001a:
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\InheritTest.cs(71): */
    /* Path=2, Unique=0: IL_001a: ldloc.1 */
    stack0_1__ = local__;
    /* Path=2, Unique=0: IL_001b: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return stack0_1__;
}

///////////////////////////////////////
// Test3

int32_t Win32_Code_InheritTypeTest_Test3(void)
{
    //-------------------
    // Local variables:

    Win32_Code_InheritTestTarget2* hoge__ = NULL;
    int32_t local__;

    //-------------------
    // Evaluation stacks:

    Win32_Code_InheritTestTarget2* stack0_0__ = NULL;
    int32_t stack0_1__;
    int32_t stack1_0__;
    int32_t stack2_0__;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        Win32_Code_InheritTestTarget2** phoge__;
        Win32_Code_InheritTestTarget2** pstack0_0__;
    } __executionFrame__;

    __executionFrame__.targetCount = 2;
    __executionFrame__.phoge__ = &hoge__;
    __executionFrame__.pstack0_0__ = &stack0_0__;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\InheritTest.cs(74): */
    /* Path=1, Unique=0: IL_0000: nop */
    /* Path=1, Unique=0: IL_0001: newobj System.Void Win32.Code.InheritTestTarget2::.ctor() */
    stack0_0__ = il2c_get_uninitialized_object(il2c_typeof(Win32_Code_InheritTestTarget2));
    stack0_0__->vptr0__ = &__Win32_Code_InheritTestTarget2_VTABLE__;
    Win32_Code_InheritTestTarget2__ctor(stack0_0__);
    /* Path=1, Unique=0: IL_0006: stloc.0 */
    hoge__ = stack0_0__;
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\InheritTest.cs(76): */
    /* Path=1, Unique=0: IL_0007: ldloc.0 */
    stack0_0__ = hoge__;
    /* Path=1, Unique=0: IL_0008: ldc.i4.s 123 */
    stack1_0__ = 123;
    /* Path=1, Unique=0: IL_000a: stfld System.Int32 Win32.Code.InheritTestTargetBase1::Value2 */
    stack0_0__->Value2 = stack1_0__;
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\InheritTest.cs(78): */
    /* Path=1, Unique=0: IL_000f: ldloc.0 */
    stack0_0__ = hoge__;
    /* Path=1, Unique=0: IL_0010: ldc.i4.1 */
    stack1_0__ = 1;
    /* Path=1, Unique=0: IL_0011: ldc.i4.2 */
    stack2_0__ = 2;
    /* Path=1, Unique=0: IL_0012: callvirt System.Int32 Win32.Code.InheritTestTargetBase1::Calc(System.Int32,System.Int32) */
    stack0_1__ = Win32_Code_InheritTestTargetBase1_Calc_1((Win32_Code_InheritTestTargetBase1*)stack0_0__, stack1_0__, stack2_0__);
    /* Path=1, Unique=0: IL_0017: stloc.1 */
    local__ = stack0_1__;
    /* Path=1, Unique=0: IL_0018: br.s IL_001a */
    goto IL_001a;
IL_001a:
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\InheritTest.cs(79): */
    /* Path=2, Unique=0: IL_001a: ldloc.1 */
    stack0_1__ = local__;
    /* Path=2, Unique=0: IL_001b: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return stack0_1__;
}

///////////////////////////////////////
// Test4

int32_t Win32_Code_InheritTypeTest_Test4(void)
{
    //-------------------
    // Local variables:

    Win32_Code_InheritTestTargetBase1* hoge__ = NULL;
    int32_t local__;

    //-------------------
    // Evaluation stacks:

    Win32_Code_InheritTestTarget2* stack0_0__ = NULL;
    Win32_Code_InheritTestTargetBase1* stack0_1__ = NULL;
    int32_t stack0_2__;
    int32_t stack1_0__;
    int32_t stack2_0__;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        Win32_Code_InheritTestTargetBase1** phoge__;
        Win32_Code_InheritTestTarget2** pstack0_0__;
        Win32_Code_InheritTestTargetBase1** pstack0_1__;
    } __executionFrame__;

    __executionFrame__.targetCount = 3;
    __executionFrame__.phoge__ = &hoge__;
    __executionFrame__.pstack0_0__ = &stack0_0__;
    __executionFrame__.pstack0_1__ = &stack0_1__;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\InheritTest.cs(82): */
    /* Path=1, Unique=0: IL_0000: nop */
    /* Path=1, Unique=0: IL_0001: newobj System.Void Win32.Code.InheritTestTarget2::.ctor() */
    stack0_0__ = il2c_get_uninitialized_object(il2c_typeof(Win32_Code_InheritTestTarget2));
    stack0_0__->vptr0__ = &__Win32_Code_InheritTestTarget2_VTABLE__;
    Win32_Code_InheritTestTarget2__ctor(stack0_0__);
    /* Path=1, Unique=0: IL_0006: stloc.0 */
    hoge__ = (Win32_Code_InheritTestTargetBase1*)stack0_0__;
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\InheritTest.cs(84): */
    /* Path=1, Unique=0: IL_0007: ldloc.0 */
    stack0_1__ = hoge__;
    /* Path=1, Unique=0: IL_0008: ldc.i4.s 123 */
    stack1_0__ = 123;
    /* Path=1, Unique=0: IL_000a: stfld System.Int32 Win32.Code.InheritTestTargetBase1::Value2 */
    stack0_1__->Value2 = stack1_0__;
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\InheritTest.cs(86): */
    /* Path=1, Unique=0: IL_000f: ldloc.0 */
    stack0_1__ = hoge__;
    /* Path=1, Unique=0: IL_0010: ldc.i4.1 */
    stack1_0__ = 1;
    /* Path=1, Unique=0: IL_0011: ldc.i4.2 */
    stack2_0__ = 2;
    /* Path=1, Unique=0: IL_0012: callvirt System.Int32 Win32.Code.InheritTestTargetBase1::Calc(System.Int32,System.Int32) */
    stack0_2__ = Win32_Code_InheritTestTargetBase1_Calc_1(stack0_1__, stack1_0__, stack2_0__);
    /* Path=1, Unique=0: IL_0017: stloc.1 */
    local__ = stack0_2__;
    /* Path=1, Unique=0: IL_0018: br.s IL_001a */
    goto IL_001a;
IL_001a:
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\InheritTest.cs(87): */
    /* Path=2, Unique=0: IL_001a: ldloc.1 */
    stack0_2__ = local__;
    /* Path=2, Unique=0: IL_001b: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return stack0_2__;
}

///////////////////////////////////////
// Test5

int32_t Win32_Code_InheritTypeTest_Test5(void)
{
    //-------------------
    // Local variables:

    System_Object* hoge__ = NULL;
    Win32_Code_InheritTestTarget2* hoge2__ = NULL;
    int32_t local__;

    //-------------------
    // Evaluation stacks:

    Win32_Code_InheritTestTarget2* stack0_0__ = NULL;
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
        Win32_Code_InheritTestTarget2** phoge2__;
        Win32_Code_InheritTestTarget2** pstack0_0__;
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

/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\InheritTest.cs(90): */
    /* Path=1, Unique=0: IL_0000: nop */
    /* Path=1, Unique=0: IL_0001: newobj System.Void Win32.Code.InheritTestTarget2::.ctor() */
    stack0_0__ = il2c_get_uninitialized_object(il2c_typeof(Win32_Code_InheritTestTarget2));
    stack0_0__->vptr0__ = &__Win32_Code_InheritTestTarget2_VTABLE__;
    Win32_Code_InheritTestTarget2__ctor(stack0_0__);
    /* Path=1, Unique=0: IL_0006: stloc.0 */
    hoge__ = (System_Object*)stack0_0__;
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\InheritTest.cs(92): */
    /* Path=1, Unique=0: IL_0007: ldloc.0 */
    stack0_1__ = hoge__;
    /* Path=1, Unique=0: IL_0008: castclass Win32.Code.InheritTestTarget2 */
    stack0_0__ = il2c_runtime_cast(stack0_1__, Win32_Code_InheritTestTarget2);
    /* Path=1, Unique=0: IL_000d: stloc.1 */
    hoge2__ = stack0_0__;
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\InheritTest.cs(93): */
    /* Path=1, Unique=0: IL_000e: ldloc.1 */
    stack0_0__ = hoge2__;
    /* Path=1, Unique=0: IL_000f: ldc.i4.s 123 */
    stack1_0__ = 123;
    /* Path=1, Unique=0: IL_0011: stfld System.Int32 Win32.Code.InheritTestTargetBase1::Value2 */
    stack0_0__->Value2 = stack1_0__;
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\InheritTest.cs(95): */
    /* Path=1, Unique=0: IL_0016: ldloc.1 */
    stack0_0__ = hoge2__;
    /* Path=1, Unique=0: IL_0017: ldc.i4.1 */
    stack1_0__ = 1;
    /* Path=1, Unique=0: IL_0018: ldc.i4.2 */
    stack2_0__ = 2;
    /* Path=1, Unique=0: IL_0019: callvirt System.Int32 Win32.Code.InheritTestTargetBase1::Calc(System.Int32,System.Int32) */
    stack0_2__ = Win32_Code_InheritTestTargetBase1_Calc_1((Win32_Code_InheritTestTargetBase1*)stack0_0__, stack1_0__, stack2_0__);
    /* Path=1, Unique=0: IL_001e: stloc.2 */
    local__ = stack0_2__;
    /* Path=1, Unique=0: IL_001f: br.s IL_0021 */
    goto IL_0021;
IL_0021:
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\InheritTest.cs(96): */
    /* Path=2, Unique=0: IL_0021: ldloc.2 */
    stack0_2__ = local__;
    /* Path=2, Unique=0: IL_0022: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return stack0_2__;
}

///////////////////////////////////////
// .ctor

void Win32_Code_InheritTypeTest__ctor(Win32_Code_InheritTypeTest* this__)
{
    //-------------------
    // Local variables:


    //-------------------
    // Evaluation stacks:

    Win32_Code_InheritTypeTest* stack0_0__ = NULL;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        Win32_Code_InheritTypeTest** pstack0_0__;
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
void* __Win32_Code_InheritTypeTest_IL2C_RuntimeCast__(Win32_Code_InheritTypeTest* this__, IL2C_RUNTIME_TYPE_DECL* type)
{
    // This type
    if (type == il2c_typeof(Win32_Code_InheritTypeTest)) return this__;

    // Delegate checking base types
    return __System_Object_IL2C_RuntimeCast__((System_Object*)this__, type);
}

// GC's mark handler
void __Win32_Code_InheritTypeTest_IL2C_MarkHandler__(Win32_Code_InheritTypeTest* this__)
{

    /* Suppressed invoke base mark handler */
}

// Vtable of Win32.Code.InheritTypeTest
__Win32_Code_InheritTypeTest_VTABLE_DECL__ __Win32_Code_InheritTypeTest_VTABLE__ = {
    /* internalcall */ __Win32_Code_InheritTypeTest_IL2C_RuntimeCast__,
    (void*)__System_Object_ToString__,
    (void*)__System_Object_GetHashCode__,
    (void*)__System_Object_Finalize__,
    (void*)__System_Object_Equals__,
};

// Runtime type information
IL2C_RUNTIME_TYPE_DECL __Win32_Code_InheritTypeTest_RUNTIME_TYPE__ = {
    "Win32.Code.InheritTypeTest",
    sizeof(Win32_Code_InheritTypeTest),
    /* internalcall */ (void*)__Win32_Code_InheritTypeTest_IL2C_MarkHandler__,
};

////////////////////////////////////////////////////////////
// Type: Win32.Code.IInterfaceTestTarget

///////////////////////////////////////
// Abstract: Calc

int32_t __Win32_Code_IInterfaceTestTarget_Calc__(Win32_Code_IInterfaceTestTarget* this__, int32_t a, int32_t b)
{
    // WARNING: Pure virtual function called.
    //TODO: throw : assert(0);
    return (int32_t)0;
}

////////////////////////////////////////////////////////////
// Type: Win32.Code.InterfaceTestTargetClass

///////////////////////////////////////
// .ctor

void Win32_Code_InterfaceTestTargetClass__ctor(Win32_Code_InterfaceTestTargetClass* this__)
{
    //-------------------
    // Local variables:


    //-------------------
    // Evaluation stacks:

    Win32_Code_InterfaceTestTargetClass* stack0_0__ = NULL;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        Win32_Code_InterfaceTestTargetClass** pstack0_0__;
    } __executionFrame__;

    __executionFrame__.targetCount = 1;
    __executionFrame__.pstack0_0__ = &stack0_0__;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\InterfaceTest.cs(18): */
    /* Path=1, Unique=0: IL_0000: ldarg.0 */
    stack0_0__ = this__;
    /* Path=1, Unique=0: IL_0001: call System.Void System.Object::.ctor() */
    /* Path=1, Unique=0: IL_0006: nop */
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\InterfaceTest.cs(19): */
    /* Path=1, Unique=0: IL_0007: nop */
    /* Path=1, Unique=0: IL_0008: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return;
}

///////////////////////////////////////
// Virtual: Calc

int32_t __Win32_Code_InterfaceTestTargetClass_Calc__(Win32_Code_InterfaceTestTargetClass* this__, int32_t a, int32_t b)
{
    //-------------------
    // Local variables:

    int32_t local__;

    //-------------------
    // Evaluation stacks:

    int32_t stack0_0__;
    int32_t stack1_0__;
    Win32_Code_InterfaceTestTargetClass* stack1_1__ = NULL;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        Win32_Code_InterfaceTestTargetClass** pstack1_1__;
    } __executionFrame__;

    __executionFrame__.targetCount = 1;
    __executionFrame__.pstack1_1__ = &stack1_1__;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\InterfaceTest.cs(23): */
    /* Path=1, Unique=0: IL_0000: nop */
    /* Path=1, Unique=0: IL_0001: ldarg.1 */
    stack0_0__ = a;
    /* Path=1, Unique=0: IL_0002: ldarg.2 */
    stack1_0__ = b;
    /* Path=1, Unique=0: IL_0003: add */
    stack0_0__ = stack0_0__ + stack1_0__;
    /* Path=1, Unique=0: IL_0004: ldarg.0 */
    stack1_1__ = this__;
    /* Path=1, Unique=0: IL_0005: ldfld System.Int32 Win32.Code.InterfaceTestTargetClass::Value2 */
    stack1_0__ = stack1_1__->Value2;
    /* Path=1, Unique=0: IL_000a: add */
    stack0_0__ = stack0_0__ + stack1_0__;
    /* Path=1, Unique=0: IL_000b: stloc.0 */
    local__ = stack0_0__;
    /* Path=1, Unique=0: IL_000c: br.s IL_000e */
    goto IL_000e;
IL_000e:
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\InterfaceTest.cs(25): */
    /* Path=2, Unique=0: IL_000e: ldloc.0 */
    stack0_0__ = local__;
    /* Path=2, Unique=0: IL_000f: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return stack0_0__;
}

//////////////////////
// Runtime helpers:

// Runtime cast
void* __Win32_Code_InterfaceTestTargetClass_IL2C_RuntimeCast__(Win32_Code_InterfaceTestTargetClass* this__, IL2C_RUNTIME_TYPE_DECL* type)
{
    // This type
    if (type == il2c_typeof(Win32_Code_InterfaceTestTargetClass)) return this__;

    // Interface types
    if (type == il2c_typeof(Win32_Code_IInterfaceTestTarget)) return &(this__->vptr_Win32_Code_IInterfaceTestTarget__);

    // Delegate checking base types
    return __System_Object_IL2C_RuntimeCast__((System_Object*)this__, type);
}

// GC's mark handler
void __Win32_Code_InterfaceTestTargetClass_IL2C_MarkHandler__(Win32_Code_InterfaceTestTargetClass* this__)
{
    // Try marking each object reference fields
    il2c_try_mark_from_handler(this__->OR2);

    /* Suppressed invoke base mark handler */
}

// Vtable of Win32.Code.InterfaceTestTargetClass
__Win32_Code_InterfaceTestTargetClass_VTABLE_DECL__ __Win32_Code_InterfaceTestTargetClass_VTABLE__ = {
    /* internalcall */ __Win32_Code_InterfaceTestTargetClass_IL2C_RuntimeCast__,
    (void*)__System_Object_ToString__,
    (void*)__System_Object_GetHashCode__,
    (void*)__System_Object_Finalize__,
    (void*)__System_Object_Equals__,
    (void*)__Win32_Code_InterfaceTestTargetClass_Calc__,
};

// Vtable of Win32.Code.IInterfaceTestTarget (with AT)
__Win32_Code_IInterfaceTestTarget_VTABLE_DECL__ __Win32_Code_InterfaceTestTargetClass_Win32_Code_IInterfaceTestTarget_VTABLE__ = {
    /* internalcall */ __Win32_Code_InterfaceTestTargetClass_IL2C_RuntimeCast__,
    (void*)__System_Object_ToString__,
    (void*)__System_Object_GetHashCode__,
    (void*)__System_Object_Finalize__,
    (void*)__System_Object_Equals__,
    (void*)__Win32_Code_IInterfaceTestTarget_Calc__,
};

// Runtime type information
IL2C_RUNTIME_TYPE_DECL __Win32_Code_InterfaceTestTargetClass_RUNTIME_TYPE__ = {
    "Win32.Code.InterfaceTestTargetClass",
    sizeof(Win32_Code_InterfaceTestTargetClass),
    /* internalcall */ (void*)__Win32_Code_InterfaceTestTargetClass_IL2C_MarkHandler__,
};

////////////////////////////////////////////////////////////
// Type: Win32.Code.InterfaceTypeTest

///////////////////////////////////////
// Test1

int32_t Win32_Code_InterfaceTypeTest_Test1(void)
{
    //-------------------
    // Local variables:

    Win32_Code_InterfaceTestTargetClass* hoge__ = NULL;
    int32_t local__;

    //-------------------
    // Evaluation stacks:

    Win32_Code_InterfaceTestTargetClass* stack0_0__ = NULL;
    int32_t stack0_1__;
    int32_t stack1_0__;
    int32_t stack2_0__;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        Win32_Code_InterfaceTestTargetClass** phoge__;
        Win32_Code_InterfaceTestTargetClass** pstack0_0__;
    } __executionFrame__;

    __executionFrame__.targetCount = 2;
    __executionFrame__.phoge__ = &hoge__;
    __executionFrame__.pstack0_0__ = &stack0_0__;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\InterfaceTest.cs(31): */
    /* Path=1, Unique=0: IL_0000: nop */
    /* Path=1, Unique=0: IL_0001: newobj System.Void Win32.Code.InterfaceTestTargetClass::.ctor() */
    stack0_0__ = il2c_get_uninitialized_object(il2c_typeof(Win32_Code_InterfaceTestTargetClass));
    stack0_0__->vptr0__ = &__Win32_Code_InterfaceTestTargetClass_VTABLE__;
    stack0_0__->vptr_Win32_Code_IInterfaceTestTarget__ = &__Win32_Code_InterfaceTestTargetClass_Win32_Code_IInterfaceTestTarget_VTABLE__;
    Win32_Code_InterfaceTestTargetClass__ctor(stack0_0__);
    /* Path=1, Unique=0: IL_0006: stloc.0 */
    hoge__ = stack0_0__;
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\InterfaceTest.cs(33): */
    /* Path=1, Unique=0: IL_0007: ldloc.0 */
    stack0_0__ = hoge__;
    /* Path=1, Unique=0: IL_0008: ldc.i4.s 123 */
    stack1_0__ = 123;
    /* Path=1, Unique=0: IL_000a: stfld System.Int32 Win32.Code.InterfaceTestTargetClass::Value2 */
    stack0_0__->Value2 = stack1_0__;
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\InterfaceTest.cs(35): */
    /* Path=1, Unique=0: IL_000f: ldloc.0 */
    stack0_0__ = hoge__;
    /* Path=1, Unique=0: IL_0010: ldc.i4.1 */
    stack1_0__ = 1;
    /* Path=1, Unique=0: IL_0011: ldc.i4.2 */
    stack2_0__ = 2;
    /* Path=1, Unique=0: IL_0012: callvirt System.Int32 Win32.Code.InterfaceTestTargetClass::Calc(System.Int32,System.Int32) */
    stack0_1__ = Win32_Code_InterfaceTestTargetClass_Calc(stack0_0__, stack1_0__, stack2_0__);
    /* Path=1, Unique=0: IL_0017: stloc.1 */
    local__ = stack0_1__;
    /* Path=1, Unique=0: IL_0018: br.s IL_001a */
    goto IL_001a;
IL_001a:
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\InterfaceTest.cs(36): */
    /* Path=2, Unique=0: IL_001a: ldloc.1 */
    stack0_1__ = local__;
    /* Path=2, Unique=0: IL_001b: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return stack0_1__;
}

///////////////////////////////////////
// Test2

int32_t Win32_Code_InterfaceTypeTest_Test2(void)
{
    //-------------------
    // Local variables:

    Win32_Code_InterfaceTestTargetClass* hoge__ = NULL;
    Win32_Code_IInterfaceTestTarget* hoge2__ = NULL;
    int32_t local__;

    //-------------------
    // Evaluation stacks:

    Win32_Code_InterfaceTestTargetClass* stack0_0__ = NULL;
    Win32_Code_IInterfaceTestTarget* stack0_1__ = NULL;
    int32_t stack0_2__;
    int32_t stack1_0__;
    int32_t stack2_0__;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        Win32_Code_InterfaceTestTargetClass** phoge__;
        Win32_Code_IInterfaceTestTarget** phoge2__;
        Win32_Code_InterfaceTestTargetClass** pstack0_0__;
        Win32_Code_IInterfaceTestTarget** pstack0_1__;
    } __executionFrame__;

    __executionFrame__.targetCount = 4;
    __executionFrame__.phoge__ = &hoge__;
    __executionFrame__.phoge2__ = &hoge2__;
    __executionFrame__.pstack0_0__ = &stack0_0__;
    __executionFrame__.pstack0_1__ = &stack0_1__;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\InterfaceTest.cs(39): */
    /* Path=1, Unique=0: IL_0000: nop */
    /* Path=1, Unique=0: IL_0001: newobj System.Void Win32.Code.InterfaceTestTargetClass::.ctor() */
    stack0_0__ = il2c_get_uninitialized_object(il2c_typeof(Win32_Code_InterfaceTestTargetClass));
    stack0_0__->vptr0__ = &__Win32_Code_InterfaceTestTargetClass_VTABLE__;
    stack0_0__->vptr_Win32_Code_IInterfaceTestTarget__ = &__Win32_Code_InterfaceTestTargetClass_Win32_Code_IInterfaceTestTarget_VTABLE__;
    Win32_Code_InterfaceTestTargetClass__ctor(stack0_0__);
    /* Path=1, Unique=0: IL_0006: stloc.0 */
    hoge__ = stack0_0__;
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\InterfaceTest.cs(41): */
    /* Path=1, Unique=0: IL_0007: ldloc.0 */
    stack0_0__ = hoge__;
    /* Path=1, Unique=0: IL_0008: ldc.i4.s 123 */
    stack1_0__ = 123;
    /* Path=1, Unique=0: IL_000a: stfld System.Int32 Win32.Code.InterfaceTestTargetClass::Value2 */
    stack0_0__->Value2 = stack1_0__;
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\InterfaceTest.cs(43): */
    /* Path=1, Unique=0: IL_000f: ldloc.0 */
    stack0_0__ = hoge__;
    /* Path=1, Unique=0: IL_0010: stloc.1 */
    hoge2__ = (Win32_Code_IInterfaceTestTarget*)stack0_0__;
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\InterfaceTest.cs(45): */
    /* Path=1, Unique=0: IL_0011: ldloc.1 */
    stack0_1__ = hoge2__;
    /* Path=1, Unique=0: IL_0012: ldc.i4.1 */
    stack1_0__ = 1;
    /* Path=1, Unique=0: IL_0013: ldc.i4.2 */
    stack2_0__ = 2;
    /* Path=1, Unique=0: IL_0014: callvirt System.Int32 Win32.Code.IInterfaceTestTarget::Calc(System.Int32,System.Int32) */
    stack0_2__ = Win32_Code_IInterfaceTestTarget_Calc(stack0_1__, stack1_0__, stack2_0__);
    /* Path=1, Unique=0: IL_0019: stloc.2 */
    local__ = stack0_2__;
    /* Path=1, Unique=0: IL_001a: br.s IL_001c */
    goto IL_001c;
IL_001c:
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\InterfaceTest.cs(46): */
    /* Path=2, Unique=0: IL_001c: ldloc.2 */
    stack0_2__ = local__;
    /* Path=2, Unique=0: IL_001d: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return stack0_2__;
}

///////////////////////////////////////
// .ctor

void Win32_Code_InterfaceTypeTest__ctor(Win32_Code_InterfaceTypeTest* this__)
{
    //-------------------
    // Local variables:


    //-------------------
    // Evaluation stacks:

    Win32_Code_InterfaceTypeTest* stack0_0__ = NULL;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        Win32_Code_InterfaceTypeTest** pstack0_0__;
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
void* __Win32_Code_InterfaceTypeTest_IL2C_RuntimeCast__(Win32_Code_InterfaceTypeTest* this__, IL2C_RUNTIME_TYPE_DECL* type)
{
    // This type
    if (type == il2c_typeof(Win32_Code_InterfaceTypeTest)) return this__;

    // Delegate checking base types
    return __System_Object_IL2C_RuntimeCast__((System_Object*)this__, type);
}

// GC's mark handler
void __Win32_Code_InterfaceTypeTest_IL2C_MarkHandler__(Win32_Code_InterfaceTypeTest* this__)
{

    /* Suppressed invoke base mark handler */
}

// Vtable of Win32.Code.InterfaceTypeTest
__Win32_Code_InterfaceTypeTest_VTABLE_DECL__ __Win32_Code_InterfaceTypeTest_VTABLE__ = {
    /* internalcall */ __Win32_Code_InterfaceTypeTest_IL2C_RuntimeCast__,
    (void*)__System_Object_ToString__,
    (void*)__System_Object_GetHashCode__,
    (void*)__System_Object_Finalize__,
    (void*)__System_Object_Equals__,
};

// Runtime type information
IL2C_RUNTIME_TYPE_DECL __Win32_Code_InterfaceTypeTest_RUNTIME_TYPE__ = {
    "Win32.Code.InterfaceTypeTest",
    sizeof(Win32_Code_InterfaceTypeTest),
    /* internalcall */ (void*)__Win32_Code_InterfaceTypeTest_IL2C_MarkHandler__,
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

    Win32_Code_Win32* stack0_0__ = NULL;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        Win32_Code_Win32** pstack0_0__;
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
void* __Win32_Code_Win32_IL2C_RuntimeCast__(Win32_Code_Win32* this__, IL2C_RUNTIME_TYPE_DECL* type)
{
    // This type
    if (type == il2c_typeof(Win32_Code_Win32)) return this__;

    // Delegate checking base types
    return __System_Object_IL2C_RuntimeCast__((System_Object*)this__, type);
}

// GC's mark handler
void __Win32_Code_Win32_IL2C_MarkHandler__(Win32_Code_Win32* this__)
{

    /* Suppressed invoke base mark handler */
}

// Vtable of Win32.Code.Win32
__Win32_Code_Win32_VTABLE_DECL__ __Win32_Code_Win32_VTABLE__ = {
    /* internalcall */ __Win32_Code_Win32_IL2C_RuntimeCast__,
    (void*)__System_Object_ToString__,
    (void*)__System_Object_GetHashCode__,
    (void*)__System_Object_Finalize__,
    (void*)__System_Object_Equals__,
};

// Runtime type information
IL2C_RUNTIME_TYPE_DECL __Win32_Code_Win32_RUNTIME_TYPE__ = {
    "Win32.Code.Win32",
    sizeof(Win32_Code_Win32),
    /* internalcall */ (void*)__Win32_Code_Win32_IL2C_MarkHandler__,
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

    Win32_Code_AbstractNode* stack0_0__ = NULL;
    int32_t stack1_0__;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        Win32_Code_AbstractNode** pstack0_0__;
    } __executionFrame__;

    __executionFrame__.targetCount = 1;
    __executionFrame__.pstack0_0__ = &stack0_0__;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(13): */
    /* Path=1, Unique=0: IL_0000: ldarg.0 */
    stack0_0__ = this__;
    /* Path=1, Unique=0: IL_0001: call System.Void System.Object::.ctor() */
    /* Path=1, Unique=0: IL_0006: nop */
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(14): */
    /* Path=1, Unique=0: IL_0007: nop */
    /* Path=1, Unique=0: IL_0008: ldarg.0 */
    stack0_0__ = this__;
    /* Path=1, Unique=0: IL_0009: ldarg.1 */
    stack1_0__ = nextIndex;
    /* Path=1, Unique=0: IL_000a: stfld System.Int32 Win32.Code.AbstractNode::NextIndex */
    stack0_0__->NextIndex = stack1_0__;
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(16): */
    /* Path=1, Unique=0: IL_000f: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return;
}

//////////////////////
// Runtime helpers:

// Runtime cast
void* __Win32_Code_AbstractNode_IL2C_RuntimeCast__(Win32_Code_AbstractNode* this__, IL2C_RUNTIME_TYPE_DECL* type)
{
    // This type
    if (type == il2c_typeof(Win32_Code_AbstractNode)) return this__;

    // Delegate checking base types
    return __System_Object_IL2C_RuntimeCast__((System_Object*)this__, type);
}

// GC's mark handler
void __Win32_Code_AbstractNode_IL2C_MarkHandler__(Win32_Code_AbstractNode* this__)
{

    /* Suppressed invoke base mark handler */
}

// Vtable of Win32.Code.AbstractNode
__Win32_Code_AbstractNode_VTABLE_DECL__ __Win32_Code_AbstractNode_VTABLE__ = {
    /* internalcall */ __Win32_Code_AbstractNode_IL2C_RuntimeCast__,
    (void*)__System_Object_ToString__,
    (void*)__System_Object_GetHashCode__,
    (void*)__System_Object_Finalize__,
    (void*)__System_Object_Equals__,
};

// Runtime type information
IL2C_RUNTIME_TYPE_DECL __Win32_Code_AbstractNode_RUNTIME_TYPE__ = {
    "Win32.Code.AbstractNode",
    sizeof(Win32_Code_AbstractNode),
    /* internalcall */ (void*)__Win32_Code_AbstractNode_IL2C_MarkHandler__,
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

    Win32_Code_OperatorNode* stack0_0__ = NULL;
    int32_t stack1_0__;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        Win32_Code_OperatorNode** pstack0_0__;
    } __executionFrame__;

    __executionFrame__.targetCount = 1;
    __executionFrame__.pstack0_0__ = &stack0_0__;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(23): */
    /* Path=1, Unique=0: IL_0000: ldarg.0 */
    stack0_0__ = this__;
    /* Path=1, Unique=0: IL_0001: ldarg.2 */
    stack1_0__ = nextIndex;
    /* Path=1, Unique=0: IL_0002: call System.Void Win32.Code.AbstractNode::.ctor(System.Int32) */
    Win32_Code_AbstractNode__ctor((Win32_Code_AbstractNode*)stack0_0__, stack1_0__);
    /* Path=1, Unique=0: IL_0007: nop */
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(24): */
    /* Path=1, Unique=0: IL_0008: nop */
    /* Path=1, Unique=0: IL_0009: ldarg.0 */
    stack0_0__ = this__;
    /* Path=1, Unique=0: IL_000a: ldarg.1 */
    stack1_0__ = (int32_t)(oper);
    /* Path=1, Unique=0: IL_000b: stfld System.Char Win32.Code.OperatorNode::Operator */
    stack0_0__->Operator = (wchar_t)stack1_0__;
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(26): */
    /* Path=1, Unique=0: IL_0010: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return;
}

//////////////////////
// Runtime helpers:

// Runtime cast
void* __Win32_Code_OperatorNode_IL2C_RuntimeCast__(Win32_Code_OperatorNode* this__, IL2C_RUNTIME_TYPE_DECL* type)
{
    // This type
    if (type == il2c_typeof(Win32_Code_OperatorNode)) return this__;

    // Delegate checking base types
    return __Win32_Code_AbstractNode_IL2C_RuntimeCast__((Win32_Code_AbstractNode*)this__, type);
}

// GC's mark handler
void __Win32_Code_OperatorNode_IL2C_MarkHandler__(Win32_Code_OperatorNode* this__)
{

    // Delegate checking base types
    __Win32_Code_AbstractNode_IL2C_MarkHandler__((Win32_Code_AbstractNode*)this__);
}

// Vtable of Win32.Code.OperatorNode
__Win32_Code_OperatorNode_VTABLE_DECL__ __Win32_Code_OperatorNode_VTABLE__ = {
    /* internalcall */ __Win32_Code_OperatorNode_IL2C_RuntimeCast__,
    (void*)__System_Object_ToString__,
    (void*)__System_Object_GetHashCode__,
    (void*)__System_Object_Finalize__,
    (void*)__System_Object_Equals__,
};

// Runtime type information
IL2C_RUNTIME_TYPE_DECL __Win32_Code_OperatorNode_RUNTIME_TYPE__ = {
    "Win32.Code.OperatorNode",
    sizeof(Win32_Code_OperatorNode),
    /* internalcall */ (void*)__Win32_Code_OperatorNode_IL2C_MarkHandler__,
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

    Win32_Code_ReducibleNode* stack0_0__ = NULL;
    int32_t stack1_0__;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        Win32_Code_ReducibleNode** pstack0_0__;
    } __executionFrame__;

    __executionFrame__.targetCount = 1;
    __executionFrame__.pstack0_0__ = &stack0_0__;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(31): */
    /* Path=1, Unique=0: IL_0000: ldarg.0 */
    stack0_0__ = this__;
    /* Path=1, Unique=0: IL_0001: ldarg.1 */
    stack1_0__ = nextIndex;
    /* Path=1, Unique=0: IL_0002: call System.Void Win32.Code.AbstractNode::.ctor(System.Int32) */
    Win32_Code_AbstractNode__ctor((Win32_Code_AbstractNode*)stack0_0__, stack1_0__);
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

// Runtime cast
void* __Win32_Code_ReducibleNode_IL2C_RuntimeCast__(Win32_Code_ReducibleNode* this__, IL2C_RUNTIME_TYPE_DECL* type)
{
    // This type
    if (type == il2c_typeof(Win32_Code_ReducibleNode)) return this__;

    // Delegate checking base types
    return __Win32_Code_AbstractNode_IL2C_RuntimeCast__((Win32_Code_AbstractNode*)this__, type);
}

// GC's mark handler
void __Win32_Code_ReducibleNode_IL2C_MarkHandler__(Win32_Code_ReducibleNode* this__)
{

    // Delegate checking base types
    __Win32_Code_AbstractNode_IL2C_MarkHandler__((Win32_Code_AbstractNode*)this__);
}

// Vtable of Win32.Code.ReducibleNode
__Win32_Code_ReducibleNode_VTABLE_DECL__ __Win32_Code_ReducibleNode_VTABLE__ = {
    /* internalcall */ __Win32_Code_ReducibleNode_IL2C_RuntimeCast__,
    (void*)__System_Object_ToString__,
    (void*)__System_Object_GetHashCode__,
    (void*)__System_Object_Finalize__,
    (void*)__System_Object_Equals__,
    (void*)__Win32_Code_ReducibleNode_Reduce__,
};

// Runtime type information
IL2C_RUNTIME_TYPE_DECL __Win32_Code_ReducibleNode_RUNTIME_TYPE__ = {
    "Win32.Code.ReducibleNode",
    sizeof(Win32_Code_ReducibleNode),
    /* internalcall */ (void*)__Win32_Code_ReducibleNode_IL2C_MarkHandler__,
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

    Win32_Code_NumericNode* stack0_0__ = NULL;
    int32_t stack1_0__;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        Win32_Code_NumericNode** pstack0_0__;
    } __executionFrame__;

    __executionFrame__.targetCount = 1;
    __executionFrame__.pstack0_0__ = &stack0_0__;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(42): */
    /* Path=1, Unique=0: IL_0000: ldarg.0 */
    stack0_0__ = this__;
    /* Path=1, Unique=0: IL_0001: ldarg.2 */
    stack1_0__ = nextIndex;
    /* Path=1, Unique=0: IL_0002: call System.Void Win32.Code.ReducibleNode::.ctor(System.Int32) */
    Win32_Code_ReducibleNode__ctor((Win32_Code_ReducibleNode*)stack0_0__, stack1_0__);
    /* Path=1, Unique=0: IL_0007: nop */
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(43): */
    /* Path=1, Unique=0: IL_0008: nop */
    /* Path=1, Unique=0: IL_0009: ldarg.0 */
    stack0_0__ = this__;
    /* Path=1, Unique=0: IL_000a: ldarg.1 */
    stack1_0__ = numeric;
    /* Path=1, Unique=0: IL_000b: stfld System.Int32 Win32.Code.NumericNode::Numeric */
    stack0_0__->Numeric = stack1_0__;
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

    int32_t local__;

    //-------------------
    // Evaluation stacks:

    Win32_Code_NumericNode* stack0_0__ = NULL;
    int32_t stack0_1__;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        Win32_Code_NumericNode** pstack0_0__;
    } __executionFrame__;

    __executionFrame__.targetCount = 1;
    __executionFrame__.pstack0_0__ = &stack0_0__;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(48): */
    /* Path=1, Unique=0: IL_0000: nop */
    /* Path=1, Unique=0: IL_0001: ldarg.0 */
    stack0_0__ = this__;
    /* Path=1, Unique=0: IL_0002: ldfld System.Int32 Win32.Code.NumericNode::Numeric */
    stack0_1__ = stack0_0__->Numeric;
    /* Path=1, Unique=0: IL_0007: stloc.0 */
    local__ = stack0_1__;
    /* Path=1, Unique=0: IL_0008: br.s IL_000a */
    goto IL_000a;
IL_000a:
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(50): */
    /* Path=2, Unique=0: IL_000a: ldloc.0 */
    stack0_1__ = local__;
    /* Path=2, Unique=0: IL_000b: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return stack0_1__;
}

//////////////////////
// Runtime helpers:

// Runtime cast
void* __Win32_Code_NumericNode_IL2C_RuntimeCast__(Win32_Code_NumericNode* this__, IL2C_RUNTIME_TYPE_DECL* type)
{
    // This type
    if (type == il2c_typeof(Win32_Code_NumericNode)) return this__;

    // Delegate checking base types
    return __Win32_Code_ReducibleNode_IL2C_RuntimeCast__((Win32_Code_ReducibleNode*)this__, type);
}

// GC's mark handler
void __Win32_Code_NumericNode_IL2C_MarkHandler__(Win32_Code_NumericNode* this__)
{

    // Delegate checking base types
    __Win32_Code_ReducibleNode_IL2C_MarkHandler__((Win32_Code_ReducibleNode*)this__);
}

// Vtable of Win32.Code.NumericNode
__Win32_Code_NumericNode_VTABLE_DECL__ __Win32_Code_NumericNode_VTABLE__ = {
    /* internalcall */ __Win32_Code_NumericNode_IL2C_RuntimeCast__,
    (void*)__System_Object_ToString__,
    (void*)__System_Object_GetHashCode__,
    (void*)__System_Object_Finalize__,
    (void*)__System_Object_Equals__,
    (void*)__Win32_Code_NumericNode_Reduce__,
};

// Runtime type information
IL2C_RUNTIME_TYPE_DECL __Win32_Code_NumericNode_RUNTIME_TYPE__ = {
    "Win32.Code.NumericNode",
    sizeof(Win32_Code_NumericNode),
    /* internalcall */ (void*)__Win32_Code_NumericNode_IL2C_MarkHandler__,
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

    Win32_Code_ExpressionNode* stack0_0__ = NULL;
    int32_t stack1_0__;
    Win32_Code_OperatorNode* stack1_1__ = NULL;
    Win32_Code_ReducibleNode* stack1_2__ = NULL;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        Win32_Code_ExpressionNode** pstack0_0__;
        Win32_Code_OperatorNode** pstack1_1__;
        Win32_Code_ReducibleNode** pstack1_2__;
    } __executionFrame__;

    __executionFrame__.targetCount = 3;
    __executionFrame__.pstack0_0__ = &stack0_0__;
    __executionFrame__.pstack1_1__ = &stack1_1__;
    __executionFrame__.pstack1_2__ = &stack1_2__;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(59): */
    /* Path=1, Unique=0: IL_0000: ldarg.0 */
    stack0_0__ = this__;
    /* Path=1, Unique=0: IL_0001: ldarg.s nextIndex */
    stack1_0__ = nextIndex;
    /* Path=1, Unique=0: IL_0003: call System.Void Win32.Code.ReducibleNode::.ctor(System.Int32) */
    Win32_Code_ReducibleNode__ctor((Win32_Code_ReducibleNode*)stack0_0__, stack1_0__);
    /* Path=1, Unique=0: IL_0008: nop */
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(60): */
    /* Path=1, Unique=0: IL_0009: nop */
    /* Path=1, Unique=0: IL_000a: ldarg.0 */
    stack0_0__ = this__;
    /* Path=1, Unique=0: IL_000b: ldarg.1 */
    stack1_1__ = oper;
    /* Path=1, Unique=0: IL_000c: stfld Win32.Code.OperatorNode Win32.Code.ExpressionNode::Operator */
    stack0_0__->Operator = stack1_1__;
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(62): */
    /* Path=1, Unique=0: IL_0011: ldarg.0 */
    stack0_0__ = this__;
    /* Path=1, Unique=0: IL_0012: ldarg.2 */
    stack1_2__ = left;
    /* Path=1, Unique=0: IL_0013: stfld Win32.Code.ReducibleNode Win32.Code.ExpressionNode::Left */
    stack0_0__->Left = stack1_2__;
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(63): */
    /* Path=1, Unique=0: IL_0018: ldarg.0 */
    stack0_0__ = this__;
    /* Path=1, Unique=0: IL_0019: ldarg.3 */
    stack1_2__ = right;
    /* Path=1, Unique=0: IL_001a: stfld Win32.Code.ReducibleNode Win32.Code.ExpressionNode::Right */
    stack0_0__->Right = stack1_2__;
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

    int32_t leftResult__;
    int32_t rightResult__;
    bool local0__;
    int32_t local1__;
    bool local2__;
    bool local3__;
    bool local4__;

    //-------------------
    // Evaluation stacks:

    Win32_Code_ExpressionNode* stack0_0__ = NULL;
    Win32_Code_ReducibleNode* stack0_1__ = NULL;
    int32_t stack0_2__;
    Win32_Code_OperatorNode* stack0_3__ = NULL;
    int32_t stack1_0__;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        Win32_Code_ExpressionNode** pstack0_0__;
        Win32_Code_ReducibleNode** pstack0_1__;
        Win32_Code_OperatorNode** pstack0_3__;
    } __executionFrame__;

    __executionFrame__.targetCount = 3;
    __executionFrame__.pstack0_0__ = &stack0_0__;
    __executionFrame__.pstack0_1__ = &stack0_1__;
    __executionFrame__.pstack0_3__ = &stack0_3__;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(67): */
    /* Path=1, Unique=0: IL_0000: nop */
    /* Path=1, Unique=0: IL_0001: ldarg.0 */
    stack0_0__ = this__;
    /* Path=1, Unique=0: IL_0002: ldfld Win32.Code.ReducibleNode Win32.Code.ExpressionNode::Left */
    stack0_1__ = stack0_0__->Left;
    /* Path=1, Unique=0: IL_0007: callvirt System.Int32 Win32.Code.ReducibleNode::Reduce() */
    stack0_2__ = Win32_Code_ReducibleNode_Reduce(stack0_1__);
    /* Path=1, Unique=0: IL_000c: stloc.0 */
    leftResult__ = stack0_2__;
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(69): */
    /* Path=1, Unique=0: IL_000d: ldarg.0 */
    stack0_0__ = this__;
    /* Path=1, Unique=0: IL_000e: ldfld Win32.Code.ReducibleNode Win32.Code.ExpressionNode::Right */
    stack0_1__ = stack0_0__->Right;
    /* Path=1, Unique=0: IL_0013: callvirt System.Int32 Win32.Code.ReducibleNode::Reduce() */
    stack0_2__ = Win32_Code_ReducibleNode_Reduce(stack0_1__);
    /* Path=1, Unique=0: IL_0018: stloc.1 */
    rightResult__ = stack0_2__;
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(70): */
    /* Path=1, Unique=0: IL_0019: ldarg.0 */
    stack0_0__ = this__;
    /* Path=1, Unique=0: IL_001a: ldfld Win32.Code.OperatorNode Win32.Code.ExpressionNode::Operator */
    stack0_3__ = stack0_0__->Operator;
    /* Path=1, Unique=0: IL_001f: ldfld System.Char Win32.Code.OperatorNode::Operator */
    stack0_2__ = (int32_t)(stack0_3__->Operator);
    /* Path=1, Unique=0: IL_0024: ldc.i4.s 43 */
    stack1_0__ = 43;
    /* Path=1, Unique=0: IL_0026: ceq */
    stack0_2__ = (stack0_2__ == stack1_0__) ? 1 : 0;
    /* Path=1, Unique=0: IL_0028: stloc.2 */
    local0__ = stack0_2__ ? true : false;
    /* Path=1, Unique=0: IL_0029: ldloc.2 */
    stack0_2__ = local0__;
    /* Path=1, Unique=0: IL_002a: brfalse.s IL_0033 */
    if (stack0_2__ == 0) goto IL_0033;
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(71): */
    /* Path=1, Unique=0: IL_002c: nop */
    /* Path=1, Unique=0: IL_002d: ldloc.0 */
    stack0_2__ = leftResult__;
    /* Path=1, Unique=0: IL_002e: ldloc.1 */
    stack1_0__ = rightResult__;
    /* Path=1, Unique=0: IL_002f: add */
    stack0_2__ = stack0_2__ + stack1_0__;
    /* Path=1, Unique=0: IL_0030: stloc.3 */
    local1__ = stack0_2__;
    /* Path=1, Unique=0: IL_0031: br.s IL_008b */
    goto IL_008b;
IL_0033:
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(74): */
    /* Path=2, Unique=0: IL_0033: ldarg.0 */
    stack0_0__ = this__;
    /* Path=2, Unique=0: IL_0034: ldfld Win32.Code.OperatorNode Win32.Code.ExpressionNode::Operator */
    stack0_3__ = stack0_0__->Operator;
    /* Path=2, Unique=0: IL_0039: ldfld System.Char Win32.Code.OperatorNode::Operator */
    stack0_2__ = (int32_t)(stack0_3__->Operator);
    /* Path=2, Unique=0: IL_003e: ldc.i4.s 45 */
    stack1_0__ = 45;
    /* Path=2, Unique=0: IL_0040: ceq */
    stack0_2__ = (stack0_2__ == stack1_0__) ? 1 : 0;
    /* Path=2, Unique=0: IL_0042: stloc.s local4 */
    local2__ = stack0_2__ ? true : false;
    /* Path=2, Unique=0: IL_0044: ldloc.s local4 */
    stack0_2__ = local2__;
    /* Path=2, Unique=0: IL_0046: brfalse.s IL_004f */
    if (stack0_2__ == 0) goto IL_004f;
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(75): */
    /* Path=2, Unique=0: IL_0048: nop */
    /* Path=2, Unique=0: IL_0049: ldloc.0 */
    stack0_2__ = leftResult__;
    /* Path=2, Unique=0: IL_004a: ldloc.1 */
    stack1_0__ = rightResult__;
    /* Path=2, Unique=0: IL_004b: sub */
    stack0_2__ = stack0_2__ - stack1_0__;
    /* Path=2, Unique=0: IL_004c: stloc.3 */
    local1__ = stack0_2__;
    /* Path=2, Unique=0: IL_004d: br.s IL_008b */
    goto IL_008b;
IL_004f:
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(78): */
    /* Path=4, Unique=0: IL_004f: ldarg.0 */
    stack0_0__ = this__;
    /* Path=4, Unique=0: IL_0050: ldfld Win32.Code.OperatorNode Win32.Code.ExpressionNode::Operator */
    stack0_3__ = stack0_0__->Operator;
    /* Path=4, Unique=0: IL_0055: ldfld System.Char Win32.Code.OperatorNode::Operator */
    stack0_2__ = (int32_t)(stack0_3__->Operator);
    /* Path=4, Unique=0: IL_005a: ldc.i4.s 42 */
    stack1_0__ = 42;
    /* Path=4, Unique=0: IL_005c: ceq */
    stack0_2__ = (stack0_2__ == stack1_0__) ? 1 : 0;
    /* Path=4, Unique=0: IL_005e: stloc.s local5 */
    local3__ = stack0_2__ ? true : false;
    /* Path=4, Unique=0: IL_0060: ldloc.s local5 */
    stack0_2__ = local3__;
    /* Path=4, Unique=0: IL_0062: brfalse.s IL_006b */
    if (stack0_2__ == 0) goto IL_006b;
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(79): */
    /* Path=4, Unique=0: IL_0064: nop */
    /* Path=4, Unique=0: IL_0065: ldloc.0 */
    stack0_2__ = leftResult__;
    /* Path=4, Unique=0: IL_0066: ldloc.1 */
    stack1_0__ = rightResult__;
    /* Path=4, Unique=0: IL_0067: mul */
    stack0_2__ = stack0_2__ * stack1_0__;
    /* Path=4, Unique=0: IL_0068: stloc.3 */
    local1__ = stack0_2__;
    /* Path=4, Unique=0: IL_0069: br.s IL_008b */
    goto IL_008b;
IL_006b:
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(82): */
    /* Path=5, Unique=0: IL_006b: ldarg.0 */
    stack0_0__ = this__;
    /* Path=5, Unique=0: IL_006c: ldfld Win32.Code.OperatorNode Win32.Code.ExpressionNode::Operator */
    stack0_3__ = stack0_0__->Operator;
    /* Path=5, Unique=0: IL_0071: ldfld System.Char Win32.Code.OperatorNode::Operator */
    stack0_2__ = (int32_t)(stack0_3__->Operator);
    /* Path=5, Unique=0: IL_0076: ldc.i4.s 47 */
    stack1_0__ = 47;
    /* Path=5, Unique=0: IL_0078: ceq */
    stack0_2__ = (stack0_2__ == stack1_0__) ? 1 : 0;
    /* Path=5, Unique=0: IL_007a: stloc.s local6 */
    local4__ = stack0_2__ ? true : false;
    /* Path=5, Unique=0: IL_007c: ldloc.s local6 */
    stack0_2__ = local4__;
    /* Path=5, Unique=0: IL_007e: brfalse.s IL_0087 */
    if (stack0_2__ == 0) goto IL_0087;
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(83): */
    /* Path=5, Unique=0: IL_0080: nop */
    /* Path=5, Unique=0: IL_0081: ldloc.0 */
    stack0_2__ = leftResult__;
    /* Path=5, Unique=0: IL_0082: ldloc.1 */
    stack1_0__ = rightResult__;
    /* Path=5, Unique=0: IL_0083: div */
    stack0_2__ = stack0_2__ / stack1_0__;
    /* Path=5, Unique=0: IL_0084: stloc.3 */
    local1__ = stack0_2__;
    /* Path=5, Unique=0: IL_0085: br.s IL_008b */
    goto IL_008b;
IL_0087:
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(88): */
    /* Path=6, Unique=0: IL_0087: ldc.i4.0 */
    stack0_2__ = 0;
    /* Path=6, Unique=0: IL_0088: stloc.3 */
    local1__ = stack0_2__;
    /* Path=6, Unique=0: IL_0089: br.s IL_008b */
    goto IL_008b;
IL_008b:
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(89): */
    /* Path=3, Unique=0: IL_008b: ldloc.3 */
    stack0_2__ = local1__;
    /* Path=3, Unique=0: IL_008c: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return stack0_2__;
}

//////////////////////
// Runtime helpers:

// Runtime cast
void* __Win32_Code_ExpressionNode_IL2C_RuntimeCast__(Win32_Code_ExpressionNode* this__, IL2C_RUNTIME_TYPE_DECL* type)
{
    // This type
    if (type == il2c_typeof(Win32_Code_ExpressionNode)) return this__;

    // Delegate checking base types
    return __Win32_Code_ReducibleNode_IL2C_RuntimeCast__((Win32_Code_ReducibleNode*)this__, type);
}

// GC's mark handler
void __Win32_Code_ExpressionNode_IL2C_MarkHandler__(Win32_Code_ExpressionNode* this__)
{
    // Try marking each object reference fields
    il2c_try_mark_from_handler(this__->Operator);
    il2c_try_mark_from_handler(this__->Left);
    il2c_try_mark_from_handler(this__->Right);

    // Delegate checking base types
    __Win32_Code_ReducibleNode_IL2C_MarkHandler__((Win32_Code_ReducibleNode*)this__);
}

// Vtable of Win32.Code.ExpressionNode
__Win32_Code_ExpressionNode_VTABLE_DECL__ __Win32_Code_ExpressionNode_VTABLE__ = {
    /* internalcall */ __Win32_Code_ExpressionNode_IL2C_RuntimeCast__,
    (void*)__System_Object_ToString__,
    (void*)__System_Object_GetHashCode__,
    (void*)__System_Object_Finalize__,
    (void*)__System_Object_Equals__,
    (void*)__Win32_Code_ExpressionNode_Reduce__,
};

// Runtime type information
IL2C_RUNTIME_TYPE_DECL __Win32_Code_ExpressionNode_RUNTIME_TYPE__ = {
    "Win32.Code.ExpressionNode",
    sizeof(Win32_Code_ExpressionNode),
    /* internalcall */ (void*)__Win32_Code_ExpressionNode_IL2C_MarkHandler__,
};

////////////////////////////////////////////////////////////
// Type: Win32.Code.PolishNotation

///////////////////////////////////////
// SkipWhiteSpace

int32_t Win32_Code_PolishNotation_SkipWhiteSpace(System_String* line, int32_t startIndex)
{
    //-------------------
    // Local variables:

    int32_t index__;
    wchar_t ch__;
    bool local0__;
    bool local1__;
    int32_t local2__;

    //-------------------
    // Evaluation stacks:

    int32_t stack0_0__;
    System_String* stack0_1__ = NULL;
    int32_t stack0_2__;
    System_String* stack1_0__ = NULL;
    int32_t stack1_1__;
    int32_t stack1_2__;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        System_String** pstack0_1__;
        System_String** pstack1_0__;
    } __executionFrame__;

    __executionFrame__.targetCount = 2;
    __executionFrame__.pstack0_1__ = &stack0_1__;
    __executionFrame__.pstack1_0__ = &stack1_0__;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(95): */
    /* Path=1, Unique=0: IL_0000: nop */
    /* Path=1, Unique=0: IL_0001: ldarg.1 */
    stack0_0__ = startIndex;
    /* Path=1, Unique=0: IL_0002: stloc.0 */
    index__ = stack0_0__;
    /* Path=1, Unique=0: IL_0003: br.s IL_002a */
    goto IL_002a;
IL_0005:
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(98): */
    /* Path=3, Unique=0: IL_0005: nop */
    /* Path=3, Unique=0: IL_0006: ldarg.0 */
    stack0_1__ = line;
    /* Path=3, Unique=0: IL_0007: ldloc.0 */
    stack1_2__ = index__;
    /* Path=3, Unique=0: IL_0008: callvirt System.Char System.String::get_Chars(System.Int32) */
    stack0_2__ = System_String_get_Chars(stack0_1__, stack1_2__);
    /* Path=3, Unique=0: IL_000d: stloc.1 */
    ch__ = (wchar_t)stack0_2__;
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(100): */
    /* Path=3, Unique=0: IL_000e: ldloc.1 */
    stack0_0__ = ch__;
    /* Path=3, Unique=0: IL_000f: ldc.i4.s 32 */
    stack1_2__ = 32;
    /* Path=3, Unique=0: IL_0011: beq.s IL_001d */
    if (stack0_0__ == stack1_2__) goto IL_001d;
    /* Path=3, Unique=0: IL_0013: ldloc.1 */
    stack0_0__ = ch__;
    /* Path=3, Unique=0: IL_0014: ldc.i4.s 9 */
    stack1_2__ = 9;
    /* Path=3, Unique=0: IL_0016: ceq */
    stack0_0__ = (stack0_0__ == stack1_2__) ? 1 : 0;
    /* Path=3, Unique=0: IL_0018: ldc.i4.0 */
    stack1_2__ = 0;
    /* Path=3, Unique=0: IL_0019: ceq */
    stack0_0__ = (stack0_0__ == stack1_2__) ? 1 : 0;
    /* Path=3, Unique=0: IL_001b: br.s IL_001e */
    goto IL_001e;
IL_001d:
    /* Path=5, Unique=0: IL_001d: ldc.i4.0 */
    stack0_0__ = 0;
IL_001e:
    /* Path=5, Unique=0: IL_001e: stloc.2 */
    local0__ = stack0_0__ ? true : false;
    /* Path=5, Unique=0: IL_001f: ldloc.2 */
    stack0_0__ = local0__;
    /* Path=5, Unique=0: IL_0020: brfalse.s IL_0025 */
    if (stack0_0__ == 0) goto IL_0025;
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(101): */
    /* Path=5, Unique=0: IL_0022: nop */
    /* Path=5, Unique=0: IL_0023: br.s IL_0037 */
    goto IL_0037;
IL_0025:
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(104): */
    /* Path=6, Unique=0: IL_0025: ldloc.0 */
    stack0_0__ = index__;
    /* Path=6, Unique=0: IL_0026: ldc.i4.1 */
    stack1_2__ = 1;
    /* Path=6, Unique=0: IL_0027: add */
    stack0_0__ = stack0_0__ + stack1_2__;
    /* Path=6, Unique=0: IL_0028: stloc.0 */
    index__ = stack0_0__;
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(105): */
    /* Path=6, Unique=0: IL_0029: nop */
IL_002a:
    /* Path=2, Unique=0: IL_002a: ldloc.0 */
    stack0_0__ = index__;
    /* Path=2, Unique=0: IL_002b: ldarg.0 */
    stack1_0__ = line;
    /* Path=2, Unique=0: IL_002c: callvirt System.Int32 System.String::get_Length() */
    stack1_1__ = System_String_get_Length(stack1_0__);
    /* Path=2, Unique=0: IL_0031: clt */
    stack0_0__ = (stack0_0__ < stack1_1__) ? 1 : 0;
    /* Path=2, Unique=0: IL_0033: stloc.3 */
    local1__ = stack0_0__ ? true : false;
    /* Path=2, Unique=0: IL_0034: ldloc.3 */
    stack0_0__ = local1__;
    /* Path=2, Unique=0: IL_0035: brtrue.s IL_0005 */
    if (stack0_0__ != 0) goto IL_0005;
IL_0037:
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(107): */
    /* Path=2, Unique=0: IL_0037: ldloc.0 */
    stack0_0__ = index__;
    /* Path=2, Unique=0: IL_0038: stloc.s local4 */
    local2__ = stack0_0__;
    /* Path=2, Unique=0: IL_003a: br.s IL_003c */
    goto IL_003c;
IL_003c:
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(108): */
    /* Path=4, Unique=0: IL_003c: ldloc.s local4 */
    stack0_0__ = local2__;
    /* Path=4, Unique=0: IL_003e: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return stack0_0__;
}

///////////////////////////////////////
// ParseOperator

Win32_Code_OperatorNode* Win32_Code_PolishNotation_ParseOperator(System_String* line, int32_t startIndex)
{
    //-------------------
    // Local variables:

    int32_t index__;
    wchar_t ch__;
    bool local0__;
    Win32_Code_OperatorNode* local1__ = NULL;
    bool local2__;

    //-------------------
    // Evaluation stacks:

    int32_t stack0_0__;
    IL2C_CecilHelper_PseudoZeroType* stack0_1__ = NULL;
    System_String* stack0_2__ = NULL;
    int32_t stack0_3__;
    Win32_Code_OperatorNode* stack0_4__ = NULL;
    System_String* stack1_0__ = NULL;
    int32_t stack1_1__;
    int32_t stack1_2__;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        Win32_Code_OperatorNode** plocal1__;
        IL2C_CecilHelper_PseudoZeroType** pstack0_1__;
        System_String** pstack0_2__;
        Win32_Code_OperatorNode** pstack0_4__;
        System_String** pstack1_0__;
    } __executionFrame__;

    __executionFrame__.targetCount = 5;
    __executionFrame__.plocal1__ = &local1__;
    __executionFrame__.pstack0_1__ = &stack0_1__;
    __executionFrame__.pstack0_2__ = &stack0_2__;
    __executionFrame__.pstack0_4__ = &stack0_4__;
    __executionFrame__.pstack1_0__ = &stack1_0__;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(111): */
    /* Path=1, Unique=0: IL_0000: nop */
    /* Path=1, Unique=0: IL_0001: ldarg.1 */
    stack0_0__ = startIndex;
    /* Path=1, Unique=0: IL_0002: ldarg.0 */
    stack1_0__ = line;
    /* Path=1, Unique=0: IL_0003: callvirt System.Int32 System.String::get_Length() */
    stack1_1__ = System_String_get_Length(stack1_0__);
    /* Path=1, Unique=0: IL_0008: clt */
    stack0_0__ = (stack0_0__ < stack1_1__) ? 1 : 0;
    /* Path=1, Unique=0: IL_000a: ldc.i4.0 */
    stack1_2__ = 0;
    /* Path=1, Unique=0: IL_000b: ceq */
    stack0_0__ = (stack0_0__ == stack1_2__) ? 1 : 0;
    /* Path=1, Unique=0: IL_000d: stloc.2 */
    local0__ = stack0_0__ ? true : false;
    /* Path=1, Unique=0: IL_000e: ldloc.2 */
    stack0_0__ = local0__;
    /* Path=1, Unique=0: IL_000f: brfalse.s IL_0016 */
    if (stack0_0__ == 0) goto IL_0016;
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(113): */
    /* Path=1, Unique=0: IL_0011: nop */
    /* Path=1, Unique=0: IL_0012: ldnull */
    stack0_1__ = NULL;
    /* Path=1, Unique=0: IL_0013: stloc.3 */
    local1__ = (Win32_Code_OperatorNode*)stack0_1__;
    /* Path=1, Unique=0: IL_0014: br.s IL_005b */
    goto IL_005b;
IL_0016:
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(117): */
    /* Path=2, Unique=0: IL_0016: ldarg.1 */
    stack0_0__ = startIndex;
    /* Path=2, Unique=0: IL_0017: stloc.0 */
    index__ = stack0_0__;
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(118): */
    /* Path=2, Unique=0: IL_0018: ldarg.0 */
    stack0_2__ = line;
    /* Path=2, Unique=0: IL_0019: ldloc.0 */
    stack1_2__ = index__;
    /* Path=2, Unique=0: IL_001a: callvirt System.Char System.String::get_Chars(System.Int32) */
    stack0_3__ = System_String_get_Chars(stack0_2__, stack1_2__);
    /* Path=2, Unique=0: IL_001f: stloc.1 */
    ch__ = (wchar_t)stack0_3__;
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(119): */
    /* Path=2, Unique=0: IL_0020: ldloc.1 */
    stack0_0__ = ch__;
    /* Path=2, Unique=0: IL_0021: ldc.i4.s 43 */
    stack1_2__ = 43;
    /* Path=2, Unique=0: IL_0023: beq.s IL_0039 */
    if (stack0_0__ == stack1_2__) goto IL_0039;
    /* Path=2, Unique=0: IL_0025: ldloc.1 */
    stack0_0__ = ch__;
    /* Path=2, Unique=0: IL_0026: ldc.i4.s 45 */
    stack1_2__ = 45;
    /* Path=2, Unique=0: IL_0028: beq.s IL_0039 */
    if (stack0_0__ == stack1_2__) goto IL_0039;
    /* Path=2, Unique=0: IL_002a: ldloc.1 */
    stack0_0__ = ch__;
    /* Path=2, Unique=0: IL_002b: ldc.i4.s 42 */
    stack1_2__ = 42;
    /* Path=2, Unique=0: IL_002d: beq.s IL_0039 */
    if (stack0_0__ == stack1_2__) goto IL_0039;
    /* Path=2, Unique=0: IL_002f: ldloc.1 */
    stack0_0__ = ch__;
    /* Path=2, Unique=0: IL_0030: ldc.i4.s 47 */
    stack1_2__ = 47;
    /* Path=2, Unique=0: IL_0032: ceq */
    stack0_0__ = (stack0_0__ == stack1_2__) ? 1 : 0;
    /* Path=2, Unique=0: IL_0034: ldc.i4.0 */
    stack1_2__ = 0;
    /* Path=2, Unique=0: IL_0035: ceq */
    stack0_0__ = (stack0_0__ == stack1_2__) ? 1 : 0;
    /* Path=2, Unique=0: IL_0037: br.s IL_003a */
    goto IL_003a;
IL_0039:
    /* Path=4, Unique=0: IL_0039: ldc.i4.0 */
    stack0_0__ = 0;
IL_003a:
    /* Path=4, Unique=0: IL_003a: stloc.s local4 */
    local2__ = stack0_0__ ? true : false;
    /* Path=4, Unique=0: IL_003c: ldloc.s local4 */
    stack0_0__ = local2__;
    /* Path=4, Unique=0: IL_003e: brfalse.s IL_0045 */
    if (stack0_0__ == 0) goto IL_0045;
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(120): */
    /* Path=4, Unique=0: IL_0040: nop */
    /* Path=4, Unique=0: IL_0041: ldnull */
    stack0_1__ = NULL;
    /* Path=4, Unique=0: IL_0042: stloc.3 */
    local1__ = (Win32_Code_OperatorNode*)stack0_1__;
    /* Path=4, Unique=0: IL_0043: br.s IL_005b */
    goto IL_005b;
IL_0045:
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(123): */
    /* Path=5, Unique=0: IL_0045: ldloc.0 */
    stack0_0__ = index__;
    /* Path=5, Unique=0: IL_0046: ldc.i4.1 */
    stack1_2__ = 1;
    /* Path=5, Unique=0: IL_0047: add */
    stack0_0__ = stack0_0__ + stack1_2__;
    /* Path=5, Unique=0: IL_0048: stloc.0 */
    index__ = stack0_0__;
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(125): */
    /* Path=5, Unique=0: IL_0049: ldarg.0 */
    stack0_2__ = line;
    /* Path=5, Unique=0: IL_004a: ldloc.0 */
    stack1_2__ = index__;
    /* Path=5, Unique=0: IL_004b: call System.Int32 Win32.Code.PolishNotation::SkipWhiteSpace(System.String,System.Int32) */
    stack0_0__ = Win32_Code_PolishNotation_SkipWhiteSpace(stack0_2__, stack1_2__);
    /* Path=5, Unique=0: IL_0050: stloc.0 */
    index__ = stack0_0__;
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(126): */
    /* Path=5, Unique=0: IL_0051: ldloc.1 */
    stack0_0__ = ch__;
    /* Path=5, Unique=0: IL_0052: ldloc.0 */
    stack1_2__ = index__;
    /* Path=5, Unique=0: IL_0053: newobj System.Void Win32.Code.OperatorNode::.ctor(System.Char,System.Int32) */
    stack0_4__ = il2c_get_uninitialized_object(il2c_typeof(Win32_Code_OperatorNode));
    stack0_4__->vptr0__ = &__Win32_Code_OperatorNode_VTABLE__;
    Win32_Code_OperatorNode__ctor(stack0_4__, (wchar_t)stack0_0__, stack1_2__);
    /* Path=5, Unique=0: IL_0058: stloc.3 */
    local1__ = stack0_4__;
    /* Path=5, Unique=0: IL_0059: br.s IL_005b */
    goto IL_005b;
IL_005b:
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(127): */
    /* Path=3, Unique=0: IL_005b: ldloc.3 */
    stack0_4__ = local1__;
    /* Path=3, Unique=0: IL_005c: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return stack0_4__;
}

///////////////////////////////////////
// ParseNumeric

Win32_Code_NumericNode* Win32_Code_PolishNotation_ParseNumeric(System_String* line, int32_t startIndex)
{
    //-------------------
    // Local variables:

    int32_t index__;
    System_String* token__ = NULL;
    int32_t numeric__;
    bool local0__;
    Win32_Code_NumericNode* local1__ = NULL;
    wchar_t ch__;
    bool local2__;
    bool local3__;
    bool local4__;
    bool local5__;

    //-------------------
    // Evaluation stacks:

    int32_t stack0_0__;
    IL2C_CecilHelper_PseudoZeroType* stack0_1__ = NULL;
    Win32_Code_NumericNode* stack0_2__ = NULL;
    System_String* stack0_3__ = NULL;
    int32_t stack0_4__;
    System_String* stack0_5__ = NULL;
    System_String* stack1_0__ = NULL;
    int32_t stack1_1__;
    int32_t stack1_2__;
    int32_t* stack1_3__ = NULL;
    int32_t stack2_0__;
    int32_t stack3_0__;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        System_String** ptoken__;
        Win32_Code_NumericNode** plocal1__;
        IL2C_CecilHelper_PseudoZeroType** pstack0_1__;
        Win32_Code_NumericNode** pstack0_2__;
        System_String** pstack0_3__;
        System_String** pstack0_5__;
        System_String** pstack1_0__;
        int32_t** pstack1_3__;
    } __executionFrame__;

    __executionFrame__.targetCount = 8;
    __executionFrame__.ptoken__ = &token__;
    __executionFrame__.plocal1__ = &local1__;
    __executionFrame__.pstack0_1__ = &stack0_1__;
    __executionFrame__.pstack0_2__ = &stack0_2__;
    __executionFrame__.pstack0_3__ = &stack0_3__;
    __executionFrame__.pstack0_5__ = &stack0_5__;
    __executionFrame__.pstack1_0__ = &stack1_0__;
    __executionFrame__.pstack1_3__ = &stack1_3__;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(130): */
    /* Path=1, Unique=0: IL_0000: nop */
    /* Path=1, Unique=0: IL_0001: ldarg.1 */
    stack0_0__ = startIndex;
    /* Path=1, Unique=0: IL_0002: ldarg.0 */
    stack1_0__ = line;
    /* Path=1, Unique=0: IL_0003: callvirt System.Int32 System.String::get_Length() */
    stack1_1__ = System_String_get_Length(stack1_0__);
    /* Path=1, Unique=0: IL_0008: clt */
    stack0_0__ = (stack0_0__ < stack1_1__) ? 1 : 0;
    /* Path=1, Unique=0: IL_000a: ldc.i4.0 */
    stack1_2__ = 0;
    /* Path=1, Unique=0: IL_000b: ceq */
    stack0_0__ = (stack0_0__ == stack1_2__) ? 1 : 0;
    /* Path=1, Unique=0: IL_000d: stloc.3 */
    local0__ = stack0_0__ ? true : false;
    /* Path=1, Unique=0: IL_000e: ldloc.3 */
    stack0_0__ = local0__;
    /* Path=1, Unique=0: IL_000f: brfalse.s IL_0017 */
    if (stack0_0__ == 0) goto IL_0017;
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(132): */
    /* Path=1, Unique=0: IL_0011: nop */
    /* Path=1, Unique=0: IL_0012: ldnull */
    stack0_1__ = NULL;
    /* Path=1, Unique=0: IL_0013: stloc.s local4 */
    local1__ = (Win32_Code_NumericNode*)stack0_1__;
    /* Path=1, Unique=0: IL_0015: br.s IL_008d */
    goto IL_008d;
IL_0017:
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(136): */
    /* Path=2, Unique=0: IL_0017: ldarg.1 */
    stack0_0__ = startIndex;
    /* Path=2, Unique=0: IL_0018: stloc.0 */
    index__ = stack0_0__;
    /* Path=2, Unique=0: IL_0019: br.s IL_0039 */
    goto IL_0039;
IL_001b:
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(138): */
    /* Path=5, Unique=0: IL_001b: nop */
    /* Path=5, Unique=0: IL_001c: ldarg.0 */
    stack0_3__ = line;
    /* Path=5, Unique=0: IL_001d: ldloc.0 */
    stack1_2__ = index__;
    /* Path=5, Unique=0: IL_001e: callvirt System.Char System.String::get_Chars(System.Int32) */
    stack0_4__ = System_String_get_Chars(stack0_3__, stack1_2__);
    /* Path=5, Unique=0: IL_0023: stloc.s local5 */
    ch__ = (wchar_t)stack0_4__;
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(140): */
    /* Path=5, Unique=0: IL_0025: ldloc.s local5 */
    stack0_0__ = ch__;
    /* Path=5, Unique=0: IL_0027: ldc.i4.s 32 */
    stack1_2__ = 32;
    /* Path=5, Unique=0: IL_0029: ceq */
    stack0_0__ = (stack0_0__ == stack1_2__) ? 1 : 0;
    /* Path=5, Unique=0: IL_002b: stloc.s local6 */
    local2__ = stack0_0__ ? true : false;
    /* Path=5, Unique=0: IL_002d: ldloc.s local6 */
    stack0_0__ = local2__;
    /* Path=5, Unique=0: IL_002f: brfalse.s IL_0034 */
    if (stack0_0__ == 0) goto IL_0034;
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(141): */
    /* Path=5, Unique=0: IL_0031: nop */
    /* Path=5, Unique=0: IL_0032: br.s IL_0048 */
    goto IL_0048;
IL_0034:
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(144): */
    /* Path=7, Unique=0: IL_0034: ldloc.0 */
    stack0_0__ = index__;
    /* Path=7, Unique=0: IL_0035: ldc.i4.1 */
    stack1_2__ = 1;
    /* Path=7, Unique=0: IL_0036: add */
    stack0_0__ = stack0_0__ + stack1_2__;
    /* Path=7, Unique=0: IL_0037: stloc.0 */
    index__ = stack0_0__;
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(145): */
    /* Path=7, Unique=0: IL_0038: nop */
IL_0039:
    /* Path=4, Unique=0: IL_0039: ldloc.0 */
    stack0_0__ = index__;
    /* Path=4, Unique=0: IL_003a: ldarg.0 */
    stack1_0__ = line;
    /* Path=4, Unique=0: IL_003b: callvirt System.Int32 System.String::get_Length() */
    stack1_1__ = System_String_get_Length(stack1_0__);
    /* Path=4, Unique=0: IL_0040: clt */
    stack0_0__ = (stack0_0__ < stack1_1__) ? 1 : 0;
    /* Path=4, Unique=0: IL_0042: stloc.s local7 */
    local3__ = stack0_0__ ? true : false;
    /* Path=4, Unique=0: IL_0044: ldloc.s local7 */
    stack0_0__ = local3__;
    /* Path=4, Unique=0: IL_0046: brtrue.s IL_001b */
    if (stack0_0__ != 0) goto IL_001b;
IL_0048:
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(147): */
    /* Path=4, Unique=0: IL_0048: ldloc.0 */
    stack0_0__ = index__;
    /* Path=4, Unique=0: IL_0049: ldarg.1 */
    stack1_2__ = startIndex;
    /* Path=4, Unique=0: IL_004a: ceq */
    stack0_0__ = (stack0_0__ == stack1_2__) ? 1 : 0;
    /* Path=4, Unique=0: IL_004c: stloc.s local8 */
    local4__ = stack0_0__ ? true : false;
    /* Path=4, Unique=0: IL_004e: ldloc.s local8 */
    stack0_0__ = local4__;
    /* Path=4, Unique=0: IL_0050: brfalse.s IL_0058 */
    if (stack0_0__ == 0) goto IL_0058;
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(148): */
    /* Path=4, Unique=0: IL_0052: nop */
    /* Path=4, Unique=0: IL_0053: ldnull */
    stack0_1__ = NULL;
    /* Path=4, Unique=0: IL_0054: stloc.s local4 */
    local1__ = (Win32_Code_NumericNode*)stack0_1__;
    /* Path=4, Unique=0: IL_0056: br.s IL_008d */
    goto IL_008d;
IL_0058:
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(152): */
    /* Path=6, Unique=0: IL_0058: ldarg.0 */
    stack0_3__ = line;
    /* Path=6, Unique=0: IL_0059: ldarg.1 */
    stack1_2__ = startIndex;
    /* Path=6, Unique=0: IL_005a: ldloc.0 */
    stack2_0__ = index__;
    /* Path=6, Unique=0: IL_005b: ldarg.1 */
    stack3_0__ = startIndex;
    /* Path=6, Unique=0: IL_005c: sub */
    stack2_0__ = stack2_0__ - stack3_0__;
    /* Path=6, Unique=0: IL_005d: callvirt System.String System.String::Substring(System.Int32,System.Int32) */
    stack0_5__ = System_String_Substring_1(stack0_3__, stack1_2__, stack2_0__);
    /* Path=6, Unique=0: IL_0062: stloc.1 */
    token__ = stack0_5__;
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(153): */
    /* Path=6, Unique=0: IL_0063: ldloc.1 */
    stack0_3__ = token__;
    /* Path=6, Unique=0: IL_0064: ldloca.s local2 */
    stack1_3__ = &numeric__;
    /* Path=6, Unique=0: IL_0066: call System.Boolean System.Int32::TryParse(System.String,System.Int32&) */
    stack0_0__ = System_Int32_TryParse(stack0_3__, stack1_3__);
    /* Path=6, Unique=0: IL_006b: ldc.i4.0 */
    stack1_2__ = 0;
    /* Path=6, Unique=0: IL_006c: ceq */
    stack0_0__ = (stack0_0__ == stack1_2__) ? 1 : 0;
    /* Path=6, Unique=0: IL_006e: stloc.s local9 */
    local5__ = stack0_0__ ? true : false;
    /* Path=6, Unique=0: IL_0070: ldloc.s local9 */
    stack0_0__ = local5__;
    /* Path=6, Unique=0: IL_0072: brfalse.s IL_007a */
    if (stack0_0__ == 0) goto IL_007a;
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(154): */
    /* Path=6, Unique=0: IL_0074: nop */
    /* Path=6, Unique=0: IL_0075: ldnull */
    stack0_1__ = NULL;
    /* Path=6, Unique=0: IL_0076: stloc.s local4 */
    local1__ = (Win32_Code_NumericNode*)stack0_1__;
    /* Path=6, Unique=0: IL_0078: br.s IL_008d */
    goto IL_008d;
IL_007a:
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(158): */
    /* Path=8, Unique=0: IL_007a: ldarg.0 */
    stack0_3__ = line;
    /* Path=8, Unique=0: IL_007b: ldloc.0 */
    stack1_2__ = index__;
    /* Path=8, Unique=0: IL_007c: call System.Int32 Win32.Code.PolishNotation::SkipWhiteSpace(System.String,System.Int32) */
    stack0_0__ = Win32_Code_PolishNotation_SkipWhiteSpace(stack0_3__, stack1_2__);
    /* Path=8, Unique=0: IL_0081: stloc.0 */
    index__ = stack0_0__;
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(159): */
    /* Path=8, Unique=0: IL_0082: ldloc.2 */
    stack0_0__ = numeric__;
    /* Path=8, Unique=0: IL_0083: ldloc.0 */
    stack1_2__ = index__;
    /* Path=8, Unique=0: IL_0084: newobj System.Void Win32.Code.NumericNode::.ctor(System.Int32,System.Int32) */
    stack0_2__ = il2c_get_uninitialized_object(il2c_typeof(Win32_Code_NumericNode));
    stack0_2__->vptr0__ = &__Win32_Code_NumericNode_VTABLE__;
    Win32_Code_NumericNode__ctor(stack0_2__, stack0_0__, stack1_2__);
    /* Path=8, Unique=0: IL_0089: stloc.s local4 */
    local1__ = stack0_2__;
    /* Path=8, Unique=0: IL_008b: br.s IL_008d */
    goto IL_008d;
IL_008d:
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(160): */
    /* Path=3, Unique=0: IL_008d: ldloc.s local4 */
    stack0_2__ = local1__;
    /* Path=3, Unique=0: IL_008f: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return stack0_2__;
}

///////////////////////////////////////
// ParseExpression

Win32_Code_ExpressionNode* Win32_Code_PolishNotation_ParseExpression(System_String* line, int32_t startIndex)
{
    //-------------------
    // Local variables:

    Win32_Code_OperatorNode* oper__ = NULL;
    Win32_Code_ReducibleNode* left__ = NULL;
    Win32_Code_ReducibleNode* right__ = NULL;
    int32_t index__;
    bool local0__;
    Win32_Code_ExpressionNode* local1__ = NULL;
    bool local2__;
    bool local3__;
    bool local4__;
    bool local5__;
    bool local6__;

    //-------------------
    // Evaluation stacks:

    int32_t stack0_0__;
    IL2C_CecilHelper_PseudoZeroType* stack0_1__ = NULL;
    System_String* stack0_2__ = NULL;
    Win32_Code_OperatorNode* stack0_3__ = NULL;
    Win32_Code_ExpressionNode* stack0_4__ = NULL;
    Win32_Code_NumericNode* stack0_5__ = NULL;
    Win32_Code_ReducibleNode* stack0_6__ = NULL;
    System_String* stack1_0__ = NULL;
    int32_t stack1_1__;
    int32_t stack1_2__;
    IL2C_CecilHelper_PseudoZeroType* stack1_3__ = NULL;
    Win32_Code_OperatorNode* stack1_4__ = NULL;
    Win32_Code_ReducibleNode* stack1_5__ = NULL;
    Win32_Code_ReducibleNode* stack2_0__ = NULL;
    int32_t stack3_0__;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        Win32_Code_OperatorNode** poper__;
        Win32_Code_ReducibleNode** pleft__;
        Win32_Code_ReducibleNode** pright__;
        Win32_Code_ExpressionNode** plocal1__;
        IL2C_CecilHelper_PseudoZeroType** pstack0_1__;
        System_String** pstack0_2__;
        Win32_Code_OperatorNode** pstack0_3__;
        Win32_Code_ExpressionNode** pstack0_4__;
        Win32_Code_NumericNode** pstack0_5__;
        Win32_Code_ReducibleNode** pstack0_6__;
        System_String** pstack1_0__;
        IL2C_CecilHelper_PseudoZeroType** pstack1_3__;
        Win32_Code_OperatorNode** pstack1_4__;
        Win32_Code_ReducibleNode** pstack1_5__;
        Win32_Code_ReducibleNode** pstack2_0__;
    } __executionFrame__;

    __executionFrame__.targetCount = 15;
    __executionFrame__.poper__ = &oper__;
    __executionFrame__.pleft__ = &left__;
    __executionFrame__.pright__ = &right__;
    __executionFrame__.plocal1__ = &local1__;
    __executionFrame__.pstack0_1__ = &stack0_1__;
    __executionFrame__.pstack0_2__ = &stack0_2__;
    __executionFrame__.pstack0_3__ = &stack0_3__;
    __executionFrame__.pstack0_4__ = &stack0_4__;
    __executionFrame__.pstack0_5__ = &stack0_5__;
    __executionFrame__.pstack0_6__ = &stack0_6__;
    __executionFrame__.pstack1_0__ = &stack1_0__;
    __executionFrame__.pstack1_3__ = &stack1_3__;
    __executionFrame__.pstack1_4__ = &stack1_4__;
    __executionFrame__.pstack1_5__ = &stack1_5__;
    __executionFrame__.pstack2_0__ = &stack2_0__;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(163): */
    /* Path=1, Unique=0: IL_0000: nop */
    /* Path=1, Unique=0: IL_0001: ldarg.1 */
    stack0_0__ = startIndex;
    /* Path=1, Unique=0: IL_0002: ldarg.0 */
    stack1_0__ = line;
    /* Path=1, Unique=0: IL_0003: callvirt System.Int32 System.String::get_Length() */
    stack1_1__ = System_String_get_Length(stack1_0__);
    /* Path=1, Unique=0: IL_0008: clt */
    stack0_0__ = (stack0_0__ < stack1_1__) ? 1 : 0;
    /* Path=1, Unique=0: IL_000a: ldc.i4.0 */
    stack1_2__ = 0;
    /* Path=1, Unique=0: IL_000b: ceq */
    stack0_0__ = (stack0_0__ == stack1_2__) ? 1 : 0;
    /* Path=1, Unique=0: IL_000d: stloc.s local4 */
    local0__ = stack0_0__ ? true : false;
    /* Path=1, Unique=0: IL_000f: ldloc.s local4 */
    stack0_0__ = local0__;
    /* Path=1, Unique=0: IL_0011: brfalse.s IL_001c */
    if (stack0_0__ == 0) goto IL_001c;
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(165): */
    /* Path=1, Unique=0: IL_0013: nop */
    /* Path=1, Unique=0: IL_0014: ldnull */
    stack0_1__ = NULL;
    /* Path=1, Unique=0: IL_0015: stloc.s local5 */
    local1__ = (Win32_Code_ExpressionNode*)stack0_1__;
    /* Path=1, Unique=0: IL_0017: br IL_00bd */
    goto IL_00bd;
IL_001c:
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(169): */
    /* Path=2, Unique=0: IL_001c: ldarg.0 */
    stack0_2__ = line;
    /* Path=2, Unique=0: IL_001d: ldarg.1 */
    stack1_2__ = startIndex;
    /* Path=2, Unique=0: IL_001e: call Win32.Code.OperatorNode Win32.Code.PolishNotation::ParseOperator(System.String,System.Int32) */
    stack0_3__ = Win32_Code_PolishNotation_ParseOperator(stack0_2__, stack1_2__);
    /* Path=2, Unique=0: IL_0023: stloc.0 */
    oper__ = stack0_3__;
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(170): */
    /* Path=2, Unique=0: IL_0024: ldloc.0 */
    stack0_3__ = oper__;
    /* Path=2, Unique=0: IL_0025: ldnull */
    stack1_3__ = NULL;
    /* Path=2, Unique=0: IL_0026: ceq */
    stack0_0__ = (stack0_3__ == ((Win32_Code_OperatorNode*)stack1_3__)) ? 1 : 0;
    /* Path=2, Unique=0: IL_0028: stloc.s local6 */
    local2__ = stack0_0__ ? true : false;
    /* Path=2, Unique=0: IL_002a: ldloc.s local6 */
    stack0_0__ = local2__;
    /* Path=2, Unique=0: IL_002c: brfalse.s IL_0037 */
    if (stack0_0__ == 0) goto IL_0037;
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(171): */
    /* Path=2, Unique=0: IL_002e: nop */
    /* Path=2, Unique=0: IL_002f: ldnull */
    stack0_1__ = NULL;
    /* Path=2, Unique=0: IL_0030: stloc.s local5 */
    local1__ = (Win32_Code_ExpressionNode*)stack0_1__;
    /* Path=2, Unique=0: IL_0032: br IL_00bd */
    goto IL_00bd;
IL_0037:
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(175): */
    /* Path=4, Unique=0: IL_0037: ldarg.0 */
    stack0_2__ = line;
    /* Path=4, Unique=0: IL_0038: ldloc.0 */
    stack1_4__ = oper__;
    /* Path=4, Unique=0: IL_0039: ldfld System.Int32 Win32.Code.AbstractNode::NextIndex */
    stack1_2__ = stack1_4__->NextIndex;
    /* Path=4, Unique=0: IL_003e: call Win32.Code.NumericNode Win32.Code.PolishNotation::ParseNumeric(System.String,System.Int32) */
    stack0_5__ = Win32_Code_PolishNotation_ParseNumeric(stack0_2__, stack1_2__);
    /* Path=4, Unique=0: IL_0043: stloc.1 */
    left__ = (Win32_Code_ReducibleNode*)stack0_5__;
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(176): */
    /* Path=4, Unique=0: IL_0044: ldloc.1 */
    stack0_6__ = left__;
    /* Path=4, Unique=0: IL_0045: ldnull */
    stack1_3__ = NULL;
    /* Path=4, Unique=0: IL_0046: ceq */
    stack0_0__ = (stack0_6__ == ((Win32_Code_ReducibleNode*)stack1_3__)) ? 1 : 0;
    /* Path=4, Unique=0: IL_0048: stloc.s local7 */
    local3__ = stack0_0__ ? true : false;
    /* Path=4, Unique=0: IL_004a: ldloc.s local7 */
    stack0_0__ = local3__;
    /* Path=4, Unique=0: IL_004c: brfalse.s IL_006d */
    if (stack0_0__ == 0) goto IL_006d;
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(177): */
    /* Path=4, Unique=0: IL_004e: nop */
    /* Path=4, Unique=0: IL_004f: ldarg.0 */
    stack0_2__ = line;
    /* Path=4, Unique=0: IL_0050: ldloc.0 */
    stack1_4__ = oper__;
    /* Path=4, Unique=0: IL_0051: ldfld System.Int32 Win32.Code.AbstractNode::NextIndex */
    stack1_2__ = stack1_4__->NextIndex;
    /* Path=4, Unique=0: IL_0056: call Win32.Code.ExpressionNode Win32.Code.PolishNotation::ParseExpression(System.String,System.Int32) */
    stack0_4__ = Win32_Code_PolishNotation_ParseExpression(stack0_2__, stack1_2__);
    /* Path=4, Unique=0: IL_005b: stloc.1 */
    left__ = (Win32_Code_ReducibleNode*)stack0_4__;
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(179): */
    /* Path=4, Unique=0: IL_005c: ldloc.1 */
    stack0_6__ = left__;
    /* Path=4, Unique=0: IL_005d: ldnull */
    stack1_3__ = NULL;
    /* Path=4, Unique=0: IL_005e: ceq */
    stack0_0__ = (stack0_6__ == ((Win32_Code_ReducibleNode*)stack1_3__)) ? 1 : 0;
    /* Path=4, Unique=0: IL_0060: stloc.s local8 */
    local4__ = stack0_0__ ? true : false;
    /* Path=4, Unique=0: IL_0062: ldloc.s local8 */
    stack0_0__ = local4__;
    /* Path=4, Unique=0: IL_0064: brfalse.s IL_006c */
    if (stack0_0__ == 0) goto IL_006c;
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(180): */
    /* Path=4, Unique=0: IL_0066: nop */
    /* Path=4, Unique=0: IL_0067: ldnull */
    stack0_1__ = NULL;
    /* Path=4, Unique=0: IL_0068: stloc.s local5 */
    local1__ = (Win32_Code_ExpressionNode*)stack0_1__;
    /* Path=4, Unique=0: IL_006a: br.s IL_00bd */
    goto IL_00bd;
IL_006c:
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(183): */
    /* Path=6, Unique=0: IL_006c: nop */
IL_006d:
    /* Path=5, Unique=0: IL_006d: ldarg.0 */
    stack0_2__ = line;
    /* Path=5, Unique=0: IL_006e: ldloc.1 */
    stack1_5__ = left__;
    /* Path=5, Unique=0: IL_006f: ldfld System.Int32 Win32.Code.AbstractNode::NextIndex */
    stack1_2__ = stack1_5__->NextIndex;
    /* Path=5, Unique=0: IL_0074: call Win32.Code.NumericNode Win32.Code.PolishNotation::ParseNumeric(System.String,System.Int32) */
    stack0_5__ = Win32_Code_PolishNotation_ParseNumeric(stack0_2__, stack1_2__);
    /* Path=5, Unique=0: IL_0079: stloc.2 */
    right__ = (Win32_Code_ReducibleNode*)stack0_5__;
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(186): */
    /* Path=5, Unique=0: IL_007a: ldloc.2 */
    stack0_6__ = right__;
    /* Path=5, Unique=0: IL_007b: ldnull */
    stack1_3__ = NULL;
    /* Path=5, Unique=0: IL_007c: ceq */
    stack0_0__ = (stack0_6__ == ((Win32_Code_ReducibleNode*)stack1_3__)) ? 1 : 0;
    /* Path=5, Unique=0: IL_007e: stloc.s local9 */
    local5__ = stack0_0__ ? true : false;
    /* Path=5, Unique=0: IL_0080: ldloc.s local9 */
    stack0_0__ = local5__;
    /* Path=5, Unique=0: IL_0082: brfalse.s IL_00a3 */
    if (stack0_0__ == 0) goto IL_00a3;
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(187): */
    /* Path=5, Unique=0: IL_0084: nop */
    /* Path=5, Unique=0: IL_0085: ldarg.0 */
    stack0_2__ = line;
    /* Path=5, Unique=0: IL_0086: ldloc.1 */
    stack1_5__ = left__;
    /* Path=5, Unique=0: IL_0087: ldfld System.Int32 Win32.Code.AbstractNode::NextIndex */
    stack1_2__ = stack1_5__->NextIndex;
    /* Path=5, Unique=0: IL_008c: call Win32.Code.ExpressionNode Win32.Code.PolishNotation::ParseExpression(System.String,System.Int32) */
    stack0_4__ = Win32_Code_PolishNotation_ParseExpression(stack0_2__, stack1_2__);
    /* Path=5, Unique=0: IL_0091: stloc.2 */
    right__ = (Win32_Code_ReducibleNode*)stack0_4__;
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(189): */
    /* Path=5, Unique=0: IL_0092: ldloc.2 */
    stack0_6__ = right__;
    /* Path=5, Unique=0: IL_0093: ldnull */
    stack1_3__ = NULL;
    /* Path=5, Unique=0: IL_0094: ceq */
    stack0_0__ = (stack0_6__ == ((Win32_Code_ReducibleNode*)stack1_3__)) ? 1 : 0;
    /* Path=5, Unique=0: IL_0096: stloc.s local10 */
    local6__ = stack0_0__ ? true : false;
    /* Path=5, Unique=0: IL_0098: ldloc.s local10 */
    stack0_0__ = local6__;
    /* Path=5, Unique=0: IL_009a: brfalse.s IL_00a2 */
    if (stack0_0__ == 0) goto IL_00a2;
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(190): */
    /* Path=5, Unique=0: IL_009c: nop */
    /* Path=5, Unique=0: IL_009d: ldnull */
    stack0_1__ = NULL;
    /* Path=5, Unique=0: IL_009e: stloc.s local5 */
    local1__ = (Win32_Code_ExpressionNode*)stack0_1__;
    /* Path=5, Unique=0: IL_00a0: br.s IL_00bd */
    goto IL_00bd;
IL_00a2:
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(193): */
    /* Path=8, Unique=0: IL_00a2: nop */
IL_00a3:
    /* Path=7, Unique=0: IL_00a3: ldarg.0 */
    stack0_2__ = line;
    /* Path=7, Unique=0: IL_00a4: ldloc.2 */
    stack1_5__ = right__;
    /* Path=7, Unique=0: IL_00a5: ldfld System.Int32 Win32.Code.AbstractNode::NextIndex */
    stack1_2__ = stack1_5__->NextIndex;
    /* Path=7, Unique=0: IL_00aa: call System.Int32 Win32.Code.PolishNotation::SkipWhiteSpace(System.String,System.Int32) */
    stack0_0__ = Win32_Code_PolishNotation_SkipWhiteSpace(stack0_2__, stack1_2__);
    /* Path=7, Unique=0: IL_00af: stloc.3 */
    index__ = stack0_0__;
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(196): */
    /* Path=7, Unique=0: IL_00b0: ldloc.0 */
    stack0_3__ = oper__;
    /* Path=7, Unique=0: IL_00b1: ldloc.1 */
    stack1_5__ = left__;
    /* Path=7, Unique=0: IL_00b2: ldloc.2 */
    stack2_0__ = right__;
    /* Path=7, Unique=0: IL_00b3: ldloc.3 */
    stack3_0__ = index__;
    /* Path=7, Unique=0: IL_00b4: newobj System.Void Win32.Code.ExpressionNode::.ctor(Win32.Code.OperatorNode,Win32.Code.ReducibleNode,Win32.Code.ReducibleNode,System.Int32) */
    stack0_4__ = il2c_get_uninitialized_object(il2c_typeof(Win32_Code_ExpressionNode));
    stack0_4__->vptr0__ = &__Win32_Code_ExpressionNode_VTABLE__;
    Win32_Code_ExpressionNode__ctor(stack0_4__, stack0_3__, stack1_5__, stack2_0__, stack3_0__);
    /* Path=7, Unique=0: IL_00b9: stloc.s local5 */
    local1__ = stack0_4__;
    /* Path=7, Unique=0: IL_00bb: br.s IL_00bd */
    goto IL_00bd;
IL_00bd:
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(197): */
    /* Path=3, Unique=0: IL_00bd: ldloc.s local5 */
    stack0_4__ = local1__;
    /* Path=3, Unique=0: IL_00bf: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return stack0_4__;
}

///////////////////////////////////////
// Main

void Win32_Code_PolishNotation_Main(void)
{
    //-------------------
    // Local variables:

    System_String* line__ = NULL;
    bool local0__;
    Win32_Code_ExpressionNode* expr__ = NULL;
    int32_t result__;
    bool local1__;
    bool local2__;
    bool local3__;

    //-------------------
    // Evaluation stacks:

    int32_t stack0_0__;
    System_String* stack0_1__ = NULL;
    Win32_Code_ExpressionNode* stack0_2__ = NULL;
    int32_t stack1_0__;
    System_String* stack1_1__ = NULL;
    IL2C_CecilHelper_PseudoZeroType* stack1_2__ = NULL;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        System_String** pline__;
        Win32_Code_ExpressionNode** pexpr__;
        System_String** pstack0_1__;
        Win32_Code_ExpressionNode** pstack0_2__;
        System_String** pstack1_1__;
        IL2C_CecilHelper_PseudoZeroType** pstack1_2__;
    } __executionFrame__;

    __executionFrame__.targetCount = 6;
    __executionFrame__.pline__ = &line__;
    __executionFrame__.pexpr__ = &expr__;
    __executionFrame__.pstack0_1__ = &stack0_1__;
    __executionFrame__.pstack0_2__ = &stack0_2__;
    __executionFrame__.pstack1_1__ = &stack1_1__;
    __executionFrame__.pstack1_2__ = &stack1_2__;
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
    stack0_1__ = string0__;
    /* Path=3, Unique=0: IL_000f: call System.Void System.Console::Write(System.String) */
    System_Console_Write_9(stack0_1__);
    /* Path=3, Unique=0: IL_0014: nop */
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(205): */
    /* Path=3, Unique=0: IL_0015: call System.String System.Console::ReadLine() */
    stack0_1__ = System_Console_ReadLine();
    /* Path=3, Unique=0: IL_001a: stloc.0 */
    line__ = stack0_1__;
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(206): */
    /* Path=3, Unique=0: IL_001b: ldloc.0 */
    stack0_1__ = line__;
    /* Path=3, Unique=0: IL_001c: call System.Boolean System.String::IsNullOrWhiteSpace(System.String) */
    stack0_0__ = System_String_IsNullOrWhiteSpace(stack0_1__);
    /* Path=3, Unique=0: IL_0021: ldc.i4.0 */
    stack1_0__ = 0;
    /* Path=3, Unique=0: IL_0022: ceq */
    stack0_0__ = (stack0_0__ == stack1_0__) ? 1 : 0;
    /* Path=3, Unique=0: IL_0024: stloc.1 */
    local0__ = stack0_0__ ? true : false;
    /* Path=3, Unique=0: IL_0025: ldloc.1 */
    stack0_0__ = local0__;
    /* Path=3, Unique=0: IL_0026: brfalse.s IL_0077 */
    if (stack0_0__ == 0) goto IL_0077;
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(207): */
    /* Path=3, Unique=0: IL_0028: nop */
    /* Path=3, Unique=0: IL_0029: ldloc.0 */
    stack0_1__ = line__;
    /* Path=3, Unique=0: IL_002a: ldstr "exit" */
    stack1_1__ = string1__;
    /* Path=3, Unique=0: IL_002f: call System.Boolean System.String::op_Equality(System.String,System.String) */
    stack0_0__ = System_String_op_Equality(stack0_1__, stack1_1__);
    /* Path=3, Unique=0: IL_0034: stloc.s local4 */
    local1__ = stack0_0__ ? true : false;
    /* Path=3, Unique=0: IL_0036: ldloc.s local4 */
    stack0_0__ = local1__;
    /* Path=3, Unique=0: IL_0038: brfalse.s IL_003d */
    if (stack0_0__ == 0) goto IL_003d;
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(209): */
    /* Path=3, Unique=0: IL_003a: nop */
    /* Path=3, Unique=0: IL_003b: br.s IL_007d */
    goto IL_007d;
IL_003d:
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(213): */
    /* Path=5, Unique=0: IL_003d: ldloc.0 */
    stack0_1__ = line__;
    /* Path=5, Unique=0: IL_003e: ldc.i4.0 */
    stack1_0__ = 0;
    /* Path=5, Unique=0: IL_003f: call Win32.Code.ExpressionNode Win32.Code.PolishNotation::ParseExpression(System.String,System.Int32) */
    stack0_2__ = Win32_Code_PolishNotation_ParseExpression(stack0_1__, stack1_0__);
    /* Path=5, Unique=0: IL_0044: stloc.2 */
    expr__ = stack0_2__;
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(214): */
    /* Path=5, Unique=0: IL_0045: ldloc.2 */
    stack0_2__ = expr__;
    /* Path=5, Unique=0: IL_0046: ldnull */
    stack1_2__ = NULL;
    /* Path=5, Unique=0: IL_0047: ceq */
    stack0_0__ = (stack0_2__ == ((Win32_Code_ExpressionNode*)stack1_2__)) ? 1 : 0;
    /* Path=5, Unique=0: IL_0049: stloc.s local5 */
    local2__ = stack0_0__ ? true : false;
    /* Path=5, Unique=0: IL_004b: ldloc.s local5 */
    stack0_0__ = local2__;
    /* Path=5, Unique=0: IL_004d: brfalse.s IL_005d */
    if (stack0_0__ == 0) goto IL_005d;
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(215): */
    /* Path=5, Unique=0: IL_004f: nop */
    /* Path=5, Unique=0: IL_0050: ldstr "Syntax error." */
    stack0_1__ = string2__;
    /* Path=5, Unique=0: IL_0055: call System.Void System.Console::WriteLine(System.String) */
    System_Console_WriteLine_10(stack0_1__);
    /* Path=5, Unique=0: IL_005a: nop */
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(217): */
    /* Path=5, Unique=0: IL_005b: br.s IL_0078 */
    goto IL_0078;
IL_005d:
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(220): */
    /* Path=7, Unique=0: IL_005d: ldloc.2 */
    stack0_2__ = expr__;
    /* Path=7, Unique=0: IL_005e: callvirt System.Int32 Win32.Code.ReducibleNode::Reduce() */
    stack0_0__ = Win32_Code_ReducibleNode_Reduce((Win32_Code_ReducibleNode*)stack0_2__);
    /* Path=7, Unique=0: IL_0063: stloc.3 */
    result__ = stack0_0__;
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(222): */
    /* Path=7, Unique=0: IL_0064: ldstr "Reuslt=" */
    stack0_1__ = string3__;
    /* Path=7, Unique=0: IL_0069: call System.Void System.Console::Write(System.String) */
    System_Console_Write_9(stack0_1__);
    /* Path=7, Unique=0: IL_006e: nop */
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(223): */
    /* Path=7, Unique=0: IL_006f: ldloc.3 */
    stack0_0__ = result__;
    /* Path=7, Unique=0: IL_0070: call System.Void System.Console::WriteLine(System.Int32) */
    System_Console_WriteLine_6(stack0_0__);
    /* Path=7, Unique=0: IL_0075: nop */
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\PolishNotation.cs(224): */
    /* Path=7, Unique=0: IL_0076: nop */
IL_0077:
    /* Path=4, Unique=0: IL_0077: nop */
IL_0078:
    /* Path=2, Unique=0: IL_0078: ldc.i4.1 */
    stack0_0__ = 1;
    /* Path=2, Unique=0: IL_0079: stloc.s local6 */
    local3__ = stack0_0__ ? true : false;
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

    Win32_Code_PolishNotation* stack0_0__ = NULL;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        Win32_Code_PolishNotation** pstack0_0__;
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
void* __Win32_Code_PolishNotation_IL2C_RuntimeCast__(Win32_Code_PolishNotation* this__, IL2C_RUNTIME_TYPE_DECL* type)
{
    // This type
    if (type == il2c_typeof(Win32_Code_PolishNotation)) return this__;

    // Delegate checking base types
    return __System_Object_IL2C_RuntimeCast__((System_Object*)this__, type);
}

// GC's mark handler
void __Win32_Code_PolishNotation_IL2C_MarkHandler__(Win32_Code_PolishNotation* this__)
{

    /* Suppressed invoke base mark handler */
}

// Vtable of Win32.Code.PolishNotation
__Win32_Code_PolishNotation_VTABLE_DECL__ __Win32_Code_PolishNotation_VTABLE__ = {
    /* internalcall */ __Win32_Code_PolishNotation_IL2C_RuntimeCast__,
    (void*)__System_Object_ToString__,
    (void*)__System_Object_GetHashCode__,
    (void*)__System_Object_Finalize__,
    (void*)__System_Object_Equals__,
};

// Runtime type information
IL2C_RUNTIME_TYPE_DECL __Win32_Code_PolishNotation_RUNTIME_TYPE__ = {
    "Win32.Code.PolishNotation",
    sizeof(Win32_Code_PolishNotation),
    /* internalcall */ (void*)__Win32_Code_PolishNotation_IL2C_MarkHandler__,
};

////////////////////////////////////////////////////////////
// Type: Win32.Code.StringTest

///////////////////////////////////////
// LiteralString

void Win32_Code_StringTest_LiteralString(void)
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

/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\StringTest.cs(12): */
    /* Path=1, Unique=0: IL_0000: nop */
    /* Path=1, Unique=0: IL_0001: ldstr "ABC" */
    stack0_0__ = string4__;
    /* Path=1, Unique=0: IL_0006: stloc.0 */
    a__ = stack0_0__;
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

/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\StringTest.cs(17): */
    /* Path=1, Unique=0: IL_0000: nop */
    /* Path=1, Unique=0: IL_0001: ldarg.0 */
    stack0_0__ = a;
    /* Path=1, Unique=0: IL_0002: stloc.0 */
    local__ = stack0_0__;
    /* Path=1, Unique=0: IL_0003: br.s IL_0005 */
    goto IL_0005;
IL_0005:
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\StringTest.cs(19): */
    /* Path=2, Unique=0: IL_0005: ldloc.0 */
    stack0_0__ = local__;
    /* Path=2, Unique=0: IL_0006: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return stack0_0__;
}

///////////////////////////////////////
// LiteralCombinedString

System_String* Win32_Code_StringTest_LiteralCombinedString(void)
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

/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\StringTest.cs(22): */
    /* Path=1, Unique=0: IL_0000: nop */
    /* Path=1, Unique=0: IL_0001: ldstr "ABC" */
    stack0_0__ = string4__;
    /* Path=1, Unique=0: IL_0006: stloc.0 */
    a__ = stack0_0__;
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\StringTest.cs(24): */
    /* Path=1, Unique=0: IL_0007: ldstr "DEF" */
    stack0_0__ = string5__;
    /* Path=1, Unique=0: IL_000c: stloc.1 */
    b__ = stack0_0__;
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\StringTest.cs(25): */
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
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\StringTest.cs(26): */
    /* Path=2, Unique=0: IL_0017: ldloc.2 */
    stack0_0__ = local__;
    /* Path=2, Unique=0: IL_0018: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return stack0_0__;
}

///////////////////////////////////////
// LiteralSubstring

System_String* Win32_Code_StringTest_LiteralSubstring(void)
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

/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\StringTest.cs(29): */
    /* Path=1, Unique=0: IL_0000: nop */
    /* Path=1, Unique=0: IL_0001: ldstr "ABCDEFGHIJKLMN" */
    stack0_0__ = string6__;
    /* Path=1, Unique=0: IL_0006: stloc.0 */
    a__ = stack0_0__;
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\StringTest.cs(31): */
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
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\StringTest.cs(32): */
    /* Path=2, Unique=0: IL_0011: ldloc.1 */
    stack0_0__ = local__;
    /* Path=2, Unique=0: IL_0012: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return stack0_0__;
}

///////////////////////////////////////
// GetChar

wchar_t Win32_Code_StringTest_GetChar(void)
{
    //-------------------
    // Local variables:

    wchar_t local__;

    //-------------------
    // Evaluation stacks:

    int32_t stack0_0__;

    //-------------------
    // IL body:

/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\StringTest.cs(35): */
    /* Path=1, Unique=0: IL_0000: nop */
    /* Path=1, Unique=0: IL_0001: ldc.i4.s 65 */
    stack0_0__ = 65;
    /* Path=1, Unique=0: IL_0003: stloc.0 */
    local__ = (wchar_t)stack0_0__;
    /* Path=1, Unique=0: IL_0004: br.s IL_0006 */
    goto IL_0006;
IL_0006:
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\StringTest.cs(37): */
    /* Path=2, Unique=0: IL_0006: ldloc.0 */
    stack0_0__ = local__;
    /* Path=2, Unique=0: IL_0007: ret */
    return (wchar_t)stack0_0__;
}

///////////////////////////////////////
// GetCharByIndex

wchar_t Win32_Code_StringTest_GetCharByIndex(System_String* str, int32_t index)
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

/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\StringTest.cs(40): */
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
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\StringTest.cs(42): */
    /* Path=2, Unique=0: IL_000b: ldloc.0 */
    stack0_2__ = local__;
    /* Path=2, Unique=0: IL_000c: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return (wchar_t)stack0_2__;
}

///////////////////////////////////////
// GetString

System_String* Win32_Code_StringTest_GetString(void)
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

/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\StringTest.cs(45): */
    /* Path=1, Unique=0: IL_0000: nop */
    /* Path=1, Unique=0: IL_0001: ldstr "ABC" */
    stack0_0__ = string4__;
    /* Path=1, Unique=0: IL_0006: callvirt System.String System.Object::ToString() */
    stack0_1__ = System_Object_ToString((System_Object*)stack0_0__);
    /* Path=1, Unique=0: IL_000b: stloc.0 */
    local__ = stack0_1__;
    /* Path=1, Unique=0: IL_000c: br.s IL_000e */
    goto IL_000e;
IL_000e:
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\StringTest.cs(47): */
    /* Path=2, Unique=0: IL_000e: ldloc.0 */
    stack0_0__ = local__;
    /* Path=2, Unique=0: IL_000f: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return stack0_0__;
}

///////////////////////////////////////
// .ctor

void Win32_Code_StringTest__ctor(Win32_Code_StringTest* this__)
{
    //-------------------
    // Local variables:


    //-------------------
    // Evaluation stacks:

    Win32_Code_StringTest* stack0_0__ = NULL;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        Win32_Code_StringTest** pstack0_0__;
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
void* __Win32_Code_StringTest_IL2C_RuntimeCast__(Win32_Code_StringTest* this__, IL2C_RUNTIME_TYPE_DECL* type)
{
    // This type
    if (type == il2c_typeof(Win32_Code_StringTest)) return this__;

    // Delegate checking base types
    return __System_Object_IL2C_RuntimeCast__((System_Object*)this__, type);
}

// GC's mark handler
void __Win32_Code_StringTest_IL2C_MarkHandler__(Win32_Code_StringTest* this__)
{

    /* Suppressed invoke base mark handler */
}

// Vtable of Win32.Code.StringTest
__Win32_Code_StringTest_VTABLE_DECL__ __Win32_Code_StringTest_VTABLE__ = {
    /* internalcall */ __Win32_Code_StringTest_IL2C_RuntimeCast__,
    (void*)__System_Object_ToString__,
    (void*)__System_Object_GetHashCode__,
    (void*)__System_Object_Finalize__,
    (void*)__System_Object_Equals__,
};

// Runtime type information
IL2C_RUNTIME_TYPE_DECL __Win32_Code_StringTest_RUNTIME_TYPE__ = {
    "Win32.Code.StringTest",
    sizeof(Win32_Code_StringTest),
    /* internalcall */ (void*)__Win32_Code_StringTest_IL2C_MarkHandler__,
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

    Win32_Code_UnsafeTest* stack0_0__ = NULL;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        Win32_Code_UnsafeTest** pstack0_0__;
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
void* __Win32_Code_UnsafeTest_IL2C_RuntimeCast__(Win32_Code_UnsafeTest* this__, IL2C_RUNTIME_TYPE_DECL* type)
{
    // This type
    if (type == il2c_typeof(Win32_Code_UnsafeTest)) return this__;

    // Delegate checking base types
    return __System_Object_IL2C_RuntimeCast__((System_Object*)this__, type);
}

// GC's mark handler
void __Win32_Code_UnsafeTest_IL2C_MarkHandler__(Win32_Code_UnsafeTest* this__)
{

    /* Suppressed invoke base mark handler */
}

// Vtable of Win32.Code.UnsafeTest
__Win32_Code_UnsafeTest_VTABLE_DECL__ __Win32_Code_UnsafeTest_VTABLE__ = {
    /* internalcall */ __Win32_Code_UnsafeTest_IL2C_RuntimeCast__,
    (void*)__System_Object_ToString__,
    (void*)__System_Object_GetHashCode__,
    (void*)__System_Object_Finalize__,
    (void*)__System_Object_Equals__,
};

// Runtime type information
IL2C_RUNTIME_TYPE_DECL __Win32_Code_UnsafeTest_RUNTIME_TYPE__ = {
    "Win32.Code.UnsafeTest",
    sizeof(Win32_Code_UnsafeTest),
    /* internalcall */ (void*)__Win32_Code_UnsafeTest_IL2C_MarkHandler__,
};

////////////////////////////////////////////////////////////
// Type: Win32.Code.ValueTypeTestTarget

///////////////////////////////////////
// GetValue2

int32_t Win32_Code_ValueTypeTestTarget_GetValue2(Win32_Code_ValueTypeTestTarget* this__, int32_t a, int32_t b)
{
    //-------------------
    // Local variables:

    int32_t local__;

    //-------------------
    // Evaluation stacks:

    Win32_Code_ValueTypeTestTarget* stack0_0__ = NULL;
    int32_t stack0_1__;
    int32_t stack1_0__;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        Win32_Code_ValueTypeTestTarget** pstack0_0__;
    } __executionFrame__;

    __executionFrame__.targetCount = 1;
    __executionFrame__.pstack0_0__ = &stack0_0__;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\ValueTypeTest.cs(15): */
    /* Path=1, Unique=0: IL_0000: nop */
    /* Path=1, Unique=0: IL_0001: ldarg.0 */
    stack0_0__ = this__;
    /* Path=1, Unique=0: IL_0002: ldfld System.Int32 Win32.Code.ValueTypeTestTarget::Value2 */
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
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\ValueTypeTest.cs(17): */
    /* Path=2, Unique=0: IL_000e: ldloc.0 */
    stack0_1__ = local__;
    /* Path=2, Unique=0: IL_000f: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return stack0_1__;
}

//////////////////////
// Runtime helpers:

// Runtime cast
void* __Win32_Code_ValueTypeTestTarget_IL2C_RuntimeCast__(Win32_Code_ValueTypeTestTarget* this__, IL2C_RUNTIME_TYPE_DECL* type)
{
    // This type
    if (type == il2c_typeof(Win32_Code_ValueTypeTestTarget)) return this__;

    // Delegate checking base types
    return __System_ValueType_IL2C_RuntimeCast__((System_ValueType*)this__, type);
}

// GC's mark handler
void __Win32_Code_ValueTypeTestTarget_IL2C_MarkHandler__(Win32_Code_ValueTypeTestTarget* this__)
{
    // Try marking each object reference fields
    il2c_try_mark_from_handler(this__->OR2);

    /* Suppressed invoke base mark handler */
}

// Vtable of Win32.Code.ValueTypeTestTarget
__Win32_Code_ValueTypeTestTarget_VTABLE_DECL__ __Win32_Code_ValueTypeTestTarget_VTABLE__ = {
    /* internalcall */ __Win32_Code_ValueTypeTestTarget_IL2C_RuntimeCast__,
    (void*)__System_ValueType_ToString__,
    (void*)__System_ValueType_GetHashCode__,
    (void*)__System_Object_Finalize__,
    (void*)__System_ValueType_Equals__,
};

// Runtime type information
IL2C_RUNTIME_TYPE_DECL __Win32_Code_ValueTypeTestTarget_RUNTIME_TYPE__ = {
    "Win32.Code.ValueTypeTestTarget",
    sizeof(Win32_Code_ValueTypeTestTarget),
    /* internalcall */ (void*)__Win32_Code_ValueTypeTestTarget_IL2C_MarkHandler__,
};

////////////////////////////////////////////////////////////
// Type: Win32.Code.ValueTypeTest

///////////////////////////////////////
// Test4

int32_t Win32_Code_ValueTypeTest_Test4(void)
{
    //-------------------
    // Local variables:

    Win32_Code_ValueTypeTestTarget hoge3__;
    int32_t local__;

    //-------------------
    // Evaluation stacks:

    Win32_Code_ValueTypeTestTarget* stack0_0__ = NULL;
    Win32_Code_ValueTypeTestTarget* stack0_1__ = NULL;
    Win32_Code_ValueTypeTestTarget stack0_2__;
    int32_t stack0_3__;
    int32_t stack1_0__;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        Win32_Code_ValueTypeTestTarget** pstack0_0__;
        Win32_Code_ValueTypeTestTarget** pstack0_1__;
    } __executionFrame__;

    __executionFrame__.targetCount = 2;
    __executionFrame__.pstack0_0__ = &stack0_0__;
    __executionFrame__.pstack0_1__ = &stack0_1__;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\ValueTypeTest.cs(23): */
    /* Path=1, Unique=0: IL_0000: nop */
    /* Path=1, Unique=0: IL_0001: ldloca.s local0 */
    stack0_0__ = &hoge3__;
    /* Path=1, Unique=0: IL_0003: initobj Win32.Code.ValueTypeTestTarget */
    memset(stack0_0__, 0x00, sizeof(Win32_Code_ValueTypeTestTarget));
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\ValueTypeTest.cs(25): */
    /* Path=1, Unique=0: IL_0009: ldloca.s local0 */
    stack0_1__ = &hoge3__;
    /* Path=1, Unique=0: IL_000b: ldc.i4 456 */
    stack1_0__ = 456;
    /* Path=1, Unique=0: IL_0010: stfld System.Int32 Win32.Code.ValueTypeTestTarget::Value2 */
    stack0_1__->Value2 = stack1_0__;
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\ValueTypeTest.cs(27): */
    /* Path=1, Unique=0: IL_0015: ldloc.0 */
    stack0_2__ = hoge3__;
    /* Path=1, Unique=0: IL_0016: ldfld System.Int32 Win32.Code.ValueTypeTestTarget::Value2 */
    stack0_3__ = stack0_2__.Value2;
    /* Path=1, Unique=0: IL_001b: stloc.1 */
    local__ = stack0_3__;
    /* Path=1, Unique=0: IL_001c: br.s IL_001e */
    goto IL_001e;
IL_001e:
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\ValueTypeTest.cs(28): */
    /* Path=2, Unique=0: IL_001e: ldloc.1 */
    stack0_3__ = local__;
    /* Path=2, Unique=0: IL_001f: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return stack0_3__;
}

///////////////////////////////////////
// Test5

int32_t Win32_Code_ValueTypeTest_Test5(void)
{
    //-------------------
    // Local variables:

    Win32_Code_ValueTypeTestTarget hoge3__;
    int32_t result__;
    int32_t local__;

    //-------------------
    // Evaluation stacks:

    Win32_Code_ValueTypeTestTarget* stack0_0__ = NULL;
    Win32_Code_ValueTypeTestTarget* stack0_1__ = NULL;
    Win32_Code_ValueTypeTestTarget* stack0_2__ = NULL;
    int32_t stack0_3__;
    int32_t stack1_0__;
    int32_t stack2_0__;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        Win32_Code_ValueTypeTestTarget** pstack0_0__;
        Win32_Code_ValueTypeTestTarget** pstack0_1__;
        Win32_Code_ValueTypeTestTarget** pstack0_2__;
    } __executionFrame__;

    __executionFrame__.targetCount = 3;
    __executionFrame__.pstack0_0__ = &stack0_0__;
    __executionFrame__.pstack0_1__ = &stack0_1__;
    __executionFrame__.pstack0_2__ = &stack0_2__;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\ValueTypeTest.cs(31): */
    /* Path=1, Unique=0: IL_0000: nop */
    /* Path=1, Unique=0: IL_0001: ldloca.s local0 */
    stack0_0__ = &hoge3__;
    /* Path=1, Unique=0: IL_0003: initobj Win32.Code.ValueTypeTestTarget */
    memset(stack0_0__, 0x00, sizeof(Win32_Code_ValueTypeTestTarget));
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\ValueTypeTest.cs(33): */
    /* Path=1, Unique=0: IL_0009: ldloca.s local0 */
    stack0_1__ = &hoge3__;
    /* Path=1, Unique=0: IL_000b: ldc.i4 789 */
    stack1_0__ = 789;
    /* Path=1, Unique=0: IL_0010: stfld System.Int32 Win32.Code.ValueTypeTestTarget::Value2 */
    stack0_1__->Value2 = stack1_0__;
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\ValueTypeTest.cs(35): */
    /* Path=1, Unique=0: IL_0015: ldloca.s local0 */
    stack0_2__ = &hoge3__;
    /* Path=1, Unique=0: IL_0017: ldc.i4.s 123 */
    stack1_0__ = 123;
    /* Path=1, Unique=0: IL_0019: ldc.i4 456 */
    stack2_0__ = 456;
    /* Path=1, Unique=0: IL_001e: call System.Int32 Win32.Code.ValueTypeTestTarget::GetValue2(System.Int32,System.Int32) */
    stack0_3__ = Win32_Code_ValueTypeTestTarget_GetValue2(stack0_2__, stack1_0__, stack2_0__);
    /* Path=1, Unique=0: IL_0023: stloc.1 */
    result__ = stack0_3__;
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\ValueTypeTest.cs(36): */
    /* Path=1, Unique=0: IL_0024: ldloc.1 */
    stack0_3__ = result__;
    /* Path=1, Unique=0: IL_0025: stloc.2 */
    local__ = stack0_3__;
    /* Path=1, Unique=0: IL_0026: br.s IL_0028 */
    goto IL_0028;
IL_0028:
/* D:\\PROJECT\\IL2C\\samples\\Win32\\Win32.Code\\ValueTypeTest.cs(37): */
    /* Path=2, Unique=0: IL_0028: ldloc.2 */
    stack0_3__ = local__;
    /* Path=2, Unique=0: IL_0029: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return stack0_3__;
}

///////////////////////////////////////
// .ctor

void Win32_Code_ValueTypeTest__ctor(Win32_Code_ValueTypeTest* this__)
{
    //-------------------
    // Local variables:


    //-------------------
    // Evaluation stacks:

    Win32_Code_ValueTypeTest* stack0_0__ = NULL;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        Win32_Code_ValueTypeTest** pstack0_0__;
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
void* __Win32_Code_ValueTypeTest_IL2C_RuntimeCast__(Win32_Code_ValueTypeTest* this__, IL2C_RUNTIME_TYPE_DECL* type)
{
    // This type
    if (type == il2c_typeof(Win32_Code_ValueTypeTest)) return this__;

    // Delegate checking base types
    return __System_Object_IL2C_RuntimeCast__((System_Object*)this__, type);
}

// GC's mark handler
void __Win32_Code_ValueTypeTest_IL2C_MarkHandler__(Win32_Code_ValueTypeTest* this__)
{

    /* Suppressed invoke base mark handler */
}

// Vtable of Win32.Code.ValueTypeTest
__Win32_Code_ValueTypeTest_VTABLE_DECL__ __Win32_Code_ValueTypeTest_VTABLE__ = {
    /* internalcall */ __Win32_Code_ValueTypeTest_IL2C_RuntimeCast__,
    (void*)__System_Object_ToString__,
    (void*)__System_Object_GetHashCode__,
    (void*)__System_Object_Finalize__,
    (void*)__System_Object_Equals__,
};

// Runtime type information
IL2C_RUNTIME_TYPE_DECL __Win32_Code_ValueTypeTest_RUNTIME_TYPE__ = {
    "Win32.Code.ValueTypeTest",
    sizeof(Win32_Code_ValueTypeTest),
    /* internalcall */ (void*)__Win32_Code_ValueTypeTest_IL2C_MarkHandler__,
};
