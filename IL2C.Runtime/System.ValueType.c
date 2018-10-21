#include "il2c_private.h"

/////////////////////////////////////////////////////////////
// System.ValueType

IL2C_CONST_STRING(System_ValueType_name, L"System.ValueType");
System_String* System_ValueType_ToString(System_ValueType* this__)
{
    // TODO: GetType().ToString();
    return System_ValueType_name;
}

int32_t System_ValueType_GetHashCode(System_ValueType* this__)
{
    // TODO:
    return (int32_t)(intptr_t)this__;
}

bool System_ValueType_Equals(System_ValueType* this__, System_Object* obj)
{
    // TODO:
    return false;
}

/////////////////////////////////////////////////
// VTable and runtime type info declarations

void* __System_ValueType_IL2C_RuntimeCast__(System_ValueType* this__, IL2C_RUNTIME_TYPE_DECL* type)
{
    il2c_assert(this__ != NULL);

    if (type == il2c_typeof(System_ValueType)) return this__;
    return __System_Object_IL2C_RuntimeCast__((System_Object*)this__, type);
}

__System_ValueType_VTABLE_DECL__ __System_ValueType_VTABLE__ = {
    /* internalcall */ __System_ValueType_IL2C_RuntimeCast__,
    System_ValueType_ToString,
    System_ValueType_GetHashCode,
    (void(*)(System_ValueType*))System_Object_Finalize,
    System_ValueType_Equals,
};

IL2C_RUNTIME_TYPE_DECL __System_ValueType_RUNTIME_TYPE__ = {
    "System.ValueType",
    IL2C_TYPE_STANDARD,
    sizeof(System_ValueType),
    /* internalcall */ IL2C_DEFAULT_MARK_HANDLER };
