#include "il2c_private.h"

/////////////////////////////////////////////////////////////
// System.ValueType

void __System_ValueType_IL2C_MarkHandler__(System_ValueType* this__)
{
    il2c_assert(this__ != NULL);
}

void* __System_ValueType_IL2C_RuntimeCast__(System_ValueType* this__, IL2C_RUNTIME_TYPE_DECL* type)
{
    il2c_assert(this__ != NULL);

    if (type == il2c_typeof(System_ValueType)) return this__;
    return __System_Object_IL2C_RuntimeCast__((System_Object*)this__, type);
}

IL2C_CONST_STRING(System_ValueType_name, L"System.ValueType");
System_String* __System_ValueType_ToString__(System_ValueType* this__)
{
    return System_ValueType_name;
}

int32_t __System_ValueType_GetHashCode__(System_ValueType* this__)
{
    // TODO:
    return (int32_t)(intptr_t)this__;
}

bool __System_ValueType_Equals__(System_ValueType* this__, System_Object* obj)
{
    // TODO:
    return false;
}

/////////////////////////////////////////////////
// VTable and runtime type info declarations

__System_ValueType_VTABLE_DECL__ __System_ValueType_VTABLE__ = {
    /* internalcall */ __System_ValueType_IL2C_RuntimeCast__,
    __System_ValueType_ToString__,
    __System_ValueType_GetHashCode__,
    (void*)__System_Object_Finalize__,
    __System_ValueType_Equals__,
};

IL2C_RUNTIME_TYPE_DECL __System_ValueType_RUNTIME_TYPE__ = {
    "System.ValueType",
    sizeof(System_ValueType),
    /* internalcall */ (IL2C_MARK_HANDLER)__System_ValueType_IL2C_MarkHandler__
};
