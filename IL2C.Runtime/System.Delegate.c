#include "il2c_private.h"

/////////////////////////////////////////////////////////////
// System.Delegate

int32_t System_Delegate_GetHashCode(System_Delegate* this__)
{
    il2c_assert(this__);

    System_Type* pType = System_Object_GetType((System_Object*)this__);
    return pType->vptr0__->GetHashCode(pType);
}

bool System_Delegate_Equals(System_Delegate* this__, System_Object* obj)
{
    il2c_assert(this__);

    if (System_Object_ReferenceEquals((System_Object*)this__, obj))
    {
        return true;
    }

    System_Delegate* rhs = il2c_isinst(obj, System_Delegate);
    if (rhs != NULL)
    {
        if ((this__->_target == rhs->_target) &&
            (this__->_methodPtr == this__->_methodPtr))
        {
            return true;
        }
    }

    return false;
}

/////////////////////////////////////////////////
// VTable and runtime type info declarations

void __System_Delegate_IL2C_MarkHandler__(System_Delegate* this__)
{
    il2c_assert(this__ != NULL);

    il2c_try_mark_from_handler(this__->_target);
}

__System_Delegate_VTABLE_DECL__ __System_Delegate_VTABLE__ = {
    /* internalcall */ il2c_isinst__,
    (bool(*)(void*, System_Object*))System_Delegate_Equals,
    (void(*)(void*))System_Object_Finalize,
    (int32_t(*)(void*))System_Delegate_GetHashCode,
    (System_String* (*)(void*))System_Object_ToString
};

IL2C_DECLARE_RUNTIME_TYPE(System_Delegate, "System.Delegate", IL2C_TYPE_REFERENCE, System_Object);
