#include "UEFI.Code.h"

//////////////////////////////////////////////////////////////////////////////////
// Const strings:

__DEFINE_CONST_STRING__(__string0, L"PN> ");
__DEFINE_CONST_STRING__(__string1, L"Syntax error.");
__DEFINE_CONST_STRING__(__string2, L"Reuslt=");

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

void UEFI_Code_AbstractNode__ctor(UEFI_Code_AbstractNode* __this, int32_t nextIndex)
{
    //-------------------
    // Local variables:


    //-------------------
    // Evaluation stacks:

    UEFI_Code_AbstractNode* __stack0_0 = NULL;
    int32_t __stack1_0;

    //-------------------
    // Setup stack frame:

    struct /* __EXECUTION_FRAME__ */
    {
        __EXECUTION_FRAME__* pNext;
        uint8_t targetCount;
        UEFI_Code_AbstractNode** p__stack0_0;
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
    __stack1_0 = nextIndex;
    /* Path=1, Unique=0: IL_000a: stfld System.Int32 UEFI.Code.AbstractNode::NextIndex */
    __stack0_0->NextIndex = __stack1_0;
    /* Path=1, Unique=0: IL_000f: ret */
    __gc_unlink_execution_frame__(&__executionFrame__);
    return;
}

//////////////////////
// Runtime helpers:

static void __UEFI_Code_AbstractNode_MARK_HANDLER__(void* pReference)
{
    __typeof__(System_Object)->pMarkHandler(pReference);
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
const __RUNTIME_TYPE__ __UEFI_Code_AbstractNode_RUNTIME_TYPE__ =
   (const __RUNTIME_TYPE__)(&__UEFI_Code_AbstractNode_RUNTIME_TYPE_DEF__);

////////////////////////////////////////////////////////////
// Type: UEFI.Code.OperatorNode

///////////////////////////////////////
// .ctor

void UEFI_Code_OperatorNode__ctor(UEFI_Code_OperatorNode* __this, wchar_t oper, int32_t nextIndex)
{
    //-------------------
    // Local variables:


    //-------------------
    // Evaluation stacks:

    UEFI_Code_OperatorNode* __stack0_0 = NULL;
    int32_t __stack1_0;

    //-------------------
    // Setup stack frame:

    struct /* __EXECUTION_FRAME__ */
    {
        __EXECUTION_FRAME__* pNext;
        uint8_t targetCount;
        UEFI_Code_OperatorNode** p__stack0_0;
    } __executionFrame__;

    __executionFrame__.targetCount = 1;
    __executionFrame__.p__stack0_0 = &__stack0_0;
    __gc_link_execution_frame__(&__executionFrame__);

    //-------------------
    // IL body:

    /* Path=1, Unique=0: IL_0000: ldarg.0 */
    __stack0_0 = __this;
    /* Path=1, Unique=0: IL_0001: ldarg.2 */
    __stack1_0 = nextIndex;
    /* Path=1, Unique=0: IL_0002: call System.Void UEFI.Code.AbstractNode::.ctor(System.Int32) */
    UEFI_Code_AbstractNode__ctor((UEFI_Code_AbstractNode*)__stack0_0, __stack1_0);
    /* Path=1, Unique=0: IL_0007: nop */
    /* Path=1, Unique=0: IL_0008: nop */
    /* Path=1, Unique=0: IL_0009: ldarg.0 */
    __stack0_0 = __this;
    /* Path=1, Unique=0: IL_000a: ldarg.1 */
    __stack1_0 = (int32_t)(oper);
    /* Path=1, Unique=0: IL_000b: stfld System.Char UEFI.Code.OperatorNode::Operator */
    __stack0_0->Operator = (wchar_t)__stack1_0;
    /* Path=1, Unique=0: IL_0010: ret */
    __gc_unlink_execution_frame__(&__executionFrame__);
    return;
}

//////////////////////
// Runtime helpers:

static void __UEFI_Code_OperatorNode_MARK_HANDLER__(void* pReference)
{
    __typeof__(UEFI_Code_AbstractNode)->pMarkHandler(pReference);
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
const __RUNTIME_TYPE__ __UEFI_Code_OperatorNode_RUNTIME_TYPE__ =
   (const __RUNTIME_TYPE__)(&__UEFI_Code_OperatorNode_RUNTIME_TYPE_DEF__);

////////////////////////////////////////////////////////////
// Type: UEFI.Code.ReducibleNode

///////////////////////////////////////
// .ctor

void UEFI_Code_ReducibleNode__ctor(UEFI_Code_ReducibleNode* __this, int32_t nextIndex)
{
    //-------------------
    // Local variables:


    //-------------------
    // Evaluation stacks:

    UEFI_Code_ReducibleNode* __stack0_0 = NULL;
    int32_t __stack1_0;

    //-------------------
    // Setup stack frame:

    struct /* __EXECUTION_FRAME__ */
    {
        __EXECUTION_FRAME__* pNext;
        uint8_t targetCount;
        UEFI_Code_ReducibleNode** p__stack0_0;
    } __executionFrame__;

    __executionFrame__.targetCount = 1;
    __executionFrame__.p__stack0_0 = &__stack0_0;
    __gc_link_execution_frame__(&__executionFrame__);

    //-------------------
    // IL body:

    /* Path=1, Unique=0: IL_0000: ldarg.0 */
    __stack0_0 = __this;
    /* Path=1, Unique=0: IL_0001: ldarg.1 */
    __stack1_0 = nextIndex;
    /* Path=1, Unique=0: IL_0002: call System.Void UEFI.Code.AbstractNode::.ctor(System.Int32) */
    UEFI_Code_AbstractNode__ctor((UEFI_Code_AbstractNode*)__stack0_0, __stack1_0);
    /* Path=1, Unique=0: IL_0007: nop */
    /* Path=1, Unique=0: IL_0008: nop */
    /* Path=1, Unique=0: IL_0009: ret */
    __gc_unlink_execution_frame__(&__executionFrame__);
    return;
}

///////////////////////////////////////
// Abstract: Reduce

int32_t __UEFI_Code_ReducibleNode_Reduce__(UEFI_Code_ReducibleNode* __this)
{
    // WARNING: Pure virtual function called.
    //TODO: throw : assert(0);
    return (int32_t)0;
}

//////////////////////
// Runtime helpers:

static void __UEFI_Code_ReducibleNode_MARK_HANDLER__(void* pReference)
{
    __typeof__(UEFI_Code_AbstractNode)->pMarkHandler(pReference);
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
const __RUNTIME_TYPE__ __UEFI_Code_ReducibleNode_RUNTIME_TYPE__ =
   (const __RUNTIME_TYPE__)(&__UEFI_Code_ReducibleNode_RUNTIME_TYPE_DEF__);

////////////////////////////////////////////////////////////
// Type: UEFI.Code.NumericNode

///////////////////////////////////////
// .ctor

void UEFI_Code_NumericNode__ctor(UEFI_Code_NumericNode* __this, int32_t numeric, int32_t nextIndex)
{
    //-------------------
    // Local variables:


    //-------------------
    // Evaluation stacks:

    UEFI_Code_NumericNode* __stack0_0 = NULL;
    int32_t __stack1_0;

    //-------------------
    // Setup stack frame:

    struct /* __EXECUTION_FRAME__ */
    {
        __EXECUTION_FRAME__* pNext;
        uint8_t targetCount;
        UEFI_Code_NumericNode** p__stack0_0;
    } __executionFrame__;

    __executionFrame__.targetCount = 1;
    __executionFrame__.p__stack0_0 = &__stack0_0;
    __gc_link_execution_frame__(&__executionFrame__);

    //-------------------
    // IL body:

    /* Path=1, Unique=0: IL_0000: ldarg.0 */
    __stack0_0 = __this;
    /* Path=1, Unique=0: IL_0001: ldarg.2 */
    __stack1_0 = nextIndex;
    /* Path=1, Unique=0: IL_0002: call System.Void UEFI.Code.ReducibleNode::.ctor(System.Int32) */
    UEFI_Code_ReducibleNode__ctor((UEFI_Code_ReducibleNode*)__stack0_0, __stack1_0);
    /* Path=1, Unique=0: IL_0007: nop */
    /* Path=1, Unique=0: IL_0008: nop */
    /* Path=1, Unique=0: IL_0009: ldarg.0 */
    __stack0_0 = __this;
    /* Path=1, Unique=0: IL_000a: ldarg.1 */
    __stack1_0 = numeric;
    /* Path=1, Unique=0: IL_000b: stfld System.Int32 UEFI.Code.NumericNode::Numeric */
    __stack0_0->Numeric = __stack1_0;
    /* Path=1, Unique=0: IL_0010: ret */
    __gc_unlink_execution_frame__(&__executionFrame__);
    return;
}

///////////////////////////////////////
// Virtual: Reduce

int32_t __UEFI_Code_NumericNode_Reduce__(UEFI_Code_NumericNode* __this)
{
    //-------------------
    // Local variables:

    int32_t local0;

    //-------------------
    // Evaluation stacks:

    UEFI_Code_NumericNode* __stack0_0 = NULL;
    int32_t __stack0_1;

    //-------------------
    // Setup stack frame:

    struct /* __EXECUTION_FRAME__ */
    {
        __EXECUTION_FRAME__* pNext;
        uint8_t targetCount;
        UEFI_Code_NumericNode** p__stack0_0;
    } __executionFrame__;

    __executionFrame__.targetCount = 1;
    __executionFrame__.p__stack0_0 = &__stack0_0;
    __gc_link_execution_frame__(&__executionFrame__);

    //-------------------
    // IL body:

    /* Path=1, Unique=0: IL_0000: nop */
    /* Path=1, Unique=0: IL_0001: ldarg.0 */
    __stack0_0 = __this;
    /* Path=1, Unique=0: IL_0002: ldfld System.Int32 UEFI.Code.NumericNode::Numeric */
    __stack0_1 = __stack0_0->Numeric;
    /* Path=1, Unique=0: IL_0007: stloc.0 */
    local0 = __stack0_1;
    /* Path=1, Unique=0: IL_0008: br.s IL_000a */
    goto IL_000a;
IL_000a:
    /* Path=2, Unique=0: IL_000a: ldloc.0 */
    __stack0_1 = local0;
    /* Path=2, Unique=0: IL_000b: ret */
    __gc_unlink_execution_frame__(&__executionFrame__);
    return __stack0_1;
}

//////////////////////
// Runtime helpers:

static void __UEFI_Code_NumericNode_MARK_HANDLER__(void* pReference)
{
    __typeof__(UEFI_Code_ReducibleNode)->pMarkHandler(pReference);
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
const __RUNTIME_TYPE__ __UEFI_Code_NumericNode_RUNTIME_TYPE__ =
   (const __RUNTIME_TYPE__)(&__UEFI_Code_NumericNode_RUNTIME_TYPE_DEF__);

////////////////////////////////////////////////////////////
// Type: UEFI.Code.ExpressionNode

///////////////////////////////////////
// .ctor

void UEFI_Code_ExpressionNode__ctor(UEFI_Code_ExpressionNode* __this, UEFI_Code_OperatorNode* oper, UEFI_Code_ReducibleNode* left, UEFI_Code_ReducibleNode* right, int32_t nextIndex)
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

    struct /* __EXECUTION_FRAME__ */
    {
        __EXECUTION_FRAME__* pNext;
        uint8_t targetCount;
        UEFI_Code_ExpressionNode** p__stack0_0;
        UEFI_Code_OperatorNode** p__stack1_1;
        UEFI_Code_ReducibleNode** p__stack1_2;
    } __executionFrame__;

    __executionFrame__.targetCount = 3;
    __executionFrame__.p__stack0_0 = &__stack0_0;
    __executionFrame__.p__stack1_1 = &__stack1_1;
    __executionFrame__.p__stack1_2 = &__stack1_2;
    __gc_link_execution_frame__(&__executionFrame__);

    //-------------------
    // IL body:

    /* Path=1, Unique=0: IL_0000: ldarg.0 */
    __stack0_0 = __this;
    /* Path=1, Unique=0: IL_0001: ldarg.s nextIndex */
    __stack1_0 = nextIndex;
    /* Path=1, Unique=0: IL_0003: call System.Void UEFI.Code.ReducibleNode::.ctor(System.Int32) */
    UEFI_Code_ReducibleNode__ctor((UEFI_Code_ReducibleNode*)__stack0_0, __stack1_0);
    /* Path=1, Unique=0: IL_0008: nop */
    /* Path=1, Unique=0: IL_0009: nop */
    /* Path=1, Unique=0: IL_000a: ldarg.0 */
    __stack0_0 = __this;
    /* Path=1, Unique=0: IL_000b: ldarg.1 */
    __stack1_1 = oper;
    /* Path=1, Unique=0: IL_000c: stfld UEFI.Code.OperatorNode UEFI.Code.ExpressionNode::Operator */
    __stack0_0->Operator = __stack1_1;
    /* Path=1, Unique=0: IL_0011: ldarg.0 */
    __stack0_0 = __this;
    /* Path=1, Unique=0: IL_0012: ldarg.2 */
    __stack1_2 = left;
    /* Path=1, Unique=0: IL_0013: stfld UEFI.Code.ReducibleNode UEFI.Code.ExpressionNode::Left */
    __stack0_0->Left = __stack1_2;
    /* Path=1, Unique=0: IL_0018: ldarg.0 */
    __stack0_0 = __this;
    /* Path=1, Unique=0: IL_0019: ldarg.3 */
    __stack1_2 = right;
    /* Path=1, Unique=0: IL_001a: stfld UEFI.Code.ReducibleNode UEFI.Code.ExpressionNode::Right */
    __stack0_0->Right = __stack1_2;
    /* Path=1, Unique=0: IL_001f: ret */
    __gc_unlink_execution_frame__(&__executionFrame__);
    return;
}

///////////////////////////////////////
// Virtual: Reduce

int32_t __UEFI_Code_ExpressionNode_Reduce__(UEFI_Code_ExpressionNode* __this)
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

    UEFI_Code_ExpressionNode* __stack0_0 = NULL;
    UEFI_Code_ReducibleNode* __stack0_1 = NULL;
    int32_t __stack0_2;
    UEFI_Code_OperatorNode* __stack0_3 = NULL;
    int32_t __stack1_0;

    //-------------------
    // Setup stack frame:

    struct /* __EXECUTION_FRAME__ */
    {
        __EXECUTION_FRAME__* pNext;
        uint8_t targetCount;
        UEFI_Code_ExpressionNode** p__stack0_0;
        UEFI_Code_ReducibleNode** p__stack0_1;
        UEFI_Code_OperatorNode** p__stack0_3;
    } __executionFrame__;

    __executionFrame__.targetCount = 3;
    __executionFrame__.p__stack0_0 = &__stack0_0;
    __executionFrame__.p__stack0_1 = &__stack0_1;
    __executionFrame__.p__stack0_3 = &__stack0_3;
    __gc_link_execution_frame__(&__executionFrame__);

    //-------------------
    // IL body:

    /* Path=1, Unique=0: IL_0000: nop */
    /* Path=1, Unique=0: IL_0001: ldarg.0 */
    __stack0_0 = __this;
    /* Path=1, Unique=0: IL_0002: ldfld UEFI.Code.ReducibleNode UEFI.Code.ExpressionNode::Left */
    __stack0_1 = __stack0_0->Left;
    /* Path=1, Unique=0: IL_0007: callvirt System.Int32 UEFI.Code.ReducibleNode::Reduce() */
    __stack0_2 = UEFI_Code_ReducibleNode_Reduce(__stack0_1);
    /* Path=1, Unique=0: IL_000c: stloc.0 */
    local0 = __stack0_2;
    /* Path=1, Unique=0: IL_000d: ldarg.0 */
    __stack0_0 = __this;
    /* Path=1, Unique=0: IL_000e: ldfld UEFI.Code.ReducibleNode UEFI.Code.ExpressionNode::Right */
    __stack0_1 = __stack0_0->Right;
    /* Path=1, Unique=0: IL_0013: callvirt System.Int32 UEFI.Code.ReducibleNode::Reduce() */
    __stack0_2 = UEFI_Code_ReducibleNode_Reduce(__stack0_1);
    /* Path=1, Unique=0: IL_0018: stloc.1 */
    local1 = __stack0_2;
    /* Path=1, Unique=0: IL_0019: ldarg.0 */
    __stack0_0 = __this;
    /* Path=1, Unique=0: IL_001a: ldfld UEFI.Code.OperatorNode UEFI.Code.ExpressionNode::Operator */
    __stack0_3 = __stack0_0->Operator;
    /* Path=1, Unique=0: IL_001f: ldfld System.Char UEFI.Code.OperatorNode::Operator */
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
    /* Path=2, Unique=0: IL_0033: ldarg.0 */
    __stack0_0 = __this;
    /* Path=2, Unique=0: IL_0034: ldfld UEFI.Code.OperatorNode UEFI.Code.ExpressionNode::Operator */
    __stack0_3 = __stack0_0->Operator;
    /* Path=2, Unique=0: IL_0039: ldfld System.Char UEFI.Code.OperatorNode::Operator */
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
    /* Path=4, Unique=0: IL_004f: ldarg.0 */
    __stack0_0 = __this;
    /* Path=4, Unique=0: IL_0050: ldfld UEFI.Code.OperatorNode UEFI.Code.ExpressionNode::Operator */
    __stack0_3 = __stack0_0->Operator;
    /* Path=4, Unique=0: IL_0055: ldfld System.Char UEFI.Code.OperatorNode::Operator */
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
    /* Path=5, Unique=0: IL_006b: ldarg.0 */
    __stack0_0 = __this;
    /* Path=5, Unique=0: IL_006c: ldfld UEFI.Code.OperatorNode UEFI.Code.ExpressionNode::Operator */
    __stack0_3 = __stack0_0->Operator;
    /* Path=5, Unique=0: IL_0071: ldfld System.Char UEFI.Code.OperatorNode::Operator */
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
    /* Path=6, Unique=0: IL_0087: ldc.i4.0 */
    __stack0_2 = 0;
    /* Path=6, Unique=0: IL_0088: stloc.3 */
    local3 = __stack0_2;
    /* Path=6, Unique=0: IL_0089: br.s IL_008b */
    goto IL_008b;
IL_008b:
    /* Path=3, Unique=0: IL_008b: ldloc.3 */
    __stack0_2 = local3;
    /* Path=3, Unique=0: IL_008c: ret */
    __gc_unlink_execution_frame__(&__executionFrame__);
    return __stack0_2;
}

//////////////////////
// Runtime helpers:

static void __UEFI_Code_ExpressionNode_MARK_HANDLER__(void* pReference)
{
    __TRY_MARK_FROM_HANDLER__(((UEFI_Code_ExpressionNode*)pReference)->Operator);
    __TRY_MARK_FROM_HANDLER__(((UEFI_Code_ExpressionNode*)pReference)->Left);
    __TRY_MARK_FROM_HANDLER__(((UEFI_Code_ExpressionNode*)pReference)->Right);
    __typeof__(UEFI_Code_ReducibleNode)->pMarkHandler(pReference);
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
const __RUNTIME_TYPE__ __UEFI_Code_ExpressionNode_RUNTIME_TYPE__ =
   (const __RUNTIME_TYPE__)(&__UEFI_Code_ExpressionNode_RUNTIME_TYPE_DEF__);

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

    struct /* __EXECUTION_FRAME__ */
    {
        __EXECUTION_FRAME__* pNext;
        uint8_t targetCount;
        System_String** p__stack0_1;
        System_String** p__stack1_0;
    } __executionFrame__;

    __executionFrame__.targetCount = 2;
    __executionFrame__.p__stack0_1 = &__stack0_1;
    __executionFrame__.p__stack1_0 = &__stack1_0;
    __gc_link_execution_frame__(&__executionFrame__);

    //-------------------
    // IL body:

    /* Path=1, Unique=0: IL_0000: nop */
    /* Path=1, Unique=0: IL_0001: ldarg.1 */
    __stack0_0 = startIndex;
    /* Path=1, Unique=0: IL_0002: stloc.0 */
    local0 = __stack0_0;
    /* Path=1, Unique=0: IL_0003: br.s IL_002a */
    goto IL_002a;
IL_0005:
    /* Path=3, Unique=0: IL_0005: nop */
    /* Path=3, Unique=0: IL_0006: ldarg.0 */
    __stack0_1 = line;
    /* Path=3, Unique=0: IL_0007: ldloc.0 */
    __stack1_2 = local0;
    /* Path=3, Unique=0: IL_0008: callvirt System.Char System.String::get_Chars(System.Int32) */
    __stack0_2 = System_String_get_Chars(__stack0_1, __stack1_2);
    /* Path=3, Unique=0: IL_000d: stloc.1 */
    local1 = (wchar_t)__stack0_2;
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
    /* Path=5, Unique=0: IL_0022: nop */
    /* Path=5, Unique=0: IL_0023: br.s IL_0037 */
    goto IL_0037;
IL_0025:
    /* Path=6, Unique=0: IL_0025: ldloc.0 */
    __stack0_0 = local0;
    /* Path=6, Unique=0: IL_0026: ldc.i4.1 */
    __stack1_2 = 1;
    /* Path=6, Unique=0: IL_0027: add */
    __stack0_0 = __stack0_0 + __stack1_2;
    /* Path=6, Unique=0: IL_0028: stloc.0 */
    local0 = __stack0_0;
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
    /* Path=2, Unique=0: IL_0037: ldloc.0 */
    __stack0_0 = local0;
    /* Path=2, Unique=0: IL_0038: stloc.s local4 */
    local4 = __stack0_0;
    /* Path=2, Unique=0: IL_003a: br.s IL_003c */
    goto IL_003c;
IL_003c:
    /* Path=4, Unique=0: IL_003c: ldloc.s local4 */
    __stack0_0 = local4;
    /* Path=4, Unique=0: IL_003e: ret */
    __gc_unlink_execution_frame__(&__executionFrame__);
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
    bool local2;
    UEFI_Code_OperatorNode* local3 = NULL;
    bool local4;

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

    struct /* __EXECUTION_FRAME__ */
    {
        __EXECUTION_FRAME__* pNext;
        uint8_t targetCount;
        UEFI_Code_OperatorNode** plocal3;
        IL2C_CecilHelper_PseudoZeroType** p__stack0_1;
        System_String** p__stack0_2;
        UEFI_Code_OperatorNode** p__stack0_4;
        System_String** p__stack1_0;
    } __executionFrame__;

    __executionFrame__.targetCount = 5;
    __executionFrame__.plocal3 = &local3;
    __executionFrame__.p__stack0_1 = &__stack0_1;
    __executionFrame__.p__stack0_2 = &__stack0_2;
    __executionFrame__.p__stack0_4 = &__stack0_4;
    __executionFrame__.p__stack1_0 = &__stack1_0;
    __gc_link_execution_frame__(&__executionFrame__);

    //-------------------
    // IL body:

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
    /* Path=1, Unique=0: IL_0011: nop */
    /* Path=1, Unique=0: IL_0012: ldnull */
    __stack0_1 = NULL;
    /* Path=1, Unique=0: IL_0013: stloc.3 */
    local3 = (UEFI_Code_OperatorNode*)__stack0_1;
    /* Path=1, Unique=0: IL_0014: br.s IL_005b */
    goto IL_005b;
IL_0016:
    /* Path=2, Unique=0: IL_0016: ldarg.1 */
    __stack0_0 = startIndex;
    /* Path=2, Unique=0: IL_0017: stloc.0 */
    local0 = __stack0_0;
    /* Path=2, Unique=0: IL_0018: ldarg.0 */
    __stack0_2 = line;
    /* Path=2, Unique=0: IL_0019: ldloc.0 */
    __stack1_2 = local0;
    /* Path=2, Unique=0: IL_001a: callvirt System.Char System.String::get_Chars(System.Int32) */
    __stack0_3 = System_String_get_Chars(__stack0_2, __stack1_2);
    /* Path=2, Unique=0: IL_001f: stloc.1 */
    local1 = (wchar_t)__stack0_3;
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
    /* Path=4, Unique=0: IL_0040: nop */
    /* Path=4, Unique=0: IL_0041: ldnull */
    __stack0_1 = NULL;
    /* Path=4, Unique=0: IL_0042: stloc.3 */
    local3 = (UEFI_Code_OperatorNode*)__stack0_1;
    /* Path=4, Unique=0: IL_0043: br.s IL_005b */
    goto IL_005b;
IL_0045:
    /* Path=5, Unique=0: IL_0045: ldloc.0 */
    __stack0_0 = local0;
    /* Path=5, Unique=0: IL_0046: ldc.i4.1 */
    __stack1_2 = 1;
    /* Path=5, Unique=0: IL_0047: add */
    __stack0_0 = __stack0_0 + __stack1_2;
    /* Path=5, Unique=0: IL_0048: stloc.0 */
    local0 = __stack0_0;
    /* Path=5, Unique=0: IL_0049: ldarg.0 */
    __stack0_2 = line;
    /* Path=5, Unique=0: IL_004a: ldloc.0 */
    __stack1_2 = local0;
    /* Path=5, Unique=0: IL_004b: call System.Int32 UEFI.Code.PolishNotation::SkipWhiteSpace(System.String,System.Int32) */
    __stack0_0 = UEFI_Code_PolishNotation_SkipWhiteSpace(__stack0_2, __stack1_2);
    /* Path=5, Unique=0: IL_0050: stloc.0 */
    local0 = __stack0_0;
    /* Path=5, Unique=0: IL_0051: ldloc.1 */
    __stack0_0 = local1;
    /* Path=5, Unique=0: IL_0052: ldloc.0 */
    __stack1_2 = local0;
    /* Path=5, Unique=0: IL_0053: newobj System.Void UEFI.Code.OperatorNode::.ctor(System.Char,System.Int32) */
    __stack0_4 = __gc_get_uninitialized_object__(__typeof__(UEFI_Code_OperatorNode));
    UEFI_Code_OperatorNode__ctor(__stack0_4, (wchar_t)__stack0_0, __stack1_2);
    /* Path=5, Unique=0: IL_0058: stloc.3 */
    local3 = __stack0_4;
    /* Path=5, Unique=0: IL_0059: br.s IL_005b */
    goto IL_005b;
IL_005b:
    /* Path=3, Unique=0: IL_005b: ldloc.3 */
    __stack0_4 = local3;
    /* Path=3, Unique=0: IL_005c: ret */
    __gc_unlink_execution_frame__(&__executionFrame__);
    return __stack0_4;
}

///////////////////////////////////////
// ParseNumeric

UEFI_Code_NumericNode* UEFI_Code_PolishNotation_ParseNumeric(System_String* line, int32_t startIndex)
{
    //-------------------
    // Local variables:

    int32_t local0;
    System_String* local1 = NULL;
    int32_t local2;
    bool local3;
    UEFI_Code_NumericNode* local4 = NULL;
    wchar_t local5;
    bool local6;
    bool local7;
    bool local8;
    bool local9;

    //-------------------
    // Evaluation stacks:

    int32_t __stack0_0;
    IL2C_CecilHelper_PseudoZeroType* __stack0_1 = NULL;
    UEFI_Code_NumericNode* __stack0_2 = NULL;
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

    struct /* __EXECUTION_FRAME__ */
    {
        __EXECUTION_FRAME__* pNext;
        uint8_t targetCount;
        System_String** plocal1;
        UEFI_Code_NumericNode** plocal4;
        IL2C_CecilHelper_PseudoZeroType** p__stack0_1;
        UEFI_Code_NumericNode** p__stack0_2;
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
    __gc_link_execution_frame__(&__executionFrame__);

    //-------------------
    // IL body:

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
    /* Path=1, Unique=0: IL_0011: nop */
    /* Path=1, Unique=0: IL_0012: ldnull */
    __stack0_1 = NULL;
    /* Path=1, Unique=0: IL_0013: stloc.s local4 */
    local4 = (UEFI_Code_NumericNode*)__stack0_1;
    /* Path=1, Unique=0: IL_0015: br.s IL_008d */
    goto IL_008d;
IL_0017:
    /* Path=2, Unique=0: IL_0017: ldarg.1 */
    __stack0_0 = startIndex;
    /* Path=2, Unique=0: IL_0018: stloc.0 */
    local0 = __stack0_0;
    /* Path=2, Unique=0: IL_0019: br.s IL_0039 */
    goto IL_0039;
IL_001b:
    /* Path=5, Unique=0: IL_001b: nop */
    /* Path=5, Unique=0: IL_001c: ldarg.0 */
    __stack0_3 = line;
    /* Path=5, Unique=0: IL_001d: ldloc.0 */
    __stack1_2 = local0;
    /* Path=5, Unique=0: IL_001e: callvirt System.Char System.String::get_Chars(System.Int32) */
    __stack0_4 = System_String_get_Chars(__stack0_3, __stack1_2);
    /* Path=5, Unique=0: IL_0023: stloc.s local5 */
    local5 = (wchar_t)__stack0_4;
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
    /* Path=5, Unique=0: IL_0031: nop */
    /* Path=5, Unique=0: IL_0032: br.s IL_0048 */
    goto IL_0048;
IL_0034:
    /* Path=7, Unique=0: IL_0034: ldloc.0 */
    __stack0_0 = local0;
    /* Path=7, Unique=0: IL_0035: ldc.i4.1 */
    __stack1_2 = 1;
    /* Path=7, Unique=0: IL_0036: add */
    __stack0_0 = __stack0_0 + __stack1_2;
    /* Path=7, Unique=0: IL_0037: stloc.0 */
    local0 = __stack0_0;
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
    /* Path=4, Unique=0: IL_0052: nop */
    /* Path=4, Unique=0: IL_0053: ldnull */
    __stack0_1 = NULL;
    /* Path=4, Unique=0: IL_0054: stloc.s local4 */
    local4 = (UEFI_Code_NumericNode*)__stack0_1;
    /* Path=4, Unique=0: IL_0056: br.s IL_008d */
    goto IL_008d;
IL_0058:
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
    /* Path=6, Unique=0: IL_0074: nop */
    /* Path=6, Unique=0: IL_0075: ldnull */
    __stack0_1 = NULL;
    /* Path=6, Unique=0: IL_0076: stloc.s local4 */
    local4 = (UEFI_Code_NumericNode*)__stack0_1;
    /* Path=6, Unique=0: IL_0078: br.s IL_008d */
    goto IL_008d;
IL_007a:
    /* Path=8, Unique=0: IL_007a: ldarg.0 */
    __stack0_3 = line;
    /* Path=8, Unique=0: IL_007b: ldloc.0 */
    __stack1_2 = local0;
    /* Path=8, Unique=0: IL_007c: call System.Int32 UEFI.Code.PolishNotation::SkipWhiteSpace(System.String,System.Int32) */
    __stack0_0 = UEFI_Code_PolishNotation_SkipWhiteSpace(__stack0_3, __stack1_2);
    /* Path=8, Unique=0: IL_0081: stloc.0 */
    local0 = __stack0_0;
    /* Path=8, Unique=0: IL_0082: ldloc.2 */
    __stack0_0 = local2;
    /* Path=8, Unique=0: IL_0083: ldloc.0 */
    __stack1_2 = local0;
    /* Path=8, Unique=0: IL_0084: newobj System.Void UEFI.Code.NumericNode::.ctor(System.Int32,System.Int32) */
    __stack0_2 = __gc_get_uninitialized_object__(__typeof__(UEFI_Code_NumericNode));
    UEFI_Code_NumericNode__ctor(__stack0_2, __stack0_0, __stack1_2);
    /* Path=8, Unique=0: IL_0089: stloc.s local4 */
    local4 = __stack0_2;
    /* Path=8, Unique=0: IL_008b: br.s IL_008d */
    goto IL_008d;
IL_008d:
    /* Path=3, Unique=0: IL_008d: ldloc.s local4 */
    __stack0_2 = local4;
    /* Path=3, Unique=0: IL_008f: ret */
    __gc_unlink_execution_frame__(&__executionFrame__);
    return __stack0_2;
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
    bool local4;
    UEFI_Code_ExpressionNode* local5 = NULL;
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
    UEFI_Code_OperatorNode* __stack0_3 = NULL;
    UEFI_Code_ExpressionNode* __stack0_4 = NULL;
    UEFI_Code_NumericNode* __stack0_5 = NULL;
    UEFI_Code_ReducibleNode* __stack0_6 = NULL;
    System_String* __stack1_0 = NULL;
    int32_t __stack1_1;
    int32_t __stack1_2;
    IL2C_CecilHelper_PseudoZeroType* __stack1_3 = NULL;
    UEFI_Code_OperatorNode* __stack1_4 = NULL;
    UEFI_Code_ReducibleNode* __stack1_5 = NULL;
    UEFI_Code_ReducibleNode* __stack2_0 = NULL;
    int32_t __stack3_0;

    //-------------------
    // Setup stack frame:

    struct /* __EXECUTION_FRAME__ */
    {
        __EXECUTION_FRAME__* pNext;
        uint8_t targetCount;
        UEFI_Code_OperatorNode** plocal0;
        UEFI_Code_ReducibleNode** plocal1;
        UEFI_Code_ReducibleNode** plocal2;
        UEFI_Code_ExpressionNode** plocal5;
        IL2C_CecilHelper_PseudoZeroType** p__stack0_1;
        System_String** p__stack0_2;
        UEFI_Code_OperatorNode** p__stack0_3;
        UEFI_Code_ExpressionNode** p__stack0_4;
        UEFI_Code_NumericNode** p__stack0_5;
        UEFI_Code_ReducibleNode** p__stack0_6;
        System_String** p__stack1_0;
        IL2C_CecilHelper_PseudoZeroType** p__stack1_3;
        UEFI_Code_OperatorNode** p__stack1_4;
        UEFI_Code_ReducibleNode** p__stack1_5;
        UEFI_Code_ReducibleNode** p__stack2_0;
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
    __gc_link_execution_frame__(&__executionFrame__);

    //-------------------
    // IL body:

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
    /* Path=1, Unique=0: IL_0013: nop */
    /* Path=1, Unique=0: IL_0014: ldnull */
    __stack0_1 = NULL;
    /* Path=1, Unique=0: IL_0015: stloc.s local5 */
    local5 = (UEFI_Code_ExpressionNode*)__stack0_1;
    /* Path=1, Unique=0: IL_0017: br IL_00bd */
    goto IL_00bd;
IL_001c:
    /* Path=2, Unique=0: IL_001c: ldarg.0 */
    __stack0_2 = line;
    /* Path=2, Unique=0: IL_001d: ldarg.1 */
    __stack1_2 = startIndex;
    /* Path=2, Unique=0: IL_001e: call UEFI.Code.OperatorNode UEFI.Code.PolishNotation::ParseOperator(System.String,System.Int32) */
    __stack0_3 = UEFI_Code_PolishNotation_ParseOperator(__stack0_2, __stack1_2);
    /* Path=2, Unique=0: IL_0023: stloc.0 */
    local0 = __stack0_3;
    /* Path=2, Unique=0: IL_0024: ldloc.0 */
    __stack0_3 = local0;
    /* Path=2, Unique=0: IL_0025: ldnull */
    __stack1_3 = NULL;
    /* Path=2, Unique=0: IL_0026: ceq */
    __stack0_0 = (__stack0_3 == ((UEFI_Code_OperatorNode*)__stack1_3)) ? 1 : 0;
    /* Path=2, Unique=0: IL_0028: stloc.s local6 */
    local6 = __stack0_0 ? true : false;
    /* Path=2, Unique=0: IL_002a: ldloc.s local6 */
    __stack0_0 = local6;
    /* Path=2, Unique=0: IL_002c: brfalse.s IL_0037 */
    if (__stack0_0 == 0) goto IL_0037;
    /* Path=2, Unique=0: IL_002e: nop */
    /* Path=2, Unique=0: IL_002f: ldnull */
    __stack0_1 = NULL;
    /* Path=2, Unique=0: IL_0030: stloc.s local5 */
    local5 = (UEFI_Code_ExpressionNode*)__stack0_1;
    /* Path=2, Unique=0: IL_0032: br IL_00bd */
    goto IL_00bd;
IL_0037:
    /* Path=4, Unique=0: IL_0037: ldarg.0 */
    __stack0_2 = line;
    /* Path=4, Unique=0: IL_0038: ldloc.0 */
    __stack1_4 = local0;
    /* Path=4, Unique=0: IL_0039: ldfld System.Int32 UEFI.Code.AbstractNode::NextIndex */
    __stack1_2 = __stack1_4->NextIndex;
    /* Path=4, Unique=0: IL_003e: call UEFI.Code.NumericNode UEFI.Code.PolishNotation::ParseNumeric(System.String,System.Int32) */
    __stack0_5 = UEFI_Code_PolishNotation_ParseNumeric(__stack0_2, __stack1_2);
    /* Path=4, Unique=0: IL_0043: stloc.1 */
    local1 = (UEFI_Code_ReducibleNode*)__stack0_5;
    /* Path=4, Unique=0: IL_0044: ldloc.1 */
    __stack0_6 = local1;
    /* Path=4, Unique=0: IL_0045: ldnull */
    __stack1_3 = NULL;
    /* Path=4, Unique=0: IL_0046: ceq */
    __stack0_0 = (__stack0_6 == ((UEFI_Code_ReducibleNode*)__stack1_3)) ? 1 : 0;
    /* Path=4, Unique=0: IL_0048: stloc.s local7 */
    local7 = __stack0_0 ? true : false;
    /* Path=4, Unique=0: IL_004a: ldloc.s local7 */
    __stack0_0 = local7;
    /* Path=4, Unique=0: IL_004c: brfalse.s IL_006d */
    if (__stack0_0 == 0) goto IL_006d;
    /* Path=4, Unique=0: IL_004e: nop */
    /* Path=4, Unique=0: IL_004f: ldarg.0 */
    __stack0_2 = line;
    /* Path=4, Unique=0: IL_0050: ldloc.0 */
    __stack1_4 = local0;
    /* Path=4, Unique=0: IL_0051: ldfld System.Int32 UEFI.Code.AbstractNode::NextIndex */
    __stack1_2 = __stack1_4->NextIndex;
    /* Path=4, Unique=0: IL_0056: call UEFI.Code.ExpressionNode UEFI.Code.PolishNotation::ParseExpression(System.String,System.Int32) */
    __stack0_4 = UEFI_Code_PolishNotation_ParseExpression(__stack0_2, __stack1_2);
    /* Path=4, Unique=0: IL_005b: stloc.1 */
    local1 = (UEFI_Code_ReducibleNode*)__stack0_4;
    /* Path=4, Unique=0: IL_005c: ldloc.1 */
    __stack0_6 = local1;
    /* Path=4, Unique=0: IL_005d: ldnull */
    __stack1_3 = NULL;
    /* Path=4, Unique=0: IL_005e: ceq */
    __stack0_0 = (__stack0_6 == ((UEFI_Code_ReducibleNode*)__stack1_3)) ? 1 : 0;
    /* Path=4, Unique=0: IL_0060: stloc.s local8 */
    local8 = __stack0_0 ? true : false;
    /* Path=4, Unique=0: IL_0062: ldloc.s local8 */
    __stack0_0 = local8;
    /* Path=4, Unique=0: IL_0064: brfalse.s IL_006c */
    if (__stack0_0 == 0) goto IL_006c;
    /* Path=4, Unique=0: IL_0066: nop */
    /* Path=4, Unique=0: IL_0067: ldnull */
    __stack0_1 = NULL;
    /* Path=4, Unique=0: IL_0068: stloc.s local5 */
    local5 = (UEFI_Code_ExpressionNode*)__stack0_1;
    /* Path=4, Unique=0: IL_006a: br.s IL_00bd */
    goto IL_00bd;
IL_006c:
    /* Path=6, Unique=0: IL_006c: nop */
IL_006d:
    /* Path=5, Unique=0: IL_006d: ldarg.0 */
    __stack0_2 = line;
    /* Path=5, Unique=0: IL_006e: ldloc.1 */
    __stack1_5 = local1;
    /* Path=5, Unique=0: IL_006f: ldfld System.Int32 UEFI.Code.AbstractNode::NextIndex */
    __stack1_2 = __stack1_5->NextIndex;
    /* Path=5, Unique=0: IL_0074: call UEFI.Code.NumericNode UEFI.Code.PolishNotation::ParseNumeric(System.String,System.Int32) */
    __stack0_5 = UEFI_Code_PolishNotation_ParseNumeric(__stack0_2, __stack1_2);
    /* Path=5, Unique=0: IL_0079: stloc.2 */
    local2 = (UEFI_Code_ReducibleNode*)__stack0_5;
    /* Path=5, Unique=0: IL_007a: ldloc.2 */
    __stack0_6 = local2;
    /* Path=5, Unique=0: IL_007b: ldnull */
    __stack1_3 = NULL;
    /* Path=5, Unique=0: IL_007c: ceq */
    __stack0_0 = (__stack0_6 == ((UEFI_Code_ReducibleNode*)__stack1_3)) ? 1 : 0;
    /* Path=5, Unique=0: IL_007e: stloc.s local9 */
    local9 = __stack0_0 ? true : false;
    /* Path=5, Unique=0: IL_0080: ldloc.s local9 */
    __stack0_0 = local9;
    /* Path=5, Unique=0: IL_0082: brfalse.s IL_00a3 */
    if (__stack0_0 == 0) goto IL_00a3;
    /* Path=5, Unique=0: IL_0084: nop */
    /* Path=5, Unique=0: IL_0085: ldarg.0 */
    __stack0_2 = line;
    /* Path=5, Unique=0: IL_0086: ldloc.1 */
    __stack1_5 = local1;
    /* Path=5, Unique=0: IL_0087: ldfld System.Int32 UEFI.Code.AbstractNode::NextIndex */
    __stack1_2 = __stack1_5->NextIndex;
    /* Path=5, Unique=0: IL_008c: call UEFI.Code.ExpressionNode UEFI.Code.PolishNotation::ParseExpression(System.String,System.Int32) */
    __stack0_4 = UEFI_Code_PolishNotation_ParseExpression(__stack0_2, __stack1_2);
    /* Path=5, Unique=0: IL_0091: stloc.2 */
    local2 = (UEFI_Code_ReducibleNode*)__stack0_4;
    /* Path=5, Unique=0: IL_0092: ldloc.2 */
    __stack0_6 = local2;
    /* Path=5, Unique=0: IL_0093: ldnull */
    __stack1_3 = NULL;
    /* Path=5, Unique=0: IL_0094: ceq */
    __stack0_0 = (__stack0_6 == ((UEFI_Code_ReducibleNode*)__stack1_3)) ? 1 : 0;
    /* Path=5, Unique=0: IL_0096: stloc.s local10 */
    local10 = __stack0_0 ? true : false;
    /* Path=5, Unique=0: IL_0098: ldloc.s local10 */
    __stack0_0 = local10;
    /* Path=5, Unique=0: IL_009a: brfalse.s IL_00a2 */
    if (__stack0_0 == 0) goto IL_00a2;
    /* Path=5, Unique=0: IL_009c: nop */
    /* Path=5, Unique=0: IL_009d: ldnull */
    __stack0_1 = NULL;
    /* Path=5, Unique=0: IL_009e: stloc.s local5 */
    local5 = (UEFI_Code_ExpressionNode*)__stack0_1;
    /* Path=5, Unique=0: IL_00a0: br.s IL_00bd */
    goto IL_00bd;
IL_00a2:
    /* Path=8, Unique=0: IL_00a2: nop */
IL_00a3:
    /* Path=7, Unique=0: IL_00a3: ldarg.0 */
    __stack0_2 = line;
    /* Path=7, Unique=0: IL_00a4: ldloc.2 */
    __stack1_5 = local2;
    /* Path=7, Unique=0: IL_00a5: ldfld System.Int32 UEFI.Code.AbstractNode::NextIndex */
    __stack1_2 = __stack1_5->NextIndex;
    /* Path=7, Unique=0: IL_00aa: call System.Int32 UEFI.Code.PolishNotation::SkipWhiteSpace(System.String,System.Int32) */
    __stack0_0 = UEFI_Code_PolishNotation_SkipWhiteSpace(__stack0_2, __stack1_2);
    /* Path=7, Unique=0: IL_00af: stloc.3 */
    local3 = __stack0_0;
    /* Path=7, Unique=0: IL_00b0: ldloc.0 */
    __stack0_3 = local0;
    /* Path=7, Unique=0: IL_00b1: ldloc.1 */
    __stack1_5 = local1;
    /* Path=7, Unique=0: IL_00b2: ldloc.2 */
    __stack2_0 = local2;
    /* Path=7, Unique=0: IL_00b3: ldloc.3 */
    __stack3_0 = local3;
    /* Path=7, Unique=0: IL_00b4: newobj System.Void UEFI.Code.ExpressionNode::.ctor(UEFI.Code.OperatorNode,UEFI.Code.ReducibleNode,UEFI.Code.ReducibleNode,System.Int32) */
    __stack0_4 = __gc_get_uninitialized_object__(__typeof__(UEFI_Code_ExpressionNode));
    UEFI_Code_ExpressionNode__ctor(__stack0_4, __stack0_3, __stack1_5, __stack2_0, __stack3_0);
    /* Path=7, Unique=0: IL_00b9: stloc.s local5 */
    local5 = __stack0_4;
    /* Path=7, Unique=0: IL_00bb: br.s IL_00bd */
    goto IL_00bd;
IL_00bd:
    /* Path=3, Unique=0: IL_00bd: ldloc.s local5 */
    __stack0_4 = local5;
    /* Path=3, Unique=0: IL_00bf: ret */
    __gc_unlink_execution_frame__(&__executionFrame__);
    return __stack0_4;
}

///////////////////////////////////////
// Main

void UEFI_Code_PolishNotation_Main(void)
{
    //-------------------
    // Local variables:

    System_String* local0 = NULL;
    bool local1;
    UEFI_Code_ExpressionNode* local2 = NULL;
    int32_t local3;
    bool local4;
    bool local5;

    //-------------------
    // Evaluation stacks:

    int32_t __stack0_0;
    System_String* __stack0_1 = NULL;
    UEFI_Code_ExpressionNode* __stack0_2 = NULL;
    int32_t __stack1_0;
    IL2C_CecilHelper_PseudoZeroType* __stack1_1 = NULL;

    //-------------------
    // Setup stack frame:

    struct /* __EXECUTION_FRAME__ */
    {
        __EXECUTION_FRAME__* pNext;
        uint8_t targetCount;
        System_String** plocal0;
        UEFI_Code_ExpressionNode** plocal2;
        System_String** p__stack0_1;
        UEFI_Code_ExpressionNode** p__stack0_2;
        IL2C_CecilHelper_PseudoZeroType** p__stack1_1;
    } __executionFrame__;

    __executionFrame__.targetCount = 5;
    __executionFrame__.plocal0 = &local0;
    __executionFrame__.plocal2 = &local2;
    __executionFrame__.p__stack0_1 = &__stack0_1;
    __executionFrame__.p__stack0_2 = &__stack0_2;
    __executionFrame__.p__stack1_1 = &__stack1_1;
    __gc_link_execution_frame__(&__executionFrame__);

    //-------------------
    // IL body:

    /* Path=1, Unique=0: IL_0000: nop */
    /* Path=1, Unique=0: IL_0001: br.s IL_0064 */
    goto IL_0064;
IL_0003:
    /* Path=3, Unique=0: IL_0003: nop */
    /* Path=3, Unique=0: IL_0004: call System.Void System.Console::WriteLine() */
    System_Console_WriteLine();
    /* Path=3, Unique=0: IL_0009: nop */
    /* Path=3, Unique=0: IL_000a: ldstr "PN> " */
    __stack0_1 = __string0;
    /* Path=3, Unique=0: IL_000f: call System.Void System.Console::Write(System.String) */
    System_Console_Write_9(__stack0_1);
    /* Path=3, Unique=0: IL_0014: nop */
    /* Path=3, Unique=0: IL_0015: call System.String System.Console::ReadLine() */
    __stack0_1 = System_Console_ReadLine();
    /* Path=3, Unique=0: IL_001a: stloc.0 */
    local0 = __stack0_1;
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
    /* Path=3, Unique=0: IL_0026: brfalse.s IL_0063 */
    if (__stack0_0 == 0) goto IL_0063;
    /* Path=3, Unique=0: IL_0028: nop */
    /* Path=3, Unique=0: IL_0029: ldloc.0 */
    __stack0_1 = local0;
    /* Path=3, Unique=0: IL_002a: ldc.i4.0 */
    __stack1_0 = 0;
    /* Path=3, Unique=0: IL_002b: call UEFI.Code.ExpressionNode UEFI.Code.PolishNotation::ParseExpression(System.String,System.Int32) */
    __stack0_2 = UEFI_Code_PolishNotation_ParseExpression(__stack0_1, __stack1_0);
    /* Path=3, Unique=0: IL_0030: stloc.2 */
    local2 = __stack0_2;
    /* Path=3, Unique=0: IL_0031: ldloc.2 */
    __stack0_2 = local2;
    /* Path=3, Unique=0: IL_0032: ldnull */
    __stack1_1 = NULL;
    /* Path=3, Unique=0: IL_0033: ceq */
    __stack0_0 = (__stack0_2 == ((UEFI_Code_ExpressionNode*)__stack1_1)) ? 1 : 0;
    /* Path=3, Unique=0: IL_0035: stloc.s local4 */
    local4 = __stack0_0 ? true : false;
    /* Path=3, Unique=0: IL_0037: ldloc.s local4 */
    __stack0_0 = local4;
    /* Path=3, Unique=0: IL_0039: brfalse.s IL_0049 */
    if (__stack0_0 == 0) goto IL_0049;
    /* Path=3, Unique=0: IL_003b: nop */
    /* Path=3, Unique=0: IL_003c: ldstr "Syntax error." */
    __stack0_1 = __string1;
    /* Path=3, Unique=0: IL_0041: call System.Void System.Console::WriteLine(System.String) */
    System_Console_WriteLine_10(__stack0_1);
    /* Path=3, Unique=0: IL_0046: nop */
    /* Path=3, Unique=0: IL_0047: br.s IL_0064 */
    goto IL_0064;
IL_0049:
    /* Path=5, Unique=0: IL_0049: ldloc.2 */
    __stack0_2 = local2;
    /* Path=5, Unique=0: IL_004a: callvirt System.Int32 UEFI.Code.ReducibleNode::Reduce() */
    __stack0_0 = UEFI_Code_ReducibleNode_Reduce((UEFI_Code_ReducibleNode*)__stack0_2);
    /* Path=5, Unique=0: IL_004f: stloc.3 */
    local3 = __stack0_0;
    /* Path=5, Unique=0: IL_0050: ldstr "Reuslt=" */
    __stack0_1 = __string2;
    /* Path=5, Unique=0: IL_0055: call System.Void System.Console::Write(System.String) */
    System_Console_Write_9(__stack0_1);
    /* Path=5, Unique=0: IL_005a: nop */
    /* Path=5, Unique=0: IL_005b: ldloc.3 */
    __stack0_0 = local3;
    /* Path=5, Unique=0: IL_005c: call System.Void System.Console::WriteLine(System.Int32) */
    System_Console_WriteLine_6(__stack0_0);
    /* Path=5, Unique=0: IL_0061: nop */
    /* Path=5, Unique=0: IL_0062: nop */
IL_0063:
    /* Path=4, Unique=0: IL_0063: nop */
IL_0064:
    /* Path=2, Unique=0: IL_0064: ldc.i4.1 */
    __stack0_0 = 1;
    /* Path=2, Unique=0: IL_0065: stloc.s local5 */
    local5 = __stack0_0 ? true : false;
    /* Path=2, Unique=0: IL_0067: br.s IL_0003 */
    goto IL_0003;
}

///////////////////////////////////////
// .ctor

void UEFI_Code_PolishNotation__ctor(UEFI_Code_PolishNotation* __this)
{
    //-------------------
    // Local variables:


    //-------------------
    // Evaluation stacks:

    UEFI_Code_PolishNotation* __stack0_0 = NULL;

    //-------------------
    // Setup stack frame:

    struct /* __EXECUTION_FRAME__ */
    {
        __EXECUTION_FRAME__* pNext;
        uint8_t targetCount;
        UEFI_Code_PolishNotation** p__stack0_0;
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

static void __UEFI_Code_PolishNotation_MARK_HANDLER__(void* pReference)
{
    __typeof__(System_Object)->pMarkHandler(pReference);
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
const __RUNTIME_TYPE__ __UEFI_Code_PolishNotation_RUNTIME_TYPE__ =
   (const __RUNTIME_TYPE__)(&__UEFI_Code_PolishNotation_RUNTIME_TYPE_DEF__);
