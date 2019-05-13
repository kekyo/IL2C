#include "il2c_private.h"

/////////////////////////////////////////////////////////////
// System.Enum

System_String* System_Enum_ToString(System_Enum* this__)
{
    // TODO:
    return System_Object_ToString((System_Object*)this__);
}

int32_t System_Enum_GetHashCode(System_Enum* this__)
{
    // TODO:
    //il2c_assert(0);
    return (int32_t)(intptr_t)this__;
}

bool System_Enum_Equals__System_Object(System_Enum* this__, System_Object* obj)
{
    // TODO:
    //il2c_assert(0);
    return false;
}

/////////////////////////////////////////////////
// VTable and runtime type info declarations

System_Enum_VTABLE_DECL__ System_Enum_VTABLE__ = {
    0, // Adjustor offset
    (bool(*)(void*, System_Object*))System_Enum_Equals__System_Object,
    (void(*)(void*))System_Object_Finalize,
    (int32_t(*)(void*))System_Enum_GetHashCode,
    (System_String* (*)(void*))System_Enum_ToString
};

IL2C_RUNTIME_TYPE_ABSTRACT_BEGIN(
    System_Enum,
    "System.Enum",
    sizeof(System_Enum),
    System_ValueType,
    0, 0)
IL2C_RUNTIME_TYPE_END();
