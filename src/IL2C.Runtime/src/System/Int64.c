#include "il2c_private.h"

/////////////////////////////////////////////////////////////
// System.Int64

System_String* System_Int64_ToString(int64_t* this__)
{
    il2c_assert(this__ != NULL);

    wchar_t buffer[24];

    il2c_i64tow(*this__, buffer, 10);
    return il2c_new_string(buffer);
}

int32_t System_Int64_GetHashCode(int64_t* this__)
{
    il2c_assert(this__ != NULL);

    return (int32_t)*this__ ^ (int32_t)(*this__ >> 32);
}

bool System_Int64_Equals__System_Int64(int64_t* this__, int64_t obj)
{
    il2c_assert(this__ != NULL);

    return *this__ == obj;
}

bool System_Int64_Equals__System_Object(int64_t* this__, System_Object* obj)
{
    il2c_assert(this__ != NULL);

    if (obj == NULL)
    {
        return false;
    }

    int64_t rhs = *il2c_unbox(obj, System_Int64);
    return *this__ == rhs;
}

bool System_Int64_TryParse__System_String_System_Int64_REF(System_String* s, int64_t* result)
{
    // TODO: NullReferenceException
    il2c_assert(s != NULL);

    il2c_assert(result != NULL);
    il2c_assert(s->string_body__ != NULL);

    wchar_t* endPtr;

    *result = il2c_wtoi64(s->string_body__, &endPtr, 10);
    return ((s->string_body__ != endPtr) && (il2c_errno == 0)) ? true : false;
}

/////////////////////////////////////////////////
// VTable and runtime type info declarations

IL2C_DECLARE_TRAMPOLINE_VFUNC_FOR_VALUE_TYPE(System_Int64);
IL2C_DECLARE_TRAMPOLINE_VTABLE_FOR_VALUE_TYPE(System_Int64);

IL2C_RUNTIME_TYPE_BEGIN(
    System_Int64,
    "System.Int64",
    IL2C_TYPE_INTEGER,
    sizeof(System_Int64),
    System_ValueType,
    0, 0)
IL2C_RUNTIME_TYPE_END();
