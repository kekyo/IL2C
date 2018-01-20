#include "UEFI.Code.h"

//////////////////////////////////////////////////////////////////////////////////
// Const strings:

__DEFINE_CONST_STRING__(__string0, L"RPN> ");

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
// Type: UEFI.Code.Expression

//////////////////////
// Runtime helpers:

static void __UEFI_Code_Expression_MARK_HANDLER__(void* pReference)
{
    __TRY_MARK_FROM_HANDLER__(((UEFI_Code_Expression*)pReference)->Lhs);
    __TRY_MARK_FROM_HANDLER__(((UEFI_Code_Expression*)pReference)->Rhs);
    __typeof__(System_Object)->pMarkHandler(pReference);
}

static __RUNTIME_TYPE_DEF__ __UEFI_Code_Expression_RUNTIME_TYPE_DEF__ = {
    "UEFI.Code.Expression",
    sizeof(UEFI_Code_Expression),
    __UEFI_Code_Expression_MARK_HANDLER__ };
const __RUNTIME_TYPE__ __UEFI_Code_Expression_RUNTIME_TYPE__ = &__UEFI_Code_Expression_RUNTIME_TYPE_DEF__;

///////////////////////////////////////
// .ctor

void UEFI_Code_Expression__ctor(UEFI_Code_Expression* __this, UEFI_Code_Expression* lhs, UEFI_Code_Expression* rhs, wchar_t oper)
{
    //-------------------
    // Local variables:


    //-------------------
    // Evaluation stacks:

    UEFI_Code_Expression* __stack0_0 = NULL;
    UEFI_Code_Expression* __stack1_0 = NULL;
    int32_t __stack1_1;

    //-------------------
    // Setup stack frame:

    struct /* __EXECUTION_FRAME__ */
    {
        __EXECUTION_FRAME__* pNext;
        uint8_t targetCount;
        UEFI_Code_Expression** p__stack0_0;
        UEFI_Code_Expression** p__stack1_0;
    } __executionFrame__;

    __executionFrame__.targetCount = 2;
    __executionFrame__.p__stack0_0 = &__stack0_0;
    __executionFrame__.p__stack1_0 = &__stack1_0;
    __gc_link_execution_frame__(&__executionFrame__);

    //-------------------
    // IL body:

#line 15 "D:\\PROJECT\\IL2C\\tests\\UEFI\\UEFI.Code\\ReversePolishNotation.cs"
    __stack0_0 = __this;
    System_Object__ctor((System_Object*)__stack0_0);
#line 16 "D:\\PROJECT\\IL2C\\tests\\UEFI\\UEFI.Code\\ReversePolishNotation.cs"
#line 17 "D:\\PROJECT\\IL2C\\tests\\UEFI\\UEFI.Code\\ReversePolishNotation.cs"
    __stack0_0 = __this;
    __stack1_0 = lhs;
    __stack0_0->Lhs = __stack1_0;
#line 18 "D:\\PROJECT\\IL2C\\tests\\UEFI\\UEFI.Code\\ReversePolishNotation.cs"
    __stack0_0 = __this;
    __stack1_0 = rhs;
    __stack0_0->Rhs = __stack1_0;
#line 19 "D:\\PROJECT\\IL2C\\tests\\UEFI\\UEFI.Code\\ReversePolishNotation.cs"
    __stack0_0 = __this;
    __stack1_1 = (int32_t)(oper);
    __stack0_0->Oper = (wchar_t)__stack1_1;
#line 20 "D:\\PROJECT\\IL2C\\tests\\UEFI\\UEFI.Code\\ReversePolishNotation.cs"
    __gc_unlink_execution_frame__(&__executionFrame__);
    return;
}

////////////////////////////////////////////////////////////
// Type: UEFI.Code.ReversePolishNotation

//////////////////////
// Runtime helpers:

static void __UEFI_Code_ReversePolishNotation_MARK_HANDLER__(void* pReference)
{
    __typeof__(System_Object)->pMarkHandler(pReference);
}

static __RUNTIME_TYPE_DEF__ __UEFI_Code_ReversePolishNotation_RUNTIME_TYPE_DEF__ = {
    "UEFI.Code.ReversePolishNotation",
    0,
    __UEFI_Code_ReversePolishNotation_MARK_HANDLER__ };
const __RUNTIME_TYPE__ __UEFI_Code_ReversePolishNotation_RUNTIME_TYPE__ = &__UEFI_Code_ReversePolishNotation_RUNTIME_TYPE_DEF__;

///////////////////////////////////////
// Parse

UEFI_Code_Expression* UEFI_Code_ReversePolishNotation_Parse(System_String* line, int32_t startIndex)
{
    //-------------------
    // Local variables:

    int32_t local0;
    bool local1;
    UEFI_Code_Expression* local2 = NULL;

    //-------------------
    // Evaluation stacks:

    int32_t __stack0_0;
    IL2C_CecilHelper_PseudoZeroType* __stack0_1 = NULL;
    UEFI_Code_Expression* __stack0_2 = NULL;
    System_String* __stack1_0 = NULL;
    int32_t __stack1_1;

    //-------------------
    // Setup stack frame:

    struct /* __EXECUTION_FRAME__ */
    {
        __EXECUTION_FRAME__* pNext;
        uint8_t targetCount;
        UEFI_Code_Expression** plocal2;
        IL2C_CecilHelper_PseudoZeroType** p__stack0_1;
        UEFI_Code_Expression** p__stack0_2;
        System_String** p__stack1_0;
    } __executionFrame__;

    __executionFrame__.targetCount = 4;
    __executionFrame__.plocal2 = &local2;
    __executionFrame__.p__stack0_1 = &__stack0_1;
    __executionFrame__.p__stack0_2 = &__stack0_2;
    __executionFrame__.p__stack1_0 = &__stack1_0;
    __gc_link_execution_frame__(&__executionFrame__);

    //-------------------
    // IL body:

#line 26 "D:\\PROJECT\\IL2C\\tests\\UEFI\\UEFI.Code\\ReversePolishNotation.cs"
#line 27 "D:\\PROJECT\\IL2C\\tests\\UEFI\\UEFI.Code\\ReversePolishNotation.cs"
    __stack0_0 = startIndex;
    local0 = __stack0_0;
    goto L_0000;
#line 28 "D:\\PROJECT\\IL2C\\tests\\UEFI\\UEFI.Code\\ReversePolishNotation.cs"
L_0000:
    __stack0_0 = local0;
    __stack1_0 = line;
    __stack1_1 = System_String_get_Length(__stack1_0);
    __stack0_0 = (__stack0_0 < __stack1_1) ? 1 : 0;
    local1 = __stack0_0 ? true : false;
    __stack0_0 = local1;
    if (__stack0_0 != 0) goto L_0001;
#line 32 "D:\\PROJECT\\IL2C\\tests\\UEFI\\UEFI.Code\\ReversePolishNotation.cs"
    __stack0_1 = NULL;
    local2 = (UEFI_Code_Expression*)__stack0_1;
    goto L_0002;
#line 29 "D:\\PROJECT\\IL2C\\tests\\UEFI\\UEFI.Code\\ReversePolishNotation.cs"
L_0001:
#line 31 "D:\\PROJECT\\IL2C\\tests\\UEFI\\UEFI.Code\\ReversePolishNotation.cs"
#line 33 "D:\\PROJECT\\IL2C\\tests\\UEFI\\UEFI.Code\\ReversePolishNotation.cs"
L_0002:
    __stack0_2 = local2;
    __gc_unlink_execution_frame__(&__executionFrame__);
    return __stack0_2;
}

///////////////////////////////////////
// Main

void UEFI_Code_ReversePolishNotation_Main(void)
{
    //-------------------
    // Local variables:

    System_String* local0 = NULL;
    bool local1;
    UEFI_Code_Expression* local2 = NULL;
    bool local3;

    //-------------------
    // Evaluation stacks:

    int32_t __stack0_0;
    System_String* __stack0_1 = NULL;
    UEFI_Code_Expression* __stack0_2 = NULL;
    int32_t __stack1_0;

    //-------------------
    // Setup stack frame:

    struct /* __EXECUTION_FRAME__ */
    {
        __EXECUTION_FRAME__* pNext;
        uint8_t targetCount;
        System_String** plocal0;
        UEFI_Code_Expression** plocal2;
        System_String** p__stack0_1;
        UEFI_Code_Expression** p__stack0_2;
    } __executionFrame__;

    __executionFrame__.targetCount = 4;
    __executionFrame__.plocal0 = &local0;
    __executionFrame__.plocal2 = &local2;
    __executionFrame__.p__stack0_1 = &__stack0_1;
    __executionFrame__.p__stack0_2 = &__stack0_2;
    __gc_link_execution_frame__(&__executionFrame__);

    //-------------------
    // IL body:

#line 36 "D:\\PROJECT\\IL2C\\tests\\UEFI\\UEFI.Code\\ReversePolishNotation.cs"
    goto L_0000;
#line 37 "D:\\PROJECT\\IL2C\\tests\\UEFI\\UEFI.Code\\ReversePolishNotation.cs"
L_0000:
    __stack0_0 = 1;
    local3 = __stack0_0 ? true : false;
    goto L_0001;
#line 38 "D:\\PROJECT\\IL2C\\tests\\UEFI\\UEFI.Code\\ReversePolishNotation.cs"
L_0001:
#line 39 "D:\\PROJECT\\IL2C\\tests\\UEFI\\UEFI.Code\\ReversePolishNotation.cs"
    __stack0_1 = __string0 /* "RPN> " */;
    System_Console_Write_9(__stack0_1);
#line 40 "D:\\PROJECT\\IL2C\\tests\\UEFI\\UEFI.Code\\ReversePolishNotation.cs"
    __stack0_1 = System_Console_ReadLine();
    local0 = __stack0_1;
#line 41 "D:\\PROJECT\\IL2C\\tests\\UEFI\\UEFI.Code\\ReversePolishNotation.cs"
    __stack0_1 = local0;
    __stack0_0 = System_String_IsNullOrWhiteSpace(__stack0_1);
    __stack1_0 = 0;
    __stack0_0 = (__stack0_0 == __stack1_0) ? 1 : 0;
    local1 = __stack0_0 ? true : false;
    __stack0_0 = local1;
    if (__stack0_0 == 0) goto L_0002;
#line 42 "D:\\PROJECT\\IL2C\\tests\\UEFI\\UEFI.Code\\ReversePolishNotation.cs"
#line 43 "D:\\PROJECT\\IL2C\\tests\\UEFI\\UEFI.Code\\ReversePolishNotation.cs"
    __stack0_1 = local0;
    __stack1_0 = 0;
    __stack0_2 = UEFI_Code_ReversePolishNotation_Parse(__stack0_1, __stack1_0);
    local2 = __stack0_2;
#line 44 "D:\\PROJECT\\IL2C\\tests\\UEFI\\UEFI.Code\\ReversePolishNotation.cs"
#line 45 "D:\\PROJECT\\IL2C\\tests\\UEFI\\UEFI.Code\\ReversePolishNotation.cs"
L_0002:
}

///////////////////////////////////////
// .ctor

void UEFI_Code_ReversePolishNotation__ctor(UEFI_Code_ReversePolishNotation* __this)
{
    //-------------------
    // Local variables:


    //-------------------
    // Evaluation stacks:

    UEFI_Code_ReversePolishNotation* __stack0_0 = NULL;

    //-------------------
    // Setup stack frame:

    struct /* __EXECUTION_FRAME__ */
    {
        __EXECUTION_FRAME__* pNext;
        uint8_t targetCount;
        UEFI_Code_ReversePolishNotation** p__stack0_0;
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
