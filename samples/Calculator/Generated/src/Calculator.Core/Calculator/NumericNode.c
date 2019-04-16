// [15-2] This is Calculator.Core native code translated by IL2C, do not edit.

#include <Calculator.Core.h>
#include <Calculator.Core_internal.h>

#include <mscorlib.h>

#ifdef __cplusplus
extern "C" {
#endif

//////////////////////////////////////////////////////////////////////////////////
// [9-1] Type: Calculator.NumericNode

//////////////////////////////////////////////////////////////////////////////////
// [9-2] File scope prototypes:

//////////////////////////////////////////////////////////////////////////////////
// [9-4] Type: Calculator.NumericNode

///////////////////////////////////////
// [3] Calculator.NumericNode..ctor(Calculator.NumericNode this__, System.Int32 numeric, System.Int32 nextIndex)

//-------------------
// [3-7] Declare execution frame:

typedef struct Calculator_NumericNode__ctor_EXECUTION_FRAME_DECL
{
    const IL2C_EXECUTION_FRAME* pNext__;
    const uint16_t objRefCount__;
    const uint16_t valueCount__;
    //-------------------- objref
    Calculator_NumericNode* stack0_0__;
} Calculator_NumericNode__ctor_EXECUTION_FRAME__;

//-------------------
// [3-2] Function body:

void Calculator_NumericNode__ctor(Calculator_NumericNode* this__, int32_t numeric, int32_t nextIndex)
{
    il2c_assert(this__ != NULL);

    //-------------------
    // [3-4] Evaluation stacks (!objref):

    int32_t stack1_0__;

    //-------------------
    // [3-5] Setup execution frame:

    Calculator_NumericNode__ctor_EXECUTION_FRAME__ frame__ =
        { NULL, 1 };
    il2c_link_execution_frame(&frame__);

    //-------------------
    // [3-6] IL body:

    /* IL_0000: ldarg.0                         : PolishNotation.cs(42) */
    frame__.stack0_0__ = this__;
    /* IL_0001: ldarg.2                         : PolishNotation.cs(42) */
    stack1_0__ = nextIndex;
    /* IL_0002: call Calculator.ReducibleNode..ctor : PolishNotation.cs(42) */
    Calculator_ReducibleNode__ctor((Calculator_ReducibleNode*)frame__.stack0_0__, stack1_0__);
    /* IL_0007: nop                             : PolishNotation.cs(42) */
    /* IL_0008: nop  */
    /* IL_0009: ldarg.0  */
    frame__.stack0_0__ = this__;
    /* IL_000a: ldarg.1                         : PolishNotation.cs(44) */
    stack1_0__ = numeric;
    /* IL_000b: stfld Calculator.NumericNode.Numeric : PolishNotation.cs(44) */
    frame__.stack0_0__->Numeric = stack1_0__;
    /* IL_0010: ret                             : PolishNotation.cs(45) */
    il2c_return_unlink(&frame__);
}

///////////////////////////////////////
// [3] Virtual: Calculator.NumericNode.Reduce(Calculator.NumericNode this__)

//-------------------
// [3-7] Declare execution frame:

typedef struct Calculator_NumericNode_Reduce_EXECUTION_FRAME_DECL
{
    const IL2C_EXECUTION_FRAME* pNext__;
    const uint16_t objRefCount__;
    const uint16_t valueCount__;
    //-------------------- objref
    Calculator_NumericNode* stack0_0__;
} Calculator_NumericNode_Reduce_EXECUTION_FRAME__;

//-------------------
// [3-2] Function body:

int32_t Calculator_NumericNode_Reduce(Calculator_NumericNode* this__)
{
    il2c_assert(this__ != NULL);

    //-------------------
    // [3-3] Local variables (!objref):

    int32_t local0__ = 0;

    //-------------------
    // [3-4] Evaluation stacks (!objref):

    int32_t stack0_1__;

    //-------------------
    // [3-5] Setup execution frame:

    Calculator_NumericNode_Reduce_EXECUTION_FRAME__ frame__ =
        { NULL, 1 };
    il2c_link_execution_frame(&frame__);

    //-------------------
    // [3-6] IL body:

    /* IL_0000: nop                             : PolishNotation.cs(48) */
    /* IL_0001: ldarg.0  */
    frame__.stack0_0__ = this__;
    /* IL_0002: ldfld Calculator.NumericNode.Numeric : PolishNotation.cs(49) */
    stack0_1__ = frame__.stack0_0__->Numeric;
    /* IL_0007: stloc.0                         : PolishNotation.cs(49) */
    local0__ = stack0_1__;
    /* IL_0008: br.s IL_000a                    : PolishNotation.cs(49) */
    goto IL_000a;
IL_000a:
    /* IL_000a: ldloc.0                         : PolishNotation.cs(50) */
    stack0_1__ = local0__;
    /* IL_000b: ret                             : PolishNotation.cs(50) */
    il2c_return_unlink_with_value(&frame__, stack0_1__);
}

//////////////////////
// [7] Runtime helpers:

// [7-10-2] VTable
Calculator_NumericNode_VTABLE_DECL__ Calculator_NumericNode_VTABLE__ = {
    0, // Adjustor offset
    (bool (*)(void*, System_Object*))System_Object_Equals,
    (void (*)(void*))System_Object_Finalize,
    (int32_t (*)(void*))System_Object_GetHashCode,
    (System_String* (*)(void*))System_Object_ToString,
    (int32_t (*)(void*))Calculator_NumericNode_Reduce,
};

// [7-8] Runtime type information
IL2C_RUNTIME_TYPE_BEGIN(Calculator_NumericNode, "Calculator.NumericNode", IL2C_TYPE_REFERENCE, sizeof(Calculator_NumericNode), Calculator_ReducibleNode, 0, 0)
IL2C_RUNTIME_TYPE_END();

#ifdef __cplusplus
}
#endif
