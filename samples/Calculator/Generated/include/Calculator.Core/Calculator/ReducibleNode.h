// [14-1] This is Calculator.Core native code translated by IL2C, do not edit.

#include <Calculator.Core.h>

#ifdef __cplusplus
extern "C" {
#endif

///////////////////////////////////////////////////////////////////////////
// [14-2] Type pre definitions:

////////////////////////////////////////////////////////////
// [2-1-1] .NET types:

/* public abstract class */ typedef struct Calculator_ReducibleNode Calculator_ReducibleNode;

////////////////////////////////////////////////////////////
// [2-1-2] VTable types:

typedef const struct Calculator_ReducibleNode_VTABLE_DECL___ Calculator_ReducibleNode_VTABLE_DECL__;

///////////////////////////////////////////////////////////////////////////
// [14-3] Type body definitions:

#ifdef Calculator_Core_DECL_TYPE_BODY__

////////////////////////////////////////////////////////////
// [1] Calculator.ReducibleNode

// [1-2-3] Class VTable layout (Derived from Calculator.AbstractNode)
struct Calculator_ReducibleNode_VTABLE_DECL___
{
    intptr_t offset__; // Adjustor offset
    bool (*Equals)(void* this__, System_Object* obj);
    void (*Finalize)(void* this__);
    int32_t (*GetHashCode)(void* this__);
    System_String* (*ToString)(void* this__);
    int32_t (*Reduce)(void* this__);
};

// [1-1-2] Class layout
/* public abstract class */ struct Calculator_ReducibleNode
{
    Calculator_ReducibleNode_VTABLE_DECL__* vptr0__;
    int32_t NextIndex;
};

// [1-4] Runtime type information
IL2C_DECLARE_RUNTIME_TYPE(Calculator_ReducibleNode);

//////////////////////////////////////////////////////////////////////////////////
// [2-3] Methods: Calculator.ReducibleNode

extern /* protected */ void Calculator_ReducibleNode__ctor(Calculator_ReducibleNode* this__, int32_t nextIndex);

#endif

#ifdef __cplusplus
}
#endif
