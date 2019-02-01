// [15-2] This is Calculator.Core native code translated by IL2C, do not edit.

#include <Calculator.Core.h>
#include <Calculator.Core_internal.h>

#ifdef __cplusplus
extern "C" {
#endif

//////////////////////////////////////////////////////////////////////////////////
// [9-1] Type: Calculator.ReducibleNode

//////////////////////////////////////////////////////////////////////////////////
// [9-2] File scope prototypes:

//////////////////////////////////////////////////////////////////////////////////
// [9-4] Type: Calculator.ReducibleNode

///////////////////////////////////////
// [3] Calculator.ReducibleNode..ctor(Calculator.ReducibleNode this__, System.Int32 nextIndex)

//-------------------
// [3-7] Declare execution frame:

typedef struct Calculator_ReducibleNode__ctor_EXECUTION_FRAME_DECL
{
    const IL2C_EXECUTION_FRAME* pNext__;
    const uint16_t objRefCount__;
    const uint16_t valueCount__;
    //-------------------- objref
    Calculator_ReducibleNode* stack0_0__;
} Calculator_ReducibleNode__ctor_EXECUTION_FRAME__;

//-------------------
// [3-2] Function body:

void Calculator_ReducibleNode__ctor(Calculator_ReducibleNode* this__, int32_t nextIndex)
{
    il2c_assert(this__ != NULL);

    //-------------------
    // [3-4] Evaluation stacks (!objref):

    int32_t stack1_0__;

    //-------------------
    // [3-5] Setup execution frame:

    Calculator_ReducibleNode__ctor_EXECUTION_FRAME__ frame__ =
        { NULL, 1 };
    il2c_link_execution_frame(&frame__);

    //-------------------
    // [3-6] IL body:

    /* IL_0000: ldarg.0                         : PolishNotation.cs(31) */
    frame__.stack0_0__ = this__;
    /* IL_0001: ldarg.1                         : PolishNotation.cs(31) */
    stack1_0__ = nextIndex;
    /* IL_0002: call Calculator.AbstractNode..ctor : PolishNotation.cs(31) */
    Calculator_AbstractNode__ctor((Calculator_AbstractNode*)frame__.stack0_0__, stack1_0__);
    /* IL_0007: nop                             : PolishNotation.cs(31) */
    /* IL_0008: nop  */
    /* IL_0009: ret  */
    il2c_unlink_execution_frame(&frame__);
    return;
}

//////////////////////
// [7] Runtime helpers:

// [7-8] Runtime type information
IL2C_RUNTIME_TYPE_ABSTRACT_BEGIN(Calculator_ReducibleNode, "Calculator.ReducibleNode", sizeof(Calculator_ReducibleNode), Calculator_AbstractNode, 0, 0)
IL2C_RUNTIME_TYPE_END();

#ifdef __cplusplus
}
#endif
