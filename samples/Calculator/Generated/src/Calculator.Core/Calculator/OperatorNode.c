// [15-2] This is Calculator.Core native code translated by IL2C, do not edit.

#include <Calculator.Core.h>
#include <Calculator.Core_internal.h>

#include <mscorlib.h>

#ifdef __cplusplus
extern "C" {
#endif

//////////////////////////////////////////////////////////////////////////////////
// [9-1] Type: Calculator.OperatorNode

//////////////////////////////////////////////////////////////////////////////////
// [9-2] File scope prototypes:

//////////////////////////////////////////////////////////////////////////////////
// [9-4] Type: Calculator.OperatorNode

///////////////////////////////////////
// [3] Calculator.OperatorNode..ctor(Calculator.OperatorNode this__, System.Char oper, System.Int32 nextIndex)

//-------------------
// [3-7] Declare execution frame:

typedef struct Calculator_OperatorNode__ctor_EXECUTION_FRAME_DECL
{
    const IL2C_EXECUTION_FRAME* pNext__;
    const uint16_t objRefCount__;
    const uint16_t valueCount__;
    //-------------------- objref
    Calculator_OperatorNode* stack0_0__;
} Calculator_OperatorNode__ctor_EXECUTION_FRAME__;

//-------------------
// [3-2] Function body:

void Calculator_OperatorNode__ctor(Calculator_OperatorNode* this__, wchar_t oper, int32_t nextIndex)
{
#line 23 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    il2c_assert(this__ != NULL);

    //-------------------
    // [3-4] Evaluation stacks (!objref):

#line 23 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    int32_t stack1_0__;
#line 23 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    wchar_t stack1_1__;

    //-------------------
    // [3-5] Setup execution frame:

#line 23 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    Calculator_OperatorNode__ctor_EXECUTION_FRAME__ frame__ =
        { NULL, 1 };
#line 23 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    il2c_link_execution_frame(&frame__);

    //-------------------
    // [3-6] IL body:

    /* IL_0000: ldarg.0  */
#line 23 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    frame__.stack0_0__ = this__;
    /* IL_0001: ldarg.2  */
#line 23 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack1_0__ = nextIndex;
    /* IL_0002: call Calculator.AbstractNode..ctor */
#line 23 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    Calculator_AbstractNode__ctor((Calculator_AbstractNode*)frame__.stack0_0__, stack1_0__);
    /* IL_0007: nop  */
    /* IL_0008: nop  */
    /* IL_0009: ldarg.0  */
#line 25 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    frame__.stack0_0__ = this__;
    /* IL_000a: ldarg.1  */
#line 25 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    stack1_1__ = oper;
    /* IL_000b: stfld Calculator.OperatorNode.Operator */
#line 25 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    frame__.stack0_0__->Operator = stack1_1__;
    /* IL_0010: ret  */
#line 26 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    il2c_unlink_execution_frame(&frame__);
#line 26 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
    return;
#line 26 "D:\\PROJECT\\IL2C\\samples\\Calculator\\Calculator.Core\\PolishNotation.cs"
}

//////////////////////
// [7] Runtime helpers:

// [7-10-1] VTable (Not defined, same as Calculator.AbstractNode)

// [7-8] Runtime type information
IL2C_RUNTIME_TYPE_BEGIN(Calculator_OperatorNode, "Calculator.OperatorNode", IL2C_TYPE_REFERENCE, sizeof(Calculator_OperatorNode), Calculator_AbstractNode, 0, 0)
IL2C_RUNTIME_TYPE_END();

#ifdef __cplusplus
}
#endif
