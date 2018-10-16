#include "il2c_private.h"

/////////////////////////////////////////////////////////////
// System.Object

void __System_Object_IL2C_MarkHandler__(System_Object* this__)
{
    il2c_assert(this__ != NULL);
}

void* __System_Object_IL2C_RuntimeCast__(System_Object* this__, IL2C_RUNTIME_TYPE_DECL* type)
{
    il2c_assert(this__ != NULL);

    if (type == il2c_typeof(System_Object)) return this__;

    // throw new InvalidCastException();
    il2c_assert(0);
    return NULL;
}

IL2C_CONST_STRING(System_Object_name, L"System.Object");
System_String* __System_Object_ToString__(System_Object* this__)
{
    return System_Object_name;
}

int32_t __System_Object_GetHashCode__(System_Object* this__)
{
    return (int32_t)(intptr_t)this__;
}

void __System_Object_Finalize__(System_Object* this__)
{
    DEBUG_WRITE("System.Object.Finalize", "called.");
}

bool __System_Object_Equals__(System_Object* this__, System_Object* obj)
{
    return ((intptr_t)this__) == ((intptr_t)obj);
}

/////////////////////////////////////////////////
// VTable and runtime type info declarations

__System_Object_VTABLE_DECL__ __System_Object_VTABLE__ = {
    /* internalcall */ __System_Object_IL2C_RuntimeCast__,
    __System_Object_ToString__,
    __System_Object_GetHashCode__,
    __System_Object_Finalize__,
    __System_Object_Equals__
};

IL2C_RUNTIME_TYPE_DECL __System_Object_RUNTIME_TYPE__ = {
    "System.Object",
    sizeof(System_Object),
    /* internalcall */ (IL2C_MARK_HANDLER)__System_Object_IL2C_MarkHandler__
};
