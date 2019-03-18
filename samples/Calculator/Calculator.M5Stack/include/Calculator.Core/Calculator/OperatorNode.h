// [14-1] This is Calculator.Core native code translated by IL2C, do not edit.

#include <Calculator.Core.h>

#ifdef __cplusplus
extern "C" {
#endif

///////////////////////////////////////////////////////////////////////////
// [14-2] Type pre definitions:

////////////////////////////////////////////////////////////
// [2-1-1] .NET types:

/* public class */ typedef struct Calculator_OperatorNode Calculator_OperatorNode;

////////////////////////////////////////////////////////////
// [2-1-2] VTable types:

typedef Calculator_AbstractNode_VTABLE_DECL__ Calculator_OperatorNode_VTABLE_DECL__;

///////////////////////////////////////////////////////////////////////////
// [14-3] Type body definitions:

#ifdef Calculator_Core_DECL_TYPE_BODY__

////////////////////////////////////////////////////////////
// [1] Calculator.OperatorNode

// [1-1-2] Class layout
/* public class */ struct Calculator_OperatorNode
{
    Calculator_OperatorNode_VTABLE_DECL__* vptr0__;
    int32_t NextIndex;
    wchar_t Operator;
};

// [1-5-1] VTable (Same as Calculator.AbstractNode)
#define Calculator_OperatorNode_VTABLE__ Calculator_AbstractNode_VTABLE__

// [1-4] Runtime type information
IL2C_DECLARE_RUNTIME_TYPE(Calculator_OperatorNode);

//////////////////////////////////////////////////////////////////////////////////
// [2-3] Methods: Calculator.OperatorNode

extern /* public */ void Calculator_OperatorNode__ctor(Calculator_OperatorNode* this__, wchar_t oper, int32_t nextIndex);

#endif

#ifdef __cplusplus
}
#endif
