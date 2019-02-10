// [14-1] This is Calculator.Core native code translated by IL2C, do not edit.

#include <Calculator.Core.h>

#ifdef __cplusplus
extern "C" {
#endif

///////////////////////////////////////////////////////////////////////////
// [14-2] Type pre definitions:

////////////////////////////////////////////////////////////
// [2-1-1] .NET types:

/* public class */ typedef struct Calculator_ExpressionNode Calculator_ExpressionNode;

////////////////////////////////////////////////////////////
// [2-1-2] VTable types:

typedef Calculator_ReducibleNode_VTABLE_DECL__ Calculator_ExpressionNode_VTABLE_DECL__;

///////////////////////////////////////////////////////////////////////////
// [14-3] Type body definitions:

#ifdef Calculator_Core_DECL_TYPE_BODY__

////////////////////////////////////////////////////////////
// [1] Calculator.ExpressionNode

// [1-1-2] Class layout
/* public class */ struct Calculator_ExpressionNode
{
    Calculator_ExpressionNode_VTABLE_DECL__* vptr0__;
    int32_t NextIndex;
    Calculator_OperatorNode* Operator;
    Calculator_ReducibleNode* Left;
    Calculator_ReducibleNode* Right;
};

// [1-5-2] VTable (Derived from Calculator.ReducibleNode)
extern Calculator_ExpressionNode_VTABLE_DECL__ Calculator_ExpressionNode_VTABLE__;

// [1-4] Runtime type information
IL2C_DECLARE_RUNTIME_TYPE(Calculator_ExpressionNode);

//////////////////////////////////////////////////////////////////////////////////
// [2-3] Methods: Calculator.ExpressionNode

extern /* public */ void Calculator_ExpressionNode__ctor(Calculator_ExpressionNode* this__, Calculator_OperatorNode* oper, Calculator_ReducibleNode* left, Calculator_ReducibleNode* right, int32_t nextIndex);
extern /* public override */ int32_t Calculator_ExpressionNode_Reduce(Calculator_ExpressionNode* this__);

#endif

#ifdef __cplusplus
}
#endif
