#include "UEFI.Code.h"

//////////////////////////////////////////////////////////////////////////////////
// Const strings:

IL2C_CONST_STRING(string0__, L"PN> ");
IL2C_CONST_STRING(string1__, L"Syntax error.");
IL2C_CONST_STRING(string2__, L"Reuslt=");

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

    UEFI_Code_AbstractNode* stack0_0__ = NULL;
    int32_t stack1_0__;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        UEFI_Code_AbstractNode** pstack0_0__;
    } __executionFrame__;

    __executionFrame__.targetCount = 1;
    __executionFrame__.pstack0_0__ = &stack0_0__;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(13): */
    /* Path=1, Unique=0: IL_0000: ldarg.0 */
    stack0_0__ = this__;
    /* Path=1, Unique=0: IL_0001: call System.Void System.Object::.ctor() */
/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(15): */
    /* Path=1, Unique=0: IL_0006: ldarg.0 */
    stack0_0__ = this__;
    /* Path=1, Unique=0: IL_0007: ldarg.1 */
    stack1_0__ = nextIndex;
    /* Path=1, Unique=0: IL_0008: stfld System.Int32 UEFI.Code.AbstractNode::NextIndex */
    stack0_0__->NextIndex = stack1_0__;
/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(16): */
    /* Path=1, Unique=0: IL_000d: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return;
}

//////////////////////
// Runtime helpers:

// Runtime cast
void* __UEFI_Code_AbstractNode_IL2C_RuntimeCast__(UEFI_Code_AbstractNode* this__, IL2C_RUNTIME_TYPE_DECL* type)
{
    if (type == il2c_typeof(System_Object)) return this__;
    return __System_Object_IL2C_RuntimeCast__((System_Object*)this__, type);
}

// GC's mark handler
void __UEFI_Code_AbstractNode_IL2C_MarkHandler__(UEFI_Code_AbstractNode* this__)
{
    /* Suppressed invoke base mark handler */
}

static __UEFI_Code_AbstractNode_VTABLE_DECL__ __UEFI_Code_AbstractNode_VTABLE__ = {
    /* internalcall */ __UEFI_Code_AbstractNode_IL2C_RuntimeCast__,
    (void*)__System_Object_ToString__,
    (void*)__System_Object_GetHashCode__,
    (void*)__System_Object_Finalize__,
    (void*)__System_Object_Equals__,
};

IL2C_RUNTIME_TYPE_DECL __UEFI_Code_AbstractNode_RUNTIME_TYPE__ = {
    "UEFI.Code.AbstractNode",
    sizeof(UEFI_Code_AbstractNode),
    /* internalcall */ (void*)__UEFI_Code_AbstractNode_IL2C_MarkHandler__,
};

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

    UEFI_Code_OperatorNode* stack0_0__ = NULL;
    int32_t stack1_0__;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        UEFI_Code_OperatorNode** pstack0_0__;
    } __executionFrame__;

    __executionFrame__.targetCount = 1;
    __executionFrame__.pstack0_0__ = &stack0_0__;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(23): */
    /* Path=1, Unique=0: IL_0000: ldarg.0 */
    stack0_0__ = this__;
    /* Path=1, Unique=0: IL_0001: ldarg.2 */
    stack1_0__ = nextIndex;
    /* Path=1, Unique=0: IL_0002: call System.Void UEFI.Code.AbstractNode::.ctor(System.Int32) */
    UEFI_Code_AbstractNode__ctor((UEFI_Code_AbstractNode*)stack0_0__, stack1_0__);
/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(25): */
    /* Path=1, Unique=0: IL_0007: ldarg.0 */
    stack0_0__ = this__;
    /* Path=1, Unique=0: IL_0008: ldarg.1 */
    stack1_0__ = (int32_t)(oper);
    /* Path=1, Unique=0: IL_0009: stfld System.Char UEFI.Code.OperatorNode::Operator */
    stack0_0__->Operator = (wchar_t)stack1_0__;
/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(26): */
    /* Path=1, Unique=0: IL_000e: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return;
}

//////////////////////
// Runtime helpers:

// Runtime cast
void* __UEFI_Code_OperatorNode_IL2C_RuntimeCast__(UEFI_Code_OperatorNode* this__, IL2C_RUNTIME_TYPE_DECL* type)
{
    if (type == il2c_typeof(UEFI_Code_AbstractNode)) return this__;
    return __UEFI_Code_AbstractNode_IL2C_RuntimeCast__((UEFI_Code_AbstractNode*)this__, type);
}

// GC's mark handler
void __UEFI_Code_OperatorNode_IL2C_MarkHandler__(UEFI_Code_OperatorNode* this__)
{
    __UEFI_Code_AbstractNode_IL2C_MarkHandler__((UEFI_Code_AbstractNode*)this__);
}

static __UEFI_Code_OperatorNode_VTABLE_DECL__ __UEFI_Code_OperatorNode_VTABLE__ = {
    /* internalcall */ __UEFI_Code_OperatorNode_IL2C_RuntimeCast__,
    (void*)__System_Object_ToString__,
    (void*)__System_Object_GetHashCode__,
    (void*)__System_Object_Finalize__,
    (void*)__System_Object_Equals__,
};

IL2C_RUNTIME_TYPE_DECL __UEFI_Code_OperatorNode_RUNTIME_TYPE__ = {
    "UEFI.Code.OperatorNode",
    sizeof(UEFI_Code_OperatorNode),
    /* internalcall */ (void*)__UEFI_Code_OperatorNode_IL2C_MarkHandler__,
};

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

    UEFI_Code_ReducibleNode* stack0_0__ = NULL;
    int32_t stack1_0__;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        UEFI_Code_ReducibleNode** pstack0_0__;
    } __executionFrame__;

    __executionFrame__.targetCount = 1;
    __executionFrame__.pstack0_0__ = &stack0_0__;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(31): */
    /* Path=1, Unique=0: IL_0000: ldarg.0 */
    stack0_0__ = this__;
    /* Path=1, Unique=0: IL_0001: ldarg.1 */
    stack1_0__ = nextIndex;
    /* Path=1, Unique=0: IL_0002: call System.Void UEFI.Code.AbstractNode::.ctor(System.Int32) */
    UEFI_Code_AbstractNode__ctor((UEFI_Code_AbstractNode*)stack0_0__, stack1_0__);
/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(33): */
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

// Runtime cast
void* __UEFI_Code_ReducibleNode_IL2C_RuntimeCast__(UEFI_Code_ReducibleNode* this__, IL2C_RUNTIME_TYPE_DECL* type)
{
    if (type == il2c_typeof(UEFI_Code_AbstractNode)) return this__;
    return __UEFI_Code_AbstractNode_IL2C_RuntimeCast__((UEFI_Code_AbstractNode*)this__, type);
}

// GC's mark handler
void __UEFI_Code_ReducibleNode_IL2C_MarkHandler__(UEFI_Code_ReducibleNode* this__)
{
    __UEFI_Code_AbstractNode_IL2C_MarkHandler__((UEFI_Code_AbstractNode*)this__);
}

static __UEFI_Code_ReducibleNode_VTABLE_DECL__ __UEFI_Code_ReducibleNode_VTABLE__ = {
    /* internalcall */ __UEFI_Code_ReducibleNode_IL2C_RuntimeCast__,
    (void*)__System_Object_ToString__,
    (void*)__System_Object_GetHashCode__,
    (void*)__System_Object_Finalize__,
    (void*)__System_Object_Equals__,
    (void*)__UEFI_Code_ReducibleNode_Reduce__,
};

IL2C_RUNTIME_TYPE_DECL __UEFI_Code_ReducibleNode_RUNTIME_TYPE__ = {
    "UEFI.Code.ReducibleNode",
    sizeof(UEFI_Code_ReducibleNode),
    /* internalcall */ (void*)__UEFI_Code_ReducibleNode_IL2C_MarkHandler__,
};

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

    UEFI_Code_NumericNode* stack0_0__ = NULL;
    int32_t stack1_0__;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        UEFI_Code_NumericNode** pstack0_0__;
    } __executionFrame__;

    __executionFrame__.targetCount = 1;
    __executionFrame__.pstack0_0__ = &stack0_0__;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(42): */
    /* Path=1, Unique=0: IL_0000: ldarg.0 */
    stack0_0__ = this__;
    /* Path=1, Unique=0: IL_0001: ldarg.2 */
    stack1_0__ = nextIndex;
    /* Path=1, Unique=0: IL_0002: call System.Void UEFI.Code.ReducibleNode::.ctor(System.Int32) */
    UEFI_Code_ReducibleNode__ctor((UEFI_Code_ReducibleNode*)stack0_0__, stack1_0__);
/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(44): */
    /* Path=1, Unique=0: IL_0007: ldarg.0 */
    stack0_0__ = this__;
    /* Path=1, Unique=0: IL_0008: ldarg.1 */
    stack1_0__ = numeric;
    /* Path=1, Unique=0: IL_0009: stfld System.Int32 UEFI.Code.NumericNode::Numeric */
    stack0_0__->Numeric = stack1_0__;
/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(45): */
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

    UEFI_Code_NumericNode* stack0_0__ = NULL;
    int32_t stack0_1__;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        UEFI_Code_NumericNode** pstack0_0__;
    } __executionFrame__;

    __executionFrame__.targetCount = 1;
    __executionFrame__.pstack0_0__ = &stack0_0__;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(49): */
    /* Path=1, Unique=0: IL_0000: ldarg.0 */
    stack0_0__ = this__;
    /* Path=1, Unique=0: IL_0001: ldfld System.Int32 UEFI.Code.NumericNode::Numeric */
    stack0_1__ = stack0_0__->Numeric;
    /* Path=1, Unique=0: IL_0006: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return stack0_1__;
}

//////////////////////
// Runtime helpers:

// Runtime cast
void* __UEFI_Code_NumericNode_IL2C_RuntimeCast__(UEFI_Code_NumericNode* this__, IL2C_RUNTIME_TYPE_DECL* type)
{
    if (type == il2c_typeof(UEFI_Code_ReducibleNode)) return this__;
    return __UEFI_Code_ReducibleNode_IL2C_RuntimeCast__((UEFI_Code_ReducibleNode*)this__, type);
}

// GC's mark handler
void __UEFI_Code_NumericNode_IL2C_MarkHandler__(UEFI_Code_NumericNode* this__)
{
    __UEFI_Code_ReducibleNode_IL2C_MarkHandler__((UEFI_Code_ReducibleNode*)this__);
}

static __UEFI_Code_NumericNode_VTABLE_DECL__ __UEFI_Code_NumericNode_VTABLE__ = {
    /* internalcall */ __UEFI_Code_NumericNode_IL2C_RuntimeCast__,
    (void*)__System_Object_ToString__,
    (void*)__System_Object_GetHashCode__,
    (void*)__System_Object_Finalize__,
    (void*)__System_Object_Equals__,
    (void*)__UEFI_Code_NumericNode_Reduce__,
};

IL2C_RUNTIME_TYPE_DECL __UEFI_Code_NumericNode_RUNTIME_TYPE__ = {
    "UEFI.Code.NumericNode",
    sizeof(UEFI_Code_NumericNode),
    /* internalcall */ (void*)__UEFI_Code_NumericNode_IL2C_MarkHandler__,
};

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

    UEFI_Code_ExpressionNode* stack0_0__ = NULL;
    int32_t stack1_0__;
    UEFI_Code_OperatorNode* stack1_1__ = NULL;
    UEFI_Code_ReducibleNode* stack1_2__ = NULL;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        UEFI_Code_ExpressionNode** pstack0_0__;
        UEFI_Code_OperatorNode** pstack1_1__;
        UEFI_Code_ReducibleNode** pstack1_2__;
    } __executionFrame__;

    __executionFrame__.targetCount = 3;
    __executionFrame__.pstack0_0__ = &stack0_0__;
    __executionFrame__.pstack1_1__ = &stack1_1__;
    __executionFrame__.pstack1_2__ = &stack1_2__;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(59): */
    /* Path=1, Unique=0: IL_0000: ldarg.0 */
    stack0_0__ = this__;
    /* Path=1, Unique=0: IL_0001: ldarg.s nextIndex */
    stack1_0__ = nextIndex;
    /* Path=1, Unique=0: IL_0003: call System.Void UEFI.Code.ReducibleNode::.ctor(System.Int32) */
    UEFI_Code_ReducibleNode__ctor((UEFI_Code_ReducibleNode*)stack0_0__, stack1_0__);
/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(61): */
    /* Path=1, Unique=0: IL_0008: ldarg.0 */
    stack0_0__ = this__;
    /* Path=1, Unique=0: IL_0009: ldarg.1 */
    stack1_1__ = oper;
    /* Path=1, Unique=0: IL_000a: stfld UEFI.Code.OperatorNode UEFI.Code.ExpressionNode::Operator */
    stack0_0__->Operator = stack1_1__;
/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(62): */
    /* Path=1, Unique=0: IL_000f: ldarg.0 */
    stack0_0__ = this__;
    /* Path=1, Unique=0: IL_0010: ldarg.2 */
    stack1_2__ = left;
    /* Path=1, Unique=0: IL_0011: stfld UEFI.Code.ReducibleNode UEFI.Code.ExpressionNode::Left */
    stack0_0__->Left = stack1_2__;
/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(63): */
    /* Path=1, Unique=0: IL_0016: ldarg.0 */
    stack0_0__ = this__;
    /* Path=1, Unique=0: IL_0017: ldarg.3 */
    stack1_2__ = right;
    /* Path=1, Unique=0: IL_0018: stfld UEFI.Code.ReducibleNode UEFI.Code.ExpressionNode::Right */
    stack0_0__->Right = stack1_2__;
/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(64): */
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

    int32_t leftResult;
    int32_t rightResult;

    //-------------------
    // Evaluation stacks:

    UEFI_Code_ExpressionNode* stack0_0__ = NULL;
    UEFI_Code_ReducibleNode* stack0_1__ = NULL;
    int32_t stack0_2__;
    UEFI_Code_OperatorNode* stack0_3__ = NULL;
    int32_t stack1_0__;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        UEFI_Code_ExpressionNode** pstack0_0__;
        UEFI_Code_ReducibleNode** pstack0_1__;
        UEFI_Code_OperatorNode** pstack0_3__;
    } __executionFrame__;

    __executionFrame__.targetCount = 3;
    __executionFrame__.pstack0_0__ = &stack0_0__;
    __executionFrame__.pstack0_1__ = &stack0_1__;
    __executionFrame__.pstack0_3__ = &stack0_3__;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(68): */
    /* Path=1, Unique=0: IL_0000: ldarg.0 */
    stack0_0__ = this__;
    /* Path=1, Unique=0: IL_0001: ldfld UEFI.Code.ReducibleNode UEFI.Code.ExpressionNode::Left */
    stack0_1__ = stack0_0__->Left;
    /* Path=1, Unique=0: IL_0006: callvirt System.Int32 UEFI.Code.ReducibleNode::Reduce() */
    stack0_2__ = UEFI_Code_ReducibleNode_Reduce(stack0_1__);
    /* Path=1, Unique=0: IL_000b: stloc.0 */
    leftResult = stack0_2__;
/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(69): */
    /* Path=1, Unique=0: IL_000c: ldarg.0 */
    stack0_0__ = this__;
    /* Path=1, Unique=0: IL_000d: ldfld UEFI.Code.ReducibleNode UEFI.Code.ExpressionNode::Right */
    stack0_1__ = stack0_0__->Right;
    /* Path=1, Unique=0: IL_0012: callvirt System.Int32 UEFI.Code.ReducibleNode::Reduce() */
    stack0_2__ = UEFI_Code_ReducibleNode_Reduce(stack0_1__);
    /* Path=1, Unique=0: IL_0017: stloc.1 */
    rightResult = stack0_2__;
/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(70): */
    /* Path=1, Unique=0: IL_0018: ldarg.0 */
    stack0_0__ = this__;
    /* Path=1, Unique=0: IL_0019: ldfld UEFI.Code.OperatorNode UEFI.Code.ExpressionNode::Operator */
    stack0_3__ = stack0_0__->Operator;
    /* Path=1, Unique=0: IL_001e: ldfld System.Char UEFI.Code.OperatorNode::Operator */
    stack0_2__ = (int32_t)(stack0_3__->Operator);
    /* Path=1, Unique=0: IL_0023: ldc.i4.s 43 */
    stack1_0__ = 43;
    /* Path=1, Unique=0: IL_0025: bne.un.s IL_002b */
    if (stack0_2__ != stack1_0__) goto IL_002b;
/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(72): */
    /* Path=1, Unique=0: IL_0027: ldloc.0 */
    stack0_2__ = leftResult;
    /* Path=1, Unique=0: IL_0028: ldloc.1 */
    stack1_0__ = rightResult;
    /* Path=1, Unique=0: IL_0029: add */
    stack0_2__ = stack0_2__ + stack1_0__;
    /* Path=1, Unique=0: IL_002a: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return stack0_2__;
IL_002b:
/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(74): */
    /* Path=2, Unique=0: IL_002b: ldarg.0 */
    stack0_0__ = this__;
    /* Path=2, Unique=0: IL_002c: ldfld UEFI.Code.OperatorNode UEFI.Code.ExpressionNode::Operator */
    stack0_3__ = stack0_0__->Operator;
    /* Path=2, Unique=0: IL_0031: ldfld System.Char UEFI.Code.OperatorNode::Operator */
    stack0_2__ = (int32_t)(stack0_3__->Operator);
    /* Path=2, Unique=0: IL_0036: ldc.i4.s 45 */
    stack1_0__ = 45;
    /* Path=2, Unique=0: IL_0038: bne.un.s IL_003e */
    if (stack0_2__ != stack1_0__) goto IL_003e;
/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(76): */
    /* Path=2, Unique=0: IL_003a: ldloc.0 */
    stack0_2__ = leftResult;
    /* Path=2, Unique=0: IL_003b: ldloc.1 */
    stack1_0__ = rightResult;
    /* Path=2, Unique=0: IL_003c: sub */
    stack0_2__ = stack0_2__ - stack1_0__;
    /* Path=2, Unique=0: IL_003d: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return stack0_2__;
IL_003e:
/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(78): */
    /* Path=3, Unique=0: IL_003e: ldarg.0 */
    stack0_0__ = this__;
    /* Path=3, Unique=0: IL_003f: ldfld UEFI.Code.OperatorNode UEFI.Code.ExpressionNode::Operator */
    stack0_3__ = stack0_0__->Operator;
    /* Path=3, Unique=0: IL_0044: ldfld System.Char UEFI.Code.OperatorNode::Operator */
    stack0_2__ = (int32_t)(stack0_3__->Operator);
    /* Path=3, Unique=0: IL_0049: ldc.i4.s 42 */
    stack1_0__ = 42;
    /* Path=3, Unique=0: IL_004b: bne.un.s IL_0051 */
    if (stack0_2__ != stack1_0__) goto IL_0051;
/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(80): */
    /* Path=3, Unique=0: IL_004d: ldloc.0 */
    stack0_2__ = leftResult;
    /* Path=3, Unique=0: IL_004e: ldloc.1 */
    stack1_0__ = rightResult;
    /* Path=3, Unique=0: IL_004f: mul */
    stack0_2__ = stack0_2__ * stack1_0__;
    /* Path=3, Unique=0: IL_0050: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return stack0_2__;
IL_0051:
/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(82): */
    /* Path=4, Unique=0: IL_0051: ldarg.0 */
    stack0_0__ = this__;
    /* Path=4, Unique=0: IL_0052: ldfld UEFI.Code.OperatorNode UEFI.Code.ExpressionNode::Operator */
    stack0_3__ = stack0_0__->Operator;
    /* Path=4, Unique=0: IL_0057: ldfld System.Char UEFI.Code.OperatorNode::Operator */
    stack0_2__ = (int32_t)(stack0_3__->Operator);
    /* Path=4, Unique=0: IL_005c: ldc.i4.s 47 */
    stack1_0__ = 47;
    /* Path=4, Unique=0: IL_005e: bne.un.s IL_0064 */
    if (stack0_2__ != stack1_0__) goto IL_0064;
/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(84): */
    /* Path=4, Unique=0: IL_0060: ldloc.0 */
    stack0_2__ = leftResult;
    /* Path=4, Unique=0: IL_0061: ldloc.1 */
    stack1_0__ = rightResult;
    /* Path=4, Unique=0: IL_0062: div */
    stack0_2__ = stack0_2__ / stack1_0__;
    /* Path=4, Unique=0: IL_0063: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return stack0_2__;
IL_0064:
/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(88): */
    /* Path=5, Unique=0: IL_0064: ldc.i4.0 */
    stack0_2__ = 0;
    /* Path=5, Unique=0: IL_0065: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return stack0_2__;
}

//////////////////////
// Runtime helpers:

// Runtime cast
void* __UEFI_Code_ExpressionNode_IL2C_RuntimeCast__(UEFI_Code_ExpressionNode* this__, IL2C_RUNTIME_TYPE_DECL* type)
{
    if (type == il2c_typeof(UEFI_Code_ReducibleNode)) return this__;
    return __UEFI_Code_ReducibleNode_IL2C_RuntimeCast__((UEFI_Code_ReducibleNode*)this__, type);
}

// GC's mark handler
void __UEFI_Code_ExpressionNode_IL2C_MarkHandler__(UEFI_Code_ExpressionNode* this__)
{
    il2c_try_mark_from_handler(this__->Operator);
    il2c_try_mark_from_handler(this__->Left);
    il2c_try_mark_from_handler(this__->Right);
    __UEFI_Code_ReducibleNode_IL2C_MarkHandler__((UEFI_Code_ReducibleNode*)this__);
}

static __UEFI_Code_ExpressionNode_VTABLE_DECL__ __UEFI_Code_ExpressionNode_VTABLE__ = {
    /* internalcall */ __UEFI_Code_ExpressionNode_IL2C_RuntimeCast__,
    (void*)__System_Object_ToString__,
    (void*)__System_Object_GetHashCode__,
    (void*)__System_Object_Finalize__,
    (void*)__System_Object_Equals__,
    (void*)__UEFI_Code_ExpressionNode_Reduce__,
};

IL2C_RUNTIME_TYPE_DECL __UEFI_Code_ExpressionNode_RUNTIME_TYPE__ = {
    "UEFI.Code.ExpressionNode",
    sizeof(UEFI_Code_ExpressionNode),
    /* internalcall */ (void*)__UEFI_Code_ExpressionNode_IL2C_MarkHandler__,
};

////////////////////////////////////////////////////////////
// Type: UEFI.Code.PolishNotation

///////////////////////////////////////
// SkipWhiteSpace

int32_t UEFI_Code_PolishNotation_SkipWhiteSpace(System_String* line, int32_t startIndex)
{
    //-------------------
    // Local variables:

    int32_t index;
    wchar_t ch;

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

/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(96): */
    /* Path=1, Unique=0: IL_0000: ldarg.1 */
    stack0_0__ = startIndex;
    /* Path=1, Unique=0: IL_0001: stloc.0 */
    index = stack0_0__;
    /* Path=1, Unique=0: IL_0002: br.s IL_001a */
    goto IL_001a;
IL_0004:
/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(99): */
    /* Path=3, Unique=0: IL_0004: ldarg.0 */
    stack0_1__ = line;
    /* Path=3, Unique=0: IL_0005: ldloc.0 */
    stack1_2__ = index;
    /* Path=3, Unique=0: IL_0006: callvirt System.Char System.String::get_Chars(System.Int32) */
    stack0_2__ = System_String_get_Chars(stack0_1__, stack1_2__);
    /* Path=3, Unique=0: IL_000b: stloc.1 */
    ch = (wchar_t)stack0_2__;
/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(100): */
    /* Path=3, Unique=0: IL_000c: ldloc.1 */
    stack0_0__ = ch;
    /* Path=3, Unique=0: IL_000d: ldc.i4.s 32 */
    stack1_2__ = 32;
    /* Path=3, Unique=0: IL_000f: beq.s IL_0016 */
    if (stack0_0__ == stack1_2__) goto IL_0016;
    /* Path=3, Unique=0: IL_0011: ldloc.1 */
    stack0_0__ = ch;
    /* Path=3, Unique=0: IL_0012: ldc.i4.s 9 */
    stack1_2__ = 9;
    /* Path=3, Unique=0: IL_0014: bne.un.s IL_0023 */
    if (stack0_0__ != stack1_2__) goto IL_0023;
IL_0016:
/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(104): */
    /* Path=3, Unique=0: IL_0016: ldloc.0 */
    stack0_0__ = index;
    /* Path=3, Unique=0: IL_0017: ldc.i4.1 */
    stack1_2__ = 1;
    /* Path=3, Unique=0: IL_0018: add */
    stack0_0__ = stack0_0__ + stack1_2__;
    /* Path=3, Unique=0: IL_0019: stloc.0 */
    index = stack0_0__;
IL_001a:
/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(97): */
    /* Path=2, Unique=0: IL_001a: ldloc.0 */
    stack0_0__ = index;
    /* Path=2, Unique=0: IL_001b: ldarg.0 */
    stack1_0__ = line;
    /* Path=2, Unique=0: IL_001c: callvirt System.Int32 System.String::get_Length() */
    stack1_1__ = System_String_get_Length(stack1_0__);
    /* Path=2, Unique=0: IL_0021: blt.s IL_0004 */
    if (stack0_0__ < stack1_1__) goto IL_0004;
IL_0023:
/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(107): */
    /* Path=2, Unique=0: IL_0023: ldloc.0 */
    stack0_0__ = index;
    /* Path=2, Unique=0: IL_0024: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return stack0_0__;
}

///////////////////////////////////////
// ParseOperator

UEFI_Code_OperatorNode* UEFI_Code_PolishNotation_ParseOperator(System_String* line, int32_t startIndex)
{
    //-------------------
    // Local variables:

    int32_t index;
    wchar_t ch;

    //-------------------
    // Evaluation stacks:

    int32_t stack0_0__;
    IL2C_CecilHelper_PseudoZeroType* stack0_1__ = NULL;
    System_String* stack0_2__ = NULL;
    int32_t stack0_3__;
    UEFI_Code_OperatorNode* stack0_4__ = NULL;
    System_String* stack1_0__ = NULL;
    int32_t stack1_1__;
    int32_t stack1_2__;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        IL2C_CecilHelper_PseudoZeroType** pstack0_1__;
        System_String** pstack0_2__;
        UEFI_Code_OperatorNode** pstack0_4__;
        System_String** pstack1_0__;
    } __executionFrame__;

    __executionFrame__.targetCount = 4;
    __executionFrame__.pstack0_1__ = &stack0_1__;
    __executionFrame__.pstack0_2__ = &stack0_2__;
    __executionFrame__.pstack0_4__ = &stack0_4__;
    __executionFrame__.pstack1_0__ = &stack1_0__;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(112): */
    /* Path=1, Unique=0: IL_0000: ldarg.1 */
    stack0_0__ = startIndex;
    /* Path=1, Unique=0: IL_0001: ldarg.0 */
    stack1_0__ = line;
    /* Path=1, Unique=0: IL_0002: callvirt System.Int32 System.String::get_Length() */
    stack1_1__ = System_String_get_Length(stack1_0__);
    /* Path=1, Unique=0: IL_0007: blt.s IL_000b */
    if (stack0_0__ < stack1_1__) goto IL_000b;
/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(114): */
    /* Path=1, Unique=0: IL_0009: ldnull */
    stack0_1__ = NULL;
    /* Path=1, Unique=0: IL_000a: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return (UEFI_Code_OperatorNode*)stack0_1__;
IL_000b:
/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(117): */
    /* Path=2, Unique=0: IL_000b: ldarg.1 */
    stack0_0__ = startIndex;
    /* Path=2, Unique=0: IL_000c: stloc.0 */
    index = stack0_0__;
/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(118): */
    /* Path=2, Unique=0: IL_000d: ldarg.0 */
    stack0_2__ = line;
    /* Path=2, Unique=0: IL_000e: ldloc.0 */
    stack1_2__ = index;
    /* Path=2, Unique=0: IL_000f: callvirt System.Char System.String::get_Chars(System.Int32) */
    stack0_3__ = System_String_get_Chars(stack0_2__, stack1_2__);
    /* Path=2, Unique=0: IL_0014: stloc.1 */
    ch = (wchar_t)stack0_3__;
/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(119): */
    /* Path=2, Unique=0: IL_0015: ldloc.1 */
    stack0_0__ = ch;
    /* Path=2, Unique=0: IL_0016: ldc.i4.s 43 */
    stack1_2__ = 43;
    /* Path=2, Unique=0: IL_0018: beq.s IL_002b */
    if (stack0_0__ == stack1_2__) goto IL_002b;
    /* Path=2, Unique=0: IL_001a: ldloc.1 */
    stack0_0__ = ch;
    /* Path=2, Unique=0: IL_001b: ldc.i4.s 45 */
    stack1_2__ = 45;
    /* Path=2, Unique=0: IL_001d: beq.s IL_002b */
    if (stack0_0__ == stack1_2__) goto IL_002b;
    /* Path=2, Unique=0: IL_001f: ldloc.1 */
    stack0_0__ = ch;
    /* Path=2, Unique=0: IL_0020: ldc.i4.s 42 */
    stack1_2__ = 42;
    /* Path=2, Unique=0: IL_0022: beq.s IL_002b */
    if (stack0_0__ == stack1_2__) goto IL_002b;
    /* Path=2, Unique=0: IL_0024: ldloc.1 */
    stack0_0__ = ch;
    /* Path=2, Unique=0: IL_0025: ldc.i4.s 47 */
    stack1_2__ = 47;
    /* Path=2, Unique=0: IL_0027: beq.s IL_002b */
    if (stack0_0__ == stack1_2__) goto IL_002b;
/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(121): */
    /* Path=2, Unique=0: IL_0029: ldnull */
    stack0_1__ = NULL;
    /* Path=2, Unique=0: IL_002a: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return (UEFI_Code_OperatorNode*)stack0_1__;
IL_002b:
/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(123): */
    /* Path=3, Unique=0: IL_002b: ldloc.0 */
    stack0_0__ = index;
    /* Path=3, Unique=0: IL_002c: ldc.i4.1 */
    stack1_2__ = 1;
    /* Path=3, Unique=0: IL_002d: add */
    stack0_0__ = stack0_0__ + stack1_2__;
    /* Path=3, Unique=0: IL_002e: stloc.0 */
    index = stack0_0__;
/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(125): */
    /* Path=3, Unique=0: IL_002f: ldarg.0 */
    stack0_2__ = line;
    /* Path=3, Unique=0: IL_0030: ldloc.0 */
    stack1_2__ = index;
    /* Path=3, Unique=0: IL_0031: call System.Int32 UEFI.Code.PolishNotation::SkipWhiteSpace(System.String,System.Int32) */
    stack0_0__ = UEFI_Code_PolishNotation_SkipWhiteSpace(stack0_2__, stack1_2__);
    /* Path=3, Unique=0: IL_0036: stloc.0 */
    index = stack0_0__;
/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(126): */
    /* Path=3, Unique=0: IL_0037: ldloc.1 */
    stack0_0__ = ch;
    /* Path=3, Unique=0: IL_0038: ldloc.0 */
    stack1_2__ = index;
    /* Path=3, Unique=0: IL_0039: newobj System.Void UEFI.Code.OperatorNode::.ctor(System.Char,System.Int32) */
    stack0_4__ = il2c_get_uninitialized_object(il2c_typeof(UEFI_Code_OperatorNode));
    stack0_4__->vptr0__ = &__UEFI_Code_OperatorNode_VTABLE__;
    UEFI_Code_OperatorNode__ctor(stack0_4__, (wchar_t)stack0_0__, stack1_2__);
    /* Path=3, Unique=0: IL_003e: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return stack0_4__;
}

///////////////////////////////////////
// ParseNumeric

UEFI_Code_NumericNode* UEFI_Code_PolishNotation_ParseNumeric(System_String* line, int32_t startIndex)
{
    //-------------------
    // Local variables:

    int32_t index;
    int32_t numeric;

    //-------------------
    // Evaluation stacks:

    int32_t stack0_0__;
    IL2C_CecilHelper_PseudoZeroType* stack0_1__ = NULL;
    System_String* stack0_2__ = NULL;
    int32_t stack0_3__;
    System_String* stack0_4__ = NULL;
    UEFI_Code_NumericNode* stack0_5__ = NULL;
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
        IL2C_CecilHelper_PseudoZeroType** pstack0_1__;
        System_String** pstack0_2__;
        System_String** pstack0_4__;
        UEFI_Code_NumericNode** pstack0_5__;
        System_String** pstack1_0__;
        int32_t** pstack1_3__;
    } __executionFrame__;

    __executionFrame__.targetCount = 6;
    __executionFrame__.pstack0_1__ = &stack0_1__;
    __executionFrame__.pstack0_2__ = &stack0_2__;
    __executionFrame__.pstack0_4__ = &stack0_4__;
    __executionFrame__.pstack0_5__ = &stack0_5__;
    __executionFrame__.pstack1_0__ = &stack1_0__;
    __executionFrame__.pstack1_3__ = &stack1_3__;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(131): */
    /* Path=1, Unique=0: IL_0000: ldarg.1 */
    stack0_0__ = startIndex;
    /* Path=1, Unique=0: IL_0001: ldarg.0 */
    stack1_0__ = line;
    /* Path=1, Unique=0: IL_0002: callvirt System.Int32 System.String::get_Length() */
    stack1_1__ = System_String_get_Length(stack1_0__);
    /* Path=1, Unique=0: IL_0007: blt.s IL_000b */
    if (stack0_0__ < stack1_1__) goto IL_000b;
/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(133): */
    /* Path=1, Unique=0: IL_0009: ldnull */
    stack0_1__ = NULL;
    /* Path=1, Unique=0: IL_000a: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return (UEFI_Code_NumericNode*)stack0_1__;
IL_000b:
/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(136): */
    /* Path=2, Unique=0: IL_000b: ldarg.1 */
    stack0_0__ = startIndex;
    /* Path=2, Unique=0: IL_000c: stloc.0 */
    index = stack0_0__;
    /* Path=2, Unique=0: IL_000d: br.s IL_001e */
    goto IL_001e;
IL_000f:
/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(139): */
    /* Path=4, Unique=0: IL_000f: ldarg.0 */
    stack0_2__ = line;
    /* Path=4, Unique=0: IL_0010: ldloc.0 */
    stack1_2__ = index;
    /* Path=4, Unique=0: IL_0011: callvirt System.Char System.String::get_Chars(System.Int32) */
    stack0_3__ = System_String_get_Chars(stack0_2__, stack1_2__);
/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(140): */
    /* Path=4, Unique=0: IL_0016: ldc.i4.s 32 */
    stack1_2__ = 32;
    /* Path=4, Unique=0: IL_0018: beq.s IL_0027 */
    if (stack0_3__ == stack1_2__) goto IL_0027;
/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(144): */
    /* Path=4, Unique=0: IL_001a: ldloc.0 */
    stack0_0__ = index;
    /* Path=4, Unique=0: IL_001b: ldc.i4.1 */
    stack1_2__ = 1;
    /* Path=4, Unique=0: IL_001c: add */
    stack0_0__ = stack0_0__ + stack1_2__;
    /* Path=4, Unique=0: IL_001d: stloc.0 */
    index = stack0_0__;
IL_001e:
/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(137): */
    /* Path=3, Unique=0: IL_001e: ldloc.0 */
    stack0_0__ = index;
    /* Path=3, Unique=0: IL_001f: ldarg.0 */
    stack1_0__ = line;
    /* Path=3, Unique=0: IL_0020: callvirt System.Int32 System.String::get_Length() */
    stack1_1__ = System_String_get_Length(stack1_0__);
    /* Path=3, Unique=0: IL_0025: blt.s IL_000f */
    if (stack0_0__ < stack1_1__) goto IL_000f;
IL_0027:
/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(147): */
    /* Path=3, Unique=0: IL_0027: ldloc.0 */
    stack0_0__ = index;
    /* Path=3, Unique=0: IL_0028: ldarg.1 */
    stack1_2__ = startIndex;
    /* Path=3, Unique=0: IL_0029: bne.un.s IL_002d */
    if (stack0_0__ != stack1_2__) goto IL_002d;
/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(149): */
    /* Path=3, Unique=0: IL_002b: ldnull */
    stack0_1__ = NULL;
    /* Path=3, Unique=0: IL_002c: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return (UEFI_Code_NumericNode*)stack0_1__;
IL_002d:
/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(152): */
    /* Path=5, Unique=0: IL_002d: ldarg.0 */
    stack0_2__ = line;
    /* Path=5, Unique=0: IL_002e: ldarg.1 */
    stack1_2__ = startIndex;
    /* Path=5, Unique=0: IL_002f: ldloc.0 */
    stack2_0__ = index;
    /* Path=5, Unique=0: IL_0030: ldarg.1 */
    stack3_0__ = startIndex;
    /* Path=5, Unique=0: IL_0031: sub */
    stack2_0__ = stack2_0__ - stack3_0__;
    /* Path=5, Unique=0: IL_0032: callvirt System.String System.String::Substring(System.Int32,System.Int32) */
    stack0_4__ = System_String_Substring_1(stack0_2__, stack1_2__, stack2_0__);
/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(153): */
    /* Path=5, Unique=0: IL_0037: ldloca.s local1 */
    stack1_3__ = &numeric;
    /* Path=5, Unique=0: IL_0039: call System.Boolean System.Int32::TryParse(System.String,System.Int32&) */
    stack0_0__ = System_Int32_TryParse(stack0_4__, stack1_3__);
    /* Path=5, Unique=0: IL_003e: brtrue.s IL_0042 */
    if (stack0_0__ != 0) goto IL_0042;
/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(155): */
    /* Path=5, Unique=0: IL_0040: ldnull */
    stack0_1__ = NULL;
    /* Path=5, Unique=0: IL_0041: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return (UEFI_Code_NumericNode*)stack0_1__;
IL_0042:
/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(158): */
    /* Path=6, Unique=0: IL_0042: ldarg.0 */
    stack0_2__ = line;
    /* Path=6, Unique=0: IL_0043: ldloc.0 */
    stack1_2__ = index;
    /* Path=6, Unique=0: IL_0044: call System.Int32 UEFI.Code.PolishNotation::SkipWhiteSpace(System.String,System.Int32) */
    stack0_0__ = UEFI_Code_PolishNotation_SkipWhiteSpace(stack0_2__, stack1_2__);
    /* Path=6, Unique=0: IL_0049: stloc.0 */
    index = stack0_0__;
/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(159): */
    /* Path=6, Unique=0: IL_004a: ldloc.1 */
    stack0_0__ = numeric;
    /* Path=6, Unique=0: IL_004b: ldloc.0 */
    stack1_2__ = index;
    /* Path=6, Unique=0: IL_004c: newobj System.Void UEFI.Code.NumericNode::.ctor(System.Int32,System.Int32) */
    stack0_5__ = il2c_get_uninitialized_object(il2c_typeof(UEFI_Code_NumericNode));
    stack0_5__->vptr0__ = &__UEFI_Code_NumericNode_VTABLE__;
    UEFI_Code_NumericNode__ctor(stack0_5__, stack0_0__, stack1_2__);
    /* Path=6, Unique=0: IL_0051: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return stack0_5__;
}

///////////////////////////////////////
// ParseExpression

UEFI_Code_ExpressionNode* UEFI_Code_PolishNotation_ParseExpression(System_String* line, int32_t startIndex)
{
    //-------------------
    // Local variables:

    UEFI_Code_OperatorNode* oper = NULL;
    UEFI_Code_ReducibleNode* left = NULL;
    UEFI_Code_ReducibleNode* right = NULL;
    int32_t index;

    //-------------------
    // Evaluation stacks:

    int32_t stack0_0__;
    IL2C_CecilHelper_PseudoZeroType* stack0_1__ = NULL;
    System_String* stack0_2__ = NULL;
    UEFI_Code_OperatorNode* stack0_3__ = NULL;
    UEFI_Code_NumericNode* stack0_4__ = NULL;
    UEFI_Code_ReducibleNode* stack0_5__ = NULL;
    UEFI_Code_ExpressionNode* stack0_6__ = NULL;
    System_String* stack1_0__ = NULL;
    int32_t stack1_1__;
    int32_t stack1_2__;
    UEFI_Code_OperatorNode* stack1_3__ = NULL;
    UEFI_Code_ReducibleNode* stack1_4__ = NULL;
    UEFI_Code_ReducibleNode* stack2_0__ = NULL;
    int32_t stack3_0__;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        UEFI_Code_OperatorNode** poper;
        UEFI_Code_ReducibleNode** pleft;
        UEFI_Code_ReducibleNode** pright;
        IL2C_CecilHelper_PseudoZeroType** pstack0_1__;
        System_String** pstack0_2__;
        UEFI_Code_OperatorNode** pstack0_3__;
        UEFI_Code_NumericNode** pstack0_4__;
        UEFI_Code_ReducibleNode** pstack0_5__;
        UEFI_Code_ExpressionNode** pstack0_6__;
        System_String** pstack1_0__;
        UEFI_Code_OperatorNode** pstack1_3__;
        UEFI_Code_ReducibleNode** pstack1_4__;
        UEFI_Code_ReducibleNode** pstack2_0__;
    } __executionFrame__;

    __executionFrame__.targetCount = 13;
    __executionFrame__.poper = &oper;
    __executionFrame__.pleft = &left;
    __executionFrame__.pright = &right;
    __executionFrame__.pstack0_1__ = &stack0_1__;
    __executionFrame__.pstack0_2__ = &stack0_2__;
    __executionFrame__.pstack0_3__ = &stack0_3__;
    __executionFrame__.pstack0_4__ = &stack0_4__;
    __executionFrame__.pstack0_5__ = &stack0_5__;
    __executionFrame__.pstack0_6__ = &stack0_6__;
    __executionFrame__.pstack1_0__ = &stack1_0__;
    __executionFrame__.pstack1_3__ = &stack1_3__;
    __executionFrame__.pstack1_4__ = &stack1_4__;
    __executionFrame__.pstack2_0__ = &stack2_0__;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(164): */
    /* Path=1, Unique=0: IL_0000: ldarg.1 */
    stack0_0__ = startIndex;
    /* Path=1, Unique=0: IL_0001: ldarg.0 */
    stack1_0__ = line;
    /* Path=1, Unique=0: IL_0002: callvirt System.Int32 System.String::get_Length() */
    stack1_1__ = System_String_get_Length(stack1_0__);
    /* Path=1, Unique=0: IL_0007: blt.s IL_000b */
    if (stack0_0__ < stack1_1__) goto IL_000b;
/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(166): */
    /* Path=1, Unique=0: IL_0009: ldnull */
    stack0_1__ = NULL;
    /* Path=1, Unique=0: IL_000a: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return (UEFI_Code_ExpressionNode*)stack0_1__;
IL_000b:
/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(169): */
    /* Path=2, Unique=0: IL_000b: ldarg.0 */
    stack0_2__ = line;
    /* Path=2, Unique=0: IL_000c: ldarg.1 */
    stack1_2__ = startIndex;
    /* Path=2, Unique=0: IL_000d: call UEFI.Code.OperatorNode UEFI.Code.PolishNotation::ParseOperator(System.String,System.Int32) */
    stack0_3__ = UEFI_Code_PolishNotation_ParseOperator(stack0_2__, stack1_2__);
    /* Path=2, Unique=0: IL_0012: stloc.0 */
    oper = stack0_3__;
/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(170): */
    /* Path=2, Unique=0: IL_0013: ldloc.0 */
    stack0_3__ = oper;
    /* Path=2, Unique=0: IL_0014: brtrue.s IL_0018 */
    if (stack0_3__ != NULL) goto IL_0018;
/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(172): */
    /* Path=2, Unique=0: IL_0016: ldnull */
    stack0_1__ = NULL;
    /* Path=2, Unique=0: IL_0017: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return (UEFI_Code_ExpressionNode*)stack0_1__;
IL_0018:
/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(175): */
    /* Path=3, Unique=0: IL_0018: ldarg.0 */
    stack0_2__ = line;
    /* Path=3, Unique=0: IL_0019: ldloc.0 */
    stack1_3__ = oper;
    /* Path=3, Unique=0: IL_001a: ldfld System.Int32 UEFI.Code.AbstractNode::NextIndex */
    stack1_2__ = stack1_3__->NextIndex;
    /* Path=3, Unique=0: IL_001f: call UEFI.Code.NumericNode UEFI.Code.PolishNotation::ParseNumeric(System.String,System.Int32) */
    stack0_4__ = UEFI_Code_PolishNotation_ParseNumeric(stack0_2__, stack1_2__);
    /* Path=3, Unique=0: IL_0024: stloc.1 */
    left = (UEFI_Code_ReducibleNode*)stack0_4__;
/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(176): */
    /* Path=3, Unique=0: IL_0025: ldloc.1 */
    stack0_5__ = left;
    /* Path=3, Unique=0: IL_0026: brtrue.s IL_003a */
    if (stack0_5__ != NULL) goto IL_003a;
/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(178): */
    /* Path=3, Unique=0: IL_0028: ldarg.0 */
    stack0_2__ = line;
    /* Path=3, Unique=0: IL_0029: ldloc.0 */
    stack1_3__ = oper;
    /* Path=3, Unique=0: IL_002a: ldfld System.Int32 UEFI.Code.AbstractNode::NextIndex */
    stack1_2__ = stack1_3__->NextIndex;
    /* Path=3, Unique=0: IL_002f: call UEFI.Code.ExpressionNode UEFI.Code.PolishNotation::ParseExpression(System.String,System.Int32) */
    stack0_6__ = UEFI_Code_PolishNotation_ParseExpression(stack0_2__, stack1_2__);
    /* Path=3, Unique=0: IL_0034: stloc.1 */
    left = (UEFI_Code_ReducibleNode*)stack0_6__;
/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(179): */
    /* Path=3, Unique=0: IL_0035: ldloc.1 */
    stack0_5__ = left;
    /* Path=3, Unique=0: IL_0036: brtrue.s IL_003a */
    if (stack0_5__ != NULL) goto IL_003a;
/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(181): */
    /* Path=3, Unique=0: IL_0038: ldnull */
    stack0_1__ = NULL;
    /* Path=3, Unique=0: IL_0039: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return (UEFI_Code_ExpressionNode*)stack0_1__;
IL_003a:
/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(185): */
    /* Path=4, Unique=0: IL_003a: ldarg.0 */
    stack0_2__ = line;
    /* Path=4, Unique=0: IL_003b: ldloc.1 */
    stack1_4__ = left;
    /* Path=4, Unique=0: IL_003c: ldfld System.Int32 UEFI.Code.AbstractNode::NextIndex */
    stack1_2__ = stack1_4__->NextIndex;
    /* Path=4, Unique=0: IL_0041: call UEFI.Code.NumericNode UEFI.Code.PolishNotation::ParseNumeric(System.String,System.Int32) */
    stack0_4__ = UEFI_Code_PolishNotation_ParseNumeric(stack0_2__, stack1_2__);
    /* Path=4, Unique=0: IL_0046: stloc.2 */
    right = (UEFI_Code_ReducibleNode*)stack0_4__;
/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(186): */
    /* Path=4, Unique=0: IL_0047: ldloc.2 */
    stack0_5__ = right;
    /* Path=4, Unique=0: IL_0048: brtrue.s IL_005c */
    if (stack0_5__ != NULL) goto IL_005c;
/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(188): */
    /* Path=4, Unique=0: IL_004a: ldarg.0 */
    stack0_2__ = line;
    /* Path=4, Unique=0: IL_004b: ldloc.1 */
    stack1_4__ = left;
    /* Path=4, Unique=0: IL_004c: ldfld System.Int32 UEFI.Code.AbstractNode::NextIndex */
    stack1_2__ = stack1_4__->NextIndex;
    /* Path=4, Unique=0: IL_0051: call UEFI.Code.ExpressionNode UEFI.Code.PolishNotation::ParseExpression(System.String,System.Int32) */
    stack0_6__ = UEFI_Code_PolishNotation_ParseExpression(stack0_2__, stack1_2__);
    /* Path=4, Unique=0: IL_0056: stloc.2 */
    right = (UEFI_Code_ReducibleNode*)stack0_6__;
/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(189): */
    /* Path=4, Unique=0: IL_0057: ldloc.2 */
    stack0_5__ = right;
    /* Path=4, Unique=0: IL_0058: brtrue.s IL_005c */
    if (stack0_5__ != NULL) goto IL_005c;
/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(191): */
    /* Path=4, Unique=0: IL_005a: ldnull */
    stack0_1__ = NULL;
    /* Path=4, Unique=0: IL_005b: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return (UEFI_Code_ExpressionNode*)stack0_1__;
IL_005c:
/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(195): */
    /* Path=5, Unique=0: IL_005c: ldarg.0 */
    stack0_2__ = line;
    /* Path=5, Unique=0: IL_005d: ldloc.2 */
    stack1_4__ = right;
    /* Path=5, Unique=0: IL_005e: ldfld System.Int32 UEFI.Code.AbstractNode::NextIndex */
    stack1_2__ = stack1_4__->NextIndex;
    /* Path=5, Unique=0: IL_0063: call System.Int32 UEFI.Code.PolishNotation::SkipWhiteSpace(System.String,System.Int32) */
    stack0_0__ = UEFI_Code_PolishNotation_SkipWhiteSpace(stack0_2__, stack1_2__);
    /* Path=5, Unique=0: IL_0068: stloc.3 */
    index = stack0_0__;
/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(196): */
    /* Path=5, Unique=0: IL_0069: ldloc.0 */
    stack0_3__ = oper;
    /* Path=5, Unique=0: IL_006a: ldloc.1 */
    stack1_4__ = left;
    /* Path=5, Unique=0: IL_006b: ldloc.2 */
    stack2_0__ = right;
    /* Path=5, Unique=0: IL_006c: ldloc.3 */
    stack3_0__ = index;
    /* Path=5, Unique=0: IL_006d: newobj System.Void UEFI.Code.ExpressionNode::.ctor(UEFI.Code.OperatorNode,UEFI.Code.ReducibleNode,UEFI.Code.ReducibleNode,System.Int32) */
    stack0_6__ = il2c_get_uninitialized_object(il2c_typeof(UEFI_Code_ExpressionNode));
    stack0_6__->vptr0__ = &__UEFI_Code_ExpressionNode_VTABLE__;
    UEFI_Code_ExpressionNode__ctor(stack0_6__, stack0_3__, stack1_4__, stack2_0__, stack3_0__);
    /* Path=5, Unique=0: IL_0072: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return stack0_6__;
}

///////////////////////////////////////
// Main

void UEFI_Code_PolishNotation_Main(void)
{
    //-------------------
    // Local variables:

    System_String* line = NULL;
    UEFI_Code_ExpressionNode* expr = NULL;

    //-------------------
    // Evaluation stacks:

    System_String* stack0_0__ = NULL;
    int32_t stack0_1__;
    UEFI_Code_ExpressionNode* stack0_2__ = NULL;
    int32_t stack1_0__;
    System_String* stack1_1__ = NULL;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        System_String** pline;
        UEFI_Code_ExpressionNode** pexpr;
        System_String** pstack0_0__;
        UEFI_Code_ExpressionNode** pstack0_2__;
        System_String** pstack1_1__;
    } __executionFrame__;

    __executionFrame__.targetCount = 5;
    __executionFrame__.pline = &line;
    __executionFrame__.pexpr = &expr;
    __executionFrame__.pstack0_0__ = &stack0_0__;
    __executionFrame__.pstack0_2__ = &stack0_2__;
    __executionFrame__.pstack1_1__ = &stack1_1__;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

IL_0000:
/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(203): */
    /* Path=1, Unique=0: IL_0000: call System.Void System.Console::WriteLine() */
    System_Console_WriteLine();
/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(204): */
    /* Path=1, Unique=0: IL_0005: ldstr "PN> " */
    stack0_0__ = string0__;
    /* Path=1, Unique=0: IL_000a: call System.Void System.Console::Write(System.String) */
    System_Console_Write_9(stack0_0__);
/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(205): */
    /* Path=1, Unique=0: IL_000f: call System.String System.Console::ReadLine() */
    stack0_0__ = System_Console_ReadLine();
    /* Path=1, Unique=0: IL_0014: stloc.0 */
    line = stack0_0__;
/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(206): */
    /* Path=1, Unique=0: IL_0015: ldloc.0 */
    stack0_0__ = line;
    /* Path=1, Unique=0: IL_0016: call System.Boolean System.String::IsNullOrWhiteSpace(System.String) */
    stack0_1__ = System_String_IsNullOrWhiteSpace(stack0_0__);
    /* Path=1, Unique=0: IL_001b: brtrue.s IL_0000 */
    if (stack0_1__ != 0) goto IL_0000;
/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(208): */
    /* Path=1, Unique=0: IL_001d: ldloc.0 */
    stack0_0__ = line;
    /* Path=1, Unique=0: IL_001e: ldc.i4.0 */
    stack1_0__ = 0;
    /* Path=1, Unique=0: IL_001f: call UEFI.Code.ExpressionNode UEFI.Code.PolishNotation::ParseExpression(System.String,System.Int32) */
    stack0_2__ = UEFI_Code_PolishNotation_ParseExpression(stack0_0__, stack1_0__);
    /* Path=1, Unique=0: IL_0024: stloc.1 */
    expr = stack0_2__;
/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(209): */
    /* Path=1, Unique=0: IL_0025: ldloc.1 */
    stack0_2__ = expr;
    /* Path=1, Unique=0: IL_0026: brtrue.s IL_0034 */
    if (stack0_2__ != NULL) goto IL_0034;
/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(211): */
    /* Path=1, Unique=0: IL_0028: ldstr "Syntax error." */
    stack0_0__ = string1__;
    /* Path=1, Unique=0: IL_002d: call System.Void System.Console::WriteLine(System.String) */
    System_Console_WriteLine_10(stack0_0__);
/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(212): */
    /* Path=1, Unique=0: IL_0032: br.s IL_0000 */
    goto IL_0000;
IL_0034:
/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(215): */
    /* Path=2, Unique=0: IL_0034: ldloc.1 */
    stack0_2__ = expr;
    /* Path=2, Unique=0: IL_0035: callvirt System.Int32 UEFI.Code.ReducibleNode::Reduce() */
    stack0_1__ = UEFI_Code_ReducibleNode_Reduce((UEFI_Code_ReducibleNode*)stack0_2__);
/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(217): */
    /* Path=2, Unique=0: IL_003a: ldstr "Reuslt=" */
    stack1_1__ = string2__;
    /* Path=2, Unique=0: IL_003f: call System.Void System.Console::Write(System.String) */
    System_Console_Write_9(stack1_1__);
/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(218): */
    /* Path=2, Unique=0: IL_0044: call System.Void System.Console::WriteLine(System.Int32) */
    System_Console_WriteLine_6(stack0_1__);
/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(201): */
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

    UEFI_Code_PolishNotation* stack0_0__ = NULL;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        UEFI_Code_PolishNotation** pstack0_0__;
    } __executionFrame__;

    __executionFrame__.targetCount = 1;
    __executionFrame__.pstack0_0__ = &stack0_0__;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

    /* Path=1, Unique=0: IL_0000: ldarg.0 */
    stack0_0__ = this__;
    /* Path=1, Unique=0: IL_0001: call System.Void System.Object::.ctor() */
    /* Path=1, Unique=0: IL_0006: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return;
}

//////////////////////
// Runtime helpers:

// Runtime cast
void* __UEFI_Code_PolishNotation_IL2C_RuntimeCast__(UEFI_Code_PolishNotation* this__, IL2C_RUNTIME_TYPE_DECL* type)
{
    if (type == il2c_typeof(System_Object)) return this__;
    return __System_Object_IL2C_RuntimeCast__((System_Object*)this__, type);
}

// GC's mark handler
void __UEFI_Code_PolishNotation_IL2C_MarkHandler__(UEFI_Code_PolishNotation* this__)
{
    /* Suppressed invoke base mark handler */
}

static __UEFI_Code_PolishNotation_VTABLE_DECL__ __UEFI_Code_PolishNotation_VTABLE__ = {
    /* internalcall */ __UEFI_Code_PolishNotation_IL2C_RuntimeCast__,
    (void*)__System_Object_ToString__,
    (void*)__System_Object_GetHashCode__,
    (void*)__System_Object_Finalize__,
    (void*)__System_Object_Equals__,
};

IL2C_RUNTIME_TYPE_DECL __UEFI_Code_PolishNotation_RUNTIME_TYPE__ = {
    "UEFI.Code.PolishNotation",
    sizeof(UEFI_Code_PolishNotation),
    /* internalcall */ (void*)__UEFI_Code_PolishNotation_IL2C_MarkHandler__,
};
