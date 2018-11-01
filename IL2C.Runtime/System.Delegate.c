#include "il2c_private.h"

/////////////////////////////////////////////////////////////
// System.Delegate

int32_t System_Delegate_GetHashCode(System_Delegate* this__)
{
    il2c_assert(this__ != NULL);
    il2c_assert(this__->vptr0__ == &__System_Delegate_VTABLE__);
    il2c_assert(this__->count__ >= 1);

    System_Type* pType = System_Object_GetType((System_Object*)this__);
    return pType->vptr0__->GetHashCode(pType);
}

bool System_Delegate_Equals(System_Delegate* this__, System_Object* obj)
{
    il2c_assert(this__ != NULL);
    il2c_assert(this__->vptr0__ == &__System_Delegate_VTABLE__);
    il2c_assert(this__->count__ >= 1);

    if (System_Object_ReferenceEquals((System_Object*)this__, obj))
    {
        return true;
    }

    System_Delegate* rhs = il2c_isinst(obj, System_Delegate);
    if (rhs == NULL)
    {
        return false;
    }

    il2c_assert(rhs->vptr0__ == &__System_Delegate_VTABLE__);
    il2c_assert(rhs->count__ >= 1);

    if (this__->count__ != rhs->count__)
    {
        return false;
    }

    return il2c_memcmp(
        this__->methodtbl__,
        rhs->methodtbl__,
        this__->count__ * sizeof(IL2C_METHOD_TABLE_DECL)) == 0;
}

System_Delegate* System_Delegate_Combine(System_Delegate* a, System_Delegate* b)
{
    // TODO:
}

/////////////////////////////////////////////////
// Delegate special functions

System_Delegate* il2c_new_delegate__(
    IL2C_RUNTIME_TYPE_DECL* delegateType, System_Object* object, intptr_t method)
{
    il2c_assert(delegateType != NULL);
    il2c_assert(method != 0);

    System_Delegate* dlg = il2c_get_uninitialized_object_internal__(delegateType, sizeof(System_Delegate));
    dlg->vptr0__ = &__System_Delegate_VTABLE__;
    dlg->count__ = 1;
    dlg->methodtbl__[0].target = object;
    dlg->methodtbl__[0].methodPtr = method;

    return dlg;
}

/////////////////////////////////////////////////
// VTable and runtime type info declarations

void __System_Delegate_IL2C_MarkHandler__(System_Delegate* this__)
{
    il2c_assert(this__ != NULL);
    il2c_assert(this__->vptr0__ == &__System_Delegate_VTABLE__);
    il2c_assert(this__->count__ >= 1);

    int32_t index;
    for (index = 0; index < this__->count__; index++)
    {
        il2c_assert(this__->methodtbl__[index].methodPtr != 0);

        il2c_try_mark_from_handler(this__->methodtbl__[index].target);
    }
}

__System_Delegate_VTABLE_DECL__ __System_Delegate_VTABLE__ = {
    /* internalcall */ il2c_isinst__,
    (bool(*)(void*, System_Object*))System_Delegate_Equals,
    (void(*)(void*))System_Object_Finalize,
    (int32_t(*)(void*))System_Delegate_GetHashCode,
    (System_String* (*)(void*))System_Object_ToString
};

IL2C_RUNTIME_TYPE_DECL __System_Delegate_RUNTIME_TYPE__ = {
    "System.Delegate",
    IL2C_TYPE_VARIABLE,
    0,
    /* internalcall */ (IL2C_MARK_HANDLER)__System_Delegate_IL2C_MarkHandler__,
    il2c_typeof(System_Object)
};
