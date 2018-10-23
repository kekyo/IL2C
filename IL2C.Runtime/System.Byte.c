#include "il2c_private.h"

/////////////////////////////////////////////////////////////
// System.Byte

System_String* System_Byte_ToString(uint8_t* this__)
{
    wchar_t buffer[5];

    il2c_itow(*this__, buffer, 10);
    return il2c_new_string(buffer);
}

int32_t System_Byte_GetHashCode(uint8_t* this__)
{
    il2c_assert(this__ != NULL);

    return *this__;
}

bool System_Byte_Equals(uint8_t* this__, uint8_t obj)
{
    il2c_assert(this__ != NULL);

    return *this__ == obj;
}

bool System_Byte_Equals_1(uint8_t* this__, System_Object* obj)
{
    il2c_assert(this__ != NULL);

    if (obj == NULL)
    {
        return false;
    }

    uint8_t rhs = il2c_unbox(obj, System_Byte);
    return *this__ == rhs;
}

/////////////////////////////////////////////////
// VTable and runtime type info declarations

void* __System_Byte_IL2C_RuntimeCast__(uint8_t* this__, IL2C_RUNTIME_TYPE_DECL* type)
{
    il2c_assert(this__ != NULL);

    if (type == il2c_typeof(System_Byte)) return this__;
    return __System_ValueType_IL2C_RuntimeCast__((System_ValueType*)this__, type);
}

__System_Byte_VTABLE_DECL__ __System_Byte_VTABLE__ = {
    /* internalcall */ __System_Byte_IL2C_RuntimeCast__,
    System_Byte_ToString,
    System_Byte_GetHashCode,
    (void(*)(System_Byte*))System_Object_Finalize,
    System_Byte_Equals_1
};

IL2C_RUNTIME_TYPE_DECL __System_Byte_RUNTIME_TYPE__ = {
    "System.Byte",
    IL2C_TYPE_INTEGER,
    sizeof(System_Byte),
    /* internalcall */ IL2C_DEFAULT_MARK_HANDLER };
