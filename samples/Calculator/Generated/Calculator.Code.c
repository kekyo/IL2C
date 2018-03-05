#include "Calculator.Code.h"

//////////////////////////////////////////////////////////////////////////////////
// Const strings:

IL2C_CONST_STRING(string0__, L"Polish notation calculator.");
IL2C_CONST_STRING(string1__, L"This is proof of concept for IL2C.");
IL2C_CONST_STRING(string2__, L"https://github.com/kekyo/IL2C");
IL2C_CONST_STRING(string3__, L"Type \"exit\" to exit.");
IL2C_CONST_STRING(string4__, L"PN> ");
IL2C_CONST_STRING(string5__, L"exit");
IL2C_CONST_STRING(string6__, L"Syntax error.");
IL2C_CONST_STRING(string7__, L"Reuslt=");

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
    /* Path=1, Unique=0: IL_0006: nop */
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(13): */
    /* Path=1, Unique=0: IL_0007: nop */
    /* Path=1, Unique=0: IL_0008: ldarg.0 */
    stack0_0__ = this__;
    /* Path=1, Unique=0: IL_0009: ldarg.1 */
    stack1_0__ = nextIndex;
    /* Path=1, Unique=0: IL_000a: stfld System.Int32 Calculator.AbstractNode::NextIndex */
    stack0_0__->NextIndex = stack1_0__;
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(15): */
    /* Path=1, Unique=0: IL_000f: ret */
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
    /* internalcall */ (IL2C_MARK_HANDLER)__Calculator_AbstractNode_IL2C_MarkHandler__,
};

//////////////////////
// VTables:

// Vtable of Calculator.AbstractNode
__Calculator_AbstractNode_VTABLE_DECL__ __Calculator_AbstractNode_VTABLE__ = {
    (void* (*)(Calculator_AbstractNode*, IL2C_RUNTIME_TYPE_DECL*))__Calculator_AbstractNode_IL2C_RuntimeCast__,
    (System_String* (*)(Calculator_AbstractNode*))__System_Object_ToString__,
    (int32_t (*)(Calculator_AbstractNode*))__System_Object_GetHashCode__,
    (void (*)(Calculator_AbstractNode*))__System_Object_Finalize__,
    (bool (*)(Calculator_AbstractNode*, System_Object*))__System_Object_Equals__,
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
    /* Path=1, Unique=0: IL_0007: nop */
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(23): */
    /* Path=1, Unique=0: IL_0008: nop */
    /* Path=1, Unique=0: IL_0009: ldarg.0 */
    stack0_0__ = this__;
    /* Path=1, Unique=0: IL_000a: ldarg.1 */
    stack1_0__ = (int32_t)(oper);
    /* Path=1, Unique=0: IL_000b: stfld System.Char Calculator.OperatorNode::Operator */
    stack0_0__->Operator = (wchar_t)stack1_0__;
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(25): */
    /* Path=1, Unique=0: IL_0010: ret */
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
    /* internalcall */ (IL2C_MARK_HANDLER)__Calculator_OperatorNode_IL2C_MarkHandler__,
};

//////////////////////
// VTables:

// Vtable of Calculator.OperatorNode
__Calculator_OperatorNode_VTABLE_DECL__ __Calculator_OperatorNode_VTABLE__ = {
    (void* (*)(Calculator_OperatorNode*, IL2C_RUNTIME_TYPE_DECL*))__Calculator_OperatorNode_IL2C_RuntimeCast__,
    (System_String* (*)(Calculator_OperatorNode*))__System_Object_ToString__,
    (int32_t (*)(Calculator_OperatorNode*))__System_Object_GetHashCode__,
    (void (*)(Calculator_OperatorNode*))__System_Object_Finalize__,
    (bool (*)(Calculator_OperatorNode*, System_Object*))__System_Object_Equals__,
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
    /* Path=1, Unique=0: IL_0007: nop */
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(31): */
    /* Path=1, Unique=0: IL_0008: nop */
    /* Path=1, Unique=0: IL_0009: ret */
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
    /* internalcall */ (IL2C_MARK_HANDLER)__Calculator_ReducibleNode_IL2C_MarkHandler__,
};

//////////////////////
// VTables:

// Vtable of Calculator.ReducibleNode
__Calculator_ReducibleNode_VTABLE_DECL__ __Calculator_ReducibleNode_VTABLE__ = {
    (void* (*)(Calculator_ReducibleNode*, IL2C_RUNTIME_TYPE_DECL*))__Calculator_ReducibleNode_IL2C_RuntimeCast__,
    (System_String* (*)(Calculator_ReducibleNode*))__System_Object_ToString__,
    (int32_t (*)(Calculator_ReducibleNode*))__System_Object_GetHashCode__,
    (void (*)(Calculator_ReducibleNode*))__System_Object_Finalize__,
    (bool (*)(Calculator_ReducibleNode*, System_Object*))__System_Object_Equals__,
    (int32_t (*)(Calculator_ReducibleNode*))__Calculator_ReducibleNode_Reduce__,
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
    /* Path=1, Unique=0: IL_0007: nop */
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(42): */
    /* Path=1, Unique=0: IL_0008: nop */
    /* Path=1, Unique=0: IL_0009: ldarg.0 */
    stack0_0__ = this__;
    /* Path=1, Unique=0: IL_000a: ldarg.1 */
    stack1_0__ = numeric;
    /* Path=1, Unique=0: IL_000b: stfld System.Int32 Calculator.NumericNode::Numeric */
    stack0_0__->Numeric = stack1_0__;
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(44): */
    /* Path=1, Unique=0: IL_0010: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return;
}

///////////////////////////////////////
// Virtual: Reduce

int32_t __Calculator_NumericNode_Reduce__(Calculator_NumericNode* this__)
{
    //-------------------
    // Local variables:

    int32_t local;

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

/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(47): */
    /* Path=1, Unique=0: IL_0000: nop */
    /* Path=1, Unique=0: IL_0001: ldarg.0 */
    stack0_0__ = this__;
    /* Path=1, Unique=0: IL_0002: ldfld System.Int32 Calculator.NumericNode::Numeric */
    stack0_1__ = stack0_0__->Numeric;
    /* Path=1, Unique=0: IL_0007: stloc.0 */
    local = stack0_1__;
    /* Path=1, Unique=0: IL_0008: br.s IL_000a */
    goto IL_000a;
IL_000a:
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(49): */
    /* Path=2, Unique=0: IL_000a: ldloc.0 */
    stack0_1__ = local;
    /* Path=2, Unique=0: IL_000b: ret */
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
    /* internalcall */ (IL2C_MARK_HANDLER)__Calculator_NumericNode_IL2C_MarkHandler__,
};

//////////////////////
// VTables:

// Vtable of Calculator.NumericNode
__Calculator_NumericNode_VTABLE_DECL__ __Calculator_NumericNode_VTABLE__ = {
    (void* (*)(Calculator_NumericNode*, IL2C_RUNTIME_TYPE_DECL*))__Calculator_NumericNode_IL2C_RuntimeCast__,
    (System_String* (*)(Calculator_NumericNode*))__System_Object_ToString__,
    (int32_t (*)(Calculator_NumericNode*))__System_Object_GetHashCode__,
    (void (*)(Calculator_NumericNode*))__System_Object_Finalize__,
    (bool (*)(Calculator_NumericNode*, System_Object*))__System_Object_Equals__,
    (int32_t (*)(Calculator_NumericNode*))__Calculator_NumericNode_Reduce__,
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
    /* Path=1, Unique=0: IL_0008: nop */
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(59): */
    /* Path=1, Unique=0: IL_0009: nop */
    /* Path=1, Unique=0: IL_000a: ldarg.0 */
    stack0_0__ = this__;
    /* Path=1, Unique=0: IL_000b: ldarg.1 */
    stack1_1__ = oper;
    /* Path=1, Unique=0: IL_000c: stfld Calculator.OperatorNode Calculator.ExpressionNode::Operator */
    stack0_0__->Operator = stack1_1__;
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(61): */
    /* Path=1, Unique=0: IL_0011: ldarg.0 */
    stack0_0__ = this__;
    /* Path=1, Unique=0: IL_0012: ldarg.2 */
    stack1_2__ = left;
    /* Path=1, Unique=0: IL_0013: stfld Calculator.ReducibleNode Calculator.ExpressionNode::Left */
    stack0_0__->Left = stack1_2__;
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(62): */
    /* Path=1, Unique=0: IL_0018: ldarg.0 */
    stack0_0__ = this__;
    /* Path=1, Unique=0: IL_0019: ldarg.3 */
    stack1_2__ = right;
    /* Path=1, Unique=0: IL_001a: stfld Calculator.ReducibleNode Calculator.ExpressionNode::Right */
    stack0_0__->Right = stack1_2__;
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(63): */
    /* Path=1, Unique=0: IL_001f: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return;
}

///////////////////////////////////////
// Virtual: Reduce

int32_t __Calculator_ExpressionNode_Reduce__(Calculator_ExpressionNode* this__)
{
    //-------------------
    // Local variables:

    int32_t leftResult;
    int32_t rightResult;
    bool local0;
    int32_t local1;
    bool local2;
    bool local3;
    bool local4;

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

/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(66): */
    /* Path=1, Unique=0: IL_0000: nop */
    /* Path=1, Unique=0: IL_0001: ldarg.0 */
    stack0_0__ = this__;
    /* Path=1, Unique=0: IL_0002: ldfld Calculator.ReducibleNode Calculator.ExpressionNode::Left */
    stack0_1__ = stack0_0__->Left;
    /* Path=1, Unique=0: IL_0007: callvirt System.Int32 Calculator.ReducibleNode::Reduce() */
    stack0_2__ = Calculator_ReducibleNode_Reduce(stack0_1__);
    /* Path=1, Unique=0: IL_000c: stloc.0 */
    leftResult = stack0_2__;
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(68): */
    /* Path=1, Unique=0: IL_000d: ldarg.0 */
    stack0_0__ = this__;
    /* Path=1, Unique=0: IL_000e: ldfld Calculator.ReducibleNode Calculator.ExpressionNode::Right */
    stack0_1__ = stack0_0__->Right;
    /* Path=1, Unique=0: IL_0013: callvirt System.Int32 Calculator.ReducibleNode::Reduce() */
    stack0_2__ = Calculator_ReducibleNode_Reduce(stack0_1__);
    /* Path=1, Unique=0: IL_0018: stloc.1 */
    rightResult = stack0_2__;
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(69): */
    /* Path=1, Unique=0: IL_0019: ldarg.0 */
    stack0_0__ = this__;
    /* Path=1, Unique=0: IL_001a: ldfld Calculator.OperatorNode Calculator.ExpressionNode::Operator */
    stack0_3__ = stack0_0__->Operator;
    /* Path=1, Unique=0: IL_001f: ldfld System.Char Calculator.OperatorNode::Operator */
    stack0_2__ = (int32_t)(stack0_3__->Operator);
    /* Path=1, Unique=0: IL_0024: ldc.i4.s 43 */
    stack1_0__ = 43;
    /* Path=1, Unique=0: IL_0026: ceq */
    stack0_2__ = (stack0_2__ == stack1_0__) ? 1 : 0;
    /* Path=1, Unique=0: IL_0028: stloc.2 */
    local0 = stack0_2__ ? true : false;
    /* Path=1, Unique=0: IL_0029: ldloc.2 */
    stack0_2__ = local0;
    /* Path=1, Unique=0: IL_002a: brfalse.s IL_0033 */
    if (stack0_2__ == 0) goto IL_0033;
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(70): */
    /* Path=1, Unique=0: IL_002c: nop */
    /* Path=1, Unique=0: IL_002d: ldloc.0 */
    stack0_2__ = leftResult;
    /* Path=1, Unique=0: IL_002e: ldloc.1 */
    stack1_0__ = rightResult;
    /* Path=1, Unique=0: IL_002f: add */
    stack0_2__ = stack0_2__ + stack1_0__;
    /* Path=1, Unique=0: IL_0030: stloc.3 */
    local1 = stack0_2__;
    /* Path=1, Unique=0: IL_0031: br.s IL_008b */
    goto IL_008b;
IL_0033:
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(73): */
    /* Path=2, Unique=0: IL_0033: ldarg.0 */
    stack0_0__ = this__;
    /* Path=2, Unique=0: IL_0034: ldfld Calculator.OperatorNode Calculator.ExpressionNode::Operator */
    stack0_3__ = stack0_0__->Operator;
    /* Path=2, Unique=0: IL_0039: ldfld System.Char Calculator.OperatorNode::Operator */
    stack0_2__ = (int32_t)(stack0_3__->Operator);
    /* Path=2, Unique=0: IL_003e: ldc.i4.s 45 */
    stack1_0__ = 45;
    /* Path=2, Unique=0: IL_0040: ceq */
    stack0_2__ = (stack0_2__ == stack1_0__) ? 1 : 0;
    /* Path=2, Unique=0: IL_0042: stloc.s local4 */
    local2 = stack0_2__ ? true : false;
    /* Path=2, Unique=0: IL_0044: ldloc.s local4 */
    stack0_2__ = local2;
    /* Path=2, Unique=0: IL_0046: brfalse.s IL_004f */
    if (stack0_2__ == 0) goto IL_004f;
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(74): */
    /* Path=2, Unique=0: IL_0048: nop */
    /* Path=2, Unique=0: IL_0049: ldloc.0 */
    stack0_2__ = leftResult;
    /* Path=2, Unique=0: IL_004a: ldloc.1 */
    stack1_0__ = rightResult;
    /* Path=2, Unique=0: IL_004b: sub */
    stack0_2__ = stack0_2__ - stack1_0__;
    /* Path=2, Unique=0: IL_004c: stloc.3 */
    local1 = stack0_2__;
    /* Path=2, Unique=0: IL_004d: br.s IL_008b */
    goto IL_008b;
IL_004f:
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(77): */
    /* Path=4, Unique=0: IL_004f: ldarg.0 */
    stack0_0__ = this__;
    /* Path=4, Unique=0: IL_0050: ldfld Calculator.OperatorNode Calculator.ExpressionNode::Operator */
    stack0_3__ = stack0_0__->Operator;
    /* Path=4, Unique=0: IL_0055: ldfld System.Char Calculator.OperatorNode::Operator */
    stack0_2__ = (int32_t)(stack0_3__->Operator);
    /* Path=4, Unique=0: IL_005a: ldc.i4.s 42 */
    stack1_0__ = 42;
    /* Path=4, Unique=0: IL_005c: ceq */
    stack0_2__ = (stack0_2__ == stack1_0__) ? 1 : 0;
    /* Path=4, Unique=0: IL_005e: stloc.s local5 */
    local3 = stack0_2__ ? true : false;
    /* Path=4, Unique=0: IL_0060: ldloc.s local5 */
    stack0_2__ = local3;
    /* Path=4, Unique=0: IL_0062: brfalse.s IL_006b */
    if (stack0_2__ == 0) goto IL_006b;
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(78): */
    /* Path=4, Unique=0: IL_0064: nop */
    /* Path=4, Unique=0: IL_0065: ldloc.0 */
    stack0_2__ = leftResult;
    /* Path=4, Unique=0: IL_0066: ldloc.1 */
    stack1_0__ = rightResult;
    /* Path=4, Unique=0: IL_0067: mul */
    stack0_2__ = stack0_2__ * stack1_0__;
    /* Path=4, Unique=0: IL_0068: stloc.3 */
    local1 = stack0_2__;
    /* Path=4, Unique=0: IL_0069: br.s IL_008b */
    goto IL_008b;
IL_006b:
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(81): */
    /* Path=5, Unique=0: IL_006b: ldarg.0 */
    stack0_0__ = this__;
    /* Path=5, Unique=0: IL_006c: ldfld Calculator.OperatorNode Calculator.ExpressionNode::Operator */
    stack0_3__ = stack0_0__->Operator;
    /* Path=5, Unique=0: IL_0071: ldfld System.Char Calculator.OperatorNode::Operator */
    stack0_2__ = (int32_t)(stack0_3__->Operator);
    /* Path=5, Unique=0: IL_0076: ldc.i4.s 47 */
    stack1_0__ = 47;
    /* Path=5, Unique=0: IL_0078: ceq */
    stack0_2__ = (stack0_2__ == stack1_0__) ? 1 : 0;
    /* Path=5, Unique=0: IL_007a: stloc.s local6 */
    local4 = stack0_2__ ? true : false;
    /* Path=5, Unique=0: IL_007c: ldloc.s local6 */
    stack0_2__ = local4;
    /* Path=5, Unique=0: IL_007e: brfalse.s IL_0087 */
    if (stack0_2__ == 0) goto IL_0087;
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(82): */
    /* Path=5, Unique=0: IL_0080: nop */
    /* Path=5, Unique=0: IL_0081: ldloc.0 */
    stack0_2__ = leftResult;
    /* Path=5, Unique=0: IL_0082: ldloc.1 */
    stack1_0__ = rightResult;
    /* Path=5, Unique=0: IL_0083: div */
    stack0_2__ = stack0_2__ / stack1_0__;
    /* Path=5, Unique=0: IL_0084: stloc.3 */
    local1 = stack0_2__;
    /* Path=5, Unique=0: IL_0085: br.s IL_008b */
    goto IL_008b;
IL_0087:
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(87): */
    /* Path=6, Unique=0: IL_0087: ldc.i4.0 */
    stack0_2__ = 0;
    /* Path=6, Unique=0: IL_0088: stloc.3 */
    local1 = stack0_2__;
    /* Path=6, Unique=0: IL_0089: br.s IL_008b */
    goto IL_008b;
IL_008b:
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(88): */
    /* Path=3, Unique=0: IL_008b: ldloc.3 */
    stack0_2__ = local1;
    /* Path=3, Unique=0: IL_008c: ret */
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
    /* internalcall */ (IL2C_MARK_HANDLER)__Calculator_ExpressionNode_IL2C_MarkHandler__,
};

//////////////////////
// VTables:

// Vtable of Calculator.ExpressionNode
__Calculator_ExpressionNode_VTABLE_DECL__ __Calculator_ExpressionNode_VTABLE__ = {
    (void* (*)(Calculator_ExpressionNode*, IL2C_RUNTIME_TYPE_DECL*))__Calculator_ExpressionNode_IL2C_RuntimeCast__,
    (System_String* (*)(Calculator_ExpressionNode*))__System_Object_ToString__,
    (int32_t (*)(Calculator_ExpressionNode*))__System_Object_GetHashCode__,
    (void (*)(Calculator_ExpressionNode*))__System_Object_Finalize__,
    (bool (*)(Calculator_ExpressionNode*, System_Object*))__System_Object_Equals__,
    (int32_t (*)(Calculator_ExpressionNode*))__Calculator_ExpressionNode_Reduce__,
};

////////////////////////////////////////////////////////////
// Type: Calculator.PolishNotation

///////////////////////////////////////
// SkipWhiteSpace

int32_t Calculator_PolishNotation_SkipWhiteSpace(System_String* line, int32_t startIndex)
{
    //-------------------
    // Local variables:

    int32_t index;
    wchar_t ch;
    bool local0;
    bool local1;
    int32_t local2;

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

/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(94): */
    /* Path=1, Unique=0: IL_0000: nop */
    /* Path=1, Unique=0: IL_0001: ldarg.1 */
    stack0_0__ = startIndex;
    /* Path=1, Unique=0: IL_0002: stloc.0 */
    index = stack0_0__;
    /* Path=1, Unique=0: IL_0003: br.s IL_002a */
    goto IL_002a;
IL_0005:
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(97): */
    /* Path=3, Unique=0: IL_0005: nop */
    /* Path=3, Unique=0: IL_0006: ldarg.0 */
    stack0_1__ = line;
    /* Path=3, Unique=0: IL_0007: ldloc.0 */
    stack1_2__ = index;
    /* Path=3, Unique=0: IL_0008: callvirt System.Char System.String::get_Chars(System.Int32) */
    stack0_2__ = System_String_get_Chars(stack0_1__, stack1_2__);
    /* Path=3, Unique=0: IL_000d: stloc.1 */
    ch = (wchar_t)stack0_2__;
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(99): */
    /* Path=3, Unique=0: IL_000e: ldloc.1 */
    stack0_0__ = ch;
    /* Path=3, Unique=0: IL_000f: ldc.i4.s 32 */
    stack1_2__ = 32;
    /* Path=3, Unique=0: IL_0011: beq.s IL_001d */
    if (stack0_0__ == stack1_2__) goto IL_001d;
    /* Path=3, Unique=0: IL_0013: ldloc.1 */
    stack0_0__ = ch;
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
    local0 = stack0_0__ ? true : false;
    /* Path=5, Unique=0: IL_001f: ldloc.2 */
    stack0_0__ = local0;
    /* Path=5, Unique=0: IL_0020: brfalse.s IL_0025 */
    if (stack0_0__ == 0) goto IL_0025;
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(100): */
    /* Path=5, Unique=0: IL_0022: nop */
    /* Path=5, Unique=0: IL_0023: br.s IL_0037 */
    goto IL_0037;
IL_0025:
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(103): */
    /* Path=6, Unique=0: IL_0025: ldloc.0 */
    stack0_0__ = index;
    /* Path=6, Unique=0: IL_0026: ldc.i4.1 */
    stack1_2__ = 1;
    /* Path=6, Unique=0: IL_0027: add */
    stack0_0__ = stack0_0__ + stack1_2__;
    /* Path=6, Unique=0: IL_0028: stloc.0 */
    index = stack0_0__;
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(104): */
    /* Path=6, Unique=0: IL_0029: nop */
IL_002a:
    /* Path=2, Unique=0: IL_002a: ldloc.0 */
    stack0_0__ = index;
    /* Path=2, Unique=0: IL_002b: ldarg.0 */
    stack1_0__ = line;
    /* Path=2, Unique=0: IL_002c: callvirt System.Int32 System.String::get_Length() */
    stack1_1__ = System_String_get_Length(stack1_0__);
    /* Path=2, Unique=0: IL_0031: clt */
    stack0_0__ = (stack0_0__ < stack1_1__) ? 1 : 0;
    /* Path=2, Unique=0: IL_0033: stloc.3 */
    local1 = stack0_0__ ? true : false;
    /* Path=2, Unique=0: IL_0034: ldloc.3 */
    stack0_0__ = local1;
    /* Path=2, Unique=0: IL_0035: brtrue.s IL_0005 */
    if (stack0_0__ != 0) goto IL_0005;
IL_0037:
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(106): */
    /* Path=2, Unique=0: IL_0037: ldloc.0 */
    stack0_0__ = index;
    /* Path=2, Unique=0: IL_0038: stloc.s local4 */
    local2 = stack0_0__;
    /* Path=2, Unique=0: IL_003a: br.s IL_003c */
    goto IL_003c;
IL_003c:
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(107): */
    /* Path=4, Unique=0: IL_003c: ldloc.s local4 */
    stack0_0__ = local2;
    /* Path=4, Unique=0: IL_003e: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return stack0_0__;
}

///////////////////////////////////////
// ParseOperator

Calculator_OperatorNode* Calculator_PolishNotation_ParseOperator(System_String* line, int32_t startIndex)
{
    //-------------------
    // Local variables:

    int32_t index;
    wchar_t ch;
    bool local0;
    Calculator_OperatorNode* local1 = NULL;
    bool local2;

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
        Calculator_OperatorNode** plocal1;
        IL2C_CecilHelper_PseudoZeroType** pstack0_1__;
        System_String** pstack0_2__;
        Calculator_OperatorNode** pstack0_4__;
        System_String** pstack1_0__;
    } __executionFrame__;

    __executionFrame__.targetCount = 5;
    __executionFrame__.plocal1 = &local1;
    __executionFrame__.pstack0_1__ = &stack0_1__;
    __executionFrame__.pstack0_2__ = &stack0_2__;
    __executionFrame__.pstack0_4__ = &stack0_4__;
    __executionFrame__.pstack1_0__ = &stack1_0__;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(110): */
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
    local0 = stack0_0__ ? true : false;
    /* Path=1, Unique=0: IL_000e: ldloc.2 */
    stack0_0__ = local0;
    /* Path=1, Unique=0: IL_000f: brfalse.s IL_0016 */
    if (stack0_0__ == 0) goto IL_0016;
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(112): */
    /* Path=1, Unique=0: IL_0011: nop */
    /* Path=1, Unique=0: IL_0012: ldnull */
    stack0_1__ = NULL;
    /* Path=1, Unique=0: IL_0013: stloc.3 */
    local1 = (Calculator_OperatorNode*)stack0_1__;
    /* Path=1, Unique=0: IL_0014: br.s IL_005b */
    goto IL_005b;
IL_0016:
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(116): */
    /* Path=2, Unique=0: IL_0016: ldarg.1 */
    stack0_0__ = startIndex;
    /* Path=2, Unique=0: IL_0017: stloc.0 */
    index = stack0_0__;
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(117): */
    /* Path=2, Unique=0: IL_0018: ldarg.0 */
    stack0_2__ = line;
    /* Path=2, Unique=0: IL_0019: ldloc.0 */
    stack1_2__ = index;
    /* Path=2, Unique=0: IL_001a: callvirt System.Char System.String::get_Chars(System.Int32) */
    stack0_3__ = System_String_get_Chars(stack0_2__, stack1_2__);
    /* Path=2, Unique=0: IL_001f: stloc.1 */
    ch = (wchar_t)stack0_3__;
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(118): */
    /* Path=2, Unique=0: IL_0020: ldloc.1 */
    stack0_0__ = ch;
    /* Path=2, Unique=0: IL_0021: ldc.i4.s 43 */
    stack1_2__ = 43;
    /* Path=2, Unique=0: IL_0023: beq.s IL_0039 */
    if (stack0_0__ == stack1_2__) goto IL_0039;
    /* Path=2, Unique=0: IL_0025: ldloc.1 */
    stack0_0__ = ch;
    /* Path=2, Unique=0: IL_0026: ldc.i4.s 45 */
    stack1_2__ = 45;
    /* Path=2, Unique=0: IL_0028: beq.s IL_0039 */
    if (stack0_0__ == stack1_2__) goto IL_0039;
    /* Path=2, Unique=0: IL_002a: ldloc.1 */
    stack0_0__ = ch;
    /* Path=2, Unique=0: IL_002b: ldc.i4.s 42 */
    stack1_2__ = 42;
    /* Path=2, Unique=0: IL_002d: beq.s IL_0039 */
    if (stack0_0__ == stack1_2__) goto IL_0039;
    /* Path=2, Unique=0: IL_002f: ldloc.1 */
    stack0_0__ = ch;
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
    local2 = stack0_0__ ? true : false;
    /* Path=4, Unique=0: IL_003c: ldloc.s local4 */
    stack0_0__ = local2;
    /* Path=4, Unique=0: IL_003e: brfalse.s IL_0045 */
    if (stack0_0__ == 0) goto IL_0045;
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(119): */
    /* Path=4, Unique=0: IL_0040: nop */
    /* Path=4, Unique=0: IL_0041: ldnull */
    stack0_1__ = NULL;
    /* Path=4, Unique=0: IL_0042: stloc.3 */
    local1 = (Calculator_OperatorNode*)stack0_1__;
    /* Path=4, Unique=0: IL_0043: br.s IL_005b */
    goto IL_005b;
IL_0045:
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(122): */
    /* Path=5, Unique=0: IL_0045: ldloc.0 */
    stack0_0__ = index;
    /* Path=5, Unique=0: IL_0046: ldc.i4.1 */
    stack1_2__ = 1;
    /* Path=5, Unique=0: IL_0047: add */
    stack0_0__ = stack0_0__ + stack1_2__;
    /* Path=5, Unique=0: IL_0048: stloc.0 */
    index = stack0_0__;
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(124): */
    /* Path=5, Unique=0: IL_0049: ldarg.0 */
    stack0_2__ = line;
    /* Path=5, Unique=0: IL_004a: ldloc.0 */
    stack1_2__ = index;
    /* Path=5, Unique=0: IL_004b: call System.Int32 Calculator.PolishNotation::SkipWhiteSpace(System.String,System.Int32) */
    stack0_0__ = Calculator_PolishNotation_SkipWhiteSpace(stack0_2__, stack1_2__);
    /* Path=5, Unique=0: IL_0050: stloc.0 */
    index = stack0_0__;
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(125): */
    /* Path=5, Unique=0: IL_0051: ldloc.1 */
    stack0_0__ = ch;
    /* Path=5, Unique=0: IL_0052: ldloc.0 */
    stack1_2__ = index;
    /* Path=5, Unique=0: IL_0053: newobj System.Void Calculator.OperatorNode::.ctor(System.Char,System.Int32) */
    stack0_4__ = il2c_get_uninitialized_object(il2c_typeof(Calculator_OperatorNode));
    stack0_4__->vptr0__ = &__Calculator_OperatorNode_VTABLE__;
    Calculator_OperatorNode__ctor(stack0_4__, (wchar_t)stack0_0__, stack1_2__);
    /* Path=5, Unique=0: IL_0058: stloc.3 */
    local1 = stack0_4__;
    /* Path=5, Unique=0: IL_0059: br.s IL_005b */
    goto IL_005b;
IL_005b:
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(126): */
    /* Path=3, Unique=0: IL_005b: ldloc.3 */
    stack0_4__ = local1;
    /* Path=3, Unique=0: IL_005c: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return stack0_4__;
}

///////////////////////////////////////
// ParseNumeric

Calculator_NumericNode* Calculator_PolishNotation_ParseNumeric(System_String* line, int32_t startIndex)
{
    //-------------------
    // Local variables:

    int32_t index;
    System_String* token = NULL;
    int32_t numeric;
    bool local0;
    Calculator_NumericNode* local1 = NULL;
    wchar_t ch;
    bool local2;
    bool local3;
    bool local4;
    bool local5;

    //-------------------
    // Evaluation stacks:

    int32_t stack0_0__;
    IL2C_CecilHelper_PseudoZeroType* stack0_1__ = NULL;
    Calculator_NumericNode* stack0_2__ = NULL;
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
        System_String** ptoken;
        Calculator_NumericNode** plocal1;
        IL2C_CecilHelper_PseudoZeroType** pstack0_1__;
        Calculator_NumericNode** pstack0_2__;
        System_String** pstack0_3__;
        System_String** pstack0_5__;
        System_String** pstack1_0__;
        int32_t** pstack1_3__;
    } __executionFrame__;

    __executionFrame__.targetCount = 8;
    __executionFrame__.ptoken = &token;
    __executionFrame__.plocal1 = &local1;
    __executionFrame__.pstack0_1__ = &stack0_1__;
    __executionFrame__.pstack0_2__ = &stack0_2__;
    __executionFrame__.pstack0_3__ = &stack0_3__;
    __executionFrame__.pstack0_5__ = &stack0_5__;
    __executionFrame__.pstack1_0__ = &stack1_0__;
    __executionFrame__.pstack1_3__ = &stack1_3__;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(129): */
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
    local0 = stack0_0__ ? true : false;
    /* Path=1, Unique=0: IL_000e: ldloc.3 */
    stack0_0__ = local0;
    /* Path=1, Unique=0: IL_000f: brfalse.s IL_0017 */
    if (stack0_0__ == 0) goto IL_0017;
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(131): */
    /* Path=1, Unique=0: IL_0011: nop */
    /* Path=1, Unique=0: IL_0012: ldnull */
    stack0_1__ = NULL;
    /* Path=1, Unique=0: IL_0013: stloc.s local4 */
    local1 = (Calculator_NumericNode*)stack0_1__;
    /* Path=1, Unique=0: IL_0015: br.s IL_008d */
    goto IL_008d;
IL_0017:
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(135): */
    /* Path=2, Unique=0: IL_0017: ldarg.1 */
    stack0_0__ = startIndex;
    /* Path=2, Unique=0: IL_0018: stloc.0 */
    index = stack0_0__;
    /* Path=2, Unique=0: IL_0019: br.s IL_0039 */
    goto IL_0039;
IL_001b:
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(137): */
    /* Path=5, Unique=0: IL_001b: nop */
    /* Path=5, Unique=0: IL_001c: ldarg.0 */
    stack0_3__ = line;
    /* Path=5, Unique=0: IL_001d: ldloc.0 */
    stack1_2__ = index;
    /* Path=5, Unique=0: IL_001e: callvirt System.Char System.String::get_Chars(System.Int32) */
    stack0_4__ = System_String_get_Chars(stack0_3__, stack1_2__);
    /* Path=5, Unique=0: IL_0023: stloc.s local5 */
    ch = (wchar_t)stack0_4__;
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(139): */
    /* Path=5, Unique=0: IL_0025: ldloc.s local5 */
    stack0_0__ = ch;
    /* Path=5, Unique=0: IL_0027: ldc.i4.s 32 */
    stack1_2__ = 32;
    /* Path=5, Unique=0: IL_0029: ceq */
    stack0_0__ = (stack0_0__ == stack1_2__) ? 1 : 0;
    /* Path=5, Unique=0: IL_002b: stloc.s local6 */
    local2 = stack0_0__ ? true : false;
    /* Path=5, Unique=0: IL_002d: ldloc.s local6 */
    stack0_0__ = local2;
    /* Path=5, Unique=0: IL_002f: brfalse.s IL_0034 */
    if (stack0_0__ == 0) goto IL_0034;
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(140): */
    /* Path=5, Unique=0: IL_0031: nop */
    /* Path=5, Unique=0: IL_0032: br.s IL_0048 */
    goto IL_0048;
IL_0034:
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(143): */
    /* Path=7, Unique=0: IL_0034: ldloc.0 */
    stack0_0__ = index;
    /* Path=7, Unique=0: IL_0035: ldc.i4.1 */
    stack1_2__ = 1;
    /* Path=7, Unique=0: IL_0036: add */
    stack0_0__ = stack0_0__ + stack1_2__;
    /* Path=7, Unique=0: IL_0037: stloc.0 */
    index = stack0_0__;
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(144): */
    /* Path=7, Unique=0: IL_0038: nop */
IL_0039:
    /* Path=4, Unique=0: IL_0039: ldloc.0 */
    stack0_0__ = index;
    /* Path=4, Unique=0: IL_003a: ldarg.0 */
    stack1_0__ = line;
    /* Path=4, Unique=0: IL_003b: callvirt System.Int32 System.String::get_Length() */
    stack1_1__ = System_String_get_Length(stack1_0__);
    /* Path=4, Unique=0: IL_0040: clt */
    stack0_0__ = (stack0_0__ < stack1_1__) ? 1 : 0;
    /* Path=4, Unique=0: IL_0042: stloc.s local7 */
    local3 = stack0_0__ ? true : false;
    /* Path=4, Unique=0: IL_0044: ldloc.s local7 */
    stack0_0__ = local3;
    /* Path=4, Unique=0: IL_0046: brtrue.s IL_001b */
    if (stack0_0__ != 0) goto IL_001b;
IL_0048:
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(146): */
    /* Path=4, Unique=0: IL_0048: ldloc.0 */
    stack0_0__ = index;
    /* Path=4, Unique=0: IL_0049: ldarg.1 */
    stack1_2__ = startIndex;
    /* Path=4, Unique=0: IL_004a: ceq */
    stack0_0__ = (stack0_0__ == stack1_2__) ? 1 : 0;
    /* Path=4, Unique=0: IL_004c: stloc.s local8 */
    local4 = stack0_0__ ? true : false;
    /* Path=4, Unique=0: IL_004e: ldloc.s local8 */
    stack0_0__ = local4;
    /* Path=4, Unique=0: IL_0050: brfalse.s IL_0058 */
    if (stack0_0__ == 0) goto IL_0058;
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(147): */
    /* Path=4, Unique=0: IL_0052: nop */
    /* Path=4, Unique=0: IL_0053: ldnull */
    stack0_1__ = NULL;
    /* Path=4, Unique=0: IL_0054: stloc.s local4 */
    local1 = (Calculator_NumericNode*)stack0_1__;
    /* Path=4, Unique=0: IL_0056: br.s IL_008d */
    goto IL_008d;
IL_0058:
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(151): */
    /* Path=6, Unique=0: IL_0058: ldarg.0 */
    stack0_3__ = line;
    /* Path=6, Unique=0: IL_0059: ldarg.1 */
    stack1_2__ = startIndex;
    /* Path=6, Unique=0: IL_005a: ldloc.0 */
    stack2_0__ = index;
    /* Path=6, Unique=0: IL_005b: ldarg.1 */
    stack3_0__ = startIndex;
    /* Path=6, Unique=0: IL_005c: sub */
    stack2_0__ = stack2_0__ - stack3_0__;
    /* Path=6, Unique=0: IL_005d: callvirt System.String System.String::Substring(System.Int32,System.Int32) */
    stack0_5__ = System_String_Substring_1(stack0_3__, stack1_2__, stack2_0__);
    /* Path=6, Unique=0: IL_0062: stloc.1 */
    token = stack0_5__;
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(152): */
    /* Path=6, Unique=0: IL_0063: ldloc.1 */
    stack0_3__ = token;
    /* Path=6, Unique=0: IL_0064: ldloca.s local2 */
    stack1_3__ = &numeric;
    /* Path=6, Unique=0: IL_0066: call System.Boolean System.Int32::TryParse(System.String,System.Int32&) */
    stack0_0__ = System_Int32_TryParse(stack0_3__, stack1_3__);
    /* Path=6, Unique=0: IL_006b: ldc.i4.0 */
    stack1_2__ = 0;
    /* Path=6, Unique=0: IL_006c: ceq */
    stack0_0__ = (stack0_0__ == stack1_2__) ? 1 : 0;
    /* Path=6, Unique=0: IL_006e: stloc.s local9 */
    local5 = stack0_0__ ? true : false;
    /* Path=6, Unique=0: IL_0070: ldloc.s local9 */
    stack0_0__ = local5;
    /* Path=6, Unique=0: IL_0072: brfalse.s IL_007a */
    if (stack0_0__ == 0) goto IL_007a;
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(153): */
    /* Path=6, Unique=0: IL_0074: nop */
    /* Path=6, Unique=0: IL_0075: ldnull */
    stack0_1__ = NULL;
    /* Path=6, Unique=0: IL_0076: stloc.s local4 */
    local1 = (Calculator_NumericNode*)stack0_1__;
    /* Path=6, Unique=0: IL_0078: br.s IL_008d */
    goto IL_008d;
IL_007a:
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(157): */
    /* Path=8, Unique=0: IL_007a: ldarg.0 */
    stack0_3__ = line;
    /* Path=8, Unique=0: IL_007b: ldloc.0 */
    stack1_2__ = index;
    /* Path=8, Unique=0: IL_007c: call System.Int32 Calculator.PolishNotation::SkipWhiteSpace(System.String,System.Int32) */
    stack0_0__ = Calculator_PolishNotation_SkipWhiteSpace(stack0_3__, stack1_2__);
    /* Path=8, Unique=0: IL_0081: stloc.0 */
    index = stack0_0__;
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(158): */
    /* Path=8, Unique=0: IL_0082: ldloc.2 */
    stack0_0__ = numeric;
    /* Path=8, Unique=0: IL_0083: ldloc.0 */
    stack1_2__ = index;
    /* Path=8, Unique=0: IL_0084: newobj System.Void Calculator.NumericNode::.ctor(System.Int32,System.Int32) */
    stack0_2__ = il2c_get_uninitialized_object(il2c_typeof(Calculator_NumericNode));
    stack0_2__->vptr0__ = &__Calculator_NumericNode_VTABLE__;
    Calculator_NumericNode__ctor(stack0_2__, stack0_0__, stack1_2__);
    /* Path=8, Unique=0: IL_0089: stloc.s local4 */
    local1 = stack0_2__;
    /* Path=8, Unique=0: IL_008b: br.s IL_008d */
    goto IL_008d;
IL_008d:
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(159): */
    /* Path=3, Unique=0: IL_008d: ldloc.s local4 */
    stack0_2__ = local1;
    /* Path=3, Unique=0: IL_008f: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return stack0_2__;
}

///////////////////////////////////////
// ParseExpression

Calculator_ExpressionNode* Calculator_PolishNotation_ParseExpression(System_String* line, int32_t startIndex)
{
    //-------------------
    // Local variables:

    Calculator_OperatorNode* oper = NULL;
    Calculator_ReducibleNode* left = NULL;
    Calculator_ReducibleNode* right = NULL;
    int32_t index;
    bool local0;
    Calculator_ExpressionNode* local1 = NULL;
    bool local2;
    bool local3;
    bool local4;
    bool local5;
    bool local6;

    //-------------------
    // Evaluation stacks:

    int32_t stack0_0__;
    IL2C_CecilHelper_PseudoZeroType* stack0_1__ = NULL;
    System_String* stack0_2__ = NULL;
    Calculator_OperatorNode* stack0_3__ = NULL;
    Calculator_ExpressionNode* stack0_4__ = NULL;
    Calculator_NumericNode* stack0_5__ = NULL;
    Calculator_ReducibleNode* stack0_6__ = NULL;
    System_String* stack1_0__ = NULL;
    int32_t stack1_1__;
    int32_t stack1_2__;
    IL2C_CecilHelper_PseudoZeroType* stack1_3__ = NULL;
    Calculator_OperatorNode* stack1_4__ = NULL;
    Calculator_ReducibleNode* stack1_5__ = NULL;
    Calculator_ReducibleNode* stack2_0__ = NULL;
    int32_t stack3_0__;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        Calculator_OperatorNode** poper;
        Calculator_ReducibleNode** pleft;
        Calculator_ReducibleNode** pright;
        Calculator_ExpressionNode** plocal1;
        IL2C_CecilHelper_PseudoZeroType** pstack0_1__;
        System_String** pstack0_2__;
        Calculator_OperatorNode** pstack0_3__;
        Calculator_ExpressionNode** pstack0_4__;
        Calculator_NumericNode** pstack0_5__;
        Calculator_ReducibleNode** pstack0_6__;
        System_String** pstack1_0__;
        IL2C_CecilHelper_PseudoZeroType** pstack1_3__;
        Calculator_OperatorNode** pstack1_4__;
        Calculator_ReducibleNode** pstack1_5__;
        Calculator_ReducibleNode** pstack2_0__;
    } __executionFrame__;

    __executionFrame__.targetCount = 15;
    __executionFrame__.poper = &oper;
    __executionFrame__.pleft = &left;
    __executionFrame__.pright = &right;
    __executionFrame__.plocal1 = &local1;
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

/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(162): */
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
    local0 = stack0_0__ ? true : false;
    /* Path=1, Unique=0: IL_000f: ldloc.s local4 */
    stack0_0__ = local0;
    /* Path=1, Unique=0: IL_0011: brfalse.s IL_001c */
    if (stack0_0__ == 0) goto IL_001c;
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(164): */
    /* Path=1, Unique=0: IL_0013: nop */
    /* Path=1, Unique=0: IL_0014: ldnull */
    stack0_1__ = NULL;
    /* Path=1, Unique=0: IL_0015: stloc.s local5 */
    local1 = (Calculator_ExpressionNode*)stack0_1__;
    /* Path=1, Unique=0: IL_0017: br IL_00bd */
    goto IL_00bd;
IL_001c:
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(168): */
    /* Path=2, Unique=0: IL_001c: ldarg.0 */
    stack0_2__ = line;
    /* Path=2, Unique=0: IL_001d: ldarg.1 */
    stack1_2__ = startIndex;
    /* Path=2, Unique=0: IL_001e: call Calculator.OperatorNode Calculator.PolishNotation::ParseOperator(System.String,System.Int32) */
    stack0_3__ = Calculator_PolishNotation_ParseOperator(stack0_2__, stack1_2__);
    /* Path=2, Unique=0: IL_0023: stloc.0 */
    oper = stack0_3__;
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(169): */
    /* Path=2, Unique=0: IL_0024: ldloc.0 */
    stack0_3__ = oper;
    /* Path=2, Unique=0: IL_0025: ldnull */
    stack1_3__ = NULL;
    /* Path=2, Unique=0: IL_0026: ceq */
    stack0_0__ = (stack0_3__ == ((Calculator_OperatorNode*)stack1_3__)) ? 1 : 0;
    /* Path=2, Unique=0: IL_0028: stloc.s local6 */
    local2 = stack0_0__ ? true : false;
    /* Path=2, Unique=0: IL_002a: ldloc.s local6 */
    stack0_0__ = local2;
    /* Path=2, Unique=0: IL_002c: brfalse.s IL_0037 */
    if (stack0_0__ == 0) goto IL_0037;
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(170): */
    /* Path=2, Unique=0: IL_002e: nop */
    /* Path=2, Unique=0: IL_002f: ldnull */
    stack0_1__ = NULL;
    /* Path=2, Unique=0: IL_0030: stloc.s local5 */
    local1 = (Calculator_ExpressionNode*)stack0_1__;
    /* Path=2, Unique=0: IL_0032: br IL_00bd */
    goto IL_00bd;
IL_0037:
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(174): */
    /* Path=4, Unique=0: IL_0037: ldarg.0 */
    stack0_2__ = line;
    /* Path=4, Unique=0: IL_0038: ldloc.0 */
    stack1_4__ = oper;
    /* Path=4, Unique=0: IL_0039: ldfld System.Int32 Calculator.AbstractNode::NextIndex */
    stack1_2__ = stack1_4__->NextIndex;
    /* Path=4, Unique=0: IL_003e: call Calculator.NumericNode Calculator.PolishNotation::ParseNumeric(System.String,System.Int32) */
    stack0_5__ = Calculator_PolishNotation_ParseNumeric(stack0_2__, stack1_2__);
    /* Path=4, Unique=0: IL_0043: stloc.1 */
    left = (Calculator_ReducibleNode*)stack0_5__;
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(175): */
    /* Path=4, Unique=0: IL_0044: ldloc.1 */
    stack0_6__ = left;
    /* Path=4, Unique=0: IL_0045: ldnull */
    stack1_3__ = NULL;
    /* Path=4, Unique=0: IL_0046: ceq */
    stack0_0__ = (stack0_6__ == ((Calculator_ReducibleNode*)stack1_3__)) ? 1 : 0;
    /* Path=4, Unique=0: IL_0048: stloc.s local7 */
    local3 = stack0_0__ ? true : false;
    /* Path=4, Unique=0: IL_004a: ldloc.s local7 */
    stack0_0__ = local3;
    /* Path=4, Unique=0: IL_004c: brfalse.s IL_006d */
    if (stack0_0__ == 0) goto IL_006d;
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(176): */
    /* Path=4, Unique=0: IL_004e: nop */
    /* Path=4, Unique=0: IL_004f: ldarg.0 */
    stack0_2__ = line;
    /* Path=4, Unique=0: IL_0050: ldloc.0 */
    stack1_4__ = oper;
    /* Path=4, Unique=0: IL_0051: ldfld System.Int32 Calculator.AbstractNode::NextIndex */
    stack1_2__ = stack1_4__->NextIndex;
    /* Path=4, Unique=0: IL_0056: call Calculator.ExpressionNode Calculator.PolishNotation::ParseExpression(System.String,System.Int32) */
    stack0_4__ = Calculator_PolishNotation_ParseExpression(stack0_2__, stack1_2__);
    /* Path=4, Unique=0: IL_005b: stloc.1 */
    left = (Calculator_ReducibleNode*)stack0_4__;
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(178): */
    /* Path=4, Unique=0: IL_005c: ldloc.1 */
    stack0_6__ = left;
    /* Path=4, Unique=0: IL_005d: ldnull */
    stack1_3__ = NULL;
    /* Path=4, Unique=0: IL_005e: ceq */
    stack0_0__ = (stack0_6__ == ((Calculator_ReducibleNode*)stack1_3__)) ? 1 : 0;
    /* Path=4, Unique=0: IL_0060: stloc.s local8 */
    local4 = stack0_0__ ? true : false;
    /* Path=4, Unique=0: IL_0062: ldloc.s local8 */
    stack0_0__ = local4;
    /* Path=4, Unique=0: IL_0064: brfalse.s IL_006c */
    if (stack0_0__ == 0) goto IL_006c;
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(179): */
    /* Path=4, Unique=0: IL_0066: nop */
    /* Path=4, Unique=0: IL_0067: ldnull */
    stack0_1__ = NULL;
    /* Path=4, Unique=0: IL_0068: stloc.s local5 */
    local1 = (Calculator_ExpressionNode*)stack0_1__;
    /* Path=4, Unique=0: IL_006a: br.s IL_00bd */
    goto IL_00bd;
IL_006c:
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(182): */
    /* Path=6, Unique=0: IL_006c: nop */
IL_006d:
    /* Path=5, Unique=0: IL_006d: ldarg.0 */
    stack0_2__ = line;
    /* Path=5, Unique=0: IL_006e: ldloc.1 */
    stack1_5__ = left;
    /* Path=5, Unique=0: IL_006f: ldfld System.Int32 Calculator.AbstractNode::NextIndex */
    stack1_2__ = stack1_5__->NextIndex;
    /* Path=5, Unique=0: IL_0074: call Calculator.NumericNode Calculator.PolishNotation::ParseNumeric(System.String,System.Int32) */
    stack0_5__ = Calculator_PolishNotation_ParseNumeric(stack0_2__, stack1_2__);
    /* Path=5, Unique=0: IL_0079: stloc.2 */
    right = (Calculator_ReducibleNode*)stack0_5__;
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(185): */
    /* Path=5, Unique=0: IL_007a: ldloc.2 */
    stack0_6__ = right;
    /* Path=5, Unique=0: IL_007b: ldnull */
    stack1_3__ = NULL;
    /* Path=5, Unique=0: IL_007c: ceq */
    stack0_0__ = (stack0_6__ == ((Calculator_ReducibleNode*)stack1_3__)) ? 1 : 0;
    /* Path=5, Unique=0: IL_007e: stloc.s local9 */
    local5 = stack0_0__ ? true : false;
    /* Path=5, Unique=0: IL_0080: ldloc.s local9 */
    stack0_0__ = local5;
    /* Path=5, Unique=0: IL_0082: brfalse.s IL_00a3 */
    if (stack0_0__ == 0) goto IL_00a3;
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(186): */
    /* Path=5, Unique=0: IL_0084: nop */
    /* Path=5, Unique=0: IL_0085: ldarg.0 */
    stack0_2__ = line;
    /* Path=5, Unique=0: IL_0086: ldloc.1 */
    stack1_5__ = left;
    /* Path=5, Unique=0: IL_0087: ldfld System.Int32 Calculator.AbstractNode::NextIndex */
    stack1_2__ = stack1_5__->NextIndex;
    /* Path=5, Unique=0: IL_008c: call Calculator.ExpressionNode Calculator.PolishNotation::ParseExpression(System.String,System.Int32) */
    stack0_4__ = Calculator_PolishNotation_ParseExpression(stack0_2__, stack1_2__);
    /* Path=5, Unique=0: IL_0091: stloc.2 */
    right = (Calculator_ReducibleNode*)stack0_4__;
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(188): */
    /* Path=5, Unique=0: IL_0092: ldloc.2 */
    stack0_6__ = right;
    /* Path=5, Unique=0: IL_0093: ldnull */
    stack1_3__ = NULL;
    /* Path=5, Unique=0: IL_0094: ceq */
    stack0_0__ = (stack0_6__ == ((Calculator_ReducibleNode*)stack1_3__)) ? 1 : 0;
    /* Path=5, Unique=0: IL_0096: stloc.s local10 */
    local6 = stack0_0__ ? true : false;
    /* Path=5, Unique=0: IL_0098: ldloc.s local10 */
    stack0_0__ = local6;
    /* Path=5, Unique=0: IL_009a: brfalse.s IL_00a2 */
    if (stack0_0__ == 0) goto IL_00a2;
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(189): */
    /* Path=5, Unique=0: IL_009c: nop */
    /* Path=5, Unique=0: IL_009d: ldnull */
    stack0_1__ = NULL;
    /* Path=5, Unique=0: IL_009e: stloc.s local5 */
    local1 = (Calculator_ExpressionNode*)stack0_1__;
    /* Path=5, Unique=0: IL_00a0: br.s IL_00bd */
    goto IL_00bd;
IL_00a2:
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(192): */
    /* Path=8, Unique=0: IL_00a2: nop */
IL_00a3:
    /* Path=7, Unique=0: IL_00a3: ldarg.0 */
    stack0_2__ = line;
    /* Path=7, Unique=0: IL_00a4: ldloc.2 */
    stack1_5__ = right;
    /* Path=7, Unique=0: IL_00a5: ldfld System.Int32 Calculator.AbstractNode::NextIndex */
    stack1_2__ = stack1_5__->NextIndex;
    /* Path=7, Unique=0: IL_00aa: call System.Int32 Calculator.PolishNotation::SkipWhiteSpace(System.String,System.Int32) */
    stack0_0__ = Calculator_PolishNotation_SkipWhiteSpace(stack0_2__, stack1_2__);
    /* Path=7, Unique=0: IL_00af: stloc.3 */
    index = stack0_0__;
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(195): */
    /* Path=7, Unique=0: IL_00b0: ldloc.0 */
    stack0_3__ = oper;
    /* Path=7, Unique=0: IL_00b1: ldloc.1 */
    stack1_5__ = left;
    /* Path=7, Unique=0: IL_00b2: ldloc.2 */
    stack2_0__ = right;
    /* Path=7, Unique=0: IL_00b3: ldloc.3 */
    stack3_0__ = index;
    /* Path=7, Unique=0: IL_00b4: newobj System.Void Calculator.ExpressionNode::.ctor(Calculator.OperatorNode,Calculator.ReducibleNode,Calculator.ReducibleNode,System.Int32) */
    stack0_4__ = il2c_get_uninitialized_object(il2c_typeof(Calculator_ExpressionNode));
    stack0_4__->vptr0__ = &__Calculator_ExpressionNode_VTABLE__;
    Calculator_ExpressionNode__ctor(stack0_4__, stack0_3__, stack1_5__, stack2_0__, stack3_0__);
    /* Path=7, Unique=0: IL_00b9: stloc.s local5 */
    local1 = stack0_4__;
    /* Path=7, Unique=0: IL_00bb: br.s IL_00bd */
    goto IL_00bd;
IL_00bd:
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(196): */
    /* Path=3, Unique=0: IL_00bd: ldloc.s local5 */
    stack0_4__ = local1;
    /* Path=3, Unique=0: IL_00bf: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return stack0_4__;
}

///////////////////////////////////////
// Main

void Calculator_PolishNotation_Main(void)
{
    //-------------------
    // Local variables:

    System_String* line = NULL;
    bool local0;
    Calculator_ExpressionNode* expr = NULL;
    int32_t result;
    bool local1;
    bool local2;
    bool local3;

    //-------------------
    // Evaluation stacks:

    System_String* stack0_0__ = NULL;
    int32_t stack0_1__;
    Calculator_ExpressionNode* stack0_2__ = NULL;
    int32_t stack1_0__;
    System_String* stack1_1__ = NULL;
    IL2C_CecilHelper_PseudoZeroType* stack1_2__ = NULL;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        System_String** pline;
        Calculator_ExpressionNode** pexpr;
        System_String** pstack0_0__;
        Calculator_ExpressionNode** pstack0_2__;
        System_String** pstack1_1__;
        IL2C_CecilHelper_PseudoZeroType** pstack1_2__;
    } __executionFrame__;

    __executionFrame__.targetCount = 6;
    __executionFrame__.pline = &line;
    __executionFrame__.pexpr = &expr;
    __executionFrame__.pstack0_0__ = &stack0_0__;
    __executionFrame__.pstack0_2__ = &stack0_2__;
    __executionFrame__.pstack1_1__ = &stack1_1__;
    __executionFrame__.pstack1_2__ = &stack1_2__;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(199): */
    /* Path=1, Unique=0: IL_0000: nop */
    /* Path=1, Unique=0: IL_0001: ldstr "Polish notation calculator." */
    stack0_0__ = string0__;
    /* Path=1, Unique=0: IL_0006: call System.Void System.Console::WriteLine(System.String) */
    System_Console_WriteLine_10(stack0_0__);
    /* Path=1, Unique=0: IL_000b: nop */
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(201): */
    /* Path=1, Unique=0: IL_000c: ldstr "This is proof of concept for IL2C." */
    stack0_0__ = string1__;
    /* Path=1, Unique=0: IL_0011: call System.Void System.Console::WriteLine(System.String) */
    System_Console_WriteLine_10(stack0_0__);
    /* Path=1, Unique=0: IL_0016: nop */
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(202): */
    /* Path=1, Unique=0: IL_0017: ldstr "https://github.com/kekyo/IL2C" */
    stack0_0__ = string2__;
    /* Path=1, Unique=0: IL_001c: call System.Void System.Console::WriteLine(System.String) */
    System_Console_WriteLine_10(stack0_0__);
    /* Path=1, Unique=0: IL_0021: nop */
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(203): */
    /* Path=1, Unique=0: IL_0022: call System.Void System.Console::WriteLine() */
    System_Console_WriteLine();
    /* Path=1, Unique=0: IL_0027: nop */
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(204): */
    /* Path=1, Unique=0: IL_0028: ldstr "Type "exit" to exit." */
    stack0_0__ = string3__;
    /* Path=1, Unique=0: IL_002d: call System.Void System.Console::WriteLine(System.String) */
    System_Console_WriteLine_10(stack0_0__);
    /* Path=1, Unique=0: IL_0032: nop */
    /* Path=1, Unique=0: IL_0033: br.s IL_00aa */
    goto IL_00aa;
IL_0035:
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(207): */
    /* Path=3, Unique=0: IL_0035: nop */
    /* Path=3, Unique=0: IL_0036: call System.Void System.Console::WriteLine() */
    System_Console_WriteLine();
    /* Path=3, Unique=0: IL_003b: nop */
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(209): */
    /* Path=3, Unique=0: IL_003c: ldstr "PN> " */
    stack0_0__ = string4__;
    /* Path=3, Unique=0: IL_0041: call System.Void System.Console::Write(System.String) */
    System_Console_Write_9(stack0_0__);
    /* Path=3, Unique=0: IL_0046: nop */
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(210): */
    /* Path=3, Unique=0: IL_0047: call System.String System.Console::ReadLine() */
    stack0_0__ = System_Console_ReadLine();
    /* Path=3, Unique=0: IL_004c: stloc.0 */
    line = stack0_0__;
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(211): */
    /* Path=3, Unique=0: IL_004d: ldloc.0 */
    stack0_0__ = line;
    /* Path=3, Unique=0: IL_004e: call System.Boolean System.String::IsNullOrWhiteSpace(System.String) */
    stack0_1__ = System_String_IsNullOrWhiteSpace(stack0_0__);
    /* Path=3, Unique=0: IL_0053: ldc.i4.0 */
    stack1_0__ = 0;
    /* Path=3, Unique=0: IL_0054: ceq */
    stack0_1__ = (stack0_1__ == stack1_0__) ? 1 : 0;
    /* Path=3, Unique=0: IL_0056: stloc.1 */
    local0 = stack0_1__ ? true : false;
    /* Path=3, Unique=0: IL_0057: ldloc.1 */
    stack0_1__ = local0;
    /* Path=3, Unique=0: IL_0058: brfalse.s IL_00a9 */
    if (stack0_1__ == 0) goto IL_00a9;
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(212): */
    /* Path=3, Unique=0: IL_005a: nop */
    /* Path=3, Unique=0: IL_005b: ldloc.0 */
    stack0_0__ = line;
    /* Path=3, Unique=0: IL_005c: ldstr "exit" */
    stack1_1__ = string5__;
    /* Path=3, Unique=0: IL_0061: call System.Boolean System.String::op_Equality(System.String,System.String) */
    stack0_1__ = System_String_op_Equality(stack0_0__, stack1_1__);
    /* Path=3, Unique=0: IL_0066: stloc.s local4 */
    local1 = stack0_1__ ? true : false;
    /* Path=3, Unique=0: IL_0068: ldloc.s local4 */
    stack0_1__ = local1;
    /* Path=3, Unique=0: IL_006a: brfalse.s IL_006f */
    if (stack0_1__ == 0) goto IL_006f;
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(214): */
    /* Path=3, Unique=0: IL_006c: nop */
    /* Path=3, Unique=0: IL_006d: br.s IL_00af */
    goto IL_00af;
IL_006f:
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(218): */
    /* Path=5, Unique=0: IL_006f: ldloc.0 */
    stack0_0__ = line;
    /* Path=5, Unique=0: IL_0070: ldc.i4.0 */
    stack1_0__ = 0;
    /* Path=5, Unique=0: IL_0071: call Calculator.ExpressionNode Calculator.PolishNotation::ParseExpression(System.String,System.Int32) */
    stack0_2__ = Calculator_PolishNotation_ParseExpression(stack0_0__, stack1_0__);
    /* Path=5, Unique=0: IL_0076: stloc.2 */
    expr = stack0_2__;
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(219): */
    /* Path=5, Unique=0: IL_0077: ldloc.2 */
    stack0_2__ = expr;
    /* Path=5, Unique=0: IL_0078: ldnull */
    stack1_2__ = NULL;
    /* Path=5, Unique=0: IL_0079: ceq */
    stack0_1__ = (stack0_2__ == ((Calculator_ExpressionNode*)stack1_2__)) ? 1 : 0;
    /* Path=5, Unique=0: IL_007b: stloc.s local5 */
    local2 = stack0_1__ ? true : false;
    /* Path=5, Unique=0: IL_007d: ldloc.s local5 */
    stack0_1__ = local2;
    /* Path=5, Unique=0: IL_007f: brfalse.s IL_008f */
    if (stack0_1__ == 0) goto IL_008f;
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(220): */
    /* Path=5, Unique=0: IL_0081: nop */
    /* Path=5, Unique=0: IL_0082: ldstr "Syntax error." */
    stack0_0__ = string6__;
    /* Path=5, Unique=0: IL_0087: call System.Void System.Console::WriteLine(System.String) */
    System_Console_WriteLine_10(stack0_0__);
    /* Path=5, Unique=0: IL_008c: nop */
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(222): */
    /* Path=5, Unique=0: IL_008d: br.s IL_00aa */
    goto IL_00aa;
IL_008f:
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(225): */
    /* Path=7, Unique=0: IL_008f: ldloc.2 */
    stack0_2__ = expr;
    /* Path=7, Unique=0: IL_0090: callvirt System.Int32 Calculator.ReducibleNode::Reduce() */
    stack0_1__ = Calculator_ReducibleNode_Reduce((Calculator_ReducibleNode*)stack0_2__);
    /* Path=7, Unique=0: IL_0095: stloc.3 */
    result = stack0_1__;
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(227): */
    /* Path=7, Unique=0: IL_0096: ldstr "Reuslt=" */
    stack0_0__ = string7__;
    /* Path=7, Unique=0: IL_009b: call System.Void System.Console::Write(System.String) */
    System_Console_Write_9(stack0_0__);
    /* Path=7, Unique=0: IL_00a0: nop */
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(228): */
    /* Path=7, Unique=0: IL_00a1: ldloc.3 */
    stack0_1__ = result;
    /* Path=7, Unique=0: IL_00a2: call System.Void System.Console::WriteLine(System.Int32) */
    System_Console_WriteLine_6(stack0_1__);
    /* Path=7, Unique=0: IL_00a7: nop */
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(229): */
    /* Path=7, Unique=0: IL_00a8: nop */
IL_00a9:
    /* Path=4, Unique=0: IL_00a9: nop */
IL_00aa:
    /* Path=2, Unique=0: IL_00aa: ldc.i4.1 */
    stack0_1__ = 1;
    /* Path=2, Unique=0: IL_00ab: stloc.s local6 */
    local3 = stack0_1__ ? true : false;
    /* Path=2, Unique=0: IL_00ad: br.s IL_0035 */
    goto IL_0035;
IL_00af:
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(231): */
    /* Path=6, Unique=0: IL_00af: ret */
    il2c_unlink_execution_frame(&__executionFrame__);
    return;
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
    /* Path=1, Unique=0: IL_0006: nop */
    /* Path=1, Unique=0: IL_0007: ret */
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
    /* internalcall */ (IL2C_MARK_HANDLER)__Calculator_PolishNotation_IL2C_MarkHandler__,
};

//////////////////////
// VTables:

// Vtable of Calculator.PolishNotation
__Calculator_PolishNotation_VTABLE_DECL__ __Calculator_PolishNotation_VTABLE__ = {
    (void* (*)(Calculator_PolishNotation*, IL2C_RUNTIME_TYPE_DECL*))__Calculator_PolishNotation_IL2C_RuntimeCast__,
    (System_String* (*)(Calculator_PolishNotation*))__System_Object_ToString__,
    (int32_t (*)(Calculator_PolishNotation*))__System_Object_GetHashCode__,
    (void (*)(Calculator_PolishNotation*))__System_Object_Finalize__,
    (bool (*)(Calculator_PolishNotation*, System_Object*))__System_Object_Equals__,
};
