#include "il2c_private.h"

/////////////////////////////////////////////////////////////
// System.UIntPtr

const uintptr_t System_UIntPtr_Zero = (uintptr_t)0;

System_String* System_UIntPtr_ToString(uintptr_t* this__)
{
    il2c_assert(this__ != NULL);

    wchar_t buffer[24];

    il2c_u64tow(*this__, buffer, 10);
    return il2c_new_string(buffer);
}

int32_t System_UIntPtr_GetHashCode(uintptr_t* this__)
{
    il2c_assert(this__ != NULL);

    uint64_t value = *this__;
    return (int32_t)value ^ (int32_t)(value >> 32);
}

bool System_UIntPtr_Equals__System_UIntPtr(uintptr_t* this__, uintptr_t obj)
{
    il2c_assert(this__ != NULL);

    return *this__ == obj;
}

bool System_UIntPtr_Equals__System_Object(uintptr_t* this__, System_Object* obj)
{
    il2c_assert(this__ != NULL);

    if (obj == NULL)
    {
        return false;
    }

    uintptr_t rhs = *il2c_unbox(obj, System_UIntPtr);
    return *this__ == rhs;
}

/////////////////////////////////////////////////
// VTable and runtime type info declarations

IL2C_DECLARE_TRAMPOLINE_VFUNC_FOR_VALUE_TYPE(System_UIntPtr);
IL2C_DECLARE_TRAMPOLINE_VTABLE_FOR_VALUE_TYPE(System_UIntPtr);

IL2C_RUNTIME_TYPE_BEGIN(
    System_UIntPtr,
    "System.UIntPtr",
    IL2C_TYPE_UNSIGNED_INTEGER,
    sizeof(System_UIntPtr),
    System_ValueType,
    0, 0)
IL2C_RUNTIME_TYPE_END();
