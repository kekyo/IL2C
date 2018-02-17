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
    /* Path=1, Unique=0: IL_0006: nop */
/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(14): */
    /* Path=1, Unique=0: IL_0007: nop */
    /* Path=1, Unique=0: IL_0008: ldarg.0 */
    stack0_0__ = this__;
    /* Path=1, Unique=0: IL_0009: ldarg.1 */
    stack1_0__ = nextIndex;
    /* Path=1, Unique=0: IL_000a: stfld System.Int32 UEFI.Code.AbstractNode::NextIndex */
    stack0_0__->NextIndex = stack1_0__;
/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(16): */
    /* Path=1, Unique=0: IL_000f: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return;
}

//////////////////////
// Runtime helpers:

// Runtime cast
void* __UEFI_Code_AbstractNode_IL2C_RuntimeCast__(UEFI_Code_AbstractNode* this__, IL2C_RUNTIME_TYPE_DECL* type)
{
    // This type
    if (type == il2c_typeof(UEFI_Code_AbstractNode)) return this__;

    // Delegate checking base types
    return __System_Object_IL2C_RuntimeCast__((System_Object*)this__, type);
}

// GC's mark handler
void __UEFI_Code_AbstractNode_IL2C_MarkHandler__(UEFI_Code_AbstractNode* this__)
{

    /* Suppressed invoke base mark handler */
}

// Runtime type information
IL2C_RUNTIME_TYPE_DECL __UEFI_Code_AbstractNode_RUNTIME_TYPE__ = {
    "UEFI.Code.AbstractNode",
    sizeof(UEFI_Code_AbstractNode),
    /* internalcall */ (void*)__UEFI_Code_AbstractNode_IL2C_MarkHandler__,
};

//////////////////////
// VTables:

// Vtable of UEFI.Code.AbstractNode
__UEFI_Code_AbstractNode_VTABLE_DECL__ __UEFI_Code_AbstractNode_VTABLE__ = {
    (void*)__UEFI_Code_AbstractNode_IL2C_RuntimeCast__,
    (void*)__System_Object_ToString__,
    (void*)__System_Object_GetHashCode__,
    (void*)__System_Object_Finalize__,
    (void*)__System_Object_Equals__,
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
    /* Path=1, Unique=0: IL_0007: nop */
/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(24): */
    /* Path=1, Unique=0: IL_0008: nop */
    /* Path=1, Unique=0: IL_0009: ldarg.0 */
    stack0_0__ = this__;
    /* Path=1, Unique=0: IL_000a: ldarg.1 */
    stack1_0__ = (int32_t)(oper);
    /* Path=1, Unique=0: IL_000b: stfld System.Char UEFI.Code.OperatorNode::Operator */
    stack0_0__->Operator = (wchar_t)stack1_0__;
/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(26): */
    /* Path=1, Unique=0: IL_0010: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return;
}

//////////////////////
// Runtime helpers:

// Runtime cast
void* __UEFI_Code_OperatorNode_IL2C_RuntimeCast__(UEFI_Code_OperatorNode* this__, IL2C_RUNTIME_TYPE_DECL* type)
{
    // This type
    if (type == il2c_typeof(UEFI_Code_OperatorNode)) return this__;

    // Delegate checking base types
    return __UEFI_Code_AbstractNode_IL2C_RuntimeCast__((UEFI_Code_AbstractNode*)this__, type);
}

// GC's mark handler
void __UEFI_Code_OperatorNode_IL2C_MarkHandler__(UEFI_Code_OperatorNode* this__)
{

    // Delegate checking base types
    __UEFI_Code_AbstractNode*_IL2C_MarkHandler__((UEFI_Code_AbstractNode*)this__);
}

// Runtime type information
IL2C_RUNTIME_TYPE_DECL __UEFI_Code_OperatorNode_RUNTIME_TYPE__ = {
    "UEFI.Code.OperatorNode",
    sizeof(UEFI_Code_OperatorNode),
    /* internalcall */ (void*)__UEFI_Code_OperatorNode_IL2C_MarkHandler__,
};

//////////////////////
// VTables:

// Vtable of UEFI.Code.OperatorNode
__UEFI_Code_OperatorNode_VTABLE_DECL__ __UEFI_Code_OperatorNode_VTABLE__ = {
    (void*)__UEFI_Code_OperatorNode_IL2C_RuntimeCast__,
    (void*)__System_Object_ToString__,
    (void*)__System_Object_GetHashCode__,
    (void*)__System_Object_Finalize__,
    (void*)__System_Object_Equals__,
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
    /* Path=1, Unique=0: IL_0007: nop */
/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(32): */
    /* Path=1, Unique=0: IL_0008: nop */
    /* Path=1, Unique=0: IL_0009: ret */
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
    // This type
    if (type == il2c_typeof(UEFI_Code_ReducibleNode)) return this__;

    // Delegate checking base types
    return __UEFI_Code_AbstractNode_IL2C_RuntimeCast__((UEFI_Code_AbstractNode*)this__, type);
}

// GC's mark handler
void __UEFI_Code_ReducibleNode_IL2C_MarkHandler__(UEFI_Code_ReducibleNode* this__)
{

    // Delegate checking base types
    __UEFI_Code_AbstractNode*_IL2C_MarkHandler__((UEFI_Code_AbstractNode*)this__);
}

// Runtime type information
IL2C_RUNTIME_TYPE_DECL __UEFI_Code_ReducibleNode_RUNTIME_TYPE__ = {
    "UEFI.Code.ReducibleNode",
    sizeof(UEFI_Code_ReducibleNode),
    /* internalcall */ (void*)__UEFI_Code_ReducibleNode_IL2C_MarkHandler__,
};

//////////////////////
// VTables:

// Vtable of UEFI.Code.ReducibleNode
__UEFI_Code_ReducibleNode_VTABLE_DECL__ __UEFI_Code_ReducibleNode_VTABLE__ = {
    (void*)__UEFI_Code_ReducibleNode_IL2C_RuntimeCast__,
    (void*)__System_Object_ToString__,
    (void*)__System_Object_GetHashCode__,
    (void*)__System_Object_Finalize__,
    (void*)__System_Object_Equals__,
    (void*)__UEFI_Code_ReducibleNode_Reduce__,
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
    /* Path=1, Unique=0: IL_0007: nop */
/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(43): */
    /* Path=1, Unique=0: IL_0008: nop */
    /* Path=1, Unique=0: IL_0009: ldarg.0 */
    stack0_0__ = this__;
    /* Path=1, Unique=0: IL_000a: ldarg.1 */
    stack1_0__ = numeric;
    /* Path=1, Unique=0: IL_000b: stfld System.Int32 UEFI.Code.NumericNode::Numeric */
    stack0_0__->Numeric = stack1_0__;
/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(45): */
    /* Path=1, Unique=0: IL_0010: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return;
}

///////////////////////////////////////
// Virtual: Reduce

int32_t __UEFI_Code_NumericNode_Reduce__(UEFI_Code_NumericNode* this__)
{
    //-------------------
    // Local variables:

    int32_t local__;

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

/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(48): */
    /* Path=1, Unique=0: IL_0000: nop */
    /* Path=1, Unique=0: IL_0001: ldarg.0 */
    stack0_0__ = this__;
    /* Path=1, Unique=0: IL_0002: ldfld System.Int32 UEFI.Code.NumericNode::Numeric */
    stack0_1__ = stack0_0__->Numeric;
    /* Path=1, Unique=0: IL_0007: stloc.0 */
    local__ = stack0_1__;
    /* Path=1, Unique=0: IL_0008: br.s IL_000a */
    goto IL_000a;
IL_000a:
/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(50): */
    /* Path=2, Unique=0: IL_000a: ldloc.0 */
    stack0_1__ = local__;
    /* Path=2, Unique=0: IL_000b: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return stack0_1__;
}

//////////////////////
// Runtime helpers:

// Runtime cast
void* __UEFI_Code_NumericNode_IL2C_RuntimeCast__(UEFI_Code_NumericNode* this__, IL2C_RUNTIME_TYPE_DECL* type)
{
    // This type
    if (type == il2c_typeof(UEFI_Code_NumericNode)) return this__;

    // Delegate checking base types
    return __UEFI_Code_ReducibleNode_IL2C_RuntimeCast__((UEFI_Code_ReducibleNode*)this__, type);
}

// GC's mark handler
void __UEFI_Code_NumericNode_IL2C_MarkHandler__(UEFI_Code_NumericNode* this__)
{

    // Delegate checking base types
    __UEFI_Code_ReducibleNode*_IL2C_MarkHandler__((UEFI_Code_ReducibleNode*)this__);
}

// Runtime type information
IL2C_RUNTIME_TYPE_DECL __UEFI_Code_NumericNode_RUNTIME_TYPE__ = {
    "UEFI.Code.NumericNode",
    sizeof(UEFI_Code_NumericNode),
    /* internalcall */ (void*)__UEFI_Code_NumericNode_IL2C_MarkHandler__,
};

//////////////////////
// VTables:

// Vtable of UEFI.Code.NumericNode
__UEFI_Code_NumericNode_VTABLE_DECL__ __UEFI_Code_NumericNode_VTABLE__ = {
    (void*)__UEFI_Code_NumericNode_IL2C_RuntimeCast__,
    (void*)__System_Object_ToString__,
    (void*)__System_Object_GetHashCode__,
    (void*)__System_Object_Finalize__,
    (void*)__System_Object_Equals__,
    (void*)__UEFI_Code_NumericNode_Reduce__,
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
    /* Path=1, Unique=0: IL_0008: nop */
/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(60): */
    /* Path=1, Unique=0: IL_0009: nop */
    /* Path=1, Unique=0: IL_000a: ldarg.0 */
    stack0_0__ = this__;
    /* Path=1, Unique=0: IL_000b: ldarg.1 */
    stack1_1__ = oper;
    /* Path=1, Unique=0: IL_000c: stfld UEFI.Code.OperatorNode UEFI.Code.ExpressionNode::Operator */
    stack0_0__->Operator = stack1_1__;
/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(62): */
    /* Path=1, Unique=0: IL_0011: ldarg.0 */
    stack0_0__ = this__;
    /* Path=1, Unique=0: IL_0012: ldarg.2 */
    stack1_2__ = left;
    /* Path=1, Unique=0: IL_0013: stfld UEFI.Code.ReducibleNode UEFI.Code.ExpressionNode::Left */
    stack0_0__->Left = stack1_2__;
/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(63): */
    /* Path=1, Unique=0: IL_0018: ldarg.0 */
    stack0_0__ = this__;
    /* Path=1, Unique=0: IL_0019: ldarg.3 */
    stack1_2__ = right;
    /* Path=1, Unique=0: IL_001a: stfld UEFI.Code.ReducibleNode UEFI.Code.ExpressionNode::Right */
    stack0_0__->Right = stack1_2__;
/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(64): */
    /* Path=1, Unique=0: IL_001f: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return;
}

///////////////////////////////////////
// Virtual: Reduce

int32_t __UEFI_Code_ExpressionNode_Reduce__(UEFI_Code_ExpressionNode* this__)
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

/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(67): */
    /* Path=1, Unique=0: IL_0000: nop */
    /* Path=1, Unique=0: IL_0001: ldarg.0 */
    stack0_0__ = this__;
    /* Path=1, Unique=0: IL_0002: ldfld UEFI.Code.ReducibleNode UEFI.Code.ExpressionNode::Left */
    stack0_1__ = stack0_0__->Left;
    /* Path=1, Unique=0: IL_0007: callvirt System.Int32 UEFI.Code.ReducibleNode::Reduce() */
    stack0_2__ = UEFI_Code_ReducibleNode_Reduce(stack0_1__);
    /* Path=1, Unique=0: IL_000c: stloc.0 */
    leftResult__ = stack0_2__;
/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(69): */
    /* Path=1, Unique=0: IL_000d: ldarg.0 */
    stack0_0__ = this__;
    /* Path=1, Unique=0: IL_000e: ldfld UEFI.Code.ReducibleNode UEFI.Code.ExpressionNode::Right */
    stack0_1__ = stack0_0__->Right;
    /* Path=1, Unique=0: IL_0013: callvirt System.Int32 UEFI.Code.ReducibleNode::Reduce() */
    stack0_2__ = UEFI_Code_ReducibleNode_Reduce(stack0_1__);
    /* Path=1, Unique=0: IL_0018: stloc.1 */
    rightResult__ = stack0_2__;
/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(70): */
    /* Path=1, Unique=0: IL_0019: ldarg.0 */
    stack0_0__ = this__;
    /* Path=1, Unique=0: IL_001a: ldfld UEFI.Code.OperatorNode UEFI.Code.ExpressionNode::Operator */
    stack0_3__ = stack0_0__->Operator;
    /* Path=1, Unique=0: IL_001f: ldfld System.Char UEFI.Code.OperatorNode::Operator */
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
/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(71): */
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
/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(74): */
    /* Path=2, Unique=0: IL_0033: ldarg.0 */
    stack0_0__ = this__;
    /* Path=2, Unique=0: IL_0034: ldfld UEFI.Code.OperatorNode UEFI.Code.ExpressionNode::Operator */
    stack0_3__ = stack0_0__->Operator;
    /* Path=2, Unique=0: IL_0039: ldfld System.Char UEFI.Code.OperatorNode::Operator */
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
/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(75): */
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
/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(78): */
    /* Path=4, Unique=0: IL_004f: ldarg.0 */
    stack0_0__ = this__;
    /* Path=4, Unique=0: IL_0050: ldfld UEFI.Code.OperatorNode UEFI.Code.ExpressionNode::Operator */
    stack0_3__ = stack0_0__->Operator;
    /* Path=4, Unique=0: IL_0055: ldfld System.Char UEFI.Code.OperatorNode::Operator */
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
/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(79): */
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
/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(82): */
    /* Path=5, Unique=0: IL_006b: ldarg.0 */
    stack0_0__ = this__;
    /* Path=5, Unique=0: IL_006c: ldfld UEFI.Code.OperatorNode UEFI.Code.ExpressionNode::Operator */
    stack0_3__ = stack0_0__->Operator;
    /* Path=5, Unique=0: IL_0071: ldfld System.Char UEFI.Code.OperatorNode::Operator */
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
/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(83): */
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
/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(88): */
    /* Path=6, Unique=0: IL_0087: ldc.i4.0 */
    stack0_2__ = 0;
    /* Path=6, Unique=0: IL_0088: stloc.3 */
    local1__ = stack0_2__;
    /* Path=6, Unique=0: IL_0089: br.s IL_008b */
    goto IL_008b;
IL_008b:
/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(89): */
    /* Path=3, Unique=0: IL_008b: ldloc.3 */
    stack0_2__ = local1__;
    /* Path=3, Unique=0: IL_008c: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return stack0_2__;
}

//////////////////////
// Runtime helpers:

// Runtime cast
void* __UEFI_Code_ExpressionNode_IL2C_RuntimeCast__(UEFI_Code_ExpressionNode* this__, IL2C_RUNTIME_TYPE_DECL* type)
{
    // This type
    if (type == il2c_typeof(UEFI_Code_ExpressionNode)) return this__;

    // Delegate checking base types
    return __UEFI_Code_ReducibleNode_IL2C_RuntimeCast__((UEFI_Code_ReducibleNode*)this__, type);
}

// GC's mark handler
void __UEFI_Code_ExpressionNode_IL2C_MarkHandler__(UEFI_Code_ExpressionNode* this__)
{
    // Try marking each object reference fields
    il2c_try_mark_from_handler(this__->Operator);
    il2c_try_mark_from_handler(this__->Left);
    il2c_try_mark_from_handler(this__->Right);

    // Delegate checking base types
    __UEFI_Code_ReducibleNode*_IL2C_MarkHandler__((UEFI_Code_ReducibleNode*)this__);
}

// Runtime type information
IL2C_RUNTIME_TYPE_DECL __UEFI_Code_ExpressionNode_RUNTIME_TYPE__ = {
    "UEFI.Code.ExpressionNode",
    sizeof(UEFI_Code_ExpressionNode),
    /* internalcall */ (void*)__UEFI_Code_ExpressionNode_IL2C_MarkHandler__,
};

//////////////////////
// VTables:

// Vtable of UEFI.Code.ExpressionNode
__UEFI_Code_ExpressionNode_VTABLE_DECL__ __UEFI_Code_ExpressionNode_VTABLE__ = {
    (void*)__UEFI_Code_ExpressionNode_IL2C_RuntimeCast__,
    (void*)__System_Object_ToString__,
    (void*)__System_Object_GetHashCode__,
    (void*)__System_Object_Finalize__,
    (void*)__System_Object_Equals__,
    (void*)__UEFI_Code_ExpressionNode_Reduce__,
};

////////////////////////////////////////////////////////////
// Type: UEFI.Code.PolishNotation

///////////////////////////////////////
// SkipWhiteSpace

int32_t UEFI_Code_PolishNotation_SkipWhiteSpace(System_String* line, int32_t startIndex)
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

/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(95): */
    /* Path=1, Unique=0: IL_0000: nop */
    /* Path=1, Unique=0: IL_0001: ldarg.1 */
    stack0_0__ = startIndex;
    /* Path=1, Unique=0: IL_0002: stloc.0 */
    index__ = stack0_0__;
    /* Path=1, Unique=0: IL_0003: br.s IL_002a */
    goto IL_002a;
IL_0005:
/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(98): */
    /* Path=3, Unique=0: IL_0005: nop */
    /* Path=3, Unique=0: IL_0006: ldarg.0 */
    stack0_1__ = line;
    /* Path=3, Unique=0: IL_0007: ldloc.0 */
    stack1_2__ = index__;
    /* Path=3, Unique=0: IL_0008: callvirt System.Char System.String::get_Chars(System.Int32) */
    stack0_2__ = System_String_get_Chars(stack0_1__, stack1_2__);
    /* Path=3, Unique=0: IL_000d: stloc.1 */
    ch__ = (wchar_t)stack0_2__;
/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(100): */
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
/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(101): */
    /* Path=5, Unique=0: IL_0022: nop */
    /* Path=5, Unique=0: IL_0023: br.s IL_0037 */
    goto IL_0037;
IL_0025:
/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(104): */
    /* Path=6, Unique=0: IL_0025: ldloc.0 */
    stack0_0__ = index__;
    /* Path=6, Unique=0: IL_0026: ldc.i4.1 */
    stack1_2__ = 1;
    /* Path=6, Unique=0: IL_0027: add */
    stack0_0__ = stack0_0__ + stack1_2__;
    /* Path=6, Unique=0: IL_0028: stloc.0 */
    index__ = stack0_0__;
/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(105): */
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
/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(107): */
    /* Path=2, Unique=0: IL_0037: ldloc.0 */
    stack0_0__ = index__;
    /* Path=2, Unique=0: IL_0038: stloc.s local4 */
    local2__ = stack0_0__;
    /* Path=2, Unique=0: IL_003a: br.s IL_003c */
    goto IL_003c;
IL_003c:
/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(108): */
    /* Path=4, Unique=0: IL_003c: ldloc.s local4 */
    stack0_0__ = local2__;
    /* Path=4, Unique=0: IL_003e: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return stack0_0__;
}

///////////////////////////////////////
// ParseOperator

UEFI_Code_OperatorNode* UEFI_Code_PolishNotation_ParseOperator(System_String* line, int32_t startIndex)
{
    //-------------------
    // Local variables:

    int32_t index__;
    wchar_t ch__;
    bool local0__;
    UEFI_Code_OperatorNode* local1__ = NULL;
    bool local2__;

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
        UEFI_Code_OperatorNode** plocal1__;
        IL2C_CecilHelper_PseudoZeroType** pstack0_1__;
        System_String** pstack0_2__;
        UEFI_Code_OperatorNode** pstack0_4__;
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

/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(111): */
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
/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(113): */
    /* Path=1, Unique=0: IL_0011: nop */
    /* Path=1, Unique=0: IL_0012: ldnull */
    stack0_1__ = NULL;
    /* Path=1, Unique=0: IL_0013: stloc.3 */
    local1__ = (UEFI_Code_OperatorNode*)stack0_1__;
    /* Path=1, Unique=0: IL_0014: br.s IL_005b */
    goto IL_005b;
IL_0016:
/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(117): */
    /* Path=2, Unique=0: IL_0016: ldarg.1 */
    stack0_0__ = startIndex;
    /* Path=2, Unique=0: IL_0017: stloc.0 */
    index__ = stack0_0__;
/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(118): */
    /* Path=2, Unique=0: IL_0018: ldarg.0 */
    stack0_2__ = line;
    /* Path=2, Unique=0: IL_0019: ldloc.0 */
    stack1_2__ = index__;
    /* Path=2, Unique=0: IL_001a: callvirt System.Char System.String::get_Chars(System.Int32) */
    stack0_3__ = System_String_get_Chars(stack0_2__, stack1_2__);
    /* Path=2, Unique=0: IL_001f: stloc.1 */
    ch__ = (wchar_t)stack0_3__;
/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(119): */
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
/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(120): */
    /* Path=4, Unique=0: IL_0040: nop */
    /* Path=4, Unique=0: IL_0041: ldnull */
    stack0_1__ = NULL;
    /* Path=4, Unique=0: IL_0042: stloc.3 */
    local1__ = (UEFI_Code_OperatorNode*)stack0_1__;
    /* Path=4, Unique=0: IL_0043: br.s IL_005b */
    goto IL_005b;
IL_0045:
/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(123): */
    /* Path=5, Unique=0: IL_0045: ldloc.0 */
    stack0_0__ = index__;
    /* Path=5, Unique=0: IL_0046: ldc.i4.1 */
    stack1_2__ = 1;
    /* Path=5, Unique=0: IL_0047: add */
    stack0_0__ = stack0_0__ + stack1_2__;
    /* Path=5, Unique=0: IL_0048: stloc.0 */
    index__ = stack0_0__;
/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(125): */
    /* Path=5, Unique=0: IL_0049: ldarg.0 */
    stack0_2__ = line;
    /* Path=5, Unique=0: IL_004a: ldloc.0 */
    stack1_2__ = index__;
    /* Path=5, Unique=0: IL_004b: call System.Int32 UEFI.Code.PolishNotation::SkipWhiteSpace(System.String,System.Int32) */
    stack0_0__ = UEFI_Code_PolishNotation_SkipWhiteSpace(stack0_2__, stack1_2__);
    /* Path=5, Unique=0: IL_0050: stloc.0 */
    index__ = stack0_0__;
/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(126): */
    /* Path=5, Unique=0: IL_0051: ldloc.1 */
    stack0_0__ = ch__;
    /* Path=5, Unique=0: IL_0052: ldloc.0 */
    stack1_2__ = index__;
    /* Path=5, Unique=0: IL_0053: newobj System.Void UEFI.Code.OperatorNode::.ctor(System.Char,System.Int32) */
    stack0_4__ = il2c_get_uninitialized_object(il2c_typeof(UEFI_Code_OperatorNode));
    stack0_4__->vptr0__ = &__UEFI_Code_OperatorNode_VTABLE__;
    UEFI_Code_OperatorNode__ctor(stack0_4__, (wchar_t)stack0_0__, stack1_2__);
    /* Path=5, Unique=0: IL_0058: stloc.3 */
    local1__ = stack0_4__;
    /* Path=5, Unique=0: IL_0059: br.s IL_005b */
    goto IL_005b;
IL_005b:
/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(127): */
    /* Path=3, Unique=0: IL_005b: ldloc.3 */
    stack0_4__ = local1__;
    /* Path=3, Unique=0: IL_005c: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return stack0_4__;
}

///////////////////////////////////////
// ParseNumeric

UEFI_Code_NumericNode* UEFI_Code_PolishNotation_ParseNumeric(System_String* line, int32_t startIndex)
{
    //-------------------
    // Local variables:

    int32_t index__;
    System_String* token__ = NULL;
    int32_t numeric__;
    bool local0__;
    UEFI_Code_NumericNode* local1__ = NULL;
    wchar_t ch__;
    bool local2__;
    bool local3__;
    bool local4__;
    bool local5__;

    //-------------------
    // Evaluation stacks:

    int32_t stack0_0__;
    IL2C_CecilHelper_PseudoZeroType* stack0_1__ = NULL;
    UEFI_Code_NumericNode* stack0_2__ = NULL;
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
        UEFI_Code_NumericNode** plocal1__;
        IL2C_CecilHelper_PseudoZeroType** pstack0_1__;
        UEFI_Code_NumericNode** pstack0_2__;
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

/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(130): */
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
/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(132): */
    /* Path=1, Unique=0: IL_0011: nop */
    /* Path=1, Unique=0: IL_0012: ldnull */
    stack0_1__ = NULL;
    /* Path=1, Unique=0: IL_0013: stloc.s local4 */
    local1__ = (UEFI_Code_NumericNode*)stack0_1__;
    /* Path=1, Unique=0: IL_0015: br.s IL_008d */
    goto IL_008d;
IL_0017:
/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(136): */
    /* Path=2, Unique=0: IL_0017: ldarg.1 */
    stack0_0__ = startIndex;
    /* Path=2, Unique=0: IL_0018: stloc.0 */
    index__ = stack0_0__;
    /* Path=2, Unique=0: IL_0019: br.s IL_0039 */
    goto IL_0039;
IL_001b:
/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(138): */
    /* Path=5, Unique=0: IL_001b: nop */
    /* Path=5, Unique=0: IL_001c: ldarg.0 */
    stack0_3__ = line;
    /* Path=5, Unique=0: IL_001d: ldloc.0 */
    stack1_2__ = index__;
    /* Path=5, Unique=0: IL_001e: callvirt System.Char System.String::get_Chars(System.Int32) */
    stack0_4__ = System_String_get_Chars(stack0_3__, stack1_2__);
    /* Path=5, Unique=0: IL_0023: stloc.s local5 */
    ch__ = (wchar_t)stack0_4__;
/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(140): */
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
/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(141): */
    /* Path=5, Unique=0: IL_0031: nop */
    /* Path=5, Unique=0: IL_0032: br.s IL_0048 */
    goto IL_0048;
IL_0034:
/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(144): */
    /* Path=7, Unique=0: IL_0034: ldloc.0 */
    stack0_0__ = index__;
    /* Path=7, Unique=0: IL_0035: ldc.i4.1 */
    stack1_2__ = 1;
    /* Path=7, Unique=0: IL_0036: add */
    stack0_0__ = stack0_0__ + stack1_2__;
    /* Path=7, Unique=0: IL_0037: stloc.0 */
    index__ = stack0_0__;
/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(145): */
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
/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(147): */
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
/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(148): */
    /* Path=4, Unique=0: IL_0052: nop */
    /* Path=4, Unique=0: IL_0053: ldnull */
    stack0_1__ = NULL;
    /* Path=4, Unique=0: IL_0054: stloc.s local4 */
    local1__ = (UEFI_Code_NumericNode*)stack0_1__;
    /* Path=4, Unique=0: IL_0056: br.s IL_008d */
    goto IL_008d;
IL_0058:
/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(152): */
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
/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(153): */
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
/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(154): */
    /* Path=6, Unique=0: IL_0074: nop */
    /* Path=6, Unique=0: IL_0075: ldnull */
    stack0_1__ = NULL;
    /* Path=6, Unique=0: IL_0076: stloc.s local4 */
    local1__ = (UEFI_Code_NumericNode*)stack0_1__;
    /* Path=6, Unique=0: IL_0078: br.s IL_008d */
    goto IL_008d;
IL_007a:
/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(158): */
    /* Path=8, Unique=0: IL_007a: ldarg.0 */
    stack0_3__ = line;
    /* Path=8, Unique=0: IL_007b: ldloc.0 */
    stack1_2__ = index__;
    /* Path=8, Unique=0: IL_007c: call System.Int32 UEFI.Code.PolishNotation::SkipWhiteSpace(System.String,System.Int32) */
    stack0_0__ = UEFI_Code_PolishNotation_SkipWhiteSpace(stack0_3__, stack1_2__);
    /* Path=8, Unique=0: IL_0081: stloc.0 */
    index__ = stack0_0__;
/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(159): */
    /* Path=8, Unique=0: IL_0082: ldloc.2 */
    stack0_0__ = numeric__;
    /* Path=8, Unique=0: IL_0083: ldloc.0 */
    stack1_2__ = index__;
    /* Path=8, Unique=0: IL_0084: newobj System.Void UEFI.Code.NumericNode::.ctor(System.Int32,System.Int32) */
    stack0_2__ = il2c_get_uninitialized_object(il2c_typeof(UEFI_Code_NumericNode));
    stack0_2__->vptr0__ = &__UEFI_Code_NumericNode_VTABLE__;
    UEFI_Code_NumericNode__ctor(stack0_2__, stack0_0__, stack1_2__);
    /* Path=8, Unique=0: IL_0089: stloc.s local4 */
    local1__ = stack0_2__;
    /* Path=8, Unique=0: IL_008b: br.s IL_008d */
    goto IL_008d;
IL_008d:
/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(160): */
    /* Path=3, Unique=0: IL_008d: ldloc.s local4 */
    stack0_2__ = local1__;
    /* Path=3, Unique=0: IL_008f: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return stack0_2__;
}

///////////////////////////////////////
// ParseExpression

UEFI_Code_ExpressionNode* UEFI_Code_PolishNotation_ParseExpression(System_String* line, int32_t startIndex)
{
    //-------------------
    // Local variables:

    UEFI_Code_OperatorNode* oper__ = NULL;
    UEFI_Code_ReducibleNode* left__ = NULL;
    UEFI_Code_ReducibleNode* right__ = NULL;
    int32_t index__;
    bool local0__;
    UEFI_Code_ExpressionNode* local1__ = NULL;
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
    UEFI_Code_OperatorNode* stack0_3__ = NULL;
    UEFI_Code_ExpressionNode* stack0_4__ = NULL;
    UEFI_Code_NumericNode* stack0_5__ = NULL;
    UEFI_Code_ReducibleNode* stack0_6__ = NULL;
    System_String* stack1_0__ = NULL;
    int32_t stack1_1__;
    int32_t stack1_2__;
    IL2C_CecilHelper_PseudoZeroType* stack1_3__ = NULL;
    UEFI_Code_OperatorNode* stack1_4__ = NULL;
    UEFI_Code_ReducibleNode* stack1_5__ = NULL;
    UEFI_Code_ReducibleNode* stack2_0__ = NULL;
    int32_t stack3_0__;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        UEFI_Code_OperatorNode** poper__;
        UEFI_Code_ReducibleNode** pleft__;
        UEFI_Code_ReducibleNode** pright__;
        UEFI_Code_ExpressionNode** plocal1__;
        IL2C_CecilHelper_PseudoZeroType** pstack0_1__;
        System_String** pstack0_2__;
        UEFI_Code_OperatorNode** pstack0_3__;
        UEFI_Code_ExpressionNode** pstack0_4__;
        UEFI_Code_NumericNode** pstack0_5__;
        UEFI_Code_ReducibleNode** pstack0_6__;
        System_String** pstack1_0__;
        IL2C_CecilHelper_PseudoZeroType** pstack1_3__;
        UEFI_Code_OperatorNode** pstack1_4__;
        UEFI_Code_ReducibleNode** pstack1_5__;
        UEFI_Code_ReducibleNode** pstack2_0__;
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

/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(163): */
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
/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(165): */
    /* Path=1, Unique=0: IL_0013: nop */
    /* Path=1, Unique=0: IL_0014: ldnull */
    stack0_1__ = NULL;
    /* Path=1, Unique=0: IL_0015: stloc.s local5 */
    local1__ = (UEFI_Code_ExpressionNode*)stack0_1__;
    /* Path=1, Unique=0: IL_0017: br IL_00bd */
    goto IL_00bd;
IL_001c:
/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(169): */
    /* Path=2, Unique=0: IL_001c: ldarg.0 */
    stack0_2__ = line;
    /* Path=2, Unique=0: IL_001d: ldarg.1 */
    stack1_2__ = startIndex;
    /* Path=2, Unique=0: IL_001e: call UEFI.Code.OperatorNode UEFI.Code.PolishNotation::ParseOperator(System.String,System.Int32) */
    stack0_3__ = UEFI_Code_PolishNotation_ParseOperator(stack0_2__, stack1_2__);
    /* Path=2, Unique=0: IL_0023: stloc.0 */
    oper__ = stack0_3__;
/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(170): */
    /* Path=2, Unique=0: IL_0024: ldloc.0 */
    stack0_3__ = oper__;
    /* Path=2, Unique=0: IL_0025: ldnull */
    stack1_3__ = NULL;
    /* Path=2, Unique=0: IL_0026: ceq */
    stack0_0__ = (stack0_3__ == ((UEFI_Code_OperatorNode*)stack1_3__)) ? 1 : 0;
    /* Path=2, Unique=0: IL_0028: stloc.s local6 */
    local2__ = stack0_0__ ? true : false;
    /* Path=2, Unique=0: IL_002a: ldloc.s local6 */
    stack0_0__ = local2__;
    /* Path=2, Unique=0: IL_002c: brfalse.s IL_0037 */
    if (stack0_0__ == 0) goto IL_0037;
/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(171): */
    /* Path=2, Unique=0: IL_002e: nop */
    /* Path=2, Unique=0: IL_002f: ldnull */
    stack0_1__ = NULL;
    /* Path=2, Unique=0: IL_0030: stloc.s local5 */
    local1__ = (UEFI_Code_ExpressionNode*)stack0_1__;
    /* Path=2, Unique=0: IL_0032: br IL_00bd */
    goto IL_00bd;
IL_0037:
/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(175): */
    /* Path=4, Unique=0: IL_0037: ldarg.0 */
    stack0_2__ = line;
    /* Path=4, Unique=0: IL_0038: ldloc.0 */
    stack1_4__ = oper__;
    /* Path=4, Unique=0: IL_0039: ldfld System.Int32 UEFI.Code.AbstractNode::NextIndex */
    stack1_2__ = stack1_4__->NextIndex;
    /* Path=4, Unique=0: IL_003e: call UEFI.Code.NumericNode UEFI.Code.PolishNotation::ParseNumeric(System.String,System.Int32) */
    stack0_5__ = UEFI_Code_PolishNotation_ParseNumeric(stack0_2__, stack1_2__);
    /* Path=4, Unique=0: IL_0043: stloc.1 */
    left__ = (UEFI_Code_ReducibleNode*)stack0_5__;
/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(176): */
    /* Path=4, Unique=0: IL_0044: ldloc.1 */
    stack0_6__ = left__;
    /* Path=4, Unique=0: IL_0045: ldnull */
    stack1_3__ = NULL;
    /* Path=4, Unique=0: IL_0046: ceq */
    stack0_0__ = (stack0_6__ == ((UEFI_Code_ReducibleNode*)stack1_3__)) ? 1 : 0;
    /* Path=4, Unique=0: IL_0048: stloc.s local7 */
    local3__ = stack0_0__ ? true : false;
    /* Path=4, Unique=0: IL_004a: ldloc.s local7 */
    stack0_0__ = local3__;
    /* Path=4, Unique=0: IL_004c: brfalse.s IL_006d */
    if (stack0_0__ == 0) goto IL_006d;
/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(177): */
    /* Path=4, Unique=0: IL_004e: nop */
    /* Path=4, Unique=0: IL_004f: ldarg.0 */
    stack0_2__ = line;
    /* Path=4, Unique=0: IL_0050: ldloc.0 */
    stack1_4__ = oper__;
    /* Path=4, Unique=0: IL_0051: ldfld System.Int32 UEFI.Code.AbstractNode::NextIndex */
    stack1_2__ = stack1_4__->NextIndex;
    /* Path=4, Unique=0: IL_0056: call UEFI.Code.ExpressionNode UEFI.Code.PolishNotation::ParseExpression(System.String,System.Int32) */
    stack0_4__ = UEFI_Code_PolishNotation_ParseExpression(stack0_2__, stack1_2__);
    /* Path=4, Unique=0: IL_005b: stloc.1 */
    left__ = (UEFI_Code_ReducibleNode*)stack0_4__;
/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(179): */
    /* Path=4, Unique=0: IL_005c: ldloc.1 */
    stack0_6__ = left__;
    /* Path=4, Unique=0: IL_005d: ldnull */
    stack1_3__ = NULL;
    /* Path=4, Unique=0: IL_005e: ceq */
    stack0_0__ = (stack0_6__ == ((UEFI_Code_ReducibleNode*)stack1_3__)) ? 1 : 0;
    /* Path=4, Unique=0: IL_0060: stloc.s local8 */
    local4__ = stack0_0__ ? true : false;
    /* Path=4, Unique=0: IL_0062: ldloc.s local8 */
    stack0_0__ = local4__;
    /* Path=4, Unique=0: IL_0064: brfalse.s IL_006c */
    if (stack0_0__ == 0) goto IL_006c;
/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(180): */
    /* Path=4, Unique=0: IL_0066: nop */
    /* Path=4, Unique=0: IL_0067: ldnull */
    stack0_1__ = NULL;
    /* Path=4, Unique=0: IL_0068: stloc.s local5 */
    local1__ = (UEFI_Code_ExpressionNode*)stack0_1__;
    /* Path=4, Unique=0: IL_006a: br.s IL_00bd */
    goto IL_00bd;
IL_006c:
/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(183): */
    /* Path=6, Unique=0: IL_006c: nop */
IL_006d:
    /* Path=5, Unique=0: IL_006d: ldarg.0 */
    stack0_2__ = line;
    /* Path=5, Unique=0: IL_006e: ldloc.1 */
    stack1_5__ = left__;
    /* Path=5, Unique=0: IL_006f: ldfld System.Int32 UEFI.Code.AbstractNode::NextIndex */
    stack1_2__ = stack1_5__->NextIndex;
    /* Path=5, Unique=0: IL_0074: call UEFI.Code.NumericNode UEFI.Code.PolishNotation::ParseNumeric(System.String,System.Int32) */
    stack0_5__ = UEFI_Code_PolishNotation_ParseNumeric(stack0_2__, stack1_2__);
    /* Path=5, Unique=0: IL_0079: stloc.2 */
    right__ = (UEFI_Code_ReducibleNode*)stack0_5__;
/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(186): */
    /* Path=5, Unique=0: IL_007a: ldloc.2 */
    stack0_6__ = right__;
    /* Path=5, Unique=0: IL_007b: ldnull */
    stack1_3__ = NULL;
    /* Path=5, Unique=0: IL_007c: ceq */
    stack0_0__ = (stack0_6__ == ((UEFI_Code_ReducibleNode*)stack1_3__)) ? 1 : 0;
    /* Path=5, Unique=0: IL_007e: stloc.s local9 */
    local5__ = stack0_0__ ? true : false;
    /* Path=5, Unique=0: IL_0080: ldloc.s local9 */
    stack0_0__ = local5__;
    /* Path=5, Unique=0: IL_0082: brfalse.s IL_00a3 */
    if (stack0_0__ == 0) goto IL_00a3;
/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(187): */
    /* Path=5, Unique=0: IL_0084: nop */
    /* Path=5, Unique=0: IL_0085: ldarg.0 */
    stack0_2__ = line;
    /* Path=5, Unique=0: IL_0086: ldloc.1 */
    stack1_5__ = left__;
    /* Path=5, Unique=0: IL_0087: ldfld System.Int32 UEFI.Code.AbstractNode::NextIndex */
    stack1_2__ = stack1_5__->NextIndex;
    /* Path=5, Unique=0: IL_008c: call UEFI.Code.ExpressionNode UEFI.Code.PolishNotation::ParseExpression(System.String,System.Int32) */
    stack0_4__ = UEFI_Code_PolishNotation_ParseExpression(stack0_2__, stack1_2__);
    /* Path=5, Unique=0: IL_0091: stloc.2 */
    right__ = (UEFI_Code_ReducibleNode*)stack0_4__;
/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(189): */
    /* Path=5, Unique=0: IL_0092: ldloc.2 */
    stack0_6__ = right__;
    /* Path=5, Unique=0: IL_0093: ldnull */
    stack1_3__ = NULL;
    /* Path=5, Unique=0: IL_0094: ceq */
    stack0_0__ = (stack0_6__ == ((UEFI_Code_ReducibleNode*)stack1_3__)) ? 1 : 0;
    /* Path=5, Unique=0: IL_0096: stloc.s local10 */
    local6__ = stack0_0__ ? true : false;
    /* Path=5, Unique=0: IL_0098: ldloc.s local10 */
    stack0_0__ = local6__;
    /* Path=5, Unique=0: IL_009a: brfalse.s IL_00a2 */
    if (stack0_0__ == 0) goto IL_00a2;
/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(190): */
    /* Path=5, Unique=0: IL_009c: nop */
    /* Path=5, Unique=0: IL_009d: ldnull */
    stack0_1__ = NULL;
    /* Path=5, Unique=0: IL_009e: stloc.s local5 */
    local1__ = (UEFI_Code_ExpressionNode*)stack0_1__;
    /* Path=5, Unique=0: IL_00a0: br.s IL_00bd */
    goto IL_00bd;
IL_00a2:
/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(193): */
    /* Path=8, Unique=0: IL_00a2: nop */
IL_00a3:
    /* Path=7, Unique=0: IL_00a3: ldarg.0 */
    stack0_2__ = line;
    /* Path=7, Unique=0: IL_00a4: ldloc.2 */
    stack1_5__ = right__;
    /* Path=7, Unique=0: IL_00a5: ldfld System.Int32 UEFI.Code.AbstractNode::NextIndex */
    stack1_2__ = stack1_5__->NextIndex;
    /* Path=7, Unique=0: IL_00aa: call System.Int32 UEFI.Code.PolishNotation::SkipWhiteSpace(System.String,System.Int32) */
    stack0_0__ = UEFI_Code_PolishNotation_SkipWhiteSpace(stack0_2__, stack1_2__);
    /* Path=7, Unique=0: IL_00af: stloc.3 */
    index__ = stack0_0__;
/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(196): */
    /* Path=7, Unique=0: IL_00b0: ldloc.0 */
    stack0_3__ = oper__;
    /* Path=7, Unique=0: IL_00b1: ldloc.1 */
    stack1_5__ = left__;
    /* Path=7, Unique=0: IL_00b2: ldloc.2 */
    stack2_0__ = right__;
    /* Path=7, Unique=0: IL_00b3: ldloc.3 */
    stack3_0__ = index__;
    /* Path=7, Unique=0: IL_00b4: newobj System.Void UEFI.Code.ExpressionNode::.ctor(UEFI.Code.OperatorNode,UEFI.Code.ReducibleNode,UEFI.Code.ReducibleNode,System.Int32) */
    stack0_4__ = il2c_get_uninitialized_object(il2c_typeof(UEFI_Code_ExpressionNode));
    stack0_4__->vptr0__ = &__UEFI_Code_ExpressionNode_VTABLE__;
    UEFI_Code_ExpressionNode__ctor(stack0_4__, stack0_3__, stack1_5__, stack2_0__, stack3_0__);
    /* Path=7, Unique=0: IL_00b9: stloc.s local5 */
    local1__ = stack0_4__;
    /* Path=7, Unique=0: IL_00bb: br.s IL_00bd */
    goto IL_00bd;
IL_00bd:
/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(197): */
    /* Path=3, Unique=0: IL_00bd: ldloc.s local5 */
    stack0_4__ = local1__;
    /* Path=3, Unique=0: IL_00bf: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return stack0_4__;
}

///////////////////////////////////////
// Main

void UEFI_Code_PolishNotation_Main(void)
{
    //-------------------
    // Local variables:

    System_String* line__ = NULL;
    bool local0__;
    UEFI_Code_ExpressionNode* expr__ = NULL;
    int32_t result__;
    bool local1__;
    bool local2__;

    //-------------------
    // Evaluation stacks:

    int32_t stack0_0__;
    System_String* stack0_1__ = NULL;
    UEFI_Code_ExpressionNode* stack0_2__ = NULL;
    int32_t stack1_0__;
    IL2C_CecilHelper_PseudoZeroType* stack1_1__ = NULL;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        System_String** pline__;
        UEFI_Code_ExpressionNode** pexpr__;
        System_String** pstack0_1__;
        UEFI_Code_ExpressionNode** pstack0_2__;
        IL2C_CecilHelper_PseudoZeroType** pstack1_1__;
    } __executionFrame__;

    __executionFrame__.targetCount = 5;
    __executionFrame__.pline__ = &line__;
    __executionFrame__.pexpr__ = &expr__;
    __executionFrame__.pstack0_1__ = &stack0_1__;
    __executionFrame__.pstack0_2__ = &stack0_2__;
    __executionFrame__.pstack1_1__ = &stack1_1__;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(200): */
    /* Path=1, Unique=0: IL_0000: nop */
    /* Path=1, Unique=0: IL_0001: br.s IL_0064 */
    goto IL_0064;
IL_0003:
/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(202): */
    /* Path=3, Unique=0: IL_0003: nop */
    /* Path=3, Unique=0: IL_0004: call System.Void System.Console::WriteLine() */
    System_Console_WriteLine();
    /* Path=3, Unique=0: IL_0009: nop */
/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(204): */
    /* Path=3, Unique=0: IL_000a: ldstr "PN> " */
    stack0_1__ = string0__;
    /* Path=3, Unique=0: IL_000f: call System.Void System.Console::Write(System.String) */
    System_Console_Write_9(stack0_1__);
    /* Path=3, Unique=0: IL_0014: nop */
/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(205): */
    /* Path=3, Unique=0: IL_0015: call System.String System.Console::ReadLine() */
    stack0_1__ = System_Console_ReadLine();
    /* Path=3, Unique=0: IL_001a: stloc.0 */
    line__ = stack0_1__;
/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(206): */
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
    /* Path=3, Unique=0: IL_0026: brfalse.s IL_0063 */
    if (stack0_0__ == 0) goto IL_0063;
/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(207): */
    /* Path=3, Unique=0: IL_0028: nop */
    /* Path=3, Unique=0: IL_0029: ldloc.0 */
    stack0_1__ = line__;
    /* Path=3, Unique=0: IL_002a: ldc.i4.0 */
    stack1_0__ = 0;
    /* Path=3, Unique=0: IL_002b: call UEFI.Code.ExpressionNode UEFI.Code.PolishNotation::ParseExpression(System.String,System.Int32) */
    stack0_2__ = UEFI_Code_PolishNotation_ParseExpression(stack0_1__, stack1_0__);
    /* Path=3, Unique=0: IL_0030: stloc.2 */
    expr__ = stack0_2__;
/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(209): */
    /* Path=3, Unique=0: IL_0031: ldloc.2 */
    stack0_2__ = expr__;
    /* Path=3, Unique=0: IL_0032: ldnull */
    stack1_1__ = NULL;
    /* Path=3, Unique=0: IL_0033: ceq */
    stack0_0__ = (stack0_2__ == ((UEFI_Code_ExpressionNode*)stack1_1__)) ? 1 : 0;
    /* Path=3, Unique=0: IL_0035: stloc.s local4 */
    local1__ = stack0_0__ ? true : false;
    /* Path=3, Unique=0: IL_0037: ldloc.s local4 */
    stack0_0__ = local1__;
    /* Path=3, Unique=0: IL_0039: brfalse.s IL_0049 */
    if (stack0_0__ == 0) goto IL_0049;
/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(210): */
    /* Path=3, Unique=0: IL_003b: nop */
    /* Path=3, Unique=0: IL_003c: ldstr "Syntax error." */
    stack0_1__ = string1__;
    /* Path=3, Unique=0: IL_0041: call System.Void System.Console::WriteLine(System.String) */
    System_Console_WriteLine_10(stack0_1__);
    /* Path=3, Unique=0: IL_0046: nop */
/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(212): */
    /* Path=3, Unique=0: IL_0047: br.s IL_0064 */
    goto IL_0064;
IL_0049:
/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(215): */
    /* Path=5, Unique=0: IL_0049: ldloc.2 */
    stack0_2__ = expr__;
    /* Path=5, Unique=0: IL_004a: callvirt System.Int32 UEFI.Code.ReducibleNode::Reduce() */
    stack0_0__ = UEFI_Code_ReducibleNode_Reduce((UEFI_Code_ReducibleNode*)stack0_2__);
    /* Path=5, Unique=0: IL_004f: stloc.3 */
    result__ = stack0_0__;
/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(217): */
    /* Path=5, Unique=0: IL_0050: ldstr "Reuslt=" */
    stack0_1__ = string2__;
    /* Path=5, Unique=0: IL_0055: call System.Void System.Console::Write(System.String) */
    System_Console_Write_9(stack0_1__);
    /* Path=5, Unique=0: IL_005a: nop */
/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(218): */
    /* Path=5, Unique=0: IL_005b: ldloc.3 */
    stack0_0__ = result__;
    /* Path=5, Unique=0: IL_005c: call System.Void System.Console::WriteLine(System.Int32) */
    System_Console_WriteLine_6(stack0_0__);
    /* Path=5, Unique=0: IL_0061: nop */
/* D:\\PROJECT\\IL2C\\samples\\UEFI\\UEFI.Code\\PolishNotation.cs(219): */
    /* Path=5, Unique=0: IL_0062: nop */
IL_0063:
    /* Path=4, Unique=0: IL_0063: nop */
IL_0064:
    /* Path=2, Unique=0: IL_0064: ldc.i4.1 */
    stack0_0__ = 1;
    /* Path=2, Unique=0: IL_0065: stloc.s local5 */
    local2__ = stack0_0__ ? true : false;
    /* Path=2, Unique=0: IL_0067: br.s IL_0003 */
    goto IL_0003;
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
    /* Path=1, Unique=0: IL_0006: nop */
    /* Path=1, Unique=0: IL_0007: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return;
}

//////////////////////
// Runtime helpers:

// Runtime cast
void* __UEFI_Code_PolishNotation_IL2C_RuntimeCast__(UEFI_Code_PolishNotation* this__, IL2C_RUNTIME_TYPE_DECL* type)
{
    // This type
    if (type == il2c_typeof(UEFI_Code_PolishNotation)) return this__;

    // Delegate checking base types
    return __System_Object_IL2C_RuntimeCast__((System_Object*)this__, type);
}

// GC's mark handler
void __UEFI_Code_PolishNotation_IL2C_MarkHandler__(UEFI_Code_PolishNotation* this__)
{

    /* Suppressed invoke base mark handler */
}

// Runtime type information
IL2C_RUNTIME_TYPE_DECL __UEFI_Code_PolishNotation_RUNTIME_TYPE__ = {
    "UEFI.Code.PolishNotation",
    sizeof(UEFI_Code_PolishNotation),
    /* internalcall */ (void*)__UEFI_Code_PolishNotation_IL2C_MarkHandler__,
};

//////////////////////
// VTables:

// Vtable of UEFI.Code.PolishNotation
__UEFI_Code_PolishNotation_VTABLE_DECL__ __UEFI_Code_PolishNotation_VTABLE__ = {
    (void*)__UEFI_Code_PolishNotation_IL2C_RuntimeCast__,
    (void*)__System_Object_ToString__,
    (void*)__System_Object_GetHashCode__,
    (void*)__System_Object_Finalize__,
    (void*)__System_Object_Equals__,
};
