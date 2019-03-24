// [14-1] This is Calculator.Core native code translated by IL2C, do not edit.

#include <Calculator.Core.h>

#ifdef __cplusplus
extern "C" {
#endif

///////////////////////////////////////////////////////////////////////////
// [14-2] Type pre definitions:

////////////////////////////////////////////////////////////
// [2-1-1] .NET types:

/* public abstract class */ typedef struct Calculator_AbstractNode Calculator_AbstractNode;

////////////////////////////////////////////////////////////
// [2-1-2] VTable types:

typedef System_Object_VTABLE_DECL__ Calculator_AbstractNode_VTABLE_DECL__;

///////////////////////////////////////////////////////////////////////////
// [14-3] Type body definitions:

#ifdef Calculator_Core_DECL_TYPE_BODY__

////////////////////////////////////////////////////////////
// [1] Calculator.AbstractNode

// [1-1-2] Class layout
/* public abstract class */ struct Calculator_AbstractNode
{
    Calculator_AbstractNode_VTABLE_DECL__* vptr0__;
    int32_t NextIndex;
};

// [1-5-1] VTable (Same as System.Object)
#define Calculator_AbstractNode_VTABLE__ System_Object_VTABLE__

// [1-4] Runtime type information
IL2C_DECLARE_RUNTIME_TYPE(Calculator_AbstractNode);

//////////////////////////////////////////////////////////////////////////////////
// [2-3] Methods: Calculator.AbstractNode

extern /* protected */ void Calculator_AbstractNode__ctor(Calculator_AbstractNode* this__, int32_t nextIndex);

#endif

#ifdef __cplusplus
}
#endif
