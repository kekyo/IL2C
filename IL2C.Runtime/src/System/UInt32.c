#include "il2c_private.h"

/////////////////////////////////////////////////////////////
// System.UInt32

System_String* System_UInt32_ToString(uint32_t* this__)
{
    il2c_assert(this__ != NULL);

    wchar_t buffer[14];

    il2c_u32tow(*this__, buffer, 10);
    return il2c_new_string(buffer);
}

int32_t System_UInt32_GetHashCode(uint32_t* this__)
{
    il2c_assert(this__ != NULL);

    return (int32_t)*this__;
}

bool System_UInt32_Equals__System_UInt32(uint32_t* this__, uint32_t obj)
{
    il2c_assert(this__ != NULL);

    return *this__ == obj;
}

bool System_UInt32_Equals__System_Object(uint32_t* this__, System_Object* obj)
{
    il2c_assert(this__ != NULL);

    if (obj == NULL)
    {
        return false;
    }

    uint32_t rhs = *il2c_unbox(obj, System_UInt32);
    return *this__ == rhs;
}

bool System_UInt32_TryParse__System_String_System_UInt32_REF(System_String* s, uint32_t* result)
{
    // TODO: NullReferenceException
    il2c_assert(s != NULL);

    il2c_assert(result != NULL);
    il2c_assert(s->string_body__ != NULL);

    wchar_t* endPtr;

    *result = il2c_wtou32(s->string_body__, &endPtr, 10);
    return ((s->string_body__ != endPtr) && (il2c_errno == 0)) ? true : false;
}

/////////////////////////////////////////////////
// VTable and runtime type info declarations

IL2C_DECLARE_TRAMPOLINE_VFUNC_FOR_VALUE_TYPE(System_UInt32);
IL2C_DECLARE_TRAMPOLINE_VTABLE_FOR_VALUE_TYPE(System_UInt32);

IL2C_RUNTIME_TYPE_BEGIN(
    System_UInt32,
    "System.UInt32",
    IL2C_TYPE_UNSIGNED_INTEGER,
    sizeof(System_UInt32),
    System_ValueType, 0, 0)
IL2C_RUNTIME_TYPE_END();
