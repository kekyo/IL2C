#include "il2c_private.h"

/////////////////////////////////////////////////////////////
// System.UInt64

System_String* System_UInt64_ToString(uint64_t* this__)
{
    wchar_t buffer[24];

    il2c_ui64tow(*this__, buffer, 10);
    return il2c_new_string(buffer);
}

int32_t System_UInt64_GetHashCode(uint64_t* this__)
{
    il2c_assert(this__ != NULL);

    return (int32_t)*this__ ^ (int32_t)(*this__ >> 32);
}

bool System_UInt64_Equals(uint64_t* this__, uint64_t obj)
{
    il2c_assert(this__ != NULL);

    return *this__ == obj;
}

bool System_UInt64_Equals_1(uint64_t* this__, System_Object* obj)
{
    il2c_assert(this__ != NULL);

    if (obj == NULL)
    {
        return false;
    }

    uint64_t rhs = il2c_unbox(obj, System_UInt64);
    return *this__ == rhs;
}

bool System_UInt64_TryParse(System_String* s, uint64_t* result)
{
    // TODO: NullReferenceException
    il2c_assert(s != NULL);

    il2c_assert(result != NULL);
    il2c_assert(s->string_body__ != NULL);

    wchar_t* endPtr;

    *result = il2c_wcstoull(s->string_body__, &endPtr, 10);
    return ((s->string_body__ != endPtr) && (errno == 0)) ? true : false;
}

/////////////////////////////////////////////////
// VTable and runtime type info declarations

IL2C_DECLARE_OBJECT_VTABLE(System_UInt64);
IL2C_DECLARE_RUNTIME_TYPE(System_UInt64, "System.UInt64", IL2C_TYPE_INTEGER, System_ValueType);
