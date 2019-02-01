// [14-1] This is Calculator.Core native code translated by IL2C, do not edit.

#include <Calculator.Core.h>

#ifdef __cplusplus
extern "C" {
#endif

///////////////////////////////////////////////////////////////////////////
// [14-2] Type pre definitions:

////////////////////////////////////////////////////////////
// [2-1-1] .NET types:

/* public class */ typedef struct Calculator_NumericNode Calculator_NumericNode;

////////////////////////////////////////////////////////////
// [2-1-2] VTable types:

typedef Calculator_ReducibleNode_VTABLE_DECL__ Calculator_NumericNode_VTABLE_DECL__;

///////////////////////////////////////////////////////////////////////////
// [14-3] Type body definitions:

#ifdef Calculator_Core_DECL_TYPE_BODY__

////////////////////////////////////////////////////////////
// [1] Calculator.NumericNode

// [1-1-2] Class layout
/* public class */ struct Calculator_NumericNode
{
    Calculator_NumericNode_VTABLE_DECL__* vptr0__;
    int32_t NextIndex;
    int32_t Numeric;
};

// [1-5-2] VTable (Derived from Calculator.ReducibleNode)
extern Calculator_NumericNode_VTABLE_DECL__ Calculator_NumericNode_VTABLE__;

// [1-4] Runtime type information
IL2C_DECLARE_RUNTIME_TYPE(Calculator_NumericNode);

//////////////////////////////////////////////////////////////////////////////////
// [2-3] Methods: Calculator.NumericNode

extern /* public */ void Calculator_NumericNode__ctor(Calculator_NumericNode* this__, int32_t numeric, int32_t nextIndex);
extern /* public override */ int32_t Calculator_NumericNode_Reduce(Calculator_NumericNode* this__);

#endif

#ifdef __cplusplus
}
#endif
