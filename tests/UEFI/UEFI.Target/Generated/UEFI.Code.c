#include "UEFI.Code.h"

//////////////////////////////////////////////////////////////////////////////////
// Const strings:

IL2C_CONST_STRING(__string0, L"PN> ");
IL2C_CONST_STRING(__string1, L"Syntax error.");
IL2C_CONST_STRING(__string2, L"Reuslt=");

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
// Type: UEFI.Code.AbstractNode

///////////////////////////////////////
// .ctor

void UEFI_Code_AbstractNode__ctor(UEFI_Code_AbstractNode* this__, int32_t nextIndex)
{
    //-------------------
    // Local variables:


    //-------------------
    // Evaluation stacks:

    UEFI_Code_AbstractNode* __stack0_0 = NULL;
    int32_t __stack1_0;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        UEFI_Code_AbstractNode** p__stack0_0;
    } __executionFrame__;

    __executionFrame__.targetCount = 1;
    __executionFrame__.p__stack0_0 = &__stack0_0;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

#line 13 "D:\\PROJECT\\IL2C\\tests\\UEFI\\UEFI.Code\\PolishNotation.cs"
    /* Path=1, Unique=0: IL_0000: ldarg.0 */
    __stack0_0 = this__;
    /* Path=1, Unique=0: IL_0001: call System.Void System.Object::.ctor() */
    System_Object__ctor((System_Object*)__stack0_0);
#line 15 "D:\\PROJECT\\IL2C\\tests\\UEFI\\UEFI.Code\\PolishNotation.cs"
    /* Path=1, Unique=0: IL_0006: ldarg.0 */
    __stack0_0 = this__;
    /* Path=1, Unique=0: IL_0007: ldarg.1 */
    __stack1_0 = nextIndex;
    /* Path=1, Unique=0: IL_0008: stfld System.Int32 UEFI.Code.AbstractNode::NextIndex */
    __stack0_0->NextIndex = __stack1_0;
#line 16 "D:\\PROJECT\\IL2C\\tests\\UEFI\\UEFI.Code\\PolishNotation.cs"
    /* Path=1, Unique=0: IL_000d: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return;
}

//////////////////////
// Runtime helpers:

static void __UEFI_Code_AbstractNode_MARK_HANDLER__(void* pReference)
{
    il2c_typeof(System_Object)->pMarkHandler(pReference);
}

static __UEFI_Code_AbstractNode_TYPE_DEF_TYPE__ __UEFI_Code_AbstractNode_RUNTIME_TYPE_DEF__ = {
    (intptr_t)"UEFI.Code.AbstractNode",
    (intptr_t)sizeof(UEFI_Code_AbstractNode),
    (intptr_t)__UEFI_Code_AbstractNode_MARK_HANDLER__,
    __System_Object_ToString__,
    __System_Object_GetHashCode__,
    __System_Object_Finalize__,
    __System_Object_Equals__,
};
const IL2C_RUNTIME_TYPE __UEFI_Code_AbstractNode_RUNTIME_TYPE__ =
   (const IL2C_RUNTIME_TYPE)(&__UEFI_Code_AbstractNode_RUNTIME_TYPE_DEF__);

////////////////////////////////////////////////////////////
// Type: UEFI.Code.OperatorNode

///////////////////////////////////////
// .ctor

void UEFI_Code_OperatorNode__ctor(UEFI_Code_OperatorNode* this__, wchar_t oper, int32_t nextIndex)
{
    //-------------------
    // Local variables:


    //-------------------
    // Evaluation stacks:

    UEFI_Code_OperatorNode* __stack0_0 = NULL;
    int32_t __stack1_0;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        UEFI_Code_OperatorNode** p__stack0_0;
    } __executionFrame__;

    __executionFrame__.targetCount = 1;
    __executionFrame__.p__stack0_0 = &__stack0_0;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

#line 23 "D:\\PROJECT\\IL2C\\tests\\UEFI\\UEFI.Code\\PolishNotation.cs"
    /* Path=1, Unique=0: IL_0000: ldarg.0 */
    __stack0_0 = this__;
    /* Path=1, Unique=0: IL_0001: ldarg.2 */
    __stack1_0 = nextIndex;
    /* Path=1, Unique=0: IL_0002: call System.Void UEFI.Code.AbstractNode::.ctor(System.Int32) */
    UEFI_Code_AbstractNode__ctor((UEFI_Code_AbstractNode*)__stack0_0, __stack1_0);
#line 25 "D:\\PROJECT\\IL2C\\tests\\UEFI\\UEFI.Code\\PolishNotation.cs"
    /* Path=1, Unique=0: IL_0007: ldarg.0 */
    __stack0_0 = this__;
    /* Path=1, Unique=0: IL_0008: ldarg.1 */
    __stack1_0 = (int32_t)(oper);
    /* Path=1, Unique=0: IL_0009: stfld System.Char UEFI.Code.OperatorNode::Operator */
    __stack0_0->Operator = (wchar_t)__stack1_0;
#line 26 "D:\\PROJECT\\IL2C\\tests\\UEFI\\UEFI.Code\\PolishNotation.cs"
    /* Path=1, Unique=0: IL_000e: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return;
}

//////////////////////
// Runtime helpers:

static void __UEFI_Code_OperatorNode_MARK_HANDLER__(void* pReference)
{
    il2c_typeof(UEFI_Code_AbstractNode)->pMarkHandler(pReference);
}

static __UEFI_Code_OperatorNode_TYPE_DEF_TYPE__ __UEFI_Code_OperatorNode_RUNTIME_TYPE_DEF__ = {
    (intptr_t)"UEFI.Code.OperatorNode",
    (intptr_t)sizeof(UEFI_Code_OperatorNode),
    (intptr_t)__UEFI_Code_OperatorNode_MARK_HANDLER__,
    __System_Object_ToString__,
    __System_Object_GetHashCode__,
    __System_Object_Finalize__,
    __System_Object_Equals__,
};
const IL2C_RUNTIME_TYPE __UEFI_Code_OperatorNode_RUNTIME_TYPE__ =
   (const IL2C_RUNTIME_TYPE)(&__UEFI_Code_OperatorNode_RUNTIME_TYPE_DEF__);

////////////////////////////////////////////////////////////
// Type: UEFI.Code.ReducibleNode

///////////////////////////////////////
// .ctor

void UEFI_Code_ReducibleNode__ctor(UEFI_Code_ReducibleNode* this__, int32_t nextIndex)
{
    //-------------------
    // Local variables:


    //-------------------
    // Evaluation stacks:

    UEFI_Code_ReducibleNode* __stack0_0 = NULL;
    int32_t __stack1_0;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        UEFI_Code_ReducibleNode** p__stack0_0;
    } __executionFrame__;

    __executionFrame__.targetCount = 1;
    __executionFrame__.p__stack0_0 = &__stack0_0;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

#line 31 "D:\\PROJECT\\IL2C\\tests\\UEFI\\UEFI.Code\\PolishNotation.cs"
    /* Path=1, Unique=0: IL_0000: ldarg.0 */
    __stack0_0 = this__;
    /* Path=1, Unique=0: IL_0001: ldarg.1 */
    __stack1_0 = nextIndex;
    /* Path=1, Unique=0: IL_0002: call System.Void UEFI.Code.AbstractNode::.ctor(System.Int32) */
    UEFI_Code_AbstractNode__ctor((UEFI_Code_AbstractNode*)__stack0_0, __stack1_0);
#line 33 "D:\\PROJECT\\IL2C\\tests\\UEFI\\UEFI.Code\\PolishNotation.cs"
    /* Path=1, Unique=0: IL_0007: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return;
}

///////////////////////////////////////
// Abstract: Reduce

int32_t __UEFI_Code_ReducibleNode_Reduce__(UEFI_Code_ReducibleNode* this__)
{
    // WARNING: Pure virtual function called.
    //TODO: throw : assert(0);
    return (int32_t)0;
}

//////////////////////
// Runtime helpers:

static void __UEFI_Code_ReducibleNode_MARK_HANDLER__(void* pReference)
{
    il2c_typeof(UEFI_Code_AbstractNode)->pMarkHandler(pReference);
}

static __UEFI_Code_ReducibleNode_TYPE_DEF_TYPE__ __UEFI_Code_ReducibleNode_RUNTIME_TYPE_DEF__ = {
    (intptr_t)"UEFI.Code.ReducibleNode",
    (intptr_t)sizeof(UEFI_Code_ReducibleNode),
    (intptr_t)__UEFI_Code_ReducibleNode_MARK_HANDLER__,
    __System_Object_ToString__,
    __System_Object_GetHashCode__,
    __System_Object_Finalize__,
    __System_Object_Equals__,
    __UEFI_Code_ReducibleNode_Reduce__,
};
const IL2C_RUNTIME_TYPE __UEFI_Code_ReducibleNode_RUNTIME_TYPE__ =
   (const IL2C_RUNTIME_TYPE)(&__UEFI_Code_ReducibleNode_RUNTIME_TYPE_DEF__);

////////////////////////////////////////////////////////////
// Type: UEFI.Code.NumericNode

///////////////////////////////////////
// .ctor

void UEFI_Code_NumericNode__ctor(UEFI_Code_NumericNode* this__, int32_t numeric, int32_t nextIndex)
{
    //-------------------
    // Local variables:


    //-------------------
    // Evaluation stacks:

    UEFI_Code_NumericNode* __stack0_0 = NULL;
    int32_t __stack1_0;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        UEFI_Code_NumericNode** p__stack0_0;
    } __executionFrame__;

    __executionFrame__.targetCount = 1;
    __executionFrame__.p__stack0_0 = &__stack0_0;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

#line 42 "D:\\PROJECT\\IL2C\\tests\\UEFI\\UEFI.Code\\PolishNotation.cs"
    /* Path=1, Unique=0: IL_0000: ldarg.0 */
    __stack0_0 = this__;
    /* Path=1, Unique=0: IL_0001: ldarg.2 */
    __stack1_0 = nextIndex;
    /* Path=1, Unique=0: IL_0002: call System.Void UEFI.Code.ReducibleNode::.ctor(System.Int32) */
    UEFI_Code_ReducibleNode__ctor((UEFI_Code_ReducibleNode*)__stack0_0, __stack1_0);
#line 44 "D:\\PROJECT\\IL2C\\tests\\UEFI\\UEFI.Code\\PolishNotation.cs"
    /* Path=1, Unique=0: IL_0007: ldarg.0 */
    __stack0_0 = this__;
    /* Path=1, Unique=0: IL_0008: ldarg.1 */
    __stack1_0 = numeric;
    /* Path=1, Unique=0: IL_0009: stfld System.Int32 UEFI.Code.NumericNode::Numeric */
    __stack0_0->Numeric = __stack1_0;
#line 45 "D:\\PROJECT\\IL2C\\tests\\UEFI\\UEFI.Code\\PolishNotation.cs"
    /* Path=1, Unique=0: IL_000e: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return;
}

///////////////////////////////////////
// Virtual: Reduce

int32_t __UEFI_Code_NumericNode_Reduce__(UEFI_Code_NumericNode* this__)
{
    //-------------------
    // Local variables:


    //-------------------
    // Evaluation stacks:

    UEFI_Code_NumericNode* __stack0_0 = NULL;
    int32_t __stack0_1;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        UEFI_Code_NumericNode** p__stack0_0;
    } __executionFrame__;

    __executionFrame__.targetCount = 1;
    __executionFrame__.p__stack0_0 = &__stack0_0;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

#line 49 "D:\\PROJECT\\IL2C\\tests\\UEFI\\UEFI.Code\\PolishNotation.cs"
    /* Path=1, Unique=0: IL_0000: ldarg.0 */
    __stack0_0 = this__;
    /* Path=1, Unique=0: IL_0001: ldfld System.Int32 UEFI.Code.NumericNode::Numeric */
    __stack0_1 = __stack0_0->Numeric;
    /* Path=1, Unique=0: IL_0006: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return __stack0_1;
}

//////////////////////
// Runtime helpers:

static void __UEFI_Code_NumericNode_MARK_HANDLER__(void* pReference)
{
    il2c_typeof(UEFI_Code_ReducibleNode)->pMarkHandler(pReference);
}

static __UEFI_Code_NumericNode_TYPE_DEF_TYPE__ __UEFI_Code_NumericNode_RUNTIME_TYPE_DEF__ = {
    (intptr_t)"UEFI.Code.NumericNode",
    (intptr_t)sizeof(UEFI_Code_NumericNode),
    (intptr_t)__UEFI_Code_NumericNode_MARK_HANDLER__,
    __System_Object_ToString__,
    __System_Object_GetHashCode__,
    __System_Object_Finalize__,
    __System_Object_Equals__,
    __UEFI_Code_NumericNode_Reduce__,
};
const IL2C_RUNTIME_TYPE __UEFI_Code_NumericNode_RUNTIME_TYPE__ =
   (const IL2C_RUNTIME_TYPE)(&__UEFI_Code_NumericNode_RUNTIME_TYPE_DEF__);

////////////////////////////////////////////////////////////
// Type: UEFI.Code.ExpressionNode

///////////////////////////////////////
// .ctor

void UEFI_Code_ExpressionNode__ctor(UEFI_Code_ExpressionNode* this__, UEFI_Code_OperatorNode* oper, UEFI_Code_ReducibleNode* left, UEFI_Code_ReducibleNode* right, int32_t nextIndex)
{
    //-------------------
    // Local variables:


    //-------------------
    // Evaluation stacks:

    UEFI_Code_ExpressionNode* __stack0_0 = NULL;
    int32_t __stack1_0;
    UEFI_Code_OperatorNode* __stack1_1 = NULL;
    UEFI_Code_ReducibleNode* __stack1_2 = NULL;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        UEFI_Code_ExpressionNode** p__stack0_0;
        UEFI_Code_OperatorNode** p__stack1_1;
        UEFI_Code_ReducibleNode** p__stack1_2;
    } __executionFrame__;

    __executionFrame__.targetCount = 3;
    __executionFrame__.p__stack0_0 = &__stack0_0;
    __executionFrame__.p__stack1_1 = &__stack1_1;
    __executionFrame__.p__stack1_2 = &__stack1_2;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

#line 59 "D:\\PROJECT\\IL2C\\tests\\UEFI\\UEFI.Code\\PolishNotation.cs"
    /* Path=1, Unique=0: IL_0000: ldarg.0 */
    __stack0_0 = this__;
    /* Path=1, Unique=0: IL_0001: ldarg.s nextIndex */
    __stack1_0 = nextIndex;
    /* Path=1, Unique=0: IL_0003: call System.Void UEFI.Code.ReducibleNode::.ctor(System.Int32) */
    UEFI_Code_ReducibleNode__ctor((UEFI_Code_ReducibleNode*)__stack0_0, __stack1_0);
#line 61 "D:\\PROJECT\\IL2C\\tests\\UEFI\\UEFI.Code\\PolishNotation.cs"
    /* Path=1, Unique=0: IL_0008: ldarg.0 */
    __stack0_0 = this__;
    /* Path=1, Unique=0: IL_0009: ldarg.1 */
    __stack1_1 = oper;
    /* Path=1, Unique=0: IL_000a: stfld UEFI.Code.OperatorNode UEFI.Code.ExpressionNode::Operator */
    __stack0_0->Operator = __stack1_1;
#line 62 "D:\\PROJECT\\IL2C\\tests\\UEFI\\UEFI.Code\\PolishNotation.cs"
    /* Path=1, Unique=0: IL_000f: ldarg.0 */
    __stack0_0 = this__;
    /* Path=1, Unique=0: IL_0010: ldarg.2 */
    __stack1_2 = left;
    /* Path=1, Unique=0: IL_0011: stfld UEFI.Code.ReducibleNode UEFI.Code.ExpressionNode::Left */
    __stack0_0->Left = __stack1_2;
#line 63 "D:\\PROJECT\\IL2C\\tests\\UEFI\\UEFI.Code\\PolishNotation.cs"
    /* Path=1, Unique=0: IL_0016: ldarg.0 */
    __stack0_0 = this__;
    /* Path=1, Unique=0: IL_0017: ldarg.3 */
    __stack1_2 = right;
    /* Path=1, Unique=0: IL_0018: stfld UEFI.Code.ReducibleNode UEFI.Code.ExpressionNode::Right */
    __stack0_0->Right = __stack1_2;
#line 64 "D:\\PROJECT\\IL2C\\tests\\UEFI\\UEFI.Code\\PolishNotation.cs"
    /* Path=1, Unique=0: IL_001d: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return;
}

///////////////////////////////////////
// Virtual: Reduce

int32_t __UEFI_Code_ExpressionNode_Reduce__(UEFI_Code_ExpressionNode* this__)
{
    //-------------------
    // Local variables:

    int32_t local0;
    int32_t local1;

    //-------------------
    // Evaluation stacks:

    UEFI_Code_ExpressionNode* __stack0_0 = NULL;
    UEFI_Code_ReducibleNode* __stack0_1 = NULL;
    int32_t __stack0_2;
    UEFI_Code_OperatorNode* __stack0_3 = NULL;
    int32_t __stack1_0;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        UEFI_Code_ExpressionNode** p__stack0_0;
        UEFI_Code_ReducibleNode** p__stack0_1;
        UEFI_Code_OperatorNode** p__stack0_3;
    } __executionFrame__;

    __executionFrame__.targetCount = 3;
    __executionFrame__.p__stack0_0 = &__stack0_0;
    __executionFrame__.p__stack0_1 = &__stack0_1;
    __executionFrame__.p__stack0_3 = &__stack0_3;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

#line 68 "D:\\PROJECT\\IL2C\\tests\\UEFI\\UEFI.Code\\PolishNotation.cs"
    /* Path=1, Unique=0: IL_0000: ldarg.0 */
    __stack0_0 = this__;
    /* Path=1, Unique=0: IL_0001: ldfld UEFI.Code.ReducibleNode UEFI.Code.ExpressionNode::Left */
    __stack0_1 = __stack0_0->Left;
    /* Path=1, Unique=0: IL_0006: callvirt System.Int32 UEFI.Code.ReducibleNode::Reduce() */
    __stack0_2 = UEFI_Code_ReducibleNode_Reduce(__stack0_1);
    /* Path=1, Unique=0: IL_000b: stloc.0 */
    local0 = __stack0_2;
#line 69 "D:\\PROJECT\\IL2C\\tests\\UEFI\\UEFI.Code\\PolishNotation.cs"
    /* Path=1, Unique=0: IL_000c: ldarg.0 */
    __stack0_0 = this__;
    /* Path=1, Unique=0: IL_000d: ldfld UEFI.Code.ReducibleNode UEFI.Code.ExpressionNode::Right */
    __stack0_1 = __stack0_0->Right;
    /* Path=1, Unique=0: IL_0012: callvirt System.Int32 UEFI.Code.ReducibleNode::Reduce() */
    __stack0_2 = UEFI_Code_ReducibleNode_Reduce(__stack0_1);
    /* Path=1, Unique=0: IL_0017: stloc.1 */
    local1 = __stack0_2;
#line 70 "D:\\PROJECT\\IL2C\\tests\\UEFI\\UEFI.Code\\PolishNotation.cs"
    /* Path=1, Unique=0: IL_0018: ldarg.0 */
    __stack0_0 = this__;
    /* Path=1, Unique=0: IL_0019: ldfld UEFI.Code.OperatorNode UEFI.Code.ExpressionNode::Operator */
    __stack0_3 = __stack0_0->Operator;
    /* Path=1, Unique=0: IL_001e: ldfld System.Char UEFI.Code.OperatorNode::Operator */
    __stack0_2 = (int32_t)(__stack0_3->Operator);
    /* Path=1, Unique=0: IL_0023: ldc.i4.s 43 */
    __stack1_0 = 43;
    /* Path=1, Unique=0: IL_0025: bne.un.s IL_002b */
    if (__stack0_2 != __stack1_0) goto IL_002b;
#line 72 "D:\\PROJECT\\IL2C\\tests\\UEFI\\UEFI.Code\\PolishNotation.cs"
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
#line 74 "D:\\PROJECT\\IL2C\\tests\\UEFI\\UEFI.Code\\PolishNotation.cs"
    /* Path=2, Unique=0: IL_002b: ldarg.0 */
    __stack0_0 = this__;
    /* Path=2, Unique=0: IL_002c: ldfld UEFI.Code.OperatorNode UEFI.Code.ExpressionNode::Operator */
    __stack0_3 = __stack0_0->Operator;
    /* Path=2, Unique=0: IL_0031: ldfld System.Char UEFI.Code.OperatorNode::Operator */
    __stack0_2 = (int32_t)(__stack0_3->Operator);
    /* Path=2, Unique=0: IL_0036: ldc.i4.s 45 */
    __stack1_0 = 45;
    /* Path=2, Unique=0: IL_0038: bne.un.s IL_003e */
    if (__stack0_2 != __stack1_0) goto IL_003e;
#line 76 "D:\\PROJECT\\IL2C\\tests\\UEFI\\UEFI.Code\\PolishNotation.cs"
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
#line 78 "D:\\PROJECT\\IL2C\\tests\\UEFI\\UEFI.Code\\PolishNotation.cs"
    /* Path=3, Unique=0: IL_003e: ldarg.0 */
    __stack0_0 = this__;
    /* Path=3, Unique=0: IL_003f: ldfld UEFI.Code.OperatorNode UEFI.Code.ExpressionNode::Operator */
    __stack0_3 = __stack0_0->Operator;
    /* Path=3, Unique=0: IL_0044: ldfld System.Char UEFI.Code.OperatorNode::Operator */
    __stack0_2 = (int32_t)(__stack0_3->Operator);
    /* Path=3, Unique=0: IL_0049: ldc.i4.s 42 */
    __stack1_0 = 42;
    /* Path=3, Unique=0: IL_004b: bne.un.s IL_0051 */
    if (__stack0_2 != __stack1_0) goto IL_0051;
#line 80 "D:\\PROJECT\\IL2C\\tests\\UEFI\\UEFI.Code\\PolishNotation.cs"
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
#line 82 "D:\\PROJECT\\IL2C\\tests\\UEFI\\UEFI.Code\\PolishNotation.cs"
    /* Path=4, Unique=0: IL_0051: ldarg.0 */
    __stack0_0 = this__;
    /* Path=4, Unique=0: IL_0052: ldfld UEFI.Code.OperatorNode UEFI.Code.ExpressionNode::Operator */
    __stack0_3 = __stack0_0->Operator;
    /* Path=4, Unique=0: IL_0057: ldfld System.Char UEFI.Code.OperatorNode::Operator */
    __stack0_2 = (int32_t)(__stack0_3->Operator);
    /* Path=4, Unique=0: IL_005c: ldc.i4.s 47 */
    __stack1_0 = 47;
    /* Path=4, Unique=0: IL_005e: bne.un.s IL_0064 */
    if (__stack0_2 != __stack1_0) goto IL_0064;
#line 84 "D:\\PROJECT\\IL2C\\tests\\UEFI\\UEFI.Code\\PolishNotation.cs"
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
#line 88 "D:\\PROJECT\\IL2C\\tests\\UEFI\\UEFI.Code\\PolishNotation.cs"
    /* Path=5, Unique=0: IL_0064: ldc.i4.0 */
    __stack0_2 = 0;
    /* Path=5, Unique=0: IL_0065: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return __stack0_2;
}

//////////////////////
// Runtime helpers:

static void __UEFI_Code_ExpressionNode_MARK_HANDLER__(void* pReference)
{
    il2c_try_mark_from_handler(((UEFI_Code_ExpressionNode*)pReference)->Operator);
    il2c_try_mark_from_handler(((UEFI_Code_ExpressionNode*)pReference)->Left);
    il2c_try_mark_from_handler(((UEFI_Code_ExpressionNode*)pReference)->Right);
    il2c_typeof(UEFI_Code_ReducibleNode)->pMarkHandler(pReference);
}

static __UEFI_Code_ExpressionNode_TYPE_DEF_TYPE__ __UEFI_Code_ExpressionNode_RUNTIME_TYPE_DEF__ = {
    (intptr_t)"UEFI.Code.ExpressionNode",
    (intptr_t)sizeof(UEFI_Code_ExpressionNode),
    (intptr_t)__UEFI_Code_ExpressionNode_MARK_HANDLER__,
    __System_Object_ToString__,
    __System_Object_GetHashCode__,
    __System_Object_Finalize__,
    __System_Object_Equals__,
    __UEFI_Code_ExpressionNode_Reduce__,
};
const IL2C_RUNTIME_TYPE __UEFI_Code_ExpressionNode_RUNTIME_TYPE__ =
   (const IL2C_RUNTIME_TYPE)(&__UEFI_Code_ExpressionNode_RUNTIME_TYPE_DEF__);

////////////////////////////////////////////////////////////
// Type: UEFI.Code.PolishNotation

///////////////////////////////////////
// SkipWhiteSpace

int32_t UEFI_Code_PolishNotation_SkipWhiteSpace(System_String* line, int32_t startIndex)
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

#line 96 "D:\\PROJECT\\IL2C\\tests\\UEFI\\UEFI.Code\\PolishNotation.cs"
    /* Path=1, Unique=0: IL_0000: ldarg.1 */
    __stack0_0 = startIndex;
    /* Path=1, Unique=0: IL_0001: stloc.0 */
    local0 = __stack0_0;
    /* Path=1, Unique=0: IL_0002: br.s IL_001a */
    goto IL_001a;
IL_0004:
#line 99 "D:\\PROJECT\\IL2C\\tests\\UEFI\\UEFI.Code\\PolishNotation.cs"
    /* Path=3, Unique=0: IL_0004: ldarg.0 */
    __stack0_1 = line;
    /* Path=3, Unique=0: IL_0005: ldloc.0 */
    __stack1_2 = local0;
    /* Path=3, Unique=0: IL_0006: callvirt System.Char System.String::get_Chars(System.Int32) */
    __stack0_2 = System_String_get_Chars(__stack0_1, __stack1_2);
    /* Path=3, Unique=0: IL_000b: stloc.1 */
    local1 = (wchar_t)__stack0_2;
#line 100 "D:\\PROJECT\\IL2C\\tests\\UEFI\\UEFI.Code\\PolishNotation.cs"
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
#line 104 "D:\\PROJECT\\IL2C\\tests\\UEFI\\UEFI.Code\\PolishNotation.cs"
    /* Path=3, Unique=0: IL_0016: ldloc.0 */
    __stack0_0 = local0;
    /* Path=3, Unique=0: IL_0017: ldc.i4.1 */
    __stack1_2 = 1;
    /* Path=3, Unique=0: IL_0018: add */
    __stack0_0 = __stack0_0 + __stack1_2;
    /* Path=3, Unique=0: IL_0019: stloc.0 */
    local0 = __stack0_0;
IL_001a:
#line 97 "D:\\PROJECT\\IL2C\\tests\\UEFI\\UEFI.Code\\PolishNotation.cs"
    /* Path=2, Unique=0: IL_001a: ldloc.0 */
    __stack0_0 = local0;
    /* Path=2, Unique=0: IL_001b: ldarg.0 */
    __stack1_0 = line;
    /* Path=2, Unique=0: IL_001c: callvirt System.Int32 System.String::get_Length() */
    __stack1_1 = System_String_get_Length(__stack1_0);
    /* Path=2, Unique=0: IL_0021: blt.s IL_0004 */
    if (__stack0_0 < __stack1_1) goto IL_0004;
IL_0023:
#line 107 "D:\\PROJECT\\IL2C\\tests\\UEFI\\UEFI.Code\\PolishNotation.cs"
    /* Path=2, Unique=0: IL_0023: ldloc.0 */
    __stack0_0 = local0;
    /* Path=2, Unique=0: IL_0024: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return __stack0_0;
}

///////////////////////////////////////
// ParseOperator

UEFI_Code_OperatorNode* UEFI_Code_PolishNotation_ParseOperator(System_String* line, int32_t startIndex)
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
    UEFI_Code_OperatorNode* __stack0_4 = NULL;
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
        UEFI_Code_OperatorNode** p__stack0_4;
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

#line 112 "D:\\PROJECT\\IL2C\\tests\\UEFI\\UEFI.Code\\PolishNotation.cs"
    /* Path=1, Unique=0: IL_0000: ldarg.1 */
    __stack0_0 = startIndex;
    /* Path=1, Unique=0: IL_0001: ldarg.0 */
    __stack1_0 = line;
    /* Path=1, Unique=0: IL_0002: callvirt System.Int32 System.String::get_Length() */
    __stack1_1 = System_String_get_Length(__stack1_0);
    /* Path=1, Unique=0: IL_0007: blt.s IL_000b */
    if (__stack0_0 < __stack1_1) goto IL_000b;
#line 114 "D:\\PROJECT\\IL2C\\tests\\UEFI\\UEFI.Code\\PolishNotation.cs"
    /* Path=1, Unique=0: IL_0009: ldnull */
    __stack0_1 = NULL;
    /* Path=1, Unique=0: IL_000a: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return (UEFI_Code_OperatorNode*)__stack0_1;
IL_000b:
#line 117 "D:\\PROJECT\\IL2C\\tests\\UEFI\\UEFI.Code\\PolishNotation.cs"
    /* Path=2, Unique=0: IL_000b: ldarg.1 */
    __stack0_0 = startIndex;
    /* Path=2, Unique=0: IL_000c: stloc.0 */
    local0 = __stack0_0;
#line 118 "D:\\PROJECT\\IL2C\\tests\\UEFI\\UEFI.Code\\PolishNotation.cs"
    /* Path=2, Unique=0: IL_000d: ldarg.0 */
    __stack0_2 = line;
    /* Path=2, Unique=0: IL_000e: ldloc.0 */
    __stack1_2 = local0;
    /* Path=2, Unique=0: IL_000f: callvirt System.Char System.String::get_Chars(System.Int32) */
    __stack0_3 = System_String_get_Chars(__stack0_2, __stack1_2);
    /* Path=2, Unique=0: IL_0014: stloc.1 */
    local1 = (wchar_t)__stack0_3;
#line 119 "D:\\PROJECT\\IL2C\\tests\\UEFI\\UEFI.Code\\PolishNotation.cs"
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
#line 121 "D:\\PROJECT\\IL2C\\tests\\UEFI\\UEFI.Code\\PolishNotation.cs"
    /* Path=2, Unique=0: IL_0029: ldnull */
    __stack0_1 = NULL;
    /* Path=2, Unique=0: IL_002a: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return (UEFI_Code_OperatorNode*)__stack0_1;
IL_002b:
#line 123 "D:\\PROJECT\\IL2C\\tests\\UEFI\\UEFI.Code\\PolishNotation.cs"
    /* Path=3, Unique=0: IL_002b: ldloc.0 */
    __stack0_0 = local0;
    /* Path=3, Unique=0: IL_002c: ldc.i4.1 */
    __stack1_2 = 1;
    /* Path=3, Unique=0: IL_002d: add */
    __stack0_0 = __stack0_0 + __stack1_2;
    /* Path=3, Unique=0: IL_002e: stloc.0 */
    local0 = __stack0_0;
#line 125 "D:\\PROJECT\\IL2C\\tests\\UEFI\\UEFI.Code\\PolishNotation.cs"
    /* Path=3, Unique=0: IL_002f: ldarg.0 */
    __stack0_2 = line;
    /* Path=3, Unique=0: IL_0030: ldloc.0 */
    __stack1_2 = local0;
    /* Path=3, Unique=0: IL_0031: call System.Int32 UEFI.Code.PolishNotation::SkipWhiteSpace(System.String,System.Int32) */
    __stack0_0 = UEFI_Code_PolishNotation_SkipWhiteSpace(__stack0_2, __stack1_2);
    /* Path=3, Unique=0: IL_0036: stloc.0 */
    local0 = __stack0_0;
#line 126 "D:\\PROJECT\\IL2C\\tests\\UEFI\\UEFI.Code\\PolishNotation.cs"
    /* Path=3, Unique=0: IL_0037: ldloc.1 */
    __stack0_0 = local1;
    /* Path=3, Unique=0: IL_0038: ldloc.0 */
    __stack1_2 = local0;
    /* Path=3, Unique=0: IL_0039: newobj System.Void UEFI.Code.OperatorNode::.ctor(System.Char,System.Int32) */
    __stack0_4 = il2c_get_uninitialized_object(il2c_typeof(UEFI_Code_OperatorNode));
    UEFI_Code_OperatorNode__ctor(__stack0_4, (wchar_t)__stack0_0, __stack1_2);
    /* Path=3, Unique=0: IL_003e: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return __stack0_4;
}

///////////////////////////////////////
// ParseNumeric

UEFI_Code_NumericNode* UEFI_Code_PolishNotation_ParseNumeric(System_String* line, int32_t startIndex)
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
    UEFI_Code_NumericNode* __stack0_5 = NULL;
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
        UEFI_Code_NumericNode** p__stack0_5;
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

#line 131 "D:\\PROJECT\\IL2C\\tests\\UEFI\\UEFI.Code\\PolishNotation.cs"
    /* Path=1, Unique=0: IL_0000: ldarg.1 */
    __stack0_0 = startIndex;
    /* Path=1, Unique=0: IL_0001: ldarg.0 */
    __stack1_0 = line;
    /* Path=1, Unique=0: IL_0002: callvirt System.Int32 System.String::get_Length() */
    __stack1_1 = System_String_get_Length(__stack1_0);
    /* Path=1, Unique=0: IL_0007: blt.s IL_000b */
    if (__stack0_0 < __stack1_1) goto IL_000b;
#line 133 "D:\\PROJECT\\IL2C\\tests\\UEFI\\UEFI.Code\\PolishNotation.cs"
    /* Path=1, Unique=0: IL_0009: ldnull */
    __stack0_1 = NULL;
    /* Path=1, Unique=0: IL_000a: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return (UEFI_Code_NumericNode*)__stack0_1;
IL_000b:
#line 136 "D:\\PROJECT\\IL2C\\tests\\UEFI\\UEFI.Code\\PolishNotation.cs"
    /* Path=2, Unique=0: IL_000b: ldarg.1 */
    __stack0_0 = startIndex;
    /* Path=2, Unique=0: IL_000c: stloc.0 */
    local0 = __stack0_0;
    /* Path=2, Unique=0: IL_000d: br.s IL_001e */
    goto IL_001e;
IL_000f:
#line 139 "D:\\PROJECT\\IL2C\\tests\\UEFI\\UEFI.Code\\PolishNotation.cs"
    /* Path=4, Unique=0: IL_000f: ldarg.0 */
    __stack0_2 = line;
    /* Path=4, Unique=0: IL_0010: ldloc.0 */
    __stack1_2 = local0;
    /* Path=4, Unique=0: IL_0011: callvirt System.Char System.String::get_Chars(System.Int32) */
    __stack0_3 = System_String_get_Chars(__stack0_2, __stack1_2);
#line 140 "D:\\PROJECT\\IL2C\\tests\\UEFI\\UEFI.Code\\PolishNotation.cs"
    /* Path=4, Unique=0: IL_0016: ldc.i4.s 32 */
    __stack1_2 = 32;
    /* Path=4, Unique=0: IL_0018: beq.s IL_0027 */
    if (__stack0_3 == __stack1_2) goto IL_0027;
#line 144 "D:\\PROJECT\\IL2C\\tests\\UEFI\\UEFI.Code\\PolishNotation.cs"
    /* Path=4, Unique=0: IL_001a: ldloc.0 */
    __stack0_0 = local0;
    /* Path=4, Unique=0: IL_001b: ldc.i4.1 */
    __stack1_2 = 1;
    /* Path=4, Unique=0: IL_001c: add */
    __stack0_0 = __stack0_0 + __stack1_2;
    /* Path=4, Unique=0: IL_001d: stloc.0 */
    local0 = __stack0_0;
IL_001e:
#line 137 "D:\\PROJECT\\IL2C\\tests\\UEFI\\UEFI.Code\\PolishNotation.cs"
    /* Path=3, Unique=0: IL_001e: ldloc.0 */
    __stack0_0 = local0;
    /* Path=3, Unique=0: IL_001f: ldarg.0 */
    __stack1_0 = line;
    /* Path=3, Unique=0: IL_0020: callvirt System.Int32 System.String::get_Length() */
    __stack1_1 = System_String_get_Length(__stack1_0);
    /* Path=3, Unique=0: IL_0025: blt.s IL_000f */
    if (__stack0_0 < __stack1_1) goto IL_000f;
IL_0027:
#line 147 "D:\\PROJECT\\IL2C\\tests\\UEFI\\UEFI.Code\\PolishNotation.cs"
    /* Path=3, Unique=0: IL_0027: ldloc.0 */
    __stack0_0 = local0;
    /* Path=3, Unique=0: IL_0028: ldarg.1 */
    __stack1_2 = startIndex;
    /* Path=3, Unique=0: IL_0029: bne.un.s IL_002d */
    if (__stack0_0 != __stack1_2) goto IL_002d;
#line 149 "D:\\PROJECT\\IL2C\\tests\\UEFI\\UEFI.Code\\PolishNotation.cs"
    /* Path=3, Unique=0: IL_002b: ldnull */
    __stack0_1 = NULL;
    /* Path=3, Unique=0: IL_002c: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return (UEFI_Code_NumericNode*)__stack0_1;
IL_002d:
#line 152 "D:\\PROJECT\\IL2C\\tests\\UEFI\\UEFI.Code\\PolishNotation.cs"
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
#line 153 "D:\\PROJECT\\IL2C\\tests\\UEFI\\UEFI.Code\\PolishNotation.cs"
    /* Path=5, Unique=0: IL_0037: ldloca.s local1 */
    __stack1_3 = &local1;
    /* Path=5, Unique=0: IL_0039: call System.Boolean System.Int32::TryParse(System.String,System.Int32&) */
    __stack0_0 = System_Int32_TryParse(__stack0_4, __stack1_3);
    /* Path=5, Unique=0: IL_003e: brtrue.s IL_0042 */
    if (__stack0_0 != 0) goto IL_0042;
#line 155 "D:\\PROJECT\\IL2C\\tests\\UEFI\\UEFI.Code\\PolishNotation.cs"
    /* Path=5, Unique=0: IL_0040: ldnull */
    __stack0_1 = NULL;
    /* Path=5, Unique=0: IL_0041: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return (UEFI_Code_NumericNode*)__stack0_1;
IL_0042:
#line 158 "D:\\PROJECT\\IL2C\\tests\\UEFI\\UEFI.Code\\PolishNotation.cs"
    /* Path=6, Unique=0: IL_0042: ldarg.0 */
    __stack0_2 = line;
    /* Path=6, Unique=0: IL_0043: ldloc.0 */
    __stack1_2 = local0;
    /* Path=6, Unique=0: IL_0044: call System.Int32 UEFI.Code.PolishNotation::SkipWhiteSpace(System.String,System.Int32) */
    __stack0_0 = UEFI_Code_PolishNotation_SkipWhiteSpace(__stack0_2, __stack1_2);
    /* Path=6, Unique=0: IL_0049: stloc.0 */
    local0 = __stack0_0;
#line 159 "D:\\PROJECT\\IL2C\\tests\\UEFI\\UEFI.Code\\PolishNotation.cs"
    /* Path=6, Unique=0: IL_004a: ldloc.1 */
    __stack0_0 = local1;
    /* Path=6, Unique=0: IL_004b: ldloc.0 */
    __stack1_2 = local0;
    /* Path=6, Unique=0: IL_004c: newobj System.Void UEFI.Code.NumericNode::.ctor(System.Int32,System.Int32) */
    __stack0_5 = il2c_get_uninitialized_object(il2c_typeof(UEFI_Code_NumericNode));
    UEFI_Code_NumericNode__ctor(__stack0_5, __stack0_0, __stack1_2);
    /* Path=6, Unique=0: IL_0051: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return __stack0_5;
}

///////////////////////////////////////
// ParseExpression

UEFI_Code_ExpressionNode* UEFI_Code_PolishNotation_ParseExpression(System_String* line, int32_t startIndex)
{
    //-------------------
    // Local variables:

    UEFI_Code_OperatorNode* local0 = NULL;
    UEFI_Code_ReducibleNode* local1 = NULL;
    UEFI_Code_ReducibleNode* local2 = NULL;
    int32_t local3;

    //-------------------
    // Evaluation stacks:

    int32_t __stack0_0;
    IL2C_CecilHelper_PseudoZeroType* __stack0_1 = NULL;
    System_String* __stack0_2 = NULL;
    UEFI_Code_OperatorNode* __stack0_3 = NULL;
    UEFI_Code_NumericNode* __stack0_4 = NULL;
    UEFI_Code_ReducibleNode* __stack0_5 = NULL;
    UEFI_Code_ExpressionNode* __stack0_6 = NULL;
    System_String* __stack1_0 = NULL;
    int32_t __stack1_1;
    int32_t __stack1_2;
    UEFI_Code_OperatorNode* __stack1_3 = NULL;
    UEFI_Code_ReducibleNode* __stack1_4 = NULL;
    UEFI_Code_ReducibleNode* __stack2_0 = NULL;
    int32_t __stack3_0;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        UEFI_Code_OperatorNode** plocal0;
        UEFI_Code_ReducibleNode** plocal1;
        UEFI_Code_ReducibleNode** plocal2;
        IL2C_CecilHelper_PseudoZeroType** p__stack0_1;
        System_String** p__stack0_2;
        UEFI_Code_OperatorNode** p__stack0_3;
        UEFI_Code_NumericNode** p__stack0_4;
        UEFI_Code_ReducibleNode** p__stack0_5;
        UEFI_Code_ExpressionNode** p__stack0_6;
        System_String** p__stack1_0;
        UEFI_Code_OperatorNode** p__stack1_3;
        UEFI_Code_ReducibleNode** p__stack1_4;
        UEFI_Code_ReducibleNode** p__stack2_0;
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

#line 164 "D:\\PROJECT\\IL2C\\tests\\UEFI\\UEFI.Code\\PolishNotation.cs"
    /* Path=1, Unique=0: IL_0000: ldarg.1 */
    __stack0_0 = startIndex;
    /* Path=1, Unique=0: IL_0001: ldarg.0 */
    __stack1_0 = line;
    /* Path=1, Unique=0: IL_0002: callvirt System.Int32 System.String::get_Length() */
    __stack1_1 = System_String_get_Length(__stack1_0);
    /* Path=1, Unique=0: IL_0007: blt.s IL_000b */
    if (__stack0_0 < __stack1_1) goto IL_000b;
#line 166 "D:\\PROJECT\\IL2C\\tests\\UEFI\\UEFI.Code\\PolishNotation.cs"
    /* Path=1, Unique=0: IL_0009: ldnull */
    __stack0_1 = NULL;
    /* Path=1, Unique=0: IL_000a: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return (UEFI_Code_ExpressionNode*)__stack0_1;
IL_000b:
#line 169 "D:\\PROJECT\\IL2C\\tests\\UEFI\\UEFI.Code\\PolishNotation.cs"
    /* Path=2, Unique=0: IL_000b: ldarg.0 */
    __stack0_2 = line;
    /* Path=2, Unique=0: IL_000c: ldarg.1 */
    __stack1_2 = startIndex;
    /* Path=2, Unique=0: IL_000d: call UEFI.Code.OperatorNode UEFI.Code.PolishNotation::ParseOperator(System.String,System.Int32) */
    __stack0_3 = UEFI_Code_PolishNotation_ParseOperator(__stack0_2, __stack1_2);
    /* Path=2, Unique=0: IL_0012: stloc.0 */
    local0 = __stack0_3;
#line 170 "D:\\PROJECT\\IL2C\\tests\\UEFI\\UEFI.Code\\PolishNotation.cs"
    /* Path=2, Unique=0: IL_0013: ldloc.0 */
    __stack0_3 = local0;
    /* Path=2, Unique=0: IL_0014: brtrue.s IL_0018 */
    if (__stack0_3 != NULL) goto IL_0018;
#line 172 "D:\\PROJECT\\IL2C\\tests\\UEFI\\UEFI.Code\\PolishNotation.cs"
    /* Path=2, Unique=0: IL_0016: ldnull */
    __stack0_1 = NULL;
    /* Path=2, Unique=0: IL_0017: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return (UEFI_Code_ExpressionNode*)__stack0_1;
IL_0018:
#line 175 "D:\\PROJECT\\IL2C\\tests\\UEFI\\UEFI.Code\\PolishNotation.cs"
    /* Path=3, Unique=0: IL_0018: ldarg.0 */
    __stack0_2 = line;
    /* Path=3, Unique=0: IL_0019: ldloc.0 */
    __stack1_3 = local0;
    /* Path=3, Unique=0: IL_001a: ldfld System.Int32 UEFI.Code.AbstractNode::NextIndex */
    __stack1_2 = __stack1_3->NextIndex;
    /* Path=3, Unique=0: IL_001f: call UEFI.Code.NumericNode UEFI.Code.PolishNotation::ParseNumeric(System.String,System.Int32) */
    __stack0_4 = UEFI_Code_PolishNotation_ParseNumeric(__stack0_2, __stack1_2);
    /* Path=3, Unique=0: IL_0024: stloc.1 */
    local1 = (UEFI_Code_ReducibleNode*)__stack0_4;
#line 176 "D:\\PROJECT\\IL2C\\tests\\UEFI\\UEFI.Code\\PolishNotation.cs"
    /* Path=3, Unique=0: IL_0025: ldloc.1 */
    __stack0_5 = local1;
    /* Path=3, Unique=0: IL_0026: brtrue.s IL_003a */
    if (__stack0_5 != NULL) goto IL_003a;
#line 178 "D:\\PROJECT\\IL2C\\tests\\UEFI\\UEFI.Code\\PolishNotation.cs"
    /* Path=3, Unique=0: IL_0028: ldarg.0 */
    __stack0_2 = line;
    /* Path=3, Unique=0: IL_0029: ldloc.0 */
    __stack1_3 = local0;
    /* Path=3, Unique=0: IL_002a: ldfld System.Int32 UEFI.Code.AbstractNode::NextIndex */
    __stack1_2 = __stack1_3->NextIndex;
    /* Path=3, Unique=0: IL_002f: call UEFI.Code.ExpressionNode UEFI.Code.PolishNotation::ParseExpression(System.String,System.Int32) */
    __stack0_6 = UEFI_Code_PolishNotation_ParseExpression(__stack0_2, __stack1_2);
    /* Path=3, Unique=0: IL_0034: stloc.1 */
    local1 = (UEFI_Code_ReducibleNode*)__stack0_6;
#line 179 "D:\\PROJECT\\IL2C\\tests\\UEFI\\UEFI.Code\\PolishNotation.cs"
    /* Path=3, Unique=0: IL_0035: ldloc.1 */
    __stack0_5 = local1;
    /* Path=3, Unique=0: IL_0036: brtrue.s IL_003a */
    if (__stack0_5 != NULL) goto IL_003a;
#line 181 "D:\\PROJECT\\IL2C\\tests\\UEFI\\UEFI.Code\\PolishNotation.cs"
    /* Path=3, Unique=0: IL_0038: ldnull */
    __stack0_1 = NULL;
    /* Path=3, Unique=0: IL_0039: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return (UEFI_Code_ExpressionNode*)__stack0_1;
IL_003a:
#line 185 "D:\\PROJECT\\IL2C\\tests\\UEFI\\UEFI.Code\\PolishNotation.cs"
    /* Path=4, Unique=0: IL_003a: ldarg.0 */
    __stack0_2 = line;
    /* Path=4, Unique=0: IL_003b: ldloc.1 */
    __stack1_4 = local1;
    /* Path=4, Unique=0: IL_003c: ldfld System.Int32 UEFI.Code.AbstractNode::NextIndex */
    __stack1_2 = __stack1_4->NextIndex;
    /* Path=4, Unique=0: IL_0041: call UEFI.Code.NumericNode UEFI.Code.PolishNotation::ParseNumeric(System.String,System.Int32) */
    __stack0_4 = UEFI_Code_PolishNotation_ParseNumeric(__stack0_2, __stack1_2);
    /* Path=4, Unique=0: IL_0046: stloc.2 */
    local2 = (UEFI_Code_ReducibleNode*)__stack0_4;
#line 186 "D:\\PROJECT\\IL2C\\tests\\UEFI\\UEFI.Code\\PolishNotation.cs"
    /* Path=4, Unique=0: IL_0047: ldloc.2 */
    __stack0_5 = local2;
    /* Path=4, Unique=0: IL_0048: brtrue.s IL_005c */
    if (__stack0_5 != NULL) goto IL_005c;
#line 188 "D:\\PROJECT\\IL2C\\tests\\UEFI\\UEFI.Code\\PolishNotation.cs"
    /* Path=4, Unique=0: IL_004a: ldarg.0 */
    __stack0_2 = line;
    /* Path=4, Unique=0: IL_004b: ldloc.1 */
    __stack1_4 = local1;
    /* Path=4, Unique=0: IL_004c: ldfld System.Int32 UEFI.Code.AbstractNode::NextIndex */
    __stack1_2 = __stack1_4->NextIndex;
    /* Path=4, Unique=0: IL_0051: call UEFI.Code.ExpressionNode UEFI.Code.PolishNotation::ParseExpression(System.String,System.Int32) */
    __stack0_6 = UEFI_Code_PolishNotation_ParseExpression(__stack0_2, __stack1_2);
    /* Path=4, Unique=0: IL_0056: stloc.2 */
    local2 = (UEFI_Code_ReducibleNode*)__stack0_6;
#line 189 "D:\\PROJECT\\IL2C\\tests\\UEFI\\UEFI.Code\\PolishNotation.cs"
    /* Path=4, Unique=0: IL_0057: ldloc.2 */
    __stack0_5 = local2;
    /* Path=4, Unique=0: IL_0058: brtrue.s IL_005c */
    if (__stack0_5 != NULL) goto IL_005c;
#line 191 "D:\\PROJECT\\IL2C\\tests\\UEFI\\UEFI.Code\\PolishNotation.cs"
    /* Path=4, Unique=0: IL_005a: ldnull */
    __stack0_1 = NULL;
    /* Path=4, Unique=0: IL_005b: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return (UEFI_Code_ExpressionNode*)__stack0_1;
IL_005c:
#line 195 "D:\\PROJECT\\IL2C\\tests\\UEFI\\UEFI.Code\\PolishNotation.cs"
    /* Path=5, Unique=0: IL_005c: ldarg.0 */
    __stack0_2 = line;
    /* Path=5, Unique=0: IL_005d: ldloc.2 */
    __stack1_4 = local2;
    /* Path=5, Unique=0: IL_005e: ldfld System.Int32 UEFI.Code.AbstractNode::NextIndex */
    __stack1_2 = __stack1_4->NextIndex;
    /* Path=5, Unique=0: IL_0063: call System.Int32 UEFI.Code.PolishNotation::SkipWhiteSpace(System.String,System.Int32) */
    __stack0_0 = UEFI_Code_PolishNotation_SkipWhiteSpace(__stack0_2, __stack1_2);
    /* Path=5, Unique=0: IL_0068: stloc.3 */
    local3 = __stack0_0;
#line 196 "D:\\PROJECT\\IL2C\\tests\\UEFI\\UEFI.Code\\PolishNotation.cs"
    /* Path=5, Unique=0: IL_0069: ldloc.0 */
    __stack0_3 = local0;
    /* Path=5, Unique=0: IL_006a: ldloc.1 */
    __stack1_4 = local1;
    /* Path=5, Unique=0: IL_006b: ldloc.2 */
    __stack2_0 = local2;
    /* Path=5, Unique=0: IL_006c: ldloc.3 */
    __stack3_0 = local3;
    /* Path=5, Unique=0: IL_006d: newobj System.Void UEFI.Code.ExpressionNode::.ctor(UEFI.Code.OperatorNode,UEFI.Code.ReducibleNode,UEFI.Code.ReducibleNode,System.Int32) */
    __stack0_6 = il2c_get_uninitialized_object(il2c_typeof(UEFI_Code_ExpressionNode));
    UEFI_Code_ExpressionNode__ctor(__stack0_6, __stack0_3, __stack1_4, __stack2_0, __stack3_0);
    /* Path=5, Unique=0: IL_0072: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return __stack0_6;
}

///////////////////////////////////////
// Main

void UEFI_Code_PolishNotation_Main(void)
{
    //-------------------
    // Local variables:

    System_String* local0 = NULL;
    UEFI_Code_ExpressionNode* local1 = NULL;

    //-------------------
    // Evaluation stacks:

    System_String* __stack0_0 = NULL;
    int32_t __stack0_1;
    UEFI_Code_ExpressionNode* __stack0_2 = NULL;
    int32_t __stack1_0;
    System_String* __stack1_1 = NULL;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        System_String** plocal0;
        UEFI_Code_ExpressionNode** plocal1;
        System_String** p__stack0_0;
        UEFI_Code_ExpressionNode** p__stack0_2;
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
#line 203 "D:\\PROJECT\\IL2C\\tests\\UEFI\\UEFI.Code\\PolishNotation.cs"
    /* Path=1, Unique=0: IL_0000: call System.Void System.Console::WriteLine() */
    System_Console_WriteLine();
#line 204 "D:\\PROJECT\\IL2C\\tests\\UEFI\\UEFI.Code\\PolishNotation.cs"
    /* Path=1, Unique=0: IL_0005: ldstr "PN> " */
    __stack0_0 = __string0;
    /* Path=1, Unique=0: IL_000a: call System.Void System.Console::Write(System.String) */
    System_Console_Write_9(__stack0_0);
#line 205 "D:\\PROJECT\\IL2C\\tests\\UEFI\\UEFI.Code\\PolishNotation.cs"
    /* Path=1, Unique=0: IL_000f: call System.String System.Console::ReadLine() */
    __stack0_0 = System_Console_ReadLine();
    /* Path=1, Unique=0: IL_0014: stloc.0 */
    local0 = __stack0_0;
#line 206 "D:\\PROJECT\\IL2C\\tests\\UEFI\\UEFI.Code\\PolishNotation.cs"
    /* Path=1, Unique=0: IL_0015: ldloc.0 */
    __stack0_0 = local0;
    /* Path=1, Unique=0: IL_0016: call System.Boolean System.String::IsNullOrWhiteSpace(System.String) */
    __stack0_1 = System_String_IsNullOrWhiteSpace(__stack0_0);
    /* Path=1, Unique=0: IL_001b: brtrue.s IL_0000 */
    if (__stack0_1 != 0) goto IL_0000;
#line 208 "D:\\PROJECT\\IL2C\\tests\\UEFI\\UEFI.Code\\PolishNotation.cs"
    /* Path=1, Unique=0: IL_001d: ldloc.0 */
    __stack0_0 = local0;
    /* Path=1, Unique=0: IL_001e: ldc.i4.0 */
    __stack1_0 = 0;
    /* Path=1, Unique=0: IL_001f: call UEFI.Code.ExpressionNode UEFI.Code.PolishNotation::ParseExpression(System.String,System.Int32) */
    __stack0_2 = UEFI_Code_PolishNotation_ParseExpression(__stack0_0, __stack1_0);
    /* Path=1, Unique=0: IL_0024: stloc.1 */
    local1 = __stack0_2;
#line 209 "D:\\PROJECT\\IL2C\\tests\\UEFI\\UEFI.Code\\PolishNotation.cs"
    /* Path=1, Unique=0: IL_0025: ldloc.1 */
    __stack0_2 = local1;
    /* Path=1, Unique=0: IL_0026: brtrue.s IL_0034 */
    if (__stack0_2 != NULL) goto IL_0034;
#line 211 "D:\\PROJECT\\IL2C\\tests\\UEFI\\UEFI.Code\\PolishNotation.cs"
    /* Path=1, Unique=0: IL_0028: ldstr "Syntax error." */
    __stack0_0 = __string1;
    /* Path=1, Unique=0: IL_002d: call System.Void System.Console::WriteLine(System.String) */
    System_Console_WriteLine_10(__stack0_0);
#line 212 "D:\\PROJECT\\IL2C\\tests\\UEFI\\UEFI.Code\\PolishNotation.cs"
    /* Path=1, Unique=0: IL_0032: br.s IL_0000 */
    goto IL_0000;
IL_0034:
#line 215 "D:\\PROJECT\\IL2C\\tests\\UEFI\\UEFI.Code\\PolishNotation.cs"
    /* Path=2, Unique=0: IL_0034: ldloc.1 */
    __stack0_2 = local1;
    /* Path=2, Unique=0: IL_0035: callvirt System.Int32 UEFI.Code.ReducibleNode::Reduce() */
    __stack0_1 = UEFI_Code_ReducibleNode_Reduce((UEFI_Code_ReducibleNode*)__stack0_2);
#line 217 "D:\\PROJECT\\IL2C\\tests\\UEFI\\UEFI.Code\\PolishNotation.cs"
    /* Path=2, Unique=0: IL_003a: ldstr "Reuslt=" */
    __stack1_1 = __string2;
    /* Path=2, Unique=0: IL_003f: call System.Void System.Console::Write(System.String) */
    System_Console_Write_9(__stack1_1);
#line 218 "D:\\PROJECT\\IL2C\\tests\\UEFI\\UEFI.Code\\PolishNotation.cs"
    /* Path=2, Unique=0: IL_0044: call System.Void System.Console::WriteLine(System.Int32) */
    System_Console_WriteLine_6(__stack0_1);
#line 201 "D:\\PROJECT\\IL2C\\tests\\UEFI\\UEFI.Code\\PolishNotation.cs"
    /* Path=2, Unique=0: IL_0049: br.s IL_0000 */
    goto IL_0000;
}

///////////////////////////////////////
// .ctor

void UEFI_Code_PolishNotation__ctor(UEFI_Code_PolishNotation* this__)
{
    //-------------------
    // Local variables:


    //-------------------
    // Evaluation stacks:

    UEFI_Code_PolishNotation* __stack0_0 = NULL;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        UEFI_Code_PolishNotation** p__stack0_0;
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

static void __UEFI_Code_PolishNotation_MARK_HANDLER__(void* pReference)
{
    il2c_typeof(System_Object)->pMarkHandler(pReference);
}

static __UEFI_Code_PolishNotation_TYPE_DEF_TYPE__ __UEFI_Code_PolishNotation_RUNTIME_TYPE_DEF__ = {
    (intptr_t)"UEFI.Code.PolishNotation",
    (intptr_t)0,
    (intptr_t)__UEFI_Code_PolishNotation_MARK_HANDLER__,
    __System_Object_ToString__,
    __System_Object_GetHashCode__,
    __System_Object_Finalize__,
    __System_Object_Equals__,
};
const IL2C_RUNTIME_TYPE __UEFI_Code_PolishNotation_RUNTIME_TYPE__ =
   (const IL2C_RUNTIME_TYPE)(&__UEFI_Code_PolishNotation_RUNTIME_TYPE_DEF__);
