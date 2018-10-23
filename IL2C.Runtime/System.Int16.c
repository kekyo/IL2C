#include "il2c_private.h"

/////////////////////////////////////////////////////////////
// System.Int16

System_String* System_Int16_ToString(int16_t* this__)
{
    wchar_t buffer[7];

    il2c_itow(*this__, buffer, 10);
    return il2c_new_string(buffer);
}

int32_t System_Int16_GetHashCode(int16_t* this__)
{
    il2c_assert(this__ != NULL);

    return *this__;
}

bool System_Int16_Equals(int16_t* this__, int16_t obj)
{
    il2c_assert(this__ != NULL);

    return *this__ == obj;
}

bool System_Int16_Equals_1(int16_t* this__, System_Object* obj)
{
    il2c_assert(this__ != NULL);

    if (obj == NULL)
    {
        return false;
    }

    int16_t rhs = il2c_unbox(obj, System_Int16);
    return *this__ == rhs;
}

/////////////////////////////////////////////////
// VTable and runtime type info declarations

void* __System_Int16_IL2C_RuntimeCast__(int16_t* this__, IL2C_RUNTIME_TYPE_DECL* type)
{
    il2c_assert(this__ != NULL);

    if (type == il2c_typeof(System_Int16)) return this__;
    return __System_ValueType_IL2C_RuntimeCast__((System_ValueType*)this__, type);
}

__System_Int16_VTABLE_DECL__ __System_Int16_VTABLE__ = {
    /* internalcall */ __System_Int16_IL2C_RuntimeCast__,
    System_Int16_ToString,
    System_Int16_GetHashCode,
    (void(*)(System_Int16*))System_Object_Finalize,
    System_Int16_Equals_1
};

IL2C_RUNTIME_TYPE_DECL __System_Int16_RUNTIME_TYPE__ = {
    "System.Int16",
    IL2C_TYPE_INTEGER,
    sizeof(System_Int16),
    /* internalcall */ IL2C_DEFAULT_MARK_HANDLER };
