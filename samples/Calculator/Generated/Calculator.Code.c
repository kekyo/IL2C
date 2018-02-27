#include "Calculator.Code.h"

//////////////////////////////////////////////////////////////////////////////////
// Const strings:

IL2C_CONST_STRING(string0__, L"PN> ");
IL2C_CONST_STRING(string1__, L"exit");
IL2C_CONST_STRING(string2__, L"Syntax error.");
IL2C_CONST_STRING(string3__, L"Reuslt=");

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
// Type: Calculator.AbstractNode

///////////////////////////////////////
// .ctor

void Calculator_AbstractNode__ctor(Calculator_AbstractNode* this__, int32_t nextIndex)
{
    //-------------------
    // Local variables:


    //-------------------
    // Evaluation stacks:

    Calculator_AbstractNode* stack0_0__ = NULL;
    int32_t stack1_0__;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        Calculator_AbstractNode** pstack0_0__;
    } __executionFrame__;

    __executionFrame__.targetCount = 1;
    __executionFrame__.pstack0_0__ = &stack0_0__;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(12): */
    /* Path=1, Unique=0: IL_0000: ldarg.0 */
    stack0_0__ = this__;
    /* Path=1, Unique=0: IL_0001: call System.Void System.Object::.ctor() */
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(14): */
    /* Path=1, Unique=0: IL_0006: ldarg.0 */
    stack0_0__ = this__;
    /* Path=1, Unique=0: IL_0007: ldarg.1 */
    stack1_0__ = nextIndex;
    /* Path=1, Unique=0: IL_0008: stfld System.Int32 Calculator.AbstractNode::NextIndex */
    stack0_0__->NextIndex = stack1_0__;
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(15): */
    /* Path=1, Unique=0: IL_000d: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return;
}

//////////////////////
// Runtime helpers:

// Runtime cast
void* __Calculator_AbstractNode_IL2C_RuntimeCast__(Calculator_AbstractNode* this__, IL2C_RUNTIME_TYPE_DECL* type)
{
    // This type
    if (type == il2c_typeof(Calculator_AbstractNode)) return this__;

    // Delegate checking base types
    return __System_Object_IL2C_RuntimeCast__((System_Object*)this__, type);
}

// GC's mark handler
void __Calculator_AbstractNode_IL2C_MarkHandler__(Calculator_AbstractNode* this__)
{

    /* Suppressed invoke base mark handler */
}

// Runtime type information
IL2C_RUNTIME_TYPE_DECL __Calculator_AbstractNode_RUNTIME_TYPE__ = {
    "Calculator.AbstractNode",
    sizeof(Calculator_AbstractNode),
    /* internalcall */ (void*)__Calculator_AbstractNode_IL2C_MarkHandler__,
};

//////////////////////
// VTables:

// Vtable of Calculator.AbstractNode
__Calculator_AbstractNode_VTABLE_DECL__ __Calculator_AbstractNode_VTABLE__ = {
    (void*)__Calculator_AbstractNode_IL2C_RuntimeCast__,
    (void*)__System_Object_ToString__,
    (void*)__System_Object_GetHashCode__,
    (void*)__System_Object_Finalize__,
    (void*)__System_Object_Equals__,
};

////////////////////////////////////////////////////////////
// Type: Calculator.OperatorNode

///////////////////////////////////////
// .ctor

void Calculator_OperatorNode__ctor(Calculator_OperatorNode* this__, wchar_t oper, int32_t nextIndex)
{
    //-------------------
    // Local variables:


    //-------------------
    // Evaluation stacks:

    Calculator_OperatorNode* stack0_0__ = NULL;
    int32_t stack1_0__;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        Calculator_OperatorNode** pstack0_0__;
    } __executionFrame__;

    __executionFrame__.targetCount = 1;
    __executionFrame__.pstack0_0__ = &stack0_0__;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(22): */
    /* Path=1, Unique=0: IL_0000: ldarg.0 */
    stack0_0__ = this__;
    /* Path=1, Unique=0: IL_0001: ldarg.2 */
    stack1_0__ = nextIndex;
    /* Path=1, Unique=0: IL_0002: call System.Void Calculator.AbstractNode::.ctor(System.Int32) */
    Calculator_AbstractNode__ctor((Calculator_AbstractNode*)stack0_0__, stack1_0__);
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(24): */
    /* Path=1, Unique=0: IL_0007: ldarg.0 */
    stack0_0__ = this__;
    /* Path=1, Unique=0: IL_0008: ldarg.1 */
    stack1_0__ = (int32_t)(oper);
    /* Path=1, Unique=0: IL_0009: stfld System.Char Calculator.OperatorNode::Operator */
    stack0_0__->Operator = (wchar_t)stack1_0__;
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(25): */
    /* Path=1, Unique=0: IL_000e: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return;
}

//////////////////////
// Runtime helpers:

// Runtime cast
void* __Calculator_OperatorNode_IL2C_RuntimeCast__(Calculator_OperatorNode* this__, IL2C_RUNTIME_TYPE_DECL* type)
{
    // This type
    if (type == il2c_typeof(Calculator_OperatorNode)) return this__;

    // Delegate checking base types
    return __Calculator_AbstractNode_IL2C_RuntimeCast__((Calculator_AbstractNode*)this__, type);
}

// GC's mark handler
void __Calculator_OperatorNode_IL2C_MarkHandler__(Calculator_OperatorNode* this__)
{

    // Delegate checking base types
    __Calculator_AbstractNode_IL2C_MarkHandler__((Calculator_AbstractNode*)this__);
}

// Runtime type information
IL2C_RUNTIME_TYPE_DECL __Calculator_OperatorNode_RUNTIME_TYPE__ = {
    "Calculator.OperatorNode",
    sizeof(Calculator_OperatorNode),
    /* internalcall */ (void*)__Calculator_OperatorNode_IL2C_MarkHandler__,
};

//////////////////////
// VTables:

// Vtable of Calculator.OperatorNode
__Calculator_OperatorNode_VTABLE_DECL__ __Calculator_OperatorNode_VTABLE__ = {
    (void*)__Calculator_OperatorNode_IL2C_RuntimeCast__,
    (void*)__System_Object_ToString__,
    (void*)__System_Object_GetHashCode__,
    (void*)__System_Object_Finalize__,
    (void*)__System_Object_Equals__,
};

////////////////////////////////////////////////////////////
// Type: Calculator.ReducibleNode

///////////////////////////////////////
// .ctor

void Calculator_ReducibleNode__ctor(Calculator_ReducibleNode* this__, int32_t nextIndex)
{
    //-------------------
    // Local variables:


    //-------------------
    // Evaluation stacks:

    Calculator_ReducibleNode* stack0_0__ = NULL;
    int32_t stack1_0__;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        Calculator_ReducibleNode** pstack0_0__;
    } __executionFrame__;

    __executionFrame__.targetCount = 1;
    __executionFrame__.pstack0_0__ = &stack0_0__;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(30): */
    /* Path=1, Unique=0: IL_0000: ldarg.0 */
    stack0_0__ = this__;
    /* Path=1, Unique=0: IL_0001: ldarg.1 */
    stack1_0__ = nextIndex;
    /* Path=1, Unique=0: IL_0002: call System.Void Calculator.AbstractNode::.ctor(System.Int32) */
    Calculator_AbstractNode__ctor((Calculator_AbstractNode*)stack0_0__, stack1_0__);
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(32): */
    /* Path=1, Unique=0: IL_0007: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return;
}

///////////////////////////////////////
// Abstract: Reduce

int32_t __Calculator_ReducibleNode_Reduce__(Calculator_ReducibleNode* this__)
{
    // WARNING: Pure virtual function called.
    //TODO: throw : assert(0);
    return (int32_t)0;
}

//////////////////////
// Runtime helpers:

// Runtime cast
void* __Calculator_ReducibleNode_IL2C_RuntimeCast__(Calculator_ReducibleNode* this__, IL2C_RUNTIME_TYPE_DECL* type)
{
    // This type
    if (type == il2c_typeof(Calculator_ReducibleNode)) return this__;

    // Delegate checking base types
    return __Calculator_AbstractNode_IL2C_RuntimeCast__((Calculator_AbstractNode*)this__, type);
}

// GC's mark handler
void __Calculator_ReducibleNode_IL2C_MarkHandler__(Calculator_ReducibleNode* this__)
{

    // Delegate checking base types
    __Calculator_AbstractNode_IL2C_MarkHandler__((Calculator_AbstractNode*)this__);
}

// Runtime type information
IL2C_RUNTIME_TYPE_DECL __Calculator_ReducibleNode_RUNTIME_TYPE__ = {
    "Calculator.ReducibleNode",
    sizeof(Calculator_ReducibleNode),
    /* internalcall */ (void*)__Calculator_ReducibleNode_IL2C_MarkHandler__,
};

//////////////////////
// VTables:

// Vtable of Calculator.ReducibleNode
__Calculator_ReducibleNode_VTABLE_DECL__ __Calculator_ReducibleNode_VTABLE__ = {
    (void*)__Calculator_ReducibleNode_IL2C_RuntimeCast__,
    (void*)__System_Object_ToString__,
    (void*)__System_Object_GetHashCode__,
    (void*)__System_Object_Finalize__,
    (void*)__System_Object_Equals__,
    (void*)__Calculator_ReducibleNode_Reduce__,
};

////////////////////////////////////////////////////////////
// Type: Calculator.NumericNode

///////////////////////////////////////
// .ctor

void Calculator_NumericNode__ctor(Calculator_NumericNode* this__, int32_t numeric, int32_t nextIndex)
{
    //-------------------
    // Local variables:


    //-------------------
    // Evaluation stacks:

    Calculator_NumericNode* stack0_0__ = NULL;
    int32_t stack1_0__;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        Calculator_NumericNode** pstack0_0__;
    } __executionFrame__;

    __executionFrame__.targetCount = 1;
    __executionFrame__.pstack0_0__ = &stack0_0__;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(41): */
    /* Path=1, Unique=0: IL_0000: ldarg.0 */
    stack0_0__ = this__;
    /* Path=1, Unique=0: IL_0001: ldarg.2 */
    stack1_0__ = nextIndex;
    /* Path=1, Unique=0: IL_0002: call System.Void Calculator.ReducibleNode::.ctor(System.Int32) */
    Calculator_ReducibleNode__ctor((Calculator_ReducibleNode*)stack0_0__, stack1_0__);
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(43): */
    /* Path=1, Unique=0: IL_0007: ldarg.0 */
    stack0_0__ = this__;
    /* Path=1, Unique=0: IL_0008: ldarg.1 */
    stack1_0__ = numeric;
    /* Path=1, Unique=0: IL_0009: stfld System.Int32 Calculator.NumericNode::Numeric */
    stack0_0__->Numeric = stack1_0__;
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(44): */
    /* Path=1, Unique=0: IL_000e: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return;
}

///////////////////////////////////////
// Virtual: Reduce

int32_t __Calculator_NumericNode_Reduce__(Calculator_NumericNode* this__)
{
    //-------------------
    // Local variables:


    //-------------------
    // Evaluation stacks:

    Calculator_NumericNode* stack0_0__ = NULL;
    int32_t stack0_1__;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        Calculator_NumericNode** pstack0_0__;
    } __executionFrame__;

    __executionFrame__.targetCount = 1;
    __executionFrame__.pstack0_0__ = &stack0_0__;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(48): */
    /* Path=1, Unique=0: IL_0000: ldarg.0 */
    stack0_0__ = this__;
    /* Path=1, Unique=0: IL_0001: ldfld System.Int32 Calculator.NumericNode::Numeric */
    stack0_1__ = stack0_0__->Numeric;
    /* Path=1, Unique=0: IL_0006: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return stack0_1__;
}

//////////////////////
// Runtime helpers:

// Runtime cast
void* __Calculator_NumericNode_IL2C_RuntimeCast__(Calculator_NumericNode* this__, IL2C_RUNTIME_TYPE_DECL* type)
{
    // This type
    if (type == il2c_typeof(Calculator_NumericNode)) return this__;

    // Delegate checking base types
    return __Calculator_ReducibleNode_IL2C_RuntimeCast__((Calculator_ReducibleNode*)this__, type);
}

// GC's mark handler
void __Calculator_NumericNode_IL2C_MarkHandler__(Calculator_NumericNode* this__)
{

    // Delegate checking base types
    __Calculator_ReducibleNode_IL2C_MarkHandler__((Calculator_ReducibleNode*)this__);
}

// Runtime type information
IL2C_RUNTIME_TYPE_DECL __Calculator_NumericNode_RUNTIME_TYPE__ = {
    "Calculator.NumericNode",
    sizeof(Calculator_NumericNode),
    /* internalcall */ (void*)__Calculator_NumericNode_IL2C_MarkHandler__,
};

//////////////////////
// VTables:

// Vtable of Calculator.NumericNode
__Calculator_NumericNode_VTABLE_DECL__ __Calculator_NumericNode_VTABLE__ = {
    (void*)__Calculator_NumericNode_IL2C_RuntimeCast__,
    (void*)__System_Object_ToString__,
    (void*)__System_Object_GetHashCode__,
    (void*)__System_Object_Finalize__,
    (void*)__System_Object_Equals__,
    (void*)__Calculator_NumericNode_Reduce__,
};

////////////////////////////////////////////////////////////
// Type: Calculator.ExpressionNode

///////////////////////////////////////
// .ctor

void Calculator_ExpressionNode__ctor(Calculator_ExpressionNode* this__, Calculator_OperatorNode* oper, Calculator_ReducibleNode* left, Calculator_ReducibleNode* right, int32_t nextIndex)
{
    //-------------------
    // Local variables:


    //-------------------
    // Evaluation stacks:

    Calculator_ExpressionNode* stack0_0__ = NULL;
    int32_t stack1_0__;
    Calculator_OperatorNode* stack1_1__ = NULL;
    Calculator_ReducibleNode* stack1_2__ = NULL;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        Calculator_ExpressionNode** pstack0_0__;
        Calculator_OperatorNode** pstack1_1__;
        Calculator_ReducibleNode** pstack1_2__;
    } __executionFrame__;

    __executionFrame__.targetCount = 3;
    __executionFrame__.pstack0_0__ = &stack0_0__;
    __executionFrame__.pstack1_1__ = &stack1_1__;
    __executionFrame__.pstack1_2__ = &stack1_2__;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(58): */
    /* Path=1, Unique=0: IL_0000: ldarg.0 */
    stack0_0__ = this__;
    /* Path=1, Unique=0: IL_0001: ldarg.s nextIndex */
    stack1_0__ = nextIndex;
    /* Path=1, Unique=0: IL_0003: call System.Void Calculator.ReducibleNode::.ctor(System.Int32) */
    Calculator_ReducibleNode__ctor((Calculator_ReducibleNode*)stack0_0__, stack1_0__);
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(60): */
    /* Path=1, Unique=0: IL_0008: ldarg.0 */
    stack0_0__ = this__;
    /* Path=1, Unique=0: IL_0009: ldarg.1 */
    stack1_1__ = oper;
    /* Path=1, Unique=0: IL_000a: stfld Calculator.OperatorNode Calculator.ExpressionNode::Operator */
    stack0_0__->Operator = stack1_1__;
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(61): */
    /* Path=1, Unique=0: IL_000f: ldarg.0 */
    stack0_0__ = this__;
    /* Path=1, Unique=0: IL_0010: ldarg.2 */
    stack1_2__ = left;
    /* Path=1, Unique=0: IL_0011: stfld Calculator.ReducibleNode Calculator.ExpressionNode::Left */
    stack0_0__->Left = stack1_2__;
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(62): */
    /* Path=1, Unique=0: IL_0016: ldarg.0 */
    stack0_0__ = this__;
    /* Path=1, Unique=0: IL_0017: ldarg.3 */
    stack1_2__ = right;
    /* Path=1, Unique=0: IL_0018: stfld Calculator.ReducibleNode Calculator.ExpressionNode::Right */
    stack0_0__->Right = stack1_2__;
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(63): */
    /* Path=1, Unique=0: IL_001d: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return;
}

///////////////////////////////////////
// Virtual: Reduce

int32_t __Calculator_ExpressionNode_Reduce__(Calculator_ExpressionNode* this__)
{
    //-------------------
    // Local variables:

    int32_t leftResult__;
    int32_t rightResult__;

    //-------------------
    // Evaluation stacks:

    Calculator_ExpressionNode* stack0_0__ = NULL;
    Calculator_ReducibleNode* stack0_1__ = NULL;
    int32_t stack0_2__;
    Calculator_OperatorNode* stack0_3__ = NULL;
    int32_t stack1_0__;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        Calculator_ExpressionNode** pstack0_0__;
        Calculator_ReducibleNode** pstack0_1__;
        Calculator_OperatorNode** pstack0_3__;
    } __executionFrame__;

    __executionFrame__.targetCount = 3;
    __executionFrame__.pstack0_0__ = &stack0_0__;
    __executionFrame__.pstack0_1__ = &stack0_1__;
    __executionFrame__.pstack0_3__ = &stack0_3__;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(67): */
    /* Path=1, Unique=0: IL_0000: ldarg.0 */
    stack0_0__ = this__;
    /* Path=1, Unique=0: IL_0001: ldfld Calculator.ReducibleNode Calculator.ExpressionNode::Left */
    stack0_1__ = stack0_0__->Left;
    /* Path=1, Unique=0: IL_0006: callvirt System.Int32 Calculator.ReducibleNode::Reduce() */
    stack0_2__ = Calculator_ReducibleNode_Reduce(stack0_1__);
    /* Path=1, Unique=0: IL_000b: stloc.0 */
    leftResult__ = stack0_2__;
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(68): */
    /* Path=1, Unique=0: IL_000c: ldarg.0 */
    stack0_0__ = this__;
    /* Path=1, Unique=0: IL_000d: ldfld Calculator.ReducibleNode Calculator.ExpressionNode::Right */
    stack0_1__ = stack0_0__->Right;
    /* Path=1, Unique=0: IL_0012: callvirt System.Int32 Calculator.ReducibleNode::Reduce() */
    stack0_2__ = Calculator_ReducibleNode_Reduce(stack0_1__);
    /* Path=1, Unique=0: IL_0017: stloc.1 */
    rightResult__ = stack0_2__;
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(69): */
    /* Path=1, Unique=0: IL_0018: ldarg.0 */
    stack0_0__ = this__;
    /* Path=1, Unique=0: IL_0019: ldfld Calculator.OperatorNode Calculator.ExpressionNode::Operator */
    stack0_3__ = stack0_0__->Operator;
    /* Path=1, Unique=0: IL_001e: ldfld System.Char Calculator.OperatorNode::Operator */
    stack0_2__ = (int32_t)(stack0_3__->Operator);
    /* Path=1, Unique=0: IL_0023: ldc.i4.s 43 */
    stack1_0__ = 43;
    /* Path=1, Unique=0: IL_0025: bne.un.s IL_002b */
    if (stack0_2__ != stack1_0__) goto IL_002b;
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(71): */
    /* Path=1, Unique=0: IL_0027: ldloc.0 */
    stack0_2__ = leftResult__;
    /* Path=1, Unique=0: IL_0028: ldloc.1 */
    stack1_0__ = rightResult__;
    /* Path=1, Unique=0: IL_0029: add */
    stack0_2__ = stack0_2__ + stack1_0__;
    /* Path=1, Unique=0: IL_002a: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return stack0_2__;
IL_002b:
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(73): */
    /* Path=2, Unique=0: IL_002b: ldarg.0 */
    stack0_0__ = this__;
    /* Path=2, Unique=0: IL_002c: ldfld Calculator.OperatorNode Calculator.ExpressionNode::Operator */
    stack0_3__ = stack0_0__->Operator;
    /* Path=2, Unique=0: IL_0031: ldfld System.Char Calculator.OperatorNode::Operator */
    stack0_2__ = (int32_t)(stack0_3__->Operator);
    /* Path=2, Unique=0: IL_0036: ldc.i4.s 45 */
    stack1_0__ = 45;
    /* Path=2, Unique=0: IL_0038: bne.un.s IL_003e */
    if (stack0_2__ != stack1_0__) goto IL_003e;
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(75): */
    /* Path=2, Unique=0: IL_003a: ldloc.0 */
    stack0_2__ = leftResult__;
    /* Path=2, Unique=0: IL_003b: ldloc.1 */
    stack1_0__ = rightResult__;
    /* Path=2, Unique=0: IL_003c: sub */
    stack0_2__ = stack0_2__ - stack1_0__;
    /* Path=2, Unique=0: IL_003d: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return stack0_2__;
IL_003e:
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(77): */
    /* Path=3, Unique=0: IL_003e: ldarg.0 */
    stack0_0__ = this__;
    /* Path=3, Unique=0: IL_003f: ldfld Calculator.OperatorNode Calculator.ExpressionNode::Operator */
    stack0_3__ = stack0_0__->Operator;
    /* Path=3, Unique=0: IL_0044: ldfld System.Char Calculator.OperatorNode::Operator */
    stack0_2__ = (int32_t)(stack0_3__->Operator);
    /* Path=3, Unique=0: IL_0049: ldc.i4.s 42 */
    stack1_0__ = 42;
    /* Path=3, Unique=0: IL_004b: bne.un.s IL_0051 */
    if (stack0_2__ != stack1_0__) goto IL_0051;
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(79): */
    /* Path=3, Unique=0: IL_004d: ldloc.0 */
    stack0_2__ = leftResult__;
    /* Path=3, Unique=0: IL_004e: ldloc.1 */
    stack1_0__ = rightResult__;
    /* Path=3, Unique=0: IL_004f: mul */
    stack0_2__ = stack0_2__ * stack1_0__;
    /* Path=3, Unique=0: IL_0050: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return stack0_2__;
IL_0051:
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(81): */
    /* Path=4, Unique=0: IL_0051: ldarg.0 */
    stack0_0__ = this__;
    /* Path=4, Unique=0: IL_0052: ldfld Calculator.OperatorNode Calculator.ExpressionNode::Operator */
    stack0_3__ = stack0_0__->Operator;
    /* Path=4, Unique=0: IL_0057: ldfld System.Char Calculator.OperatorNode::Operator */
    stack0_2__ = (int32_t)(stack0_3__->Operator);
    /* Path=4, Unique=0: IL_005c: ldc.i4.s 47 */
    stack1_0__ = 47;
    /* Path=4, Unique=0: IL_005e: bne.un.s IL_0064 */
    if (stack0_2__ != stack1_0__) goto IL_0064;
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(83): */
    /* Path=4, Unique=0: IL_0060: ldloc.0 */
    stack0_2__ = leftResult__;
    /* Path=4, Unique=0: IL_0061: ldloc.1 */
    stack1_0__ = rightResult__;
    /* Path=4, Unique=0: IL_0062: div */
    stack0_2__ = stack0_2__ / stack1_0__;
    /* Path=4, Unique=0: IL_0063: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return stack0_2__;
IL_0064:
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(87): */
    /* Path=5, Unique=0: IL_0064: ldc.i4.0 */
    stack0_2__ = 0;
    /* Path=5, Unique=0: IL_0065: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return stack0_2__;
}

//////////////////////
// Runtime helpers:

// Runtime cast
void* __Calculator_ExpressionNode_IL2C_RuntimeCast__(Calculator_ExpressionNode* this__, IL2C_RUNTIME_TYPE_DECL* type)
{
    // This type
    if (type == il2c_typeof(Calculator_ExpressionNode)) return this__;

    // Delegate checking base types
    return __Calculator_ReducibleNode_IL2C_RuntimeCast__((Calculator_ReducibleNode*)this__, type);
}

// GC's mark handler
void __Calculator_ExpressionNode_IL2C_MarkHandler__(Calculator_ExpressionNode* this__)
{
    // Try marking each object reference fields
    il2c_try_mark_from_handler(this__->Operator);
    il2c_try_mark_from_handler(this__->Left);
    il2c_try_mark_from_handler(this__->Right);

    // Delegate checking base types
    __Calculator_ReducibleNode_IL2C_MarkHandler__((Calculator_ReducibleNode*)this__);
}

// Runtime type information
IL2C_RUNTIME_TYPE_DECL __Calculator_ExpressionNode_RUNTIME_TYPE__ = {
    "Calculator.ExpressionNode",
    sizeof(Calculator_ExpressionNode),
    /* internalcall */ (void*)__Calculator_ExpressionNode_IL2C_MarkHandler__,
};

//////////////////////
// VTables:

// Vtable of Calculator.ExpressionNode
__Calculator_ExpressionNode_VTABLE_DECL__ __Calculator_ExpressionNode_VTABLE__ = {
    (void*)__Calculator_ExpressionNode_IL2C_RuntimeCast__,
    (void*)__System_Object_ToString__,
    (void*)__System_Object_GetHashCode__,
    (void*)__System_Object_Finalize__,
    (void*)__System_Object_Equals__,
    (void*)__Calculator_ExpressionNode_Reduce__,
};

////////////////////////////////////////////////////////////
// Type: Calculator.PolishNotation

///////////////////////////////////////
// SkipWhiteSpace

int32_t Calculator_PolishNotation_SkipWhiteSpace(System_String* line, int32_t startIndex)
{
    //-------------------
    // Local variables:

    int32_t index__;
    wchar_t ch__;

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

/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(95): */
    /* Path=1, Unique=0: IL_0000: ldarg.1 */
    stack0_0__ = startIndex;
    /* Path=1, Unique=0: IL_0001: stloc.0 */
    index__ = stack0_0__;
    /* Path=1, Unique=0: IL_0002: br.s IL_001a */
    goto IL_001a;
IL_0004:
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(98): */
    /* Path=3, Unique=0: IL_0004: ldarg.0 */
    stack0_1__ = line;
    /* Path=3, Unique=0: IL_0005: ldloc.0 */
    stack1_2__ = index__;
    /* Path=3, Unique=0: IL_0006: callvirt System.Char System.String::get_Chars(System.Int32) */
    stack0_2__ = System_String_get_Chars(stack0_1__, stack1_2__);
    /* Path=3, Unique=0: IL_000b: stloc.1 */
    ch__ = (wchar_t)stack0_2__;
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(99): */
    /* Path=3, Unique=0: IL_000c: ldloc.1 */
    stack0_0__ = ch__;
    /* Path=3, Unique=0: IL_000d: ldc.i4.s 32 */
    stack1_2__ = 32;
    /* Path=3, Unique=0: IL_000f: beq.s IL_0016 */
    if (stack0_0__ == stack1_2__) goto IL_0016;
    /* Path=3, Unique=0: IL_0011: ldloc.1 */
    stack0_0__ = ch__;
    /* Path=3, Unique=0: IL_0012: ldc.i4.s 9 */
    stack1_2__ = 9;
    /* Path=3, Unique=0: IL_0014: bne.un.s IL_0023 */
    if (stack0_0__ != stack1_2__) goto IL_0023;
IL_0016:
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(103): */
    /* Path=3, Unique=0: IL_0016: ldloc.0 */
    stack0_0__ = index__;
    /* Path=3, Unique=0: IL_0017: ldc.i4.1 */
    stack1_2__ = 1;
    /* Path=3, Unique=0: IL_0018: add */
    stack0_0__ = stack0_0__ + stack1_2__;
    /* Path=3, Unique=0: IL_0019: stloc.0 */
    index__ = stack0_0__;
IL_001a:
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(96): */
    /* Path=2, Unique=0: IL_001a: ldloc.0 */
    stack0_0__ = index__;
    /* Path=2, Unique=0: IL_001b: ldarg.0 */
    stack1_0__ = line;
    /* Path=2, Unique=0: IL_001c: callvirt System.Int32 System.String::get_Length() */
    stack1_1__ = System_String_get_Length(stack1_0__);
    /* Path=2, Unique=0: IL_0021: blt.s IL_0004 */
    if (stack0_0__ < stack1_1__) goto IL_0004;
IL_0023:
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(106): */
    /* Path=2, Unique=0: IL_0023: ldloc.0 */
    stack0_0__ = index__;
    /* Path=2, Unique=0: IL_0024: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return stack0_0__;
}

///////////////////////////////////////
// ParseOperator

Calculator_OperatorNode* Calculator_PolishNotation_ParseOperator(System_String* line, int32_t startIndex)
{
    //-------------------
    // Local variables:

    int32_t index__;
    wchar_t ch__;

    //-------------------
    // Evaluation stacks:

    int32_t stack0_0__;
    IL2C_CecilHelper_PseudoZeroType* stack0_1__ = NULL;
    System_String* stack0_2__ = NULL;
    int32_t stack0_3__;
    Calculator_OperatorNode* stack0_4__ = NULL;
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
        Calculator_OperatorNode** pstack0_4__;
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

/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(111): */
    /* Path=1, Unique=0: IL_0000: ldarg.1 */
    stack0_0__ = startIndex;
    /* Path=1, Unique=0: IL_0001: ldarg.0 */
    stack1_0__ = line;
    /* Path=1, Unique=0: IL_0002: callvirt System.Int32 System.String::get_Length() */
    stack1_1__ = System_String_get_Length(stack1_0__);
    /* Path=1, Unique=0: IL_0007: blt.s IL_000b */
    if (stack0_0__ < stack1_1__) goto IL_000b;
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(113): */
    /* Path=1, Unique=0: IL_0009: ldnull */
    stack0_1__ = NULL;
    /* Path=1, Unique=0: IL_000a: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return (Calculator_OperatorNode*)stack0_1__;
IL_000b:
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(116): */
    /* Path=2, Unique=0: IL_000b: ldarg.1 */
    stack0_0__ = startIndex;
    /* Path=2, Unique=0: IL_000c: stloc.0 */
    index__ = stack0_0__;
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(117): */
    /* Path=2, Unique=0: IL_000d: ldarg.0 */
    stack0_2__ = line;
    /* Path=2, Unique=0: IL_000e: ldloc.0 */
    stack1_2__ = index__;
    /* Path=2, Unique=0: IL_000f: callvirt System.Char System.String::get_Chars(System.Int32) */
    stack0_3__ = System_String_get_Chars(stack0_2__, stack1_2__);
    /* Path=2, Unique=0: IL_0014: stloc.1 */
    ch__ = (wchar_t)stack0_3__;
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(118): */
    /* Path=2, Unique=0: IL_0015: ldloc.1 */
    stack0_0__ = ch__;
    /* Path=2, Unique=0: IL_0016: ldc.i4.s 43 */
    stack1_2__ = 43;
    /* Path=2, Unique=0: IL_0018: beq.s IL_002b */
    if (stack0_0__ == stack1_2__) goto IL_002b;
    /* Path=2, Unique=0: IL_001a: ldloc.1 */
    stack0_0__ = ch__;
    /* Path=2, Unique=0: IL_001b: ldc.i4.s 45 */
    stack1_2__ = 45;
    /* Path=2, Unique=0: IL_001d: beq.s IL_002b */
    if (stack0_0__ == stack1_2__) goto IL_002b;
    /* Path=2, Unique=0: IL_001f: ldloc.1 */
    stack0_0__ = ch__;
    /* Path=2, Unique=0: IL_0020: ldc.i4.s 42 */
    stack1_2__ = 42;
    /* Path=2, Unique=0: IL_0022: beq.s IL_002b */
    if (stack0_0__ == stack1_2__) goto IL_002b;
    /* Path=2, Unique=0: IL_0024: ldloc.1 */
    stack0_0__ = ch__;
    /* Path=2, Unique=0: IL_0025: ldc.i4.s 47 */
    stack1_2__ = 47;
    /* Path=2, Unique=0: IL_0027: beq.s IL_002b */
    if (stack0_0__ == stack1_2__) goto IL_002b;
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(120): */
    /* Path=2, Unique=0: IL_0029: ldnull */
    stack0_1__ = NULL;
    /* Path=2, Unique=0: IL_002a: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return (Calculator_OperatorNode*)stack0_1__;
IL_002b:
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(122): */
    /* Path=3, Unique=0: IL_002b: ldloc.0 */
    stack0_0__ = index__;
    /* Path=3, Unique=0: IL_002c: ldc.i4.1 */
    stack1_2__ = 1;
    /* Path=3, Unique=0: IL_002d: add */
    stack0_0__ = stack0_0__ + stack1_2__;
    /* Path=3, Unique=0: IL_002e: stloc.0 */
    index__ = stack0_0__;
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(124): */
    /* Path=3, Unique=0: IL_002f: ldarg.0 */
    stack0_2__ = line;
    /* Path=3, Unique=0: IL_0030: ldloc.0 */
    stack1_2__ = index__;
    /* Path=3, Unique=0: IL_0031: call System.Int32 Calculator.PolishNotation::SkipWhiteSpace(System.String,System.Int32) */
    stack0_0__ = Calculator_PolishNotation_SkipWhiteSpace(stack0_2__, stack1_2__);
    /* Path=3, Unique=0: IL_0036: stloc.0 */
    index__ = stack0_0__;
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(125): */
    /* Path=3, Unique=0: IL_0037: ldloc.1 */
    stack0_0__ = ch__;
    /* Path=3, Unique=0: IL_0038: ldloc.0 */
    stack1_2__ = index__;
    /* Path=3, Unique=0: IL_0039: newobj System.Void Calculator.OperatorNode::.ctor(System.Char,System.Int32) */
    stack0_4__ = il2c_get_uninitialized_object(il2c_typeof(Calculator_OperatorNode));
    stack0_4__->vptr0__ = &__Calculator_OperatorNode_VTABLE__;
    Calculator_OperatorNode__ctor(stack0_4__, (wchar_t)stack0_0__, stack1_2__);
    /* Path=3, Unique=0: IL_003e: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return stack0_4__;
}

///////////////////////////////////////
// ParseNumeric

Calculator_NumericNode* Calculator_PolishNotation_ParseNumeric(System_String* line, int32_t startIndex)
{
    //-------------------
    // Local variables:

    int32_t index__;
    int32_t numeric__;

    //-------------------
    // Evaluation stacks:

    int32_t stack0_0__;
    IL2C_CecilHelper_PseudoZeroType* stack0_1__ = NULL;
    System_String* stack0_2__ = NULL;
    int32_t stack0_3__;
    System_String* stack0_4__ = NULL;
    Calculator_NumericNode* stack0_5__ = NULL;
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
        Calculator_NumericNode** pstack0_5__;
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

/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(130): */
    /* Path=1, Unique=0: IL_0000: ldarg.1 */
    stack0_0__ = startIndex;
    /* Path=1, Unique=0: IL_0001: ldarg.0 */
    stack1_0__ = line;
    /* Path=1, Unique=0: IL_0002: callvirt System.Int32 System.String::get_Length() */
    stack1_1__ = System_String_get_Length(stack1_0__);
    /* Path=1, Unique=0: IL_0007: blt.s IL_000b */
    if (stack0_0__ < stack1_1__) goto IL_000b;
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(132): */
    /* Path=1, Unique=0: IL_0009: ldnull */
    stack0_1__ = NULL;
    /* Path=1, Unique=0: IL_000a: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return (Calculator_NumericNode*)stack0_1__;
IL_000b:
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(135): */
    /* Path=2, Unique=0: IL_000b: ldarg.1 */
    stack0_0__ = startIndex;
    /* Path=2, Unique=0: IL_000c: stloc.0 */
    index__ = stack0_0__;
    /* Path=2, Unique=0: IL_000d: br.s IL_001e */
    goto IL_001e;
IL_000f:
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(138): */
    /* Path=4, Unique=0: IL_000f: ldarg.0 */
    stack0_2__ = line;
    /* Path=4, Unique=0: IL_0010: ldloc.0 */
    stack1_2__ = index__;
    /* Path=4, Unique=0: IL_0011: callvirt System.Char System.String::get_Chars(System.Int32) */
    stack0_3__ = System_String_get_Chars(stack0_2__, stack1_2__);
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(139): */
    /* Path=4, Unique=0: IL_0016: ldc.i4.s 32 */
    stack1_2__ = 32;
    /* Path=4, Unique=0: IL_0018: beq.s IL_0027 */
    if (stack0_3__ == stack1_2__) goto IL_0027;
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(143): */
    /* Path=4, Unique=0: IL_001a: ldloc.0 */
    stack0_0__ = index__;
    /* Path=4, Unique=0: IL_001b: ldc.i4.1 */
    stack1_2__ = 1;
    /* Path=4, Unique=0: IL_001c: add */
    stack0_0__ = stack0_0__ + stack1_2__;
    /* Path=4, Unique=0: IL_001d: stloc.0 */
    index__ = stack0_0__;
IL_001e:
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(136): */
    /* Path=3, Unique=0: IL_001e: ldloc.0 */
    stack0_0__ = index__;
    /* Path=3, Unique=0: IL_001f: ldarg.0 */
    stack1_0__ = line;
    /* Path=3, Unique=0: IL_0020: callvirt System.Int32 System.String::get_Length() */
    stack1_1__ = System_String_get_Length(stack1_0__);
    /* Path=3, Unique=0: IL_0025: blt.s IL_000f */
    if (stack0_0__ < stack1_1__) goto IL_000f;
IL_0027:
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(146): */
    /* Path=3, Unique=0: IL_0027: ldloc.0 */
    stack0_0__ = index__;
    /* Path=3, Unique=0: IL_0028: ldarg.1 */
    stack1_2__ = startIndex;
    /* Path=3, Unique=0: IL_0029: bne.un.s IL_002d */
    if (stack0_0__ != stack1_2__) goto IL_002d;
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(148): */
    /* Path=3, Unique=0: IL_002b: ldnull */
    stack0_1__ = NULL;
    /* Path=3, Unique=0: IL_002c: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return (Calculator_NumericNode*)stack0_1__;
IL_002d:
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(151): */
    /* Path=5, Unique=0: IL_002d: ldarg.0 */
    stack0_2__ = line;
    /* Path=5, Unique=0: IL_002e: ldarg.1 */
    stack1_2__ = startIndex;
    /* Path=5, Unique=0: IL_002f: ldloc.0 */
    stack2_0__ = index__;
    /* Path=5, Unique=0: IL_0030: ldarg.1 */
    stack3_0__ = startIndex;
    /* Path=5, Unique=0: IL_0031: sub */
    stack2_0__ = stack2_0__ - stack3_0__;
    /* Path=5, Unique=0: IL_0032: callvirt System.String System.String::Substring(System.Int32,System.Int32) */
    stack0_4__ = System_String_Substring_1(stack0_2__, stack1_2__, stack2_0__);
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(152): */
    /* Path=5, Unique=0: IL_0037: ldloca.s local1 */
    stack1_3__ = &numeric__;
    /* Path=5, Unique=0: IL_0039: call System.Boolean System.Int32::TryParse(System.String,System.Int32&) */
    stack0_0__ = System_Int32_TryParse(stack0_4__, stack1_3__);
    /* Path=5, Unique=0: IL_003e: brtrue.s IL_0042 */
    if (stack0_0__ != 0) goto IL_0042;
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(154): */
    /* Path=5, Unique=0: IL_0040: ldnull */
    stack0_1__ = NULL;
    /* Path=5, Unique=0: IL_0041: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return (Calculator_NumericNode*)stack0_1__;
IL_0042:
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(157): */
    /* Path=6, Unique=0: IL_0042: ldarg.0 */
    stack0_2__ = line;
    /* Path=6, Unique=0: IL_0043: ldloc.0 */
    stack1_2__ = index__;
    /* Path=6, Unique=0: IL_0044: call System.Int32 Calculator.PolishNotation::SkipWhiteSpace(System.String,System.Int32) */
    stack0_0__ = Calculator_PolishNotation_SkipWhiteSpace(stack0_2__, stack1_2__);
    /* Path=6, Unique=0: IL_0049: stloc.0 */
    index__ = stack0_0__;
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(158): */
    /* Path=6, Unique=0: IL_004a: ldloc.1 */
    stack0_0__ = numeric__;
    /* Path=6, Unique=0: IL_004b: ldloc.0 */
    stack1_2__ = index__;
    /* Path=6, Unique=0: IL_004c: newobj System.Void Calculator.NumericNode::.ctor(System.Int32,System.Int32) */
    stack0_5__ = il2c_get_uninitialized_object(il2c_typeof(Calculator_NumericNode));
    stack0_5__->vptr0__ = &__Calculator_NumericNode_VTABLE__;
    Calculator_NumericNode__ctor(stack0_5__, stack0_0__, stack1_2__);
    /* Path=6, Unique=0: IL_0051: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return stack0_5__;
}

///////////////////////////////////////
// ParseExpression

Calculator_ExpressionNode* Calculator_PolishNotation_ParseExpression(System_String* line, int32_t startIndex)
{
    //-------------------
    // Local variables:

    Calculator_OperatorNode* oper__ = NULL;
    Calculator_ReducibleNode* left__ = NULL;
    Calculator_ReducibleNode* right__ = NULL;
    int32_t index__;

    //-------------------
    // Evaluation stacks:

    int32_t stack0_0__;
    IL2C_CecilHelper_PseudoZeroType* stack0_1__ = NULL;
    System_String* stack0_2__ = NULL;
    Calculator_OperatorNode* stack0_3__ = NULL;
    Calculator_NumericNode* stack0_4__ = NULL;
    Calculator_ReducibleNode* stack0_5__ = NULL;
    Calculator_ExpressionNode* stack0_6__ = NULL;
    System_String* stack1_0__ = NULL;
    int32_t stack1_1__;
    int32_t stack1_2__;
    Calculator_OperatorNode* stack1_3__ = NULL;
    Calculator_ReducibleNode* stack1_4__ = NULL;
    Calculator_ReducibleNode* stack2_0__ = NULL;
    int32_t stack3_0__;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        Calculator_OperatorNode** poper__;
        Calculator_ReducibleNode** pleft__;
        Calculator_ReducibleNode** pright__;
        IL2C_CecilHelper_PseudoZeroType** pstack0_1__;
        System_String** pstack0_2__;
        Calculator_OperatorNode** pstack0_3__;
        Calculator_NumericNode** pstack0_4__;
        Calculator_ReducibleNode** pstack0_5__;
        Calculator_ExpressionNode** pstack0_6__;
        System_String** pstack1_0__;
        Calculator_OperatorNode** pstack1_3__;
        Calculator_ReducibleNode** pstack1_4__;
        Calculator_ReducibleNode** pstack2_0__;
    } __executionFrame__;

    __executionFrame__.targetCount = 13;
    __executionFrame__.poper__ = &oper__;
    __executionFrame__.pleft__ = &left__;
    __executionFrame__.pright__ = &right__;
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

/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(163): */
    /* Path=1, Unique=0: IL_0000: ldarg.1 */
    stack0_0__ = startIndex;
    /* Path=1, Unique=0: IL_0001: ldarg.0 */
    stack1_0__ = line;
    /* Path=1, Unique=0: IL_0002: callvirt System.Int32 System.String::get_Length() */
    stack1_1__ = System_String_get_Length(stack1_0__);
    /* Path=1, Unique=0: IL_0007: blt.s IL_000b */
    if (stack0_0__ < stack1_1__) goto IL_000b;
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(165): */
    /* Path=1, Unique=0: IL_0009: ldnull */
    stack0_1__ = NULL;
    /* Path=1, Unique=0: IL_000a: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return (Calculator_ExpressionNode*)stack0_1__;
IL_000b:
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(168): */
    /* Path=2, Unique=0: IL_000b: ldarg.0 */
    stack0_2__ = line;
    /* Path=2, Unique=0: IL_000c: ldarg.1 */
    stack1_2__ = startIndex;
    /* Path=2, Unique=0: IL_000d: call Calculator.OperatorNode Calculator.PolishNotation::ParseOperator(System.String,System.Int32) */
    stack0_3__ = Calculator_PolishNotation_ParseOperator(stack0_2__, stack1_2__);
    /* Path=2, Unique=0: IL_0012: stloc.0 */
    oper__ = stack0_3__;
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(169): */
    /* Path=2, Unique=0: IL_0013: ldloc.0 */
    stack0_3__ = oper__;
    /* Path=2, Unique=0: IL_0014: brtrue.s IL_0018 */
    if (stack0_3__ != NULL) goto IL_0018;
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(171): */
    /* Path=2, Unique=0: IL_0016: ldnull */
    stack0_1__ = NULL;
    /* Path=2, Unique=0: IL_0017: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return (Calculator_ExpressionNode*)stack0_1__;
IL_0018:
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(174): */
    /* Path=3, Unique=0: IL_0018: ldarg.0 */
    stack0_2__ = line;
    /* Path=3, Unique=0: IL_0019: ldloc.0 */
    stack1_3__ = oper__;
    /* Path=3, Unique=0: IL_001a: ldfld System.Int32 Calculator.AbstractNode::NextIndex */
    stack1_2__ = stack1_3__->NextIndex;
    /* Path=3, Unique=0: IL_001f: call Calculator.NumericNode Calculator.PolishNotation::ParseNumeric(System.String,System.Int32) */
    stack0_4__ = Calculator_PolishNotation_ParseNumeric(stack0_2__, stack1_2__);
    /* Path=3, Unique=0: IL_0024: stloc.1 */
    left__ = (Calculator_ReducibleNode*)stack0_4__;
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(175): */
    /* Path=3, Unique=0: IL_0025: ldloc.1 */
    stack0_5__ = left__;
    /* Path=3, Unique=0: IL_0026: brtrue.s IL_003a */
    if (stack0_5__ != NULL) goto IL_003a;
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(177): */
    /* Path=3, Unique=0: IL_0028: ldarg.0 */
    stack0_2__ = line;
    /* Path=3, Unique=0: IL_0029: ldloc.0 */
    stack1_3__ = oper__;
    /* Path=3, Unique=0: IL_002a: ldfld System.Int32 Calculator.AbstractNode::NextIndex */
    stack1_2__ = stack1_3__->NextIndex;
    /* Path=3, Unique=0: IL_002f: call Calculator.ExpressionNode Calculator.PolishNotation::ParseExpression(System.String,System.Int32) */
    stack0_6__ = Calculator_PolishNotation_ParseExpression(stack0_2__, stack1_2__);
    /* Path=3, Unique=0: IL_0034: stloc.1 */
    left__ = (Calculator_ReducibleNode*)stack0_6__;
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(178): */
    /* Path=3, Unique=0: IL_0035: ldloc.1 */
    stack0_5__ = left__;
    /* Path=3, Unique=0: IL_0036: brtrue.s IL_003a */
    if (stack0_5__ != NULL) goto IL_003a;
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(180): */
    /* Path=3, Unique=0: IL_0038: ldnull */
    stack0_1__ = NULL;
    /* Path=3, Unique=0: IL_0039: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return (Calculator_ExpressionNode*)stack0_1__;
IL_003a:
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(184): */
    /* Path=4, Unique=0: IL_003a: ldarg.0 */
    stack0_2__ = line;
    /* Path=4, Unique=0: IL_003b: ldloc.1 */
    stack1_4__ = left__;
    /* Path=4, Unique=0: IL_003c: ldfld System.Int32 Calculator.AbstractNode::NextIndex */
    stack1_2__ = stack1_4__->NextIndex;
    /* Path=4, Unique=0: IL_0041: call Calculator.NumericNode Calculator.PolishNotation::ParseNumeric(System.String,System.Int32) */
    stack0_4__ = Calculator_PolishNotation_ParseNumeric(stack0_2__, stack1_2__);
    /* Path=4, Unique=0: IL_0046: stloc.2 */
    right__ = (Calculator_ReducibleNode*)stack0_4__;
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(185): */
    /* Path=4, Unique=0: IL_0047: ldloc.2 */
    stack0_5__ = right__;
    /* Path=4, Unique=0: IL_0048: brtrue.s IL_005c */
    if (stack0_5__ != NULL) goto IL_005c;
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(187): */
    /* Path=4, Unique=0: IL_004a: ldarg.0 */
    stack0_2__ = line;
    /* Path=4, Unique=0: IL_004b: ldloc.1 */
    stack1_4__ = left__;
    /* Path=4, Unique=0: IL_004c: ldfld System.Int32 Calculator.AbstractNode::NextIndex */
    stack1_2__ = stack1_4__->NextIndex;
    /* Path=4, Unique=0: IL_0051: call Calculator.ExpressionNode Calculator.PolishNotation::ParseExpression(System.String,System.Int32) */
    stack0_6__ = Calculator_PolishNotation_ParseExpression(stack0_2__, stack1_2__);
    /* Path=4, Unique=0: IL_0056: stloc.2 */
    right__ = (Calculator_ReducibleNode*)stack0_6__;
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(188): */
    /* Path=4, Unique=0: IL_0057: ldloc.2 */
    stack0_5__ = right__;
    /* Path=4, Unique=0: IL_0058: brtrue.s IL_005c */
    if (stack0_5__ != NULL) goto IL_005c;
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(190): */
    /* Path=4, Unique=0: IL_005a: ldnull */
    stack0_1__ = NULL;
    /* Path=4, Unique=0: IL_005b: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return (Calculator_ExpressionNode*)stack0_1__;
IL_005c:
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(194): */
    /* Path=5, Unique=0: IL_005c: ldarg.0 */
    stack0_2__ = line;
    /* Path=5, Unique=0: IL_005d: ldloc.2 */
    stack1_4__ = right__;
    /* Path=5, Unique=0: IL_005e: ldfld System.Int32 Calculator.AbstractNode::NextIndex */
    stack1_2__ = stack1_4__->NextIndex;
    /* Path=5, Unique=0: IL_0063: call System.Int32 Calculator.PolishNotation::SkipWhiteSpace(System.String,System.Int32) */
    stack0_0__ = Calculator_PolishNotation_SkipWhiteSpace(stack0_2__, stack1_2__);
    /* Path=5, Unique=0: IL_0068: stloc.3 */
    index__ = stack0_0__;
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(195): */
    /* Path=5, Unique=0: IL_0069: ldloc.0 */
    stack0_3__ = oper__;
    /* Path=5, Unique=0: IL_006a: ldloc.1 */
    stack1_4__ = left__;
    /* Path=5, Unique=0: IL_006b: ldloc.2 */
    stack2_0__ = right__;
    /* Path=5, Unique=0: IL_006c: ldloc.3 */
    stack3_0__ = index__;
    /* Path=5, Unique=0: IL_006d: newobj System.Void Calculator.ExpressionNode::.ctor(Calculator.OperatorNode,Calculator.ReducibleNode,Calculator.ReducibleNode,System.Int32) */
    stack0_6__ = il2c_get_uninitialized_object(il2c_typeof(Calculator_ExpressionNode));
    stack0_6__->vptr0__ = &__Calculator_ExpressionNode_VTABLE__;
    Calculator_ExpressionNode__ctor(stack0_6__, stack0_3__, stack1_4__, stack2_0__, stack3_0__);
    /* Path=5, Unique=0: IL_0072: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return stack0_6__;
}

///////////////////////////////////////
// Main

void Calculator_PolishNotation_Main(void)
{
    //-------------------
    // Local variables:

    System_String* line__ = NULL;
    Calculator_ExpressionNode* expr__ = NULL;

    //-------------------
    // Evaluation stacks:

    System_String* stack0_0__ = NULL;
    int32_t stack0_1__;
    Calculator_ExpressionNode* stack0_2__ = NULL;
    System_String* stack1_0__ = NULL;
    int32_t stack1_1__;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        System_String** pline__;
        Calculator_ExpressionNode** pexpr__;
        System_String** pstack0_0__;
        Calculator_ExpressionNode** pstack0_2__;
        System_String** pstack1_0__;
    } __executionFrame__;

    __executionFrame__.targetCount = 5;
    __executionFrame__.pline__ = &line__;
    __executionFrame__.pexpr__ = &expr__;
    __executionFrame__.pstack0_0__ = &stack0_0__;
    __executionFrame__.pstack0_2__ = &stack0_2__;
    __executionFrame__.pstack1_0__ = &stack1_0__;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

IL_0000:
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(202): */
    /* Path=1, Unique=0: IL_0000: call System.Void System.Console::WriteLine() */
    System_Console_WriteLine();
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(203): */
    /* Path=1, Unique=0: IL_0005: ldstr "PN> " */
    stack0_0__ = string0__;
    /* Path=1, Unique=0: IL_000a: call System.Void System.Console::Write(System.String) */
    System_Console_Write_9(stack0_0__);
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(204): */
    /* Path=1, Unique=0: IL_000f: call System.String System.Console::ReadLine() */
    stack0_0__ = System_Console_ReadLine();
    /* Path=1, Unique=0: IL_0014: stloc.0 */
    line__ = stack0_0__;
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(205): */
    /* Path=1, Unique=0: IL_0015: ldloc.0 */
    stack0_0__ = line__;
    /* Path=1, Unique=0: IL_0016: call System.Boolean System.String::IsNullOrWhiteSpace(System.String) */
    stack0_1__ = System_String_IsNullOrWhiteSpace(stack0_0__);
    /* Path=1, Unique=0: IL_001b: brtrue.s IL_0000 */
    if (stack0_1__ != 0) goto IL_0000;
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(207): */
    /* Path=1, Unique=0: IL_001d: ldloc.0 */
    stack0_0__ = line__;
    /* Path=1, Unique=0: IL_001e: ldstr "exit" */
    stack1_0__ = string1__;
    /* Path=1, Unique=0: IL_0023: call System.Boolean System.String::op_Equality(System.String,System.String) */
    stack0_1__ = System_String_op_Equality(stack0_0__, stack1_0__);
    /* Path=1, Unique=0: IL_0028: brfalse.s IL_002b */
    if (stack0_1__ == 0) goto IL_002b;
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(209): */
    /* Path=1, Unique=0: IL_002a: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return;
IL_002b:
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(212): */
    /* Path=2, Unique=0: IL_002b: ldloc.0 */
    stack0_0__ = line__;
    /* Path=2, Unique=0: IL_002c: ldc.i4.0 */
    stack1_1__ = 0;
    /* Path=2, Unique=0: IL_002d: call Calculator.ExpressionNode Calculator.PolishNotation::ParseExpression(System.String,System.Int32) */
    stack0_2__ = Calculator_PolishNotation_ParseExpression(stack0_0__, stack1_1__);
    /* Path=2, Unique=0: IL_0032: stloc.1 */
    expr__ = stack0_2__;
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(213): */
    /* Path=2, Unique=0: IL_0033: ldloc.1 */
    stack0_2__ = expr__;
    /* Path=2, Unique=0: IL_0034: brtrue.s IL_0042 */
    if (stack0_2__ != NULL) goto IL_0042;
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(215): */
    /* Path=2, Unique=0: IL_0036: ldstr "Syntax error." */
    stack0_0__ = string2__;
    /* Path=2, Unique=0: IL_003b: call System.Void System.Console::WriteLine(System.String) */
    System_Console_WriteLine_10(stack0_0__);
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(216): */
    /* Path=2, Unique=0: IL_0040: br.s IL_0000 */
    goto IL_0000;
IL_0042:
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(219): */
    /* Path=3, Unique=0: IL_0042: ldloc.1 */
    stack0_2__ = expr__;
    /* Path=3, Unique=0: IL_0043: callvirt System.Int32 Calculator.ReducibleNode::Reduce() */
    stack0_1__ = Calculator_ReducibleNode_Reduce((Calculator_ReducibleNode*)stack0_2__);
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(221): */
    /* Path=3, Unique=0: IL_0048: ldstr "Reuslt=" */
    stack1_0__ = string3__;
    /* Path=3, Unique=0: IL_004d: call System.Void System.Console::Write(System.String) */
    System_Console_Write_9(stack1_0__);
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(222): */
    /* Path=3, Unique=0: IL_0052: call System.Void System.Console::WriteLine(System.Int32) */
    System_Console_WriteLine_6(stack0_1__);
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(200): */
    /* Path=3, Unique=0: IL_0057: br.s IL_0000 */
    goto IL_0000;
}

///////////////////////////////////////
// .ctor

void Calculator_PolishNotation__ctor(Calculator_PolishNotation* this__)
{
    //-------------------
    // Local variables:


    //-------------------
    // Evaluation stacks:

    Calculator_PolishNotation* stack0_0__ = NULL;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        Calculator_PolishNotation** pstack0_0__;
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
void* __Calculator_PolishNotation_IL2C_RuntimeCast__(Calculator_PolishNotation* this__, IL2C_RUNTIME_TYPE_DECL* type)
{
    // This type
    if (type == il2c_typeof(Calculator_PolishNotation)) return this__;

    // Delegate checking base types
    return __System_Object_IL2C_RuntimeCast__((System_Object*)this__, type);
}

// GC's mark handler
void __Calculator_PolishNotation_IL2C_MarkHandler__(Calculator_PolishNotation* this__)
{

    /* Suppressed invoke base mark handler */
}

// Runtime type information
IL2C_RUNTIME_TYPE_DECL __Calculator_PolishNotation_RUNTIME_TYPE__ = {
    "Calculator.PolishNotation",
    sizeof(Calculator_PolishNotation),
    /* internalcall */ (void*)__Calculator_PolishNotation_IL2C_MarkHandler__,
};

//////////////////////
// VTables:

// Vtable of Calculator.PolishNotation
__Calculator_PolishNotation_VTABLE_DECL__ __Calculator_PolishNotation_VTABLE__ = {
    (void*)__Calculator_PolishNotation_IL2C_RuntimeCast__,
    (void*)__System_Object_ToString__,
    (void*)__System_Object_GetHashCode__,
    (void*)__System_Object_Finalize__,
    (void*)__System_Object_Equals__,
};
