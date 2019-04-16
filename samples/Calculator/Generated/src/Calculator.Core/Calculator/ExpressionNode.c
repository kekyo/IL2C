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
    il2c_assert(this__ != NULL);

    //-------------------
    // [3-4] Evaluation stacks (!objref):

    int32_t stack1_0__;

    //-------------------
    // [3-5] Setup execution frame:

    Calculator_ExpressionNode__ctor_EXECUTION_FRAME__ frame__ =
        { NULL, 3 };
    il2c_link_execution_frame(&frame__);

    //-------------------
    // [3-6] IL body:

    /* IL_0000: ldarg.0                         : PolishNotation.cs(59) */
    frame__.stack0_0__ = this__;
    /* IL_0001: ldarg.s nextIndex               : PolishNotation.cs(59) */
    stack1_0__ = nextIndex;
    /* IL_0003: call Calculator.ReducibleNode..ctor : PolishNotation.cs(59) */
    Calculator_ReducibleNode__ctor((Calculator_ReducibleNode*)frame__.stack0_0__, stack1_0__);
    /* IL_0008: nop                             : PolishNotation.cs(59) */
    /* IL_0009: nop  */
    /* IL_000a: ldarg.0  */
    frame__.stack0_0__ = this__;
    /* IL_000b: ldarg.1                         : PolishNotation.cs(61) */
    frame__.stack1_1__ = oper;
    /* IL_000c: stfld Calculator.ExpressionNode.Operator : PolishNotation.cs(61) */
    frame__.stack0_0__->Operator = frame__.stack1_1__;
    /* IL_0011: ldarg.0                         : PolishNotation.cs(62) */
    frame__.stack0_0__ = this__;
    /* IL_0012: ldarg.2                         : PolishNotation.cs(62) */
    frame__.stack1_2__ = left;
    /* IL_0013: stfld Calculator.ExpressionNode.Left : PolishNotation.cs(62) */
    frame__.stack0_0__->Left = frame__.stack1_2__;
    /* IL_0018: ldarg.0                         : PolishNotation.cs(63) */
    frame__.stack0_0__ = this__;
    /* IL_0019: ldarg.3                         : PolishNotation.cs(63) */
    frame__.stack1_2__ = right;
    /* IL_001a: stfld Calculator.ExpressionNode.Right : PolishNotation.cs(63) */
    frame__.stack0_0__->Right = frame__.stack1_2__;
    /* IL_001f: ret                             : PolishNotation.cs(64) */
    il2c_return_unlink(&frame__);
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
    il2c_assert(this__ != NULL);

    //-------------------
    // [3-3] Local variables (!objref):

    int32_t leftResult = 0;
    int32_t rightResult = 0;
    bool local2__ = false;
    int32_t local3__ = 0;
    bool local4__ = false;
    bool local5__ = false;
    bool local6__ = false;

    //-------------------
    // [3-4] Evaluation stacks (!objref):

    int32_t stack0_2__;
    wchar_t stack0_4__;
    bool stack0_5__;
    int32_t stack1_0__;

    //-------------------
    // [3-5] Setup execution frame:

    Calculator_ExpressionNode_Reduce_EXECUTION_FRAME__ frame__ =
        { NULL, 3 };
    il2c_link_execution_frame(&frame__);

    //-------------------
    // [3-6] IL body:

    /* IL_0000: nop                             : PolishNotation.cs(67) */
    /* IL_0001: ldarg.0  */
    frame__.stack0_0__ = this__;
    /* IL_0002: ldfld Calculator.ExpressionNode.Left : PolishNotation.cs(68) */
    frame__.stack0_1__ = frame__.stack0_0__->Left;
    /* IL_0007: callvirt Calculator.ReducibleNode.Reduce : PolishNotation.cs(68) */
    stack0_2__ = frame__.stack0_1__->vptr0__->Reduce(frame__.stack0_1__);
    /* IL_000c: stloc.0                         : PolishNotation.cs(68) */
    leftResult = stack0_2__;
    /* IL_000d: ldarg.0                         : PolishNotation.cs(69) */
    frame__.stack0_0__ = this__;
    /* IL_000e: ldfld Calculator.ExpressionNode.Right : PolishNotation.cs(69) */
    frame__.stack0_1__ = frame__.stack0_0__->Right;
    /* IL_0013: callvirt Calculator.ReducibleNode.Reduce : PolishNotation.cs(69) */
    stack0_2__ = frame__.stack0_1__->vptr0__->Reduce(frame__.stack0_1__);
    /* IL_0018: stloc.1                         : PolishNotation.cs(69) */
    rightResult = stack0_2__;
    /* IL_0019: ldarg.0                         : PolishNotation.cs(70) */
    frame__.stack0_0__ = this__;
    /* IL_001a: ldfld Calculator.ExpressionNode.Operator : PolishNotation.cs(70) */
    frame__.stack0_3__ = frame__.stack0_0__->Operator;
    /* IL_001f: ldfld Calculator.OperatorNode.Operator : PolishNotation.cs(70) */
    stack0_4__ = frame__.stack0_3__->Operator;
    /* IL_0024: ldc.i4.s 43                     : PolishNotation.cs(70) */
    stack1_0__ = 43;
    /* IL_0026: ceq                             : PolishNotation.cs(70) */
    stack0_2__ = (int32_t)stack0_4__ == (int32_t)stack1_0__;
    /* IL_0028: stloc.2                         : PolishNotation.cs(70) */
    local2__ = (bool)stack0_2__;
    /* IL_0029: ldloc.2                         : PolishNotation.cs(70) */
    stack0_5__ = local2__;
    /* IL_002a: brfalse.s IL_0033               : PolishNotation.cs(70) */
    if (stack0_5__ == false) goto IL_0033;
    /* IL_002c: nop                             : PolishNotation.cs(71) */
    /* IL_002d: ldloc.0  */
    stack0_2__ = leftResult;
    /* IL_002e: ldloc.1                         : PolishNotation.cs(72) */
    stack1_0__ = rightResult;
    /* IL_002f: add                             : PolishNotation.cs(72) */
    stack0_2__ = stack0_2__ + stack1_0__;
    /* IL_0030: stloc.3                         : PolishNotation.cs(72) */
    local3__ = stack0_2__;
    /* IL_0031: br.s IL_008b                    : PolishNotation.cs(72) */
    goto IL_008b;
IL_0033:
    /* IL_0033: ldarg.0                         : PolishNotation.cs(74) */
    frame__.stack0_0__ = this__;
    /* IL_0034: ldfld Calculator.ExpressionNode.Operator : PolishNotation.cs(74) */
    frame__.stack0_3__ = frame__.stack0_0__->Operator;
    /* IL_0039: ldfld Calculator.OperatorNode.Operator : PolishNotation.cs(74) */
    stack0_4__ = frame__.stack0_3__->Operator;
    /* IL_003e: ldc.i4.s 45                     : PolishNotation.cs(74) */
    stack1_0__ = 45;
    /* IL_0040: ceq                             : PolishNotation.cs(74) */
    stack0_2__ = (int32_t)stack0_4__ == (int32_t)stack1_0__;
    /* IL_0042: stloc.s local4__                : PolishNotation.cs(74) */
    local4__ = (bool)stack0_2__;
    /* IL_0044: ldloc.s local4__                : PolishNotation.cs(74) */
    stack0_5__ = local4__;
    /* IL_0046: brfalse.s IL_004f               : PolishNotation.cs(74) */
    if (stack0_5__ == false) goto IL_004f;
    /* IL_0048: nop                             : PolishNotation.cs(75) */
    /* IL_0049: ldloc.0  */
    stack0_2__ = leftResult;
    /* IL_004a: ldloc.1                         : PolishNotation.cs(76) */
    stack1_0__ = rightResult;
    /* IL_004b: sub                             : PolishNotation.cs(76) */
    stack0_2__ = stack0_2__ - stack1_0__;
    /* IL_004c: stloc.3                         : PolishNotation.cs(76) */
    local3__ = stack0_2__;
    /* IL_004d: br.s IL_008b                    : PolishNotation.cs(76) */
    goto IL_008b;
IL_004f:
    /* IL_004f: ldarg.0                         : PolishNotation.cs(78) */
    frame__.stack0_0__ = this__;
    /* IL_0050: ldfld Calculator.ExpressionNode.Operator : PolishNotation.cs(78) */
    frame__.stack0_3__ = frame__.stack0_0__->Operator;
    /* IL_0055: ldfld Calculator.OperatorNode.Operator : PolishNotation.cs(78) */
    stack0_4__ = frame__.stack0_3__->Operator;
    /* IL_005a: ldc.i4.s 42                     : PolishNotation.cs(78) */
    stack1_0__ = 42;
    /* IL_005c: ceq                             : PolishNotation.cs(78) */
    stack0_2__ = (int32_t)stack0_4__ == (int32_t)stack1_0__;
    /* IL_005e: stloc.s local5__                : PolishNotation.cs(78) */
    local5__ = (bool)stack0_2__;
    /* IL_0060: ldloc.s local5__                : PolishNotation.cs(78) */
    stack0_5__ = local5__;
    /* IL_0062: brfalse.s IL_006b               : PolishNotation.cs(78) */
    if (stack0_5__ == false) goto IL_006b;
    /* IL_0064: nop                             : PolishNotation.cs(79) */
    /* IL_0065: ldloc.0  */
    stack0_2__ = leftResult;
    /* IL_0066: ldloc.1                         : PolishNotation.cs(80) */
    stack1_0__ = rightResult;
    /* IL_0067: mul                             : PolishNotation.cs(80) */
    stack0_2__ = stack0_2__ * stack1_0__;
    /* IL_0068: stloc.3                         : PolishNotation.cs(80) */
    local3__ = stack0_2__;
    /* IL_0069: br.s IL_008b                    : PolishNotation.cs(80) */
    goto IL_008b;
IL_006b:
    /* IL_006b: ldarg.0                         : PolishNotation.cs(82) */
    frame__.stack0_0__ = this__;
    /* IL_006c: ldfld Calculator.ExpressionNode.Operator : PolishNotation.cs(82) */
    frame__.stack0_3__ = frame__.stack0_0__->Operator;
    /* IL_0071: ldfld Calculator.OperatorNode.Operator : PolishNotation.cs(82) */
    stack0_4__ = frame__.stack0_3__->Operator;
    /* IL_0076: ldc.i4.s 47                     : PolishNotation.cs(82) */
    stack1_0__ = 47;
    /* IL_0078: ceq                             : PolishNotation.cs(82) */
    stack0_2__ = (int32_t)stack0_4__ == (int32_t)stack1_0__;
    /* IL_007a: stloc.s local6__                : PolishNotation.cs(82) */
    local6__ = (bool)stack0_2__;
    /* IL_007c: ldloc.s local6__                : PolishNotation.cs(82) */
    stack0_5__ = local6__;
    /* IL_007e: brfalse.s IL_0087               : PolishNotation.cs(82) */
    if (stack0_5__ == false) goto IL_0087;
    /* IL_0080: nop                             : PolishNotation.cs(83) */
    /* IL_0081: ldloc.0  */
    stack0_2__ = leftResult;
    /* IL_0082: ldloc.1                         : PolishNotation.cs(84) */
    stack1_0__ = rightResult;
    /* IL_0083: div                             : PolishNotation.cs(84) */
    stack0_2__ = stack0_2__ / stack1_0__;
    /* IL_0084: stloc.3                         : PolishNotation.cs(84) */
    local3__ = stack0_2__;
    /* IL_0085: br.s IL_008b                    : PolishNotation.cs(84) */
    goto IL_008b;
IL_0087:
    /* IL_0087: ldc.i4.0                        : PolishNotation.cs(88) */
    stack0_2__ = 0;
    /* IL_0088: stloc.3                         : PolishNotation.cs(88) */
    local3__ = stack0_2__;
    /* IL_0089: br.s IL_008b                    : PolishNotation.cs(88) */
    goto IL_008b;
IL_008b:
    /* IL_008b: ldloc.3                         : PolishNotation.cs(89) */
    stack0_2__ = local3__;
    /* IL_008c: ret                             : PolishNotation.cs(89) */
    il2c_return_unlink_with_value(&frame__, stack0_2__);
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
