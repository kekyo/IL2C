// [15-2] This is Calculator.Core native code translated by IL2C, do not edit.

#include <Calculator.Core.h>
#include <Calculator.Core_internal.h>

#include <mscorlib.h>

#ifdef __cplusplus
extern "C" {
#endif

//////////////////////////////////////////////////////////////////////////////////
// [9-1] Type: Calculator.ExpressionNode

//////////////////////////////////////////////////////////////////////////////////
// [9-2] File scope prototypes:

//////////////////////////////////////////////////////////////////////////////////
// [9-4] Type: Calculator.ExpressionNode

///////////////////////////////////////
// [3] Calculator.ExpressionNode..ctor(Calculator.ExpressionNode this__, Calculator.OperatorNode oper, Calculator.ReducibleNode left, Calculator.ReducibleNode right, System.Int32 nextIndex)

//-------------------
// [3-7] Declare execution frame:

typedef struct Calculator_ExpressionNode__ctor_EXECUTION_FRAME_DECL
{
    const IL2C_EXECUTION_FRAME* pNext__;
    const uint16_t objRefCount__;
    const uint16_t valueCount__;
    //-------------------- objref
    Calculator_ExpressionNode* stack0_0__;
    Calculator_OperatorNode* stack1_1__;
    Calculator_ReducibleNode* stack1_2__;
} Calculator_ExpressionNode__ctor_EXECUTION_FRAME__;

//-------------------
// [3-2] Function body:

void Calculator_ExpressionNode__ctor(Calculator_ExpressionNode* this__, Calculator_OperatorNode* oper, Calculator_ReducibleNode* left, Calculator_ReducibleNode* right, int32_t nextIndex)
{
#line 59 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    il2c_assert(this__ != NULL);

    //-------------------
    // [3-4] Evaluation stacks (!objref):

#line 59 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    int32_t stack1_0__;

    //-------------------
    // [3-5] Setup execution frame:

#line 59 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    Calculator_ExpressionNode__ctor_EXECUTION_FRAME__ frame__ =
        { NULL, 3 };
#line 59 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    il2c_link_execution_frame(&frame__);

    //-------------------
    // [3-6] IL body:

    /* IL_0000: ldarg.0  */
#line 59 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    frame__.stack0_0__ = this__;
    /* IL_0001: ldarg.s nextIndex */
#line 59 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack1_0__ = nextIndex;
    /* IL_0003: call Calculator.ReducibleNode..ctor */
#line 59 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    Calculator_ReducibleNode__ctor((Calculator_ReducibleNode*)frame__.stack0_0__, stack1_0__);
    /* IL_0008: ldarg.0  */
#line 61 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    frame__.stack0_0__ = this__;
    /* IL_0009: ldarg.1  */
#line 61 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    frame__.stack1_1__ = oper;
    /* IL_000a: stfld Calculator.ExpressionNode.Operator */
#line 61 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    frame__.stack0_0__->Operator = frame__.stack1_1__;
    /* IL_000f: ldarg.0  */
#line 62 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    frame__.stack0_0__ = this__;
    /* IL_0010: ldarg.2  */
#line 62 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    frame__.stack1_2__ = left;
    /* IL_0011: stfld Calculator.ExpressionNode.Left */
#line 62 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    frame__.stack0_0__->Left = frame__.stack1_2__;
    /* IL_0016: ldarg.0  */
#line 63 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    frame__.stack0_0__ = this__;
    /* IL_0017: ldarg.3  */
#line 63 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    frame__.stack1_2__ = right;
    /* IL_0018: stfld Calculator.ExpressionNode.Right */
#line 63 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    frame__.stack0_0__->Right = frame__.stack1_2__;
    /* IL_001d: ret  */
#line 64 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    il2c_return_unlink(&frame__);
#line 64 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
}

///////////////////////////////////////
// [3] Virtual: Calculator.ExpressionNode.Reduce(Calculator.ExpressionNode this__)

//-------------------
// [3-7] Declare execution frame:

typedef struct Calculator_ExpressionNode_Reduce_EXECUTION_FRAME_DECL
{
    const IL2C_EXECUTION_FRAME* pNext__;
    const uint16_t objRefCount__;
    const uint16_t valueCount__;
    //-------------------- objref
    Calculator_ExpressionNode* stack0_0__;
    Calculator_ReducibleNode* stack0_1__;
    Calculator_OperatorNode* stack0_3__;
} Calculator_ExpressionNode_Reduce_EXECUTION_FRAME__;

//-------------------
// [3-2] Function body:

int32_t Calculator_ExpressionNode_Reduce(Calculator_ExpressionNode* this__)
{
#line 68 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    il2c_assert(this__ != NULL);

    //-------------------
    // [3-3] Local variables (!objref):

#line 68 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    int32_t leftResult = 0;
#line 68 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    int32_t rightResult = 0;

    //-------------------
    // [3-4] Evaluation stacks (!objref):

#line 68 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    int32_t stack0_2__;
#line 68 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    wchar_t stack0_4__;
#line 68 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    int32_t stack1_0__;

    //-------------------
    // [3-5] Setup execution frame:

#line 68 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    Calculator_ExpressionNode_Reduce_EXECUTION_FRAME__ frame__ =
        { NULL, 3 };
#line 68 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    il2c_link_execution_frame(&frame__);

    //-------------------
    // [3-6] IL body:

    /* IL_0000: ldarg.0  */
#line 68 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    frame__.stack0_0__ = this__;
    /* IL_0001: ldfld Calculator.ExpressionNode.Left */
#line 68 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    frame__.stack0_1__ = frame__.stack0_0__->Left;
    /* IL_0006: callvirt Calculator.ReducibleNode.Reduce */
#line 68 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack0_2__ = frame__.stack0_1__->vptr0__->Reduce(frame__.stack0_1__);
    /* IL_000b: stloc.0  */
#line 68 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    leftResult = stack0_2__;
    /* IL_000c: ldarg.0  */
#line 69 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    frame__.stack0_0__ = this__;
    /* IL_000d: ldfld Calculator.ExpressionNode.Right */
#line 69 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    frame__.stack0_1__ = frame__.stack0_0__->Right;
    /* IL_0012: callvirt Calculator.ReducibleNode.Reduce */
#line 69 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack0_2__ = frame__.stack0_1__->vptr0__->Reduce(frame__.stack0_1__);
    /* IL_0017: stloc.1  */
#line 69 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    rightResult = stack0_2__;
    /* IL_0018: ldarg.0  */
#line 70 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    frame__.stack0_0__ = this__;
    /* IL_0019: ldfld Calculator.ExpressionNode.Operator */
#line 70 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    frame__.stack0_3__ = frame__.stack0_0__->Operator;
    /* IL_001e: ldfld Calculator.OperatorNode.Operator */
#line 70 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack0_4__ = frame__.stack0_3__->Operator;
    /* IL_0023: ldc.i4.s 43 */
#line 70 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack1_0__ = 43;
    /* IL_0025: bne.un.s IL_002b */
#line 70 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    if (stack0_4__ != stack1_0__) goto IL_002b;
    /* IL_0027: ldloc.0  */
#line 72 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack0_2__ = leftResult;
    /* IL_0028: ldloc.1  */
#line 72 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack1_0__ = rightResult;
    /* IL_0029: add  */
#line 72 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack0_2__ = stack0_2__ + stack1_0__;
    /* IL_002a: ret  */
#line 72 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    il2c_return_unlink_with_value(&frame__, stack0_2__);
IL_002b:
    /* IL_002b: ldarg.0  */
#line 74 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    frame__.stack0_0__ = this__;
    /* IL_002c: ldfld Calculator.ExpressionNode.Operator */
#line 74 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    frame__.stack0_3__ = frame__.stack0_0__->Operator;
    /* IL_0031: ldfld Calculator.OperatorNode.Operator */
#line 74 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack0_4__ = frame__.stack0_3__->Operator;
    /* IL_0036: ldc.i4.s 45 */
#line 74 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack1_0__ = 45;
    /* IL_0038: bne.un.s IL_003e */
#line 74 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    if (stack0_4__ != stack1_0__) goto IL_003e;
    /* IL_003a: ldloc.0  */
#line 76 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack0_2__ = leftResult;
    /* IL_003b: ldloc.1  */
#line 76 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack1_0__ = rightResult;
    /* IL_003c: sub  */
#line 76 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack0_2__ = stack0_2__ - stack1_0__;
    /* IL_003d: ret  */
#line 76 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    il2c_return_unlink_with_value(&frame__, stack0_2__);
IL_003e:
    /* IL_003e: ldarg.0  */
#line 78 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    frame__.stack0_0__ = this__;
    /* IL_003f: ldfld Calculator.ExpressionNode.Operator */
#line 78 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    frame__.stack0_3__ = frame__.stack0_0__->Operator;
    /* IL_0044: ldfld Calculator.OperatorNode.Operator */
#line 78 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack0_4__ = frame__.stack0_3__->Operator;
    /* IL_0049: ldc.i4.s 42 */
#line 78 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack1_0__ = 42;
    /* IL_004b: bne.un.s IL_0051 */
#line 78 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    if (stack0_4__ != stack1_0__) goto IL_0051;
    /* IL_004d: ldloc.0  */
#line 80 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack0_2__ = leftResult;
    /* IL_004e: ldloc.1  */
#line 80 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack1_0__ = rightResult;
    /* IL_004f: mul  */
#line 80 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack0_2__ = stack0_2__ * stack1_0__;
    /* IL_0050: ret  */
#line 80 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    il2c_return_unlink_with_value(&frame__, stack0_2__);
IL_0051:
    /* IL_0051: ldarg.0  */
#line 82 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    frame__.stack0_0__ = this__;
    /* IL_0052: ldfld Calculator.ExpressionNode.Operator */
#line 82 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    frame__.stack0_3__ = frame__.stack0_0__->Operator;
    /* IL_0057: ldfld Calculator.OperatorNode.Operator */
#line 82 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack0_4__ = frame__.stack0_3__->Operator;
    /* IL_005c: ldc.i4.s 47 */
#line 82 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack1_0__ = 47;
    /* IL_005e: bne.un.s IL_0064 */
#line 82 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    if (stack0_4__ != stack1_0__) goto IL_0064;
    /* IL_0060: ldloc.0  */
#line 84 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack0_2__ = leftResult;
    /* IL_0061: ldloc.1  */
#line 84 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack1_0__ = rightResult;
    /* IL_0062: div  */
#line 84 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack0_2__ = stack0_2__ / stack1_0__;
    /* IL_0063: ret  */
#line 84 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    il2c_return_unlink_with_value(&frame__, stack0_2__);
IL_0064:
    /* IL_0064: ldc.i4.0  */
#line 88 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack0_2__ = 0;
    /* IL_0065: ret  */
#line 88 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    il2c_return_unlink_with_value(&frame__, stack0_2__);
#line 88 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
}

//////////////////////
// [7] Runtime helpers:

// [7-10-2] VTable
Calculator_ExpressionNode_VTABLE_DECL__ Calculator_ExpressionNode_VTABLE__ = {
    0, // Adjustor offset
    (bool (*)(void*, System_Object*))System_Object_Equals,
    (void (*)(void*))System_Object_Finalize,
    (int32_t (*)(void*))System_Object_GetHashCode,
    (System_String* (*)(void*))System_Object_ToString,
    (int32_t (*)(void*))Calculator_ExpressionNode_Reduce,
};

// [7-8] Runtime type information
IL2C_RUNTIME_TYPE_BEGIN(Calculator_ExpressionNode, "Calculator.ExpressionNode", IL2C_TYPE_REFERENCE, sizeof(Calculator_ExpressionNode), Calculator_ReducibleNode, 3, 0)
    IL2C_RUNTIME_TYPE_MARK_TARGET_FOR_REFERENCE(Calculator_ExpressionNode, Operator)
    IL2C_RUNTIME_TYPE_MARK_TARGET_FOR_REFERENCE(Calculator_ExpressionNode, Left)
    IL2C_RUNTIME_TYPE_MARK_TARGET_FOR_REFERENCE(Calculator_ExpressionNode, Right)
IL2C_RUNTIME_TYPE_END();

#ifdef __cplusplus
}
#endif
