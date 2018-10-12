
#include <il2c.h>

#include "Calculator.h"
#include "Calculator.Code.h"

//////////////////////////////////////////////////////////////////////////////////
// [9-1] Const strings:

IL2C_CONST_STRING(string0__, L"Polish notation calculator.");
IL2C_CONST_STRING(string1__, L"This is proof of concept for IL2C.");
IL2C_CONST_STRING(string2__, L"https://github.com/kekyo/IL2C");
IL2C_CONST_STRING(string3__, L"Type \"exit\" to exit.");
IL2C_CONST_STRING(string4__, L"PN> ");
IL2C_CONST_STRING(string5__, L"exit");
IL2C_CONST_STRING(string6__, L"Syntax error.");
IL2C_CONST_STRING(string7__, L"Reuslt=");
IL2C_CONST_STRING(string8__, L"(");
IL2C_CONST_STRING(string9__, L") = ");

//////////////////////////////////////////////////////////////////////////////////
// [9-2] File scope prototypes:

#ifdef __cplusplus
extern "C" {
#endif

//////////////////////////////////////////////////////////////////////////////////
// [2-1] Types:


//////////////////////////////////////////////////////////////////////////////////
// [2-2] Public static fields:







//////////////////////////////////////////////////////////////////////////////////
// [2-3] Methods:

// [2-4] Member methods: Calculator.AbstractNode

extern /* internalcall */ void __Calculator_AbstractNode_IL2C_MarkHandler__(Calculator_AbstractNode* this__);
extern /* internalcall */ void* __Calculator_AbstractNode_IL2C_RuntimeCast__(Calculator_AbstractNode* this__, IL2C_RUNTIME_TYPE_DECL* type);

// [2-5] Virtual methods: Calculator.AbstractNode


// [2-4] Member methods: Calculator.OperatorNode

extern /* internalcall */ void __Calculator_OperatorNode_IL2C_MarkHandler__(Calculator_OperatorNode* this__);
extern /* internalcall */ void* __Calculator_OperatorNode_IL2C_RuntimeCast__(Calculator_OperatorNode* this__, IL2C_RUNTIME_TYPE_DECL* type);

// [2-5] Virtual methods: Calculator.OperatorNode


// [2-4] Member methods: Calculator.ReducibleNode

extern /* internalcall */ void __Calculator_ReducibleNode_IL2C_MarkHandler__(Calculator_ReducibleNode* this__);
extern /* internalcall */ void* __Calculator_ReducibleNode_IL2C_RuntimeCast__(Calculator_ReducibleNode* this__, IL2C_RUNTIME_TYPE_DECL* type);

// [2-5] Virtual methods: Calculator.ReducibleNode


// [2-4] Member methods: Calculator.NumericNode

extern /* internalcall */ void __Calculator_NumericNode_IL2C_MarkHandler__(Calculator_NumericNode* this__);
extern /* internalcall */ void* __Calculator_NumericNode_IL2C_RuntimeCast__(Calculator_NumericNode* this__, IL2C_RUNTIME_TYPE_DECL* type);

// [2-5] Virtual methods: Calculator.NumericNode


// [2-4] Member methods: Calculator.ExpressionNode

extern /* internalcall */ void __Calculator_ExpressionNode_IL2C_MarkHandler__(Calculator_ExpressionNode* this__);
extern /* internalcall */ void* __Calculator_ExpressionNode_IL2C_RuntimeCast__(Calculator_ExpressionNode* this__, IL2C_RUNTIME_TYPE_DECL* type);

// [2-5] Virtual methods: Calculator.ExpressionNode


// [2-4] Member methods: Calculator.PolishNotation

extern /* internalcall */ void __Calculator_PolishNotation_IL2C_MarkHandler__(Calculator_PolishNotation* this__);
extern /* internalcall */ void* __Calculator_PolishNotation_IL2C_RuntimeCast__(Calculator_PolishNotation* this__, IL2C_RUNTIME_TYPE_DECL* type);
extern int32_t Calculator_PolishNotation_SkipWhiteSpace(System_String* line, int32_t startIndex);
extern Calculator_OperatorNode* Calculator_PolishNotation_ParseOperator(System_String* line, int32_t startIndex);
extern Calculator_NumericNode* Calculator_PolishNotation_ParseNumeric(System_String* line, int32_t startIndex);
extern Calculator_ExpressionNode* Calculator_PolishNotation_ParseExpression(System_String* line, int32_t startIndex);
extern void Calculator_PolishNotation_SendExternalTicker(System_String* message);

// [2-5] Virtual methods: Calculator.PolishNotation


#ifdef __cplusplus
}
#endif

//////////////////////////////////////////////////////////////////////////////////
// [9-3] Declare static fields:







//////////////////////////////////////////////////////////////////////////////////
// [9-4] Declare methods:

////////////////////////////////////////////////////////////
// [9-4] Type: Calculator.AbstractNode

///////////////////////////////////////
// [3] Calculator.AbstractNode..ctor(Calculator.AbstractNode this__, System.Int32 nextIndex)

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

/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(13): */
    /* IL_0000: ldarg.0  */
    stack0_0__ = this__;
    /* IL_0001: call System.Object..ctor */
    /* IL_0006: nop  */
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(14): */
    /* IL_0007: nop  */
    /* IL_0008: ldarg.0  */
    stack0_0__ = this__;
    /* IL_0009: ldarg.1  */
    stack1_0__ = nextIndex;
    /* IL_000a: stfld Calculator.AbstractNode.NextIndex */
    stack0_0__->NextIndex = stack1_0__;
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(16): */
    /* IL_000f: ret  */
    il2c_unlink_execution_frame(&__executionFrame__);
    return;
}

//////////////////////
// [7] Runtime helpers:

// [7-1] Runtime cast
void* __Calculator_AbstractNode_IL2C_RuntimeCast__(Calculator_AbstractNode* this__, IL2C_RUNTIME_TYPE_DECL* type)
{
    // [7-2] This type
    if (type == il2c_typeof(Calculator_AbstractNode)) return this__;

    // [7-4] Delegate checking base types
    return __System_Object_IL2C_RuntimeCast__((System_Object*)this__, type);
}

// [7-5] GC's mark handler
void __Calculator_AbstractNode_IL2C_MarkHandler__(Calculator_AbstractNode* this__)
{

    // [7-7] Delegate checking base types
    __System_Object_IL2C_MarkHandler__((System_Object*)this__);
}

// [7-8] Runtime type information
IL2C_RUNTIME_TYPE_DECL __Calculator_AbstractNode_RUNTIME_TYPE__ = {
    "Calculator.AbstractNode",
    sizeof(Calculator_AbstractNode),
    /* internalcall */ (IL2C_MARK_HANDLER)__Calculator_AbstractNode_IL2C_MarkHandler__,
};

//////////////////////
// [7-9] VTables:

// [7-10] Vtable of Calculator.AbstractNode
__Calculator_AbstractNode_VTABLE_DECL__ __Calculator_AbstractNode_VTABLE__ = {
    __System_Object_ToString__,
    __System_Object_GetHashCode__,
    __System_Object_GetType__,
    __System_Object_Finalize__,
    __System_Object_MemberwiseClone__,
    __System_Object_Equals__,
    __System_Object_GetFieldInfo__,
    __System_Object_FieldSetter__,
    __System_Object_FieldGetter__,
};

////////////////////////////////////////////////////////////
// [9-4] Type: Calculator.OperatorNode

///////////////////////////////////////
// [3] Calculator.OperatorNode..ctor(Calculator.OperatorNode this__, System.Char oper, System.Int32 nextIndex)

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

/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(23): */
    /* IL_0000: ldarg.0  */
    stack0_0__ = this__;
    /* IL_0001: ldarg.2  */
    stack1_0__ = nextIndex;
    /* IL_0002: call Calculator.AbstractNode..ctor */
    Calculator_AbstractNode__ctor((Calculator_AbstractNode*)stack0_0__, stack1_0__);
    /* IL_0007: nop  */
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(24): */
    /* IL_0008: nop  */
    /* IL_0009: ldarg.0  */
    stack0_0__ = this__;
    /* IL_000a: ldarg.1  */
    stack1_0__ = (int32_t)(oper);
    /* IL_000b: stfld Calculator.OperatorNode.Operator */
    stack0_0__->Operator = (wchar_t)(stack1_0__);
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(26): */
    /* IL_0010: ret  */
    il2c_unlink_execution_frame(&__executionFrame__);
    return;
}

//////////////////////
// [7] Runtime helpers:

// [7-1] Runtime cast
void* __Calculator_OperatorNode_IL2C_RuntimeCast__(Calculator_OperatorNode* this__, IL2C_RUNTIME_TYPE_DECL* type)
{
    // [7-2] This type
    if (type == il2c_typeof(Calculator_OperatorNode)) return this__;

    // [7-4] Delegate checking base types
    return __Calculator_AbstractNode_IL2C_RuntimeCast__((Calculator_AbstractNode*)this__, type);
}

// [7-5] GC's mark handler
void __Calculator_OperatorNode_IL2C_MarkHandler__(Calculator_OperatorNode* this__)
{

    /* Suppressed invoke base mark handler */
}

// [7-8] Runtime type information
IL2C_RUNTIME_TYPE_DECL __Calculator_OperatorNode_RUNTIME_TYPE__ = {
    "Calculator.OperatorNode",
    sizeof(Calculator_OperatorNode),
    /* internalcall */ (IL2C_MARK_HANDLER)__Calculator_OperatorNode_IL2C_MarkHandler__,
};

//////////////////////
// [7-9] VTables:

// [7-10] Vtable of Calculator.OperatorNode
__Calculator_OperatorNode_VTABLE_DECL__ __Calculator_OperatorNode_VTABLE__ = {
    __System_Object_ToString__,
    __System_Object_GetHashCode__,
    __System_Object_GetType__,
    __System_Object_Finalize__,
    __System_Object_MemberwiseClone__,
    __System_Object_Equals__,
    __System_Object_GetFieldInfo__,
    __System_Object_FieldSetter__,
    __System_Object_FieldGetter__,
};

////////////////////////////////////////////////////////////
// [9-4] Type: Calculator.ReducibleNode

///////////////////////////////////////
// [3] Calculator.ReducibleNode..ctor(Calculator.ReducibleNode this__, System.Int32 nextIndex)

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

/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(31): */
    /* IL_0000: ldarg.0  */
    stack0_0__ = this__;
    /* IL_0001: ldarg.1  */
    stack1_0__ = nextIndex;
    /* IL_0002: call Calculator.AbstractNode..ctor */
    Calculator_AbstractNode__ctor((Calculator_AbstractNode*)stack0_0__, stack1_0__);
    /* IL_0007: nop  */
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(32): */
    /* IL_0008: nop  */
    /* IL_0009: ret  */
    il2c_unlink_execution_frame(&__executionFrame__);
    return;
}

///////////////////////////////////////
// [5] Abstract: Calculator.ReducibleNode.Reduce(Calculator.ReducibleNode this__)

int32_t __Calculator_ReducibleNode_Reduce__(Calculator_ReducibleNode* this__)
{
    // WARNING: Pure virtual function called.
    //TODO: throw : assert(0);
    return (int32_t)0;
}

//////////////////////
// [7] Runtime helpers:

// [7-1] Runtime cast
void* __Calculator_ReducibleNode_IL2C_RuntimeCast__(Calculator_ReducibleNode* this__, IL2C_RUNTIME_TYPE_DECL* type)
{
    // [7-2] This type
    if (type == il2c_typeof(Calculator_ReducibleNode)) return this__;

    // [7-4] Delegate checking base types
    return __Calculator_AbstractNode_IL2C_RuntimeCast__((Calculator_AbstractNode*)this__, type);
}

// [7-5] GC's mark handler
void __Calculator_ReducibleNode_IL2C_MarkHandler__(Calculator_ReducibleNode* this__)
{

    /* Suppressed invoke base mark handler */
}

// [7-8] Runtime type information
IL2C_RUNTIME_TYPE_DECL __Calculator_ReducibleNode_RUNTIME_TYPE__ = {
    "Calculator.ReducibleNode",
    sizeof(Calculator_ReducibleNode),
    /* internalcall */ (IL2C_MARK_HANDLER)__Calculator_ReducibleNode_IL2C_MarkHandler__,
};

//////////////////////
// [7-9] VTables:

// [7-10] Vtable of Calculator.ReducibleNode
__Calculator_ReducibleNode_VTABLE_DECL__ __Calculator_ReducibleNode_VTABLE__ = {
    __System_Object_ToString__,
    __System_Object_GetHashCode__,
    __System_Object_GetType__,
    __System_Object_Finalize__,
    __System_Object_MemberwiseClone__,
    __System_Object_Equals__,
    __System_Object_GetFieldInfo__,
    __System_Object_FieldSetter__,
    __System_Object_FieldGetter__,
    __Calculator_ReducibleNode_Reduce__,
};

////////////////////////////////////////////////////////////
// [9-4] Type: Calculator.NumericNode

///////////////////////////////////////
// [3] Calculator.NumericNode..ctor(Calculator.NumericNode this__, System.Int32 numeric, System.Int32 nextIndex)

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

/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(42): */
    /* IL_0000: ldarg.0  */
    stack0_0__ = this__;
    /* IL_0001: ldarg.2  */
    stack1_0__ = nextIndex;
    /* IL_0002: call Calculator.ReducibleNode..ctor */
    Calculator_ReducibleNode__ctor((Calculator_ReducibleNode*)stack0_0__, stack1_0__);
    /* IL_0007: nop  */
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(43): */
    /* IL_0008: nop  */
    /* IL_0009: ldarg.0  */
    stack0_0__ = this__;
    /* IL_000a: ldarg.1  */
    stack1_0__ = numeric;
    /* IL_000b: stfld Calculator.NumericNode.Numeric */
    stack0_0__->Numeric = stack1_0__;
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(45): */
    /* IL_0010: ret  */
    il2c_unlink_execution_frame(&__executionFrame__);
    return;
}

///////////////////////////////////////
// [3] Virtual: Calculator.NumericNode.Reduce(Calculator.NumericNode this__)

int32_t __Calculator_NumericNode_Reduce__(Calculator_NumericNode* this__)
{
    //-------------------
    // Local variables:

    int32_t local0__;

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
    /* IL_0000: nop  */
    /* IL_0001: ldarg.0  */
    stack0_0__ = this__;
    /* IL_0002: ldfld Calculator.NumericNode.Numeric */
    stack0_1__ = stack0_0__->Numeric;
    /* IL_0007: stloc.0  */
    local0__ = stack0_1__;
    /* IL_0008: br.s IL_000a */
    goto IL_000a;
IL_000a:
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(50): */
    /* IL_000a: ldloc.0  */
    stack0_1__ = local0__;
    /* IL_000b: ret  */
    il2c_unlink_execution_frame(&__executionFrame__);
    return stack0_1__;
}

//////////////////////
// [7] Runtime helpers:

// [7-1] Runtime cast
void* __Calculator_NumericNode_IL2C_RuntimeCast__(Calculator_NumericNode* this__, IL2C_RUNTIME_TYPE_DECL* type)
{
    // [7-2] This type
    if (type == il2c_typeof(Calculator_NumericNode)) return this__;

    // [7-4] Delegate checking base types
    return __Calculator_ReducibleNode_IL2C_RuntimeCast__((Calculator_ReducibleNode*)this__, type);
}

// [7-5] GC's mark handler
void __Calculator_NumericNode_IL2C_MarkHandler__(Calculator_NumericNode* this__)
{

    /* Suppressed invoke base mark handler */
}

// [7-8] Runtime type information
IL2C_RUNTIME_TYPE_DECL __Calculator_NumericNode_RUNTIME_TYPE__ = {
    "Calculator.NumericNode",
    sizeof(Calculator_NumericNode),
    /* internalcall */ (IL2C_MARK_HANDLER)__Calculator_NumericNode_IL2C_MarkHandler__,
};

//////////////////////
// [7-9] VTables:

// [7-10] Vtable of Calculator.NumericNode
__Calculator_NumericNode_VTABLE_DECL__ __Calculator_NumericNode_VTABLE__ = {
    __System_Object_ToString__,
    __System_Object_GetHashCode__,
    __System_Object_GetType__,
    __System_Object_Finalize__,
    __System_Object_MemberwiseClone__,
    __System_Object_Equals__,
    __System_Object_GetFieldInfo__,
    __System_Object_FieldSetter__,
    __System_Object_FieldGetter__,
    __Calculator_ReducibleNode_Reduce__,
    __Calculator_NumericNode_Reduce__,
};

////////////////////////////////////////////////////////////
// [9-4] Type: Calculator.ExpressionNode

///////////////////////////////////////
// [3] Calculator.ExpressionNode..ctor(Calculator.ExpressionNode this__, Calculator.OperatorNode oper, Calculator.ReducibleNode left, Calculator.ReducibleNode right, System.Int32 nextIndex)

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

/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(59): */
    /* IL_0000: ldarg.0  */
    stack0_0__ = this__;
    /* IL_0001: ldarg.s nextIndex */
    stack1_0__ = nextIndex;
    /* IL_0003: call Calculator.ReducibleNode..ctor */
    Calculator_ReducibleNode__ctor((Calculator_ReducibleNode*)stack0_0__, stack1_0__);
    /* IL_0008: nop  */
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(60): */
    /* IL_0009: nop  */
    /* IL_000a: ldarg.0  */
    stack0_0__ = this__;
    /* IL_000b: ldarg.1  */
    stack1_1__ = oper;
    /* IL_000c: stfld Calculator.ExpressionNode.Operator */
    stack0_0__->Operator = stack1_1__;
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(62): */
    /* IL_0011: ldarg.0  */
    stack0_0__ = this__;
    /* IL_0012: ldarg.2  */
    stack1_2__ = left;
    /* IL_0013: stfld Calculator.ExpressionNode.Left */
    stack0_0__->Left = stack1_2__;
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(63): */
    /* IL_0018: ldarg.0  */
    stack0_0__ = this__;
    /* IL_0019: ldarg.3  */
    stack1_2__ = right;
    /* IL_001a: stfld Calculator.ExpressionNode.Right */
    stack0_0__->Right = stack1_2__;
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(64): */
    /* IL_001f: ret  */
    il2c_unlink_execution_frame(&__executionFrame__);
    return;
}

///////////////////////////////////////
// [3] Virtual: Calculator.ExpressionNode.Reduce(Calculator.ExpressionNode this__)

int32_t __Calculator_ExpressionNode_Reduce__(Calculator_ExpressionNode* this__)
{
    //-------------------
    // Local variables:

    int32_t leftResult;
    int32_t rightResult;
    bool local2__;
    int32_t local3__;
    bool local4__;
    bool local5__;
    bool local6__;

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
    /* IL_0000: nop  */
    /* IL_0001: ldarg.0  */
    stack0_0__ = this__;
    /* IL_0002: ldfld Calculator.ExpressionNode.Left */
    stack0_1__ = stack0_0__->Left;
    /* IL_0007: callvirt Calculator.ReducibleNode.Reduce */
    stack0_2__ = Calculator_ReducibleNode_Reduce(stack0_1__);
    /* IL_000c: stloc.0  */
    leftResult = stack0_2__;
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(69): */
    /* IL_000d: ldarg.0  */
    stack0_0__ = this__;
    /* IL_000e: ldfld Calculator.ExpressionNode.Right */
    stack0_1__ = stack0_0__->Right;
    /* IL_0013: callvirt Calculator.ReducibleNode.Reduce */
    stack0_2__ = Calculator_ReducibleNode_Reduce(stack0_1__);
    /* IL_0018: stloc.1  */
    rightResult = stack0_2__;
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(70): */
    /* IL_0019: ldarg.0  */
    stack0_0__ = this__;
    /* IL_001a: ldfld Calculator.ExpressionNode.Operator */
    stack0_3__ = stack0_0__->Operator;
    /* IL_001f: ldfld Calculator.OperatorNode.Operator */
    stack0_2__ = (int32_t)(stack0_3__->Operator);
    /* IL_0024: ldc.i4.s 43 */
    stack1_0__ = 43;
    /* IL_0026: ceq  */
    stack0_2__ = (stack0_2__ == stack1_0__) ? 1 : 0;
    /* IL_0028: stloc.2  */
    local2__ = (stack0_2__) ? true : false;
    /* IL_0029: ldloc.2  */
    stack0_2__ = local2__;
    /* IL_002a: brfalse.s IL_0033 */
    if (stack0_2__ == 0) goto IL_0033;
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(71): */
    /* IL_002c: nop  */
    /* IL_002d: ldloc.0  */
    stack0_2__ = leftResult;
    /* IL_002e: ldloc.1  */
    stack1_0__ = rightResult;
    /* IL_002f: add  */
    stack0_2__ = stack0_2__ + stack1_0__;
    /* IL_0030: stloc.3  */
    local3__ = stack0_2__;
    /* IL_0031: br.s IL_008b */
    goto IL_008b;
IL_0033:
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(74): */
    /* IL_0033: ldarg.0  */
    stack0_0__ = this__;
    /* IL_0034: ldfld Calculator.ExpressionNode.Operator */
    stack0_3__ = stack0_0__->Operator;
    /* IL_0039: ldfld Calculator.OperatorNode.Operator */
    stack0_2__ = (int32_t)(stack0_3__->Operator);
    /* IL_003e: ldc.i4.s 45 */
    stack1_0__ = 45;
    /* IL_0040: ceq  */
    stack0_2__ = (stack0_2__ == stack1_0__) ? 1 : 0;
    /* IL_0042: stloc.s local4__ */
    local4__ = (stack0_2__) ? true : false;
    /* IL_0044: ldloc.s local4__ */
    stack0_2__ = local4__;
    /* IL_0046: brfalse.s IL_004f */
    if (stack0_2__ == 0) goto IL_004f;
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(75): */
    /* IL_0048: nop  */
    /* IL_0049: ldloc.0  */
    stack0_2__ = leftResult;
    /* IL_004a: ldloc.1  */
    stack1_0__ = rightResult;
    /* IL_004b: sub  */
    stack0_2__ = stack0_2__ - stack1_0__;
    /* IL_004c: stloc.3  */
    local3__ = stack0_2__;
    /* IL_004d: br.s IL_008b */
    goto IL_008b;
IL_004f:
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(78): */
    /* IL_004f: ldarg.0  */
    stack0_0__ = this__;
    /* IL_0050: ldfld Calculator.ExpressionNode.Operator */
    stack0_3__ = stack0_0__->Operator;
    /* IL_0055: ldfld Calculator.OperatorNode.Operator */
    stack0_2__ = (int32_t)(stack0_3__->Operator);
    /* IL_005a: ldc.i4.s 42 */
    stack1_0__ = 42;
    /* IL_005c: ceq  */
    stack0_2__ = (stack0_2__ == stack1_0__) ? 1 : 0;
    /* IL_005e: stloc.s local5__ */
    local5__ = (stack0_2__) ? true : false;
    /* IL_0060: ldloc.s local5__ */
    stack0_2__ = local5__;
    /* IL_0062: brfalse.s IL_006b */
    if (stack0_2__ == 0) goto IL_006b;
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(79): */
    /* IL_0064: nop  */
    /* IL_0065: ldloc.0  */
    stack0_2__ = leftResult;
    /* IL_0066: ldloc.1  */
    stack1_0__ = rightResult;
    /* IL_0067: mul  */
    stack0_2__ = stack0_2__ * stack1_0__;
    /* IL_0068: stloc.3  */
    local3__ = stack0_2__;
    /* IL_0069: br.s IL_008b */
    goto IL_008b;
IL_006b:
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(82): */
    /* IL_006b: ldarg.0  */
    stack0_0__ = this__;
    /* IL_006c: ldfld Calculator.ExpressionNode.Operator */
    stack0_3__ = stack0_0__->Operator;
    /* IL_0071: ldfld Calculator.OperatorNode.Operator */
    stack0_2__ = (int32_t)(stack0_3__->Operator);
    /* IL_0076: ldc.i4.s 47 */
    stack1_0__ = 47;
    /* IL_0078: ceq  */
    stack0_2__ = (stack0_2__ == stack1_0__) ? 1 : 0;
    /* IL_007a: stloc.s local6__ */
    local6__ = (stack0_2__) ? true : false;
    /* IL_007c: ldloc.s local6__ */
    stack0_2__ = local6__;
    /* IL_007e: brfalse.s IL_0087 */
    if (stack0_2__ == 0) goto IL_0087;
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(83): */
    /* IL_0080: nop  */
    /* IL_0081: ldloc.0  */
    stack0_2__ = leftResult;
    /* IL_0082: ldloc.1  */
    stack1_0__ = rightResult;
    /* IL_0083: div  */
    stack0_2__ = stack0_2__ / stack1_0__;
    /* IL_0084: stloc.3  */
    local3__ = stack0_2__;
    /* IL_0085: br.s IL_008b */
    goto IL_008b;
IL_0087:
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(88): */
    /* IL_0087: ldc.i4.0  */
    stack0_2__ = 0;
    /* IL_0088: stloc.3  */
    local3__ = stack0_2__;
    /* IL_0089: br.s IL_008b */
    goto IL_008b;
IL_008b:
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(89): */
    /* IL_008b: ldloc.3  */
    stack0_2__ = local3__;
    /* IL_008c: ret  */
    il2c_unlink_execution_frame(&__executionFrame__);
    return stack0_2__;
}

//////////////////////
// [7] Runtime helpers:

// [7-1] Runtime cast
void* __Calculator_ExpressionNode_IL2C_RuntimeCast__(Calculator_ExpressionNode* this__, IL2C_RUNTIME_TYPE_DECL* type)
{
    // [7-2] This type
    if (type == il2c_typeof(Calculator_ExpressionNode)) return this__;

    // [7-4] Delegate checking base types
    return __Calculator_ReducibleNode_IL2C_RuntimeCast__((Calculator_ReducibleNode*)this__, type);
}

// [7-5] GC's mark handler
void __Calculator_ExpressionNode_IL2C_MarkHandler__(Calculator_ExpressionNode* this__)
{
    // [7-6] Try marking each object reference fields
    il2c_try_mark_from_handler(this__->Calculator_ExpressionNode_Operator);
    il2c_try_mark_from_handler(this__->Calculator_ExpressionNode_Left);
    il2c_try_mark_from_handler(this__->Calculator_ExpressionNode_Right);

    /* Suppressed invoke base mark handler */
}

// [7-8] Runtime type information
IL2C_RUNTIME_TYPE_DECL __Calculator_ExpressionNode_RUNTIME_TYPE__ = {
    "Calculator.ExpressionNode",
    sizeof(Calculator_ExpressionNode),
    /* internalcall */ (IL2C_MARK_HANDLER)__Calculator_ExpressionNode_IL2C_MarkHandler__,
};

//////////////////////
// [7-9] VTables:

// [7-10] Vtable of Calculator.ExpressionNode
__Calculator_ExpressionNode_VTABLE_DECL__ __Calculator_ExpressionNode_VTABLE__ = {
    __System_Object_ToString__,
    __System_Object_GetHashCode__,
    __System_Object_GetType__,
    __System_Object_Finalize__,
    __System_Object_MemberwiseClone__,
    __System_Object_Equals__,
    __System_Object_GetFieldInfo__,
    __System_Object_FieldSetter__,
    __System_Object_FieldGetter__,
    __Calculator_ReducibleNode_Reduce__,
    __Calculator_ExpressionNode_Reduce__,
};

////////////////////////////////////////////////////////////
// [9-4] Type: Calculator.PolishNotation

///////////////////////////////////////
// [3] Calculator.PolishNotation.SkipWhiteSpace(System.String line, System.Int32 startIndex)

int32_t Calculator_PolishNotation_SkipWhiteSpace(System_String* line, int32_t startIndex)
{
    //-------------------
    // Local variables:

    int32_t index;
    wchar_t ch;
    bool local2__;
    bool local3__;
    int32_t local4__;

    //-------------------
    // Evaluation stacks:

    int32_t stack0_0__;
    System_String* stack0_1__ = NULL;
    System_String* stack1_0__ = NULL;
    int32_t stack1_1__;

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
    /* IL_0000: nop  */
    /* IL_0001: ldarg.1  */
    stack0_0__ = startIndex;
    /* IL_0002: stloc.0  */
    index = stack0_0__;
    /* IL_0003: br.s IL_002a */
    goto IL_002a;
IL_0005:
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(98): */
    /* IL_0005: nop  */
    /* IL_0006: ldarg.0  */
    stack0_1__ = line;
    /* IL_0007: ldloc.0  */
    stack1_1__ = index;
    /* IL_0008: callvirt System.String.get_Chars */
    stack0_0__ = System_String_get_Chars(stack0_1__, stack1_1__);
    /* IL_000d: stloc.1  */
    ch = (wchar_t)(stack0_0__);
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(100): */
    /* IL_000e: ldloc.1  */
    stack0_0__ = ch;
    /* IL_000f: ldc.i4.s 32 */
    stack1_1__ = 32;
    /* IL_0011: beq.s IL_001d */
    if (stack0_0__ == stack1_1__) goto IL_001d;
    /* IL_0013: ldloc.1  */
    stack0_0__ = ch;
    /* IL_0014: ldc.i4.s 9 */
    stack1_1__ = 9;
    /* IL_0016: ceq  */
    stack0_0__ = (stack0_0__ == stack1_1__) ? 1 : 0;
    /* IL_0018: ldc.i4.0  */
    stack1_1__ = 0;
    /* IL_0019: ceq  */
    stack0_0__ = (stack0_0__ == stack1_1__) ? 1 : 0;
    /* IL_001b: br.s IL_001e */
    goto IL_001e;
IL_001d:
    /* IL_001d: ldc.i4.0  */
    stack0_0__ = 0;
IL_001e:
    /* IL_001e: stloc.2  */
    local2__ = (stack0_0__) ? true : false;
    /* IL_001f: ldloc.2  */
    stack0_0__ = local2__;
    /* IL_0020: brfalse.s IL_0025 */
    if (stack0_0__ == 0) goto IL_0025;
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(101): */
    /* IL_0022: nop  */
    /* IL_0023: br.s IL_0037 */
    goto IL_0037;
IL_0025:
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(104): */
    /* IL_0025: ldloc.0  */
    stack0_0__ = index;
    /* IL_0026: ldc.i4.1  */
    stack1_1__ = 1;
    /* IL_0027: add  */
    stack0_0__ = stack0_0__ + stack1_1__;
    /* IL_0028: stloc.0  */
    index = stack0_0__;
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(105): */
    /* IL_0029: nop  */
IL_002a:
    /* IL_002a: ldloc.0  */
    stack0_0__ = index;
    /* IL_002b: ldarg.0  */
    stack1_0__ = line;
    /* IL_002c: callvirt System.String.get_Length */
    stack1_1__ = System_String_get_Length(stack1_0__);
    /* IL_0031: clt  */
    stack0_0__ = (stack0_0__ < stack1_1__) ? 1 : 0;
    /* IL_0033: stloc.3  */
    local3__ = (stack0_0__) ? true : false;
    /* IL_0034: ldloc.3  */
    stack0_0__ = local3__;
    /* IL_0035: brtrue.s IL_0005 */
    if (stack0_0__ != 0) goto IL_0005;
IL_0037:
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(107): */
    /* IL_0037: ldloc.0  */
    stack0_0__ = index;
    /* IL_0038: stloc.s local4__ */
    local4__ = stack0_0__;
    /* IL_003a: br.s IL_003c */
    goto IL_003c;
IL_003c:
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(108): */
    /* IL_003c: ldloc.s local4__ */
    stack0_0__ = local4__;
    /* IL_003e: ret  */
    il2c_unlink_execution_frame(&__executionFrame__);
    return stack0_0__;
}

///////////////////////////////////////
// [3] Calculator.PolishNotation.ParseOperator(System.String line, System.Int32 startIndex)

Calculator_OperatorNode* Calculator_PolishNotation_ParseOperator(System_String* line, int32_t startIndex)
{
    //-------------------
    // Local variables:

    int32_t index;
    wchar_t ch;
    bool local2__;
    Calculator_OperatorNode* local3__ = NULL;
    bool local4__;

    //-------------------
    // Evaluation stacks:

    int32_t stack0_0__;
    intptr_t stack0_1__;
    System_String* stack0_2__ = NULL;
    Calculator_OperatorNode* stack0_3__ = NULL;
    System_String* stack1_0__ = NULL;
    int32_t stack1_1__;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        Calculator_OperatorNode** plocal3__;
        System_String** pstack0_2__;
        Calculator_OperatorNode** pstack0_3__;
        System_String** pstack1_0__;
    } __executionFrame__;

    __executionFrame__.targetCount = 4;
    __executionFrame__.plocal3__ = &local3__;
    __executionFrame__.pstack0_2__ = &stack0_2__;
    __executionFrame__.pstack0_3__ = &stack0_3__;
    __executionFrame__.pstack1_0__ = &stack1_0__;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(111): */
    /* IL_0000: nop  */
    /* IL_0001: ldarg.1  */
    stack0_0__ = startIndex;
    /* IL_0002: ldarg.0  */
    stack1_0__ = line;
    /* IL_0003: callvirt System.String.get_Length */
    stack1_1__ = System_String_get_Length(stack1_0__);
    /* IL_0008: clt  */
    stack0_0__ = (stack0_0__ < stack1_1__) ? 1 : 0;
    /* IL_000a: ldc.i4.0  */
    stack1_1__ = 0;
    /* IL_000b: ceq  */
    stack0_0__ = (stack0_0__ == stack1_1__) ? 1 : 0;
    /* IL_000d: stloc.2  */
    local2__ = (stack0_0__) ? true : false;
    /* IL_000e: ldloc.2  */
    stack0_0__ = local2__;
    /* IL_000f: brfalse.s IL_0016 */
    if (stack0_0__ == 0) goto IL_0016;
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(113): */
    /* IL_0011: nop  */
    /* IL_0012: ldnull  */
    stack0_1__ = NULL;
    /* IL_0013: stloc.3  */
    local3__ = (Calculator_OperatorNode*)stack0_1__;
    /* IL_0014: br.s IL_005b */
    goto IL_005b;
IL_0016:
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(117): */
    /* IL_0016: ldarg.1  */
    stack0_0__ = startIndex;
    /* IL_0017: stloc.0  */
    index = stack0_0__;
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(118): */
    /* IL_0018: ldarg.0  */
    stack0_2__ = line;
    /* IL_0019: ldloc.0  */
    stack1_1__ = index;
    /* IL_001a: callvirt System.String.get_Chars */
    stack0_0__ = System_String_get_Chars(stack0_2__, stack1_1__);
    /* IL_001f: stloc.1  */
    ch = (wchar_t)(stack0_0__);
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(119): */
    /* IL_0020: ldloc.1  */
    stack0_0__ = ch;
    /* IL_0021: ldc.i4.s 43 */
    stack1_1__ = 43;
    /* IL_0023: beq.s IL_0039 */
    if (stack0_0__ == stack1_1__) goto IL_0039;
    /* IL_0025: ldloc.1  */
    stack0_0__ = ch;
    /* IL_0026: ldc.i4.s 45 */
    stack1_1__ = 45;
    /* IL_0028: beq.s IL_0039 */
    if (stack0_0__ == stack1_1__) goto IL_0039;
    /* IL_002a: ldloc.1  */
    stack0_0__ = ch;
    /* IL_002b: ldc.i4.s 42 */
    stack1_1__ = 42;
    /* IL_002d: beq.s IL_0039 */
    if (stack0_0__ == stack1_1__) goto IL_0039;
    /* IL_002f: ldloc.1  */
    stack0_0__ = ch;
    /* IL_0030: ldc.i4.s 47 */
    stack1_1__ = 47;
    /* IL_0032: ceq  */
    stack0_0__ = (stack0_0__ == stack1_1__) ? 1 : 0;
    /* IL_0034: ldc.i4.0  */
    stack1_1__ = 0;
    /* IL_0035: ceq  */
    stack0_0__ = (stack0_0__ == stack1_1__) ? 1 : 0;
    /* IL_0037: br.s IL_003a */
    goto IL_003a;
IL_0039:
    /* IL_0039: ldc.i4.0  */
    stack0_0__ = 0;
IL_003a:
    /* IL_003a: stloc.s local4__ */
    local4__ = (stack0_0__) ? true : false;
    /* IL_003c: ldloc.s local4__ */
    stack0_0__ = local4__;
    /* IL_003e: brfalse.s IL_0045 */
    if (stack0_0__ == 0) goto IL_0045;
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(120): */
    /* IL_0040: nop  */
    /* IL_0041: ldnull  */
    stack0_1__ = NULL;
    /* IL_0042: stloc.3  */
    local3__ = (Calculator_OperatorNode*)stack0_1__;
    /* IL_0043: br.s IL_005b */
    goto IL_005b;
IL_0045:
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(123): */
    /* IL_0045: ldloc.0  */
    stack0_0__ = index;
    /* IL_0046: ldc.i4.1  */
    stack1_1__ = 1;
    /* IL_0047: add  */
    stack0_0__ = stack0_0__ + stack1_1__;
    /* IL_0048: stloc.0  */
    index = stack0_0__;
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(125): */
    /* IL_0049: ldarg.0  */
    stack0_2__ = line;
    /* IL_004a: ldloc.0  */
    stack1_1__ = index;
    /* IL_004b: call Calculator.PolishNotation.SkipWhiteSpace */
    stack0_0__ = Calculator_PolishNotation_SkipWhiteSpace(stack0_2__, stack1_1__);
    /* IL_0050: stloc.0  */
    index = stack0_0__;
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(126): */
    /* IL_0051: ldloc.1  */
    stack0_0__ = ch;
    /* IL_0052: ldloc.0  */
    stack1_1__ = index;
    /* IL_0053: newobj Calculator.OperatorNode..ctor */
    stack0_3__ = il2c_get_uninitialized_object(il2c_typeof(Calculator_OperatorNode));
    stack0_3__->vptr0__ = &__Calculator_OperatorNode_VTABLE__;
    Calculator_OperatorNode__ctor(stack0_3__, (wchar_t)(stack0_0__), stack1_1__);
    /* IL_0058: stloc.3  */
    local3__ = stack0_3__;
    /* IL_0059: br.s IL_005b */
    goto IL_005b;
IL_005b:
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(127): */
    /* IL_005b: ldloc.3  */
    stack0_3__ = local3__;
    /* IL_005c: ret  */
    il2c_unlink_execution_frame(&__executionFrame__);
    return stack0_3__;
}

///////////////////////////////////////
// [3] Calculator.PolishNotation.ParseNumeric(System.String line, System.Int32 startIndex)

Calculator_NumericNode* Calculator_PolishNotation_ParseNumeric(System_String* line, int32_t startIndex)
{
    //-------------------
    // Local variables:

    int32_t index;
    System_String* token = NULL;
    int32_t numeric;
    bool local3__;
    Calculator_NumericNode* local4__ = NULL;
    wchar_t ch;
    bool local6__;
    bool local7__;
    bool local8__;
    bool local9__;

    //-------------------
    // Evaluation stacks:

    int32_t stack0_0__;
    intptr_t stack0_1__;
    Calculator_NumericNode* stack0_2__ = NULL;
    System_String* stack0_3__ = NULL;
    System_String* stack1_0__ = NULL;
    int32_t stack1_1__;
    int32_t* stack1_2__ = NULL;
    int32_t stack2_0__;
    int32_t stack3_0__;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        System_String** ptoken;
        Calculator_NumericNode** plocal4__;
        Calculator_NumericNode** pstack0_2__;
        System_String** pstack0_3__;
        System_String** pstack1_0__;
        int32_t** pstack1_2__;
    } __executionFrame__;

    __executionFrame__.targetCount = 6;
    __executionFrame__.ptoken = &token;
    __executionFrame__.plocal4__ = &local4__;
    __executionFrame__.pstack0_2__ = &stack0_2__;
    __executionFrame__.pstack0_3__ = &stack0_3__;
    __executionFrame__.pstack1_0__ = &stack1_0__;
    __executionFrame__.pstack1_2__ = &stack1_2__;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(130): */
    /* IL_0000: nop  */
    /* IL_0001: ldarg.1  */
    stack0_0__ = startIndex;
    /* IL_0002: ldarg.0  */
    stack1_0__ = line;
    /* IL_0003: callvirt System.String.get_Length */
    stack1_1__ = System_String_get_Length(stack1_0__);
    /* IL_0008: clt  */
    stack0_0__ = (stack0_0__ < stack1_1__) ? 1 : 0;
    /* IL_000a: ldc.i4.0  */
    stack1_1__ = 0;
    /* IL_000b: ceq  */
    stack0_0__ = (stack0_0__ == stack1_1__) ? 1 : 0;
    /* IL_000d: stloc.3  */
    local3__ = (stack0_0__) ? true : false;
    /* IL_000e: ldloc.3  */
    stack0_0__ = local3__;
    /* IL_000f: brfalse.s IL_0017 */
    if (stack0_0__ == 0) goto IL_0017;
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(132): */
    /* IL_0011: nop  */
    /* IL_0012: ldnull  */
    stack0_1__ = NULL;
    /* IL_0013: stloc.s local4__ */
    local4__ = (Calculator_NumericNode*)stack0_1__;
    /* IL_0015: br.s IL_008d */
    goto IL_008d;
IL_0017:
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(136): */
    /* IL_0017: ldarg.1  */
    stack0_0__ = startIndex;
    /* IL_0018: stloc.0  */
    index = stack0_0__;
    /* IL_0019: br.s IL_0039 */
    goto IL_0039;
IL_001b:
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(138): */
    /* IL_001b: nop  */
    /* IL_001c: ldarg.0  */
    stack0_3__ = line;
    /* IL_001d: ldloc.0  */
    stack1_1__ = index;
    /* IL_001e: callvirt System.String.get_Chars */
    stack0_0__ = System_String_get_Chars(stack0_3__, stack1_1__);
    /* IL_0023: stloc.s ch */
    ch = (wchar_t)(stack0_0__);
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(140): */
    /* IL_0025: ldloc.s ch */
    stack0_0__ = ch;
    /* IL_0027: ldc.i4.s 32 */
    stack1_1__ = 32;
    /* IL_0029: ceq  */
    stack0_0__ = (stack0_0__ == stack1_1__) ? 1 : 0;
    /* IL_002b: stloc.s local6__ */
    local6__ = (stack0_0__) ? true : false;
    /* IL_002d: ldloc.s local6__ */
    stack0_0__ = local6__;
    /* IL_002f: brfalse.s IL_0034 */
    if (stack0_0__ == 0) goto IL_0034;
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(141): */
    /* IL_0031: nop  */
    /* IL_0032: br.s IL_0048 */
    goto IL_0048;
IL_0034:
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(144): */
    /* IL_0034: ldloc.0  */
    stack0_0__ = index;
    /* IL_0035: ldc.i4.1  */
    stack1_1__ = 1;
    /* IL_0036: add  */
    stack0_0__ = stack0_0__ + stack1_1__;
    /* IL_0037: stloc.0  */
    index = stack0_0__;
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(145): */
    /* IL_0038: nop  */
IL_0039:
    /* IL_0039: ldloc.0  */
    stack0_0__ = index;
    /* IL_003a: ldarg.0  */
    stack1_0__ = line;
    /* IL_003b: callvirt System.String.get_Length */
    stack1_1__ = System_String_get_Length(stack1_0__);
    /* IL_0040: clt  */
    stack0_0__ = (stack0_0__ < stack1_1__) ? 1 : 0;
    /* IL_0042: stloc.s local7__ */
    local7__ = (stack0_0__) ? true : false;
    /* IL_0044: ldloc.s local7__ */
    stack0_0__ = local7__;
    /* IL_0046: brtrue.s IL_001b */
    if (stack0_0__ != 0) goto IL_001b;
IL_0048:
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(147): */
    /* IL_0048: ldloc.0  */
    stack0_0__ = index;
    /* IL_0049: ldarg.1  */
    stack1_1__ = startIndex;
    /* IL_004a: ceq  */
    stack0_0__ = (stack0_0__ == stack1_1__) ? 1 : 0;
    /* IL_004c: stloc.s local8__ */
    local8__ = (stack0_0__) ? true : false;
    /* IL_004e: ldloc.s local8__ */
    stack0_0__ = local8__;
    /* IL_0050: brfalse.s IL_0058 */
    if (stack0_0__ == 0) goto IL_0058;
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(148): */
    /* IL_0052: nop  */
    /* IL_0053: ldnull  */
    stack0_1__ = NULL;
    /* IL_0054: stloc.s local4__ */
    local4__ = (Calculator_NumericNode*)stack0_1__;
    /* IL_0056: br.s IL_008d */
    goto IL_008d;
IL_0058:
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(152): */
    /* IL_0058: ldarg.0  */
    stack0_3__ = line;
    /* IL_0059: ldarg.1  */
    stack1_1__ = startIndex;
    /* IL_005a: ldloc.0  */
    stack2_0__ = index;
    /* IL_005b: ldarg.1  */
    stack3_0__ = startIndex;
    /* IL_005c: sub  */
    stack2_0__ = stack2_0__ - stack3_0__;
    /* IL_005d: callvirt System.String.Substring */
    stack0_3__ = System_String_Substring_1(stack0_3__, stack1_1__, stack2_0__);
    /* IL_0062: stloc.1  */
    token = stack0_3__;
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(153): */
    /* IL_0063: ldloc.1  */
    stack0_3__ = token;
    /* IL_0064: ldloca.s numeric */
    stack1_2__ = &numeric;
    /* IL_0066: call System.Int32.TryParse */
    stack0_0__ = System_Int32_TryParse(stack0_3__, stack1_2__);
    /* IL_006b: ldc.i4.0  */
    stack1_1__ = 0;
    /* IL_006c: ceq  */
    stack0_0__ = (stack0_0__ == stack1_1__) ? 1 : 0;
    /* IL_006e: stloc.s local9__ */
    local9__ = (stack0_0__) ? true : false;
    /* IL_0070: ldloc.s local9__ */
    stack0_0__ = local9__;
    /* IL_0072: brfalse.s IL_007a */
    if (stack0_0__ == 0) goto IL_007a;
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(154): */
    /* IL_0074: nop  */
    /* IL_0075: ldnull  */
    stack0_1__ = NULL;
    /* IL_0076: stloc.s local4__ */
    local4__ = (Calculator_NumericNode*)stack0_1__;
    /* IL_0078: br.s IL_008d */
    goto IL_008d;
IL_007a:
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(158): */
    /* IL_007a: ldarg.0  */
    stack0_3__ = line;
    /* IL_007b: ldloc.0  */
    stack1_1__ = index;
    /* IL_007c: call Calculator.PolishNotation.SkipWhiteSpace */
    stack0_0__ = Calculator_PolishNotation_SkipWhiteSpace(stack0_3__, stack1_1__);
    /* IL_0081: stloc.0  */
    index = stack0_0__;
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(159): */
    /* IL_0082: ldloc.2  */
    stack0_0__ = numeric;
    /* IL_0083: ldloc.0  */
    stack1_1__ = index;
    /* IL_0084: newobj Calculator.NumericNode..ctor */
    stack0_2__ = il2c_get_uninitialized_object(il2c_typeof(Calculator_NumericNode));
    stack0_2__->vptr0__ = &__Calculator_NumericNode_VTABLE__;
    Calculator_NumericNode__ctor(stack0_2__, stack0_0__, stack1_1__);
    /* IL_0089: stloc.s local4__ */
    local4__ = stack0_2__;
    /* IL_008b: br.s IL_008d */
    goto IL_008d;
IL_008d:
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(160): */
    /* IL_008d: ldloc.s local4__ */
    stack0_2__ = local4__;
    /* IL_008f: ret  */
    il2c_unlink_execution_frame(&__executionFrame__);
    return stack0_2__;
}

///////////////////////////////////////
// [3] Calculator.PolishNotation.ParseExpression(System.String line, System.Int32 startIndex)

Calculator_ExpressionNode* Calculator_PolishNotation_ParseExpression(System_String* line, int32_t startIndex)
{
    //-------------------
    // Local variables:

    Calculator_OperatorNode* oper = NULL;
    Calculator_ReducibleNode* left = NULL;
    Calculator_ReducibleNode* right = NULL;
    int32_t index;
    bool local4__;
    Calculator_ExpressionNode* local5__ = NULL;
    bool local6__;
    bool local7__;
    bool local8__;
    bool local9__;
    bool local10__;

    //-------------------
    // Evaluation stacks:

    int32_t stack0_0__;
    intptr_t stack0_1__;
    System_String* stack0_2__ = NULL;
    Calculator_OperatorNode* stack0_3__ = NULL;
    Calculator_ExpressionNode* stack0_4__ = NULL;
    Calculator_NumericNode* stack0_5__ = NULL;
    Calculator_ReducibleNode* stack0_6__ = NULL;
    System_String* stack1_0__ = NULL;
    int32_t stack1_1__;
    intptr_t stack1_2__;
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
        Calculator_OperatorNode** poper;
        Calculator_ReducibleNode** pleft;
        Calculator_ReducibleNode** pright;
        Calculator_ExpressionNode** plocal5__;
        System_String** pstack0_2__;
        Calculator_OperatorNode** pstack0_3__;
        Calculator_ExpressionNode** pstack0_4__;
        Calculator_NumericNode** pstack0_5__;
        Calculator_ReducibleNode** pstack0_6__;
        System_String** pstack1_0__;
        Calculator_OperatorNode** pstack1_3__;
        Calculator_ReducibleNode** pstack1_4__;
        Calculator_ReducibleNode** pstack2_0__;
    } __executionFrame__;

    __executionFrame__.targetCount = 13;
    __executionFrame__.poper = &oper;
    __executionFrame__.pleft = &left;
    __executionFrame__.pright = &right;
    __executionFrame__.plocal5__ = &local5__;
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
    /* IL_0000: nop  */
    /* IL_0001: ldarg.1  */
    stack0_0__ = startIndex;
    /* IL_0002: ldarg.0  */
    stack1_0__ = line;
    /* IL_0003: callvirt System.String.get_Length */
    stack1_1__ = System_String_get_Length(stack1_0__);
    /* IL_0008: clt  */
    stack0_0__ = (stack0_0__ < stack1_1__) ? 1 : 0;
    /* IL_000a: ldc.i4.0  */
    stack1_1__ = 0;
    /* IL_000b: ceq  */
    stack0_0__ = (stack0_0__ == stack1_1__) ? 1 : 0;
    /* IL_000d: stloc.s local4__ */
    local4__ = (stack0_0__) ? true : false;
    /* IL_000f: ldloc.s local4__ */
    stack0_0__ = local4__;
    /* IL_0011: brfalse.s IL_001c */
    if (stack0_0__ == 0) goto IL_001c;
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(165): */
    /* IL_0013: nop  */
    /* IL_0014: ldnull  */
    stack0_1__ = NULL;
    /* IL_0015: stloc.s local5__ */
    local5__ = (Calculator_ExpressionNode*)stack0_1__;
    /* IL_0017: br IL_00bd */
    goto IL_00bd;
IL_001c:
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(169): */
    /* IL_001c: ldarg.0  */
    stack0_2__ = line;
    /* IL_001d: ldarg.1  */
    stack1_1__ = startIndex;
    /* IL_001e: call Calculator.PolishNotation.ParseOperator */
    stack0_3__ = Calculator_PolishNotation_ParseOperator(stack0_2__, stack1_1__);
    /* IL_0023: stloc.0  */
    oper = stack0_3__;
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(170): */
    /* IL_0024: ldloc.0  */
    stack0_3__ = oper;
    /* IL_0025: ldnull  */
    stack1_2__ = NULL;
    /* IL_0026: ceq  */
    stack0_0__ = (stack0_3__ == ((Calculator_OperatorNode*)stack1_2__)) ? 1 : 0;
    /* IL_0028: stloc.s local6__ */
    local6__ = (stack0_0__) ? true : false;
    /* IL_002a: ldloc.s local6__ */
    stack0_0__ = local6__;
    /* IL_002c: brfalse.s IL_0037 */
    if (stack0_0__ == 0) goto IL_0037;
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(171): */
    /* IL_002e: nop  */
    /* IL_002f: ldnull  */
    stack0_1__ = NULL;
    /* IL_0030: stloc.s local5__ */
    local5__ = (Calculator_ExpressionNode*)stack0_1__;
    /* IL_0032: br IL_00bd */
    goto IL_00bd;
IL_0037:
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(175): */
    /* IL_0037: ldarg.0  */
    stack0_2__ = line;
    /* IL_0038: ldloc.0  */
    stack1_3__ = oper;
    /* IL_0039: ldfld Calculator.AbstractNode.NextIndex */
    stack1_1__ = stack1_3__->NextIndex;
    /* IL_003e: call Calculator.PolishNotation.ParseNumeric */
    stack0_5__ = Calculator_PolishNotation_ParseNumeric(stack0_2__, stack1_1__);
    /* IL_0043: stloc.1  */
    left = (Calculator_ReducibleNode*)stack0_5__;
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(176): */
    /* IL_0044: ldloc.1  */
    stack0_6__ = left;
    /* IL_0045: ldnull  */
    stack1_2__ = NULL;
    /* IL_0046: ceq  */
    stack0_0__ = (stack0_6__ == ((Calculator_ReducibleNode*)stack1_2__)) ? 1 : 0;
    /* IL_0048: stloc.s local7__ */
    local7__ = (stack0_0__) ? true : false;
    /* IL_004a: ldloc.s local7__ */
    stack0_0__ = local7__;
    /* IL_004c: brfalse.s IL_006d */
    if (stack0_0__ == 0) goto IL_006d;
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(177): */
    /* IL_004e: nop  */
    /* IL_004f: ldarg.0  */
    stack0_2__ = line;
    /* IL_0050: ldloc.0  */
    stack1_3__ = oper;
    /* IL_0051: ldfld Calculator.AbstractNode.NextIndex */
    stack1_1__ = stack1_3__->NextIndex;
    /* IL_0056: call Calculator.PolishNotation.ParseExpression */
    stack0_4__ = Calculator_PolishNotation_ParseExpression(stack0_2__, stack1_1__);
    /* IL_005b: stloc.1  */
    left = (Calculator_ReducibleNode*)stack0_4__;
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(179): */
    /* IL_005c: ldloc.1  */
    stack0_6__ = left;
    /* IL_005d: ldnull  */
    stack1_2__ = NULL;
    /* IL_005e: ceq  */
    stack0_0__ = (stack0_6__ == ((Calculator_ReducibleNode*)stack1_2__)) ? 1 : 0;
    /* IL_0060: stloc.s local8__ */
    local8__ = (stack0_0__) ? true : false;
    /* IL_0062: ldloc.s local8__ */
    stack0_0__ = local8__;
    /* IL_0064: brfalse.s IL_006c */
    if (stack0_0__ == 0) goto IL_006c;
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(180): */
    /* IL_0066: nop  */
    /* IL_0067: ldnull  */
    stack0_1__ = NULL;
    /* IL_0068: stloc.s local5__ */
    local5__ = (Calculator_ExpressionNode*)stack0_1__;
    /* IL_006a: br.s IL_00bd */
    goto IL_00bd;
IL_006c:
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(183): */
    /* IL_006c: nop  */
IL_006d:
    /* IL_006d: ldarg.0  */
    stack0_2__ = line;
    /* IL_006e: ldloc.1  */
    stack1_4__ = left;
    /* IL_006f: ldfld Calculator.AbstractNode.NextIndex */
    stack1_1__ = stack1_4__->NextIndex;
    /* IL_0074: call Calculator.PolishNotation.ParseNumeric */
    stack0_5__ = Calculator_PolishNotation_ParseNumeric(stack0_2__, stack1_1__);
    /* IL_0079: stloc.2  */
    right = (Calculator_ReducibleNode*)stack0_5__;
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(186): */
    /* IL_007a: ldloc.2  */
    stack0_6__ = right;
    /* IL_007b: ldnull  */
    stack1_2__ = NULL;
    /* IL_007c: ceq  */
    stack0_0__ = (stack0_6__ == ((Calculator_ReducibleNode*)stack1_2__)) ? 1 : 0;
    /* IL_007e: stloc.s local9__ */
    local9__ = (stack0_0__) ? true : false;
    /* IL_0080: ldloc.s local9__ */
    stack0_0__ = local9__;
    /* IL_0082: brfalse.s IL_00a3 */
    if (stack0_0__ == 0) goto IL_00a3;
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(187): */
    /* IL_0084: nop  */
    /* IL_0085: ldarg.0  */
    stack0_2__ = line;
    /* IL_0086: ldloc.1  */
    stack1_4__ = left;
    /* IL_0087: ldfld Calculator.AbstractNode.NextIndex */
    stack1_1__ = stack1_4__->NextIndex;
    /* IL_008c: call Calculator.PolishNotation.ParseExpression */
    stack0_4__ = Calculator_PolishNotation_ParseExpression(stack0_2__, stack1_1__);
    /* IL_0091: stloc.2  */
    right = (Calculator_ReducibleNode*)stack0_4__;
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(189): */
    /* IL_0092: ldloc.2  */
    stack0_6__ = right;
    /* IL_0093: ldnull  */
    stack1_2__ = NULL;
    /* IL_0094: ceq  */
    stack0_0__ = (stack0_6__ == ((Calculator_ReducibleNode*)stack1_2__)) ? 1 : 0;
    /* IL_0096: stloc.s local10__ */
    local10__ = (stack0_0__) ? true : false;
    /* IL_0098: ldloc.s local10__ */
    stack0_0__ = local10__;
    /* IL_009a: brfalse.s IL_00a2 */
    if (stack0_0__ == 0) goto IL_00a2;
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(190): */
    /* IL_009c: nop  */
    /* IL_009d: ldnull  */
    stack0_1__ = NULL;
    /* IL_009e: stloc.s local5__ */
    local5__ = (Calculator_ExpressionNode*)stack0_1__;
    /* IL_00a0: br.s IL_00bd */
    goto IL_00bd;
IL_00a2:
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(193): */
    /* IL_00a2: nop  */
IL_00a3:
    /* IL_00a3: ldarg.0  */
    stack0_2__ = line;
    /* IL_00a4: ldloc.2  */
    stack1_4__ = right;
    /* IL_00a5: ldfld Calculator.AbstractNode.NextIndex */
    stack1_1__ = stack1_4__->NextIndex;
    /* IL_00aa: call Calculator.PolishNotation.SkipWhiteSpace */
    stack0_0__ = Calculator_PolishNotation_SkipWhiteSpace(stack0_2__, stack1_1__);
    /* IL_00af: stloc.3  */
    index = stack0_0__;
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(196): */
    /* IL_00b0: ldloc.0  */
    stack0_3__ = oper;
    /* IL_00b1: ldloc.1  */
    stack1_4__ = left;
    /* IL_00b2: ldloc.2  */
    stack2_0__ = right;
    /* IL_00b3: ldloc.3  */
    stack3_0__ = index;
    /* IL_00b4: newobj Calculator.ExpressionNode..ctor */
    stack0_4__ = il2c_get_uninitialized_object(il2c_typeof(Calculator_ExpressionNode));
    stack0_4__->vptr0__ = &__Calculator_ExpressionNode_VTABLE__;
    Calculator_ExpressionNode__ctor(stack0_4__, stack0_3__, stack1_4__, stack2_0__, stack3_0__);
    /* IL_00b9: stloc.s local5__ */
    local5__ = stack0_4__;
    /* IL_00bb: br.s IL_00bd */
    goto IL_00bd;
IL_00bd:
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(197): */
    /* IL_00bd: ldloc.s local5__ */
    stack0_4__ = local5__;
    /* IL_00bf: ret  */
    il2c_unlink_execution_frame(&__executionFrame__);
    return stack0_4__;
}

///////////////////////////////////////
// [6] P/Invoke: Calculator.PolishNotation.SendExternalTicker(System.String message)

void Calculator_PolishNotation_SendExternalTicker(System_String* message)
{
    SendExternalTicker(message->string_body__);
}

///////////////////////////////////////
// [3] Calculator.PolishNotation.Main()

void Calculator_PolishNotation_Main()
{
    //-------------------
    // Local variables:

    System_String* line = NULL;
    bool local1__;
    Calculator_ExpressionNode* expr = NULL;
    int32_t result;
    System_String* message = NULL;
    bool local5__;
    bool local6__;
    bool local7__;

    //-------------------
    // Evaluation stacks:

    System_String* stack0_0__ = NULL;
    int32_t stack0_1__;
    Calculator_ExpressionNode* stack0_2__ = NULL;
    int32_t stack1_0__;
    System_String* stack1_1__ = NULL;
    intptr_t stack1_2__;
    int32_t* stack1_3__ = NULL;

    //-------------------
    // Setup stack frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext;
        uint8_t targetCount;
        System_String** pline;
        Calculator_ExpressionNode** pexpr;
        System_String** pmessage;
        System_String** pstack0_0__;
        Calculator_ExpressionNode** pstack0_2__;
        System_String** pstack1_1__;
        int32_t** pstack1_3__;
    } __executionFrame__;

    __executionFrame__.targetCount = 7;
    __executionFrame__.pline = &line;
    __executionFrame__.pexpr = &expr;
    __executionFrame__.pmessage = &message;
    __executionFrame__.pstack0_0__ = &stack0_0__;
    __executionFrame__.pstack0_2__ = &stack0_2__;
    __executionFrame__.pstack1_1__ = &stack1_1__;
    __executionFrame__.pstack1_3__ = &stack1_3__;
    il2c_link_execution_frame(&__executionFrame__);

    //-------------------
    // IL body:

/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(203): */
    /* IL_0000: nop  */
    /* IL_0001: ldstr "Polish notation calculator." */
    stack0_0__ = string0__;
    /* IL_0006: call System.Console.WriteLine */
    System_Console_WriteLine_10(stack0_0__);
    /* IL_000b: nop  */
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(205): */
    /* IL_000c: ldstr "This is proof of concept for IL2C." */
    stack0_0__ = string1__;
    /* IL_0011: call System.Console.WriteLine */
    System_Console_WriteLine_10(stack0_0__);
    /* IL_0016: nop  */
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(206): */
    /* IL_0017: ldstr "https://github.com/kekyo/IL2C" */
    stack0_0__ = string2__;
    /* IL_001c: call System.Console.WriteLine */
    System_Console_WriteLine_10(stack0_0__);
    /* IL_0021: nop  */
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(207): */
    /* IL_0022: call System.Console.WriteLine */
    System_Console_WriteLine();
    /* IL_0027: nop  */
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(208): */
    /* IL_0028: ldstr "Type "exit" to exit." */
    stack0_0__ = string3__;
    /* IL_002d: call System.Console.WriteLine */
    System_Console_WriteLine_10(stack0_0__);
    /* IL_0032: nop  */
    /* IL_0033: br IL_00e7 */
    goto IL_00e7;
IL_0038:
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(211): */
    /* IL_0038: nop  */
    /* IL_0039: call System.Console.WriteLine */
    System_Console_WriteLine();
    /* IL_003e: nop  */
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(213): */
    /* IL_003f: ldstr "PN> " */
    stack0_0__ = string4__;
    /* IL_0044: call System.Console.Write */
    System_Console_Write_9(stack0_0__);
    /* IL_0049: nop  */
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(214): */
    /* IL_004a: call System.Console.ReadLine */
    stack0_0__ = System_Console_ReadLine();
    /* IL_004f: stloc.0  */
    line = stack0_0__;
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(215): */
    /* IL_0050: ldloc.0  */
    stack0_0__ = line;
    /* IL_0051: call System.String.IsNullOrWhiteSpace */
    stack0_1__ = System_String_IsNullOrWhiteSpace(stack0_0__);
    /* IL_0056: ldc.i4.0  */
    stack1_0__ = 0;
    /* IL_0057: ceq  */
    stack0_1__ = (stack0_1__ == stack1_0__) ? 1 : 0;
    /* IL_0059: stloc.1  */
    local1__ = (stack0_1__) ? true : false;
    /* IL_005a: ldloc.1  */
    stack0_1__ = local1__;
    /* IL_005b: brfalse IL_00e6 */
    if (stack0_1__ == 0) goto IL_00e6;
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(216): */
    /* IL_0060: nop  */
    /* IL_0061: ldloc.0  */
    stack0_0__ = line;
    /* IL_0062: ldstr "exit" */
    stack1_1__ = string5__;
    /* IL_0067: call System.String.op_Equality */
    stack0_1__ = System_String_op_Equality(stack0_0__, stack1_1__);
    /* IL_006c: stloc.s local5__ */
    local5__ = (stack0_1__) ? true : false;
    /* IL_006e: ldloc.s local5__ */
    stack0_1__ = local5__;
    /* IL_0070: brfalse.s IL_0075 */
    if (stack0_1__ == 0) goto IL_0075;
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(218): */
    /* IL_0072: nop  */
    /* IL_0073: br.s IL_00ef */
    goto IL_00ef;
IL_0075:
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(222): */
    /* IL_0075: ldloc.0  */
    stack0_0__ = line;
    /* IL_0076: ldc.i4.0  */
    stack1_0__ = 0;
    /* IL_0077: call Calculator.PolishNotation.ParseExpression */
    stack0_2__ = Calculator_PolishNotation_ParseExpression(stack0_0__, stack1_0__);
    /* IL_007c: stloc.2  */
    expr = stack0_2__;
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(223): */
    /* IL_007d: ldloc.2  */
    stack0_2__ = expr;
    /* IL_007e: ldnull  */
    stack1_2__ = NULL;
    /* IL_007f: ceq  */
    stack0_1__ = (stack0_2__ == ((Calculator_ExpressionNode*)stack1_2__)) ? 1 : 0;
    /* IL_0081: stloc.s local6__ */
    local6__ = (stack0_1__) ? true : false;
    /* IL_0083: ldloc.s local6__ */
    stack0_1__ = local6__;
    /* IL_0085: brfalse.s IL_0095 */
    if (stack0_1__ == 0) goto IL_0095;
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(224): */
    /* IL_0087: nop  */
    /* IL_0088: ldstr "Syntax error." */
    stack0_0__ = string6__;
    /* IL_008d: call System.Console.WriteLine */
    System_Console_WriteLine_10(stack0_0__);
    /* IL_0092: nop  */
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(226): */
    /* IL_0093: br.s IL_00e7 */
    goto IL_00e7;
IL_0095:
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(229): */
    /* IL_0095: ldloc.2  */
    stack0_2__ = expr;
    /* IL_0096: callvirt Calculator.ReducibleNode.Reduce */
    stack0_1__ = Calculator_ReducibleNode_Reduce((Calculator_ReducibleNode*)stack0_2__);
    /* IL_009b: stloc.3  */
    result = stack0_1__;
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(231): */
    /* IL_009c: ldstr "Reuslt=" */
    stack0_0__ = string7__;
    /* IL_00a1: call System.Console.Write */
    System_Console_Write_9(stack0_0__);
    /* IL_00a6: nop  */
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(232): */
    /* IL_00a7: ldloc.3  */
    stack0_1__ = result;
    /* IL_00a8: call System.Console.WriteLine */
    System_Console_WriteLine_6(stack0_1__);
    /* IL_00ad: nop  */
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(234): */
    /* IL_00ae: ldstr "(" */
    stack0_0__ = string8__;
    /* IL_00b3: stloc.s message */
    message = stack0_0__;
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(235): */
    /* IL_00b5: ldloc.s message */
    stack0_0__ = message;
    /* IL_00b7: ldloc.0  */
    stack1_1__ = line;
    /* IL_00b8: call System.String.Concat */
    stack0_0__ = System_String_Concat_6(stack0_0__, stack1_1__);
    /* IL_00bd: stloc.s message */
    message = stack0_0__;
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(236): */
    /* IL_00bf: ldloc.s message */
    stack0_0__ = message;
    /* IL_00c1: ldstr ") = " */
    stack1_1__ = string9__;
    /* IL_00c6: call System.String.Concat */
    stack0_0__ = System_String_Concat_6(stack0_0__, stack1_1__);
    /* IL_00cb: stloc.s message */
    message = stack0_0__;
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(237): */
    /* IL_00cd: ldloc.s message */
    stack0_0__ = message;
    /* IL_00cf: ldloca.s result */
    stack1_3__ = &result;
    /* IL_00d1: call System.Int32.ToString */
    stack1_1__ = System_Int32_ToString((int32_t)(stack1_3__));
    /* IL_00d6: call System.String.Concat */
    stack0_0__ = System_String_Concat_6(stack0_0__, stack1_1__);
    /* IL_00db: stloc.s message */
    message = stack0_0__;
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(238): */
    /* IL_00dd: ldloc.s message */
    stack0_0__ = message;
    /* IL_00df: call Calculator.PolishNotation.SendExternalTicker */
    Calculator_PolishNotation_SendExternalTicker(stack0_0__);
    /* IL_00e4: nop  */
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(239): */
    /* IL_00e5: nop  */
IL_00e6:
    /* IL_00e6: nop  */
IL_00e7:
    /* IL_00e7: ldc.i4.1  */
    stack0_1__ = 1;
    /* IL_00e8: stloc.s local7__ */
    local7__ = (stack0_1__) ? true : false;
    /* IL_00ea: br IL_0038 */
    goto IL_0038;
IL_00ef:
/* D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Code\\PolishNotation.cs(241): */
    /* IL_00ef: ret  */
    il2c_unlink_execution_frame(&__executionFrame__);
    return;
}

///////////////////////////////////////
// [3] Calculator.PolishNotation..ctor(Calculator.PolishNotation this__)

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

    /* IL_0000: ldarg.0  */
    stack0_0__ = this__;
    /* IL_0001: call System.Object..ctor */
    /* IL_0006: nop  */
    /* IL_0007: ret  */
    il2c_unlink_execution_frame(&__executionFrame__);
    return;
}

//////////////////////
// [7] Runtime helpers:

// [7-1] Runtime cast
void* __Calculator_PolishNotation_IL2C_RuntimeCast__(Calculator_PolishNotation* this__, IL2C_RUNTIME_TYPE_DECL* type)
{
    // [7-2] This type
    if (type == il2c_typeof(Calculator_PolishNotation)) return this__;

    // [7-4] Delegate checking base types
    return __System_Object_IL2C_RuntimeCast__((System_Object*)this__, type);
}

// [7-5] GC's mark handler
void __Calculator_PolishNotation_IL2C_MarkHandler__(Calculator_PolishNotation* this__)
{

    // [7-7] Delegate checking base types
    __System_Object_IL2C_MarkHandler__((System_Object*)this__);
}

// [7-8] Runtime type information
IL2C_RUNTIME_TYPE_DECL __Calculator_PolishNotation_RUNTIME_TYPE__ = {
    "Calculator.PolishNotation",
    sizeof(Calculator_PolishNotation),
    /* internalcall */ (IL2C_MARK_HANDLER)__Calculator_PolishNotation_IL2C_MarkHandler__,
};

//////////////////////
// [7-9] VTables:

// [7-10] Vtable of Calculator.PolishNotation
__Calculator_PolishNotation_VTABLE_DECL__ __Calculator_PolishNotation_VTABLE__ = {
    __System_Object_ToString__,
    __System_Object_GetHashCode__,
    __System_Object_GetType__,
    __System_Object_Finalize__,
    __System_Object_MemberwiseClone__,
    __System_Object_Equals__,
    __System_Object_GetFieldInfo__,
    __System_Object_FieldSetter__,
    __System_Object_FieldGetter__,
};
