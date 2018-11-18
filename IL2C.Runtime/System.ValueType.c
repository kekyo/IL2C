#include "il2c_private.h"

/////////////////////////////////////////////////////////////
// System.ValueType

System_String* System_ValueType_ToString(System_ValueType* this__)
{
    return NULL;
}

int32_t System_ValueType_GetHashCode(System_ValueType* this__)
{
    // TODO:
    il2c_assert(0);
    return (int32_t)(intptr_t)this__;
}

bool System_ValueType_Equals(System_ValueType* this__, System_Object* obj)
{
    // TODO:
    il2c_assert(0);
    return false;
}

/////////////////////////////////////////////////
// VTable and runtime type info declarations

System_ValueType_VTABLE_DECL__ System_ValueType_VTABLE__ = {
    (bool(*)(void*, System_Object*))System_ValueType_Equals,
    (void(*)(void*))System_Object_Finalize,
    (int32_t(*)(void*))System_ValueType_GetHashCode,
    (System_String* (*)(void*))System_ValueType_ToString
};

IL2C_RUNTIME_TYPE_BEGIN(System_ValueType, "System.ValueType", IL2C_TYPE_REFERENCE, System_Object, 0, 0)
IL2C_RUNTIME_TYPE_END();
